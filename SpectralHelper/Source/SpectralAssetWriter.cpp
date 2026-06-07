#include "SpectralAssetWriter.h"

bool SpectralAssetWriter::writeJson(const SpectralAsset& asset, const juce::File& outputFile)
{
    juce::DynamicObject::Ptr root = new juce::DynamicObject();
    root->setProperty("version", asset.version);
    root->setProperty("format", asset.format);
    root->setProperty("sourceFile", asset.sourceFile);
    root->setProperty("sampleRate", asset.sampleRate);
    root->setProperty("durationSeconds", asset.durationSeconds);
    root->setProperty("rootHz", asset.rootHz);
    root->setProperty("hopTime", asset.hopTime);
    root->setProperty("fftSize", asset.fftSize);
    root->setProperty("hopSizeSamples", asset.hopSizeSamples);
    root->setProperty("timedomain", asset.timedomain);
    root->setProperty("frameCount", asset.frameCount);
    root->setProperty("partialCount", asset.partialCount);

    juce::Array<juce::var> frames;
    for (const auto& frame : asset.frames)
    {
        juce::DynamicObject::Ptr frameObj = new juce::DynamicObject();
        frameObj->setProperty("time", frame.timeSeconds);
        frameObj->setProperty("transient", frame.transient);

        juce::Array<juce::var> partials;
        for (const auto& partial : frame.partials)
        {
            juce::DynamicObject::Ptr partialObj = new juce::DynamicObject();
            partialObj->setProperty("id", partial.id);
            partialObj->setProperty("frequency", partial.frequency);
            partialObj->setProperty("amplitude", partial.amplitude);
            partialObj->setProperty("bandwidth", partial.bandwidth);
            partials.add(juce::var(partialObj.get()));
        }

        frameObj->setProperty("partials", juce::var(partials));
        frames.add(juce::var(frameObj.get()));
    }

    root->setProperty("frames", juce::var(frames));

    outputFile.deleteFile();
    return outputFile.replaceWithText(juce::JSON::toString(juce::var(root.get()), true));
}
