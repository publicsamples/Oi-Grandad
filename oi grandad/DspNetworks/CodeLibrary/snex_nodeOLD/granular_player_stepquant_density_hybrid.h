template <int NV>
struct granular_player_stepquant_density_hybrid
{
    SNEX_NODE(granular_player_stepquant_density_hybrid);

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
	double pitchSpread = 0.0;     // 0..1 amount
	double pitchMode = 0.0; 

  double maxGrains = 4.0;     // 1–8
  double scrubMode = 0.0;     // 0 = stack, 1 = morph
  double scrubBlend = 0.0;    // 0–1 shaping
  double reverse = 0.0;   // 0 = forward, 1 = reverse
  double jitter = 0.0;   // 0..1 global jitter amount
	
    // -----------------------------------------------------
    struct VoiceData
{
    double scanPos = 0.0;
    double delta   = 1.0;
    int noteNumber = 60;

    double scrubQ = 0.0;
  double speedPhase = 0.0;
    

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
    speedPhase = 0.0;

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

    // -----------------------------------------------------
    void updateDelta(VoiceData& v)
    {
          double semis = 0.0;

    // If NOT fixed mode, track MIDI
    if (pitchMode < 0.66)
    {
        semis = (double)v.noteNumber - (double)rootNote;
    }

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
    if (jitter <= 0.0)
        return 0.0;

    // deterministic seed
    double s = (double)gi * 57.123 + scrubVal * 31.77;
    double r = Math.abs(Math.sin(s)) * 1.999;

    // -0.5 .. +0.5
    double centered = r - 0.5;

    // max 50% of grainSize scaled by user control
    double j = jitter * jitter; // square for exponential feel
double amount = grainSize * 32.0 * j;

    return centered * amount;
}
    
inline double getGrainWeight(int GI, int g)
{
    // STACK MODE = all grains always on
    if (scrubBlend < 0.5)
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
	    maxStart = 0.0;

	double scrubBase = scrub * maxStart;
    
// ----------------------------
// SCRUB MODE
// 0 = normal
// 1 = pack
// 2 = speed
// ----------------------------

int scrubState = 0;

// =====================================================
// VARISPEED SCRUB (Mode 3)
// =====================================================
if (scrubState == 3)
{
    double W = grainMs * (sr * 0.001);
    if (W < 16.0) W = 16.0;

    double maxStart = (double)audioData.numSamples - W - 2.0;
    if (maxStart <= 0.0)
        return;

    // scrub position → sample position
    double base = scrub * maxStart;

    double halfW = W * 0.5;

    double dir = (reverse > 0.5) ? -1.0 : 1.0;

    // INITIALISE PHASES
    if (!v.schedActive)
    {
        v.schedActive  = true;
        v.schedActive2 = true;

        v.schedPhase  = 0.0;
        v.schedPhase2 = halfW;

        v.schedStart  = base;
        v.schedStart2 = base;
    }

    // ADVANCE BOTH GRAINS BY SAME DELTA
    double inc = v.delta * dir;

    v.schedPhase  += inc;
    v.schedPhase2 += inc;

    if (v.schedPhase  >= W) v.schedPhase  -= W;
    if (v.schedPhase  < 0.0) v.schedPhase  += W;

    if (v.schedPhase2 >= W) v.schedPhase2 -= W;
    if (v.schedPhase2 < 0.0) v.schedPhase2 += W;

    // WINDOW SHAPE FACTOR (from old engine)
    double baseExp = 0.3 + 2.7 * windowShape;
    double exponent = baseExp;
    if (exponent < 0.05) exponent = 0.05;

    // ------------------------
    // GRAIN A
    // ------------------------
    double posA = base + v.schedPhase;
    if (posA < 0.0) posA = 0.0;
    if (posA >= audioData.numSamples - 1.0)
        posA = audioData.numSamples - 2.0;

    int iA = (int)posA;
    double fA = posA - (double)iA;

    double wA = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase / W));
    wA = Math.pow(wA, exponent);

    double LA = (1.0 - fA) * sample[0][iA] + fA * sample[0][iA+1];
    double RA = (1.0 - fA) * sample[1][iA] + fA * sample[1][iA+1];

    // ------------------------
    // GRAIN B (180° OFFSET)
    // ------------------------
    double posB = base + v.schedPhase2;
    if (posB < 0.0) posB = 0.0;
    if (posB >= audioData.numSamples - 1.0)
        posB = audioData.numSamples - 2.0;

    int iB = (int)posB;
    double fB = posB - (double)iB;

    double wB = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase2 / W));
    wB = Math.pow(wB, exponent);

    double LB = (1.0 - fB) * sample[0][iB] + fB * sample[0][iB+1];
    double RB = (1.0 - fB) * sample[1][iB] + fB * sample[1][iB+1];

    // SUM
    double L = LA * wA + LB * wB;
    double R = RA * wA + RB * wB;

    fd[0] += (float)L;
    fd[1] += (float)R;

    return;
}

// 0 = normal
// 1 = multi-scrub
// 2 = legacy speed (unused now)
// 3 = varispeed scrub

if (scrubMode < 0.25)
    scrubState = 0;
else if (scrubMode < 0.5)
    scrubState = 1;
else if (scrubMode < 0.75)
    scrubState = 2;
else
    scrubState = 3;

// =====================================================
// VARISPEED SCRUB (Mode 3)
// =====================================================

if (scrubState == 3)
{
    double W = grainSize;
    if (W < 16.0) W = 16.0;

    double maxStart = (double)audioData.numSamples - W - 2.0;
    if (maxStart <= 0.0)
        return;

    double base = scrub * maxStart;

    double halfW = W * 0.5;

    double dir = (reverse > 0.5) ? -1.0 : 1.0;

    // Grain A + B state reuse:
    // We hijack schedPhase + schedPhase2 for phase,
    // schedStart + schedStart2 for positions.

    if (!v.schedActive)
    {
        v.schedActive = true;
        v.schedActive2 = true;

        v.schedPhase = 0.0;
        v.schedPhase2 = halfW;

        v.schedStart = base;
        v.schedStart2 = base;
    }

    // Advance phase continuously
    double inc = v.delta * dir;

    v.schedPhase += inc;
    v.schedPhase2 += inc;

    if (v.schedPhase >= W) v.schedPhase -= W;
    if (v.schedPhase < 0.0) v.schedPhase += W;

    if (v.schedPhase2 >= W) v.schedPhase2 -= W;
    if (v.schedPhase2 < 0.0) v.schedPhase2 += W;

    // Window exponent logic (your old shaping)
    double baseExp = 0.3 + 2.7 * windowShape;
    double exponent = baseExp;
    if (exponent < 0.05) exponent = 0.05;

    // ========================
    // GRAIN A
    // ========================
    double posA = base + v.schedPhase;

    if (posA < 0.0) posA = 0.0;
    if (posA >= audioData.numSamples - 1.0)
        posA = audioData.numSamples - 2.0;

    int iA = (int)posA;
    double fA = posA - (double)iA;

    double wA = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase / W));
    wA = Math.pow(wA, exponent);

    double monoLA = (1.0 - fA) * sample[0][iA] + fA * sample[0][iA+1];
    double monoRA = (1.0 - fA) * sample[1][iA] + fA * sample[1][iA+1];

    // ========================
    // GRAIN B (180° offset)
    // ========================
    double posB = base + v.schedPhase2;

    if (posB < 0.0) posB = 0.0;
    if (posB >= audioData.numSamples - 1.0)
        posB = audioData.numSamples - 2.0;

    int iB = (int)posB;
    double fB = posB - (double)iB;

    double wB = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase2 / W));
    wB = Math.pow(wB, exponent);

    double monoLB = (1.0 - fB) * sample[0][iB] + fB * sample[0][iB+1];
    double monoRB = (1.0 - fB) * sample[1][iB] + fB * sample[1][iB+1];

    // Mix (equal power style)
    double L = monoLA * wA + monoLB * wB;
    double R = monoRA * wA + monoRB * wB;

    fd[0] += (float)L;
    fd[1] += (float)R;

    return;
}



int pitchState = 0;

// 0 = detune (track MIDI)
// 1 = harmonic (track MIDI)
// 2 = fixed (ignore MIDI)

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
// Mode 2 = speed mode
//---------------------------------------------------------

// ---- values (paired grains) ----
double scrubVal1 = scrub;
double scrubVal2 = scrub;

double scrubVal3 = scrubB;
double scrubVal4 = scrubB;

double scrubVal5 = scrubC;
double scrubVal6 = scrubC;

double scrubVal7 = scrubD;
double scrubVal8 = scrubD;

// ---- quantise only in non-speed modes ----
if (scrubState != 2)
{
    scrubVal1 = quantiseScrub(scrubVal1, audioData);
    scrubVal2 = scrubVal1;

    scrubVal3 = quantiseScrub(scrubVal3, audioData);
    scrubVal4 = scrubVal3;

    scrubVal5 = quantiseScrub(scrubVal5, audioData);
    scrubVal6 = scrubVal5;

    scrubVal7 = quantiseScrub(scrubVal7, audioData);
    scrubVal8 = scrubVal7;
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

// SPEED MODE
if (scrubState == 2)
{
    basePos1 = scrubBase;
    basePos2 = scrubBase;
    basePos3 = scrubBase;
    basePos4 = scrubBase;
    basePos5 = scrubBase;
    basePos6 = scrubBase;
    basePos7 = scrubBase;
    basePos8 = scrubBase;
}
// MULTI-SCRUB MODE (NO SLIDERPACK)
else if (scrubState == 1)
{
    basePos1 = scrubVal1 * maxStart;
    basePos2 = scrubVal2 * maxStart;

    basePos3 = scrubVal3 * maxStart;
    basePos4 = scrubVal4 * maxStart;

    basePos5 = scrubVal5 * maxStart;
    basePos6 = scrubVal6 * maxStart;

    basePos7 = scrubVal7 * maxStart;
    basePos8 = scrubVal8 * maxStart;
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
}
// --- integer density ---
int g = (int)maxGrains;
if (g < 1) g = 1;
if (g > 8) g = 8;

          
		double center = (double)(g - 1) * 0.5;
       double invDenom = (g > 1) ? 1.0 / (double)(g - 1) : 0.0;
       
double densityChaos = density;   // 0 → 1



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
}
else
{
    // Normal & speed modes
    basePos1 = scrubBase;
    basePos2 = scrubBase;
    basePos3 = scrubBase;
    basePos4 = scrubBase;
    basePos5 = scrubBase;
    basePos6 = scrubBase;
    basePos7 = scrubBase;
    basePos8 = scrubBase;
}

// -----------------------------------------------------
// DENSITY-DRIVEN START POSITION SPREAD
// -----------------------------------------------------

double densitySpreadAmount = grainSize * 0.8 * density;

// Only apply when NOT in morph mode
if (scrubBlend < 0.5)
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
bool isStackMode = (scrubBlend < 0.5);
double spreadNorm = isStackMode ? 1.0 : density;


double baseExp = 0.3 + 2.7 * windowShape;
double flatten = 1.0 - (0.85 * densityNorm);

flatten = flatten * 0.7 + 0.3;
if (flatten < 0.25) flatten = 0.25;

double exponent1 = baseExp * flatten;
if (exponent1 < 0.05) exponent1 = 0.05;

double Lsum = 0.0;
double Rsum = 0.0;

double dir = (reverse > 0.5) ? -1.0 : 1.0;

// ============================
// GRAIN 1
// ============================

double weight1 = getGrainWeight(0, g);

if (!v.schedActive)
{
    v.schedActive = true;
    v.schedPhase = 0.0;
    v.schedStart = basePos1;
}

{
    double grainPitchMul1 = 1.0;

    if (pitchState == 0)
    {
        double spread = pitchSpread * spreadNorm;
        grainPitchMul1 += spread * Math.sin(0.77);
    }
    else
    {
        double harmonicTarget = 1.0;
        grainPitchMul1 = 1.0 + (harmonicTarget - 1.0) * pitchSpread;
    }

    double phaseInc1 = v.delta * grainPitchMul1 * dir;

    v.schedPhase += phaseInc1 * (1.0);

    if (v.schedPhase >= grainSize)
    {
        v.schedPhase -= grainSize;
        v.schedStart = basePos1;
    }

    if (v.schedPhase < 0.0)
    {
        v.schedPhase += grainSize;
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

    double normPan1 = ((0.0 - center) * invDenom);
    double pan1 = panSpread * normPan1 * 2.0;

    Lsum += monoL1 * w1 * (0.5 * (1.0 - pan1)) * weight1;
    Rsum += monoR1 * w1 * (0.5 * (1.0 + pan1)) * weight1;
}

// ============================
// GRAIN 2
// ============================

double weight2 = getGrainWeight(1, g);

if (g > 1)
{
    if (!v.schedActive2)
    {
        v.schedActive2 = true;
        v.schedPhase2 = 0.0;
        v.schedStart2 = basePos2;
    }

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

	double phaseInc2 = v.delta * grainPitchMul2 * dir;

    v.schedPhase2 += phaseInc2 * (1.0);

    if (v.schedPhase2 >= grainSize)
    {
        v.schedPhase2 -= grainSize;
        v.schedStart2 = basePos2;
    }

    if (v.schedPhase2 < 0.0)
    {
        v.schedPhase2 += grainSize;
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

    double normPan2 = ((1.0 - center) * invDenom);
    double pan2 = panSpread * normPan2 * 2.0;

    Lsum += monoL2 * w2 * (0.5 * (1.0 - pan2)) * weight2;
    Rsum += monoR2 * w2 * (0.5 * (1.0 + pan2)) * weight2;
}

// ============================
// GRAIN 3
// ============================

double weight3 = getGrainWeight(2, g);

if (g > 2)
{
    if (!v.schedActive3)
    {
        v.schedActive3 = true;
        v.schedPhase3 = 0.0;
        v.schedStart3 = basePos3;
    }

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

    double phaseInc3 = v.delta * grainPitchMul3 * dir;

    v.schedPhase3 += phaseInc3 * (1.0);

    if (v.schedPhase3 >= grainSize)
    {
        v.schedPhase3 -= grainSize;
        v.schedStart3 = basePos3;
    }

    if (v.schedPhase3 < 0.0)
    {
        v.schedPhase3 += grainSize;
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

    double normPan3 = ((2.0 - center) * invDenom);
    double pan3 = panSpread * normPan3 * 2.0;

    Lsum += monoL3 * w3 * (0.5 * (1.0 - pan3)) * weight3;
    Rsum += monoR3 * w3 * (0.5 * (1.0 + pan3)) * weight3;
}

// ----------------------------
// GRAIN 4
// --

double weight4 = getGrainWeight(3, g);

if (g > 3)
{
    if (!v.schedActive4)
    {
        v.schedActive4 = true;
        v.schedPhase4 = 0.0;
        v.schedStart4 = basePos4;
    }

    double grainPitchMul4 = 1.0;

    if (pitchState == 0)
    {
        double spread = pitchSpread * spreadNorm;
        grainPitchMul4 += spread * Math.sin(3.17);
    }
    else
    {
        double harmonicTarget = 4.0;
        grainPitchMul4 = 1.0 + (harmonicTarget - 1.0) * pitchSpread;
    }

    double phaseInc4 = v.delta * grainPitchMul4 * dir;

    v.schedPhase4 += phaseInc4 * (1.0);

    if (v.schedPhase4 >= grainSize)
    {
        v.schedPhase4 -= grainSize;
        v.schedStart4 = basePos4;
    }

    if (v.schedPhase4 < 0.0)
    {
        v.schedPhase4 += grainSize;
        v.schedStart4 = basePos4;
    }

    double pos4 = v.schedStart4 + v.schedPhase4;

    if (pos4 < 0.0) pos4 = 0.0;
    if (pos4 >= audioData.numSamples - 1.0)
        pos4 = audioData.numSamples - 2.0;

    int i4 = (int)pos4;
    double f4 = pos4 - i4;

    double w4 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase4 / grainSize));
    w4 = Math.pow(w4, exponent1);

    double monoL4 = (1.0 - f4) * sample[0][i4] + f4 * sample[0][i4+1];
    double monoR4 = (1.0 - f4) * sample[1][i4] + f4 * sample[1][i4+1];

    double normPan4 = ((3.0 - center) * invDenom);
    double pan4 = panSpread * normPan4 * 2.0;

    Lsum += monoL4 * w4 * (0.5 * (1.0 - pan4)) * weight4;
    Rsum += monoR4 * w4 * (0.5 * (1.0 + pan4)) * weight4;
}

// ----------------------------
// GRAIN 5
// --

double weight5 = getGrainWeight(4, g);

if (g > 4)
{
    if (!v.schedActive5)
    {
        v.schedActive5 = true;
        v.schedPhase5 = 0.0;
        v.schedStart5 = basePos5;
    }

    double grainPitchMul5 = 1.0;

    if (pitchState == 0)
    {
        double spread = pitchSpread * spreadNorm;
        grainPitchMul5 += spread * Math.sin(4.03);
    }
    else
    {
        double harmonicTarget = 5.0;
        grainPitchMul5 = 1.0 + (harmonicTarget - 1.0) * pitchSpread;
    }

    double phaseInc5 = v.delta * grainPitchMul5 * dir;

    v.schedPhase5 += phaseInc5 * (1.0);

    if (v.schedPhase5 >= grainSize)
    {
        v.schedPhase5 -= grainSize;
        v.schedStart5 = basePos5;
    }

    if (v.schedPhase5 < 0.0)
    {
        v.schedPhase5 += grainSize;
        v.schedStart5 = basePos5;
    }

    double pos5 = v.schedStart5 + v.schedPhase5;

    if (pos5 < 0.0) pos5 = 0.0;
    if (pos5 >= audioData.numSamples - 1.0)
        pos5 = audioData.numSamples - 2.0;

    int i5 = (int)pos5;
    double f5 = pos5 - i5;

    double w5 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase5 / grainSize));
    w5 = Math.pow(w5, exponent1);

    double monoL5 = (1.0 - f5) * sample[0][i5] + f5 * sample[0][i5+1];
    double monoR5 = (1.0 - f5) * sample[1][i5] + f5 * sample[1][i5+1];

    double normPan5 = ((4.0 - center) * invDenom);
    double pan5 = panSpread * normPan5 * 2.0;

    Lsum += monoL5 * w5 * (0.5 * (1.0 - pan5)) * weight5;
    Rsum += monoR5 * w5 * (0.5 * (1.0 + pan5)) * weight5;
}

// ----------------------------
// GRAIN 6
// ----------------------------

double weight6 = getGrainWeight(5, g);

if (g > 5)
{
    if (!v.schedActive6)
    {
        v.schedActive6 = true;
        v.schedPhase6 = 0.0;
        v.schedStart6 = basePos6;
    }

    double grainPitchMul6 = 1.0;

    if (pitchState == 0)
    {
        double spread = pitchSpread * spreadNorm;
        grainPitchMul6 += spread * Math.sin(5.11);
    }
    else
    {
        double harmonicTarget = 6.0;
        grainPitchMul6 = 1.0 + (harmonicTarget - 1.0) * pitchSpread;
    }

    double phaseInc6 = v.delta * grainPitchMul6 * dir;

    v.schedPhase6 += phaseInc6 * (1.0);

    if (v.schedPhase6 >= grainSize)
    {
        v.schedPhase6 -= grainSize;
        v.schedStart6 = basePos6;
    }

    if (v.schedPhase6 < 0.0)
    {
        v.schedPhase6 += grainSize;
        v.schedStart6 = basePos6;
    }

    double pos6 = v.schedStart6 + v.schedPhase6;

    if (pos6 < 0.0) pos6 = 0.0;
    if (pos6 >= audioData.numSamples - 1.0)
        pos6 = audioData.numSamples - 2.0;

    int i6 = (int)pos6;
    double f6 = pos6 - i6;

    double w6 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase6 / grainSize));
    w6 = Math.pow(w6, exponent1);

    double monoL6 = (1.0 - f6) * sample[0][i6] + f6 * sample[0][i6+1];
    double monoR6 = (1.0 - f6) * sample[1][i6] + f6 * sample[1][i6+1];

    double normPan6 = ((5.0 - center) * invDenom);
    double pan6 = panSpread * normPan6 * 2.0;

    Lsum += monoL6 * w6 * (0.5 * (1.0 - pan6)) * weight6;
    Rsum += monoR6 * w6 * (0.5 * (1.0 + pan6)) * weight6;
}

// ----------------------------
// GRAIN 7
// ----------------------------

double weight7 = getGrainWeight(6, g);

if (g > 6)
{
    if (!v.schedActive7)
    {
        v.schedActive7 = true;
        v.schedPhase7 = 0.0;
        v.schedStart7 = basePos7;
    }

    double grainPitchMul7 = 1.0;

    if (pitchState == 0)
    {
        double spread = pitchSpread * spreadNorm;
        grainPitchMul7 += spread * Math.sin(6.41);
    }
    else
    {
        double harmonicTarget = 7.0;
        grainPitchMul7 = 1.0 + (harmonicTarget - 1.0) * pitchSpread;
    }

    double phaseInc7 = v.delta * grainPitchMul7 * dir;

    v.schedPhase7 += phaseInc7 * (1.0);

    if (v.schedPhase7 >= grainSize)
    {
        v.schedPhase7 -= grainSize;
        v.schedStart7 = basePos7;
    }

    if (v.schedPhase7 < 0.0)
    {
        v.schedPhase7 += grainSize;
        v.schedStart7 = basePos7;
    }

    double pos7 = v.schedStart7 + v.schedPhase7;

    if (pos7 < 0.0) pos7 = 0.0;
    if (pos7 >= audioData.numSamples - 1.0)
        pos7 = audioData.numSamples - 2.0;

    int i7 = (int)pos7;
    double f7 = pos7 - i7;

    double w7 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase7 / grainSize));
    w7 = Math.pow(w7, exponent1);

    double monoL7 = (1.0 - f7) * sample[0][i7] + f7 * sample[0][i7+1];
    double monoR7 = (1.0 - f7) * sample[1][i7] + f7 * sample[1][i7+1];

    double normPan7 = ((6.0 - center) * invDenom);
    double pan7 = panSpread * normPan7 * 2.0;

    Lsum += monoL7 * w7 * (0.5 * (1.0 - pan7)) * weight7;
    Rsum += monoR7 * w7 * (0.5 * (1.0 + pan7)) * weight7;
}

// ----------------------------
// GRAIN 8
// 

double weight8 = getGrainWeight(7, g);

if (g > 7)
{
    if (!v.schedActive8)
    {
        v.schedActive8 = true;
        v.schedPhase8 = 0.0;
        v.schedStart8 = basePos8;
    }

    double grainPitchMul8 = 1.0;

    if (pitchState == 0)
    {
        double spread = pitchSpread * spreadNorm;
        grainPitchMul8 += spread * Math.sin(7.73);
    }
    else
    {
        double harmonicTarget = 8.0;
        grainPitchMul8 = 1.0 + (harmonicTarget - 1.0) * pitchSpread;
    }

    double phaseInc8 = v.delta * grainPitchMul8 * dir;

    v.schedPhase8 += phaseInc8 * (1.0);

    if (v.schedPhase8 >= grainSize)
    {
        v.schedPhase8 -= grainSize;
        v.schedStart8 = basePos8;
    }

    if (v.schedPhase8 < 0.0)
    {
        v.schedPhase8 += grainSize;
        v.schedStart8 = basePos8;
    }

    double pos8 = v.schedStart8 + v.schedPhase8;

    if (pos8 < 0.0) pos8 = 0.0;
    if (pos8 >= audioData.numSamples - 1.0)
        pos8 = audioData.numSamples - 2.0;

    int i8 = (int)pos8;
    double f8 = pos8 - i8;

    double w8 = 0.5 - 0.5 * Math.cos(2.0 * Math.PI * (v.schedPhase8 / grainSize));
    w8 = Math.pow(w8, exponent1);

    double monoL8 = (1.0 - f8) * sample[0][i8] + f8 * sample[0][i8+1];
    double monoR8 = (1.0 - f8) * sample[1][i8] + f8 * sample[1][i8+1];

    double normPan8 = ((7.0 - center) * invDenom);
    double pan8 = panSpread * normPan8 * 2.0;

    Lsum += monoL8 * w8 * (0.5 * (1.0 - pan8)) * weight8;
    Rsum += monoR8 * w8 * (0.5 * (1.0 + pan8)) * weight8;
}

// ----------------------------
// RMS NORMALISATION (SAFE SNEX VERSION)
// ----------------------------

double rmsNorm = 1.0;
if (g > 1)
    rmsNorm = 1.0 / Math.sqrt((double)g);

Lsum *= rmsNorm;
Rsum *= rmsNorm;

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
    reset();
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
                   for (auto& voice : voiceData)
                       updateDelta(voice);
               }
         if (P == 7)
                      {
                          if (v < 0.0) v = 0.0;
                          if (v > 1.0) v = 1.0;
                          pitchSpread = v;
                      }     
     
// 16 — maxGrains (1–8)
if (P == 8)
{
    if (v < 1.0) v = 1.0;
    if (v > 8.0) v = 8.0;
    maxGrains = v;
}

// 17 — scrubMode (0 or 1)
if (P == 9)
{
    if (v < 0.0) v = 0.0;
    if (v > 1.0) v = 1.0;
    scrubMode = v;
}

// 18 — scrubBlend (0–1)
if (P == 10)
{
    if (v < 0.0) v = 0.0;
    if (v > 1.0) v = 1.0;
    scrubBlend = v;
}

// 19 — reverse (0–1 toggle)
if (P == 11)
{
    if (v < 0.0) v = 0.0;
    if (v > 1.0) v = 1.0;
    reverse = v;
}
// jitter (0–1)
if (P == 12)
{
    if (v < 0.0) v = 0.0;
    if (v > 1.0) v = 1.0;
    jitter = v;
}
if (P == 13) scrubB = v;
if (P == 14) scrubC = v;
if (P == 15) scrubD = v;
                       
    }
};
