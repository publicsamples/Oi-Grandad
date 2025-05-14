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
// ==========================| Node & Parameter type declarations |==========================

using granulator_t = wrap::data<core::granulator, 
                                data::external::audiofile<0>>;

using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<2, granulator_t>>;

using midichain_t = wrap::event<midichain_t_>;

namespace gt2244_t_parameters
{
// Parameter list for gt2244_impl::gt2244_t -------------------------------------------------

using Position = parameter::plain<gt2244_impl::granulator_t, 
                                  0>;
using GrainSize = parameter::plain<gt2244_impl::granulator_t, 
                                   2>;
using Dense = parameter::plain<gt2244_impl::granulator_t, 
                               3>;
using spread = parameter::plain<gt2244_impl::granulator_t, 
                                4>;
using Detune = parameter::plain<gt2244_impl::granulator_t, 
                                5>;
using gt2244_t_plist = parameter::list<Position, 
                                       GrainSize, 
                                       Dense, 
                                       spread, 
                                       Detune>;
}

using gt2244_t_ = container::chain<gt2244_t_parameters::gt2244_t_plist, 
                                   wrap::fix<2, midichain_t>>;

// ==============================| Root node initialiser class |==============================

struct instance: public gt2244_impl::gt2244_t_
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
		SNEX_METADATA_ENCODED_PARAMETERS(84)
		{
			0x005B, 0x0000, 0x5000, 0x736F, 0x7469, 0x6F69, 0x006E, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x9BD3, 0x3D06, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x015B, 0x0000, 0x4700, 0x6172, 0x6E69, 0x6953, 0x657A, 
            0x0000, 0xA000, 0x0041, 0xFA00, 0x2047, 0x2C29, 0x0046, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0002, 0x0000, 0x6544, 0x736E, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x035B, 0x0000, 0x7300, 0x7270, 0x6165, 0x0064, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0xB959, 0x3F5E, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x045B, 0x0000, 0x4400, 0x7465, 0x6E75, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References ------------------------------------------------------------------
		
		auto& midichain = this->getT(0);          // gt2244_impl::midichain_t
		auto& granulator = this->getT(0).getT(0); // gt2244_impl::granulator_t
		
		// Parameter Connections ------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, granulator); // Position -> granulator::Position
		
		this->getParameterT(1).connectT(0, granulator); // GrainSize -> granulator::GrainSize
		
		this->getParameterT(2).connectT(0, granulator); // Dense -> granulator::Density
		
		this->getParameterT(3).connectT(0, granulator); // spread -> granulator::Spread
		
		this->getParameterT(4).connectT(0, granulator); // Detune -> granulator::Detune
		
		// Default Values -------------------------------------------------------------------
		
		;                                // granulator::Position is automated
		granulator.setParameterT(1, 1.); // core::granulator::Pitch
		;                                // granulator::GrainSize is automated
		;                                // granulator::Density is automated
		;                                // granulator::Spread is automated
		;                                // granulator::Detune is automated
		
		this->setParameterT(0, 0.0328635);
		this->setParameterT(1, 11018.3);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.870016);
		this->setParameterT(4, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references -------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections --------------------------------------------------------
		
		this->getT(0).getT(0).setExternalData(b, index); // gt2244_impl::granulator_t
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ===================================| Public Definition |===================================

namespace project
{
using gt2244 = wrap::node<gt2244_impl::instance>;
}


