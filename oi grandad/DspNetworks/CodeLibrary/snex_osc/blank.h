template <int NumVoices> struct DualWT
{
    SNEX_NODE(DualWT);

    //==============================================================
    // ExternalData + spans
    //==============================================================

    ExternalData tableA;
    ExternalData tableB;

    span<float, 1> wavA = { };
    span<float, 1> wavB = { };

    //==============================================================
    // Oscillator state (ALL MUST BE INITIALISED!)
    //==============================================================

    float phaseA = 0.f;
    float phaseB = 0.f;

    float lastA   = 0.f;
    float lastB   = 0.f;

    float freqA   = 220.f;
    float freqB   = 220.f;

    float fmAmtA  = 0.f;    // B -> A
    float fmAmtB  = 0.f;    // A -> B

    int fmModeA   = 0;      // 0=off,1=linear,2=exp
    int fmModeB   = 0;

    float sampleRate = 44100.f;
    float invSR      = 1.f / 44100.f;

    //==============================================================
    // prepare()
    //==============================================================

    void prepare(PrepareSpecs ps)
    {
        sampleRate = (float)ps.sampleRate;
        if(sampleRate <= 0.f)
            sampleRate = 44100.f;

        invSR = 1.f / sampleRate;
    }

    //==============================================================
    // setExternalData()
    //==============================================================

    void setExternalData(const ExternalData& d, int index)
    {
        if(index == 0)
            tableA = d;
        else if(index == 1)
            tableB = d;
    }

    //==============================================================
    // Safe per-block assign (call externally before process)
    //==============================================================

    void assign()
    {
        tableA.referBlockTo(wavA, 0);
        tableB.referBlockTo(wavB, 0);
    }

    //==============================================================
    // Inline wt read
    //==============================================================

    inline float wtRead(span<float,1> wt, int size, float ph) const
    {
        if(size < 2)
            return 0.f;

        float pos = ph * (float)(size - 1);
        int i = (int)pos;

        if(i < 0)
            i = 0;

        int i2 = i + 1;
        if(i2 >= size)
        {
            i2 = size - 1;
            i  = i2 - 1;
            if(i < 0)
                i = 0;
        }

        float f = pos - (float)i;
        float a = wt[i];
        float b = wt[i2];
        return a + (b - a) * f;
    }

    //==============================================================
    // FM
    //==============================================================

    inline float fmDelta(float base, float amt, int mode, float src) const
    {
        if(mode == 1)
            return base + amt * src;

        if(mode == 2)
        {
            float m = exp(amt * src);
            if(m < 0.25f) m = 0.25f;
            if(m > 4.0f)  m = 4.0f;
            return base * m;
        }

        return base;
    }

    //==============================================================
    // tick() — one sample
    //==============================================================

    float tick(double)
    {
        int sizeA = wavA.size;
        int sizeB = wavB.size;

        if(sizeA < 2 || sizeB < 2)
            return 0.f;

        // base deltas
        float baseA = freqA * invSR;
        float baseB = freqB * invSR;

        // stable FM
        float dA = fmDelta(baseA, fmAmtA, fmModeA, lastB);
        float dB = fmDelta(baseB, fmAmtB, fmModeB, lastA);

        // advance phase
        phaseA += dA;
        phaseB += dB;

        // hard sync
        if(phaseA >= 1.f)
        {
            phaseA -= 1.f;
            phaseB  = 0.f;
        }

        if(phaseA < 0.f) phaseA += 1.f;
        if(phaseB >= 1.f) phaseB -= 1.f;
        if(phaseB < 0.f) phaseB += 1.f;

        // lookup
        float sa = wtRead(wavA, sizeA, phaseA);
        float sb = wtRead(wavB, sizeB, phaseB);

        lastA = sa;
        lastB = sb;

        return sa + sb;
    }

    //==============================================================
    // process() — block processing
    //==============================================================

    void process(OscProcessData& d)
    {
        for(auto& s : d.data)
        {
            s = tick(d.uptime);
            d.uptime += d.delta;
        }
    }

    //==============================================================
    // Parameter setter template (required)
    //==============================================================

    template <int P> void setParameter(double v)
    {
        if(P == 0) freqA   = (float)v;
        if(P == 1) freqB   = (float)v;
        if(P == 2) fmAmtA  = (float)v;
        if(P == 3) fmAmtB  = (float)v;
        if(P == 4) fmModeA = (int)v;
        if(P == 5) fmModeB = (int)v;
    }
};