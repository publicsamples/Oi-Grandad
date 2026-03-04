#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace specTest_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, tempo_sync_t<NV>>, 
                                     ramp_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using fix8_block_t = container::chain<parameter::empty, 
                                      wrap::fix<2, modchain_t<NV>>>;

template <int NV>
using frame2_block_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, fix8_block_t<NV>>>;

template <int NV>
using frame2_block_t = wrap::frame<2, frame2_block_t_<NV>>;
template <int NV>
struct granular_player_stepquant_density_hybrid: public data::base
{
	SNEX_NODE(granular_player_stepquant_density_hybrid);
	static const int NUM_CHANNELS = 2;
	static const int MAX_GRAINS   = 32;
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
	double densityMorphSmoothed = 0.0;
	double maxGrains = 4.0;     // 1–32
	double scrubMode = 0.0;     // 0 = normal, 1 = xfade
	double scrubBlend = 0.0;    // 0–1 shaping
	double reverse = 0.0;   // 0 = forward, 1 = reverse
	double phaseScatter = 0.0;   // raw sample-domain scatter amount
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
		double schedPhase17 = 0.0;
		double schedStart17 = 0.0;
		bool   schedActive17 = false;
		double schedPhase18 = 0.0;
		double schedStart18 = 0.0;
		bool   schedActive18 = false;
		double schedPhase19 = 0.0;
		double schedStart19 = 0.0;
		bool   schedActive19 = false;
		double schedPhase20 = 0.0;
		double schedStart20 = 0.0;
		bool   schedActive20 = false;
		double schedPhase21 = 0.0;
		double schedStart21 = 0.0;
		bool   schedActive21 = false;
		double schedPhase22 = 0.0;
		double schedStart22 = 0.0;
		bool   schedActive22 = false;
		double schedPhase23 = 0.0;
		double schedStart23 = 0.0;
		bool   schedActive23 = false;
		double schedPhase24 = 0.0;
		double schedStart24 = 0.0;
		bool   schedActive24 = false;
		double schedPhase25 = 0.0;
		double schedStart25 = 0.0;
		bool   schedActive25 = false;
		double schedPhase26 = 0.0;
		double schedStart26 = 0.0;
		bool   schedActive26 = false;
		double schedPhase27 = 0.0;
		double schedStart27 = 0.0;
		bool   schedActive27 = false;
		double schedPhase28 = 0.0;
		double schedStart28 = 0.0;
		bool   schedActive28 = false;
		double schedPhase29 = 0.0;
		double schedStart29 = 0.0;
		bool   schedActive29 = false;
		double schedPhase30 = 0.0;
		double schedStart30 = 0.0;
		bool   schedActive30 = false;
		double schedPhase31 = 0.0;
		double schedStart31 = 0.0;
		bool   schedActive31 = false;
		double schedPhase32 = 0.0;
		double schedStart32 = 0.0;
		bool   schedActive32 = false;
		// Output diffusion state (allpass, per voice)
		double ap1L = 0.0;
		double ap1R = 0.0;
		double ap2L = 0.0;
		double ap2R = 0.0;
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
			schedPhase17 = 0.0;
			schedStart17 = 0.0;
			schedActive17 = false;
			schedPhase18 = 0.0;
			schedStart18 = 0.0;
			schedActive18 = false;
			schedPhase19 = 0.0;
			schedStart19 = 0.0;
			schedActive19 = false;
			schedPhase20 = 0.0;
			schedStart20 = 0.0;
			schedActive20 = false;
			schedPhase21 = 0.0;
			schedStart21 = 0.0;
			schedActive21 = false;
			schedPhase22 = 0.0;
			schedStart22 = 0.0;
			schedActive22 = false;
			schedPhase23 = 0.0;
			schedStart23 = 0.0;
			schedActive23 = false;
			schedPhase24 = 0.0;
			schedStart24 = 0.0;
			schedActive24 = false;
			schedPhase25 = 0.0;
			schedStart25 = 0.0;
			schedActive25 = false;
			schedPhase26 = 0.0;
			schedStart26 = 0.0;
			schedActive26 = false;
			schedPhase27 = 0.0;
			schedStart27 = 0.0;
			schedActive27 = false;
			schedPhase28 = 0.0;
			schedStart28 = 0.0;
			schedActive28 = false;
			schedPhase29 = 0.0;
			schedStart29 = 0.0;
			schedActive29 = false;
			schedPhase30 = 0.0;
			schedStart30 = 0.0;
			schedActive30 = false;
			schedPhase31 = 0.0;
			schedStart31 = 0.0;
			schedActive31 = false;
			schedPhase32 = 0.0;
			schedStart32 = 0.0;
			schedActive32 = false;
			ap1L = 0.0;
			ap1R = 0.0;
			ap2L = 0.0;
			ap2R = 0.0;
		}
	};   // ← absolutely required
	PolyData<VoiceData, NV> voiceData;
	// -----------------------------------------------------
	void prepare(PrepareSpecs ps)
	{
		sr = ps.sampleRate;
		voiceData.prepare(ps);
		densityMorphSmoothed = density;
		if (densityMorphSmoothed < 0.0) densityMorphSmoothed = 0.0;
			if (densityMorphSmoothed > 1.0) densityMorphSmoothed = 1.0;
		}
	void reset()
	{
		for (auto& v : voiceData)
			v.reset();
		densityMorphSmoothed = density;
		if (densityMorphSmoothed < 0.0) densityMorphSmoothed = 0.0;
			if (densityMorphSmoothed > 1.0) densityMorphSmoothed = 1.0;
		}
	inline double getTailPhase(const VoiceData& v, int i)
	{
		if (i == 16) return v.schedPhase17;
			if (i == 17) return v.schedPhase18;
			if (i == 18) return v.schedPhase19;
			if (i == 19) return v.schedPhase20;
			if (i == 20) return v.schedPhase21;
			if (i == 21) return v.schedPhase22;
			if (i == 22) return v.schedPhase23;
			if (i == 23) return v.schedPhase24;
			if (i == 24) return v.schedPhase25;
			if (i == 25) return v.schedPhase26;
			if (i == 26) return v.schedPhase27;
			if (i == 27) return v.schedPhase28;
			if (i == 28) return v.schedPhase29;
			if (i == 29) return v.schedPhase30;
			if (i == 30) return v.schedPhase31;
			return v.schedPhase32;
	}
	inline void setTailPhase(VoiceData& v, int i, double x)
	{
		if (i == 16) v.schedPhase17 = x;
			else if (i == 17) v.schedPhase18 = x;
			else if (i == 18) v.schedPhase19 = x;
			else if (i == 19) v.schedPhase20 = x;
			else if (i == 20) v.schedPhase21 = x;
			else if (i == 21) v.schedPhase22 = x;
			else if (i == 22) v.schedPhase23 = x;
			else if (i == 23) v.schedPhase24 = x;
			else if (i == 24) v.schedPhase25 = x;
			else if (i == 25) v.schedPhase26 = x;
			else if (i == 26) v.schedPhase27 = x;
			else if (i == 27) v.schedPhase28 = x;
			else if (i == 28) v.schedPhase29 = x;
			else if (i == 29) v.schedPhase30 = x;
			else if (i == 30) v.schedPhase31 = x;
			else v.schedPhase32 = x;
		}
	inline double getTailStart(const VoiceData& v, int i)
	{
		if (i == 16) return v.schedStart17;
			if (i == 17) return v.schedStart18;
			if (i == 18) return v.schedStart19;
			if (i == 19) return v.schedStart20;
			if (i == 20) return v.schedStart21;
			if (i == 21) return v.schedStart22;
			if (i == 22) return v.schedStart23;
			if (i == 23) return v.schedStart24;
			if (i == 24) return v.schedStart25;
			if (i == 25) return v.schedStart26;
			if (i == 26) return v.schedStart27;
			if (i == 27) return v.schedStart28;
			if (i == 28) return v.schedStart29;
			if (i == 29) return v.schedStart30;
			if (i == 30) return v.schedStart31;
			return v.schedStart32;
	}
	inline void setTailStart(VoiceData& v, int i, double x)
	{
		if (i == 16) v.schedStart17 = x;
			else if (i == 17) v.schedStart18 = x;
			else if (i == 18) v.schedStart19 = x;
			else if (i == 19) v.schedStart20 = x;
			else if (i == 20) v.schedStart21 = x;
			else if (i == 21) v.schedStart22 = x;
			else if (i == 22) v.schedStart23 = x;
			else if (i == 23) v.schedStart24 = x;
			else if (i == 24) v.schedStart25 = x;
			else if (i == 25) v.schedStart26 = x;
			else if (i == 26) v.schedStart27 = x;
			else if (i == 27) v.schedStart28 = x;
			else if (i == 28) v.schedStart29 = x;
			else if (i == 29) v.schedStart30 = x;
			else if (i == 30) v.schedStart31 = x;
			else v.schedStart32 = x;
		}
	inline bool getTailActive(const VoiceData& v, int i)
	{
		if (i == 16) return v.schedActive17;
			if (i == 17) return v.schedActive18;
			if (i == 18) return v.schedActive19;
			if (i == 19) return v.schedActive20;
			if (i == 20) return v.schedActive21;
			if (i == 21) return v.schedActive22;
			if (i == 22) return v.schedActive23;
			if (i == 23) return v.schedActive24;
			if (i == 24) return v.schedActive25;
			if (i == 25) return v.schedActive26;
			if (i == 26) return v.schedActive27;
			if (i == 27) return v.schedActive28;
			if (i == 28) return v.schedActive29;
			if (i == 29) return v.schedActive30;
			if (i == 30) return v.schedActive31;
			return v.schedActive32;
	}
	inline void setTailActive(VoiceData& v, int i, bool x)
	{
		if (i == 16) v.schedActive17 = x;
			else if (i == 17) v.schedActive18 = x;
			else if (i == 18) v.schedActive19 = x;
			else if (i == 19) v.schedActive20 = x;
			else if (i == 20) v.schedActive21 = x;
			else if (i == 21) v.schedActive22 = x;
			else if (i == 22) v.schedActive23 = x;
			else if (i == 23) v.schedActive24 = x;
			else if (i == 24) v.schedActive25 = x;
			else if (i == 25) v.schedActive26 = x;
			else if (i == 26) v.schedActive27 = x;
			else if (i == 27) v.schedActive28 = x;
			else if (i == 28) v.schedActive29 = x;
			else if (i == 29) v.schedActive30 = x;
			else if (i == 30) v.schedActive31 = x;
			else v.schedActive32 = x;
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
	inline double wrap01(double x)
	{
		x = x - Math.floor(x);
		if (x < 0.0) x += 1.0;
			return x;
	}
	// Deterministic per-grain envelope phase offset (in cycles).
	// phaseScatter is interpreted in samples and converted to cycles by grainSize.
	inline double phaseScatterOffset(int grainIndex, double scrubVal)
	{
		if (phaseScatter <= 0.0)
			return 0.0;
		double seed = (double)(grainIndex + 1) * 37.17 + scrubVal * 19.73;
		double r = Math.sin(seed * 12.9898 + 78.233); // -1..1
		double scatterSamples = r * phaseScatter;
		double maxScatterCycles = (grainSize > 1.0) ? (scatterSamples / grainSize) : 0.0;
		return maxScatterCycles;
	}
	// Deterministic per-grain read-start offset (in samples).
	// Uses the same raw sample-domain control as phase scatter.
	inline double phaseScatterStartOffsetSamples(int grainIndex, double scrubVal, double maxStart)
	{
		if (phaseScatter <= 0.0)
			return 0.0;
		double seed = (double)(grainIndex + 1) * 37.17 + scrubVal * 19.73;
		double r = Math.sin(seed * 12.9898 + 78.233); // -1..1
		double maxScatterSamples = phaseScatter;
		if (maxScatterSamples > maxStart)
			maxScatterSamples = maxStart;
		return r * maxScatterSamples;
	}
	// Envelope phase staggering per grain (driven by phaseScatter only).
	inline double cloudWindowPhase(double phaseNorm, int grainIndex)
	{
		double scatter = phaseScatterOffset(grainIndex, scrub);
		return wrap01(phaseNorm + scatter);
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
	// -----------------------------------------------------
	void processInternal(span<float, NUM_CHANNELS>& fd, VoiceData& v)
	{
		double maxStart = (double)audioData.numSamples - grainSize - 2.0;
		if (maxStart <= 0.0)
			maxStart = 0.0;
		double scrubSmoothed = scrub;
		// ----------------------------
		// SCRUB MODE
		// 0 = normal
		// 1 = multi-scrub
		// 2 = normal (fallback)
		// 3 = multi-scrub (fallback)
		// ----------------------------
		int scrubState = 0;
		// 0 = normal
		// 1 = multi-scrub
		// 2 = normal (fallback)
		// 3 = multi-scrub (fallback)
		if (scrubMode < 0.25)
			scrubState = 0;
		else if (scrubMode < 0.50)
			scrubState = 1;
		else if (scrubMode < 0.75)
			scrubState = 0;
		else
			scrubState = 1;
		v.scrubQ = scrub;
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
			int gActive = g;
		bool isStackMode = (scrubBlend < 0.5);
		// =========================================================
		// 16-GRAIN NORMALISATION  (APPLY BEFORE MIXING)
		// =========================================================
		// Compute all raw weights now
		// ===============================================
		// SNEX-SAFE 16-GRAIN NORMALISATION
		// ===============================================
		// Raw, unnormalised weights
		double w_raw1  = getGrainWeight(0,  gActive, isStackMode);
		double w_raw2  = getGrainWeight(1,  gActive, isStackMode);
		double w_raw3  = getGrainWeight(2,  gActive, isStackMode);
		double w_raw4  = getGrainWeight(3,  gActive, isStackMode);
		double w_raw5  = getGrainWeight(4,  gActive, isStackMode);
		double w_raw6  = getGrainWeight(5,  gActive, isStackMode);
		double w_raw7  = getGrainWeight(6,  gActive, isStackMode);
		double w_raw8  = getGrainWeight(7,  gActive, isStackMode);
		double w_raw9  = getGrainWeight(8,  gActive, isStackMode);
		double w_raw10 = getGrainWeight(9,  gActive, isStackMode);
		double w_raw11 = getGrainWeight(10, gActive, isStackMode);
		double w_raw12 = getGrainWeight(11, gActive, isStackMode);
		double w_raw13 = getGrainWeight(12, gActive, isStackMode);
		double w_raw14 = getGrainWeight(13, gActive, isStackMode);
		double w_raw15 = getGrainWeight(14, gActive, isStackMode);
		double w_raw16 = getGrainWeight(15, gActive, isStackMode);
		// -----------------------------------------------
		// CONSTANT-POWER GRAIN NORMALISATION (16 grains)
		// -----------------------------------------------
		// Sum of squared weights
		double sumsq =
		w_raw1*w_raw1 + w_raw2*w_raw2 + w_raw3*w_raw3 + w_raw4*w_raw4 +
		w_raw5*w_raw5 + w_raw6*w_raw6 + w_raw7*w_raw7 + w_raw8*w_raw8 +
		w_raw9*w_raw9 + w_raw10*w_raw10 + w_raw11*w_raw11 + w_raw12*w_raw12 +
		w_raw13*w_raw13 + w_raw14*w_raw14 + w_raw15*w_raw15 + w_raw16*w_raw16;
		if (isStackMode && gActive > 16)
		{
			for (int i = 16; i < gActive; ++i)
			{
				double wt = getGrainWeight(i, gActive, true);
				sumsq += wt * wt;
			}
		}
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
		double center = (double)(gActive - 1) * 0.5;
		double invDenom = (gActive > 1) ? 1.0 / (double)(gActive - 1) : 0.0;
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
		// phaseScatter-driven read-start spread (joint with envelope phase scatter).
		basePos1  += phaseScatterStartOffsetSamples(0,  scrub, maxStart);
		basePos2  += phaseScatterStartOffsetSamples(1,  scrub, maxStart);
		basePos3  += phaseScatterStartOffsetSamples(2,  scrub, maxStart);
		basePos4  += phaseScatterStartOffsetSamples(3,  scrub, maxStart);
		basePos5  += phaseScatterStartOffsetSamples(4,  scrub, maxStart);
		basePos6  += phaseScatterStartOffsetSamples(5,  scrub, maxStart);
		basePos7  += phaseScatterStartOffsetSamples(6,  scrub, maxStart);
		basePos8  += phaseScatterStartOffsetSamples(7,  scrub, maxStart);
		basePos9  += phaseScatterStartOffsetSamples(8,  scrub, maxStart);
		basePos10 += phaseScatterStartOffsetSamples(9,  scrub, maxStart);
		basePos11 += phaseScatterStartOffsetSamples(10, scrub, maxStart);
		basePos12 += phaseScatterStartOffsetSamples(11, scrub, maxStart);
		basePos13 += phaseScatterStartOffsetSamples(12, scrub, maxStart);
		basePos14 += phaseScatterStartOffsetSamples(13, scrub, maxStart);
		basePos15 += phaseScatterStartOffsetSamples(14, scrub, maxStart);
		basePos16 += phaseScatterStartOffsetSamples(15, scrub, maxStart);
		// --- Morph calculation (shared by all grains) ---
		int baseIndex = 0;
		double frac = 0.0;
		double densityMorphTarget = clamp01(density);
		double morphAlpha = 0.01;
		if (sr > 1.0)
		{
			double tauSec = 0.01; // ~10 ms smoothing
			morphAlpha = 1.0 - Math.exp(-1.0 / (tauSec * sr));
		}
		densityMorphSmoothed += (densityMorphTarget - densityMorphSmoothed) * morphAlpha;
		if (scrubBlend > 0.5)
		{
			double pos = densityMorphSmoothed * (double)(gActive - 1);
			if (pos < 0.0) pos = 0.0;
				if (pos > (double)(gActive - 1)) pos = (double)(gActive - 1);
				baseIndex = (int)Math.floor(pos);
			frac = pos - (double)baseIndex;
		}
		// Apply morph gains directly to raw grain weights so all later
		// per-grain weight assignments inherit the same blend behavior.
		if (!isStackMode)
		{
			int idxA = baseIndex;
			int idxB = baseIndex + 1;
			if (idxA < 0) idxA = 0;
				if (idxA > gActive - 1) idxA = gActive - 1;
				if (idxB > gActive - 1) idxB = gActive - 1;
				// Equal-power blend between adjacent active grains.
			double t = clamp01(frac);
			double gA = Math.cos(0.5 * Math.PI * t);
			double gB = Math.sin(0.5 * Math.PI * t);
			if (gActive <= 1)
			{
				idxA = 0;
				idxB = 0;
				gA = 1.0;
				gB = 0.0;
			}
			double m1  = ((idxA == 0)  ? gA : 0.0) + ((idxB == 0)  ? gB : 0.0);
			double m2  = ((idxA == 1)  ? gA : 0.0) + ((idxB == 1)  ? gB : 0.0);
			double m3  = ((idxA == 2)  ? gA : 0.0) + ((idxB == 2)  ? gB : 0.0);
			double m4  = ((idxA == 3)  ? gA : 0.0) + ((idxB == 3)  ? gB : 0.0);
			double m5  = ((idxA == 4)  ? gA : 0.0) + ((idxB == 4)  ? gB : 0.0);
			double m6  = ((idxA == 5)  ? gA : 0.0) + ((idxB == 5)  ? gB : 0.0);
			double m7  = ((idxA == 6)  ? gA : 0.0) + ((idxB == 6)  ? gB : 0.0);
			double m8  = ((idxA == 7)  ? gA : 0.0) + ((idxB == 7)  ? gB : 0.0);
			double m9  = ((idxA == 8)  ? gA : 0.0) + ((idxB == 8)  ? gB : 0.0);
			double m10 = ((idxA == 9)  ? gA : 0.0) + ((idxB == 9)  ? gB : 0.0);
			double m11 = ((idxA == 10) ? gA : 0.0) + ((idxB == 10) ? gB : 0.0);
			double m12 = ((idxA == 11) ? gA : 0.0) + ((idxB == 11) ? gB : 0.0);
			double m13 = ((idxA == 12) ? gA : 0.0) + ((idxB == 12) ? gB : 0.0);
			double m14 = ((idxA == 13) ? gA : 0.0) + ((idxB == 13) ? gB : 0.0);
			double m15 = ((idxA == 14) ? gA : 0.0) + ((idxB == 14) ? gB : 0.0);
			double m16 = ((idxA == 15) ? gA : 0.0) + ((idxB == 15) ? gB : 0.0);
			w_raw1  *= m1;
			w_raw2  *= m2;
			w_raw3  *= m3;
			w_raw4  *= m4;
			w_raw5  *= m5;
			w_raw6  *= m6;
			w_raw7  *= m7;
			w_raw8  *= m8;
			w_raw9  *= m9;
			w_raw10 *= m10;
			w_raw11 *= m11;
			w_raw12 *= m12;
			w_raw13 *= m13;
			w_raw14 *= m14;
			w_raw15 *= m15;
			w_raw16 *= m16;
		}
		// Keep density dedicated to grain weighting/crossfade; don't let it modulate pitch spread.
		double spreadNorm = 1.0;
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
		// Additional rendered grains 17..32
		if (gActive > 16)
		{
			for (int i = 16; i < gActive; ++i)
			{
				double weightNRaw = getGrainWeight(i, gActive, isStackMode);
				if (!isStackMode)
				{
					int idxA = baseIndex;
					int idxB = baseIndex + 1;
					if (idxA < 0) idxA = 0;
						if (idxA > gActive - 1) idxA = gActive - 1;
						if (idxB > gActive - 1) idxB = gActive - 1;
						double t = clamp01(frac);
					double gA = Math.cos(0.5 * Math.PI * t);
					double gB = Math.sin(0.5 * Math.PI * t);
					double mN = ((idxA == i) ? gA : 0.0) + ((idxB == i) ? gB : 0.0);
					weightNRaw *= mN;
				}
				double weightN = weightNRaw * wnorm;
				if (weightN <= 0.0)
					continue;
				double baseN = scrubBase;
				if (scrubState == 1)
				{
					int bank = i % 8;
					if (bank < 2) baseN = scrub * maxStart;
						else if (bank < 4) baseN = scrubB * maxStart;
						else if (bank < 6) baseN = scrubC * maxStart;
						else baseN = scrubD * maxStart;
					}
				baseN += phaseScatterStartOffsetSamples(i, scrub, maxStart);
				bool activeN = getTailActive(v, i);
				double phaseN = getTailPhase(v, i);
				double startN = getTailStart(v, i);
				if (!activeN)
				{
					activeN = true;
					phaseN = 0.0;
					startN = baseN;
				}
				double detuneSeedN = 0.77 + (double)(i + 1) * 1.31;
				double harmonicTargetN = (double)(i + 1);
				double grainPitchMulN = getPitchModeMul(pitchState, spreadNorm, detuneSeedN, harmonicTargetN);
				double phaseIncN = v.delta * grainPitchMulN * dir;
				phaseN += phaseIncN;
				if (phaseN >= grainSize)
				{
					phaseN -= grainSize;
					if (lockStartOnWrap)
						startN = baseN;
				}
				if (phaseN < 0.0)
				{
					phaseN += grainSize;
					if (lockStartOnWrap)
						startN = baseN;
				}
				double posN = startN + phaseN;
				if (posN < 0.0) posN = 0.0;
					if (posN >= audioData.numSamples - 1.0)
					posN = audioData.numSamples - 2.0;
				int iN = (int)posN;
				double fN = posN - (double)iN;
				double wN = morphedWindow(cloudWindowPhase(phaseN / grainSize, i));
				double monoLN = (1.0 - fN) * sample[0][iN] + fN * sample[0][iN + 1];
				double monoRN = (1.0 - fN) * sample[1][iN] + fN * sample[1][iN + 1];
				double normPanN = (((double)i - center) * invDenom);
				double panN = panSpread * normPanN * 2.0;
				Lsum += monoLN * wN * (0.5 * (1.0 - panN)) * weightN;
				Rsum += monoRN * wN * (0.5 * (1.0 + panN)) * weightN;
				setTailActive(v, i, activeN);
				setTailPhase(v, i, phaseN);
				setTailStart(v, i, startN);
			}
		}
		// ----------------------------
		// RMS NORMALISATION (SAFE SNEX VERSION)
		// ----------------------------
		double rmsNorm = 1.0;
		if (isStackMode && gActive > 1)
			rmsNorm = 1.0 / Math.sqrt((double)gActive);
		Lsum *= rmsNorm;
		Rsum *= rmsNorm;
		// Write mixed grain output to the current stereo frame.
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
	}
	void processFrame(span<float, NUM_CHANNELS>& fd)
	{
		if (audioData.numSamples == 0)
			return;
		auto& v = voiceData.get();
		processInternal(fd, v);
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
			// Keep normalized spread for modes 0/1.
			double norm = v;
			if (norm < 0.0) norm = 0.0;
				if (norm > 1.0) norm = 1.0;
				pitchSpread = norm;
			// Keep raw input for mode 2 sync lock (Hz or ms).
			pitchSyncInput = v;
		}
		// 16 — maxGrains (1–32)
		if (P == 8)
		{
			if (v < 1.0) v = 1.0;
				if (v > (double)MAX_GRAINS) v = (double)MAX_GRAINS;
				maxGrains = v;
		}
		// 17 — scrubMode (0..1 mapped to 4 menu slots / 2 behaviours)
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
		// phaseScatter (raw samples)
		if (P == 12)
		{
			if (v < 0.0) v = 0.0;
				phaseScatter = v;
		}
		if (P == 13) scrubB = v;
			if (P == 14) scrubC = v;
			if (P == 15) scrubD = v;
		}
};

struct snex_node1_t_data: public data::embedded::multichannel_data
{
	// Metadata functions for embedded data --------------------------------------------------------
	
	int    getNumSamples()     const override { return 1310953; }
	double getSamplerate()     const override { return 48000.; }
	int    getNumChannels()    const override { return 1; }
	const float* getChannelData(int index) override
	{
		if(index == 0) { return reinterpret_cast<const float*>(audiodata::specTest_impl_snex_node1_t_data0); }
		jassertfalse;    return nullptr;
	};
};

template <int NV>
using snex_node1_t = wrap::data<granular_player_stepquant_density_hybrid<NV>, 
                                data::embedded::audiofile<snex_node1_t_data>>;

template <int NV>
using specTest_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, frame2_block_t<NV>>, 
                                     snex_node1_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public specTest_impl::specTest_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(specTest);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(2)
		{
			0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& frame2_block = this->getT(0);                       // specTest_impl::frame2_block_t<NV>
		auto& fix8_block = this->getT(0).getT(0);                 // specTest_impl::fix8_block_t<NV>
		auto& modchain = this->getT(0).getT(0).getT(0);           // specTest_impl::modchain_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(0).getT(0); // specTest_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(0).getT(0).getT(0).getT(1);       // specTest_impl::ramp_t<NV>
		auto& snex_node1 = this->getT(1);                         // specTest_impl::snex_node1_t<NV>
		
		// Modulation Connections ------------------------------------------------------------------
		
		tempo_sync.getParameter().connectT(0, ramp); // tempo_sync -> ramp::PeriodTime
		
		// Default Values --------------------------------------------------------------------------
		
		tempo_sync.setParameterT(0, 0.);   // control::tempo_sync::Tempo
		tempo_sync.setParameterT(1, 4.);   // control::tempo_sync::Multiplier
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		snex_node1.setParameterT(0, 0.);   // core::snex_node::pitch
		snex_node1.setParameterT(1, 0.);   // core::snex_node::scrub
		snex_node1.setParameterT(2, 261.); // core::snex_node::grainMs
		snex_node1.setParameterT(3, 0.);   // core::snex_node::density
		snex_node1.setParameterT(4, 0.);   // core::snex_node::windowShape
		snex_node1.setParameterT(5, 0.);   // core::snex_node::panSpread
		snex_node1.setParameterT(6, 0.);   // core::snex_node::pitchMode
		snex_node1.setParameterT(7, 0.);   // core::snex_node::pitchSpread
		snex_node1.setParameterT(8, 0.);   // core::snex_node::maxGrains
		snex_node1.setParameterT(9, 0.);   // core::snex_node::scrubMode
		snex_node1.setParameterT(10, 0.);  // core::snex_node::scrubBlend
		snex_node1.setParameterT(11, 0.);  // core::snex_node::reverse
		snex_node1.setParameterT(12, 0.);  // core::snex_node::windowType
		snex_node1.setParameterT(13, 0.);  // core::snex_node::scrubB
		snex_node1.setParameterT(14, 0.);  // core::snex_node::scrubC
		snex_node1.setParameterT(15, 0.);  // core::snex_node::scrubD
		
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(1).setExternalData(b, index); // specTest_impl::ramp_t<NV>
		this->getT(1).setExternalData(b, index);                         // specTest_impl::snex_node1_t<NV>
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using specTest = wrap::node<specTest_impl::instance<NV>>;
}


