template <int NV>
struct granular_player_B_phaseLocked
{
    SNEX_NODE(granular_player_B_phaseLocked);

    // ================================================================
    // CONSTANTS
    // ================================================================
    static const int NUM_CHANNELS = 2;

    // ================================================================
    // SAMPLE DATA
    // ================================================================
    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 0.0;

    // ================================================================
    // PARAMETERS
    // ================================================================
    
    // --- Main controls ---
    double scrub = 0.0;            // 0..1, user position parameter
    double grainMs = 50.0;         // ms, grain length
    double grainSize = 2048.0;     // samples

    // --- Pitch ---
    double pitchSemitones = 0.0;
    int rootNote = 60;

    // --- Scrub smoothing ---
    double scrubSmooth = 0.0;      // 0..1 time constant
    double smoothedScrub = 0.0;    // internal

    // --- Polyphonic scrub offsets ---
    double polySpread = 0.0;       // 0..1 amount of per-voice offset
    double polyRandom = 0.0;       // 0..1 random per-voice spread

    // ================================================================
    // PER-VOICE STATE
    // ================================================================
    struct VoiceData
    {
        double scanPos = 0.0;       // position inside a grain
        double delta = 1.0;         // pitch-based scanning speed
        int noteNumber = 60;

        // Voice-specific scrub offset (in samples)
        double scrubOffset = 0.0;

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

        smoothedScrub = scrub;
    }

    // ================================================================
    // HELPERS
    // ================================================================
    inline double hann(double x)
    {
        return 0.5 - 0.5 * Math.cos(2.0 * Math.PI * x);
    }

    void updateDelta(VoiceData& v)
    {
        const double midiDiff = (double)(v.noteNumber - rootNote);
        const double totalSemis = midiDiff + pitchSemitones;
        const double mult = Math.pow(2.0, totalSemis / 12.0);

        v.delta = (data.sampleRate / sr) * mult;
    }

    void updateGrainSize()
    {
        if (sr > 0.0)
            grainSize = grainMs * sr * 0.001;

        if (grainSize < 16.0) grainSize = 16.0;

        const double maxAllowed = (double)data.numSamples - 2.0;
        if (grainSize > maxAllowed)
            grainSize = maxAllowed;
    }

    // ================================================================
    // MAIN DSP PER FRAME
    // ================================================================
    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    {
        const double totalSamples = (double)data.numSamples;
        const double maxStart = totalSamples - grainSize - 2.0;
        if (maxStart <= 0.0)
            return;

        // ------------------------------------------------------------
        // 1. SCRUB SMOOTHING (simple one-pole)
        // ------------------------------------------------------------
        double s = scrub;
        double alpha = scrubSmooth;

        smoothedScrub = (1.0 - alpha) * smoothedScrub + alpha * s;

        // Convert to sample domain
        double basePos = smoothedScrub * maxStart;

        // ------------------------------------------------------------
        // 2. APPLY POLYPHONIC SCRUB OFFSETS (sample domain)
        // ------------------------------------------------------------
        double offsetSamples = v.scrubOffset;

        double finalStart = basePos + offsetSamples;

        if (finalStart < 0.0) finalStart = 0.0;
        if (finalStart > maxStart) finalStart = maxStart;

        // ------------------------------------------------------------
        // 3. FINAL READ POSITION
        // ------------------------------------------------------------
        double pos = finalStart + v.scanPos;

        // Wrap scan
        if (v.scanPos >= grainSize)
            v.scanPos -= grainSize;

        // Advance according to pitch
        v.scanPos += v.delta;

        // Clamp read position
        if (pos < 0.0) pos = 0.0;
        if (pos > totalSamples - 2.0) pos = totalSamples - 2.0;

        // ------------------------------------------------------------
        // 4. INTERPOLATION
        // ------------------------------------------------------------
        int iPos = (int)pos;
        int iNext = iPos + 1;
        double frac = pos - (double)iPos;

        double env = hann(v.scanPos / grainSize);

        const float L0 = sample[0][iPos];
        const float L1 = sample[0][iNext];
        const float R0 = sample[1][iPos];
        const float R1 = sample[1][iNext];

        double L = ((1.0 - frac) * L0 + frac * L1) * env;
        double R = ((1.0 - frac) * R0 + frac * R1) * env;

        fd[0] += (float)L;
        fd[1] += (float)R;
    }

    // ================================================================
    // POLY PROCESS
    // ================================================================
    template <typename PD>
    void process(PD& pd)
    {
        if (data.numSamples == 0) return;

        DataReadLock sl(data);
        auto& v = voiceData.get();
        auto fd = pd.toFrameData();

        while (fd.next())
            processInternal(fd.toSpan(), v);

        data.setDisplayedValue(v.scanPos);
    }

    void processFrame(span<float, NUM_CHANNELS>& fd)
    {
        if (data.numSamples == 0) return;

        DataReadLock sl(data);
        auto& v = voiceData.get();

        processInternal(fd, v);
        data.setDisplayedValue(v.scanPos);
    }

    // ================================================================
    // MIDI EVENTS
    // ================================================================
    void handleHiseEvent(HiseEvent& e)
    {
        if (e.isNoteOn())
        {
            auto& v = voiceData.get();
            v.reset();

            // voice-specific scrub offsets (in samples)
            double r = (Math.random() - 0.5) * 2.0; // -1..1
            v.scrubOffset =
                (r * polyRandom * 4000.0) +      // random  ±4000 samples
                (polySpread * (e.getNoteNumber() - 60) * 200.0); // ± per key

            v.noteNumber = e.getNoteNumber();
            updateDelta(v);
        }
    }

    // ================================================================
    // EXTERNAL DATA
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
    // ================================================================
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
        if (P == 3) scrubSmooth = v;

        if (P == 4) polySpread = v;
        if (P == 5) polyRandom = v;
    }
};