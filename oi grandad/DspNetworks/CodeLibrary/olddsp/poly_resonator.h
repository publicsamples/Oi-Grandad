template <int NV>
struct poly_resonator
{
    SNEX_NODE(poly_resonator);

    static const int NUM_CHANNELS = 2;

    double sr = 44100.0;

    // Controls
    double feedback = 0.7;
    double tone = 0.5;
    double mix = 0.5;
    double mode = 1.0;        // 0 = off, 1 = active
    double structure = 0.0;   // 0 = Karplus, 1 = metallic

    // ============================
    // Voice Data
    // ============================

    struct VoiceData
    {
        static const int DelaySize = 48000;

        span<float, DelaySize> buffer;

        int writeIndex = 0;
        int delaySamples = 200;
        double lpState = 0.0;
        int noteNumber = 60;

        void reset()
        {
            writeIndex = 0;
            lpState = 0.0;

            for(int i = 0; i < DelaySize; i++)
                buffer[i] = 0.0f;
        }
    };

    PolyData<VoiceData, NV> voiceData;

    // ============================
    // Prepare
    // ============================

    void prepare(PrepareSpecs ps)
    {
        sr = ps.sampleRate;
        voiceData.prepare(ps);
    }

    void reset() {}

    // ============================
    // Processing
    // ============================

    template <int C>
    void processFrame(span<float, C>& data)
    {
        if(mode < 0.5)
            return; // OFF

        auto& v = voiceData.get();

        float input = 0.5f * (data[0] + data[1]);

        int readIndex = v.writeIndex - v.delaySamples;
        if(readIndex < 0)
            readIndex += VoiceData::DelaySize;

        float delayed = v.buffer[readIndex];

        // ============================
        // Frequency-aware damping
        // ============================

        double freq = sr / (double)v.delaySamples;
        double normFreq = freq / 8000.0;
        if(normFreq > 1.0) normFreq = 1.0;
        if(normFreq < 0.0) normFreq = 0.0;

        // Structure morph
        double s = structure; // 0–1

        // Base cutoff from tone
        double baseCut = 0.02 + tone * 0.48;

        // More metallic = less damping
        double cutoff = baseCut * (1.0 - 0.6 * normFreq * (1.0 - s));

        v.lpState += cutoff * (delayed - v.lpState);

        // Feedback compensation
        double fb = feedback * (1.0 - 0.3 * normFreq);

        // Metallic behaviour: alternating sign component
       double sign = 1.0;

if((v.writeIndex % 2) != 0)
    sign = -1.0;

double metallic = delayed * sign;
        double blended = (1.0 - s) * v.lpState + s * metallic;

        float out = (float)blended;

        // Write back into delay
        v.buffer[v.writeIndex] = input + out * fb;

        v.writeIndex++;
        if(v.writeIndex >= VoiceData::DelaySize)
            v.writeIndex = 0;

        // Mix
        data[0] = data[0] * (1.0 - mix) + out * mix;
        data[1] = data[1] * (1.0 - mix) + out * mix;
    }

    template <typename ProcessDataType>
    void process(ProcessDataType& data)
    {
        auto fd = data.toFrameData();

        while(fd.next())
            processFrame(fd.toSpan());
    }

    // ============================
    // MIDI
    // ============================

    inline void updateDelay(VoiceData& v)
    {
        double freq = 440.0 * Math.pow(2.0, (v.noteNumber - 69) / 12.0);
        double delay = sr / freq;

        if(delay < 2.0)
            delay = 2.0;

        if(delay >= VoiceData::DelaySize)
            delay = VoiceData::DelaySize - 1;

        v.delaySamples = (int)delay;
    }

    void handleHiseEvent(HiseEvent& e)
    {
        if(e.isNoteOn())
        {
            auto& v = voiceData.get();
            v.noteNumber = e.getNoteNumber();
            v.reset();
            updateDelay(v);
        }
    }

    void setExternalData(const ExternalData& d, int index) {}

    // ============================
    // Parameters
    // ============================

    template<int P>
    void setParameter(double v)
    {
        if(P == 0) feedback = v;
        if(P == 1) tone = v;
        if(P == 2) structure = v;  // <-- fixed
        if(P == 3) mix = v;
        if(P == 4) mode = v;
    }
};