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

namespace DspNetwork_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using smoothed_parameter_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<smoothed_parameter_t<NV>, 0>>, 
                                data::external::sliderpack<0>>;
template <int NV>
using bipolar_t = control::bipolar<NV, 
                                   parameter::plain<cable_pack_t<NV>, 0>>;
template <int NV>
using ramp_t = wrap::mod<parameter::plain<bipolar_t<NV>, 0>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, tempo_sync_t<NV>>, 
                                     ramp_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

namespace DspNetwork_t_parameters
{
// Parameter list for DspNetwork_impl::DspNetwork_t ------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(tempoRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using tempo = parameter::from0To1<DspNetwork_impl::tempo_sync_t<NV>, 
                                  0, 
                                  tempoRange>;

DECLARE_PARAMETER_RANGE_STEP(multiRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using multi = parameter::from0To1<DspNetwork_impl::tempo_sync_t<NV>, 
                                  1, 
                                  multiRange>;

DECLARE_PARAMETER_RANGE(scaleRange, 
                        -1., 
                        1.);

template <int NV>
using scale = parameter::from0To1<DspNetwork_impl::bipolar_t<NV>, 
                                  1, 
                                  scaleRange>;

DECLARE_PARAMETER_RANGE_SKEW(gammaRange, 
                             0.5, 
                             2., 
                             0.63093);

template <int NV>
using gamma = parameter::from0To1<DspNetwork_impl::bipolar_t<NV>, 
                                  2, 
                                  gammaRange>;

DECLARE_PARAMETER_RANGE_STEP(smoothRange, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using smooth = parameter::from0To1<DspNetwork_impl::smoothed_parameter_t<NV>, 
                                   1, 
                                   smoothRange>;

template <int NV>
using DspNetwork_t_plist = parameter::list<tempo<NV>, 
                                           multi<NV>, 
                                           scale<NV>, 
                                           gamma<NV>, 
                                           smooth<NV>>;
}

template <int NV>
using DspNetwork_t_ = container::chain<DspNetwork_t_parameters::DspNetwork_t_plist<NV>, 
                                       wrap::fix<2, modchain_t<NV>>, 
                                       bipolar_t<NV>, 
                                       cable_pack_t<NV>, 
                                       smoothed_parameter_t<NV>, 
                                       math::add<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public DspNetwork_impl::DspNetwork_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(DspNetwork);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(80)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x756D, 0x746C, 0x0069, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x7300, 0x6163, 0x656C, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 
            0x0000, 0x6167, 0x6D6D, 0x0061, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 
            0x7300, 0x6F6D, 0x746F, 0x0068, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain = this->getT(0);           // DspNetwork_impl::modchain_t<NV>
		auto& tempo_sync = this->getT(0).getT(0); // DspNetwork_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(0).getT(1);       // DspNetwork_impl::ramp_t<NV>
		auto& bipolar = this->getT(1);            // DspNetwork_impl::bipolar_t<NV>
		auto& cable_pack = this->getT(2);         // DspNetwork_impl::cable_pack_t<NV>
		auto& smoothed_parameter = this->getT(3); // DspNetwork_impl::smoothed_parameter_t<NV>
		auto& add = this->getT(4);                // math::add<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		this->getParameterT(1).connectT(0, tempo_sync); // multi -> tempo_sync::Multiplier
		
		this->getParameterT(2).connectT(0, bipolar); // scale -> bipolar::Scale
		
		this->getParameterT(3).connectT(0, bipolar); // gamma -> bipolar::Gamma
		
		this->getParameterT(4).connectT(0, smoothed_parameter); // smooth -> smoothed_parameter::SmoothingTime
		
		// Modulation Connections ------------------------------------------------------------------
		
		smoothed_parameter.getParameter().connectT(0, add);                           // smoothed_parameter -> add::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, smoothed_parameter); // cable_pack -> smoothed_parameter::Value
		bipolar.getWrappedObject().getParameter().connectT(0, cable_pack);            // bipolar -> cable_pack::Value
		ramp.getParameter().connectT(0, bipolar);                                     // ramp -> bipolar::Value
		tempo_sync.getParameter().connectT(0, ramp);                                  // tempo_sync -> ramp::PeriodTime
		
		// Default Values --------------------------------------------------------------------------
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		; // bipolar::Value is automated
		; // bipolar::Scale is automated
		; // bipolar::Gamma is automated
		
		; // cable_pack::Value is automated
		
		;                                        // smoothed_parameter::Value is automated
		;                                        // smoothed_parameter::SmoothingTime is automated
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // add::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.);
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(1).setExternalData(b, index); // DspNetwork_impl::ramp_t<NV>
		this->getT(2).setExternalData(b, index);         // DspNetwork_impl::cable_pack_t<NV>
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
using DspNetwork = wrap::node<DspNetwork_impl::instance<NV>>;
}


