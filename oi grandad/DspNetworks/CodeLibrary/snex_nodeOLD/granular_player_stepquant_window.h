template <int NV>
struct granular_player_stepquant
{
    SNEX_NODE(granular_player_stepquant);

    static const int NUM_CHANNELS = 2;

    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 44100.0;

    // Parameters
    double scrub = 0.0;
    double grainMs = 50.0;
    double grainSize = 2048.0;

    double pitchSemitones = 0.0;
    int rootNote = 60;

    int scrubStepCount = 64;

    // NEW: window mode (0–3)
    int windowMode = 0;

    struct VoiceData
    {
        double scanPos = 0.0;
        double delta = 1.0;
        int noteNumber = 60;

        double scrubQ = 0.0;

        void reset()
        {
            scanPos = 0.0;
            scrubQ = 0.0;
        }
    };

    PolyData<VoiceData, NV> voiceData;

    // ============================================
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

    // ============================================
    // Window functions
    inline double hann(double x)
    {
        return 0.5 - 0.5 * Math.cos(2.0 * Math.PI * x);
    }

    inline double hamming(double x)
    {
        return 0.54 - 0.46 * Math.cos(2.0 * Math.PI * x);
    }

    inline double triangle(double x)
    {
        return 1.0 - Math.abs(2.0 * x - 1.0);
    }

    inline double blackman(double x)
    {
        return 0.42
             - 0.5 * Math.cos(2.0 * Math.PI * x)
             + 0.08 * Math.cos(4.0 * Math.PI * x);
    }

    inline double getWindowValue(double x)
    {
        x = Math.min(1.0, Math.max(0.0, x));

        if (windowMode == 0) return hann(x);
        if (windowMode == 1) return hamming(x);
        if (windowMode == 2) return triangle(x);
        if (windowMode == 3) return blackman(x);

        return hann(x);
    }

    // ============================================
    // Pitch
    void updateDelta(VoiceData& v)
    {
        double midiSemis = (double)v.noteNumber - (double)rootNote;
        double total = midiSemis + pitchSemitones;
        double mult = Math.pow(2.0, total / 12.0);

        v.delta = (data.sampleRate / sr) * mult;
    }

    // ============================================
    // Grain size
    void updateGrainSize()
    {
        if (sr > 0.0)
            grainSize = grainMs * sr * 0.001;

        if (grainSize < 16.0)
            grainSize = 16.0;

        double maxAllowed = (double)data.numSamples - 2.0;
        if (grainSize > maxAllowed)
            grainSize = maxAllowed;
    }

    // ============================================
    // Scrub stepping
    inline double quantiseScrub(double raw, const ExternalData& d)
    {
        if (scrubStepCount <= 1)
            return raw;

        if (d.numSamples <= 1)
            return raw;

        double step = 1.0 / (double)scrubStepCount;
        return step * Math.floor(raw / step);
    }

    // ============================================
    // DSP
    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    {
        double maxStart = (double)data.numSamples - grainSize - 2.0;
        if (maxStart < 0.0)
            return;

        v.scrubQ = quantiseScrub(scrub, data);

        double basePos = v.scrubQ * maxStart;
        double pos = basePos + v.scanPos;

        if (pos < 0.0) pos = 0.0;
        if (pos >= (double)data.numSamples - 1.0)
            pos = (double)data.numSamples - 2.0;

        int iPos = (int)pos;
        int iNext = iPos + 1;

        double frac = pos - (double)iPos;

        double win = getWindowValue(v.scanPos / grainSize);

        float L0 = sample[0][iPos];
        float L1 = sample[0][iNext];
        float R0 = sample[1][iPos];
        float R1 = sample[1][iNext];

        fd[0] += (float)((1.0 - frac) * L0 + frac * L1) * win;
        fd[1] += (float)((1.0 - frac) * R0 + frac * R1) * win;

        v.scanPos += v.delta;
        if (v.scanPos >= grainSize)
            v.scanPos -= grainSize;
    }

    // ============================================
    template<typename PD>
    void process(PD& pd)
    {
        if (data.numSamples == 0)
            return;

        DataReadLock lock(data);
        auto& v = voiceData.get();

        auto fd = pd.toFrameData();
        while (fd.next())
            processInternal(fd.toSpan(), v);

        data.setDisplayedValue(v.scanPos);
    }

    void processFrame(span<float, NUM_CHANNELS>& fd)
    {
        if (data.numSamples == 0)
            return;

        auto& v = voiceData.get();
        processInternal(fd, v);
        data.setDisplayedValue(v.scanPos);
    }

    // ============================================
    void handleHiseEvent(HiseEvent& e)
    {
        if (e.isNoteOn())
        {
            auto& v = voiceData.get();

            v.reset();
            v.noteNumber = e.getNoteNumber();
            updateDelta(v);

            v.scrubQ = scrub;
        }
    }

    // ============================================
    void setExternalData(const ExternalData& ed, int index)
    {
        data = ed;

        ed.referBlockTo(sample[0], 0);
        ed.referBlockTo(sample[1], 1);

        updateGrainSize();
        reset();
    }

    // ============================================
    template<int P>
    void setParameter(double v)
    {
        if (P == 0)
        {
            pitchSemitones = v;
            for (auto& voice : voiceData)
                updateDelta(voice);
        }

        if (P == 1) scrub = v;
        if (P == 2) { grainMs = v; updateGrainSize(); }

        if (P == 3) // window mode
        {
            int m = (int)v;
            if (m < 0) m = 0;
            if (m > 3) m = 3;
            windowMode = m;
        }

        if (P == 4) // step count (keep working numbering)
        {
            int s = (int)v;
            if (s < 1) s = 1;
            if (s > 1024) s = 1024;
            scrubStepCount = s;
        }
    
};
