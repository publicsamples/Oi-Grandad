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

namespace loopenv_impl
{
// =========================| Node & Parameter type declarations |=========================

template <int NV>
using simple_ar_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                           parameter::empty>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod<NV>>>;
template <int NV>
using timer_t = wrap::mod<parameter::plain<simple_ar_t<NV>, 2>, 
                          control::timer<NV, timer_logic::toggle<NV>>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<timer_t<NV>, 1>, 
                               control::tempo_sync>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, timer_t<NV>>, 
                                     simple_ar_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

namespace loopenv_t_parameters
{
// Parameter list for loopenv_impl::loopenv_t --------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(tempoRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using tempo = parameter::from0To1<loopenv_impl::tempo_sync_t<NV>, 
                                  0, 
                                  tempoRange>;

DECLARE_PARAMETER_RANGE_STEP(multiRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using multi = parameter::from0To1<loopenv_impl::tempo_sync_t<NV>, 
                                  1, 
                                  multiRange>;

DECLARE_PARAMETER_RANGE_SKEW(attackRange, 
                             0., 
                             5168.4, 
                             0.30103);

template <int NV>
using attack = parameter::from0To1<loopenv_impl::simple_ar_t<NV>, 
                                   0, 
                                   attackRange>;

DECLARE_PARAMETER_RANGE_SKEW(relRange, 
                             0., 
                             2106.38, 
                             0.30103);

template <int NV>
using rel = parameter::from0To1<loopenv_impl::simple_ar_t<NV>, 
                                1, 
                                relRange>;

template <int NV>
using loopenv_t_plist = parameter::list<tempo<NV>, 
                                        multi<NV>, 
                                        attack<NV>, 
                                        rel<NV>>;
}

template <int NV>
using loopenv_t_ = container::chain<loopenv_t_parameters::loopenv_t_plist<NV>, 
                                    wrap::fix<2, tempo_sync_t<NV>>, 
                                    modchain_t<NV>, 
                                    math::add<NV>>;

// ============================| Root node initialiser class |============================

template <int NV> struct instance: public loopenv_impl::loopenv_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(loopenv);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(62)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x756D, 0x746C, 0x0069, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x6100, 0x7474, 0x6361, 0x006B, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3EA5, 0x0000, 0x3F80, 0x0000, 0x0000, 0x035B, 
            0x0000, 0x7200, 0x6C65, 0x0000, 0x0000, 0x0000, 0x8000, 0x833F, 
            0x50C0, 0x003F, 0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References ---------------------------------------------------------------
		
		auto& tempo_sync = this->getT(0);        // loopenv_impl::tempo_sync_t<NV>
		auto& modchain = this->getT(1);          // loopenv_impl::modchain_t<NV>
		auto& timer = this->getT(1).getT(0);     // loopenv_impl::timer_t<NV>
		auto& simple_ar = this->getT(1).getT(1); // loopenv_impl::simple_ar_t<NV>
		auto& add = this->getT(2);               // math::add<NV>
		
		// Parameter Connections ---------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		this->getParameterT(1).connectT(0, tempo_sync); // multi -> tempo_sync::Multiplier
		
		this->getParameterT(2).connectT(0, simple_ar); // attack -> simple_ar::Attack
		
		this->getParameterT(3).connectT(0, simple_ar); // rel -> simple_ar::Release
		
		// Modulation Connections --------------------------------------------------------
		
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		simple_ar_p.getParameterT(0).connectT(0, add); // simple_ar -> add::Value
		timer.getParameter().connectT(0, simple_ar);   // timer -> simple_ar::Gate
		tempo_sync.getParameter().connectT(0, timer);  // tempo_sync -> timer::Interval
		
		// Default Values ----------------------------------------------------------------
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 12.2); // control::tempo_sync::UnsyncedTime
		
		timer.setParameterT(0, 1.); // control::timer::Active
		;                           // timer::Interval is automated
		
		;                                  // simple_ar::Attack is automated
		;                                  // simple_ar::Release is automated
		;                                  // simple_ar::Gate is automated
		simple_ar.setParameterT(3, 0.576); // envelope::simple_ar::AttackCurve
		
		; // add::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 0.322266);
		this->setParameterT(3, 0.815438);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections -----------------------------------------------------
		
		this->getT(1).getT(1).setExternalData(b, index); // loopenv_impl::simple_ar_t<NV>
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
using loopenv = wrap::node<loopenv_impl::instance<NV>>;
}


