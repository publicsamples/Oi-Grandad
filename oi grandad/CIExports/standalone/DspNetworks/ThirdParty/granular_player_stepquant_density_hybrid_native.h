/*
    Third-party C++ scriptnode shell for porting:
    CodeLibrary/snex_node/granular_player_stepquant_density_hybrid.h

    This is intentionally a wrapper shell first. It establishes the correct
    third-party node structure, parameters, audiofile slot, and polyphonic
    state so the DSP core can be moved over incrementally without patching HISE.
*/

#pragma once

#include <array>
#include <cmath>
#include <cstdint>

namespace project
{
using namespace juce;
using namespace hise;
using namespace scriptnode;

template <int NV> struct granular_player_stepquant_density_hybrid_native : public data::base
{
	SNEX_NODE(granular_player_stepquant_density_hybrid_native);

	struct MetadataClass
	{
		SN_NODE_ID("granular_player_stepquant_density_hybrid_native");
	};

	static constexpr bool isModNode() { return false; }
	static constexpr bool isPolyphonic() { return NV > 1; }
	static constexpr bool hasTail() { return false; }
	static constexpr bool isSuspendedOnSilence() { return false; }
	static constexpr int getFixChannelAmount() { return 2; }

	static constexpr int NumTables = 0;
	static constexpr int NumSliderPacks = 1;
	static constexpr int NumAudioFiles = 1;
	static constexpr int NumFilters = 0;
	static constexpr int NumDisplayBuffers = 0;

	static constexpr int NumChannels = 2;
	static constexpr int MaxGrains = 32;
	static constexpr int MaxSourceChannels = 32;
	static constexpr int MaxStereoPairs = 16;
	static constexpr double DensityPositionSpreadRange = 0.3;

	struct GrainState
	{
		double phase = 0.0;
		double readPhase = 0.0;
		double start = 0.0;
		double latchedStart = 0.0;
		double scatterOffset = 0.0;
		double fadePhase = 0.0;
		double fadeReadPhase = 0.0;
		double fadeStart = 0.0;
		double fadeGrainSize = 0.0;
		double fadeWindowSize = 0.0;
		double fadeDurationSeconds = 0.01;
		double wrapFade = 0.0;
		double morphCellBase = 0.0;
		double morphCellSize = 0.0;
		double morphCellAStart = 0.0;
		double morphCellBStart = 0.0;
		double morphScatterOffset = 0.0;
		double morphMaxStart = 0.0;
		bool fadeIsOneShot = false;
		bool morphCellsValid = false;
		int respawnCount = 0;
		bool active = false;

		void reset()
		{
			phase = 0.0;
			readPhase = 0.0;
			start = 0.0;
			latchedStart = 0.0;
			scatterOffset = 0.0;
			fadePhase = 0.0;
			fadeReadPhase = 0.0;
			fadeStart = 0.0;
			fadeGrainSize = 0.0;
			fadeWindowSize = 0.0;
			fadeDurationSeconds = 0.01;
			wrapFade = 0.0;
			morphCellBase = 0.0;
			morphCellSize = 0.0;
			morphCellAStart = 0.0;
			morphCellBStart = 0.0;
			morphScatterOffset = 0.0;
			morphMaxStart = 0.0;
			fadeIsOneShot = false;
			morphCellsValid = false;
			respawnCount = 0;
			active = false;
		}
	};

	struct VoiceState
	{
		double scanPos = 0.0;
		double stretchBasePos = -1.0;
		double delta = 1.0;
		double deltaTarget = 1.0;
		double noteAgeSamples = 0.0;
		int noteNumber = 60;
		double scrubQ = 0.0;
		double modeAnchorScrub = -1.0;
		double lastPhaseScatter = -1.0;
		double lastScatterMaxStart = -1.0;
		std::array<double, 4> previousScrubSource {};
		std::array<int, 4> previousOneShotStep {};
		double densityMorphSmoothed = -1.0;
		double cloudMixSmoothed = -1.0;
		double speedPhase = 0.0;
		double ap1L = 0.0;
		double ap1R = 0.0;
		double ap2L = 0.0;
		double ap2R = 0.0;
		std::array<GrainState, MaxGrains> grains {};

		void reset()
		{
			scanPos = 0.0;
			stretchBasePos = -1.0;
			delta = 1.0;
			deltaTarget = 1.0;
			noteAgeSamples = 0.0;
			noteNumber = 60;
			scrubQ = 0.0;
			modeAnchorScrub = -1.0;
			lastPhaseScatter = -1.0;
			lastScatterMaxStart = -1.0;
			previousScrubSource = { 0.0, 0.0, 0.0, 0.0 };
			previousOneShotStep = { -1, -1, -1, -1 };
			densityMorphSmoothed = -1.0;
			cloudMixSmoothed = -1.0;
			speedPhase = 0.0;
			ap1L = 0.0;
			ap1R = 0.0;
			ap2L = 0.0;
			ap2R = 0.0;

			for (auto& grain : grains)
				grain.reset();
		}
	};

	template <typename T> void resetVoiceContainer(T& container)
	{
		for (auto& voice : container)
			voice.reset();
	}

	void reseedVoiceAfterGrainSizeLimit(VoiceState& voice)
	{
		// Keep the held note and pitch state, but discard grain phases that were
		// expressed against the previous source-length-limited grain duration.
		voice.stretchBasePos = -1.0;
		voice.modeAnchorScrub = -1.0;
		voice.lastPhaseScatter = -1.0;
		voice.lastScatterMaxStart = -1.0;
		voice.previousScrubSource = { 0.0, 0.0, 0.0, 0.0 };
		voice.previousOneShotStep = { -1, -1, -1, -1 };

		for (auto& grain : voice.grains)
			grain.reset();
	}

	void prepare(PrepareSpecs ps)
	{
		sampleRate = ps.sampleRate;
		blockSize = ps.blockSize;
		voiceStates.prepare(ps);
		updateGrainSize();
		reset();
	}

	void reset()
	{
		resetVoiceContainer(voiceStates);
	}

	bool hasValidSourceData() const
	{
		if (audioFile.numSamples <= 1)
			return false;

		if (sourceSample[0].size() <= 1)
			return false;

		return true;
	}

	template <typename ProcessDataType> void process(ProcessDataType& data)
	{
		if (!hasValidSourceData())
		{
			reset();
			return;
		}

		auto audioLock = DataTryReadLock(audioFile);
		if (!audioLock)
		{
			reset();
			return;
		}

		auto& fixData = data.template as<ProcessData<2>>();
		auto fd = fixData.toFrameData();
		auto& voice = voiceStates.get();

		while (fd.next())
			renderFrame(fd.toSpan(), voice);

		audioFile.setDisplayedValue(voice.scanPos);
	}

	template <typename FrameDataType> void processFrame(FrameDataType& data)
	{
		if (!hasValidSourceData())
		{
			reset();
			return;
		}

		auto audioLock = DataTryReadLock(audioFile);
		if (!audioLock)
		{
			reset();
			return;
		}

		auto& voice = voiceStates.get();
		auto& fixFrame = span<float, 2>::as(data.begin());
		renderFrame(fixFrame, voice);
		audioFile.setDisplayedValue(voice.scanPos);
	}

	void handleHiseEvent(HiseEvent& e)
	{
		if (!e.isNoteOn())
			return;

		auto& voice = voiceStates.get();
		double previousDelta = voice.delta;
		voice.reset();
		voice.noteNumber = e.getNoteNumber();
		voice.scrubQ = scrub;
		if (getGlideTimeSeconds() > 0.0001)
			voice.delta = previousDelta;
		updateDelta(voice);
	}

	void setExternalData(const ExternalData& data, int index)
	{
		if (auto sp = dynamic_cast<SliderPackData*>(data.obj))
		{
			sp->setNumSliders(8);
			data.referBlockTo(modePack, 0);
			return;
		}

		if (index != 0)
			return;

		audioFile = data;
		int detectedChannels = 0;

		for (int ch = 0; ch < MaxSourceChannels; ++ch)
		{
			data.referBlockTo(sourceSample[(size_t) ch], ch);
			if (sourceSample[(size_t) ch].size() > 1)
				detectedChannels = ch + 1;
		}

		if (detectedChannels < 1)
			detectedChannels = 1;
		if (detectedChannels > 1 && (detectedChannels % 2) != 0)
			--detectedChannels;

		sourceChannelCount = detectedChannels;
		sourcePairCount = (sourceChannelCount > 1) ? (sourceChannelCount / 2) : 1;
		if (sourcePairCount < 1)
			sourcePairCount = 1;
		if (sourcePairCount > MaxStereoPairs)
			sourcePairCount = MaxStereoPairs;

		updateGrainSize();
		reset();
	}

	template <int P> void setParameter(double v)
	{
		if (P == 0)
		{
			pitchSemitones = v;
			for (auto& voice : voiceStates)
				updateDelta(voice);
		}

		if (P == 1) scrub = v;

		if (P == 2)
		{
			// Grain duration can be driven beyond the UI range by tempo sync, but a
			// malformed upstream value must not poison the live grain state.
			if (!std::isfinite(v))
				return;

			const bool wasSourceLimited = grainSizeIsSourceLimited;
			grainMs = jmax(1.0, v);
			updateGrainSize();

			if (wasSourceLimited && !grainSizeIsSourceLimited)
			{
				for (auto& voice : voiceStates)
					reseedVoiceAfterGrainSizeLimit(voice);
			}
		}

		if (P == 3) density = clamp01(v);
		if (P == 4) windowShape = clamp01(v);
		if (P == 5) panSpread = clamp01(v);

		if (P == 6) respawn = clamp01(v);

		if (P == 7)
			pitchSpread = clamp01(v);

		if (P == 8)
			maxGrainsValue = jlimit(1.0, (double) MaxGrains, v);
		if (P == 9) diffusion = clamp01(v);
		if (P == 10) cloudAmount = clamp01(v);

		if (P == 11)
		{
			directionMode = decodeMenuValue(v, 4);
		}

		if (P == 12) phaseScatter = clamp01(v);
		if (P == 13) scrubB = v;
		if (P == 14) scrubC = v;
		if (P == 15) scrubD = v;
		if (P == 16) bloomDuration = v;
		if (P == 17) pitchSyncInput = v;
	}

	void createParameters(ParameterDataList& data)
	{
		addParameter<0>(data, "PitchSemitones", -12.0, 12.0, 0.0);
		addParameter<1>(data, "Scrub", 0.0, 1.0, 0.0);
		addParameter<2>(data, "GrainMs", 1.0, 500.0, 50.0);
		addParameter<3>(data, "Density", 0.0, 1.0, 1.0);
		addParameter<4>(data, "WindowShape", 0.0, 1.0, 0.0);
		addParameter<5>(data, "PanSpread", 0.0, 1.0, 0.0);
		addParameter<6>(data, "Respawn", 0.0, 1.0, 0.0);
		addParameter<7>(data, "PitchSpread", 0.0, 1.0, 0.0);
		addParameter<8>(data, "MaxGrains", 1.0, 32.0, 4.0);
		addParameter<9>(data, "Diffusion", 0.0, 1.0, 0.0);
		addParameter<10>(data, "CloudAmount", 0.0, 1.0, 0.0);
		addParameter<11>(data, "DirectionMode", 1.0, 4.0, 1.0);
		addParameter<12>(data, "PhaseScatter", 0.0, 1.0, 0.0);
		addParameter<13>(data, "ScrubB", 0.0, 1.0, 0.0);
		addParameter<14>(data, "ScrubC", 0.0, 1.0, 0.0);
		addParameter<15>(data, "ScrubD", 0.0, 1.0, 0.0);
		addParameter<16>(data, "BloomDuration", 1.0, 500.0, 250.0);
		addParameter<17>(data, "PitchSyncInput", 1.0, 2000.0, 500.0);
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

	double decodeMenuValue(double v, int maxValue) const
	{
		return jlimit(1.0, (double) maxValue, std::round(v));
	}

	double getModePackValue(int index, double fallback) const
	{
		if (index >= 0 && index < modePack.size())
			return clamp01(modePack[(size_t) index]);

		return fallback;
	}

	double decodeModePackMenuValue(int index, int maxValue, double fallback) const
	{
		double value = getModePackValue(index, fallback);
		return decodeMenuValue(1.0 + value * (double) (maxValue - 1), maxValue);
	}

	double smooth01(double x) const
	{
		x = clamp01(x);
		return x * x * (3.0 - 2.0 * x);
	}

	double hann(double x) const
	{
		return 0.5 - 0.5 * std::cos(2.0 * MathConstants<double>::pi * x);
	}

	double tukey(double x, double alpha) const
	{
		x = clamp01(x);
		if (alpha <= 0.0) return 1.0;
		if (alpha >= 1.0) return hann(x);

		double edge = 0.5 * alpha;
		if (x < edge)
		{
			double t = x / edge;
			return 0.5 - 0.5 * std::cos(MathConstants<double>::pi * t);
		}
		if (x > (1.0 - edge))
		{
			double t = (1.0 - x) / edge;
			return 0.5 - 0.5 * std::cos(MathConstants<double>::pi * t);
		}

		return 1.0;
	}

	double morphedWindow(double phaseNorm) const
	{
		double x = clamp01(phaseNorm);
		double shape = clamp01(windowShape);

		auto smoothRamp = [&](double phase) -> double
		{
			return 0.5 - 0.5 * std::cos(MathConstants<double>::pi * clamp01(phase));
		};

		auto softGate = [&](double edge, double releaseStart) -> double
		{
			edge = jlimit(0.0001, 0.25, edge);
			releaseStart = jlimit(edge, 1.0, releaseStart);

			if (x < edge)
				return smoothRamp(x / edge);

			if (x <= releaseStart)
				return 1.0;

			double tailLen = jmax(edge, 1.0 - releaseStart);
			return 1.0 - smoothRamp((x - releaseStart) / tailLen);
		};

		if (shape <= 0.5)
		{
			double t = shape * 2.0;
			double triangle = 1.0 - std::abs(2.0 * x - 1.0);
			double gateEdge = 0.003 + 0.009 * t;
			double gate = softGate(gateEdge, 1.0 - gateEdge);
			return triangle + (gate - triangle) * t;
		}

		double releaseNorm = (shape - 0.5) * 2.0;
		double releaseStart = 1.0 - releaseNorm;
		if (releaseStart <= 0.0)
			return 1.0 - x;

		double releaseEdge = 0.004 + 0.008 * (1.0 - releaseNorm);
		return softGate(releaseEdge, releaseStart);
	}

	double getOneShotTailFactor() const
	{
		double shape = clamp01(windowShape);
		if (shape <= 0.5)
			return 0.0;

		return (shape - 0.5) * 2.0;
	}

	double A2curve(double x) const
	{
		double base = (1.0 - x);
		base = base * base * (1.0 - 0.5 * x);
		return (base * -1.0) + x;
	}

	double wrap01(double x) const
	{
		x = x - std::floor(x);
		if (x < 0.0)
			x += 1.0;
		return x;
	}

	double grainRandom01(int grainIndex) const
	{
		uint32_t seed = (uint32_t) (grainIndex + 1) * 0x9E3779B9u + 0xA511E9B3u;
		return hashToUnitFloat(seed);
	}

	double grainRandomFromSeed(double seed) const
	{
		double clamped = seed;
		if (clamped > 2147483647.0) clamped = 2147483647.0;
		if (clamped < -2147483647.0) clamped = -2147483647.0;
		int64_t scaled = (int64_t) std::llround(clamped * 65536.0);
		uint64_t bits = (uint64_t) scaled;
		uint32_t mixed = (uint32_t) bits ^ (uint32_t) (bits >> 32);
		return hashToUnitFloat(mixed);
	}

	double hashToUnitFloat(uint32_t x) const
	{
		x ^= x >> 16;
		x *= 0x7feb352du;
		x ^= x >> 15;
		x *= 0x846ca68bu;
		x ^= x >> 16;
		return (double) (x & 0x00FFFFFFu) / (double) 0x01000000u;
	}

	double startSprayOffsetSamples(int grainIndex, double maxStart) const
	{
		if (phaseScatter <= 0.0 || maxStart <= 0.0)
			return 0.0;

		double maxSpray = maxStart * DensityPositionSpreadRange * clamp01(phaseScatter);
		double hardLimit = maxStart * 0.95;
		if (maxSpray > hardLimit)
			maxSpray = hardLimit;

		double r = grainRandom01(grainIndex) * 2.0 - 1.0;
		return r * maxSpray;
	}

	double panOrderIndex(int grainIndex, int grainCount) const
	{
		if (grainCount <= 1)
			return 0.0;

		int pairIndex = grainIndex / 2;
		if ((grainIndex % 2) == 0)
			return (double) pairIndex;

		return (double) (grainCount - 1 - pairIndex);
	}

	double getDirectionSign(int directionState, int grainIndex) const
	{
		if (directionState == 0)
			return 1.0;
		if (directionState == 1)
			return -1.0;

		return ((grainIndex % 2) == 1) ? -1.0 : 1.0;
	}

	void updateGrainSize()
	{
		grainSizeIsSourceLimited = false;

		if (sampleRate <= 0.0)
			return;

		const double minSamples = jmax(16.0, sampleRate * 0.001);
		grainSize = grainMs * sampleRate * 0.001;

		if (!std::isfinite(grainSize) || grainSize < minSamples)
			grainSize = minSamples;

		double maxAllowed = (double) audioFile.numSamples - 2.0;
		if (maxAllowed > minSamples && grainSize > maxAllowed)
		{
			grainSize = maxAllowed;
			grainSizeIsSourceLimited = true;
		}
	}

	void updateDelta(VoiceState& voice)
	{
		double mult = 1.0;

		if (getPitchSyncEnabled())
		{
			mult = tempoSyncRatioFromInput(pitchSyncInput);
		}
		else
		{
			double semis = (double) voice.noteNumber - (double) rootNote;
			semis += pitchSemitones;
			mult = std::pow(2.0, semis / 12.0);
		}

		if (sampleRate > 0.0)
			voice.deltaTarget = (audioFile.sampleRate / sampleRate) * mult;
		else
			voice.deltaTarget = mult;

		if (getGlideTimeSeconds() <= 0.0001)
			voice.delta = voice.deltaTarget;
	}

	double quantiseScrub(double raw) const
	{
		if (scrubStepCount <= 1)
			return raw;

		if (!hasValidSourceData())
			return raw;

		double step = 1.0 / (double) scrubStepCount;
		return step * std::floor(raw / step);
	}

	double tempoSyncRatioFromInput(double x) const
	{
		if (x <= 0.0)
			return 1.0;

		double hz = x;
		if (x > 20.0)
			hz = 1000.0 / x;

		const double syncReferenceHz = 2.0;
		double ratio = hz / syncReferenceHz;

		if (ratio < 0.125) ratio = 0.125;
		if (ratio > 8.0) ratio = 8.0;
		return ratio;
	}

	double getGlideTimeSeconds() const
	{
		return getModePackValue(5, 0.0) * 0.5;
	}

	bool getPitchSyncEnabled() const
	{
		return decodeModePackMenuValue(4, 2, 0.0) > 1.5;
	}

	int getPitchState()
	{
		return jlimit(0, 7, (int)std::round(decodeModePackMenuValue(0, 8, 0.0)) - 1);
	}

	void updateGlideSmoothing(VoiceState& voice)
	{
		double glideTime = getGlideTimeSeconds();
		if (glideTime <= 0.0001 || sampleRate <= 0.0)
		{
			voice.delta = voice.deltaTarget;
			return;
		}

		double smoothCoeff = 1.0 - std::exp(-1.0 / (glideTime * sampleRate));
		voice.delta += (voice.deltaTarget - voice.delta) * smoothCoeff;
	}

	double getPitchModeMul(int pitchState, double spreadNorm, double detuneSinValue, double harmonicTarget) const
	{
		if (pitchState == 0)
		{
			double spread = std::pow(clamp01(pitchSpread), 2.5) * spreadNorm;
			return 1.0 + spread * detuneSinValue;
		}
		else if (pitchState == 1)
		{
			return 1.0 + (harmonicTarget - 1.0) * pitchSpread;
		}
		else if (pitchState == 2)
		{
			static constexpr int majorSteps[] = { 0, 2, 4, 5, 7, 9, 11, 12, 14, 16, 17, 19, 21, 23, 24 };
			return getScaleModeMul(majorSteps, (int)(sizeof(majorSteps) / sizeof(majorSteps[0])), harmonicTarget);
		}
		else if (pitchState == 3)
		{
			static constexpr int minorSteps[] = { 0, 2, 3, 5, 7, 8, 10, 12, 14, 15, 17, 19, 20, 22, 24 };
			return getScaleModeMul(minorSteps, (int)(sizeof(minorSteps) / sizeof(minorSteps[0])), harmonicTarget);
		}
		else if (pitchState == 4)
		{
			static constexpr int maj7Steps[] = { 0, 4, 7, 11, 12, 16, 19, 23, 24 };
			return getScaleModeMul(maj7Steps, (int)(sizeof(maj7Steps) / sizeof(maj7Steps[0])), harmonicTarget);
		}
		else if (pitchState == 5)
		{
			static constexpr int min7Steps[] = { 0, 3, 7, 10, 12, 15, 19, 22, 24 };
			return getScaleModeMul(min7Steps, (int)(sizeof(min7Steps) / sizeof(min7Steps[0])), harmonicTarget);
		}
		else if (pitchState == 6)
		{
			static constexpr int fifthSteps[] = { 0, 7, 12, 19, 24 };
			return getScaleModeMul(fifthSteps, (int)(sizeof(fifthSteps) / sizeof(fifthSteps[0])), harmonicTarget);
		}
		else if (pitchState == 7)
		{
			static constexpr int seventhSteps[] = { 0, 10, 12, 22, 24 };
			return getScaleModeMul(seventhSteps, (int)(sizeof(seventhSteps) / sizeof(seventhSteps[0])), harmonicTarget);
		}

		return 1.0;
	}

	double getScaleModeMul(const int* semitoneSteps, int numSteps, double harmonicTarget) const
	{
		if (numSteps <= 0)
			return 1.0;

		double x = clamp01(pitchSpread);
		int activeCount = 1 + (int)std::floor(x * (double)(numSteps - 1) + 0.000001);
		if (activeCount < 1) activeCount = 1;
		if (activeCount > numSteps) activeCount = numSteps;

		int grainIndex = jmax(0, (int)std::round(harmonicTarget) - 1);
		int stepIndex = grainIndex % activeCount;
		return getScaleRatioFromSemitones(semitoneSteps[stepIndex]);
	}

	double getGrainWeight(int i, int grainCount, bool isStackMode, double densityValue) const
	{
		if (i < 0 || i >= grainCount)
			return 0.0;

		if (!isStackMode)
			return 1.0;

		if (grainCount <= 1)
			return 1.0;

		double d = clamp01(densityValue);
		double coverage = 1.0 + d * (double) (grainCount - 1);
		if (coverage > (double) grainCount)
			coverage = (double) grainCount;

		const double floorWeight = 0.06;
		double edge = coverage - (double) i;
		if (edge <= 0.0)
			return floorWeight;
		if (edge >= 1.0)
			return 1.0;

		return floorWeight + (1.0 - floorWeight) * smooth01(edge);
	}

	int getPlayheadModeState() const
	{
		return jlimit(0, 1, (int)std::round(getModePackValue(1, 0.0)));
	}

	int getPhaseScatterShapeState() const
	{
		return jlimit(1, 4, (int)std::round(decodeModePackMenuValue(6, 4, 0.0)));
	}

	int getGrainTravelShapeState() const
	{
		return jlimit(1, 5, (int)std::round(decodeModePackMenuValue(7, 5, 0.0)));
	}

	void getPlaybackPresetState(int& transportState, bool& stretchEnabled, bool& legacyExact, bool& legacyWrapFade,
		bool& cloudMode, bool& microSliceMode, bool& microSliceMorphMode, bool& safeStartMode) const
	{
		int mode = jlimit(1, 5, (int)std::round(decodeModePackMenuValue(3, 5, 0.0)));
		stretchEnabled = true;
		legacyWrapFade = false;
		legacyExact = false;
		cloudMode = false;
		microSliceMode = false;
		microSliceMorphMode = false;
		safeStartMode = false;

		switch (mode)
		{
			case 1: // Default
				transportState = 2;
				stretchEnabled = true;
				legacyExact = true;
				legacyWrapFade = true;
				break;
			case 2: // Cloud
				transportState = 2;
				stretchEnabled = true;
				cloudMode = true;
				break;
			case 3: // Microslice
				transportState = 2;
				stretchEnabled = false;
				microSliceMode = true;
				break;
			case 4: // Microslice Morph
				transportState = 2;
				stretchEnabled = false;
				microSliceMode = true;
				microSliceMorphMode = true;
				break;
			case 5: // Safe Start
			default:
				transportState = 2;
				stretchEnabled = true;
				legacyExact = true;
				legacyWrapFade = true;
				safeStartMode = true;
				break;
		}
	}

	double quantiseSliceBase(double base, double localGrainSize, double localMaxStart) const
	{
		if (localGrainSize <= 1.0)
			return jlimit(0.0, localMaxStart, base);

		double slice = std::floor(base / localGrainSize) * localGrainSize;
		return jlimit(0.0, localMaxStart, slice);
	}

	bool isQStyleReadMode(int readState) const
	{
		return readState >= 2;
	}

	double getGrainTravelSizeScale(int grainIndex, int grainCount) const
	{
		double minSamples = jmax(16.0, sampleRate * 0.001);
		double minScale = grainSize > minSamples ? (minSamples / grainSize) : 1.0;
		minScale = jlimit(0.0, 1.0, minScale);

		double random01 = grainRandom01(grainIndex);
		double ordered01 = grainCount > 1 ? (double) grainIndex / (double) (grainCount - 1) : 0.5;
		double mirrored01 = 0.5;

		if (grainCount > 1)
		{
			int pairIndex = grainIndex / 2;
			int pairCount = (grainCount + 1) / 2;
			double shell = pairCount > 1 ? (double) pairIndex / (double) (pairCount - 1) : 0.0;
			double signedShell = ((grainIndex % 2) == 0 ? -1.0 : 1.0) * shell;
			mirrored01 = 0.5 + 0.5 * signedShell;
		}

		double clustered01 = wrap01(0.5 + (random01 - 0.5) * 0.35);
		double shape01 = 0.5;

		switch (getGrainTravelShapeState())
		{
			case 2: // Random
				return minScale + (1.0 - minScale) * random01;
				break;
			case 3: // Spread
			{
				double orderedScale = grainCount > 0 ? (double) (grainIndex + 1) / (double) grainCount : 1.0;
				return jmax(minScale, orderedScale);
			}
				break;
			case 4: // Mirror
				shape01 = mirrored01;
				break;
			case 5: // Cluster
				shape01 = clustered01;
				break;
			case 1: // Fixed
			default:
				shape01 = 0.5;
				break;
		}

		return 0.5 + shape01;
	}

	double getEffectiveGrainSize(int grainIndex, int grainCount) const
	{
		double localGrainSize = grainSize * getGrainTravelSizeScale(grainIndex, grainCount);
		if (localGrainSize < 16.0)
			localGrainSize = 16.0;

		double maxAllowed = (double) audioFile.numSamples - 2.0;
		if (maxAllowed > 16.0 && localGrainSize > maxAllowed)
			localGrainSize = maxAllowed;

		return localGrainSize;
	}

	double getSchedulerPhaseOffset(int grainIndex, int grainCount, double localGrainSize) const
	{
		if (grainCount <= 0)
			return 0.0;

		double ordered01 = grainCount > 1 ? (double) grainIndex / (double) (grainCount - 1) : 0.0;
		return ordered01 * localGrainSize;
	}

	double getInitialSchedulerPhase(int grainIndex, int grainCount, bool stretchMode, double localGrainSize) const
	{
		ignoreUnused(stretchMode);
		return getSchedulerPhaseOffset(grainIndex, grainCount, localGrainSize);
	}

	double getBloomDurationSeconds() const
	{
		return jmax(1.0, bloomDuration) * 0.001;
	}

	double getCloudTransitionCoeff() const
	{
		if (sampleRate <= 0.0)
			return 1.0;

		double seconds = getBloomDurationSeconds();
		if (seconds <= 0.001)
			return 1.0;

		return 1.0 - std::exp(-1.0 / (seconds * sampleRate));
	}

	double getCloudMix(VoiceState& voice) const
	{
		double target = clamp01(cloudAmount);
		if (target <= 0.0)
		{
			voice.cloudMixSmoothed = 0.0;
			return 0.0;
		}

		if (voice.cloudMixSmoothed < 0.0)
			voice.cloudMixSmoothed = 0.0;

		double coeff = getCloudTransitionCoeff();
		voice.cloudMixSmoothed += (target - voice.cloudMixSmoothed) * coeff;
		return clamp01(voice.cloudMixSmoothed);
	}

	double getCloudPhaseOffset(const VoiceState& voice, int grainIndex, double localGrainSize, double cloudMix) const
	{
		if (cloudMix <= 0.0 || localGrainSize <= 0.0)
			return 0.0;

		double signedRand = grainRandomFromSeed((double) (grainIndex + 1) * 41.17 + (double) voice.noteNumber * 3.71) * 2.0 - 1.0;
		double maxOffset = localGrainSize * 0.18 * cloudMix;
		return signedRand * maxOffset;
	}

	double getCloudStartOffset(const VoiceState& voice, int grainIndex, double maxStart, double cloudMix) const
	{
		if (cloudMix <= 0.0 || maxStart <= 0.0)
			return 0.0;

		double signedRand = grainRandomFromSeed((double) (grainIndex + 1) * 67.91 + (double) voice.noteNumber * 5.13) * 2.0 - 1.0;
		double maxOffset = jmax(2.0, maxStart * 0.015) * cloudMix;
		return signedRand * maxOffset;
	}

	double getCloudRespawnOffset(const VoiceState& voice, int grainIndex, double maxStart, int respawnCount,
		double cloudMix) const
	{
		if (maxStart <= 0.0)
			return 0.0;

		// Cloud mode always has a small local field; Cloud Amount expands it.
		double width = maxStart * (0.012 + 0.108 * clamp01(cloudMix));
		double seed = ((double) grainIndex + 1.0) * 83.17
			+ ((double) voice.noteNumber + 1.0) * 19.91
			+ ((double) respawnCount + 1.0) * 137.23;
		return (grainRandomFromSeed(seed) * 2.0 - 1.0) * width;
	}

	double getSafeStartPosition(int grainIndex, int grainCount, double requestedStart, double maxStart) const
	{
		if (maxStart <= 0.0 || sampleRate <= 0.0)
			return 0.0;

		const double target = jlimit(0.0, maxStart, requestedStart);
		const int radius = jlimit(4, 96, (int) std::round(sampleRate * 0.00075));
		double bestPos = target;
		double bestL = 0.0;
		double bestR = 0.0;
		readGrainStereo(grainIndex, grainCount, target, bestL, bestR);
		double bestEnergy = bestL * bestL + bestR * bestR;

		for (int offset = 1; offset <= radius; ++offset)
		{
			const double candidates[2] = { target - (double) offset, target + (double) offset };
			for (double candidate : candidates)
			{
				if (candidate < 0.0 || candidate > maxStart)
					continue;

				double l = 0.0;
				double r = 0.0;
				readGrainStereo(grainIndex, grainCount, candidate, l, r);
				double energy = l * l + r * r;
				if (energy < bestEnergy)
				{
					bestEnergy = energy;
					bestPos = candidate;
				}
			}
		}

		return bestPos;
	}

	double getScatterStartOffset(int grainIndex, int grainCount, double maxStart, int respawnCount) const
	{
		if (maxStart <= 0.0)
			return 0.0;

		double spread = clamp01(phaseScatter);
		if (spread <= 0.0)
			return 0.0;

		double stableSeed = (double) (grainIndex + 1) * 57.31 + 91.73;
		double rerollSeed = stableSeed + (double) respawnCount * 173.31;
		double stableRand = grainRandomFromSeed(stableSeed);
		double rerollRand = grainRandomFromSeed(rerollSeed);
		double rerollBlend = clamp01(respawn);
		double random01 = stableRand + (rerollRand - stableRand) * rerollBlend;
		double ordered01 = grainCount > 1 ? (double) grainIndex / (double) (grainCount - 1) : 0.5;
		double mirrored01 = 0.5;

		if (grainCount > 1)
		{
			int pairIndex = grainIndex / 2;
			int pairCount = (grainCount + 1) / 2;
			double shell = pairCount > 1 ? (double) pairIndex / (double) (pairCount - 1) : 0.0;
			double signedShell = ((grainIndex % 2) == 0 ? -1.0 : 1.0) * shell;
			mirrored01 = 0.5 + 0.5 * signedShell;
		}

		double clustered01 = 0.5 + (random01 - 0.5) * (0.2 + 0.8 * smooth01(clamp01(phaseScatter)));
		double shape01 = random01;

		switch (getPhaseScatterShapeState())
		{
			case 2: // Spread
				shape01 = ordered01;
				break;
			case 3: // Mirror
				shape01 = mirrored01;
				break;
			case 4: // Cluster
				shape01 = clustered01;
				break;
			case 1: // Random
			default:
				shape01 = random01;
				break;
		}

		double halfWidth = 0.0;
		if (spread <= 0.5)
		{
			double localSpread = smooth01(spread * 2.0);
			halfWidth = jmax(2.0, maxStart * 0.08) * localSpread;
		}
		else
		{
			double broadSpread = smooth01((spread - 0.5) * 2.0);
			double localWidth = jmax(2.0, maxStart * 0.08);
			double broadWidth = jmax(localWidth, maxStart * 0.3);
			halfWidth = localWidth + (broadWidth - localWidth) * broadSpread;
		}

		double offset = (shape01 * 2.0 - 1.0) * halfWidth;
		return offset;
	}

	double getReadPhaseForMode(double phase, int readState, double pitchMul) const
	{
		ignoreUnused(readState, pitchMul);
		return phase;
	}

	double getTimelinePhaseForRead(double carrierPhase, bool timeInvariant, double readRate, double localGrainSize) const
	{
		ignoreUnused(readRate);

		if (!timeInvariant)
			return carrierPhase;
		if (localGrainSize <= 0.0)
			return 0.0;

		// In time-invariant modes the source-read phase is already advanced explicitly
		// via grain.readPhase, so multiplying by readRate again shifts the pitch baseline.
		return wrap01(carrierPhase / localGrainSize) * localGrainSize;
	}

	void readStereoPairAt(int pairIndex, double pos, double& outL, double& outR) const
	{
		int chL = pairIndex + pairIndex;
		int chR = chL + 1;

		if (sourceChannelCount <= 1)
		{
			chL = 0;
			chR = 0;
		}
		else if (chL < 0 || chR >= sourceChannelCount)
		{
			chL = 0;
			chR = 1;
		}

		int i = (int) pos;
		double f = pos - (double) i;

		if (sourceSample[(size_t) chL].size() <= i + 1)
			chL = 0;
		if (sourceSample[(size_t) chR].size() <= i + 1)
			chR = chL;

		outL = (1.0 - f) * sourceSample[(size_t) chL][i] + f * sourceSample[(size_t) chL][i + 1];
		outR = (1.0 - f) * sourceSample[(size_t) chR][i] + f * sourceSample[(size_t) chR][i + 1];
	}

	void readGrainStereo(int grainIndex, int grainCount, double pos, double& outL, double& outR) const
	{
		int pairCount = sourcePairCount;
		if (pairCount < 1)
			pairCount = 1;
		if (pairCount > MaxStereoPairs)
			pairCount = MaxStereoPairs;
		if (grainCount < 1)
			grainCount = 1;

		if (pairCount == 1 || grainCount >= pairCount)
		{
			int pairIndex = (grainIndex * pairCount) / grainCount;
			if (pairIndex < 0) pairIndex = 0;
			if (pairIndex > pairCount - 1) pairIndex = pairCount - 1;
			readStereoPairAt(pairIndex, pos, outL, outR);
			return;
		}

		int startPair = (grainIndex * pairCount) / grainCount;
		int endPair = ((grainIndex + 1) * pairCount) / grainCount;
		if (endPair <= startPair)
			endPair = startPair + 1;
		if (startPair < 0) startPair = 0;
		if (endPair > pairCount) endPair = pairCount;

		double sumL = 0.0;
		double sumR = 0.0;
		int count = 0;
		for (int p = startPair; p < endPair; ++p)
		{
			double l = 0.0;
			double r = 0.0;
			readStereoPairAt(p, pos, l, r);
			sumL += l;
			sumR += r;
			++count;
		}

		if (count <= 0)
		{
			readStereoPairAt(0, pos, outL, outR);
			return;
		}

		double inv = 1.0 / std::sqrt((double) count);
		outL = sumL * inv;
		outR = sumR * inv;
	}

	double getDetuneSeed(int grainIndex) const
	{
		static constexpr double seeds[16] =
		{
			0.77, 1.91, 2.43, 3.17, 4.03, 5.11, 6.41, 7.73,
			8.97, 9.31, 10.62, 11.91, 12.27, 13.44, 14.72, 15.91
		};

		if (grainIndex < 16)
			return seeds[grainIndex];

		return 0.77 + (double) grainIndex * 1.31;
	}

	double getDetuneSinCached(int grainIndex) const
	{
		static const std::array<double, MaxGrains> values = []
		{
			std::array<double, MaxGrains> cached {};
			static constexpr double seeds[16] =
			{
				0.77, 1.91, 2.43, 3.17, 4.03, 5.11, 6.41, 7.73,
				8.97, 9.31, 10.62, 11.91, 12.27, 13.44, 14.72, 15.91
			};

			for (int i = 0; i < MaxGrains; ++i)
			{
				double seed = i < 16 ? seeds[i] : (0.77 + (double) i * 1.31);
				cached[(size_t) i] = std::sin(seed);
			}

			return cached;
		}();

		int clampedIndex = jlimit(0, MaxGrains - 1, grainIndex);
		return values[(size_t) clampedIndex];
	}

	const std::array<double, 25>& getScaleRatioTable() const
	{
		static const std::array<double, 25> ratios = []
		{
			std::array<double, 25> table {};
			for (size_t i = 0; i < table.size(); ++i)
				table[i] = std::pow(2.0, (double) i / 12.0);
			return table;
		}();

		return ratios;
	}

	double getScaleRatioFromSemitones(int semitones) const
	{
		const auto& ratios = getScaleRatioTable();
		int clamped = jlimit(0, (int) ratios.size() - 1, semitones);
		return ratios[(size_t) clamped];
	}

	double getQStyleReadPhase(int grainIndex, int respawnCount, bool qStyleRead, double localGrainSize) const
	{
		if (!qStyleRead || localGrainSize <= 0.0)
			return 0.0;

		double seed = ((double) grainIndex + 1.0) * 31.17 + ((double) respawnCount + 1.0) * 97.13;
		return grainRandomFromSeed(seed) * localGrainSize;
	}

	double getScrubSourceForGrain(int grainIndex, int grainCount) const
	{
		const double values[4] = { scrub, scrubB, scrubC, scrubD };
		int laneCount = getPlayheadModeState() == 1 ? 4 : 1;

		int clampedCount = jmax(1, grainCount);
		int lane = (grainIndex * laneCount) / clampedCount;
		lane = jlimit(0, laneCount - 1, lane);
		return clamp01(values[lane]);
	}

	int getScrubGroupForGrain(int grainIndex, int grainCount, bool isStackMode) const
	{
		if (!isStackMode)
		{
			if (getPlayheadModeState() == 0)
				return jlimit(0, jmax(0, grainCount - 1), grainIndex);

			int laneCount = 4;
			int clampedCount = jmax(1, grainCount);
			int lane = (grainIndex * laneCount) / clampedCount;
			return jlimit(0, laneCount - 1, lane);
		}

		return 0;
	}

	double getInterpolatedScrubForGrain(int grainIndex, int grainCount) const
	{
		if (grainCount <= 1)
			return scrub;

		double t = (double) grainIndex / (double) (grainCount - 1);
		double s = scrub;
		if (t <= (1.0 / 3.0))
			s = scrub + (scrubB - scrub) * (t * 3.0);
		else if (t <= (2.0 / 3.0))
			s = scrubB + (scrubC - scrubB) * ((t - (1.0 / 3.0)) * 3.0);
		else
			s = scrubC + (scrubD - scrubC) * ((t - (2.0 / 3.0)) * 3.0);

		s = quantiseScrub(s);
		if (s < 0.0) s += 1.0;
		if (s > 1.0) s -= 1.0;
		return s;
	}

	int getDirectionState() const
	{
		return jlimit(1, 4, (int)std::round(directionMode));
	}

	double getOneShotStepSize(double maxStart) const
	{
		int directionState = getDirectionState();
		if (directionState == 4)
		{
			if (maxStart <= 0.0)
				return 1.0;

			double step = grainSize / maxStart;
			if (step < 0.0001) step = 0.0001;
			if (step > 1.0) step = 1.0;
			return step;
		}

		return 0.0;
	}

	double getTransportFollowCoeff() const
	{
		if (sampleRate <= 0.0)
			return 1.0;

		return 1.0 - std::exp(-1.0 / (0.01 * sampleRate));
	}

	template <typename FrameType> void renderFrame(FrameType& fd, VoiceState& voice)
	{
		double maxStart = (double) audioFile.numSamples - grainSize - 2.0;
		if (maxStart <= 0.0)
			maxStart = 0.0;

		const double scrubSmoothed = scrub;
		const double previousScrub = voice.scrubQ;
		voice.scrubQ = scrub;
		voice.scanPos = scrubSmoothed * maxStart;
		const bool transportWrapped = (scrubSmoothed + 0.25) < previousScrub;

		// Keep pitch sync and glide responsive to live control changes, not just note-on.
		updateDelta(voice);

		const int pitchState = getPitchState();
		if (getGlideTimeSeconds() > 0.0001)
			updateGlideSmoothing(voice);

		int transportState = 2;
		bool stretchEnabled = true;
		bool legacyExact = true;
		bool legacyWrapFade = false;
		bool cloudMode = false;
		bool microSliceMode = false;
		bool microSliceMorphMode = false;
		bool safeStartMode = false;
		getPlaybackPresetState(transportState, stretchEnabled, legacyExact, legacyWrapFade, cloudMode, microSliceMode, microSliceMorphMode, safeStartMode);
		const bool timeInvariant = false;
		const bool smoothTimeInvariant = false;
		const int readState = 0;
		const bool qStyleRead = false;
		const int g = jlimit(1, MaxGrains, (int) std::round(maxGrainsValue));
		const bool isStackMode = (getModePackValue(2, 0.0) < 0.5);
		const bool stretchMode = legacyExact ? true : stretchEnabled;
		const int densitySlots = g;

		double morphDensity = clamp01(density);
		if (voice.densityMorphSmoothed < 0.0)
			voice.densityMorphSmoothed = morphDensity;

		double densitySmoothCoeff = 1.0;
		if (sampleRate > 0.0)
			densitySmoothCoeff = 1.0 - std::exp(-1.0 / (0.02 * sampleRate));

		voice.densityMorphSmoothed += (morphDensity - voice.densityMorphSmoothed) * densitySmoothCoeff;
		morphDensity = voice.densityMorphSmoothed;

		std::array<double, MaxGrains> weights {};
		std::array<int, MaxGrains> grainGroup {};
		std::array<int, MaxGrains> grainIndexInGroup {};
		std::array<int, MaxGrains> groupSizes {};
		double sumsq = 0.0;

		int idxA = 0;
		int idxB = 0;
		double gA = 1.0;
		double gB = 0.0;
		std::array<double, MaxGrains> groupMorphWeights {};

		for (int i = 0; i < g; ++i)
		{
			int group = getScrubGroupForGrain(i, g, isStackMode);
			grainGroup[(size_t)i] = group;
			grainIndexInGroup[(size_t)i] = groupSizes[(size_t)group];
			++groupSizes[(size_t)group];
		}

		if (!isStackMode)
		{
			int activeGroupCount = getPlayheadModeState() == 0 ? g : 4;
			activeGroupCount = jlimit(1, MaxGrains, activeGroupCount);

			double selector = morphDensity * (double) activeGroupCount;
			if (selector >= (double) activeGroupCount)
				selector = (double) activeGroupCount - 0.000001;

			idxA = jlimit(0, activeGroupCount - 1, (int) std::floor(selector));
			idxB = jlimit(0, activeGroupCount - 1, idxA + 1);
			double t = smooth01(clamp01(selector - (double) idxA));
			gA = std::sqrt(1.0 - t);
			gB = std::sqrt(t);
			groupMorphWeights[(size_t)idxA] += gA;
			groupMorphWeights[(size_t)idxB] += gB;
		}

		for (int i = 0; i < g; ++i)
		{
			double w = getGrainWeight(i, densitySlots, isStackMode, morphDensity);
			if (!isStackMode)
			{
				int group = grainGroup[(size_t)i];
				int groupIndex = grainIndexInGroup[(size_t)i];
				int groupCount = groupSizes[(size_t)group];
				if (getPlayheadModeState() == 0)
				{
					w = groupMorphWeights[(size_t)group];
				}
				else
				{
					w = getGrainWeight(groupIndex, groupCount, true, morphDensity) * groupMorphWeights[(size_t)group];
				}
			}
			weights[(size_t) i] = w;
			sumsq += w * w;
		}

		double wnorm = (sumsq > 0.0 ? 1.0 / std::sqrt(sumsq) : 1.0);

		double Lsum = 0.0;
		double Rsum = 0.0;
		double center = (double) (g - 1) * 0.5;
		double invDenom = (g > 1) ? 1.0 / (double) (g - 1) : 0.0;
		int directionState = getDirectionState();
		const bool oneShotMode = directionState >= 4;
		const double oneShotStepSize = getOneShotStepSize(maxStart);
		std::array<bool, 4> oneShotTriggeredByPlayhead {};
		if (oneShotMode)
		{
			// Detect each scrub event once, then let every grain in that playhead
			// group launch together. Detecting inside the grain loop only launched
			// the first grain because it consumed the shared event state.
			const double scrubSources[4] = { scrub, scrubB, scrubC, scrubD };
			const int playheadCount = getPlayheadModeState() == 1 ? 4 : 1;
			const double denom = oneShotStepSize > 0.0 ? oneShotStepSize : 1.0;

			for (int playhead = 0; playhead < playheadCount; ++playhead)
			{
				const double scrubSource = clamp01(scrubSources[playhead]);
				int currentStep = (int) std::floor(scrubSource / denom);
				if (scrubSource >= 1.0)
					currentStep = (int) std::floor(1.0 / denom);

				if (voice.previousOneShotStep[(size_t) playhead] != currentStep)
				{
					voice.previousOneShotStep[(size_t) playhead] = currentStep;
					oneShotTriggeredByPlayhead[(size_t) playhead] = true;
				}
			}
		}
		double spreadNorm = isStackMode ? 1.0 : morphDensity;
		bool scrubMoved = std::abs(previousScrub - scrub) > 0.0005;
		double cloudMix = getCloudMix(voice);
		const bool enableBloom = cloudMix > 0.0001;
		const int bloomActiveGrainCount = g;
		const bool scatterParamsChanged = std::abs(voice.lastPhaseScatter - phaseScatter) > 0.000001
			|| std::abs(voice.lastScatterMaxStart - maxStart) > 0.5;
		voice.lastPhaseScatter = phaseScatter;
		voice.lastScatterMaxStart = maxStart;

		if (cloudMode)
		{
			if (voice.modeAnchorScrub < 0.0 || std::abs(voice.modeAnchorScrub - scrubSmoothed) > 0.000001)
				voice.modeAnchorScrub = scrubSmoothed;
		}
		else if (voice.modeAnchorScrub >= 0.0)
		{
			voice.modeAnchorScrub = -1.0;
		}

		if (stretchMode && !cloudMode && (voice.stretchBasePos < 0.0 || scrubMoved))
			voice.stretchBasePos = scrubSmoothed * maxStart;

		for (int i = 0; i < g; ++i)
		{
			double weight = weights[(size_t) i] * wnorm;
			if (weight <= 0.0)
				continue;

			int playheadIndex = getPlayheadModeState() == 1 ? getScrubGroupForGrain(i, g, false) : 0;
			double scrubValue = getScrubSourceForGrain(i, g);
			double previousSource = voice.previousScrubSource[(size_t) playheadIndex];
			bool scrubWrapped = false;

			auto& grain = voice.grains[(size_t) i];
			double localGrainSize = getEffectiveGrainSize(i, g);
			double oneShotWindowSize = localGrainSize * (1.0 + getOneShotTailFactor());
			double localMaxStart = (double) audioFile.numSamples - localGrainSize - 2.0;
			if (localMaxStart <= 0.0)
				localMaxStart = 0.0;

			double base = scrubSmoothed * localMaxStart;
			if (cloudMode)
			{
				double anchorScrub = voice.modeAnchorScrub >= 0.0 ? voice.modeAnchorScrub : scrubSmoothed;
				base = anchorScrub * localMaxStart;
			}
			else if (legacyExact)
			{
				if (getPlayheadModeState() > 0)
				{
					base = scrubValue * localMaxStart;
				}
			}
			else
			{
				voice.previousScrubSource[(size_t) playheadIndex] = scrubValue;
				scrubWrapped = (scrubValue + 0.25) < previousSource;
				base = scrubValue * localMaxStart;
			}

			const double unslicedBase = base;
			if (microSliceMode)
				base = quantiseSliceBase(unslicedBase, localGrainSize, localMaxStart);

			const bool oneShotTriggered = oneShotMode
				&& oneShotTriggeredByPlayhead[(size_t) playheadIndex];

			const bool bloomActivationAllowed = i < bloomActiveGrainCount;
			double cloudPhaseOffset = enableBloom ? getCloudPhaseOffset(voice, i, localGrainSize, cloudMix) : 0.0;
			double cloudStartOffset = enableBloom ? getCloudStartOffset(voice, i, localMaxStart, cloudMix) : 0.0;
			auto finaliseSpawnStart = [&](double requestedStart, int respawnCount) -> double
			{
				if (cloudMode)
					requestedStart += getCloudRespawnOffset(voice, i, localMaxStart, respawnCount, cloudMix);

				requestedStart = jlimit(0.0, localMaxStart, requestedStart);
				return safeStartMode
					? getSafeStartPosition(i, g, requestedStart, localMaxStart)
					: requestedStart;
			};
			auto setMorphCells = [&](double cellBase, double cellSize, double sourceMaxStart, double scatterOffset)
			{
				grain.morphCellSize = jmax(1.0, cellSize);
				grain.morphMaxStart = jmax(0.0, sourceMaxStart);
				grain.morphCellBase = quantiseSliceBase(cellBase, grain.morphCellSize, grain.morphMaxStart);
				grain.morphScatterOffset = scatterOffset;
				grain.morphCellAStart = jlimit(0.0, grain.morphMaxStart, grain.morphCellBase + scatterOffset);
				grain.morphCellBStart = jlimit(0.0, grain.morphMaxStart,
					grain.morphCellBase + grain.morphCellSize + scatterOffset);
				grain.morphCellsValid = true;
			};
			if (!grain.active && !oneShotMode && bloomActivationAllowed)
			{
				grain.active = true;
				double schedulerOffset = getInitialSchedulerPhase(i, g, stretchMode, localGrainSize);
				grain.phase = schedulerOffset + cloudPhaseOffset;
				if (grain.phase < 0.0)
					grain.phase += localGrainSize;
				if (grain.phase >= localGrainSize)
					grain.phase -= localGrainSize;
				grain.readPhase = getQStyleReadPhase(i, grain.respawnCount, qStyleRead, localGrainSize);
				grain.respawnCount = 0;
				grain.scatterOffset = getScatterStartOffset(i, g, localMaxStart, grain.respawnCount);
				double scatterBase = finaliseSpawnStart(base + grain.scatterOffset + cloudStartOffset, grain.respawnCount);
				grain.latchedStart = scatterBase;
				grain.start = legacyExact && stretchMode
					? finaliseSpawnStart(voice.stretchBasePos + grain.scatterOffset + cloudStartOffset, grain.respawnCount)
					: scatterBase;
				grain.wrapFade = 0.0;
			}
			else if (scatterParamsChanged)
			{
				grain.scatterOffset = getScatterStartOffset(i, g, localMaxStart, grain.respawnCount);
			}

			if (oneShotMode && oneShotTriggered)
			{
				const bool replacingActiveGrain = grain.active;
				if (replacingActiveGrain)
				{
					// Preserve the old one-shot briefly so its source discontinuity is
					// crossfaded against the newly triggered cluster.
					grain.fadePhase = grain.phase;
					grain.fadeReadPhase = grain.readPhase;
					grain.fadeStart = grain.start;
					grain.fadeGrainSize = localGrainSize;
					grain.fadeWindowSize = oneShotWindowSize;
					grain.fadeDurationSeconds = 0.008;
					grain.fadeIsOneShot = true;
					grain.wrapFade = 1.0;
				}

				grain.active = true;
				grain.phase = getInitialSchedulerPhase(i, g, stretchMode, localGrainSize) + cloudPhaseOffset;
				++grain.respawnCount;
				grain.readPhase = getQStyleReadPhase(i, grain.respawnCount, qStyleRead, localGrainSize);
				grain.scatterOffset = getScatterStartOffset(i, g, localMaxStart, grain.respawnCount);
				grain.start = finaliseSpawnStart(base + grain.scatterOffset + cloudStartOffset, grain.respawnCount);
				grain.latchedStart = grain.start;
				if (!replacingActiveGrain)
					grain.wrapFade = 0.0;
			}

			if (microSliceMorphMode && grain.active && !grain.morphCellsValid)
			{
				setMorphCells(unslicedBase, localGrainSize, localMaxStart, grain.scatterOffset);
			}
			else if (!microSliceMorphMode)
			{
				grain.morphCellsValid = false;
			}

			if (!grain.active)
				continue;

			double microSliceMorph = 0.0;
			if (microSliceMorphMode && grain.morphCellsValid)
			{
				const double morphUnslicedBase = clamp01(scrubValue) * grain.morphMaxStart;
				const double desiredCellBase = quantiseSliceBase(morphUnslicedBase, grain.morphCellSize, grain.morphMaxStart);
				const double cellSize = grain.morphCellSize;

				if (desiredCellBase > grain.morphCellBase + 0.5)
				{
					if (desiredCellBase <= grain.morphCellBase + cellSize + 0.5)
					{
						grain.morphCellBase = desiredCellBase;
						grain.morphCellAStart = grain.morphCellBStart;
						grain.morphCellBStart = jlimit(0.0, grain.morphMaxStart,
							desiredCellBase + cellSize + grain.morphScatterOffset);
					}
					else
					{
						setMorphCells(desiredCellBase, cellSize, grain.morphMaxStart, grain.morphScatterOffset);
					}
				}
				else if (desiredCellBase < grain.morphCellBase - 0.5)
				{
					if (desiredCellBase >= grain.morphCellBase - cellSize - 0.5)
					{
						grain.morphCellBase = desiredCellBase;
						grain.morphCellBStart = grain.morphCellAStart;
						grain.morphCellAStart = jlimit(0.0, grain.morphMaxStart,
							desiredCellBase + grain.morphScatterOffset);
					}
					else
					{
						setMorphCells(desiredCellBase, cellSize, grain.morphMaxStart, grain.morphScatterOffset);
					}
				}

				microSliceMorph = clamp01((morphUnslicedBase - grain.morphCellBase) / cellSize);
			}

			if (!oneShotMode && legacyExact && transportWrapped)
			{
				if (legacyWrapFade)
				{
					grain.fadePhase = grain.phase;
					grain.fadeReadPhase = grain.readPhase;
					grain.fadeStart = grain.start;
					grain.fadeGrainSize = localGrainSize;
					grain.fadeWindowSize = localGrainSize;
					grain.fadeDurationSeconds = 0.01;
					grain.fadeIsOneShot = false;
				}

				grain.phase = getInitialSchedulerPhase(i, g, stretchMode, localGrainSize) + cloudPhaseOffset;
				++grain.respawnCount;
				grain.readPhase = getQStyleReadPhase(i, grain.respawnCount, qStyleRead, localGrainSize);
				grain.scatterOffset = getScatterStartOffset(i, g, localMaxStart, grain.respawnCount);
				grain.start = finaliseSpawnStart(base + grain.scatterOffset + cloudStartOffset, grain.respawnCount);
				grain.latchedStart = grain.start;
				grain.latchedStart = grain.start;
				if (legacyWrapFade)
					grain.wrapFade = 1.0;
			}

			ignoreUnused(scrubWrapped);

			if (!legacyExact)
			{
				if (transportState == 0)
				{
					grain.start = finaliseSpawnStart(base + cloudStartOffset, grain.respawnCount);
					grain.latchedStart = grain.start;
				}
				else if (transportState == 1)
				{
					double coeff = getTransportFollowCoeff();
					grain.latchedStart += (finaliseSpawnStart(base + cloudStartOffset, grain.respawnCount) - grain.latchedStart) * coeff;
					grain.start = grain.latchedStart;
				}
				else
				{
					grain.start = grain.latchedStart;
				}
			}

			double grainPitchMul = getPitchModeMul(pitchState, spreadNorm, getDetuneSinCached(i), (double) (i + 1));
			int signState = directionState;
			if (signState > 3)
				signState = 1;
			double dir = getDirectionSign(signState - 1, i);
			double schedulerInc = timeInvariant ? dir : (voice.delta * grainPitchMul * dir);
			double readInc = schedulerInc;
			bool grainCycleWrapped = false;

			if (timeInvariant)
			{
				schedulerInc = dir;
				readInc = voice.delta * grainPitchMul * dir;
			}
			else if (stretchMode)
			{
				// In stretch mode the grain window should advance in output time,
				// while note / semitone pitch only affects the source-read phase.
				schedulerInc = dir;
				readInc = voice.delta * grainPitchMul * dir;
			}

			grain.phase += schedulerInc;
			grain.readPhase += readInc;

			if (grain.phase >= localGrainSize)
			{
				if (oneShotMode)
				{
					if (grain.phase >= oneShotWindowSize)
					{
						grain.active = false;
						grain.phase = oneShotWindowSize;
						continue;
					}
				}
				else
				{
					grainCycleWrapped = true;
					grain.phase -= localGrainSize;
					if (stretchMode || timeInvariant)
					{
						if (qStyleRead)
						{
							++grain.respawnCount;
							grain.readPhase = getQStyleReadPhase(i, grain.respawnCount, qStyleRead, localGrainSize);
						}
						else
						{
							while (grain.readPhase >= localGrainSize)
								grain.readPhase -= localGrainSize;
						}
					}
					else
					{
						grain.readPhase = qStyleRead ? getQStyleReadPhase(i, grain.respawnCount, qStyleRead, localGrainSize) : grain.phase;
					}

					if (legacyExact)
					{
						++grain.respawnCount;
						grain.scatterOffset = getScatterStartOffset(i, g, localMaxStart, grain.respawnCount);
						grain.start = finaliseSpawnStart(base + grain.scatterOffset + cloudStartOffset, grain.respawnCount);
						grain.latchedStart = grain.start;
					}
					else if (transportState == 2)
					{
						++grain.respawnCount;
						grain.scatterOffset = getScatterStartOffset(i, g, localMaxStart, grain.respawnCount);
						grain.latchedStart = finaliseSpawnStart(base + grain.scatterOffset + cloudStartOffset, grain.respawnCount);
					}
				}
			}
			if (grain.phase < 0.0)
			{
				if (oneShotMode)
				{
					grain.active = false;
					grain.phase = 0.0;
					grain.readPhase = 0.0;
					continue;
				}

				grainCycleWrapped = true;
				grain.phase += localGrainSize;
				if (stretchMode || timeInvariant)
				{
					if (qStyleRead)
					{
						++grain.respawnCount;
						grain.readPhase = getQStyleReadPhase(i, grain.respawnCount, qStyleRead, localGrainSize);
					}
					else
					{
						while (grain.readPhase < 0.0)
							grain.readPhase += localGrainSize;
					}
				}
				else
				{
					grain.readPhase = qStyleRead ? getQStyleReadPhase(i, grain.respawnCount, qStyleRead, localGrainSize) : grain.phase;
				}
				if (legacyExact)
				{
					++grain.respawnCount;
					grain.scatterOffset = getScatterStartOffset(i, g, localMaxStart, grain.respawnCount);
					grain.start = finaliseSpawnStart(base + grain.scatterOffset + cloudStartOffset, grain.respawnCount);
					grain.latchedStart = grain.start;
				}
				else if (transportState == 2)
				{
					++grain.respawnCount;
					grain.scatterOffset = getScatterStartOffset(i, g, localMaxStart, grain.respawnCount);
					grain.latchedStart = finaliseSpawnStart(base + grain.scatterOffset + cloudStartOffset, grain.respawnCount);
				}
			}

			if (microSliceMorphMode && grainCycleWrapped
				&& (std::abs(grain.morphCellSize - localGrainSize) > 0.5
					|| std::abs(grain.morphScatterOffset - grain.scatterOffset) > 0.5
					|| std::abs(grain.morphMaxStart - localMaxStart) > 0.5))
			{
				// GrainMs and Scatter change the cell layout only at the grain boundary,
				// avoiding a source-position discontinuity within an audible window.
				setMorphCells(unslicedBase, localGrainSize, localMaxStart, grain.scatterOffset);
				microSliceMorph = clamp01((clamp01(scrubValue) * grain.morphMaxStart - grain.morphCellBase)
					/ grain.morphCellSize);
			}

			if (stretchMode)
			{
				if (grain.latchedStart < 0.0)
					grain.latchedStart = 0.0;
				if (grain.latchedStart > localMaxStart)
					grain.latchedStart = localMaxStart;
			}

			if (grain.start < 0.0)
				grain.start = 0.0;
			if (grain.start > localMaxStart)
				grain.start = localMaxStart;

			const bool oneShotTailActive = oneShotMode && oneShotWindowSize > localGrainSize;
			double readCarrier = (stretchMode || timeInvariant || oneShotTailActive)
				? grain.readPhase : jmin(grain.phase, localGrainSize);
			double readRate = stretchMode ? grainPitchMul : (voice.delta * grainPitchMul);
			double currentReadStart = grain.start;
			if (microSliceMorphMode)
			{
				currentReadStart = grain.morphCellAStart;
			}

			double readOffset = getReadPhaseForMode(getTimelinePhaseForRead(readCarrier, timeInvariant, readRate, localGrainSize), readState, grainPitchMul);
			double pos = currentReadStart + readOffset;
			if (pos < 0.0) pos = 0.0;
			if (pos >= audioFile.numSamples - 1.0)
				pos = audioFile.numSamples - 2.0;

			double envelopePhase = grain.phase;
			if (oneShotMode)
			{
				envelopePhase = jlimit(0.0, oneShotWindowSize, envelopePhase);
			}
			else
			{
				while (envelopePhase >= localGrainSize)
					envelopePhase -= localGrainSize;
				while (envelopePhase < 0.0)
					envelopePhase += localGrainSize;
			}

			double w = morphedWindow(oneShotMode ? (envelopePhase / jmax(1.0, oneShotWindowSize)) : wrap01(envelopePhase / localGrainSize));
			double monoL = 0.0;
			double monoR = 0.0;
			readGrainStereo(i, g, pos, monoL, monoR);

			if (microSliceMorph > 0.0 && grain.morphCellsValid)
			{
				// Read the adjacent quantised cell with the same grain timeline. This
				// preserves the Microslice cycle rate while Scrub morphs its timbre.
				double nextPos = grain.morphCellBStart + readOffset;
				if (nextPos >= audioFile.numSamples - 1.0)
					nextPos = audioFile.numSamples - 2.0;

				double nextL = 0.0;
				double nextR = 0.0;
				readGrainStereo(i, g, nextPos, nextL, nextR);

				const double currentMix = 1.0 - microSliceMorph;
				monoL = monoL * currentMix + nextL * microSliceMorph;
				monoR = monoR * currentMix + nextR * microSliceMorph;
			}

			if (grain.wrapFade > 0.0 && grain.fadeGrainSize > 1.0)
			{
				const bool fadeOneShotTailActive = grain.fadeIsOneShot && grain.fadeWindowSize > grain.fadeGrainSize;
				double fadeCarrier = (stretchMode || timeInvariant || fadeOneShotTailActive)
					? grain.fadeReadPhase : grain.fadePhase;
				double fadePos = grain.fadeStart + getReadPhaseForMode(getTimelinePhaseForRead(fadeCarrier, timeInvariant, readRate, grain.fadeGrainSize), readState, grainPitchMul);
				if (fadePos < 0.0) fadePos = 0.0;
				if (fadePos >= audioFile.numSamples - 1.0)
					fadePos = audioFile.numSamples - 2.0;

				double fadeEnvelopePhase = grain.fadePhase;
				double fadeW = 0.0;
				if (grain.fadeIsOneShot)
				{
					fadeEnvelopePhase = jlimit(0.0, grain.fadeWindowSize, fadeEnvelopePhase);
					fadeW = morphedWindow(fadeEnvelopePhase / jmax(1.0, grain.fadeWindowSize));
				}
				else
				{
					while (fadeEnvelopePhase >= grain.fadeGrainSize)
						fadeEnvelopePhase -= grain.fadeGrainSize;
					while (fadeEnvelopePhase < 0.0)
						fadeEnvelopePhase += grain.fadeGrainSize;

					fadeW = morphedWindow(wrap01(fadeEnvelopePhase / grain.fadeGrainSize));
				}
				double fadeL = 0.0;
				double fadeR = 0.0;
				readGrainStereo(i, g, fadePos, fadeL, fadeR);

				double fadeMix = grain.wrapFade;
				double newMix = 1.0 - fadeMix;
				monoL = monoL * w * newMix + fadeL * fadeW * fadeMix;
				monoR = monoR * w * newMix + fadeR * fadeW * fadeMix;
				w = 1.0;

				grain.fadePhase += schedulerInc;
				grain.fadeReadPhase += readInc;

				if (!grain.fadeIsOneShot)
				{
					while (grain.fadePhase >= grain.fadeGrainSize)
						grain.fadePhase -= grain.fadeGrainSize;
					while (grain.fadePhase < 0.0)
						grain.fadePhase += grain.fadeGrainSize;

					while (grain.fadeReadPhase >= grain.fadeGrainSize)
						grain.fadeReadPhase -= grain.fadeGrainSize;
					while (grain.fadeReadPhase < 0.0)
						grain.fadeReadPhase += grain.fadeGrainSize;
				}
			}

			if (smoothTimeInvariant && localGrainSize > 1.0)
			{
				double timelinePhase = getTimelinePhaseForRead(readCarrier, timeInvariant, readRate, localGrainSize);
				double fadeSamples = jlimit(4.0, 128.0, localGrainSize * 0.04);
				double wrapMix = 0.0;
				double altPhase = timelinePhase;

				if (timelinePhase < fadeSamples)
				{
					wrapMix = smooth01(1.0 - (timelinePhase / fadeSamples));
					altPhase = timelinePhase + localGrainSize;
				}
				else if (timelinePhase > (localGrainSize - fadeSamples))
				{
					wrapMix = smooth01((timelinePhase - (localGrainSize - fadeSamples)) / fadeSamples);
					altPhase = timelinePhase - localGrainSize;
				}

				if (wrapMix > 0.0)
				{
					double altPos = grain.start + getReadPhaseForMode(altPhase, readState, grainPitchMul);
					if (altPos < 0.0) altPos = 0.0;
					if (altPos >= audioFile.numSamples - 1.0)
						altPos = audioFile.numSamples - 2.0;

					double altL = 0.0;
					double altR = 0.0;
					readGrainStereo(i, g, altPos, altL, altR);

					double dry = 1.0 - wrapMix;
					monoL = monoL * dry + altL * wrapMix;
					monoR = monoR * dry + altR * wrapMix;
				}
			}

			double panSlot = panOrderIndex(i, g);
			double normPan = ((panSlot - center) * invDenom);
			double pan = panSpread * normPan * 2.0;
			if (grain.wrapFade > 0.0)
			{
				double fadeDec = (sampleRate > 0.0)
					? (1.0 / (jmax(0.001, grain.fadeDurationSeconds) * sampleRate)) : 1.0;
				grain.wrapFade -= fadeDec;
				if (grain.wrapFade < 0.0)
				{
					grain.wrapFade = 0.0;
					grain.fadeGrainSize = 0.0;
					grain.fadeWindowSize = 0.0;
					grain.fadeIsOneShot = false;
				}
			}

			Lsum += monoL * w * (0.5 * (1.0 - pan)) * weight;
			Rsum += monoR * w * (0.5 * (1.0 + pan)) * weight;
		}

		voice.noteAgeSamples += 1.0;

		double diffusionAmount = clamp01(diffusion);
		if (diffusionAmount > 0.0001)
		{
			double a1 = 0.08 + 0.62 * diffusionAmount;
			double a2 = 0.04 + 0.47 * diffusionAmount;

			double yL1 = (0.0 - a1) * Lsum + voice.ap1L;
			voice.ap1L = Lsum + a1 * yL1;
			double yR1 = (0.0 - a1) * Rsum + voice.ap1R;
			voice.ap1R = Rsum + a1 * yR1;

			double yL2 = (0.0 - a2) * yL1 + voice.ap2L;
			voice.ap2L = yL1 + a2 * yL2;
			double yR2 = (0.0 - a2) * yR1 + voice.ap2R;
			voice.ap2R = yR1 + a2 * yR2;

			double wet = 0.75 * diffusionAmount;
			double dry = 1.0 - wet;
			Lsum = Lsum * dry + yL2 * wet;
			Rsum = Rsum * dry + yR2 * wet;
		}

		fd[0] += (float) Lsum;
		fd[1] += (float) Rsum;
	}

	ExternalData audioFile;
	PolyData<VoiceState, NV> voiceStates;
	block modePack;
	std::array<block, MaxSourceChannels> sourceSample {};

	double sampleRate = 0.0;
	int blockSize = 0;
	int sourceChannelCount = 2;
	int sourcePairCount = 1;

	double scrub = 0.0;
	double grainMs = 50.0;
	double grainSize = 2048.0;
	bool grainSizeIsSourceLimited = false;
	double scrubB = 0.0;
	double scrubC = 0.0;
	double scrubD = 0.0;
	double pitchSemitones = 0.0;
	int rootNote = 60;
	int scrubStepCount = 64;
	double density = 1.0;
	double windowShape = 0.0;
	double panSpread = 0.0;
	double pitchSpread = 0.0;
	double pitchSyncInput = 0.0;
	double pitchMode = 1.0;
	double maxGrainsValue = 4.0;
	double scrubMode = 1.0;
	double scrubBlend = 0.0;
	double respawn = 0.0;
	double diffusion = 0.0;
	double cloudAmount = 0.0;
	double directionMode = 0.0;
	double phaseScatter = 0.0;
	double transportMode = 1.0;
	double readMode = 1.0;
	double bloomDuration = 250.0;
};

} // namespace project
