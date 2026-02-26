template <int NV> struct BufferState
{
    SNEX_NODE(BufferState);

    // ============================================================
    // Constants
    // ============================================================

    static const int NumMaxSamples = 65536;

    // ============================================================
    // Buffers (ExternalData will bind these)
    // ============================================================

    span<float, NumMaxSamples> leftBuffer;
span<float, NumMaxSamples> rightBuffer;

    // ============================================================
    // State
    // ============================================================

    double readPos        = 0.0;
    int    writePos       = 0;

    int    stutterActive  = 0;
    double stutterStart   = 0.0;
    double stutterCounter = 0.0;
    double stutterLen     = 0.0;

    double rndSeed        = 0.12345;
    double sampleRate     = 44100.0;

    // ============================================================
    // Parameters
    // ============================================================

    double paramSpeed         = 1.0;
    double paramFreeze        = 0.0;
    double paramReverse       = 0.0;
    double paramJumpProb      = 0.0;
    double paramJumpAmount    = 0.0;
    double paramStutterLength = 0.0;
    double paramWarp          = 0.0;
    double paramReadOffset = 0.0;
    double paramReadRange = 0.0;    // 0.0–1.0
    double freezeLoopStart = 0.0;
    double freezeLoopEnd   = 0.0;
    int freezeWasActive    = 0;

    template <int P>
    void setParameter(double v)
    {
        if(P == 0) paramSpeed = v;
        else if(P == 1) paramFreeze = v;
        else if(P == 2) paramReverse = v;
        else if(P == 3) paramJumpProb = v;
        else if(P == 4) paramJumpAmount = v;
        else if(P == 5) paramStutterLength = v;
        else if(P == 6) paramWarp = v;
        else if(P == 7) paramReadOffset = v;
        else if(P == 8) paramReadRange = v;
    }

    // ============================================================
    // External buffer binding
    // ============================================================

    void setExternalData(const ExternalData& d, int index)
    {
      
    }

    // ============================================================
    // prepare / reset
    // ============================================================

    void prepare(PrepareSpecs ps)
    {
        sampleRate = ps.sampleRate;
    }

    void reset()
    {
        readPos        = 0.0;
        writePos       = 0;
        rndSeed        = 0.12345;

        stutterActive  = 0;
        stutterStart   = 0.0;
        stutterCounter = 0.0;
        stutterLen     = 0.0;
    }

    // ============================================================
    // Random Generator (SNEX-safe LCG)
    // ============================================================

    inline double snexRand()
    {
        rndSeed = rndSeed * 16807.0;
        double t = rndSeed / 2147483647.0;
        int k = (int)t;
        double r = rndSeed - (double)k * 2147483647.0;
        return r / 2147483647.0;
    }

    // ============================================================
    // Per-sample processing
    // ============================================================

  
  template <int C>
void processFrame(span<float, C>& data)
{
    // -------------------------------
    // 1. Write incoming audio (when not frozen)
    // -------------------------------
    if(paramFreeze < 0.5)
    {
        int w = writePos;
        if(w >= NumMaxSamples)
            w -= NumMaxSamples;

        if(C >= 1) leftBuffer[w]  = data[0];
        if(C >= 2) rightBuffer[w] = data[1];

        writePos++;
        if(writePos >= NumMaxSamples)
            writePos = 0;
    }

    // -------------------------------
    // 2. Detect freeze activation/deactivation
    // -------------------------------
    if(paramFreeze >= 0.5 && freezeWasActive == 0)
    {
        // Freeze just turned ON
        double loopLen = paramReadRange * (double)NumMaxSamples;
        if(loopLen < 4.0)
            loopLen = 4.0;

        freezeLoopStart = readPos;
        freezeLoopEnd   = freezeLoopStart + loopLen;

        while(freezeLoopEnd >= (double)NumMaxSamples)
            freezeLoopEnd -= (double)NumMaxSamples;

        freezeWasActive = 1;
    }
    else if(paramFreeze < 0.5 && freezeWasActive == 1)
    {
        // Freeze just turned OFF
        freezeWasActive = 0;
    }

    // -------------------------------
    // 3. Non-freeze: Read Offset + Speed motion
    // -------------------------------
    if(freezeWasActive == 0)
    {
        // --- readOffset ---
        double r = (double)writePos - (paramReadOffset * (double)NumMaxSamples);

        while(r < 0.0)
            r += (double)NumMaxSamples;
        while(r >= (double)NumMaxSamples)
            r -= (double)NumMaxSamples;

        readPos = r;

        // --- Speed / Reverse / Warp ---
        double sp = paramSpeed;
        if(paramReverse >= 0.5)
            sp = sp * -1.0;

        sp = sp + paramWarp * (sp * sp);

        readPos += sp;

        while(readPos < 0.0)
            readPos += (double)NumMaxSamples;
        while(readPos >= (double)NumMaxSamples)
            readPos -= (double)NumMaxSamples;
    }

    // -------------------------------
    // 4. Freeze mode: constrain readPos to [freezeLoopStart, freezeLoopEnd)
    // -------------------------------
    if(freezeWasActive == 1)
    {
        // Wrap readPos into freeze window
        while(readPos < freezeLoopStart)
            readPos += (double)NumMaxSamples;

        while(readPos >= freezeLoopEnd)
            readPos -= (freezeLoopEnd - freezeLoopStart);
    }

    // -------------------------------
    // 5. Interpolation
    // -------------------------------
    int i0 = (int)readPos;
    int i1 = i0 + 1;

    if(i1 >= NumMaxSamples)
        i1 = 0;

    double frac = readPos - (double)i0;

    for(int ch = 0; ch < C; ch++)
    {
        float a = (ch == 0 ? leftBuffer[i0] : rightBuffer[i0]);
        float b = (ch == 0 ? leftBuffer[i1] : rightBuffer[i1]);

        data[ch] = a + (b - a) * (float)frac;
    }
}

    // ============================================================
    // Block processing
    // ============================================================

    template <typename PDT>
    void process(PDT& data)
    {
        auto fd = data.toFrameData();
        while(fd.next())
            processFrame(fd.toSpan());
    }

    void handleHiseEvent(HiseEvent& e) {}
};
