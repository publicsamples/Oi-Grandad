template <int NV>
struct granular_player_spec: public data::base
{
    SNEX_NODE(granular_player_spec);

    static const int NUM_CHANNELS = 2;
    static const int MAX_GRAINS   = 16;
  
    
    ExternalData audioData;
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 0.0;

    // Parameters
    double scrub = 0.0;       // 0..1 UI
    double grainMs = 50.0;
    double grainSize = 2048.0;
    double scrubB = 0.0;
    double scrubC = 0.0;
    double scrubD = 0.0;
   
    double pitchSemitones = 0.0;
    int rootNote = 60;

    int scrubStepCount = 64;      // stepping of scrub
	double density = 1.0;   // 0..1 morph position
    double windowShape = 0.0; 
	double panSpread = 0.0; // 0..1
	double pitchSpread = 0.0;     // 0..1 amount (modes 0/1)
    double pitchSyncInput = 0.0; // raw external input for mode 2 (Hz or ms)
	double pitchMode = 0.0; 
    double noiseSineMix = 0.5;   // 0..1 (0=noise, 1=sines)
    double harmonicity = 0.0;    // 0..1 (log bands -> harmonic series)
    double analysisWindowMs = 80.0; // raw ms input
    double freqLock = 0.18;      // 0..1 semitone pull
    double partials = 12.0;      // 1..16 active sine count

  double maxGrains = 4.0;     // 1–16
  double scrubMode = 0.0;     // 0 = normal, 1 = multi, 2 = spectral, 3 = multi
  double scrubBlend = 0.0;    // 0–1 shaping
  double reverse = 0.0;   // 0 = forward, 1 = reverse
  double phaseScatter = 0.0;   // 0..1 per-grain envelope phase scatter
  // Subtle density-linked grain start spread. Tweak this to taste.
  // Final spread in samples = maxStart * densityPositionSpreadRange * density.
  const double densityPositionSpreadRange = 0.03;

  // Spectral mode constants.
  static const int MAX_PARTIALS = 16;
  bool spectralReady = false;
		
    // -----------------------------------------------------
    struct VoiceData
{
    double scanPos = 0.0;
    double delta   = 1.0;
    int noteNumber = 60;

    double scrubQ = 0.0;
  double speedPhase = 0.0;
    int specUpdateCounter = 0;
    double specBaseHz = 120.0;
    double specF0Conf = 0.0;
    double specEnergy = 0.0;
    double specBrightness = 0.0;
    

double schedPhase = 0.0;
double schedStart = 0.0;
bool   schedActive = false;
double schedPhase2 = 0.0;
double schedStart2 = 0.0;
bool   schedActive2 = false;

double schedPhase3 = 0.0;
double schedStart3 = 0.0;
bool   schedActive3 = false;

double schedPhase4 = 0.0;
double schedStart4 = 0.0;
bool   schedActive4 = false;

double schedPhase5 = 0.0;
double schedStart5 = 0.0;
bool   schedActive5 = false;

double schedPhase6 = 0.0;
double schedStart6 = 0.0;
bool   schedActive6 = false;

double schedPhase7 = 0.0;
double schedStart7 = 0.0;
bool   schedActive7 = false;

double schedPhase8 = 0.0;
double schedStart8 = 0.0;
bool   schedActive8 = false;
double schedPhase9 = 0.0;
double schedStart9 = 0.0;
bool   schedActive9 = false;
double schedPhase10 = 0.0;
double schedStart10 = 0.0;
bool   schedActive10 = false;
double schedPhase11 = 0.0;
double schedStart11 = 0.0;
bool   schedActive11 = false;
double schedPhase12 = 0.0;
double schedStart12 = 0.0;
bool   schedActive12 = false;
double schedPhase13 = 0.0;
double schedStart13 = 0.0;
bool   schedActive13 = false;
double schedPhase14 = 0.0;
double schedStart14 = 0.0;
bool   schedActive14 = false;
double schedPhase15 = 0.0;
double schedStart15 = 0.0;
bool   schedActive15 = false;
double schedPhase16 = 0.0;
double schedStart16 = 0.0;
bool   schedActive16 = false;
double specFreq1 = 120.0;
double specFreq2 = 240.0;
double specFreq3 = 360.0;
double specFreq4 = 480.0;
double specFreq5 = 600.0;
double specFreq6 = 720.0;
double specFreq7 = 840.0;
double specFreq8 = 960.0;
double specFreq9 = 1080.0;
double specFreq10 = 1200.0;
double specFreq11 = 1320.0;
double specFreq12 = 1440.0;
double specFreq13 = 1560.0;
double specFreq14 = 1680.0;
double specFreq15 = 1800.0;
double specFreq16 = 1920.0;

// Output diffusion state (allpass, per voice)
double ap1L = 0.0;
double ap1R = 0.0;
double ap2L = 0.0;
double ap2R = 0.0;
double noiseStateL = 0.173;
double noiseStateR = 0.731;

 void reset()
{
    scanPos = 0.0;
    scrubQ  = 0.0;
    speedPhase = 0.0;
    specUpdateCounter = 0;
    specBaseHz = 120.0;
    specF0Conf = 0.0;
    specEnergy = 0.0;
    specBrightness = 0.0;

    schedPhase = 0.0;
    schedStart = 0.0;
    schedActive = false;

    schedPhase2 = 0.0;
    schedStart2 = 0.0;
    schedActive2 = false;

    schedPhase3 = 0.0;
    schedStart3 = 0.0;
    schedActive3 = false;

    schedPhase4 = 0.0;
    schedStart4 = 0.0;
    schedActive4 = false;
    
    schedPhase5 = 0.0;
    schedStart5 = 0.0;
    schedActive5 = false;
    
    schedPhase6 = 0.0;
    schedStart6 = 0.0;
    schedActive6 = false;
    
    schedPhase7 = 0.0;
    schedStart7 = 0.0;
    schedActive7 = false;
    
    schedPhase8 = 0.0;
    schedStart8 = 0.0;
    schedActive8 = false;
    
    schedPhase9 = 0.0;
    schedStart9 = 0.0;
    schedActive9 = false;

    schedPhase10 = 0.0;
    schedStart10 = 0.0;
    schedActive10 = false;

    schedPhase11 = 0.0;
    schedStart11 = 0.0;
    schedActive11 = false;

    schedPhase12 = 0.0;
    schedStart12 = 0.0;
    schedActive12 = false;

    schedPhase13 = 0.0;
    schedStart13 = 0.0;
    schedActive13 = false;

    schedPhase14 = 0.0;
    schedStart14 = 0.0;
    schedActive14 = false;

    schedPhase15 = 0.0;
    schedStart15 = 0.0;
    schedActive15 = false;

    schedPhase16 = 0.0;
    schedStart16 = 0.0;
    schedActive16 = false;
    specFreq1 = 120.0;
    specFreq2 = 240.0;
    specFreq3 = 360.0;
    specFreq4 = 480.0;
    specFreq5 = 600.0;
    specFreq6 = 720.0;
    specFreq7 = 840.0;
    specFreq8 = 960.0;
    specFreq9 = 1080.0;
    specFreq10 = 1200.0;
    specFreq11 = 1320.0;
    specFreq12 = 1440.0;
    specFreq13 = 1560.0;
    specFreq14 = 1680.0;
    specFreq15 = 1800.0;
    specFreq16 = 1920.0;

    ap1L = 0.0;
    ap1R = 0.0;
    ap2L = 0.0;
    ap2R = 0.0;
    noiseStateL = 0.173;
    noiseStateR = 0.731;

}
};   // ← absolutely required

PolyData<VoiceData, NV> voiceData;

    // -----------------------------------------------------
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

    inline double clamp01(double x)
    {
        if (x < 0.0) return 0.0;
        if (x > 1.0) return 1.0;
        return x;
    }

    inline double smooth01(double x)
    {
        x = clamp01(x);
        return x * x * (3.0 - 2.0 * x);
    }

    inline double tukey(double x, double alpha)
    {
        x = clamp01(x);
        if (alpha <= 0.0) return 1.0;
        if (alpha >= 1.0) return hann(x);

        double edge = 0.5 * alpha;
        if (x < edge)
        {
            double t = x / edge;
            return 0.5 - 0.5 * Math.cos(Math.PI * t);
        }
        if (x > (1.0 - edge))
        {
            double t = (1.0 - x) / edge;
            return 0.5 - 0.5 * Math.cos(Math.PI * t);
        }

        return 1.0;
    }

    inline double triangle(double x)
    {
        x = clamp01(x);
        return 1.0 - Math.abs(2.0 * x - 1.0);
    }

    inline double cosineWindow(double x)
    {
        x = clamp01(x);
        return Math.sin(Math.PI * x);
    }

    inline double blackman(double x)
    {
        x = clamp01(x);
        return 0.42 - 0.5 * Math.cos(2.0 * Math.PI * x) + 0.08 * Math.cos(4.0 * Math.PI * x);
    }

    // Legacy-style Hann shaper:
    // 0.0 = plain Hann
    // 1.0 = narrower + steeper falloff
    inline double morphedWindow(double phaseNorm)
    {
        double x = clamp01(phaseNorm);
        double shape = clamp01(windowShape);

        // Width shrink around center.
        double width = 1.0 - 0.85 * shape;
        if (width < 0.05) width = 0.05;

        double c = 2.0 * x - 1.0;    // -1..+1
        double cw = c / width;       // width-shaped domain
        if (cw <= -1.0 || cw >= 1.0)
            return 0.0;

        double xw = 0.5 * (cw + 1.0); // back to 0..1
        double w = hann(xw);

        // Falloff steepness.
        double fall = 1.0 + 3.0 * shape;
        return Math.pow(w, fall);
    }
    
    
    inline double A2curve(double x)
    {
        // Base cluster at beginning: (1-x)^2 * (1 - 0.5x)
        double base = (1.0 - x);
        base = base * base * (1.0 - 0.5 * x);
    
        // Map base (0..1) to symmetric -1..+1 range
        return (base * -1.0) + x;
    }

    inline double wrap01(double x)
    {
        x = x - Math.floor(x);
        if (x < 0.0) x += 1.0;
        return x;
    }

    // Deterministic per-grain envelope phase offset (in cycles).
    // This moves envelope timing only, not grain read position.
    inline double phaseScatterOffset(int grainIndex, double scrubVal)
    {
        if (phaseScatter <= 0.0)
            return 0.0;

        double seed = (double)(grainIndex + 1) * 37.17 + scrubVal * 19.73;
        double r = Math.sin(seed * 12.9898 + 78.233); // -1..1

        double p = phaseScatter * phaseScatter; // finer low-end control
        double maxScatterCycles = 0.45 * p;

        return r * maxScatterCycles;
    }

    // Density-driven envelope phase staggering per grain.
    // Only active in stack mode (scrubBlend < 0.5).
    // In morph mode, density is reserved for crossfade weighting only.
    inline double cloudWindowPhase(double phaseNorm, int grainIndex)
    {
        double d = (scrubBlend < 0.5) ? clamp01(density) : 0.0;
        // Keep some anchor so it doesn't become too "chorused"/detached.
        double maxSpreadCycles = 1.2 * d;

        double denom = (double)(MAX_GRAINS - 1);
        if (denom < 1.0) denom = 1.0;

        double frac = (double)grainIndex / denom; // 0..1 across grains
        double offset = frac * maxSpreadCycles;

        double scatter = phaseScatterOffset(grainIndex, scrub);
        return wrap01(phaseNorm + offset + scatter);
    }

    // Mode 2 sync input converter:
    // - If input > 20, treat as milliseconds and convert to Hz.
    // - Else treat as Hz.
    // Output is a playback ratio around syncReferenceHz.
    inline double tempoSyncRatioFromInput(double x)
    {
        if (x <= 0.0)
            return 1.0;

        double hz = x;

        // Heuristic: large values are almost certainly milliseconds.
        if (x > 20.0)
            hz = 1000.0 / x;

        // 2 Hz = 500 ms quarter-note reference -> ratio 1.0
        const double syncReferenceHz = 2.0;
        double ratio = hz / syncReferenceHz;

        if (ratio < 0.125) ratio = 0.125;
        if (ratio > 8.0)   ratio = 8.0;

        return ratio;
    }

    inline double getPitchModeMul(int pitchState, double spreadNorm, double detuneSeed, double harmonicTarget)
    {
        if (pitchState == 0)
        {
            double spread = pitchSpread * spreadNorm;
            return 1.0 + spread * Math.sin(detuneSeed);
        }
        else if (pitchState == 1)
        {
            return 1.0 + (harmonicTarget - 1.0) * pitchSpread;
        }

        // Mode 2: tempo-sync lock (raw external input via pitchSpread parameter).
        return tempoSyncRatioFromInput(pitchSyncInput);
    }

    // -----------------------------------------------------
    void updateDelta(VoiceData& v)
    {
          double semis = (double)v.noteNumber - (double)rootNote;

    semis += pitchSemitones;

    double mult = Math.pow(2.0, semis / 12.0);

    v.delta = (audioData.sampleRate / sr) * mult;
}

    // -----------------------------------------------------
    void updateGrainSize()
    {
        if (sr > 0.0)
            grainSize = grainMs * sr * 0.001;

        if (grainSize < 16.0)
            grainSize = 16.0;

        double maxAllowed = (double)audioData.numSamples - 2.0;
        if (grainSize > maxAllowed)
            grainSize = maxAllowed;
    }

    // -----------------------------------------------------
    inline double quantiseScrub(double raw, const ExternalData& d)
    {
        if (scrubStepCount <= 1)
            return raw;

        if (d.numSamples <= 1)
            return raw;

        double step = 1.0 / (double)scrubStepCount;
        return step * Math.floor(raw / step);
    }

inline double getGrainWeight(int i, int grainCount, bool isStackMode)
{
    if (i < 0 || i >= grainCount)
        return 0.0;

    // In morph mode, keep per-grain gain flat and avoid density weighting.
    if (!isStackMode)
        return 1.0;

    if (grainCount <= 1)
        return 1.0;

    double pos = (double)i / (double)(grainCount - 1);

    // Base clustered shape (small at high indices)
    double base = 1.0 - pos;
    base = base * base;
    base = base * (0.5 + 0.5 * (1.0 - pos));

    // density = 0 → UNIFORM (no weighting)
    // density = 1 → BASE SHAPE (cluster)
    double d = clamp01(density);

    // Correct blend direction (FIXED)
    double w = base * d + 1.0 * (1.0 - d);

    return w;
}

inline int getScrubState()
{
    // Menu slots:
    // 0 = normal, 1 = multi, 2 = spectral, 3 = multi (fallback)
    if (scrubMode < 0.25) return 0;
    if (scrubMode < 0.50) return 1;
    if (scrubMode < 0.75) return 2;
    return 1;
}

inline double getSpecPhase(const VoiceData& v, int p)
{
    if (p == 0) return v.schedPhase;
    if (p == 1) return v.schedPhase2;
    if (p == 2) return v.schedPhase3;
    if (p == 3) return v.schedPhase4;
    if (p == 4) return v.schedPhase5;
    if (p == 5) return v.schedPhase6;
    if (p == 6) return v.schedPhase7;
    if (p == 7) return v.schedPhase8;
    if (p == 8) return v.schedPhase9;
    if (p == 9) return v.schedPhase10;
    if (p == 10) return v.schedPhase11;
    if (p == 11) return v.schedPhase12;
    if (p == 12) return v.schedPhase13;
    if (p == 13) return v.schedPhase14;
    if (p == 14) return v.schedPhase15;
    return v.schedPhase16;
}

inline void setSpecPhase(VoiceData& v, int p, double x)
{
    if (p == 0) v.schedPhase = x;
    else if (p == 1) v.schedPhase2 = x;
    else if (p == 2) v.schedPhase3 = x;
    else if (p == 3) v.schedPhase4 = x;
    else if (p == 4) v.schedPhase5 = x;
    else if (p == 5) v.schedPhase6 = x;
    else if (p == 6) v.schedPhase7 = x;
    else if (p == 7) v.schedPhase8 = x;
    else if (p == 8) v.schedPhase9 = x;
    else if (p == 9) v.schedPhase10 = x;
    else if (p == 10) v.schedPhase11 = x;
    else if (p == 11) v.schedPhase12 = x;
    else if (p == 12) v.schedPhase13 = x;
    else if (p == 13) v.schedPhase14 = x;
    else if (p == 14) v.schedPhase15 = x;
    else v.schedPhase16 = x;
}

inline double getSpecAmp(const VoiceData& v, int p)
{
    if (p == 0) return v.schedStart;
    if (p == 1) return v.schedStart2;
    if (p == 2) return v.schedStart3;
    if (p == 3) return v.schedStart4;
    if (p == 4) return v.schedStart5;
    if (p == 5) return v.schedStart6;
    if (p == 6) return v.schedStart7;
    if (p == 7) return v.schedStart8;
    if (p == 8) return v.schedStart9;
    if (p == 9) return v.schedStart10;
    if (p == 10) return v.schedStart11;
    if (p == 11) return v.schedStart12;
    if (p == 12) return v.schedStart13;
    if (p == 13) return v.schedStart14;
    if (p == 14) return v.schedStart15;
    return v.schedStart16;
}

inline void setSpecAmp(VoiceData& v, int p, double x)
{
    if (p == 0) v.schedStart = x;
    else if (p == 1) v.schedStart2 = x;
    else if (p == 2) v.schedStart3 = x;
    else if (p == 3) v.schedStart4 = x;
    else if (p == 4) v.schedStart5 = x;
    else if (p == 5) v.schedStart6 = x;
    else if (p == 6) v.schedStart7 = x;
    else if (p == 7) v.schedStart8 = x;
    else if (p == 8) v.schedStart9 = x;
    else if (p == 9) v.schedStart10 = x;
    else if (p == 10) v.schedStart11 = x;
    else if (p == 11) v.schedStart12 = x;
    else if (p == 12) v.schedStart13 = x;
    else if (p == 13) v.schedStart14 = x;
    else if (p == 14) v.schedStart15 = x;
    else v.schedStart16 = x;
}

inline double getSpecFreq(const VoiceData& v, int p)
{
    if (p == 0) return v.specFreq1;
    if (p == 1) return v.specFreq2;
    if (p == 2) return v.specFreq3;
    if (p == 3) return v.specFreq4;
    if (p == 4) return v.specFreq5;
    if (p == 5) return v.specFreq6;
    if (p == 6) return v.specFreq7;
    if (p == 7) return v.specFreq8;
    if (p == 8) return v.specFreq9;
    if (p == 9) return v.specFreq10;
    if (p == 10) return v.specFreq11;
    if (p == 11) return v.specFreq12;
    if (p == 12) return v.specFreq13;
    if (p == 13) return v.specFreq14;
    if (p == 14) return v.specFreq15;
    return v.specFreq16;
}

inline void setSpecFreq(VoiceData& v, int p, double x)
{
    if (p == 0) v.specFreq1 = x;
    else if (p == 1) v.specFreq2 = x;
    else if (p == 2) v.specFreq3 = x;
    else if (p == 3) v.specFreq4 = x;
    else if (p == 4) v.specFreq5 = x;
    else if (p == 5) v.specFreq6 = x;
    else if (p == 6) v.specFreq7 = x;
    else if (p == 7) v.specFreq8 = x;
    else if (p == 8) v.specFreq9 = x;
    else if (p == 9) v.specFreq10 = x;
    else if (p == 10) v.specFreq11 = x;
    else if (p == 11) v.specFreq12 = x;
    else if (p == 12) v.specFreq13 = x;
    else if (p == 13) v.specFreq14 = x;
    else if (p == 14) v.specFreq15 = x;
    else v.specFreq16 = x;
}

inline double monoAt(int index)
{
    int i = index;
    if (i < 0) i = 0;
    if (i > audioData.numSamples - 1) i = audioData.numSamples - 1;
    return 0.5 * ((double)sample[0][i] + (double)sample[1][i]);
}

inline double spectralBandHz(int p, double nyquist)
{
    double fLo = 45.0;
    double fHi = nyquist * 0.92;
    if (fHi < fLo * 2.0) fHi = fLo * 2.0;
    double t = ((double)p + 0.5) / (double)MAX_PARTIALS;
    return fLo * Math.pow(fHi / fLo, t);
}

inline double partialMagnitude(int start, int end, double freqHz)
{
    if (sr <= 0.0 || end <= start || freqHz <= 0.0)
        return 0.0;

    double re = 0.0;
    double im = 0.0;
    double ph = 0.0;
    double dph = 2.0 * Math.PI * freqHz / sr;
    int n = 0;

    for (int i = start; i < end; ++i)
    {
        double x = monoAt(i);
        re += x * Math.cos(ph);
        im += x * Math.sin(ph);
        ph += dph;
        n += 1;
    }

    if (n < 1)
        return 0.0;

    return (2.0 / (double)n) * Math.sqrt(re * re + im * im);
}

void analyzeSpectralData()
{
    spectralReady = (audioData.numSamples > 2);
    for (auto& voice : voiceData)
        voice.specUpdateCounter = 0;
}

bool processSpectralInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
{
    if (!spectralReady || sr <= 0.0 || audioData.numSamples <= 2)
        return false;

    int pitchState = 0;
    if (pitchMode < 0.33) pitchState = 0;
    else if (pitchMode < 0.66) pitchState = 1;
    else pitchState = 2;

    double spreadNorm = 1.0;

    double scrubTarget = clamp01(scrub);
    v.scrubQ += (scrubTarget - v.scrubQ) * 0.02;
    double scrubVal = clamp01(v.scrubQ);

    int active = (int)partials;
    if (active < 1) active = 1;
    if (active > MAX_PARTIALS) active = MAX_PARTIALS;

    if (v.specUpdateCounter <= 0)
    {
        int center = (int)(scrubVal * (double)(audioData.numSamples - 2));
        int halfWin = (int)(0.5 * analysisWindowMs * sr * 0.001);
        if (halfWin < 32) halfWin = 32;
        if (halfWin > 4096) halfWin = 4096;

        int start = center - halfWin;
        int end = center + halfWin;
        if (start < 0) start = 0;
        if (end > audioData.numSamples - 1) end = audioData.numSamples - 1;

        double sumSq = 0.0;
        double sumAbs = 0.0;
        double sumDiff = 0.0;
        int zc = 0;
        int count = 0;

        double prev = 0.0;
        bool havePrev = false;
        for (int i = start; i < end; ++i)
        {
            double x = 0.5 * ((double)sample[0][i] + (double)sample[1][i]);
            sumSq += x * x;
            sumAbs += Math.abs(x);

            if (havePrev)
            {
                sumDiff += Math.abs(x - prev);
                if ((x >= 0.0 && prev < 0.0) || (x < 0.0 && prev >= 0.0))
                    zc += 1;
            }

            prev = x;
            havePrev = true;
            count += 1;
        }

        if (count < 2) count = 2;
        double invN = 1.0 / (double)count;
        double rms = Math.sqrt(sumSq * invN);
        double zcr = (double)zc * invN;
        double diffNorm = sumDiff / (sumAbs + 1.0e-9);
        double centroid = clamp01(0.65 * diffNorm + 0.35 * zcr * 8.0);

        v.specEnergy = clamp01(rms * 3.5);
        v.specBrightness = centroid;

        // Normalized autocorrelation F0 estimator with confidence gating.
        int minLag = (int)(sr / 900.0);
        int maxLag = (int)(sr / 45.0);
        int maxUseful = end - start - 2;
        if (minLag < 2) minLag = 2;
        if (maxLag > maxUseful) maxLag = maxUseful;
        if (maxLag < minLag) maxLag = minLag;

        double bestCorr = -1.0;
        int bestLag = minLag;
        for (int lag = minLag; lag <= maxLag; ++lag)
        {
            double num = 0.0;
            double denA = 0.0;
            double denB = 0.0;
            for (int i = start; i < end - lag; ++i)
            {
                double a = monoAt(i);
                double b = monoAt(i + lag);
                num += a * b;
                denA += a * a;
                denB += b * b;
            }

            double corr = 0.0;
            double den = Math.sqrt(denA * denB + 1.0e-9);
            if (den > 0.0)
                corr = num / den;

            if (corr > bestCorr)
            {
                bestCorr = corr;
                bestLag = lag;
            }
        }

        // Basic octave-error guard: if 2x lag has close correlation, prefer lower F0.
        int lag2 = bestLag * 2;
        if (lag2 <= maxLag)
        {
            double num2 = 0.0;
            double denA2 = 0.0;
            double denB2 = 0.0;
            for (int i = start; i < end - lag2; ++i)
            {
                double a2 = monoAt(i);
                double b2 = monoAt(i + lag2);
                num2 += a2 * b2;
                denA2 += a2 * a2;
                denB2 += b2 * b2;
            }
            double corr2 = 0.0;
            double den2 = Math.sqrt(denA2 * denB2 + 1.0e-9);
            if (den2 > 0.0) corr2 = num2 / den2;
            if (corr2 > bestCorr * 0.90)
                bestLag = lag2;
        }

        double detectedF0 = sr / (double)bestLag;
        if (detectedF0 < 50.0) detectedF0 = 50.0;
        if (detectedF0 > 800.0) detectedF0 = 800.0;

        double corrConf = clamp01((bestCorr - 0.18) * 2.3);
        double energyConf = clamp01((rms - 0.01) * 24.0);
        double conf = corrConf * energyConf;
        v.specF0Conf += (conf - v.specF0Conf) * 0.22;

        if (v.specF0Conf > 0.12)
        {
            double follow = 0.08 + 0.40 * v.specF0Conf;
            v.specBaseHz += (detectedF0 - v.specBaseHz) * follow;
        }

        double nyquistLocal = 0.5 * sr * 0.92;
        double maxMag = 1.0e-9;

        for (int p = 0; p < MAX_PARTIALS; ++p)
        {
            double harm = (double)(p + 1);
            double bandHz = spectralBandHz(p, nyquistLocal);
            double harmHz = v.specBaseHz * harm;
            if (harmHz > nyquistLocal) harmHz = nyquistLocal;
            double tonalBlend = 0.20 + 0.80 * clamp01(harmonicity);
            tonalBlend = tonalBlend * (0.70 + 0.30 * v.specF0Conf);
            double expectedHz = bandHz + (harmHz - bandHz) * tonalBlend;
            double prevHz = getSpecFreq(v, p);
            if (prevHz > 0.0)
                expectedHz = expectedHz * 0.65 + prevHz * 0.35;

            double bestHz = expectedHz;
            double bestMag = 0.0;
            const double f1 = 0.88;
            const double f2 = 0.94;
            const double f3 = 1.00;
            const double f4 = 1.06;
            const double f5 = 1.12;
            double candHz = expectedHz * f1;
            if (candHz < 20.0) candHz = 20.0;
            if (candHz > nyquistLocal) candHz = nyquistLocal;
            double mag = partialMagnitude(start, end, candHz);
            if (mag > bestMag) { bestMag = mag; bestHz = candHz; }

            candHz = expectedHz * f2;
            if (candHz < 20.0) candHz = 20.0;
            if (candHz > nyquistLocal) candHz = nyquistLocal;
            mag = partialMagnitude(start, end, candHz);
            if (mag > bestMag) { bestMag = mag; bestHz = candHz; }

            candHz = expectedHz * f3;
            if (candHz < 20.0) candHz = 20.0;
            if (candHz > nyquistLocal) candHz = nyquistLocal;
            mag = partialMagnitude(start, end, candHz);
            if (mag > bestMag) { bestMag = mag; bestHz = candHz; }

            candHz = expectedHz * f4;
            if (candHz < 20.0) candHz = 20.0;
            if (candHz > nyquistLocal) candHz = nyquistLocal;
            mag = partialMagnitude(start, end, candHz);
            if (mag > bestMag) { bestMag = mag; bestHz = candHz; }

            candHz = expectedHz * f5;
            if (candHz < 20.0) candHz = 20.0;
            if (candHz > nyquistLocal) candHz = nyquistLocal;
            mag = partialMagnitude(start, end, candHz);
            if (mag > bestMag) { bestMag = mag; bestHz = candHz; }

            double track = getSpecFreq(v, p);
            if (track < 20.0) track = bestHz;
            track += (bestHz - track) * 0.22;
            setSpecFreq(v, p, track);

            mag = bestMag;
            if (mag > maxMag) maxMag = mag;
        }

        for (int p = 0; p < MAX_PARTIALS; ++p)
        {
            double harm = (double)(p + 1);
            double bandHz = spectralBandHz(p, nyquistLocal);
            double harmHz = v.specBaseHz * harm;
            if (harmHz > nyquistLocal) harmHz = nyquistLocal;
            double trackHz = getSpecFreq(v, p);
            if (trackHz < 20.0) trackHz = bandHz;
            if (trackHz > nyquistLocal) trackHz = nyquistLocal;
            double mag = partialMagnitude(start, end, trackHz);

            double comp = 0.55 + 0.40 * Math.sqrt(trackHz / 5000.0);
            if (comp < 0.55) comp = 0.55;
            if (comp > 1.10) comp = 1.10;

            double rank = (double)p / (double)(MAX_PARTIALS - 1);
            double magNorm = mag / maxMag;
            double noiseFloor = (0.015 + 0.05 * v.specBrightness) * (1.0 - 0.70 * rank);
            double targetAmp = (magNorm * comp + noiseFloor) * (0.20 + 1.20 * v.specEnergy);
            double prevAmp = getSpecAmp(v, p);
            double smooth = prevAmp + (targetAmp - prevAmp) * 0.16;
            setSpecAmp(v, p, smooth);
        }

        int upd = halfWin / 48;
        if (upd < 12) upd = 12;
        if (upd > 96) upd = 96;
        v.specUpdateCounter = upd;
    }
    else
    {
        v.specUpdateCounter -= 1;
    }

    double dir = 1.0;
    v.speedPhase += (1.0 / sr) * dir;
    if (v.speedPhase > 1.0e6 || v.speedPhase < -1.0e6)
        v.speedPhase = 0.0;

    double center = (double)(active - 1) * 0.5;
    double invDenom = (active > 1) ? 1.0 / (double)(active - 1) : 0.0;

    double Lsum = 0.0;
    double Rsum = 0.0;
    double nyquist = 0.5 * sr * 0.98;
    double pi = 3.14159265358979323846;
    double twoPi = 6.28318530717958647692;

    for (int p = 0; p < active; ++p)
    {
        double harm = (double)(p + 1);
        double bandHz = spectralBandHz(p, nyquist);

        double amp = getSpecAmp(v, p);

        amp *= (0.55 + 0.70 * v.specEnergy);

        double pitchMul = getPitchModeMul(pitchState, spreadNorm, harm * 0.31, harm);
        double harmHz = v.specBaseHz * harm;
        if (harmHz > nyquist) harmHz = nyquist;
        double trackedHz = getSpecFreq(v, p);
        if (trackedHz < 20.0) trackedHz = bandHz;
        if (trackedHz > nyquist) trackedHz = nyquist;
        double tonalBlend = 0.25 + 0.75 * clamp01(harmonicity);
        tonalBlend = tonalBlend * (0.65 + 0.35 * v.specF0Conf);
        double baseHz = trackedHz + (harmHz - trackedHz) * tonalBlend;
        double fHz = baseHz * pitchMul * v.delta;
        if (fHz < 10.0) fHz = 10.0;
        if (fHz > nyquist) fHz = nyquist;

        // Harmonic-target stabilisation (less warbly than semitone quantisation).
        double targetHz = harmHz * pitchMul * v.delta;
        if (targetHz < 10.0) targetHz = 10.0;
        if (targetHz > nyquist) targetHz = nyquist;
        double lock = clamp01(freqLock) * (0.50 + 0.50 * v.specF0Conf);
        fHz = fHz + (targetHz - fHz) * lock;

        double ph = getSpecPhase(v, p);
        ph += dir * (twoPi * fHz / sr);
        if (ph > pi) ph -= twoPi;
        if ((ph + pi) < 0.0) ph += twoPi;
        setSpecPhase(v, p, ph);

        double s = Math.sin(ph) * amp;

        double normPan = ((double)p - center) * invDenom;
        double pan = panSpread * normPan * 2.0;

        Lsum += s * (0.5 * (1.0 - pan));
        Rsum += s * (0.5 * (1.0 + pan));
    }

    int srcIndex = (int)(scrubVal * (double)(audioData.numSamples - 2));
    // Explicit noise bed (decorrelated L/R) for unvoiced character.
    double srcNoiseA = monoAt(srcIndex + 317) - monoAt(srcIndex + 293);
    double srcNoiseB = monoAt(srcIndex - 271) - monoAt(srcIndex - 239);
    double dry = monoAt(srcIndex);
    double dryPrev = monoAt(srcIndex - 1);
    double dryHP = dry - dryPrev;
    // Non-tonal decorrelated pseudo-random stream per voice.
    v.noiseStateL = wrap01(v.noiseStateL * 1.61803398875 + 0.1379);
    v.noiseStateR = wrap01(v.noiseStateR * 1.41421356237 + 0.0917);
    double wnL = 2.0 * v.noiseStateL - 1.0;
    double wnR = 2.0 * v.noiseStateR - 1.0;
    double noiseBodyL = 0.46 * srcNoiseA + 0.14 * dryHP + 0.40 * wnL;
    double noiseBodyR = 0.46 * srcNoiseB + 0.14 * dryHP + 0.40 * wnR;
    double noiseTone = 0.35 + 0.85 * v.specBrightness;
    double noiseGain = (0.30 + 0.90 * v.specEnergy) * noiseTone;
    double nL = noiseBodyL * noiseGain;
    double nR = noiseBodyR * noiseGain;
    // Keep pitch influence in noise-only operation by shaping with the
    // current fundamental partial phase (tracks pitchSemitones / MIDI pitch).
    double ph0 = getSpecPhase(v, 0);
    double pitchEnv = 0.5 + 0.5 * Math.sin(ph0);
    double pitchShape = 0.35 + 0.65 * pitchEnv;
    nL *= pitchShape;
    nR *= pitchShape;

    double sineL = Lsum;
    double sineR = Rsum;
    double mix = clamp01(noiseSineMix); // 0=noise, 1=sine
    Lsum = nL * (1.0 - mix) + sineL * mix;
    Rsum = nR * (1.0 - mix) + sineR * mix;

    double gain = 0.24;
    if (active > 1)
        gain *= 1.0 / Math.sqrt((double)active);

    fd[0] += (float)(Lsum * gain);
    fd[1] += (float)(Rsum * gain);

    v.scanPos = scrubVal;
    return true;
}



    // -----------------------------------------------------
    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
   
	
{
    // Dedicated spectral engine path.
    processSpectralInternal(fd, v);
    return;

	double maxStart = (double)audioData.numSamples - grainSize - 2.0;
	if (maxStart <= 0.0)
	    maxStart = 0.0;

    double scrubSmoothed = scrub;
    
// ----------------------------
// SCRUB MODE
// 0 = normal
// 1 = multi-scrub
// 2 = spectral
// 3 = multi-scrub (fallback)
// ----------------------------

int scrubState = getScrubState();

v.scrubQ = scrub;

// Spectral mode is isolated to scrubMode slot 2.
if (scrubState == 2)
{
    if (processSpectralInternal(fd, v))
        return;
}

	double scrubBase = scrubSmoothed * maxStart;



int pitchState = 0;

// 0 = detune (track MIDI)
// 1 = harmonic (track MIDI)
// 2 = tempo-sync lock (track MIDI + semitone, sync ratio from pitchSpread)

if (pitchMode < 0.33)
    pitchState = 0;
else if (pitchMode < 0.66)
    pitchState = 1;
else
    pitchState = 2;
 
      // scrub
      
      
      
//---------------------------------------------------------
// CLEAN SCRUB SYSTEM (NO SLIDERPACK)
// Mode 0 = normal
// Mode 1 = multi-scrub (scrub/B/C/D)
//---------------------------------------------------------

// ---- values (paired grains) ----
double scrubVal1 = scrubSmoothed;
double scrubVal2 = scrubSmoothed;

double scrubVal3 = scrubB;
double scrubVal4 = scrubB;

double scrubVal5 = scrubC;
double scrubVal6 = scrubC;

double scrubVal7 = scrubD;
double scrubVal8 = scrubD;
double scrubVal9  = scrub;
double scrubVal10 = scrub;
double scrubVal11 = scrubB;
double scrubVal12 = scrubB;
double scrubVal13 = scrubC;
double scrubVal14 = scrubC;
double scrubVal15 = scrubD;
double scrubVal16 = scrubD;

// ---- quantise only in normal + multi-scrub ----
if (scrubState == 0 || scrubState == 1)
{
    scrubVal1 = quantiseScrub(scrubVal1, audioData);
    scrubVal2 = scrubVal1;

    scrubVal3 = quantiseScrub(scrubVal3, audioData);
    scrubVal4 = scrubVal3;

    scrubVal5 = quantiseScrub(scrubVal5, audioData);
    scrubVal6 = scrubVal5;

    scrubVal7 = quantiseScrub(scrubVal7, audioData);
    scrubVal8 = scrubVal7;
    scrubVal9 = quantiseScrub(scrubVal9, audioData);
    scrubVal10 = scrubVal9;
    scrubVal11 = quantiseScrub(scrubVal11, audioData);
    scrubVal12 = scrubVal11;
    scrubVal13 = quantiseScrub(scrubVal13, audioData);
    scrubVal14 = scrubVal13;
    scrubVal15 = quantiseScrub(scrubVal15, audioData);
    scrubVal16 = scrubVal15;
}

// ---- wrap 0..1 ----
if (scrubVal1 < 0.0) scrubVal1 += 1.0; if (scrubVal1 > 1.0) scrubVal1 -= 1.0;
if (scrubVal2 < 0.0) scrubVal2 += 1.0; if (scrubVal2 > 1.0) scrubVal2 -= 1.0;

if (scrubVal3 < 0.0) scrubVal3 += 1.0; if (scrubVal3 > 1.0) scrubVal3 -= 1.0;
if (scrubVal4 < 0.0) scrubVal4 += 1.0; if (scrubVal4 > 1.0) scrubVal4 -= 1.0;

if (scrubVal5 < 0.0) scrubVal5 += 1.0; if (scrubVal5 > 1.0) scrubVal5 -= 1.0;
if (scrubVal6 < 0.0) scrubVal6 += 1.0; if (scrubVal6 > 1.0) scrubVal6 -= 1.0;

if (scrubVal7 < 0.0) scrubVal7 += 1.0; if (scrubVal7 > 1.0) scrubVal7 -= 1.0;
if (scrubVal8 < 0.0) scrubVal8 += 1.0; if (scrubVal8 > 1.0) scrubVal8 -= 1.0;
if (scrubVal9 < 0.0) scrubVal9 += 1.0; if (scrubVal9 > 1.0) scrubVal9 -= 1.0;
if (scrubVal10 < 0.0) scrubVal10 += 1.0; if (scrubVal10 > 1.0) scrubVal10 -= 1.0;
if (scrubVal11 < 0.0) scrubVal11 += 1.0; if (scrubVal11 > 1.0) scrubVal11 -= 1.0;
if (scrubVal12 < 0.0) scrubVal12 += 1.0; if (scrubVal12 > 1.0) scrubVal12 -= 1.0;
if (scrubVal13 < 0.0) scrubVal13 += 1.0; if (scrubVal13 > 1.0) scrubVal13 -= 1.0;
if (scrubVal14 < 0.0) scrubVal14 += 1.0; if (scrubVal14 > 1.0) scrubVal14 -= 1.0;
if (scrubVal15 < 0.0) scrubVal15 += 1.0; if (scrubVal15 > 1.0) scrubVal15 -= 1.0;
if (scrubVal16 < 0.0) scrubVal16 += 1.0; if (scrubVal16 > 1.0) scrubVal16 -= 1.0;

// --------------------------------------
// base positions (each declared safely)
// --------------------------------------
double basePos1 = 0.0;
double basePos2 = 0.0;
double basePos3 = 0.0;
double basePos4 = 0.0;
double basePos5 = 0.0;
double basePos6 = 0.0;
double basePos7 = 0.0;
double basePos8 = 0.0;
double basePos9 = 0.0;
double basePos10 = 0.0;
double basePos11 = 0.0;
double basePos12 = 0.0;
double basePos13 = 0.0;
double basePos14 = 0.0;
double basePos15 = 0.0;
double basePos16 = 0.0;

// MULTI-SCRUB MODE (NO SLIDERPACK)
if (scrubState == 1)
{
    basePos1 = scrubVal1 * maxStart;
    basePos2 = scrubVal2 * maxStart;

    basePos3 = scrubVal3 * maxStart;
    basePos4 = scrubVal4 * maxStart;

    basePos5 = scrubVal5 * maxStart;
    basePos6 = scrubVal6 * maxStart;

    basePos7 = scrubVal7 * maxStart;
    basePos8 = scrubVal8 * maxStart;
    basePos9 = scrubVal9 * maxStart;
    basePos10 = scrubVal10 * maxStart;
    basePos11 = scrubVal11 * maxStart;
    basePos12 = scrubVal12 * maxStart;
    basePos13 = scrubVal13 * maxStart;
    basePos14 = scrubVal14 * maxStart;
    basePos15 = scrubVal15 * maxStart;
    basePos16 = scrubVal16 * maxStart;
}
// NORMAL MODE
else
{
    basePos1 = scrubBase;
    basePos2 = scrubBase;
    basePos3 = scrubBase;
    basePos4 = scrubBase;
    basePos5 = scrubBase;
    basePos6 = scrubBase;
    basePos7 = scrubBase;
    basePos8 = scrubBase;
    basePos9 = scrubBase;
    basePos10 = scrubBase;
    basePos11 = scrubBase;
    basePos12 = scrubBase;
    basePos13 = scrubBase;
    basePos14 = scrubBase;
    basePos15 = scrubBase;
    basePos16 = scrubBase;
}
// --- integer density ---
int g = (int)maxGrains;
if (g < 1) g = 1;
if (g > MAX_GRAINS) g = MAX_GRAINS;
bool isStackMode = (scrubBlend < 0.5);

// =========================================================
// 16-GRAIN NORMALISATION  (APPLY BEFORE MIXING)
// =========================================================

// Compute all raw weights now
// ===============================================
// SNEX-SAFE 16-GRAIN NORMALISATION
// ===============================================

// Raw, unnormalised weights
double w_raw1  = getGrainWeight(0,  g, isStackMode);
double w_raw2  = getGrainWeight(1,  g, isStackMode);
double w_raw3  = getGrainWeight(2,  g, isStackMode);
double w_raw4  = getGrainWeight(3,  g, isStackMode);
double w_raw5  = getGrainWeight(4,  g, isStackMode);
double w_raw6  = getGrainWeight(5,  g, isStackMode);
double w_raw7  = getGrainWeight(6,  g, isStackMode);
double w_raw8  = getGrainWeight(7,  g, isStackMode);
double w_raw9  = getGrainWeight(8,  g, isStackMode);
double w_raw10 = getGrainWeight(9,  g, isStackMode);
double w_raw11 = getGrainWeight(10, g, isStackMode);
double w_raw12 = getGrainWeight(11, g, isStackMode);
double w_raw13 = getGrainWeight(12, g, isStackMode);
double w_raw14 = getGrainWeight(13, g, isStackMode);
double w_raw15 = getGrainWeight(14, g, isStackMode);
double w_raw16 = getGrainWeight(15, g, isStackMode);

// -----------------------------------------------
// CONSTANT-POWER GRAIN NORMALISATION (16 grains)
// -----------------------------------------------

// Sum of squared weights
double sumsq =
    w_raw1*w_raw1 + w_raw2*w_raw2 + w_raw3*w_raw3 + w_raw4*w_raw4 +
    w_raw5*w_raw5 + w_raw6*w_raw6 + w_raw7*w_raw7 + w_raw8*w_raw8 +
    w_raw9*w_raw9 + w_raw10*w_raw10 + w_raw11*w_raw11 + w_raw12*w_raw12 +
    w_raw13*w_raw13 + w_raw14*w_raw14 + w_raw15*w_raw15 + w_raw16*w_raw16;

// Normalisation factor (protect against zero)
double wnorm = 1.0;
if (isStackMode)
    wnorm = (sumsq > 0.0 ? 1.0 / Math.sqrt(sumsq) : 1.0);

// Final normalised weights
double weight1  = w_raw1  * wnorm;
double weight2  = w_raw2  * wnorm;
double weight3  = w_raw3  * wnorm;
double weight4  = w_raw4  * wnorm;
double weight5  = w_raw5  * wnorm;
double weight6  = w_raw6  * wnorm;
double weight7  = w_raw7  * wnorm;
double weight8  = w_raw8  * wnorm;
double weight9  = w_raw9  * wnorm;
double weight10 = w_raw10 * wnorm;
double weight11 = w_raw11 * wnorm;
double weight12 = w_raw12 * wnorm;
double weight13 = w_raw13 * wnorm;
double weight14 = w_raw14 * wnorm;
double weight15 = w_raw15 * wnorm;
double weight16 = w_raw16 * wnorm;

          
		double center = (double)(g - 1) * 0.5;
       double invDenom = (g > 1) ? 1.0 / (double)(g - 1) : 0.0;
       

if (scrubState == 1)
{
    // Multi-scrub mode (no sliderpack)
    basePos1 = scrub  * maxStart;
    basePos2 = scrub  * maxStart;

    basePos3 = scrubB * maxStart;
    basePos4 = scrubB * maxStart;

    basePos5 = scrubC * maxStart;
    basePos6 = scrubC * maxStart;

    basePos7 = scrubD * maxStart;
    basePos8 = scrubD * maxStart;
    basePos9  = scrub  * maxStart;
    basePos10 = scrub  * maxStart;
    basePos11 = scrubB * maxStart;
    basePos12 = scrubB * maxStart;
    basePos13 = scrubC * maxStart;
    basePos14 = scrubC * maxStart;
    basePos15 = scrubD * maxStart;
    basePos16 = scrubD * maxStart;
}
else
{
    // Normal mode
    basePos1 = scrubBase;
    basePos2 = scrubBase;
    basePos3 = scrubBase;
    basePos4 = scrubBase;
    basePos5 = scrubBase;
    basePos6 = scrubBase;
    basePos7 = scrubBase;
    basePos8 = scrubBase;
    basePos9 = scrubBase;
    basePos10 = scrubBase;
    basePos11 = scrubBase;
    basePos12 = scrubBase;
    basePos13 = scrubBase;
    basePos14 = scrubBase;
    basePos15 = scrubBase;
    basePos16 = scrubBase;
}


// -----------------------------------------------------
// A2 START POSITION SPREAD (Soft Cluster)
// -----------------------------------------------------
if (scrubBlend < 0.5)   // only stack mode
{
    double d = clamp01(density);

    double denom = (g > 1 ? (double)(g - 1) : 1.0);

    double iNorm0  = 0.0          / denom;
    double iNorm1  = 1.0          / denom;
    double iNorm2  = 2.0          / denom;
    double iNorm3  = 3.0          / denom;
    double iNorm4  = 4.0          / denom;
    double iNorm5  = 5.0          / denom;
    double iNorm6  = 6.0          / denom;
    double iNorm7  = 7.0          / denom;
    double iNorm8  = 8.0          / denom;
    double iNorm9  = 9.0          / denom;
    double iNorm10 = 10.0         / denom;
    double iNorm11 = 11.0         / denom;
    double iNorm12 = 12.0         / denom;
    double iNorm13 = 13.0         / denom;
    double iNorm14 = 14.0         / denom;
    double iNorm15 = 15.0         / denom;

    double o0  = A2curve(iNorm0);
    double o1  = A2curve(iNorm1);
    double o2  = A2curve(iNorm2);
    double o3  = A2curve(iNorm3);
    double o4  = A2curve(iNorm4);
    double o5  = A2curve(iNorm5);
    double o6  = A2curve(iNorm6);
    double o7  = A2curve(iNorm7);
    double o8  = A2curve(iNorm8);
    double o9  = A2curve(iNorm9);
    double o10 = A2curve(iNorm10);
    double o11 = A2curve(iNorm11);
    double o12 = A2curve(iNorm12);
    double o13 = A2curve(iNorm13);
    double o14 = A2curve(iNorm14);
    double o15 = A2curve(iNorm15);

    double amt = maxStart * densityPositionSpreadRange * d;
    basePos1  += o0  * amt;
    basePos2  += o1  * amt;
    basePos3  += o2  * amt;
    basePos4  += o3  * amt;
    basePos5  += o4  * amt;
    basePos6  += o5  * amt;
    basePos7  += o6  * amt;
    basePos8  += o7  * amt;
    basePos9  += o8  * amt;
    basePos10 += o9  * amt;
    basePos11 += o10 * amt;
    basePos12 += o11 * amt;
    basePos13 += o12 * amt;
    basePos14 += o13 * amt;
    basePos15 += o14 * amt;
    basePos16 += o15 * amt;
}
// (Spray mode removed)


// --- Morph calculation (shared by all grains) ---
int baseIndex = 0;
double frac = 0.0;

if (scrubMode > 0.5 && scrubBlend > 0.5)
{
    double pos = density * (double)(g - 1);

    if (pos < 0.0) pos = 0.0;
    if (pos > (double)(g - 1)) pos = (double)(g - 1);

    baseIndex = (int)Math.floor(pos);
    frac = pos - (double)baseIndex;
}

double spreadNorm = isStackMode ? 1.0 : density;


double Lsum = 0.0;
double Rsum = 0.0;

double dir = (reverse > 0.5) ? -1.0 : 1.0;
bool lockStartOnWrap = true;

// ============================
// GRAIN 1 (Hybrid Mode C)
// ============================

weight1  = w_raw1  * wnorm;

// Selected scrub source
double s1 = (scrubState == 1 ? scrubVal1 : scrubSmoothed);

// Final base position (density-spread applied above)
double base1 = basePos1;

if (!v.schedActive)
{
    v.schedActive = true;
    v.schedPhase = 0.0;
    v.schedStart = base1;
}

// pitch multiplier (Hybrid keeps your detune seed 0.77)
double grainPitchMul1 = getPitchModeMul(pitchState, spreadNorm, 0.77, 1.0);

double phaseInc1 = v.delta * grainPitchMul1 * dir;

// advance phase
v.schedPhase += phaseInc1;

// wrap handling
if (v.schedPhase >= grainSize)
{
    v.schedPhase -= grainSize;
    if (lockStartOnWrap)
        v.schedStart = base1;
}
if (v.schedPhase < 0.0)
{
    v.schedPhase += grainSize;
    if (lockStartOnWrap)
        v.schedStart = base1;
}

// absolute playback position
double pos1 = v.schedStart + v.schedPhase;

// bounds check
if (pos1 < 0.0) pos1 = 0.0;
if (pos1 >= audioData.numSamples - 1.0)
    pos1 = audioData.numSamples - 2.0;

int i1 = (int)pos1;
double f1 = pos1 - (double)i1;

// window
double w1 = morphedWindow(
    cloudWindowPhase(v.schedPhase / grainSize, 0)
);

// sample fetch
double monoL1 = (1.0 - f1) * sample[0][i1] + f1 * sample[0][i1 + 1];
double monoR1 = (1.0 - f1) * sample[1][i1] + f1 * sample[1][i1 + 1];

// panning
double normPan1 = ((0.0 - center) * invDenom);
double pan1 = panSpread * normPan1 * 2.0;

// pan into mix
Lsum += monoL1 * w1 * (0.5 * (1.0 - pan1)) * weight1;
Rsum += monoR1 * w1 * (0.5 * (1.0 + pan1)) * weight1;

weight2  = w_raw2  * wnorm;
double s2 = (scrubState == 1 ? scrubVal2 : scrubSmoothed);
double base2 = basePos2;

if (!v.schedActive2)
{
    v.schedActive2 = true;
    v.schedPhase2 = 0.0;
    v.schedStart2 = base2;
}

double grainPitchMul2 = getPitchModeMul(pitchState, spreadNorm, 1.91, 2.0);
double phaseInc2 = v.delta * grainPitchMul2 * dir;

v.schedPhase2 += phaseInc2;

if (v.schedPhase2 >= grainSize)
{
    v.schedPhase2 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart2 = base2;
}
if (v.schedPhase2 < 0.0)
{
    v.schedPhase2 += grainSize;
    if (lockStartOnWrap)
        v.schedStart2 = base2;
}

double pos2 = v.schedStart2 + v.schedPhase2;
if (pos2 < 0.0) pos2 = 0.0;
if (pos2 >= audioData.numSamples - 1.0)
    pos2 = audioData.numSamples - 2.0;

int i2 = (int)pos2;
double f2 = pos2 - (double)i2;

double w2 = morphedWindow(
    cloudWindowPhase(v.schedPhase2 / grainSize, 1)
);

double monoL2 = (1.0 - f2) * sample[0][i2] + f2 * sample[0][i2 + 1];
double monoR2 = (1.0 - f2) * sample[1][i2] + f2 * sample[1][i2 + 1];

double normPan2 = ((1.0 - center) * invDenom);
double pan2 = panSpread * normPan2 * 2.0;

Lsum += monoL2 * w2 * (0.5 * (1.0 - pan2)) * weight2;
Rsum += monoR2 * w2 * (0.5 * (1.0 + pan2)) * weight2;

weight3  = w_raw3  * wnorm;
double s3 = (scrubState == 1 ? scrubVal3 : scrubSmoothed);
double base3 = basePos3;

if (!v.schedActive3)
{
    v.schedActive3 = true;
    v.schedPhase3 = 0.0;
    v.schedStart3 = base3;
}

double grainPitchMul3 = getPitchModeMul(pitchState, spreadNorm, 2.43, 3.0);
double phaseInc3 = v.delta * grainPitchMul3 * dir;

v.schedPhase3 += phaseInc3;

if (v.schedPhase3 >= grainSize)
{
    v.schedPhase3 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart3 = base3;
}
if (v.schedPhase3 < 0.0)
{
    v.schedPhase3 += grainSize;
    if (lockStartOnWrap)
        v.schedStart3 = base3;
}

double pos3 = v.schedStart3 + v.schedPhase3;
if (pos3 < 0.0) pos3 = 0.0;
if (pos3 >= audioData.numSamples - 1.0)
    pos3 = audioData.numSamples - 2.0;

int i3 = (int)pos3;
double f3 = pos3 - (double)i3;

double w3 = morphedWindow(
    cloudWindowPhase(v.schedPhase3 / grainSize, 2)
);

double monoL3 = (1.0 - f3) * sample[0][i3] + f3 * sample[0][i3 + 1];
double monoR3 = (1.0 - f3) * sample[1][i3] + f3 * sample[1][i3 + 1];

double normPan3 = ((2.0 - center) * invDenom);
double pan3 = panSpread * normPan3 * 2.0;

Lsum += monoL3 * w3 * (0.5 * (1.0 - pan3)) * weight3;
Rsum += monoR3 * w3 * (0.5 * (1.0 + pan3)) * weight3;

weight4  = w_raw4  * wnorm;
double s4 = (scrubState == 1 ? scrubVal4 : scrubSmoothed);
double base4 = basePos4;

if (!v.schedActive4)
{
    v.schedActive4 = true;
    v.schedPhase4 = 0.0;
    v.schedStart4 = base4;
}

double grainPitchMul4 = getPitchModeMul(pitchState, spreadNorm, 3.17, 4.0);
double phaseInc4 = v.delta * grainPitchMul4 * dir;

v.schedPhase4 += phaseInc4;

if (v.schedPhase4 >= grainSize)
{
    v.schedPhase4 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart4 = base4;
}
if (v.schedPhase4 < 0.0)
{
    v.schedPhase4 += grainSize;
    if (lockStartOnWrap)
        v.schedStart4 = base4;
}

double pos4 = v.schedStart4 + v.schedPhase4;
if (pos4 < 0.0) pos4 = 0.0;
if (pos4 >= audioData.numSamples - 1.0)
    pos4 = audioData.numSamples - 2.0;

int i4 = (int)pos4;
double f4 = pos4 - (double)i4;

double w4 = morphedWindow(
    cloudWindowPhase(v.schedPhase4 / grainSize, 3)
);

double monoL4 = (1.0 - f4) * sample[0][i4] + f4 * sample[0][i4 + 1];
double monoR4 = (1.0 - f4) * sample[1][i4] + f4 * sample[1][i4 + 1];

double normPan4 = ((3.0 - center) * invDenom);
double pan4 = panSpread * normPan4 * 2.0;

Lsum += monoL4 * w4 * (0.5 * (1.0 - pan4)) * weight4;
Rsum += monoR4 * w4 * (0.5 * (1.0 + pan4)) * weight4;

weight5  = w_raw5  * wnorm;
double s5 = (scrubState == 1 ? scrubVal5 : scrubSmoothed);
double base5 = basePos5;

if (!v.schedActive5)
{
    v.schedActive5 = true;
    v.schedPhase5 = 0.0;
    v.schedStart5 = base5;
}

double grainPitchMul5 = getPitchModeMul(pitchState, spreadNorm, 4.03, 5.0);
double phaseInc5 = v.delta * grainPitchMul5 * dir;

v.schedPhase5 += phaseInc5;

if (v.schedPhase5 >= grainSize)
{
    v.schedPhase5 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart5 = base5;
}
if (v.schedPhase5 < 0.0)
{
    v.schedPhase5 += grainSize;
    if (lockStartOnWrap)
        v.schedStart5 = base5;
}

double pos5 = v.schedStart5 + v.schedPhase5;
if (pos5 < 0.0) pos5 = 0.0;
if (pos5 >= audioData.numSamples - 1.0)
    pos5 = audioData.numSamples - 2.0;

int i5 = (int)pos5;
double f5 = pos5 - (double)i5;

double w5 = morphedWindow(
    cloudWindowPhase(v.schedPhase5 / grainSize, 4)
);

double monoL5 = (1.0 - f5) * sample[0][i5] + f5 * sample[0][i5 + 1];
double monoR5 = (1.0 - f5) * sample[1][i5] + f5 * sample[1][i5 + 1];

double normPan5 = ((4.0 - center) * invDenom);
double pan5 = panSpread * normPan5 * 2.0;

Lsum += monoL5 * w5 * (0.5 * (1.0 - pan5)) * weight5;
Rsum += monoR5 * w5 * (0.5 * (1.0 + pan5)) * weight5;

weight6  = w_raw6  * wnorm;
double s6 = (scrubState == 1 ? scrubVal6 : scrubSmoothed);
double base6 = basePos6;

if (!v.schedActive6)
{
    v.schedActive6 = true;
    v.schedPhase6 = 0.0;
    v.schedStart6 = base6;
}

double grainPitchMul6 = getPitchModeMul(pitchState, spreadNorm, 5.11, 6.0);
double phaseInc6 = v.delta * grainPitchMul6 * dir;

v.schedPhase6 += phaseInc6;

if (v.schedPhase6 >= grainSize)
{
    v.schedPhase6 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart6 = base6;
}
if (v.schedPhase6 < 0.0)
{
    v.schedPhase6 += grainSize;
    if (lockStartOnWrap)
        v.schedStart6 = base6;
}

double pos6 = v.schedStart6 + v.schedPhase6;
if (pos6 < 0.0) pos6 = 0.0;
if (pos6 >= audioData.numSamples - 1.0)
    pos6 = audioData.numSamples - 2.0;

int i6 = (int)pos6;
double f6 = pos6 - (double)i6;

double w6 = morphedWindow(
    cloudWindowPhase(v.schedPhase6 / grainSize, 5)
);

double monoL6 = (1.0 - f6) * sample[0][i6] + f6 * sample[0][i6 + 1];
double monoR6 = (1.0 - f6) * sample[1][i6] + f6 * sample[1][i6 + 1];

double normPan6 = ((5.0 - center) * invDenom);
double pan6 = panSpread * normPan6 * 2.0;

Lsum += monoL6 * w6 * (0.5 * (1.0 - pan6)) * weight6;
Rsum += monoR6 * w6 * (0.5 * (1.0 + pan6)) * weight6;

weight7  = w_raw7  * wnorm;
double s7 = (scrubState == 1 ? scrubVal7 : scrubSmoothed);
double base7 = basePos7;

if (!v.schedActive7)
{
    v.schedActive7 = true;
    v.schedPhase7 = 0.0;
    v.schedStart7 = base7;
}

double grainPitchMul7 = getPitchModeMul(pitchState, spreadNorm, 6.41, 7.0);
double phaseInc7 = v.delta * grainPitchMul7 * dir;

v.schedPhase7 += phaseInc7;

if (v.schedPhase7 >= grainSize)
{
    v.schedPhase7 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart7 = base7;
}
if (v.schedPhase7 < 0.0)
{
    v.schedPhase7 += grainSize;
    if (lockStartOnWrap)
        v.schedStart7 = base7;
}

double pos7 = v.schedStart7 + v.schedPhase7;
if (pos7 < 0.0) pos7 = 0.0;
if (pos7 >= audioData.numSamples - 1.0)
    pos7 = audioData.numSamples - 2.0;

int i7 = (int)pos7;
double f7 = pos7 - (double)i7;

double w7 = morphedWindow(
    cloudWindowPhase(v.schedPhase7 / grainSize, 6)
);

double monoL7 = (1.0 - f7) * sample[0][i7] + f7 * sample[0][i7 + 1];
double monoR7 = (1.0 - f7) * sample[1][i7] + f7 * sample[1][i7 + 1];

double normPan7 = ((6.0 - center) * invDenom);
double pan7 = panSpread * normPan7 * 2.0;

Lsum += monoL7 * w7 * (0.5 * (1.0 - pan7)) * weight7;
Rsum += monoR7 * w7 * (0.5 * (1.0 + pan7)) * weight7;

weight8  = w_raw8  * wnorm;
double s8 = (scrubState == 1 ? scrubVal8 : scrubSmoothed);
double base8 = basePos8;

if (!v.schedActive8)
{
    v.schedActive8 = true;
    v.schedPhase8 = 0.0;
    v.schedStart8 = base8;
}

double grainPitchMul8 = getPitchModeMul(pitchState, spreadNorm, 7.73, 8.0);
double phaseInc8 = v.delta * grainPitchMul8 * dir;

v.schedPhase8 += phaseInc8;

if (v.schedPhase8 >= grainSize)
{
    v.schedPhase8 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart8 = base8;
}
if (v.schedPhase8 < 0.0)
{
    v.schedPhase8 += grainSize;
    if (lockStartOnWrap)
        v.schedStart8 = base8;
}

double pos8 = v.schedStart8 + v.schedPhase8;
if (pos8 < 0.0) pos8 = 0.0;
if (pos8 >= audioData.numSamples - 1.0)
    pos8 = audioData.numSamples - 2.0;

int i8 = (int)pos8;
double f8 = pos8 - (double)i8;

double w8 = morphedWindow(
    cloudWindowPhase(v.schedPhase8 / grainSize, 7)
);

double monoL8 = (1.0 - f8) * sample[0][i8] + f8 * sample[0][i8 + 1];
double monoR8 = (1.0 - f8) * sample[1][i8] + f8 * sample[1][i8 + 1];

double normPan8 = ((7.0 - center) * invDenom);
double pan8 = panSpread * normPan8 * 2.0;

Lsum += monoL8 * w8 * (0.5 * (1.0 - pan8)) * weight8;
Rsum += monoR8 * w8 * (0.5 * (1.0 + pan8)) * weight8;

weight9  = w_raw9  * wnorm;
double s9 = (scrubState == 1 ? scrubVal9 : scrubSmoothed);
double base9 = basePos9;

if (!v.schedActive9)
{
    v.schedActive9 = true;
    v.schedPhase9 = 0.0;
    v.schedStart9 = base9;
}

double grainPitchMul9 = getPitchModeMul(pitchState, spreadNorm, 8.97, 9.0);
double phaseInc9 = v.delta * grainPitchMul9 * dir;

v.schedPhase9 += phaseInc9;

if (v.schedPhase9 >= grainSize)
{
    v.schedPhase9 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart9 = base9;
}
if (v.schedPhase9 < 0.0)
{
    v.schedPhase9 += grainSize;
    if (lockStartOnWrap)
        v.schedStart9 = base9;
}

double pos9 = v.schedStart9 + v.schedPhase9;
if (pos9 < 0.0) pos9 = 0.0;
if (pos9 >= audioData.numSamples - 1.0)
    pos9 = audioData.numSamples - 2.0;

int i9 = (int)pos9;
double f9 = pos9 - (double)i9;

double w9 = morphedWindow(
    cloudWindowPhase(v.schedPhase9 / grainSize, 8)
);

double monoL9 = (1.0 - f9) * sample[0][i9] + f9 * sample[0][i9 + 1];
double monoR9 = (1.0 - f9) * sample[1][i9] + f9 * sample[1][i9 + 1];

double normPan9 = ((8.0 - center) * invDenom);
double pan9 = panSpread * normPan9 * 2.0;

Lsum += monoL9 * w9 * (0.5 * (1.0 - pan9)) * weight9;
Rsum += monoR9 * w9 * (0.5 * (1.0 + pan9)) * weight9;

weight10  = w_raw10  * wnorm;
double s10 = (scrubState == 1 ? scrubVal10 : scrubSmoothed);
double base10 = basePos10;

if (!v.schedActive10)
{
    v.schedActive10 = true;
    v.schedPhase10 = 0.0;
    v.schedStart10 = base10;
}

double grainPitchMul10 = getPitchModeMul(pitchState, spreadNorm, 9.31, 10.0);
double phaseInc10 = v.delta * grainPitchMul10 * dir;

v.schedPhase10 += phaseInc10;

if (v.schedPhase10 >= grainSize)
{
    v.schedPhase10 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart10 = base10;
}
if (v.schedPhase10 < 0.0)
{
    v.schedPhase10 += grainSize;
    if (lockStartOnWrap)
        v.schedStart10 = base10;
}

double pos10 = v.schedStart10 + v.schedPhase10;
if (pos10 < 0.0) pos10 = 0.0;
if (pos10 >= audioData.numSamples - 1.0)
    pos10 = audioData.numSamples - 2.0;

int i10 = (int)pos10;
double f10 = pos10 - (double)i10;

double w10 = morphedWindow(
    cloudWindowPhase(v.schedPhase10 / grainSize, 9)
);

double monoL10 = (1.0 - f10) * sample[0][i10] + f10 * sample[0][i10 + 1];
double monoR10 = (1.0 - f10) * sample[1][i10] + f10 * sample[1][i10 + 1];

double normPan10 = ((9.0 - center) * invDenom);
double pan10 = panSpread * normPan10 * 2.0;

Lsum += monoL10 * w10 * (0.5 * (1.0 - pan10)) * weight10;
Rsum += monoR10 * w10 * (0.5 * (1.0 + pan10)) * weight10;

weight11  = w_raw11  * wnorm;
double s11 = (scrubState == 1 ? scrubVal11 : scrubSmoothed);
double base11 = basePos11;

if (!v.schedActive11)
{
    v.schedActive11 = true;
    v.schedPhase11 = 0.0;
    v.schedStart11 = base11;
}

double grainPitchMul11 = getPitchModeMul(pitchState, spreadNorm, 10.62, 11.0);
double phaseInc11 = v.delta * grainPitchMul11 * dir;

v.schedPhase11 += phaseInc11;

if (v.schedPhase11 >= grainSize)
{
    v.schedPhase11 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart11 = base11;
}
if (v.schedPhase11 < 0.0)
{
    v.schedPhase11 += grainSize;
    if (lockStartOnWrap)
        v.schedStart11 = base11;
}

double pos11 = v.schedStart11 + v.schedPhase11;
if (pos11 < 0.0) pos11 = 0.0;
if (pos11 >= audioData.numSamples - 1.0)
    pos11 = audioData.numSamples - 2.0;

int i11 = (int)pos11;
double f11 = pos11 - (double)i11;

double w11 = morphedWindow(
    cloudWindowPhase(v.schedPhase11 / grainSize, 10)
);

double monoL11 = (1.0 - f11) * sample[0][i11] + f11 * sample[0][i11 + 1];
double monoR11 = (1.0 - f11) * sample[1][i11] + f11 * sample[1][i11 + 1];

double normPan11 = ((10.0 - center) * invDenom);
double pan11 = panSpread * normPan11 * 2.0;

Lsum += monoL11 * w11 * (0.5 * (1.0 - pan11)) * weight11;
Rsum += monoR11 * w11 * (0.5 * (1.0 + pan11)) * weight11;

weight12  = w_raw12  * wnorm;
double s12 = (scrubState == 1 ? scrubVal12 : scrubSmoothed);
double base12 = basePos12;

if (!v.schedActive12)
{
    v.schedActive12 = true;
    v.schedPhase12 = 0.0;
    v.schedStart12 = base12;
}

double grainPitchMul12 = getPitchModeMul(pitchState, spreadNorm, 11.91, 12.0);
double phaseInc12 = v.delta * grainPitchMul12 * dir;

v.schedPhase12 += phaseInc12;

if (v.schedPhase12 >= grainSize)
{
    v.schedPhase12 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart12 = base12;
}
if (v.schedPhase12 < 0.0)
{
    v.schedPhase12 += grainSize;
    if (lockStartOnWrap)
        v.schedStart12 = base12;
}

double pos12 = v.schedStart12 + v.schedPhase12;
if (pos12 < 0.0) pos12 = 0.0;
if (pos12 >= audioData.numSamples - 1.0)
    pos12 = audioData.numSamples - 2.0;

int i12 = (int)pos12;
double f12 = pos12 - (double)i12;

double w12 = morphedWindow(
    cloudWindowPhase(v.schedPhase12 / grainSize, 11)
);

double monoL12 = (1.0 - f12) * sample[0][i12] + f12 * sample[0][i12 + 1];
double monoR12 = (1.0 - f12) * sample[1][i12] + f12 * sample[1][i12 + 1];

double normPan12 = ((11.0 - center) * invDenom);
double pan12 = panSpread * normPan12 * 2.0;

Lsum += monoL12 * w12 * (0.5 * (1.0 - pan12)) * weight12;
Rsum += monoR12 * w12 * (0.5 * (1.0 + pan12)) * weight12;

weight13  = w_raw13  * wnorm;
double s13 = (scrubState == 1 ? scrubVal13 : scrubSmoothed);
double base13 = basePos13;

if (!v.schedActive13)
{
    v.schedActive13 = true;
    v.schedPhase13 = 0.0;
    v.schedStart13 = base13;
}

double grainPitchMul13 = getPitchModeMul(pitchState, spreadNorm, 12.27, 13.0);
double phaseInc13 = v.delta * grainPitchMul13 * dir;

v.schedPhase13 += phaseInc13;

if (v.schedPhase13 >= grainSize)
{
    v.schedPhase13 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart13 = base13;
}
if (v.schedPhase13 < 0.0)
{
    v.schedPhase13 += grainSize;
    if (lockStartOnWrap)
        v.schedStart13 = base13;
}

double pos13 = v.schedStart13 + v.schedPhase13;
if (pos13 < 0.0) pos13 = 0.0;
if (pos13 >= audioData.numSamples - 1.0)
    pos13 = audioData.numSamples - 2.0;

int i13 = (int)pos13;
double f13 = pos13 - (double)i13;

double w13 = morphedWindow(
    cloudWindowPhase(v.schedPhase13 / grainSize, 12)
);

double monoL13 = (1.0 - f13) * sample[0][i13] + f13 * sample[0][i13 + 1];
double monoR13 = (1.0 - f13) * sample[1][i13] + f13 * sample[1][i13 + 1];

double normPan13 = ((12.0 - center) * invDenom);
double pan13 = panSpread * normPan13 * 2.0;

Lsum += monoL13 * w13 * (0.5 * (1.0 - pan13)) * weight13;
Rsum += monoR13 * w13 * (0.5 * (1.0 + pan13)) * weight13;

weight14  = w_raw14  * wnorm;
double s14 = (scrubState == 1 ? scrubVal14 : scrubSmoothed);
double base14 = basePos14;

if (!v.schedActive14)
{
    v.schedActive14 = true;
    v.schedPhase14 = 0.0;
    v.schedStart14 = base14;
}

double grainPitchMul14 = getPitchModeMul(pitchState, spreadNorm, 13.44, 14.0);
double phaseInc14 = v.delta * grainPitchMul14 * dir;

v.schedPhase14 += phaseInc14;

if (v.schedPhase14 >= grainSize)
{
    v.schedPhase14 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart14 = base14;
}
if (v.schedPhase14 < 0.0)
{
    v.schedPhase14 += grainSize;
    if (lockStartOnWrap)
        v.schedStart14 = base14;
}

double pos14 = v.schedStart14 + v.schedPhase14;
if (pos14 < 0.0) pos14 = 0.0;
if (pos14 >= audioData.numSamples - 1.0)
    pos14 = audioData.numSamples - 2.0;

int i14 = (int)pos14;
double f14 = pos14 - (double)i14;

double w14 = morphedWindow(
    cloudWindowPhase(v.schedPhase14 / grainSize, 13)
);

double monoL14 = (1.0 - f14) * sample[0][i14] + f14 * sample[0][i14 + 1];
double monoR14 = (1.0 - f14) * sample[1][i14] + f14 * sample[1][i14 + 1];

double normPan14 = ((13.0 - center) * invDenom);
double pan14 = panSpread * normPan14 * 2.0;

Lsum += monoL14 * w14 * (0.5 * (1.0 - pan14)) * weight14;
Rsum += monoR14 * w14 * (0.5 * (1.0 + pan14)) * weight14;

weight15  = w_raw15  * wnorm;
double s15 = (scrubState == 1 ? scrubVal15 : scrubSmoothed);
double base15 = basePos15;

if (!v.schedActive15)
{
    v.schedActive15 = true;
    v.schedPhase15 = 0.0;
    v.schedStart15 = base15;
}

double grainPitchMul15 = getPitchModeMul(pitchState, spreadNorm, 14.72, 15.0);
double phaseInc15 = v.delta * grainPitchMul15 * dir;

v.schedPhase15 += phaseInc15;

if (v.schedPhase15 >= grainSize)
{
    v.schedPhase15 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart15 = base15;
}
if (v.schedPhase15 < 0.0)
{
    v.schedPhase15 += grainSize;
    if (lockStartOnWrap)
        v.schedStart15 = base15;
}

double pos15 = v.schedStart15 + v.schedPhase15;
if (pos15 < 0.0) pos15 = 0.0;
if (pos15 >= audioData.numSamples - 1.0)
    pos15 = audioData.numSamples - 2.0;

int i15 = (int)pos15;
double f15 = pos15 - (double)i15;

double w15 = morphedWindow(
    cloudWindowPhase(v.schedPhase15 / grainSize, 14)
);

double monoL15 = (1.0 - f15) * sample[0][i15] + f15 * sample[0][i15 + 1];
double monoR15 = (1.0 - f15) * sample[1][i15] + f15 * sample[1][i15 + 1];

double normPan15 = ((14.0 - center) * invDenom);
double pan15 = panSpread * normPan15 * 2.0;

Lsum += monoL15 * w15 * (0.5 * (1.0 - pan15)) * weight15;
Rsum += monoR15 * w15 * (0.5 * (1.0 + pan15)) * weight15;

weight16  = w_raw16  * wnorm;
double s16 = (scrubState == 1 ? scrubVal16 : scrubSmoothed);
double base16 = basePos16;

if (!v.schedActive16)
{
    v.schedActive16 = true;
    v.schedPhase16 = 0.0;
    v.schedStart16 = base16;
}

double grainPitchMul16 = getPitchModeMul(pitchState, spreadNorm, 15.91, 16.0);
double phaseInc16 = v.delta * grainPitchMul16 * dir;

v.schedPhase16 += phaseInc16;

if (v.schedPhase16 >= grainSize)
{
    v.schedPhase16 -= grainSize;
    if (lockStartOnWrap)
        v.schedStart16 = base16;
}
if (v.schedPhase16 < 0.0)
{
    v.schedPhase16 += grainSize;
    if (lockStartOnWrap)
        v.schedStart16 = base16;
}

double pos16 = v.schedStart16 + v.schedPhase16;
if (pos16 < 0.0) pos16 = 0.0;
if (pos16 >= audioData.numSamples - 1.0)
    pos16 = audioData.numSamples - 2.0;

int i16 = (int)pos16;
double f16 = pos16 - (double)i16;

double w16 = morphedWindow(
    cloudWindowPhase(v.schedPhase16 / grainSize, 15)
);

double monoL16 = (1.0 - f16) * sample[0][i16] + f16 * sample[0][i16 + 1];
double monoR16 = (1.0 - f16) * sample[1][i16] + f16 * sample[1][i16 + 1];

double normPan16 = ((15.0 - center) * invDenom);
double pan16 = panSpread * normPan16 * 2.0;

Lsum += monoL16 * w16 * (0.5 * (1.0 - pan16)) * weight16;
Rsum += monoR16 * w16 * (0.5 * (1.0 + pan16)) * weight16;




// ----------------------------
// RMS NORMALISATION (SAFE SNEX VERSION)
// ----------------------------

double rmsNorm = 1.0;
if (isStackMode && g > 1)
    rmsNorm = 1.0 / Math.sqrt((double)g);

Lsum *= rmsNorm;
Rsum *= rmsNorm;



// ----------------------------
// DENSITY-DRIVEN ALLPASS DIFFUSION
// Keeps brightness but smears transients / grain edges.
// ----------------------------
double diffusion = (isStackMode) ? clamp01(density) : 0.0;
if (diffusion > 0.0001)
{
    // Conservative coefficients for stability and subtle buildup.
    double a1 = 0.08 + 0.62 * diffusion;
    double a2 = 0.04 + 0.47 * diffusion;

    double yL1 = (0.0 - a1) * Lsum + v.ap1L;
    v.ap1L = Lsum + a1 * yL1;
    double yR1 = (0.0 - a1) * Rsum + v.ap1R;
    v.ap1R = Rsum + a1 * yR1;

    double yL2 = (0.0 - a2) * yL1 + v.ap2L;
    v.ap2L = yL1 + a2 * yL2;
    double yR2 = (0.0 - a2) * yR1 + v.ap2R;
    v.ap2R = yR1 + a2 * yR2;

    double wet = 0.75 * diffusion;
    double dry = 1.0 - wet;
    Lsum = Lsum * dry + yL2 * wet;
    Rsum = Rsum * dry + yR2 * wet;
}

fd[0] += (float)Lsum;
fd[1] += (float)Rsum;
}   // ← VERY IMPORTANT: close processInternal()
// -----------------------------------------------------

template<typename PD>
void process(PD& pd)
{
    if (audioData.numSamples == 0)
        return;

    DataReadLock lock(audioData);
    auto& v = voiceData.get();

    auto fd = pd.toFrameData();
    while (fd.next())
        processInternal(fd.toSpan(), v);

    audioData.setDisplayedValue(v.scanPos);
}

    void processFrame(span<float, NUM_CHANNELS>& fd)
    {
        if (audioData.numSamples == 0)
            return;

        auto& v = voiceData.get();
        processInternal(fd, v);

        audioData.setDisplayedValue(v.scanPos);
    }

    // -----------------------------------------------------
    void handleHiseEvent(HiseEvent& e)
    {
        if (e.isNoteOn())
        {
            auto& v = voiceData.get();
            v.reset();
            v.noteNumber = e.getNoteNumber();
            updateDelta(v);

            v.scrubQ = scrub;
        }
    }

    // -----------------------------------------------------
void setExternalData(const ExternalData& ed, int index)
{
    // Require external data to arrive on the correct slot.
    // If your audio file is slot 1 in Scriptnode UI,
    // that corresponds to index 0 in SNEX.
    if (index != 0)
        return;   // ignore all other slots

    // At this point, we know the data belongs to the audio file input.
    audioData = ed;

    ed.referBlockTo(sample[0], 0);
    ed.referBlockTo(sample[1], 1);

    updateGrainSize();
    analyzeSpectralData();
    reset();
}

    // -----------------------------------------------------
    template<int P>
    void setParameter(double v)
    {
        // Spectral node parameter map:
        // 0 pitch, 1 scrub, 2 panSpread, 3 pitchMode, 4 pitchSpread
        // 5 noiseSineMix, 6 harmonicity, 7 analysisWindowMs, 8 freqLock
        // 9 partials
        if (P == 0)
        {
            pitchSemitones = v;
            for (auto& voice : voiceData)
                updateDelta(voice);
        }

        if (P == 1)
        {
            if (v < 0.0) v = 0.0;
            if (v > 1.0) v = 1.0;
            scrub = v;
        }

        if (P == 2)
        {
            if (v < 0.0) v = 0.0;
            if (v > 1.0) v = 1.0;
            panSpread = v;
        }

        if (P == 3)
        {
            if (v < 0.0) v = 0.0;
            if (v > 1.0) v = 1.0;
            pitchMode = v;
            for (auto& voice : voiceData)
                updateDelta(voice);
        }

        if (P == 4)
        {
            // Keep normalized spread for modes 0/1.
            double norm = v;
            if (norm < 0.0) norm = 0.0;
            if (norm > 1.0) norm = 1.0;
            pitchSpread = norm;

            // Keep raw input for mode 2 sync lock (Hz or ms).
            pitchSyncInput = v;
        }

        if (P == 5)
        {
            if (v < 0.0) v = 0.0;
            if (v > 1.0) v = 1.0;
            noiseSineMix = v;
        }

        if (P == 6)
        {
            if (v < 0.0) v = 0.0;
            if (v > 1.0) v = 1.0;
            harmonicity = v;
        }

        if (P == 7)
        {
            if (v < 1.0) v = 1.0;
            if (v > 2000.0) v = 2000.0;
            analysisWindowMs = v;
        }

        if (P == 8)
        {
            if (v < 0.0) v = 0.0;
            if (v > 1.0) v = 1.0;
            freqLock = v;
        }

        if (P == 9)
        {
            if (v < 1.0) v = 1.0;
            if (v > (double)MAX_PARTIALS) v = (double)MAX_PARTIALS;
            partials = v;
        }
                       
    }
};
