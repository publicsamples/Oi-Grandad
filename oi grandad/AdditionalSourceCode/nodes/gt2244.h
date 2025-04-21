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

namespace gt2244_impl
{
// ==============================| Node & Parameter type declarations |==============================

using granulator_t = wrap::data<core::granulator, 
                                data::external::audiofile<0>>;

using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<2, granulator_t>>;

using midichain_t = wrap::event<midichain_t_>;
template <int NV>
using oscillator_t = wrap::no_data<core::oscillator<NV>>;

template <int NV>
using midichain1_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, oscillator_t<NV>>>;

template <int NV>
using midichain1_t = wrap::event<midichain1_t_<NV>>;
template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;

using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::empty>>;

using chain3_t = chain2_t;

using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain2_t>, 
                                 chain3_t>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, project::greyhole<NV>>, 
                                 project::granular<NV>, 
                                 core::gain<NV>, 
                                 split_t>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, midichain1_t<NV>>, 
                                  math::add<NV>, 
                                  file_player_t<NV>, 
                                  chain_t<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, midichain_t>, 
                                    chain1_t<NV>>;

namespace gt2244_t_parameters
{
// Parameter list for gt2244_impl::gt2244_t --------------------------------------------------------

template <int NV>
using Position = parameter::chain<ranges::Identity, 
                                  parameter::plain<gt2244_impl::granulator_t, 0>, 
                                  parameter::plain<math::add<NV>, 0>>;

DECLARE_PARAMETER_RANGE(GrainSize_InputRange, 
                        20., 
                        128000.);
DECLARE_PARAMETER_RANGE(GrainSize_0Range, 
                        20., 
                        128000.);

using GrainSize_0 = parameter::from0To1<gt2244_impl::granulator_t, 
                                        2, 
                                        GrainSize_0Range>;

DECLARE_PARAMETER_RANGE_STEP(GrainSize_1Range, 
                             4, 
                             1200., 
                             0.001);

template <int NV>
using GrainSize_1 = parameter::from0To1<project::granular<NV>, 
                                        4, 
                                        GrainSize_1Range>;

template <int NV>
using GrainSize = parameter::chain<GrainSize_InputRange, 
                                   GrainSize_0, 
                                   GrainSize_1<NV>>;

template <int NV>
using Dense = parameter::chain<ranges::Identity, 
                               parameter::plain<gt2244_impl::granulator_t, 3>, 
                               parameter::plain<project::granular<NV>, 2>>;

DECLARE_PARAMETER_RANGE(InputGain_InputRange, 
                        0., 
                        0.08);
DECLARE_PARAMETER_RANGE(InputGain_0Range, 
                        0., 
                        0.25);

template <int NV>
using InputGain_0 = parameter::from0To1<gt2244_impl::oscillator_t<NV>, 
                                        5, 
                                        InputGain_0Range>;

template <int NV>
using InputGain = parameter::chain<InputGain_InputRange, InputGain_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Feed_1Range, 
                             0., 
                             1.5, 
                             0.001);

template <int NV>
using Feed_1 = parameter::from0To1<project::granular<NV>, 
                                   1, 
                                   Feed_1Range>;

template <int NV>
using Feed = parameter::chain<ranges::Identity, 
                              parameter::plain<project::greyhole<NV>, 4>, 
                              Feed_1<NV>>;

using Pitch = parameter::empty;
using spread = parameter::plain<gt2244_impl::granulator_t, 
                                4>;
using Detune = parameter::plain<gt2244_impl::granulator_t, 
                                5>;
using PitchWinSync = Pitch;
using PitchWinTempo = Pitch;
using PitchWinDiv = Pitch;
using PitchWinTime = Pitch;
using PitchXXfSync = Pitch;
using PichXfTempo = Pitch;
using PitchXfDiv = Pitch;
using PitchXfTime = Pitch;
using PitchMin = Pitch;
using PitchMax = Pitch;
using PitchStep = Pitch;
template <int NV>
using Mode = parameter::plain<gt2244_impl::branch1_t<NV>, 
                              0>;
template <int NV>
using InputShape = parameter::plain<gt2244_impl::oscillator_t<NV>, 
                                    0>;
template <int NV>
using InputRatio = parameter::plain<gt2244_impl::oscillator_t<NV>, 
                                    2>;
template <int NV>
using Damp = parameter::plain<project::greyhole<NV>, 1>;
template <int NV>
using Size = parameter::plain<project::greyhole<NV>, 2>;
template <int NV>
using Diff = parameter::plain<project::greyhole<NV>, 3>;
template <int NV>
using gt2244_t_plist = parameter::list<Position<NV>, 
                                       Pitch, 
                                       GrainSize<NV>, 
                                       Dense<NV>, 
                                       spread, 
                                       Detune, 
                                       PitchWinSync, 
                                       PitchWinTempo, 
                                       PitchWinDiv, 
                                       PitchWinTime, 
                                       PitchXXfSync, 
                                       PichXfTempo, 
                                       PitchXfDiv, 
                                       PitchXfTime, 
                                       PitchMin, 
                                       PitchMax, 
                                       PitchStep, 
                                       Mode<NV>, 
                                       InputShape<NV>, 
                                       InputRatio<NV>, 
                                       InputGain<NV>, 
                                       Feed<NV>, 
                                       Damp<NV>, 
                                       Size<NV>, 
                                       Diff<NV>>;
}

template <int NV>
using gt2244_t_ = container::chain<gt2244_t_parameters::gt2244_t_plist<NV>, 
                                   wrap::fix<2, branch1_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public gt2244_impl::gt2244_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(gt2244);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(428)
		{
			0x005B, 0x0000, 0x5000, 0x736F, 0x7469, 0x6F69, 0x006E, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x9BD3, 0x3D06, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x015B, 0x0000, 0x5000, 0x7469, 0x6863, 0x0000, 0x1000, 
            0x00C2, 0x1000, 0x0242, 0x0000, 0x0040, 0x8000, 0xCD3F, 0xCCCC, 
            0x5B3D, 0x0002, 0x0000, 0x7247, 0x6961, 0x536E, 0x7A69, 0x0065, 
            0x0000, 0x41A0, 0x0000, 0x47FA, 0x2920, 0x462C, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x035B, 0x0000, 0x4400, 0x6E65, 0x6573, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0004, 0x0000, 0x7073, 0x6572, 0x6461, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x593F, 0x5EB9, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0005, 0x0000, 0x6544, 0x7574, 0x656E, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0006, 0x0000, 0x6950, 0x6374, 0x5768, 0x6E69, 
            0x7953, 0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0007, 0x0000, 0x6950, 
            0x6374, 0x5768, 0x6E69, 0x6554, 0x706D, 0x006F, 0x0000, 0x0000, 
            0x0000, 0x4190, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x085B, 0x0000, 0x5000, 0x7469, 0x6863, 0x6957, 0x446E, 0x7669, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x0000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0009, 0x0000, 0x6950, 0x6374, 0x5768, 
            0x6E69, 0x6954, 0x656D, 0x0000, 0x0000, 0x0000, 0x7A00, 0x9A44, 
            0x7F99, 0x0042, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x000A, 0x0000, 
            0x6950, 0x6374, 0x5868, 0x6658, 0x7953, 0x636E, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x000B, 0x0000, 0x6950, 0x6863, 0x6658, 0x6554, 0x706D, 
            0x006F, 0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x4160, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0C5B, 0x0000, 0x5000, 0x7469, 0x6863, 
            0x6658, 0x6944, 0x0076, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 
            0x4100, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0D5B, 0x0000, 0x5000, 
            0x7469, 0x6863, 0x6658, 0x6954, 0x656D, 0x0000, 0x0000, 0x0000, 
            0x7A00, 0x9A44, 0x6399, 0x0042, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 
            0x000E, 0x0000, 0x6950, 0x6374, 0x4D68, 0x6E69, 0x0000, 0x4000, 
            0x00C1, 0x4000, 0x0041, 0x4000, 0x00C1, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x000F, 0x0000, 0x6950, 0x6374, 0x4D68, 0x7861, 0x0000, 
            0x4000, 0x00C1, 0x4000, 0x0041, 0x4000, 0x0041, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0010, 0x0000, 0x6950, 0x6374, 0x5368, 0x6574, 
            0x0070, 0x0000, 0x0000, 0x0000, 0x4140, 0x8E56, 0x3F7E, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x115B, 0x0000, 0x4D00, 0x646F, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x125B, 0x0000, 0x4900, 0x706E, 0x7475, 0x6853, 
            0x7061, 0x0065, 0x0000, 0x0000, 0x0000, 0x4080, 0x0000, 0x4000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x135B, 0x0000, 0x4900, 0x706E, 
            0x7475, 0x6152, 0x6974, 0x006F, 0x0000, 0x0000, 0x0000, 0x4180, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x145B, 0x0000, 
            0x4900, 0x706E, 0x7475, 0x6147, 0x6E69, 0x0000, 0x0000, 0x0A00, 
            0xA3D7, 0x603D, 0x0FB0, 0x003B, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0015, 0x0000, 0x6546, 0x6465, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x0A3F, 0x23D7, 0x5B3C, 0x0016, 
            0x0000, 0x6144, 0x706D, 0x0000, 0x0000, 0xA400, 0x7D70, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x6F3F, 0x8312, 0x5B3A, 0x0017, 0x0000, 
            0x6953, 0x657A, 0x0000, 0x0000, 0x003F, 0x4000, 0x0040, 0x0000, 
            0x003F, 0x8000, 0x173F, 0xD1B7, 0x5B38, 0x0018, 0x0000, 0x6944, 
            0x6666, 0x0000, 0x0000, 0xA400, 0x7D70, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x173F, 0xD1B7, 0x0038
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& branch1 = this->getT(0);                                // gt2244_impl::branch1_t<NV>
		auto& midichain = this->getT(0).getT(0);                      // gt2244_impl::midichain_t
		auto& granulator = this->getT(0).getT(0).getT(0);             // gt2244_impl::granulator_t
		auto& chain1 = this->getT(0).getT(1);                         // gt2244_impl::chain1_t<NV>
		auto& midichain1 = this->getT(0).getT(1).getT(0);             // gt2244_impl::midichain1_t<NV>
		auto& oscillator = this->getT(0).getT(1).getT(0).getT(0);     // gt2244_impl::oscillator_t<NV>
		auto& add = this->getT(0).getT(1).getT(1);                    // math::add<NV>
		auto& file_player = this->getT(0).getT(1).getT(2);            // gt2244_impl::file_player_t<NV>
		auto& chain = this->getT(0).getT(1).getT(3);                  // gt2244_impl::chain_t<NV>
		auto& faust1 = this->getT(0).getT(1).getT(3).getT(0);         // project::greyhole<NV>
		auto& faust2 = this->getT(0).getT(1).getT(3).getT(1);         // project::granular<NV>
		auto& gain1 = this->getT(0).getT(1).getT(3).getT(2);          // core::gain<NV>
		auto& split = this->getT(0).getT(1).getT(3).getT(3);          // gt2244_impl::split_t
		auto& chain2 = this->getT(0).getT(1).getT(3).getT(3).getT(0); // gt2244_impl::chain2_t
		auto& chain3 = this->getT(0).getT(1).getT(3).getT(3).getT(1); // gt2244_impl::chain3_t
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& Position_p = this->getParameterT(0);
		Position_p.connectT(0, granulator); // Position -> granulator::Position
		Position_p.connectT(1, add);        // Position -> add::Value
		
		auto& GrainSize_p = this->getParameterT(2);
		GrainSize_p.connectT(0, granulator); // GrainSize -> granulator::GrainSize
		GrainSize_p.connectT(1, faust2);     // GrainSize -> faust2::taille
		
		auto& Dense_p = this->getParameterT(3);
		Dense_p.connectT(0, granulator); // Dense -> granulator::Density
		Dense_p.connectT(1, faust2);     // Dense -> faust2::population
		
		this->getParameterT(4).connectT(0, granulator); // spread -> granulator::Spread
		
		this->getParameterT(5).connectT(0, granulator); // Detune -> granulator::Detune
		
		this->getParameterT(17).connectT(0, branch1); // Mode -> branch1::Index
		
		this->getParameterT(18).connectT(0, oscillator); // InputShape -> oscillator::Mode
		
		this->getParameterT(19).connectT(0, oscillator); // InputRatio -> oscillator::FreqRatio
		
		this->getParameterT(20).connectT(0, oscillator); // InputGain -> oscillator::Gain
		
		auto& Feed_p = this->getParameterT(21);
		Feed_p.connectT(0, faust1); // Feed -> faust1::feedback
		Feed_p.connectT(1, faust2); // Feed -> faust2::feedback
		
		this->getParameterT(22).connectT(0, faust1); // Damp -> faust1::damping
		
		this->getParameterT(23).connectT(0, faust1); // Size -> faust1::size
		
		this->getParameterT(24).connectT(0, faust1); // Diff -> faust1::diffusion
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch1::Index is automated
		
		;                                // granulator::Position is automated
		granulator.setParameterT(1, 1.); // core::granulator::Pitch
		;                                // granulator::GrainSize is automated
		;                                // granulator::Density is automated
		;                                // granulator::Spread is automated
		;                                // granulator::Detune is automated
		
		;                                      // oscillator::Mode is automated
		oscillator.setParameterT(1, 55.);      // core::oscillator::Frequency
		;                                      // oscillator::FreqRatio is automated
		oscillator.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator.setParameterT(4, 0.497823); // core::oscillator::Phase
		;                                      // oscillator::Gain is automated
		
		; // add::Value is automated
		
		file_player.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);      // core::file_player::Gate
		file_player.setParameterT(2, 504.907); // core::file_player::RootFrequency
		file_player.setParameterT(3, 0.);      // core::file_player::FreqRatio
		
		faust1.setParameterT(0, 0.0016); // core::faust::delayTime
		;                                // faust1::damping is automated
		;                                // faust1::size is automated
		;                                // faust1::diffusion is automated
		;                                // faust1::feedback is automated
		faust1.setParameterT(5, 0.);     // core::faust::modDepth
		faust1.setParameterT(6, 5.83);   // core::faust::modFreq
		
		faust2.setParameterT(0, 0.045); // core::faust::decal
		;                               // faust2::feedback is automated
		;                               // faust2::population is automated
		faust2.setParameterT(3, 0.648); // core::faust::speed
		;                               // faust2::taille is automated
		
		gain1.setParameterT(0, 0.);  // core::gain::Gain
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.0328635);
		this->setParameterT(1, 2);
		this->setParameterT(2, 11018.3);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.870016);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 2.);
		this->setParameterT(8, 8.);
		this->setParameterT(9, 63.9);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 14.);
		this->setParameterT(12, 8.);
		this->setParameterT(13, 56.9);
		this->setParameterT(14, -12.);
		this->setParameterT(15, 12.);
		this->setParameterT(16, 0.994359);
		this->setParameterT(17, 0.);
		this->setParameterT(18, 2.);
		this->setParameterT(19, 0.);
		this->setParameterT(20, 0.00219252);
		this->setParameterT(21, 0.);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 0.5);
		this->setParameterT(24, 0.);
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
		
		this->getT(0).getT(0).getT(0).setExternalData(b, index);         // gt2244_impl::granulator_t
		this->getT(0).getT(1).getT(0).getT(0).setExternalData(b, index); // gt2244_impl::oscillator_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index);         // gt2244_impl::file_player_t<NV>
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
using gt2244 = wrap::node<gt2244_impl::instance<NV>>;
}


