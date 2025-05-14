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
// ==============================| Node & Parameter type declarations |==============================

using global_cable64_t_index = runtime_target::indexers::fix_hash<1120565314>;

template <int NV>
using global_cable64_t = routing::global_cable<global_cable64_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain81_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable64_t<NV>>, 
                                   math::add<NV>>;
using global_cable65_t_index = runtime_target::indexers::fix_hash<1120565315>;

template <int NV>
using global_cable65_t = routing::global_cable<global_cable65_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain82_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable65_t<NV>>, 
                                   math::add<NV>>;
using global_cable66_t_index = runtime_target::indexers::fix_hash<1120565316>;

template <int NV>
using global_cable66_t = routing::global_cable<global_cable66_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable66_t<NV>>, 
                                   math::add<NV>>;
using global_cable67_t_index = runtime_target::indexers::fix_hash<1120565317>;

template <int NV>
using global_cable67_t = routing::global_cable<global_cable67_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain84_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable67_t<NV>>, 
                                   math::add<NV>>;
using global_cable68_t_index = runtime_target::indexers::fix_hash<1120565318>;

template <int NV>
using global_cable68_t = routing::global_cable<global_cable68_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain85_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable68_t<NV>>, 
                                   math::add<NV>>;
using global_cable69_t_index = runtime_target::indexers::fix_hash<1120565319>;

template <int NV>
using global_cable69_t = routing::global_cable<global_cable69_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain86_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable69_t<NV>>, 
                                   math::add<NV>>;
using global_cable70_t_index = runtime_target::indexers::fix_hash<1120565320>;

template <int NV>
using global_cable70_t = routing::global_cable<global_cable70_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain87_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable70_t<NV>>, 
                                   math::add<NV>>;
using global_cable71_t_index = runtime_target::indexers::fix_hash<1120565321>;

template <int NV>
using global_cable71_t = routing::global_cable<global_cable71_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain88_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable71_t<NV>>, 
                                   math::add<NV>>;
using global_cable72_t_index = runtime_target::indexers::fix_hash<1120565322>;

template <int NV>
using global_cable72_t = routing::global_cable<global_cable72_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain89_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable72_t<NV>>, 
                                   math::add<NV>>;
using global_cable73_t_index = runtime_target::indexers::fix_hash<377786414>;

template <int NV>
using global_cable73_t = routing::global_cable<global_cable73_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable73_t<NV>>, 
                                   math::add<NV>>;
using global_cable74_t_index = runtime_target::indexers::fix_hash<377786415>;

template <int NV>
using global_cable74_t = routing::global_cable<global_cable74_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain91_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable74_t<NV>>, 
                                   math::add<NV>>;
using global_cable75_t_index = runtime_target::indexers::fix_hash<377786416>;

template <int NV>
using global_cable75_t = routing::global_cable<global_cable75_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain92_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable75_t<NV>>, 
                                   math::add<NV>>;
using global_cable76_t_index = runtime_target::indexers::fix_hash<377786417>;

template <int NV>
using global_cable76_t = routing::global_cable<global_cable76_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain93_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable76_t<NV>>, 
                                   math::add<NV>>;
using global_cable77_t_index = runtime_target::indexers::fix_hash<377786418>;

template <int NV>
using chain94_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable77_t_index, parameter::empty>>, 
                                   math::add<NV>>;
using global_cable78_t_index = runtime_target::indexers::fix_hash<377786419>;

template <int NV>
using global_cable78_t = routing::global_cable<global_cable78_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain95_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable78_t<NV>>, 
                                   math::add<NV>>;
using global_cable79_t_index = runtime_target::indexers::fix_hash<377786420>;

template <int NV>
using global_cable79_t = routing::global_cable<global_cable79_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain96_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable79_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain81_t<NV>>, 
                                    chain82_t<NV>, 
                                    chain83_t<NV>, 
                                    chain84_t<NV>, 
                                    chain85_t<NV>, 
                                    chain86_t<NV>, 
                                    chain87_t<NV>, 
                                    chain88_t<NV>, 
                                    chain89_t<NV>, 
                                    chain90_t<NV>, 
                                    chain91_t<NV>, 
                                    chain92_t<NV>, 
                                    chain93_t<NV>, 
                                    chain94_t<NV>, 
                                    chain95_t<NV>, 
                                    chain96_t<NV>>;

template <int NV>
using pma12_t = control::pma<NV, 
                             parameter::plain<math::add<NV>, 0>>;
template <int NV>
using peak6_t = wrap::mod<parameter::plain<pma12_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

namespace MacroMod_t_parameters
{
// Parameter list for MacroMod_impl::MacroMod_t ----------------------------------------------------

DECLARE_PARAMETER_RANGE(modRange, 
                        -1., 
                        1.);

template <int NV>
using mod = parameter::from0To1<MacroMod_impl::pma12_t<NV>, 
                                1, 
                                modRange>;

DECLARE_PARAMETER_RANGE_STEP(src_InputRange, 
                             1., 
                             16., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(src_0Range, 
                             0., 
                             15., 
                             1.);

template <int NV>
using src_0 = parameter::from0To1<MacroMod_impl::branch4_t<NV>, 
                                  0, 
                                  src_0Range>;

template <int NV>
using src = parameter::chain<src_InputRange, src_0<NV>>;

template <int NV>
using macro = parameter::plain<MacroMod_impl::pma12_t<NV>, 
                               2>;
template <int NV>
using MacroMod_t_plist = parameter::list<mod<NV>, 
                                         src<NV>, 
                                         macro<NV>>;
}

template <int NV>
using MacroMod_t_ = container::chain<MacroMod_t_parameters::MacroMod_t_plist<NV>, 
                                     wrap::fix<1, math::clear<NV>>, 
                                     branch4_t<NV>, 
                                     peak6_t<NV>, 
                                     pma12_t<NV>, 
                                     math::add<NV>>;

// =================================| Root node initialiser class |=================================

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
		SNEX_METADATA_ENCODED_PARAMETERS(46)
		{
			0x005B, 0x0000, 0x6D00, 0x646F, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x7273, 0x0063, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x025B, 0x0000, 0x6D00, 
            0x6361, 0x6F72, 0x0000, 0x4000, 0x0026, 0x8000, 0x003F, 0x4000, 
            0x0026, 0x8000, 0x003F, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& clear7 = this->getT(0);                          // math::clear<NV>
		auto& branch4 = this->getT(1);                         // MacroMod_impl::branch4_t<NV>
		auto& chain81 = this->getT(1).getT(0);                 // MacroMod_impl::chain81_t<NV>
		auto& global_cable64 = this->getT(1).getT(0).getT(0);  // MacroMod_impl::global_cable64_t<NV>
		auto& add58 = this->getT(1).getT(0).getT(1);           // math::add<NV>
		auto& chain82 = this->getT(1).getT(1);                 // MacroMod_impl::chain82_t<NV>
		auto& global_cable65 = this->getT(1).getT(1).getT(0);  // MacroMod_impl::global_cable65_t<NV>
		auto& add59 = this->getT(1).getT(1).getT(1);           // math::add<NV>
		auto& chain83 = this->getT(1).getT(2);                 // MacroMod_impl::chain83_t<NV>
		auto& global_cable66 = this->getT(1).getT(2).getT(0);  // MacroMod_impl::global_cable66_t<NV>
		auto& add60 = this->getT(1).getT(2).getT(1);           // math::add<NV>
		auto& chain84 = this->getT(1).getT(3);                 // MacroMod_impl::chain84_t<NV>
		auto& global_cable67 = this->getT(1).getT(3).getT(0);  // MacroMod_impl::global_cable67_t<NV>
		auto& add61 = this->getT(1).getT(3).getT(1);           // math::add<NV>
		auto& chain85 = this->getT(1).getT(4);                 // MacroMod_impl::chain85_t<NV>
		auto& global_cable68 = this->getT(1).getT(4).getT(0);  // MacroMod_impl::global_cable68_t<NV>
		auto& add62 = this->getT(1).getT(4).getT(1);           // math::add<NV>
		auto& chain86 = this->getT(1).getT(5);                 // MacroMod_impl::chain86_t<NV>
		auto& global_cable69 = this->getT(1).getT(5).getT(0);  // MacroMod_impl::global_cable69_t<NV>
		auto& add63 = this->getT(1).getT(5).getT(1);           // math::add<NV>
		auto& chain87 = this->getT(1).getT(6);                 // MacroMod_impl::chain87_t<NV>
		auto& global_cable70 = this->getT(1).getT(6).getT(0);  // MacroMod_impl::global_cable70_t<NV>
		auto& add64 = this->getT(1).getT(6).getT(1);           // math::add<NV>
		auto& chain88 = this->getT(1).getT(7);                 // MacroMod_impl::chain88_t<NV>
		auto& global_cable71 = this->getT(1).getT(7).getT(0);  // MacroMod_impl::global_cable71_t<NV>
		auto& add65 = this->getT(1).getT(7).getT(1);           // math::add<NV>
		auto& chain89 = this->getT(1).getT(8);                 // MacroMod_impl::chain89_t<NV>
		auto& global_cable72 = this->getT(1).getT(8).getT(0);  // MacroMod_impl::global_cable72_t<NV>
		auto& add66 = this->getT(1).getT(8).getT(1);           // math::add<NV>
		auto& chain90 = this->getT(1).getT(9);                 // MacroMod_impl::chain90_t<NV>
		auto& global_cable73 = this->getT(1).getT(9).getT(0);  // MacroMod_impl::global_cable73_t<NV>
		auto& add67 = this->getT(1).getT(9).getT(1);           // math::add<NV>
		auto& chain91 = this->getT(1).getT(10);                // MacroMod_impl::chain91_t<NV>
		auto& global_cable74 = this->getT(1).getT(10).getT(0); // MacroMod_impl::global_cable74_t<NV>
		auto& add68 = this->getT(1).getT(10).getT(1);          // math::add<NV>
		auto& chain92 = this->getT(1).getT(11);                // MacroMod_impl::chain92_t<NV>
		auto& global_cable75 = this->getT(1).getT(11).getT(0); // MacroMod_impl::global_cable75_t<NV>
		auto& add69 = this->getT(1).getT(11).getT(1);          // math::add<NV>
		auto& chain93 = this->getT(1).getT(12);                // MacroMod_impl::chain93_t<NV>
		auto& global_cable76 = this->getT(1).getT(12).getT(0); // MacroMod_impl::global_cable76_t<NV>
		auto& add70 = this->getT(1).getT(12).getT(1);          // math::add<NV>
		auto& chain94 = this->getT(1).getT(13);                // MacroMod_impl::chain94_t<NV>
		auto& global_cable77 = this->getT(1).getT(13).getT(0); // routing::global_cable<global_cable77_t_index, parameter::empty>
		auto& add71 = this->getT(1).getT(13).getT(1);          // math::add<NV>
		auto& chain95 = this->getT(1).getT(14);                // MacroMod_impl::chain95_t<NV>
		auto& global_cable78 = this->getT(1).getT(14).getT(0); // MacroMod_impl::global_cable78_t<NV>
		auto& add72 = this->getT(1).getT(14).getT(1);          // math::add<NV>
		auto& chain96 = this->getT(1).getT(15);                // MacroMod_impl::chain96_t<NV>
		auto& global_cable79 = this->getT(1).getT(15).getT(0); // MacroMod_impl::global_cable79_t<NV>
		auto& add73 = this->getT(1).getT(15).getT(1);          // math::add<NV>
		auto& peak6 = this->getT(2);                           // MacroMod_impl::peak6_t<NV>
		auto& pma12 = this->getT(3);                           // MacroMod_impl::pma12_t<NV>
		auto& add = this->getT(4);                             // math::add<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma12); // mod -> pma12::Multiply
		
		this->getParameterT(1).connectT(0, branch4); // src -> branch4::Index
		
		this->getParameterT(2).connectT(0, pma12); // macro -> pma12::Add
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable64.getWrappedObject().getParameter().connectT(0, add58); // global_cable64 -> add58::Value
		global_cable65.getWrappedObject().getParameter().connectT(0, add59); // global_cable65 -> add59::Value
		global_cable66.getWrappedObject().getParameter().connectT(0, add60); // global_cable66 -> add60::Value
		global_cable67.getWrappedObject().getParameter().connectT(0, add61); // global_cable67 -> add61::Value
		global_cable68.getWrappedObject().getParameter().connectT(0, add62); // global_cable68 -> add62::Value
		global_cable69.getWrappedObject().getParameter().connectT(0, add63); // global_cable69 -> add63::Value
		global_cable70.getWrappedObject().getParameter().connectT(0, add64); // global_cable70 -> add64::Value
		global_cable71.getWrappedObject().getParameter().connectT(0, add65); // global_cable71 -> add65::Value
		global_cable72.getWrappedObject().getParameter().connectT(0, add66); // global_cable72 -> add66::Value
		global_cable73.getWrappedObject().getParameter().connectT(0, add67); // global_cable73 -> add67::Value
		global_cable74.getWrappedObject().getParameter().connectT(0, add68); // global_cable74 -> add68::Value
		global_cable75.getWrappedObject().getParameter().connectT(0, add69); // global_cable75 -> add69::Value
		global_cable76.getWrappedObject().getParameter().connectT(0, add70); // global_cable76 -> add70::Value
		global_cable78.getWrappedObject().getParameter().connectT(0, add72); // global_cable78 -> add72::Value
		global_cable79.getWrappedObject().getParameter().connectT(0, add73); // global_cable79 -> add73::Value
		pma12.getWrappedObject().getParameter().connectT(0, add);            // pma12 -> add::Value
		peak6.getParameter().connectT(0, pma12);                             // peak6 -> pma12::Value
		
		// Default Values --------------------------------------------------------------------------
		
		clear7.setParameterT(0, 0.); // math::clear::Value
		
		; // branch4::Index is automated
		
		global_cable64.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add58::Value is automated
		
		global_cable65.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add59::Value is automated
		
		global_cable66.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add60::Value is automated
		
		global_cable67.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add61::Value is automated
		
		global_cable68.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add62::Value is automated
		
		global_cable69.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add63::Value is automated
		
		global_cable70.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add64::Value is automated
		
		global_cable71.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add65::Value is automated
		
		global_cable72.setParameterT(0, 0.998024); // routing::global_cable::Value
		
		; // add66::Value is automated
		
		global_cable73.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add67::Value is automated
		
		global_cable74.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add68::Value is automated
		
		global_cable75.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add69::Value is automated
		
		global_cable76.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add70::Value is automated
		
		global_cable77.setParameterT(0, 1.); // routing::global_cable::Value
		
		add71.setParameterT(0, 0.); // math::add::Value
		
		global_cable78.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add72::Value is automated
		
		global_cable79.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add73::Value is automated
		
		; // pma12::Value is automated
		; // pma12::Multiply is automated
		; // pma12::Add is automated
		
		; // add::Value is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 6.66134e-16);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // MacroMod_impl::global_cable64_t<NV>
		this->getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // MacroMod_impl::global_cable65_t<NV>
		this->getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // MacroMod_impl::global_cable66_t<NV>
		this->getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // MacroMod_impl::global_cable67_t<NV>
		this->getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // MacroMod_impl::global_cable68_t<NV>
		this->getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // MacroMod_impl::global_cable69_t<NV>
		this->getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // MacroMod_impl::global_cable70_t<NV>
		this->getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // MacroMod_impl::global_cable71_t<NV>
		this->getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // MacroMod_impl::global_cable72_t<NV>
		this->getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // MacroMod_impl::global_cable73_t<NV>
		this->getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // MacroMod_impl::global_cable74_t<NV>
		this->getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // MacroMod_impl::global_cable75_t<NV>
		this->getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // MacroMod_impl::global_cable76_t<NV>
		this->getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable77_t_index, parameter::empty>
		this->getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // MacroMod_impl::global_cable78_t<NV>
		this->getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // MacroMod_impl::global_cable79_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(2).setExternalData(b, index); // MacroMod_impl::peak6_t<NV>
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
using MacroMod = wrap::node<MacroMod_impl::instance<NV>>;
}


