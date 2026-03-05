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

namespace res2_impl
{
// ===========================| Node & Parameter type declarations |===========================

template <int NV>
using stereo_cable = cable::block<NV, 2>;

namespace res2_t_parameters
{
// Parameter list for res2_impl::res2_t -------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(lpRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using lp = parameter::from0To1<filters::one_pole<NV>, 
                               0, 
                               lpRange>;

template <int NV>
using FB = parameter::plain<routing::receive<NV, stereo_cable<NV>>, 
                            0>;
template <int NV>
using DELAY = parameter::plain<jdsp::jdelay_thiran<NV>, 
                               1>;
template <int NV>
using HASS = parameter::plain<fx::haas<NV>, 0>;
template <int NV>
using res2_t_plist = parameter::list<FB<NV>, 
                                     DELAY<NV>, 
                                     HASS<NV>, 
                                     lp<NV>>;
}

template <int NV>
using res2_t_ = container::chain<res2_t_parameters::res2_t_plist<NV>, 
                                 wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                 jdsp::jdelay_thiran<NV>, 
                                 fx::haas<NV>, 
                                 filters::one_pole<NV>, 
                                 routing::send<NV, stereo_cable<NV>>>;

// ===============================| Root node initialiser class |===============================

template <int NV> struct instance: public res2_impl::res2_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(res2);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(64)
		{
			0x005C, 0x0000, 0x0000, 0x4246, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xF3B6, 0x3F0F, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025C, 
            0x0001, 0x0000, 0x4544, 0x414C, 0x0059, 0x0000, 0x0000, 0x0000, 
            0xF000, 0x1F41, 0xA1CD, 0x0041, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0200, 0x0000, 0x4800, 0x5341, 0x0053, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0xCF3F, 0xCCCC, 0x003D, 0x8000, 0xCD3F, 0xCCCC, 0x5C3D, 
            0x0300, 0x0000, 0x6C00, 0x0070, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References --------------------------------------------------------------------
		
		auto& receive = this->getT(0);       // routing::receive<NV, stereo_cable<NV>>
		auto& jdelay_thiran = this->getT(1); // jdsp::jdelay_thiran<NV>
		auto& haas = this->getT(2);          // fx::haas<NV>
		auto& one_pole = this->getT(3);      // filters::one_pole<NV>
		auto& send = this->getT(4);          // routing::send<NV, stereo_cable<NV>>
		
		// Parameter Connections --------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, receive); // FB -> receive::Feedback
		
		this->getParameterT(1).connectT(0, jdelay_thiran); // DELAY -> jdelay_thiran::DelayTime
		
		this->getParameterT(2).connectT(0, haas); // HASS -> haas::Position
		
		this->getParameterT(3).connectT(0, one_pole); // lp -> one_pole::Frequency
		
		// Send Connections -------------------------------------------------------------------
		
		send.connect(receive);
		
		// Default Values ---------------------------------------------------------------------
		
		; // receive::Feedback is automated
		
		jdelay_thiran.setParameterT(0, 30.); // jdsp::jdelay_thiran::Limit
		;                                    // jdelay_thiran::DelayTime is automated
		
		; // haas::Position is automated
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		this->setParameterT(0, 0.562312);
		this->setParameterT(1, 20.2252);
		this->setParameterT(2, 0.1);
		this->setParameterT(3, 0.);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ====================================| Public Definition |====================================

namespace project
{
// polyphonic template declaration

template <int NV>
using res2 = wrap::node<res2_impl::instance<NV>>;
}


