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

namespace ENV_impl
{
// =======================| Node & Parameter type declarations |=======================

template <int NV>
using flex_ahdsr_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                            parameter::empty>;

template <int NV>
using flex_ahdsr_t = wrap::data<envelope::flex_ahdsr<NV, flex_ahdsr_multimod<NV>>, 
                                data::external::displaybuffer<0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, flex_ahdsr_t<NV>>, 
                                  math::add<NV>>;

namespace ENV_t_parameters
{
// Parameter list for ENV_impl::ENV_t ------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(Loop_InputRange, 
                             0., 
                             1., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Loop_0Range, 
                             1., 
                             2., 
                             1.);

template <int NV>
using Loop_0 = parameter::from0To1<ENV_impl::flex_ahdsr_t<NV>, 
                                   5, 
                                   Loop_0Range>;

template <int NV>
using Loop = parameter::chain<Loop_InputRange, Loop_0<NV>>;

template <int NV>
using A = parameter::plain<ENV_impl::flex_ahdsr_t<NV>, 
                           0>;
template <int NV>
using D = parameter::plain<ENV_impl::flex_ahdsr_t<NV>, 
                           2>;
template <int NV>
using S = parameter::plain<ENV_impl::flex_ahdsr_t<NV>, 
                           3>;
template <int NV>
using R = parameter::plain<ENV_impl::flex_ahdsr_t<NV>, 
                           4>;
template <int NV>
using ENV_t_plist = parameter::list<A<NV>, 
                                    D<NV>, 
                                    S<NV>, 
                                    R<NV>, 
                                    Loop<NV>>;
}

template <int NV>
using ENV_t_ = container::chain<ENV_t_parameters::ENV_t_plist<NV>, 
                                wrap::fix<1, chain5_t<NV>>>;

// ==========================| Root node initialiser class |==========================

template <int NV> struct instance: public ENV_impl::ENV_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(ENV);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(76)
		{
			0x025C, 0x0000, 0x0000, 0x0041, 0x0000, 0x0000, 0x0000, 0xEA60, 
            0x0046, 0x8000, 0xEE3F, 0x830C, 0x003E, 0x0000, 0x5C00, 0x0102, 
            0x0000, 0x4400, 0x0000, 0x0000, 0x0000, 0x6000, 0x46EA, 0x16E4, 
            0x4640, 0x0CEE, 0x3E83, 0x0000, 0x0000, 0x005C, 0x0002, 0x0000, 
            0x0053, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x0302, 0x0000, 0x5200, 0x0000, 
            0x0000, 0x0000, 0x6000, 0x46EA, 0xC000, 0x4512, 0x0CEE, 0x3E83, 
            0x0000, 0x0000, 0x005C, 0x0004, 0x0000, 0x6F4C, 0x706F, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -----------------------------------------------------------
		
		auto& chain5 = this->getT(0);             // ENV_impl::chain5_t<NV>
		auto& flex_ahdsr = this->getT(0).getT(0); // ENV_impl::flex_ahdsr_t<NV>
		auto& add8 = this->getT(0).getT(1);       // math::add<NV>
		
		// Parameter Connections -----------------------------------------------------
		
		this->getParameterT(0).connectT(0, flex_ahdsr); // A -> flex_ahdsr::Attack
		
		this->getParameterT(1).connectT(0, flex_ahdsr); // D -> flex_ahdsr::Decay
		
		this->getParameterT(2).connectT(0, flex_ahdsr); // S -> flex_ahdsr::Sustain
		
		this->getParameterT(3).connectT(0, flex_ahdsr); // R -> flex_ahdsr::Release
		
		this->getParameterT(4).connectT(0, flex_ahdsr); // Loop -> flex_ahdsr::Mode
		
		// Modulation Connections ----------------------------------------------------
		
		auto& flex_ahdsr_p = flex_ahdsr.getWrappedObject().getParameter();
		flex_ahdsr_p.getParameterT(0).connectT(0, add8); // flex_ahdsr -> add8::Value
		
		// Default Values ------------------------------------------------------------
		
		;                                      // flex_ahdsr::Attack is automated
		flex_ahdsr.setParameterT(1, 0.);       // envelope::flex_ahdsr::Hold
		;                                      // flex_ahdsr::Decay is automated
		;                                      // flex_ahdsr::Sustain is automated
		;                                      // flex_ahdsr::Release is automated
		;                                      // flex_ahdsr::Mode is automated
		flex_ahdsr.setParameterT(6, 1.);       // envelope::flex_ahdsr::AttackLevel
		flex_ahdsr.setParameterT(7, 0.311111); // envelope::flex_ahdsr::AttackCurve
		flex_ahdsr.setParameterT(8, 0.516667); // envelope::flex_ahdsr::DecayCurve
		flex_ahdsr.setParameterT(9, 0.1);      // envelope::flex_ahdsr::ReleaseCurve
		
		; // add8::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 12293.7);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 2348.);
		this->setParameterT(4, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references ------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections -------------------------------------------------
		
		this->getT(0).getT(0).setExternalData(b, index); // ENV_impl::flex_ahdsr_t<NV>
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ===============================| Public Definition |===============================

namespace project
{
// polyphonic template declaration

template <int NV>
using ENV = wrap::node<ENV_impl::instance<NV>>;
}


