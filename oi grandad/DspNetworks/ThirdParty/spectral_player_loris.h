/*
    Playback-only spectral player.

    This version intentionally strips the node down to the minimum needed for
    polyphonic spectral asset playback:
    - no AudioFile slot
    - no display buffer
    - no global cable manager
    - no internal analysis
    - no placeholder synthesis path
*/

#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <vector>

namespace project
{
using namespace juce;
using namespace hise;
using namespace scriptnode;

template <int NV> struct spectral_player_loris : public data::base
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
	static constexpr int NumAudioFiles = 0;
	static constexpr int NumFilters = 0;
	static constexpr int NumDisplayBuffers = 0;
	static constexpr int MaxRenderablePartials = 2048;
	static constexpr int CycleSize = 2048;

	struct PartialFrame
	{
		int id = -1;
		float frequencyHz = 0.0f;
		float amplitude = 0.0f;
		float phase = 0.0f;
		float noisiness = 0.0f;
	};

	struct AnalysisFrame
	{
		double timeSeconds = 0.0;
		float transient = 0.0f;
		float frameEnergy = 0.0f;
		std::vector<PartialFrame> partials;
		std::vector<float> harmonicGains;
		std::vector<float> harmonicPhases;
		std::vector<float> harmonicBandwidths;
		std::vector<float> waveform;
		float noiseEnergy = 0.0f;
	};

	struct SpectralCache
	{
		bool valid = false;
		double sampleRate = 44100.0;
		double durationSeconds = 0.0;
		double averageFrameEnergy = 0.0;
		std::vector<AnalysisFrame> frames;
		std::vector<float> resynthMono;

		void reset()
		{
			valid = false;
			sampleRate = 44100.0;
			durationSeconds = 0.0;
			averageFrameEnergy = 0.0;
			frames.clear();
			resynthMono.clear();
		}
	};

	struct VoiceState
	{
		bool active = false;
		int noteNumber = 60;
		double pitchRatio = 1.0;
		double scrubPosition = 0.0;
		double lastScrubPosition = -1.0;
		double oscillatorPhase = 0.0;
		double resynthReadPos = 0.0;
		double transientEnvelope = 0.0;
		double lastNoise = 0.0;
		int lastFrameIndex = -1;
		uint32 noiseState = 0x12345678u;
		std::array<double, MaxRenderablePartials> partialPhases {};

		void reset()
		{
			active = false;
			noteNumber = 60;
			pitchRatio = 1.0;
			scrubPosition = 0.0;
			lastScrubPosition = -1.0;
			oscillatorPhase = 0.0;
			resynthReadPos = 0.0;
			transientEnvelope = 0.0;
			lastNoise = 0.0;
			lastFrameIndex = -1;
			noiseState = 0x12345678u;
			partialPhases.fill(0.0);
		}
	};

	void prepare(PrepareSpecs ps)
	{
		sampleRate = ps.sampleRate;
		blockSize = ps.blockSize;
		voiceStates.prepare(ps);
		reset();
		reloadCacheFromSelection();
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
		auto fixFrame = span<float, 2>::as(data.begin());
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
		updatePitchRatio(voice);
	}

	void setExternalData(const ExternalData&, int)
	{
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
		if (P == 2) spectralBlend = clamp01(v);
		if (P == 3) partialCount = jlimit(1.0, 2048.0, std::round(v));
		if (P == 4) debugMode = jlimit(0.0, 2.0, std::round(v));
		if (P == 5)
		{
			assetIndex = jmax(0, (int) std::round(v));
			reloadCacheFromSelection();
		}
		if (P == 6) transientMix = clamp01(v);
	}

	void createParameters(ParameterDataList& data)
	{
		addParameter<0>(data, "Scrub", 0.0, 1.0, 0.0);
		addParameter<1>(data, "PitchSemitones", -24.0, 24.0, 0.0);
		addParameter<2>(data, "SpectralBlend", 0.0, 1.0, 0.5);
		addParameter<3>(data, "PartialCount", 1.0, 2048.0, 256.0);
		addParameter<4>(data, "DebugMode", 0.0, 2.0, 1.0);
		addParameter<5>(data, "AssetIndex", 0.0, 512.0, 0.0);
		addParameter<6>(data, "TransientMix", 0.0, 1.0, 0.5);
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

	double wrap01(double x) const
	{
		x -= std::floor(x);
		return x;
	}

	void updatePitchRatio(VoiceState& voice)
	{
		double semis = (double) voice.noteNumber - (double) rootNote;
		semis += pitchSemitones;
		voice.pitchRatio = std::pow(2.0, semis / 12.0);
	}

	File getPreferredCacheFile() const
	{
		return File("/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/AudioFiles/spectral_cache_current.json");
	}

	File getSpectralAssetDirectory() const
	{
		return File("/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/AudioFiles/Spectral");
	}

	File getSelectedAssetFile() const
	{
		if (assetIndex <= 0)
			return {};

		auto spectralDir = getSpectralAssetDirectory();
		if (!spectralDir.isDirectory())
			return {};

		Array<File> files;
		spectralDir.findChildFiles(files, File::findFiles, false, "*.spectral.json");
		files.sort();

		const int idx = assetIndex - 1;
		if (idx < 0 || idx >= files.size())
			return {};

		return files.getReference(idx);
	}

	void reloadCacheFromSelection()
	{
		auto selectedAssetFile = getSelectedAssetFile();
		auto cacheFile = selectedAssetFile.existsAsFile() ? selectedAssetFile : getPreferredCacheFile();
		auto debugCacheFile = File("/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/AudioFiles/spectral_cache_debug.json");

		if ((cacheFile == File() || !loadCacheFromJsonFile(cacheFile)) &&
			!loadCacheFromJsonFile(debugCacheFile))
			cache.reset();
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

	bool loadCacheFromJsonFile(const File& f)
	{
		if (!f.existsAsFile())
			return false;

		auto parsed = JSON::parse(f);
		if (parsed.isVoid())
			return false;

		auto* root = parsed.getDynamicObject();
		if (root == nullptr)
			return false;

		auto framesVar = root->getProperty("frames");
		if (!framesVar.isArray())
			return false;

		auto* framesArray = framesVar.getArray();
		if (framesArray == nullptr || framesArray->isEmpty())
			return false;

		cache.reset();
		cache.sampleRate = (double) root->getProperty("sampleRate");
		cache.durationSeconds = (double) root->getProperty("durationSeconds");

		double energySumForAverage = 0.0;
		int energyFrameCount = 0;

		for (const auto& frameVar : *framesArray)
		{
			auto* frameObj = frameVar.getDynamicObject();
			if (frameObj == nullptr)
				continue;

			AnalysisFrame frame;
			frame.timeSeconds = (double) frameObj->getProperty("time");
			frame.transient = (float) (double) frameObj->getProperty("transient");

			auto readFloatArray = [](const var& v, std::vector<float>& dst)
			{
				dst.clear();
				if (!v.isArray())
					return;

				if (auto* a = v.getArray())
				{
					dst.reserve((size_t) a->size());
					for (const auto& item : *a)
						dst.push_back((float) (double) item);
				}
			};

			readFloatArray(frameObj->getProperty("gains"), frame.harmonicGains);
			readFloatArray(frameObj->getProperty("phases"), frame.harmonicPhases);
			readFloatArray(frameObj->getProperty("bandwidth"), frame.harmonicBandwidths);

			auto partialsVar = frameObj->getProperty("partials");
			if (partialsVar.isArray())
			{
				if (auto* partialsArray = partialsVar.getArray())
				{
					frame.partials.reserve((size_t) partialsArray->size());
					for (const auto& partialVar : *partialsArray)
					{
						auto* partialObj = partialVar.getDynamicObject();
						if (partialObj == nullptr)
							continue;

						PartialFrame p;
						p.id = (int) partialObj->getProperty("id");
						p.frequencyHz = (float) (double) partialObj->getProperty("frequency");
						p.amplitude = (float) (double) partialObj->getProperty("amplitude");
						p.phase = (float) (double) partialObj->getProperty("phase");
						p.noisiness = (float) (double) partialObj->getProperty("bandwidth");
						frame.partials.push_back(p);
					}
				}
			}

			if (frame.harmonicGains.empty() && !frame.partials.empty())
			{
				frame.harmonicGains.assign((size_t) MaxRenderablePartials, 0.0f);
				frame.harmonicPhases.assign((size_t) MaxRenderablePartials, 0.0f);
				frame.harmonicBandwidths.assign((size_t) MaxRenderablePartials, 0.0f);

				const double rootHz = (double) root->getProperty("rootHz");
				const double safeRootHz = rootHz > 20.0 ? rootHz : 220.0;

				for (const auto& p : frame.partials)
				{
					if (p.frequencyHz <= 0.0f || p.amplitude <= 0.0f)
						continue;

					const int harmonicIndex = (int) std::round((double) p.frequencyHz / safeRootHz) - 1;
					if (harmonicIndex < 0 || harmonicIndex >= MaxRenderablePartials)
						continue;

					frame.harmonicGains[(size_t) harmonicIndex] += p.amplitude;
					frame.harmonicPhases[(size_t) harmonicIndex] = p.phase;
					frame.harmonicBandwidths[(size_t) harmonicIndex] = jmax(frame.harmonicBandwidths[(size_t) harmonicIndex], p.noisiness);
				}

				while (!frame.harmonicGains.empty() && frame.harmonicGains.back() == 0.0f)
				{
					frame.harmonicGains.pop_back();
					frame.harmonicPhases.pop_back();
					frame.harmonicBandwidths.pop_back();
				}
			}

			if (frame.harmonicGains.empty())
				continue;

			float noiseWeightedSum = 0.0f;
			float gainWeightedSum = 0.0f;
			const int count = jmin((int) frame.harmonicGains.size(), (int) frame.harmonicBandwidths.size());
			for (int i = 0; i < count; ++i)
			{
				const float g = std::abs(frame.harmonicGains[(size_t) i]);
				gainWeightedSum += g;
				noiseWeightedSum += g * jlimit(0.0f, 1.0f, frame.harmonicBandwidths[(size_t) i]);
			}

			frame.noiseEnergy = gainWeightedSum > 0.0f ? noiseWeightedSum / gainWeightedSum : 0.0f;
			frame.frameEnergy = gainWeightedSum;
			if (frame.noiseEnergy <= 1.0e-4f && !frame.partials.empty())
				frame.noiseEnergy = 0.2f;
			buildWaveformFromHarmonics(frame);
			energySumForAverage += frame.frameEnergy;
			++energyFrameCount;
			cache.frames.push_back(std::move(frame));
		}

		cache.valid = !cache.frames.empty();
		cache.averageFrameEnergy = energyFrameCount > 0 ? energySumForAverage / (double) energyFrameCount : 0.0;
		if (cache.durationSeconds <= 0.0 && !cache.frames.empty())
			cache.durationSeconds = cache.frames.back().timeSeconds;
		return cache.valid;
	}

	template <typename FrameType> void renderFrame(FrameType& fd, VoiceState& voice)
	{
		if (!voice.active || sampleRate <= 0.0)
			return;

		voice.scrubPosition = scrub;

		const double rootFrequency = 440.0 * std::pow(2.0, ((double) rootNote - 69.0) / 12.0);
		const double oscFrequency = rootFrequency * voice.pitchRatio;
		voice.oscillatorPhase = wrap01(voice.oscillatorPhase + oscFrequency / sampleRate);

		if (debugMode >= 2.0)
		{
			const double sine = std::sin(voice.oscillatorPhase * MathConstants<double>::twoPi);
			const float s = (float) (sine * 0.15);
			fd[0] += s;
			fd[1] += s;
			return;
		}

		if (!cache.valid || cache.frames.empty())
			return;

		const double voiceOutputGain = isPolyphonic() ? 0.32 : 0.7;

		const double maxTime = cache.durationSeconds > 0.0 ? cache.durationSeconds : cache.frames.back().timeSeconds;
		const double targetTime = scrub * maxTime;
		int frameA = 0;
		int frameB = 0;
		double frameT = 0.0;

		if (cache.frames.size() > 1)
		{
			auto it = std::lower_bound(cache.frames.begin(), cache.frames.end(), targetTime,
				[](const AnalysisFrame& frame, double t)
				{
					return frame.timeSeconds < t;
				});

			if (it == cache.frames.begin())
			{
				frameA = 0;
				frameB = 1;
			}
			else if (it == cache.frames.end())
			{
				frameA = (int) cache.frames.size() - 2;
				frameB = (int) cache.frames.size() - 1;
			}
			else
			{
				frameB = (int) std::distance(cache.frames.begin(), it);
				frameA = frameB - 1;
			}

			const double timeA = cache.frames[(size_t) frameA].timeSeconds;
			const double timeB = cache.frames[(size_t) frameB].timeSeconds;
			const double denom = timeB - timeA;
			if (denom > 1.0e-9)
				frameT = jlimit(0.0, 1.0, (targetTime - timeA) / denom);
		}

		const auto& a = cache.frames[(size_t) frameA];
		const auto& b = cache.frames[(size_t) frameB];
		if (a.waveform.empty() || b.waveform.empty())
			return;

		const double transientLevel = (1.0 - frameT) * a.transient + frameT * b.transient;
		const double frameEnergy = (1.0 - frameT) * a.frameEnergy + frameT * b.frameEnergy;
		const double averageFrameEnergy = jmax(1.0e-6, cache.averageFrameEnergy);
		const double activityNorm = jlimit(0.0, 1.0, frameEnergy / (averageFrameEnergy * 0.85));
		if (frameA != voice.lastFrameIndex)
		{
			voice.transientEnvelope = jmax(voice.transientEnvelope, transientLevel * activityNorm);
			voice.lastFrameIndex = frameA;
		}
		voice.transientEnvelope *= 0.992;

		if (debugMode >= 1.5 && debugMode < 2.0 && !cache.resynthMono.empty())
		{
			const double scrubJump = std::abs(scrub - voice.lastScrubPosition);
			if (voice.lastScrubPosition < 0.0 || scrubJump > 0.002)
			{
				const double maxPos = (double) jmax(0, (int) cache.resynthMono.size() - 1);
				voice.resynthReadPos = scrub * maxPos;
			}

			voice.lastScrubPosition = scrub;
			const double increment = jmax(0.125, voice.pitchRatio);
			const double maxPos = (double) cache.resynthMono.size();
			const double pos = std::fmod(voice.resynthReadPos, maxPos);
			const int i0 = jlimit(0, (int) cache.resynthMono.size() - 1, (int) std::floor(pos));
			const int i1 = (i0 + 1) % (int) cache.resynthMono.size();
			const double t = pos - std::floor(pos);
			const double s0 = cache.resynthMono[(size_t) i0];
			const double s1 = cache.resynthMono[(size_t) i1];
			const float s = (float) std::tanh((s0 + (s1 - s0) * t) * voiceOutputGain);
			voice.resynthReadPos += increment;
			fd[0] += s;
			fd[1] += s;
			return;
		}

		if (!a.partials.empty())
		{
			const auto& current = cache.frames[(size_t) ((frameT < 0.5) ? frameA : frameB)];
			const int partialLimit = jmin(jlimit(1, MaxRenderablePartials, (int) partialCount),
										  (int) current.partials.size());
			const double partialMix = jlimit(0.0, 1.0, 2.0 * (1.0 - spectralBlend));
			const double noiseMix = jlimit(0.0, 1.0, 2.0 * spectralBlend);
			double sum = 0.0;
			double gainSum = 0.0;
			double noiseWeightedSum = 0.0;
			double totalFrameAmplitude = 0.0;
			double selectedFrameAmplitude = 0.0;
			const double targetCoverage = 0.96;

			for (const auto& p : current.partials)
			{
				if (p.id < 0 || p.id >= MaxRenderablePartials || p.amplitude <= 0.0f)
					continue;

				totalFrameAmplitude += std::abs((double) p.amplitude);
			}

			for (int i = 0; i < partialLimit; ++i)
			{
				const auto& p = current.partials[(size_t) i];
				if (p.id < 0 || p.id >= MaxRenderablePartials || p.amplitude <= 0.0f)
					continue;

				const double frequency = (double) p.frequencyHz * voice.pitchRatio;
				if (frequency <= 0.0 || frequency >= sampleRate * 0.45)
					continue;

				auto& phase = voice.partialPhases[(size_t) p.id];
				phase += MathConstants<double>::twoPi * frequency / sampleRate;
				if (phase >= MathConstants<double>::twoPi)
					phase = std::fmod(phase, MathConstants<double>::twoPi);

				sum += std::sin(phase) * (double) p.amplitude;
				const double amp = std::abs((double) p.amplitude);
				gainSum += amp;
				selectedFrameAmplitude += amp;
				noiseWeightedSum += amp * (double) p.noisiness;

				if (totalFrameAmplitude > 1.0e-9 && selectedFrameAmplitude / totalFrameAmplitude >= targetCoverage)
					break;
			}

			const double averageNoise = gainSum > 1.0e-9 ? noiseWeightedSum / gainSum : 0.0;
			const double energyComp = gainSum > 1.0e-9
				? jlimit(1.0, 2.25, std::sqrt(averageFrameEnergy / gainSum))
				: 1.0;
			const double partialNorm = gainSum > 1.0e-9 ? (0.9 / std::sqrt(gainSum)) : 0.0;
			sum *= partialNorm * partialMix;
			sum *= energyComp;

			voice.noiseState = voice.noiseState * 1664525u + 1013904223u;
			const double white = ((double) ((voice.noiseState >> 8) & 0x00ffffff) / 8388607.5) - 1.0;
			const double hpNoise = white - voice.lastNoise;
			voice.lastNoise = white;
			const double transientBoost = jlimit(0.0, 1.0, voice.transientEnvelope) * activityNorm;
			const double broadbandNoise = hpNoise * averageNoise * noiseMix * activityNorm * (0.015 + transientBoost * 0.12);
			const double transientLayer = hpNoise * transientBoost * transientMix * 0.22;
			sum += broadbandNoise + transientLayer;
			sum *= 1.0 + transientBoost * transientMix * 0.45;

			const float s = (float) std::tanh(sum * voiceOutputGain);
			voice.lastScrubPosition = scrub;
			fd[0] += s;
			fd[1] += s;
			return;
		}

		const int harmonicLimit = jmin(jlimit(1, MaxRenderablePartials, (int) partialCount),
									   jmin((int) a.harmonicGains.size(), (int) b.harmonicGains.size()));
		const double partialMix = jlimit(0.0, 1.0, 2.0 * (1.0 - spectralBlend));
		const double noiseMix = jlimit(0.0, 1.0, 2.0 * spectralBlend);

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
			sum *= partialWeight * partialMix;

		const double harmonicEnergyComp = frameEnergy > 1.0e-9
			? jlimit(1.0, 2.25, std::sqrt(averageFrameEnergy / frameEnergy))
			: 1.0;
		sum *= harmonicEnergyComp;

		const double noiseAmt = ((1.0 - frameT) * a.noiseEnergy + frameT * b.noiseEnergy) * noiseMix;
		voice.noiseState = voice.noiseState * 1664525u + 1013904223u;
		const double white = ((double) ((voice.noiseState >> 8) & 0x00ffffff) / 8388607.5) - 1.0;
		const double hpNoise = white - voice.lastNoise;
		voice.lastNoise = white;
		const double transientBoost = jlimit(0.0, 1.0, voice.transientEnvelope) * activityNorm;
		if (debugMode < 0.5)
			sum += hpNoise * noiseAmt * activityNorm * (0.015 + transientBoost * 0.12);

		if (debugMode < 0.5 && transientMix > 0.0)
		{
			sum += hpNoise * transientBoost * transientMix * 0.22;
			sum *= 1.0 + transientBoost * transientMix * 0.45;
		}

		const float s = (float) std::tanh(sum * voiceOutputGain);
		voice.lastScrubPosition = scrub;
		fd[0] += s;
		fd[1] += s;
	}

	PolyData<VoiceState, NV> voiceStates;
	SpectralCache cache;

	double sampleRate = 44100.0;
	int blockSize = 0;
	double scrub = 0.0;
	double pitchSemitones = 0.0;
	double spectralBlend = 0.5;
	double partialCount = 256.0;
	double debugMode = 0.0;
	int assetIndex = 0;
	double transientMix = 0.5;
	int rootNote = 60;
};

} // namespace project
