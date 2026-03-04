#pragma once

#include "res2.h"
#include "res2.h"
#include "res2.h"
#include "res2.h"
#include "res2.h"
#include "res2.h"
#include "res2.h"
#include "res2.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace sn_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable_t_index = runtime_target::indexers::fix_hash<1120565314>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable_t<NV>>, 
                                  math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<1120565315>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<1120565316>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t<NV>>, 
                                  math::add<NV>>;
using global_cable14_t_index = runtime_target::indexers::fix_hash<1120565317>;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>>;
using global_cable13_t_index = runtime_target::indexers::fix_hash<1120565318>;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>>;
using global_cable12_t_index = runtime_target::indexers::fix_hash<1120565319>;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<1120565320>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<1120565321>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>>;
using global_cable9_t_index = runtime_target::indexers::fix_hash<1120565322>;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable9_t<NV>>, 
                                   math::add<NV>>;
using global_cable8_t_index = runtime_target::indexers::fix_hash<377786414>;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable8_t<NV>>, 
                                  math::add<NV>>;
using global_cable7_t_index = runtime_target::indexers::fix_hash<377786415>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable7_t<NV>>, 
                                  math::add<NV>>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<377786416>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable6_t<NV>>, 
                                  math::add<NV>>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<377786417>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable5_t<NV>>, 
                                  math::add<NV>>;
using global_cable4_t_index = runtime_target::indexers::fix_hash<377786418>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable4_t<NV>>, 
                                  math::add<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<377786419>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable3_t<NV>>, 
                                  math::add<NV>>;
using global_cable45_t_index = runtime_target::indexers::fix_hash<377786420>;

template <int NV>
using global_cable45_t = routing::global_cable<global_cable45_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable45_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain1_t<NV>>, 
                                   chain3_t<NV>, 
                                   chain2_t<NV>, 
                                   chain15_t<NV>, 
                                   chain14_t<NV>, 
                                   chain13_t<NV>, 
                                   chain12_t<NV>, 
                                   chain11_t<NV>, 
                                   chain10_t<NV>, 
                                   chain9_t<NV>, 
                                   chain8_t<NV>, 
                                   chain7_t<NV>, 
                                   chain6_t<NV>, 
                                   chain5_t<NV>, 
                                   chain4_t<NV>, 
                                   chain48_t<NV>>;

using cable_table_t = wrap::data<control::cable_table<parameter::empty>, 
                                 data::external::table<0>>;
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
	double pitchSyncInput = 0.0; // raw external input for mode 2 (Hz/ms) or mode 3 (formant semis)
	double pitchMode = 0.0;
	double formantRatioSmoothed = 1.0;
	double maxGrains = 4.0;     // 1–32
	double scrubMode = 0.0;     // 0 = normal, 1 = xfade
	double scrubBlend = 0.0;    // 0–1 shaping
	double directionMode = 0.0;   // 3-way menu packed into 0..1
	double phaseScatter = 0.0;   // startSpraySamples (raw sample-domain amount)
	// Subtle density-linked grain start spread. Tweak this to taste.
	// Final spread in samples = maxStart * densityPositionSpreadRange * density.
	const double densityPositionSpreadRange = 0.3;
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
		formantRatioSmoothed = 1.0;
		}
	void reset()
	{
		for (auto& v : voiceData)
			v.reset();
		formantRatioSmoothed = 1.0;
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
	// 0.0 = Hann
	// 1.0 = Tukey with a wide flat centre / short taper
	inline double morphedWindow(double phaseNorm)
	{
		double x = clamp01(phaseNorm);
		double shape = clamp01(windowShape);
		double alpha = 1.0 - shape;
		return tukey(x, alpha);
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
	inline double grainRandom01(int grainIndex)
	{
		double seed = (double)(grainIndex + 1) * 57.31 + 91.73;
		double r = Math.sin(seed * 12.9898 + 78.233);
		return 0.5 + 0.5 * r;
	}
	inline double startSprayOffsetSamples(int grainIndex, double maxStart)
	{
		if (phaseScatter <= 0.0 || maxStart <= 0.0)
			return 0.0;
		double maxSpray = phaseScatter;
		double hardLimit = maxStart * 0.95;
		if (maxSpray > hardLimit)
			maxSpray = hardLimit;
		double r = grainRandom01(grainIndex) * 2.0 - 1.0; // -1..1
		return r * maxSpray;
	}
	inline double panOrderIndex(int grainIndex, int grainCount)
	{
		if (grainCount <= 1)
			return 0.0;
		int pairIndex = (int)Math.floor((double)grainIndex * 0.5);
		int twicePair = pairIndex + pairIndex;
		if (grainIndex == twicePair)
			return (double)pairIndex;
		return (double)(grainCount - 1 - pairIndex);
	}
	inline double getDirectionSign(int directionState, int grainIndex)
	{
		double negOne = 0.0 - 1.0;
		if (directionState == 0)
			return 1.0;
		if (directionState == 1)
			return negOne;
		bool invert = false;
		if (grainIndex == 1) invert = true;
			if (grainIndex == 3) invert = true;
			if (grainIndex == 5) invert = true;
			if (grainIndex == 7) invert = true;
			if (grainIndex == 9) invert = true;
			if (grainIndex == 11) invert = true;
			if (grainIndex == 13) invert = true;
			if (grainIndex == 15) invert = true;
			if (grainIndex == 17) invert = true;
			if (grainIndex == 19) invert = true;
			if (grainIndex == 21) invert = true;
			if (grainIndex == 23) invert = true;
			if (grainIndex == 25) invert = true;
			if (grainIndex == 27) invert = true;
			if (grainIndex == 29) invert = true;
			if (grainIndex == 31) invert = true;
			if (invert)
			return negOne;
		return 1.0;
	}
	// Envelope phase path (phaseScatter removed for now).
	inline double cloudWindowPhase(double phaseNorm, int grainIndex)
	{
		return wrap01(phaseNorm);
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
		else if (pitchState == 2)
		{
			// Mode 2: tempo-sync lock (raw external input via pitchSpread parameter).
			return tempoSyncRatioFromInput(pitchSyncInput);
		}
		// Mode 3: formant ratio drives window-rate path;
		// read-phase applies inverse + nonlinear warp to keep pitch centered.
		return formantRatioSmoothed;
	}
	inline double getFormantTargetRatio()
	{
		double semis = pitchSyncInput;
		if (semis >= 0.0 && semis <= 1.0)
			semis = semis * 48.0 - 24.0;
		if (semis < -24.0) semis = -24.0;
			if (semis > 24.0) semis = 24.0;
			double ratio = Math.pow(2.0, semis / 12.0);
		if (ratio < 0.25) ratio = 0.25;
			if (ratio > 4.0) ratio = 4.0;
			return ratio;
	}
	inline double getReadPhaseForMode(double phase, int pitchState, double pitchMul)
	{
		if (pitchState != 3)
			return phase;
		double ratio = pitchMul;
		if (ratio < 0.25) ratio = 0.25;
			if (ratio > 4.0) ratio = 4.0;
			double c = 0.5 * grainSize;
		// Linear inverse to keep base pitch roughly constant.
		double lin = c + (phase - c) / ratio;
		// Nonlinear phase warp to produce audible formant colour.
		// This keeps endpoints stable and focuses shaping near the grain centre.
		double x = (phase / grainSize) - 0.5; // -0.5..0.5
		double shape = x * (1.0 - 4.0 * x * x); // zero at edges, max near centre
		double amt = Math.log(ratio) / Math.log(2.0); // ~ -2..+2 across 0.25..4
		if (amt < -2.0) amt = -2.0;
			if (amt > 2.0)  amt = 2.0;
			amt *= 0.5; // normalize to ~ -1..1
		double warpSamples = amt * shape * grainSize * 0.9;
		double warped = lin + warpSamples;
		if (warped < 0.0) warped = 0.0;
			if (warped > grainSize - 1.0) warped = grainSize - 1.0;
			return warped;
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
		int baseOn = 4;
		if (baseOn > grainCount)
			baseOn = grainCount;
		if (i < baseOn)
			return 1.0;
		double d = clamp01(density);
		double coverage = (double)baseOn + d * (double)grainCount;
		if (coverage > (double)grainCount)
			coverage = (double)grainCount;
		double edge = coverage - (double)i;
		if (edge <= 0.0)
			return 0.0;
		if (edge >= 1.0)
			return 1.0;
		return smooth01(edge);
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
		// 0 = normal scrub + varispeed-time
		// 1 = multi-scrub + varispeed-time
		// 2 = normal scrub + time-invariant
		// 3 = multi-scrub + time-invariant
		// ----------------------------
		int scrubState = 0;
		bool timeInvariant = false;
		// 0 = normal scrub + varispeed-time
		// 1 = multi-scrub + varispeed-time
		// 2 = normal scrub + time-invariant
		// 3 = multi-scrub + time-invariant
		if (scrubMode < 0.25)
		{
			scrubState = 0;
			timeInvariant = false;
		}
		else if (scrubMode < 0.50)
		{
			scrubState = 1;
			timeInvariant = false;
		}
		else if (scrubMode < 0.75)
		{
			scrubState = 0;
			timeInvariant = true;
		}
		else
		{
			scrubState = 1;
			timeInvariant = true;
		}
		v.scrubQ = scrub;
		double scrubBase = scrubSmoothed * maxStart;
		int pitchState = 0;
		// 0 = detune (track MIDI)
		// 1 = harmonic (track MIDI)
		// 2 = tempo-sync lock (track MIDI + semitone, sync ratio from pitchSpread)
		// 3 = formant shift (pitchSpread input mapped to -24..+24 semitones)
		if (pitchMode < 0.25)
			pitchState = 0;
		else if (pitchMode < 0.50)
			pitchState = 1;
		else if (pitchMode < 0.75)
			pitchState = 2;
		else
			pitchState = 3;
		// Smooth formant ratio to avoid zipper / clicks when moving control.
		double formantTarget = getFormantTargetRatio();
		double smoothCoeff = 1.0;
		if (sr > 0.0)
		{
			// ~15ms smoothing
			smoothCoeff = 1.0 - Math.exp(-1.0 / (0.015 * sr));
		}
		formantRatioSmoothed += (formantTarget - formantRatioSmoothed) * smoothCoeff;
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
			int densitySlots = g;
		bool isStackMode = (scrubBlend < 0.5);
		// =========================================================
		// 16-GRAIN NORMALISATION  (APPLY BEFORE MIXING)
		// =========================================================
		// Compute all raw weights now
		// ===============================================
		// SNEX-SAFE 16-GRAIN NORMALISATION
		// ===============================================
		// Raw, unnormalised weights
		double w_raw1  = getGrainWeight(0,  densitySlots, isStackMode);
		double w_raw2  = getGrainWeight(1,  densitySlots, isStackMode);
		double w_raw3  = getGrainWeight(2,  densitySlots, isStackMode);
		double w_raw4  = getGrainWeight(3,  densitySlots, isStackMode);
		double w_raw5  = getGrainWeight(4,  densitySlots, isStackMode);
		double w_raw6  = getGrainWeight(5,  densitySlots, isStackMode);
		double w_raw7  = getGrainWeight(6,  densitySlots, isStackMode);
		double w_raw8  = getGrainWeight(7,  densitySlots, isStackMode);
		double w_raw9  = getGrainWeight(8,  densitySlots, isStackMode);
		double w_raw10 = getGrainWeight(9,  densitySlots, isStackMode);
		double w_raw11 = getGrainWeight(10, densitySlots, isStackMode);
		double w_raw12 = getGrainWeight(11, densitySlots, isStackMode);
		double w_raw13 = getGrainWeight(12, densitySlots, isStackMode);
		double w_raw14 = getGrainWeight(13, densitySlots, isStackMode);
		double w_raw15 = getGrainWeight(14, densitySlots, isStackMode);
		double w_raw16 = getGrainWeight(15, densitySlots, isStackMode);
		// -----------------------------------------------
		// CONSTANT-POWER GRAIN NORMALISATION (16 grains)
		// -----------------------------------------------
		// Sum of squared weights
		double sumsq =
		w_raw1*w_raw1 + w_raw2*w_raw2 + w_raw3*w_raw3 + w_raw4*w_raw4 +
		w_raw5*w_raw5 + w_raw6*w_raw6 + w_raw7*w_raw7 + w_raw8*w_raw8 +
		w_raw9*w_raw9 + w_raw10*w_raw10 + w_raw11*w_raw11 + w_raw12*w_raw12 +
		w_raw13*w_raw13 + w_raw14*w_raw14 + w_raw15*w_raw15 + w_raw16*w_raw16;
		if (isStackMode && g > 16)
		{
			for (int i = 16; i < g; ++i)
			{
				double wt = getGrainWeight(i, densitySlots, true);
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
		double center = (double)(g - 1) * 0.5;
		double invDenom = (g > 1) ? 1.0 / (double)(g - 1) : 0.0;
		double panSlot1  = panOrderIndex(0,  g);
		double panSlot2  = panOrderIndex(1,  g);
		double panSlot3  = panOrderIndex(2,  g);
		double panSlot4  = panOrderIndex(3,  g);
		double panSlot5  = panOrderIndex(4,  g);
		double panSlot6  = panOrderIndex(5,  g);
		double panSlot7  = panOrderIndex(6,  g);
		double panSlot8  = panOrderIndex(7,  g);
		double panSlot9  = panOrderIndex(8,  g);
		double panSlot10 = panOrderIndex(9,  g);
		double panSlot11 = panOrderIndex(10, g);
		double panSlot12 = panOrderIndex(11, g);
		double panSlot13 = panOrderIndex(12, g);
		double panSlot14 = panOrderIndex(13, g);
		double panSlot15 = panOrderIndex(14, g);
		double panSlot16 = panOrderIndex(15, g);
		if (scrubState == 1)
		{
			if (isStackMode)
			{
				// Legacy grouped mapping in stack mode.
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
				double denomMorph = (g > 1) ? (double)(g - 1) : 1.0;
				double t1 = 0.0 / denomMorph;
				double t2 = 1.0 / denomMorph;
				double t3 = 2.0 / denomMorph;
				double t4 = 3.0 / denomMorph;
				double t5 = 4.0 / denomMorph;
				double t6 = 5.0 / denomMorph;
				double t7 = 6.0 / denomMorph;
				double t8 = 7.0 / denomMorph;
				double t9 = 8.0 / denomMorph;
				double t10 = 9.0 / denomMorph;
				double t11 = 10.0 / denomMorph;
				double t12 = 11.0 / denomMorph;
				double t13 = 12.0 / denomMorph;
				double t14 = 13.0 / denomMorph;
				double t15 = 14.0 / denomMorph;
				double t16 = 15.0 / denomMorph;
				double scrubM1 = scrub;
				if (t1 <= (1.0 / 3.0)) scrubM1 = scrub + (scrubB - scrub) * (t1 * 3.0);
					else if (t1 <= (2.0 / 3.0)) scrubM1 = scrubB + (scrubC - scrubB) * ((t1 - (1.0 / 3.0)) * 3.0);
					else scrubM1 = scrubC + (scrubD - scrubC) * ((t1 - (2.0 / 3.0)) * 3.0);
					scrubM1 = quantiseScrub(scrubM1, audioData); if (scrubM1 < 0.0) scrubM1 += 1.0; if (scrubM1 > 1.0) scrubM1 -= 1.0; basePos1 = scrubM1 * maxStart;
				double scrubM2 = scrub;
				if (t2 <= (1.0 / 3.0)) scrubM2 = scrub + (scrubB - scrub) * (t2 * 3.0);
					else if (t2 <= (2.0 / 3.0)) scrubM2 = scrubB + (scrubC - scrubB) * ((t2 - (1.0 / 3.0)) * 3.0);
					else scrubM2 = scrubC + (scrubD - scrubC) * ((t2 - (2.0 / 3.0)) * 3.0);
					scrubM2 = quantiseScrub(scrubM2, audioData); if (scrubM2 < 0.0) scrubM2 += 1.0; if (scrubM2 > 1.0) scrubM2 -= 1.0; basePos2 = scrubM2 * maxStart;
				double scrubM3 = scrub;
				if (t3 <= (1.0 / 3.0)) scrubM3 = scrub + (scrubB - scrub) * (t3 * 3.0);
					else if (t3 <= (2.0 / 3.0)) scrubM3 = scrubB + (scrubC - scrubB) * ((t3 - (1.0 / 3.0)) * 3.0);
					else scrubM3 = scrubC + (scrubD - scrubC) * ((t3 - (2.0 / 3.0)) * 3.0);
					scrubM3 = quantiseScrub(scrubM3, audioData); if (scrubM3 < 0.0) scrubM3 += 1.0; if (scrubM3 > 1.0) scrubM3 -= 1.0; basePos3 = scrubM3 * maxStart;
				double scrubM4 = scrub;
				if (t4 <= (1.0 / 3.0)) scrubM4 = scrub + (scrubB - scrub) * (t4 * 3.0);
					else if (t4 <= (2.0 / 3.0)) scrubM4 = scrubB + (scrubC - scrubB) * ((t4 - (1.0 / 3.0)) * 3.0);
					else scrubM4 = scrubC + (scrubD - scrubC) * ((t4 - (2.0 / 3.0)) * 3.0);
					scrubM4 = quantiseScrub(scrubM4, audioData); if (scrubM4 < 0.0) scrubM4 += 1.0; if (scrubM4 > 1.0) scrubM4 -= 1.0; basePos4 = scrubM4 * maxStart;
				double scrubM5 = scrub;
				if (t5 <= (1.0 / 3.0)) scrubM5 = scrub + (scrubB - scrub) * (t5 * 3.0);
					else if (t5 <= (2.0 / 3.0)) scrubM5 = scrubB + (scrubC - scrubB) * ((t5 - (1.0 / 3.0)) * 3.0);
					else scrubM5 = scrubC + (scrubD - scrubC) * ((t5 - (2.0 / 3.0)) * 3.0);
					scrubM5 = quantiseScrub(scrubM5, audioData); if (scrubM5 < 0.0) scrubM5 += 1.0; if (scrubM5 > 1.0) scrubM5 -= 1.0; basePos5 = scrubM5 * maxStart;
				double scrubM6 = scrub;
				if (t6 <= (1.0 / 3.0)) scrubM6 = scrub + (scrubB - scrub) * (t6 * 3.0);
					else if (t6 <= (2.0 / 3.0)) scrubM6 = scrubB + (scrubC - scrubB) * ((t6 - (1.0 / 3.0)) * 3.0);
					else scrubM6 = scrubC + (scrubD - scrubC) * ((t6 - (2.0 / 3.0)) * 3.0);
					scrubM6 = quantiseScrub(scrubM6, audioData); if (scrubM6 < 0.0) scrubM6 += 1.0; if (scrubM6 > 1.0) scrubM6 -= 1.0; basePos6 = scrubM6 * maxStart;
				double scrubM7 = scrub;
				if (t7 <= (1.0 / 3.0)) scrubM7 = scrub + (scrubB - scrub) * (t7 * 3.0);
					else if (t7 <= (2.0 / 3.0)) scrubM7 = scrubB + (scrubC - scrubB) * ((t7 - (1.0 / 3.0)) * 3.0);
					else scrubM7 = scrubC + (scrubD - scrubC) * ((t7 - (2.0 / 3.0)) * 3.0);
					scrubM7 = quantiseScrub(scrubM7, audioData); if (scrubM7 < 0.0) scrubM7 += 1.0; if (scrubM7 > 1.0) scrubM7 -= 1.0; basePos7 = scrubM7 * maxStart;
				double scrubM8 = scrub;
				if (t8 <= (1.0 / 3.0)) scrubM8 = scrub + (scrubB - scrub) * (t8 * 3.0);
					else if (t8 <= (2.0 / 3.0)) scrubM8 = scrubB + (scrubC - scrubB) * ((t8 - (1.0 / 3.0)) * 3.0);
					else scrubM8 = scrubC + (scrubD - scrubC) * ((t8 - (2.0 / 3.0)) * 3.0);
					scrubM8 = quantiseScrub(scrubM8, audioData); if (scrubM8 < 0.0) scrubM8 += 1.0; if (scrubM8 > 1.0) scrubM8 -= 1.0; basePos8 = scrubM8 * maxStart;
				double scrubM9 = scrub;
				if (t9 <= (1.0 / 3.0)) scrubM9 = scrub + (scrubB - scrub) * (t9 * 3.0);
					else if (t9 <= (2.0 / 3.0)) scrubM9 = scrubB + (scrubC - scrubB) * ((t9 - (1.0 / 3.0)) * 3.0);
					else scrubM9 = scrubC + (scrubD - scrubC) * ((t9 - (2.0 / 3.0)) * 3.0);
					scrubM9 = quantiseScrub(scrubM9, audioData); if (scrubM9 < 0.0) scrubM9 += 1.0; if (scrubM9 > 1.0) scrubM9 -= 1.0; basePos9 = scrubM9 * maxStart;
				double scrubM10 = scrub;
				if (t10 <= (1.0 / 3.0)) scrubM10 = scrub + (scrubB - scrub) * (t10 * 3.0);
					else if (t10 <= (2.0 / 3.0)) scrubM10 = scrubB + (scrubC - scrubB) * ((t10 - (1.0 / 3.0)) * 3.0);
					else scrubM10 = scrubC + (scrubD - scrubC) * ((t10 - (2.0 / 3.0)) * 3.0);
					scrubM10 = quantiseScrub(scrubM10, audioData); if (scrubM10 < 0.0) scrubM10 += 1.0; if (scrubM10 > 1.0) scrubM10 -= 1.0; basePos10 = scrubM10 * maxStart;
				double scrubM11 = scrub;
				if (t11 <= (1.0 / 3.0)) scrubM11 = scrub + (scrubB - scrub) * (t11 * 3.0);
					else if (t11 <= (2.0 / 3.0)) scrubM11 = scrubB + (scrubC - scrubB) * ((t11 - (1.0 / 3.0)) * 3.0);
					else scrubM11 = scrubC + (scrubD - scrubC) * ((t11 - (2.0 / 3.0)) * 3.0);
					scrubM11 = quantiseScrub(scrubM11, audioData); if (scrubM11 < 0.0) scrubM11 += 1.0; if (scrubM11 > 1.0) scrubM11 -= 1.0; basePos11 = scrubM11 * maxStart;
				double scrubM12 = scrub;
				if (t12 <= (1.0 / 3.0)) scrubM12 = scrub + (scrubB - scrub) * (t12 * 3.0);
					else if (t12 <= (2.0 / 3.0)) scrubM12 = scrubB + (scrubC - scrubB) * ((t12 - (1.0 / 3.0)) * 3.0);
					else scrubM12 = scrubC + (scrubD - scrubC) * ((t12 - (2.0 / 3.0)) * 3.0);
					scrubM12 = quantiseScrub(scrubM12, audioData); if (scrubM12 < 0.0) scrubM12 += 1.0; if (scrubM12 > 1.0) scrubM12 -= 1.0; basePos12 = scrubM12 * maxStart;
				double scrubM13 = scrub;
				if (t13 <= (1.0 / 3.0)) scrubM13 = scrub + (scrubB - scrub) * (t13 * 3.0);
					else if (t13 <= (2.0 / 3.0)) scrubM13 = scrubB + (scrubC - scrubB) * ((t13 - (1.0 / 3.0)) * 3.0);
					else scrubM13 = scrubC + (scrubD - scrubC) * ((t13 - (2.0 / 3.0)) * 3.0);
					scrubM13 = quantiseScrub(scrubM13, audioData); if (scrubM13 < 0.0) scrubM13 += 1.0; if (scrubM13 > 1.0) scrubM13 -= 1.0; basePos13 = scrubM13 * maxStart;
				double scrubM14 = scrub;
				if (t14 <= (1.0 / 3.0)) scrubM14 = scrub + (scrubB - scrub) * (t14 * 3.0);
					else if (t14 <= (2.0 / 3.0)) scrubM14 = scrubB + (scrubC - scrubB) * ((t14 - (1.0 / 3.0)) * 3.0);
					else scrubM14 = scrubC + (scrubD - scrubC) * ((t14 - (2.0 / 3.0)) * 3.0);
					scrubM14 = quantiseScrub(scrubM14, audioData); if (scrubM14 < 0.0) scrubM14 += 1.0; if (scrubM14 > 1.0) scrubM14 -= 1.0; basePos14 = scrubM14 * maxStart;
				double scrubM15 = scrub;
				if (t15 <= (1.0 / 3.0)) scrubM15 = scrub + (scrubB - scrub) * (t15 * 3.0);
					else if (t15 <= (2.0 / 3.0)) scrubM15 = scrubB + (scrubC - scrubB) * ((t15 - (1.0 / 3.0)) * 3.0);
					else scrubM15 = scrubC + (scrubD - scrubC) * ((t15 - (2.0 / 3.0)) * 3.0);
					scrubM15 = quantiseScrub(scrubM15, audioData); if (scrubM15 < 0.0) scrubM15 += 1.0; if (scrubM15 > 1.0) scrubM15 -= 1.0; basePos15 = scrubM15 * maxStart;
				double scrubM16 = scrub;
				if (t16 <= (1.0 / 3.0)) scrubM16 = scrub + (scrubB - scrub) * (t16 * 3.0);
					else if (t16 <= (2.0 / 3.0)) scrubM16 = scrubB + (scrubC - scrubB) * ((t16 - (1.0 / 3.0)) * 3.0);
					else scrubM16 = scrubC + (scrubD - scrubC) * ((t16 - (2.0 / 3.0)) * 3.0);
					scrubM16 = quantiseScrub(scrubM16, audioData); if (scrubM16 < 0.0) scrubM16 += 1.0; if (scrubM16 > 1.0) scrubM16 -= 1.0; basePos16 = scrubM16 * maxStart;
			}
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
		// startSpraySamples: per-grain read-start offset in raw samples.
		basePos1  += startSprayOffsetSamples(0,  maxStart);
		basePos2  += startSprayOffsetSamples(1,  maxStart);
		basePos3  += startSprayOffsetSamples(2,  maxStart);
		basePos4  += startSprayOffsetSamples(3,  maxStart);
		basePos5  += startSprayOffsetSamples(4,  maxStart);
		basePos6  += startSprayOffsetSamples(5,  maxStart);
		basePos7  += startSprayOffsetSamples(6,  maxStart);
		basePos8  += startSprayOffsetSamples(7,  maxStart);
		basePos9  += startSprayOffsetSamples(8,  maxStart);
		basePos10 += startSprayOffsetSamples(9,  maxStart);
		basePos11 += startSprayOffsetSamples(10, maxStart);
		basePos12 += startSprayOffsetSamples(11, maxStart);
		basePos13 += startSprayOffsetSamples(12, maxStart);
		basePos14 += startSprayOffsetSamples(13, maxStart);
		basePos15 += startSprayOffsetSamples(14, maxStart);
		basePos16 += startSprayOffsetSamples(15, maxStart);
		// (Spray mode removed)
		// --- Morph calculation (shared by all grains) ---
		int baseIndex = 0;
		double frac = 0.0;
		if (scrubBlend > 0.5)
		{
			double pos = density * (double)(g - 1);
			if (pos < 0.0) pos = 0.0;
				if (pos > (double)(g - 1)) pos = (double)(g - 1);
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
				if (idxA > g - 1) idxA = g - 1;
				if (idxB > g - 1) idxB = g - 1;
				// Equal-power blend between adjacent active grains.
			double t = clamp01(frac);
			double gA = Math.cos(0.5 * Math.PI * t);
			double gB = Math.sin(0.5 * Math.PI * t);
			if (g <= 1)
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
		double spreadNorm = isStackMode ? 1.0 : density;
		double Lsum = 0.0;
		double Rsum = 0.0;
		int directionState = 0;
		if (directionMode < (1.0 / 3.0))
			directionState = 0;
		else if (directionMode < (2.0 / 3.0))
			directionState = 1;
		else
			directionState = 2;
		double dir = 1.0;
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
		dir = getDirectionSign(directionState, 0);
		double phaseInc1 = timeInvariant ? dir : (v.delta * grainPitchMul1 * dir);
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
		double pos1 = v.schedStart + getReadPhaseForMode((timeInvariant ? (v.schedPhase * (v.delta * grainPitchMul1)) : v.schedPhase), pitchState, grainPitchMul1);
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
		double normPan1 = ((panSlot1 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 1);
		double phaseInc2 = timeInvariant ? dir : (v.delta * grainPitchMul2 * dir);
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
		double pos2 = v.schedStart2 + getReadPhaseForMode((timeInvariant ? (v.schedPhase2 * (v.delta * grainPitchMul2)) : v.schedPhase2), pitchState, grainPitchMul2);
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
		double normPan2 = ((panSlot2 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 2);
		double phaseInc3 = timeInvariant ? dir : (v.delta * grainPitchMul3 * dir);
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
		double pos3 = v.schedStart3 + getReadPhaseForMode((timeInvariant ? (v.schedPhase3 * (v.delta * grainPitchMul3)) : v.schedPhase3), pitchState, grainPitchMul3);
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
		double normPan3 = ((panSlot3 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 3);
		double phaseInc4 = timeInvariant ? dir : (v.delta * grainPitchMul4 * dir);
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
		double pos4 = v.schedStart4 + getReadPhaseForMode((timeInvariant ? (v.schedPhase4 * (v.delta * grainPitchMul4)) : v.schedPhase4), pitchState, grainPitchMul4);
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
		double normPan4 = ((panSlot4 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 4);
		double phaseInc5 = timeInvariant ? dir : (v.delta * grainPitchMul5 * dir);
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
		double pos5 = v.schedStart5 + getReadPhaseForMode((timeInvariant ? (v.schedPhase5 * (v.delta * grainPitchMul5)) : v.schedPhase5), pitchState, grainPitchMul5);
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
		double normPan5 = ((panSlot5 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 5);
		double phaseInc6 = timeInvariant ? dir : (v.delta * grainPitchMul6 * dir);
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
		double pos6 = v.schedStart6 + getReadPhaseForMode((timeInvariant ? (v.schedPhase6 * (v.delta * grainPitchMul6)) : v.schedPhase6), pitchState, grainPitchMul6);
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
		double normPan6 = ((panSlot6 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 6);
		double phaseInc7 = timeInvariant ? dir : (v.delta * grainPitchMul7 * dir);
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
		double pos7 = v.schedStart7 + getReadPhaseForMode((timeInvariant ? (v.schedPhase7 * (v.delta * grainPitchMul7)) : v.schedPhase7), pitchState, grainPitchMul7);
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
		double normPan7 = ((panSlot7 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 7);
		double phaseInc8 = timeInvariant ? dir : (v.delta * grainPitchMul8 * dir);
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
		double pos8 = v.schedStart8 + getReadPhaseForMode((timeInvariant ? (v.schedPhase8 * (v.delta * grainPitchMul8)) : v.schedPhase8), pitchState, grainPitchMul8);
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
		double normPan8 = ((panSlot8 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 8);
		double phaseInc9 = timeInvariant ? dir : (v.delta * grainPitchMul9 * dir);
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
		double pos9 = v.schedStart9 + getReadPhaseForMode((timeInvariant ? (v.schedPhase9 * (v.delta * grainPitchMul9)) : v.schedPhase9), pitchState, grainPitchMul9);
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
		double normPan9 = ((panSlot9 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 9);
		double phaseInc10 = timeInvariant ? dir : (v.delta * grainPitchMul10 * dir);
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
		double pos10 = v.schedStart10 + getReadPhaseForMode((timeInvariant ? (v.schedPhase10 * (v.delta * grainPitchMul10)) : v.schedPhase10), pitchState, grainPitchMul10);
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
		double normPan10 = ((panSlot10 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 10);
		double phaseInc11 = timeInvariant ? dir : (v.delta * grainPitchMul11 * dir);
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
		double pos11 = v.schedStart11 + getReadPhaseForMode((timeInvariant ? (v.schedPhase11 * (v.delta * grainPitchMul11)) : v.schedPhase11), pitchState, grainPitchMul11);
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
		double normPan11 = ((panSlot11 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 11);
		double phaseInc12 = timeInvariant ? dir : (v.delta * grainPitchMul12 * dir);
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
		double pos12 = v.schedStart12 + getReadPhaseForMode((timeInvariant ? (v.schedPhase12 * (v.delta * grainPitchMul12)) : v.schedPhase12), pitchState, grainPitchMul12);
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
		double normPan12 = ((panSlot12 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 12);
		double phaseInc13 = timeInvariant ? dir : (v.delta * grainPitchMul13 * dir);
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
		double pos13 = v.schedStart13 + getReadPhaseForMode((timeInvariant ? (v.schedPhase13 * (v.delta * grainPitchMul13)) : v.schedPhase13), pitchState, grainPitchMul13);
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
		double normPan13 = ((panSlot13 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 13);
		double phaseInc14 = timeInvariant ? dir : (v.delta * grainPitchMul14 * dir);
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
		double pos14 = v.schedStart14 + getReadPhaseForMode((timeInvariant ? (v.schedPhase14 * (v.delta * grainPitchMul14)) : v.schedPhase14), pitchState, grainPitchMul14);
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
		double normPan14 = ((panSlot14 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 14);
		double phaseInc15 = timeInvariant ? dir : (v.delta * grainPitchMul15 * dir);
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
		double pos15 = v.schedStart15 + getReadPhaseForMode((timeInvariant ? (v.schedPhase15 * (v.delta * grainPitchMul15)) : v.schedPhase15), pitchState, grainPitchMul15);
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
		double normPan15 = ((panSlot15 - center) * invDenom);
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
		dir = getDirectionSign(directionState, 15);
		double phaseInc16 = timeInvariant ? dir : (v.delta * grainPitchMul16 * dir);
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
		double pos16 = v.schedStart16 + getReadPhaseForMode((timeInvariant ? (v.schedPhase16 * (v.delta * grainPitchMul16)) : v.schedPhase16), pitchState, grainPitchMul16);
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
		double normPan16 = ((panSlot16 - center) * invDenom);
		double pan16 = panSpread * normPan16 * 2.0;
		Lsum += monoL16 * w16 * (0.5 * (1.0 - pan16)) * weight16;
		Rsum += monoR16 * w16 * (0.5 * (1.0 + pan16)) * weight16;
		// Additional rendered grains 17..32
		if (g > 16)
		{
			for (int i = 16; i < g; ++i)
			{
				double weightNRaw = getGrainWeight(i, g, false);
				if (isStackMode)
					weightNRaw = getGrainWeight(i, densitySlots, true);
				if (!isStackMode)
				{
					int idxA = baseIndex;
					int idxB = baseIndex + 1;
					if (idxA < 0) idxA = 0;
						if (idxA > g - 1) idxA = g - 1;
						if (idxB > g - 1) idxB = g - 1;
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
					double tN = (g > 1) ? ((double)i / (double)(g - 1)) : 0.0;
					double scrubN = scrub;
					if (tN <= (1.0 / 3.0))
					{
						double u = tN * 3.0;
						scrubN = scrub + (scrubB - scrub) * u;
					}
					else if (tN <= (2.0 / 3.0))
					{
						double u = (tN - (1.0 / 3.0)) * 3.0;
						scrubN = scrubB + (scrubC - scrubB) * u;
					}
					else
					{
						double u = (tN - (2.0 / 3.0)) * 3.0;
						scrubN = scrubC + (scrubD - scrubC) * u;
					}
					scrubN = quantiseScrub(scrubN, audioData);
					if (scrubN < 0.0) scrubN += 1.0;
						if (scrubN > 1.0) scrubN -= 1.0;
						baseN = scrubN * maxStart;
				}
				if (isStackMode)
				{
					double denomN = (g > 1) ? (double)(g - 1) : 1.0;
					double idxNormN = (double)i / denomN;
					double amtN = maxStart * densityPositionSpreadRange * clamp01(density);
					baseN += A2curve(idxNormN) * amtN;
				}
				baseN += startSprayOffsetSamples(i, maxStart);
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
				double dirN = getDirectionSign(directionState, i);
				double phaseIncN = timeInvariant ? dirN : (v.delta * grainPitchMulN * dirN);
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
				double posN = startN + getReadPhaseForMode((timeInvariant ? (phaseN * (v.delta * grainPitchMulN)) : phaseN), pitchState, grainPitchMulN);
				if (posN < 0.0) posN = 0.0;
					if (posN >= audioData.numSamples - 1.0)
					posN = audioData.numSamples - 2.0;
				int iN = (int)posN;
				double fN = posN - (double)iN;
				double wN = morphedWindow(cloudWindowPhase(phaseN / grainSize, i));
				double monoLN = (1.0 - fN) * sample[0][iN] + fN * sample[0][iN + 1];
				double monoRN = (1.0 - fN) * sample[1][iN] + fN * sample[1][iN + 1];
				double panSlotN = panOrderIndex(i, g);
				double normPanN = ((panSlotN - center) * invDenom);
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
			// Keep raw input for mode 2 sync lock (Hz or ms)
			// and mode 3 formant semitone control.
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
		// 19 — direction menu (3 slots mapped across 0..1)
		if (P == 11)
		{
			if (v < 0.0) v = 0.0;
				if (v > 1.0) v = 1.0;
				directionMode = v;
		}
		// startSpraySamples (raw samples)
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

template <int NV>
using snex_node_t = wrap::data<granular_player_stepquant_density_hybrid<NV>, 
                               data::external::audiofile<0>>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<cable_table_t, 0>, 
                                 parameter::plain<snex_node_t<NV>, 1>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, branch_t<NV>>, 
                                 peak_t<NV>, 
                                 math::clear<NV>, 
                                 pma_t<NV>, 
                                 cable_table_t>;
using global_cable46_t_index = global_cable_t_index;

template <int NV>
using global_cable46_t = routing::global_cable<global_cable46_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable46_t<NV>>, 
                                   math::add<NV>>;
using global_cable47_t_index = global_cable2_t_index;

template <int NV>
using global_cable47_t = routing::global_cable<global_cable47_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable47_t<NV>>, 
                                   math::add<NV>>;
using global_cable48_t_index = global_cable1_t_index;

template <int NV>
using global_cable48_t = routing::global_cable<global_cable48_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable48_t<NV>>, 
                                   math::add<NV>>;
using global_cable49_t_index = global_cable14_t_index;

template <int NV>
using global_cable49_t = routing::global_cable<global_cable49_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable49_t<NV>>, 
                                   math::add<NV>>;
using global_cable50_t_index = global_cable13_t_index;

template <int NV>
using global_cable50_t = routing::global_cable<global_cable50_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable50_t<NV>>, 
                                   math::add<NV>>;
using global_cable51_t_index = global_cable12_t_index;

template <int NV>
using global_cable51_t = routing::global_cable<global_cable51_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable51_t<NV>>, 
                                   math::add<NV>>;
using global_cable52_t_index = global_cable11_t_index;

template <int NV>
using global_cable52_t = routing::global_cable<global_cable52_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable52_t<NV>>, 
                                   math::add<NV>>;
using global_cable53_t_index = global_cable10_t_index;

template <int NV>
using global_cable53_t = routing::global_cable<global_cable53_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable53_t<NV>>, 
                                   math::add<NV>>;
using global_cable54_t_index = global_cable9_t_index;

template <int NV>
using global_cable54_t = routing::global_cable<global_cable54_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable54_t<NV>>, 
                                   math::add<NV>>;
using global_cable55_t_index = global_cable8_t_index;

template <int NV>
using global_cable55_t = routing::global_cable<global_cable55_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable55_t<NV>>, 
                                   math::add<NV>>;
using global_cable56_t_index = global_cable7_t_index;

template <int NV>
using global_cable56_t = routing::global_cable<global_cable56_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable56_t<NV>>, 
                                   math::add<NV>>;
using global_cable57_t_index = global_cable6_t_index;

template <int NV>
using global_cable57_t = routing::global_cable<global_cable57_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable57_t<NV>>, 
                                   math::add<NV>>;
using global_cable58_t_index = global_cable5_t_index;

template <int NV>
using global_cable58_t = routing::global_cable<global_cable58_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable58_t<NV>>, 
                                   math::add<NV>>;
using global_cable59_t_index = global_cable4_t_index;

template <int NV>
using global_cable59_t = routing::global_cable<global_cable59_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable59_t<NV>>, 
                                   math::add<NV>>;
using global_cable60_t_index = global_cable3_t_index;

template <int NV>
using global_cable60_t = routing::global_cable<global_cable60_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable60_t<NV>>, 
                                   math::add<NV>>;
using global_cable61_t_index = global_cable45_t_index;

template <int NV>
using global_cable61_t = routing::global_cable<global_cable61_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable61_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain50_t<NV>>, 
                                    chain51_t<NV>, 
                                    chain52_t<NV>, 
                                    chain53_t<NV>, 
                                    chain54_t<NV>, 
                                    chain55_t<NV>, 
                                    chain56_t<NV>, 
                                    chain57_t<NV>, 
                                    chain58_t<NV>, 
                                    chain59_t<NV>, 
                                    chain60_t<NV>, 
                                    chain61_t<NV>, 
                                    chain62_t<NV>, 
                                    chain63_t<NV>, 
                                    chain64_t<NV>, 
                                    chain65_t<NV>>;

using cable_table1_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<1>>;

template <int NV>
using pma3_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table1_t, 0>, 
                                  parameter::plain<snex_node_t<NV>, 13>>;

template <int NV>
using pma3_t = control::pma<NV, pma3_mod<NV>>;
template <int NV>
using peak3_t = wrap::mod<parameter::plain<pma3_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak3_t<NV>, 
                                   math::clear<NV>, 
                                   pma3_t<NV>, 
                                   cable_table1_t>;
using global_cable62_t_index = global_cable_t_index;

template <int NV>
using global_cable62_t = routing::global_cable<global_cable62_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable62_t<NV>>, 
                                   math::add<NV>>;
using global_cable63_t_index = global_cable2_t_index;

template <int NV>
using global_cable63_t = routing::global_cable<global_cable63_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable63_t<NV>>, 
                                   math::add<NV>>;
using global_cable64_t_index = global_cable1_t_index;

template <int NV>
using global_cable64_t = routing::global_cable<global_cable64_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable64_t<NV>>, 
                                   math::add<NV>>;
using global_cable65_t_index = global_cable14_t_index;

template <int NV>
using global_cable65_t = routing::global_cable<global_cable65_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable65_t<NV>>, 
                                   math::add<NV>>;
using global_cable66_t_index = global_cable13_t_index;

template <int NV>
using global_cable66_t = routing::global_cable<global_cable66_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable66_t<NV>>, 
                                   math::add<NV>>;
using global_cable67_t_index = global_cable12_t_index;

template <int NV>
using global_cable67_t = routing::global_cable<global_cable67_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain72_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable67_t<NV>>, 
                                   math::add<NV>>;
using global_cable68_t_index = global_cable11_t_index;

template <int NV>
using global_cable68_t = routing::global_cable<global_cable68_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable68_t<NV>>, 
                                   math::add<NV>>;
using global_cable69_t_index = global_cable10_t_index;

template <int NV>
using global_cable69_t = routing::global_cable<global_cable69_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain74_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable69_t<NV>>, 
                                   math::add<NV>>;
using global_cable70_t_index = global_cable9_t_index;

template <int NV>
using global_cable70_t = routing::global_cable<global_cable70_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain75_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable70_t<NV>>, 
                                   math::add<NV>>;
using global_cable71_t_index = global_cable8_t_index;

template <int NV>
using global_cable71_t = routing::global_cable<global_cable71_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain76_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable71_t<NV>>, 
                                   math::add<NV>>;
using global_cable72_t_index = global_cable7_t_index;

template <int NV>
using global_cable72_t = routing::global_cable<global_cable72_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain77_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable72_t<NV>>, 
                                   math::add<NV>>;
using global_cable73_t_index = global_cable6_t_index;

template <int NV>
using global_cable73_t = routing::global_cable<global_cable73_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable73_t<NV>>, 
                                   math::add<NV>>;
using global_cable74_t_index = global_cable5_t_index;

template <int NV>
using global_cable74_t = routing::global_cable<global_cable74_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable74_t<NV>>, 
                                   math::add<NV>>;
using global_cable75_t_index = global_cable4_t_index;

template <int NV>
using global_cable75_t = routing::global_cable<global_cable75_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain80_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable75_t<NV>>, 
                                   math::add<NV>>;
using global_cable76_t_index = global_cable3_t_index;

template <int NV>
using global_cable76_t = routing::global_cable<global_cable76_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain81_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable76_t<NV>>, 
                                   math::add<NV>>;
using global_cable77_t_index = global_cable45_t_index;

template <int NV>
using global_cable77_t = routing::global_cable<global_cable77_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain82_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable77_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain67_t<NV>>, 
                                    chain68_t<NV>, 
                                    chain69_t<NV>, 
                                    chain70_t<NV>, 
                                    chain71_t<NV>, 
                                    chain72_t<NV>, 
                                    chain73_t<NV>, 
                                    chain74_t<NV>, 
                                    chain75_t<NV>, 
                                    chain76_t<NV>, 
                                    chain77_t<NV>, 
                                    chain78_t<NV>, 
                                    chain79_t<NV>, 
                                    chain80_t<NV>, 
                                    chain81_t<NV>, 
                                    chain82_t<NV>>;

using cable_table2_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<2>>;

template <int NV>
using pma4_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table2_t, 0>, 
                                  parameter::plain<snex_node_t<NV>, 14>>;

template <int NV>
using pma4_t = control::pma<NV, pma4_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma4_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch4_t<NV>>, 
                                   peak4_t<NV>, 
                                   math::clear<NV>, 
                                   pma4_t<NV>, 
                                   cable_table2_t>;
using global_cable78_t_index = global_cable_t_index;

template <int NV>
using global_cable78_t = routing::global_cable<global_cable78_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain84_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable78_t<NV>>, 
                                   math::add<NV>>;
using global_cable79_t_index = global_cable2_t_index;

template <int NV>
using global_cable79_t = routing::global_cable<global_cable79_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain85_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable79_t<NV>>, 
                                   math::add<NV>>;
using global_cable80_t_index = global_cable1_t_index;

template <int NV>
using global_cable80_t = routing::global_cable<global_cable80_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain86_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable80_t<NV>>, 
                                   math::add<NV>>;
using global_cable81_t_index = global_cable14_t_index;

template <int NV>
using global_cable81_t = routing::global_cable<global_cable81_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain87_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable81_t<NV>>, 
                                   math::add<NV>>;
using global_cable82_t_index = global_cable13_t_index;

template <int NV>
using global_cable82_t = routing::global_cable<global_cable82_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain88_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable82_t<NV>>, 
                                   math::add<NV>>;
using global_cable83_t_index = global_cable12_t_index;

template <int NV>
using global_cable83_t = routing::global_cable<global_cable83_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain89_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable83_t<NV>>, 
                                   math::add<NV>>;
using global_cable84_t_index = global_cable11_t_index;

template <int NV>
using global_cable84_t = routing::global_cable<global_cable84_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable84_t<NV>>, 
                                   math::add<NV>>;
using global_cable85_t_index = global_cable10_t_index;

template <int NV>
using global_cable85_t = routing::global_cable<global_cable85_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain91_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable85_t<NV>>, 
                                   math::add<NV>>;
using global_cable86_t_index = global_cable9_t_index;

template <int NV>
using global_cable86_t = routing::global_cable<global_cable86_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain92_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable86_t<NV>>, 
                                   math::add<NV>>;
using global_cable87_t_index = global_cable8_t_index;

template <int NV>
using global_cable87_t = routing::global_cable<global_cable87_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain93_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable87_t<NV>>, 
                                   math::add<NV>>;
using global_cable88_t_index = global_cable7_t_index;

template <int NV>
using global_cable88_t = routing::global_cable<global_cable88_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain94_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable88_t<NV>>, 
                                   math::add<NV>>;
using global_cable89_t_index = global_cable6_t_index;

template <int NV>
using global_cable89_t = routing::global_cable<global_cable89_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain95_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable89_t<NV>>, 
                                   math::add<NV>>;
using global_cable90_t_index = global_cable5_t_index;

template <int NV>
using global_cable90_t = routing::global_cable<global_cable90_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain96_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable90_t<NV>>, 
                                   math::add<NV>>;
using global_cable91_t_index = global_cable4_t_index;

template <int NV>
using global_cable91_t = routing::global_cable<global_cable91_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain97_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable91_t<NV>>, 
                                   math::add<NV>>;
using global_cable92_t_index = global_cable3_t_index;

template <int NV>
using global_cable92_t = routing::global_cable<global_cable92_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain98_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable92_t<NV>>, 
                                   math::add<NV>>;
using global_cable93_t_index = global_cable45_t_index;

template <int NV>
using global_cable93_t = routing::global_cable<global_cable93_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain99_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable93_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain84_t<NV>>, 
                                    chain85_t<NV>, 
                                    chain86_t<NV>, 
                                    chain87_t<NV>, 
                                    chain88_t<NV>, 
                                    chain89_t<NV>, 
                                    chain90_t<NV>, 
                                    chain91_t<NV>, 
                                    chain92_t<NV>, 
                                    chain93_t<NV>, 
                                    chain94_t<NV>, 
                                    chain95_t<NV>, 
                                    chain96_t<NV>, 
                                    chain97_t<NV>, 
                                    chain98_t<NV>, 
                                    chain99_t<NV>>;

using cable_table3_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<3>>;

template <int NV>
using pma5_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table3_t, 0>, 
                                  parameter::plain<snex_node_t<NV>, 15>>;

template <int NV>
using pma5_t = control::pma<NV, pma5_mod<NV>>;
template <int NV>
using peak5_t = wrap::mod<parameter::plain<pma5_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   peak5_t<NV>, 
                                   math::clear<NV>, 
                                   pma5_t<NV>, 
                                   cable_table3_t>;
using global_cable94_t_index = global_cable_t_index;

template <int NV>
using global_cable94_t = routing::global_cable<global_cable94_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain101_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable94_t<NV>>, 
                                    math::add<NV>>;
using global_cable95_t_index = global_cable2_t_index;

template <int NV>
using global_cable95_t = routing::global_cable<global_cable95_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain102_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable95_t<NV>>, 
                                    math::add<NV>>;
using global_cable96_t_index = global_cable1_t_index;

template <int NV>
using global_cable96_t = routing::global_cable<global_cable96_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain103_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable96_t<NV>>, 
                                    math::add<NV>>;
using global_cable97_t_index = global_cable14_t_index;

template <int NV>
using global_cable97_t = routing::global_cable<global_cable97_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain104_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable97_t<NV>>, 
                                    math::add<NV>>;
using global_cable98_t_index = global_cable13_t_index;

template <int NV>
using global_cable98_t = routing::global_cable<global_cable98_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain105_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable98_t<NV>>, 
                                    math::add<NV>>;
using global_cable99_t_index = global_cable12_t_index;

template <int NV>
using global_cable99_t = routing::global_cable<global_cable99_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain106_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable99_t<NV>>, 
                                    math::add<NV>>;
using global_cable100_t_index = global_cable11_t_index;

template <int NV>
using global_cable100_t = routing::global_cable<global_cable100_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain107_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable100_t<NV>>, 
                                    math::add<NV>>;
using global_cable101_t_index = global_cable10_t_index;

template <int NV>
using global_cable101_t = routing::global_cable<global_cable101_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain108_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable101_t<NV>>, 
                                    math::add<NV>>;
using global_cable102_t_index = global_cable9_t_index;

template <int NV>
using global_cable102_t = routing::global_cable<global_cable102_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain109_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable102_t<NV>>, 
                                    math::add<NV>>;
using global_cable103_t_index = global_cable8_t_index;

template <int NV>
using global_cable103_t = routing::global_cable<global_cable103_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain110_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable103_t<NV>>, 
                                    math::add<NV>>;
using global_cable104_t_index = global_cable7_t_index;

template <int NV>
using global_cable104_t = routing::global_cable<global_cable104_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain111_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable104_t<NV>>, 
                                    math::add<NV>>;
using global_cable105_t_index = global_cable6_t_index;

template <int NV>
using global_cable105_t = routing::global_cable<global_cable105_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain112_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable105_t<NV>>, 
                                    math::add<NV>>;
using global_cable106_t_index = global_cable5_t_index;

template <int NV>
using global_cable106_t = routing::global_cable<global_cable106_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain113_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable106_t<NV>>, 
                                    math::add<NV>>;
using global_cable107_t_index = global_cable4_t_index;

template <int NV>
using global_cable107_t = routing::global_cable<global_cable107_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain114_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable107_t<NV>>, 
                                    math::add<NV>>;
using global_cable108_t_index = global_cable3_t_index;

template <int NV>
using global_cable108_t = routing::global_cable<global_cable108_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain115_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable108_t<NV>>, 
                                    math::add<NV>>;
using global_cable109_t_index = global_cable45_t_index;

template <int NV>
using global_cable109_t = routing::global_cable<global_cable109_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain116_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable109_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain101_t<NV>>, 
                                    chain102_t<NV>, 
                                    chain103_t<NV>, 
                                    chain104_t<NV>, 
                                    chain105_t<NV>, 
                                    chain106_t<NV>, 
                                    chain107_t<NV>, 
                                    chain108_t<NV>, 
                                    chain109_t<NV>, 
                                    chain110_t<NV>, 
                                    chain111_t<NV>, 
                                    chain112_t<NV>, 
                                    chain113_t<NV>, 
                                    chain114_t<NV>, 
                                    chain115_t<NV>, 
                                    chain116_t<NV>>;

DECLARE_PARAMETER_RANGE(pma6_modRange, 
                        -12., 
                        12.);

template <int NV>
using pma6_mod = parameter::from0To1<snex_node_t<NV>, 
                                     0, 
                                     pma6_modRange>;

template <int NV>
using pma6_t = control::pma<NV, pma6_mod<NV>>;
template <int NV>
using peak6_t = wrap::mod<parameter::plain<pma6_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain100_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch6_t<NV>>, 
                                    peak6_t<NV>, 
                                    math::clear<NV>, 
                                    pma6_t<NV>>;
using global_cable126_t_index = global_cable_t_index;

template <int NV>
using global_cable126_t = routing::global_cable<global_cable126_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain135_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable126_t<NV>>, 
                                    math::add<NV>>;
using global_cable127_t_index = global_cable2_t_index;

template <int NV>
using global_cable127_t = routing::global_cable<global_cable127_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain136_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable127_t<NV>>, 
                                    math::add<NV>>;
using global_cable128_t_index = global_cable1_t_index;

template <int NV>
using global_cable128_t = routing::global_cable<global_cable128_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain137_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable128_t<NV>>, 
                                    math::add<NV>>;
using global_cable129_t_index = global_cable14_t_index;

template <int NV>
using global_cable129_t = routing::global_cable<global_cable129_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain138_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable129_t<NV>>, 
                                    math::add<NV>>;
using global_cable130_t_index = global_cable13_t_index;

template <int NV>
using global_cable130_t = routing::global_cable<global_cable130_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain139_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable130_t<NV>>, 
                                    math::add<NV>>;
using global_cable131_t_index = global_cable12_t_index;

template <int NV>
using global_cable131_t = routing::global_cable<global_cable131_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain140_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable131_t<NV>>, 
                                    math::add<NV>>;
using global_cable132_t_index = global_cable11_t_index;

template <int NV>
using global_cable132_t = routing::global_cable<global_cable132_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain141_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable132_t<NV>>, 
                                    math::add<NV>>;
using global_cable133_t_index = global_cable10_t_index;

template <int NV>
using global_cable133_t = routing::global_cable<global_cable133_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain142_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable133_t<NV>>, 
                                    math::add<NV>>;
using global_cable134_t_index = global_cable9_t_index;

template <int NV>
using global_cable134_t = routing::global_cable<global_cable134_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain143_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable134_t<NV>>, 
                                    math::add<NV>>;
using global_cable135_t_index = global_cable8_t_index;

template <int NV>
using global_cable135_t = routing::global_cable<global_cable135_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain144_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable135_t<NV>>, 
                                    math::add<NV>>;
using global_cable136_t_index = global_cable7_t_index;

template <int NV>
using global_cable136_t = routing::global_cable<global_cable136_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain145_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable136_t<NV>>, 
                                    math::add<NV>>;
using global_cable137_t_index = global_cable6_t_index;

template <int NV>
using global_cable137_t = routing::global_cable<global_cable137_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain146_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable137_t<NV>>, 
                                    math::add<NV>>;
using global_cable138_t_index = global_cable5_t_index;

template <int NV>
using global_cable138_t = routing::global_cable<global_cable138_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain147_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable138_t<NV>>, 
                                    math::add<NV>>;
using global_cable139_t_index = global_cable4_t_index;

template <int NV>
using global_cable139_t = routing::global_cable<global_cable139_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain148_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable139_t<NV>>, 
                                    math::add<NV>>;
using global_cable140_t_index = global_cable3_t_index;

template <int NV>
using global_cable140_t = routing::global_cable<global_cable140_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain149_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable140_t<NV>>, 
                                    math::add<NV>>;
using global_cable141_t_index = global_cable45_t_index;

template <int NV>
using global_cable141_t = routing::global_cable<global_cable141_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain150_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable141_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch8_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain135_t<NV>>, 
                                    chain136_t<NV>, 
                                    chain137_t<NV>, 
                                    chain138_t<NV>, 
                                    chain139_t<NV>, 
                                    chain140_t<NV>, 
                                    chain141_t<NV>, 
                                    chain142_t<NV>, 
                                    chain143_t<NV>, 
                                    chain144_t<NV>, 
                                    chain145_t<NV>, 
                                    chain146_t<NV>, 
                                    chain147_t<NV>, 
                                    chain148_t<NV>, 
                                    chain149_t<NV>, 
                                    chain150_t<NV>>;

template <int NV>
using pma9_t = control::pma<NV, 
                            parameter::plain<snex_node_t<NV>, 3>>;
template <int NV>
using peak8_t = wrap::mod<parameter::plain<pma9_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain134_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch8_t<NV>>, 
                                    peak8_t<NV>, 
                                    math::clear<NV>, 
                                    pma9_t<NV>>;
using global_cable142_t_index = global_cable_t_index;

template <int NV>
using global_cable142_t = routing::global_cable<global_cable142_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain152_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable142_t<NV>>, 
                                    math::add<NV>>;
using global_cable143_t_index = global_cable2_t_index;

template <int NV>
using global_cable143_t = routing::global_cable<global_cable143_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain153_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable143_t<NV>>, 
                                    math::add<NV>>;
using global_cable144_t_index = global_cable1_t_index;

template <int NV>
using global_cable144_t = routing::global_cable<global_cable144_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain154_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable144_t<NV>>, 
                                    math::add<NV>>;
using global_cable145_t_index = global_cable14_t_index;

template <int NV>
using global_cable145_t = routing::global_cable<global_cable145_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain155_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable145_t<NV>>, 
                                    math::add<NV>>;
using global_cable146_t_index = global_cable13_t_index;

template <int NV>
using global_cable146_t = routing::global_cable<global_cable146_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain156_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable146_t<NV>>, 
                                    math::add<NV>>;
using global_cable147_t_index = global_cable12_t_index;

template <int NV>
using global_cable147_t = routing::global_cable<global_cable147_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain157_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable147_t<NV>>, 
                                    math::add<NV>>;
using global_cable148_t_index = global_cable11_t_index;

template <int NV>
using global_cable148_t = routing::global_cable<global_cable148_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain158_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable148_t<NV>>, 
                                    math::add<NV>>;
using global_cable149_t_index = global_cable10_t_index;

template <int NV>
using global_cable149_t = routing::global_cable<global_cable149_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain159_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable149_t<NV>>, 
                                    math::add<NV>>;
using global_cable150_t_index = global_cable9_t_index;

template <int NV>
using global_cable150_t = routing::global_cable<global_cable150_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain160_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable150_t<NV>>, 
                                    math::add<NV>>;
using global_cable151_t_index = global_cable8_t_index;

template <int NV>
using global_cable151_t = routing::global_cable<global_cable151_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain161_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable151_t<NV>>, 
                                    math::add<NV>>;
using global_cable152_t_index = global_cable7_t_index;

template <int NV>
using global_cable152_t = routing::global_cable<global_cable152_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain162_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable152_t<NV>>, 
                                    math::add<NV>>;
using global_cable153_t_index = global_cable6_t_index;

template <int NV>
using global_cable153_t = routing::global_cable<global_cable153_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain163_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable153_t<NV>>, 
                                    math::add<NV>>;
using global_cable154_t_index = global_cable5_t_index;

template <int NV>
using global_cable154_t = routing::global_cable<global_cable154_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain164_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable154_t<NV>>, 
                                    math::add<NV>>;
using global_cable155_t_index = global_cable4_t_index;

template <int NV>
using global_cable155_t = routing::global_cable<global_cable155_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain165_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable155_t<NV>>, 
                                    math::add<NV>>;
using global_cable156_t_index = global_cable3_t_index;

template <int NV>
using global_cable156_t = routing::global_cable<global_cable156_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain166_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable156_t<NV>>, 
                                    math::add<NV>>;
using global_cable157_t_index = global_cable45_t_index;

template <int NV>
using global_cable157_t = routing::global_cable<global_cable157_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain167_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable157_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch9_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain152_t<NV>>, 
                                    chain153_t<NV>, 
                                    chain154_t<NV>, 
                                    chain155_t<NV>, 
                                    chain156_t<NV>, 
                                    chain157_t<NV>, 
                                    chain158_t<NV>, 
                                    chain159_t<NV>, 
                                    chain160_t<NV>, 
                                    chain161_t<NV>, 
                                    chain162_t<NV>, 
                                    chain163_t<NV>, 
                                    chain164_t<NV>, 
                                    chain165_t<NV>, 
                                    chain166_t<NV>, 
                                    chain167_t<NV>>;

template <int NV>
using pma10_t = control::pma<NV, 
                             parameter::plain<snex_node_t<NV>, 4>>;
template <int NV>
using peak9_t = wrap::mod<parameter::plain<pma10_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain151_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch9_t<NV>>, 
                                    peak9_t<NV>, 
                                    math::clear<NV>, 
                                    pma10_t<NV>>;
using global_cable158_t_index = global_cable_t_index;

template <int NV>
using global_cable158_t = routing::global_cable<global_cable158_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain169_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable158_t<NV>>, 
                                    math::add<NV>>;
using global_cable159_t_index = global_cable2_t_index;

template <int NV>
using global_cable159_t = routing::global_cable<global_cable159_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain170_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable159_t<NV>>, 
                                    math::add<NV>>;
using global_cable160_t_index = global_cable1_t_index;

template <int NV>
using global_cable160_t = routing::global_cable<global_cable160_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain171_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable160_t<NV>>, 
                                    math::add<NV>>;
using global_cable161_t_index = global_cable14_t_index;

template <int NV>
using global_cable161_t = routing::global_cable<global_cable161_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain172_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable161_t<NV>>, 
                                    math::add<NV>>;
using global_cable162_t_index = global_cable13_t_index;

template <int NV>
using global_cable162_t = routing::global_cable<global_cable162_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain173_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable162_t<NV>>, 
                                    math::add<NV>>;
using global_cable163_t_index = global_cable12_t_index;

template <int NV>
using global_cable163_t = routing::global_cable<global_cable163_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain174_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable163_t<NV>>, 
                                    math::add<NV>>;
using global_cable164_t_index = global_cable11_t_index;

template <int NV>
using global_cable164_t = routing::global_cable<global_cable164_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain175_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable164_t<NV>>, 
                                    math::add<NV>>;
using global_cable165_t_index = global_cable10_t_index;

template <int NV>
using global_cable165_t = routing::global_cable<global_cable165_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain176_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable165_t<NV>>, 
                                    math::add<NV>>;
using global_cable166_t_index = global_cable9_t_index;

template <int NV>
using global_cable166_t = routing::global_cable<global_cable166_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain177_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable166_t<NV>>, 
                                    math::add<NV>>;
using global_cable167_t_index = global_cable8_t_index;

template <int NV>
using global_cable167_t = routing::global_cable<global_cable167_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain178_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable167_t<NV>>, 
                                    math::add<NV>>;
using global_cable168_t_index = global_cable7_t_index;

template <int NV>
using global_cable168_t = routing::global_cable<global_cable168_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain179_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable168_t<NV>>, 
                                    math::add<NV>>;
using global_cable169_t_index = global_cable6_t_index;

template <int NV>
using global_cable169_t = routing::global_cable<global_cable169_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain180_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable169_t<NV>>, 
                                    math::add<NV>>;
using global_cable170_t_index = global_cable5_t_index;

template <int NV>
using global_cable170_t = routing::global_cable<global_cable170_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain181_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable170_t<NV>>, 
                                    math::add<NV>>;
using global_cable171_t_index = global_cable4_t_index;

template <int NV>
using global_cable171_t = routing::global_cable<global_cable171_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain182_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable171_t<NV>>, 
                                    math::add<NV>>;
using global_cable172_t_index = global_cable3_t_index;

template <int NV>
using global_cable172_t = routing::global_cable<global_cable172_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain183_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable172_t<NV>>, 
                                    math::add<NV>>;
using global_cable173_t_index = global_cable45_t_index;

template <int NV>
using global_cable173_t = routing::global_cable<global_cable173_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain184_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable173_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch10_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain169_t<NV>>, 
                                     chain170_t<NV>, 
                                     chain171_t<NV>, 
                                     chain172_t<NV>, 
                                     chain173_t<NV>, 
                                     chain174_t<NV>, 
                                     chain175_t<NV>, 
                                     chain176_t<NV>, 
                                     chain177_t<NV>, 
                                     chain178_t<NV>, 
                                     chain179_t<NV>, 
                                     chain180_t<NV>, 
                                     chain181_t<NV>, 
                                     chain182_t<NV>, 
                                     chain183_t<NV>, 
                                     chain184_t<NV>>;

template <int NV>
using pma11_t = control::pma<NV, 
                             parameter::plain<snex_node_t<NV>, 5>>;
template <int NV>
using peak10_t = wrap::mod<parameter::plain<pma11_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain168_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch10_t<NV>>, 
                                    peak10_t<NV>, 
                                    math::clear<NV>, 
                                    pma11_t<NV>>;
using global_cable174_t_index = global_cable_t_index;

template <int NV>
using global_cable174_t = routing::global_cable<global_cable174_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain186_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable174_t<NV>>, 
                                    math::add<NV>>;
using global_cable175_t_index = global_cable2_t_index;

template <int NV>
using global_cable175_t = routing::global_cable<global_cable175_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain187_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable175_t<NV>>, 
                                    math::add<NV>>;
using global_cable176_t_index = global_cable1_t_index;

template <int NV>
using global_cable176_t = routing::global_cable<global_cable176_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain188_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable176_t<NV>>, 
                                    math::add<NV>>;
using global_cable177_t_index = global_cable14_t_index;

template <int NV>
using global_cable177_t = routing::global_cable<global_cable177_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain189_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable177_t<NV>>, 
                                    math::add<NV>>;
using global_cable178_t_index = global_cable13_t_index;

template <int NV>
using global_cable178_t = routing::global_cable<global_cable178_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain190_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable178_t<NV>>, 
                                    math::add<NV>>;
using global_cable179_t_index = global_cable12_t_index;

template <int NV>
using global_cable179_t = routing::global_cable<global_cable179_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain191_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable179_t<NV>>, 
                                    math::add<NV>>;
using global_cable180_t_index = global_cable11_t_index;

template <int NV>
using global_cable180_t = routing::global_cable<global_cable180_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain192_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable180_t<NV>>, 
                                    math::add<NV>>;
using global_cable181_t_index = global_cable10_t_index;

template <int NV>
using global_cable181_t = routing::global_cable<global_cable181_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain193_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable181_t<NV>>, 
                                    math::add<NV>>;
using global_cable182_t_index = global_cable9_t_index;

template <int NV>
using global_cable182_t = routing::global_cable<global_cable182_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain194_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable182_t<NV>>, 
                                    math::add<NV>>;
using global_cable183_t_index = global_cable8_t_index;

template <int NV>
using global_cable183_t = routing::global_cable<global_cable183_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain195_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable183_t<NV>>, 
                                    math::add<NV>>;
using global_cable184_t_index = global_cable7_t_index;

template <int NV>
using global_cable184_t = routing::global_cable<global_cable184_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain196_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable184_t<NV>>, 
                                    math::add<NV>>;
using global_cable185_t_index = global_cable6_t_index;

template <int NV>
using global_cable185_t = routing::global_cable<global_cable185_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain197_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable185_t<NV>>, 
                                    math::add<NV>>;
using global_cable186_t_index = global_cable5_t_index;

template <int NV>
using global_cable186_t = routing::global_cable<global_cable186_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain198_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable186_t<NV>>, 
                                    math::add<NV>>;
using global_cable187_t_index = global_cable4_t_index;

template <int NV>
using global_cable187_t = routing::global_cable<global_cable187_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain199_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable187_t<NV>>, 
                                    math::add<NV>>;
using global_cable188_t_index = global_cable3_t_index;

template <int NV>
using global_cable188_t = routing::global_cable<global_cable188_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain200_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable188_t<NV>>, 
                                    math::add<NV>>;
using global_cable189_t_index = global_cable45_t_index;

template <int NV>
using global_cable189_t = routing::global_cable<global_cable189_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain201_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable189_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch11_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain186_t<NV>>, 
                                     chain187_t<NV>, 
                                     chain188_t<NV>, 
                                     chain189_t<NV>, 
                                     chain190_t<NV>, 
                                     chain191_t<NV>, 
                                     chain192_t<NV>, 
                                     chain193_t<NV>, 
                                     chain194_t<NV>, 
                                     chain195_t<NV>, 
                                     chain196_t<NV>, 
                                     chain197_t<NV>, 
                                     chain198_t<NV>, 
                                     chain199_t<NV>, 
                                     chain200_t<NV>, 
                                     chain201_t<NV>>;

template <int NV>
using input_toggle_t = control::input_toggle<NV, 
                                             parameter::plain<snex_node_t<NV>, 7>>;
template <int NV>
using pma12_t = control::pma<NV, 
                             parameter::plain<input_toggle_t<NV>, 1>>;

template <int NV>
using tempo_sync1_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 2>, 
                                control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma21_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma21_mod = parameter::from0To1<tempo_sync1_t<NV>, 
                                      0, 
                                      pma21_modRange>;

template <int NV>
using pma21_t = control::pma<NV, pma21_mod<NV>>;

template <int NV>
using peak11_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<pma12_t<NV>, 0>, 
                                    parameter::plain<pma21_t<NV>, 0>>;

template <int NV>
using peak11_t = wrap::mod<peak11_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain185_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch11_t<NV>>, 
                                    peak11_t<NV>, 
                                    math::clear<NV>, 
                                    pma12_t<NV>, 
                                    pma21_t<NV>>;
using global_cable190_t_index = global_cable_t_index;

template <int NV>
using global_cable190_t = routing::global_cable<global_cable190_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain203_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable190_t<NV>>, 
                                    math::add<NV>>;
using global_cable191_t_index = global_cable2_t_index;

template <int NV>
using global_cable191_t = routing::global_cable<global_cable191_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain204_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable191_t<NV>>, 
                                    math::add<NV>>;
using global_cable192_t_index = global_cable1_t_index;

template <int NV>
using global_cable192_t = routing::global_cable<global_cable192_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain205_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable192_t<NV>>, 
                                    math::add<NV>>;
using global_cable193_t_index = global_cable14_t_index;

template <int NV>
using global_cable193_t = routing::global_cable<global_cable193_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain206_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable193_t<NV>>, 
                                    math::add<NV>>;
using global_cable194_t_index = global_cable13_t_index;

template <int NV>
using global_cable194_t = routing::global_cable<global_cable194_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain207_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable194_t<NV>>, 
                                    math::add<NV>>;
using global_cable195_t_index = global_cable12_t_index;

template <int NV>
using global_cable195_t = routing::global_cable<global_cable195_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain208_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable195_t<NV>>, 
                                    math::add<NV>>;
using global_cable196_t_index = global_cable11_t_index;

template <int NV>
using global_cable196_t = routing::global_cable<global_cable196_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain209_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable196_t<NV>>, 
                                    math::add<NV>>;
using global_cable197_t_index = global_cable10_t_index;

template <int NV>
using global_cable197_t = routing::global_cable<global_cable197_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain210_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable197_t<NV>>, 
                                    math::add<NV>>;
using global_cable198_t_index = global_cable9_t_index;

template <int NV>
using global_cable198_t = routing::global_cable<global_cable198_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain211_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable198_t<NV>>, 
                                    math::add<NV>>;
using global_cable199_t_index = global_cable8_t_index;

template <int NV>
using global_cable199_t = routing::global_cable<global_cable199_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain212_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable199_t<NV>>, 
                                    math::add<NV>>;
using global_cable200_t_index = global_cable7_t_index;

template <int NV>
using global_cable200_t = routing::global_cable<global_cable200_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain213_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable200_t<NV>>, 
                                    math::add<NV>>;
using global_cable201_t_index = global_cable6_t_index;

template <int NV>
using global_cable201_t = routing::global_cable<global_cable201_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain214_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable201_t<NV>>, 
                                    math::add<NV>>;
using global_cable202_t_index = global_cable5_t_index;

template <int NV>
using global_cable202_t = routing::global_cable<global_cable202_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain215_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable202_t<NV>>, 
                                    math::add<NV>>;
using global_cable203_t_index = global_cable4_t_index;

template <int NV>
using global_cable203_t = routing::global_cable<global_cable203_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain216_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable203_t<NV>>, 
                                    math::add<NV>>;
using global_cable204_t_index = global_cable3_t_index;

template <int NV>
using global_cable204_t = routing::global_cable<global_cable204_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain217_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable204_t<NV>>, 
                                    math::add<NV>>;
using global_cable205_t_index = global_cable45_t_index;

template <int NV>
using global_cable205_t = routing::global_cable<global_cable205_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain218_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable205_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch12_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain203_t<NV>>, 
                                     chain204_t<NV>, 
                                     chain205_t<NV>, 
                                     chain206_t<NV>, 
                                     chain207_t<NV>, 
                                     chain208_t<NV>, 
                                     chain209_t<NV>, 
                                     chain210_t<NV>, 
                                     chain211_t<NV>, 
                                     chain212_t<NV>, 
                                     chain213_t<NV>, 
                                     chain214_t<NV>, 
                                     chain215_t<NV>, 
                                     chain216_t<NV>, 
                                     chain217_t<NV>, 
                                     chain218_t<NV>>;

DECLARE_PARAMETER_RANGE(pma2_modRange, 
                        0., 
                        3200.);

template <int NV>
using pma2_mod = parameter::from0To1<snex_node_t<NV>, 
                                     12, 
                                     pma2_modRange>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;
template <int NV>
using peak12_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain202_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch12_t<NV>>, 
                                    peak12_t<NV>, 
                                    math::clear<NV>, 
                                    pma2_t<NV>>;
using global_cable206_t_index = global_cable_t_index;

template <int NV>
using global_cable206_t = routing::global_cable<global_cable206_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain220_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable206_t<NV>>, 
                                    math::add<NV>>;
using global_cable207_t_index = global_cable2_t_index;

template <int NV>
using global_cable207_t = routing::global_cable<global_cable207_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain221_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable207_t<NV>>, 
                                    math::add<NV>>;
using global_cable208_t_index = global_cable1_t_index;

template <int NV>
using global_cable208_t = routing::global_cable<global_cable208_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain222_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable208_t<NV>>, 
                                    math::add<NV>>;
using global_cable209_t_index = global_cable14_t_index;

template <int NV>
using global_cable209_t = routing::global_cable<global_cable209_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain223_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable209_t<NV>>, 
                                    math::add<NV>>;
using global_cable210_t_index = global_cable13_t_index;

template <int NV>
using global_cable210_t = routing::global_cable<global_cable210_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain224_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable210_t<NV>>, 
                                    math::add<NV>>;
using global_cable211_t_index = global_cable12_t_index;

template <int NV>
using global_cable211_t = routing::global_cable<global_cable211_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain225_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable211_t<NV>>, 
                                    math::add<NV>>;
using global_cable212_t_index = global_cable11_t_index;

template <int NV>
using global_cable212_t = routing::global_cable<global_cable212_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain226_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable212_t<NV>>, 
                                    math::add<NV>>;
using global_cable213_t_index = global_cable10_t_index;

template <int NV>
using global_cable213_t = routing::global_cable<global_cable213_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain227_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable213_t<NV>>, 
                                    math::add<NV>>;
using global_cable214_t_index = global_cable9_t_index;

template <int NV>
using global_cable214_t = routing::global_cable<global_cable214_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain228_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable214_t<NV>>, 
                                    math::add<NV>>;
using global_cable215_t_index = global_cable8_t_index;

template <int NV>
using global_cable215_t = routing::global_cable<global_cable215_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain229_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable215_t<NV>>, 
                                    math::add<NV>>;
using global_cable216_t_index = global_cable7_t_index;

template <int NV>
using global_cable216_t = routing::global_cable<global_cable216_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain230_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable216_t<NV>>, 
                                    math::add<NV>>;
using global_cable217_t_index = global_cable6_t_index;

template <int NV>
using global_cable217_t = routing::global_cable<global_cable217_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain231_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable217_t<NV>>, 
                                    math::add<NV>>;
using global_cable218_t_index = global_cable5_t_index;

template <int NV>
using global_cable218_t = routing::global_cable<global_cable218_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain232_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable218_t<NV>>, 
                                    math::add<NV>>;
using global_cable219_t_index = global_cable4_t_index;

template <int NV>
using global_cable219_t = routing::global_cable<global_cable219_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain233_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable219_t<NV>>, 
                                    math::add<NV>>;
using global_cable220_t_index = global_cable3_t_index;

template <int NV>
using global_cable220_t = routing::global_cable<global_cable220_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain234_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable220_t<NV>>, 
                                    math::add<NV>>;
using global_cable221_t_index = global_cable45_t_index;

template <int NV>
using global_cable221_t = routing::global_cable<global_cable221_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain235_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable221_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch13_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain220_t<NV>>, 
                                     chain221_t<NV>, 
                                     chain222_t<NV>, 
                                     chain223_t<NV>, 
                                     chain224_t<NV>, 
                                     chain225_t<NV>, 
                                     chain226_t<NV>, 
                                     chain227_t<NV>, 
                                     chain228_t<NV>, 
                                     chain229_t<NV>, 
                                     chain230_t<NV>, 
                                     chain231_t<NV>, 
                                     chain232_t<NV>, 
                                     chain233_t<NV>, 
                                     chain234_t<NV>, 
                                     chain235_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma14_modRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma14_mod = parameter::from0To1<filters::svf<NV>, 
                                      0, 
                                      pma14_modRange>;

template <int NV>
using pma14_t = control::pma<NV, pma14_mod<NV>>;
template <int NV>
using peak13_t = wrap::mod<parameter::plain<pma14_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain219_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch13_t<NV>>, 
                                    peak13_t<NV>, 
                                    math::clear<NV>, 
                                    pma14_t<NV>>;
using global_cable222_t_index = global_cable_t_index;

template <int NV>
using global_cable222_t = routing::global_cable<global_cable222_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain237_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable222_t<NV>>, 
                                    math::add<NV>>;
using global_cable223_t_index = global_cable2_t_index;

template <int NV>
using global_cable223_t = routing::global_cable<global_cable223_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain238_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable223_t<NV>>, 
                                    math::add<NV>>;
using global_cable224_t_index = global_cable1_t_index;

template <int NV>
using global_cable224_t = routing::global_cable<global_cable224_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain239_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable224_t<NV>>, 
                                    math::add<NV>>;
using global_cable225_t_index = global_cable14_t_index;

template <int NV>
using global_cable225_t = routing::global_cable<global_cable225_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain240_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable225_t<NV>>, 
                                    math::add<NV>>;
using global_cable226_t_index = global_cable13_t_index;

template <int NV>
using global_cable226_t = routing::global_cable<global_cable226_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain241_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable226_t<NV>>, 
                                    math::add<NV>>;
using global_cable227_t_index = global_cable12_t_index;

template <int NV>
using global_cable227_t = routing::global_cable<global_cable227_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain242_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable227_t<NV>>, 
                                    math::add<NV>>;
using global_cable228_t_index = global_cable11_t_index;

template <int NV>
using global_cable228_t = routing::global_cable<global_cable228_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain243_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable228_t<NV>>, 
                                    math::add<NV>>;
using global_cable229_t_index = global_cable10_t_index;

template <int NV>
using global_cable229_t = routing::global_cable<global_cable229_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain244_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable229_t<NV>>, 
                                    math::add<NV>>;
using global_cable230_t_index = global_cable9_t_index;

template <int NV>
using global_cable230_t = routing::global_cable<global_cable230_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain245_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable230_t<NV>>, 
                                    math::add<NV>>;
using global_cable231_t_index = global_cable8_t_index;

template <int NV>
using global_cable231_t = routing::global_cable<global_cable231_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain246_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable231_t<NV>>, 
                                    math::add<NV>>;
using global_cable232_t_index = global_cable7_t_index;

template <int NV>
using global_cable232_t = routing::global_cable<global_cable232_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain247_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable232_t<NV>>, 
                                    math::add<NV>>;
using global_cable233_t_index = global_cable6_t_index;

template <int NV>
using global_cable233_t = routing::global_cable<global_cable233_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain248_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable233_t<NV>>, 
                                    math::add<NV>>;
using global_cable234_t_index = global_cable5_t_index;

template <int NV>
using global_cable234_t = routing::global_cable<global_cable234_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain249_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable234_t<NV>>, 
                                    math::add<NV>>;
using global_cable235_t_index = global_cable4_t_index;

template <int NV>
using global_cable235_t = routing::global_cable<global_cable235_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain250_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable235_t<NV>>, 
                                    math::add<NV>>;
using global_cable236_t_index = global_cable3_t_index;

template <int NV>
using global_cable236_t = routing::global_cable<global_cable236_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain251_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable236_t<NV>>, 
                                    math::add<NV>>;
using global_cable237_t_index = global_cable45_t_index;

template <int NV>
using global_cable237_t = routing::global_cable<global_cable237_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain252_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable237_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch14_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain237_t<NV>>, 
                                     chain238_t<NV>, 
                                     chain239_t<NV>, 
                                     chain240_t<NV>, 
                                     chain241_t<NV>, 
                                     chain242_t<NV>, 
                                     chain243_t<NV>, 
                                     chain244_t<NV>, 
                                     chain245_t<NV>, 
                                     chain246_t<NV>, 
                                     chain247_t<NV>, 
                                     chain248_t<NV>, 
                                     chain249_t<NV>, 
                                     chain250_t<NV>, 
                                     chain251_t<NV>, 
                                     chain252_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV>
using clone_cable2_t = control::clone_cable<parameter::cloned<parameter::plain<project::res2<NV>, 0>>, 
                                            duplilogic::fixed>;

struct cable_table6_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00366092f, 0.00732183f, 0.0109827f, 0.0146436f, 0.0183045f,
		0.0219654f, 0.0256264f, 0.0292872f, 0.0329481f, 0.0366091f, 0.04027f,
		0.0439309f, 0.0475917f, 0.0512527f, 0.0549136f, 0.0585745f, 0.0622354f,
		0.0658963f, 0.0695572f, 0.0732181f, 0.076879f, 0.0805399f, 0.0842008f,
		0.0878617f, 0.0915226f, 0.0951835f, 0.0988444f, 0.102505f, 0.106166f,
		0.109827f, 0.113488f, 0.117149f, 0.12081f, 0.124471f, 0.128132f,
		0.131793f, 0.135453f, 0.139114f, 0.142775f, 0.146436f, 0.150097f,
		0.153758f, 0.157419f, 0.16108f, 0.164741f, 0.168402f, 0.172063f,
		0.175723f, 0.179384f, 0.183045f, 0.186706f, 0.190367f, 0.194028f,
		0.197689f, 0.20135f, 0.205011f, 0.208672f, 0.212332f, 0.215993f,
		0.219654f, 0.223315f, 0.226976f, 0.230637f, 0.234298f, 0.237959f,
		0.24162f, 0.245281f, 0.248942f, 0.252602f, 0.256263f, 0.259924f,
		0.263585f, 0.267246f, 0.270907f, 0.274568f, 0.278229f, 0.28189f,
		0.285551f, 0.289212f, 0.292872f, 0.296533f, 0.300194f, 0.303855f,
		0.307516f, 0.311177f, 0.314838f, 0.318499f, 0.32216f, 0.325821f,
		0.329481f, 0.333142f, 0.336803f, 0.340464f, 0.344125f, 0.347786f,
		0.351447f, 0.355108f, 0.358769f, 0.36243f, 0.36609f, 0.369751f,
		0.373412f, 0.377073f, 0.380734f, 0.384395f, 0.388056f, 0.391717f,
		0.395378f, 0.399039f, 0.402699f, 0.40636f, 0.410021f, 0.413682f,
		0.417343f, 0.421004f, 0.424665f, 0.428326f, 0.431987f, 0.435648f,
		0.439309f, 0.44297f, 0.44663f, 0.450291f, 0.453952f, 0.457613f,
		0.461274f, 0.464935f, 0.468596f, 0.472257f, 0.475918f, 0.479579f,
		0.483239f, 0.4869f, 0.490561f, 0.494222f, 0.497883f, 0.501544f,
		0.505205f, 0.508866f, 0.512527f, 0.516188f, 0.519849f, 0.523509f,
		0.52717f, 0.530831f, 0.534492f, 0.538153f, 0.541814f, 0.545475f,
		0.549136f, 0.552797f, 0.556458f, 0.560118f, 0.563779f, 0.56744f,
		0.571101f, 0.574762f, 0.578423f, 0.582084f, 0.585745f, 0.589406f,
		0.593067f, 0.596727f, 0.600388f, 0.604049f, 0.60771f, 0.611371f,
		0.615032f, 0.618693f, 0.622354f, 0.626015f, 0.629676f, 0.633337f,
		0.636997f, 0.640658f, 0.644319f, 0.64798f, 0.651641f, 0.655302f,
		0.658963f, 0.662624f, 0.666285f, 0.669946f, 0.673607f, 0.677267f,
		0.680928f, 0.684589f, 0.68825f, 0.691911f, 0.695572f, 0.699233f,
		0.702894f, 0.706555f, 0.710216f, 0.713876f, 0.717537f, 0.721198f,
		0.724859f, 0.72852f, 0.732181f, 0.735842f, 0.739503f, 0.743164f,
		0.746825f, 0.750485f, 0.754146f, 0.757807f, 0.761468f, 0.765129f,
		0.76879f, 0.772451f, 0.776112f, 0.779773f, 0.783434f, 0.787095f,
		0.790755f, 0.794416f, 0.798077f, 0.801738f, 0.805399f, 0.80906f,
		0.812721f, 0.816382f, 0.820043f, 0.823704f, 0.827365f, 0.831025f,
		0.834686f, 0.838347f, 0.842008f, 0.845669f, 0.84933f, 0.852991f,
		0.856652f, 0.860313f, 0.863973f, 0.867634f, 0.871295f, 0.874956f,
		0.878617f, 0.882278f, 0.885939f, 0.8896f, 0.893261f, 0.896922f,
		0.900583f, 0.904243f, 0.907904f, 0.911565f, 0.915226f, 0.918887f,
		0.922548f, 0.926209f, 0.92987f, 0.933531f, 0.937192f, 0.940853f,
		0.944513f, 0.948174f, 0.951835f, 0.955496f, 0.959157f, 0.962818f,
		0.966479f, 0.97014f, 0.973801f, 0.977462f, 0.981122f, 0.984783f,
		0.988444f, 0.992105f, 0.995766f, 0.999427f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table6_t = wrap::data<control::cable_table<parameter::plain<clone_cable2_t<NV>, 1>>, 
                                  data::embedded::table<cable_table6_t_data>>;
template <int NV> using xfader_c1_0 = xfader_c0<NV>;

template <int NV>
using xfader_c1 = parameter::chain<ranges::Identity, 
                                   xfader_c1_0<NV>, 
                                   parameter::plain<cable_table6_t<NV>, 0>>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;
template <int NV>
using pma15_t = control::pma<NV, 
                             parameter::plain<xfader_t<NV>, 0>>;
template <int NV>
using peak14_t = wrap::mod<parameter::plain<pma15_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain236_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch14_t<NV>>, 
                                    peak14_t<NV>, 
                                    math::clear<NV>, 
                                    pma15_t<NV>>;
using global_cable238_t_index = global_cable_t_index;

template <int NV>
using global_cable238_t = routing::global_cable<global_cable238_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain254_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable238_t<NV>>, 
                                    math::add<NV>>;
using global_cable239_t_index = global_cable2_t_index;

template <int NV>
using global_cable239_t = routing::global_cable<global_cable239_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain255_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable239_t<NV>>, 
                                    math::add<NV>>;
using global_cable240_t_index = global_cable1_t_index;

template <int NV>
using global_cable240_t = routing::global_cable<global_cable240_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain256_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable240_t<NV>>, 
                                    math::add<NV>>;
using global_cable241_t_index = global_cable14_t_index;

template <int NV>
using global_cable241_t = routing::global_cable<global_cable241_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain257_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable241_t<NV>>, 
                                    math::add<NV>>;
using global_cable242_t_index = global_cable13_t_index;

template <int NV>
using global_cable242_t = routing::global_cable<global_cable242_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain258_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable242_t<NV>>, 
                                    math::add<NV>>;
using global_cable243_t_index = global_cable12_t_index;

template <int NV>
using global_cable243_t = routing::global_cable<global_cable243_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain259_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable243_t<NV>>, 
                                    math::add<NV>>;
using global_cable244_t_index = global_cable11_t_index;

template <int NV>
using global_cable244_t = routing::global_cable<global_cable244_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain260_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable244_t<NV>>, 
                                    math::add<NV>>;
using global_cable245_t_index = global_cable10_t_index;

template <int NV>
using global_cable245_t = routing::global_cable<global_cable245_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain261_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable245_t<NV>>, 
                                    math::add<NV>>;
using global_cable246_t_index = global_cable9_t_index;

template <int NV>
using global_cable246_t = routing::global_cable<global_cable246_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain262_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable246_t<NV>>, 
                                    math::add<NV>>;
using global_cable247_t_index = global_cable8_t_index;

template <int NV>
using global_cable247_t = routing::global_cable<global_cable247_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain263_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable247_t<NV>>, 
                                    math::add<NV>>;
using global_cable248_t_index = global_cable7_t_index;

template <int NV>
using global_cable248_t = routing::global_cable<global_cable248_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain264_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable248_t<NV>>, 
                                    math::add<NV>>;
using global_cable249_t_index = global_cable6_t_index;

template <int NV>
using global_cable249_t = routing::global_cable<global_cable249_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain265_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable249_t<NV>>, 
                                    math::add<NV>>;
using global_cable250_t_index = global_cable5_t_index;

template <int NV>
using global_cable250_t = routing::global_cable<global_cable250_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain266_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable250_t<NV>>, 
                                    math::add<NV>>;
using global_cable251_t_index = global_cable4_t_index;

template <int NV>
using global_cable251_t = routing::global_cable<global_cable251_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain267_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable251_t<NV>>, 
                                    math::add<NV>>;
using global_cable252_t_index = global_cable3_t_index;

template <int NV>
using global_cable252_t = routing::global_cable<global_cable252_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain268_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable252_t<NV>>, 
                                    math::add<NV>>;
using global_cable253_t_index = global_cable45_t_index;

template <int NV>
using global_cable253_t = routing::global_cable<global_cable253_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain269_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable253_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch15_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain254_t<NV>>, 
                                     chain255_t<NV>, 
                                     chain256_t<NV>, 
                                     chain257_t<NV>, 
                                     chain258_t<NV>, 
                                     chain259_t<NV>, 
                                     chain260_t<NV>, 
                                     chain261_t<NV>, 
                                     chain262_t<NV>, 
                                     chain263_t<NV>, 
                                     chain264_t<NV>, 
                                     chain265_t<NV>, 
                                     chain266_t<NV>, 
                                     chain267_t<NV>, 
                                     chain268_t<NV>, 
                                     chain269_t<NV>>;

template <int NV>
using converter7_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<jdsp::jdelay_thiran<NV>, 1>, 
                                        parameter::plain<wrap::no_process<core::fix_delay>, 0>>;

template <int NV>
using converter7_t = control::converter<converter7_mod<NV>, 
                                        conversion_logic::freq2ms>;
// Apply the pitch modulation to the delay time ----------------------------------------------------

template <int NV>
using pma_unscaled3_t = control::pma_unscaled<NV, 
                                              parameter::plain<converter7_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(clone_cable_modRange, 
                        0., 
                        30.);

template <int NV>
using clone_cable_mod = parameter::from0To1<project::res2<NV>, 
                                            1, 
                                            clone_cable_modRange>;

template <int NV>
using clone_cable_t = control::clone_cable<parameter::cloned<clone_cable_mod<NV>>, 
                                           duplilogic::spread>;
DECLARE_PARAMETER_RANGE_SKEW(pma16_mod_0Range, 
                             0.5, 
                             2., 
                             0.63093);

template <int NV>
using pma16_mod_0 = parameter::from0To1<pma_unscaled3_t<NV>, 
                                        1, 
                                        pma16_mod_0Range>;

template <int NV>
using pma16_mod = parameter::chain<ranges::Identity, 
                                   pma16_mod_0<NV>, 
                                   parameter::plain<clone_cable_t<NV>, 1>>;

template <int NV>
using pma16_t = control::pma<NV, pma16_mod<NV>>;
template <int NV>
using peak15_t = wrap::mod<parameter::plain<pma16_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain253_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch15_t<NV>>, 
                                    peak15_t<NV>, 
                                    math::clear<NV>, 
                                    pma16_t<NV>>;
using global_cable270_t_index = global_cable_t_index;

template <int NV>
using global_cable270_t = routing::global_cable<global_cable270_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain288_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable270_t<NV>>, 
                                    math::add<NV>>;
using global_cable271_t_index = global_cable2_t_index;

template <int NV>
using global_cable271_t = routing::global_cable<global_cable271_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain289_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable271_t<NV>>, 
                                    math::add<NV>>;
using global_cable272_t_index = global_cable1_t_index;

template <int NV>
using global_cable272_t = routing::global_cable<global_cable272_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain290_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable272_t<NV>>, 
                                    math::add<NV>>;
using global_cable273_t_index = global_cable14_t_index;

template <int NV>
using global_cable273_t = routing::global_cable<global_cable273_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain291_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable273_t<NV>>, 
                                    math::add<NV>>;
using global_cable274_t_index = global_cable13_t_index;

template <int NV>
using global_cable274_t = routing::global_cable<global_cable274_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain292_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable274_t<NV>>, 
                                    math::add<NV>>;
using global_cable275_t_index = global_cable12_t_index;

template <int NV>
using global_cable275_t = routing::global_cable<global_cable275_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain293_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable275_t<NV>>, 
                                    math::add<NV>>;
using global_cable276_t_index = global_cable11_t_index;

template <int NV>
using global_cable276_t = routing::global_cable<global_cable276_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain294_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable276_t<NV>>, 
                                    math::add<NV>>;
using global_cable277_t_index = global_cable10_t_index;

template <int NV>
using global_cable277_t = routing::global_cable<global_cable277_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain295_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable277_t<NV>>, 
                                    math::add<NV>>;
using global_cable278_t_index = global_cable9_t_index;

template <int NV>
using global_cable278_t = routing::global_cable<global_cable278_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain296_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable278_t<NV>>, 
                                    math::add<NV>>;
using global_cable279_t_index = global_cable8_t_index;

template <int NV>
using global_cable279_t = routing::global_cable<global_cable279_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain297_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable279_t<NV>>, 
                                    math::add<NV>>;
using global_cable280_t_index = global_cable7_t_index;

template <int NV>
using global_cable280_t = routing::global_cable<global_cable280_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain298_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable280_t<NV>>, 
                                    math::add<NV>>;
using global_cable281_t_index = global_cable6_t_index;

template <int NV>
using global_cable281_t = routing::global_cable<global_cable281_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain299_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable281_t<NV>>, 
                                    math::add<NV>>;
using global_cable282_t_index = global_cable5_t_index;

template <int NV>
using global_cable282_t = routing::global_cable<global_cable282_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain300_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable282_t<NV>>, 
                                    math::add<NV>>;
using global_cable283_t_index = global_cable4_t_index;

template <int NV>
using global_cable283_t = routing::global_cable<global_cable283_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain301_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable283_t<NV>>, 
                                    math::add<NV>>;
using global_cable284_t_index = global_cable3_t_index;

template <int NV>
using global_cable284_t = routing::global_cable<global_cable284_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain302_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable284_t<NV>>, 
                                    math::add<NV>>;
using global_cable285_t_index = global_cable45_t_index;

template <int NV>
using global_cable285_t = routing::global_cable<global_cable285_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain303_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable285_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch17_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain288_t<NV>>, 
                                     chain289_t<NV>, 
                                     chain290_t<NV>, 
                                     chain291_t<NV>, 
                                     chain292_t<NV>, 
                                     chain293_t<NV>, 
                                     chain294_t<NV>, 
                                     chain295_t<NV>, 
                                     chain296_t<NV>, 
                                     chain297_t<NV>, 
                                     chain298_t<NV>, 
                                     chain299_t<NV>, 
                                     chain300_t<NV>, 
                                     chain301_t<NV>, 
                                     chain302_t<NV>, 
                                     chain303_t<NV>>;

template <int NV>
using clone_cable1_t = control::clone_cable<parameter::cloned<parameter::plain<project::res2<NV>, 3>>, 
                                            duplilogic::fixed>;
template <int NV>
using pma18_mod_0 = parameter::from0To1<filters::one_pole<NV>, 
                                        0, 
                                        pma14_modRange>;

template <int NV>
using pma18_mod = parameter::chain<ranges::Identity, 
                                   pma18_mod_0<NV>, 
                                   parameter::plain<clone_cable1_t<NV>, 1>>;

template <int NV>
using pma18_t = control::pma<NV, pma18_mod<NV>>;
template <int NV>
using peak17_t = wrap::mod<parameter::plain<pma18_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain287_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch17_t<NV>>, 
                                    peak17_t<NV>, 
                                    math::clear<NV>, 
                                    pma18_t<NV>>;
using global_cable254_t_index = global_cable_t_index;

template <int NV>
using global_cable254_t = routing::global_cable<global_cable254_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain271_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable254_t<NV>>, 
                                    math::add<NV>>;
using global_cable255_t_index = global_cable2_t_index;

template <int NV>
using global_cable255_t = routing::global_cable<global_cable255_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain272_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable255_t<NV>>, 
                                    math::add<NV>>;
using global_cable256_t_index = global_cable1_t_index;

template <int NV>
using global_cable256_t = routing::global_cable<global_cable256_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain273_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable256_t<NV>>, 
                                    math::add<NV>>;
using global_cable257_t_index = global_cable14_t_index;

template <int NV>
using global_cable257_t = routing::global_cable<global_cable257_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain274_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable257_t<NV>>, 
                                    math::add<NV>>;
using global_cable258_t_index = global_cable13_t_index;

template <int NV>
using global_cable258_t = routing::global_cable<global_cable258_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain275_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable258_t<NV>>, 
                                    math::add<NV>>;
using global_cable259_t_index = global_cable12_t_index;

template <int NV>
using global_cable259_t = routing::global_cable<global_cable259_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain276_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable259_t<NV>>, 
                                    math::add<NV>>;
using global_cable260_t_index = global_cable11_t_index;

template <int NV>
using global_cable260_t = routing::global_cable<global_cable260_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain277_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable260_t<NV>>, 
                                    math::add<NV>>;
using global_cable261_t_index = global_cable10_t_index;

template <int NV>
using global_cable261_t = routing::global_cable<global_cable261_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain278_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable261_t<NV>>, 
                                    math::add<NV>>;
using global_cable262_t_index = global_cable9_t_index;

template <int NV>
using global_cable262_t = routing::global_cable<global_cable262_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain279_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable262_t<NV>>, 
                                    math::add<NV>>;
using global_cable263_t_index = global_cable8_t_index;

template <int NV>
using global_cable263_t = routing::global_cable<global_cable263_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain280_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable263_t<NV>>, 
                                    math::add<NV>>;
using global_cable264_t_index = global_cable7_t_index;

template <int NV>
using global_cable264_t = routing::global_cable<global_cable264_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain281_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable264_t<NV>>, 
                                    math::add<NV>>;
using global_cable265_t_index = global_cable6_t_index;

template <int NV>
using global_cable265_t = routing::global_cable<global_cable265_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain282_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable265_t<NV>>, 
                                    math::add<NV>>;
using global_cable266_t_index = global_cable5_t_index;

template <int NV>
using global_cable266_t = routing::global_cable<global_cable266_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain283_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable266_t<NV>>, 
                                    math::add<NV>>;
using global_cable267_t_index = global_cable4_t_index;

template <int NV>
using global_cable267_t = routing::global_cable<global_cable267_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain284_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable267_t<NV>>, 
                                    math::add<NV>>;
using global_cable268_t_index = global_cable3_t_index;

template <int NV>
using global_cable268_t = routing::global_cable<global_cable268_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain285_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable268_t<NV>>, 
                                    math::add<NV>>;
using global_cable269_t_index = global_cable45_t_index;

template <int NV>
using global_cable269_t = routing::global_cable<global_cable269_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain286_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable269_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch16_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain271_t<NV>>, 
                                     chain272_t<NV>, 
                                     chain273_t<NV>, 
                                     chain274_t<NV>, 
                                     chain275_t<NV>, 
                                     chain276_t<NV>, 
                                     chain277_t<NV>, 
                                     chain278_t<NV>, 
                                     chain279_t<NV>, 
                                     chain280_t<NV>, 
                                     chain281_t<NV>, 
                                     chain282_t<NV>, 
                                     chain283_t<NV>, 
                                     chain284_t<NV>, 
                                     chain285_t<NV>, 
                                     chain286_t<NV>>;

template <int NV> using pma17_mod = pma14_mod<NV>;

template <int NV>
using pma17_t = control::pma<NV, pma17_mod<NV>>;
template <int NV>
using peak16_t = wrap::mod<parameter::plain<pma17_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain270_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch16_t<NV>>, 
                                    peak16_t<NV>, 
                                    math::clear<NV>, 
                                    pma17_t<NV>>;
using global_cable286_t_index = global_cable_t_index;

template <int NV>
using global_cable286_t = routing::global_cable<global_cable286_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain305_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable286_t<NV>>, 
                                    math::add<NV>>;
using global_cable287_t_index = global_cable2_t_index;

template <int NV>
using global_cable287_t = routing::global_cable<global_cable287_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain306_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable287_t<NV>>, 
                                    math::add<NV>>;
using global_cable288_t_index = global_cable1_t_index;

template <int NV>
using global_cable288_t = routing::global_cable<global_cable288_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain307_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable288_t<NV>>, 
                                    math::add<NV>>;
using global_cable289_t_index = global_cable14_t_index;

template <int NV>
using global_cable289_t = routing::global_cable<global_cable289_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain308_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable289_t<NV>>, 
                                    math::add<NV>>;
using global_cable290_t_index = global_cable13_t_index;

template <int NV>
using global_cable290_t = routing::global_cable<global_cable290_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain309_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable290_t<NV>>, 
                                    math::add<NV>>;
using global_cable291_t_index = global_cable12_t_index;

template <int NV>
using global_cable291_t = routing::global_cable<global_cable291_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain310_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable291_t<NV>>, 
                                    math::add<NV>>;
using global_cable292_t_index = global_cable11_t_index;

template <int NV>
using global_cable292_t = routing::global_cable<global_cable292_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain311_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable292_t<NV>>, 
                                    math::add<NV>>;
using global_cable293_t_index = global_cable10_t_index;

template <int NV>
using global_cable293_t = routing::global_cable<global_cable293_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain312_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable293_t<NV>>, 
                                    math::add<NV>>;
using global_cable294_t_index = global_cable9_t_index;

template <int NV>
using global_cable294_t = routing::global_cable<global_cable294_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain313_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable294_t<NV>>, 
                                    math::add<NV>>;
using global_cable295_t_index = global_cable8_t_index;

template <int NV>
using global_cable295_t = routing::global_cable<global_cable295_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain314_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable295_t<NV>>, 
                                    math::add<NV>>;
using global_cable296_t_index = global_cable7_t_index;

template <int NV>
using global_cable296_t = routing::global_cable<global_cable296_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain315_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable296_t<NV>>, 
                                    math::add<NV>>;
using global_cable297_t_index = global_cable6_t_index;

template <int NV>
using global_cable297_t = routing::global_cable<global_cable297_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain316_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable297_t<NV>>, 
                                    math::add<NV>>;
using global_cable298_t_index = global_cable5_t_index;

template <int NV>
using global_cable298_t = routing::global_cable<global_cable298_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain317_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable298_t<NV>>, 
                                    math::add<NV>>;
using global_cable299_t_index = global_cable4_t_index;

template <int NV>
using global_cable299_t = routing::global_cable<global_cable299_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain318_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable299_t<NV>>, 
                                    math::add<NV>>;
using global_cable300_t_index = global_cable3_t_index;

template <int NV>
using global_cable300_t = routing::global_cable<global_cable300_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain319_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable300_t<NV>>, 
                                    math::add<NV>>;
using global_cable301_t_index = global_cable45_t_index;

template <int NV>
using global_cable301_t = routing::global_cable<global_cable301_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain320_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable301_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch19_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain305_t<NV>>, 
                                     chain306_t<NV>, 
                                     chain307_t<NV>, 
                                     chain308_t<NV>, 
                                     chain309_t<NV>, 
                                     chain310_t<NV>, 
                                     chain311_t<NV>, 
                                     chain312_t<NV>, 
                                     chain313_t<NV>, 
                                     chain314_t<NV>, 
                                     chain315_t<NV>, 
                                     chain316_t<NV>, 
                                     chain317_t<NV>, 
                                     chain318_t<NV>, 
                                     chain319_t<NV>, 
                                     chain320_t<NV>>;

template <int NV> using pma19_mod = xfader_c0<NV>;

template <int NV>
using pma19_t = control::pma<NV, pma19_mod<NV>>;
template <int NV>
using peak24_t = wrap::mod<parameter::plain<pma19_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain304_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch19_t<NV>>, 
                                    peak24_t<NV>, 
                                    math::clear<NV>, 
                                    pma19_t<NV>>;
using global_cable302_t_index = global_cable_t_index;

template <int NV>
using global_cable302_t = routing::global_cable<global_cable302_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain322_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable302_t<NV>>, 
                                    math::add<NV>>;
using global_cable303_t_index = global_cable2_t_index;

template <int NV>
using global_cable303_t = routing::global_cable<global_cable303_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain323_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable303_t<NV>>, 
                                    math::add<NV>>;
using global_cable304_t_index = global_cable1_t_index;

template <int NV>
using global_cable304_t = routing::global_cable<global_cable304_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain324_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable304_t<NV>>, 
                                    math::add<NV>>;
using global_cable305_t_index = global_cable14_t_index;

template <int NV>
using global_cable305_t = routing::global_cable<global_cable305_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain325_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable305_t<NV>>, 
                                    math::add<NV>>;
using global_cable306_t_index = global_cable13_t_index;

template <int NV>
using global_cable306_t = routing::global_cable<global_cable306_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain326_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable306_t<NV>>, 
                                    math::add<NV>>;
using global_cable307_t_index = global_cable12_t_index;

template <int NV>
using global_cable307_t = routing::global_cable<global_cable307_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain327_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable307_t<NV>>, 
                                    math::add<NV>>;
using global_cable308_t_index = global_cable11_t_index;

template <int NV>
using global_cable308_t = routing::global_cable<global_cable308_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain328_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable308_t<NV>>, 
                                    math::add<NV>>;
using global_cable309_t_index = global_cable10_t_index;

template <int NV>
using global_cable309_t = routing::global_cable<global_cable309_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain329_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable309_t<NV>>, 
                                    math::add<NV>>;
using global_cable310_t_index = global_cable9_t_index;

template <int NV>
using global_cable310_t = routing::global_cable<global_cable310_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain330_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable310_t<NV>>, 
                                    math::add<NV>>;
using global_cable311_t_index = global_cable8_t_index;

template <int NV>
using global_cable311_t = routing::global_cable<global_cable311_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain331_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable311_t<NV>>, 
                                    math::add<NV>>;
using global_cable312_t_index = global_cable7_t_index;

template <int NV>
using global_cable312_t = routing::global_cable<global_cable312_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain332_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable312_t<NV>>, 
                                    math::add<NV>>;
using global_cable313_t_index = global_cable6_t_index;

template <int NV>
using global_cable313_t = routing::global_cable<global_cable313_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain333_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable313_t<NV>>, 
                                    math::add<NV>>;
using global_cable314_t_index = global_cable5_t_index;

template <int NV>
using global_cable314_t = routing::global_cable<global_cable314_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain334_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable314_t<NV>>, 
                                    math::add<NV>>;
using global_cable315_t_index = global_cable4_t_index;

template <int NV>
using global_cable315_t = routing::global_cable<global_cable315_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain335_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable315_t<NV>>, 
                                    math::add<NV>>;
using global_cable316_t_index = global_cable3_t_index;

template <int NV>
using global_cable316_t = routing::global_cable<global_cable316_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain336_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable316_t<NV>>, 
                                    math::add<NV>>;
using global_cable317_t_index = global_cable45_t_index;

template <int NV>
using global_cable317_t = routing::global_cable<global_cable317_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain337_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable317_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch20_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain322_t<NV>>, 
                                     chain323_t<NV>, 
                                     chain324_t<NV>, 
                                     chain325_t<NV>, 
                                     chain326_t<NV>, 
                                     chain327_t<NV>, 
                                     chain328_t<NV>, 
                                     chain329_t<NV>, 
                                     chain330_t<NV>, 
                                     chain331_t<NV>, 
                                     chain332_t<NV>, 
                                     chain333_t<NV>, 
                                     chain334_t<NV>, 
                                     chain335_t<NV>, 
                                     chain336_t<NV>, 
                                     chain337_t<NV>>;

DECLARE_PARAMETER_RANGE(pma20_modRange, 
                        -1., 
                        1.);

template <int NV>
using pma20_mod = parameter::from0To1<jdsp::jpanner<NV>, 
                                      0, 
                                      pma20_modRange>;

template <int NV>
using pma20_t = control::pma<NV, pma20_mod<NV>>;
template <int NV>
using peak25_t = wrap::mod<parameter::plain<pma20_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain321_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch20_t<NV>>, 
                                    peak25_t<NV>, 
                                    math::clear<NV>, 
                                    pma20_t<NV>>;
using global_cable110_t_index = global_cable_t_index;

template <int NV>
using global_cable110_t = routing::global_cable<global_cable110_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain118_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable110_t<NV>>, 
                                    math::add<NV>>;
using global_cable111_t_index = global_cable2_t_index;

template <int NV>
using global_cable111_t = routing::global_cable<global_cable111_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain119_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable111_t<NV>>, 
                                    math::add<NV>>;
using global_cable112_t_index = global_cable1_t_index;

template <int NV>
using global_cable112_t = routing::global_cable<global_cable112_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain120_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable112_t<NV>>, 
                                    math::add<NV>>;
using global_cable113_t_index = global_cable14_t_index;

template <int NV>
using global_cable113_t = routing::global_cable<global_cable113_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain121_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable113_t<NV>>, 
                                    math::add<NV>>;
using global_cable114_t_index = global_cable13_t_index;

template <int NV>
using global_cable114_t = routing::global_cable<global_cable114_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain122_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable114_t<NV>>, 
                                    math::add<NV>>;
using global_cable115_t_index = global_cable12_t_index;

template <int NV>
using global_cable115_t = routing::global_cable<global_cable115_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain123_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable115_t<NV>>, 
                                    math::add<NV>>;
using global_cable116_t_index = global_cable11_t_index;

template <int NV>
using global_cable116_t = routing::global_cable<global_cable116_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain124_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable116_t<NV>>, 
                                    math::add<NV>>;
using global_cable117_t_index = global_cable10_t_index;

template <int NV>
using global_cable117_t = routing::global_cable<global_cable117_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain125_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable117_t<NV>>, 
                                    math::add<NV>>;
using global_cable118_t_index = global_cable9_t_index;

template <int NV>
using global_cable118_t = routing::global_cable<global_cable118_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain126_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable118_t<NV>>, 
                                    math::add<NV>>;
using global_cable119_t_index = global_cable8_t_index;

template <int NV>
using global_cable119_t = routing::global_cable<global_cable119_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain127_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable119_t<NV>>, 
                                    math::add<NV>>;
using global_cable120_t_index = global_cable7_t_index;

template <int NV>
using global_cable120_t = routing::global_cable<global_cable120_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain128_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable120_t<NV>>, 
                                    math::add<NV>>;
using global_cable121_t_index = global_cable6_t_index;

template <int NV>
using global_cable121_t = routing::global_cable<global_cable121_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain129_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable121_t<NV>>, 
                                    math::add<NV>>;
using global_cable122_t_index = global_cable5_t_index;

template <int NV>
using global_cable122_t = routing::global_cable<global_cable122_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain130_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable122_t<NV>>, 
                                    math::add<NV>>;
using global_cable123_t_index = global_cable4_t_index;

template <int NV>
using global_cable123_t = routing::global_cable<global_cable123_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain131_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable123_t<NV>>, 
                                    math::add<NV>>;
using global_cable124_t_index = global_cable3_t_index;

template <int NV>
using global_cable124_t = routing::global_cable<global_cable124_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain132_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable124_t<NV>>, 
                                    math::add<NV>>;
using global_cable125_t_index = global_cable45_t_index;

template <int NV>
using global_cable125_t = routing::global_cable<global_cable125_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain133_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable125_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain118_t<NV>>, 
                                    chain119_t<NV>, 
                                    chain120_t<NV>, 
                                    chain121_t<NV>, 
                                    chain122_t<NV>, 
                                    chain123_t<NV>, 
                                    chain124_t<NV>, 
                                    chain125_t<NV>, 
                                    chain126_t<NV>, 
                                    chain127_t<NV>, 
                                    chain128_t<NV>, 
                                    chain129_t<NV>, 
                                    chain130_t<NV>, 
                                    chain131_t<NV>, 
                                    chain132_t<NV>, 
                                    chain133_t<NV>>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<snex_node_t<NV>, 2>, 
                               control::tempo_sync<NV>>;
template <int NV>
using pma7_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                     0, 
                                     pma21_modRange>;

template <int NV>
using pma7_t = control::pma<NV, pma7_mod<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma8_modRange, 
                             5, 
                             1000., 
                             0.1);

template <int NV>
using pma8_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                     3, 
                                     pma8_modRange>;

template <int NV>
using pma8_t = control::pma<NV, pma8_mod<NV>>;

template <int NV>
using peak7_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma7_t<NV>, 0>, 
                                   parameter::plain<pma8_t<NV>, 0>>;

template <int NV>
using peak7_t = wrap::mod<peak7_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain117_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch7_t<NV>>, 
                                    peak7_t<NV>, 
                                    math::clear<NV>, 
                                    pma8_t<NV>, 
                                    pma7_t<NV>, 
                                    tempo_sync_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain_t<NV>>, 
                                 chain49_t<NV>, 
                                 chain66_t<NV>, 
                                 chain83_t<NV>, 
                                 chain100_t<NV>, 
                                 chain134_t<NV>, 
                                 chain151_t<NV>, 
                                 chain168_t<NV>, 
                                 chain185_t<NV>, 
                                 chain202_t<NV>, 
                                 chain219_t<NV>, 
                                 chain236_t<NV>, 
                                 chain253_t<NV>, 
                                 chain287_t<NV>, 
                                 chain270_t<NV>, 
                                 chain304_t<NV>, 
                                 chain321_t<NV>, 
                                 chain117_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

struct cable_table4_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.00354689f,
		0.00956458f, 0.0155822f, 0.0215998f, 0.0276173f, 0.033635f, 0.0396526f,
		0.0456702f, 0.0516878f, 0.0577055f, 0.0637231f, 0.0697407f, 0.0757583f,
		0.081776f, 0.0877935f, 0.0938111f, 0.0998287f, 0.105846f, 0.111864f,
		0.117882f, 0.123899f, 0.129917f, 0.135934f, 0.141952f, 0.14797f,
		0.153987f, 0.160005f, 0.166022f, 0.17204f, 0.178058f, 0.184075f,
		0.190093f, 0.19611f, 0.202128f, 0.208146f, 0.214163f, 0.220181f,
		0.226199f, 0.232216f, 0.238234f, 0.244251f, 0.250269f, 0.256287f,
		0.262304f, 0.268322f, 0.27434f, 0.280357f, 0.286375f, 0.292392f,
		0.29841f, 0.304428f, 0.310445f, 0.316463f, 0.32248f, 0.328498f,
		0.334516f, 0.340533f, 0.346551f, 0.352569f, 0.358586f, 0.364604f,
		0.370621f, 0.376639f, 0.382656f, 0.388674f, 0.394692f, 0.400709f,
		0.406727f, 0.412745f, 0.418762f, 0.42478f, 0.430797f, 0.436815f,
		0.442833f, 0.44885f, 0.454868f, 0.460885f, 0.466903f, 0.472921f,
		0.478938f, 0.484956f, 0.490974f, 0.496991f, 0.503009f, 0.509026f,
		0.515044f, 0.521061f, 0.527079f, 0.533097f, 0.539114f, 0.545132f,
		0.55115f, 0.557167f, 0.563185f, 0.569202f, 0.57522f, 0.581238f,
		0.587255f, 0.593273f, 0.599291f, 0.605308f, 0.611326f, 0.617343f,
		0.623361f, 0.629379f, 0.635396f, 0.641414f, 0.647431f, 0.653449f,
		0.659467f, 0.665484f, 0.671502f, 0.67752f, 0.683537f, 0.689555f,
		0.695572f, 0.70159f, 0.707608f, 0.713625f, 0.719643f, 0.72566f,
		0.731678f, 0.737696f, 0.743713f, 0.749731f, 0.755748f, 0.761766f,
		0.767784f, 0.773801f, 0.779819f, 0.785837f, 0.791854f, 0.797872f,
		0.803889f, 0.809907f, 0.815925f, 0.821942f, 0.82796f, 0.833977f,
		0.839995f, 0.846013f, 0.85203f, 0.858048f, 0.864066f, 0.870083f,
		0.876101f, 0.882118f, 0.888136f, 0.894153f, 0.900171f, 0.906189f,
		0.912206f, 0.918224f, 0.924242f, 0.930259f, 0.936277f, 0.942294f,
		0.948312f, 0.95433f, 0.960347f, 0.966365f, 0.972382f, 0.9784f,
		0.984418f, 0.990435f, 0.996453f, 0.997619f, 0.991819f, 0.986018f,
		0.980218f, 0.974418f, 0.968618f, 0.962818f, 0.957018f, 0.951218f,
		0.945418f, 0.939618f, 0.933818f, 0.928017f, 0.922217f, 0.916417f,
		0.910617f, 0.904817f, 0.899017f, 0.893217f, 0.887417f, 0.881617f,
		0.875816f, 0.870016f, 0.864216f, 0.858416f, 0.852616f, 0.846816f,
		0.841016f, 0.835216f, 0.829416f, 0.823615f, 0.817815f, 0.812015f,
		0.806215f, 0.800415f, 0.794615f, 0.788815f, 0.783015f, 0.777215f,
		0.771415f, 0.765614f, 0.759814f, 0.754014f, 0.748214f, 0.742414f,
		0.736614f, 0.730814f, 0.725014f, 0.719214f, 0.713413f, 0.707613f,
		0.701813f, 0.696013f, 0.690213f, 0.684413f, 0.678613f, 0.672813f,
		0.667012f, 0.661212f, 0.655412f, 0.649612f, 0.643812f, 0.638012f,
		0.632212f, 0.626412f, 0.620612f, 0.614812f, 0.609011f, 0.603211f,
		0.597411f, 0.591611f, 0.585811f, 0.580011f, 0.574211f, 0.568411f,
		0.562611f, 0.55681f, 0.55101f, 0.54521f, 0.53941f, 0.53361f,
		0.52781f, 0.52201f, 0.51621f, 0.51041f, 0.504609f, 0.498809f,
		0.493009f, 0.487209f, 0.481409f, 0.475609f, 0.469809f, 0.464009f,
		0.458209f, 0.452409f, 0.446608f, 0.440808f, 0.435008f, 0.429208f,
		0.423408f, 0.417608f, 0.411808f, 0.406008f, 0.400208f, 0.394408f,
		0.388607f, 0.382807f, 0.377007f, 0.371207f, 0.365407f, 0.359607f,
		0.353807f, 0.348007f, 0.342206f, 0.336406f, 0.330606f, 0.324806f,
		0.319006f, 0.313206f, 0.307406f, 0.301606f, 0.295806f, 0.290005f,
		0.284205f, 0.278405f, 0.272605f, 0.266805f, 0.261005f, 0.255205f,
		0.249405f, 0.243605f, 0.237804f, 0.232004f, 0.226204f, 0.220404f,
		0.214604f, 0.208804f, 0.203004f, 0.197204f, 0.191404f, 0.185603f,
		0.179803f, 0.174003f, 0.168203f, 0.162403f, 0.156603f, 0.150803f,
		0.145003f, 0.139203f, 0.133403f, 0.127602f, 0.121802f, 0.116002f,
		0.110202f, 0.104402f, 0.0986019f, 0.0928017f, 0.0870017f, 0.0812016f,
		0.0754015f, 0.0696014f, 0.0638012f, 0.0580011f, 0.052201f, 0.0464009f,
		0.0406008f, 0.0348008f, 0.0290006f, 0.0232006f, 0.0174003f, 0.0116002f,
		0.00580013f, 0.f
	};
};

template <int NV>
using cable_table4_t = wrap::data<control::cable_table<parameter::plain<input_toggle_t<NV>, 0>>, 
                                  data::embedded::table<cable_table4_t_data>>;

template <int NV>
using fix8_block_t = container::chain<parameter::empty, 
                                      wrap::fix<2, modchain_t<NV>>, 
                                      tempo_sync1_t<NV>, 
                                      cable_table4_t<NV>, 
                                      input_toggle_t<NV>>;

using global_cable15_t_index = runtime_target::indexers::fix_hash<162771259>;
using peak1_mod = parameter::plain<routing::global_cable<global_cable15_t_index, parameter::empty>, 
                                   0>;
using peak1_t = wrap::mod<peak1_mod, 
                          wrap::no_data<core::peak>>;

using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak1_t>, 
                                   routing::global_cable<global_cable15_t_index, parameter::empty>>;

using global_cable18_t_index = runtime_target::indexers::fix_hash<162771260>;
using peak19_mod = parameter::plain<routing::global_cable<global_cable18_t_index, parameter::empty>, 
                                    0>;
using peak19_t = wrap::mod<peak19_mod, 
                           wrap::no_data<core::peak>>;

using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak19_t>, 
                                   routing::global_cable<global_cable18_t_index, parameter::empty>>;

using global_cable17_t_index = runtime_target::indexers::fix_hash<162771261>;
using peak18_mod = parameter::plain<routing::global_cable<global_cable17_t_index, parameter::empty>, 
                                    0>;
using peak18_t = wrap::mod<peak18_mod, 
                           wrap::no_data<core::peak>>;

using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak18_t>, 
                                   routing::global_cable<global_cable17_t_index, parameter::empty>>;

using global_cable16_t_index = runtime_target::indexers::fix_hash<162771262>;
using peak2_mod = parameter::plain<routing::global_cable<global_cable16_t_index, parameter::empty>, 
                                   0>;
using peak2_t = wrap::mod<peak2_mod, 
                          wrap::no_data<core::peak>>;

using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak2_t>, 
                                   routing::global_cable<global_cable16_t_index, parameter::empty>>;
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain25_t>, 
                                    chain28_t, 
                                    chain27_t, 
                                    chain26_t>;

template <int NV> using xfader1_c0 = xfader_c0<NV>;

template <int NV> using xfader1_c1 = xfader_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::svf<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain24_t<NV>>, 
                                  chain33_t<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader1_t<NV>>, 
                                   split3_t<NV>>;

template <int NV> using chain22_t = chain24_t<NV>;

using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

template <int NV>
using converter6_t = control::converter<parameter::plain<pma_unscaled3_t<NV>, 0>, 
                                        conversion_logic::midi2freq>;
template <int NV>
using midi3_t = wrap::mod<parameter::plain<converter6_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using offline2_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, converter6_t<NV>>, 
                                     converter7_t<NV>>;

template <int NV>
using offline2_t = wrap::offline<offline2_t_<NV>>;

// Calculate the delay time from the incoming note number ------------------------------------------

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<2, midi3_t<NV>>, 
                                   offline2_t<NV>>;
template <int NV>
using stereo_frame_cable = cable::frame<NV, 2>;

template <int NV>
using frame2_block1_t_ = container::chain<parameter::empty, 
                                          wrap::fix<2, pma_unscaled3_t<NV>>, 
                                          routing::receive<NV, stereo_frame_cable<NV>>, 
                                          filters::one_pole<NV>, 
                                          wrap::no_process<core::fix_delay>, 
                                          jdsp::jdelay_thiran<NV>, 
                                          routing::send<NV, stereo_frame_cable<NV>>, 
                                          filters::one_pole<NV>>;

template <int NV>
using frame2_block1_t = wrap::frame<2, frame2_block1_t_<NV>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain41_t<NV>>, 
                                   frame2_block1_t<NV>>;

template <int NV>
using fix8_block1_t = container::chain<parameter::empty, 
                                       wrap::fix<2, chain18_t<NV>>>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, project::res2<NV>>, 
                                       core::gain<NV>>;
template <int NV>
using clone_t = wrap::fix_clonecopy<clone_child_t<NV>, 8>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, clone_cable_t<NV>>, 
                                   clone_cable1_t<NV>, 
                                   cable_table6_t<NV>, 
                                   clone_cable2_t<NV>, 
                                   clone_t<NV>, 
                                   filters::one_pole<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain20_t>, 
                                    fix8_block1_t<NV>, 
                                    chain17_t<NV>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch1_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain22_t<NV>>, 
                                  chain19_t<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split1_t<NV>>>;

template <int NV> using xfader2_c0 = xfader_c0<NV>;

template <int NV> using xfader2_c1 = xfader_c0<NV>;

template <int NV>
using xfader2_multimod = parameter::list<xfader2_c0<NV>, xfader2_c1<NV>>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::linear>;

template <int NV> using chain35_t = chain24_t<NV>;

template <int NV> using chain36_t = chain33_t<NV>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain35_t<NV>>, 
                                  chain36_t<NV>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader2_t<NV>>, 
                                   split4_t<NV>>;

using global_cable19_t_index = runtime_target::indexers::fix_hash<-1533890749>;
using peak20_mod = parameter::plain<routing::global_cable<global_cable19_t_index, parameter::empty>, 
                                    0>;
using peak20_t = wrap::mod<peak20_mod, 
                           wrap::no_data<core::peak>>;

using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak20_t>, 
                                   routing::global_cable<global_cable19_t_index, parameter::empty>>;

using global_cable20_t_index = runtime_target::indexers::fix_hash<-1533890748>;
using peak21_mod = parameter::plain<routing::global_cable<global_cable20_t_index, parameter::empty>, 
                                    0>;
using peak21_t = wrap::mod<peak21_mod, 
                           wrap::no_data<core::peak>>;

using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak21_t>, 
                                   routing::global_cable<global_cable20_t_index, parameter::empty>>;

using global_cable21_t_index = runtime_target::indexers::fix_hash<-1533890747>;
using peak22_mod = parameter::plain<routing::global_cable<global_cable21_t_index, parameter::empty>, 
                                    0>;
using peak22_t = wrap::mod<peak22_mod, 
                           wrap::no_data<core::peak>>;

using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak22_t>, 
                                   routing::global_cable<global_cable21_t_index, parameter::empty>>;

using global_cable22_t_index = runtime_target::indexers::fix_hash<-1533890746>;
using peak23_mod = parameter::plain<routing::global_cable<global_cable22_t_index, parameter::empty>, 
                                    0>;
using peak23_t = wrap::mod<peak23_mod, 
                           wrap::no_data<core::peak>>;

using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak23_t>, 
                                   routing::global_cable<global_cable22_t_index, parameter::empty>>;
using branch18_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain29_t>, 
                                     chain30_t, 
                                     chain31_t, 
                                     chain32_t>;

namespace sn_t_parameters
{
// Parameter list for sn_impl::sn_t ----------------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(PitchMode_InputRange, 
                             1., 
                             4., 
                             1.);

template <int NV>
using PitchMode = parameter::chain<PitchMode_InputRange, 
                                   parameter::plain<sn_impl::cable_table4_t<NV>, 0>, 
                                   parameter::plain<sn_impl::snex_node_t<NV>, 6>>;

DECLARE_PARAMETER_RANGE_STEP(scrubMode_InputRange, 
                             1., 
                             4., 
                             1.);

template <int NV>
using scrubMode = parameter::chain<scrubMode_InputRange, 
                                   parameter::plain<sn_impl::snex_node_t<NV>, 9>>;

DECLARE_PARAMETER_RANGE_STEP(reverse_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(reverse_0Range, 
                             0., 
                             1., 
                             1.);

template <int NV>
using reverse_0 = parameter::from0To1<sn_impl::snex_node_t<NV>, 
                                      11, 
                                      reverse_0Range>;

template <int NV>
using reverse = parameter::chain<reverse_InputRange, reverse_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(PositionSrc_InputRange, 
                             1., 
                             16., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(PositionSrc_0Range, 
                             0., 
                             15., 
                             1.);

template <int NV>
using PositionSrc_0 = parameter::from0To1<sn_impl::branch_t<NV>, 
                                          0, 
                                          PositionSrc_0Range>;

template <int NV>
using PositionSrc = parameter::chain<PositionSrc_InputRange, PositionSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Pos2Src_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using Pos2Src_0 = parameter::from0To1<sn_impl::branch3_t<NV>, 
                                      0, 
                                      PositionSrc_0Range>;

template <int NV>
using Pos2Src = parameter::chain<Pos2Src_InputRange, Pos2Src_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Pos3Src_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using Pos3Src_0 = parameter::from0To1<sn_impl::branch4_t<NV>, 
                                      0, 
                                      PositionSrc_0Range>;

template <int NV>
using Pos3Src = parameter::chain<Pos3Src_InputRange, Pos3Src_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Pos4Src_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using Pos4Src_0 = parameter::from0To1<sn_impl::branch5_t<NV>, 
                                      0, 
                                      PositionSrc_0Range>;

template <int NV>
using Pos4Src = parameter::chain<Pos4Src_InputRange, Pos4Src_0<NV>>;

DECLARE_PARAMETER_RANGE(Pitch_InputRange, 
                        -12., 
                        12.);

template <int NV>
using Pitch = parameter::chain<Pitch_InputRange, 
                               parameter::plain<sn_impl::pma6_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(PitchSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using PitchSrc_0 = parameter::from0To1<sn_impl::branch6_t<NV>, 
                                       0, 
                                       PositionSrc_0Range>;

template <int NV>
using PitchSrc = parameter::chain<PitchSrc_InputRange, PitchSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(DenseSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using DenseSrc_0 = parameter::from0To1<sn_impl::branch8_t<NV>, 
                                       0, 
                                       PositionSrc_0Range>;

template <int NV>
using DenseSrc = parameter::chain<DenseSrc_InputRange, DenseSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(WinShapeSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using WinShapeSrc_0 = parameter::from0To1<sn_impl::branch9_t<NV>, 
                                          0, 
                                          PositionSrc_0Range>;

template <int NV>
using WinShapeSrc = parameter::chain<WinShapeSrc_InputRange, WinShapeSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(PanSprdsrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using PanSprdsrc_0 = parameter::from0To1<sn_impl::branch10_t<NV>, 
                                         0, 
                                         PositionSrc_0Range>;

template <int NV>
using PanSprdsrc = parameter::chain<PanSprdsrc_InputRange, PanSprdsrc_0<NV>>;

template <int NV>
using PitchSprdMod = parameter::chain<ranges::Identity, 
                                      parameter::plain<sn_impl::pma12_t<NV>, 1>, 
                                      parameter::plain<sn_impl::pma21_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(PitchSprdSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using PitchSprdSrc_0 = parameter::from0To1<sn_impl::branch11_t<NV>, 
                                           0, 
                                           PositionSrc_0Range>;

template <int NV>
using PitchSprdSrc = parameter::chain<PitchSprdSrc_InputRange, 
                                      PitchSprdSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(phaseScatterSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using phaseScatterSrc_0 = parameter::from0To1<sn_impl::branch12_t<NV>, 
                                              0, 
                                              PositionSrc_0Range>;

template <int NV>
using phaseScatterSrc = parameter::chain<phaseScatterSrc_InputRange, 
                                         phaseScatterSrc_0<NV>>;

DECLARE_PARAMETER_RANGE(GrainSize_InputRange, 
                        5., 
                        1000.);

template <int NV>
using GrainSize = parameter::chain<GrainSize_InputRange, 
                                   parameter::plain<sn_impl::pma8_t<NV>, 2>>;

template <int NV>
using GrainMod = parameter::chain<ranges::Identity, 
                                  parameter::plain<sn_impl::pma7_t<NV>, 1>, 
                                  parameter::plain<sn_impl::pma8_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(GrainSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using GrainSrc_0 = parameter::from0To1<sn_impl::branch7_t<NV>, 
                                       0, 
                                       PositionSrc_0Range>;

template <int NV>
using GrainSrc = parameter::chain<GrainSrc_InputRange, GrainSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(GrainTempo_InputRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using GrainTempo = parameter::chain<GrainTempo_InputRange, 
                                    parameter::plain<sn_impl::pma7_t<NV>, 2>>;

template <int NV>
using GrainSync = parameter::from0To1<sn_impl::tempo_sync_t<NV>, 
                                      2, 
                                      reverse_0Range>;

template <int NV>
using PreCutSrc = parameter::from0To1<sn_impl::branch13_t<NV>, 
                                      0, 
                                      PositionSrc_0Range>;

DECLARE_PARAMETER_RANGE_STEP(PreCutMode_InputRange, 
                             1., 
                             5., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(PreCutMode_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using PreCutMode_0 = parameter::from0To1<filters::svf<NV>, 
                                         4, 
                                         PreCutMode_0Range>;

template <int NV>
using PreCutMode = parameter::chain<PreCutMode_InputRange, PreCutMode_0<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(PreCutQRange, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using PreCutQ = parameter::from0To1<filters::svf<NV>, 
                                    1, 
                                    PreCutQRange>;

DECLARE_PARAMETER_RANGE_STEP(ResoSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using ResoSrc_0 = parameter::from0To1<sn_impl::branch14_t<NV>, 
                                      0, 
                                      PositionSrc_0Range>;

template <int NV>
using ResoSrc = parameter::chain<ResoSrc_InputRange, ResoSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ResPitchSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using ResPitchSrc_0 = parameter::from0To1<sn_impl::branch15_t<NV>, 
                                          0, 
                                          PositionSrc_0Range>;

template <int NV>
using ResPitchSrc = parameter::chain<ResPitchSrc_InputRange, ResPitchSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ResLpSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using ResLpSrc_0 = parameter::from0To1<sn_impl::branch17_t<NV>, 
                                       0, 
                                       PositionSrc_0Range>;

template <int NV>
using ResLpSrc = parameter::chain<ResLpSrc_InputRange, ResLpSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(PostCutSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using PostCutSrc_0 = parameter::from0To1<sn_impl::branch16_t<NV>, 
                                         0, 
                                         PositionSrc_0Range>;

template <int NV>
using PostCutSrc = parameter::chain<PostCutSrc_InputRange, PostCutSrc_0<NV>>;

template <int NV> using PostQ = PreCutQ<NV>;

DECLARE_PARAMETER_RANGE_STEP(PostMode_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV> using PostMode_0 = PreCutMode_0<NV>;

template <int NV>
using PostMode = parameter::chain<PostMode_InputRange, PostMode_0<NV>>;

template <int NV>
using gainSrc = parameter::from0To1<sn_impl::branch19_t<NV>, 
                                    0, 
                                    PositionSrc_0Range>;

DECLARE_PARAMETER_RANGE(Parn_InputRange, 
                        -1., 
                        1.);

template <int NV>
using Parn = parameter::chain<Parn_InputRange, 
                              parameter::plain<sn_impl::pma20_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(PanSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using PanSrc_0 = parameter::from0To1<sn_impl::branch20_t<NV>, 
                                     0, 
                                     PositionSrc_0Range>;

template <int NV>
using PanSrc = parameter::chain<PanSrc_InputRange, PanSrc_0<NV>>;

DECLARE_PARAMETER_RANGE(feedRange, 
                        0.9, 
                        1.);

template <int NV>
using feed = parameter::from0To1<routing::receive<NV, stereo_frame_cable<NV>>, 
                                 0, 
                                 feedRange>;

DECLARE_PARAMETER_RANGE_STEP(PitchTempo_InputRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using PitchTempo = parameter::chain<PitchTempo_InputRange, 
                                    parameter::plain<sn_impl::pma21_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(delMode_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(delMode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using delMode_0 = parameter::from0To1<sn_impl::branch1_t<NV>, 
                                      0, 
                                      delMode_0Range>;

template <int NV>
using delMode = parameter::chain<delMode_InputRange, delMode_0<NV>>;

template <int NV>
using MaxGrains = parameter::plain<sn_impl::snex_node_t<NV>, 
                                   8>;
template <int NV>
using scrubBlen = parameter::plain<sn_impl::snex_node_t<NV>, 
                                   10>;
template <int NV>
using Position = parameter::plain<sn_impl::pma_t<NV>, 2>;
template <int NV>
using PositionMod = parameter::plain<sn_impl::pma_t<NV>, 1>;
template <int NV>
using Pos2 = parameter::plain<sn_impl::pma3_t<NV>, 2>;
template <int NV>
using Pos2Mod = parameter::plain<sn_impl::pma3_t<NV>, 1>;
template <int NV>
using Pos3 = parameter::plain<sn_impl::pma4_t<NV>, 2>;
template <int NV>
using Pos3Mod = parameter::plain<sn_impl::pma4_t<NV>, 1>;
template <int NV>
using Pos4 = parameter::plain<sn_impl::pma5_t<NV>, 2>;
template <int NV>
using Pos4Mod = parameter::plain<sn_impl::pma5_t<NV>, 1>;
template <int NV>
using PitchMod = parameter::plain<sn_impl::pma6_t<NV>, 1>;
template <int NV>
using Dense = parameter::plain<sn_impl::pma9_t<NV>, 2>;
template <int NV>
using DenseMod = parameter::plain<sn_impl::pma9_t<NV>, 1>;
template <int NV>
using WinShape = parameter::plain<sn_impl::pma10_t<NV>, 2>;
template <int NV>
using PanSpread = parameter::plain<sn_impl::pma11_t<NV>, 2>;
template <int NV>
using PanSpreadMod = parameter::plain<sn_impl::pma11_t<NV>, 1>;
template <int NV>
using PitchSprd = parameter::plain<sn_impl::pma12_t<NV>, 2>;
template <int NV>
using phaseScatter = parameter::plain<sn_impl::pma2_t<NV>, 2>;
template <int NV>
using phaseScatterMod = parameter::plain<sn_impl::pma2_t<NV>, 1>;
template <int NV>
using GrainDiv = parameter::plain<sn_impl::tempo_sync_t<NV>, 
                                  1>;
template <int NV>
using WinShapeMod = parameter::plain<sn_impl::pma10_t<NV>, 1>;
template <int NV>
using PreCut = parameter::plain<sn_impl::pma14_t<NV>, 2>;
template <int NV>
using PreCutMod = parameter::plain<sn_impl::pma14_t<NV>, 1>;
template <int NV>
using ResoMix = parameter::plain<sn_impl::pma15_t<NV>, 2>;
template <int NV>
using ResoMixMod = parameter::plain<sn_impl::pma15_t<NV>, 1>;
template <int NV>
using ResPitch = parameter::plain<sn_impl::pma16_t<NV>, 2>;
template <int NV>
using RespPitchMod = parameter::plain<sn_impl::pma16_t<NV>, 1>;
template <int NV>
using ResLp = parameter::plain<sn_impl::pma18_t<NV>, 2>;
template <int NV>
using ResLpMod = parameter::plain<sn_impl::pma18_t<NV>, 1>;
template <int NV>
using PostCut = parameter::plain<sn_impl::pma17_t<NV>, 2>;
template <int NV>
using PostCutMod = parameter::plain<sn_impl::pma17_t<NV>, 1>;
using GrainOut = parameter::plain<sn_impl::branch2_t, 0>;
using ResOut = parameter::plain<sn_impl::branch18_t, 0>;
template <int NV>
using GainMod = parameter::plain<sn_impl::pma19_t<NV>, 1>;
template <int NV>
using Vol = parameter::plain<sn_impl::pma19_t<NV>, 2>;
template <int NV>
using PanMod = parameter::plain<sn_impl::pma20_t<NV>, 1>;
template <int NV>
using Fmix1 = parameter::plain<sn_impl::xfader1_t<NV>, 0>;
template <int NV>
using Fmix2 = parameter::plain<sn_impl::xfader2_t<NV>, 0>;
template <int NV>
using PitchDiv = parameter::plain<sn_impl::tempo_sync1_t<NV>, 
                                  1>;
using JitSync = parameter::empty;
template <int NV>
using sn_t_plist = parameter::list<PitchMode<NV>, 
                                   MaxGrains<NV>, 
                                   scrubMode<NV>, 
                                   scrubBlen<NV>, 
                                   reverse<NV>, 
                                   Position<NV>, 
                                   PositionMod<NV>, 
                                   PositionSrc<NV>, 
                                   Pos2<NV>, 
                                   Pos2Mod<NV>, 
                                   Pos2Src<NV>, 
                                   Pos3<NV>, 
                                   Pos3Mod<NV>, 
                                   Pos3Src<NV>, 
                                   Pos4<NV>, 
                                   Pos4Mod<NV>, 
                                   Pos4Src<NV>, 
                                   Pitch<NV>, 
                                   PitchMod<NV>, 
                                   PitchSrc<NV>, 
                                   Dense<NV>, 
                                   DenseMod<NV>, 
                                   DenseSrc<NV>, 
                                   WinShape<NV>, 
                                   WinShapeSrc<NV>, 
                                   PanSpread<NV>, 
                                   PanSpreadMod<NV>, 
                                   PanSprdsrc<NV>, 
                                   PitchSprd<NV>, 
                                   PitchSprdMod<NV>, 
                                   PitchSprdSrc<NV>, 
                                   phaseScatter<NV>, 
                                   phaseScatterMod<NV>, 
                                   phaseScatterSrc<NV>, 
                                   GrainSize<NV>, 
                                   GrainMod<NV>, 
                                   GrainSrc<NV>, 
                                   GrainTempo<NV>, 
                                   GrainDiv<NV>, 
                                   GrainSync<NV>, 
                                   WinShapeMod<NV>, 
                                   PreCut<NV>, 
                                   PreCutMod<NV>, 
                                   PreCutSrc<NV>, 
                                   PreCutMode<NV>, 
                                   PreCutQ<NV>, 
                                   ResoMix<NV>, 
                                   ResoMixMod<NV>, 
                                   ResoSrc<NV>, 
                                   ResPitch<NV>, 
                                   RespPitchMod<NV>, 
                                   ResPitchSrc<NV>, 
                                   ResLp<NV>, 
                                   ResLpMod<NV>, 
                                   ResLpSrc<NV>, 
                                   PostCut<NV>, 
                                   PostCutMod<NV>, 
                                   PostCutSrc<NV>, 
                                   PostQ<NV>, 
                                   PostMode<NV>, 
                                   GrainOut, 
                                   ResOut, 
                                   GainMod<NV>, 
                                   gainSrc<NV>, 
                                   Vol<NV>, 
                                   Parn<NV>, 
                                   PanMod<NV>, 
                                   PanSrc<NV>, 
                                   Fmix1<NV>, 
                                   Fmix2<NV>, 
                                   feed<NV>, 
                                   PitchTempo<NV>, 
                                   PitchDiv<NV>, 
                                   delMode<NV>, 
                                   JitSync>;
}

template <int NV>
using sn_t_ = container::chain<sn_t_parameters::sn_t_plist<NV>, 
                               wrap::fix<2, fix8_block_t<NV>>, 
                               snex_node_t<NV>, 
                               branch2_t, 
                               chain23_t<NV>, 
                               xfader_t<NV>, 
                               chain16_t<NV>, 
                               chain34_t<NV>, 
                               core::gain<NV>, 
                               jdsp::jpanner<NV>, 
                               branch18_t>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public sn_impl::sn_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 4;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(sn);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(1354)
		{
			0x005C, 0x0000, 0x0000, 0x6950, 0x6374, 0x4D68, 0x646F, 0x0065, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x4000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x0100, 0x0000, 0x4D00, 0x7861, 0x7247, 
            0x6961, 0x736E, 0x0000, 0x0000, 0x4080, 0x0000, 0x4200, 0x0000, 
            0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0002, 0x0000, 
            0x6373, 0x7572, 0x4D62, 0x646F, 0x0065, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0040, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x0300, 0x0000, 0x7300, 0x7263, 0x6275, 0x6C42, 0x6E65, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0004, 0x0000, 0x6572, 0x6576, 0x7372, 
            0x0065, 0x0000, 0x8000, 0x003F, 0x4000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5C3F, 0x0500, 0x0000, 0x5000, 0x736F, 
            0x7469, 0x6F69, 0x006E, 0x0000, 0x0000, 0x0000, 0x8000, 0xEC3F, 
            0xB851, 0x003E, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0600, 0x0000, 
            0x5000, 0x736F, 0x7469, 0x6F69, 0x4D6E, 0x646F, 0x0000, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x3D71, 0xBF0A, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0007, 0x0000, 0x6F50, 0x6973, 0x6974, 0x6E6F, 
            0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x4000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0800, 0x0000, 0x5000, 
            0x736F, 0x0032, 0x0000, 0x0000, 0x0000, 0x8000, 0xB83F, 0x451E, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0900, 0x0000, 0x5000, 
            0x736F, 0x4D32, 0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000A, 
            0x0000, 0x6F50, 0x3273, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0041, 0x5000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x0B00, 0x0000, 0x5000, 0x736F, 0x0033, 0x0000, 0x0000, 0x0000, 
            0x8000, 0xC33F, 0xA8F5, 0x003E, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0C00, 0x0000, 0x5000, 0x736F, 0x4D33, 0x646F, 0x0000, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x000D, 0x0000, 0x6F50, 0x3373, 0x7253, 0x0063, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x0E00, 0x0000, 0x5000, 0x736F, 0x0034, 
            0x0000, 0x0000, 0x0000, 0x8000, 0xB83F, 0x051E, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x0F00, 0x0000, 0x5000, 0x736F, 0x4D34, 
            0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0010, 0x0000, 0x6F50, 
            0x3473, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x1100, 0x0000, 
            0x5000, 0x7469, 0x6863, 0x0000, 0x0000, 0xC140, 0x0000, 0x4140, 
            0x0000, 0x3440, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0012, 
            0x0000, 0x6950, 0x6374, 0x4D68, 0x646F, 0x0000, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0xD70A, 0xBC23, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0013, 0x0000, 0x6950, 0x6374, 0x5368, 0x6372, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x4150, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x0014, 0x0000, 0x6544, 0x736E, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x1500, 0x0000, 0x4400, 0x6E65, 0x6573, 
            0x6F4D, 0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 0x8F3F, 0xF5C2, 
            0x003C, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1600, 0x0000, 0x4400, 
            0x6E65, 0x6573, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0041, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x1700, 
            0x0000, 0x5700, 0x6E69, 0x6853, 0x7061, 0x0065, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x1800, 0x0000, 0x5700, 0x6E69, 0x6853, 0x7061, 0x5365, 
            0x6372, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0019, 0x0000, 0x6150, 
            0x536E, 0x7270, 0x6165, 0x0064, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x713F, 0x8A3D, 0x003E, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1A00, 
            0x0000, 0x5000, 0x6E61, 0x7053, 0x6572, 0x6461, 0x6F4D, 0x0064, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x1B00, 0x0000, 0x5000, 0x6E61, 0x7053, 
            0x6472, 0x7273, 0x0063, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 
            0x6000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x1C00, 0x0000, 
            0x5000, 0x7469, 0x6863, 0x7053, 0x6472, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x7AE1, 0x3F14, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x001D, 0x0000, 0x6950, 0x6374, 0x5368, 0x7270, 0x4D64, 
            0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x001E, 0x0000, 0x6950, 
            0x6374, 0x5368, 0x7270, 0x5364, 0x6372, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x4180, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x001F, 0x0000, 0x6870, 0x7361, 0x5365, 0x6163, 0x7474, 
            0x7265, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0020, 0x0000, 0x6870, 
            0x7361, 0x5365, 0x6163, 0x7474, 0x7265, 0x6F4D, 0x0064, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x663F, 0x2A66, 0x00BD, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x2100, 0x0000, 0x7000, 0x6168, 0x6573, 0x6353, 
            0x7461, 0x6574, 0x5372, 0x6372, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x4180, 0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x0022, 0x0000, 0x7247, 0x6961, 0x536E, 0x7A69, 0x0065, 0x0000, 
            0xA000, 0x0040, 0x7A00, 0x0044, 0xE800, 0x0043, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x2300, 0x0000, 0x4700, 0x6172, 0x6E69, 0x6F4D, 
            0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x2400, 0x0000, 0x4700, 0x6172, 
            0x6E69, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 
            0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x2500, 0x0000, 
            0x4700, 0x6172, 0x6E69, 0x6554, 0x706D, 0x006F, 0x0000, 0x0000, 
            0x0000, 0x9000, 0x0041, 0x2000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x2600, 0x0000, 0x4700, 0x6172, 0x6E69, 0x6944, 0x0076, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x2700, 0x0000, 0x4700, 0x6172, 0x6E69, 
            0x7953, 0x636E, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0028, 0x0000, 
            0x6957, 0x536E, 0x6168, 0x6570, 0x6F4D, 0x0064, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x2900, 0x0000, 0x5000, 0x6572, 0x7543, 0x0074, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x2A00, 0x0000, 0x5000, 0x6572, 0x7543, 0x4D74, 
            0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0xD70A, 0x3EA3, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x002B, 0x0000, 0x7250, 
            0x4365, 0x7475, 0x7253, 0x0063, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x2C00, 
            0x0000, 0x5000, 0x6572, 0x7543, 0x4D74, 0x646F, 0x0065, 0x0000, 
            0x8000, 0x003F, 0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x2D00, 0x0000, 0x5000, 0x6572, 0x7543, 0x5174, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x3333, 0x3F33, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x002E, 0x0000, 0x6552, 0x6F73, 
            0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x2F00, 0x0000, 0x5200, 
            0x7365, 0x4D6F, 0x7869, 0x6F4D, 0x0064, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x3000, 0x0000, 0x5200, 0x7365, 0x536F, 0x6372, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x4180, 0x0000, 0x4150, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0031, 0x0000, 0x6552, 0x5073, 0x7469, 0x6863, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0A3D, 0x3E57, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0032, 0x0000, 0x6552, 0x7073, 
            0x6950, 0x6374, 0x4D68, 0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x0033, 0x0000, 0x6552, 0x5073, 0x7469, 0x6863, 0x7253, 0x0063, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x4000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x3400, 0x0000, 0x5200, 0x7365, 0x704C, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0035, 0x0000, 0x6552, 0x4C73, 
            0x4D70, 0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0036, 0x0000, 
            0x6552, 0x4C73, 0x5370, 0x6372, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x4180, 0x0000, 0x4150, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x0037, 0x0000, 0x6F50, 0x7473, 0x7543, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x5C3F, 0x428F, 0x003E, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x3800, 0x0000, 0x5000, 0x736F, 0x4374, 0x7475, 0x6F4D, 
            0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 0x7B3F, 0x2E14, 0x003E, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x3900, 0x0000, 0x5000, 0x736F, 
            0x4374, 0x7475, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x3A00, 
            0x0000, 0x5000, 0x736F, 0x5174, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x47AE, 0x3F21, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x003B, 0x0000, 0x6F50, 0x7473, 0x6F4D, 0x6564, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x40A0, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x003C, 0x0000, 0x7247, 0x6961, 0x4F6E, 0x7475, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x4040, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x005C, 0x003D, 0x0000, 0x6552, 0x4F73, 
            0x7475, 0x0000, 0x0000, 0x0000, 0x0000, 0x4040, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x003E, 0x0000, 0x6147, 
            0x6E69, 0x6F4D, 0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x3F00, 0x0000, 
            0x6700, 0x6961, 0x536E, 0x6372, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x0040, 0x0000, 0x6F56, 0x006C, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x4100, 
            0x0000, 0x5000, 0x7261, 0x006E, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x4200, 
            0x0000, 0x5000, 0x6E61, 0x6F4D, 0x0064, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x4300, 0x0000, 0x5000, 0x6E61, 0x7253, 0x0063, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x4400, 0x0000, 0x4600, 0x696D, 0x3178, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0045, 0x0000, 0x6D46, 0x7869, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x4600, 0x0000, 0x6600, 0x6565, 0x0064, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x263F, 0x6BD5, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x4700, 0x0000, 0x5000, 0x7469, 0x6863, 0x6554, 
            0x706D, 0x006F, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x2000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x4800, 0x0000, 0x5000, 
            0x7469, 0x6863, 0x6944, 0x0076, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x4900, 
            0x0000, 0x6400, 0x6C65, 0x6F4D, 0x6564, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x4040, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x004A, 0x0000, 0x694A, 0x5374, 0x6E79, 0x0063, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
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
		
		auto& fix8_block = this->getT(0);                                                        // sn_impl::fix8_block_t<NV>
		auto& modchain = this->getT(0).getT(0);                                                  // sn_impl::modchain_t<NV>
		auto& split = this->getT(0).getT(0).getT(0);                                             // sn_impl::split_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0).getT(0);                                     // sn_impl::chain_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0).getT(0).getT(0);                            // sn_impl::branch_t<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);                    // sn_impl::chain1_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);      // sn_impl::global_cable_t<NV>
		auto& add = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);               // math::add<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);                    // sn_impl::chain3_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);     // sn_impl::global_cable2_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);              // math::add<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);                    // sn_impl::chain2_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(0);     // sn_impl::global_cable1_t<NV>
		auto& add1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(1);              // math::add<NV>
		auto& chain15 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3);                   // sn_impl::chain15_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(0);    // sn_impl::global_cable14_t<NV>
		auto& add14 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(1);             // math::add<NV>
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4);                   // sn_impl::chain14_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(0);    // sn_impl::global_cable13_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(1);             // math::add<NV>
		auto& chain13 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5);                   // sn_impl::chain13_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(0);    // sn_impl::global_cable12_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(1);             // math::add<NV>
		auto& chain12 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(6);                   // sn_impl::chain12_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(6).getT(0);    // sn_impl::global_cable11_t<NV>
		auto& add11 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(6).getT(1);             // math::add<NV>
		auto& chain11 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(7);                   // sn_impl::chain11_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(7).getT(0);    // sn_impl::global_cable10_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(7).getT(1);             // math::add<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(8);                   // sn_impl::chain10_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(8).getT(0);     // sn_impl::global_cable9_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(8).getT(1);              // math::add<NV>
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(9);                    // sn_impl::chain9_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(9).getT(0);     // sn_impl::global_cable8_t<NV>
		auto& add8 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(9).getT(1);              // math::add<NV>
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(10);                   // sn_impl::chain8_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(10).getT(0);    // sn_impl::global_cable7_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(10).getT(1);             // math::add<NV>
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(11);                   // sn_impl::chain7_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(11).getT(0);    // sn_impl::global_cable6_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(11).getT(1);             // math::add<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(12);                   // sn_impl::chain6_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(12).getT(0);    // sn_impl::global_cable5_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(12).getT(1);             // math::add<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(13);                   // sn_impl::chain5_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(13).getT(0);    // sn_impl::global_cable4_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(13).getT(1);             // math::add<NV>
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(14);                   // sn_impl::chain4_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(14).getT(0);    // sn_impl::global_cable3_t<NV>
		auto& add3 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(14).getT(1);             // math::add<NV>
		auto& chain48 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(15);                  // sn_impl::chain48_t<NV>
		auto& global_cable45 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(15).getT(0);   // sn_impl::global_cable45_t<NV>
		auto& add45 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(15).getT(1);            // math::add<NV>
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).getT(1);                              // sn_impl::peak_t<NV>
		auto& clear = this->getT(0).getT(0).getT(0).getT(0).getT(2);                             // math::clear<NV>
		auto& pma = this->getT(0).getT(0).getT(0).getT(0).getT(3);                               // sn_impl::pma_t<NV>
		auto& cable_table = this->getT(0).getT(0).getT(0).getT(0).getT(4);                       // sn_impl::cable_table_t
		auto& chain49 = this->getT(0).getT(0).getT(0).getT(1);                                   // sn_impl::chain49_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                           // sn_impl::branch3_t<NV>
		auto& chain50 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);                   // sn_impl::chain50_t<NV>
		auto& global_cable46 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);    // sn_impl::global_cable46_t<NV>
		auto& add46 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1);             // math::add<NV>
		auto& chain51 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);                   // sn_impl::chain51_t<NV>
		auto& global_cable47 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);    // sn_impl::global_cable47_t<NV>
		auto& add47 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).getT(1);             // math::add<NV>
		auto& chain52 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);                   // sn_impl::chain52_t<NV>
		auto& global_cable48 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2).getT(0);    // sn_impl::global_cable48_t<NV>
		auto& add48 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2).getT(1);             // math::add<NV>
		auto& chain53 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(3);                   // sn_impl::chain53_t<NV>
		auto& global_cable49 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(3).getT(0);    // sn_impl::global_cable49_t<NV>
		auto& add49 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(3).getT(1);             // math::add<NV>
		auto& chain54 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(4);                   // sn_impl::chain54_t<NV>
		auto& global_cable50 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(4).getT(0);    // sn_impl::global_cable50_t<NV>
		auto& add50 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(4).getT(1);             // math::add<NV>
		auto& chain55 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(5);                   // sn_impl::chain55_t<NV>
		auto& global_cable51 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(5).getT(0);    // sn_impl::global_cable51_t<NV>
		auto& add51 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(5).getT(1);             // math::add<NV>
		auto& chain56 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(6);                   // sn_impl::chain56_t<NV>
		auto& global_cable52 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(6).getT(0);    // sn_impl::global_cable52_t<NV>
		auto& add52 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(6).getT(1);             // math::add<NV>
		auto& chain57 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(7);                   // sn_impl::chain57_t<NV>
		auto& global_cable53 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(7).getT(0);    // sn_impl::global_cable53_t<NV>
		auto& add53 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(7).getT(1);             // math::add<NV>
		auto& chain58 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(8);                   // sn_impl::chain58_t<NV>
		auto& global_cable54 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(8).getT(0);    // sn_impl::global_cable54_t<NV>
		auto& add54 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(8).getT(1);             // math::add<NV>
		auto& chain59 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(9);                   // sn_impl::chain59_t<NV>
		auto& global_cable55 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(9).getT(0);    // sn_impl::global_cable55_t<NV>
		auto& add55 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(9).getT(1);             // math::add<NV>
		auto& chain60 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(10);                  // sn_impl::chain60_t<NV>
		auto& global_cable56 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(10).getT(0);   // sn_impl::global_cable56_t<NV>
		auto& add56 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(10).getT(1);            // math::add<NV>
		auto& chain61 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(11);                  // sn_impl::chain61_t<NV>
		auto& global_cable57 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(11).getT(0);   // sn_impl::global_cable57_t<NV>
		auto& add57 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(11).getT(1);            // math::add<NV>
		auto& chain62 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(12);                  // sn_impl::chain62_t<NV>
		auto& global_cable58 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(12).getT(0);   // sn_impl::global_cable58_t<NV>
		auto& add58 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(12).getT(1);            // math::add<NV>
		auto& chain63 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(13);                  // sn_impl::chain63_t<NV>
		auto& global_cable59 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(13).getT(0);   // sn_impl::global_cable59_t<NV>
		auto& add59 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(13).getT(1);            // math::add<NV>
		auto& chain64 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(14);                  // sn_impl::chain64_t<NV>
		auto& global_cable60 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(14).getT(0);   // sn_impl::global_cable60_t<NV>
		auto& add60 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(14).getT(1);            // math::add<NV>
		auto& chain65 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(15);                  // sn_impl::chain65_t<NV>
		auto& global_cable61 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(15).getT(0);   // sn_impl::global_cable61_t<NV>
		auto& add61 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(15).getT(1);            // math::add<NV>
		auto& peak3 = this->getT(0).getT(0).getT(0).getT(1).getT(1);                             // sn_impl::peak3_t<NV>
		auto& clear3 = this->getT(0).getT(0).getT(0).getT(1).getT(2);                            // math::clear<NV>
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(1).getT(3);                              // sn_impl::pma3_t<NV>
		auto& cable_table1 = this->getT(0).getT(0).getT(0).getT(1).getT(4);                      // sn_impl::cable_table1_t
		auto& chain66 = this->getT(0).getT(0).getT(0).getT(2);                                   // sn_impl::chain66_t<NV>
		auto& branch4 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                           // sn_impl::branch4_t<NV>
		auto& chain67 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0);                   // sn_impl::chain67_t<NV>
		auto& global_cable62 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0).getT(0);    // sn_impl::global_cable62_t<NV>
		auto& add62 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0).getT(1);             // math::add<NV>
		auto& chain68 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1);                   // sn_impl::chain68_t<NV>
		auto& global_cable63 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1).getT(0);    // sn_impl::global_cable63_t<NV>
		auto& add63 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1).getT(1);             // math::add<NV>
		auto& chain69 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2);                   // sn_impl::chain69_t<NV>
		auto& global_cable64 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2).getT(0);    // sn_impl::global_cable64_t<NV>
		auto& add64 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2).getT(1);             // math::add<NV>
		auto& chain70 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(3);                   // sn_impl::chain70_t<NV>
		auto& global_cable65 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(3).getT(0);    // sn_impl::global_cable65_t<NV>
		auto& add65 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(3).getT(1);             // math::add<NV>
		auto& chain71 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(4);                   // sn_impl::chain71_t<NV>
		auto& global_cable66 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(4).getT(0);    // sn_impl::global_cable66_t<NV>
		auto& add66 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(4).getT(1);             // math::add<NV>
		auto& chain72 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(5);                   // sn_impl::chain72_t<NV>
		auto& global_cable67 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(5).getT(0);    // sn_impl::global_cable67_t<NV>
		auto& add67 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(5).getT(1);             // math::add<NV>
		auto& chain73 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(6);                   // sn_impl::chain73_t<NV>
		auto& global_cable68 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(6).getT(0);    // sn_impl::global_cable68_t<NV>
		auto& add68 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(6).getT(1);             // math::add<NV>
		auto& chain74 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(7);                   // sn_impl::chain74_t<NV>
		auto& global_cable69 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(7).getT(0);    // sn_impl::global_cable69_t<NV>
		auto& add69 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(7).getT(1);             // math::add<NV>
		auto& chain75 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(8);                   // sn_impl::chain75_t<NV>
		auto& global_cable70 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(8).getT(0);    // sn_impl::global_cable70_t<NV>
		auto& add70 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(8).getT(1);             // math::add<NV>
		auto& chain76 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(9);                   // sn_impl::chain76_t<NV>
		auto& global_cable71 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(9).getT(0);    // sn_impl::global_cable71_t<NV>
		auto& add71 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(9).getT(1);             // math::add<NV>
		auto& chain77 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(10);                  // sn_impl::chain77_t<NV>
		auto& global_cable72 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(10).getT(0);   // sn_impl::global_cable72_t<NV>
		auto& add72 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(10).getT(1);            // math::add<NV>
		auto& chain78 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(11);                  // sn_impl::chain78_t<NV>
		auto& global_cable73 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(11).getT(0);   // sn_impl::global_cable73_t<NV>
		auto& add73 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(11).getT(1);            // math::add<NV>
		auto& chain79 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(12);                  // sn_impl::chain79_t<NV>
		auto& global_cable74 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(12).getT(0);   // sn_impl::global_cable74_t<NV>
		auto& add74 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(12).getT(1);            // math::add<NV>
		auto& chain80 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(13);                  // sn_impl::chain80_t<NV>
		auto& global_cable75 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(13).getT(0);   // sn_impl::global_cable75_t<NV>
		auto& add75 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(13).getT(1);            // math::add<NV>
		auto& chain81 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(14);                  // sn_impl::chain81_t<NV>
		auto& global_cable76 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(14).getT(0);   // sn_impl::global_cable76_t<NV>
		auto& add76 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(14).getT(1);            // math::add<NV>
		auto& chain82 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(15);                  // sn_impl::chain82_t<NV>
		auto& global_cable77 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(15).getT(0);   // sn_impl::global_cable77_t<NV>
		auto& add77 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(15).getT(1);            // math::add<NV>
		auto& peak4 = this->getT(0).getT(0).getT(0).getT(2).getT(1);                             // sn_impl::peak4_t<NV>
		auto& clear4 = this->getT(0).getT(0).getT(0).getT(2).getT(2);                            // math::clear<NV>
		auto& pma4 = this->getT(0).getT(0).getT(0).getT(2).getT(3);                              // sn_impl::pma4_t<NV>
		auto& cable_table2 = this->getT(0).getT(0).getT(0).getT(2).getT(4);                      // sn_impl::cable_table2_t
		auto& chain83 = this->getT(0).getT(0).getT(0).getT(3);                                   // sn_impl::chain83_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(0).getT(3).getT(0);                           // sn_impl::branch5_t<NV>
		auto& chain84 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0);                   // sn_impl::chain84_t<NV>
		auto& global_cable78 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0).getT(0);    // sn_impl::global_cable78_t<NV>
		auto& add78 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0).getT(1);             // math::add<NV>
		auto& chain85 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1);                   // sn_impl::chain85_t<NV>
		auto& global_cable79 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1).getT(0);    // sn_impl::global_cable79_t<NV>
		auto& add79 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1).getT(1);             // math::add<NV>
		auto& chain86 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2);                   // sn_impl::chain86_t<NV>
		auto& global_cable80 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2).getT(0);    // sn_impl::global_cable80_t<NV>
		auto& add80 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2).getT(1);             // math::add<NV>
		auto& chain87 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(3);                   // sn_impl::chain87_t<NV>
		auto& global_cable81 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(3).getT(0);    // sn_impl::global_cable81_t<NV>
		auto& add81 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(3).getT(1);             // math::add<NV>
		auto& chain88 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(4);                   // sn_impl::chain88_t<NV>
		auto& global_cable82 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(4).getT(0);    // sn_impl::global_cable82_t<NV>
		auto& add82 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(4).getT(1);             // math::add<NV>
		auto& chain89 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(5);                   // sn_impl::chain89_t<NV>
		auto& global_cable83 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(5).getT(0);    // sn_impl::global_cable83_t<NV>
		auto& add83 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(5).getT(1);             // math::add<NV>
		auto& chain90 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(6);                   // sn_impl::chain90_t<NV>
		auto& global_cable84 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(6).getT(0);    // sn_impl::global_cable84_t<NV>
		auto& add84 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(6).getT(1);             // math::add<NV>
		auto& chain91 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(7);                   // sn_impl::chain91_t<NV>
		auto& global_cable85 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(7).getT(0);    // sn_impl::global_cable85_t<NV>
		auto& add85 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(7).getT(1);             // math::add<NV>
		auto& chain92 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(8);                   // sn_impl::chain92_t<NV>
		auto& global_cable86 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(8).getT(0);    // sn_impl::global_cable86_t<NV>
		auto& add86 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(8).getT(1);             // math::add<NV>
		auto& chain93 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(9);                   // sn_impl::chain93_t<NV>
		auto& global_cable87 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(9).getT(0);    // sn_impl::global_cable87_t<NV>
		auto& add87 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(9).getT(1);             // math::add<NV>
		auto& chain94 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(10);                  // sn_impl::chain94_t<NV>
		auto& global_cable88 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(10).getT(0);   // sn_impl::global_cable88_t<NV>
		auto& add88 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(10).getT(1);            // math::add<NV>
		auto& chain95 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(11);                  // sn_impl::chain95_t<NV>
		auto& global_cable89 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(11).getT(0);   // sn_impl::global_cable89_t<NV>
		auto& add89 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(11).getT(1);            // math::add<NV>
		auto& chain96 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(12);                  // sn_impl::chain96_t<NV>
		auto& global_cable90 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(12).getT(0);   // sn_impl::global_cable90_t<NV>
		auto& add90 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(12).getT(1);            // math::add<NV>
		auto& chain97 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(13);                  // sn_impl::chain97_t<NV>
		auto& global_cable91 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(13).getT(0);   // sn_impl::global_cable91_t<NV>
		auto& add91 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(13).getT(1);            // math::add<NV>
		auto& chain98 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(14);                  // sn_impl::chain98_t<NV>
		auto& global_cable92 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(14).getT(0);   // sn_impl::global_cable92_t<NV>
		auto& add92 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(14).getT(1);            // math::add<NV>
		auto& chain99 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(15);                  // sn_impl::chain99_t<NV>
		auto& global_cable93 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(15).getT(0);   // sn_impl::global_cable93_t<NV>
		auto& add93 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(15).getT(1);            // math::add<NV>
		auto& peak5 = this->getT(0).getT(0).getT(0).getT(3).getT(1);                             // sn_impl::peak5_t<NV>
		auto& clear5 = this->getT(0).getT(0).getT(0).getT(3).getT(2);                            // math::clear<NV>
		auto& pma5 = this->getT(0).getT(0).getT(0).getT(3).getT(3);                              // sn_impl::pma5_t<NV>
		auto& cable_table3 = this->getT(0).getT(0).getT(0).getT(3).getT(4);                      // sn_impl::cable_table3_t
		auto& chain100 = this->getT(0).getT(0).getT(0).getT(4);                                  // sn_impl::chain100_t<NV>
		auto& branch6 = this->getT(0).getT(0).getT(0).getT(4).getT(0);                           // sn_impl::branch6_t<NV>
		auto& chain101 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(0);                  // sn_impl::chain101_t<NV>
		auto& global_cable94 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(0).getT(0);    // sn_impl::global_cable94_t<NV>
		auto& add94 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(0).getT(1);             // math::add<NV>
		auto& chain102 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(1);                  // sn_impl::chain102_t<NV>
		auto& global_cable95 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(1).getT(0);    // sn_impl::global_cable95_t<NV>
		auto& add95 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(1).getT(1);             // math::add<NV>
		auto& chain103 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(2);                  // sn_impl::chain103_t<NV>
		auto& global_cable96 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(2).getT(0);    // sn_impl::global_cable96_t<NV>
		auto& add96 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(2).getT(1);             // math::add<NV>
		auto& chain104 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(3);                  // sn_impl::chain104_t<NV>
		auto& global_cable97 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(3).getT(0);    // sn_impl::global_cable97_t<NV>
		auto& add97 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(3).getT(1);             // math::add<NV>
		auto& chain105 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(4);                  // sn_impl::chain105_t<NV>
		auto& global_cable98 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(4).getT(0);    // sn_impl::global_cable98_t<NV>
		auto& add98 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(4).getT(1);             // math::add<NV>
		auto& chain106 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(5);                  // sn_impl::chain106_t<NV>
		auto& global_cable99 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(5).getT(0);    // sn_impl::global_cable99_t<NV>
		auto& add99 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(5).getT(1);             // math::add<NV>
		auto& chain107 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(6);                  // sn_impl::chain107_t<NV>
		auto& global_cable100 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(6).getT(0);   // sn_impl::global_cable100_t<NV>
		auto& add100 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(6).getT(1);            // math::add<NV>
		auto& chain108 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(7);                  // sn_impl::chain108_t<NV>
		auto& global_cable101 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(7).getT(0);   // sn_impl::global_cable101_t<NV>
		auto& add101 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(7).getT(1);            // math::add<NV>
		auto& chain109 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(8);                  // sn_impl::chain109_t<NV>
		auto& global_cable102 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(8).getT(0);   // sn_impl::global_cable102_t<NV>
		auto& add102 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(8).getT(1);            // math::add<NV>
		auto& chain110 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(9);                  // sn_impl::chain110_t<NV>
		auto& global_cable103 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(9).getT(0);   // sn_impl::global_cable103_t<NV>
		auto& add103 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(9).getT(1);            // math::add<NV>
		auto& chain111 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(10);                 // sn_impl::chain111_t<NV>
		auto& global_cable104 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(10).getT(0);  // sn_impl::global_cable104_t<NV>
		auto& add104 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(10).getT(1);           // math::add<NV>
		auto& chain112 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(11);                 // sn_impl::chain112_t<NV>
		auto& global_cable105 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(11).getT(0);  // sn_impl::global_cable105_t<NV>
		auto& add105 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(11).getT(1);           // math::add<NV>
		auto& chain113 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(12);                 // sn_impl::chain113_t<NV>
		auto& global_cable106 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(12).getT(0);  // sn_impl::global_cable106_t<NV>
		auto& add106 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(12).getT(1);           // math::add<NV>
		auto& chain114 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(13);                 // sn_impl::chain114_t<NV>
		auto& global_cable107 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(13).getT(0);  // sn_impl::global_cable107_t<NV>
		auto& add107 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(13).getT(1);           // math::add<NV>
		auto& chain115 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(14);                 // sn_impl::chain115_t<NV>
		auto& global_cable108 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(14).getT(0);  // sn_impl::global_cable108_t<NV>
		auto& add108 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(14).getT(1);           // math::add<NV>
		auto& chain116 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(15);                 // sn_impl::chain116_t<NV>
		auto& global_cable109 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(15).getT(0);  // sn_impl::global_cable109_t<NV>
		auto& add109 = this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(15).getT(1);           // math::add<NV>
		auto& peak6 = this->getT(0).getT(0).getT(0).getT(4).getT(1);                             // sn_impl::peak6_t<NV>
		auto& clear6 = this->getT(0).getT(0).getT(0).getT(4).getT(2);                            // math::clear<NV>
		auto& pma6 = this->getT(0).getT(0).getT(0).getT(4).getT(3);                              // sn_impl::pma6_t<NV>
		auto& chain134 = this->getT(0).getT(0).getT(0).getT(5);                                  // sn_impl::chain134_t<NV>
		auto& branch8 = this->getT(0).getT(0).getT(0).getT(5).getT(0);                           // sn_impl::branch8_t<NV>
		auto& chain135 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(0);                  // sn_impl::chain135_t<NV>
		auto& global_cable126 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(0).getT(0);   // sn_impl::global_cable126_t<NV>
		auto& add126 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(0).getT(1);            // math::add<NV>
		auto& chain136 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(1);                  // sn_impl::chain136_t<NV>
		auto& global_cable127 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(1).getT(0);   // sn_impl::global_cable127_t<NV>
		auto& add127 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(1).getT(1);            // math::add<NV>
		auto& chain137 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(2);                  // sn_impl::chain137_t<NV>
		auto& global_cable128 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(2).getT(0);   // sn_impl::global_cable128_t<NV>
		auto& add128 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(2).getT(1);            // math::add<NV>
		auto& chain138 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(3);                  // sn_impl::chain138_t<NV>
		auto& global_cable129 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(3).getT(0);   // sn_impl::global_cable129_t<NV>
		auto& add129 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(3).getT(1);            // math::add<NV>
		auto& chain139 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(4);                  // sn_impl::chain139_t<NV>
		auto& global_cable130 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(4).getT(0);   // sn_impl::global_cable130_t<NV>
		auto& add130 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(4).getT(1);            // math::add<NV>
		auto& chain140 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(5);                  // sn_impl::chain140_t<NV>
		auto& global_cable131 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(5).getT(0);   // sn_impl::global_cable131_t<NV>
		auto& add131 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(5).getT(1);            // math::add<NV>
		auto& chain141 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(6);                  // sn_impl::chain141_t<NV>
		auto& global_cable132 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(6).getT(0);   // sn_impl::global_cable132_t<NV>
		auto& add132 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(6).getT(1);            // math::add<NV>
		auto& chain142 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(7);                  // sn_impl::chain142_t<NV>
		auto& global_cable133 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(7).getT(0);   // sn_impl::global_cable133_t<NV>
		auto& add133 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(7).getT(1);            // math::add<NV>
		auto& chain143 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(8);                  // sn_impl::chain143_t<NV>
		auto& global_cable134 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(8).getT(0);   // sn_impl::global_cable134_t<NV>
		auto& add134 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(8).getT(1);            // math::add<NV>
		auto& chain144 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(9);                  // sn_impl::chain144_t<NV>
		auto& global_cable135 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(9).getT(0);   // sn_impl::global_cable135_t<NV>
		auto& add135 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(9).getT(1);            // math::add<NV>
		auto& chain145 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(10);                 // sn_impl::chain145_t<NV>
		auto& global_cable136 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(10).getT(0);  // sn_impl::global_cable136_t<NV>
		auto& add136 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(10).getT(1);           // math::add<NV>
		auto& chain146 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(11);                 // sn_impl::chain146_t<NV>
		auto& global_cable137 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(11).getT(0);  // sn_impl::global_cable137_t<NV>
		auto& add137 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(11).getT(1);           // math::add<NV>
		auto& chain147 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(12);                 // sn_impl::chain147_t<NV>
		auto& global_cable138 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(12).getT(0);  // sn_impl::global_cable138_t<NV>
		auto& add138 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(12).getT(1);           // math::add<NV>
		auto& chain148 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(13);                 // sn_impl::chain148_t<NV>
		auto& global_cable139 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(13).getT(0);  // sn_impl::global_cable139_t<NV>
		auto& add139 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(13).getT(1);           // math::add<NV>
		auto& chain149 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(14);                 // sn_impl::chain149_t<NV>
		auto& global_cable140 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(14).getT(0);  // sn_impl::global_cable140_t<NV>
		auto& add140 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(14).getT(1);           // math::add<NV>
		auto& chain150 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(15);                 // sn_impl::chain150_t<NV>
		auto& global_cable141 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(15).getT(0);  // sn_impl::global_cable141_t<NV>
		auto& add141 = this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(15).getT(1);           // math::add<NV>
		auto& peak8 = this->getT(0).getT(0).getT(0).getT(5).getT(1);                             // sn_impl::peak8_t<NV>
		auto& clear8 = this->getT(0).getT(0).getT(0).getT(5).getT(2);                            // math::clear<NV>
		auto& pma9 = this->getT(0).getT(0).getT(0).getT(5).getT(3);                              // sn_impl::pma9_t<NV>
		auto& chain151 = this->getT(0).getT(0).getT(0).getT(6);                                  // sn_impl::chain151_t<NV>
		auto& branch9 = this->getT(0).getT(0).getT(0).getT(6).getT(0);                           // sn_impl::branch9_t<NV>
		auto& chain152 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(0);                  // sn_impl::chain152_t<NV>
		auto& global_cable142 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(0).getT(0);   // sn_impl::global_cable142_t<NV>
		auto& add142 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(0).getT(1);            // math::add<NV>
		auto& chain153 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(1);                  // sn_impl::chain153_t<NV>
		auto& global_cable143 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(1).getT(0);   // sn_impl::global_cable143_t<NV>
		auto& add143 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(1).getT(1);            // math::add<NV>
		auto& chain154 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(2);                  // sn_impl::chain154_t<NV>
		auto& global_cable144 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(2).getT(0);   // sn_impl::global_cable144_t<NV>
		auto& add144 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(2).getT(1);            // math::add<NV>
		auto& chain155 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(3);                  // sn_impl::chain155_t<NV>
		auto& global_cable145 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(3).getT(0);   // sn_impl::global_cable145_t<NV>
		auto& add145 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(3).getT(1);            // math::add<NV>
		auto& chain156 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(4);                  // sn_impl::chain156_t<NV>
		auto& global_cable146 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(4).getT(0);   // sn_impl::global_cable146_t<NV>
		auto& add146 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(4).getT(1);            // math::add<NV>
		auto& chain157 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(5);                  // sn_impl::chain157_t<NV>
		auto& global_cable147 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(5).getT(0);   // sn_impl::global_cable147_t<NV>
		auto& add147 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(5).getT(1);            // math::add<NV>
		auto& chain158 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(6);                  // sn_impl::chain158_t<NV>
		auto& global_cable148 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(6).getT(0);   // sn_impl::global_cable148_t<NV>
		auto& add148 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(6).getT(1);            // math::add<NV>
		auto& chain159 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(7);                  // sn_impl::chain159_t<NV>
		auto& global_cable149 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(7).getT(0);   // sn_impl::global_cable149_t<NV>
		auto& add149 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(7).getT(1);            // math::add<NV>
		auto& chain160 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(8);                  // sn_impl::chain160_t<NV>
		auto& global_cable150 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(8).getT(0);   // sn_impl::global_cable150_t<NV>
		auto& add150 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(8).getT(1);            // math::add<NV>
		auto& chain161 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(9);                  // sn_impl::chain161_t<NV>
		auto& global_cable151 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(9).getT(0);   // sn_impl::global_cable151_t<NV>
		auto& add151 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(9).getT(1);            // math::add<NV>
		auto& chain162 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(10);                 // sn_impl::chain162_t<NV>
		auto& global_cable152 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(10).getT(0);  // sn_impl::global_cable152_t<NV>
		auto& add152 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(10).getT(1);           // math::add<NV>
		auto& chain163 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(11);                 // sn_impl::chain163_t<NV>
		auto& global_cable153 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(11).getT(0);  // sn_impl::global_cable153_t<NV>
		auto& add153 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(11).getT(1);           // math::add<NV>
		auto& chain164 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(12);                 // sn_impl::chain164_t<NV>
		auto& global_cable154 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(12).getT(0);  // sn_impl::global_cable154_t<NV>
		auto& add154 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(12).getT(1);           // math::add<NV>
		auto& chain165 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(13);                 // sn_impl::chain165_t<NV>
		auto& global_cable155 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(13).getT(0);  // sn_impl::global_cable155_t<NV>
		auto& add155 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(13).getT(1);           // math::add<NV>
		auto& chain166 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(14);                 // sn_impl::chain166_t<NV>
		auto& global_cable156 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(14).getT(0);  // sn_impl::global_cable156_t<NV>
		auto& add156 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(14).getT(1);           // math::add<NV>
		auto& chain167 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(15);                 // sn_impl::chain167_t<NV>
		auto& global_cable157 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(15).getT(0);  // sn_impl::global_cable157_t<NV>
		auto& add157 = this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(15).getT(1);           // math::add<NV>
		auto& peak9 = this->getT(0).getT(0).getT(0).getT(6).getT(1);                             // sn_impl::peak9_t<NV>
		auto& clear9 = this->getT(0).getT(0).getT(0).getT(6).getT(2);                            // math::clear<NV>
		auto& pma10 = this->getT(0).getT(0).getT(0).getT(6).getT(3);                             // sn_impl::pma10_t<NV>
		auto& chain168 = this->getT(0).getT(0).getT(0).getT(7);                                  // sn_impl::chain168_t<NV>
		auto& branch10 = this->getT(0).getT(0).getT(0).getT(7).getT(0);                          // sn_impl::branch10_t<NV>
		auto& chain169 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(0);                  // sn_impl::chain169_t<NV>
		auto& global_cable158 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(0).getT(0);   // sn_impl::global_cable158_t<NV>
		auto& add158 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(0).getT(1);            // math::add<NV>
		auto& chain170 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(1);                  // sn_impl::chain170_t<NV>
		auto& global_cable159 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(1).getT(0);   // sn_impl::global_cable159_t<NV>
		auto& add159 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(1).getT(1);            // math::add<NV>
		auto& chain171 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(2);                  // sn_impl::chain171_t<NV>
		auto& global_cable160 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(2).getT(0);   // sn_impl::global_cable160_t<NV>
		auto& add160 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(2).getT(1);            // math::add<NV>
		auto& chain172 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(3);                  // sn_impl::chain172_t<NV>
		auto& global_cable161 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(3).getT(0);   // sn_impl::global_cable161_t<NV>
		auto& add161 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(3).getT(1);            // math::add<NV>
		auto& chain173 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(4);                  // sn_impl::chain173_t<NV>
		auto& global_cable162 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(4).getT(0);   // sn_impl::global_cable162_t<NV>
		auto& add162 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(4).getT(1);            // math::add<NV>
		auto& chain174 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(5);                  // sn_impl::chain174_t<NV>
		auto& global_cable163 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(5).getT(0);   // sn_impl::global_cable163_t<NV>
		auto& add163 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(5).getT(1);            // math::add<NV>
		auto& chain175 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(6);                  // sn_impl::chain175_t<NV>
		auto& global_cable164 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(6).getT(0);   // sn_impl::global_cable164_t<NV>
		auto& add164 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(6).getT(1);            // math::add<NV>
		auto& chain176 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(7);                  // sn_impl::chain176_t<NV>
		auto& global_cable165 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(7).getT(0);   // sn_impl::global_cable165_t<NV>
		auto& add165 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(7).getT(1);            // math::add<NV>
		auto& chain177 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(8);                  // sn_impl::chain177_t<NV>
		auto& global_cable166 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(8).getT(0);   // sn_impl::global_cable166_t<NV>
		auto& add166 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(8).getT(1);            // math::add<NV>
		auto& chain178 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(9);                  // sn_impl::chain178_t<NV>
		auto& global_cable167 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(9).getT(0);   // sn_impl::global_cable167_t<NV>
		auto& add167 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(9).getT(1);            // math::add<NV>
		auto& chain179 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(10);                 // sn_impl::chain179_t<NV>
		auto& global_cable168 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(10).getT(0);  // sn_impl::global_cable168_t<NV>
		auto& add168 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(10).getT(1);           // math::add<NV>
		auto& chain180 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(11);                 // sn_impl::chain180_t<NV>
		auto& global_cable169 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(11).getT(0);  // sn_impl::global_cable169_t<NV>
		auto& add169 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(11).getT(1);           // math::add<NV>
		auto& chain181 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(12);                 // sn_impl::chain181_t<NV>
		auto& global_cable170 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(12).getT(0);  // sn_impl::global_cable170_t<NV>
		auto& add170 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(12).getT(1);           // math::add<NV>
		auto& chain182 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(13);                 // sn_impl::chain182_t<NV>
		auto& global_cable171 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(13).getT(0);  // sn_impl::global_cable171_t<NV>
		auto& add171 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(13).getT(1);           // math::add<NV>
		auto& chain183 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(14);                 // sn_impl::chain183_t<NV>
		auto& global_cable172 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(14).getT(0);  // sn_impl::global_cable172_t<NV>
		auto& add172 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(14).getT(1);           // math::add<NV>
		auto& chain184 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(15);                 // sn_impl::chain184_t<NV>
		auto& global_cable173 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(15).getT(0);  // sn_impl::global_cable173_t<NV>
		auto& add173 = this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(15).getT(1);           // math::add<NV>
		auto& peak10 = this->getT(0).getT(0).getT(0).getT(7).getT(1);                            // sn_impl::peak10_t<NV>
		auto& clear10 = this->getT(0).getT(0).getT(0).getT(7).getT(2);                           // math::clear<NV>
		auto& pma11 = this->getT(0).getT(0).getT(0).getT(7).getT(3);                             // sn_impl::pma11_t<NV>
		auto& chain185 = this->getT(0).getT(0).getT(0).getT(8);                                  // sn_impl::chain185_t<NV>
		auto& branch11 = this->getT(0).getT(0).getT(0).getT(8).getT(0);                          // sn_impl::branch11_t<NV>
		auto& chain186 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(0);                  // sn_impl::chain186_t<NV>
		auto& global_cable174 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(0).getT(0);   // sn_impl::global_cable174_t<NV>
		auto& add174 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(0).getT(1);            // math::add<NV>
		auto& chain187 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(1);                  // sn_impl::chain187_t<NV>
		auto& global_cable175 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(1).getT(0);   // sn_impl::global_cable175_t<NV>
		auto& add175 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(1).getT(1);            // math::add<NV>
		auto& chain188 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(2);                  // sn_impl::chain188_t<NV>
		auto& global_cable176 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(2).getT(0);   // sn_impl::global_cable176_t<NV>
		auto& add176 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(2).getT(1);            // math::add<NV>
		auto& chain189 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(3);                  // sn_impl::chain189_t<NV>
		auto& global_cable177 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(3).getT(0);   // sn_impl::global_cable177_t<NV>
		auto& add177 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(3).getT(1);            // math::add<NV>
		auto& chain190 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(4);                  // sn_impl::chain190_t<NV>
		auto& global_cable178 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(4).getT(0);   // sn_impl::global_cable178_t<NV>
		auto& add178 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(4).getT(1);            // math::add<NV>
		auto& chain191 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(5);                  // sn_impl::chain191_t<NV>
		auto& global_cable179 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(5).getT(0);   // sn_impl::global_cable179_t<NV>
		auto& add179 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(5).getT(1);            // math::add<NV>
		auto& chain192 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(6);                  // sn_impl::chain192_t<NV>
		auto& global_cable180 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(6).getT(0);   // sn_impl::global_cable180_t<NV>
		auto& add180 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(6).getT(1);            // math::add<NV>
		auto& chain193 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(7);                  // sn_impl::chain193_t<NV>
		auto& global_cable181 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(7).getT(0);   // sn_impl::global_cable181_t<NV>
		auto& add181 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(7).getT(1);            // math::add<NV>
		auto& chain194 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(8);                  // sn_impl::chain194_t<NV>
		auto& global_cable182 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(8).getT(0);   // sn_impl::global_cable182_t<NV>
		auto& add182 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(8).getT(1);            // math::add<NV>
		auto& chain195 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(9);                  // sn_impl::chain195_t<NV>
		auto& global_cable183 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(9).getT(0);   // sn_impl::global_cable183_t<NV>
		auto& add183 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(9).getT(1);            // math::add<NV>
		auto& chain196 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(10);                 // sn_impl::chain196_t<NV>
		auto& global_cable184 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(10).getT(0);  // sn_impl::global_cable184_t<NV>
		auto& add184 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(10).getT(1);           // math::add<NV>
		auto& chain197 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(11);                 // sn_impl::chain197_t<NV>
		auto& global_cable185 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(11).getT(0);  // sn_impl::global_cable185_t<NV>
		auto& add185 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(11).getT(1);           // math::add<NV>
		auto& chain198 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(12);                 // sn_impl::chain198_t<NV>
		auto& global_cable186 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(12).getT(0);  // sn_impl::global_cable186_t<NV>
		auto& add186 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(12).getT(1);           // math::add<NV>
		auto& chain199 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(13);                 // sn_impl::chain199_t<NV>
		auto& global_cable187 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(13).getT(0);  // sn_impl::global_cable187_t<NV>
		auto& add187 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(13).getT(1);           // math::add<NV>
		auto& chain200 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(14);                 // sn_impl::chain200_t<NV>
		auto& global_cable188 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(14).getT(0);  // sn_impl::global_cable188_t<NV>
		auto& add188 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(14).getT(1);           // math::add<NV>
		auto& chain201 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(15);                 // sn_impl::chain201_t<NV>
		auto& global_cable189 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(15).getT(0);  // sn_impl::global_cable189_t<NV>
		auto& add189 = this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(15).getT(1);           // math::add<NV>
		auto& peak11 = this->getT(0).getT(0).getT(0).getT(8).getT(1);                            // sn_impl::peak11_t<NV>
		auto& clear11 = this->getT(0).getT(0).getT(0).getT(8).getT(2);                           // math::clear<NV>
		auto& pma12 = this->getT(0).getT(0).getT(0).getT(8).getT(3);                             // sn_impl::pma12_t<NV>
		auto& pma21 = this->getT(0).getT(0).getT(0).getT(8).getT(4);                             // sn_impl::pma21_t<NV>
		auto& chain202 = this->getT(0).getT(0).getT(0).getT(9);                                  // sn_impl::chain202_t<NV>
		auto& branch12 = this->getT(0).getT(0).getT(0).getT(9).getT(0);                          // sn_impl::branch12_t<NV>
		auto& chain203 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(0);                  // sn_impl::chain203_t<NV>
		auto& global_cable190 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(0).getT(0);   // sn_impl::global_cable190_t<NV>
		auto& add190 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(0).getT(1);            // math::add<NV>
		auto& chain204 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(1);                  // sn_impl::chain204_t<NV>
		auto& global_cable191 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(1).getT(0);   // sn_impl::global_cable191_t<NV>
		auto& add191 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(1).getT(1);            // math::add<NV>
		auto& chain205 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(2);                  // sn_impl::chain205_t<NV>
		auto& global_cable192 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(2).getT(0);   // sn_impl::global_cable192_t<NV>
		auto& add192 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(2).getT(1);            // math::add<NV>
		auto& chain206 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(3);                  // sn_impl::chain206_t<NV>
		auto& global_cable193 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(3).getT(0);   // sn_impl::global_cable193_t<NV>
		auto& add193 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(3).getT(1);            // math::add<NV>
		auto& chain207 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(4);                  // sn_impl::chain207_t<NV>
		auto& global_cable194 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(4).getT(0);   // sn_impl::global_cable194_t<NV>
		auto& add194 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(4).getT(1);            // math::add<NV>
		auto& chain208 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(5);                  // sn_impl::chain208_t<NV>
		auto& global_cable195 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(5).getT(0);   // sn_impl::global_cable195_t<NV>
		auto& add195 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(5).getT(1);            // math::add<NV>
		auto& chain209 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(6);                  // sn_impl::chain209_t<NV>
		auto& global_cable196 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(6).getT(0);   // sn_impl::global_cable196_t<NV>
		auto& add196 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(6).getT(1);            // math::add<NV>
		auto& chain210 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(7);                  // sn_impl::chain210_t<NV>
		auto& global_cable197 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(7).getT(0);   // sn_impl::global_cable197_t<NV>
		auto& add197 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(7).getT(1);            // math::add<NV>
		auto& chain211 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(8);                  // sn_impl::chain211_t<NV>
		auto& global_cable198 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(8).getT(0);   // sn_impl::global_cable198_t<NV>
		auto& add198 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(8).getT(1);            // math::add<NV>
		auto& chain212 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(9);                  // sn_impl::chain212_t<NV>
		auto& global_cable199 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(9).getT(0);   // sn_impl::global_cable199_t<NV>
		auto& add199 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(9).getT(1);            // math::add<NV>
		auto& chain213 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(10);                 // sn_impl::chain213_t<NV>
		auto& global_cable200 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(10).getT(0);  // sn_impl::global_cable200_t<NV>
		auto& add200 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(10).getT(1);           // math::add<NV>
		auto& chain214 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(11);                 // sn_impl::chain214_t<NV>
		auto& global_cable201 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(11).getT(0);  // sn_impl::global_cable201_t<NV>
		auto& add201 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(11).getT(1);           // math::add<NV>
		auto& chain215 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(12);                 // sn_impl::chain215_t<NV>
		auto& global_cable202 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(12).getT(0);  // sn_impl::global_cable202_t<NV>
		auto& add202 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(12).getT(1);           // math::add<NV>
		auto& chain216 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(13);                 // sn_impl::chain216_t<NV>
		auto& global_cable203 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(13).getT(0);  // sn_impl::global_cable203_t<NV>
		auto& add203 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(13).getT(1);           // math::add<NV>
		auto& chain217 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(14);                 // sn_impl::chain217_t<NV>
		auto& global_cable204 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(14).getT(0);  // sn_impl::global_cable204_t<NV>
		auto& add204 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(14).getT(1);           // math::add<NV>
		auto& chain218 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(15);                 // sn_impl::chain218_t<NV>
		auto& global_cable205 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(15).getT(0);  // sn_impl::global_cable205_t<NV>
		auto& add205 = this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(15).getT(1);           // math::add<NV>
		auto& peak12 = this->getT(0).getT(0).getT(0).getT(9).getT(1);                            // sn_impl::peak12_t<NV>
		auto& clear12 = this->getT(0).getT(0).getT(0).getT(9).getT(2);                           // math::clear<NV>
		auto& pma2 = this->getT(0).getT(0).getT(0).getT(9).getT(3);                              // sn_impl::pma2_t<NV>
		auto& chain219 = this->getT(0).getT(0).getT(0).getT(10);                                 // sn_impl::chain219_t<NV>
		auto& branch13 = this->getT(0).getT(0).getT(0).getT(10).getT(0);                         // sn_impl::branch13_t<NV>
		auto& chain220 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(0);                 // sn_impl::chain220_t<NV>
		auto& global_cable206 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(0).getT(0);  // sn_impl::global_cable206_t<NV>
		auto& add206 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain221 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(1);                 // sn_impl::chain221_t<NV>
		auto& global_cable207 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(1).getT(0);  // sn_impl::global_cable207_t<NV>
		auto& add207 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain222 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(2);                 // sn_impl::chain222_t<NV>
		auto& global_cable208 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(2).getT(0);  // sn_impl::global_cable208_t<NV>
		auto& add208 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain223 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(3);                 // sn_impl::chain223_t<NV>
		auto& global_cable209 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(3).getT(0);  // sn_impl::global_cable209_t<NV>
		auto& add209 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain224 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(4);                 // sn_impl::chain224_t<NV>
		auto& global_cable210 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(4).getT(0);  // sn_impl::global_cable210_t<NV>
		auto& add210 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain225 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(5);                 // sn_impl::chain225_t<NV>
		auto& global_cable211 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(5).getT(0);  // sn_impl::global_cable211_t<NV>
		auto& add211 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain226 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(6);                 // sn_impl::chain226_t<NV>
		auto& global_cable212 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(6).getT(0);  // sn_impl::global_cable212_t<NV>
		auto& add212 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain227 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(7);                 // sn_impl::chain227_t<NV>
		auto& global_cable213 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(7).getT(0);  // sn_impl::global_cable213_t<NV>
		auto& add213 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain228 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(8);                 // sn_impl::chain228_t<NV>
		auto& global_cable214 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(8).getT(0);  // sn_impl::global_cable214_t<NV>
		auto& add214 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain229 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(9);                 // sn_impl::chain229_t<NV>
		auto& global_cable215 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(9).getT(0);  // sn_impl::global_cable215_t<NV>
		auto& add215 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain230 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(10);                // sn_impl::chain230_t<NV>
		auto& global_cable216 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(10).getT(0); // sn_impl::global_cable216_t<NV>
		auto& add216 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain231 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(11);                // sn_impl::chain231_t<NV>
		auto& global_cable217 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(11).getT(0); // sn_impl::global_cable217_t<NV>
		auto& add217 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain232 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(12);                // sn_impl::chain232_t<NV>
		auto& global_cable218 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(12).getT(0); // sn_impl::global_cable218_t<NV>
		auto& add218 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain233 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(13);                // sn_impl::chain233_t<NV>
		auto& global_cable219 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(13).getT(0); // sn_impl::global_cable219_t<NV>
		auto& add219 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain234 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(14);                // sn_impl::chain234_t<NV>
		auto& global_cable220 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(14).getT(0); // sn_impl::global_cable220_t<NV>
		auto& add220 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain235 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(15);                // sn_impl::chain235_t<NV>
		auto& global_cable221 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(15).getT(0); // sn_impl::global_cable221_t<NV>
		auto& add221 = this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak13 = this->getT(0).getT(0).getT(0).getT(10).getT(1);                           // sn_impl::peak13_t<NV>
		auto& clear13 = this->getT(0).getT(0).getT(0).getT(10).getT(2);                          // math::clear<NV>
		auto& pma14 = this->getT(0).getT(0).getT(0).getT(10).getT(3);                            // sn_impl::pma14_t<NV>
		auto& chain236 = this->getT(0).getT(0).getT(0).getT(11);                                 // sn_impl::chain236_t<NV>
		auto& branch14 = this->getT(0).getT(0).getT(0).getT(11).getT(0);                         // sn_impl::branch14_t<NV>
		auto& chain237 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(0);                 // sn_impl::chain237_t<NV>
		auto& global_cable222 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(0).getT(0);  // sn_impl::global_cable222_t<NV>
		auto& add222 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain238 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(1);                 // sn_impl::chain238_t<NV>
		auto& global_cable223 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(1).getT(0);  // sn_impl::global_cable223_t<NV>
		auto& add223 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain239 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(2);                 // sn_impl::chain239_t<NV>
		auto& global_cable224 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(2).getT(0);  // sn_impl::global_cable224_t<NV>
		auto& add224 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain240 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(3);                 // sn_impl::chain240_t<NV>
		auto& global_cable225 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(3).getT(0);  // sn_impl::global_cable225_t<NV>
		auto& add225 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain241 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(4);                 // sn_impl::chain241_t<NV>
		auto& global_cable226 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(4).getT(0);  // sn_impl::global_cable226_t<NV>
		auto& add226 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain242 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(5);                 // sn_impl::chain242_t<NV>
		auto& global_cable227 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(5).getT(0);  // sn_impl::global_cable227_t<NV>
		auto& add227 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain243 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(6);                 // sn_impl::chain243_t<NV>
		auto& global_cable228 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(6).getT(0);  // sn_impl::global_cable228_t<NV>
		auto& add228 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain244 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(7);                 // sn_impl::chain244_t<NV>
		auto& global_cable229 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(7).getT(0);  // sn_impl::global_cable229_t<NV>
		auto& add229 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain245 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(8);                 // sn_impl::chain245_t<NV>
		auto& global_cable230 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(8).getT(0);  // sn_impl::global_cable230_t<NV>
		auto& add230 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain246 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(9);                 // sn_impl::chain246_t<NV>
		auto& global_cable231 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(9).getT(0);  // sn_impl::global_cable231_t<NV>
		auto& add231 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain247 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(10);                // sn_impl::chain247_t<NV>
		auto& global_cable232 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(10).getT(0); // sn_impl::global_cable232_t<NV>
		auto& add232 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain248 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(11);                // sn_impl::chain248_t<NV>
		auto& global_cable233 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(11).getT(0); // sn_impl::global_cable233_t<NV>
		auto& add233 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain249 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(12);                // sn_impl::chain249_t<NV>
		auto& global_cable234 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(12).getT(0); // sn_impl::global_cable234_t<NV>
		auto& add234 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain250 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(13);                // sn_impl::chain250_t<NV>
		auto& global_cable235 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(13).getT(0); // sn_impl::global_cable235_t<NV>
		auto& add235 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain251 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(14);                // sn_impl::chain251_t<NV>
		auto& global_cable236 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(14).getT(0); // sn_impl::global_cable236_t<NV>
		auto& add236 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain252 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(15);                // sn_impl::chain252_t<NV>
		auto& global_cable237 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(15).getT(0); // sn_impl::global_cable237_t<NV>
		auto& add237 = this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak14 = this->getT(0).getT(0).getT(0).getT(11).getT(1);                           // sn_impl::peak14_t<NV>
		auto& clear14 = this->getT(0).getT(0).getT(0).getT(11).getT(2);                          // math::clear<NV>
		auto& pma15 = this->getT(0).getT(0).getT(0).getT(11).getT(3);                            // sn_impl::pma15_t<NV>
		auto& chain253 = this->getT(0).getT(0).getT(0).getT(12);                                 // sn_impl::chain253_t<NV>
		auto& branch15 = this->getT(0).getT(0).getT(0).getT(12).getT(0);                         // sn_impl::branch15_t<NV>
		auto& chain254 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(0);                 // sn_impl::chain254_t<NV>
		auto& global_cable238 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(0).getT(0);  // sn_impl::global_cable238_t<NV>
		auto& add238 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain255 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(1);                 // sn_impl::chain255_t<NV>
		auto& global_cable239 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(1).getT(0);  // sn_impl::global_cable239_t<NV>
		auto& add239 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain256 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(2);                 // sn_impl::chain256_t<NV>
		auto& global_cable240 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(2).getT(0);  // sn_impl::global_cable240_t<NV>
		auto& add240 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain257 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(3);                 // sn_impl::chain257_t<NV>
		auto& global_cable241 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(3).getT(0);  // sn_impl::global_cable241_t<NV>
		auto& add241 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain258 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(4);                 // sn_impl::chain258_t<NV>
		auto& global_cable242 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(4).getT(0);  // sn_impl::global_cable242_t<NV>
		auto& add242 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain259 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(5);                 // sn_impl::chain259_t<NV>
		auto& global_cable243 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(5).getT(0);  // sn_impl::global_cable243_t<NV>
		auto& add243 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain260 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(6);                 // sn_impl::chain260_t<NV>
		auto& global_cable244 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(6).getT(0);  // sn_impl::global_cable244_t<NV>
		auto& add244 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain261 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(7);                 // sn_impl::chain261_t<NV>
		auto& global_cable245 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(7).getT(0);  // sn_impl::global_cable245_t<NV>
		auto& add245 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain262 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(8);                 // sn_impl::chain262_t<NV>
		auto& global_cable246 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(8).getT(0);  // sn_impl::global_cable246_t<NV>
		auto& add246 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain263 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(9);                 // sn_impl::chain263_t<NV>
		auto& global_cable247 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(9).getT(0);  // sn_impl::global_cable247_t<NV>
		auto& add247 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain264 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(10);                // sn_impl::chain264_t<NV>
		auto& global_cable248 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(10).getT(0); // sn_impl::global_cable248_t<NV>
		auto& add248 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain265 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(11);                // sn_impl::chain265_t<NV>
		auto& global_cable249 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(11).getT(0); // sn_impl::global_cable249_t<NV>
		auto& add249 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain266 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(12);                // sn_impl::chain266_t<NV>
		auto& global_cable250 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(12).getT(0); // sn_impl::global_cable250_t<NV>
		auto& add250 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain267 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(13);                // sn_impl::chain267_t<NV>
		auto& global_cable251 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(13).getT(0); // sn_impl::global_cable251_t<NV>
		auto& add251 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain268 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(14);                // sn_impl::chain268_t<NV>
		auto& global_cable252 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(14).getT(0); // sn_impl::global_cable252_t<NV>
		auto& add252 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain269 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(15);                // sn_impl::chain269_t<NV>
		auto& global_cable253 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(15).getT(0); // sn_impl::global_cable253_t<NV>
		auto& add253 = this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak15 = this->getT(0).getT(0).getT(0).getT(12).getT(1);                           // sn_impl::peak15_t<NV>
		auto& clear15 = this->getT(0).getT(0).getT(0).getT(12).getT(2);                          // math::clear<NV>
		auto& pma16 = this->getT(0).getT(0).getT(0).getT(12).getT(3);                            // sn_impl::pma16_t<NV>
		auto& chain287 = this->getT(0).getT(0).getT(0).getT(13);                                 // sn_impl::chain287_t<NV>
		auto& branch17 = this->getT(0).getT(0).getT(0).getT(13).getT(0);                         // sn_impl::branch17_t<NV>
		auto& chain288 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(0);                 // sn_impl::chain288_t<NV>
		auto& global_cable270 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(0).getT(0);  // sn_impl::global_cable270_t<NV>
		auto& add270 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain289 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(1);                 // sn_impl::chain289_t<NV>
		auto& global_cable271 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(1).getT(0);  // sn_impl::global_cable271_t<NV>
		auto& add271 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain290 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(2);                 // sn_impl::chain290_t<NV>
		auto& global_cable272 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(2).getT(0);  // sn_impl::global_cable272_t<NV>
		auto& add272 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain291 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(3);                 // sn_impl::chain291_t<NV>
		auto& global_cable273 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(3).getT(0);  // sn_impl::global_cable273_t<NV>
		auto& add273 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain292 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(4);                 // sn_impl::chain292_t<NV>
		auto& global_cable274 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(4).getT(0);  // sn_impl::global_cable274_t<NV>
		auto& add274 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain293 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(5);                 // sn_impl::chain293_t<NV>
		auto& global_cable275 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(5).getT(0);  // sn_impl::global_cable275_t<NV>
		auto& add275 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain294 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(6);                 // sn_impl::chain294_t<NV>
		auto& global_cable276 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(6).getT(0);  // sn_impl::global_cable276_t<NV>
		auto& add276 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain295 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(7);                 // sn_impl::chain295_t<NV>
		auto& global_cable277 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(7).getT(0);  // sn_impl::global_cable277_t<NV>
		auto& add277 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain296 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(8);                 // sn_impl::chain296_t<NV>
		auto& global_cable278 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(8).getT(0);  // sn_impl::global_cable278_t<NV>
		auto& add278 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain297 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(9);                 // sn_impl::chain297_t<NV>
		auto& global_cable279 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(9).getT(0);  // sn_impl::global_cable279_t<NV>
		auto& add279 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain298 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(10);                // sn_impl::chain298_t<NV>
		auto& global_cable280 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(10).getT(0); // sn_impl::global_cable280_t<NV>
		auto& add280 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain299 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(11);                // sn_impl::chain299_t<NV>
		auto& global_cable281 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(11).getT(0); // sn_impl::global_cable281_t<NV>
		auto& add281 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain300 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(12);                // sn_impl::chain300_t<NV>
		auto& global_cable282 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(12).getT(0); // sn_impl::global_cable282_t<NV>
		auto& add282 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain301 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(13);                // sn_impl::chain301_t<NV>
		auto& global_cable283 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(13).getT(0); // sn_impl::global_cable283_t<NV>
		auto& add283 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain302 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(14);                // sn_impl::chain302_t<NV>
		auto& global_cable284 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(14).getT(0); // sn_impl::global_cable284_t<NV>
		auto& add284 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain303 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(15);                // sn_impl::chain303_t<NV>
		auto& global_cable285 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(15).getT(0); // sn_impl::global_cable285_t<NV>
		auto& add285 = this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak17 = this->getT(0).getT(0).getT(0).getT(13).getT(1);                           // sn_impl::peak17_t<NV>
		auto& clear17 = this->getT(0).getT(0).getT(0).getT(13).getT(2);                          // math::clear<NV>
		auto& pma18 = this->getT(0).getT(0).getT(0).getT(13).getT(3);                            // sn_impl::pma18_t<NV>
		auto& chain270 = this->getT(0).getT(0).getT(0).getT(14);                                 // sn_impl::chain270_t<NV>
		auto& branch16 = this->getT(0).getT(0).getT(0).getT(14).getT(0);                         // sn_impl::branch16_t<NV>
		auto& chain271 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(0);                 // sn_impl::chain271_t<NV>
		auto& global_cable254 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(0).getT(0);  // sn_impl::global_cable254_t<NV>
		auto& add254 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain272 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(1);                 // sn_impl::chain272_t<NV>
		auto& global_cable255 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(1).getT(0);  // sn_impl::global_cable255_t<NV>
		auto& add255 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain273 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(2);                 // sn_impl::chain273_t<NV>
		auto& global_cable256 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(2).getT(0);  // sn_impl::global_cable256_t<NV>
		auto& add256 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain274 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(3);                 // sn_impl::chain274_t<NV>
		auto& global_cable257 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(3).getT(0);  // sn_impl::global_cable257_t<NV>
		auto& add257 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain275 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(4);                 // sn_impl::chain275_t<NV>
		auto& global_cable258 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(4).getT(0);  // sn_impl::global_cable258_t<NV>
		auto& add258 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain276 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(5);                 // sn_impl::chain276_t<NV>
		auto& global_cable259 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(5).getT(0);  // sn_impl::global_cable259_t<NV>
		auto& add259 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain277 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(6);                 // sn_impl::chain277_t<NV>
		auto& global_cable260 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(6).getT(0);  // sn_impl::global_cable260_t<NV>
		auto& add260 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain278 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(7);                 // sn_impl::chain278_t<NV>
		auto& global_cable261 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(7).getT(0);  // sn_impl::global_cable261_t<NV>
		auto& add261 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain279 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(8);                 // sn_impl::chain279_t<NV>
		auto& global_cable262 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(8).getT(0);  // sn_impl::global_cable262_t<NV>
		auto& add262 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain280 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(9);                 // sn_impl::chain280_t<NV>
		auto& global_cable263 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(9).getT(0);  // sn_impl::global_cable263_t<NV>
		auto& add263 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain281 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(10);                // sn_impl::chain281_t<NV>
		auto& global_cable264 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(10).getT(0); // sn_impl::global_cable264_t<NV>
		auto& add264 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain282 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(11);                // sn_impl::chain282_t<NV>
		auto& global_cable265 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(11).getT(0); // sn_impl::global_cable265_t<NV>
		auto& add265 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain283 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(12);                // sn_impl::chain283_t<NV>
		auto& global_cable266 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(12).getT(0); // sn_impl::global_cable266_t<NV>
		auto& add266 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain284 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(13);                // sn_impl::chain284_t<NV>
		auto& global_cable267 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(13).getT(0); // sn_impl::global_cable267_t<NV>
		auto& add267 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain285 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(14);                // sn_impl::chain285_t<NV>
		auto& global_cable268 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(14).getT(0); // sn_impl::global_cable268_t<NV>
		auto& add268 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain286 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(15);                // sn_impl::chain286_t<NV>
		auto& global_cable269 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(15).getT(0); // sn_impl::global_cable269_t<NV>
		auto& add269 = this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak16 = this->getT(0).getT(0).getT(0).getT(14).getT(1);                           // sn_impl::peak16_t<NV>
		auto& clear16 = this->getT(0).getT(0).getT(0).getT(14).getT(2);                          // math::clear<NV>
		auto& pma17 = this->getT(0).getT(0).getT(0).getT(14).getT(3);                            // sn_impl::pma17_t<NV>
		auto& chain304 = this->getT(0).getT(0).getT(0).getT(15);                                 // sn_impl::chain304_t<NV>
		auto& branch19 = this->getT(0).getT(0).getT(0).getT(15).getT(0);                         // sn_impl::branch19_t<NV>
		auto& chain305 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(0);                 // sn_impl::chain305_t<NV>
		auto& global_cable286 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(0).getT(0);  // sn_impl::global_cable286_t<NV>
		auto& add286 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain306 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(1);                 // sn_impl::chain306_t<NV>
		auto& global_cable287 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(1).getT(0);  // sn_impl::global_cable287_t<NV>
		auto& add287 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain307 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(2);                 // sn_impl::chain307_t<NV>
		auto& global_cable288 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(2).getT(0);  // sn_impl::global_cable288_t<NV>
		auto& add288 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain308 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(3);                 // sn_impl::chain308_t<NV>
		auto& global_cable289 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(3).getT(0);  // sn_impl::global_cable289_t<NV>
		auto& add289 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain309 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(4);                 // sn_impl::chain309_t<NV>
		auto& global_cable290 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(4).getT(0);  // sn_impl::global_cable290_t<NV>
		auto& add290 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain310 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(5);                 // sn_impl::chain310_t<NV>
		auto& global_cable291 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(5).getT(0);  // sn_impl::global_cable291_t<NV>
		auto& add291 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain311 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(6);                 // sn_impl::chain311_t<NV>
		auto& global_cable292 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(6).getT(0);  // sn_impl::global_cable292_t<NV>
		auto& add292 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain312 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(7);                 // sn_impl::chain312_t<NV>
		auto& global_cable293 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(7).getT(0);  // sn_impl::global_cable293_t<NV>
		auto& add293 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain313 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(8);                 // sn_impl::chain313_t<NV>
		auto& global_cable294 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(8).getT(0);  // sn_impl::global_cable294_t<NV>
		auto& add294 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain314 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(9);                 // sn_impl::chain314_t<NV>
		auto& global_cable295 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(9).getT(0);  // sn_impl::global_cable295_t<NV>
		auto& add295 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain315 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(10);                // sn_impl::chain315_t<NV>
		auto& global_cable296 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(10).getT(0); // sn_impl::global_cable296_t<NV>
		auto& add296 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain316 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(11);                // sn_impl::chain316_t<NV>
		auto& global_cable297 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(11).getT(0); // sn_impl::global_cable297_t<NV>
		auto& add297 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain317 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(12);                // sn_impl::chain317_t<NV>
		auto& global_cable298 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(12).getT(0); // sn_impl::global_cable298_t<NV>
		auto& add298 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain318 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(13);                // sn_impl::chain318_t<NV>
		auto& global_cable299 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(13).getT(0); // sn_impl::global_cable299_t<NV>
		auto& add299 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain319 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(14);                // sn_impl::chain319_t<NV>
		auto& global_cable300 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(14).getT(0); // sn_impl::global_cable300_t<NV>
		auto& add300 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain320 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(15);                // sn_impl::chain320_t<NV>
		auto& global_cable301 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(15).getT(0); // sn_impl::global_cable301_t<NV>
		auto& add301 = this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak24 = this->getT(0).getT(0).getT(0).getT(15).getT(1);                           // sn_impl::peak24_t<NV>
		auto& clear18 = this->getT(0).getT(0).getT(0).getT(15).getT(2);                          // math::clear<NV>
		auto& pma19 = this->getT(0).getT(0).getT(0).getT(15).getT(3);                            // sn_impl::pma19_t<NV>
		auto& chain321 = this->getT(0).getT(0).getT(0).getT(16);                                 // sn_impl::chain321_t<NV>
		auto& branch20 = this->getT(0).getT(0).getT(0).getT(16).getT(0);                         // sn_impl::branch20_t<NV>
		auto& chain322 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(0);                 // sn_impl::chain322_t<NV>
		auto& global_cable302 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(0).getT(0);  // sn_impl::global_cable302_t<NV>
		auto& add302 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain323 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(1);                 // sn_impl::chain323_t<NV>
		auto& global_cable303 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(1).getT(0);  // sn_impl::global_cable303_t<NV>
		auto& add303 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain324 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(2);                 // sn_impl::chain324_t<NV>
		auto& global_cable304 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(2).getT(0);  // sn_impl::global_cable304_t<NV>
		auto& add304 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain325 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(3);                 // sn_impl::chain325_t<NV>
		auto& global_cable305 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(3).getT(0);  // sn_impl::global_cable305_t<NV>
		auto& add305 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain326 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(4);                 // sn_impl::chain326_t<NV>
		auto& global_cable306 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(4).getT(0);  // sn_impl::global_cable306_t<NV>
		auto& add306 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain327 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(5);                 // sn_impl::chain327_t<NV>
		auto& global_cable307 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(5).getT(0);  // sn_impl::global_cable307_t<NV>
		auto& add307 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain328 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(6);                 // sn_impl::chain328_t<NV>
		auto& global_cable308 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(6).getT(0);  // sn_impl::global_cable308_t<NV>
		auto& add308 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain329 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(7);                 // sn_impl::chain329_t<NV>
		auto& global_cable309 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(7).getT(0);  // sn_impl::global_cable309_t<NV>
		auto& add309 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain330 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(8);                 // sn_impl::chain330_t<NV>
		auto& global_cable310 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(8).getT(0);  // sn_impl::global_cable310_t<NV>
		auto& add310 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain331 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(9);                 // sn_impl::chain331_t<NV>
		auto& global_cable311 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(9).getT(0);  // sn_impl::global_cable311_t<NV>
		auto& add311 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain332 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(10);                // sn_impl::chain332_t<NV>
		auto& global_cable312 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(10).getT(0); // sn_impl::global_cable312_t<NV>
		auto& add312 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain333 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(11);                // sn_impl::chain333_t<NV>
		auto& global_cable313 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(11).getT(0); // sn_impl::global_cable313_t<NV>
		auto& add313 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain334 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(12);                // sn_impl::chain334_t<NV>
		auto& global_cable314 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(12).getT(0); // sn_impl::global_cable314_t<NV>
		auto& add314 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain335 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(13);                // sn_impl::chain335_t<NV>
		auto& global_cable315 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(13).getT(0); // sn_impl::global_cable315_t<NV>
		auto& add315 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain336 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(14);                // sn_impl::chain336_t<NV>
		auto& global_cable316 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(14).getT(0); // sn_impl::global_cable316_t<NV>
		auto& add316 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain337 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(15);                // sn_impl::chain337_t<NV>
		auto& global_cable317 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(15).getT(0); // sn_impl::global_cable317_t<NV>
		auto& add317 = this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak25 = this->getT(0).getT(0).getT(0).getT(16).getT(1);                           // sn_impl::peak25_t<NV>
		auto& clear19 = this->getT(0).getT(0).getT(0).getT(16).getT(2);                          // math::clear<NV>
		auto& pma20 = this->getT(0).getT(0).getT(0).getT(16).getT(3);                            // sn_impl::pma20_t<NV>
		auto& chain117 = this->getT(0).getT(0).getT(0).getT(17);                                 // sn_impl::chain117_t<NV>
		auto& branch7 = this->getT(0).getT(0).getT(0).getT(17).getT(0);                          // sn_impl::branch7_t<NV>
		auto& chain118 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(0);                 // sn_impl::chain118_t<NV>
		auto& global_cable110 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(0).getT(0);  // sn_impl::global_cable110_t<NV>
		auto& add110 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain119 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(1);                 // sn_impl::chain119_t<NV>
		auto& global_cable111 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(1).getT(0);  // sn_impl::global_cable111_t<NV>
		auto& add111 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain120 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(2);                 // sn_impl::chain120_t<NV>
		auto& global_cable112 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(2).getT(0);  // sn_impl::global_cable112_t<NV>
		auto& add112 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain121 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(3);                 // sn_impl::chain121_t<NV>
		auto& global_cable113 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(3).getT(0);  // sn_impl::global_cable113_t<NV>
		auto& add113 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain122 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(4);                 // sn_impl::chain122_t<NV>
		auto& global_cable114 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(4).getT(0);  // sn_impl::global_cable114_t<NV>
		auto& add114 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain123 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(5);                 // sn_impl::chain123_t<NV>
		auto& global_cable115 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(5).getT(0);  // sn_impl::global_cable115_t<NV>
		auto& add115 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain124 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(6);                 // sn_impl::chain124_t<NV>
		auto& global_cable116 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(6).getT(0);  // sn_impl::global_cable116_t<NV>
		auto& add116 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain125 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(7);                 // sn_impl::chain125_t<NV>
		auto& global_cable117 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(7).getT(0);  // sn_impl::global_cable117_t<NV>
		auto& add117 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain126 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(8);                 // sn_impl::chain126_t<NV>
		auto& global_cable118 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(8).getT(0);  // sn_impl::global_cable118_t<NV>
		auto& add118 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain127 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(9);                 // sn_impl::chain127_t<NV>
		auto& global_cable119 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(9).getT(0);  // sn_impl::global_cable119_t<NV>
		auto& add119 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain128 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(10);                // sn_impl::chain128_t<NV>
		auto& global_cable120 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(10).getT(0); // sn_impl::global_cable120_t<NV>
		auto& add120 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain129 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(11);                // sn_impl::chain129_t<NV>
		auto& global_cable121 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(11).getT(0); // sn_impl::global_cable121_t<NV>
		auto& add121 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain130 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(12);                // sn_impl::chain130_t<NV>
		auto& global_cable122 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(12).getT(0); // sn_impl::global_cable122_t<NV>
		auto& add122 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain131 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(13);                // sn_impl::chain131_t<NV>
		auto& global_cable123 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(13).getT(0); // sn_impl::global_cable123_t<NV>
		auto& add123 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain132 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(14);                // sn_impl::chain132_t<NV>
		auto& global_cable124 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(14).getT(0); // sn_impl::global_cable124_t<NV>
		auto& add124 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain133 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(15);                // sn_impl::chain133_t<NV>
		auto& global_cable125 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(15).getT(0); // sn_impl::global_cable125_t<NV>
		auto& add125 = this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak7 = this->getT(0).getT(0).getT(0).getT(17).getT(1);                            // sn_impl::peak7_t<NV>
		auto& clear7 = this->getT(0).getT(0).getT(0).getT(17).getT(2);                           // math::clear<NV>
		auto& pma8 = this->getT(0).getT(0).getT(0).getT(17).getT(3);                             // sn_impl::pma8_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(0).getT(17).getT(4);                             // sn_impl::pma7_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(0).getT(17).getT(5);                       // sn_impl::tempo_sync_t<NV>
		auto& tempo_sync1 = this->getT(0).getT(1);                                               // sn_impl::tempo_sync1_t<NV>
		auto& cable_table4 = this->getT(0).getT(2);                                              // sn_impl::cable_table4_t<NV>
		auto& input_toggle = this->getT(0).getT(3);                                              // sn_impl::input_toggle_t<NV>
		auto& snex_node = this->getT(1);                                                         // sn_impl::snex_node_t<NV>
		auto& branch2 = this->getT(2);                                                           // sn_impl::branch2_t
		auto& chain25 = this->getT(2).getT(0);                                                   // sn_impl::chain25_t
		auto& peak1 = this->getT(2).getT(0).getT(0);                                             // sn_impl::peak1_t
		auto& global_cable15 = this->getT(2).getT(0).getT(1);                                    // routing::global_cable<global_cable15_t_index, parameter::empty>
		auto& chain28 = this->getT(2).getT(1);                                                   // sn_impl::chain28_t
		auto& peak19 = this->getT(2).getT(1).getT(0);                                            // sn_impl::peak19_t
		auto& global_cable18 = this->getT(2).getT(1).getT(1);                                    // routing::global_cable<global_cable18_t_index, parameter::empty>
		auto& chain27 = this->getT(2).getT(2);                                                   // sn_impl::chain27_t
		auto& peak18 = this->getT(2).getT(2).getT(0);                                            // sn_impl::peak18_t
		auto& global_cable17 = this->getT(2).getT(2).getT(1);                                    // routing::global_cable<global_cable17_t_index, parameter::empty>
		auto& chain26 = this->getT(2).getT(3);                                                   // sn_impl::chain26_t
		auto& peak2 = this->getT(2).getT(3).getT(0);                                             // sn_impl::peak2_t
		auto& global_cable16 = this->getT(2).getT(3).getT(1);                                    // routing::global_cable<global_cable16_t_index, parameter::empty>
		auto& chain23 = this->getT(3);                                                           // sn_impl::chain23_t<NV>
		auto& xfader1 = this->getT(3).getT(0);                                                   // sn_impl::xfader1_t<NV>
		auto& split3 = this->getT(3).getT(1);                                                    // sn_impl::split3_t<NV>
		auto& chain24 = this->getT(3).getT(1).getT(0);                                           // sn_impl::chain24_t<NV>
		auto& gain4 = this->getT(3).getT(1).getT(0).getT(0);                                     // core::gain<NV>
		auto& chain33 = this->getT(3).getT(1).getT(1);                                           // sn_impl::chain33_t<NV>
		auto& svf1 = this->getT(3).getT(1).getT(1).getT(0);                                      // filters::svf<NV>
		auto& gain5 = this->getT(3).getT(1).getT(1).getT(1);                                     // core::gain<NV>
		auto& xfader = this->getT(4);                                                            // sn_impl::xfader_t<NV>
		auto& chain16 = this->getT(5);                                                           // sn_impl::chain16_t<NV>
		auto& split1 = this->getT(5).getT(0);                                                    // sn_impl::split1_t<NV>
		auto& chain22 = this->getT(5).getT(0).getT(0);                                           // sn_impl::chain22_t<NV>
		auto& gain = this->getT(5).getT(0).getT(0).getT(0);                                      // core::gain<NV>
		auto& chain19 = this->getT(5).getT(0).getT(1);                                           // sn_impl::chain19_t<NV>
		auto& branch1 = this->getT(5).getT(0).getT(1).getT(0);                                   // sn_impl::branch1_t<NV>
		auto& chain20 = this->getT(5).getT(0).getT(1).getT(0).getT(0);                           // sn_impl::chain20_t
		auto& fix8_block1 = this->getT(5).getT(0).getT(1).getT(0).getT(1);                       // sn_impl::fix8_block1_t<NV>
		auto& chain18 = this->getT(5).getT(0).getT(1).getT(0).getT(1).getT(0);                   // sn_impl::chain18_t<NV>
		auto& chain41 = this->getT(5).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0);           // sn_impl::chain41_t<NV>
		auto& midi3 = this->getT(5).getT(0).getT(1).getT(0).                                     // sn_impl::midi3_t<NV>
                      getT(1).getT(0).getT(0).getT(0);
		auto& offline2 = this->getT(5).getT(0).getT(1).getT(0).                              // sn_impl::offline2_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& converter6 = this->getT(5).getT(0).getT(1).getT(0).                            // sn_impl::converter6_t<NV>
                           getT(1).getT(0).getT(0).getT(1).
                           getT(0);
		auto& converter7 = this->getT(5).getT(0).getT(1).getT(0).                            // sn_impl::converter7_t<NV>
                           getT(1).getT(0).getT(0).getT(1).
                           getT(1);
		auto& frame2_block1 = this->getT(5).getT(0).getT(1).getT(0).getT(1).getT(0).getT(1); // sn_impl::frame2_block1_t<NV>
		auto& pma_unscaled3 = this->getT(5).getT(0).getT(1).getT(0).                         // sn_impl::pma_unscaled3_t<NV>
                              getT(1).getT(0).getT(1).getT(0);
		auto& receive3 = this->getT(5).getT(0).getT(1).getT(0).                     // routing::receive<NV, stereo_frame_cable<NV>>
                         getT(1).getT(0).getT(1).getT(1);
		auto& one_pole5 = this->getT(5).getT(0).getT(1).getT(0).                    // filters::one_pole<NV>
                          getT(1).getT(0).getT(1).getT(2);
		auto& fix_delay = this->getT(5).getT(0).getT(1).getT(0).                    // wrap::no_process<core::fix_delay>
                          getT(1).getT(0).getT(1).getT(3);
		auto& jdelay_thiran3 = this->getT(5).getT(0).getT(1).getT(0).               // jdsp::jdelay_thiran<NV>
                               getT(1).getT(0).getT(1).getT(4);
		auto& send3 = this->getT(5).getT(0).getT(1).getT(0).                        // routing::send<NV, stereo_frame_cable<NV>>
                      getT(1).getT(0).getT(1).getT(5);
		auto& one_pole3 = this->getT(5).getT(0).getT(1).getT(0).                    // filters::one_pole<NV>
                          getT(1).getT(0).getT(1).getT(6);
		auto& chain17 = this->getT(5).getT(0).getT(1).getT(0).getT(2);              // sn_impl::chain17_t<NV>
		auto& clone_cable = this->getT(5).getT(0).getT(1).getT(0).getT(2).getT(0);  // sn_impl::clone_cable_t<NV>
		auto& clone_cable1 = this->getT(5).getT(0).getT(1).getT(0).getT(2).getT(1); // sn_impl::clone_cable1_t<NV>
		auto& cable_table6 = this->getT(5).getT(0).getT(1).getT(0).getT(2).getT(2); // sn_impl::cable_table6_t<NV>
		auto& clone_cable2 = this->getT(5).getT(0).getT(1).getT(0).getT(2).getT(3); // sn_impl::clone_cable2_t<NV>
		auto& clone = this->getT(5).getT(0).getT(1).getT(0).getT(2).getT(4);        // sn_impl::clone_t<NV>        // sn_impl::clone_child_t<NV>
		auto res2 = this->getT(5).getT(0).getT(1).getT(0).getT(2).getT(4).getT(0);  // project::res2<NV>
		auto gain2 = this->getT(5).getT(0).getT(1).getT(0).getT(2).getT(4).getT(1); // core::gain<NV>
		auto& one_pole2 = this->getT(5).getT(0).getT(1).getT(0).getT(2).getT(5);    // filters::one_pole<NV>
		auto& gain1 = this->getT(5).getT(0).getT(1).getT(1);                        // core::gain<NV>
		auto& chain34 = this->getT(6);                                              // sn_impl::chain34_t<NV>
		auto& xfader2 = this->getT(6).getT(0);                                      // sn_impl::xfader2_t<NV>
		auto& split4 = this->getT(6).getT(1);                                       // sn_impl::split4_t<NV>
		auto& chain35 = this->getT(6).getT(1).getT(0);                              // sn_impl::chain35_t<NV>
		auto& gain6 = this->getT(6).getT(1).getT(0).getT(0);                        // core::gain<NV>
		auto& chain36 = this->getT(6).getT(1).getT(1);                              // sn_impl::chain36_t<NV>
		auto& svf2 = this->getT(6).getT(1).getT(1).getT(0);                         // filters::svf<NV>
		auto& gain7 = this->getT(6).getT(1).getT(1).getT(1);                        // core::gain<NV>
		auto& gain3 = this->getT(7);                                                // core::gain<NV>
		auto& jpanner = this->getT(8);                                              // jdsp::jpanner<NV>
		auto& branch18 = this->getT(9);                                             // sn_impl::branch18_t
		auto& chain29 = this->getT(9).getT(0);                                      // sn_impl::chain29_t
		auto& peak20 = this->getT(9).getT(0).getT(0);                               // sn_impl::peak20_t
		auto& global_cable19 = this->getT(9).getT(0).getT(1);                       // routing::global_cable<global_cable19_t_index, parameter::empty>
		auto& chain30 = this->getT(9).getT(1);                                      // sn_impl::chain30_t
		auto& peak21 = this->getT(9).getT(1).getT(0);                               // sn_impl::peak21_t
		auto& global_cable20 = this->getT(9).getT(1).getT(1);                       // routing::global_cable<global_cable20_t_index, parameter::empty>
		auto& chain31 = this->getT(9).getT(2);                                      // sn_impl::chain31_t
		auto& peak22 = this->getT(9).getT(2).getT(0);                               // sn_impl::peak22_t
		auto& global_cable21 = this->getT(9).getT(2).getT(1);                       // routing::global_cable<global_cable21_t_index, parameter::empty>
		auto& chain32 = this->getT(9).getT(3);                                      // sn_impl::chain32_t
		auto& peak23 = this->getT(9).getT(3).getT(0);                               // sn_impl::peak23_t
		auto& global_cable22 = this->getT(9).getT(3).getT(1);                       // routing::global_cable<global_cable22_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& PitchMode_p = this->getParameterT(0);
		PitchMode_p.connectT(0, cable_table4); // PitchMode -> cable_table4::Value
		PitchMode_p.connectT(1, snex_node);    // PitchMode -> snex_node::pitchMode
		
		this->getParameterT(1).connectT(0, snex_node); // MaxGrains -> snex_node::maxGrains
		
		this->getParameterT(2).connectT(0, snex_node); // scrubMode -> snex_node::scrubMode
		
		this->getParameterT(3).connectT(0, snex_node); // scrubBlen -> snex_node::scrubBlend
		
		this->getParameterT(4).connectT(0, snex_node); // reverse -> snex_node::reverse
		
		this->getParameterT(5).connectT(0, pma); // Position -> pma::Add
		
		this->getParameterT(6).connectT(0, pma); // PositionMod -> pma::Multiply
		
		this->getParameterT(7).connectT(0, branch); // PositionSrc -> branch::Index
		
		this->getParameterT(8).connectT(0, pma3); // Pos2 -> pma3::Add
		
		this->getParameterT(9).connectT(0, pma3); // Pos2Mod -> pma3::Multiply
		
		this->getParameterT(10).connectT(0, branch3); // Pos2Src -> branch3::Index
		
		this->getParameterT(11).connectT(0, pma4); // Pos3 -> pma4::Add
		
		this->getParameterT(12).connectT(0, pma4); // Pos3Mod -> pma4::Multiply
		
		this->getParameterT(13).connectT(0, branch4); // Pos3Src -> branch4::Index
		
		this->getParameterT(14).connectT(0, pma5); // Pos4 -> pma5::Add
		
		this->getParameterT(15).connectT(0, pma5); // Pos4Mod -> pma5::Multiply
		
		this->getParameterT(16).connectT(0, branch5); // Pos4Src -> branch5::Index
		
		this->getParameterT(17).connectT(0, pma6); // Pitch -> pma6::Add
		
		this->getParameterT(18).connectT(0, pma6); // PitchMod -> pma6::Multiply
		
		this->getParameterT(19).connectT(0, branch6); // PitchSrc -> branch6::Index
		
		this->getParameterT(20).connectT(0, pma9); // Dense -> pma9::Add
		
		this->getParameterT(21).connectT(0, pma9); // DenseMod -> pma9::Multiply
		
		this->getParameterT(22).connectT(0, branch8); // DenseSrc -> branch8::Index
		
		this->getParameterT(23).connectT(0, pma10); // WinShape -> pma10::Add
		
		this->getParameterT(24).connectT(0, branch9); // WinShapeSrc -> branch9::Index
		
		this->getParameterT(25).connectT(0, pma11); // PanSpread -> pma11::Add
		
		this->getParameterT(26).connectT(0, pma11); // PanSpreadMod -> pma11::Multiply
		
		this->getParameterT(27).connectT(0, branch10); // PanSprdsrc -> branch10::Index
		
		this->getParameterT(28).connectT(0, pma12); // PitchSprd -> pma12::Add
		
		auto& PitchSprdMod_p = this->getParameterT(29);
		PitchSprdMod_p.connectT(0, pma12); // PitchSprdMod -> pma12::Multiply
		PitchSprdMod_p.connectT(1, pma21); // PitchSprdMod -> pma21::Multiply
		
		this->getParameterT(30).connectT(0, branch11); // PitchSprdSrc -> branch11::Index
		
		this->getParameterT(31).connectT(0, pma2); // phaseScatter -> pma2::Add
		
		this->getParameterT(32).connectT(0, pma2); // phaseScatterMod -> pma2::Multiply
		
		this->getParameterT(33).connectT(0, branch12); // phaseScatterSrc -> branch12::Index
		
		this->getParameterT(34).connectT(0, pma8); // GrainSize -> pma8::Add
		
		auto& GrainMod_p = this->getParameterT(35);
		GrainMod_p.connectT(0, pma7); // GrainMod -> pma7::Multiply
		GrainMod_p.connectT(1, pma8); // GrainMod -> pma8::Multiply
		
		this->getParameterT(36).connectT(0, branch7); // GrainSrc -> branch7::Index
		
		this->getParameterT(37).connectT(0, pma7); // GrainTempo -> pma7::Add
		
		this->getParameterT(38).connectT(0, tempo_sync); // GrainDiv -> tempo_sync::Multiplier
		
		this->getParameterT(39).connectT(0, tempo_sync); // GrainSync -> tempo_sync::Enabled
		
		this->getParameterT(40).connectT(0, pma10); // WinShapeMod -> pma10::Multiply
		
		this->getParameterT(41).connectT(0, pma14); // PreCut -> pma14::Add
		
		this->getParameterT(42).connectT(0, pma14); // PreCutMod -> pma14::Multiply
		
		this->getParameterT(43).connectT(0, branch13); // PreCutSrc -> branch13::Index
		
		this->getParameterT(44).connectT(0, svf1); // PreCutMode -> svf1::Mode
		
		this->getParameterT(45).connectT(0, svf1); // PreCutQ -> svf1::Q
		
		this->getParameterT(46).connectT(0, pma15); // ResoMix -> pma15::Add
		
		this->getParameterT(47).connectT(0, pma15); // ResoMixMod -> pma15::Multiply
		
		this->getParameterT(48).connectT(0, branch14); // ResoSrc -> branch14::Index
		
		this->getParameterT(49).connectT(0, pma16); // ResPitch -> pma16::Add
		
		this->getParameterT(50).connectT(0, pma16); // RespPitchMod -> pma16::Multiply
		
		this->getParameterT(51).connectT(0, branch15); // ResPitchSrc -> branch15::Index
		
		this->getParameterT(52).connectT(0, pma18); // ResLp -> pma18::Add
		
		this->getParameterT(53).connectT(0, pma18); // ResLpMod -> pma18::Multiply
		
		this->getParameterT(54).connectT(0, branch17); // ResLpSrc -> branch17::Index
		
		this->getParameterT(55).connectT(0, pma17); // PostCut -> pma17::Add
		
		this->getParameterT(56).connectT(0, pma17); // PostCutMod -> pma17::Multiply
		
		this->getParameterT(57).connectT(0, branch16); // PostCutSrc -> branch16::Index
		
		this->getParameterT(58).connectT(0, svf2); // PostQ -> svf2::Q
		
		this->getParameterT(59).connectT(0, svf2); // PostMode -> svf2::Mode
		
		this->getParameterT(60).connectT(0, branch2); // GrainOut -> branch2::Index
		
		this->getParameterT(61).connectT(0, branch18); // ResOut -> branch18::Index
		
		this->getParameterT(62).connectT(0, pma19); // GainMod -> pma19::Multiply
		
		this->getParameterT(63).connectT(0, branch19); // gainSrc -> branch19::Index
		
		this->getParameterT(64).connectT(0, pma19); // Vol -> pma19::Add
		
		this->getParameterT(65).connectT(0, pma20); // Parn -> pma20::Add
		
		this->getParameterT(66).connectT(0, pma20); // PanMod -> pma20::Multiply
		
		this->getParameterT(67).connectT(0, branch20); // PanSrc -> branch20::Index
		
		this->getParameterT(68).connectT(0, xfader1); // Fmix1 -> xfader1::Value
		
		this->getParameterT(69).connectT(0, xfader2); // Fmix2 -> xfader2::Value
		
		this->getParameterT(70).connectT(0, receive3); // feed -> receive3::Feedback
		
		this->getParameterT(71).connectT(0, pma21); // PitchTempo -> pma21::Add
		
		this->getParameterT(72).connectT(0, tempo_sync1); // PitchDiv -> tempo_sync1::Multiplier
		
		this->getParameterT(73).connectT(0, branch1); // delMode -> branch1::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable.getWrappedObject().getParameter().connectT(0, add);          // global_cable -> add::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2);        // global_cable2 -> add2::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add1);        // global_cable1 -> add1::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add14);      // global_cable14 -> add14::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add13);      // global_cable13 -> add13::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add12);      // global_cable12 -> add12::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add11);      // global_cable11 -> add11::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add10);      // global_cable10 -> add10::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, add9);        // global_cable9 -> add9::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add8);        // global_cable8 -> add8::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add7);        // global_cable7 -> add7::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add6);        // global_cable6 -> add6::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add5);        // global_cable5 -> add5::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add4);        // global_cable4 -> add4::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add3);        // global_cable3 -> add3::Value
		global_cable45.getWrappedObject().getParameter().connectT(0, add45);      // global_cable45 -> add45::Value
		pma.getWrappedObject().getParameter().connectT(0, cable_table);           // pma -> cable_table::Value
		pma.getWrappedObject().getParameter().connectT(1, snex_node);             // pma -> snex_node::scrub
		peak.getParameter().connectT(0, pma);                                     // peak -> pma::Value
		global_cable46.getWrappedObject().getParameter().connectT(0, add46);      // global_cable46 -> add46::Value
		global_cable47.getWrappedObject().getParameter().connectT(0, add47);      // global_cable47 -> add47::Value
		global_cable48.getWrappedObject().getParameter().connectT(0, add48);      // global_cable48 -> add48::Value
		global_cable49.getWrappedObject().getParameter().connectT(0, add49);      // global_cable49 -> add49::Value
		global_cable50.getWrappedObject().getParameter().connectT(0, add50);      // global_cable50 -> add50::Value
		global_cable51.getWrappedObject().getParameter().connectT(0, add51);      // global_cable51 -> add51::Value
		global_cable52.getWrappedObject().getParameter().connectT(0, add52);      // global_cable52 -> add52::Value
		global_cable53.getWrappedObject().getParameter().connectT(0, add53);      // global_cable53 -> add53::Value
		global_cable54.getWrappedObject().getParameter().connectT(0, add54);      // global_cable54 -> add54::Value
		global_cable55.getWrappedObject().getParameter().connectT(0, add55);      // global_cable55 -> add55::Value
		global_cable56.getWrappedObject().getParameter().connectT(0, add56);      // global_cable56 -> add56::Value
		global_cable57.getWrappedObject().getParameter().connectT(0, add57);      // global_cable57 -> add57::Value
		global_cable58.getWrappedObject().getParameter().connectT(0, add58);      // global_cable58 -> add58::Value
		global_cable59.getWrappedObject().getParameter().connectT(0, add59);      // global_cable59 -> add59::Value
		global_cable60.getWrappedObject().getParameter().connectT(0, add60);      // global_cable60 -> add60::Value
		global_cable61.getWrappedObject().getParameter().connectT(0, add61);      // global_cable61 -> add61::Value
		pma3.getWrappedObject().getParameter().connectT(0, cable_table1);         // pma3 -> cable_table1::Value
		pma3.getWrappedObject().getParameter().connectT(1, snex_node);            // pma3 -> snex_node::scrubB
		peak3.getParameter().connectT(0, pma3);                                   // peak3 -> pma3::Value
		global_cable62.getWrappedObject().getParameter().connectT(0, add62);      // global_cable62 -> add62::Value
		global_cable63.getWrappedObject().getParameter().connectT(0, add63);      // global_cable63 -> add63::Value
		global_cable64.getWrappedObject().getParameter().connectT(0, add64);      // global_cable64 -> add64::Value
		global_cable65.getWrappedObject().getParameter().connectT(0, add65);      // global_cable65 -> add65::Value
		global_cable66.getWrappedObject().getParameter().connectT(0, add66);      // global_cable66 -> add66::Value
		global_cable67.getWrappedObject().getParameter().connectT(0, add67);      // global_cable67 -> add67::Value
		global_cable68.getWrappedObject().getParameter().connectT(0, add68);      // global_cable68 -> add68::Value
		global_cable69.getWrappedObject().getParameter().connectT(0, add69);      // global_cable69 -> add69::Value
		global_cable70.getWrappedObject().getParameter().connectT(0, add70);      // global_cable70 -> add70::Value
		global_cable71.getWrappedObject().getParameter().connectT(0, add71);      // global_cable71 -> add71::Value
		global_cable72.getWrappedObject().getParameter().connectT(0, add72);      // global_cable72 -> add72::Value
		global_cable73.getWrappedObject().getParameter().connectT(0, add73);      // global_cable73 -> add73::Value
		global_cable74.getWrappedObject().getParameter().connectT(0, add74);      // global_cable74 -> add74::Value
		global_cable75.getWrappedObject().getParameter().connectT(0, add75);      // global_cable75 -> add75::Value
		global_cable76.getWrappedObject().getParameter().connectT(0, add76);      // global_cable76 -> add76::Value
		global_cable77.getWrappedObject().getParameter().connectT(0, add77);      // global_cable77 -> add77::Value
		pma4.getWrappedObject().getParameter().connectT(0, cable_table2);         // pma4 -> cable_table2::Value
		pma4.getWrappedObject().getParameter().connectT(1, snex_node);            // pma4 -> snex_node::scrubC
		peak4.getParameter().connectT(0, pma4);                                   // peak4 -> pma4::Value
		global_cable78.getWrappedObject().getParameter().connectT(0, add78);      // global_cable78 -> add78::Value
		global_cable79.getWrappedObject().getParameter().connectT(0, add79);      // global_cable79 -> add79::Value
		global_cable80.getWrappedObject().getParameter().connectT(0, add80);      // global_cable80 -> add80::Value
		global_cable81.getWrappedObject().getParameter().connectT(0, add81);      // global_cable81 -> add81::Value
		global_cable82.getWrappedObject().getParameter().connectT(0, add82);      // global_cable82 -> add82::Value
		global_cable83.getWrappedObject().getParameter().connectT(0, add83);      // global_cable83 -> add83::Value
		global_cable84.getWrappedObject().getParameter().connectT(0, add84);      // global_cable84 -> add84::Value
		global_cable85.getWrappedObject().getParameter().connectT(0, add85);      // global_cable85 -> add85::Value
		global_cable86.getWrappedObject().getParameter().connectT(0, add86);      // global_cable86 -> add86::Value
		global_cable87.getWrappedObject().getParameter().connectT(0, add87);      // global_cable87 -> add87::Value
		global_cable88.getWrappedObject().getParameter().connectT(0, add88);      // global_cable88 -> add88::Value
		global_cable89.getWrappedObject().getParameter().connectT(0, add89);      // global_cable89 -> add89::Value
		global_cable90.getWrappedObject().getParameter().connectT(0, add90);      // global_cable90 -> add90::Value
		global_cable91.getWrappedObject().getParameter().connectT(0, add91);      // global_cable91 -> add91::Value
		global_cable92.getWrappedObject().getParameter().connectT(0, add92);      // global_cable92 -> add92::Value
		global_cable93.getWrappedObject().getParameter().connectT(0, add93);      // global_cable93 -> add93::Value
		pma5.getWrappedObject().getParameter().connectT(0, cable_table3);         // pma5 -> cable_table3::Value
		pma5.getWrappedObject().getParameter().connectT(1, snex_node);            // pma5 -> snex_node::scrubD
		peak5.getParameter().connectT(0, pma5);                                   // peak5 -> pma5::Value
		global_cable94.getWrappedObject().getParameter().connectT(0, add94);      // global_cable94 -> add94::Value
		global_cable95.getWrappedObject().getParameter().connectT(0, add95);      // global_cable95 -> add95::Value
		global_cable96.getWrappedObject().getParameter().connectT(0, add96);      // global_cable96 -> add96::Value
		global_cable97.getWrappedObject().getParameter().connectT(0, add97);      // global_cable97 -> add97::Value
		global_cable98.getWrappedObject().getParameter().connectT(0, add98);      // global_cable98 -> add98::Value
		global_cable99.getWrappedObject().getParameter().connectT(0, add99);      // global_cable99 -> add99::Value
		global_cable100.getWrappedObject().getParameter().connectT(0, add100);    // global_cable100 -> add100::Value
		global_cable101.getWrappedObject().getParameter().connectT(0, add101);    // global_cable101 -> add101::Value
		global_cable102.getWrappedObject().getParameter().connectT(0, add102);    // global_cable102 -> add102::Value
		global_cable103.getWrappedObject().getParameter().connectT(0, add103);    // global_cable103 -> add103::Value
		global_cable104.getWrappedObject().getParameter().connectT(0, add104);    // global_cable104 -> add104::Value
		global_cable105.getWrappedObject().getParameter().connectT(0, add105);    // global_cable105 -> add105::Value
		global_cable106.getWrappedObject().getParameter().connectT(0, add106);    // global_cable106 -> add106::Value
		global_cable107.getWrappedObject().getParameter().connectT(0, add107);    // global_cable107 -> add107::Value
		global_cable108.getWrappedObject().getParameter().connectT(0, add108);    // global_cable108 -> add108::Value
		global_cable109.getWrappedObject().getParameter().connectT(0, add109);    // global_cable109 -> add109::Value
		pma6.getWrappedObject().getParameter().connectT(0, snex_node);            // pma6 -> snex_node::pitch
		peak6.getParameter().connectT(0, pma6);                                   // peak6 -> pma6::Value
		global_cable126.getWrappedObject().getParameter().connectT(0, add126);    // global_cable126 -> add126::Value
		global_cable127.getWrappedObject().getParameter().connectT(0, add127);    // global_cable127 -> add127::Value
		global_cable128.getWrappedObject().getParameter().connectT(0, add128);    // global_cable128 -> add128::Value
		global_cable129.getWrappedObject().getParameter().connectT(0, add129);    // global_cable129 -> add129::Value
		global_cable130.getWrappedObject().getParameter().connectT(0, add130);    // global_cable130 -> add130::Value
		global_cable131.getWrappedObject().getParameter().connectT(0, add131);    // global_cable131 -> add131::Value
		global_cable132.getWrappedObject().getParameter().connectT(0, add132);    // global_cable132 -> add132::Value
		global_cable133.getWrappedObject().getParameter().connectT(0, add133);    // global_cable133 -> add133::Value
		global_cable134.getWrappedObject().getParameter().connectT(0, add134);    // global_cable134 -> add134::Value
		global_cable135.getWrappedObject().getParameter().connectT(0, add135);    // global_cable135 -> add135::Value
		global_cable136.getWrappedObject().getParameter().connectT(0, add136);    // global_cable136 -> add136::Value
		global_cable137.getWrappedObject().getParameter().connectT(0, add137);    // global_cable137 -> add137::Value
		global_cable138.getWrappedObject().getParameter().connectT(0, add138);    // global_cable138 -> add138::Value
		global_cable139.getWrappedObject().getParameter().connectT(0, add139);    // global_cable139 -> add139::Value
		global_cable140.getWrappedObject().getParameter().connectT(0, add140);    // global_cable140 -> add140::Value
		global_cable141.getWrappedObject().getParameter().connectT(0, add141);    // global_cable141 -> add141::Value
		pma9.getWrappedObject().getParameter().connectT(0, snex_node);            // pma9 -> snex_node::density
		peak8.getParameter().connectT(0, pma9);                                   // peak8 -> pma9::Value
		global_cable142.getWrappedObject().getParameter().connectT(0, add142);    // global_cable142 -> add142::Value
		global_cable143.getWrappedObject().getParameter().connectT(0, add143);    // global_cable143 -> add143::Value
		global_cable144.getWrappedObject().getParameter().connectT(0, add144);    // global_cable144 -> add144::Value
		global_cable145.getWrappedObject().getParameter().connectT(0, add145);    // global_cable145 -> add145::Value
		global_cable146.getWrappedObject().getParameter().connectT(0, add146);    // global_cable146 -> add146::Value
		global_cable147.getWrappedObject().getParameter().connectT(0, add147);    // global_cable147 -> add147::Value
		global_cable148.getWrappedObject().getParameter().connectT(0, add148);    // global_cable148 -> add148::Value
		global_cable149.getWrappedObject().getParameter().connectT(0, add149);    // global_cable149 -> add149::Value
		global_cable150.getWrappedObject().getParameter().connectT(0, add150);    // global_cable150 -> add150::Value
		global_cable151.getWrappedObject().getParameter().connectT(0, add151);    // global_cable151 -> add151::Value
		global_cable152.getWrappedObject().getParameter().connectT(0, add152);    // global_cable152 -> add152::Value
		global_cable153.getWrappedObject().getParameter().connectT(0, add153);    // global_cable153 -> add153::Value
		global_cable154.getWrappedObject().getParameter().connectT(0, add154);    // global_cable154 -> add154::Value
		global_cable155.getWrappedObject().getParameter().connectT(0, add155);    // global_cable155 -> add155::Value
		global_cable156.getWrappedObject().getParameter().connectT(0, add156);    // global_cable156 -> add156::Value
		global_cable157.getWrappedObject().getParameter().connectT(0, add157);    // global_cable157 -> add157::Value
		pma10.getWrappedObject().getParameter().connectT(0, snex_node);           // pma10 -> snex_node::windowShape
		peak9.getParameter().connectT(0, pma10);                                  // peak9 -> pma10::Value
		global_cable158.getWrappedObject().getParameter().connectT(0, add158);    // global_cable158 -> add158::Value
		global_cable159.getWrappedObject().getParameter().connectT(0, add159);    // global_cable159 -> add159::Value
		global_cable160.getWrappedObject().getParameter().connectT(0, add160);    // global_cable160 -> add160::Value
		global_cable161.getWrappedObject().getParameter().connectT(0, add161);    // global_cable161 -> add161::Value
		global_cable162.getWrappedObject().getParameter().connectT(0, add162);    // global_cable162 -> add162::Value
		global_cable163.getWrappedObject().getParameter().connectT(0, add163);    // global_cable163 -> add163::Value
		global_cable164.getWrappedObject().getParameter().connectT(0, add164);    // global_cable164 -> add164::Value
		global_cable165.getWrappedObject().getParameter().connectT(0, add165);    // global_cable165 -> add165::Value
		global_cable166.getWrappedObject().getParameter().connectT(0, add166);    // global_cable166 -> add166::Value
		global_cable167.getWrappedObject().getParameter().connectT(0, add167);    // global_cable167 -> add167::Value
		global_cable168.getWrappedObject().getParameter().connectT(0, add168);    // global_cable168 -> add168::Value
		global_cable169.getWrappedObject().getParameter().connectT(0, add169);    // global_cable169 -> add169::Value
		global_cable170.getWrappedObject().getParameter().connectT(0, add170);    // global_cable170 -> add170::Value
		global_cable171.getWrappedObject().getParameter().connectT(0, add171);    // global_cable171 -> add171::Value
		global_cable172.getWrappedObject().getParameter().connectT(0, add172);    // global_cable172 -> add172::Value
		global_cable173.getWrappedObject().getParameter().connectT(0, add173);    // global_cable173 -> add173::Value
		pma11.getWrappedObject().getParameter().connectT(0, snex_node);           // pma11 -> snex_node::panSpread
		peak10.getParameter().connectT(0, pma11);                                 // peak10 -> pma11::Value
		global_cable174.getWrappedObject().getParameter().connectT(0, add174);    // global_cable174 -> add174::Value
		global_cable175.getWrappedObject().getParameter().connectT(0, add175);    // global_cable175 -> add175::Value
		global_cable176.getWrappedObject().getParameter().connectT(0, add176);    // global_cable176 -> add176::Value
		global_cable177.getWrappedObject().getParameter().connectT(0, add177);    // global_cable177 -> add177::Value
		global_cable178.getWrappedObject().getParameter().connectT(0, add178);    // global_cable178 -> add178::Value
		global_cable179.getWrappedObject().getParameter().connectT(0, add179);    // global_cable179 -> add179::Value
		global_cable180.getWrappedObject().getParameter().connectT(0, add180);    // global_cable180 -> add180::Value
		global_cable181.getWrappedObject().getParameter().connectT(0, add181);    // global_cable181 -> add181::Value
		global_cable182.getWrappedObject().getParameter().connectT(0, add182);    // global_cable182 -> add182::Value
		global_cable183.getWrappedObject().getParameter().connectT(0, add183);    // global_cable183 -> add183::Value
		global_cable184.getWrappedObject().getParameter().connectT(0, add184);    // global_cable184 -> add184::Value
		global_cable185.getWrappedObject().getParameter().connectT(0, add185);    // global_cable185 -> add185::Value
		global_cable186.getWrappedObject().getParameter().connectT(0, add186);    // global_cable186 -> add186::Value
		global_cable187.getWrappedObject().getParameter().connectT(0, add187);    // global_cable187 -> add187::Value
		global_cable188.getWrappedObject().getParameter().connectT(0, add188);    // global_cable188 -> add188::Value
		global_cable189.getWrappedObject().getParameter().connectT(0, add189);    // global_cable189 -> add189::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, snex_node);    // input_toggle -> snex_node::pitchSpread
		pma12.getWrappedObject().getParameter().connectT(0, input_toggle);        // pma12 -> input_toggle::Value1
		tempo_sync1.getParameter().connectT(0, input_toggle);                     // tempo_sync1 -> input_toggle::Value2
		pma21.getWrappedObject().getParameter().connectT(0, tempo_sync1);         // pma21 -> tempo_sync1::Tempo
		peak11.getParameter().connectT(0, pma12);                                 // peak11 -> pma12::Value
		peak11.getParameter().connectT(1, pma21);                                 // peak11 -> pma21::Value
		global_cable190.getWrappedObject().getParameter().connectT(0, add190);    // global_cable190 -> add190::Value
		global_cable191.getWrappedObject().getParameter().connectT(0, add191);    // global_cable191 -> add191::Value
		global_cable192.getWrappedObject().getParameter().connectT(0, add192);    // global_cable192 -> add192::Value
		global_cable193.getWrappedObject().getParameter().connectT(0, add193);    // global_cable193 -> add193::Value
		global_cable194.getWrappedObject().getParameter().connectT(0, add194);    // global_cable194 -> add194::Value
		global_cable195.getWrappedObject().getParameter().connectT(0, add195);    // global_cable195 -> add195::Value
		global_cable196.getWrappedObject().getParameter().connectT(0, add196);    // global_cable196 -> add196::Value
		global_cable197.getWrappedObject().getParameter().connectT(0, add197);    // global_cable197 -> add197::Value
		global_cable198.getWrappedObject().getParameter().connectT(0, add198);    // global_cable198 -> add198::Value
		global_cable199.getWrappedObject().getParameter().connectT(0, add199);    // global_cable199 -> add199::Value
		global_cable200.getWrappedObject().getParameter().connectT(0, add200);    // global_cable200 -> add200::Value
		global_cable201.getWrappedObject().getParameter().connectT(0, add201);    // global_cable201 -> add201::Value
		global_cable202.getWrappedObject().getParameter().connectT(0, add202);    // global_cable202 -> add202::Value
		global_cable203.getWrappedObject().getParameter().connectT(0, add203);    // global_cable203 -> add203::Value
		global_cable204.getWrappedObject().getParameter().connectT(0, add204);    // global_cable204 -> add204::Value
		global_cable205.getWrappedObject().getParameter().connectT(0, add205);    // global_cable205 -> add205::Value
		pma2.getWrappedObject().getParameter().connectT(0, snex_node);            // pma2 -> snex_node::phaseScatter
		peak12.getParameter().connectT(0, pma2);                                  // peak12 -> pma2::Value
		global_cable206.getWrappedObject().getParameter().connectT(0, add206);    // global_cable206 -> add206::Value
		global_cable207.getWrappedObject().getParameter().connectT(0, add207);    // global_cable207 -> add207::Value
		global_cable208.getWrappedObject().getParameter().connectT(0, add208);    // global_cable208 -> add208::Value
		global_cable209.getWrappedObject().getParameter().connectT(0, add209);    // global_cable209 -> add209::Value
		global_cable210.getWrappedObject().getParameter().connectT(0, add210);    // global_cable210 -> add210::Value
		global_cable211.getWrappedObject().getParameter().connectT(0, add211);    // global_cable211 -> add211::Value
		global_cable212.getWrappedObject().getParameter().connectT(0, add212);    // global_cable212 -> add212::Value
		global_cable213.getWrappedObject().getParameter().connectT(0, add213);    // global_cable213 -> add213::Value
		global_cable214.getWrappedObject().getParameter().connectT(0, add214);    // global_cable214 -> add214::Value
		global_cable215.getWrappedObject().getParameter().connectT(0, add215);    // global_cable215 -> add215::Value
		global_cable216.getWrappedObject().getParameter().connectT(0, add216);    // global_cable216 -> add216::Value
		global_cable217.getWrappedObject().getParameter().connectT(0, add217);    // global_cable217 -> add217::Value
		global_cable218.getWrappedObject().getParameter().connectT(0, add218);    // global_cable218 -> add218::Value
		global_cable219.getWrappedObject().getParameter().connectT(0, add219);    // global_cable219 -> add219::Value
		global_cable220.getWrappedObject().getParameter().connectT(0, add220);    // global_cable220 -> add220::Value
		global_cable221.getWrappedObject().getParameter().connectT(0, add221);    // global_cable221 -> add221::Value
		pma14.getWrappedObject().getParameter().connectT(0, svf1);                // pma14 -> svf1::Frequency
		peak13.getParameter().connectT(0, pma14);                                 // peak13 -> pma14::Value
		global_cable222.getWrappedObject().getParameter().connectT(0, add222);    // global_cable222 -> add222::Value
		global_cable223.getWrappedObject().getParameter().connectT(0, add223);    // global_cable223 -> add223::Value
		global_cable224.getWrappedObject().getParameter().connectT(0, add224);    // global_cable224 -> add224::Value
		global_cable225.getWrappedObject().getParameter().connectT(0, add225);    // global_cable225 -> add225::Value
		global_cable226.getWrappedObject().getParameter().connectT(0, add226);    // global_cable226 -> add226::Value
		global_cable227.getWrappedObject().getParameter().connectT(0, add227);    // global_cable227 -> add227::Value
		global_cable228.getWrappedObject().getParameter().connectT(0, add228);    // global_cable228 -> add228::Value
		global_cable229.getWrappedObject().getParameter().connectT(0, add229);    // global_cable229 -> add229::Value
		global_cable230.getWrappedObject().getParameter().connectT(0, add230);    // global_cable230 -> add230::Value
		global_cable231.getWrappedObject().getParameter().connectT(0, add231);    // global_cable231 -> add231::Value
		global_cable232.getWrappedObject().getParameter().connectT(0, add232);    // global_cable232 -> add232::Value
		global_cable233.getWrappedObject().getParameter().connectT(0, add233);    // global_cable233 -> add233::Value
		global_cable234.getWrappedObject().getParameter().connectT(0, add234);    // global_cable234 -> add234::Value
		global_cable235.getWrappedObject().getParameter().connectT(0, add235);    // global_cable235 -> add235::Value
		global_cable236.getWrappedObject().getParameter().connectT(0, add236);    // global_cable236 -> add236::Value
		global_cable237.getWrappedObject().getParameter().connectT(0, add237);    // global_cable237 -> add237::Value
		clone_cable2.getWrappedObject().getParameter().connectT(0, res2);         // clone_cable2 -> res2::FB
		cable_table6.getWrappedObject().getParameter().connectT(0, clone_cable2); // cable_table6 -> clone_cable2::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                              // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);                             // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(1, cable_table6);                      // xfader -> cable_table6::Value
		pma15.getWrappedObject().getParameter().connectT(0, xfader);              // pma15 -> xfader::Value
		peak14.getParameter().connectT(0, pma15);                                 // peak14 -> pma15::Value
		global_cable238.getWrappedObject().getParameter().connectT(0, add238);    // global_cable238 -> add238::Value
		global_cable239.getWrappedObject().getParameter().connectT(0, add239);    // global_cable239 -> add239::Value
		global_cable240.getWrappedObject().getParameter().connectT(0, add240);    // global_cable240 -> add240::Value
		global_cable241.getWrappedObject().getParameter().connectT(0, add241);    // global_cable241 -> add241::Value
		global_cable242.getWrappedObject().getParameter().connectT(0, add242);    // global_cable242 -> add242::Value
		global_cable243.getWrappedObject().getParameter().connectT(0, add243);    // global_cable243 -> add243::Value
		global_cable244.getWrappedObject().getParameter().connectT(0, add244);    // global_cable244 -> add244::Value
		global_cable245.getWrappedObject().getParameter().connectT(0, add245);    // global_cable245 -> add245::Value
		global_cable246.getWrappedObject().getParameter().connectT(0, add246);    // global_cable246 -> add246::Value
		global_cable247.getWrappedObject().getParameter().connectT(0, add247);    // global_cable247 -> add247::Value
		global_cable248.getWrappedObject().getParameter().connectT(0, add248);    // global_cable248 -> add248::Value
		global_cable249.getWrappedObject().getParameter().connectT(0, add249);    // global_cable249 -> add249::Value
		global_cable250.getWrappedObject().getParameter().connectT(0, add250);    // global_cable250 -> add250::Value
		global_cable251.getWrappedObject().getParameter().connectT(0, add251);    // global_cable251 -> add251::Value
		global_cable252.getWrappedObject().getParameter().connectT(0, add252);    // global_cable252 -> add252::Value
		global_cable253.getWrappedObject().getParameter().connectT(0, add253);    // global_cable253 -> add253::Value
		converter7.getWrappedObject().getParameter().connectT(0, jdelay_thiran3); // converter7 -> jdelay_thiran3::DelayTime
		converter7.getWrappedObject().getParameter().connectT(1, fix_delay);      // converter7 -> fix_delay::DelayTime
		pma_unscaled3.getWrappedObject().getParameter().connectT(0, converter7);  // pma_unscaled3 -> converter7::Value
		clone_cable.getWrappedObject().getParameter().connectT(0, res2);          // clone_cable -> res2::DELAY
		pma16.getWrappedObject().getParameter().connectT(0, pma_unscaled3);       // pma16 -> pma_unscaled3::Multiply
		pma16.getWrappedObject().getParameter().connectT(1, clone_cable);         // pma16 -> clone_cable::Value
		peak15.getParameter().connectT(0, pma16);                                 // peak15 -> pma16::Value
		global_cable270.getWrappedObject().getParameter().connectT(0, add270);    // global_cable270 -> add270::Value
		global_cable271.getWrappedObject().getParameter().connectT(0, add271);    // global_cable271 -> add271::Value
		global_cable272.getWrappedObject().getParameter().connectT(0, add272);    // global_cable272 -> add272::Value
		global_cable273.getWrappedObject().getParameter().connectT(0, add273);    // global_cable273 -> add273::Value
		global_cable274.getWrappedObject().getParameter().connectT(0, add274);    // global_cable274 -> add274::Value
		global_cable275.getWrappedObject().getParameter().connectT(0, add275);    // global_cable275 -> add275::Value
		global_cable276.getWrappedObject().getParameter().connectT(0, add276);    // global_cable276 -> add276::Value
		global_cable277.getWrappedObject().getParameter().connectT(0, add277);    // global_cable277 -> add277::Value
		global_cable278.getWrappedObject().getParameter().connectT(0, add278);    // global_cable278 -> add278::Value
		global_cable279.getWrappedObject().getParameter().connectT(0, add279);    // global_cable279 -> add279::Value
		global_cable280.getWrappedObject().getParameter().connectT(0, add280);    // global_cable280 -> add280::Value
		global_cable281.getWrappedObject().getParameter().connectT(0, add281);    // global_cable281 -> add281::Value
		global_cable282.getWrappedObject().getParameter().connectT(0, add282);    // global_cable282 -> add282::Value
		global_cable283.getWrappedObject().getParameter().connectT(0, add283);    // global_cable283 -> add283::Value
		global_cable284.getWrappedObject().getParameter().connectT(0, add284);    // global_cable284 -> add284::Value
		global_cable285.getWrappedObject().getParameter().connectT(0, add285);    // global_cable285 -> add285::Value
		clone_cable1.getWrappedObject().getParameter().connectT(0, res2);         // clone_cable1 -> res2::lp
		pma18.getWrappedObject().getParameter().connectT(0, one_pole5);           // pma18 -> one_pole5::Frequency
		pma18.getWrappedObject().getParameter().connectT(1, clone_cable1);        // pma18 -> clone_cable1::Value
		peak17.getParameter().connectT(0, pma18);                                 // peak17 -> pma18::Value
		global_cable254.getWrappedObject().getParameter().connectT(0, add254);    // global_cable254 -> add254::Value
		global_cable255.getWrappedObject().getParameter().connectT(0, add255);    // global_cable255 -> add255::Value
		global_cable256.getWrappedObject().getParameter().connectT(0, add256);    // global_cable256 -> add256::Value
		global_cable257.getWrappedObject().getParameter().connectT(0, add257);    // global_cable257 -> add257::Value
		global_cable258.getWrappedObject().getParameter().connectT(0, add258);    // global_cable258 -> add258::Value
		global_cable259.getWrappedObject().getParameter().connectT(0, add259);    // global_cable259 -> add259::Value
		global_cable260.getWrappedObject().getParameter().connectT(0, add260);    // global_cable260 -> add260::Value
		global_cable261.getWrappedObject().getParameter().connectT(0, add261);    // global_cable261 -> add261::Value
		global_cable262.getWrappedObject().getParameter().connectT(0, add262);    // global_cable262 -> add262::Value
		global_cable263.getWrappedObject().getParameter().connectT(0, add263);    // global_cable263 -> add263::Value
		global_cable264.getWrappedObject().getParameter().connectT(0, add264);    // global_cable264 -> add264::Value
		global_cable265.getWrappedObject().getParameter().connectT(0, add265);    // global_cable265 -> add265::Value
		global_cable266.getWrappedObject().getParameter().connectT(0, add266);    // global_cable266 -> add266::Value
		global_cable267.getWrappedObject().getParameter().connectT(0, add267);    // global_cable267 -> add267::Value
		global_cable268.getWrappedObject().getParameter().connectT(0, add268);    // global_cable268 -> add268::Value
		global_cable269.getWrappedObject().getParameter().connectT(0, add269);    // global_cable269 -> add269::Value
		pma17.getWrappedObject().getParameter().connectT(0, svf2);                // pma17 -> svf2::Frequency
		peak16.getParameter().connectT(0, pma17);                                 // peak16 -> pma17::Value
		global_cable286.getWrappedObject().getParameter().connectT(0, add286);    // global_cable286 -> add286::Value
		global_cable287.getWrappedObject().getParameter().connectT(0, add287);    // global_cable287 -> add287::Value
		global_cable288.getWrappedObject().getParameter().connectT(0, add288);    // global_cable288 -> add288::Value
		global_cable289.getWrappedObject().getParameter().connectT(0, add289);    // global_cable289 -> add289::Value
		global_cable290.getWrappedObject().getParameter().connectT(0, add290);    // global_cable290 -> add290::Value
		global_cable291.getWrappedObject().getParameter().connectT(0, add291);    // global_cable291 -> add291::Value
		global_cable292.getWrappedObject().getParameter().connectT(0, add292);    // global_cable292 -> add292::Value
		global_cable293.getWrappedObject().getParameter().connectT(0, add293);    // global_cable293 -> add293::Value
		global_cable294.getWrappedObject().getParameter().connectT(0, add294);    // global_cable294 -> add294::Value
		global_cable295.getWrappedObject().getParameter().connectT(0, add295);    // global_cable295 -> add295::Value
		global_cable296.getWrappedObject().getParameter().connectT(0, add296);    // global_cable296 -> add296::Value
		global_cable297.getWrappedObject().getParameter().connectT(0, add297);    // global_cable297 -> add297::Value
		global_cable298.getWrappedObject().getParameter().connectT(0, add298);    // global_cable298 -> add298::Value
		global_cable299.getWrappedObject().getParameter().connectT(0, add299);    // global_cable299 -> add299::Value
		global_cable300.getWrappedObject().getParameter().connectT(0, add300);    // global_cable300 -> add300::Value
		global_cable301.getWrappedObject().getParameter().connectT(0, add301);    // global_cable301 -> add301::Value
		pma19.getWrappedObject().getParameter().connectT(0, gain3);               // pma19 -> gain3::Gain
		peak24.getParameter().connectT(0, pma19);                                 // peak24 -> pma19::Value
		global_cable302.getWrappedObject().getParameter().connectT(0, add302);    // global_cable302 -> add302::Value
		global_cable303.getWrappedObject().getParameter().connectT(0, add303);    // global_cable303 -> add303::Value
		global_cable304.getWrappedObject().getParameter().connectT(0, add304);    // global_cable304 -> add304::Value
		global_cable305.getWrappedObject().getParameter().connectT(0, add305);    // global_cable305 -> add305::Value
		global_cable306.getWrappedObject().getParameter().connectT(0, add306);    // global_cable306 -> add306::Value
		global_cable307.getWrappedObject().getParameter().connectT(0, add307);    // global_cable307 -> add307::Value
		global_cable308.getWrappedObject().getParameter().connectT(0, add308);    // global_cable308 -> add308::Value
		global_cable309.getWrappedObject().getParameter().connectT(0, add309);    // global_cable309 -> add309::Value
		global_cable310.getWrappedObject().getParameter().connectT(0, add310);    // global_cable310 -> add310::Value
		global_cable311.getWrappedObject().getParameter().connectT(0, add311);    // global_cable311 -> add311::Value
		global_cable312.getWrappedObject().getParameter().connectT(0, add312);    // global_cable312 -> add312::Value
		global_cable313.getWrappedObject().getParameter().connectT(0, add313);    // global_cable313 -> add313::Value
		global_cable314.getWrappedObject().getParameter().connectT(0, add314);    // global_cable314 -> add314::Value
		global_cable315.getWrappedObject().getParameter().connectT(0, add315);    // global_cable315 -> add315::Value
		global_cable316.getWrappedObject().getParameter().connectT(0, add316);    // global_cable316 -> add316::Value
		global_cable317.getWrappedObject().getParameter().connectT(0, add317);    // global_cable317 -> add317::Value
		pma20.getWrappedObject().getParameter().connectT(0, jpanner);             // pma20 -> jpanner::Pan
		peak25.getParameter().connectT(0, pma20);                                 // peak25 -> pma20::Value
		global_cable110.getWrappedObject().getParameter().connectT(0, add110);    // global_cable110 -> add110::Value
		global_cable111.getWrappedObject().getParameter().connectT(0, add111);    // global_cable111 -> add111::Value
		global_cable112.getWrappedObject().getParameter().connectT(0, add112);    // global_cable112 -> add112::Value
		global_cable113.getWrappedObject().getParameter().connectT(0, add113);    // global_cable113 -> add113::Value
		global_cable114.getWrappedObject().getParameter().connectT(0, add114);    // global_cable114 -> add114::Value
		global_cable115.getWrappedObject().getParameter().connectT(0, add115);    // global_cable115 -> add115::Value
		global_cable116.getWrappedObject().getParameter().connectT(0, add116);    // global_cable116 -> add116::Value
		global_cable117.getWrappedObject().getParameter().connectT(0, add117);    // global_cable117 -> add117::Value
		global_cable118.getWrappedObject().getParameter().connectT(0, add118);    // global_cable118 -> add118::Value
		global_cable119.getWrappedObject().getParameter().connectT(0, add119);    // global_cable119 -> add119::Value
		global_cable120.getWrappedObject().getParameter().connectT(0, add120);    // global_cable120 -> add120::Value
		global_cable121.getWrappedObject().getParameter().connectT(0, add121);    // global_cable121 -> add121::Value
		global_cable122.getWrappedObject().getParameter().connectT(0, add122);    // global_cable122 -> add122::Value
		global_cable123.getWrappedObject().getParameter().connectT(0, add123);    // global_cable123 -> add123::Value
		global_cable124.getWrappedObject().getParameter().connectT(0, add124);    // global_cable124 -> add124::Value
		global_cable125.getWrappedObject().getParameter().connectT(0, add125);    // global_cable125 -> add125::Value
		tempo_sync.getParameter().connectT(0, snex_node);                         // tempo_sync -> snex_node::grainMs
		pma7.getWrappedObject().getParameter().connectT(0, tempo_sync);           // pma7 -> tempo_sync::Tempo
		pma8.getWrappedObject().getParameter().connectT(0, tempo_sync);           // pma8 -> tempo_sync::UnsyncedTime
		peak7.getParameter().connectT(0, pma7);                                   // peak7 -> pma7::Value
		peak7.getParameter().connectT(1, pma8);                                   // peak7 -> pma8::Value
		cable_table4.getWrappedObject().getParameter().connectT(0, input_toggle); // cable_table4 -> input_toggle::Input
		peak1.getParameter().connectT(0, global_cable15);                         // peak1 -> global_cable15::Value
		peak19.getParameter().connectT(0, global_cable18);                        // peak19 -> global_cable18::Value
		peak18.getParameter().connectT(0, global_cable17);                        // peak18 -> global_cable17::Value
		peak2.getParameter().connectT(0, global_cable16);                         // peak2 -> global_cable16::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain4);                           // xfader1 -> gain4::Gain
		xfader1_p.getParameterT(1).connectT(0, gain5);                           // xfader1 -> gain5::Gain
		converter6.getWrappedObject().getParameter().connectT(0, pma_unscaled3); // converter6 -> pma_unscaled3::Value
		midi3.getParameter().connectT(0, converter6);                            // midi3 -> converter6::Value
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(0).connectT(0, gain6);     // xfader2 -> gain6::Gain
		xfader2_p.getParameterT(1).connectT(0, gain7);     // xfader2 -> gain7::Gain
		peak20.getParameter().connectT(0, global_cable19); // peak20 -> global_cable19::Value
		peak21.getParameter().connectT(0, global_cable20); // peak21 -> global_cable20::Value
		peak22.getParameter().connectT(0, global_cable21); // peak22 -> global_cable21::Value
		peak23.getParameter().connectT(0, global_cable22); // peak23 -> global_cable22::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send3.connect(receive3);
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch::Index is automated
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add1::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add14::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add9::Value is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add3::Value is automated
		
		global_cable45.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add45::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // cable_table::Value is automated
		
		; // branch3::Index is automated
		
		global_cable46.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add46::Value is automated
		
		global_cable47.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add47::Value is automated
		
		global_cable48.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add48::Value is automated
		
		global_cable49.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add49::Value is automated
		
		global_cable50.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add50::Value is automated
		
		global_cable51.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add51::Value is automated
		
		global_cable52.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add52::Value is automated
		
		global_cable53.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add53::Value is automated
		
		global_cable54.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add54::Value is automated
		
		global_cable55.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add55::Value is automated
		
		global_cable56.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add56::Value is automated
		
		global_cable57.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add57::Value is automated
		
		global_cable58.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add58::Value is automated
		
		global_cable59.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add59::Value is automated
		
		global_cable60.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add60::Value is automated
		
		global_cable61.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add61::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		; // cable_table1::Value is automated
		
		; // branch4::Index is automated
		
		global_cable62.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add62::Value is automated
		
		global_cable63.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add63::Value is automated
		
		global_cable64.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add64::Value is automated
		
		global_cable65.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add65::Value is automated
		
		global_cable66.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add66::Value is automated
		
		global_cable67.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add67::Value is automated
		
		global_cable68.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add68::Value is automated
		
		global_cable69.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add69::Value is automated
		
		global_cable70.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add70::Value is automated
		
		global_cable71.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add71::Value is automated
		
		global_cable72.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add72::Value is automated
		
		global_cable73.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add73::Value is automated
		
		global_cable74.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add74::Value is automated
		
		global_cable75.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add75::Value is automated
		
		global_cable76.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add76::Value is automated
		
		global_cable77.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add77::Value is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		; // pma4::Value is automated
		; // pma4::Multiply is automated
		; // pma4::Add is automated
		
		; // cable_table2::Value is automated
		
		; // branch5::Index is automated
		
		global_cable78.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add78::Value is automated
		
		global_cable79.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add79::Value is automated
		
		global_cable80.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add80::Value is automated
		
		global_cable81.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add81::Value is automated
		
		global_cable82.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add82::Value is automated
		
		global_cable83.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add83::Value is automated
		
		global_cable84.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add84::Value is automated
		
		global_cable85.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add85::Value is automated
		
		global_cable86.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add86::Value is automated
		
		global_cable87.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add87::Value is automated
		
		global_cable88.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add88::Value is automated
		
		global_cable89.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add89::Value is automated
		
		global_cable90.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add90::Value is automated
		
		global_cable91.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add91::Value is automated
		
		global_cable92.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add92::Value is automated
		
		global_cable93.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add93::Value is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // pma5::Value is automated
		; // pma5::Multiply is automated
		; // pma5::Add is automated
		
		; // cable_table3::Value is automated
		
		; // branch6::Index is automated
		
		global_cable94.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add94::Value is automated
		
		global_cable95.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add95::Value is automated
		
		global_cable96.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add96::Value is automated
		
		global_cable97.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add97::Value is automated
		
		global_cable98.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add98::Value is automated
		
		global_cable99.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add99::Value is automated
		
		global_cable100.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add100::Value is automated
		
		global_cable101.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add101::Value is automated
		
		global_cable102.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add102::Value is automated
		
		global_cable103.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add103::Value is automated
		
		global_cable104.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add104::Value is automated
		
		global_cable105.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add105::Value is automated
		
		global_cable106.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add106::Value is automated
		
		global_cable107.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add107::Value is automated
		
		global_cable108.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add108::Value is automated
		
		global_cable109.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add109::Value is automated
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		; // pma6::Value is automated
		; // pma6::Multiply is automated
		; // pma6::Add is automated
		
		; // branch8::Index is automated
		
		global_cable126.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add126::Value is automated
		
		global_cable127.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add127::Value is automated
		
		global_cable128.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add128::Value is automated
		
		global_cable129.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add129::Value is automated
		
		global_cable130.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add130::Value is automated
		
		global_cable131.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add131::Value is automated
		
		global_cable132.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add132::Value is automated
		
		global_cable133.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add133::Value is automated
		
		global_cable134.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add134::Value is automated
		
		global_cable135.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add135::Value is automated
		
		global_cable136.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add136::Value is automated
		
		global_cable137.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add137::Value is automated
		
		global_cable138.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add138::Value is automated
		
		global_cable139.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add139::Value is automated
		
		global_cable140.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add140::Value is automated
		
		global_cable141.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add141::Value is automated
		
		clear8.setParameterT(0, 0.); // math::clear::Value
		
		; // pma9::Value is automated
		; // pma9::Multiply is automated
		; // pma9::Add is automated
		
		; // branch9::Index is automated
		
		global_cable142.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add142::Value is automated
		
		global_cable143.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add143::Value is automated
		
		global_cable144.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add144::Value is automated
		
		global_cable145.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add145::Value is automated
		
		global_cable146.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add146::Value is automated
		
		global_cable147.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add147::Value is automated
		
		global_cable148.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add148::Value is automated
		
		global_cable149.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add149::Value is automated
		
		global_cable150.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add150::Value is automated
		
		global_cable151.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add151::Value is automated
		
		global_cable152.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add152::Value is automated
		
		global_cable153.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add153::Value is automated
		
		global_cable154.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add154::Value is automated
		
		global_cable155.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add155::Value is automated
		
		global_cable156.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add156::Value is automated
		
		global_cable157.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add157::Value is automated
		
		clear9.setParameterT(0, 0.); // math::clear::Value
		
		; // pma10::Value is automated
		; // pma10::Multiply is automated
		; // pma10::Add is automated
		
		; // branch10::Index is automated
		
		global_cable158.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add158::Value is automated
		
		global_cable159.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add159::Value is automated
		
		global_cable160.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add160::Value is automated
		
		global_cable161.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add161::Value is automated
		
		global_cable162.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add162::Value is automated
		
		global_cable163.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add163::Value is automated
		
		global_cable164.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add164::Value is automated
		
		global_cable165.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add165::Value is automated
		
		global_cable166.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add166::Value is automated
		
		global_cable167.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add167::Value is automated
		
		global_cable168.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add168::Value is automated
		
		global_cable169.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add169::Value is automated
		
		global_cable170.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add170::Value is automated
		
		global_cable171.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add171::Value is automated
		
		global_cable172.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add172::Value is automated
		
		global_cable173.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add173::Value is automated
		
		clear10.setParameterT(0, 0.); // math::clear::Value
		
		; // pma11::Value is automated
		; // pma11::Multiply is automated
		; // pma11::Add is automated
		
		; // branch11::Index is automated
		
		global_cable174.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add174::Value is automated
		
		global_cable175.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add175::Value is automated
		
		global_cable176.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add176::Value is automated
		
		global_cable177.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add177::Value is automated
		
		global_cable178.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add178::Value is automated
		
		global_cable179.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add179::Value is automated
		
		global_cable180.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add180::Value is automated
		
		global_cable181.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add181::Value is automated
		
		global_cable182.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add182::Value is automated
		
		global_cable183.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add183::Value is automated
		
		global_cable184.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add184::Value is automated
		
		global_cable185.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add185::Value is automated
		
		global_cable186.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add186::Value is automated
		
		global_cable187.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add187::Value is automated
		
		global_cable188.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add188::Value is automated
		
		global_cable189.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add189::Value is automated
		
		clear11.setParameterT(0, 0.); // math::clear::Value
		
		; // pma12::Value is automated
		; // pma12::Multiply is automated
		; // pma12::Add is automated
		
		; // pma21::Value is automated
		; // pma21::Multiply is automated
		; // pma21::Add is automated
		
		; // branch12::Index is automated
		
		global_cable190.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add190::Value is automated
		
		global_cable191.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add191::Value is automated
		
		global_cable192.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add192::Value is automated
		
		global_cable193.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add193::Value is automated
		
		global_cable194.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add194::Value is automated
		
		global_cable195.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add195::Value is automated
		
		global_cable196.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add196::Value is automated
		
		global_cable197.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add197::Value is automated
		
		global_cable198.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add198::Value is automated
		
		global_cable199.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add199::Value is automated
		
		global_cable200.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add200::Value is automated
		
		global_cable201.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add201::Value is automated
		
		global_cable202.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add202::Value is automated
		
		global_cable203.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add203::Value is automated
		
		global_cable204.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add204::Value is automated
		
		global_cable205.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add205::Value is automated
		
		clear12.setParameterT(0, 0.); // math::clear::Value
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		; // branch13::Index is automated
		
		global_cable206.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add206::Value is automated
		
		global_cable207.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add207::Value is automated
		
		global_cable208.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add208::Value is automated
		
		global_cable209.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add209::Value is automated
		
		global_cable210.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add210::Value is automated
		
		global_cable211.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add211::Value is automated
		
		global_cable212.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add212::Value is automated
		
		global_cable213.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add213::Value is automated
		
		global_cable214.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add214::Value is automated
		
		global_cable215.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add215::Value is automated
		
		global_cable216.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add216::Value is automated
		
		global_cable217.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add217::Value is automated
		
		global_cable218.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add218::Value is automated
		
		global_cable219.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add219::Value is automated
		
		global_cable220.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add220::Value is automated
		
		global_cable221.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add221::Value is automated
		
		clear13.setParameterT(0, 0.); // math::clear::Value
		
		; // pma14::Value is automated
		; // pma14::Multiply is automated
		; // pma14::Add is automated
		
		; // branch14::Index is automated
		
		global_cable222.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add222::Value is automated
		
		global_cable223.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add223::Value is automated
		
		global_cable224.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add224::Value is automated
		
		global_cable225.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add225::Value is automated
		
		global_cable226.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add226::Value is automated
		
		global_cable227.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add227::Value is automated
		
		global_cable228.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add228::Value is automated
		
		global_cable229.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add229::Value is automated
		
		global_cable230.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add230::Value is automated
		
		global_cable231.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add231::Value is automated
		
		global_cable232.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add232::Value is automated
		
		global_cable233.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add233::Value is automated
		
		global_cable234.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add234::Value is automated
		
		global_cable235.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add235::Value is automated
		
		global_cable236.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add236::Value is automated
		
		global_cable237.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add237::Value is automated
		
		clear14.setParameterT(0, 0.); // math::clear::Value
		
		; // pma15::Value is automated
		; // pma15::Multiply is automated
		; // pma15::Add is automated
		
		; // branch15::Index is automated
		
		global_cable238.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add238::Value is automated
		
		global_cable239.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add239::Value is automated
		
		global_cable240.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add240::Value is automated
		
		global_cable241.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add241::Value is automated
		
		global_cable242.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add242::Value is automated
		
		global_cable243.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add243::Value is automated
		
		global_cable244.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add244::Value is automated
		
		global_cable245.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add245::Value is automated
		
		global_cable246.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add246::Value is automated
		
		global_cable247.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add247::Value is automated
		
		global_cable248.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add248::Value is automated
		
		global_cable249.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add249::Value is automated
		
		global_cable250.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add250::Value is automated
		
		global_cable251.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add251::Value is automated
		
		global_cable252.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add252::Value is automated
		
		global_cable253.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add253::Value is automated
		
		clear15.setParameterT(0, 0.); // math::clear::Value
		
		; // pma16::Value is automated
		; // pma16::Multiply is automated
		; // pma16::Add is automated
		
		; // branch17::Index is automated
		
		global_cable270.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add270::Value is automated
		
		global_cable271.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add271::Value is automated
		
		global_cable272.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add272::Value is automated
		
		global_cable273.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add273::Value is automated
		
		global_cable274.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add274::Value is automated
		
		global_cable275.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add275::Value is automated
		
		global_cable276.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add276::Value is automated
		
		global_cable277.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add277::Value is automated
		
		global_cable278.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add278::Value is automated
		
		global_cable279.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add279::Value is automated
		
		global_cable280.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add280::Value is automated
		
		global_cable281.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add281::Value is automated
		
		global_cable282.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add282::Value is automated
		
		global_cable283.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add283::Value is automated
		
		global_cable284.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add284::Value is automated
		
		global_cable285.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add285::Value is automated
		
		clear17.setParameterT(0, 0.); // math::clear::Value
		
		; // pma18::Value is automated
		; // pma18::Multiply is automated
		; // pma18::Add is automated
		
		; // branch16::Index is automated
		
		global_cable254.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add254::Value is automated
		
		global_cable255.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add255::Value is automated
		
		global_cable256.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add256::Value is automated
		
		global_cable257.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add257::Value is automated
		
		global_cable258.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add258::Value is automated
		
		global_cable259.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add259::Value is automated
		
		global_cable260.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add260::Value is automated
		
		global_cable261.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add261::Value is automated
		
		global_cable262.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add262::Value is automated
		
		global_cable263.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add263::Value is automated
		
		global_cable264.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add264::Value is automated
		
		global_cable265.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add265::Value is automated
		
		global_cable266.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add266::Value is automated
		
		global_cable267.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add267::Value is automated
		
		global_cable268.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add268::Value is automated
		
		global_cable269.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add269::Value is automated
		
		clear16.setParameterT(0, 0.); // math::clear::Value
		
		; // pma17::Value is automated
		; // pma17::Multiply is automated
		; // pma17::Add is automated
		
		; // branch19::Index is automated
		
		global_cable286.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add286::Value is automated
		
		global_cable287.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add287::Value is automated
		
		global_cable288.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add288::Value is automated
		
		global_cable289.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add289::Value is automated
		
		global_cable290.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add290::Value is automated
		
		global_cable291.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add291::Value is automated
		
		global_cable292.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add292::Value is automated
		
		global_cable293.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add293::Value is automated
		
		global_cable294.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add294::Value is automated
		
		global_cable295.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add295::Value is automated
		
		global_cable296.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add296::Value is automated
		
		global_cable297.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add297::Value is automated
		
		global_cable298.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add298::Value is automated
		
		global_cable299.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add299::Value is automated
		
		global_cable300.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add300::Value is automated
		
		global_cable301.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add301::Value is automated
		
		clear18.setParameterT(0, 0.); // math::clear::Value
		
		; // pma19::Value is automated
		; // pma19::Multiply is automated
		; // pma19::Add is automated
		
		; // branch20::Index is automated
		
		global_cable302.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add302::Value is automated
		
		global_cable303.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add303::Value is automated
		
		global_cable304.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add304::Value is automated
		
		global_cable305.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add305::Value is automated
		
		global_cable306.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add306::Value is automated
		
		global_cable307.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add307::Value is automated
		
		global_cable308.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add308::Value is automated
		
		global_cable309.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add309::Value is automated
		
		global_cable310.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add310::Value is automated
		
		global_cable311.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add311::Value is automated
		
		global_cable312.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add312::Value is automated
		
		global_cable313.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add313::Value is automated
		
		global_cable314.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add314::Value is automated
		
		global_cable315.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add315::Value is automated
		
		global_cable316.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add316::Value is automated
		
		global_cable317.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add317::Value is automated
		
		clear19.setParameterT(0, 0.); // math::clear::Value
		
		; // pma20::Value is automated
		; // pma20::Multiply is automated
		; // pma20::Add is automated
		
		; // branch7::Index is automated
		
		global_cable110.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add110::Value is automated
		
		global_cable111.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add111::Value is automated
		
		global_cable112.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add112::Value is automated
		
		global_cable113.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add113::Value is automated
		
		global_cable114.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add114::Value is automated
		
		global_cable115.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add115::Value is automated
		
		global_cable116.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add116::Value is automated
		
		global_cable117.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add117::Value is automated
		
		global_cable118.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add118::Value is automated
		
		global_cable119.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add119::Value is automated
		
		global_cable120.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add120::Value is automated
		
		global_cable121.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add121::Value is automated
		
		global_cable122.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add122::Value is automated
		
		global_cable123.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add123::Value is automated
		
		global_cable124.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add124::Value is automated
		
		global_cable125.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add125::Value is automated
		
		clear7.setParameterT(0, 0.); // math::clear::Value
		
		; // pma8::Value is automated
		; // pma8::Multiply is automated
		; // pma8::Add is automated
		
		; // pma7::Value is automated
		; // pma7::Multiply is automated
		; // pma7::Add is automated
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		;                                   // tempo_sync1::Tempo is automated
		;                                   // tempo_sync1::Multiplier is automated
		tempo_sync1.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // cable_table4::Value is automated
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		;                                       // snex_node::pitch is automated
		;                                       // snex_node::scrub is automated
		;                                       // snex_node::grainMs is automated
		;                                       // snex_node::density is automated
		;                                       // snex_node::windowShape is automated
		;                                       // snex_node::panSpread is automated
		;                                       // snex_node::pitchMode is automated
		;                                       // snex_node::pitchSpread is automated
		;                                       // snex_node::maxGrains is automated
		;                                       // snex_node::scrubMode is automated
		;                                       // snex_node::scrubBlend is automated
		;                                       // snex_node::reverse is automated
		;                                       // snex_node::phaseScatter is automated
		;                                       // snex_node::scrubB is automated
		;                                       // snex_node::scrubC is automated
		;                                       // snex_node::scrubD is automated
		snex_node.setParameterT(16, 0.0299482); // core::snex_node::Parameter
		
		; // branch2::Index is automated
		
		; // global_cable15::Value is automated
		
		; // global_cable18::Value is automated
		
		; // global_cable17::Value is automated
		
		; // global_cable16::Value is automated
		
		; // xfader1::Value is automated
		
		;                            // gain4::Gain is automated
		gain4.setParameterT(1, 20.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                            // svf1::Mode is automated
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // gain5::Gain is automated
		gain5.setParameterT(1, 20.); // core::gain::Smoothing
		gain5.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader::Value is automated
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 10.3);  // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // branch1::Index is automated
		
		; // converter6::Value is automated
		
		; // converter7::Value is automated
		
		;                                   // pma_unscaled3::Value is automated
		;                                   // pma_unscaled3::Multiply is automated
		pma_unscaled3.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // receive3::Feedback is automated
		
		;                                 // one_pole5::Frequency is automated
		one_pole5.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole5.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole5.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole5.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole5.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                 // fix_delay::DelayTime is automated
		fix_delay.setParameterT(1, 621.); // core::fix_delay::FadeTime
		
		jdelay_thiran3.setParameterT(0, 30.); // jdsp::jdelay_thiran::Limit
		;                                     // jdelay_thiran3::DelayTime is automated
		
		one_pole3.setParameterT(0, 50.);  // filters::one_pole::Frequency
		one_pole3.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole3.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole3.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole3.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole3.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                 // clone_cable::NumClones is deactivated
		;                                 // clone_cable::Value is automated
		clone_cable.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable1::NumClones is deactivated
		;                                  // clone_cable1::Value is automated
		clone_cable1.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // cable_table6::Value is automated
		
		;                                  // clone_cable2::NumClones is deactivated
		;                                  // clone_cable2::Value is automated
		clone_cable2.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone.setParameterT(0, 8.); // container::clone::NumClones
		clone.setParameterT(1, 2.); // container::clone::SplitSignal
		
		;                           // res2::FB is automated
		;                           // res2::DELAY is automated
		res2.setParameterT(2, -1.); // project::res2::HASS
		;                           // res2::lp is automated
		
		gain2.setParameterT(0, -17.); // core::gain::Gain
		gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		gain2.setParameterT(2, 0.);   // core::gain::ResetValue
		
		one_pole2.setParameterT(0, 50.);  // filters::one_pole::Frequency
		one_pole2.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole2.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole2.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole2.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole2.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 11.6);  // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader2::Value is automated
		
		;                            // gain6::Gain is automated
		gain6.setParameterT(1, 20.); // core::gain::Smoothing
		gain6.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // svf2::Frequency is automated
		;                            // svf2::Q is automated
		svf2.setParameterT(2, 0.);   // filters::svf::Gain
		svf2.setParameterT(3, 0.01); // filters::svf::Smoothing
		;                            // svf2::Mode is automated
		svf2.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // gain7::Gain is automated
		gain7.setParameterT(1, 20.); // core::gain::Smoothing
		gain7.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 4.4);   // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		; // branch18::Index is automated
		
		; // global_cable19::Value is automated
		
		; // global_cable20::Value is automated
		
		; // global_cable21::Value is automated
		
		; // global_cable22::Value is automated
		
		this->setParameterT(0, 3.);
		this->setParameterT(1, 32.);
		this->setParameterT(2, 4.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.36);
		this->setParameterT(6, -0.54);
		this->setParameterT(7, 3.);
		this->setParameterT(8, 0.77);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 13.);
		this->setParameterT(11, 0.33);
		this->setParameterT(12, 0.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 0.52);
		this->setParameterT(15, 0.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 1.78814e-07);
		this->setParameterT(18, -0.01);
		this->setParameterT(19, 13.);
		this->setParameterT(20, 0.);
		this->setParameterT(21, 0.03);
		this->setParameterT(22, 3.);
		this->setParameterT(23, 1.);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 0.27);
		this->setParameterT(26, 0.);
		this->setParameterT(27, 14.);
		this->setParameterT(28, 0.58);
		this->setParameterT(29, 0.);
		this->setParameterT(30, 7.);
		this->setParameterT(31, 0.);
		this->setParameterT(32, -0.0416016);
		this->setParameterT(33, 6.);
		this->setParameterT(34, 464.);
		this->setParameterT(35, 0.);
		this->setParameterT(36, 2.);
		this->setParameterT(37, 10.);
		this->setParameterT(38, 1.);
		this->setParameterT(39, 1.);
		this->setParameterT(40, 0.);
		this->setParameterT(41, 1.);
		this->setParameterT(42, 0.32);
		this->setParameterT(43, 1.);
		this->setParameterT(44, 1.);
		this->setParameterT(45, 0.7);
		this->setParameterT(46, 0.);
		this->setParameterT(47, 0.);
		this->setParameterT(48, 13.);
		this->setParameterT(49, 0.21);
		this->setParameterT(50, 0.);
		this->setParameterT(51, 3.);
		this->setParameterT(52, 1.);
		this->setParameterT(53, 0.);
		this->setParameterT(54, 13.);
		this->setParameterT(55, 0.19);
		this->setParameterT(56, 0.17);
		this->setParameterT(57, 4.);
		this->setParameterT(58, 0.63);
		this->setParameterT(59, 3.);
		this->setParameterT(60, 0.);
		this->setParameterT(61, 0.);
		this->setParameterT(62, 0.);
		this->setParameterT(63, 1.);
		this->setParameterT(64, 1.);
		this->setParameterT(65, 0.);
		this->setParameterT(66, 0.);
		this->setParameterT(67, 4.);
		this->setParameterT(68, 1.);
		this->setParameterT(69, 0.);
		this->setParameterT(70, 0.921221);
		this->setParameterT(71, 10.);
		this->setParameterT(72, 1.);
		this->setParameterT(73, 3.);
		this->setParameterT(74, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable2_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable1_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable14_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable13_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable12_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable9_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable8_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable45_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable46_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable47_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable48_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable49_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable50_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable51_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable52_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable53_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable54_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable55_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable56_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable57_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable58_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable59_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable60_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable61_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable62_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable63_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable64_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable65_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable66_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable67_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable68_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable69_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable70_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable71_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable72_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable73_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable74_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable75_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable76_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable77_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable78_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable79_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable80_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable81_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable82_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable83_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable84_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable85_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable86_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable87_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable88_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable89_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable90_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable91_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable92_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable93_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable94_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable95_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable96_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable97_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable98_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable99_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable100_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable101_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable102_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable103_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable104_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable105_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable106_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable107_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable108_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable109_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable126_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable127_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable128_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable129_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable130_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable131_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable132_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable133_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable134_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable135_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable136_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable137_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable138_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable139_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable140_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable141_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable142_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable143_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable144_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable145_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable146_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable147_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable148_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable149_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable150_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable151_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable152_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable153_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable154_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable155_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable156_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable157_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable158_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable159_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable160_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable161_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable162_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable163_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable164_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable165_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable166_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable167_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable168_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable169_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable170_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable171_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable172_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable173_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable174_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable175_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable176_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable177_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable178_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable179_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable180_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable181_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable182_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable183_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable184_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable185_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable186_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable187_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable188_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable189_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable190_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable191_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable192_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable193_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable194_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable195_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable196_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable197_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable198_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);   // sn_impl::global_cable199_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable200_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable201_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable202_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable203_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable204_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable205_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable206_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable207_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable208_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable209_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable210_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable211_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable212_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable213_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable214_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable215_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable216_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable217_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable218_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable219_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable220_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable221_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable222_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable223_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable224_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable225_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable226_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable227_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable228_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable229_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable230_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable231_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable232_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable233_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable234_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable235_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable236_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable237_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable238_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable239_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable240_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable241_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable242_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable243_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable244_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable245_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable246_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable247_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable248_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable249_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable250_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable251_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable252_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable253_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable270_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable271_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable272_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable273_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable274_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable275_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable276_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable277_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable278_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable279_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable280_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable281_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable282_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable283_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable284_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable285_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable254_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable255_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable256_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable257_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable258_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable259_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable260_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable261_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable262_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable263_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable264_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable265_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable266_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable267_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable268_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable269_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable286_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable287_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable288_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable289_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable290_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable291_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable292_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable293_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable294_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable295_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable296_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable297_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable298_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable299_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable300_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable301_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable302_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable303_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable304_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable305_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable306_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable307_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable308_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable309_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable310_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable311_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable312_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable313_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable314_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable315_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable316_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable317_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable110_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable111_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable112_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable113_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable114_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable115_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable116_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable117_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable118_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_impl::global_cable119_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable120_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable121_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable122_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable123_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable124_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_impl::global_cable125_t<NV>
		this->getT(2).getT(0).getT(1).connectToRuntimeTarget(addConnection, c);                                   // routing::global_cable<global_cable15_t_index, parameter::empty>
		this->getT(2).getT(1).getT(1).connectToRuntimeTarget(addConnection, c);                                   // routing::global_cable<global_cable18_t_index, parameter::empty>
		this->getT(2).getT(2).getT(1).connectToRuntimeTarget(addConnection, c);                                   // routing::global_cable<global_cable17_t_index, parameter::empty>
		this->getT(2).getT(3).getT(1).connectToRuntimeTarget(addConnection, c);                                   // routing::global_cable<global_cable16_t_index, parameter::empty>
		this->getT(9).getT(0).getT(1).connectToRuntimeTarget(addConnection, c);                                   // routing::global_cable<global_cable19_t_index, parameter::empty>
		this->getT(9).getT(1).getT(1).connectToRuntimeTarget(addConnection, c);                                   // routing::global_cable<global_cable20_t_index, parameter::empty>
		this->getT(9).getT(2).getT(1).connectToRuntimeTarget(addConnection, c);                                   // routing::global_cable<global_cable21_t_index, parameter::empty>
		this->getT(9).getT(3).getT(1).connectToRuntimeTarget(addConnection, c);                                   // routing::global_cable<global_cable22_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);         // sn_impl::peak_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(4).setExternalData(b, index);         // sn_impl::cable_table_t
		this->getT(0).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);         // sn_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(4).setExternalData(b, index);         // sn_impl::cable_table1_t
		this->getT(0).getT(0).getT(0).getT(2).getT(1).setExternalData(b, index);         // sn_impl::peak4_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(4).setExternalData(b, index);         // sn_impl::cable_table2_t
		this->getT(0).getT(0).getT(0).getT(3).getT(1).setExternalData(b, index);         // sn_impl::peak5_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(4).setExternalData(b, index);         // sn_impl::cable_table3_t
		this->getT(0).getT(0).getT(0).getT(4).getT(1).setExternalData(b, index);         // sn_impl::peak6_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(1).setExternalData(b, index);         // sn_impl::peak8_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(1).setExternalData(b, index);         // sn_impl::peak9_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(1).setExternalData(b, index);         // sn_impl::peak10_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(1).setExternalData(b, index);         // sn_impl::peak11_t<NV>
		this->getT(0).getT(0).getT(0).getT(9).getT(1).setExternalData(b, index);         // sn_impl::peak12_t<NV>
		this->getT(0).getT(0).getT(0).getT(10).getT(1).setExternalData(b, index);        // sn_impl::peak13_t<NV>
		this->getT(0).getT(0).getT(0).getT(11).getT(1).setExternalData(b, index);        // sn_impl::peak14_t<NV>
		this->getT(0).getT(0).getT(0).getT(12).getT(1).setExternalData(b, index);        // sn_impl::peak15_t<NV>
		this->getT(0).getT(0).getT(0).getT(13).getT(1).setExternalData(b, index);        // sn_impl::peak17_t<NV>
		this->getT(0).getT(0).getT(0).getT(14).getT(1).setExternalData(b, index);        // sn_impl::peak16_t<NV>
		this->getT(0).getT(0).getT(0).getT(15).getT(1).setExternalData(b, index);        // sn_impl::peak24_t<NV>
		this->getT(0).getT(0).getT(0).getT(16).getT(1).setExternalData(b, index);        // sn_impl::peak25_t<NV>
		this->getT(0).getT(0).getT(0).getT(17).getT(1).setExternalData(b, index);        // sn_impl::peak7_t<NV>
		this->getT(0).getT(2).setExternalData(b, index);                                 // sn_impl::cable_table4_t<NV>
		this->getT(1).setExternalData(b, index);                                         // sn_impl::snex_node_t<NV>
		this->getT(2).getT(0).getT(0).setExternalData(b, index);                         // sn_impl::peak1_t
		this->getT(2).getT(1).getT(0).setExternalData(b, index);                         // sn_impl::peak19_t
		this->getT(2).getT(2).getT(0).setExternalData(b, index);                         // sn_impl::peak18_t
		this->getT(2).getT(3).getT(0).setExternalData(b, index);                         // sn_impl::peak2_t
		this->getT(5).getT(0).getT(1).getT(0).getT(2).getT(2).setExternalData(b, index); // sn_impl::cable_table6_t<NV>
		this->getT(9).getT(0).getT(0).setExternalData(b, index);                         // sn_impl::peak20_t
		this->getT(9).getT(1).getT(0).setExternalData(b, index);                         // sn_impl::peak21_t
		this->getT(9).getT(2).getT(0).setExternalData(b, index);                         // sn_impl::peak22_t
		this->getT(9).getT(3).getT(0).setExternalData(b, index);                         // sn_impl::peak23_t
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
using sn = wrap::node<sn_impl::instance<NV>>;
}


