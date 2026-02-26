template <int NV>
struct granular_player
{
    SNEX_NODE(granular_player);

    static const int NUM_CHANNELS = 2;

    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 0.0;
    
    // pass the index into the constructor
index::wrapped<0, false> idx(6);

// create a dummy data array
span data = {1, 2, 3, 4, 5 };

// using this index will wrap around the data bounds.
auto x = data[idx]; // => 6
    // -----------------------------
    // Parameters
    // -----------------------------
    double pitchSemitones = 0.0;
    double scrubTarget    = 0.0;   // 0..1
    double grainMs        = 50.0;
    double grainSize      = 2048.0;

    double scrubSmooth    = 0.0;   // 0..1

    int rootNote = 60;

    // -----------------------------
    // Per-voice storage
    // -----------------------------
    struct VoiceData
    {
        double scanPos  = 0.0;     // position inside grain window
        double scrubPos = 0.0;     // per-voice smoothed scrub
        double delta    = 1.0;     // playback speed
        int noteNumber  = 60;

        void reset()
        {
            scanPos  = 0.0;
            scrubPos = 0.0;
        }
    };

    PolyData<VoiceData, NV> voiceData;

    // -----------------------------
    // Init
    // -----------------------------
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

    // -----------------------------
    // Pitch
    // -----------------------------
    void updateDelta(VoiceData& v)
    {
        double midi = (double)(v.noteNumber - rootNote);
        double totalSemis = midi + pitchSemitones;
        double mult = Math.pow(2.0, totalSemis / 12.0);

        // pitch only from delta
        v.delta = (data.sampleRate / sr) * mult;
    }

    // -----------------------------
    // Grain size
    // -----------------------------
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

    // -----------------------------
    // DSP per frame
    // -----------------------------
    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    {
        double maxStart = (double)data.numSamples - grainSize - 2.0;
        if (maxStart < 0.0)
            return;

        // -------------------------
        // Per-voice smoothing
        // -------------------------
        double smoothAmt = scrubSmooth;

        v.scrubPos += (scrubTarget - v.scrubPos) * smoothAmt;

        double basePos = v.scrubPos * maxStart;

        double pos = basePos + v.scanPos;

        // wrap inside grain window
        if (v.scanPos >= grainSize)
            v.scanPos -= grainSize;

        // increment internal read position
        v.scanPos += v.delta;

        // clamp reading position
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

    // -----------------------------
    // Polyphonic process
    // -----------------------------
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

        data.setDisplayedValue(v.scrubPos);
    }

    void processFrame(span<float, NUM_CHANNELS>& fd)
    {
        if (data.numSamples == 0)
            return;

        DataReadLock lock(data);
        auto& v = voiceData.get();
        processInternal(fd, v);

        data.setDisplayedValue(v.scrubPos);
    }

    // -----------------------------
    // MIDI
    // -----------------------------
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

    // -----------------------------
    // External data (samples)
    // -----------------------------
    void setExternalData(const ExternalData& ed, int index)
    {
        data = ed;
        ed.referBlockTo(sample[0], 0);
        ed.referBlockTo(sample[1], 1);

        updateGrainSize();
        reset();
    }

    // -----------------------------
    // Parameters
    // -----------------------------
    template<int P>
    void setParameter(double v)
    {
        if (P == 0)
        {
            pitchSemitones = v;
            for (auto& voice : voiceData)
                updateDelta(voice);
        }

        if (P == 1)
            scrubTarget = v;

        if (P == 2)
        {
            grainMs = v;
            updateGrainSize();
        }

        if (P == 3)
            scrubSmooth = v;
    }
};