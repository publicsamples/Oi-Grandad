#pragma once

#include <juce_core/juce_core.h>
#include "SpectralAsset.h"

class AnalysisEngine
{
public:
    SpectralAsset analyzeFile(const juce::File& file,
                              const AnalysisSettings& settings,
                              juce::Range<double> analysisRangeSeconds) const;
};
