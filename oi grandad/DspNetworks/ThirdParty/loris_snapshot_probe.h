#pragma once

#include <array>
#include <atomic>

namespace project
{
using namespace juce;
using namespace hise;
using namespace scriptnode;

template <int NV> struct loris_snapshot_probe : public data::base
{
	SNEX_NODE(loris_snapshot_probe);

	struct MetadataClass
	{
		SN_NODE_ID("loris_snapshot_probe");
	};

	static constexpr bool isModNode() { return false; }
	static constexpr bool isPolyphonic() { return NV > 1; }
	static constexpr bool hasTail() { return false; }
	static constexpr bool isSuspendedOnSilence() { return false; }
	static constexpr int getFixChannelAmount() { return 2; }

	static constexpr int NumTables = 0;
	static constexpr int NumSliderPacks = 0;
	static constexpr int NumAudioFiles = 1;
	static constexpr int NumFilters = 0;
	static constexpr int NumDisplayBuffers = 1;

	enum class ProbeState
	{
		Idle = 0,
		Running,
		Success,
		Error
	};

	void prepare(PrepareSpecs ps)
	{
		sampleRate = ps.sampleRate;
	}

	void reset() {}

	template <typename ProcessDataType> void process(ProcessDataType& data)
	{
		auto& fixData = data.template as<ProcessData<2>>();
		auto fd = fixData.toFrameData();

		while (fd.next())
		{
			fd.toSpan()[0] += 0.0f;
			fd.toSpan()[1] += 0.0f;
		}

		statusBuffer.setDisplayedValue((double) (int) state.load());
	}

	template <typename FrameDataType> void processFrame(FrameDataType& data)
	{
		auto& fixFrame = span<float, 2>::as(data.begin());
		fixFrame[0] += 0.0f;
		fixFrame[1] += 0.0f;
		statusBuffer.setDisplayedValue((double) (int) state.load());
	}

	void handleHiseEvent(HiseEvent&) {}

	void setExternalData(const ExternalData& data, int index)
	{
		if (data.dataType == ExternalData::DataType::DisplayBuffer)
		{
			if (index == 0)
				statusBuffer = data;
			return;
		}

		if (data.dataType != ExternalData::DataType::AudioFile || index != 0)
			return;

		audioFile = data;

		for (int ch = 0; ch < 2; ++ch)
			data.referBlockTo(sourceSample[(size_t) ch], ch);
	}

	template <int P> void setParameter(double v)
	{
		if (P == 0)
		{
			if (v >= 0.5 && trigger < 0.5)
				runProbe();

			trigger = v;
		}
	}

	void createParameters(ParameterDataList& data)
	{
		parameter::data p("Probe", { 0.0, 1.0, 1.0 });
		registerCallback<0>(p);
		p.setParameterValueNames({ "Idle", "Run" });
		p.setDefaultValue(0.0);
		data.add(std::move(p));
	}

	void runProbe()
	{
		if (audioFile.numSamples <= 2 || audioFile.sampleRate <= 0.0)
		{
			lastMessage = "No sample loaded";
			state.store(ProbeState::Error);
			statusBuffer.setDisplayedValue((double) (int) ProbeState::Error);
			Logger::writeToLog("[loris_snapshot_probe] " + lastMessage);
			return;
		}

		state.store(ProbeState::Running);
		statusBuffer.setDisplayedValue((double) (int) ProbeState::Running);

#if HISE_INCLUDE_LORIS
		WavAudioFormat wav;
		AudioSampleBuffer tempBuffer(jmax(1, audioFile.numChannels), audioFile.numSamples);

		for (int ch = 0; ch < tempBuffer.getNumChannels(); ++ch)
		{
			if (sourceSample[(size_t) ch].size() <= 0)
				continue;

			auto* dst = tempBuffer.getWritePointer(ch);
			for (int i = 0; i < audioFile.numSamples; ++i)
				dst[i] = sourceSample[(size_t) ch][i];
		}

		auto tempFile = File::getSpecialLocation(File::tempDirectory)
			.getChildFile("oi_grandad_loris_snapshot_probe.wav");
		tempFile.deleteFile();

		{
			std::unique_ptr<FileOutputStream> fos(tempFile.createOutputStream());
			if (fos == nullptr)
			{
				lastMessage = "Failed to create temp file";
				state.store(ProbeState::Error);
				Logger::writeToLog("[loris_snapshot_probe] " + lastMessage);
				return;
			}

			std::unique_ptr<AudioFormatWriter> writer(wav.createWriterFor(fos.release(),
				audioFile.sampleRate,
				(unsigned int) tempBuffer.getNumChannels(),
				24,
				{},
				5));

			if (writer == nullptr || !writer->writeFromAudioSampleBuffer(tempBuffer, 0, tempBuffer.getNumSamples()))
			{
				lastMessage = "Failed to write temp file";
				state.store(ProbeState::Error);
				Logger::writeToLog("[loris_snapshot_probe] " + lastMessage);
				return;
			}
		}

		if (lorisManager == nullptr)
			lorisManager = new hise::LorisManager(File(), [](String m)
			{
				Logger::writeToLog("[loris_snapshot_probe] Loris: " + m);
			});

		if (lorisManager == nullptr)
		{
			lastMessage = "Failed to create Loris manager";
			state.store(ProbeState::Error);
			Logger::writeToLog("[loris_snapshot_probe] " + lastMessage);
			return;
		}

		const double rootFrequency = 220.0;
		hise::LorisManager::AnalyseData analysisData;
		analysisData.file = tempFile;
		analysisData.rootFrequency = rootFrequency;

		lorisManager->set("enablecache", "0");
		lorisManager->set("timedomain", "seconds");
		lorisManager->set("hoptime", "0.01");
		lorisManager->set("croptime", "0.01");
		lorisManager->set("windowwidth", "1.0");

		Logger::writeToLog("[loris_snapshot_probe] About to analyse " + tempFile.getFileName());
		lorisManager->analyse({ analysisData });
		Logger::writeToLog("[loris_snapshot_probe] Analyse returned");

		auto gainsVar = lorisManager->getSnapshot(tempFile, 0.0, "gain");
		if (!gainsVar.isArray())
		{
			lastMessage = "gain snapshot was not an array";
			state.store(ProbeState::Error);
			Logger::writeToLog("[loris_snapshot_probe] " + lastMessage);
			return;
		}

		if (gainsVar.size() == 0)
		{
			lastMessage = "gain snapshot had zero channels";
			state.store(ProbeState::Error);
			Logger::writeToLog("[loris_snapshot_probe] " + lastMessage);
			return;
		}

		auto* gainsArray = gainsVar[0].getArray();
		if (gainsArray == nullptr)
		{
			lastMessage = "gain snapshot channel 0 was null";
			state.store(ProbeState::Error);
			Logger::writeToLog("[loris_snapshot_probe] " + lastMessage);
			return;
		}

		if (gainsArray->isEmpty())
		{
			lastMessage = "gain snapshot channel 0 was empty";
			state.store(ProbeState::Error);
			Logger::writeToLog("[loris_snapshot_probe] " + lastMessage);
			return;
		}

		lastMessage = "success: channels=" + String(gainsVar.size()) + " harmonics=" + String(gainsArray->size());
		state.store(ProbeState::Success);
		Logger::writeToLog("[loris_snapshot_probe] " + lastMessage);
#else
		lastMessage = "Loris support is not available in this build";
		state.store(ProbeState::Error);
		Logger::writeToLog("[loris_snapshot_probe] " + lastMessage);
#endif

		statusBuffer.setDisplayedValue((double) (int) state.load());
	}

	ExternalData audioFile;
	ExternalData statusBuffer;
	std::array<block, 2> sourceSample {};
	std::atomic<ProbeState> state { ProbeState::Idle };
	String lastMessage;
	double sampleRate = 0.0;
	double trigger = 0.0;

#if HISE_INCLUDE_LORIS
	hise::LorisManager::Ptr lorisManager;
#endif
};

} // namespace project
