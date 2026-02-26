template <int NV>
struct DualWT
{
    SNEX_NODE(DualWT);

    //==========================================================
    // ExternalData + spans MUST COME FIRST
    //==========================================================
    ExternalData tableA;
    ExternalData tableB;

    span<dyn<float>, 1> wavA;
    span<dyn<float>, 1> wavB;

    //==========================================================
    // VoiceData
    //==========================================================
    struct VoiceData
    {
        double phaseA = 0.0;
        double freqA  = 440.0;
        int noteNumber = 60;

        void reset()
        {
            phaseA = 0.0;
        }
    };

    //==========================================================
    // PolyData MUST COME AFTER spans
    //==========================================================
    PolyData<VoiceData, NV> voices;
    
    
    //==========================================================
    // ExternalData (mono)
    //==========================================================
    ExternalData tableA;
    ExternalData tableB;

    // Mono spans (rank-1)
    span<dyn<float>, 1> wavA;
    span<dyn<float>, 1> wavB;

    //==========================================================
    // Global
    //==========================================================
    double sr    = 44100.0;
    double invSr = 1.0 / 44100.0;

    // Wavetable info
    int frameSize  = 1024;   // default slice size
    int frameCount = 1;      // computed from file length

    //==========================================================
    // prepare
    //==========================================================
    void prepare(PrepareSpecs ps)
    {
        sr    = ps.sampleRate;
        invSr = 1.0 / sr;
        voices.prepare(ps);
    }

    //==========================================================
    // Recompute frameCount from ExternalData
    //==========================================================
    void updateFrameCount()
    {
        int bs = tableA.blockSize;
        int nb = tableA.numBlocks;

        if(bs <= 0 || nb <= 0)
        {
            frameCount = 1;
            return;
        }

        int totalSamples = bs * nb;

        if(frameSize <= 0)
            frameSize = 1024;

        frameCount = totalSamples / frameSize;

        if(frameCount < 1)
            frameCount = 1;
    }

    //==========================================================
    // setExternalData
    //==========================================================
    void setExternalData(const ExternalData& ed, int index)
    {
        if(index == 0)
        {
            tableA = ed;
            ed.referBlockTo(wavA[0], 0);   // mono
        }

        if(index == 1)
        {
            tableB = ed;
            ed.referBlockTo(wavB[0], 0);   // mono
        }

        updateFrameCount();
    }

    //==========================================================
    // Frame reader (mono)
    //==========================================================
    inline float readFrame(span<dyn<float>,1>& tbl,
                           double phase,
                           int frameIndex,
                           int frameSize)
    {
        auto& ch = tbl[0];

        int total = tableA.blockSize * tableA.numBlocks;
        if(total < 2)
            return 0.0f;

        int start = frameIndex * frameSize;
        if(start < 0) start = 0;

        int end = start + frameSize - 1;
        if(end >= total)
            end = total - 1;

        // position within the current frame
        double pos = phase * (double)(frameSize - 1);

        int i = (int)pos;
        if(i < 0) i = 0;
        if(i >= frameSize) i = frameSize - 1;

        int i2 = i + 1;
        if(i2 >= frameSize) i2 = frameSize - 1;

        double frac = pos - (double)i;

        int idx1 = start + i;
        int idx2 = start + i2;

        if(idx1 < 0) idx1 = 0;
        if(idx1 >= total) idx1 = total - 1;

        if(idx2 < 0) idx2 = 0;
        if(idx2 >= total) idx2 = total - 1;

        float a = ch[idx1];
        float b = ch[idx2];

        return a + (b - a) * (float)frac;
    }


    //==========================================================
    // tick
    //==========================================================
    inline double tick(VoiceData& v)
    {
        v.phaseA += v.freqA * invSr;

        if(v.phaseA >= 1.0)
            v.phaseA -= 1.0;
        if(v.phaseA < 0.0)
            v.phaseA += 1.0;

        // Temporary fixed to frame 0 (scanning comes later)
        return (double)readFrame(wavA, v.phaseA, 0, frameSize);
    }


    //==========================================================
    // processInternal
    //==========================================================
    void processInternal(span<float,2>& f, VoiceData& v)
    {
        float s = (float)tick(v);
        f[0] = s;
        f[1] = s;
    }

    //==========================================================
    // process()
    //==========================================================
    template<typename PD>
    void process(PD& pd)
    {
        auto& v = voices.get();
        auto fd = pd.toFrameData();

        while(fd.next())
            processInternal(fd.toSpan(), v);
    }

    //==========================================================
    // Required legacy SNEX API
    //==========================================================
    void processFrame(span<float,2>& fd)
    {
        auto& v = voices.get();
        processInternal(fd, v);
    }

    void reset()
    {
        for(auto& v : voices)
            v.reset();
    }

    void handleHiseEvent(HiseEvent& e)
    {
        auto& v = voices.get();

        if(e.isNoteOn())
        {
            int nn = e.getNoteNumber();
            v.noteNumber = nn;

            double freq = 440.0 * Math.pow(2.0, ((double)nn - 69.0) / 12.0);
            v.freqA = freq;

            v.reset();
        }
    }
//==========================================================
    // Helper must be here (before spans + before ExternalData)
    //==========================================================


  template<int P>
void setParameter(double v)
{
    auto& vd = voices.get();
}

};