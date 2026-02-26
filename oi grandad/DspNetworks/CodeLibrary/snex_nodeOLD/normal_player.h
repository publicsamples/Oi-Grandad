template <int NV> struct normal_player
{
    SNEX_NODE(normal_player);

    using IndexType = index::clamped<0, false>;
    using FloatIndex = index::unscaled<double, IndexType>;
    using InterpolatorType = index::lerp<FloatIndex>;

    static const int NUM_CHANNELS = 2;

    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 0.0;

    // Pitch knob value in SEMITONES (-12 .. +12)
    double pitchSemitones = 0.0;

    // Loop toggle
    bool loop = 0;

    // MIDI note that plays the sample at normal speed
    int rootNote = 60;

    struct VoiceData
    {
        double uptime = 0.0;   // read position in samples
        double delta = 1.0;    // playback speed
        int noteNumber = 60;   // MIDI note for this voice

        void reset()
        {
            uptime = 0.0;
        }

        double bump()
        {
            double rv = uptime;
            uptime += delta;
            return rv;
        }
    };

    PolyData<VoiceData, NV> voiceData;

    void prepare(PrepareSpecs ps)
    {
        voiceData.prepare(ps);
        sr = ps.sampleRate;
    }

    void reset()
    {
        for (auto& v : voiceData)
            v.reset();
    }

    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    {
        double pos = v.bump();

        // Stop safely before end (important for interpolation)
        if (pos >= (data.numSamples - 1))
        {
            if (loop)
            {
                v.reset();
                pos = 0.0;
            }
            else
            {
                return;
            }
        }

        InterpolatorType idx(pos);

        for (int ch = 0; ch < NUM_CHANNELS; ch++)
            fd[ch] = sample[ch][idx];
    }

    template <typename ProcessDataType>
    void process(ProcessDataType& pd)
    {
        if (data.numSamples == 0)
            return;

        DataReadLock sl(data);
        auto& v = voiceData.get();
        auto fd = pd.toFrameData();

        while (fd.next())
            processInternal(fd.toSpan(), v);

        data.setDisplayedValue(v.uptime);

        bool isPlaying = (int)v.uptime < data.numSamples;
        gate.setModValueIfChanged((double)isPlaying);
    }

    void processFrame(span<float, NUM_CHANNELS>& fd)
    {
        if (data.numSamples == 0)
            return;

        DataReadLock sl(data);
        auto& v = voiceData.get();
        processInternal(fd, v);
    }

    // MIDI handling: pitch tracks note number
    void handleHiseEvent(HiseEvent& e)
    {
        if (e.isNoteOn())
        {
            auto& v = voiceData.get();
            v.reset();
            v.noteNumber = e.getNoteNumber();

            // --- inline pitch math (SNEX-safe) ---
            double midiSemis = (double)(v.noteNumber - rootNote);
            double totalSemis = midiSemis + pitchSemitones;
            double pitchMult = Math.pow(2.0, totalSemis / 12.0);
            v.delta = (data.sampleRate / sr) * pitchMult;
        }
    }

    // Update pitch for all voices (called when knob or sample changes)
    void updateDelta()
    {
        if (data.numSamples == 0 || sr == 0.0)
            return;

        for (auto& v : voiceData)
        {
            double midiSemis = (double)(v.noteNumber - rootNote);
            double totalSemis = midiSemis + pitchSemitones;
            double pitchMult = Math.pow(2.0, totalSemis / 12.0);
            v.delta = (data.sampleRate / sr) * pitchMult;
        }
    }

    void setExternalData(const ExternalData& ed, int index)
    {
        data = ed;

        ed.referBlockTo(sample[0], 0);
        ed.referBlockTo(sample[1], 1);

        updateDelta();
        reset();
    }

    ModValue gate;

    bool handleModulation(double& value)
    {
        return gate.getChangedValue(value);
    }

    template <int P>
    void setParameter(double v)
    {
        // Pitch knob: 0..1 → -12..+12 semitones
        if (P == 0)
        {
            pitchSemitones = (v * 24.0) - 12.0;
            updateDelta();
        }

        // Loop toggle
        if (P == 1)
        {
            loop = v;
        }
    }
};
