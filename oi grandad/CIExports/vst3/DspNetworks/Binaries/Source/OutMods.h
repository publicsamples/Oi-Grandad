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

using global_cable_t_index = runtime_target::indexers::fix_hash<162771259>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable_t<NV>>, 
                                  math::add<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<162771260>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>>;
using global_cable9_t_index = runtime_target::indexers::fix_hash<162771261>;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable9_t<NV>>, 
                                  math::add<NV>>;
using global_cable8_t_index = runtime_target::indexers::fix_hash<162771262>;

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

using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::empty>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain6_t>, 
                                    math::rect<NV>>;

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
                                    math::clear<NV>, 
                                    ahdsr_t<NV>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, no_midi_t<NV>>, 
                                  math::add<NV>>;

template <int NV> using flex_ahdsr_multimod = ahdsr_multimod<NV>;

template <int NV>
using flex_ahdsr_t = wrap::data<envelope::flex_ahdsr<NV, flex_ahdsr_multimod<NV>>, 
                                data::external::displaybuffer<0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, flex_ahdsr_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain4_t<NV>>, 
                                   chain5_t<NV>>;

using global_cable1_t_index = runtime_target::indexers::fix_hash<377786417>;

template <int NV>
using peak4_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<routing::event_data_writer<NV>, 1>, 
                                   parameter::plain<routing::global_cable<global_cable1_t_index, parameter::empty>, 0>>;

template <int NV>
using peak4_t = wrap::mod<peak4_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak4_t<NV>>, 
                                   routing::event_data_writer<NV>, 
                                   routing::global_cable<global_cable1_t_index, parameter::empty>>;

using global_cable2_t_index = runtime_target::indexers::fix_hash<377786418>;

template <int NV>
using peak7_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<routing::event_data_writer<NV>, 1>, 
                                   parameter::plain<routing::global_cable<global_cable2_t_index, parameter::empty>, 0>>;

template <int NV>
using peak7_t = wrap::mod<peak7_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak7_t<NV>>, 
                                   routing::event_data_writer<NV>, 
                                   routing::global_cable<global_cable2_t_index, parameter::empty>>;

using global_cable3_t_index = runtime_target::indexers::fix_hash<377786419>;

template <int NV>
using peak6_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<routing::event_data_writer<NV>, 1>, 
                                   parameter::plain<routing::global_cable<global_cable3_t_index, parameter::empty>, 0>>;

template <int NV>
using peak6_t = wrap::mod<peak6_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak6_t<NV>>, 
                                   routing::event_data_writer<NV>, 
                                   routing::global_cable<global_cable3_t_index, parameter::empty>>;

using global_cable4_t_index = global_cable2_t_index;

template <int NV>
using peak5_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<routing::event_data_writer<NV>, 1>, 
                                   parameter::plain<routing::global_cable<global_cable4_t_index, parameter::empty>, 0>>;

template <int NV>
using peak5_t = wrap::mod<peak5_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak5_t<NV>>, 
                                   routing::event_data_writer<NV>, 
                                   routing::global_cable<global_cable4_t_index, parameter::empty>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain11_t<NV>>, 
                                    chain14_t<NV>, 
                                    chain13_t<NV>, 
                                    chain12_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, branch_t<NV>>, 
                                 branch3_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain_t<NV>>>;

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

DECLARE_PARAMETER_RANGE_SKEW(A_InputRange, 
                             0., 
                             30000., 
                             0.255958);
DECLARE_PARAMETER_RANGE_SKEW(A_0Range, 
                             0., 
                             30000., 
                             0.255958);

template <int NV>
using A_0 = parameter::from0To1<OutMods_impl::flex_ahdsr_t<NV>, 
                                0, 
                                A_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(A_1Range, 
                             0., 
                             10000., 
                             0.197672);

template <int NV>
using A_1 = parameter::from0To1<OutMods_impl::ahdsr_t<NV>, 
                                0, 
                                A_1Range>;

template <int NV>
using A = parameter::chain<A_InputRange, 
                           A_0<NV>, 
                           A_1<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(D_InputRange, 
                             0., 
                             30000., 
                             0.255958);
template <int NV>
using D_0 = parameter::from0To1<OutMods_impl::flex_ahdsr_t<NV>, 
                                2, 
                                A_0Range>;

template <int NV>
using D_1 = parameter::from0To1<OutMods_impl::ahdsr_t<NV>, 
                                3, 
                                A_1Range>;

template <int NV>
using D = parameter::chain<D_InputRange, 
                           D_0<NV>, 
                           D_1<NV>>;

template <int NV>
using S = parameter::chain<ranges::Identity, 
                           parameter::plain<OutMods_impl::flex_ahdsr_t<NV>, 3>, 
                           parameter::plain<OutMods_impl::ahdsr_t<NV>, 4>>;

DECLARE_PARAMETER_RANGE_SKEW(R_InputRange, 
                             0., 
                             30000., 
                             0.255958);
template <int NV>
using R_0 = parameter::from0To1<OutMods_impl::flex_ahdsr_t<NV>, 
                                4, 
                                A_0Range>;

template <int NV>
using R_1 = parameter::from0To1<OutMods_impl::ahdsr_t<NV>, 
                                5, 
                                A_1Range>;

template <int NV>
using R = parameter::chain<R_InputRange, 
                           R_0<NV>, 
                           R_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Loop_InputRange, 
                             0., 
                             1., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Loop_0Range, 
                             1., 
                             2., 
                             1.);

template <int NV>
using Loop_0 = parameter::from0To1<OutMods_impl::flex_ahdsr_t<NV>, 
                                   5, 
                                   Loop_0Range>;

template <int NV>
using Loop = parameter::chain<Loop_InputRange, Loop_0<NV>>;

template <int NV>
using TrigPeak = parameter::from0To1<OutMods_impl::branch1_t<NV>, 
                                     0, 
                                     OutMods_impl::peak_modRange>;

template <int NV>
using Mode = parameter::from0To1<OutMods_impl::branch_t<NV>, 
                                 0, 
                                 OutMods_impl::peak_modRange>;

template <int NV>
using Output = parameter::plain<OutMods_impl::branch3_t<NV>, 
                                0>;
template <int NV>
using OutMods_t_plist = parameter::list<Input<NV>, 
                                        Output<NV>, 
                                        A<NV>, 
                                        D<NV>, 
                                        S<NV>, 
                                        R<NV>, 
                                        Loop<NV>, 
                                        TrigPeak<NV>, 
                                        Mode<NV>>;
}

template <int NV>
using OutMods_t_ = container::chain<OutMods_t_parameters::OutMods_t_plist<NV>, 
                                    wrap::fix<1, split_t<NV>>>;

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
		SNEX_METADATA_ENCODED_PARAMETERS(142)
		{
			0x005C, 0x0000, 0x0000, 0x6E49, 0x7570, 0x0074, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0040, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x0100, 0x0000, 0x4F00, 0x7475, 0x7570, 0x0074, 0x0000, 
            0x0000, 0x0000, 0x4000, 0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x0202, 0x0000, 0x4100, 0x0000, 0x0000, 0x0000, 
            0x6000, 0x46EA, 0x0000, 0x0000, 0x0CEE, 0x3E83, 0x0000, 0x0000, 
            0x025C, 0x0003, 0x0000, 0x0044, 0x0000, 0x0000, 0x0000, 0xEA60, 
            0x0046, 0xEA60, 0xEE46, 0x830C, 0x003E, 0x0000, 0x5C00, 0x0400, 
            0x0000, 0x5300, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025C, 0x0005, 0x0000, 
            0x0052, 0x0000, 0x0000, 0x0000, 0xEA60, 0x0046, 0x17CC, 0xEE46, 
            0x830C, 0x003E, 0x0000, 0x5C00, 0x0600, 0x0000, 0x4C00, 0x6F6F, 
            0x0070, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x5C3F, 0x0700, 0x0000, 0x5400, 0x6972, 
            0x5067, 0x6165, 0x006B, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0800, 0x0000, 
            0x4D00, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split = this->getT(0);                                                   // OutMods_impl::split_t<NV>
		auto& chain = this->getT(0).getT(0);                                           // OutMods_impl::chain_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0);                                  // OutMods_impl::branch_t<NV>
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(0);                          // OutMods_impl::chain4_t<NV>
		auto& no_midi = this->getT(0).getT(0).getT(0).getT(0).getT(0);                 // OutMods_impl::no_midi_t<NV>
		auto& branch2 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);         // OutMods_impl::branch2_t<NV>
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);  // OutMods_impl::chain7_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(0).getT(0).                    // OutMods_impl::global_cable_t<NV>
                             getT(0).getT(0).getT(0).getT(0);
		auto& add = this->getT(0).getT(0).getT(0).getT(0).                             // math::add<NV>
                    getT(0).getT(0).getT(0).getT(1);
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(1); // OutMods_impl::chain10_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(0).getT(0).                  // OutMods_impl::global_cable10_t<NV>
                               getT(0).getT(0).getT(1).getT(0);
		auto& add7 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                     getT(0).getT(0).getT(1).getT(1);
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(2); // OutMods_impl::chain9_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(0).getT(0).                  // OutMods_impl::global_cable9_t<NV>
                              getT(0).getT(0).getT(2).getT(0);
		auto& add6 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                     getT(0).getT(0).getT(2).getT(1);
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(3); // OutMods_impl::chain8_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(0).getT(0).                  // OutMods_impl::global_cable8_t<NV>
                              getT(0).getT(0).getT(3).getT(0);
		auto& add5 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                     getT(0).getT(0).getT(3).getT(1);
		auto& branch1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);        // OutMods_impl::branch1_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0); // OutMods_impl::chain6_t
		auto& rect = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);   // math::rect<NV>
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);           // OutMods_impl::peak_t<NV>
		auto& clear = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3);          // math::clear<NV>
		auto& ahdsr = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4);          // OutMods_impl::ahdsr_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                   // math::add<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(1);                         // OutMods_impl::chain5_t<NV>
		auto& flex_ahdsr = this->getT(0).getT(0).getT(0).getT(1).getT(0);             // OutMods_impl::flex_ahdsr_t<NV>
		auto& add8 = this->getT(0).getT(0).getT(0).getT(1).getT(1);                   // math::add<NV>
		auto& branch3 = this->getT(0).getT(0).getT(1);                                // OutMods_impl::branch3_t<NV>
		auto& chain11 = this->getT(0).getT(0).getT(1).getT(0);                        // OutMods_impl::chain11_t<NV>
		auto& peak4 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                  // OutMods_impl::peak4_t<NV>
		auto& event_data_writer1 = this->getT(0).getT(0).getT(1).getT(0).getT(1);     // routing::event_data_writer<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(1).getT(0).getT(2);          // routing::global_cable<global_cable1_t_index, parameter::empty>
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(1);                        // OutMods_impl::chain14_t<NV>
		auto& peak7 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                  // OutMods_impl::peak7_t<NV>
		auto& event_data_writer4 = this->getT(0).getT(0).getT(1).getT(1).getT(1);     // routing::event_data_writer<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(1).getT(1).getT(2);          // routing::global_cable<global_cable2_t_index, parameter::empty>
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(2);                        // OutMods_impl::chain13_t<NV>
		auto& peak6 = this->getT(0).getT(0).getT(1).getT(2).getT(0);                  // OutMods_impl::peak6_t<NV>
		auto& event_data_writer3 = this->getT(0).getT(0).getT(1).getT(2).getT(1);     // routing::event_data_writer<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(1).getT(2).getT(2);          // routing::global_cable<global_cable3_t_index, parameter::empty>
		auto& chain12 = this->getT(0).getT(0).getT(1).getT(3);                        // OutMods_impl::chain12_t<NV>
		auto& peak5 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                  // OutMods_impl::peak5_t<NV>
		auto& event_data_writer2 = this->getT(0).getT(0).getT(1).getT(3).getT(1);     // routing::event_data_writer<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(1).getT(3).getT(2);          // routing::global_cable<global_cable4_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, branch2); // Input -> branch2::Index
		
		this->getParameterT(1).connectT(0, branch3); // Output -> branch3::Index
		
		auto& A_p = this->getParameterT(2);
		A_p.connectT(0, flex_ahdsr); // A -> flex_ahdsr::Attack
		A_p.connectT(1, ahdsr);      // A -> ahdsr::Attack
		
		auto& D_p = this->getParameterT(3);
		D_p.connectT(0, flex_ahdsr); // D -> flex_ahdsr::Decay
		D_p.connectT(1, ahdsr);      // D -> ahdsr::Decay
		
		auto& S_p = this->getParameterT(4);
		S_p.connectT(0, flex_ahdsr); // S -> flex_ahdsr::Sustain
		S_p.connectT(1, ahdsr);      // S -> ahdsr::Sustain
		
		auto& R_p = this->getParameterT(5);
		R_p.connectT(0, flex_ahdsr); // R -> flex_ahdsr::Release
		R_p.connectT(1, ahdsr);      // R -> ahdsr::Release
		
		this->getParameterT(6).connectT(0, flex_ahdsr); // Loop -> flex_ahdsr::Mode
		
		this->getParameterT(7).connectT(0, branch1); // TrigPeak -> branch1::Index
		
		this->getParameterT(8).connectT(0, branch); // Mode -> branch::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable.getWrappedObject().getParameter().connectT(0, add);    // global_cable -> add::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add7); // global_cable10 -> add7::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, add6);  // global_cable9 -> add6::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add5);  // global_cable8 -> add5::Value
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, add4); // ahdsr -> add4::Value
		peak.getParameter().connectT(0, ahdsr);     // peak -> ahdsr::Gate
		auto& flex_ahdsr_p = flex_ahdsr.getWrappedObject().getParameter();
		flex_ahdsr_p.getParameterT(0).connectT(0, add8);      // flex_ahdsr -> add8::Value
		peak4.getParameter().connectT(0, event_data_writer1); // peak4 -> event_data_writer1::Value
		peak4.getParameter().connectT(1, global_cable1);      // peak4 -> global_cable1::Value
		peak7.getParameter().connectT(0, event_data_writer4); // peak7 -> event_data_writer4::Value
		peak7.getParameter().connectT(1, global_cable2);      // peak7 -> global_cable2::Value
		peak6.getParameter().connectT(0, event_data_writer3); // peak6 -> event_data_writer3::Value
		peak6.getParameter().connectT(1, global_cable3);      // peak6 -> global_cable3::Value
		peak5.getParameter().connectT(0, event_data_writer2); // peak5 -> event_data_writer2::Value
		peak5.getParameter().connectT(1, global_cable4);      // peak5 -> global_cable4::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch::Index is automated
		
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
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                                 // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);       // envelope::ahdsr::AttackLevel
		ahdsr.setParameterT(2, 0.);       // envelope::ahdsr::Hold
		;                                 // ahdsr::Decay is automated
		;                                 // ahdsr::Sustain is automated
		;                                 // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.480187); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 1.);       // envelope::ahdsr::Retrigger
		;                                 // ahdsr::Gate is automated
		
		; // add4::Value is automated
		
		;                                      // flex_ahdsr::Attack is automated
		flex_ahdsr.setParameterT(1, 0.);       // envelope::flex_ahdsr::Hold
		;                                      // flex_ahdsr::Decay is automated
		;                                      // flex_ahdsr::Sustain is automated
		;                                      // flex_ahdsr::Release is automated
		;                                      // flex_ahdsr::Mode is automated
		flex_ahdsr.setParameterT(6, 1.);       // envelope::flex_ahdsr::AttackLevel
		flex_ahdsr.setParameterT(7, 0.483333); // envelope::flex_ahdsr::AttackCurve
		flex_ahdsr.setParameterT(8, 0.516667); // envelope::flex_ahdsr::DecayCurve
		flex_ahdsr.setParameterT(9, 0.1);      // envelope::flex_ahdsr::ReleaseCurve
		
		; // add8::Value is automated
		
		; // branch3::Index is automated
		
		event_data_writer1.setParameterT(0, 0.); // routing::event_data_writer::SlotIndex
		;                                        // event_data_writer1::Value is automated
		
		; // global_cable1::Value is automated
		
		event_data_writer4.setParameterT(0, 1.); // routing::event_data_writer::SlotIndex
		;                                        // event_data_writer4::Value is automated
		
		; // global_cable2::Value is automated
		
		event_data_writer3.setParameterT(0, 2.); // routing::event_data_writer::SlotIndex
		;                                        // event_data_writer3::Value is automated
		
		; // global_cable3::Value is automated
		
		event_data_writer2.setParameterT(0, 3.); // routing::event_data_writer::SlotIndex
		;                                        // event_data_writer2::Value is automated
		
		; // global_cable4::Value is automated
		
		this->setParameterT(0, 2.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 30000.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 9715.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 0.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).                                                  // OutMods_impl::global_cable_t<NV>
        getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).                                                  // OutMods_impl::global_cable10_t<NV>
        getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).                                                  // OutMods_impl::global_cable9_t<NV>
        getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).                                                  // OutMods_impl::global_cable8_t<NV>
        getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(0).getT(2).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable1_t_index, parameter::empty>
		this->getT(0).getT(0).getT(1).getT(1).getT(2).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable2_t_index, parameter::empty>
		this->getT(0).getT(0).getT(1).getT(2).getT(2).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable3_t_index, parameter::empty>
		this->getT(0).getT(0).getT(1).getT(3).getT(2).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable4_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // OutMods_impl::peak_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).setExternalData(b, index); // OutMods_impl::ahdsr_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);         // OutMods_impl::flex_ahdsr_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);         // OutMods_impl::peak4_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(0).setExternalData(b, index);         // OutMods_impl::peak7_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(0).setExternalData(b, index);         // OutMods_impl::peak6_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(0).setExternalData(b, index);         // OutMods_impl::peak5_t<NV>
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


