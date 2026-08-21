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

namespace DspNetwork_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV> using ramp1_t = ramp_t<NV>;
template <int NV> using ramp2_t = ramp_t<NV>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<ramp_t<NV>, 0>, 
                                        parameter::plain<ramp1_t<NV>, 0>, 
                                        parameter::plain<ramp2_t<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, ramp_t<NV>>>;

template <int NV>
using resetter1_t = control::resetter<parameter::plain<ramp1_t<NV>, 2>>;
template <int NV>
using bang1_t = control::bang<NV, 
                              parameter::plain<resetter1_t<NV>, 0>>;
template <int NV>
using change1_t = control::change<NV, 
                                  parameter::plain<bang1_t<NV>, 1>>;
template <int NV>
using compare1_t = control::compare<NV, 
                                    parameter::plain<change1_t<NV>, 0>>;
template <int NV>
using ahdsr1_multimod = parameter::list<parameter::empty, 
                                        parameter::plain<compare1_t<NV>, 0>>;

template <int NV>
using ahdsr1_t = wrap::no_data<envelope::ahdsr<NV, ahdsr1_multimod<NV>>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, compare1_t<NV>>, 
                                  change1_t<NV>, 
                                  bang1_t<NV>, 
                                  resetter1_t<NV>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, ahdsr1_t<NV>>, 
                                      math::clear<NV>, 
                                      chain7_t<NV>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midichain_t<NV>>, 
                                  ramp1_t<NV>>;

template <int NV>
using clock_ramp1_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                wrap::no_data<core::clock_ramp<NV, false>>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, clock_ramp1_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using resetter_t = control::resetter<parameter::plain<ramp2_t<NV>, 2>>;
template <int NV>
using bang_t = control::bang<NV, 
                             parameter::plain<resetter_t<NV>, 0>>;
template <int NV>
using change_t = control::change<NV, 
                                 parameter::plain<bang_t<NV>, 1>>;
template <int NV>
using compare_t = control::compare<NV, 
                                   parameter::plain<change_t<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, compare_t<NV>>, 
                                  change_t<NV>, 
                                  bang_t<NV>, 
                                  resetter_t<NV>, 
                                  ramp2_t<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain_t<NV>>, 
                                   chain4_t<NV>, 
                                   chain5_t<NV>, 
                                   chain6_t<NV>>;

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<0>>;

template <int NV>
using cable_table17_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                   data::external::table<1>>;

template <int NV>
using cable_table16_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                   data::external::table<2>>;

template <int NV>
using cable_table15_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                   data::external::table<3>>;

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;

template <int NV>
using cable_pack7_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::sliderpack<1>>;

template <int NV>
using cable_pack6_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::sliderpack<2>>;

template <int NV>
using cable_pack5_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::sliderpack<3>>;

template <int NV>
using peak21_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<cable_table_t<NV>, 0>, 
                                    parameter::plain<cable_table17_t<NV>, 0>, 
                                    parameter::plain<cable_table16_t<NV>, 0>, 
                                    parameter::plain<cable_table15_t<NV>, 0>, 
                                    parameter::plain<cable_pack_t<NV>, 0>, 
                                    parameter::plain<cable_pack7_t<NV>, 0>, 
                                    parameter::plain<cable_pack6_t<NV>, 0>, 
                                    parameter::plain<cable_pack5_t<NV>, 0>>;

template <int NV>
using peak21_t = wrap::mod<peak21_mod<NV>, 
                           wrap::no_data<core::peak>>;
using cable_pack1_t = wrap::data<control::cable_pack<parameter::empty>, 
                                 data::external::sliderpack<5>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::clear<NV>>, 
                                  cable_pack1_t>;

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV> using xfader_c2 = xfader_c0<NV>;

template <int NV> using xfader_c3 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, 
                                        xfader_c1<NV>, 
                                        xfader_c2<NV>, 
                                        xfader_c3<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::switcher>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_table_t<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_table15_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain3_t<NV>>, 
                                  chain17_t<NV>, 
                                  chain16_t<NV>, 
                                  chain15_t<NV>>;

template <int NV>
using peak3_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, xfader_t<NV>>, 
                                  split1_t<NV>, 
                                  math::fmod<NV>, 
                                  peak3_t<NV>, 
                                  math::clear<NV>, 
                                  math::add<NV>>;

template <int NV>
using sb1_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, chain2_t<NV>>>;

template <int NV>
using sb1_t = bypass::smoothed<20, sb1_t_<NV>>;
template <int NV>
using switcher_c0 = parameter::bypass<sb1_t<NV>>;

template <int NV> using xfader1_c0 = xfader_c0<NV>;

template <int NV> using xfader1_c1 = xfader_c0<NV>;

template <int NV> using xfader1_c2 = xfader_c0<NV>;

template <int NV> using xfader1_c3 = xfader_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, 
                                         xfader1_c1<NV>, 
                                         xfader1_c2<NV>, 
                                         xfader1_c3<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::switcher>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_pack_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_pack7_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_pack6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, cable_pack5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain19_t<NV>>, 
                                  chain26_t<NV>, 
                                  chain25_t<NV>, 
                                  chain24_t<NV>>;

template <int NV> using peak1_t = peak3_t<NV>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, xfader1_t<NV>>, 
                                   split2_t<NV>, 
                                   math::fmod<NV>, 
                                   peak1_t<NV>, 
                                   math::clear<NV>, 
                                   math::add<NV>>;

template <int NV>
using sb2_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, chain18_t<NV>>>;

template <int NV>
using sb2_t = bypass::smoothed<20, sb2_t_<NV>>;
template <int NV>
using switcher_c1 = parameter::bypass<sb2_t<NV>>;

template <int NV>
using switcher_multimod = parameter::list<switcher_c0<NV>, switcher_c1<NV>>;

template <int NV>
using switcher_t = control::xfader<switcher_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container_t = container::chain<parameter::empty, 
                                        wrap::fix<1, sb1_t<NV>>, 
                                        sb2_t<NV>>;

namespace softbypass_switch3_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(Switch_InputRange, 
                             0., 
                             1., 
                             1.);

template <int NV>
using Switch = parameter::chain<Switch_InputRange, 
                                parameter::plain<DspNetwork_impl::switcher_t<NV>, 0>>;

}

template <int NV>
using softbypass_switch3_t = container::chain<softbypass_switch3_t_parameters::Switch<NV>, 
                                              wrap::fix<1, switcher_t<NV>>, 
                                              sb_container_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain1_t<NV>>, 
                                 softbypass_switch3_t<NV>>;

namespace DspNetwork_t_parameters
{
// Parameter list for DspNetwork_impl::DspNetwork_t ------------------------------------------------

template <int NV>
using tempo = parameter::chain<ranges::Identity, 
                               parameter::plain<DspNetwork_impl::tempo_sync_t<NV>, 0>, 
                               parameter::plain<DspNetwork_impl::clock_ramp1_t<NV>, 0>>;

template <int NV>
using multi = parameter::chain<ranges::Identity, 
                               parameter::plain<DspNetwork_impl::tempo_sync_t<NV>, 1>, 
                               parameter::plain<DspNetwork_impl::clock_ramp1_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP_INV(type_InputRange, 
                                 0., 
                                 1., 
                                 0.1);
DECLARE_PARAMETER_RANGE_STEP(type_0Range, 
                             0., 
                             1., 
                             1.);

template <int NV>
using type_0 = parameter::from0To1<DspNetwork_impl::softbypass_switch3_t<NV>, 
                                   0, 
                                   type_0Range>;

template <int NV>
using type = parameter::chain<type_InputRange, type_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(keysync_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(keysync_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using keysync_0 = parameter::from0To1<DspNetwork_impl::branch_t<NV>, 
                                      0, 
                                      keysync_0Range>;

template <int NV>
using keysync = parameter::chain<keysync_InputRange, keysync_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(onshot_InputRange, 
                             0., 
                             1., 
                             1.);

template <int NV>
using onshot = parameter::chain<onshot_InputRange, 
                                parameter::plain<DspNetwork_impl::ramp_t<NV>, 1>, 
                                parameter::plain<DspNetwork_impl::ramp1_t<NV>, 1>, 
                                parameter::plain<DspNetwork_impl::ramp2_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(morph_InputRange, 
                        1., 
                        4.);
DECLARE_PARAMETER_RANGE(morph_2Range, 
                        0.1, 
                        1.);

using morph_2 = parameter::from0To1<DspNetwork_impl::cable_pack1_t, 
                                    0, 
                                    morph_2Range>;

template <int NV>
using morph = parameter::chain<morph_InputRange, 
                               parameter::plain<DspNetwork_impl::xfader_t<NV>, 0>, 
                               parameter::plain<DspNetwork_impl::xfader1_t<NV>, 0>, 
                               morph_2>;

DECLARE_PARAMETER_RANGE_STEP(ExtTrig_InputRange, 
                             0., 
                             1., 
                             1.);

template <int NV>
using ExtTrig = parameter::chain<ExtTrig_InputRange, 
                                 parameter::plain<DspNetwork_impl::compare_t<NV>, 0>>;

template <int NV>
using DspNetwork_t_plist = parameter::list<tempo<NV>, 
                                           multi<NV>, 
                                           type<NV>, 
                                           keysync<NV>, 
                                           onshot<NV>, 
                                           morph<NV>, 
                                           ExtTrig<NV>>;
}

template <int NV>
using DspNetwork_t_ = container::chain<DspNetwork_t_parameters::DspNetwork_t_plist<NV>, 
                                       wrap::fix<1, tempo_sync_t<NV>>, 
                                       math::clear<NV>, 
                                       branch_t<NV>, 
                                       math::fmod<NV>, 
                                       peak21_t<NV>, 
                                       math::clear<NV>, 
                                       split_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public DspNetwork_impl::DspNetwork_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 4;
		static const int NumSliderPacks = 6;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(DspNetwork);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(118)
		{
			0x005C, 0x0000, 0x0000, 0x6574, 0x706D, 0x006F, 0x0000, 0x0000, 
            0x0000, 0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x0100, 0x0000, 0x6D00, 0x6C75, 0x6974, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0002, 0x0000, 0x7974, 0x6570, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0xCCCD, 
            0x3DCC, 0x005C, 0x0003, 0x0000, 0x656B, 0x7379, 0x6E79, 0x0063, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x0000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x0400, 0x0000, 0x6F00, 0x736E, 0x6F68, 
            0x0074, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x5C3F, 0x0500, 0x0000, 0x6D00, 0x726F, 
            0x6870, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0006, 0x0000, 0x7845, 
            0x5474, 0x6972, 0x0067, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
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
		
		auto& tempo_sync = this->getT(0);                                              // DspNetwork_impl::tempo_sync_t<NV>
		auto& clear4 = this->getT(1);                                                  // math::clear<NV>
		auto& branch = this->getT(2);                                                  // DspNetwork_impl::branch_t<NV>
		auto& chain = this->getT(2).getT(0);                                           // DspNetwork_impl::chain_t<NV>
		auto& ramp = this->getT(2).getT(0).getT(0);                                    // DspNetwork_impl::ramp_t<NV>
		auto& chain4 = this->getT(2).getT(1);                                          // DspNetwork_impl::chain4_t<NV>
		auto& midichain = this->getT(2).getT(1).getT(0);                               // DspNetwork_impl::midichain_t<NV>
		auto& ahdsr1 = this->getT(2).getT(1).getT(0).getT(0);                          // DspNetwork_impl::ahdsr1_t<NV>
		auto& clear9 = this->getT(2).getT(1).getT(0).getT(1);                          // math::clear<NV>
		auto& chain7 = this->getT(2).getT(1).getT(0).getT(2);                          // DspNetwork_impl::chain7_t<NV>
		auto& compare1 = this->getT(2).getT(1).getT(0).getT(2).getT(0);                // DspNetwork_impl::compare1_t<NV>
		auto& change1 = this->getT(2).getT(1).getT(0).getT(2).getT(1);                 // DspNetwork_impl::change1_t<NV>
		auto& bang1 = this->getT(2).getT(1).getT(0).getT(2).getT(2);                   // DspNetwork_impl::bang1_t<NV>
		auto& resetter1 = this->getT(2).getT(1).getT(0).getT(2).getT(3);               // DspNetwork_impl::resetter1_t<NV>
		auto& ramp1 = this->getT(2).getT(1).getT(1);                                   // DspNetwork_impl::ramp1_t<NV>
		auto& chain5 = this->getT(2).getT(2);                                          // DspNetwork_impl::chain5_t<NV>
		auto& clock_ramp1 = this->getT(2).getT(2).getT(0);                             // DspNetwork_impl::clock_ramp1_t<NV>
		auto& add6 = this->getT(2).getT(2).getT(1);                                    // math::add<NV>
		auto& chain6 = this->getT(2).getT(3);                                          // DspNetwork_impl::chain6_t<NV>
		auto& compare = this->getT(2).getT(3).getT(0);                                 // DspNetwork_impl::compare_t<NV>
		auto& change = this->getT(2).getT(3).getT(1);                                  // DspNetwork_impl::change_t<NV>
		auto& bang = this->getT(2).getT(3).getT(2);                                    // DspNetwork_impl::bang_t<NV>
		auto& resetter = this->getT(2).getT(3).getT(3);                                // DspNetwork_impl::resetter_t<NV>
		auto& ramp2 = this->getT(2).getT(3).getT(4);                                   // DspNetwork_impl::ramp2_t<NV>
		auto& fmod = this->getT(3);                                                    // math::fmod<NV>
		auto& peak21 = this->getT(4);                                                  // DspNetwork_impl::peak21_t<NV>
		auto& clear2 = this->getT(5);                                                  // math::clear<NV>
		auto& split = this->getT(6);                                                   // DspNetwork_impl::split_t<NV>
		auto& chain1 = this->getT(6).getT(0);                                          // DspNetwork_impl::chain1_t<NV>
		auto& clear = this->getT(6).getT(0).getT(0);                                   // math::clear<NV>
		auto& cable_pack1 = this->getT(6).getT(0).getT(1);                             // DspNetwork_impl::cable_pack1_t
		auto& softbypass_switch3 = this->getT(6).getT(1);                              // DspNetwork_impl::softbypass_switch3_t<NV>
		auto& switcher = this->getT(6).getT(1).getT(0);                                // DspNetwork_impl::switcher_t<NV>
		auto& sb_container = this->getT(6).getT(1).getT(1);                            // DspNetwork_impl::sb_container_t<NV>
		auto& sb1 = this->getT(6).getT(1).getT(1).getT(0);                             // DspNetwork_impl::sb1_t<NV>
		auto& chain2 = this->getT(6).getT(1).getT(1).getT(0).getT(0);                  // DspNetwork_impl::chain2_t<NV>
		auto& xfader = this->getT(6).getT(1).getT(1).getT(0).getT(0).getT(0);          // DspNetwork_impl::xfader_t<NV>
		auto& split1 = this->getT(6).getT(1).getT(1).getT(0).getT(0).getT(1);          // DspNetwork_impl::split1_t<NV>
		auto& chain3 = this->getT(6).getT(1).getT(1).getT(0).getT(0).getT(1).getT(0);  // DspNetwork_impl::chain3_t<NV>
		auto& cable_table = this->getT(6).getT(1).getT(1).getT(0).                     // DspNetwork_impl::cable_table_t<NV>
                            getT(0).getT(1).getT(0).getT(0);
		auto& add1 = this->getT(6).getT(1).getT(1).getT(0).                            // math::add<NV>
                     getT(0).getT(1).getT(0).getT(1);
		auto& gain = this->getT(6).getT(1).getT(1).getT(0).                            // core::gain<NV>
                     getT(0).getT(1).getT(0).getT(2);
		auto& chain17 = this->getT(6).getT(1).getT(1).getT(0).getT(0).getT(1).getT(1); // DspNetwork_impl::chain17_t<NV>
		auto& cable_table17 = this->getT(6).getT(1).getT(1).getT(0).                   // DspNetwork_impl::cable_table17_t<NV>
                              getT(0).getT(1).getT(1).getT(0);
		auto& add15 = this->getT(6).getT(1).getT(1).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& gain14 = this->getT(6).getT(1).getT(1).getT(0).                          // core::gain<NV>
                       getT(0).getT(1).getT(1).getT(2);
		auto& chain16 = this->getT(6).getT(1).getT(1).getT(0).getT(0).getT(1).getT(2); // DspNetwork_impl::chain16_t<NV>
		auto& cable_table16 = this->getT(6).getT(1).getT(1).getT(0).                   // DspNetwork_impl::cable_table16_t<NV>
                              getT(0).getT(1).getT(2).getT(0);
		auto& add14 = this->getT(6).getT(1).getT(1).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(2).getT(1);
		auto& gain13 = this->getT(6).getT(1).getT(1).getT(0).                          // core::gain<NV>
                       getT(0).getT(1).getT(2).getT(2);
		auto& chain15 = this->getT(6).getT(1).getT(1).getT(0).getT(0).getT(1).getT(3); // DspNetwork_impl::chain15_t<NV>
		auto& cable_table15 = this->getT(6).getT(1).getT(1).getT(0).                   // DspNetwork_impl::cable_table15_t<NV>
                              getT(0).getT(1).getT(3).getT(0);
		auto& add13 = this->getT(6).getT(1).getT(1).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(3).getT(1);
		auto& gain12 = this->getT(6).getT(1).getT(1).getT(0).                          // core::gain<NV>
                       getT(0).getT(1).getT(3).getT(2);
		auto& fmod2 = this->getT(6).getT(1).getT(1).getT(0).getT(0).getT(2);           // math::fmod<NV>
		auto& peak3 = this->getT(6).getT(1).getT(1).getT(0).getT(0).getT(3);           // DspNetwork_impl::peak3_t<NV>
		auto& clear3 = this->getT(6).getT(1).getT(1).getT(0).getT(0).getT(4);          // math::clear<NV>
		auto& add3 = this->getT(6).getT(1).getT(1).getT(0).getT(0).getT(5);            // math::add<NV>
		auto& sb2 = this->getT(6).getT(1).getT(1).getT(1);                             // DspNetwork_impl::sb2_t<NV>
		auto& chain18 = this->getT(6).getT(1).getT(1).getT(1).getT(0);                 // DspNetwork_impl::chain18_t<NV>
		auto& xfader1 = this->getT(6).getT(1).getT(1).getT(1).getT(0).getT(0);         // DspNetwork_impl::xfader1_t<NV>
		auto& split2 = this->getT(6).getT(1).getT(1).getT(1).getT(0).getT(1);          // DspNetwork_impl::split2_t<NV>
		auto& chain19 = this->getT(6).getT(1).getT(1).getT(1).getT(0).getT(1).getT(0); // DspNetwork_impl::chain19_t<NV>
		auto& cable_pack = this->getT(6).getT(1).getT(1).getT(1).                      // DspNetwork_impl::cable_pack_t<NV>
                           getT(0).getT(1).getT(0).getT(0);
		auto& add16 = this->getT(6).getT(1).getT(1).getT(1).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(1);
		auto& gain15 = this->getT(6).getT(1).getT(1).getT(1).                          // core::gain<NV>
                       getT(0).getT(1).getT(0).getT(2);
		auto& chain26 = this->getT(6).getT(1).getT(1).getT(1).getT(0).getT(1).getT(1); // DspNetwork_impl::chain26_t<NV>
		auto& cable_pack7 = this->getT(6).getT(1).getT(1).getT(1).                     // DspNetwork_impl::cable_pack7_t<NV>
                            getT(0).getT(1).getT(1).getT(0);
		auto& add23 = this->getT(6).getT(1).getT(1).getT(1).                           // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& gain22 = this->getT(6).getT(1).getT(1).getT(1).                          // core::gain<NV>
                       getT(0).getT(1).getT(1).getT(2);
		auto& chain25 = this->getT(6).getT(1).getT(1).getT(1).getT(0).getT(1).getT(2); // DspNetwork_impl::chain25_t<NV>
		auto& cable_pack6 = this->getT(6).getT(1).getT(1).getT(1).                     // DspNetwork_impl::cable_pack6_t<NV>
                            getT(0).getT(1).getT(2).getT(0);
		auto& add22 = this->getT(6).getT(1).getT(1).getT(1).                           // math::add<NV>
                      getT(0).getT(1).getT(2).getT(1);
		auto& gain21 = this->getT(6).getT(1).getT(1).getT(1).                          // core::gain<NV>
                       getT(0).getT(1).getT(2).getT(2);
		auto& chain24 = this->getT(6).getT(1).getT(1).getT(1).getT(0).getT(1).getT(3); // DspNetwork_impl::chain24_t<NV>
		auto& cable_pack5 = this->getT(6).getT(1).getT(1).getT(1).                     // DspNetwork_impl::cable_pack5_t<NV>
                            getT(0).getT(1).getT(3).getT(0);
		auto& add21 = this->getT(6).getT(1).getT(1).getT(1).                  // math::add<NV>
                      getT(0).getT(1).getT(3).getT(1);
		auto& gain20 = this->getT(6).getT(1).getT(1).getT(1).                 // core::gain<NV>
                       getT(0).getT(1).getT(3).getT(2);
		auto& fmod1 = this->getT(6).getT(1).getT(1).getT(1).getT(0).getT(2);  // math::fmod<NV>
		auto& peak1 = this->getT(6).getT(1).getT(1).getT(1).getT(0).getT(3);  // DspNetwork_impl::peak1_t<NV>
		auto& clear1 = this->getT(6).getT(1).getT(1).getT(1).getT(0).getT(4); // math::clear<NV>
		auto& add2 = this->getT(6).getT(1).getT(1).getT(1).getT(0).getT(5);   // math::add<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		softbypass_switch3.getParameterT(0).connectT(0, switcher); // Switch -> switcher::Value
		auto& tempo_p = this->getParameterT(0);
		tempo_p.connectT(0, tempo_sync);  // tempo -> tempo_sync::Tempo
		tempo_p.connectT(1, clock_ramp1); // tempo -> clock_ramp1::Tempo
		
		auto& multi_p = this->getParameterT(1);
		multi_p.connectT(0, tempo_sync);  // multi -> tempo_sync::Multiplier
		multi_p.connectT(1, clock_ramp1); // multi -> clock_ramp1::Multiplier
		
		this->getParameterT(2).connectT(0, softbypass_switch3); // type -> softbypass_switch3::Switch
		
		this->getParameterT(3).connectT(0, branch); // keysync -> branch::Index
		
		auto& onshot_p = this->getParameterT(4);
		onshot_p.connectT(0, ramp);  // onshot -> ramp::LoopStart
		onshot_p.connectT(1, ramp1); // onshot -> ramp1::LoopStart
		onshot_p.connectT(2, ramp2); // onshot -> ramp2::LoopStart
		
		auto& morph_p = this->getParameterT(5);
		morph_p.connectT(0, xfader);      // morph -> xfader::Value
		morph_p.connectT(1, xfader1);     // morph -> xfader1::Value
		morph_p.connectT(2, cable_pack1); // morph -> cable_pack1::Value
		
		this->getParameterT(6).connectT(0, compare); // ExtTrig -> compare::Left
		
		// Modulation Connections ------------------------------------------------------------------
		
		tempo_sync.getParameter().connectT(0, ramp);                     // tempo_sync -> ramp::PeriodTime
		tempo_sync.getParameter().connectT(1, ramp1);                    // tempo_sync -> ramp1::PeriodTime
		tempo_sync.getParameter().connectT(2, ramp2);                    // tempo_sync -> ramp2::PeriodTime
		resetter1.getWrappedObject().getParameter().connectT(0, ramp1);  // resetter1 -> ramp1::Gate
		bang1.getWrappedObject().getParameter().connectT(0, resetter1);  // bang1 -> resetter1::Value
		change1.getWrappedObject().getParameter().connectT(0, bang1);    // change1 -> bang1::Bang
		compare1.getWrappedObject().getParameter().connectT(0, change1); // compare1 -> change1::Value
		auto& ahdsr1_p = ahdsr1.getWrappedObject().getParameter();
		ahdsr1_p.getParameterT(1).connectT(0, compare1);                    // ahdsr1 -> compare1::Left
		clock_ramp1.getParameter().connectT(0, add6);                       // clock_ramp1 -> add6::Value
		resetter.getWrappedObject().getParameter().connectT(0, ramp2);      // resetter -> ramp2::Gate
		bang.getWrappedObject().getParameter().connectT(0, resetter);       // bang -> resetter::Value
		change.getWrappedObject().getParameter().connectT(0, bang);         // change -> bang::Bang
		compare.getWrappedObject().getParameter().connectT(0, change);      // compare -> change::Value
		cable_table.getWrappedObject().getParameter().connectT(0, add1);    // cable_table -> add1::Value
		cable_table17.getWrappedObject().getParameter().connectT(0, add15); // cable_table17 -> add15::Value
		cable_table16.getWrappedObject().getParameter().connectT(0, add14); // cable_table16 -> add14::Value
		cable_table15.getWrappedObject().getParameter().connectT(0, add13); // cable_table15 -> add13::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add16);    // cable_pack -> add16::Value
		cable_pack7.getWrappedObject().getParameter().connectT(0, add23);   // cable_pack7 -> add23::Value
		cable_pack6.getWrappedObject().getParameter().connectT(0, add22);   // cable_pack6 -> add22::Value
		cable_pack5.getWrappedObject().getParameter().connectT(0, add21);   // cable_pack5 -> add21::Value
		peak21.getParameter().connectT(0, cable_table);                     // peak21 -> cable_table::Value
		peak21.getParameter().connectT(1, cable_table17);                   // peak21 -> cable_table17::Value
		peak21.getParameter().connectT(2, cable_table16);                   // peak21 -> cable_table16::Value
		peak21.getParameter().connectT(3, cable_table15);                   // peak21 -> cable_table15::Value
		peak21.getParameter().connectT(4, cable_pack);                      // peak21 -> cable_pack::Value
		peak21.getParameter().connectT(5, cable_pack7);                     // peak21 -> cable_pack7::Value
		peak21.getParameter().connectT(6, cable_pack6);                     // peak21 -> cable_pack6::Value
		peak21.getParameter().connectT(7, cable_pack5);                     // peak21 -> cable_pack5::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);   // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain14); // xfader -> gain14::Gain
		xfader_p.getParameterT(2).connectT(0, gain13); // xfader -> gain13::Gain
		xfader_p.getParameterT(3).connectT(0, gain12); // xfader -> gain12::Gain
		peak3.getParameter().connectT(0, add3);        // peak3 -> add3::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain15); // xfader1 -> gain15::Gain
		xfader1_p.getParameterT(1).connectT(0, gain22); // xfader1 -> gain22::Gain
		xfader1_p.getParameterT(2).connectT(0, gain21); // xfader1 -> gain21::Gain
		xfader1_p.getParameterT(3).connectT(0, gain20); // xfader1 -> gain20::Gain
		peak1.getParameter().connectT(0, add2);         // peak1 -> add2::Value
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1); // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2); // switcher -> sb2::Bypassed
		
		// Default Values --------------------------------------------------------------------------
		
		;                                // tempo_sync::Tempo is automated
		;                                // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.); // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 0.); // control::tempo_sync::UnsyncedTime
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		; // branch::Index is automated
		
		;                          // ramp::PeriodTime is automated
		;                          // ramp::LoopStart is automated
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		ahdsr1.setParameterT(0, 0.);    // envelope::ahdsr::Attack
		ahdsr1.setParameterT(1, 1.);    // envelope::ahdsr::AttackLevel
		ahdsr1.setParameterT(2, 0.);    // envelope::ahdsr::Hold
		ahdsr1.setParameterT(3, 335.1); // envelope::ahdsr::Decay
		ahdsr1.setParameterT(4, 1.);    // envelope::ahdsr::Sustain
		ahdsr1.setParameterT(5, 0.);    // envelope::ahdsr::Release
		ahdsr1.setParameterT(6, 0.5);   // envelope::ahdsr::AttackCurve
		ahdsr1.setParameterT(7, 0.);    // envelope::ahdsr::Retrigger
		ahdsr1.setParameterT(8, 1.);    // envelope::ahdsr::Gate
		
		clear9.setParameterT(0, 0.); // math::clear::Value
		
		;                               // compare1::Left is automated
		compare1.setParameterT(1, 0.5); // control::compare::Right
		compare1.setParameterT(2, 2.);  // control::compare::Comparator
		
		; // change1::Value is automated
		
		bang1.setParameterT(0, 1.); // control::bang::Value
		;                           // bang1::Bang is automated
		
		; // resetter1::Value is automated
		
		; // ramp1::PeriodTime is automated
		; // ramp1::LoopStart is automated
		; // ramp1::Gate is automated
		
		;                                 // clock_ramp1::Tempo is automated
		;                                 // clock_ramp1::Multiplier is automated
		clock_ramp1.setParameterT(2, 0.); // core::clock_ramp::AddToSignal
		clock_ramp1.setParameterT(3, 0.); // core::clock_ramp::UpdateMode
		clock_ramp1.setParameterT(4, 0.); // core::clock_ramp::Inactive
		
		; // add6::Value is automated
		
		;                              // compare::Left is automated
		compare.setParameterT(1, 0.5); // control::compare::Right
		compare.setParameterT(2, 2.);  // control::compare::Comparator
		
		; // change::Value is automated
		
		bang.setParameterT(0, 1.); // control::bang::Value
		;                          // bang::Bang is automated
		
		; // resetter::Value is automated
		
		; // ramp2::PeriodTime is automated
		; // ramp2::LoopStart is automated
		; // ramp2::Gate is automated
		
		fmod.setParameterT(0, 1.); // math::fmod::Value
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack1::Value is automated
		
		; // softbypass_switch3::Switch is automated
		
		; // switcher::Value is automated
		
		chain2.setParameterT(0, 3.01631); // container::chain::swich
		
		; // xfader::Value is automated
		
		; // cable_table::Value is automated
		
		; // add1::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // cable_table17::Value is automated
		
		; // add15::Value is automated
		
		;                             // gain14::Gain is automated
		gain14.setParameterT(1, 20.); // core::gain::Smoothing
		gain14.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // cable_table16::Value is automated
		
		; // add14::Value is automated
		
		;                             // gain13::Gain is automated
		gain13.setParameterT(1, 20.); // core::gain::Smoothing
		gain13.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // cable_table15::Value is automated
		
		; // add13::Value is automated
		
		;                             // gain12::Gain is automated
		gain12.setParameterT(1, 20.); // core::gain::Smoothing
		gain12.setParameterT(2, 0.);  // core::gain::ResetValue
		
		fmod2.setParameterT(0, 2.); // math::fmod::Value
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // add3::Value is automated
		
		; // xfader1::Value is automated
		
		; // cable_pack::Value is automated
		
		; // add16::Value is automated
		
		;                             // gain15::Gain is automated
		gain15.setParameterT(1, 20.); // core::gain::Smoothing
		gain15.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // cable_pack7::Value is automated
		
		; // add23::Value is automated
		
		;                             // gain22::Gain is automated
		gain22.setParameterT(1, 20.); // core::gain::Smoothing
		gain22.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // cable_pack6::Value is automated
		
		; // add22::Value is automated
		
		;                             // gain21::Gain is automated
		gain21.setParameterT(1, 20.); // core::gain::Smoothing
		gain21.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // cable_pack5::Value is automated
		
		; // add21::Value is automated
		
		;                             // gain20::Gain is automated
		gain20.setParameterT(1, 20.); // core::gain::Smoothing
		gain20.setParameterT(2, 0.);  // core::gain::ResetValue
		
		fmod1.setParameterT(0, 2.); // math::fmod::Value
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // add2::Value is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 2.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 1.);
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
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return true; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(2).getT(0).getT(0).setExternalData(b, index);                         // DspNetwork_impl::ramp_t<NV>
		this->getT(2).getT(1).getT(0).getT(0).setExternalData(b, index);                 // DspNetwork_impl::ahdsr1_t<NV>
		this->getT(2).getT(1).getT(1).setExternalData(b, index);                         // DspNetwork_impl::ramp1_t<NV>
		this->getT(2).getT(2).getT(0).setExternalData(b, index);                         // DspNetwork_impl::clock_ramp1_t<NV>
		this->getT(2).getT(3).getT(4).setExternalData(b, index);                         // DspNetwork_impl::ramp2_t<NV>
		this->getT(4).setExternalData(b, index);                                         // DspNetwork_impl::peak21_t<NV>
		this->getT(6).getT(0).getT(1).setExternalData(b, index);                         // DspNetwork_impl::cable_pack1_t
		this->getT(6).getT(1).getT(1).getT(0).                                           // DspNetwork_impl::cable_table_t<NV>
        getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(6).getT(1).getT(1).getT(0).                                           // DspNetwork_impl::cable_table17_t<NV>
        getT(0).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(6).getT(1).getT(1).getT(0).                                           // DspNetwork_impl::cable_table16_t<NV>
        getT(0).getT(1).getT(2).getT(0).setExternalData(b, index);
		this->getT(6).getT(1).getT(1).getT(0).                                           // DspNetwork_impl::cable_table15_t<NV>
        getT(0).getT(1).getT(3).getT(0).setExternalData(b, index);
		this->getT(6).getT(1).getT(1).getT(0).getT(0).getT(3).setExternalData(b, index); // DspNetwork_impl::peak3_t<NV>
		this->getT(6).getT(1).getT(1).getT(1).                                           // DspNetwork_impl::cable_pack_t<NV>
        getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(6).getT(1).getT(1).getT(1).                                           // DspNetwork_impl::cable_pack7_t<NV>
        getT(0).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(6).getT(1).getT(1).getT(1).                                           // DspNetwork_impl::cable_pack6_t<NV>
        getT(0).getT(1).getT(2).getT(0).setExternalData(b, index);
		this->getT(6).getT(1).getT(1).getT(1).                                           // DspNetwork_impl::cable_pack5_t<NV>
        getT(0).getT(1).getT(3).getT(0).setExternalData(b, index);
		this->getT(6).getT(1).getT(1).getT(1).getT(0).getT(3).setExternalData(b, index); // DspNetwork_impl::peak1_t<NV>
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


