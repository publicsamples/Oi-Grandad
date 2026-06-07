#include "WaveformPanel.h"

WaveformPanel::WaveformPanel()
    : thumbnail(512, formatManager, thumbnailCache)
{
    formatManager.registerBasicFormats();
}

void WaveformPanel::setFile(const juce::File& file)
{
    thumbnail.clear();
    if (file.existsAsFile())
    {
        thumbnail.setSource(new juce::FileInputSource(file));
        fileRangeSeconds = { 0.0, thumbnail.getTotalLength() };
    }
    else
    {
        fileRangeSeconds = { 0.0, 1.0 };
    }

    clearSelection();
    repaint();
}

juce::Range<double> WaveformPanel::getSelectionRangeSeconds() const
{
    if (hasSelection)
        return selectionRangeSeconds;

    return fileRangeSeconds;
}

void WaveformPanel::clearSelection()
{
    hasSelection = false;
    selectionRangeSeconds = { 0.0, 0.0 };
}

void WaveformPanel::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black.withAlpha(0.9f));

    auto bounds = getLocalBounds();
    g.setColour(juce::Colours::darkgrey);
    g.drawRect(bounds);

    if (thumbnail.getTotalLength() > 0.0)
    {
        g.setColour(juce::Colours::white);
        thumbnail.drawChannels(g, bounds, fileRangeSeconds.getStart(), fileRangeSeconds.getEnd(), 1.0f);
    }

    if (hasSelection)
    {
        auto x1 = (float) timeToX(selectionRangeSeconds.getStart());
        auto x2 = (float) timeToX(selectionRangeSeconds.getEnd());
        g.setColour(juce::Colours::gold.withAlpha(0.2f));
        g.fillRect(juce::Rectangle<float>(x1, 0.0f, x2 - x1, (float) getHeight()));
        g.setColour(juce::Colours::gold);
        g.drawRect(juce::Rectangle<float>(x1, 0.0f, x2 - x1, (float) getHeight()), 1.5f);
    }
}

void WaveformPanel::mouseDown(const juce::MouseEvent& event)
{
    auto t = xToTime(event.x);
    selectionRangeSeconds = { t, t };
    hasSelection = true;
    repaint();
}

void WaveformPanel::mouseDrag(const juce::MouseEvent& event)
{
    auto start = selectionRangeSeconds.getStart();
    auto end = xToTime(event.x);
    selectionRangeSeconds = { juce::jmin(start, end), juce::jmax(start, end) };
    repaint();
}

void WaveformPanel::mouseDoubleClick(const juce::MouseEvent&)
{
    clearSelection();
    repaint();
}

double WaveformPanel::xToTime(int x) const
{
    if (getWidth() <= 0)
        return 0.0;

    auto norm = juce::jlimit(0.0, 1.0, (double) x / (double) getWidth());
    return fileRangeSeconds.getStart() + norm * fileRangeSeconds.getLength();
}

int WaveformPanel::timeToX(double timeSeconds) const
{
    if (fileRangeSeconds.getLength() <= 0.0)
        return 0;

    auto norm = (timeSeconds - fileRangeSeconds.getStart()) / fileRangeSeconds.getLength();
    return (int) std::round(norm * (double) getWidth());
}
