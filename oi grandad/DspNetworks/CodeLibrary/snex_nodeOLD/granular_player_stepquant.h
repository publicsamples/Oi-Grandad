template <int NV>
struct granular_player_stepquant
{
    SNEX_NODE(granular_player_stepquant);

    static const int NUM_CHANNELS = 2;

    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 0.0;

    // Parameters
    double scrub = 0.0;        // 0..1 UI input
    double grainMs = 50.0;
    double grainSize = 2048.0;

    double pitchSemitones = 0.0;
    int rootNote = 60;

    int scrubStepCount = 64;   // number of quantisation steps
    int grainCount = 1;        // 1..8 grains

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

    // ====================================================
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

    // ====================================================
    void updateDelta(VoiceData& v)
    {
        double midiSemis = (double)v.noteNumber - (double)rootNote;
        double total = midiSemis + pitchSemitones;
        double mult = Math.pow(2.0, total / 12.0);

        v.delta = (data.sampleRate / sr) * mult;
    }

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

    // ====================================================
    inline double quantiseScrub(double raw, const ExternalData& d)
    {
        if (scrubStepCount <= 1)
            return raw;

        if (d.numSamples <= 1)
            return raw;

        double step = 1.0 / (double)scrubStepCount;
        return step * Math.floor(raw / step);
    }

    // ====================================================
    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    {
        double maxStart = (double)data.numSamples - grainSize - 2.0;
        if (maxStart < 0.0)
            return;

        v.scrubQ = quantiseScrub(scrub, data);

        double basePos = v.scrubQ * maxStart;

        double outL = 0.0;
        double outR = 0.0;

        int g = grainCount;

        for (int gi = 0; gi < g; gi++)
        {
            double offset = (grainSize / (double)g) * (double)gi;

            double local = v.scanPos + offset;

            while (local < 0.0) local += grainSize;
            while (local >= grainSize) local -= grainSize;

            double pos = basePos + local;

            if (pos < 0.0) pos = 0.0;
            if (pos >= (double)data.numSamples - 1.0)
                pos = (double)data.numSamples - 2.0;

            int iPos = (int)pos;
            int iNext = iPos + 1;

            double frac = pos - (double)iPos;
            double w = hann(local / grainSize);

            float L0 = sample[0][iPos];
            float L1 = sample[0][iNext];
            float R0 = sample[1][iPos];
            float R1 = sample[1][iNext];

            outL += ((1.0 - frac) * L0 + frac * L1) * w;
            outR += ((1.0 - frac) * R0 + frac * R1) * w;
        }

        fd[0] += (float)(outL / (double)g);
        fd[1] += (float)(outR / (double)g);

        v.scanPos += v.delta;
        if (v.scanPos >= grainSize)
            v.scanPos -= grainSize;
    }

    // ====================================================
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

    // ====================================================
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

    // ====================================================
    void setExternalData(const ExternalData& ed, int index)
    {
        data = ed;

        ed.referBlockTo(sample[0], 0);
        ed.referBlockTo(sample[1], 1);

        updateGrainSize();
        reset();
    }

    // ====================================================
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

        if (P == 3)
        {
            int s = (int)v;
            if (s < 1) s = 1;
            if (s > 1024) s = 1024;
            scrubStepCount = s;
        }

        if (P == 4)
        {
            int g = (int)v;
            if (g < 1) g = 1;
            if (g > 8) g = 8;
            grainCount = g;
        }
    }
}; (g < 1) g = 1;
        if (g > MAX_GRAINS) g = MAX_GRAINS;

        double Lsum = 0.0;
        double Rsum = 0.0;

        double grainSpacing = grainSize / (double)g;

        for (int gi = 0; gi < g; gi++)
        {
            double local = v.scanPos + (grainSpacing * (double)gi);

            // wrap inside grain window
            while (local < 0.0) local += grainSize;
            while (local >= grainSize) local -= grainSize;

            double pos = basePos + local;

            // clamp
            if (pos < 0.0) pos = 0.0;
            if (pos >= (double)data.numSamples - 1.0)
                pos = (double)data.numSamples - 2.0;

            int iPos = (int)pos;
            int iNext = iPos + 1;

            double frac = pos - (double)iPos;
            double w = hann(local / grainSize);

            float L0 = sample[0][iPos];
            float L1 = sample[0][iNext];
            float R0 = sample[1][iPos];
            float R1 = sample[1][iNext];

            Lsum += ((1.0 - frac) * L0 + frac * L1) * w;
            Rsum += ((1.0 - frac) * R0 + frac * R1) * w;
        }

        // mix down
        fd[0] += (float)(Lsum / (double)g);
        fd[1] += (float)(Rsum / (double)g);

        // advance main grain phase
        v.scanPos += v.delta;
        if (v.scanPos >= grainSize)
            v.scanPos -= grainSize;
    }

    // -----------------------------------------------------
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

    // -----------------------------------------------------
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

    // -----------------------------------------------------
    void setExternalData(const ExternalData& ed, int index)
    {
        data = ed;

        ed.referBlockTo(sample[0], 0);
        ed.referBlockTo(sample[1], 1);

        updateGrainSize();
        reset();
    }

    // -----------------------------------------------------
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

        if (P == 3)
        {
            int s = (int)v;
            if (s < 1) s = 1;
            if (s > 1024) s = 1024;
            scrubStepCount = s;
        }

        if (P == 4)
        {
            int d = (int)v;
            if (d < 1) d = 1;
            if (d > MAX_GRAINS) d = MAX_GRAINS;
            density = d;
        }
    }
};