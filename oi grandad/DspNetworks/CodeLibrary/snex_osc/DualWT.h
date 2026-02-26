template <int NumVoices> struct DualWT
{
    SNEX_NODE(DualWT);

    //==============================================================
    // ExternalData + spans (explicit 1-channel wavetables)
    //==============================================================

    ExternalData tableA;
    ExternalData tableB;

    span<float, 1> wavA;
    span<float, 1> wavB;

    //==============================================================
    // Oscillator state
    //==============================================================

    float phaseA;
    float phaseB;

    float lastSampleA;
    float lastSampleB;

    float deltaA;
    float deltaB;

    float baseDeltaA;
    float baseDeltaB;

    float sampleRate;
    float invSr;

    //==============================================================
    // Parameters
    //==============================================================

    float freqA;
    float freqB;

    float fmAmountA;   // B → A
    float fmAmountB;   // A → B

    int fmModeA;       // 0=off, 1=linear, 2=exp
    int fmModeB;

    //==============================================================
    // Constructor
    //==============================================================

    DualWT()
    {
        phaseA = 0.0f;
        phaseB = 0.0f;

        lastSampleA = 0.0f;
        lastSampleB = 0.0f;

        deltaA = 0.0f;
        deltaB = 0.0f;

        baseDeltaA = 0.0f;
        baseDeltaB = 0.0f;

        sampleRate = 44100.0f;
        invSr = 1.0f / sampleRate;

        freqA = 220.0f;
        freqB = 220.0f;

        fmAmountA = 0.0f;
        fmAmountB = 0.0f;

        fmModeA = 0;
        fmModeB = 0;
    }

    //==============================================================
    // Prepare
    //==============================================================

    void prepare(double newSampleRate)
    {
        sampleRate = (float)newSampleRate;
        if(sampleRate <= 0.0f)
            sampleRate = 44100.0f;

        invSr = 1.0f / sampleRate;
    }

    //==============================================================
    // ExternalData assignment — call once per block externally
    //==============================================================

    void assignTables()
    {
        tableA.referBlockTo(wavA, 0);
        tableB.referBlockTo(wavB, 0);
    }

    //==============================================================
    // Inline wavetable lookup
    //==============================================================

    inline float readWT(span<float,1> data, int size, float ph)
    {
        if(size < 2)
            return 0.0f;

        float pos = ph * (float)(size - 1);
        int idx = (int)pos;

        if(idx < 0)
            idx = 0;

        int idx2 = idx + 1;
        if(idx2 >= size)
        {
            idx2 = size - 1;
            idx = idx2 - 1;
            if(idx < 0)
                idx = 0;
        }

        float t = pos - (float)idx;
        float a = data[idx];
        float b = data[idx2];

        return a + (b - a) * t;
    }

    //==============================================================
    // FM delta computation
    //==============================================================

    inline float computeDelta(float baseD, float amt, int mode, float fmSrc)
    {
        float d = baseD;

        if(mode == 1)
        {
            d = baseD + amt * fmSrc;  // linear FM
        }
        else if(mode == 2)
        {
            float m = exp(amt * fmSrc);

            // clamp exponential FM
            if(m < 0.25f) m = 0.25f;
            if(m > 4.0f)  m = 4.0f;

            d = baseD * m;
        }

        return d;
    }

    //==============================================================
    // Per-sample DSP
    //==============================================================

    void processSample(float &outL, float &outR)
    {
        int sizeA = wavA.size;
        int sizeB = wavB.size;

        if(sizeA < 2 || sizeB < 2)
        {
            outL = 0.0f;
            outR = 0.0f;
            return;
        }

        baseDeltaA = freqA * invSr;
        baseDeltaB = freqB * invSr;

        float prevA = lastSampleA;
        float prevB = lastSampleB;

        deltaA = computeDelta(baseDeltaA, fmAmountA, fmModeA, prevB);
        deltaB = computeDelta(baseDeltaB, fmAmountB, fmModeB, prevA);

        phaseA += deltaA;
        phaseB += deltaB;

        // HARD SYNC (A = master)
        if(phaseA >= 1.0f)
        {
            phaseA -= 1.0f;
            phaseB  = 0.0f;
        }

        if(phaseA < 0.0f) phaseA += 1.0f;
        if(phaseB >= 1.0f) phaseB -= 1.0f;
        if(phaseB < 0.0f)  phaseB += 1.0f;

        float sa = readWT(wavA, sizeA, phaseA);
        float sb = readWT(wavB, sizeB, phaseB);

        lastSampleA = sa;
        lastSampleB = sb;

        float mix = sa + sb;

        outL = mix;
        outR = mix;
    }
};