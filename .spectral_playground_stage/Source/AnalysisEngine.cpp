#include "AnalysisEngine.h"

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_audio_formats/juce_audio_formats.h>
#include <juce_dsp/juce_dsp.h>

#include <cmath>

SpectralAsset AnalysisEngine::analyzeFile(const juce::File& file,
                                          const AnalysisSettings& settings,
                                          juce::Range<double> analysisRangeSeconds) const
{
    SpectralAsset asset;
    asset.sourceFile = file.getFullPathName();
    asset.rootHz = settings.rootHz;
    asset.hopTime = settings.hopSize > 0 ? (double) settings.hopSize / 44100.0 : 0.01;
    asset.fftSize = settings.fftSize;
    asset.hopSizeSamples = settings.hopSize;
    asset.format = "sparse-partials-v1";
    asset.timedomain = "seconds";

    juce::AudioFormatManager formatManager;
    formatManager.registerBasicFormats();

    std::unique_ptr<juce::AudioFormatReader> reader(formatManager.createReaderFor(file));
    if (reader == nullptr)
        return asset;

    asset.sampleRate = reader->sampleRate;

    const auto totalDuration = (double) reader->lengthInSamples / reader->sampleRate;
    auto start = juce::jlimit(0.0, totalDuration, analysisRangeSeconds.getStart());
    auto end = juce::jlimit(0.0, totalDuration, analysisRangeSeconds.getEnd());

    if (end <= start)
        end = totalDuration;

    const auto startSample = (juce::int64) std::floor(start * reader->sampleRate);
    const auto endSample = (juce::int64) std::ceil(end * reader->sampleRate);
    const auto numSamples = juce::jmax<juce::int64>(0, endSample - startSample);

    if (numSamples <= settings.fftSize)
        return asset;

    juce::AudioBuffer<float> fileBuffer((int) reader->numChannels, (int) numSamples);
    reader->read(&fileBuffer, 0, (int) numSamples, startSample, true, true);

    juce::AudioBuffer<float> monoBuffer(1, (int) numSamples);
    monoBuffer.clear();

    for (int ch = 0; ch < fileBuffer.getNumChannels(); ++ch)
        monoBuffer.addFrom(0, 0, fileBuffer, ch, 0, (int) numSamples, 1.0f / (float) fileBuffer.getNumChannels());

    const int fftSize = settings.fftSize;
    const int hopSize = juce::jmax(1, settings.hopSize);
    const int fftOrder = (int) std::round(std::log2((double) fftSize));
    juce::dsp::FFT fft(fftOrder);
    juce::dsp::WindowingFunction<float> window((size_t) fftSize, juce::dsp::WindowingFunction<float>::hann, false);

    std::vector<float> fftData((size_t) fftSize * 2, 0.0f);
    std::vector<float> magnitudes((size_t) fftSize / 2, 0.0f);
    std::vector<float> previousMagnitudes((size_t) fftSize / 2, 0.0f);
    std::vector<int> activeTrackIds;
    std::vector<float> activeTrackFrequencies;
    int nextTrackId = 0;
    int maxAssignedTrackId = -1;

    const auto* mono = monoBuffer.getReadPointer(0);
    const float minMagnitude = std::pow(10.0f, settings.peakThresholdDb / 20.0f);

    for (int frameStart = 0; frameStart < monoBuffer.getNumSamples(); frameStart += hopSize)
    {
        std::fill(fftData.begin(), fftData.end(), 0.0f);
        const auto availableSamples = juce::jmin(fftSize, monoBuffer.getNumSamples() - frameStart);
        if (availableSamples <= 0)
            break;

        std::copy(mono + frameStart, mono + frameStart + availableSamples, fftData.begin());
        window.multiplyWithWindowingTable(fftData.data(), fftSize);
        fft.performRealOnlyForwardTransform(fftData.data());

        for (int bin = 0; bin < fftSize / 2; ++bin)
        {
            const auto real = fftData[(size_t) bin * 2];
            const auto imag = fftData[(size_t) bin * 2 + 1];
            magnitudes[(size_t) bin] = std::sqrt(real * real + imag * imag) / (float) fftSize;
        }

        struct Peak
        {
            float frequency = 0.0f;
            float amplitude = 0.0f;
            float bandwidth = 0.0f;
        };

        std::vector<Peak> peaks;
        peaks.reserve((size_t) settings.maxPartials);

        for (int bin = 1; bin < (fftSize / 2) - 1; ++bin)
        {
            const auto left = magnitudes[(size_t) bin - 1];
            const auto centre = magnitudes[(size_t) bin];
            const auto right = magnitudes[(size_t) bin + 1];

            if (centre < minMagnitude || centre <= left || centre <= right)
                continue;

            float delta = 0.0f;
            const auto denom = left - 2.0f * centre + right;
            if (std::abs(denom) > 1.0e-12f)
                delta = 0.5f * (left - right) / denom;

            const auto interpolatedBin = (float) bin + juce::jlimit(-0.5f, 0.5f, delta);
            const auto frequency = interpolatedBin * (float) reader->sampleRate / (float) fftSize;
            const auto localSum = left + centre + right;
            const auto sideEnergy = left + right;
            auto bandwidth = 0.0f;

            if (localSum > 1.0e-12f)
                bandwidth = juce::jlimit(0.0f, 1.0f, sideEnergy / localSum);

            peaks.push_back({ frequency, centre, bandwidth });
        }

        std::sort(peaks.begin(), peaks.end(), [](const Peak& a, const Peak& b)
        {
            return a.amplitude > b.amplitude;
        });

        if ((int) peaks.size() > settings.maxPartials)
            peaks.resize((size_t) settings.maxPartials);

        SpectralFrame frame;
        frame.timeSeconds = start + (double) frameStart / reader->sampleRate;
        double weightedFlux = 0.0;
        double weightedEnergy = 0.0;

        for (int bin = 0; bin < fftSize / 2; ++bin)
        {
            const auto mag = magnitudes[(size_t) bin];
            const auto prev = previousMagnitudes[(size_t) bin];
            const auto rise = juce::jmax(0.0f, mag - prev);
            const auto weight = (double) bin / (double) juce::jmax(1, (fftSize / 2) - 1);
            weightedFlux += (double) rise * (0.25 + 0.75 * weight);
            weightedEnergy += (double) mag * (0.25 + 0.75 * weight);
        }

        if (weightedEnergy > 1.0e-12)
            frame.transient = (float) juce::jlimit(0.0, 1.0, (weightedFlux / weightedEnergy) * 3.0);
        else
            frame.transient = 0.0f;

        std::vector<int> nextActiveIds;
        std::vector<float> nextActiveFrequencies;

        for (const auto& peak : peaks)
        {
            int bestTrackId = -1;
            int bestTrackIndex = -1;
            float bestDistance = std::numeric_limits<float>::max();

            for (int i = 0; i < (int) activeTrackIds.size(); ++i)
            {
                const auto distance = std::abs(activeTrackFrequencies[(size_t) i] - peak.frequency);
                if (distance <= settings.trackToleranceHz && distance < bestDistance)
                {
                    bestDistance = distance;
                    bestTrackId = activeTrackIds[(size_t) i];
                    bestTrackIndex = i;
                }
            }

            if (bestTrackId < 0)
                bestTrackId = nextTrackId++;
            else if (bestTrackIndex >= 0)
            {
                activeTrackIds.erase(activeTrackIds.begin() + bestTrackIndex);
                activeTrackFrequencies.erase(activeTrackFrequencies.begin() + bestTrackIndex);
            }

            maxAssignedTrackId = juce::jmax(maxAssignedTrackId, bestTrackId);
            nextActiveIds.push_back(bestTrackId);
            nextActiveFrequencies.push_back(peak.frequency);
            frame.partials.push_back({ bestTrackId, peak.frequency, peak.amplitude, peak.bandwidth });
        }

        activeTrackIds = std::move(nextActiveIds);
        activeTrackFrequencies = std::move(nextActiveFrequencies);
        asset.frames.push_back(std::move(frame));
        previousMagnitudes = magnitudes;
    }

    asset.durationSeconds = end - start;
    asset.hopTime = (double) hopSize / reader->sampleRate;
    asset.frameCount = (int) asset.frames.size();
    asset.partialCount = juce::jmax(0, maxAssignedTrackId + 1);
    return asset;
}
