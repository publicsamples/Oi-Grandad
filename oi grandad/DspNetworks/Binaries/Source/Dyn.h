#pragma once

#include "master_bus_compressor_native.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace Dyn_impl
{
// ==============================| Node & Parameter type declarations |==============================

using sb4_t_ = container::chain<parameter::empty, 
                                wrap::fix<8, core::empty>>;

using sb4_t = bypass::smoothed<20, sb4_t_>;
using switcher1_c0 = parameter::bypass<sb4_t>;

template <int NV>
using sb5_t_ = container::chain<parameter::empty, 
                                wrap::fix<8, project::master_bus_compressor_native<NV>>>;

template <int NV>
using sb5_t = bypass::smoothed<20, sb5_t_<NV>>;
template <int NV>
using switcher1_c1 = parameter::bypass<sb5_t<NV>>;

template <int NV>
using switcher1_multimod = parameter::list<switcher1_c0, switcher1_c1<NV>>;

template <int NV>
using switcher1_t = control::xfader<switcher1_multimod<NV>, faders::switcher>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<switcher1_t<NV>, 0>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, minmax_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using sb_container1_t = container::chain<parameter::empty, 
                                         wrap::fix<8, sb4_t>, 
                                         sb5_t<NV>>;

namespace Dyn_t_parameters
{
// Parameter list for Dyn_impl::Dyn_t --------------------------------------------------------------

template <int NV>
using Thresh = parameter::plain<project::master_bus_compressor_native<NV>, 
                                0>;
template <int NV>
using Makeup = parameter::plain<project::master_bus_compressor_native<NV>, 
                                1>;
template <int NV>
using Atk = parameter::plain<project::master_bus_compressor_native<NV>, 
                             2>;
template <int NV>
using Rel = parameter::plain<project::master_bus_compressor_native<NV>, 
                             3>;
template <int NV>
using Ratio = parameter::plain<project::master_bus_compressor_native<NV>, 
                               4>;
template <int NV>
using POWER = parameter::plain<Dyn_impl::minmax_t<NV>, 0>;
template <int NV>
using Dyn_t_plist = parameter::list<Thresh<NV>, 
                                    Makeup<NV>, 
                                    Atk<NV>, 
                                    Rel<NV>, 
                                    Ratio<NV>, 
                                    POWER<NV>>;
}

template <int NV>
using Dyn_t_ = container::chain<Dyn_t_parameters::Dyn_t_plist<NV>, 
                                wrap::fix<8, modchain_t<NV>>, 
                                switcher1_t<NV>, 
                                sb_container1_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Dyn_impl::Dyn_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Dyn);
		SNEX_METADATA_NUM_CHANNELS(8);
		SNEX_METADATA_ENCODED_PARAMETERS(100)
		{
			0x065C, 0x0000, 0x0000, 0x6854, 0x6572, 0x6873, 0x0000, 0x0000, 
            0xC1F0, 0x0000, 0x0000, 0x0000, 0x0000, 0xD144, 0x3FDA, 0xCCCD, 
            0x3DCC, 0x065C, 0x0001, 0x0000, 0x614D, 0x656B, 0x7075, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x41C0, 0x0000, 0x41C0, 0x0000, 0x3F00, 
            0xCCCD, 0x3DCC, 0x025C, 0x0002, 0x0000, 0x7441, 0x006B, 0xCD00, 
            0xCCCC, 0x003D, 0xF000, 0xCD41, 0xCCCC, 0x8C3D, 0x2089, 0xCD3F, 
            0xCCCC, 0x5C3D, 0x0302, 0x0000, 0x5200, 0x6C65, 0x0000, 0x0000, 
            0x4248, 0x0000, 0x4496, 0x0000, 0x4248, 0x5ECB, 0x3E62, 0x0000, 
            0x3F80, 0x005C, 0x0004, 0x0000, 0x6152, 0x6974, 0x006F, 0x0000, 
            0x8000, 0x003F, 0x2000, 0x6641, 0x0666, 0x9D40, 0x2184, 0xCD3F, 
            0xCCCC, 0x5C3D, 0x0500, 0x0000, 0x5000, 0x574F, 0x5245, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);                                     // Dyn_impl::modchain_t<NV>
		auto& minmax = this->getT(0).getT(0);                               // Dyn_impl::minmax_t<NV>
		auto& switcher1 = this->getT(1);                                    // Dyn_impl::switcher1_t<NV>
		auto& sb_container1 = this->getT(2);                                // Dyn_impl::sb_container1_t<NV>
		auto& sb4 = this->getT(2).getT(0);                                  // Dyn_impl::sb4_t
		auto& sb5 = this->getT(2).getT(1);                                  // Dyn_impl::sb5_t<NV>
		auto& master_bus_compressor_native = this->getT(2).getT(1).getT(0); // project::master_bus_compressor_native<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, master_bus_compressor_native); // Thresh -> master_bus_compressor_native::Threshold
		
		this->getParameterT(1).connectT(0, master_bus_compressor_native); // Makeup -> master_bus_compressor_native::MakeupGain
		
		this->getParameterT(2).connectT(0, master_bus_compressor_native); // Atk -> master_bus_compressor_native::Attack
		
		this->getParameterT(3).connectT(0, master_bus_compressor_native); // Rel -> master_bus_compressor_native::Release
		
		this->getParameterT(4).connectT(0, master_bus_compressor_native); // Ratio -> master_bus_compressor_native::Ratio
		
		this->getParameterT(5).connectT(0, minmax); // POWER -> minmax::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& switcher1_p = switcher1.getWrappedObject().getParameter();
		switcher1_p.getParameterT(0).connectT(0, sb4);                   // switcher1 -> sb4::Bypassed
		switcher1_p.getParameterT(1).connectT(0, sb5);                   // switcher1 -> sb5::Bypassed
		minmax.getWrappedObject().getParameter().connectT(0, switcher1); // minmax -> switcher1::Value
		
		// Default Values --------------------------------------------------------------------------
		
		;                            // minmax::Value is automated
		minmax.setParameterT(1, 0.); // control::minmax::Minimum
		minmax.setParameterT(2, 1.); // control::minmax::Maximum
		minmax.setParameterT(3, 1.); // control::minmax::Skew
		minmax.setParameterT(4, 0.); // control::minmax::Step
		minmax.setParameterT(5, 1.); // control::minmax::Polarity
		
		; // switcher1::Value is automated
		
		; // master_bus_compressor_native::Threshold is automated
		; // master_bus_compressor_native::MakeupGain is automated
		; // master_bus_compressor_native::Attack is automated
		; // master_bus_compressor_native::Release is automated
		; // master_bus_compressor_native::Ratio is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 24.);
		this->setParameterT(2, 0.1);
		this->setParameterT(3, 50.);
		this->setParameterT(4, 2.1);
		this->setParameterT(5, 0.);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
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
using Dyn = wrap::node<Dyn_impl::instance<NV>>;
}


