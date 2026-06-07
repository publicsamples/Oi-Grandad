#include "MainComponent.h"

namespace
{
class BufferPreviewSource final : public juce::PositionableAudioSource
{
public:
    void setBuffer(juce::AudioBuffer<float> newBuffer)
    {
        buffer = std::move(newBuffer);
        position = 0;
    }

    void prepareToPlay(int, double) override {}
    void releaseResources() override {}

    void getNextAudioBlock(const juce::AudioSourceChannelInfo& info) override
    {
        info.clearActiveBufferRegion();

        if (buffer.getNumSamples() <= 0)
            return;

        const auto remaining = buffer.getNumSamples() - (int) position;
        if (remaining <= 0)
            return;

        const auto numToCopy = juce::jmin(info.numSamples, remaining);

        for (int ch = 0; ch < info.buffer->getNumChannels(); ++ch)
        {
            const auto sourceChannel = juce::jmin(ch, buffer.getNumChannels() - 1);
            info.buffer->copyFrom(ch, info.startSample, buffer, sourceChannel, (int) position, numToCopy);
        }

        position += numToCopy;
    }

    void setNextReadPosition(juce::int64 newPosition) override
    {
        position = juce::jlimit<juce::int64>(0, getTotalLength(), newPosition);
    }

    juce::int64 getNextReadPosition() const override { return position; }
    juce::int64 getTotalLength() const override { return buffer.getNumSamples(); }
    bool isLooping() const override { return false; }

private:
    juce::AudioBuffer<float> buffer;
    juce::int64 position = 0;
};
}

MainComponent::MainComponent()
{
    for (auto* b : { &loadButton, &analyzeButton, &saveButton, &auditionSourceButton, &auditionAnalyzedButton })
    {
        addAndMakeVisible(*b);
        b->addListener(this);
    }

    for (auto* l : { &sourceLabel, &statusLabel, &fftSizeLabel, &hopSizeLabel, &thresholdLabel,
                     &maxPartialsLabel, &toleranceLabel, &rootHzLabel, &noiseLevelLabel })
        addAndMakeVisible(*l);

    addAndMakeVisible(waveformPanel);
    addAndMakeVisible(fftSizeBox);
    addAndMakeVisible(hopSizeSlider);
    addAndMakeVisible(thresholdSlider);
    addAndMakeVisible(maxPartialsSlider);
    addAndMakeVisible(toleranceSlider);
    addAndMakeVisible(rootHzSlider);
    addAndMakeVisible(noiseLevelSlider);

    sourceLabel.setText("No file loaded", juce::dontSendNotification);
    statusLabel.setText("Idle", juce::dontSendNotification);

    fftSizeLabel.setText("FFT Size", juce::dontSendNotification);
    hopSizeLabel.setText("Hop Size", juce::dontSendNotification);
    thresholdLabel.setText("Peak Threshold", juce::dontSendNotification);
    maxPartialsLabel.setText("Max Partials", juce::dontSendNotification);
    toleranceLabel.setText("Track Tolerance", juce::dontSendNotification);
    rootHzLabel.setText("Root Hz", juce::dontSendNotification);
    noiseLevelLabel.setText("Noise Level", juce::dontSendNotification);

    fftSizeBox.addItem("1024", 1);
    fftSizeBox.addItem("2048", 2);
    fftSizeBox.addItem("4096", 3);
    fftSizeBox.setSelectedId(2);

    auto initSlider = [](juce::Slider& s, double min, double max, double value, double step)
    {
        s.setSliderStyle(juce::Slider::LinearHorizontal);
        s.setTextBoxStyle(juce::Slider::TextBoxRight, false, 80, 20);
        s.setRange(min, max, step);
        s.setValue(value);
    };

    initSlider(hopSizeSlider, 64, 2048, 512, 1);
    initSlider(thresholdSlider, -120.0, 0.0, -60.0, 0.1);
    initSlider(maxPartialsSlider, 8, 2048, 128, 1);
    initSlider(toleranceSlider, 1.0, 200.0, 25.0, 0.1);
    initSlider(rootHzSlider, 20.0, 2000.0, 220.0, 0.01);
    initSlider(noiseLevelSlider, 0.0, 1.0, 0.25, 0.001);

    audioFormatManager.registerBasicFormats();
    audioDeviceManager.initialise(0, 2, nullptr, true);
    audioDeviceManager.addAudioCallback(&audioSourcePlayer);
    analyzedPreviewSource = std::make_unique<BufferPreviewSource>();
}

MainComponent::~MainComponent()
{
    stopPlayback();
    audioSourcePlayer.setSource(nullptr);
    audioDeviceManager.removeAudioCallback(&audioSourcePlayer);

    for (auto* b : { &loadButton, &analyzeButton, &saveButton, &auditionSourceButton, &auditionAnalyzedButton })
        b->removeListener(this);
}

void MainComponent::resized()
{
    auto area = getLocalBounds().reduced(12);
    auto top = area.removeFromTop(34);
    loadButton.setBounds(top.removeFromLeft(120));
    analyzeButton.setBounds(top.removeFromLeft(100));
    saveButton.setBounds(top.removeFromLeft(100));
    auditionSourceButton.setBounds(top.removeFromLeft(130));
    auditionAnalyzedButton.setBounds(top.removeFromLeft(140));
    sourceLabel.setBounds(top);

    area.removeFromTop(8);
    auto right = area.removeFromRight(320);
    waveformPanel.setBounds(area.removeFromTop(area.getHeight() - 40));
    statusLabel.setBounds(area);

    auto row = [&](juce::Label& label, juce::Component& comp)
    {
        auto r = right.removeFromTop(40);
        label.setBounds(r.removeFromLeft(120));
        comp.setBounds(r);
        right.removeFromTop(6);
    };

    row(fftSizeLabel, fftSizeBox);
    row(hopSizeLabel, hopSizeSlider);
    row(thresholdLabel, thresholdSlider);
    row(maxPartialsLabel, maxPartialsSlider);
    row(toleranceLabel, toleranceSlider);
    row(rootHzLabel, rootHzSlider);
    row(noiseLevelLabel, noiseLevelSlider);
}

void MainComponent::buttonClicked(juce::Button* button)
{
    if (button == &loadButton) loadFile();
    if (button == &analyzeButton) analyzeSelection();
    if (button == &saveButton) saveAsset();
    if (button == &auditionSourceButton) auditionSource();
    if (button == &auditionAnalyzedButton) auditionAnalyzed();
}

void MainComponent::loadFile()
{
    juce::FileChooser chooser("Load audio file", {}, "*.wav;*.aif;*.aiff");
    if (!chooser.browseForFileToOpen())
        return;

    currentFile = chooser.getResult();
    stopPlayback();
    waveformPanel.setFile(currentFile);
    sourceLabel.setText(currentFile.getFullPathName(), juce::dontSendNotification);
    statusLabel.setText("Loaded file", juce::dontSendNotification);
}

void MainComponent::analyzeSelection()
{
    if (!currentFile.existsAsFile())
    {
        statusLabel.setText("Load a file first", juce::dontSendNotification);
        return;
    }

    statusLabel.setText("Analyzing...", juce::dontSendNotification);
    currentAsset = analysisEngine.analyzeFile(currentFile,
                                              getAnalysisSettings(),
                                              waveformPanel.getSelectionRangeSeconds());
    statusLabel.setText("Analysis complete: " + juce::String(currentAsset.frameCount) + " frames",
                        juce::dontSendNotification);
}

void MainComponent::saveAsset()
{
    if (currentAsset.frames.empty())
    {
        statusLabel.setText("Nothing to save yet", juce::dontSendNotification);
        return;
    }

    auto spectralDir = juce::File(SPECTRAL_PLAYGROUND_ASSET_DIR);
    spectralDir.createDirectory();

    auto out = spectralDir.getChildFile(currentFile.getFileNameWithoutExtension() + ".spectral.json");
    if (SpectralAssetWriter::writeJson(currentAsset, out))
        statusLabel.setText("Saved: " + out.getFileName(), juce::dontSendNotification);
    else
        statusLabel.setText("Failed to save asset", juce::dontSendNotification);
}

void MainComponent::auditionSource()
{
    if (!currentFile.existsAsFile())
    {
        statusLabel.setText("Load a file first", juce::dontSendNotification);
        return;
    }

    stopPlayback();

    std::unique_ptr<juce::AudioFormatReader> reader(audioFormatManager.createReaderFor(currentFile));
    if (reader == nullptr)
    {
        statusLabel.setText("Failed to open source audio", juce::dontSendNotification);
        return;
    }

    const auto readerSampleRate = reader->sampleRate;
    fileReaderSource = std::make_unique<juce::AudioFormatReaderSource>(reader.release(), true);
    fileTransportSource.setSource(fileReaderSource.get(), 0, nullptr, readerSampleRate);
    activePlaybackSource = &fileTransportSource;
    audioSourcePlayer.setSource(activePlaybackSource);
    fileTransportSource.setPosition(waveformPanel.getSelectionRangeSeconds().getStart());
    fileTransportSource.start();

    statusLabel.setText("Auditioning source", juce::dontSendNotification);
}

void MainComponent::auditionAnalyzed()
{
    if (currentAsset.frames.empty())
    {
        statusLabel.setText("Analyze a file first", juce::dontSendNotification);
        return;
    }

    stopPlayback();

    auto previewBuffer = renderAnalyzedPreviewBuffer();
    if (previewBuffer.getNumSamples() <= 0)
    {
        statusLabel.setText("Preview render failed", juce::dontSendNotification);
        return;
    }

    if (auto* preview = dynamic_cast<BufferPreviewSource*>(analyzedPreviewSource.get()))
    {
        preview->setBuffer(std::move(previewBuffer));
        preview->setNextReadPosition(0);
        activePlaybackSource = preview;
        audioSourcePlayer.setSource(activePlaybackSource);
        statusLabel.setText("Auditioning analyzed preview", juce::dontSendNotification);
    }
}

void MainComponent::stopPlayback()
{
    fileTransportSource.stop();
    fileTransportSource.setSource(nullptr);
    fileReaderSource.reset();
    activePlaybackSource = nullptr;
    audioSourcePlayer.setSource(nullptr);
}

juce::AudioBuffer<float> MainComponent::renderAnalyzedPreviewBuffer() const
{
    if (currentAsset.frames.empty() || currentAsset.sampleRate <= 0.0)
        return {};

    const auto totalSamples = juce::jmax(1, (int) std::ceil(currentAsset.durationSeconds * currentAsset.sampleRate));
    juce::AudioBuffer<float> buffer(2, totalSamples);
    buffer.clear();

    const auto sampleRate = currentAsset.sampleRate;
    const auto twoPi = juce::MathConstants<double>::twoPi;
    juce::HashMap<int, double> phaseById;
    juce::Random random(0x53484e4f);
    const auto noiseLevel = noiseLevelSlider.getValue();
    double lastNoise = 0.0;
    double averageFrameEnergy = 0.0;

    for (const auto& frame : currentAsset.frames)
    {
        double frameEnergy = 0.0;
        for (const auto& partial : frame.partials)
            frameEnergy += (double) partial.amplitude;
        averageFrameEnergy += frameEnergy;
    }

    averageFrameEnergy /= juce::jmax(1, currentAsset.frameCount);

    for (int frameIndex = 0; frameIndex < currentAsset.frameCount; ++frameIndex)
    {
        const auto& frame = currentAsset.frames[(size_t) frameIndex];
        const auto frameStart = juce::jlimit(0, totalSamples, (int) std::round(frame.timeSeconds * sampleRate));

        auto nextTime = frame.timeSeconds + currentAsset.hopTime;
        if (frameIndex + 1 < currentAsset.frameCount)
            nextTime = currentAsset.frames[(size_t) frameIndex + 1].timeSeconds;

        const auto frameEnd = juce::jlimit(frameStart, totalSamples, (int) std::round(nextTime * sampleRate));
        if (frameEnd <= frameStart)
            continue;

        const auto partialCount = juce::jmin<int>((int) frame.partials.size(), 128);
        double transientEnv = 0.0;
        double frameNoiseSum = 0.0;
        double frameAmpSum = 0.0;

        for (int partialIndex = 0; partialIndex < partialCount; ++partialIndex)
        {
            const auto& partial = frame.partials[(size_t) partialIndex];
            frameNoiseSum += (double) partial.amplitude * (double) partial.bandwidth;
            frameAmpSum += (double) partial.amplitude;
        }

        const double frameNoise = frameAmpSum > 1.0e-9 ? frameNoiseSum / frameAmpSum : 0.0;
        const double activityNorm = juce::jlimit(0.0, 1.0, frameAmpSum / juce::jmax(1.0e-6, averageFrameEnergy * 0.85));
        const double energyComp = frameAmpSum > 1.0e-9
            ? juce::jlimit(1.0, 2.25, std::sqrt(averageFrameEnergy / frameAmpSum))
            : 1.0;

        for (int sample = frameStart; sample < frameEnd; ++sample)
        {
            double value = 0.0;

            for (int partialIndex = 0; partialIndex < partialCount; ++partialIndex)
            {
                const auto& partial = frame.partials[(size_t) partialIndex];
                auto phase = phaseById[partial.id];
                value += (double) partial.amplitude * std::sin(phase);
                phase += twoPi * (double) partial.frequency / sampleRate;

                if (phase >= twoPi)
                    phase = std::fmod(phase, twoPi);

                phaseById.set(partial.id, phase);
            }

            transientEnv = juce::jmax(transientEnv, (double) frame.transient);
            transientEnv *= 0.995;

            const double white = random.nextDouble() * 2.0 - 1.0;
            const double hpNoise = white - lastNoise;
            lastNoise = white;

            value *= energyComp;
            value *= 1.0 + (transientEnv * activityNorm) * 0.35;
            value += hpNoise * frameNoise * noiseLevel * activityNorm * (0.015 + transientEnv * 0.12);

            const auto out = (float) (value * 0.28);
            buffer.setSample(0, sample, out);
            buffer.setSample(1, sample, out);
        }
    }

    auto maxMagnitude = 0.0f;
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        maxMagnitude = juce::jmax(maxMagnitude, buffer.getMagnitude(ch, 0, buffer.getNumSamples()));

    if (maxMagnitude > 0.0001f)
        buffer.applyGain(0.8f / maxMagnitude);

    return buffer;
}

AnalysisSettings MainComponent::getAnalysisSettings() const
{
    AnalysisSettings s;
    s.fftSize = fftSizeBox.getText().getIntValue();
    s.hopSize = (int) hopSizeSlider.getValue();
    s.peakThresholdDb = (float) thresholdSlider.getValue();
    s.maxPartials = (int) maxPartialsSlider.getValue();
    s.trackToleranceHz = (float) toleranceSlider.getValue();
    s.rootHz = rootHzSlider.getValue();
    return s;
}
