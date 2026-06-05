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
	static constexpr int NumSliderPacks = 0;
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
		bool active = false;

		void reset()
		{
			phase = 0.0;
			readPhase = 0.0;
			start = 0.0;
			active = false;
		}
	};

	struct VoiceState
	{
		double scanPos = 0.0;
		double stretchBasePos = -1.0;
		double delta = 1.0;
		int noteNumber = 60;
		double scrubQ = 0.0;
		double densityMorphSmoothed = -1.0;
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
			noteNumber = 60;
			scrubQ = 0.0;
			densityMorphSmoothed = -1.0;
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

	void prepare(PrepareSpecs ps)
	{
		sampleRate = ps.sampleRate;
		blockSize = ps.blockSize;
		voiceStates.prepare(ps);
		formantRatioSmoothed = 1.0;
		updateGrainSize();
		reset();
	}

	void reset()
	{
		resetVoiceContainer(voiceStates);
		formantRatioSmoothed = 1.0;
	}

	template <typename ProcessDataType> void process(ProcessDataType& data)
	{
		if (audioFile.numSamples <= 1)
			return;

		auto audioLock = DataTryReadLock(audioFile);
		if (!audioLock)
			return;

		auto& fixData = data.template as<ProcessData<2>>();
		auto fd = fixData.toFrameData();
		auto& voice = voiceStates.get();
		updateFormantSmoothing();

		while (fd.next())
			renderFrame(fd.toSpan(), voice);

		audioFile.setDisplayedValue(voice.scanPos);
	}

	template <typename FrameDataType> void processFrame(FrameDataType& data)
	{
		if (audioFile.numSamples <= 1)
			return;

		auto audioLock = DataTryReadLock(audioFile);
		if (!audioLock)
			return;

		auto& voice = voiceStates.get();
		updateFormantSmoothing();
		auto& fixFrame = span<float, 2>::as(data.begin());
		renderFrame(fixFrame, voice);
		audioFile.setDisplayedValue(voice.scanPos);
	}

	void handleHiseEvent(HiseEvent& e)
	{
		if (!e.isNoteOn())
			return;

		auto& voice = voiceStates.get();
		voice.reset();
		voice.noteNumber = e.getNoteNumber();
		voice.scrubQ = scrub;
		updateDelta(voice);
	}

	void setExternalData(const ExternalData& data, int index)
	{
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
			grainMs = v;
			updateGrainSize();
		}

		if (P == 3) density = clamp01(v);
		if (P == 4) windowShape = clamp01(v);
		if (P == 5) panSpread = clamp01(v);

		if (P == 6)
		{
			pitchMode = clamp01(v);
			for (auto& voice : voiceStates)
				updateDelta(voice);
		}

		if (P == 7)
		{
			pitchSpread = clamp01(v);
			pitchSyncInput = v;
		}

		if (P == 8)
			maxGrainsValue = jlimit(1.0, (double) MaxGrains, v);
		if (P == 9) scrubMode = clamp01(v);
		if (P == 10) scrubBlend = clamp01(v);

		if (P == 11)
		{
			v = clamp01(v);
			if (v < 0.25) directionMode = 0.0;
			else if (v < 0.75) directionMode = 0.5;
			else directionMode = 1.0;
		}

		if (P == 12) phaseScatter = jmax(0.0, v);
		if (P == 13) scrubB = v;
		if (P == 14) scrubC = v;
		if (P == 15) scrubD = v;
		if (P == 16) density2 = clamp01(v);
		if (P == 17) diffusionAmount = clamp01(v);
		if (P == 18) positionSpreadAmount = clamp01(v);
	}

	void createParameters(ParameterDataList& data)
	{
		addParameter<0>(data, "PitchSemitones", -12.0, 12.0, 0.0);
		addParameter<1>(data, "Scrub", 0.0, 1.0, 0.0);
		addParameter<2>(data, "GrainMs", 1.0, 500.0, 50.0);
		addParameter<3>(data, "Density", 0.0, 1.0, 1.0);
		addParameter<4>(data, "WindowShape", 0.0, 1.0, 0.0);
		addParameter<5>(data, "PanSpread", 0.0, 1.0, 0.0);
		addParameter<6>(data, "PitchMode", 0.0, 1.0, 0.0);
		addParameter<7>(data, "PitchSpreadOrSync", 0.0, 1.0, 0.0);
		addParameter<8>(data, "MaxGrains", 1.0, 32.0, 4.0);
		addParameter<9>(data, "ScrubMode", 0.0, 1.0, 0.0);
		addParameter<10>(data, "ScrubBlend", 0.0, 1.0, 0.0);
		addParameter<11>(data, "DirectionMode", 0.0, 1.0, 0.0);
		addParameter<12>(data, "PhaseScatter", 0.0, 4096.0, 0.0);
		addParameter<13>(data, "ScrubB", 0.0, 1.0, 0.0);
		addParameter<14>(data, "ScrubC", 0.0, 1.0, 0.0);
		addParameter<15>(data, "ScrubD", 0.0, 1.0, 0.0);
		addParameter<16>(data, "Density2", 0.0, 1.0, 1.0);
		addParameter<17>(data, "Diffusion", 0.0, 1.0, 1.0);
		addParameter<18>(data, "PositionSpread", 0.0, 1.0, 1.0);
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
		double alpha = 1.0 - shape;
		return tukey(x, alpha);
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
		double seed = (double) (grainIndex + 1) * 57.31 + 91.73;
		double r = std::sin(seed * 12.9898 + 78.233);
		return 0.5 + 0.5 * r;
	}

	double startSprayOffsetSamples(int grainIndex, double maxStart) const
	{
		if (phaseScatter <= 0.0 || maxStart <= 0.0)
			return 0.0;

		double maxSpray = phaseScatter;
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

	double cloudWindowPhase(double phaseNorm, int grainIndex) const
	{
		ignoreUnused(grainIndex);
		return wrap01(phaseNorm);
	}

	void updateGrainSize()
	{
		if (sampleRate <= 0.0)
			return;

		grainSize = grainMs * sampleRate * 0.001;

		if (grainSize < 16.0)
			grainSize = 16.0;

		double maxAllowed = (double) audioFile.numSamples - 2.0;
		if (maxAllowed > 16.0 && grainSize > maxAllowed)
			grainSize = maxAllowed;
	}

	void updateDelta(VoiceState& voice)
	{
		double semis = (double) voice.noteNumber - (double) rootNote;
		semis += pitchSemitones;

		double mult = std::pow(2.0, semis / 12.0);
		if (sampleRate > 0.0)
			voice.delta = (audioFile.sampleRate / sampleRate) * mult;
		else
			voice.delta = mult;
	}

	double quantiseScrub(double raw) const
	{
		if (scrubStepCount <= 1)
			return raw;

		if (audioFile.numSamples <= 1)
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

	double getFormantTargetRatio() const
	{
		double semis = pitchSyncInput;
		if (semis >= 0.0 && semis <= 1.0)
			semis = semis * 48.0 - 24.0;

		if (semis < -24.0) semis = -24.0;
		if (semis > 24.0) semis = 24.0;

		double ratio = std::pow(2.0, semis / 12.0);
		if (ratio < 0.25) ratio = 0.25;
		if (ratio > 4.0) ratio = 4.0;
		return ratio;
	}

	int getPitchState()
	{
		if (pitchMode < 0.25)
			return 0;
		if (pitchMode < 0.50)
			return 1;
		if (pitchMode < 0.75)
			return 2;
		return 3;
	}

	void updateFormantSmoothing()
	{
		double formantTarget = getFormantTargetRatio();
		double smoothCoeff = 1.0;
		if (sampleRate > 0.0)
			smoothCoeff = 1.0 - std::exp(-1.0 / (0.015 * sampleRate));

		formantRatioSmoothed += (formantTarget - formantRatioSmoothed) * smoothCoeff;
	}

	double getPitchModeMul(int pitchState, double spreadNorm, double detuneSeed, double harmonicTarget) const
	{
		if (pitchState == 0)
		{
			double spread = pitchSpread * spreadNorm;
			return 1.0 + spread * std::sin(detuneSeed);
		}
		else if (pitchState == 1)
		{
			return 1.0 + (harmonicTarget - 1.0) * pitchSpread;
		}
		else if (pitchState == 2)
		{
			return tempoSyncRatioFromInput(pitchSyncInput);
		}

		return formantRatioSmoothed;
	}

	double getGrainWeight(int i, int grainCount, bool isStackMode) const
	{
		if (i < 0 || i >= grainCount)
			return 0.0;

		if (!isStackMode)
			return 1.0;

		if (grainCount <= 1)
			return 1.0;

		int baseOn = 4;
		if (baseOn > grainCount)
			baseOn = grainCount;

		if (i < baseOn)
			return 1.0;

		double d = clamp01(density2);
		double coverage = (double) baseOn + d * (double) grainCount;
		if (coverage > (double) grainCount)
			coverage = (double) grainCount;

		const double floorWeight = 0.08;
		double edge = coverage - (double) i;
		if (edge <= 0.0)
			return floorWeight;
		if (edge >= 1.0)
			return 1.0;

		return floorWeight + (1.0 - floorWeight) * smooth01(edge);
	}

	double getReadPhaseForMode(double phase, int pitchState, double pitchMul) const
	{
		if (pitchState != 3)
			return phase;

		double ratio = pitchMul;
		if (ratio < 0.25) ratio = 0.25;
		if (ratio > 4.0) ratio = 4.0;

		double c = 0.5 * grainSize;
		double lin = c + (phase - c) / ratio;

		double x = (phase / grainSize) - 0.5;
		double shape = x * (1.0 - 4.0 * x * x);
		double amt = std::log(ratio) / std::log(2.0);
		if (amt < -2.0) amt = -2.0;
		if (amt > 2.0) amt = 2.0;
		amt *= 0.5;

		double warpSamples = amt * shape * grainSize * 0.9;
		double warped = lin + warpSamples;
		if (warped < 0.0) warped = 0.0;
		if (warped > grainSize - 1.0) warped = grainSize - 1.0;
		return warped;
	}

	double getTimelinePhaseForRead(double carrierPhase, bool timeInvariant, double readRate) const
	{
		if (!timeInvariant)
			return carrierPhase;
		if (grainSize <= 0.0)
			return 0.0;

		double ph = carrierPhase * readRate;
		return wrap01(ph / grainSize) * grainSize;
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

	double getScrubSourceForGrain(int grainIndex, int grainCount) const
	{
		ignoreUnused(grainCount);
		const double values[4] = { scrub, scrubB, scrubC, scrubD };
		return clamp01(values[(grainIndex / 2) % 4]);
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
		if (directionMode < (1.0 / 3.0))
			return 0;
		if (directionMode < (2.0 / 3.0))
			return 1;
		return 2;
	}

	void getScrubModeState(int& scrubState, bool& timeInvariant) const
	{
		scrubState = (scrubMode >= 0.5) ? 1 : 0;
		timeInvariant = false;
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

		int scrubState = 0;
		bool timeInvariant = false;
		getScrubModeState(scrubState, timeInvariant);

		const int pitchState = getPitchState();
		const int g = jlimit(1, MaxGrains, (int) std::round(maxGrainsValue));
		const bool isStackMode = (scrubBlend < 0.5);
		const bool stretchMode = true;
		const bool stretchFreezeMode = true;
		const int densitySlots = g;

		double morphDensity = clamp01(density2);
		if (!isStackMode)
		{
			if (voice.densityMorphSmoothed < 0.0)
				voice.densityMorphSmoothed = morphDensity;

			double densitySmoothCoeff = 1.0;
			if (sampleRate > 0.0)
				densitySmoothCoeff = 1.0 - std::exp(-1.0 / (0.01 * sampleRate));

			voice.densityMorphSmoothed += (morphDensity - voice.densityMorphSmoothed) * densitySmoothCoeff;
			morphDensity = voice.densityMorphSmoothed;
		}
		else
		{
			voice.densityMorphSmoothed = morphDensity;
		}

		int baseIndex = 0;
		double frac = 0.0;
		if (!isStackMode)
		{
			double pos = morphDensity * (double) (g - 1);
			if (pos < 0.0) pos = 0.0;
			if (pos > (double) (g - 1)) pos = (double) (g - 1);
			baseIndex = (int) std::floor(pos);
			frac = pos - (double) baseIndex;
		}

		std::array<double, MaxGrains> weights {};
		double sumsq = 0.0;

		int idxA = 0;
		int idxB = 0;
		double gA = 1.0;
		double gB = 0.0;

		if (!isStackMode)
		{
			idxA = jlimit(0, g - 1, baseIndex);
			idxB = jlimit(0, g - 1, baseIndex + 1);
			double t = clamp01(frac);
			gA = std::sqrt(1.0 - t);
			gB = std::sqrt(t);
			const double morphMin = 0.12;
			if (gA < morphMin) gA = morphMin;
			if (gB < morphMin) gB = morphMin;
			double gNorm = 1.0 / std::sqrt(gA * gA + gB * gB);
			gA *= gNorm;
			gB *= gNorm;
			if (g <= 1)
			{
				idxA = 0;
				idxB = 0;
				gA = 1.0;
				gB = 0.0;
			}
		}

		for (int i = 0; i < g; ++i)
		{
			double w = getGrainWeight(i, densitySlots, isStackMode);
			if (!isStackMode)
			{
				double m = ((idxA == i) ? gA : 0.0) + ((idxB == i) ? gB : 0.0);
				w *= m;
			}
			weights[(size_t) i] = w;
			sumsq += w * w;
		}

		double wnorm = 1.0;
		if (isStackMode)
			wnorm = (sumsq > 0.0 ? 1.0 / std::sqrt(sumsq) : 1.0);

		double Lsum = 0.0;
		double Rsum = 0.0;
		double center = (double) (g - 1) * 0.5;
		double invDenom = (g > 1) ? 1.0 / (double) (g - 1) : 0.0;
		int directionState = getDirectionState();
		bool lockStartOnWrap = true;
		double spreadNorm = isStackMode ? 1.0 : morphDensity;
		double stretchAnalysisHop = 0.0;
		bool scrubMoved = std::abs(previousScrub - scrub) > 0.0005;

		if (stretchMode && (voice.stretchBasePos < 0.0 || scrubMoved))
			voice.stretchBasePos = scrubSmoothed * maxStart;

		for (int i = 0; i < g; ++i)
		{
			double weight = weights[(size_t) i] * wnorm;
			if (weight <= 0.0)
				continue;

			double base = scrubSmoothed * maxStart;
			if (scrubState == 1)
			{
				if (isStackMode)
				{
					double scrubValue = getScrubSourceForGrain(i, g);
					scrubValue = quantiseScrub(scrubValue);
					base = scrubValue * maxStart;
				}
				else
				{
					base = getInterpolatedScrubForGrain(i, g) * maxStart;
				}
			}

			if (isStackMode)
			{
				double denom = (g > 1) ? (double) (g - 1) : 1.0;
				double idxNorm = (double) i / denom;
				double amt = maxStart * DensityPositionSpreadRange * clamp01(positionSpreadAmount);
				base += A2curve(idxNorm) * amt;
			}

			base += startSprayOffsetSamples(i, maxStart);

			auto& grain = voice.grains[(size_t) i];
			if (!grain.active)
			{
				grain.active = true;
				grain.phase = stretchMode ? (grainSize * (double) i / (double) g) : 0.0;
				grain.readPhase = 0.0;
				if (stretchMode)
					grain.start = voice.stretchBasePos + (double) i * stretchAnalysisHop;
				else
					grain.start = base;
			}

			double grainPitchMul = getPitchModeMul(pitchState, spreadNorm, getDetuneSeed(i), (double) (i + 1));
			double dir = getDirectionSign(directionState, i);
			double schedulerInc = timeInvariant ? dir : (voice.delta * grainPitchMul * dir);
			double readInc = schedulerInc;

			if (stretchMode)
			{
				// In stretch mode the grain window should advance in output time,
				// while note / semitone pitch only affects the source-read phase.
				schedulerInc = dir;
				readInc = voice.delta * grainPitchMul * dir;
			}

			grain.phase += schedulerInc;
			grain.readPhase += readInc;

			if (grain.phase >= grainSize)
			{
				grain.phase -= grainSize;
				if (stretchMode)
				{
					while (grain.readPhase >= grainSize)
						grain.readPhase -= grainSize;
				}
				else
				{
					grain.readPhase = grain.phase;
				}
				if (lockStartOnWrap)
				{
					if (stretchMode && !stretchFreezeMode)
						grain.start += stretchAnalysisHop * dir;
					else
						grain.start = base;
				}
			}
			if (grain.phase < 0.0)
			{
				grain.phase += grainSize;
				if (stretchMode)
				{
					while (grain.readPhase < 0.0)
						grain.readPhase += grainSize;
				}
				else
				{
					grain.readPhase = grain.phase;
				}
				if (lockStartOnWrap)
				{
					if (stretchMode && !stretchFreezeMode)
						grain.start -= stretchAnalysisHop * dir;
					else
						grain.start = base;
				}
			}

			if (stretchMode)
			{
				if (grain.start < 0.0)
					grain.start = 0.0;
				if (grain.start > maxStart)
					grain.start = maxStart;
			}

			double readCarrier = stretchMode ? grain.readPhase : grain.phase;
			double readRate = stretchMode ? grainPitchMul : (voice.delta * grainPitchMul);
			double pos = grain.start + getReadPhaseForMode(getTimelinePhaseForRead(readCarrier, timeInvariant, readRate), pitchState, grainPitchMul);
			if (pos < 0.0) pos = 0.0;
			if (pos >= audioFile.numSamples - 1.0)
				pos = audioFile.numSamples - 2.0;

			double w = morphedWindow(cloudWindowPhase(grain.phase / grainSize, i));
			double monoL = 0.0;
			double monoR = 0.0;
			readGrainStereo(i, g, pos, monoL, monoR);

			double panSlot = panOrderIndex(i, g);
			double normPan = ((panSlot - center) * invDenom);
			double pan = panSpread * normPan * 2.0;

			Lsum += monoL * w * (0.5 * (1.0 - pan)) * weight;
			Rsum += monoR * w * (0.5 * (1.0 + pan)) * weight;
		}

		double diffusion = isStackMode ? clamp01(diffusionAmount) : 0.0;
		if (diffusion > 0.0001)
		{
			double a1 = 0.08 + 0.62 * diffusion;
			double a2 = 0.04 + 0.47 * diffusion;

			double yL1 = (0.0 - a1) * Lsum + voice.ap1L;
			voice.ap1L = Lsum + a1 * yL1;
			double yR1 = (0.0 - a1) * Rsum + voice.ap1R;
			voice.ap1R = Rsum + a1 * yR1;

			double yL2 = (0.0 - a2) * yL1 + voice.ap2L;
			voice.ap2L = yL1 + a2 * yL2;
			double yR2 = (0.0 - a2) * yR1 + voice.ap2R;
			voice.ap2R = yR1 + a2 * yR2;

			double wet = 0.75 * diffusion;
			double dry = 1.0 - wet;
			Lsum = Lsum * dry + yL2 * wet;
			Rsum = Rsum * dry + yR2 * wet;
		}

		fd[0] += (float) Lsum;
		fd[1] += (float) Rsum;
	}

	ExternalData audioFile;
	PolyData<VoiceState, NV> voiceStates;
	std::array<block, MaxSourceChannels> sourceSample {};

	double sampleRate = 0.0;
	int blockSize = 0;
	int sourceChannelCount = 2;
	int sourcePairCount = 1;

	double scrub = 0.0;
	double grainMs = 50.0;
	double grainSize = 2048.0;
	double scrubB = 0.0;
	double scrubC = 0.0;
	double scrubD = 0.0;
	double pitchSemitones = 0.0;
	int rootNote = 60;
	int scrubStepCount = 64;
	double density = 1.0;
	double density2 = 1.0;
	double diffusionAmount = 1.0;
	double positionSpreadAmount = 1.0;
	double windowShape = 0.0;
	double panSpread = 0.0;
	double pitchSpread = 0.0;
	double pitchSyncInput = 0.0;
	double pitchMode = 0.0;
	double formantRatioSmoothed = 1.0;
	double maxGrainsValue = 4.0;
	double scrubMode = 0.0;
	double scrubBlend = 0.0;
	double directionMode = 0.0;
	double phaseScatter = 0.0;
};

} // namespace project
