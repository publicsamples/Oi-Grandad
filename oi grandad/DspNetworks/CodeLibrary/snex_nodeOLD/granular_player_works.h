template <int NV>
struct granular_player_stepquant_density_works
{
    SNEX_NODE(granular_player_stepquant_density_works);

    static const int NUM_CHANNELS = 2;
    static const int MAX_GRAINS   = 16;
  
    
    ExternalData audioData;
    
    ExternalData scrubData;
    span<dyn<float>, 1> scrubSpan;
    
    span<dyn<float>, NUM_CHANNELS> sample;

    double sr = 0.0;

    // Parameters
    double scrub = 0.0;       // 0..1 UI
    double grainMs = 50.0;
    double grainSize = 2048.0;

    double pitchSemitones = 0.0;
    int rootNote = 60;

    int scrubStepCount = 64;      // stepping of scrub
	double density = 1.0;   // 0..1 morph position
    double windowShape = 0.0; 
	double pitchDrift = 0.0;   // 0..1
	double retrigDrift = 0.0;   // 0..1
	double randStart = 0.0;   // 0..1
	double wander = 0.0;   // 0..1
	double microDelay = 0.0;   // 0..1
	double panSpread = 0.0; // 0..1
	double pitchSpread = 0.0;     // 0..1 amount
	double pitchMode = 0.0; 

  double stretchMs = 100.0;
  double maxGrains = 4.0;     // 1–8
  double scrubMode = 0.0;     // 0 = stack, 1 = morph
  double scrubBlend = 0.0;    // 0–1 shaping
	
    // -----------------------------------------------------
    struct VoiceData
{
    double scanPos = 0.0;
    double delta   = 1.0;
    int noteNumber = 60;

    double scrubQ = 0.0;

double schedPhase = 0.0;
double schedStart = 0.0;
bool   schedActive = false;
double schedPhase2 = 0.0;
double schedStart2 = 0.0;
bool   schedActive2 = false;
double wanderPhase = 0.0;

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

 void reset()
{
    scanPos = 0.0;
    scrubQ  = 0.0;

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

    wanderPhase = 0.0;
    
    }
};  // ← absolutely required

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

    // -----------------------------------------------------
    // HYBRID JITTER: grows with density (musical!)
    // jitter strength = ±(grainSize * jitterAmt)
    inline double jitterOffset(int gi, int g, double scrubVal)
    {
        // jitter amount scales from 0% → 20% as density goes 1→16
        double jitterAmt = (double)(g - 1) / (double)(MAX_GRAINS - 1);
        jitterAmt *= 0.35; // max ±20%

        // deterministic pseudo-random seed
        double s = (double)gi * 57.123 + scrubVal * 31.77;

        // safe deterministic 0..1 value
        double r = Math.abs(Math.sin(s)) * 0.999;

        // convert to -0.5..+0.5
        double centered = r - 0.5;

        return centered * (grainSize * jitterAmt);
    }
    
inline double getGrainWeight(int GI, int g)
{
    // STACK MODE = all grains always on
    if (scrubMode < 0.5 || scrubBlend < 0.5)
    {
        return 1.0;
    }

    // MORPH MODE (unchanged)
    double pos = density * (double)(g - 1);

    if (pos < 0.0) pos = 0.0;
    if (pos > (double)(g - 1)) pos = (double)(g - 1);

    int baseIndex = (int)Math.floor(pos);
    double frac = pos - (double)baseIndex;

    if (GI == baseIndex)
        return 1.0 - frac;
    else if (GI == baseIndex + 1)
        return frac;

    return 0.0;
}

    // -----------------------------------------------------
    void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
    

	
    {
	
	

        double maxStart = (double)audioData.numSamples - grainSize - 2.0;
        if (maxStart <= 0.0)
            return;
           
          int pitchState = 0;
          
          if (pitchMode < 0.33)
              pitchState = 0;      // detune
          else if (pitchMode < 0.66)
              pitchState = 1;      // harmonic
          else
              pitchState = 2;      // stretch
              
              double scrubBase = quantiseScrub(scrub, audioData) * maxStart;
          
          // --- TRUE GRANULAR SCAN MOVEMENT ---
if (pitchState == 2)
{
    double stretchSamples = stretchMs * sr * 0.001;

    if (stretchSamples > 1.0)
    {
        double scanSpeed = 1.0 / stretchSamples;

        v.scanPos += scanSpeed;

        if (v.scanPos >= grainSize)
            v.scanPos -= grainSize;
    }
}
        // Step quantised scrub
double scrubVal1 = scrub;
double scrubVal2 = scrub;
double scrubVal3 = scrub;
double scrubVal4 = scrub;
double scrubVal5 = scrub;
double scrubVal6 = scrub;
double scrubVal7 = scrub;
double scrubVal8 = scrub;

if (scrubMode > 0.5 && scrubData.numSamples >= 8)
{

double off1 = scrubSpan[0][0] - 0.5;
double off2 = scrubSpan[0][1] - 0.5;
double off3 = scrubSpan[0][2] - 0.5;
double off4 = scrubSpan[0][3] - 0.5;
double off5 = scrubSpan[0][4] - 0.5;
double off6 = scrubSpan[0][5] - 0.5;
double off7 = scrubSpan[0][6] - 0.5;
double off8 = scrubSpan[0][7] - 0.5;

scrubVal1 = scrub + off1;
scrubVal2 = scrub + off2;
scrubVal3 = scrub + off3;
scrubVal4 = scrub + off4;
scrubVal5 = scrub + off5;
scrubVal6 = scrub + off6;
scrubVal7 = scrub + off7;
scrubVal8 = scrub + off8;

}

if (scrubVal1 < 0.0) scrubVal1 += 1.0;
if (scrubVal1 > 1.0) scrubVal1 -= 1.0;

if (scrubVal2 < 0.0) scrubVal2 += 1.0;
if (scrubVal2 > 1.0) scrubVal2 -= 1.0;

if (scrubVal3 < 0.0) scrubVal3 += 1.0;
if (scrubVal3 > 1.0) scrubVal3 -= 1.0;

if (scrubVal4 < 0.0) scrubVal4 += 1.0;
if (scrubVal4 > 1.0) scrubVal4 -= 1.0;

if (scrubVal5 < 0.0) scrubVal5 += 1.0;
if (scrubVal5 > 1.0) scrubVal5 -= 1.0;

if (scrubVal6 < 0.0) scrubVal6 += 1.0;
if (scrubVal6 > 1.0) scrubVal6 -= 1.0;

if (scrubVal7 < 0.0) scrubVal7 += 1.0;
if (scrubVal7 > 1.0) scrubVal7 -= 1.0;

if (scrubVal8 < 0.0) scrubVal8 += 1.0;
if (scrubVal8 > 1.0) scrubVal8 -= 1.0;

// --- integer density ---
int g = (int)maxGrains;
if (g < 1) g = 1;
if (g > 8) g = 8;

          
		double center = (double)(g - 1) * 0.5;
       double invDenom = (g > 1) ? 1.0 / (double)(g - 1) : 0.0;
       
double densityChaos = density;   // 0 → 1

double basePos1 = quantiseScrub(scrubVal1, audioData) * maxStart;
double basePos2 = quantiseScrub(scrubVal2, audioData) * maxStart;
double basePos3 = quantiseScrub(scrubVal3, audioData) * maxStart;
double basePos4 = quantiseScrub(scrubVal4, audioData) * maxStart;
double basePos5 = quantiseScrub(scrubVal5, audioData) * maxStart;
double basePos6 = quantiseScrub(scrubVal6, audioData) * maxStart;
double basePos7 = quantiseScrub(scrubVal7, audioData) * maxStart;
double basePos8 = quantiseScrub(scrubVal8, audioData) * maxStart;

// -----------------------------------------------------
// DENSITY-DRIVEN START POSITION SPREAD
// -----------------------------------------------------

double densitySpreadAmount = grainSize * 0.8 * density;

// Only apply when NOT in morph mode
if (scrubMode < 0.5 || scrubBlend < 0.5)
{
double center = (double)(g - 1) * 0.5;
double denom = (g > 1) ? (double)(g - 1) : 1.0;
double invDenom = 1.0 / denom;   // ← only ONE division

double offset0 = (0.0 - center) * invDenom;
double offset1 = (1.0 - center) * invDenom;
double offset2 = (2.0 - center) * invDenom;
double offset3 = (3.0 - center) * invDenom;
double offset4 = (4.0 - center) * invDenom;
double offset5 = (5.0 - center) * invDenom;
double offset6 = (6.0 - center) * invDenom;
double offset7 = (7.0 - center) * invDenom;

basePos1 += offset0 * densitySpreadAmount;
basePos2 += offset1 * densitySpreadAmount;
basePos3 += offset2 * densitySpreadAmount;
basePos4 += offset3 * densitySpreadAmount;
basePos5 += offset4 * densitySpreadAmount;
basePos6 += offset5 * densitySpreadAmount;
basePos7 += offset6 * densitySpreadAmount;
basePos8 += offset7 * densitySpreadAmount;
}

basePos1 += jitterOffset(0, g, scrubVal1) * densityChaos;
basePos2 += jitterOffset(1, g, scrubVal2) * densityChaos;
basePos3 += jitterOffset(2, g, scrubVal3) * densityChaos;
basePos4 += jitterOffset(3, g, scrubVal4) * densityChaos;
basePos5 += jitterOffset(4, g, scrubVal5) * densityChaos;
basePos6 += jitterOffset(5, g, scrubVal6) * densityChaos;
basePos7 += jitterOffset(6, g, scrubVal7) * densityChaos;
basePos8 += jitterOffset(7, g, scrubVal8) * densityChaos;

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

double densityNorm = density;

bool isStackMode = (scrubMode < 0.5 || scrubBlend < 0.5);

double spreadNorm = isStackMode ? 1.0 : density;
double collapse = wander * densityNorm;   // master chaos amount
//double panAmount = panSpread * spreadNorm;
double microSpread = microDelay * densityNorm;
double microSamples = 11500.0 * microSpread; 

double spatialAmount = grainSize * 0.35 * collapse;

// --- WANDER ---
double wanderDepth = grainSize * 0.5 * wander;

// slow phase
v.wanderPhase += 0.00005;

// non-linear nested sine (removes obvious LFO feel)
double wanderCurve =
    Math.sin(v.wanderPhase + Math.sin(v.wanderPhase * 0.37));

// scale by density so low density stays clean
double wanderOffset =
    wanderCurve * wanderDepth * densityNorm;

double driftAmount = 0.03 * pitchDrift * densityChaos;
double retrigAmount = grainSize * 0.25 * retrigDrift * densityChaos;

double baseExp = 0.3 + 2.7 * windowShape;

double flatten = 1.0 - (0.85 * densityNorm);
flatten = flatten * 0.7 + 0.3;
if (flatten < 0.25) flatten = 0.25;

double exponent1 = baseExp * flatten;
if (exponent1 < 0.05) exponent1 = 0.05;

double Lsum = 0.0;
double Rsum = 0.0;

// ----------------------------
// FIRST GRAIN
// ----------------------------

double weight1 = getGrainWeight(0, g);

if (!v.schedActive)
{
    v.schedActive = true;
    v.schedPhase = 0.0;
}

if (pitchState == 2) // STRETCH MODE
{
    // grain moves at normal playback rate
    v.schedPhase += 1.0;

    if (v.schedPhase >= grainSize)
        v.schedPhase = 0.0;

    // centered around scanPos
    double scrubBase = quantiseScrub(scrub, audioData) * maxStart;

double pos1 = scrubBase
            + v.scanPos
            + v.schedPhase
            - (grainSize * 0.5);

    if (pos1 < 0.0) pos1 = 0.0;
    if (pos1 >= audioData.numSamples - 1.0)
        pos1 = audioData.numSamples - 2.0;

    int i1 = (int)pos1;
    double f1 = pos1 - i1;

    double w1 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase / grainSize));
    w1 = Math.pow(w1, exponent1);

    double monoL1 = (1.0 - f1) * sample[0][i1] + f1 * sample[0][i1+1];
    double monoR1 = (1.0 - f1) * sample[1][i1] + f1 * sample[1][i1+1];

    double normPan = ((0.0 - center) * invDenom);
    double pan1 = panSpread * normPan * 2.0;

    Lsum += monoL1 * w1 * (0.5 * (1.0 - pan1)) * weight1;
    Rsum += monoR1 * w1 * (0.5 * (1.0 + pan1)) * weight1;
}
else
{
    // ---- ORIGINAL NON-STRETCH BEHAVIOUR ----

    if (!v.schedActive)
    {
        v.schedStart = basePos1;
    }

    double grainPitchMul = 1.0;

    if (pitchState == 0)
    {
        double spread = pitchSpread * spreadNorm;
        grainPitchMul += spread * Math.sin(0.77);
    }
    else
    {
        double harmonicTarget = 1.0;
        grainPitchMul = 1.0 + (harmonicTarget - 1.0) * pitchSpread;
    }

    double phaseInc = v.delta * grainPitchMul;
    v.schedPhase += phaseInc * (1.0 + driftAmount);

    if (v.schedPhase >= grainSize)
    {
        v.schedPhase -= grainSize;
        v.schedStart = basePos1;
    }

    double pos1 = v.schedStart + v.schedPhase;

    if (pos1 < 0.0) pos1 = 0.0;
    if (pos1 >= audioData.numSamples - 1.0)
        pos1 = audioData.numSamples - 2.0;

    int i1 = (int)pos1;
    double f1 = pos1 - i1;

    double w1 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase / grainSize));
    w1 = Math.pow(w1, exponent1);

    double monoL1 = (1.0 - f1) * sample[0][i1] + f1 * sample[0][i1+1];
    double monoR1 = (1.0 - f1) * sample[1][i1] + f1 * sample[1][i1+1];

    double normPan = ((0.0 - center) * invDenom);
    double pan1 = panSpread * normPan * 2.0;

    Lsum += monoL1 * w1 * (0.5 * (1.0 - pan1)) * weight1;
    Rsum += monoR1 * w1 * (0.5 * (1.0 + pan1)) * weight1;
}

// ----------------------------
// SECOND GRAIN
// ----------------------------

double weight2 = getGrainWeight(1, g);

if (g > 1)
{
    if (!v.schedActive2)
    {
        v.schedActive2 = true;
        v.schedPhase2 = 0.0;
    }

    if (pitchState == 2) // STRETCH
    {
        v.schedPhase2 += 1.0;

        if (v.schedPhase2 >= grainSize)
            v.schedPhase2 = 0.0;

        double pos2 = scrubBase
            + v.scanPos
            + v.schedPhase2
            - (grainSize * 0.5);

        if (pos2 < 0.0) pos2 = 0.0;
        if (pos2 >= audioData.numSamples - 1.0)
            pos2 = audioData.numSamples - 2.0;

        int i2 = (int)pos2;
        double f2 = pos2 - i2;

        double w2 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase2 / grainSize));
        w2 = Math.pow(w2, exponent1);

        double monoL2 = (1.0 - f2) * sample[0][i2] + f2 * sample[0][i2+1];
        double monoR2 = (1.0 - f2) * sample[1][i2] + f2 * sample[1][i2+1];

        double normPan = ((1.0 - center) * invDenom);
        double pan2 = panSpread * normPan * 2.0;

        Lsum += monoL2 * w2 * (0.5 * (1.0 - pan2)) * weight2;
        Rsum += monoR2 * w2 * (0.5 * (1.0 + pan2)) * weight2;
    }
    else
    {
        double grainPitchMul2 = 1.0;

        if (pitchState == 0)
        {
            double spread = pitchSpread * spreadNorm;
            grainPitchMul2 += spread * Math.sin(1.91);
        }
        else
        {
            double harmonicTarget = 2.0;
            grainPitchMul2 = 1.0 + (harmonicTarget - 1.0) * pitchSpread;
        }

        double phaseInc2 = v.delta * grainPitchMul2;
        v.schedPhase2 += phaseInc2 * (1.0 + driftAmount);

        if (v.schedPhase2 >= grainSize)
        {
            v.schedPhase2 -= grainSize;
            v.schedStart2 = basePos2;
        }

        double pos2 = v.schedStart2 + v.schedPhase2;

        if (pos2 < 0.0) pos2 = 0.0;
        if (pos2 >= audioData.numSamples - 1.0)
            pos2 = audioData.numSamples - 2.0;

        int i2 = (int)pos2;
        double f2 = pos2 - i2;

        double w2 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase2 / grainSize));
        w2 = Math.pow(w2, exponent1);

        double monoL2 = (1.0 - f2) * sample[0][i2] + f2 * sample[0][i2+1];
        double monoR2 = (1.0 - f2) * sample[1][i2] + f2 * sample[1][i2+1];

        double normPan = ((1.0 - center) * invDenom);
        double pan2 = panSpread * normPan * 2.0;

        Lsum += monoL2 * w2 * (0.5 * (1.0 - pan2)) * weight2;
        Rsum += monoR2 * w2 * (0.5 * (1.0 + pan2)) * weight2;
    }
}

// ----------------------------
// THIRD GRAIN
// ----------------------------

double weight3 = getGrainWeight(2, g);

if (g > 2)
{
    if (!v.schedActive3)
    {
        v.schedActive3 = true;
        v.schedPhase3 = 0.0;
    }

    if (pitchState == 2)
    {
        v.schedPhase3 += 1.0;

        if (v.schedPhase3 >= grainSize)
            v.schedPhase3 = 0.0;

        double pos3 = scrubBase
            + v.scanPos
            + v.schedPhase3
            - (grainSize * 0.5);

        if (pos3 < 0.0) pos3 = 0.0;
        if (pos3 >= audioData.numSamples - 1.0)
            pos3 = audioData.numSamples - 2.0;

        int i3 = (int)pos3;
        double f3 = pos3 - i3;

        double w3 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase3 / grainSize));
        w3 = Math.pow(w3, exponent1);

        double monoL3 = (1.0 - f3) * sample[0][i3] + f3 * sample[0][i3+1];
        double monoR3 = (1.0 - f3) * sample[1][i3] + f3 * sample[1][i3+1];

        double normPan = ((2.0 - center) * invDenom);
        double pan3 = panSpread * normPan * 2.0;

        Lsum += monoL3 * w3 * (0.5 * (1.0 - pan3)) * weight3;
        Rsum += monoR3 * w3 * (0.5 * (1.0 + pan3)) * weight3;
    }
    else
    {
        double grainPitchMul3 = 1.0;

        if (pitchState == 0)
        {
            double spread = pitchSpread * spreadNorm;
            grainPitchMul3 += spread * Math.sin(2.43);
        }
        else
        {
            double harmonicTarget = 3.0;
            grainPitchMul3 = 1.0 + (harmonicTarget - 1.0) * pitchSpread;
        }

        double phaseInc3 = v.delta * grainPitchMul3;
        v.schedPhase3 += phaseInc3 * (1.0 + driftAmount);

        if (v.schedPhase3 >= grainSize)
        {
            v.schedPhase3 -= grainSize;
            v.schedStart3 = basePos3;
        }

        double pos3 = v.schedStart3 + v.schedPhase3;

        if (pos3 < 0.0) pos3 = 0.0;
        if (pos3 >= audioData.numSamples - 1.0)
            pos3 = audioData.numSamples - 2.0;

        int i3 = (int)pos3;
        double f3 = pos3 - i3;

        double w3 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase3 / grainSize));
        w3 = Math.pow(w3, exponent1);

        double monoL3 = (1.0 - f3) * sample[0][i3] + f3 * sample[0][i3+1];
        double monoR3 = (1.0 - f3) * sample[1][i3] + f3 * sample[1][i3+1];

        double normPan = ((2.0 - center) * invDenom);
        double pan3 = panSpread * normPan * 2.0;

        Lsum += monoL3 * w3 * (0.5 * (1.0 - pan3)) * weight3;
        Rsum += monoR3 * w3 * (0.5 * (1.0 + pan3)) * weight3;
    }
}
// ----------------------------
// FOURTH GRAIN (if g > 3)
// ----------------------------

double weight4 = getGrainWeight(3, g);

if (g > 3)
{
    if (!v.schedActive4)
    {
        v.schedActive4 = true;
        v.schedPhase4 = grainSize * 0.75 * density;

        if (pitchState == 2)
            v.schedStart4 = v.scanPos;
        else
            v.schedStart4 = basePos4;
    }

    double phaseInc4 = (pitchState == 2) ? 1.0 : v.delta;

    v.schedPhase4 += phaseInc4;

    if (v.schedPhase4 >= grainSize)
    {
        v.schedPhase4 -= grainSize;

        if (pitchState == 2)
            v.schedStart4 = v.scanPos;
        else
            v.schedStart4 = basePos4;
    }

    double pos4 = scrubBase
            + v.scanPos
            + v.schedPhase4
            - (grainSize * 0.5);

    if (pos4 < 0.0) pos4 = 0.0;
    if (pos4 >= audioData.numSamples - 1.0)
        pos4 = audioData.numSamples - 2.0;

    int i4 = (int)pos4;
    double f4 = pos4 - i4;

    double w4 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase4 / grainSize));

    double monoL4 = (1.0 - f4) * sample[0][i4] + f4 * sample[0][i4+1];
    double monoR4 = (1.0 - f4) * sample[1][i4] + f4 * sample[1][i4+1];

    double normPan = ((3.0 - center) * invDenom);
    double pan4 = panSpread * normPan * 2.0;
    double leftGain4  = 0.5 * (1.0 - pan4);
    double rightGain4 = 0.5 * (1.0 + pan4);

    Lsum += monoL4 * w4 * leftGain4 * weight4;
    Rsum += monoR4 * w4 * rightGain4 * weight4;
}

//5th

// ----------------------------
// FIFTH GRAIN (if g > 4)
// ----------------------------

double weight5 = getGrainWeight(4, g);

if (g > 4)
{
    if (!v.schedActive5)
    {
        v.schedActive5 = true;
        v.schedPhase5 = grainSize * 0.125 * density;

        if (pitchState == 2)
            v.schedStart5 = v.scanPos;
        else
            v.schedStart5 = basePos5;
    }

    double phaseInc5 = (pitchState == 2) ? 1.0 : v.delta;

    v.schedPhase5 += phaseInc5;

    if (v.schedPhase5 >= grainSize)
    {
        v.schedPhase5 -= grainSize;

        if (pitchState == 2)
            v.schedStart5 = v.scanPos;
        else
            v.schedStart5 = basePos5;
    }

    double pos5 = scrubBase
            + v.scanPos
            + v.schedPhase5
            - (grainSize * 0.5);

    if (pos5 < 0.0) pos5 = 0.0;
    if (pos5 >= audioData.numSamples - 1.0)
        pos5 = audioData.numSamples - 2.0;

    int i5 = (int)pos5;
    double f5 = pos5 - i5;

    double w5 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase5 / grainSize));

    double monoL5 = (1.0 - f5) * sample[0][i5] + f5 * sample[0][i5+1];
    double monoR5 = (1.0 - f5) * sample[1][i5] + f5 * sample[1][i5+1];

    double normPan = ((4.0 - center) * invDenom);
    double pan5 = panSpread * normPan * 2.0;
    double leftGain5  = 0.5 * (1.0 - pan5);
    double rightGain5 = 0.5 * (1.0 + pan5);

    Lsum += monoL5 * w5 * leftGain5 * weight5;
    Rsum += monoR5 * w5 * rightGain5 * weight5;
}

// ----------------------------
// SIXTH GRAIN (if g > 5)
// ----------------------------

double weight6 = getGrainWeight(5, g);

if (g > 5)
{
    if (!v.schedActive6)
    {
        v.schedActive6 = true;
        v.schedPhase6 = grainSize * 0.375 * density;

        if (pitchState == 2)
            v.schedStart6 = v.scanPos;
        else
            v.schedStart6 = basePos6;
    }

    double phaseInc6 = (pitchState == 2) ? 1.0 : v.delta;

    v.schedPhase6 += phaseInc6;

    if (v.schedPhase6 >= grainSize)
    {
        v.schedPhase6 -= grainSize;

        if (pitchState == 2)
            v.schedStart6 = v.scanPos;
        else
            v.schedStart6 = basePos6;
    }

    double pos6 = scrubBase
            + v.scanPos
            + v.schedPhase6
            - (grainSize * 0.5);

    if (pos6 < 0.0) pos6 = 0.0;
    if (pos6 >= audioData.numSamples - 1.0)
        pos6 = audioData.numSamples - 2.0;

    int i6 = (int)pos6;
    double f6 = pos6 - i6;

    double w6 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase6 / grainSize));

    double monoL6 = (1.0 - f6) * sample[0][i6] + f6 * sample[0][i6+1];
    double monoR6 = (1.0 - f6) * sample[1][i6] + f6 * sample[1][i6+1];

    double normPan = ((5.0 - center) * invDenom);
    double pan6 = panSpread * normPan * 2.0;
    double leftGain6  = 0.5 * (1.0 - pan6);
    double rightGain6 = 0.5 * (1.0 + pan6);

    Lsum += monoL6 * w6 * leftGain6 * weight6;
    Rsum += monoR6 * w6 * rightGain6 * weight6;
}

// ----------------------------
// SEVENTH GRAIN (if g > 6)
// ----------------------------

double weight7 = getGrainWeight(6, g);

if (g > 6)
{
    if (!v.schedActive7)
    {
        v.schedActive7 = true;
        v.schedPhase7 = grainSize * 0.625 * density;

        if (pitchState == 2)
            v.schedStart7 = v.scanPos;
        else
            v.schedStart7 = basePos7;
    }

    double phaseInc7 = (pitchState == 2) ? 1.0 : v.delta;

    v.schedPhase7 += phaseInc7;

    if (v.schedPhase7 >= grainSize)
    {
        v.schedPhase7 -= grainSize;

        if (pitchState == 2)
            v.schedStart7 = v.scanPos;
        else
            v.schedStart7 = basePos7;
    }

    double pos7 = scrubBase
            + v.scanPos
            + v.schedPhase7
            - (grainSize * 0.5);

    if (pos7 < 0.0) pos7 = 0.0;
    if (pos7 >= audioData.numSamples - 1.0)
        pos7 = audioData.numSamples - 2.0;

    int i7 = (int)pos7;
    double f7 = pos7 - i7;

    double w7 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase7 / grainSize));

    double monoL7 = (1.0 - f7) * sample[0][i7] + f7 * sample[0][i7+1];
    double monoR7 = (1.0 - f7) * sample[1][i7] + f7 * sample[1][i7+1];

    double normPan = ((6.0 - center) * invDenom);
    double pan7 = panSpread * normPan * 2.0;
    double leftGain7  = 0.5 * (1.0 - pan7);
    double rightGain7 = 0.5 * (1.0 + pan7);

    Lsum += monoL7 * w7 * leftGain7 * weight7;
    Rsum += monoR7 * w7 * rightGain7 * weight7;
}

// ----------------------------
// EIGHTH GRAIN (if g > 7)
// ----------------------------

double weight8 = getGrainWeight(7, g);

if (g > 7)
{
    if (!v.schedActive8)
    {
        v.schedActive8 = true;
        v.schedPhase8 = grainSize * 0.875 * density;

        if (pitchState == 2)
            v.schedStart8 = v.scanPos;
        else
            v.schedStart8 = basePos8;
    }

    double phaseInc8 = (pitchState == 2) ? 1.0 : v.delta;

    v.schedPhase8 += phaseInc8;

    if (v.schedPhase8 >= grainSize)
    {
        v.schedPhase8 -= grainSize;

        if (pitchState == 2)
            v.schedStart8 = v.scanPos;
        else
            v.schedStart8 = basePos8;
    }

    double pos8 = scrubBase
            + v.scanPos
            + v.schedPhase8
            - (grainSize * 0.5);

    if (pos8 < 0.0) pos8 = 0.0;
    if (pos8 >= audioData.numSamples - 1.0)
        pos8 = audioData.numSamples - 2.0;

    int i8 = (int)pos8;
    double f8 = pos8 - i8;

    double w8 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase8 / grainSize));

    double monoL8 = (1.0 - f8) * sample[0][i8] + f8 * sample[0][i8+1];
    double monoR8 = (1.0 - f8) * sample[1][i8] + f8 * sample[1][i8+1];

    double normPan = ((7.0 - center) * invDenom);
    double pan8 = panSpread * normPan * 2.0;
    double leftGain8  = 0.5 * (1.0 - pan8);
    double rightGain8 = 0.5 * (1.0 + pan8);

    Lsum += monoL8 * w8 * leftGain8 * weight8;
    Rsum += monoR8 * w8 * rightGain8 * weight8;
}

// ----------------------------
// WEIGHT-BASED NORMALISATION
// ----------------------------

if (scrubMode < 0.5 || scrubBlend < 0.5)
{
    // Stack mode
    double norm = (double)g;
    if (norm > 0.0)
    {
        Lsum /= norm;
        Rsum /= norm;
    }
}
else
{
    // Morph mode – slight compensation
    Lsum *= 0.85;
    Rsum *= 0.85;
}
fd[0] += (float)Lsum;
fd[1] += (float)Rsum;
    }

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
    if (index == 1)   // Slot 0 = Audio
    {
        audioData = ed;

        ed.referBlockTo(sample[0], 0);
        ed.referBlockTo(sample[1], 1);

        updateGrainSize();
        reset();
    }
    else if (index == 0)  // Slot 1 = Sliderpack
    {
        scrubData = ed;
        ed.referBlockTo(scrubSpan[0], 0);
    }
}

    // -----------------------------------------------------
    template<int P>
    void setParameter(double v)
    {
        if (P == 0)
        {
            pitchSemitones = v;
            for (auto& voice : voiceData)
                updateDelta(voice);
        }

        if (P == 1) scrub = v;

        if (P == 2)
        {
            grainMs = v;
            updateGrainSize();
        }

        if (P == 3)
{
    if (v < 0.0) v = 0.0;
    if (v > 1.0) v = 1.0;
    density = v;
}
        
      
        if (P == 4)
        {
            if (v < 0.0) v = 0.0;
            if (v > 1.0) v = 1.0;
            windowShape = v;
        } 
        
        if (P == 5)
        {
            if (v < 0.0) v = 0.0;
            if (v > 1.0) v = 1.0;
            panSpread = v;
        }
        if (P == 6)
               {
                   if (v < 0.0) v = 0.0;
                   if (v > 1.0) v = 1.0;
                   pitchMode = v;
               }
         if (P == 7)
                      {
                          if (v < 0.0) v = 0.0;
                          if (v > 1.0) v = 1.0;
                          pitchSpread = v;
                      }     
     
       
     if (P == 8)
{
    if (v < 1.0) v = 1.0;
    if (v > 5000.0) v = 5000.0;
    stretchMs = v;
}         

// 16 — maxGrains (1–8)
if (P == 9)
{
    if (v < 1.0) v = 1.0;
    if (v > 8.0) v = 8.0;
    maxGrains = v;
}

// 17 — scrubMode (0 or 1)
if (P == 10)
{
    if (v < 0.0) v = 0.0;
    if (v > 1.0) v = 1.0;
    scrubMode = v;
}

// 18 — scrubBlend (0–1)
if (P == 11)
{
    if (v < 0.0) v = 0.0;
    if (v > 1.0) v = 1.0;
    scrubBlend = v;
}

// 18 — scrubBlend (0–1)
if (P == 12)
{
    if (v < 0.0) v = 0.0;
    if (v > 1.0) v = 1.0;
    wander = v;
}
                       
    }
};