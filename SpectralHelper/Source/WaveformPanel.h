#pragma once

#include <juce_audio_utils/juce_audio_utils.h>

class WaveformPanel : public juce::Component
{
public:
    WaveformPanel();

    void setFile(const juce::File& file);
    juce::Range<double> getSelectionRangeSeconds() const;
    void clearSelection();

    void paint(juce::Graphics& g) override;
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDrag(const juce::MouseEvent& event) override;
    void mouseDoubleClick(const juce::MouseEvent&) override;

private:
    double xToTime(int x) const;
    int timeToX(double timeSeconds) const;

    juce::AudioFormatManager formatManager;
    juce::AudioThumbnailCache thumbnailCache { 8 };
    juce::AudioThumbnail thumbnail;
    juce::Range<double> fileRangeSeconds { 0.0, 1.0 };
    juce::Range<double> selectionRangeSeconds { 0.0, 0.0 };
    bool hasSelection = false;
};
