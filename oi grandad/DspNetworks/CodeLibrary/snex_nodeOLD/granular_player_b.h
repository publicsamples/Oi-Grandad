template <int NV>
struct granular_player_b
{
    SNEX_NODE(granular_player_b);

    // Explicitly declare this node is block-based only
    static const bool kIsFrameBased = false;
    static const int NUM_CHANNELS = 2;

    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 48000.0;

    // ============================
    // Parameters
    // ============================
    double scrub = 0.0;          // 0..1 UI target
    double grainMs = 50.0;
    double grainSize = 2048.0;

    double scrubSmoothMs = 0.0;  // 0 = off, >0 = interpolation active

    double pitchSemitones = 0.0;
    int rootNote = 60;

    // ============================
    // Per-voice data
    // ============================
    struct VoiceData
    {
        double phase = 0.0;          // position inside grain window
        double delta = 1.0;
        int noteNumber = 60;

        double scrubActual = 0.0;    // interpolated scrub
        double scrubStep = 0.0;      // how much scrub moves per sample
        int scrubSamplesLeft = 0;

        void reset()
        {
            phase = 0.0;
            scrubActual = 0.0;
            scrubStep = 0.0;
            scrubSamplesLeft = 0;
        }
    };

    PolyData<VoiceData, NV> voiceData;

    // ============================
    // Init
    // ============================
    void prepare(PrepareSpecs ps)
    {
        sr = ps.sampleRate;
        voiceData.prepare(ps);
    }

    void reset()
    {
        for (auto& v : voiceData)
            v.reset();
    }

    inline double hann(double x)
    {
        return 0.5 - 0.5 * Math.cos(2.0 * Math.PI * x);
    }

    // ============================
    // Pitch
    // ============================
    void updateDelta(VoiceData& v)
    {
        double midiSemis = (double)v.noteNumber - (double)rootNote;
        double total = midiSemis + pitchSemitones;
        v.delta = Math.pow(2.0, total / 12.0);
    }

    void updateGrainSize()
    {
        grainSize = grainMs * sr * 0.001;
        if (grainSize < 16.0)
            grainSize = 16.0;
        double maxAllowed = (double)data.numSamples - 2.0;
        if (grainSize > maxAllowed)
            grainSize = maxAllowed;
    }

    // ============================
    // Start scrub transition
    // ============================
    void startScrubMotion(VoiceData& v, int blockSize)
    {
        if (scrubSmoothMs <= 0.0)
        {
            v.scrubActual = scrub;
            v.scrubSamplesLeft = 0;
            v.scrubStep = 0.0;
            return;
        }

        double durationSeconds = scrubSmoothMs * 0.001;
        int samples = (int)(durationSeconds * sr);

        if (samples < blockSize)
            samples = blockSize;

        v.scrubStep = (scrub - v.scrubActual) / (double)samples;
        v.scrubSamplesLeft = samples;
    }

    inline void advanceScrubOneSample(VoiceData& v)
    {
        if (v.scrubSamplesLeft > 0)
        {
            v.scrubActual += v.scrubStep;
            v.scrubSamplesLeft--;
        }
        else
        {
            v.scrubActual = scrub;
        }

        if (v.scrubActual < 0.0) v.scrubActual = 0.0;
        if (v.scrubActual > 1.0) v.scrubActual = 1.0;
    }

    // ============================
    // DSP
    // ============================
    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    {
        advanceScrubOneSample(v);

        double maxStart = (double)data.numSamples - grainSize - 2.0;
        if (maxStart < 0.0)
            return;

        double basePos = v.scrubActual * maxStart;
        double pos = basePos + v.phase;

        if (pos < 0.0) pos = 0.0;
        if (pos >= (double)data.numSamples - 1.0)
            pos = (double)data.numSamples - 2.0;

        int iPos = (int)pos;
        int iNext = iPos + 1;

        double frac = pos - (double)iPos;
        double win = hann(v.phase / grainSize);

        float L0 = sample[0][iPos];
        float L1 = sample[0][iNext];
        float R0 = sample[1][iPos];
        float R1 = sample[1][iNext];

        fd[0] += (float)((1.0 - frac) * L0 + frac * L1) * win;
        fd[1] += (float)((1.0 - frac) * R0 + frac * R1) * win;

        v.phase += v.delta;
        if (v.phase >= grainSize)
            v.phase -= grainSize;
    }

    // ============================
    // Block process
    // ============================
    template<typename PD>
    void process(PD& pd)
    {
        if (data.numSamples == 0)
            return;

        int blockSize = pd.blockSize;

        DataReadLock lock(data);
        auto& v = voiceData.get();

        // Begin scrub transition at block start
        startScrubMotion(v, blockSize);

       auto fd = pd.toFrameData();
while (fd.next())
{
    auto s = fd.toSpan();
    processInternal(s, v);
}
        data.setDisplayedValue(v.phase);
    }

	
    // ============================
    // MIDI
    // ============================
    void handleHiseEvent(HiseEvent& e)
    {
        if (e.isNoteOn())
        {
            auto& v = voiceData.get();

            v.reset();
            v.noteNumber = e.getNoteNumber();
            updateDelta(v);

            v.scrubActual = scrub;
        }
    }

    // ============================
    // Sample source
    // ============================
    void setExternalData(const ExternalData& ed, int index)
    {
        data = ed;
        ed.referBlockTo(sample[0], 0);
        ed.referBlockTo(sample[1], 1);
        updateGrainSize();
        reset();
    }

    // ============================
    // Parameters
    // ============================
    template<int P>
    void setParameter(double v)
    {
        if (P == 0)     // pitch
        {
            pitchSemitones = v;
            for (auto& voice : voiceData)
                updateDelta(voice);
        }

        if (P == 1) scrub = v;
        if (P == 2) { grainMs = v; updateGrainSize(); }
        if (P == 3) scrubSmoothMs = v;   // 0 = off
    }
};