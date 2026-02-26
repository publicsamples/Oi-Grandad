template <int NV>
struct granular_player_phaseLocked
{
    SNEX_NODE(granular_player_phaseLocked);

    static const int NUM_CHANNELS = 2;

    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 44100.0;

    // ========================================================
    // Parameters
    // ========================================================
    double scrub = 0.0;            // UI scrub (0..1)
    double grainMs = 50.0;         // not used heavily yet, still needed for window size
    double grainSize = 4096.0;

    double scrubSmoothMs = 0.0;    // 0 = OFF, >0 = smoothing applied per voice

    // Pitch
    double pitchSemitones = 0.0;
    int rootNote = 60;

    // ========================================================
    // Voice data
    // ========================================================
    struct VoiceData
    {
        double scanPos = 0.0;        // phase inside grain
        double delta = 1.0;          // pitch increment
        int noteNumber = 60;

        double scrubSmoothed = 0.0;  // per-voice smoothed scrub
        bool scrubInit = false;      // prevents jumps on first sample

        void reset()
        {
            scanPos = 0.0;
            scrubInit = false;
        }
    };

    PolyData<VoiceData, NV> voiceData;

    // ========================================================
    // Init
    // ========================================================
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

    // ========================================================
    // Helpers
    // ========================================================
    inline double hann(double x)
    {
        return 0.5 - 0.5 * Math.cos(2.0 * Math.PI * x);
    }

    void updateDelta(VoiceData& v)
    {
        double semis = (double)(v.noteNumber - rootNote) + pitchSemitones;
        double pitchMul = Math.pow(2.0, semis / 12.0);

        v.delta = (data.sampleRate / sr) * pitchMul;
    }

    void updateGrainSize()
    {
        if (sr > 0.0)
            grainSize = grainMs * sr * 0.001;

        if (grainSize < 16.0) grainSize = 16.0;

        double maxAllowed = (double)data.numSamples - 2.0;
        if (grainSize > maxAllowed)
            grainSize = maxAllowed;
    }

    // ========================================================
    // Per-voice scrub smoothing (phase-locked)
    // ========================================================
    inline double smoothScrub(VoiceData& v, double target)
    {
        if (scrubSmoothMs <= 0.0)
        {
            v.scrubSmoothed = target;   // hard follow
            v.scrubInit = true;
            return target;
        }

        double coef = Math.exp(-1.0 / ( (scrubSmoothMs * 0.001) * sr ));

        if (!v.scrubInit)
        {
            v.scrubSmoothed = target;
            v.scrubInit = true;
        }
        else
        {
            v.scrubSmoothed = (v.scrubSmoothed - target) * coef + target;
        }

        return v.scrubSmoothed;
    }

    // ========================================================
    // Main DSP (One grain, phase locked)
    // ========================================================
    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    {
        if (data.numSamples == 0)
            return;

        double maxStart = (double)data.numSamples - grainSize - 2.0;
        if (maxStart < 0.0)
            return;

        // Per-voice smoothed scrub -----------------------------
        double s = smoothScrub(v, scrub);
        double basePos = s * maxStart;

        // Compute read position
        double pos = basePos + v.scanPos;

        // Wrap scan inside grain
        if (v.scanPos >= grainSize)
            v.scanPos -= grainSize;

        // Advance scan (phase locking keeps pitch stable)
        v.scanPos += v.delta;

        // Clamp
        if (pos < 0.0) pos = 0.0;
        if (pos >= (double)data.numSamples - 1.0)
            pos = (double)data.numSamples - 2.0;

        int iPos  = (int)pos;
        int iNext = iPos + 1;
        double frac = pos - (double)iPos;

        double win = hann(v.scanPos / grainSize);

        float L0 = sample[0][iPos];
        float L1 = sample[0][iNext];
        float R0 = sample[1][iPos];
        float R1 = sample[1][iNext];

        double L = ((1.0 - frac) * L0 + frac * L1) * win;
        double R = ((1.0 - frac) * R0 + frac * R1) * win;

        fd[0] += (float)L;
        fd[1] += (float)R;
    }

    // ========================================================
    // Polyphonic process
    // ========================================================
    template <typename PD>
    void process(PD& pd)
    {
        if (data.numSamples == 0)
            return;

        DataReadLock lock(data);
        auto& v = voiceData.get();
        auto f = pd.toFrameData();

        while (f.next())
            processInternal(f.toSpan(), v);

        data.setDisplayedValue(v.scanPos);
    }

    // ========================================================
    // Per-frame process
    // ========================================================
    void processFrame(span<float, NUM_CHANNELS>& fd)
    {
        if (data.numSamples == 0)
            return;

        DataReadLock lock(data);
        auto& v = voiceData.get();
        processInternal(fd, v);

        data.setDisplayedValue(v.scanPos);
    }

    // ========================================================
    // MIDI
    // ========================================================
    void handleHiseEvent(HiseEvent& e)
    {
        if (e.isNoteOn())
        {
            auto& v = voiceData.get();
            v.reset();
            v.noteNumber = e.getNoteNumber();
            updateDelta(v);
        }
    }

    // ========================================================
    // External sample
    // ========================================================
    void setExternalData(const ExternalData& ed, int index)
    {
        data = ed;
        ed.referBlockTo(sample[0], 0);
        ed.referBlockTo(sample[1], 1);

        updateGrainSize();
        reset();
    }

    // ========================================================
    // Parameters
    // ========================================================
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

        if (P == 3) scrubSmoothMs = v;   // 0–500 ms smoothing
    }
};
