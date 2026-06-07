/*
    Minimal third-party polyphonic sine probe.

    This node exists only to verify whether the compiled scriptnode shell can
    run a trivial per-voice polyphonic source cleanly in the current runtime.
*/

#pragma once

#include <array>
#include <cmath>

namespace project
{
using namespace juce;
using namespace hise;
using namespace scriptnode;

template <int NV> struct poly_sine_probe : public data::base
{
	SNEX_NODE(poly_sine_probe);

	struct MetadataClass
	{
		SN_NODE_ID("poly_sine_probe");
	};

	static constexpr bool isModNode() { return false; }
	static constexpr bool isPolyphonic() { return NV > 1; }
	static constexpr bool hasTail() { return false; }
	static constexpr bool isSuspendedOnSilence() { return false; }
	static constexpr int getFixChannelAmount() { return 2; }

	static constexpr int NumTables = 0;
	static constexpr int NumSliderPacks = 0;
	static constexpr int NumAudioFiles = 0;
	static constexpr int NumFilters = 0;
	static constexpr int NumDisplayBuffers = 0;

	struct VoiceState
	{
		bool active = false;
		int noteNumber = 60;
		double phase = 0.0;
		double delta = 0.0;

		void reset()
		{
			active = false;
			noteNumber = 60;
			phase = 0.0;
			delta = 0.0;
		}
	};

	void prepare(PrepareSpecs ps)
	{
		sampleRate = ps.sampleRate;
		blockSize = ps.blockSize;
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
	}

	template <typename FrameDataType> void processFrame(FrameDataType& data)
	{
		auto& voice = voiceStates.get();
		auto& fixFrame = span<float, 2>::as(data.begin());
		renderFrame(fixFrame, voice);
	}

	void handleHiseEvent(HiseEvent& e)
	{
		if (!e.isNoteOn())
			return;

		auto& voice = voiceStates.get();
		voice.reset();
		voice.active = true;
		voice.noteNumber = e.getNoteNumber();
		updateDelta(voice);
	}

	template <int P> void setParameter(double v)
	{
		if (P == 0)
			level = jlimit(0.0, 1.0, v);
		if (P == 1)
			pitchSemitones = jlimit(-24.0, 24.0, v);
	}

	void createParameters(ParameterDataList& data)
	{
		addParameter<0>(data, "Level", 0.0, 1.0, 0.15);
		addParameter<1>(data, "PitchSemitones", -24.0, 24.0, 0.0);
	}

	template <int P> void addParameter(ParameterDataList& data, const char* id, double min, double max, double defaultValue)
	{
		parameter::data p(id, { min, max });
		registerCallback<P>(p);
		p.setDefaultValue(defaultValue);
		data.add(std::move(p));
	}

	void updateDelta(VoiceState& voice)
	{
		const double semis = ((double) voice.noteNumber - 69.0) + pitchSemitones;
		const double frequency = 440.0 * std::pow(2.0, semis / 12.0);
		voice.delta = MathConstants<double>::twoPi * frequency / jmax(1.0, sampleRate);
	}

	template <typename FrameType> void renderFrame(FrameType& fd, VoiceState& voice)
	{
		if (!voice.active)
			return;

		voice.phase += voice.delta;
		if (voice.phase >= MathConstants<double>::twoPi)
			voice.phase = std::fmod(voice.phase, MathConstants<double>::twoPi);

		const float s = (float) (std::sin(voice.phase) * level);
		fd[0] += s;
		fd[1] += s;
	}

	PolyData<VoiceState, NV> voiceStates;
	double sampleRate = 44100.0;
	int blockSize = 0;
	double level = 0.15;
	double pitchSemitones = 0.0;
};

} // namespace project
