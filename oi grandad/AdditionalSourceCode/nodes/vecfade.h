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

namespace vecfade_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable40_t_index = runtime_target::indexers::fix_hash<115222>;
using smoothed_parameter41_mod = parameter::plain<routing::global_cable<global_cable40_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter41_t = wrap::mod<smoothed_parameter41_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable41_t_index = runtime_target::indexers::fix_hash<3708>;
using smoothed_parameter42_mod = parameter::plain<routing::global_cable<global_cable41_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter42_t = wrap::mod<smoothed_parameter42_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable42_t_index = runtime_target::indexers::fix_hash<3709>;
using smoothed_parameter43_mod = parameter::plain<routing::global_cable<global_cable42_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter43_t = wrap::mod<smoothed_parameter43_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable43_t_index = runtime_target::indexers::fix_hash<3710>;
using smoothed_parameter44_mod = parameter::plain<routing::global_cable<global_cable43_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter44_t = wrap::mod<smoothed_parameter44_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using xfader13_multimod = parameter::list<parameter::plain<smoothed_parameter41_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter42_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter43_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter44_t<NV>, 0>>;

template <int NV>
using xfader13_t = control::xfader<xfader13_multimod<NV>, faders::switcher>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter41_t<NV>>, 
                                   routing::global_cable<global_cable40_t_index, parameter::empty>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter42_t<NV>>, 
                                   routing::global_cable<global_cable41_t_index, parameter::empty>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter43_t<NV>>, 
                                   routing::global_cable<global_cable42_t_index, parameter::empty>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter44_t<NV>>, 
                                   routing::global_cable<global_cable43_t_index, parameter::empty>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain43_t<NV>>, 
                                  chain44_t<NV>, 
                                  chain45_t<NV>, 
                                  chain46_t<NV>>;

template <int NV>
using chain110_t = container::chain<parameter::empty, 
                                    wrap::fix<2, xfader13_t<NV>>, 
                                    split5_t<NV>>;

template <int NV>
using sb5_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain110_t<NV>>>;

template <int NV>
using sb5_t = bypass::smoothed<20, sb5_t_<NV>>;
template <int NV>
using switcher1_c0 = parameter::bypass<sb5_t<NV>>;

using global_cable32_t_index = global_cable40_t_index;
using smoothed_parameter33_mod = parameter::plain<routing::global_cable<global_cable32_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter33_t = wrap::mod<smoothed_parameter33_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable33_t_index = global_cable41_t_index;
using smoothed_parameter34_mod = parameter::plain<routing::global_cable<global_cable33_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter34_t = wrap::mod<smoothed_parameter34_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable34_t_index = global_cable42_t_index;
using smoothed_parameter35_mod = parameter::plain<routing::global_cable<global_cable34_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter35_t = wrap::mod<smoothed_parameter35_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable35_t_index = global_cable43_t_index;
using smoothed_parameter36_mod = parameter::plain<routing::global_cable<global_cable35_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter36_t = wrap::mod<smoothed_parameter36_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using xfader12_multimod = parameter::list<parameter::plain<smoothed_parameter33_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter34_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter35_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter36_t<NV>, 0>>;

template <int NV>
using xfader12_t = control::xfader<xfader12_multimod<NV>, faders::linear>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter33_t<NV>>, 
                                   routing::global_cable<global_cable32_t_index, parameter::empty>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter34_t<NV>>, 
                                   routing::global_cable<global_cable33_t_index, parameter::empty>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter35_t<NV>>, 
                                   routing::global_cable<global_cable34_t_index, parameter::empty>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter36_t<NV>>, 
                                   routing::global_cable<global_cable35_t_index, parameter::empty>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain35_t<NV>>, 
                                  chain36_t<NV>, 
                                  chain37_t<NV>, 
                                  chain38_t<NV>>;

template <int NV>
using chain91_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader12_t<NV>>, 
                                   split4_t<NV>>;

template <int NV>
using sb6_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain91_t<NV>>>;

template <int NV>
using sb6_t = bypass::smoothed<20, sb6_t_<NV>>;
template <int NV>
using switcher1_c1 = parameter::bypass<sb6_t<NV>>;

using global_cable16_t_index = global_cable40_t_index;
using smoothed_parameter17_mod = parameter::plain<routing::global_cable<global_cable16_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter17_t = wrap::mod<smoothed_parameter17_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable17_t_index = global_cable41_t_index;
using smoothed_parameter18_mod = parameter::plain<routing::global_cable<global_cable17_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter18_t = wrap::mod<smoothed_parameter18_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable18_t_index = global_cable42_t_index;
using smoothed_parameter19_mod = parameter::plain<routing::global_cable<global_cable18_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter19_t = wrap::mod<smoothed_parameter19_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable19_t_index = global_cable43_t_index;
using smoothed_parameter20_mod = parameter::plain<routing::global_cable<global_cable19_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter20_t = wrap::mod<smoothed_parameter20_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using xfader10_multimod = parameter::list<parameter::plain<smoothed_parameter17_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter18_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter19_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter20_t<NV>, 0>>;

template <int NV>
using xfader10_t = control::xfader<xfader10_multimod<NV>, faders::rms>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter17_t<NV>>, 
                                   routing::global_cable<global_cable16_t_index, parameter::empty>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter18_t<NV>>, 
                                   routing::global_cable<global_cable17_t_index, parameter::empty>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter19_t<NV>>, 
                                   routing::global_cable<global_cable18_t_index, parameter::empty>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter20_t<NV>>, 
                                   routing::global_cable<global_cable19_t_index, parameter::empty>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain19_t<NV>>, 
                                  chain20_t<NV>, 
                                  chain21_t<NV>, 
                                  chain22_t<NV>>;

template <int NV>
using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader10_t<NV>>, 
                                   split2_t<NV>>;

template <int NV>
using sb7_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain90_t<NV>>>;

template <int NV>
using sb7_t = bypass::smoothed<20, sb7_t_<NV>>;
template <int NV>
using switcher1_c2 = parameter::bypass<sb7_t<NV>>;

using global_cable24_t_index = global_cable40_t_index;
using smoothed_parameter25_mod = parameter::plain<routing::global_cable<global_cable24_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter25_t = wrap::mod<smoothed_parameter25_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable25_t_index = global_cable41_t_index;
using smoothed_parameter26_mod = parameter::plain<routing::global_cable<global_cable25_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter26_t = wrap::mod<smoothed_parameter26_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable26_t_index = global_cable42_t_index;
using smoothed_parameter27_mod = parameter::plain<routing::global_cable<global_cable26_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter27_t = wrap::mod<smoothed_parameter27_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

using global_cable27_t_index = global_cable43_t_index;
using smoothed_parameter28_mod = parameter::plain<routing::global_cable<global_cable27_t_index, parameter::empty>, 
                                                  0>;
template <int NV>
using smoothed_parameter28_t = wrap::mod<smoothed_parameter28_mod, 
                                         control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using xfader11_multimod = parameter::list<parameter::plain<smoothed_parameter25_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter26_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter27_t<NV>, 0>, 
                                          parameter::plain<smoothed_parameter28_t<NV>, 0>>;

template <int NV>
using xfader11_t = control::xfader<xfader11_multimod<NV>, faders::cosine_half>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter25_t<NV>>, 
                                   routing::global_cable<global_cable24_t_index, parameter::empty>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter26_t<NV>>, 
                                   routing::global_cable<global_cable25_t_index, parameter::empty>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter27_t<NV>>, 
                                   routing::global_cable<global_cable26_t_index, parameter::empty>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter28_t<NV>>, 
                                   routing::global_cable<global_cable27_t_index, parameter::empty>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain27_t<NV>>, 
                                  chain28_t<NV>, 
                                  chain29_t<NV>, 
                                  chain30_t<NV>>;

template <int NV>
using chain100_t = container::chain<parameter::empty, 
                                    wrap::fix<2, xfader11_t<NV>>, 
                                    split3_t<NV>>;

template <int NV>
using sb8_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, chain100_t<NV>>>;

template <int NV>
using sb8_t = bypass::smoothed<20, sb8_t_<NV>>;
template <int NV>
using switcher1_c3 = parameter::bypass<sb8_t<NV>>;

template <int NV>
using switcher1_multimod = parameter::list<switcher1_c0<NV>, 
                                           switcher1_c1<NV>, 
                                           switcher1_c2<NV>, 
                                           switcher1_c3<NV>>;

template <int NV>
using switcher1_t = control::xfader<switcher1_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container1_t = container::chain<parameter::empty, 
                                         wrap::fix<2, sb5_t<NV>>, 
                                         sb6_t<NV>, 
                                         sb7_t<NV>, 
                                         sb8_t<NV>>;

template <int NV>
using softbypass_switch6_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher1_t<NV>>, 
                                              sb_container1_t<NV>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<2, softbypass_switch6_t<NV>>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

namespace vecfade_t_parameters
{
// Parameter list for vecfade_impl::vecfade_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(smooth_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using smooth_0 = parameter::from0To1<vecfade_impl::smoothed_parameter41_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_1 = parameter::from0To1<vecfade_impl::smoothed_parameter42_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_2 = parameter::from0To1<vecfade_impl::smoothed_parameter43_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_3 = parameter::from0To1<vecfade_impl::smoothed_parameter44_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_4 = parameter::from0To1<vecfade_impl::smoothed_parameter33_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_5 = parameter::from0To1<vecfade_impl::smoothed_parameter34_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_6 = parameter::from0To1<vecfade_impl::smoothed_parameter35_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_7 = parameter::from0To1<vecfade_impl::smoothed_parameter36_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_8 = parameter::from0To1<vecfade_impl::smoothed_parameter17_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_9 = parameter::from0To1<vecfade_impl::smoothed_parameter18_t<NV>, 
                                     1, 
                                     smooth_0Range>;

template <int NV>
using smooth_10 = parameter::from0To1<vecfade_impl::smoothed_parameter19_t<NV>, 
                                      1, 
                                      smooth_0Range>;

template <int NV>
using smooth_11 = parameter::from0To1<vecfade_impl::smoothed_parameter20_t<NV>, 
                                      1, 
                                      smooth_0Range>;

template <int NV>
using smooth_12 = parameter::from0To1<vecfade_impl::smoothed_parameter25_t<NV>, 
                                      1, 
                                      smooth_0Range>;

template <int NV>
using smooth_13 = parameter::from0To1<vecfade_impl::smoothed_parameter26_t<NV>, 
                                      1, 
                                      smooth_0Range>;

template <int NV>
using smooth_14 = parameter::from0To1<vecfade_impl::smoothed_parameter27_t<NV>, 
                                      1, 
                                      smooth_0Range>;

template <int NV>
using smooth_15 = parameter::from0To1<vecfade_impl::smoothed_parameter28_t<NV>, 
                                      1, 
                                      smooth_0Range>;

template <int NV>
using smooth = parameter::chain<ranges::Identity, 
                                smooth_0<NV>, 
                                smooth_1<NV>, 
                                smooth_2<NV>, 
                                smooth_3<NV>, 
                                smooth_4<NV>, 
                                smooth_5<NV>, 
                                smooth_6<NV>, 
                                smooth_7<NV>, 
                                smooth_8<NV>, 
                                smooth_9<NV>, 
                                smooth_10<NV>, 
                                smooth_11<NV>, 
                                smooth_12<NV>, 
                                smooth_13<NV>, 
                                smooth_14<NV>, 
                                smooth_15<NV>>;

template <int NV>
using scan = parameter::chain<ranges::Identity, 
                              parameter::plain<vecfade_impl::xfader13_t<NV>, 0>, 
                              parameter::plain<vecfade_impl::xfader12_t<NV>, 0>, 
                              parameter::plain<vecfade_impl::xfader10_t<NV>, 0>, 
                              parameter::plain<vecfade_impl::xfader11_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(fadetype_InputRange, 
                             1., 
                             4., 
                             1.);

template <int NV>
using fadetype = parameter::chain<fadetype_InputRange, 
                                  parameter::plain<vecfade_impl::switcher1_t<NV>, 0>>;

template <int NV>
using vecfade_t_plist = parameter::list<smooth<NV>, 
                                        scan<NV>, 
                                        fadetype<NV>>;
}

template <int NV>
using vecfade_t_ = container::chain<vecfade_t_parameters::vecfade_t_plist<NV>, 
                                    wrap::fix<2, no_midi_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public vecfade_impl::vecfade_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(vecfade);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(52)
		{
			0x005C, 0x0000, 0x0000, 0x6D73, 0x6F6F, 0x6874, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0001, 0x0000, 0x6373, 0x6E61, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0002, 0x0000, 0x6166, 0x6564, 0x7974, 0x6570, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& no_midi = this->getT(0);                                                 // vecfade_impl::no_midi_t<NV>
		auto& softbypass_switch6 = this->getT(0).getT(0);                              // vecfade_impl::softbypass_switch6_t<NV>
		auto& switcher1 = this->getT(0).getT(0).getT(0);                               // vecfade_impl::switcher1_t<NV>
		auto& sb_container1 = this->getT(0).getT(0).getT(1);                           // vecfade_impl::sb_container1_t<NV>
		auto& sb5 = this->getT(0).getT(0).getT(1).getT(0);                             // vecfade_impl::sb5_t<NV>
		auto& chain110 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                // vecfade_impl::chain110_t<NV>
		auto& xfader13 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);        // vecfade_impl::xfader13_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1);          // vecfade_impl::split5_t<NV>
		auto& chain43 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).getT(0); // vecfade_impl::chain43_t<NV>
		auto& smoothed_parameter41 = this->getT(0).getT(0).getT(1).getT(0).            // vecfade_impl::smoothed_parameter41_t<NV>
                                     getT(0).getT(1).getT(0).getT(0);
		auto& global_cable40 = this->getT(0).getT(0).getT(1).getT(0).                  // routing::global_cable<global_cable40_t_index, parameter::empty>
                               getT(0).getT(1).getT(0).getT(1);
		auto& chain44 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).getT(1); // vecfade_impl::chain44_t<NV>
		auto& smoothed_parameter42 = this->getT(0).getT(0).getT(1).getT(0).            // vecfade_impl::smoothed_parameter42_t<NV>
                                     getT(0).getT(1).getT(1).getT(0);
		auto& global_cable41 = this->getT(0).getT(0).getT(1).getT(0).                  // routing::global_cable<global_cable41_t_index, parameter::empty>
                               getT(0).getT(1).getT(1).getT(1);
		auto& chain45 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).getT(2); // vecfade_impl::chain45_t<NV>
		auto& smoothed_parameter43 = this->getT(0).getT(0).getT(1).getT(0).            // vecfade_impl::smoothed_parameter43_t<NV>
                                     getT(0).getT(1).getT(2).getT(0);
		auto& global_cable42 = this->getT(0).getT(0).getT(1).getT(0).                  // routing::global_cable<global_cable42_t_index, parameter::empty>
                               getT(0).getT(1).getT(2).getT(1);
		auto& chain46 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).getT(3); // vecfade_impl::chain46_t<NV>
		auto& smoothed_parameter44 = this->getT(0).getT(0).getT(1).getT(0).            // vecfade_impl::smoothed_parameter44_t<NV>
                                     getT(0).getT(1).getT(3).getT(0);
		auto& global_cable43 = this->getT(0).getT(0).getT(1).getT(0).                  // routing::global_cable<global_cable43_t_index, parameter::empty>
                               getT(0).getT(1).getT(3).getT(1);
		auto& sb6 = this->getT(0).getT(0).getT(1).getT(1);                             // vecfade_impl::sb6_t<NV>
		auto& chain91 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                 // vecfade_impl::chain91_t<NV>
		auto& xfader12 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0);        // vecfade_impl::xfader12_t<NV>
		auto& split4 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(1);          // vecfade_impl::split4_t<NV>
		auto& chain35 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(1).getT(0); // vecfade_impl::chain35_t<NV>
		auto& smoothed_parameter33 = this->getT(0).getT(0).getT(1).getT(1).            // vecfade_impl::smoothed_parameter33_t<NV>
                                     getT(0).getT(1).getT(0).getT(0);
		auto& global_cable32 = this->getT(0).getT(0).getT(1).getT(1).                  // routing::global_cable<global_cable32_t_index, parameter::empty>
                               getT(0).getT(1).getT(0).getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(1).getT(1); // vecfade_impl::chain36_t<NV>
		auto& smoothed_parameter34 = this->getT(0).getT(0).getT(1).getT(1).            // vecfade_impl::smoothed_parameter34_t<NV>
                                     getT(0).getT(1).getT(1).getT(0);
		auto& global_cable33 = this->getT(0).getT(0).getT(1).getT(1).                  // routing::global_cable<global_cable33_t_index, parameter::empty>
                               getT(0).getT(1).getT(1).getT(1);
		auto& chain37 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(1).getT(2); // vecfade_impl::chain37_t<NV>
		auto& smoothed_parameter35 = this->getT(0).getT(0).getT(1).getT(1).            // vecfade_impl::smoothed_parameter35_t<NV>
                                     getT(0).getT(1).getT(2).getT(0);
		auto& global_cable34 = this->getT(0).getT(0).getT(1).getT(1).                  // routing::global_cable<global_cable34_t_index, parameter::empty>
                               getT(0).getT(1).getT(2).getT(1);
		auto& chain38 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(1).getT(3); // vecfade_impl::chain38_t<NV>
		auto& smoothed_parameter36 = this->getT(0).getT(0).getT(1).getT(1).            // vecfade_impl::smoothed_parameter36_t<NV>
                                     getT(0).getT(1).getT(3).getT(0);
		auto& global_cable35 = this->getT(0).getT(0).getT(1).getT(1).                  // routing::global_cable<global_cable35_t_index, parameter::empty>
                               getT(0).getT(1).getT(3).getT(1);
		auto& sb7 = this->getT(0).getT(0).getT(1).getT(2);                             // vecfade_impl::sb7_t<NV>
		auto& chain90 = this->getT(0).getT(0).getT(1).getT(2).getT(0);                 // vecfade_impl::chain90_t<NV>
		auto& xfader10 = this->getT(0).getT(0).getT(1).getT(2).getT(0).getT(0);        // vecfade_impl::xfader10_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(1).getT(2).getT(0).getT(1);          // vecfade_impl::split2_t<NV>
		auto& chain19 = this->getT(0).getT(0).getT(1).getT(2).getT(0).getT(1).getT(0); // vecfade_impl::chain19_t<NV>
		auto& smoothed_parameter17 = this->getT(0).getT(0).getT(1).getT(2).            // vecfade_impl::smoothed_parameter17_t<NV>
                                     getT(0).getT(1).getT(0).getT(0);
		auto& global_cable16 = this->getT(0).getT(0).getT(1).getT(2).                  // routing::global_cable<global_cable16_t_index, parameter::empty>
                               getT(0).getT(1).getT(0).getT(1);
		auto& chain20 = this->getT(0).getT(0).getT(1).getT(2).getT(0).getT(1).getT(1); // vecfade_impl::chain20_t<NV>
		auto& smoothed_parameter18 = this->getT(0).getT(0).getT(1).getT(2).            // vecfade_impl::smoothed_parameter18_t<NV>
                                     getT(0).getT(1).getT(1).getT(0);
		auto& global_cable17 = this->getT(0).getT(0).getT(1).getT(2).                  // routing::global_cable<global_cable17_t_index, parameter::empty>
                               getT(0).getT(1).getT(1).getT(1);
		auto& chain21 = this->getT(0).getT(0).getT(1).getT(2).getT(0).getT(1).getT(2); // vecfade_impl::chain21_t<NV>
		auto& smoothed_parameter19 = this->getT(0).getT(0).getT(1).getT(2).            // vecfade_impl::smoothed_parameter19_t<NV>
                                     getT(0).getT(1).getT(2).getT(0);
		auto& global_cable18 = this->getT(0).getT(0).getT(1).getT(2).                  // routing::global_cable<global_cable18_t_index, parameter::empty>
                               getT(0).getT(1).getT(2).getT(1);
		auto& chain22 = this->getT(0).getT(0).getT(1).getT(2).getT(0).getT(1).getT(3); // vecfade_impl::chain22_t<NV>
		auto& smoothed_parameter20 = this->getT(0).getT(0).getT(1).getT(2).            // vecfade_impl::smoothed_parameter20_t<NV>
                                     getT(0).getT(1).getT(3).getT(0);
		auto& global_cable19 = this->getT(0).getT(0).getT(1).getT(2).                  // routing::global_cable<global_cable19_t_index, parameter::empty>
                               getT(0).getT(1).getT(3).getT(1);
		auto& sb8 = this->getT(0).getT(0).getT(1).getT(3);                             // vecfade_impl::sb8_t<NV>
		auto& chain100 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                // vecfade_impl::chain100_t<NV>
		auto& xfader11 = this->getT(0).getT(0).getT(1).getT(3).getT(0).getT(0);        // vecfade_impl::xfader11_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(1).getT(3).getT(0).getT(1);          // vecfade_impl::split3_t<NV>
		auto& chain27 = this->getT(0).getT(0).getT(1).getT(3).getT(0).getT(1).getT(0); // vecfade_impl::chain27_t<NV>
		auto& smoothed_parameter25 = this->getT(0).getT(0).getT(1).getT(3).            // vecfade_impl::smoothed_parameter25_t<NV>
                                     getT(0).getT(1).getT(0).getT(0);
		auto& global_cable24 = this->getT(0).getT(0).getT(1).getT(3).                  // routing::global_cable<global_cable24_t_index, parameter::empty>
                               getT(0).getT(1).getT(0).getT(1);
		auto& chain28 = this->getT(0).getT(0).getT(1).getT(3).getT(0).getT(1).getT(1); // vecfade_impl::chain28_t<NV>
		auto& smoothed_parameter26 = this->getT(0).getT(0).getT(1).getT(3).            // vecfade_impl::smoothed_parameter26_t<NV>
                                     getT(0).getT(1).getT(1).getT(0);
		auto& global_cable25 = this->getT(0).getT(0).getT(1).getT(3).                  // routing::global_cable<global_cable25_t_index, parameter::empty>
                               getT(0).getT(1).getT(1).getT(1);
		auto& chain29 = this->getT(0).getT(0).getT(1).getT(3).getT(0).getT(1).getT(2); // vecfade_impl::chain29_t<NV>
		auto& smoothed_parameter27 = this->getT(0).getT(0).getT(1).getT(3).            // vecfade_impl::smoothed_parameter27_t<NV>
                                     getT(0).getT(1).getT(2).getT(0);
		auto& global_cable26 = this->getT(0).getT(0).getT(1).getT(3).                  // routing::global_cable<global_cable26_t_index, parameter::empty>
                               getT(0).getT(1).getT(2).getT(1);
		auto& chain30 = this->getT(0).getT(0).getT(1).getT(3).getT(0).getT(1).getT(3); // vecfade_impl::chain30_t<NV>
		auto& smoothed_parameter28 = this->getT(0).getT(0).getT(1).getT(3).            // vecfade_impl::smoothed_parameter28_t<NV>
                                     getT(0).getT(1).getT(3).getT(0);
		auto& global_cable27 = this->getT(0).getT(0).getT(1).getT(3).  // routing::global_cable<global_cable27_t_index, parameter::empty>
                               getT(0).getT(1).getT(3).getT(1);
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& smooth_p = this->getParameterT(0);
		smooth_p.connectT(0, smoothed_parameter41);  // smooth -> smoothed_parameter41::SmoothingTime
		smooth_p.connectT(1, smoothed_parameter42);  // smooth -> smoothed_parameter42::SmoothingTime
		smooth_p.connectT(2, smoothed_parameter43);  // smooth -> smoothed_parameter43::SmoothingTime
		smooth_p.connectT(3, smoothed_parameter44);  // smooth -> smoothed_parameter44::SmoothingTime
		smooth_p.connectT(4, smoothed_parameter33);  // smooth -> smoothed_parameter33::SmoothingTime
		smooth_p.connectT(5, smoothed_parameter34);  // smooth -> smoothed_parameter34::SmoothingTime
		smooth_p.connectT(6, smoothed_parameter35);  // smooth -> smoothed_parameter35::SmoothingTime
		smooth_p.connectT(7, smoothed_parameter36);  // smooth -> smoothed_parameter36::SmoothingTime
		smooth_p.connectT(8, smoothed_parameter17);  // smooth -> smoothed_parameter17::SmoothingTime
		smooth_p.connectT(9, smoothed_parameter18);  // smooth -> smoothed_parameter18::SmoothingTime
		smooth_p.connectT(10, smoothed_parameter19); // smooth -> smoothed_parameter19::SmoothingTime
		smooth_p.connectT(11, smoothed_parameter20); // smooth -> smoothed_parameter20::SmoothingTime
		smooth_p.connectT(12, smoothed_parameter25); // smooth -> smoothed_parameter25::SmoothingTime
		smooth_p.connectT(13, smoothed_parameter26); // smooth -> smoothed_parameter26::SmoothingTime
		smooth_p.connectT(14, smoothed_parameter27); // smooth -> smoothed_parameter27::SmoothingTime
		smooth_p.connectT(15, smoothed_parameter28); // smooth -> smoothed_parameter28::SmoothingTime
		
		auto& scan_p = this->getParameterT(1);
		scan_p.connectT(0, xfader13); // scan -> xfader13::Value
		scan_p.connectT(1, xfader12); // scan -> xfader12::Value
		scan_p.connectT(2, xfader10); // scan -> xfader10::Value
		scan_p.connectT(3, xfader11); // scan -> xfader11::Value
		
		this->getParameterT(2).connectT(0, switcher1); // fadetype -> switcher1::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		smoothed_parameter41.getParameter().connectT(0, global_cable40); // smoothed_parameter41 -> global_cable40::Value
		smoothed_parameter42.getParameter().connectT(0, global_cable41); // smoothed_parameter42 -> global_cable41::Value
		smoothed_parameter43.getParameter().connectT(0, global_cable42); // smoothed_parameter43 -> global_cable42::Value
		smoothed_parameter44.getParameter().connectT(0, global_cable43); // smoothed_parameter44 -> global_cable43::Value
		auto& xfader13_p = xfader13.getWrappedObject().getParameter();
		xfader13_p.getParameterT(0).connectT(0, smoothed_parameter41);   // xfader13 -> smoothed_parameter41::Value
		xfader13_p.getParameterT(1).connectT(0, smoothed_parameter42);   // xfader13 -> smoothed_parameter42::Value
		xfader13_p.getParameterT(2).connectT(0, smoothed_parameter43);   // xfader13 -> smoothed_parameter43::Value
		xfader13_p.getParameterT(3).connectT(0, smoothed_parameter44);   // xfader13 -> smoothed_parameter44::Value
		smoothed_parameter33.getParameter().connectT(0, global_cable32); // smoothed_parameter33 -> global_cable32::Value
		smoothed_parameter34.getParameter().connectT(0, global_cable33); // smoothed_parameter34 -> global_cable33::Value
		smoothed_parameter35.getParameter().connectT(0, global_cable34); // smoothed_parameter35 -> global_cable34::Value
		smoothed_parameter36.getParameter().connectT(0, global_cable35); // smoothed_parameter36 -> global_cable35::Value
		auto& xfader12_p = xfader12.getWrappedObject().getParameter();
		xfader12_p.getParameterT(0).connectT(0, smoothed_parameter33);   // xfader12 -> smoothed_parameter33::Value
		xfader12_p.getParameterT(1).connectT(0, smoothed_parameter34);   // xfader12 -> smoothed_parameter34::Value
		xfader12_p.getParameterT(2).connectT(0, smoothed_parameter35);   // xfader12 -> smoothed_parameter35::Value
		xfader12_p.getParameterT(3).connectT(0, smoothed_parameter36);   // xfader12 -> smoothed_parameter36::Value
		smoothed_parameter17.getParameter().connectT(0, global_cable16); // smoothed_parameter17 -> global_cable16::Value
		smoothed_parameter18.getParameter().connectT(0, global_cable17); // smoothed_parameter18 -> global_cable17::Value
		smoothed_parameter19.getParameter().connectT(0, global_cable18); // smoothed_parameter19 -> global_cable18::Value
		smoothed_parameter20.getParameter().connectT(0, global_cable19); // smoothed_parameter20 -> global_cable19::Value
		auto& xfader10_p = xfader10.getWrappedObject().getParameter();
		xfader10_p.getParameterT(0).connectT(0, smoothed_parameter17);   // xfader10 -> smoothed_parameter17::Value
		xfader10_p.getParameterT(1).connectT(0, smoothed_parameter18);   // xfader10 -> smoothed_parameter18::Value
		xfader10_p.getParameterT(2).connectT(0, smoothed_parameter19);   // xfader10 -> smoothed_parameter19::Value
		xfader10_p.getParameterT(3).connectT(0, smoothed_parameter20);   // xfader10 -> smoothed_parameter20::Value
		smoothed_parameter25.getParameter().connectT(0, global_cable24); // smoothed_parameter25 -> global_cable24::Value
		smoothed_parameter26.getParameter().connectT(0, global_cable25); // smoothed_parameter26 -> global_cable25::Value
		smoothed_parameter27.getParameter().connectT(0, global_cable26); // smoothed_parameter27 -> global_cable26::Value
		smoothed_parameter28.getParameter().connectT(0, global_cable27); // smoothed_parameter28 -> global_cable27::Value
		auto& xfader11_p = xfader11.getWrappedObject().getParameter();
		xfader11_p.getParameterT(0).connectT(0, smoothed_parameter25); // xfader11 -> smoothed_parameter25::Value
		xfader11_p.getParameterT(1).connectT(0, smoothed_parameter26); // xfader11 -> smoothed_parameter26::Value
		xfader11_p.getParameterT(2).connectT(0, smoothed_parameter27); // xfader11 -> smoothed_parameter27::Value
		xfader11_p.getParameterT(3).connectT(0, smoothed_parameter28); // xfader11 -> smoothed_parameter28::Value
		auto& switcher1_p = switcher1.getWrappedObject().getParameter();
		switcher1_p.getParameterT(0).connectT(0, sb5); // switcher1 -> sb5::Bypassed
		switcher1_p.getParameterT(1).connectT(0, sb6); // switcher1 -> sb6::Bypassed
		switcher1_p.getParameterT(2).connectT(0, sb7); // switcher1 -> sb7::Bypassed
		switcher1_p.getParameterT(3).connectT(0, sb8); // switcher1 -> sb8::Bypassed
		
		// Default Values --------------------------------------------------------------------------
		
		softbypass_switch6.setParameterT(0, 0.); // container::chain::Switch
		
		; // switcher1::Value is automated
		
		; // xfader13::Value is automated
		
		;                                          // smoothed_parameter41::Value is automated
		;                                          // smoothed_parameter41::SmoothingTime is automated
		smoothed_parameter41.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable40::Value is automated
		
		;                                          // smoothed_parameter42::Value is automated
		;                                          // smoothed_parameter42::SmoothingTime is automated
		smoothed_parameter42.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable41::Value is automated
		
		;                                          // smoothed_parameter43::Value is automated
		;                                          // smoothed_parameter43::SmoothingTime is automated
		smoothed_parameter43.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable42::Value is automated
		
		;                                          // smoothed_parameter44::Value is automated
		;                                          // smoothed_parameter44::SmoothingTime is automated
		smoothed_parameter44.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable43::Value is automated
		
		; // xfader12::Value is automated
		
		;                                          // smoothed_parameter33::Value is automated
		;                                          // smoothed_parameter33::SmoothingTime is automated
		smoothed_parameter33.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable32::Value is automated
		
		;                                          // smoothed_parameter34::Value is automated
		;                                          // smoothed_parameter34::SmoothingTime is automated
		smoothed_parameter34.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable33::Value is automated
		
		;                                          // smoothed_parameter35::Value is automated
		;                                          // smoothed_parameter35::SmoothingTime is automated
		smoothed_parameter35.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable34::Value is automated
		
		;                                          // smoothed_parameter36::Value is automated
		;                                          // smoothed_parameter36::SmoothingTime is automated
		smoothed_parameter36.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable35::Value is automated
		
		; // xfader10::Value is automated
		
		;                                          // smoothed_parameter17::Value is automated
		;                                          // smoothed_parameter17::SmoothingTime is automated
		smoothed_parameter17.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable16::Value is automated
		
		;                                          // smoothed_parameter18::Value is automated
		;                                          // smoothed_parameter18::SmoothingTime is automated
		smoothed_parameter18.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable17::Value is automated
		
		;                                          // smoothed_parameter19::Value is automated
		;                                          // smoothed_parameter19::SmoothingTime is automated
		smoothed_parameter19.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable18::Value is automated
		
		;                                          // smoothed_parameter20::Value is automated
		;                                          // smoothed_parameter20::SmoothingTime is automated
		smoothed_parameter20.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable19::Value is automated
		
		; // xfader11::Value is automated
		
		;                                          // smoothed_parameter25::Value is automated
		;                                          // smoothed_parameter25::SmoothingTime is automated
		smoothed_parameter25.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable24::Value is automated
		
		;                                          // smoothed_parameter26::Value is automated
		;                                          // smoothed_parameter26::SmoothingTime is automated
		smoothed_parameter26.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable25::Value is automated
		
		;                                          // smoothed_parameter27::Value is automated
		;                                          // smoothed_parameter27::SmoothingTime is automated
		smoothed_parameter27.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable26::Value is automated
		
		;                                          // smoothed_parameter28::Value is automated
		;                                          // smoothed_parameter28::SmoothingTime is automated
		smoothed_parameter28.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // global_cable27::Value is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 1.);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(0).  // routing::global_cable<global_cable40_t_index, parameter::empty>
        getT(0).getT(1).getT(0).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(0).  // routing::global_cable<global_cable41_t_index, parameter::empty>
        getT(0).getT(1).getT(1).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(0).  // routing::global_cable<global_cable42_t_index, parameter::empty>
        getT(0).getT(1).getT(2).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(0).  // routing::global_cable<global_cable43_t_index, parameter::empty>
        getT(0).getT(1).getT(3).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).  // routing::global_cable<global_cable32_t_index, parameter::empty>
        getT(0).getT(1).getT(0).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).  // routing::global_cable<global_cable33_t_index, parameter::empty>
        getT(0).getT(1).getT(1).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).  // routing::global_cable<global_cable34_t_index, parameter::empty>
        getT(0).getT(1).getT(2).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).  // routing::global_cable<global_cable35_t_index, parameter::empty>
        getT(0).getT(1).getT(3).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).  // routing::global_cable<global_cable16_t_index, parameter::empty>
        getT(0).getT(1).getT(0).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).  // routing::global_cable<global_cable17_t_index, parameter::empty>
        getT(0).getT(1).getT(1).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).  // routing::global_cable<global_cable18_t_index, parameter::empty>
        getT(0).getT(1).getT(2).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).  // routing::global_cable<global_cable19_t_index, parameter::empty>
        getT(0).getT(1).getT(3).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(3).  // routing::global_cable<global_cable24_t_index, parameter::empty>
        getT(0).getT(1).getT(0).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(3).  // routing::global_cable<global_cable25_t_index, parameter::empty>
        getT(0).getT(1).getT(1).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(3).  // routing::global_cable<global_cable26_t_index, parameter::empty>
        getT(0).getT(1).getT(2).getT(1).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(3).  // routing::global_cable<global_cable27_t_index, parameter::empty>
        getT(0).getT(1).getT(3).getT(1).connectToRuntimeTarget(addConnection, c);
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
using vecfade = wrap::node<vecfade_impl::instance<NV>>;
}


