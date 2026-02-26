template <int NV>
struct granular_player_C
{
    SNEX_NODE(granular_player_C);

    // ================================================================
    // CONSTANTS & MEMBERS
    // ================================================================
    static const int NUM_CHANNELS = 2;

    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 0.0;

    // Parameters
    double scrub = 0.0;
    double grainMs = 50.0;
    double grainSize = 2048.0;
    double density = 0.5;

    int scrubStepSize = 16;      // quantisation (samples)
    int scrubMode = 0;           // 0=A1, 1=A2
    int densityMode = 0;         // 0=Unified, 1=Dual
    int maxGrains = 8;           // 1..16
    int pitchMode = 0;           // 0=Tape, 1=Time-stretch

    // Pitch
    double pitchSemitones = 0.0;
    int rootNote = 60;

    // State vars
    double prevBasePos = 0.0;
    double transportPos = 0.0;

    // ================================================================
    // PER-VOICE DATA
    // ================================================================
    struct VoiceData
    {
        double scanPos = 0.0;
        double delta = 1.0;
        int noteNumber = 60;

        void reset()
        {
            scanPos = 0.0;
        }
    };

    PolyData<VoiceData, NV> voiceData;

    // ================================================================
    // INIT
    // ================================================================
    void prepare(PrepareSpecs ps)
    {
        sr = ps.sampleRate;
        voiceData.prepare(ps);
    }

    void reset()
    {
        for (auto& v : voiceData)
            v.reset();

        prevBasePos = 0.0;
        transportPos = 0.0;
    }

    inline double hann(double x)
    {
        return 0.5 - 0.5 * Math.cos(2.0 * Math.PI * x);
    }

    // ================================================================
    // PITCH & GRAIN SIZE
    // ================================================================
    void updateDelta(VoiceData& v)
    {
        double midiSemis = (double)(v.noteNumber - rootNote);
        double semis = midiSemis + pitchSemitones;
        double mult = Math.pow(2.0, semis / 12.0);

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

    // ================================================================
    // QUANTISE SCRUB VALUE
    // ================================================================
    double quantisedScrubValue(double s, double maxStart)
    {
        double step = scrubStepSize / maxStart; 
        if (step <= 0.0) return s;
        return step * Math.floor(s / step);
    }

    // ================================================================
    // MAIN DSP
    // ================================================================
    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    {
        double maxStart = (double)data.numSamples - grainSize - 2.0;
        if (maxStart < 0.0)
            return;

        // -----------------------------
        // SCRUB MODE A1 / A2
        // -----------------------------
        double basePos = 0.0;

        if (scrubMode == 0)  // A1 — scrub = window position
        {
            double qScrub = quantisedScrubValue(scrub, maxStart);

            double target = qScrub * maxStart;
            double xf = 0.25;
            prevBasePos += xf * (target - prevBasePos);
            basePos = prevBasePos;
        }
        else                 // A2 — free running transport
        {
            double qScrub = quantisedScrubValue(scrub, maxStart);
            basePos = qScrub * maxStart;

            transportPos += v.delta;
            if (transportPos >= grainSize)
                transportPos -= grainSize;
        }

        // -----------------------------
        // GRAIN COUNT
        // -----------------------------
        int g = 1 + (int)Math.floor(density * (double)(maxGrains - 1));
        if (g < 1) g = 1;
        if (g > maxGrains) g = maxGrains;

        double finalL = 0.0;
        double finalR = 0.0;

        // -----------------------------
        // LOOP FOR EACH GRAIN
        // -----------------------------
        for (int gi = 0; gi < g; gi++)
        {
            double localScan = v.scanPos;

            // =======================================================
            // DENSITY MODE
            // =======================================================
            if (densityMode == 0)
            {
                // unified
                localScan += (double)gi * (grainSize / (double)g);
            }
            else
            {
                // dual mode
                if (scrubMode == 0)
                {
                    localScan += (double)gi * (grainSize * 0.10);
                }
                else
                {
                    double jitter = ((double)gi * 31.0 + scrub * 91.123);
                    jitter -= (int)jitter;
                    double jitterOffset = (jitter - 0.5) * (grainSize * 0.75);
                    localScan += (double)gi * (grainSize * 0.20);
                    localScan += jitterOffset;
                }
            }

            while (localScan >= grainSize) localScan -= grainSize;
            while (localScan < 0.0)        localScan += grainSize;

            double pos =
                (scrubMode == 0)
                ? basePos + localScan
                : basePos + transportPos + localScan;

            if (pos < 0.0) pos = 0.0;
            if (pos >= (double)data.numSamples - 1.0)
                pos = (double)data.numSamples - 2.0;

            int iPos = (int)pos;
            int iNext = iPos + 1;
            double frac = pos - (double)iPos;

            double win = hann(localScan / grainSize);

            float L0 = sample[0][iPos];
            float L1 = sample[0][iNext];
            float R0 = sample[1][iPos];
            float R1 = sample[1][iNext];

            finalL += ((1.0 - frac) * L0 + frac * L1) * win;
            finalR += ((1.0 - frac) * R0 + frac * R1) * win;
        }

        finalL /= (double)g;
        finalR /= (double)g;

        fd[0] += (float)finalL;
        fd[1] += (float)finalR;

        // ================================================================
        // FIXED — CORRECTED TIME-STRETCH MODE
        // ================================================================
        if (pitchMode == 0)
        {
            // Tape mode
            v.scanPos += v.delta;
        }
        else
        {
            // TIME-STRETCH FIX — 1 sample per frame
            v.scanPos += 1.0;
        }

        if (v.scanPos >= grainSize)
            v.scanPos -= grainSize;
    }

    // ================================================================
    // POLYPHONIC PROCESS
    // ================================================================
    template <typename PD>
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

    // ================================================================
    // FRAME PROCESS
    // ================================================================
    void processFrame(span<float, NUM_CHANNELS>& fd)
    {
        if (data.numSamples == 0)
            return;

        DataReadLock lock(data);
        auto& v = voiceData.get();
        processInternal(fd, v);

        data.setDisplayedValue(v.scanPos);
    }

    // ================================================================
    // MIDI
    // ================================================================
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

    // ================================================================
    // SAMPLE SOURCE
    // ================================================================
    void setExternalData(const ExternalData& ed, int index)
    {
        data = ed;
        ed.referBlockTo(sample[0], 0);
        ed.referBlockTo(sample[1], 1);

        updateGrainSize();
        reset();
    }

    // ================================================================
    // PARAMETERS
    //-----------------------------------------------------------------
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
        
        if (P == 3) scrubStepSize = v;

        if (P == 4) density = v;

        if (P == 5) scrubMode = (v > 0.5 ? 1 : 0);

        if (P == 6) densityMode = (v > 0.5 ? 1 : 0);

        if (P == 7)
        {
            int mg = 1 + (int)Math.floor(v * 15.0);
            if (mg < 1) mg = 1;
            if (mg > 16) mg = 16;
            maxGrains = mg;
        }

        if (P == 8) pitchMode = (v > 0.5 ? 1 : 0);
    }
};
