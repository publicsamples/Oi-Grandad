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

namespace OutMods_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable_t_index = runtime_target::indexers::fix_hash<2615364>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable_t<NV>>, 
                                  math::add<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<2615365>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>>;
using global_cable9_t_index = runtime_target::indexers::fix_hash<2615366>;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable9_t<NV>>, 
                                  math::add<NV>>;
using global_cable8_t_index = runtime_target::indexers::fix_hash<2615367>;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable8_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain7_t<NV>>, 
                                    chain10_t<NV>, 
                                    chain9_t<NV>, 
                                    chain8_t<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::pi<NV>>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::pi<NV>>, 
                                   math::rect<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain6_t<NV>>, 
                                    chain11_t<NV>>;

template <int NV>
using ahdsr_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                       parameter::empty>;

template <int NV>
using ahdsr_t = wrap::data<envelope::ahdsr<NV, ahdsr_multimod<NV>>, 
                           data::external::displaybuffer<2>>;
DECLARE_PARAMETER_RANGE_STEP(peak_modRange, 
                             0., 
                             1., 
                             1.);

template <int NV>
using peak_mod = parameter::from0To1<ahdsr_t<NV>, 
                                     8, 
                                     peak_modRange>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::data<core::peak, data::external::displaybuffer<1>>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, branch2_t<NV>>, 
                                    branch1_t<NV>, 
                                    peak_t<NV>, 
                                    wrap::no_process<math::clear<NV>>, 
                                    ahdsr_t<NV>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, no_midi_t<NV>>, 
                                       math::add<NV>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

namespace OutMods_t_parameters
{
// Parameter list for OutMods_impl::OutMods_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(Input_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Input_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using Input_0 = parameter::from0To1<OutMods_impl::branch2_t<NV>, 
                                    0, 
                                    Input_0Range>;

template <int NV>
using Input = parameter::chain<Input_InputRange, Input_0<NV>>;

using Output = parameter::empty;
template <int NV>
using A = parameter::plain<OutMods_impl::ahdsr_t<NV>, 
                           0>;
template <int NV>
using D = parameter::plain<OutMods_impl::ahdsr_t<NV>, 
                           3>;
template <int NV>
using S = parameter::plain<OutMods_impl::ahdsr_t<NV>, 
                           4>;
template <int NV>
using R = parameter::plain<OutMods_impl::ahdsr_t<NV>, 
                           5>;
template <int NV>
using TrigPeak = parameter::plain<OutMods_impl::branch1_t<NV>, 
                                  0>;
template <int NV>
using OutMods_t_plist = parameter::list<Input<NV>, 
                                        Output, 
                                        A<NV>, 
                                        D<NV>, 
                                        S<NV>, 
                                        R<NV>, 
                                        TrigPeak<NV>>;
}

template <int NV>
using OutMods_t_ = container::chain<OutMods_t_parameters::OutMods_t_plist<NV>, 
                                    wrap::fix<1, fix8_block_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public OutMods_impl::OutMods_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 3;
		
		SNEX_METADATA_ID(OutMods);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(110)
		{
			0x005C, 0x0000, 0x0000, 0x6E49, 0x7570, 0x0074, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x0100, 0x0000, 0x4F00, 0x7475, 0x7570, 0x0074, 0x0000, 
            0x0000, 0x0000, 0x4000, 0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x0202, 0x0000, 0x4100, 0x0000, 0x0000, 0x0000, 
            0xC19A, 0x459B, 0x0000, 0x4040, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 
            0x025C, 0x0003, 0x0000, 0x0044, 0x0000, 0x0000, 0x0000, 0x9C40, 
            0x0045, 0xAB80, 0x7243, 0x4A6A, 0xCD3E, 0xCCCC, 0x5C3D, 0x0400, 
            0x0000, 0x5300, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025C, 0x0005, 0x0000, 
            0x0052, 0x0000, 0x0000, 0x0000, 0x9C40, 0x0045, 0x0000, 0x7200, 
            0x4A6A, 0xCD3E, 0xCCCC, 0x5C3D, 0x0600, 0x0000, 0x5400, 0x6972, 
            0x5067, 0x6165, 0x006B, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block = this->getT(0);                                     // OutMods_impl::fix8_block_t<NV>
		auto& no_midi = this->getT(0).getT(0);                                // OutMods_impl::no_midi_t<NV>
		auto& branch2 = this->getT(0).getT(0).getT(0);                        // OutMods_impl::branch2_t<NV>
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(0);                 // OutMods_impl::chain7_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(0).getT(0).getT(0);   // OutMods_impl::global_cable_t<NV>
		auto& add = this->getT(0).getT(0).getT(0).getT(0).getT(1);            // math::add<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(1);                // OutMods_impl::chain10_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(0).getT(1).getT(0); // OutMods_impl::global_cable10_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(2);                 // OutMods_impl::chain9_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(0).getT(2).getT(0);  // OutMods_impl::global_cable9_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(3);                 // OutMods_impl::chain8_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(0).getT(3).getT(0);  // OutMods_impl::global_cable8_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& branch1 = this->getT(0).getT(0).getT(1);                        // OutMods_impl::branch1_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(1).getT(0);                 // OutMods_impl::chain6_t<NV>
		auto& pi = this->getT(0).getT(0).getT(1).getT(0).getT(0);             // math::pi<NV>
		auto& chain11 = this->getT(0).getT(0).getT(1).getT(1);                // OutMods_impl::chain11_t<NV>
		auto& pi1 = this->getT(0).getT(0).getT(1).getT(1).getT(0);            // math::pi<NV>
		auto& rect = this->getT(0).getT(0).getT(1).getT(1).getT(1);           // math::rect<NV>
		auto& peak = this->getT(0).getT(0).getT(2);                           // OutMods_impl::peak_t<NV>
		auto& clear = this->getT(0).getT(0).getT(3);                          // wrap::no_process<math::clear<NV>>
		auto& ahdsr = this->getT(0).getT(0).getT(4);                          // OutMods_impl::ahdsr_t<NV>
		auto& add4 = this->getT(0).getT(1);                                   // math::add<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, branch2); // Input -> branch2::Index
		
		this->getParameterT(2).connectT(0, ahdsr); // A -> ahdsr::Attack
		
		this->getParameterT(3).connectT(0, ahdsr); // D -> ahdsr::Decay
		
		this->getParameterT(4).connectT(0, ahdsr); // S -> ahdsr::Sustain
		
		this->getParameterT(5).connectT(0, ahdsr); // R -> ahdsr::Release
		
		this->getParameterT(6).connectT(0, branch1); // TrigPeak -> branch1::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable.getWrappedObject().getParameter().connectT(0, add);    // global_cable -> add::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add7); // global_cable10 -> add7::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, add6);  // global_cable9 -> add6::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add5);  // global_cable8 -> add5::Value
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, add4); // ahdsr -> add4::Value
		peak.getParameter().connectT(0, ahdsr);     // peak -> ahdsr::Gate
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch2::Index is automated
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		; // branch1::Index is automated
		
		pi.setParameterT(0, 2.); // math::pi::Value
		
		pi1.setParameterT(0, 2.); // math::pi::Value
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                                 // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);       // envelope::ahdsr::AttackLevel
		ahdsr.setParameterT(2, 0.);       // envelope::ahdsr::Hold
		;                                 // ahdsr::Decay is automated
		;                                 // ahdsr::Sustain is automated
		;                                 // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.532531); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);       // envelope::ahdsr::Retrigger
		;                                 // ahdsr::Gate is automated
		
		; // add4::Value is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 3);
		this->setParameterT(3, 343.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 1.);
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
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // OutMods_impl::global_cable_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // OutMods_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // OutMods_impl::global_cable9_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // OutMods_impl::global_cable8_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(2).setExternalData(b, index); // OutMods_impl::peak_t<NV>
		this->getT(0).getT(0).getT(4).setExternalData(b, index); // OutMods_impl::ahdsr_t<NV>
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
using OutMods = wrap::node<OutMods_impl::instance<NV>>;
}


