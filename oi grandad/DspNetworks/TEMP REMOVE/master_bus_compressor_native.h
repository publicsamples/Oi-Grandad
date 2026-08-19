/*
    Stereo-linked master bus compressor inspired by classic VCA bus designs.
    It is not a circuit clone, but it follows the broad behaviour we want for
    mix-bus glue: linked detection, ratio/threshold control, and smooth ballistics.
*/

#pragma once

#include <cmath>

namespace project
{
using namespace juce;
using namespace hise;
using namespace scriptnode;

template <int NV> struct master_bus_compressor_native : public data::base
{
	SNEX_NODE(master_bus_compressor_native);

	enum Parameters
	{
		Threshold,
		MakeupGain,
		Attack,
		Release,
		Ratio
	};

	struct MetadataClass
	{
		SN_NODE_ID("master_bus_compressor_native");
	};

	static constexpr bool isModNode() { return false; }
	static constexpr bool isPolyphonic() { return false; }
	static constexpr bool hasTail() { return false; }
	static constexpr bool isSuspendedOnSilence() { return false; }

	static constexpr int NumTables = 0;
	static constexpr int NumSliderPacks = 0;
	static constexpr int NumAudioFiles = 0;
	static constexpr int NumFilters = 0;
	static constexpr int NumDisplayBuffers = 0;

	void prepare(PrepareSpecs ps)
	{
		sampleRate = jmax(1.0, ps.sampleRate);
		updateTimeConstants();
		reset();
	}

	void reset()
	{
		envelope = 0.0;
		gainReductionDb = 0.0;
	}

	template <typename ProcessDataType> void process(ProcessDataType& data)
	{
		auto& dynData = data.template as<ProcessDataDyn>();
		auto** channels = dynData.getRawChannelPointers();
		const int numChannels = dynData.getNumChannels();
		const int numSamples = dynData.getNumSamples();

		for (int sampleIndex = 0; sampleIndex < numSamples; ++sampleIndex)
			processSample(channels, numChannels, sampleIndex);
	}

	template <typename FrameDataType> void processFrame(FrameDataType& data)
	{
		processFrameChannels(data.begin(), data.size());
	}

	template <int P> void setParameter(double v)
	{
		if (P == 0)
			thresholdDb = jlimit(-30.0, 0.0, v);
		else if (P == 1)
			makeupGainDb = jlimit(0.0, 24.0, v);
		else if (P == 2)
			attackMs = jlimit(0.1, 30.0, v);
		else if (P == 3)
			releaseMs = jlimit(50.0, 1200.0, v);
		else if (P == 4)
			ratio = jlimit(1.0, 10.0, v);

		updateTimeConstants();
	}

	void createParameters(ParameterDataList& data)
	{
		{
			DEFINE_PARAMETERDATA(master_bus_compressor_native, Threshold);
			p.setRange({ -30.0, 0.0, 0.1 });
			p.setSkewForCentre(-10.0);
			p.info.textConverter = parameter::pod::Decibel;
			p.setDefaultValue(-10.0);
			data.add(std::move(p));
		}

		{
			DEFINE_PARAMETERDATA(master_bus_compressor_native, MakeupGain);
			p.setRange({ 0.0, 24.0, 0.1 });
			p.setSkewForCentre(6.0);
			p.info.textConverter = parameter::pod::Decibel;
			p.setDefaultValue(0.0);
			data.add(std::move(p));
		}

		{
			DEFINE_PARAMETERDATA(master_bus_compressor_native, Attack);
			p.setRange({ 0.1, 30.0, 0.1 });
			p.setSkewForCentre(10.0);
			p.info.textConverter = parameter::pod::Time;
			p.setDefaultValue(10.0);
			data.add(std::move(p));
		}

		{
			DEFINE_PARAMETERDATA(master_bus_compressor_native, Release);
			p.setRange({ 50.0, 1200.0, 1.0 });
			p.setSkewForCentre(100.0);
			p.info.textConverter = parameter::pod::Time;
			p.setDefaultValue(100.0);
			data.add(std::move(p));
		}

		{
			DEFINE_PARAMETERDATA(master_bus_compressor_native, Ratio);
			p.setRange({ 1.0, 10.0, 0.1 });
			p.setSkewForCentre(4.0);
			p.setDefaultValue(4.0);
			data.add(std::move(p));
		}
	}

	void handleHiseEvent(HiseEvent&)
	{
	}

	private:
	static constexpr double kneeWidthDb = 3.0;
	static constexpr double detectorFloor = 1.0e-9;

	double sampleRate = 44100.0;

	double thresholdDb = -10.0;
	double makeupGainDb = 0.0;
	double attackMs = 10.0;
	double releaseMs = 100.0;
	double ratio = 4.0;

	double attackCoeff = 0.0;
	double releaseCoeff = 0.0;
	double envelope = 0.0;
	double gainReductionDb = 0.0;

	void updateTimeConstants()
	{
		attackCoeff = computeBallisticCoeff(attackMs);
		releaseCoeff = computeBallisticCoeff(releaseMs);
	}

	double computeBallisticCoeff(double timeMs) const
	{
		const double timeSeconds = jmax(0.0001, timeMs * 0.001);
		return std::exp(-1.0 / (timeSeconds * sampleRate));
	}

	double computeGainReductionDb(double inputDb) const
	{
		const double halfKnee = kneeWidthDb * 0.5;
		const double delta = inputDb - thresholdDb;

		if (delta <= -halfKnee)
			return 0.0;

		if (delta >= halfKnee)
			return (1.0 - (1.0 / ratio)) * delta;

		const double kneePos = delta + halfKnee;
		return (1.0 - (1.0 / ratio)) * (kneePos * kneePos) / (2.0 * kneeWidthDb);
	}

	void processSample(float** channels, int numChannels, int sampleIndex)
	{
		if (numChannels <= 0)
			return;

		double linkedPower = 0.0;

		for (int channelIndex = 0; channelIndex < numChannels; ++channelIndex)
		{
			const double sample = double(channels[channelIndex][sampleIndex]);
			linkedPower += sample * sample;
		}

		linkedPower /= double(numChannels);

		const double detectorCoeff = linkedPower > envelope ? attackCoeff : releaseCoeff;
		envelope = linkedPower + detectorCoeff * (envelope - linkedPower);

		const double rmsInput = std::sqrt(envelope + detectorFloor);
		const double inputDb = Decibels::gainToDecibels(rmsInput, -160.0);
		const double targetReductionDb = computeGainReductionDb(inputDb);
		const double adaptiveReleaseCoeff = computeAdaptiveReleaseCoeff();
		const double gainCoeff = targetReductionDb > gainReductionDb ? attackCoeff : adaptiveReleaseCoeff;
		gainReductionDb = targetReductionDb + gainCoeff * (gainReductionDb - targetReductionDb);

		const double linearGain = Decibels::decibelsToGain(makeupGainDb - gainReductionDb);

		for (int channelIndex = 0; channelIndex < numChannels; ++channelIndex)
			channels[channelIndex][sampleIndex] = float(double(channels[channelIndex][sampleIndex]) * linearGain);
	}

	template <typename SampleType> void processFrameChannels(SampleType* samples, int numChannels)
	{
		if (numChannels <= 0)
			return;

		double linkedPower = 0.0;

		for (int channelIndex = 0; channelIndex < numChannels; ++channelIndex)
		{
			const double sample = double(samples[channelIndex]);
			linkedPower += sample * sample;
		}

		linkedPower /= double(numChannels);

		const double detectorCoeff = linkedPower > envelope ? attackCoeff : releaseCoeff;
		envelope = linkedPower + detectorCoeff * (envelope - linkedPower);

		const double rmsInput = std::sqrt(envelope + detectorFloor);
		const double inputDb = Decibels::gainToDecibels(rmsInput, -160.0);
		const double targetReductionDb = computeGainReductionDb(inputDb);
		const double adaptiveReleaseCoeff = computeAdaptiveReleaseCoeff();
		const double gainCoeff = targetReductionDb > gainReductionDb ? attackCoeff : adaptiveReleaseCoeff;
		gainReductionDb = targetReductionDb + gainCoeff * (gainReductionDb - targetReductionDb);

		const double linearGain = Decibels::decibelsToGain(makeupGainDb - gainReductionDb);

		for (int channelIndex = 0; channelIndex < numChannels; ++channelIndex)
			samples[channelIndex] = SampleType(double(samples[channelIndex]) * linearGain);
	}

	double computeAdaptiveReleaseCoeff() const
	{
		const double recoveryWeight = jlimit(0.0, 1.0, gainReductionDb / 12.0);
		const double fastReleaseMs = jmax(20.0, releaseMs * 0.35);
		const double slowReleaseMs = jmax(fastReleaseMs, releaseMs * 1.4);
		const double blendedReleaseMs = jmap(recoveryWeight, fastReleaseMs, slowReleaseMs);
		return computeBallisticCoeff(blendedReleaseMs);
	}
};

} // namespace project
