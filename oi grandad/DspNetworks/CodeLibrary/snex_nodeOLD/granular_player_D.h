template <int NV>
struct granular_player_D
{
    SNEX_NODE(granular_player_D);

    // ================================================================
    // CONSTANTS & MEMBERS
    // ================================================================
    static const int NUM_CHANNELS = 2;

    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 0.0;

    // --- Parameters ---
    double scrub = 0.0;
    double grainMs = 50.0;
    double grainSize = 2048.0;
    double density = 0.5;

    double scrubStepSize = 16.0;  
    int scrubMode = 0;            // 0=A1, 1=A2
    int scrubQuantMode = 0;       // 0/1/2
    int densityMode = 0;          // 0=Unified, 1=Dual
    int maxGrains = 8;            // 1..16

    int pitchMode = 0;            // 0=Tape, 1=Timestretch, 2=Formant
    double formantAmount = 0.0;   // 0..1

    int reverseMode = 0;          // 0=FWD, 1=REV, 2=DUAL
    double reverseBlend = 0.0;    // 0..1 continuous

    double transportRateScale = 1.0; // multiplies delta in A2

    double pitchSemitones = 0.0;
    int rootNote = 60;

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
    // PITCH LOGIC
    // ================================================================
    void updateDelta(VoiceData& v)
    {
        double midiSemis = (double)(v.noteNumber - rootNote);
        double semis = midiSemis + pitchSemitones;
        double mult = Math.pow(2.0, semis / 12.0);
        v.delta = (data.sampleRate / sr) * mult;
    }

    // ================================================================
    // GRAIN SIZE
    // ================================================================
    void updateGrainSize()
    {
        if (sr > 0.0)
            grainSize = grainMs * sr * 0.001;

        if (grainSize < 16.0) grainSize = 16.0;

        double maxAllowed = (double)data.numSamples - 2.0;
        if (grainSize > maxAllowed)
            grainSize = maxAllowed;
    }

    // ================================================================
    // SCRUB QUANTISATION
    // ================================================================
    double quantScrub(double x, double maxStart)
    {
        if (scrubQuantMode == 0)
            return x; // no quant

        double step = scrubStepSize / maxStart;
        if (step <= 0.0)
            return x;

        double q = step * Math.floor(x / step);

        return q;
    }

    double quantTransport(double x, double maxStart)
    {
        if (scrubQuantMode < 1)
            return x;

        double step = scrubStepSize / maxStart;
        double q = step * Math.floor(x / step);
        return q;
    }

    double quantLocal(double x, double maxStart)
    {
        if (scrubQuantMode < 2)
            return x;

        double step = scrubStepSize;
        return step * Math.floor(x / step);
    }

    // ================================================================
    // DSP
    // ================================================================
    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    {
        double maxStart = (double)data.numSamples - grainSize - 2.0;
        if (maxStart < 0.0)
            return;

        // ============================================================
        // SCRUB SYSTEM
        // ============================================================
        double qScrub = quantScrub(scrub, maxStart);

        double basePos = 0.0;

        if (scrubMode == 0)
        {
            // A1 – scrub = window position
            double target = qScrub * maxStart;
            prevBasePos += 0.25 * (target - prevBasePos);
            basePos = prevBasePos;
        }
        else
        {
            // A2 – transport moves independently
            basePos = qScrub * maxStart;

            double adv = v.delta * transportRateScale;
            transportPos += adv;
            if (transportPos >= grainSize) transportPos -= grainSize;
        }

        double qTransport = quantTransport(transportPos, maxStart);

        // ============================================================
        // GRAIN COUNT
        // ============================================================
        int g = 1 + (int)Math.floor(density * (double)(maxGrains - 1));
        if (g < 1) g = 1;
        if (g > maxGrains) g = maxGrains;

        double outL = 0.0;
        double outR = 0.0;

        // ============================================================
        // LOOP OVER GRAINS
        // ============================================================
        for (int gi = 0; gi < g; gi++)
        {
            double localScan = v.scanPos;

            // -------------------------------
            // density modes
            // -------------------------------
            if (densityMode == 0)
            {
                localScan += (double)gi * (grainSize / (double)g);
            }
            else
            {
                double jitter = ((double)gi * 31.0 + scrub * 91.123);
                jitter -= (int)jitter;
                double joff = (jitter - 0.5) * (grainSize * 0.60);

                localScan += (double)gi * (grainSize * 0.15);
                localScan += joff;
            }

            // optional quant for grain offsets
            localScan = quantLocal(localScan, maxStart);

            while (localScan >= grainSize) localScan -= grainSize;
            while (localScan < 0.0)        localScan += grainSize;

        // ========================================================
// FINAL POSITION (FWD / REV / BLEND)
// ========================================================

// 1) map scan inside window
double scanFwd = localScan;
double scanRev = grainSize - localScan;
if (scanRev < 0.0) scanRev += grainSize;

// 2) compute window positions
double posFwd =
    (scrubMode == 0)
    ? basePos + scanFwd
    : basePos + qTransport + scanFwd;

double posRev =
    (scrubMode == 0)
    ? basePos + scanRev
    : basePos + qTransport + scanRev;

// 3) blend or select
double pos = 0.0;

if (reverseMode == 0)            // forward
    pos = posFwd;
else if (reverseMode == 1)       // reverse
    pos = posRev;
else                             // dual blend
    pos = posFwd * (1.0 - reverseBlend)
        + posRev * reverseBlend;

// 4) clamp
if (pos < 0.0) pos = 0.0;
if (pos >= (double)data.numSamples - 1.0)
    pos = (double)data.numSamples - 2.0;

            int iPos = (int)pos;
            int iNext = iPos + 1;
            double frac = pos - (double)iPos;

            double w = hann(localScan / grainSize);

            float L0 = sample[0][iPos];
            float L1 = sample[0][iNext];
            float R0 = sample[1][iPos];
            float R1 = sample[1][iNext];

            double L = ((1.0 - frac) * L0 + frac * L1) * w;
            double R = ((1.0 - frac) * R0 + frac * R1) * w;

            outL += L;
            outR += R;
        }

        outL /= (double)g;
        outR /= (double)g;

        fd[0] += (float)outL;
        fd[1] += (float)outR;

        // ============================================================
        // SCAN ADVANCE
        // ============================================================
        if (pitchMode == 0)
        {
            v.scanPos += v.delta;
        }
        else if (pitchMode == 1)
        {
            v.scanPos += 1.0;
        }
        else
        {
            v.scanPos += (1.0 + formantAmount * 0.5);
        }

        if (v.scanPos >= grainSize) v.scanPos -= grainSize;
    }

    // ================================================================
    // PROCESS (BLOCK)
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
        if (data.numSamples == 0) return;

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
    // ================================================================
    template <int P>
    void setParameter(double v)
    {
        if (P == 0)  // pitch
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

        if (P == 8) pitchMode = (int)Math.floor(v * 2.999);

        if (P == 9) formantAmount = v;

        if (P == 10) reverseMode = (int)Math.floor(v * 2.999);
        if (P == 11) reverseBlend = v;

        if (P == 12) scrubQuantMode = (int)Math.floor(v * 2.999);

        if (P == 13)
        {
            // scale 0..1 to 0.1x .. 4x
            double scale = 0.1 + v * 3.9;
            transportRateScale = scale;
        }
    }
};
