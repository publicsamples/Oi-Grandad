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

namespace seq_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using smoothed_parameter_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using bipolar_t = control::bipolar<NV, 
                                   parameter::plain<smoothed_parameter_t<NV>, 0>>;
template <int NV>
using cable_pack1_t = wrap::data<control::cable_pack<parameter::plain<bipolar_t<NV>, 0>>, 
                                 data::external::sliderpack<0>>;
template <int NV>
using bipolar2_t = control::bipolar<NV, 
                                    parameter::plain<cable_pack1_t<NV>, 0>>;
template <int NV>
using ramp_t = wrap::mod<parameter::plain<bipolar2_t<NV>, 0>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync>;

// Parameter list for seq_impl::modchain1_t --------------------------------------------------------

using Tempo = parameter::empty;
using Mutlplier = Tempo;
using modchain1_t_plist = parameter::list<Tempo, Mutlplier>;
template <int NV>
using modchain1_t_ = container::chain<modchain1_t_plist, 
                                      wrap::fix<1, tempo_sync_t<NV>>, 
                                      ramp_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

namespace seq_t_parameters
{
// Parameter list for seq_impl::seq_t --------------------------------------------------------------

DECLARE_PARAMETER_RANGE(scaleRange, 
                        -1., 
                        1.);

template <int NV>
using scale = parameter::from0To1<seq_impl::bipolar2_t<NV>, 
                                  1, 
                                  scaleRange>;

DECLARE_PARAMETER_RANGE_SKEW(gammaRange, 
                             0.5, 
                             2., 
                             0.63093);

template <int NV>
using gamma = parameter::from0To1<seq_impl::bipolar2_t<NV>, 
                                  2, 
                                  gammaRange>;

DECLARE_PARAMETER_RANGE_STEP(tempo_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using tempo_0 = parameter::from0To1<seq_impl::tempo_sync_t<NV>, 
                                    0, 
                                    tempo_0Range>;

DECLARE_PARAMETER_RANGE_STEP(tempo_1Range, 
                             0., 
                             1000., 
                             0.1);

template <int NV>
using tempo_1 = parameter::from0To1<seq_impl::tempo_sync_t<NV>, 
                                    3, 
                                    tempo_1Range>;

template <int NV>
using tempo = parameter::chain<ranges::Identity, 
                               tempo_0<NV>, 
                               tempo_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(mutlRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using mutl = parameter::from0To1<seq_impl::tempo_sync_t<NV>, 
                                 1, 
                                 mutlRange>;

DECLARE_PARAMETER_RANGE_STEP(SmoothRange, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using Smooth = parameter::from0To1<seq_impl::smoothed_parameter_t<NV>, 
                                   1, 
                                   SmoothRange>;

template <int NV>
using sync = parameter::plain<seq_impl::tempo_sync_t<NV>, 
                              2>;
template <int NV>
using seq_t_plist = parameter::list<scale<NV>, 
                                    gamma<NV>, 
                                    tempo<NV>, 
                                    mutl<NV>, 
                                    Smooth<NV>, 
                                    sync<NV>>;
}

template <int NV>
using seq_t_ = container::chain<seq_t_parameters::seq_t_plist<NV>, 
                                wrap::fix<2, modchain1_t<NV>>, 
                                bipolar2_t<NV>, 
                                cable_pack1_t<NV>, 
                                bipolar_t<NV>, 
                                smoothed_parameter_t<NV>, 
                                math::add<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public seq_impl::seq_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(seq);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(94)
		{
			0x005B, 0x0000, 0x7300, 0x6163, 0x656C, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6167, 0x6D6D, 0x0061, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x78D5, 0x3F01, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 0x8000, 
            0xF83F, 0xEF53, 0x003D, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 
            0x0000, 0x756D, 0x6C74, 0x0000, 0x0000, 0x0000, 0x8000, 0xA43F, 
            0xA870, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0004, 0x0000, 
            0x6D53, 0x6F6F, 0x6874, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 
            0x7973, 0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain1 = this->getT(0);          // seq_impl::modchain1_t<NV>
		auto& tempo_sync = this->getT(0).getT(0); // seq_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(0).getT(1);       // seq_impl::ramp_t<NV>
		auto& bipolar2 = this->getT(1);           // seq_impl::bipolar2_t<NV>
		auto& cable_pack1 = this->getT(2);        // seq_impl::cable_pack1_t<NV>
		auto& bipolar = this->getT(3);            // seq_impl::bipolar_t<NV>
		auto& smoothed_parameter = this->getT(4); // seq_impl::smoothed_parameter_t<NV>
		auto& add = this->getT(5);                // math::add<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, bipolar2); // scale -> bipolar2::Scale
		
		this->getParameterT(1).connectT(0, bipolar2); // gamma -> bipolar2::Gamma
		
		auto& tempo_p = this->getParameterT(2);
		tempo_p.connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		tempo_p.connectT(1, tempo_sync); // tempo -> tempo_sync::UnsyncedTime
		
		this->getParameterT(3).connectT(0, tempo_sync); // mutl -> tempo_sync::Multiplier
		
		this->getParameterT(4).connectT(0, smoothed_parameter); // Smooth -> smoothed_parameter::SmoothingTime
		
		this->getParameterT(5).connectT(0, tempo_sync); // sync -> tempo_sync::Enabled
		
		// Modulation Connections ------------------------------------------------------------------
		
		smoothed_parameter.getParameter().connectT(0, add);                        // smoothed_parameter -> add::Value
		bipolar.getWrappedObject().getParameter().connectT(0, smoothed_parameter); // bipolar -> smoothed_parameter::Value
		cable_pack1.getWrappedObject().getParameter().connectT(0, bipolar);        // cable_pack1 -> bipolar::Value
		bipolar2.getWrappedObject().getParameter().connectT(0, cable_pack1);       // bipolar2 -> cable_pack1::Value
		ramp.getParameter().connectT(0, bipolar2);                                 // ramp -> bipolar2::Value
		tempo_sync.getParameter().connectT(0, ramp);                               // tempo_sync -> ramp::PeriodTime
		
		// Default Values --------------------------------------------------------------------------
		
		modchain1.setParameterT(0, 0.188781); // container::chain::Tempo
		modchain1.setParameterT(1, 0.595375); // container::chain::Mutlplier
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		; // bipolar2::Value is automated
		; // bipolar2::Scale is automated
		; // bipolar2::Gamma is automated
		
		; // cable_pack1::Value is automated
		
		;                                  // bipolar::Value is automated
		bipolar.setParameterT(1, 1.);      // control::bipolar::Scale
		bipolar.setParameterT(2, 1.02187); // control::bipolar::Gamma
		
		;                                        // smoothed_parameter::Value is automated
		;                                        // smoothed_parameter::SmoothingTime is automated
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // add::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.50575);
		this->setParameterT(2, 0.116859);
		this->setParameterT(3, 0.328984);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(1).setExternalData(b, index); // seq_impl::ramp_t<NV>
		this->getT(2).setExternalData(b, index);         // seq_impl::cable_pack1_t<NV>
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
using seq = wrap::node<seq_impl::instance<NV>>;
}


