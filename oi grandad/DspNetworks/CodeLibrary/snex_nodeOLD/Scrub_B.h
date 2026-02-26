template <int NV> struct Scrub_B
{
    SNEX_NODE(Scrub_B);

    static const int NUM_CHANNELS = 2;

    //========================================================
    // EXTERNAL DATA
    //========================================================
    ExternalData data;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 44100.0;

    //========================================================
    // PARAMETERS (new layout)
    //========================================================
    double pitchSemitones = 0.0;   // P0
    double scrub = 0.0;            // P1
    double grainMs = 50.0;         // P2
    int playbackMode = 0;          // P3 (0 = Scrub, 1 = WSOLA placeholder)
  
	double searchWinSize = 0.5;   // P4 — 0..1, fraction of grain window for WSOLA
	
    //========================================================
    // PER-VOICE DATA
    //========================================================
struct VoiceData
{
	// Core scrub engine
	double uptime = 0.0;
	double delta = 1.0;
	int noteNumber = 60;
	
	double grainAPos = 0.0;
	double grainBPos = 0.0;
	
	// Future pitch (unused until PSOLA)
	double readPosA = 0.0;
	double readPosB = 0.0;
	
	// WSOLA state (Patch 2+)
	double wsolaWritePos = 0.0;
	double wsolaReadPos = 0.0;
	double wsolaPhase = 0.0;
	
	double lastZC = 0.0;
	double prevSample = 0.0;
	double period = 100.0;       // samples; default ~440Hz
	double periodPos = 0.0;      // running counter inside a period
	

	
	void reset()
	{
		uptime = 0.0;
		grainAPos = 0.0;
		grainBPos = 0.0;
		
		readPosA = 0.0;
		readPosB = 0.0;
		
		wsolaWritePos = 0.0;
		wsolaReadPos = 0.0;
		wsolaPhase = 0.0;
		
		lastZC = 0.0;
		prevSample = 0.0;
		period = 100.0;
		periodPos = 0.0;
	}
};

    PolyData<VoiceData, NV> voiceData;

    //========================================================
    // PREP
    //========================================================
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

    //========================================================
    // UPDATE PITCH DELTA
    //========================================================
    void updateDelta()
    {
        for (auto& v : voiceData)
        {
            double semi = (double)(v.noteNumber - 60) + pitchSemitones;
            v.delta = Math.pow(2.0, semi / 12.0);
        }
    }

    inline double hann(double x)
    {
        return 0.5 - 0.5 * Math.cos(2.0 * Math.PI * x);
    }

    //========================================================
    // MODE 0: SCRUB TIME-STRETCH (dual grain)
    //========================================================
    void modeScrub(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    {
        int W = (int)(grainMs * (sr * 0.001));
        if (W < 16) W = 16;
        if (W > 262144) W = 262144;
    
        int halfW = (int)((double)W * 0.5);
    
        double maxStart = (double)data.numSamples - W - 2.0;
        if (maxStart <= 0.0) return;
    
        //====================================================
        // NEW GRAIN CYCLE
        //====================================================
        if (v.uptime == 0.0)
        {
            double base = scrub * maxStart;
            v.grainAPos = base;
            v.grainBPos = base + (double)halfW;
        }
    
        //====================================================
        // ADVANCE PHASE
        //====================================================
        v.uptime += 1.0;
        if (v.uptime >= W)
            v.uptime = 0.0;
    
        double phaseA = v.uptime;
        double phaseB = v.uptime + (double)halfW;
        if (phaseB >= W)
            phaseB -= (double)W;
    
        //====================================================
        // APPLY NORMAL VARISPEED PITCH (delta only)
        //====================================================
        v.grainAPos += v.delta;
        v.grainBPos += v.delta;
    
        //====================================================
        // CLAMP
        //====================================================
        if (v.grainAPos >= data.numSamples - 2) v.grainAPos = data.numSamples - 2;
        if (v.grainBPos >= data.numSamples - 2) v.grainBPos = data.numSamples - 2;
    
        //====================================================
        // WINDOWS
        //====================================================
        double wA = hann(phaseA / (double)W);
        double wB = hann(phaseB / (double)W);
    
        //====================================================
        // READ A
        //====================================================
        int iA = (int)v.grainAPos;
        double fA = v.grainAPos - (double)iA;
        double a =
            (1.0 - fA) * sample[0][iA] +
                    fA * sample[0][iA + 1];
    
        //====================================================
        // READ B
        //====================================================
        int iB = (int)v.grainBPos;
        double fB = v.grainBPos - (double)iB;
        double b =
            (1.0 - fB) * sample[0][iB] +
                    fB * sample[0][iB + 1];
    
        //====================================================
        // MIX
        //====================================================
        double out = a * wA + b * wB;
        fd[0] += (float)out;
        fd[1] += (float)out;
    }
 
    
    //========================================================
    // MODE 1: WSOLA (Patch 3 — correlation search, SNEX safe)
    //========================================================
  void modeWSOLA(span<float, NUM_CHANNELS>& fd, VoiceData& v)
{
    int W = (int)(grainMs * (sr * 0.001));
    if (W < 32) W = 32;

    double maxPos = (double)data.numSamples - W - 2.0;
    if (maxPos <= 0.0) return;

    // ------------------------------------------------------------
    // STRICT SCRUB CENTER
    // ------------------------------------------------------------
    double center = scrub * maxPos;

    // pitch ratio from MIDI + slider
    double pitchRatio = v.delta;

    // synthesis hop (fixed)
    double Hs = (double)W * 0.5;

    // analysis hop (pitch controls this)
    double Ha = Hs * pitchRatio;

    // search window (tight, anchored to scrub)
    int WS = (int)(searchWinSize * (double)W);
    if (WS < 8) WS = 8;
    if (WS > W / 2) WS = W / 2;

    // ------------------------------------------------------------
    // INIT
    // ------------------------------------------------------------
    if (v.wsolaPhase == 0.0)
    {
        v.wsolaWritePos = center;
        v.wsolaReadPos  = center;
    }

    // ------------------------------------------------------------
    // PHASE ADVANCE
    // ------------------------------------------------------------
    v.wsolaPhase = v.wsolaPhase + 1.0;

    if (v.wsolaPhase >= Hs)
    {
        double negHs = 0.0 - Hs;
        v.wsolaPhase = v.wsolaPhase + negHs;

        // --------------------------------------------------------
        // STRICT: write position stays locked to scrub center
        // --------------------------------------------------------
        v.wsolaWritePos = center;

        // pitch hop (read head only)
        v.wsolaReadPos = v.wsolaReadPos + Ha;

        // --------------------------------------------------------
        // HARD LIMIT read head inside scrub window
        // --------------------------------------------------------
        double minBound = center + (0.0 - (double)WS);
        double maxBound = center + (double)WS;

        if (v.wsolaReadPos < minBound)
            v.wsolaReadPos = minBound;

        if (v.wsolaReadPos > maxBound)
            v.wsolaReadPos = maxBound;

        double pred = v.wsolaReadPos;

        // --------------------------------------------------------
        // CORRELATION (search only around scrub center)
        // --------------------------------------------------------
        double bestScore = -1.0;
        double bestPos   = pred;

        double negWSd = 0.0 - (double)WS;
        int offs = (int)negWSd;

        while (offs <= WS)
        {
            double cand = center + (double)offs;

            if (cand < 0.0) cand = 0.0;
            if (cand > maxPos) cand = maxPos;

            double score = 0.0;

            int k = 0;
            while (k < 32)
            {
                double posA = center + (double)k;
                int iA = (int)posA;
                if (iA >= data.numSamples - 1) iA = data.numSamples - 2;

                double posB = cand + (double)k;
                int iB = (int)posB;
                if (iB >= data.numSamples - 1) iB = data.numSamples - 2;

                double a = sample[0][iA];
                double b = sample[0][iB];

                score = score + (a * b);
                k = k + 1;
            }

            if (score > bestScore)
            {
                bestScore = score;
                bestPos = cand;
            }

            offs = offs + 1;
        }

        v.wsolaReadPos = bestPos;
    }

    // ------------------------------------------------------------
    // CROSSFADE
    // ------------------------------------------------------------
    double t = v.wsolaPhase / Hs;

    double c = Math.cos(Math.PI * t);
    double negc = 0.0 - c;
    double wB = 0.5 + (0.5 * negc);

    double negWB = 0.0 - wB;
    double wA = 1.0 + negWB;

    // ------------------------------------------------------------
    // READ A (center grain)
    // ------------------------------------------------------------
    double posA = center + v.wsolaPhase;
    int last = data.numSamples - 2;

    int iA = (int)posA;
    if (iA > last) iA = last;
    if (iA < 0) iA = 0;

    double neg_iA = 0.0 - (double)iA;
    double fracA = posA + neg_iA;

    double negFracA = 0.0 - fracA;
    double w0A = 1.0 + negFracA;
    double w1A = fracA;

    int iA1 = iA + 1;
    double sA = (w0A * sample[0][iA]) + (w1A * sample[0][iA1]);

    // ------------------------------------------------------------
    // READ B (pitch-shifted grain)
    // ------------------------------------------------------------
    double posB = v.wsolaReadPos + v.wsolaPhase;

    int iB = (int)posB;
    if (iB > last) iB = last;
    if (iB < 0) iB = 0;

    double neg_iB = 0.0 - (double)iB;
    double fracB = posB + neg_iB;

    double negFracB = 0.0 - fracB;
    double w0B = 1.0 + negFracB;
    double w1B = fracB;

    int iB1 = iB + 1;
    double sB = (w0B * sample[0][iB]) + (w1B * sample[0][iB1]);

    // ------------------------------------------------------------
    // MIX
    // ------------------------------------------------------------
    double out = (sA * wA) + (sB * wB);

    fd[0] += (float)out;
    fd[1] += (float)out;
}

    
    //========================================================
    // MODE DISPATCH
    //========================================================
    inline void runMode(span<float, NUM_CHANNELS>& fd, VoiceData& v)
{
    if (playbackMode == 0)
        modeScrub(fd, v);
    else if (playbackMode == 1)
        modeWSOLA(fd, v);
}

    //========================================================
    // PROCESS (vector)
    //========================================================
    template <typename PD>
    void process(PD& pd)
    {
        if (data.numSamples < 10) return;

        DataReadLock sl(data);
        auto& v = voiceData.get();

        auto frames = pd.toFrameData();
        while (frames.next())
            runMode(frames.toSpan(), v);

        data.setDisplayedValue(v.uptime);
    }

    //========================================================
    // PROCESS (single frame)
    //========================================================
    template <int C>
    void processFrame(span<float, C>& fd)
    {
        if (data.numSamples < 10) return;

        DataReadLock sl(data);
        auto& v = voiceData.get();

        span<float, NUM_CHANNELS> out;
        out[0] = fd[0];
        out[1] = fd[1];

        runMode(out, v);

        fd[0] = out[0];
        fd[1] = out[1];
        data.setDisplayedValue(v.uptime);
    }

    //========================================================
    // EVENTS
    //========================================================
    void handleHiseEvent(HiseEvent& e)
    {
        if (e.isNoteOn())
        {
            auto& v = voiceData.get();
            v.reset();
            v.noteNumber = e.getNoteNumber();
            updateDelta();
        }
    }

    //========================================================
    // EXTERNAL DATA
    //========================================================
    void setExternalData(const ExternalData& ed, int index)
    {
        data = ed;
        ed.referBlockTo(sample[0], 0);
        ed.referBlockTo(sample[1], 1);
        updateDelta();
        reset();
    }

    //========================================================
    // PARAMETER ROUTING (new layout)
    //========================================================
    template <int P>
    void setParameter(double v)
    {
        if (P == 0) { pitchSemitones = (v * 24.0) - 12.0; updateDelta(); }
        if (P == 1) scrub = v;
        if (P == 2) grainMs = v;
        if (P == 3) playbackMode = (int)v;  // 0 = Scrub, 1 = WSOLA (future)
       if (P == 4)
{
    if (v < 0.05) v = 0.05;
    if (v > 1.0)  v = 1.0;
    searchWinSize = v;
}
    }
};
