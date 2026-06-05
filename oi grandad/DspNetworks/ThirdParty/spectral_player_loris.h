/*
    Third-party spectral player scaffold.

    This node is intentionally minimal: it establishes the audiofile slot,
    offline-analysis state, cache layout, and playback parameter surface for a
    future Loris-backed spectral resynthesis engine.
*/

#pragma once

#include <algorithm>
#include <array>
#include <atomic>
#include <map>
#include <vector>

namespace project
{
using namespace juce;
using namespace hise;
using namespace scriptnode;

enum class GlobalCables
{
	spectral_status = 0
};

using spectral_cable_manager_t = routing::global_cable_cpp_manager<SN_GLOBAL_CABLE(-276979923)>;

template <int NV> struct spectral_player_loris : public data::base,
												 public spectral_cable_manager_t
{
	SNEX_NODE(spectral_player_loris);

	struct MetadataClass
	{
		SN_NODE_ID("spectral_player_loris");
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
	static constexpr int MaxRenderablePartials = 64;
	static constexpr int CycleSize = 2048;

	enum class AnalysisState
	{
		NotAnalysed = 0,
		Analysing,
		Ready,
		Error
	};

	struct PartialFrame
	{
		float frequencyHz = 0.0f;
		float amplitude = 0.0f;
		float phase = 0.0f;
		float noisiness = 0.0f;
	};

	struct AnalysisFrame
	{
		double timeSeconds = 0.0;
		std::vector<PartialFrame> partials;
		std::vector<float> harmonicGains;
		std::vector<float> harmonicPhases;
		std::vector<float> harmonicBandwidths;
		std::vector<float> waveform;
		float noiseEnergy = 0.0f;
	};

	struct SpectralAnalysisCache
	{
		bool valid = false;
		double sampleRate = 0.0;
		int64 numSourceSamples = 0;
		int partialCountHint = 0;
		int laneCount = 0;
		uint32 contentHash = 0;
		String lastError;
		std::vector<int> laneIds;
		std::vector<AnalysisFrame> frames;
		std::vector<float> lorisResynthMono;

		void reset()
		{
			valid = false;
			sampleRate = 0.0;
			numSourceSamples = 0;
			partialCountHint = 0;
			laneCount = 0;
			contentHash = 0;
			lastError.clear();
			laneIds.clear();
			frames.clear();
			lorisResynthMono.clear();
		}
	};

	struct VoiceState
	{
		double scrubPosition = 0.0;
		double lastScrubPosition = -1.0;
		double oscillatorPhase = 0.0;
		double resynthReadPos = 0.0;
		int noteNumber = 60;
		double pitchRatio = 1.0;
		std::array<double, MaxRenderablePartials> partialPhases {};
		std::array<double, MaxRenderablePartials> smoothedFrequencies {};
		std::array<double, MaxRenderablePartials> smoothedAmplitudes {};
		std::array<double, MaxRenderablePartials> smoothedNoisiness {};
		uint32 noiseState = 0x12345678u;

		void reset()
		{
			scrubPosition = 0.0;
			lastScrubPosition = -1.0;
			oscillatorPhase = 0.0;
			resynthReadPos = 0.0;
			noteNumber = 60;
			pitchRatio = 1.0;
			partialPhases.fill(0.0);
			smoothedFrequencies.fill(0.0);
			smoothedAmplitudes.fill(0.0);
			smoothedNoisiness.fill(0.0);
			noiseState = 0x12345678u;
		}
	};

	struct BreakpointCollector
	{
		struct FrameAccumulator
		{
			double timeSeconds = 0.0;
			std::vector<PartialFrame> partials;
			float noiseSum = 0.0f;
			int noiseCount = 0;
		};

		std::map<int64, FrameAccumulator> frames;
		double sampleRate = 44100.0;

#if HISE_INCLUDE_LORIS
		static bool collect(hise::LorisManager::CustomPOD& a)
		{
			auto* self = static_cast<BreakpointCollector*>(a.obj);
			if (self == nullptr || a.channelIndex != 0)
				return false;

			int64 sampleIndex = (int64) std::llround(a.time * self->sampleRate);
			auto& frame = self->frames[sampleIndex];
			frame.timeSeconds = a.time;

			if ((int) frame.partials.size() <= a.partialIndex)
				frame.partials.resize((size_t) a.partialIndex + 1);

			auto& p = frame.partials[(size_t) a.partialIndex];
			p.frequencyHz = (float) a.frequency;
			p.amplitude = (float) a.gain;
			p.phase = (float) a.phase;
			p.noisiness = (float) a.bandwidth;

			frame.noiseSum += (float) a.bandwidth;
			frame.noiseCount++;
			return false;
		}
#endif
	};

	void prepare(PrepareSpecs ps)
	{
		sampleRate = ps.sampleRate;
		blockSize = ps.blockSize;
		spectral_cable_manager_t::prepare(ps);
		voiceStates.prepare(ps);
		reset();
	}

	void reset()
	{
		for (auto& voice : voiceStates)
			voice.reset();
	}

	template <typename ProcessDataType> void process(ProcessDataType& data)
	{
		auto& fixData = data.template as<ProcessData<2>>();
		auto fd = fixData.toFrameData();
		auto& voice = voiceStates.get();

		while (fd.next())
			renderFrame(fd.toSpan(), voice);

		this->setGlobalCableValue<GlobalCables::spectral_status>(getNormalisedStateValue(state.load()));
		audioFile.setDisplayedValue(voice.scrubPosition);
		statusBuffer.setDisplayedValue((double) (int) state.load());
	}

	template <typename FrameDataType> void processFrame(FrameDataType& data)
	{
		auto& voice = voiceStates.get();
		auto& fixFrame = span<float, 2>::as(data.begin());
		renderFrame(fixFrame, voice);
		this->setGlobalCableValue<GlobalCables::spectral_status>(getNormalisedStateValue(state.load()));
		audioFile.setDisplayedValue(voice.scrubPosition);
		statusBuffer.setDisplayedValue((double) (int) state.load());
	}

	void handleHiseEvent(HiseEvent& e)
	{
		if (!e.isNoteOn())
			return;

		auto& voice = voiceStates.get();
		voice.reset();
		voice.noteNumber = e.getNoteNumber();
		updatePitchRatio(voice);
	}

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

		if (audioFile.numSamples <= 2 || audioFile.sampleRate <= 0.0)
		{
			invalidateAnalysis();
			return;
		}

		if (!cacheMatchesCurrentSample())
		{
			invalidateAnalysis();

			// If the Analyze parameter was already high when the node was restored,
			// retrigger analysis now that the sample slot is actually valid.
			if (analyzeTrigger >= 0.5)
				analyzeCurrentSample();
		}
	}

	template <int P> void setParameter(double v)
	{
		if (P == 0) scrub = clamp01(v);
		if (P == 1)
		{
			pitchSemitones = v;
			for (auto& voice : voiceStates)
				updatePitchRatio(voice);
		}
		if (P == 2) partialBlend = clamp01(v);
		if (P == 3) noiseBlend = clamp01(v);
		if (P == 4) partialCount = jlimit(1.0, 256.0, std::round(v));
		if (P == 5)
		{
			if (v >= 0.5 && (analyzeTrigger < 0.5 || !cacheMatchesCurrentSample()))
				analyzeCurrentSample();

			analyzeTrigger = v;
		}
		if (P == 6) debugMode = jlimit(0.0, 2.0, std::round(v));
	}

	void createParameters(ParameterDataList& data)
	{
		addParameter<0>(data, "Scrub", 0.0, 1.0, 0.0);
		addParameter<1>(data, "PitchSemitones", -24.0, 24.0, 0.0);
		addParameter<2>(data, "PartialBlend", 0.0, 1.0, 1.0);
		addParameter<3>(data, "NoiseBlend", 0.0, 1.0, 0.0);
		addParameter<4>(data, "PartialCount", 1.0, 256.0, 64.0);
		{
			parameter::data p("Analyze", { 0.0, 1.0, 1.0 });
			registerCallback<5>(p);
			p.setParameterValueNames({ "Idle", "Analyze" });
			p.setDefaultValue(0.0);
			data.add(std::move(p));
		}
		{
			parameter::data p("DebugMode", { 0.0, 2.0, 1.0 });
			registerCallback<6>(p);
			p.setParameterValueNames({ "Normal", "Snapshot", "Loris" });
			p.setDefaultValue(0.0);
			data.add(std::move(p));
		}
	}

	template <int P> void addParameter(ParameterDataList& data, const char* id, double min, double max, double defaultValue)
	{
		parameter::data p(id, { min, max });
		registerCallback<P>(p);
		p.setDefaultValue(defaultValue);
		data.add(std::move(p));
	}

	double clamp01(double v) const
	{
		return jlimit(0.0, 1.0, v);
	}

	double smooth01(double x) const
	{
		x = clamp01(x);
		return x * x * (3.0 - 2.0 * x);
	}

	double wrap01(double x) const
	{
		x -= std::floor(x);
		return x;
	}

	double wrapPhaseRadians(double x) const
	{
		while (x > MathConstants<double>::pi)
			x -= MathConstants<double>::twoPi;
		while (x < -MathConstants<double>::pi)
			x += MathConstants<double>::twoPi;
		return x;
	}

	double lerpWrappedPhase(double a, double b, double t) const
	{
		const double delta = wrapPhaseRadians(b - a);
		return a + delta * t;
	}

	void buildWaveformFromHarmonics(AnalysisFrame& frame) const
	{
		frame.waveform.assign((size_t) CycleSize, 0.0f);

		const int count = jmin((int) frame.harmonicGains.size(), MaxRenderablePartials);
		if (count <= 0)
			return;

		AudioSampleBuffer magnitude(1, CycleSize);
		AudioSampleBuffer phase(1, CycleSize);
		AudioSampleBuffer slice(1, CycleSize * 2);
		magnitude.clear();
		phase.clear();
		slice.clear();

		for (int h = 0; h < count; ++h)
		{
			const int binIndex = h + 1;
			if (binIndex >= CycleSize)
				break;

			magnitude.setSample(0, binIndex, frame.harmonicGains[(size_t) h] * 1024.0f);
			phase.setSample(0, binIndex, frame.harmonicPhases[(size_t) h]);
		}

		FFTHelpers::toComplexArray(phase, magnitude, slice, 0);
		juce::dsp::FFT fft((int) std::log2((double) CycleSize));
		fft.performRealOnlyInverseTransform(slice.getWritePointer(0));

		auto* src = slice.getReadPointer(0);
		frame.waveform.assign(src, src + CycleSize);

		float maxAbs = 0.0f;
		for (auto v : frame.waveform)
			maxAbs = jmax(maxAbs, std::abs(v));

		if (maxAbs > 0.0f)
		{
			const float norm = 1.0f / maxAbs;
			for (auto& v : frame.waveform)
				v *= norm;
		}
	}

	void updatePitchRatio(VoiceState& voice)
	{
		double semis = (double) voice.noteNumber - (double) rootNote;
		semis += pitchSemitones;
		voice.pitchRatio = std::pow(2.0, semis / 12.0);
	}

	void invalidateAnalysis()
	{
		cache.reset();
		state.store(AnalysisState::NotAnalysed);
		statusBuffer.setDisplayedValue((double) (int) AnalysisState::NotAnalysed);
		this->setGlobalCableValue<GlobalCables::spectral_status>(getNormalisedStateValue(AnalysisState::NotAnalysed));
	}

	void logAnalysisMessage(const String& message) const
	{
		Logger::writeToLog("[spectral_player_loris] " + message);
	}

	double getNormalisedStateValue(AnalysisState s) const
	{
		return (double) (int) s / 3.0;
	}

	void sendStatusMessage(const String& message)
	{
		this->sendDataToGlobalCable<GlobalCables::spectral_status>(message);
	}

	void failAnalysis(const String& errorMessage)
	{
		cache.reset();
		cache.lastError = errorMessage;
		state.store(AnalysisState::Error);
		statusBuffer.setDisplayedValue((double) (int) AnalysisState::Error);
		this->setGlobalCableValue<GlobalCables::spectral_status>(getNormalisedStateValue(AnalysisState::Error));
		sendStatusMessage("Analysis failed: " + errorMessage);
		logAnalysisMessage("Analysis failed: " + errorMessage);
	}

	bool cacheMatchesCurrentSample() const
	{
		return cache.valid &&
			   cache.numSourceSamples == audioFile.numSamples &&
			   cache.sampleRate == audioFile.sampleRate &&
			   cache.contentHash == computeSampleHash();
	}

	uint32 computeSampleHash() const
	{
		if (audioFile.numSamples <= 0)
			return 0;

		uint32 hash = (uint32) audioFile.numSamples ^ (uint32) audioFile.sampleRate;
		const int probeCount = jmin(16, audioFile.numSamples);

		for (int i = 0; i < probeCount; ++i)
		{
			const int idx = (probeCount > 1) ? (i * (audioFile.numSamples - 1) / (probeCount - 1)) : 0;
			float s = 0.0f;
			if (sourceSample[0].size() > idx)
				s = sourceSample[0][idx];
			hash = hash * 16777619u ^ (uint32) std::abs((int) (s * 2147483647.0f));
		}

		return hash;
	}

	void analyzeCurrentSample()
	{
		if (audioFile.numSamples <= 2 || audioFile.sampleRate <= 0.0)
		{
			failAnalysis("No sample loaded");
			return;
		}

		state.store(AnalysisState::Analysing);
		statusBuffer.setDisplayedValue((double) (int) AnalysisState::Analysing);
		this->setGlobalCableValue<GlobalCables::spectral_status>(getNormalisedStateValue(AnalysisState::Analysing));
		sendStatusMessage("Analysis started");
		cache.reset();

		cache.sampleRate = audioFile.sampleRate;
		cache.numSourceSamples = audioFile.numSamples;
		cache.partialCountHint = MaxRenderablePartials;
		cache.contentHash = computeSampleHash();

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

		tempAnalysisFile = File::getSpecialLocation(File::tempDirectory)
			.getChildFile("oi_grandad_spectral_analysis.wav");
		tempAnalysisFile.deleteFile();

		{
			std::unique_ptr<FileOutputStream> fos(tempAnalysisFile.createOutputStream());
				if (fos == nullptr)
				{
					failAnalysis("Failed to create temporary analysis file");
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
					failAnalysis("Failed to write temporary analysis file");
					return;
				}
			}

		if (lorisManager == nullptr)
			lorisManager = new hise::LorisManager(File(), [this](String m)
			{
				logAnalysisMessage("Loris: " + m);
			});

			if (lorisManager == nullptr)
			{
				failAnalysis("Failed to create Loris manager");
				return;
			}

		const double rootFrequency = 440.0 * std::pow(2.0, ((double) rootNote - 69.0) / 12.0);
		hise::LorisManager::AnalyseData analysisData;
		analysisData.file = tempAnalysisFile;
		analysisData.rootFrequency = rootFrequency;

		const int snapshotCount = 256;
		const double sampleLengthSeconds = (double) audioFile.numSamples / audioFile.sampleRate;
		double hoptime = sampleLengthSeconds / (double) snapshotCount;
		hoptime = jmax(hoptime, 1.0 / rootFrequency);
		hoptime = jmin(0.02, hoptime);

		lorisManager->set("timedomain", "0to1");
		lorisManager->set("hoptime", String(hoptime));
		lorisManager->set("croptime", String(hoptime));
		lorisManager->set("windowwidth", "0.25");
		logAnalysisMessage("Starting analysis for " + tempAnalysisFile.getFileName()
			+ " rootHz=" + String(rootFrequency, 2)
			+ " hoptime=" + String(hoptime, 6));
		sendStatusMessage("Starting analysis rootHz=" + String(rootFrequency, 2)
			+ " hoptime=" + String(hoptime, 6));
		lorisManager->analyse({ analysisData });

		cache.frames.reserve((size_t) snapshotCount);
		float globalMaxGain = 0.0f;

		for (int i = 0; i < snapshotCount; ++i)
		{
			const double t = (snapshotCount > 1) ? ((double) i / (double) (snapshotCount - 1)) : 0.0;
			auto gainsVar = lorisManager->getSnapshot(tempAnalysisFile, t, "gain");
			auto phaseVar = lorisManager->getSnapshot(tempAnalysisFile, t, "phase");
			auto bandwidthVar = lorisManager->getSnapshot(tempAnalysisFile, t, "bandwidth");

			if (i == 0)
			{
				logAnalysisMessage("Snapshot[0] gainArray=" + String(gainsVar.isArray() ? gainsVar.size() : 0)
					+ " phaseArray=" + String(phaseVar.isArray() ? phaseVar.size() : 0)
					+ " bandwidthArray=" + String(bandwidthVar.isArray() ? bandwidthVar.size() : 0));
			}

			if (!gainsVar.isArray() || gainsVar.size() == 0)
				continue;

			auto* gainsArray = gainsVar[0].getArray();
			auto* phaseArray = (phaseVar.isArray() && phaseVar.size() > 0) ? phaseVar[0].getArray() : nullptr;
			auto* bandwidthArray = (bandwidthVar.isArray() && bandwidthVar.size() > 0) ? bandwidthVar[0].getArray() : nullptr;

			if (gainsArray == nullptr || gainsArray->isEmpty())
				continue;

			const int numHarmonics = jmin((int) gainsArray->size(), MaxRenderablePartials);
			AnalysisFrame frame;
			frame.timeSeconds = t * sampleLengthSeconds;
			frame.harmonicGains.resize((size_t) numHarmonics, 0.0f);
			frame.harmonicPhases.resize((size_t) numHarmonics, 0.0f);
			frame.harmonicBandwidths.resize((size_t) numHarmonics, 0.0f);

			float phaseDelta = 0.0f;
			if (phaseArray != nullptr && phaseArray->size() > 0)
			{
				phaseDelta = -1.0f * (float) (*phaseArray)[0];
				if (phaseDelta < 0.0f)
					phaseDelta += 2.0f * MathConstants<float>::pi;
			}

			float noiseWeightedSum = 0.0f;
			float gainWeightedSum = 0.0f;

			for (int h = 0; h < numHarmonics; ++h)
			{
				const float gain = (float) (*gainsArray)[h];
				float phase = (phaseArray != nullptr && h < (int) phaseArray->size()) ? (float) (*phaseArray)[h] : 0.0f;

				if (h == 0)
				{
					phase = 0.0f;
				}
				else
				{
					const float twoPi = 2.0f * MathConstants<float>::pi;
					phase += phaseDelta * (float) (h + 1);
					phase = std::fmod(phase + MathConstants<float>::pi, twoPi);
					if (phase < 0.0f)
						phase += twoPi;
					phase -= MathConstants<float>::pi;
				}

				const float bandwidth = (bandwidthArray != nullptr && h < (int) bandwidthArray->size())
					? jlimit(0.0f, 1.0f, (float) (*bandwidthArray)[h])
					: 0.0f;

				frame.harmonicGains[(size_t) h] = gain;
				frame.harmonicPhases[(size_t) h] = phase;
				frame.harmonicBandwidths[(size_t) h] = bandwidth;
				globalMaxGain = jmax(globalMaxGain, std::abs(gain));
				noiseWeightedSum += std::abs(gain) * bandwidth;
				gainWeightedSum += std::abs(gain);
			}

			frame.noiseEnergy = (gainWeightedSum > 0.0f)
				? jlimit(0.0f, 1.0f, noiseWeightedSum / gainWeightedSum)
				: 0.0f;
			buildWaveformFromHarmonics(frame);
			cache.frames.push_back(std::move(frame));
		}

		if (cache.frames.empty())
		{
			failAnalysis("Loris analysis returned no usable snapshots");
			return;
		}

		if (globalMaxGain > 0.0f)
		{
			const float norm = 1.0f / globalMaxGain;
			for (auto& frame : cache.frames)
			{
				for (auto& gain : frame.harmonicGains)
					gain *= norm;
				buildWaveformFromHarmonics(frame);
			}
		}

		cache.laneCount = 0;
		for (const auto& frame : cache.frames)
			cache.laneCount = jmax(cache.laneCount, (int) frame.harmonicGains.size());

		auto synthBuffers = lorisManager->synthesise(tempAnalysisFile);
		if (!synthBuffers.isEmpty())
		{
			auto* left = synthBuffers[0].getBuffer();
			auto* right = synthBuffers[jmin(1, synthBuffers.size() - 1)].getBuffer();

			if (left != nullptr && left->size > 0)
			{
				cache.lorisResynthMono.resize((size_t) left->size, 0.0f);
				auto* leftSrc = left->buffer.getReadPointer(0);
				auto* rightSrc = (right != nullptr) ? right->buffer.getReadPointer(0) : leftSrc;

				for (int i = 0; i < left->size; ++i)
					cache.lorisResynthMono[(size_t) i] = 0.5f * (leftSrc[i] + rightSrc[i]);
			}
		}
	#else
			failAnalysis("Loris support is not available in this build");
			return;
	#endif

		cache.valid = true;
		state.store(AnalysisState::Ready);
		statusBuffer.setDisplayedValue((double) (int) AnalysisState::Ready);
		this->setGlobalCableValue<GlobalCables::spectral_status>(getNormalisedStateValue(AnalysisState::Ready));
		sendStatusMessage("Analysis ready: " + String(cache.frames.size()) + " frames, " + String(cache.laneCount) + " harmonics");
		logAnalysisMessage("Analysis ready: " + String(cache.frames.size()) + " frames, " + String(cache.laneCount) + " harmonics");
	}

	void buildPlaceholderCache()
	{
		cache.reset();
		cache.sampleRate = audioFile.sampleRate > 0.0 ? audioFile.sampleRate : sampleRate;
		cache.numSourceSamples = audioFile.numSamples;
		cache.partialCountHint = MaxRenderablePartials;
		cache.contentHash = computeSampleHash();

		const int frameCount = 64;
		const int framePartials = 16;
		cache.laneCount = framePartials;
		cache.laneIds.resize((size_t) cache.laneCount);
		for (int i = 0; i < cache.laneCount; ++i)
			cache.laneIds[(size_t) i] = i;
		cache.frames.reserve((size_t) frameCount);

		for (int i = 0; i < frameCount; ++i)
		{
			AnalysisFrame frame;
			double norm = (double) i / (double) jmax(1, frameCount - 1);
			frame.timeSeconds = norm * ((double) jmax(1, audioFile.numSamples) / jmax(1.0, cache.sampleRate));
			frame.noiseEnergy = 0.1f + 0.2f * (float) std::sin(norm * MathConstants<double>::twoPi);

			frame.partials.reserve((size_t) framePartials);
			frame.harmonicGains.reserve((size_t) framePartials);
			frame.harmonicPhases.reserve((size_t) framePartials);
			frame.harmonicBandwidths.reserve((size_t) framePartials);

			for (int p = 0; p < framePartials; ++p)
			{
				PartialFrame partial;
				float harmonic = (float) (p + 1);
				partial.frequencyHz = 100.0f * harmonic * (1.0f + 0.1f * (float) std::sin(norm * MathConstants<double>::twoPi * harmonic * 0.2));
				partial.amplitude = 1.0f / harmonic;
				partial.phase = 0.0f;
				partial.noisiness = jlimit(0.0f, 1.0f, 0.05f * harmonic);
				frame.partials.push_back(partial);
				frame.harmonicGains.push_back(partial.amplitude);
				frame.harmonicPhases.push_back((float) (norm * MathConstants<double>::pi * harmonic * 0.1));
				frame.harmonicBandwidths.push_back(partial.noisiness);
			}

			buildWaveformFromHarmonics(frame);

			cache.frames.push_back(std::move(frame));
		}

		cache.valid = true;
		state.store(AnalysisState::Ready);
	}

	template <typename FrameType> void renderFrame(FrameType& fd, VoiceState& voice)
	{
		voice.scrubPosition = scrub;

		if (state.load() != AnalysisState::Ready || !cache.valid || cache.frames.empty())
			return;

		if (sampleRate <= 0.0)
			return;

		double framePos = scrub * (double) jmax(1, (int) cache.frames.size() - 1);
		int frameA = jlimit(0, (int) cache.frames.size() - 1, (int) std::floor(framePos));
		int frameB = jlimit(0, (int) cache.frames.size() - 1, frameA + 1);
		double frameT = framePos - (double) frameA;

		const auto& a = cache.frames[(size_t) frameA];
		const auto& b = cache.frames[(size_t) frameB];
		if (a.waveform.empty() || b.waveform.empty())
			return;

		const double rootFrequency = 440.0 * std::pow(2.0, ((double) rootNote - 69.0) / 12.0);
		const double oscFrequency = rootFrequency * voice.pitchRatio;

		if (debugMode >= 1.5 && !cache.lorisResynthMono.empty())
		{
			const double scrubJump = std::abs(scrub - voice.lastScrubPosition);
			if (voice.lastScrubPosition < 0.0 || scrubJump > 0.002)
			{
				const double maxPos = (double) jmax(0, (int) cache.lorisResynthMono.size() - 1);
				voice.resynthReadPos = scrub * maxPos;
			}

			voice.lastScrubPosition = scrub;
			const double increment = jmax(0.125, voice.pitchRatio);
			const double maxPos = (double) cache.lorisResynthMono.size();
			const double pos = std::fmod(voice.resynthReadPos, maxPos);
			const int i0 = jlimit(0, (int) cache.lorisResynthMono.size() - 1, (int) std::floor(pos));
			const int i1 = (i0 + 1) % (int) cache.lorisResynthMono.size();
			const double t = pos - std::floor(pos);
			const double s0 = cache.lorisResynthMono[(size_t) i0];
			const double s1 = cache.lorisResynthMono[(size_t) i1];
			const float s = (float) jlimit(-0.8, 0.8, s0 + (s1 - s0) * t);
			voice.resynthReadPos += increment;
			fd[0] += s;
			fd[1] += s;
			return;
		}

		voice.oscillatorPhase = wrap01(voice.oscillatorPhase + oscFrequency / sampleRate);

		const int harmonicLimit = jmin(jlimit(1, MaxRenderablePartials, (int) partialCount),
									   jmin((int) a.harmonicGains.size(), (int) b.harmonicGains.size()));

		double harmonicEnergy = 0.0;
		double selectedEnergy = 0.0;
		for (int i = 0; i < harmonicLimit; ++i)
		{
			const double ga = std::abs(a.harmonicGains[(size_t) i]);
			const double gb = std::abs(b.harmonicGains[(size_t) i]);
			selectedEnergy += (1.0 - frameT) * ga + frameT * gb;
		}

		for (int i = 0; i < jmin((int) a.harmonicGains.size(), (int) b.harmonicGains.size()); ++i)
		{
			const double ga = std::abs(a.harmonicGains[(size_t) i]);
			const double gb = std::abs(b.harmonicGains[(size_t) i]);
			harmonicEnergy += (1.0 - frameT) * ga + frameT * gb;
		}

		const double partialWeight = (harmonicEnergy > 0.0)
			? jlimit(0.0, 1.0, selectedEnergy / harmonicEnergy)
			: 1.0;

		const double phasePos = voice.oscillatorPhase * (double) CycleSize;
		const int i0 = ((int) std::floor(phasePos)) % CycleSize;
		const int i1 = (i0 + 1) % CycleSize;
		const double sampleT = phasePos - std::floor(phasePos);

		const double wa0 = a.waveform[(size_t) i0];
		const double wa1 = a.waveform[(size_t) i1];
		const double wb0 = b.waveform[(size_t) i0];
		const double wb1 = b.waveform[(size_t) i1];

		const double sampleA = wa0 + (wa1 - wa0) * sampleT;
		const double sampleB = wb0 + (wb1 - wb0) * sampleT;
		double sum = sampleA + (sampleB - sampleA) * frameT;

		if (debugMode < 0.5)
			sum *= partialWeight * (0.35 + 0.65 * partialBlend);

		double noiseAmt = ((1.0 - frameT) * a.noiseEnergy + frameT * b.noiseEnergy) * noiseBlend * 0.01;
		voice.noiseState = voice.noiseState * 1664525u + 1013904223u;
		double white = ((double) ((voice.noiseState >> 8) & 0x00ffffff) / 8388607.5) - 1.0;
		if (debugMode < 0.5)
			sum += white * noiseAmt;

		float s = (float) jlimit(-0.8, 0.8, sum);
		voice.lastScrubPosition = scrub;
		fd[0] += s;
		fd[1] += s;
	}

	ExternalData audioFile;
	ExternalData statusBuffer;
	PolyData<VoiceState, NV> voiceStates;
	std::array<block, 2> sourceSample {};
	SpectralAnalysisCache cache;
	std::atomic<AnalysisState> state { AnalysisState::NotAnalysed };

	double sampleRate = 0.0;
	int blockSize = 0;
	double scrub = 0.0;
	double pitchSemitones = 0.0;
	double partialBlend = 1.0;
	double noiseBlend = 0.0;
	double partialCount = 64.0;
	double debugMode = 0.0;
	int rootNote = 60;
	double analyzeTrigger = 0.0;
	File tempAnalysisFile;
#if HISE_INCLUDE_LORIS
	hise::LorisManager::Ptr lorisManager;
#endif
};

} // namespace project
