#pragma once

#include <juce_gui_extra/juce_gui_extra.h>
#include <juce_audio_utils/juce_audio_utils.h>
#include "WaveformPanel.h"
#include "AnalysisEngine.h"
#include "SpectralAssetWriter.h"

class MainComponent : public juce::Component,
                      private juce::Button::Listener
{
public:
    MainComponent();
    ~MainComponent() override;

    void resized() override;

private:
    void buttonClicked(juce::Button* button) override;
    void loadFile();
    void analyzeSelection();
    void saveAsset();
    void auditionSource();
    void auditionAnalyzed();
    void stopPlayback();
    AnalysisSettings getAnalysisSettings() const;
    juce::AudioBuffer<float> renderAnalyzedPreviewBuffer() const;

    juce::TextButton loadButton { "Load Audio" };
    juce::TextButton analyzeButton { "Analyze" };
    juce::TextButton saveButton { "Save Asset" };
    juce::TextButton auditionSourceButton { "Audition Source" };
    juce::TextButton auditionAnalyzedButton { "Audition Spectral" };

    juce::Label sourceLabel;
    juce::Label statusLabel;
    juce::Label fftSizeLabel;
    juce::Label hopSizeLabel;
    juce::Label thresholdLabel;
    juce::Label maxPartialsLabel;
    juce::Label toleranceLabel;
    juce::Label rootHzLabel;
    juce::Label noiseLevelLabel;

    juce::ComboBox fftSizeBox;
    juce::Slider hopSizeSlider;
    juce::Slider thresholdSlider;
    juce::Slider maxPartialsSlider;
    juce::Slider toleranceSlider;
    juce::Slider rootHzSlider;
    juce::Slider noiseLevelSlider;

    WaveformPanel waveformPanel;
    AnalysisEngine analysisEngine;
    SpectralAsset currentAsset;
    juce::File currentFile;

    juce::AudioDeviceManager audioDeviceManager;
    juce::AudioSourcePlayer audioSourcePlayer;
    juce::AudioFormatManager audioFormatManager;
    juce::AudioTransportSource fileTransportSource;
    std::unique_ptr<juce::AudioFormatReaderSource> fileReaderSource;
    std::unique_ptr<juce::PositionableAudioSource> analyzedPreviewSource;
    juce::AudioSource* activePlaybackSource = nullptr;
};
