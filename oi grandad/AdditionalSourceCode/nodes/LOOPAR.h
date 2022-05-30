#pragma once

#include <JuceHeader.h>
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace LOOPAR_impl
{
// ========================| Node & Parameter type declarations |========================

template <int NV>
using simple_ar_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                           parameter::empty>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod<NV>>>;
template <int NV>
using ramp_t = wrap::mod<parameter::plain<simple_ar_t<NV>, 2>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, ramp_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

namespace LOOPAR_t_parameters
{
// Parameter list for LOOPAR_impl::LOOPAR_t ---------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(tempoRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using tempo = parameter::from0To1<LOOPAR_impl::tempo_sync_t<NV>, 
                                  0, 
                                  tempoRange>;

DECLARE_PARAMETER_RANGE_STEP(multRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using mult = parameter::from0To1<LOOPAR_impl::tempo_sync_t<NV>, 
                                 1, 
                                 multRange>;

DECLARE_PARAMETER_RANGE_SKEW(attackRange, 
                             0., 
                             1000., 
                             0.30103);

template <int NV>
using attack = parameter::from0To1<LOOPAR_impl::simple_ar_t<NV>, 
                                   0, 
                                   attackRange>;

template <int NV>
using rel = parameter::from0To1<LOOPAR_impl::simple_ar_t<NV>, 
                                1, 
                                attackRange>;

template <int NV>
using LOOPAR_t_plist = parameter::list<tempo<NV>, 
                                       mult<NV>, 
                                       attack<NV>, 
                                       rel<NV>>;
}

template <int NV>
using LOOPAR_t_ = container::chain<LOOPAR_t_parameters::LOOPAR_t_plist<NV>, 
                                   wrap::fix<2, tempo_sync_t<NV>>, 
                                   modchain_t<NV>, 
                                   simple_ar_t<NV>, 
                                   math::add<NV>>;

// ============================| Root node initialiser class |============================

template <int NV> struct instance: public LOOPAR_impl::LOOPAR_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(LOOPAR);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(62)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x756D, 0x746C, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 
            0x0000, 0x7461, 0x6174, 0x6B63, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 
            0x0000, 0x6572, 0x006C, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References --------------------------------------------------------------
		
		auto& tempo_sync = this->getT(0);   // LOOPAR_impl::tempo_sync_t<NV>
		auto& modchain = this->getT(1);     // LOOPAR_impl::modchain_t<NV>
		auto& ramp = this->getT(1).getT(0); // LOOPAR_impl::ramp_t<NV>
		auto& simple_ar = this->getT(2);    // LOOPAR_impl::simple_ar_t<NV>
		auto& add = this->getT(3);          // math::add<NV>
		
		// Parameter Connections --------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		this->getParameterT(1).connectT(0, tempo_sync); // mult -> tempo_sync::Multiplier
		
		this->getParameterT(2).connectT(0, simple_ar); // attack -> simple_ar::Attack
		
		this->getParameterT(3).connectT(0, simple_ar); // rel -> simple_ar::Release
		
		// Modulation Connections -------------------------------------------------------
		
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		simple_ar_p.getParameterT(0).connectT(0, add); // simple_ar -> add::Value
		ramp.getParameter().connectT(0, simple_ar);    // ramp -> simple_ar::Gate
		tempo_sync.getParameter().connectT(0, ramp);   // tempo_sync -> ramp::PeriodTime
		
		// Default Values ---------------------------------------------------------------
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		;                               // simple_ar::Attack is automated
		;                               // simple_ar::Release is automated
		;                               // simple_ar::Gate is automated
		simple_ar.setParameterT(3, 0.); // envelope::simple_ar::AttackCurve
		
		; // add::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ----------------------------------------------------
		
		this->getT(1).getT(0).setExternalData(b, index); // LOOPAR_impl::ramp_t<NV>
		this->getT(2).setExternalData(b, index);         // LOOPAR_impl::simple_ar_t<NV>
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// =================================| Public Definition |=================================

namespace project
{
// polyphonic template declaration

template <int NV>
using LOOPAR = wrap::node<LOOPAR_impl::instance<NV>>;
}


