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

namespace MacroMod_impl
{
// ==================| Node & Parameter type declarations |==================

namespace MacroMod_t_parameters
{
}

template <int NV>
using MacroMod_t_ = container::chain<parameter::plain<math::add<NV>, 0>, 
                                     wrap::fix<1, math::add<NV>>>;

// =====================| Root node initialiser class |=====================

template <int NV> struct instance: public MacroMod_impl::MacroMod_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(MacroMod);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(18)
		{
			0x005C, 0x0000, 0x0000, 0x616D, 0x7263, 0x006F, 0x0000, 0x0000, 
            0x0000, 0x8000, 0xD03F, 0x05F7, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------
		
		auto& add = this->getT(0); // math::add<NV>
		
		// Parameter Connections -------------------------------------------
		
		this->getParameterT(0).connectT(0, add); // macro -> add::Value
		
		// Default Values --------------------------------------------------
		
		; // add::Value is automated
		
		this->setParameterT(0, 0.523313);
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
// ==========================| Public Definition |==========================

namespace project
{
// polyphonic template declaration

template <int NV>
using MacroMod = wrap::node<MacroMod_impl::instance<NV>>;
}


