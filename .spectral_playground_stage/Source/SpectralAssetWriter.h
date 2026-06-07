#pragma once

#include "SpectralAsset.h"

class SpectralAssetWriter
{
public:
    static bool writeJson(const SpectralAsset& asset, const juce::File& outputFile);
};

