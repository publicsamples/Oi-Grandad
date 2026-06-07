#pragma once

#include <juce_core/juce_core.h>

struct PartialPoint
{
    int id = -1;
    float frequency = 0.0f;
    float amplitude = 0.0f;
    float bandwidth = 0.0f;
};

struct SpectralFrame
{
    double timeSeconds = 0.0;
    float transient = 0.0f;
    std::vector<PartialPoint> partials;
};

struct SpectralAsset
{
    int version = 1;
    juce::String format = "sparse-partials-v1";
    juce::String sourceFile;
    double sampleRate = 0.0;
    double durationSeconds = 0.0;
    double rootHz = 220.0;
    double hopTime = 0.01;
    int fftSize = 2048;
    int hopSizeSamples = 512;
    juce::String timedomain = "seconds";
    int frameCount = 0;
    int partialCount = 0;
    std::vector<SpectralFrame> frames;
};

struct AnalysisSettings
{
    int fftSize = 2048;
    int hopSize = 512;
    float peakThresholdDb = -60.0f;
    int maxPartials = 128;
    float trackToleranceHz = 25.0f;
    double rootHz = 220.0;
};
