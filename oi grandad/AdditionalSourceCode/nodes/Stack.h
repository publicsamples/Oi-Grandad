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

namespace Stack_impl
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
using global_cable77_t = routing::global_cable<global_cable77_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain94_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable77_t<NV>>, 
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

using cable_table16_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<0>>;
using granulator_t = wrap::data<core::granulator, 
                                data::external::audiofile<0>>;

using input_toggle16_mod = parameter::chain<ranges::Identity, 
                                            parameter::plain<cable_table16_t, 0>, 
                                            parameter::plain<granulator_t, 0>>;

template <int NV>
using input_toggle16_t = control::input_toggle<NV, input_toggle16_mod>;

using cable_table34_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<1>>;
using granulator1_t = granulator_t;

using input_toggle34_mod = parameter::chain<ranges::Identity, 
                                            parameter::plain<cable_table34_t, 0>, 
                                            parameter::plain<granulator1_t, 0>>;

template <int NV>
using input_toggle34_t = control::input_toggle<NV, input_toggle34_mod>;

using cable_table33_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<2>>;
using granulator2_t = granulator_t;

using input_toggle33_mod = parameter::chain<ranges::Identity, 
                                            parameter::plain<cable_table33_t, 0>, 
                                            parameter::plain<granulator2_t, 0>>;

template <int NV>
using input_toggle33_t = control::input_toggle<NV, input_toggle33_mod>;

using cable_table32_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<3>>;
using granulator3_t = granulator_t;

using input_toggle32_mod = parameter::chain<ranges::Identity, 
                                            parameter::plain<cable_table32_t, 0>, 
                                            parameter::plain<granulator3_t, 0>>;

template <int NV>
using input_toggle32_t = control::input_toggle<NV, input_toggle32_mod>;

template <int NV>
using sliderbank_multimod = parameter::list<parameter::plain<input_toggle16_t<NV>, 2>, 
                                            parameter::plain<input_toggle34_t<NV>, 2>, 
                                            parameter::plain<input_toggle33_t<NV>, 2>, 
                                            parameter::plain<input_toggle32_t<NV>, 2>>;

template <int NV>
using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod<NV>>, 
                                data::external::sliderpack<0>>;
DECLARE_PARAMETER_RANGE(pma12_mod_4Range, 
                        6.66134e-16, 
                        1.);

template <int NV>
using pma12_mod_4 = parameter::from0To1<sliderbank_t<NV>, 
                                        0, 
                                        pma12_mod_4Range>;

template <int NV>
using pma12_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<input_toggle16_t<NV>, 1>, 
                                   parameter::plain<input_toggle34_t<NV>, 1>, 
                                   parameter::plain<input_toggle33_t<NV>, 1>, 
                                   parameter::plain<input_toggle32_t<NV>, 1>, 
                                   pma12_mod_4<NV>>;

template <int NV>
using pma12_t = control::pma<NV, pma12_mod<NV>>;
template <int NV>
using peak6_t = wrap::mod<parameter::plain<pma12_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

namespace chain80_t_parameters
{
}

template <int NV>
using chain80_t = container::chain<parameter::plain<Stack_impl::branch4_t<NV>, 0>, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   branch4_t<NV>, 
                                   peak6_t<NV>, 
                                   pma12_t<NV>, 
                                   sliderbank_t<NV>, 
                                   math::clear<NV>>;
using global_cable96_t_index = global_cable64_t_index;

template <int NV>
using global_cable96_t = routing::global_cable<global_cable96_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain115_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable96_t<NV>>, 
                                    math::add<NV>>;
using global_cable97_t_index = global_cable65_t_index;

template <int NV>
using global_cable97_t = routing::global_cable<global_cable97_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain116_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable97_t<NV>>, 
                                    math::add<NV>>;
using global_cable98_t_index = global_cable66_t_index;

template <int NV>
using global_cable98_t = routing::global_cable<global_cable98_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain117_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable98_t<NV>>, 
                                    math::add<NV>>;
using global_cable99_t_index = global_cable67_t_index;

template <int NV>
using global_cable99_t = routing::global_cable<global_cable99_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain118_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable99_t<NV>>, 
                                    math::add<NV>>;
using global_cable100_t_index = global_cable68_t_index;

template <int NV>
using global_cable100_t = routing::global_cable<global_cable100_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain119_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable100_t<NV>>, 
                                    math::add<NV>>;
using global_cable101_t_index = global_cable69_t_index;

template <int NV>
using global_cable101_t = routing::global_cable<global_cable101_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain120_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable101_t<NV>>, 
                                    math::add<NV>>;
using global_cable102_t_index = global_cable70_t_index;

template <int NV>
using global_cable102_t = routing::global_cable<global_cable102_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain121_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable102_t<NV>>, 
                                    math::add<NV>>;
using global_cable103_t_index = global_cable71_t_index;

template <int NV>
using global_cable103_t = routing::global_cable<global_cable103_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain122_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable103_t<NV>>, 
                                    math::add<NV>>;
using global_cable104_t_index = global_cable72_t_index;

template <int NV>
using global_cable104_t = routing::global_cable<global_cable104_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain123_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable104_t<NV>>, 
                                    math::add<NV>>;
using global_cable105_t_index = global_cable73_t_index;

template <int NV>
using global_cable105_t = routing::global_cable<global_cable105_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain124_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable105_t<NV>>, 
                                    math::add<NV>>;
using global_cable106_t_index = global_cable74_t_index;

template <int NV>
using global_cable106_t = routing::global_cable<global_cable106_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain125_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable106_t<NV>>, 
                                    math::add<NV>>;
using global_cable107_t_index = global_cable75_t_index;

template <int NV>
using global_cable107_t = routing::global_cable<global_cable107_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain126_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable107_t<NV>>, 
                                    math::add<NV>>;
using global_cable108_t_index = global_cable76_t_index;

template <int NV>
using global_cable108_t = routing::global_cable<global_cable108_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain127_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable108_t<NV>>, 
                                    math::add<NV>>;
using global_cable109_t_index = global_cable77_t_index;

template <int NV>
using global_cable109_t = routing::global_cable<global_cable109_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain128_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable109_t<NV>>, 
                                    math::add<NV>>;
using global_cable110_t_index = global_cable78_t_index;

template <int NV>
using global_cable110_t = routing::global_cable<global_cable110_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain129_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable110_t<NV>>, 
                                    math::add<NV>>;
using global_cable111_t_index = global_cable79_t_index;

template <int NV>
using global_cable111_t = routing::global_cable<global_cable111_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain130_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable111_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain115_t<NV>>, 
                                    chain116_t<NV>, 
                                    chain117_t<NV>, 
                                    chain118_t<NV>, 
                                    chain119_t<NV>, 
                                    chain120_t<NV>, 
                                    chain121_t<NV>, 
                                    chain122_t<NV>, 
                                    chain123_t<NV>, 
                                    chain124_t<NV>, 
                                    chain125_t<NV>, 
                                    chain126_t<NV>, 
                                    chain127_t<NV>, 
                                    chain128_t<NV>, 
                                    chain129_t<NV>, 
                                    chain130_t<NV>>;

template <int NV>
using input_toggle2_t = control::input_toggle<NV, 
                                              parameter::plain<project::PitchShifter<NV>, 0>>;
template <int NV>
using minmax1_t = control::minmax<NV, 
                                  parameter::plain<input_toggle2_t<NV>, 2>>;

template <int NV> using input_toggle11_t = input_toggle2_t<NV>;
template <int NV>
using minmax7_t = control::minmax<NV, 
                                  parameter::plain<input_toggle11_t<NV>, 2>>;

template <int NV> using input_toggle10_t = input_toggle2_t<NV>;
template <int NV>
using minmax6_t = control::minmax<NV, 
                                  parameter::plain<input_toggle10_t<NV>, 2>>;

template <int NV> using input_toggle9_t = input_toggle2_t<NV>;
template <int NV>
using minmax5_t = control::minmax<NV, 
                                  parameter::plain<input_toggle9_t<NV>, 2>>;
template <int NV>
using sliderbank1_multimod = parameter::list<parameter::plain<minmax1_t<NV>, 0>, 
                                             parameter::plain<minmax7_t<NV>, 0>, 
                                             parameter::plain<minmax6_t<NV>, 0>, 
                                             parameter::plain<minmax5_t<NV>, 0>>;

template <int NV>
using sliderbank1_t = wrap::data<control::sliderbank<sliderbank1_multimod<NV>>, 
                                 data::external::sliderpack<1>>;
template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<sliderbank1_t<NV>, 0>>;

template <int NV>
using pma_unscaled_mod = parameter::chain<ranges::Identity, 
                                          parameter::plain<input_toggle2_t<NV>, 1>, 
                                          parameter::plain<input_toggle9_t<NV>, 1>, 
                                          parameter::plain<input_toggle10_t<NV>, 1>, 
                                          parameter::plain<input_toggle11_t<NV>, 1>>;

template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, pma_unscaled_mod<NV>>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma_unscaled_t<NV>, 2>>;
template <int NV>
using pma4_t = control::pma<NV, 
                            parameter::plain<minmax_t<NV>, 0>>;

template <int NV>
using peak8_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma_t<NV>, 0>, 
                                   parameter::plain<pma4_t<NV>, 0>>;

template <int NV>
using peak8_t = wrap::mod<peak8_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, minmax1_t<NV>>, 
                                  minmax7_t<NV>, 
                                  minmax6_t<NV>, 
                                  minmax5_t<NV>>;

namespace chain114_t_parameters
{
}

template <int NV>
using chain114_t = container::chain<parameter::plain<Stack_impl::branch6_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch6_t<NV>, 
                                    peak8_t<NV>, 
                                    pma4_t<NV>, 
                                    minmax_t<NV>, 
                                    pma_unscaled_t<NV>, 
                                    pma_t<NV>, 
                                    sliderbank1_t<NV>, 
                                    split3_t<NV>, 
                                    math::clear<NV>>;
using global_cable80_t_index = global_cable64_t_index;

template <int NV>
using global_cable80_t = routing::global_cable<global_cable80_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain98_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable80_t<NV>>, 
                                   math::add<NV>>;
using global_cable81_t_index = global_cable65_t_index;

template <int NV>
using global_cable81_t = routing::global_cable<global_cable81_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain99_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable81_t<NV>>, 
                                   math::add<NV>>;
using global_cable82_t_index = global_cable66_t_index;

template <int NV>
using global_cable82_t = routing::global_cable<global_cable82_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain100_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable82_t<NV>>, 
                                    math::add<NV>>;
using global_cable83_t_index = global_cable67_t_index;

template <int NV>
using global_cable83_t = routing::global_cable<global_cable83_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain101_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable83_t<NV>>, 
                                    math::add<NV>>;
using global_cable84_t_index = global_cable68_t_index;

template <int NV>
using global_cable84_t = routing::global_cable<global_cable84_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain102_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable84_t<NV>>, 
                                    math::add<NV>>;
using global_cable85_t_index = global_cable69_t_index;

template <int NV>
using global_cable85_t = routing::global_cable<global_cable85_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain103_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable85_t<NV>>, 
                                    math::add<NV>>;
using global_cable86_t_index = global_cable70_t_index;

template <int NV>
using global_cable86_t = routing::global_cable<global_cable86_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain104_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable86_t<NV>>, 
                                    math::add<NV>>;
using global_cable87_t_index = global_cable71_t_index;

template <int NV>
using global_cable87_t = routing::global_cable<global_cable87_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain105_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable87_t<NV>>, 
                                    math::add<NV>>;
using global_cable88_t_index = global_cable72_t_index;

template <int NV>
using global_cable88_t = routing::global_cable<global_cable88_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain106_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable88_t<NV>>, 
                                    math::add<NV>>;
using global_cable89_t_index = global_cable73_t_index;

template <int NV>
using global_cable89_t = routing::global_cable<global_cable89_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain107_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable89_t<NV>>, 
                                    math::add<NV>>;
using global_cable90_t_index = global_cable74_t_index;

template <int NV>
using global_cable90_t = routing::global_cable<global_cable90_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain108_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable90_t<NV>>, 
                                    math::add<NV>>;
using global_cable91_t_index = global_cable75_t_index;

template <int NV>
using global_cable91_t = routing::global_cable<global_cable91_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain109_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable91_t<NV>>, 
                                    math::add<NV>>;
using global_cable92_t_index = global_cable76_t_index;

template <int NV>
using global_cable92_t = routing::global_cable<global_cable92_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain110_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable92_t<NV>>, 
                                    math::add<NV>>;
using global_cable93_t_index = global_cable77_t_index;

template <int NV>
using global_cable93_t = routing::global_cable<global_cable93_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain111_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable93_t<NV>>, 
                                    math::add<NV>>;
using global_cable94_t_index = global_cable78_t_index;

template <int NV>
using global_cable94_t = routing::global_cable<global_cable94_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain112_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable94_t<NV>>, 
                                    math::add<NV>>;
using global_cable95_t_index = global_cable79_t_index;

template <int NV>
using global_cable95_t = routing::global_cable<global_cable95_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain113_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable95_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain98_t<NV>>, 
                                    chain99_t<NV>, 
                                    chain100_t<NV>, 
                                    chain101_t<NV>, 
                                    chain102_t<NV>, 
                                    chain103_t<NV>, 
                                    chain104_t<NV>, 
                                    chain105_t<NV>, 
                                    chain106_t<NV>, 
                                    chain107_t<NV>, 
                                    chain108_t<NV>, 
                                    chain109_t<NV>, 
                                    chain110_t<NV>, 
                                    chain111_t<NV>, 
                                    chain112_t<NV>, 
                                    chain113_t<NV>>;

template <int NV>
using pma13_t = control::pma<NV, 
                             parameter::plain<math::add<NV>, 0>>;

template <int NV> using pma21_t = pma13_t<NV>;

template <int NV>
using peak7_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma13_t<NV>, 0>, 
                                   parameter::plain<pma21_t<NV>, 0>>;

template <int NV>
using peak7_t = wrap::mod<peak7_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, pma13_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma21_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain9_t<NV>>, 
                                    chain10_t<NV>>;

template <int NV>
using minmax8_t = control::minmax<NV, 
                                  parameter::plain<granulator_t, 2>>;
template <int NV>
using tempo_sync2_t = wrap::mod<parameter::plain<minmax8_t<NV>, 1>, 
                                control::tempo_sync<NV>>;

template <int NV>
using minmax15_t = control::minmax<NV, 
                                   parameter::plain<granulator3_t, 2>>;
template <int NV>
using tempo_sync12_t = wrap::mod<parameter::plain<minmax15_t<NV>, 1>, 
                                 control::tempo_sync<NV>>;

template <int NV>
using minmax13_t = control::minmax<NV, 
                                   parameter::plain<granulator2_t, 2>>;
template <int NV>
using tempo_sync11_t = wrap::mod<parameter::plain<minmax13_t<NV>, 1>, 
                                 control::tempo_sync<NV>>;

template <int NV>
using minmax11_t = control::minmax<NV, 
                                   parameter::plain<granulator1_t, 2>>;
template <int NV>
using tempo_sync10_t = wrap::mod<parameter::plain<minmax11_t<NV>, 1>, 
                                 control::tempo_sync<NV>>;

template <int NV>
using minmax14_t = control::minmax<NV, 
                                   parameter::plain<tempo_sync12_t<NV>, 3>>;

template <int NV>
using minmax12_t = control::minmax<NV, 
                                   parameter::plain<tempo_sync11_t<NV>, 3>>;

template <int NV>
using minmax10_t = control::minmax<NV, 
                                   parameter::plain<tempo_sync10_t<NV>, 3>>;

template <int NV>
using minmax9_t = control::minmax<NV, 
                                  parameter::plain<tempo_sync2_t<NV>, 3>>;
DECLARE_PARAMETER_RANGE_STEP(peak_mod_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using peak_mod_0 = parameter::from0To1<tempo_sync2_t<NV>, 
                                       0, 
                                       peak_mod_0Range>;

template <int NV>
using peak_mod_1 = parameter::from0To1<tempo_sync12_t<NV>, 
                                       0, 
                                       peak_mod_0Range>;

template <int NV>
using peak_mod_2 = parameter::from0To1<tempo_sync11_t<NV>, 
                                       0, 
                                       peak_mod_0Range>;

template <int NV>
using peak_mod_3 = parameter::from0To1<tempo_sync10_t<NV>, 
                                       0, 
                                       peak_mod_0Range>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  peak_mod_0<NV>, 
                                  peak_mod_1<NV>, 
                                  peak_mod_2<NV>, 
                                  peak_mod_3<NV>, 
                                  parameter::plain<minmax14_t<NV>, 0>, 
                                  parameter::plain<minmax12_t<NV>, 0>, 
                                  parameter::plain<minmax10_t<NV>, 0>, 
                                  parameter::plain<minmax9_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   branch2_t<NV>, 
                                   peak_t<NV>>;

namespace chain97_t_parameters
{
}

template <int NV>
using chain97_t = container::chain<parameter::plain<Stack_impl::branch5_t<NV>, 0>, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   branch5_t<NV>, 
                                   peak7_t<NV>, 
                                   chain11_t<NV>, 
                                   math::clear<NV>>;
using global_cable112_t_index = global_cable64_t_index;

template <int NV>
using global_cable112_t = routing::global_cable<global_cable112_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain132_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable112_t<NV>>, 
                                    math::add<NV>>;
using global_cable113_t_index = global_cable65_t_index;

template <int NV>
using global_cable113_t = routing::global_cable<global_cable113_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain133_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable113_t<NV>>, 
                                    math::add<NV>>;
using global_cable114_t_index = global_cable66_t_index;

template <int NV>
using global_cable114_t = routing::global_cable<global_cable114_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain134_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable114_t<NV>>, 
                                    math::add<NV>>;
using global_cable115_t_index = global_cable67_t_index;

template <int NV>
using global_cable115_t = routing::global_cable<global_cable115_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain135_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable115_t<NV>>, 
                                    math::add<NV>>;
using global_cable116_t_index = global_cable68_t_index;

template <int NV>
using global_cable116_t = routing::global_cable<global_cable116_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain136_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable116_t<NV>>, 
                                    math::add<NV>>;
using global_cable117_t_index = global_cable69_t_index;

template <int NV>
using global_cable117_t = routing::global_cable<global_cable117_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain137_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable117_t<NV>>, 
                                    math::add<NV>>;
using global_cable118_t_index = global_cable70_t_index;

template <int NV>
using global_cable118_t = routing::global_cable<global_cable118_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain138_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable118_t<NV>>, 
                                    math::add<NV>>;
using global_cable119_t_index = global_cable71_t_index;

template <int NV>
using global_cable119_t = routing::global_cable<global_cable119_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain139_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable119_t<NV>>, 
                                    math::add<NV>>;
using global_cable120_t_index = global_cable72_t_index;

template <int NV>
using global_cable120_t = routing::global_cable<global_cable120_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain140_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable120_t<NV>>, 
                                    math::add<NV>>;
using global_cable121_t_index = global_cable73_t_index;

template <int NV>
using global_cable121_t = routing::global_cable<global_cable121_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain141_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable121_t<NV>>, 
                                    math::add<NV>>;
using global_cable122_t_index = global_cable74_t_index;

template <int NV>
using global_cable122_t = routing::global_cable<global_cable122_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain142_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable122_t<NV>>, 
                                    math::add<NV>>;
using global_cable123_t_index = global_cable75_t_index;

template <int NV>
using global_cable123_t = routing::global_cable<global_cable123_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain143_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable123_t<NV>>, 
                                    math::add<NV>>;
using global_cable124_t_index = global_cable76_t_index;

template <int NV>
using global_cable124_t = routing::global_cable<global_cable124_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain144_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable124_t<NV>>, 
                                    math::add<NV>>;
using global_cable125_t_index = global_cable77_t_index;

template <int NV>
using global_cable125_t = routing::global_cable<global_cable125_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain145_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable125_t<NV>>, 
                                    math::add<NV>>;
using global_cable126_t_index = global_cable78_t_index;

template <int NV>
using global_cable126_t = routing::global_cable<global_cable126_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain146_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable126_t<NV>>, 
                                    math::add<NV>>;
using global_cable127_t_index = global_cable79_t_index;

template <int NV>
using global_cable127_t = routing::global_cable<global_cable127_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain147_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable127_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain132_t<NV>>, 
                                    chain133_t<NV>, 
                                    chain134_t<NV>, 
                                    chain135_t<NV>, 
                                    chain136_t<NV>, 
                                    chain137_t<NV>, 
                                    chain138_t<NV>, 
                                    chain139_t<NV>, 
                                    chain140_t<NV>, 
                                    chain141_t<NV>, 
                                    chain142_t<NV>, 
                                    chain143_t<NV>, 
                                    chain144_t<NV>, 
                                    chain145_t<NV>, 
                                    chain146_t<NV>, 
                                    chain147_t<NV>>;

using pma15_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<granulator_t, 3>, 
                                   parameter::plain<granulator1_t, 3>, 
                                   parameter::plain<granulator2_t, 3>, 
                                   parameter::plain<granulator3_t, 3>>;

template <int NV>
using pma15_t = control::pma<NV, pma15_mod>;
template <int NV>
using peak9_t = wrap::mod<parameter::plain<pma15_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

namespace chain131_t_parameters
{
}

template <int NV>
using chain131_t = container::chain<parameter::plain<Stack_impl::branch7_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch7_t<NV>, 
                                    peak9_t<NV>, 
                                    pma15_t<NV>, 
                                    math::clear<NV>>;
using global_cable192_t_index = global_cable64_t_index;

template <int NV>
using global_cable192_t = routing::global_cable<global_cable192_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain217_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable192_t<NV>>, 
                                    math::add<NV>>;
using global_cable193_t_index = global_cable65_t_index;

template <int NV>
using global_cable193_t = routing::global_cable<global_cable193_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain218_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable193_t<NV>>, 
                                    math::add<NV>>;
using global_cable194_t_index = global_cable66_t_index;

template <int NV>
using global_cable194_t = routing::global_cable<global_cable194_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain219_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable194_t<NV>>, 
                                    math::add<NV>>;
using global_cable195_t_index = global_cable67_t_index;

template <int NV>
using global_cable195_t = routing::global_cable<global_cable195_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain220_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable195_t<NV>>, 
                                    math::add<NV>>;
using global_cable196_t_index = global_cable68_t_index;

template <int NV>
using global_cable196_t = routing::global_cable<global_cable196_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain221_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable196_t<NV>>, 
                                    math::add<NV>>;
using global_cable197_t_index = global_cable69_t_index;

template <int NV>
using global_cable197_t = routing::global_cable<global_cable197_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain222_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable197_t<NV>>, 
                                    math::add<NV>>;
using global_cable198_t_index = global_cable70_t_index;

template <int NV>
using global_cable198_t = routing::global_cable<global_cable198_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain223_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable198_t<NV>>, 
                                    math::add<NV>>;
using global_cable199_t_index = global_cable71_t_index;

template <int NV>
using global_cable199_t = routing::global_cable<global_cable199_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain224_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable199_t<NV>>, 
                                    math::add<NV>>;
using global_cable200_t_index = global_cable72_t_index;

template <int NV>
using global_cable200_t = routing::global_cable<global_cable200_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain225_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable200_t<NV>>, 
                                    math::add<NV>>;
using global_cable201_t_index = global_cable73_t_index;

template <int NV>
using global_cable201_t = routing::global_cable<global_cable201_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain226_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable201_t<NV>>, 
                                    math::add<NV>>;
using global_cable202_t_index = global_cable74_t_index;

template <int NV>
using global_cable202_t = routing::global_cable<global_cable202_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain227_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable202_t<NV>>, 
                                    math::add<NV>>;
using global_cable203_t_index = global_cable75_t_index;

template <int NV>
using global_cable203_t = routing::global_cable<global_cable203_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain228_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable203_t<NV>>, 
                                    math::add<NV>>;
using global_cable204_t_index = global_cable76_t_index;

template <int NV>
using global_cable204_t = routing::global_cable<global_cable204_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain229_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable204_t<NV>>, 
                                    math::add<NV>>;
using global_cable205_t_index = global_cable77_t_index;

template <int NV>
using global_cable205_t = routing::global_cable<global_cable205_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain230_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable205_t<NV>>, 
                                    math::add<NV>>;
using global_cable206_t_index = global_cable78_t_index;

template <int NV>
using global_cable206_t = routing::global_cable<global_cable206_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain231_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable206_t<NV>>, 
                                    math::add<NV>>;
using global_cable207_t_index = global_cable79_t_index;

template <int NV>
using global_cable207_t = routing::global_cable<global_cable207_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain232_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable207_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch12_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain217_t<NV>>, 
                                     chain218_t<NV>, 
                                     chain219_t<NV>, 
                                     chain220_t<NV>, 
                                     chain221_t<NV>, 
                                     chain222_t<NV>, 
                                     chain223_t<NV>, 
                                     chain224_t<NV>, 
                                     chain225_t<NV>, 
                                     chain226_t<NV>, 
                                     chain227_t<NV>, 
                                     chain228_t<NV>, 
                                     chain229_t<NV>, 
                                     chain230_t<NV>, 
                                     chain231_t<NV>, 
                                     chain232_t<NV>>;

using pma20_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<granulator_t, 4>, 
                                   parameter::plain<granulator1_t, 4>, 
                                   parameter::plain<granulator2_t, 4>, 
                                   parameter::plain<granulator3_t, 4>>;

template <int NV>
using pma20_t = control::pma<NV, pma20_mod>;
template <int NV>
using peak14_t = wrap::mod<parameter::plain<pma20_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

namespace chain216_t_parameters
{
}

template <int NV>
using chain216_t = container::chain<parameter::plain<Stack_impl::branch12_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch12_t<NV>, 
                                    peak14_t<NV>, 
                                    pma20_t<NV>, 
                                    math::clear<NV>>;
using global_cable176_t_index = global_cable64_t_index;

template <int NV>
using global_cable176_t = routing::global_cable<global_cable176_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain200_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable176_t<NV>>, 
                                    math::add<NV>>;
using global_cable177_t_index = global_cable65_t_index;

template <int NV>
using global_cable177_t = routing::global_cable<global_cable177_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain201_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable177_t<NV>>, 
                                    math::add<NV>>;
using global_cable178_t_index = global_cable66_t_index;

template <int NV>
using global_cable178_t = routing::global_cable<global_cable178_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain202_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable178_t<NV>>, 
                                    math::add<NV>>;
using global_cable179_t_index = global_cable67_t_index;

template <int NV>
using global_cable179_t = routing::global_cable<global_cable179_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain203_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable179_t<NV>>, 
                                    math::add<NV>>;
using global_cable180_t_index = global_cable68_t_index;

template <int NV>
using global_cable180_t = routing::global_cable<global_cable180_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain204_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable180_t<NV>>, 
                                    math::add<NV>>;
using global_cable181_t_index = global_cable69_t_index;

template <int NV>
using global_cable181_t = routing::global_cable<global_cable181_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain205_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable181_t<NV>>, 
                                    math::add<NV>>;
using global_cable182_t_index = global_cable70_t_index;

template <int NV>
using global_cable182_t = routing::global_cable<global_cable182_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain206_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable182_t<NV>>, 
                                    math::add<NV>>;
using global_cable183_t_index = global_cable71_t_index;

template <int NV>
using global_cable183_t = routing::global_cable<global_cable183_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain207_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable183_t<NV>>, 
                                    math::add<NV>>;
using global_cable184_t_index = global_cable72_t_index;

template <int NV>
using global_cable184_t = routing::global_cable<global_cable184_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain208_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable184_t<NV>>, 
                                    math::add<NV>>;
using global_cable185_t_index = global_cable73_t_index;

template <int NV>
using global_cable185_t = routing::global_cable<global_cable185_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain209_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable185_t<NV>>, 
                                    math::add<NV>>;
using global_cable186_t_index = global_cable74_t_index;

template <int NV>
using global_cable186_t = routing::global_cable<global_cable186_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain210_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable186_t<NV>>, 
                                    math::add<NV>>;
using global_cable187_t_index = global_cable75_t_index;

template <int NV>
using global_cable187_t = routing::global_cable<global_cable187_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain211_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable187_t<NV>>, 
                                    math::add<NV>>;
using global_cable188_t_index = global_cable76_t_index;

template <int NV>
using global_cable188_t = routing::global_cable<global_cable188_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain212_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable188_t<NV>>, 
                                    math::add<NV>>;
using global_cable189_t_index = global_cable77_t_index;

template <int NV>
using global_cable189_t = routing::global_cable<global_cable189_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain213_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable189_t<NV>>, 
                                    math::add<NV>>;
using global_cable190_t_index = global_cable78_t_index;

template <int NV>
using global_cable190_t = routing::global_cable<global_cable190_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain214_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable190_t<NV>>, 
                                    math::add<NV>>;
using global_cable191_t_index = global_cable79_t_index;

template <int NV>
using global_cable191_t = routing::global_cable<global_cable191_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain215_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable191_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch11_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain200_t<NV>>, 
                                     chain201_t<NV>, 
                                     chain202_t<NV>, 
                                     chain203_t<NV>, 
                                     chain204_t<NV>, 
                                     chain205_t<NV>, 
                                     chain206_t<NV>, 
                                     chain207_t<NV>, 
                                     chain208_t<NV>, 
                                     chain209_t<NV>, 
                                     chain210_t<NV>, 
                                     chain211_t<NV>, 
                                     chain212_t<NV>, 
                                     chain213_t<NV>, 
                                     chain214_t<NV>, 
                                     chain215_t<NV>>;

using pma19_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<granulator_t, 5>, 
                                   parameter::plain<granulator3_t, 5>, 
                                   parameter::plain<granulator2_t, 5>, 
                                   parameter::plain<granulator1_t, 5>>;

template <int NV>
using pma19_t = control::pma<NV, pma19_mod>;
template <int NV>
using peak13_t = wrap::mod<parameter::plain<pma19_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

namespace chain199_t_parameters
{
}

template <int NV>
using chain199_t = container::chain<parameter::plain<Stack_impl::branch11_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch11_t<NV>, 
                                    peak13_t<NV>, 
                                    pma19_t<NV>, 
                                    math::clear<NV>>;
using global_cable208_t_index = global_cable64_t_index;

template <int NV>
using global_cable208_t = routing::global_cable<global_cable208_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain234_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable208_t<NV>>, 
                                    math::add<NV>>;
using global_cable209_t_index = global_cable65_t_index;

template <int NV>
using global_cable209_t = routing::global_cable<global_cable209_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain235_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable209_t<NV>>, 
                                    math::add<NV>>;
using global_cable210_t_index = global_cable66_t_index;

template <int NV>
using global_cable210_t = routing::global_cable<global_cable210_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain236_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable210_t<NV>>, 
                                    math::add<NV>>;
using global_cable211_t_index = global_cable67_t_index;

template <int NV>
using global_cable211_t = routing::global_cable<global_cable211_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain237_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable211_t<NV>>, 
                                    math::add<NV>>;
using global_cable212_t_index = global_cable68_t_index;

template <int NV>
using chain238_t = container::chain<parameter::empty, 
                                    wrap::fix<1, routing::global_cable<global_cable212_t_index, parameter::empty>>, 
                                    math::add<NV>>;
using global_cable213_t_index = global_cable69_t_index;

template <int NV>
using global_cable213_t = routing::global_cable<global_cable213_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain239_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable213_t<NV>>, 
                                    math::add<NV>>;
using global_cable214_t_index = global_cable70_t_index;

template <int NV>
using global_cable214_t = routing::global_cable<global_cable214_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain240_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable214_t<NV>>, 
                                    math::add<NV>>;
using global_cable215_t_index = global_cable71_t_index;

template <int NV>
using global_cable215_t = routing::global_cable<global_cable215_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain241_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable215_t<NV>>, 
                                    math::add<NV>>;
using global_cable216_t_index = global_cable72_t_index;

template <int NV>
using global_cable216_t = routing::global_cable<global_cable216_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain242_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable216_t<NV>>, 
                                    math::add<NV>>;
using global_cable217_t_index = global_cable73_t_index;

template <int NV>
using global_cable217_t = routing::global_cable<global_cable217_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain243_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable217_t<NV>>, 
                                    math::add<NV>>;
using global_cable218_t_index = global_cable74_t_index;

template <int NV>
using global_cable218_t = routing::global_cable<global_cable218_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain244_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable218_t<NV>>, 
                                    math::add<NV>>;
using global_cable219_t_index = global_cable75_t_index;

template <int NV>
using global_cable219_t = routing::global_cable<global_cable219_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain245_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable219_t<NV>>, 
                                    math::add<NV>>;
using global_cable220_t_index = global_cable76_t_index;

template <int NV>
using global_cable220_t = routing::global_cable<global_cable220_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain246_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable220_t<NV>>, 
                                    math::add<NV>>;
using global_cable221_t_index = global_cable77_t_index;

template <int NV>
using global_cable221_t = routing::global_cable<global_cable221_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain247_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable221_t<NV>>, 
                                    math::add<NV>>;
using global_cable222_t_index = global_cable78_t_index;

template <int NV>
using global_cable222_t = routing::global_cable<global_cable222_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain248_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable222_t<NV>>, 
                                    math::add<NV>>;
using global_cable223_t_index = global_cable79_t_index;

template <int NV>
using global_cable223_t = routing::global_cable<global_cable223_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain249_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable223_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch13_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain234_t<NV>>, 
                                     chain235_t<NV>, 
                                     chain236_t<NV>, 
                                     chain237_t<NV>, 
                                     chain238_t<NV>, 
                                     chain239_t<NV>, 
                                     chain240_t<NV>, 
                                     chain241_t<NV>, 
                                     chain242_t<NV>, 
                                     chain243_t<NV>, 
                                     chain244_t<NV>, 
                                     chain245_t<NV>, 
                                     chain246_t<NV>, 
                                     chain247_t<NV>, 
                                     chain248_t<NV>, 
                                     chain249_t<NV>>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<project::PitchShifter<NV>, 1>, 
                               control::tempo_sync<NV>>;

template <int NV> using tempo_sync3_t = tempo_sync_t<NV>;

template <int NV> using tempo_sync5_t = tempo_sync_t<NV>;

template <int NV>
using tempo_sync7_mod = parameter::chain<ranges::Identity, 
                                         parameter::plain<project::PitchShifter<NV>, 1>, 
                                         parameter::plain<project::PitchShifter<NV>, 2>>;

template <int NV>
using tempo_sync7_t = wrap::mod<tempo_sync7_mod<NV>, 
                                control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma22_mod_1Range, 
                             50., 
                             10000., 
                             0.1);

template <int NV>
using pma22_mod_1 = parameter::from0To1<tempo_sync_t<NV>, 
                                        3, 
                                        pma22_mod_1Range>;

DECLARE_PARAMETER_RANGE_STEP(pma22_mod_2Range, 
                             50., 
                             10000., 
                             0.1);

template <int NV>
using pma22_mod_2 = parameter::from0To1<tempo_sync3_t<NV>, 
                                        3, 
                                        pma22_mod_2Range>;

template <int NV>
using pma22_mod_3 = parameter::from0To1<tempo_sync5_t<NV>, 
                                        3, 
                                        pma22_mod_1Range>;

template <int NV>
using pma22_mod_4 = parameter::from0To1<tempo_sync7_t<NV>, 
                                        3, 
                                        pma22_mod_1Range>;

template <int NV>
using pma22_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   pma22_mod_1<NV>, 
                                   pma22_mod_2<NV>, 
                                   pma22_mod_3<NV>, 
                                   pma22_mod_4<NV>>;

template <int NV>
using pma22_t = control::pma<NV, pma22_mod<NV>>;

template <int NV>
using pma23_mod_1 = parameter::from0To1<tempo_sync7_t<NV>, 
                                        0, 
                                        peak_mod_0Range>;

template <int NV>
using pma23_mod_2 = parameter::from0To1<tempo_sync5_t<NV>, 
                                        0, 
                                        peak_mod_0Range>;

template <int NV>
using pma23_mod_3 = parameter::from0To1<tempo_sync3_t<NV>, 
                                        0, 
                                        peak_mod_0Range>;

template <int NV>
using pma23_mod_4 = parameter::from0To1<tempo_sync_t<NV>, 
                                        0, 
                                        peak_mod_0Range>;

template <int NV>
using pma23_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   pma23_mod_1<NV>, 
                                   pma23_mod_2<NV>, 
                                   pma23_mod_3<NV>, 
                                   pma23_mod_4<NV>>;

template <int NV>
using pma23_t = control::pma<NV, pma23_mod<NV>>;

template <int NV>
using peak15_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<pma22_t<NV>, 0>, 
                                    parameter::plain<pma23_t<NV>, 0>>;

template <int NV>
using peak15_t = wrap::mod<peak15_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma22_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma23_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch14_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain15_t<NV>>, 
                                     chain16_t<NV>>;
using peak1_t = wrap::no_data<core::peak>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   branch14_t<NV>, 
                                   peak1_t>;

namespace chain233_t_parameters
{
}

template <int NV>
using chain233_t = container::chain<parameter::plain<Stack_impl::branch13_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch13_t<NV>, 
                                    peak15_t<NV>, 
                                    chain14_t<NV>, 
                                    math::clear<NV>>;
using global_cable272_t_index = global_cable64_t_index;

template <int NV>
using global_cable272_t = routing::global_cable<global_cable272_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain302_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable272_t<NV>>, 
                                    math::add<NV>>;
using global_cable273_t_index = global_cable65_t_index;

template <int NV>
using global_cable273_t = routing::global_cable<global_cable273_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain303_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable273_t<NV>>, 
                                    math::add<NV>>;
using global_cable274_t_index = global_cable66_t_index;

template <int NV>
using global_cable274_t = routing::global_cable<global_cable274_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain304_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable274_t<NV>>, 
                                    math::add<NV>>;
using global_cable275_t_index = global_cable67_t_index;

template <int NV>
using global_cable275_t = routing::global_cable<global_cable275_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain305_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable275_t<NV>>, 
                                    math::add<NV>>;
using global_cable276_t_index = global_cable68_t_index;

template <int NV>
using global_cable276_t = routing::global_cable<global_cable276_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain306_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable276_t<NV>>, 
                                    math::add<NV>>;
using global_cable277_t_index = global_cable69_t_index;

template <int NV>
using global_cable277_t = routing::global_cable<global_cable277_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain307_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable277_t<NV>>, 
                                    math::add<NV>>;
using global_cable278_t_index = global_cable70_t_index;

template <int NV>
using global_cable278_t = routing::global_cable<global_cable278_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain308_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable278_t<NV>>, 
                                    math::add<NV>>;
using global_cable279_t_index = global_cable71_t_index;

template <int NV>
using global_cable279_t = routing::global_cable<global_cable279_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain309_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable279_t<NV>>, 
                                    math::add<NV>>;
using global_cable280_t_index = global_cable72_t_index;

template <int NV>
using global_cable280_t = routing::global_cable<global_cable280_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain310_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable280_t<NV>>, 
                                    math::add<NV>>;
using global_cable281_t_index = global_cable73_t_index;

template <int NV>
using global_cable281_t = routing::global_cable<global_cable281_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain311_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable281_t<NV>>, 
                                    math::add<NV>>;
using global_cable282_t_index = global_cable74_t_index;

template <int NV>
using global_cable282_t = routing::global_cable<global_cable282_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain312_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable282_t<NV>>, 
                                    math::add<NV>>;
using global_cable283_t_index = global_cable75_t_index;

template <int NV>
using global_cable283_t = routing::global_cable<global_cable283_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain313_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable283_t<NV>>, 
                                    math::add<NV>>;
using global_cable284_t_index = global_cable76_t_index;

template <int NV>
using global_cable284_t = routing::global_cable<global_cable284_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain314_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable284_t<NV>>, 
                                    math::add<NV>>;
using global_cable285_t_index = global_cable77_t_index;

template <int NV>
using global_cable285_t = routing::global_cable<global_cable285_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain315_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable285_t<NV>>, 
                                    math::add<NV>>;
using global_cable286_t_index = global_cable78_t_index;

template <int NV>
using global_cable286_t = routing::global_cable<global_cable286_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain316_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable286_t<NV>>, 
                                    math::add<NV>>;
using global_cable287_t_index = global_cable79_t_index;

template <int NV>
using global_cable287_t = routing::global_cable<global_cable287_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain317_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable287_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch19_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain302_t<NV>>, 
                                     chain303_t<NV>, 
                                     chain304_t<NV>, 
                                     chain305_t<NV>, 
                                     chain306_t<NV>, 
                                     chain307_t<NV>, 
                                     chain308_t<NV>, 
                                     chain309_t<NV>, 
                                     chain310_t<NV>, 
                                     chain311_t<NV>, 
                                     chain312_t<NV>, 
                                     chain313_t<NV>, 
                                     chain314_t<NV>, 
                                     chain315_t<NV>, 
                                     chain316_t<NV>, 
                                     chain317_t<NV>>;

template <int NV>
using xfader_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                        parameter::plain<math::add<NV>, 0>, 
                                        parameter::plain<math::add<NV>, 0>, 
                                        parameter::plain<math::add<NV>, 0>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;

template <int NV> using xfader1_multimod = xfader_multimod<NV>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::cosine_half>;

template <int NV> using xfader2_multimod = xfader_multimod<NV>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::switcher>;

template <int NV>
using pma28_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<xfader_t<NV>, 0>, 
                                   parameter::plain<xfader1_t<NV>, 0>, 
                                   parameter::plain<xfader2_t<NV>, 0>>;

template <int NV>
using pma28_t = control::pma<NV, pma28_mod<NV>>;
template <int NV>
using peak19_t = wrap::mod<parameter::plain<pma28_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

namespace chain301_t_parameters
{
}

template <int NV>
using chain301_t = container::chain<parameter::plain<Stack_impl::branch19_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch19_t<NV>, 
                                    peak19_t<NV>, 
                                    pma28_t<NV>, 
                                    math::clear<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain80_t<NV>>, 
                                  chain114_t<NV>, 
                                  chain97_t<NV>, 
                                  chain131_t<NV>, 
                                  chain216_t<NV>, 
                                  chain199_t<NV>, 
                                  chain233_t<NV>, 
                                  chain301_t<NV>>;
using pack_resizer1_t = wrap::data<control::pack_resizer, 
                                   data::external::sliderpack<5>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, math::clear<NV>>, 
                                      split4_t<NV>, 
                                      pack_resizer1_t>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, xfader_t<NV>>, 
                                 xfader1_t<NV>, 
                                 xfader2_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using event_data_reader1_mod = parameter::chain<ranges::Identity, 
                                                parameter::plain<minmax8_t<NV>, 2>, 
                                                parameter::plain<minmax9_t<NV>, 2>>;

template <int NV>
using event_data_reader1_t = wrap::mod<event_data_reader1_mod<NV>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, event_data_reader1_t<NV>>, 
                                   minmax9_t<NV>, 
                                   tempo_sync2_t<NV>, 
                                   minmax8_t<NV>>;
template <int NV>
using oversample_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, chain19_t<NV>>, 
                                       granulator_t>;

template <int NV>
using oversample_t = wrap::oversample<0, oversample_t_<NV>>;

template <int NV>
using tempo_sync1_t = wrap::mod<parameter::plain<project::PitchShifter<NV>, 2>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync_t<NV>>, 
                                   tempo_sync1_t<NV>, 
                                   project::PitchShifter<NV>>;

using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, math::add<NV>>>;

template <int NV> using chain6_t = chain5_t<NV>;

template <int NV> using chain7_t = chain5_t<NV>;

template <int NV> using chain17_t = chain5_t<NV>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain5_t<NV>>, 
                                    chain6_t<NV>, 
                                    chain7_t<NV>, 
                                    chain17_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(peak4_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using peak4_mod = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      peak4_modRange>;

template <int NV>
using peak4_t = wrap::mod<peak4_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   branch1_t<NV>, 
                                   peak4_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain39_t>, 
                                  chain43_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain28_t<NV>>, 
                                  split1_t<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle16_t<NV>>, 
                                   input_toggle2_t<NV>, 
                                   oversample_t<NV>, 
                                   chain4_t<NV>, 
                                   cable_table16_t, 
                                   core::gain<NV>>;

using chain12_t = chain39_t;

template <int NV>
using event_data_reader2_mod = parameter::chain<ranges::Identity, 
                                                parameter::plain<minmax11_t<NV>, 2>, 
                                                parameter::plain<minmax10_t<NV>, 2>>;

template <int NV>
using event_data_reader2_t = wrap::mod<event_data_reader2_mod<NV>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<2, event_data_reader2_t<NV>>, 
                                   minmax10_t<NV>, 
                                   tempo_sync10_t<NV>, 
                                   minmax11_t<NV>>;
template <int NV>
using oversample1_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, chain34_t<NV>>, 
                                        granulator1_t>;

template <int NV>
using oversample1_t = wrap::oversample<0, oversample1_t_<NV>>;

template <int NV> using tempo_sync8_t = tempo_sync1_t<NV>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oversample1_t<NV>>, 
                                   tempo_sync3_t<NV>, 
                                   tempo_sync8_t<NV>, 
                                   project::PitchShifter<NV>>;

using chain48_t = chain39_t;

template <int NV> using chain20_t = chain5_t<NV>;

template <int NV> using chain21_t = chain5_t<NV>;

template <int NV> using chain22_t = chain5_t<NV>;

template <int NV> using chain32_t = chain5_t<NV>;
template <int NV>
using branch8_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain20_t<NV>>, 
                                    chain21_t<NV>, 
                                    chain22_t<NV>, 
                                    chain32_t<NV>>;

template <int NV> using peak5_mod = peak4_mod<NV>;

template <int NV>
using peak5_t = wrap::mod<peak5_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, peak5_t<NV>>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   branch8_t<NV>, 
                                   chain8_t<NV>, 
                                   cable_table34_t, 
                                   math::clear<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain48_t>, 
                                  chain49_t<NV>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle34_t<NV>>, 
                                   input_toggle11_t<NV>, 
                                   chain29_t<NV>, 
                                   split7_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using event_data_reader3_mod = parameter::chain<ranges::Identity, 
                                                parameter::plain<minmax13_t<NV>, 2>, 
                                                parameter::plain<minmax12_t<NV>, 2>>;

template <int NV>
using event_data_reader3_t = wrap::mod<event_data_reader3_mod<NV>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<2, event_data_reader3_t<NV>>, 
                                   minmax12_t<NV>, 
                                   tempo_sync11_t<NV>, 
                                   minmax13_t<NV>>;
template <int NV>
using oversample3_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, chain35_t<NV>>, 
                                        granulator2_t>;

template <int NV>
using oversample3_t = wrap::oversample<0, oversample3_t_<NV>>;

template <int NV> using tempo_sync6_t = tempo_sync1_t<NV>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oversample3_t<NV>>, 
                                   tempo_sync5_t<NV>, 
                                   tempo_sync6_t<NV>, 
                                   project::PitchShifter<NV>>;

using chain46_t = chain39_t;

template <int NV> using chain25_t = chain5_t<NV>;

template <int NV> using chain26_t = chain5_t<NV>;

template <int NV> using chain27_t = chain5_t<NV>;

template <int NV> using chain33_t = chain5_t<NV>;
template <int NV>
using branch17_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain25_t<NV>>, 
                                     chain26_t<NV>, 
                                     chain27_t<NV>, 
                                     chain33_t<NV>>;

template <int NV> using peak10_mod = peak4_mod<NV>;

template <int NV>
using peak10_t = wrap::mod<peak10_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   branch17_t<NV>, 
                                   peak10_t<NV>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain23_t<NV>>, 
                                   math::clear<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain46_t>, 
                                  chain47_t<NV>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle33_t<NV>>, 
                                   input_toggle10_t<NV>, 
                                   chain30_t<NV>, 
                                   split6_t<NV>, 
                                   cable_table33_t, 
                                   core::gain<NV>>;

template <int NV>
using event_data_reader4_mod = parameter::chain<ranges::Identity, 
                                                parameter::plain<minmax15_t<NV>, 2>, 
                                                parameter::plain<minmax14_t<NV>, 2>>;

template <int NV>
using event_data_reader4_t = wrap::mod<event_data_reader4_mod<NV>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<2, event_data_reader4_t<NV>>, 
                                   minmax14_t<NV>, 
                                   tempo_sync12_t<NV>, 
                                   minmax15_t<NV>>;
template <int NV>
using oversample2_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, chain36_t<NV>>, 
                                        granulator3_t>;

template <int NV>
using oversample2_t = wrap::oversample<0, oversample2_t_<NV>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oversample2_t<NV>>, 
                                   tempo_sync7_t<NV>, 
                                   control::tempo_sync<NV>, 
                                   project::PitchShifter<NV>>;

using chain44_t = chain39_t;

template <int NV> using chain_t = chain5_t<NV>;

template <int NV> using chain2_t = chain5_t<NV>;

template <int NV> using chain3_t = chain5_t<NV>;

template <int NV> using chain18_t = chain5_t<NV>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain_t<NV>>, 
                                   chain2_t<NV>, 
                                   chain3_t<NV>, 
                                   chain18_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, branch_t<NV>>>;

template <int NV> using peak3_mod = peak4_mod<NV>;

template <int NV>
using peak3_t = wrap::mod<peak3_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   chain1_t<NV>, 
                                   peak3_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain44_t>, 
                                  chain45_t<NV>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle32_t<NV>>, 
                                   input_toggle9_t<NV>, 
                                   chain31_t<NV>, 
                                   cable_table32_t, 
                                   split5_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain42_t<NV>>, 
                                  chain41_t<NV>, 
                                  chain40_t<NV>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split2_t<NV>>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain12_t>, 
                                    chain13_t<NV>>;

template <int NV>
using split16_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain24_t<NV>>, 
                                   branch3_t<NV>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<2, modchain1_t<NV>>, 
                                      modchain_t<NV>, 
                                      split16_t<NV>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

namespace Stack_t_parameters
{
// Parameter list for Stack_impl::Stack_t ----------------------------------------------------------

template <int NV>
using Position = parameter::from0To1<Stack_impl::pma12_t<NV>, 
                                     2, 
                                     Stack_impl::pma12_mod_4Range>;

DECLARE_PARAMETER_RANGE_STEP(PositionSrc_InputRange, 
                             1., 
                             16., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(PositionSrc_0Range, 
                             0., 
                             15., 
                             1.);

template <int NV>
using PositionSrc_0 = parameter::from0To1<Stack_impl::chain80_t<NV>, 
                                          0, 
                                          PositionSrc_0Range>;

template <int NV>
using PositionSrc = parameter::chain<PositionSrc_InputRange, PositionSrc_0<NV>>;

template <int NV>
using PositionModMode = parameter::chain<ranges::Identity, 
                                         parameter::plain<Stack_impl::input_toggle16_t<NV>, 0>, 
                                         parameter::plain<Stack_impl::input_toggle32_t<NV>, 0>, 
                                         parameter::plain<Stack_impl::input_toggle33_t<NV>, 0>, 
                                         parameter::plain<Stack_impl::input_toggle34_t<NV>, 0>>;

template <int NV>
using PitchMod = parameter::chain<ranges::Identity, 
                                  parameter::plain<Stack_impl::pma_t<NV>, 1>, 
                                  parameter::plain<Stack_impl::pma4_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(PitchSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using PitchSrc_0 = parameter::from0To1<Stack_impl::chain114_t<NV>, 
                                       0, 
                                       PositionSrc_0Range>;

template <int NV>
using PitchSrc = parameter::chain<PitchSrc_InputRange, PitchSrc_0<NV>>;

template <int NV>
using PitchModMode = parameter::chain<ranges::Identity, 
                                      parameter::plain<Stack_impl::input_toggle2_t<NV>, 0>, 
                                      parameter::plain<Stack_impl::input_toggle10_t<NV>, 0>, 
                                      parameter::plain<Stack_impl::input_toggle9_t<NV>, 0>, 
                                      parameter::plain<Stack_impl::input_toggle11_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(GrainRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Grain = parameter::from0To1<Stack_impl::pma13_t<NV>, 
                                  2, 
                                  GrainRange>;

template <int NV>
using GrainMod = parameter::chain<ranges::Identity, 
                                  parameter::plain<Stack_impl::pma13_t<NV>, 1>, 
                                  parameter::plain<Stack_impl::pma21_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(GrainSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using GrainSrc_0 = parameter::from0To1<Stack_impl::chain97_t<NV>, 
                                       0, 
                                       PositionSrc_0Range>;

template <int NV>
using GrainSrc = parameter::chain<GrainSrc_InputRange, GrainSrc_0<NV>>;

template <int NV>
using GrainSync = parameter::chain<ranges::Identity, 
                                   parameter::plain<Stack_impl::branch2_t<NV>, 0>, 
                                   parameter::plain<Stack_impl::tempo_sync12_t<NV>, 2>, 
                                   parameter::plain<Stack_impl::tempo_sync11_t<NV>, 2>, 
                                   parameter::plain<Stack_impl::tempo_sync10_t<NV>, 2>, 
                                   parameter::plain<Stack_impl::tempo_sync2_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(GrainTempo_InputRange, 
                             0., 
                             18., 
                             1.);
template <int NV>
using GrainTempo_0 = parameter::from0To1<Stack_impl::pma21_t<NV>, 
                                         2, 
                                         GrainRange>;

template <int NV>
using GrainTempo = parameter::chain<GrainTempo_InputRange, GrainTempo_0<NV>>;

template <int NV>
using GrainDiv = parameter::chain<ranges::Identity, 
                                  parameter::plain<Stack_impl::tempo_sync12_t<NV>, 1>, 
                                  parameter::plain<Stack_impl::tempo_sync11_t<NV>, 1>, 
                                  parameter::plain<Stack_impl::tempo_sync10_t<NV>, 1>, 
                                  parameter::plain<Stack_impl::tempo_sync2_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(GrainAnSlot_InputRange, 
                             0., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(GrainAnSlot_0Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using GrainAnSlot_0 = parameter::from0To1<Stack_impl::event_data_reader1_t<NV>, 
                                          0, 
                                          GrainAnSlot_0Range>;

template <int NV>
using GrainAnSlot_1 = parameter::from0To1<Stack_impl::event_data_reader2_t<NV>, 
                                          0, 
                                          GrainAnSlot_0Range>;

template <int NV>
using GrainAnSlot_2 = parameter::from0To1<Stack_impl::event_data_reader4_t<NV>, 
                                          0, 
                                          GrainAnSlot_0Range>;

template <int NV>
using GrainAnSlot = parameter::chain<GrainAnSlot_InputRange, 
                                     GrainAnSlot_0<NV>, 
                                     GrainAnSlot_1<NV>, 
                                     GrainAnSlot_2<NV>>;

template <int NV>
using Demse = parameter::from0To1<Stack_impl::pma15_t<NV>, 
                                  2, 
                                  GrainRange>;

DECLARE_PARAMETER_RANGE_STEP(DenseSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using DenseSrc_0 = parameter::from0To1<Stack_impl::chain131_t<NV>, 
                                       0, 
                                       PositionSrc_0Range>;

template <int NV>
using DenseSrc = parameter::chain<DenseSrc_InputRange, DenseSrc_0<NV>>;

template <int NV>
using Spread = parameter::from0To1<Stack_impl::pma20_t<NV>, 
                                   2, 
                                   GrainRange>;

DECLARE_PARAMETER_RANGE_STEP(SpreadSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using SpreadSrc_0 = parameter::from0To1<Stack_impl::chain216_t<NV>, 
                                        0, 
                                        PositionSrc_0Range>;

template <int NV>
using SpreadSrc = parameter::chain<SpreadSrc_InputRange, SpreadSrc_0<NV>>;

template <int NV>
using Detune = parameter::from0To1<Stack_impl::pma19_t<NV>, 
                                   2, 
                                   GrainRange>;

DECLARE_PARAMETER_RANGE_STEP(DetuneSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using DetuneSrc_0 = parameter::from0To1<Stack_impl::chain199_t<NV>, 
                                        0, 
                                        PositionSrc_0Range>;

template <int NV>
using DetuneSrc = parameter::chain<DetuneSrc_InputRange, DetuneSrc_0<NV>>;

DECLARE_PARAMETER_RANGE(WinTime_InputRange, 
                        40., 
                        10000.);
template <int NV>
using WinTime_0 = parameter::from0To1<Stack_impl::pma22_t<NV>, 
                                      2, 
                                      GrainRange>;

template <int NV>
using WinTime = parameter::chain<WinTime_InputRange, WinTime_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(WinTempo_InputRange, 
                             0., 
                             18., 
                             1.);
template <int NV>
using WinTempo_0 = parameter::from0To1<Stack_impl::pma23_t<NV>, 
                                       2, 
                                       GrainRange>;

template <int NV>
using WinTempo = parameter::chain<WinTempo_InputRange, WinTempo_0<NV>>;

template <int NV>
using WinDiv = parameter::chain<ranges::Identity, 
                                parameter::plain<Stack_impl::tempo_sync7_t<NV>, 1>, 
                                parameter::plain<Stack_impl::tempo_sync5_t<NV>, 1>, 
                                parameter::plain<Stack_impl::tempo_sync3_t<NV>, 1>, 
                                parameter::plain<Stack_impl::tempo_sync_t<NV>, 1>, 
                                parameter::plain<Stack_impl::tempo_sync1_t<NV>, 1>, 
                                parameter::plain<control::tempo_sync<NV>, 1>, 
                                parameter::plain<Stack_impl::tempo_sync6_t<NV>, 1>, 
                                parameter::plain<Stack_impl::tempo_sync8_t<NV>, 1>>;

template <int NV>
using WinSync = parameter::chain<ranges::Identity, 
                                 parameter::plain<Stack_impl::branch14_t<NV>, 0>, 
                                 parameter::plain<Stack_impl::tempo_sync_t<NV>, 2>, 
                                 parameter::plain<Stack_impl::tempo_sync3_t<NV>, 2>, 
                                 parameter::plain<Stack_impl::tempo_sync5_t<NV>, 2>, 
                                 parameter::plain<Stack_impl::tempo_sync7_t<NV>, 2>, 
                                 parameter::plain<Stack_impl::tempo_sync1_t<NV>, 2>, 
                                 parameter::plain<control::tempo_sync<NV>, 2>, 
                                 parameter::plain<Stack_impl::tempo_sync6_t<NV>, 2>, 
                                 parameter::plain<Stack_impl::tempo_sync8_t<NV>, 2>>;

template <int NV>
using WinMod = parameter::chain<ranges::Identity, 
                                parameter::plain<Stack_impl::pma22_t<NV>, 1>, 
                                parameter::plain<Stack_impl::pma23_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(WinSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using WinSrc_0 = parameter::from0To1<Stack_impl::chain233_t<NV>, 
                                     0, 
                                     PositionSrc_0Range>;

template <int NV>
using WinSrc = parameter::chain<WinSrc_InputRange, WinSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(XfMode_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(XfMode_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using XfMode_0 = parameter::from0To1<Stack_impl::branch1_t<NV>, 
                                     0, 
                                     XfMode_0Range>;

template <int NV>
using XfMode_1 = parameter::from0To1<Stack_impl::branch8_t<NV>, 
                                     0, 
                                     XfMode_0Range>;

template <int NV>
using XfMode_2 = parameter::from0To1<Stack_impl::branch17_t<NV>, 
                                     0, 
                                     XfMode_0Range>;

template <int NV>
using XfMode_3 = parameter::from0To1<Stack_impl::branch_t<NV>, 
                                     0, 
                                     XfMode_0Range>;

template <int NV>
using XfMode = parameter::chain<XfMode_InputRange, 
                                XfMode_0<NV>, 
                                XfMode_1<NV>, 
                                XfMode_2<NV>, 
                                XfMode_3<NV>>;

template <int NV>
using Xfade = parameter::from0To1<Stack_impl::pma28_t<NV>, 
                                  2, 
                                  GrainRange>;

DECLARE_PARAMETER_RANGE_STEP(XfadeSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using XfadeSrc_0 = parameter::from0To1<Stack_impl::chain301_t<NV>, 
                                       0, 
                                       PositionSrc_0Range>;

template <int NV>
using XfadeSrc = parameter::chain<XfadeSrc_InputRange, XfadeSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Pitch_InputRange, 
                             -24., 
                             24., 
                             1.);
template <int NV>
using Pitch_0 = parameter::from0To1<Stack_impl::pma4_t<NV>, 
                                    2, 
                                    GrainRange>;

template <int NV>
using Pitch = parameter::chain<Pitch_InputRange, Pitch_0<NV>>;

template <int NV>
using FadeTempo = parameter::chain<ranges::Identity, 
                                   parameter::plain<Stack_impl::tempo_sync1_t<NV>, 0>, 
                                   parameter::plain<Stack_impl::tempo_sync8_t<NV>, 0>, 
                                   parameter::plain<Stack_impl::tempo_sync6_t<NV>, 0>, 
                                   parameter::plain<control::tempo_sync<NV>, 0>>;

template <int NV>
using FadeTime = parameter::chain<ranges::Identity, 
                                  parameter::plain<Stack_impl::tempo_sync1_t<NV>, 3>, 
                                  parameter::plain<Stack_impl::tempo_sync8_t<NV>, 3>, 
                                  parameter::plain<Stack_impl::tempo_sync6_t<NV>, 3>, 
                                  parameter::plain<control::tempo_sync<NV>, 3>>;

DECLARE_PARAMETER_RANGE_STEP(over_InputRange, 
                             1., 
                             5., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(over_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using over_0 = parameter::from0To1<Stack_impl::oversample2_t<NV>, 
                                   0, 
                                   over_0Range>;

template <int NV>
using over_1 = parameter::from0To1<Stack_impl::oversample3_t<NV>, 
                                   0, 
                                   over_0Range>;

template <int NV>
using over_2 = parameter::from0To1<Stack_impl::oversample1_t<NV>, 
                                   0, 
                                   over_0Range>;

template <int NV>
using over_3 = parameter::from0To1<Stack_impl::oversample_t<NV>, 
                                   0, 
                                   over_0Range>;

template <int NV>
using over = parameter::chain<over_InputRange, 
                              over_0<NV>, 
                              over_1<NV>, 
                              over_2<NV>, 
                              over_3<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Step_InputRange, 
                             0., 
                             13., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Step_0Range, 
                             0., 
                             12., 
                             1.);

template <int NV>
using Step_0 = parameter::from0To1<Stack_impl::minmax_t<NV>, 
                                   4, 
                                   Step_0Range>;

template <int NV>
using Step_1 = parameter::from0To1<Stack_impl::minmax1_t<NV>, 
                                   4, 
                                   Step_0Range>;

template <int NV>
using Step_2 = parameter::from0To1<Stack_impl::minmax7_t<NV>, 
                                   4, 
                                   Step_0Range>;

template <int NV>
using Step_3 = parameter::from0To1<Stack_impl::minmax6_t<NV>, 
                                   4, 
                                   Step_0Range>;

template <int NV>
using Step_4 = parameter::from0To1<Stack_impl::minmax5_t<NV>, 
                                   4, 
                                   Step_0Range>;

template <int NV>
using Step = parameter::chain<Step_InputRange, 
                              Step_0<NV>, 
                              Step_1<NV>, 
                              Step_2<NV>, 
                              Step_3<NV>, 
                              Step_4<NV>>;

template <int NV>
using PositionMod = parameter::plain<Stack_impl::pma12_t<NV>, 
                                     1>;
template <int NV>
using DenseMod = parameter::plain<Stack_impl::pma15_t<NV>, 
                                  1>;
template <int NV>
using SpreadMod = parameter::plain<Stack_impl::pma20_t<NV>, 
                                   1>;
template <int NV>
using DetuneMod = parameter::plain<Stack_impl::pma19_t<NV>, 
                                   1>;
using FadeDiv = parameter::empty;
using Mode = FadeDiv;
using PitchMin = FadeDiv;
using PitchMax = FadeDiv;
using PitchStep = FadeDiv;
template <int NV>
using Stack = parameter::plain<Stack_impl::branch3_t<NV>, 
                               0>;
template <int NV>
using XfadeMod = parameter::plain<Stack_impl::pma28_t<NV>, 
                                  1>;
template <int NV>
using PitchStack = parameter::plain<Stack_impl::pma_t<NV>, 2>;
template <int NV>
using Stack_t_plist = parameter::list<Position<NV>, 
                                      PositionMod<NV>, 
                                      PositionSrc<NV>, 
                                      PositionModMode<NV>, 
                                      PitchMod<NV>, 
                                      PitchSrc<NV>, 
                                      PitchModMode<NV>, 
                                      Grain<NV>, 
                                      GrainMod<NV>, 
                                      GrainSrc<NV>, 
                                      GrainSync<NV>, 
                                      GrainTempo<NV>, 
                                      GrainDiv<NV>, 
                                      GrainAnSlot<NV>, 
                                      Demse<NV>, 
                                      DenseMod<NV>, 
                                      DenseSrc<NV>, 
                                      Spread<NV>, 
                                      SpreadMod<NV>, 
                                      SpreadSrc<NV>, 
                                      Detune<NV>, 
                                      DetuneMod<NV>, 
                                      DetuneSrc<NV>, 
                                      WinTime<NV>, 
                                      WinTempo<NV>, 
                                      WinDiv<NV>, 
                                      WinSync<NV>, 
                                      WinMod<NV>, 
                                      WinSrc<NV>, 
                                      FadeDiv, 
                                      Mode, 
                                      PitchMin, 
                                      PitchMax, 
                                      PitchStep, 
                                      Stack<NV>, 
                                      XfMode<NV>, 
                                      Xfade<NV>, 
                                      XfadeMod<NV>, 
                                      XfadeSrc<NV>, 
                                      PitchStack<NV>, 
                                      Pitch<NV>, 
                                      FadeTempo<NV>, 
                                      FadeTime<NV>, 
                                      over<NV>, 
                                      Step<NV>>;
}

template <int NV>
using Stack_t_ = container::chain<Stack_t_parameters::Stack_t_plist<NV>, 
                                  wrap::fix<2, midichain_t<NV>>, 
                                  core::gain<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Stack_impl::Stack_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 4;
		static const int NumSliderPacks = 6;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Stack);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(760)
		{
			0x005B, 0x0000, 0x5000, 0x736F, 0x7469, 0x6F69, 0x006E, 0x0000, 
            0x2640, 0x0000, 0x3F80, 0x0000, 0x2640, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x015B, 0x0000, 0x5000, 0x736F, 0x7469, 0x6F69, 0x4D6E, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 0x0000, 0x6F50, 0x6973, 
            0x6974, 0x6E6F, 0x7253, 0x0063, 0x0000, 0x3F80, 0x0000, 0x4180, 
            0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 0x0000, 
            0x5000, 0x736F, 0x7469, 0x6F69, 0x4D6E, 0x646F, 0x6F4D, 0x6564, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0004, 0x0000, 0x6950, 0x6374, 0x4D68, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 0x6950, 0x6374, 
            0x5368, 0x6372, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0006, 0x0000, 0x6950, 
            0x6374, 0x4D68, 0x646F, 0x6F4D, 0x6564, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0007, 0x0000, 0x7247, 0x6961, 0x006E, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x085B, 
            0x0000, 0x4700, 0x6172, 0x6E69, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x095B, 0x0000, 0x4700, 0x6172, 0x6E69, 0x7253, 0x0063, 0x0000, 
            0x3F80, 0x0000, 0x4180, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0A5B, 0x0000, 0x4700, 0x6172, 0x6E69, 0x7953, 0x636E, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x000B, 0x0000, 0x7247, 0x6961, 0x546E, 
            0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x2000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000C, 0x0000, 0x7247, 
            0x6961, 0x446E, 0x7669, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 
            0x2000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000D, 0x0000, 
            0x7247, 0x6961, 0x416E, 0x536E, 0x6F6C, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x4040, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0E5B, 0x0000, 0x4400, 0x6D65, 0x6573, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x000F, 0x0000, 0x6544, 0x736E, 0x4D65, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0010, 0x0000, 0x6544, 0x736E, 0x5365, 0x6372, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0011, 0x0000, 0x7053, 0x6572, 0x6461, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0012, 0x0000, 0x7053, 0x6572, 0x6461, 0x6F4D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x135B, 0x0000, 0x5300, 0x7270, 0x6165, 
            0x5364, 0x6372, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0014, 0x0000, 0x6544, 
            0x7574, 0x656E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0015, 0x0000, 0x6544, 
            0x7574, 0x656E, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x165B, 0x0000, 
            0x4400, 0x7465, 0x6E75, 0x5365, 0x6372, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0017, 0x0000, 0x6957, 0x546E, 0x6D69, 0x0065, 0x0000, 0x4220, 
            0x4000, 0x461C, 0x7CB8, 0x45BC, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x185B, 0x0000, 0x5700, 0x6E69, 0x6554, 0x706D, 0x006F, 0x0000, 
            0x0000, 0x0000, 0x4190, 0x0000, 0x4120, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x195B, 0x0000, 0x5700, 0x6E69, 0x6944, 0x0076, 0x0000, 
            0x3F80, 0x0000, 0x4180, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x1A5B, 0x0000, 0x5700, 0x6E69, 0x7953, 0x636E, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x001B, 0x0000, 0x6957, 0x4D6E, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x001C, 0x0000, 0x6957, 0x536E, 0x6372, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x001D, 0x0000, 0x6146, 0x6564, 0x6944, 0x0076, 
            0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x4160, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x1E5B, 0x0000, 0x4D00, 0x646F, 0x0065, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x1F5B, 0x0000, 0x5000, 0x7469, 0x6863, 0x694D, 0x006E, 
            0x0000, 0xC210, 0x0000, 0x4210, 0x0000, 0xC208, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x205B, 0x0000, 0x5000, 0x7469, 0x6863, 0x614D, 
            0x0078, 0x0000, 0xC210, 0x0000, 0x4210, 0x0000, 0x41A0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x215B, 0x0000, 0x5000, 0x7469, 0x6863, 
            0x7453, 0x7065, 0x0000, 0x0000, 0x0000, 0x4000, 0x0041, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0022, 0x0000, 0x7453, 
            0x6361, 0x006B, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x235B, 0x0000, 0x5800, 0x4D66, 
            0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x245B, 0x0000, 0x5800, 0x6166, 
            0x6564, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0025, 0x0000, 0x6658, 0x6461, 
            0x4D65, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x3D3F, 0x570A, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0026, 0x0000, 0x6658, 
            0x6461, 0x5365, 0x6372, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 
            0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0027, 0x0000, 
            0x6950, 0x6374, 0x5368, 0x6174, 0x6B63, 0x0000, 0x8000, 0x0024, 
            0x8000, 0x003F, 0x0000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0028, 0x0000, 0x6950, 0x6374, 0x0068, 0x0000, 0xC1C0, 0x0000, 
            0x41C0, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x295B, 
            0x0000, 0x4600, 0x6461, 0x5465, 0x6D65, 0x6F70, 0x0000, 0x0000, 
            0x0000, 0x9000, 0x0041, 0x2000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x002A, 0x0000, 0x6146, 0x6564, 0x6954, 0x656D, 0x0000, 
            0x0000, 0x0000, 0x7A00, 0x0044, 0x7A00, 0x0044, 0x8000, 0xCD3F, 
            0xCCCC, 0x5B3D, 0x002B, 0x0000, 0x766F, 0x7265, 0x0000, 0x8000, 
            0x003F, 0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x002C, 0x0000, 0x7453, 0x7065, 0x0000, 0x0000, 0x0000, 
            0x5000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& midichain = this->getT(0);                                                        // Stack_impl::midichain_t<NV>
		auto& modchain1 = this->getT(0).getT(0);                                                // Stack_impl::modchain1_t<NV>
		auto& clear = this->getT(0).getT(0).getT(0);                                            // math::clear<NV>
		auto& split4 = this->getT(0).getT(0).getT(1);                                           // Stack_impl::split4_t<NV>
		auto& chain80 = this->getT(0).getT(0).getT(1).getT(0);                                  // Stack_impl::chain80_t<NV>
		auto& clear7 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                           // math::clear<NV>
		auto& branch4 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                          // Stack_impl::branch4_t<NV>
		auto& chain81 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);                  // Stack_impl::chain81_t<NV>
		auto& global_cable64 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0);   // Stack_impl::global_cable64_t<NV>
		auto& add58 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(1);            // math::add<NV>
		auto& chain82 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1);                  // Stack_impl::chain82_t<NV>
		auto& global_cable65 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(0);   // Stack_impl::global_cable65_t<NV>
		auto& add59 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(1);            // math::add<NV>
		auto& chain83 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2);                  // Stack_impl::chain83_t<NV>
		auto& global_cable66 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(0);   // Stack_impl::global_cable66_t<NV>
		auto& add60 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(1);            // math::add<NV>
		auto& chain84 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3);                  // Stack_impl::chain84_t<NV>
		auto& global_cable67 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(0);   // Stack_impl::global_cable67_t<NV>
		auto& add61 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(1);            // math::add<NV>
		auto& chain85 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(4);                  // Stack_impl::chain85_t<NV>
		auto& global_cable68 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(4).getT(0);   // Stack_impl::global_cable68_t<NV>
		auto& add62 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(4).getT(1);            // math::add<NV>
		auto& chain86 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(5);                  // Stack_impl::chain86_t<NV>
		auto& global_cable69 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(5).getT(0);   // Stack_impl::global_cable69_t<NV>
		auto& add63 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(5).getT(1);            // math::add<NV>
		auto& chain87 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(6);                  // Stack_impl::chain87_t<NV>
		auto& global_cable70 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(6).getT(0);   // Stack_impl::global_cable70_t<NV>
		auto& add64 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(6).getT(1);            // math::add<NV>
		auto& chain88 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(7);                  // Stack_impl::chain88_t<NV>
		auto& global_cable71 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(7).getT(0);   // Stack_impl::global_cable71_t<NV>
		auto& add65 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(7).getT(1);            // math::add<NV>
		auto& chain89 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(8);                  // Stack_impl::chain89_t<NV>
		auto& global_cable72 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(8).getT(0);   // Stack_impl::global_cable72_t<NV>
		auto& add66 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(8).getT(1);            // math::add<NV>
		auto& chain90 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(9);                  // Stack_impl::chain90_t<NV>
		auto& global_cable73 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(9).getT(0);   // Stack_impl::global_cable73_t<NV>
		auto& add67 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(9).getT(1);            // math::add<NV>
		auto& chain91 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(10);                 // Stack_impl::chain91_t<NV>
		auto& global_cable74 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(10).getT(0);  // Stack_impl::global_cable74_t<NV>
		auto& add68 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(10).getT(1);           // math::add<NV>
		auto& chain92 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(11);                 // Stack_impl::chain92_t<NV>
		auto& global_cable75 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(11).getT(0);  // Stack_impl::global_cable75_t<NV>
		auto& add69 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(11).getT(1);           // math::add<NV>
		auto& chain93 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(12);                 // Stack_impl::chain93_t<NV>
		auto& global_cable76 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(12).getT(0);  // Stack_impl::global_cable76_t<NV>
		auto& add70 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(12).getT(1);           // math::add<NV>
		auto& chain94 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(13);                 // Stack_impl::chain94_t<NV>
		auto& global_cable77 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(13).getT(0);  // Stack_impl::global_cable77_t<NV>
		auto& add71 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(13).getT(1);           // math::add<NV>
		auto& chain95 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(14);                 // Stack_impl::chain95_t<NV>
		auto& global_cable78 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(14).getT(0);  // Stack_impl::global_cable78_t<NV>
		auto& add72 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(14).getT(1);           // math::add<NV>
		auto& chain96 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(15);                 // Stack_impl::chain96_t<NV>
		auto& global_cable79 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(15).getT(0);  // Stack_impl::global_cable79_t<NV>
		auto& add73 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(15).getT(1);           // math::add<NV>
		auto& peak6 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                            // Stack_impl::peak6_t<NV>
		auto& pma12 = this->getT(0).getT(0).getT(1).getT(0).getT(3);                            // Stack_impl::pma12_t<NV>
		auto& sliderbank = this->getT(0).getT(0).getT(1).getT(0).getT(4);                       // Stack_impl::sliderbank_t<NV>
		auto& clear8 = this->getT(0).getT(0).getT(1).getT(0).getT(5);                           // math::clear<NV>
		auto& chain114 = this->getT(0).getT(0).getT(1).getT(1);                                 // Stack_impl::chain114_t<NV>
		auto& clear11 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                          // math::clear<NV>
		auto& branch6 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                          // Stack_impl::branch6_t<NV>
		auto& chain115 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0);                 // Stack_impl::chain115_t<NV>
		auto& global_cable96 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).getT(0);   // Stack_impl::global_cable96_t<NV>
		auto& add90 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).getT(1);            // math::add<NV>
		auto& chain116 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(1);                 // Stack_impl::chain116_t<NV>
		auto& global_cable97 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(1).getT(0);   // Stack_impl::global_cable97_t<NV>
		auto& add91 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(1).getT(1);            // math::add<NV>
		auto& chain117 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(2);                 // Stack_impl::chain117_t<NV>
		auto& global_cable98 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(2).getT(0);   // Stack_impl::global_cable98_t<NV>
		auto& add92 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(2).getT(1);            // math::add<NV>
		auto& chain118 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(3);                 // Stack_impl::chain118_t<NV>
		auto& global_cable99 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(3).getT(0);   // Stack_impl::global_cable99_t<NV>
		auto& add93 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(3).getT(1);            // math::add<NV>
		auto& chain119 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(4);                 // Stack_impl::chain119_t<NV>
		auto& global_cable100 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(4).getT(0);  // Stack_impl::global_cable100_t<NV>
		auto& add94 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(4).getT(1);            // math::add<NV>
		auto& chain120 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(5);                 // Stack_impl::chain120_t<NV>
		auto& global_cable101 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(5).getT(0);  // Stack_impl::global_cable101_t<NV>
		auto& add95 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(5).getT(1);            // math::add<NV>
		auto& chain121 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(6);                 // Stack_impl::chain121_t<NV>
		auto& global_cable102 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(6).getT(0);  // Stack_impl::global_cable102_t<NV>
		auto& add96 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(6).getT(1);            // math::add<NV>
		auto& chain122 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(7);                 // Stack_impl::chain122_t<NV>
		auto& global_cable103 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(7).getT(0);  // Stack_impl::global_cable103_t<NV>
		auto& add97 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(7).getT(1);            // math::add<NV>
		auto& chain123 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(8);                 // Stack_impl::chain123_t<NV>
		auto& global_cable104 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(8).getT(0);  // Stack_impl::global_cable104_t<NV>
		auto& add98 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(8).getT(1);            // math::add<NV>
		auto& chain124 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(9);                 // Stack_impl::chain124_t<NV>
		auto& global_cable105 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(9).getT(0);  // Stack_impl::global_cable105_t<NV>
		auto& add99 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(9).getT(1);            // math::add<NV>
		auto& chain125 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(10);                // Stack_impl::chain125_t<NV>
		auto& global_cable106 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(10).getT(0); // Stack_impl::global_cable106_t<NV>
		auto& add100 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(10).getT(1);          // math::add<NV>
		auto& chain126 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(11);                // Stack_impl::chain126_t<NV>
		auto& global_cable107 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(11).getT(0); // Stack_impl::global_cable107_t<NV>
		auto& add101 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(11).getT(1);          // math::add<NV>
		auto& chain127 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(12);                // Stack_impl::chain127_t<NV>
		auto& global_cable108 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(12).getT(0); // Stack_impl::global_cable108_t<NV>
		auto& add102 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(12).getT(1);          // math::add<NV>
		auto& chain128 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(13);                // Stack_impl::chain128_t<NV>
		auto& global_cable109 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(13).getT(0); // Stack_impl::global_cable109_t<NV>
		auto& add103 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(13).getT(1);          // math::add<NV>
		auto& chain129 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(14);                // Stack_impl::chain129_t<NV>
		auto& global_cable110 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(14).getT(0); // Stack_impl::global_cable110_t<NV>
		auto& add104 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(14).getT(1);          // math::add<NV>
		auto& chain130 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(15);                // Stack_impl::chain130_t<NV>
		auto& global_cable111 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(15).getT(0); // Stack_impl::global_cable111_t<NV>
		auto& add105 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(15).getT(1);          // math::add<NV>
		auto& peak8 = this->getT(0).getT(0).getT(1).getT(1).getT(2);                            // Stack_impl::peak8_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(1).getT(1).getT(3);                             // Stack_impl::pma4_t<NV>
		auto& minmax = this->getT(0).getT(0).getT(1).getT(1).getT(4);                           // Stack_impl::minmax_t<NV>
		auto& pma_unscaled = this->getT(0).getT(0).getT(1).getT(1).getT(5);                     // Stack_impl::pma_unscaled_t<NV>
		auto& pma = this->getT(0).getT(0).getT(1).getT(1).getT(6);                              // Stack_impl::pma_t<NV>
		auto& sliderbank1 = this->getT(0).getT(0).getT(1).getT(1).getT(7);                      // Stack_impl::sliderbank1_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(1).getT(1).getT(8);                           // Stack_impl::split3_t<NV>
		auto& minmax1 = this->getT(0).getT(0).getT(1).getT(1).getT(8).getT(0);                  // Stack_impl::minmax1_t<NV>
		auto& minmax7 = this->getT(0).getT(0).getT(1).getT(1).getT(8).getT(1);                  // Stack_impl::minmax7_t<NV>
		auto& minmax6 = this->getT(0).getT(0).getT(1).getT(1).getT(8).getT(2);                  // Stack_impl::minmax6_t<NV>
		auto& minmax5 = this->getT(0).getT(0).getT(1).getT(1).getT(8).getT(3);                  // Stack_impl::minmax5_t<NV>
		auto& clear12 = this->getT(0).getT(0).getT(1).getT(1).getT(9);                          // math::clear<NV>
		auto& chain97 = this->getT(0).getT(0).getT(1).getT(2);                                  // Stack_impl::chain97_t<NV>
		auto& clear9 = this->getT(0).getT(0).getT(1).getT(2).getT(0);                           // math::clear<NV>
		auto& branch5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                          // Stack_impl::branch5_t<NV>
		auto& chain98 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0);                  // Stack_impl::chain98_t<NV>
		auto& global_cable80 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(0);   // Stack_impl::global_cable80_t<NV>
		auto& add74 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(1);            // math::add<NV>
		auto& chain99 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(1);                  // Stack_impl::chain99_t<NV>
		auto& global_cable81 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(1).getT(0);   // Stack_impl::global_cable81_t<NV>
		auto& add75 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(1).getT(1);            // math::add<NV>
		auto& chain100 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(2);                 // Stack_impl::chain100_t<NV>
		auto& global_cable82 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(2).getT(0);   // Stack_impl::global_cable82_t<NV>
		auto& add76 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(2).getT(1);            // math::add<NV>
		auto& chain101 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(3);                 // Stack_impl::chain101_t<NV>
		auto& global_cable83 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(3).getT(0);   // Stack_impl::global_cable83_t<NV>
		auto& add77 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(3).getT(1);            // math::add<NV>
		auto& chain102 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(4);                 // Stack_impl::chain102_t<NV>
		auto& global_cable84 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(4).getT(0);   // Stack_impl::global_cable84_t<NV>
		auto& add78 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(4).getT(1);            // math::add<NV>
		auto& chain103 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(5);                 // Stack_impl::chain103_t<NV>
		auto& global_cable85 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(5).getT(0);   // Stack_impl::global_cable85_t<NV>
		auto& add79 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(5).getT(1);            // math::add<NV>
		auto& chain104 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(6);                 // Stack_impl::chain104_t<NV>
		auto& global_cable86 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(6).getT(0);   // Stack_impl::global_cable86_t<NV>
		auto& add80 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(6).getT(1);            // math::add<NV>
		auto& chain105 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(7);                 // Stack_impl::chain105_t<NV>
		auto& global_cable87 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(7).getT(0);   // Stack_impl::global_cable87_t<NV>
		auto& add81 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(7).getT(1);            // math::add<NV>
		auto& chain106 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(8);                 // Stack_impl::chain106_t<NV>
		auto& global_cable88 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(8).getT(0);   // Stack_impl::global_cable88_t<NV>
		auto& add82 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(8).getT(1);            // math::add<NV>
		auto& chain107 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(9);                 // Stack_impl::chain107_t<NV>
		auto& global_cable89 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(9).getT(0);   // Stack_impl::global_cable89_t<NV>
		auto& add83 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(9).getT(1);            // math::add<NV>
		auto& chain108 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(10);                // Stack_impl::chain108_t<NV>
		auto& global_cable90 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(10).getT(0);  // Stack_impl::global_cable90_t<NV>
		auto& add84 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(10).getT(1);           // math::add<NV>
		auto& chain109 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(11);                // Stack_impl::chain109_t<NV>
		auto& global_cable91 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(11).getT(0);  // Stack_impl::global_cable91_t<NV>
		auto& add85 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(11).getT(1);           // math::add<NV>
		auto& chain110 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(12);                // Stack_impl::chain110_t<NV>
		auto& global_cable92 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(12).getT(0);  // Stack_impl::global_cable92_t<NV>
		auto& add86 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(12).getT(1);           // math::add<NV>
		auto& chain111 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(13);                // Stack_impl::chain111_t<NV>
		auto& global_cable93 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(13).getT(0);  // Stack_impl::global_cable93_t<NV>
		auto& add87 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(13).getT(1);           // math::add<NV>
		auto& chain112 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(14);                // Stack_impl::chain112_t<NV>
		auto& global_cable94 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(14).getT(0);  // Stack_impl::global_cable94_t<NV>
		auto& add88 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(14).getT(1);           // math::add<NV>
		auto& chain113 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(15);                // Stack_impl::chain113_t<NV>
		auto& global_cable95 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(15).getT(0);  // Stack_impl::global_cable95_t<NV>
		auto& add89 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(15).getT(1);           // math::add<NV>
		auto& peak7 = this->getT(0).getT(0).getT(1).getT(2).getT(2);                            // Stack_impl::peak7_t<NV>
		auto& chain11 = this->getT(0).getT(0).getT(1).getT(2).getT(3);                          // Stack_impl::chain11_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(1).getT(2).getT(3).getT(0);                   // math::clear<NV>
		auto& branch2 = this->getT(0).getT(0).getT(1).getT(2).getT(3).getT(1);                  // Stack_impl::branch2_t<NV>
		auto& chain9 = this->getT(0).getT(0).getT(1).getT(2).getT(3).getT(1).getT(0);           // Stack_impl::chain9_t<NV>
		auto& pma13 = this->getT(0).getT(0).getT(1).getT(2).                                    // Stack_impl::pma13_t<NV>
                      getT(3).getT(1).getT(0).getT(0);
		auto& add = this->getT(0).getT(0).getT(1).getT(2).                                      // math::add<NV>
                    getT(3).getT(1).getT(0).getT(1);
		auto& chain10 = this->getT(0).getT(0).getT(1).getT(2).getT(3).getT(1).getT(1);          // Stack_impl::chain10_t<NV>
		auto& pma21 = this->getT(0).getT(0).getT(1).getT(2).                                    // Stack_impl::pma21_t<NV>
                      getT(3).getT(1).getT(1).getT(0);
		auto& add1 = this->getT(0).getT(0).getT(1).getT(2).                                     // math::add<NV>
                     getT(3).getT(1).getT(1).getT(1);
		auto& peak = this->getT(0).getT(0).getT(1).getT(2).getT(3).getT(2);                     // Stack_impl::peak_t<NV>
		auto& clear10 = this->getT(0).getT(0).getT(1).getT(2).getT(4);                          // math::clear<NV>
		auto& chain131 = this->getT(0).getT(0).getT(1).getT(3);                                 // Stack_impl::chain131_t<NV>
		auto& clear13 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                          // math::clear<NV>
		auto& branch7 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                          // Stack_impl::branch7_t<NV>
		auto& chain132 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0);                 // Stack_impl::chain132_t<NV>
		auto& global_cable112 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).getT(0);  // Stack_impl::global_cable112_t<NV>
		auto& add106 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).getT(1);           // math::add<NV>
		auto& chain133 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(1);                 // Stack_impl::chain133_t<NV>
		auto& global_cable113 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(1).getT(0);  // Stack_impl::global_cable113_t<NV>
		auto& add107 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(1).getT(1);           // math::add<NV>
		auto& chain134 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(2);                 // Stack_impl::chain134_t<NV>
		auto& global_cable114 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(2).getT(0);  // Stack_impl::global_cable114_t<NV>
		auto& add108 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(2).getT(1);           // math::add<NV>
		auto& chain135 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(3);                 // Stack_impl::chain135_t<NV>
		auto& global_cable115 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(3).getT(0);  // Stack_impl::global_cable115_t<NV>
		auto& add109 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(3).getT(1);           // math::add<NV>
		auto& chain136 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(4);                 // Stack_impl::chain136_t<NV>
		auto& global_cable116 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(4).getT(0);  // Stack_impl::global_cable116_t<NV>
		auto& add110 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(4).getT(1);           // math::add<NV>
		auto& chain137 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(5);                 // Stack_impl::chain137_t<NV>
		auto& global_cable117 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(5).getT(0);  // Stack_impl::global_cable117_t<NV>
		auto& add111 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(5).getT(1);           // math::add<NV>
		auto& chain138 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(6);                 // Stack_impl::chain138_t<NV>
		auto& global_cable118 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(6).getT(0);  // Stack_impl::global_cable118_t<NV>
		auto& add112 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(6).getT(1);           // math::add<NV>
		auto& chain139 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(7);                 // Stack_impl::chain139_t<NV>
		auto& global_cable119 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(7).getT(0);  // Stack_impl::global_cable119_t<NV>
		auto& add113 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(7).getT(1);           // math::add<NV>
		auto& chain140 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(8);                 // Stack_impl::chain140_t<NV>
		auto& global_cable120 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(8).getT(0);  // Stack_impl::global_cable120_t<NV>
		auto& add114 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(8).getT(1);           // math::add<NV>
		auto& chain141 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(9);                 // Stack_impl::chain141_t<NV>
		auto& global_cable121 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(9).getT(0);  // Stack_impl::global_cable121_t<NV>
		auto& add115 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(9).getT(1);           // math::add<NV>
		auto& chain142 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(10);                // Stack_impl::chain142_t<NV>
		auto& global_cable122 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(10).getT(0); // Stack_impl::global_cable122_t<NV>
		auto& add116 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(10).getT(1);          // math::add<NV>
		auto& chain143 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(11);                // Stack_impl::chain143_t<NV>
		auto& global_cable123 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(11).getT(0); // Stack_impl::global_cable123_t<NV>
		auto& add117 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(11).getT(1);          // math::add<NV>
		auto& chain144 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(12);                // Stack_impl::chain144_t<NV>
		auto& global_cable124 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(12).getT(0); // Stack_impl::global_cable124_t<NV>
		auto& add118 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(12).getT(1);          // math::add<NV>
		auto& chain145 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(13);                // Stack_impl::chain145_t<NV>
		auto& global_cable125 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(13).getT(0); // Stack_impl::global_cable125_t<NV>
		auto& add119 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(13).getT(1);          // math::add<NV>
		auto& chain146 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(14);                // Stack_impl::chain146_t<NV>
		auto& global_cable126 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(14).getT(0); // Stack_impl::global_cable126_t<NV>
		auto& add120 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(14).getT(1);          // math::add<NV>
		auto& chain147 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(15);                // Stack_impl::chain147_t<NV>
		auto& global_cable127 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(15).getT(0); // Stack_impl::global_cable127_t<NV>
		auto& add121 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(15).getT(1);          // math::add<NV>
		auto& peak9 = this->getT(0).getT(0).getT(1).getT(3).getT(2);                            // Stack_impl::peak9_t<NV>
		auto& pma15 = this->getT(0).getT(0).getT(1).getT(3).getT(3);                            // Stack_impl::pma15_t<NV>
		auto& clear14 = this->getT(0).getT(0).getT(1).getT(3).getT(4);                          // math::clear<NV>
		auto& chain216 = this->getT(0).getT(0).getT(1).getT(4);                                 // Stack_impl::chain216_t<NV>
		auto& clear23 = this->getT(0).getT(0).getT(1).getT(4).getT(0);                          // math::clear<NV>
		auto& branch12 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                         // Stack_impl::branch12_t<NV>
		auto& chain217 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0);                 // Stack_impl::chain217_t<NV>
		auto& global_cable192 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).getT(0);  // Stack_impl::global_cable192_t<NV>
		auto& add186 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).getT(1);           // math::add<NV>
		auto& chain218 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(1);                 // Stack_impl::chain218_t<NV>
		auto& global_cable193 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(1).getT(0);  // Stack_impl::global_cable193_t<NV>
		auto& add187 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(1).getT(1);           // math::add<NV>
		auto& chain219 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(2);                 // Stack_impl::chain219_t<NV>
		auto& global_cable194 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(2).getT(0);  // Stack_impl::global_cable194_t<NV>
		auto& add188 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(2).getT(1);           // math::add<NV>
		auto& chain220 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(3);                 // Stack_impl::chain220_t<NV>
		auto& global_cable195 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(3).getT(0);  // Stack_impl::global_cable195_t<NV>
		auto& add189 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(3).getT(1);           // math::add<NV>
		auto& chain221 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(4);                 // Stack_impl::chain221_t<NV>
		auto& global_cable196 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(4).getT(0);  // Stack_impl::global_cable196_t<NV>
		auto& add190 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(4).getT(1);           // math::add<NV>
		auto& chain222 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(5);                 // Stack_impl::chain222_t<NV>
		auto& global_cable197 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(5).getT(0);  // Stack_impl::global_cable197_t<NV>
		auto& add191 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(5).getT(1);           // math::add<NV>
		auto& chain223 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(6);                 // Stack_impl::chain223_t<NV>
		auto& global_cable198 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(6).getT(0);  // Stack_impl::global_cable198_t<NV>
		auto& add192 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(6).getT(1);           // math::add<NV>
		auto& chain224 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(7);                 // Stack_impl::chain224_t<NV>
		auto& global_cable199 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(7).getT(0);  // Stack_impl::global_cable199_t<NV>
		auto& add193 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(7).getT(1);           // math::add<NV>
		auto& chain225 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(8);                 // Stack_impl::chain225_t<NV>
		auto& global_cable200 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(8).getT(0);  // Stack_impl::global_cable200_t<NV>
		auto& add194 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(8).getT(1);           // math::add<NV>
		auto& chain226 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(9);                 // Stack_impl::chain226_t<NV>
		auto& global_cable201 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(9).getT(0);  // Stack_impl::global_cable201_t<NV>
		auto& add195 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(9).getT(1);           // math::add<NV>
		auto& chain227 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(10);                // Stack_impl::chain227_t<NV>
		auto& global_cable202 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(10).getT(0); // Stack_impl::global_cable202_t<NV>
		auto& add196 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(10).getT(1);          // math::add<NV>
		auto& chain228 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(11);                // Stack_impl::chain228_t<NV>
		auto& global_cable203 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(11).getT(0); // Stack_impl::global_cable203_t<NV>
		auto& add197 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(11).getT(1);          // math::add<NV>
		auto& chain229 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(12);                // Stack_impl::chain229_t<NV>
		auto& global_cable204 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(12).getT(0); // Stack_impl::global_cable204_t<NV>
		auto& add198 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(12).getT(1);          // math::add<NV>
		auto& chain230 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(13);                // Stack_impl::chain230_t<NV>
		auto& global_cable205 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(13).getT(0); // Stack_impl::global_cable205_t<NV>
		auto& add199 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(13).getT(1);          // math::add<NV>
		auto& chain231 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(14);                // Stack_impl::chain231_t<NV>
		auto& global_cable206 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(14).getT(0); // Stack_impl::global_cable206_t<NV>
		auto& add200 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(14).getT(1);          // math::add<NV>
		auto& chain232 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(15);                // Stack_impl::chain232_t<NV>
		auto& global_cable207 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(15).getT(0); // Stack_impl::global_cable207_t<NV>
		auto& add201 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(15).getT(1);          // math::add<NV>
		auto& peak14 = this->getT(0).getT(0).getT(1).getT(4).getT(2);                           // Stack_impl::peak14_t<NV>
		auto& pma20 = this->getT(0).getT(0).getT(1).getT(4).getT(3);                            // Stack_impl::pma20_t<NV>
		auto& clear24 = this->getT(0).getT(0).getT(1).getT(4).getT(4);                          // math::clear<NV>
		auto& chain199 = this->getT(0).getT(0).getT(1).getT(5);                                 // Stack_impl::chain199_t<NV>
		auto& clear21 = this->getT(0).getT(0).getT(1).getT(5).getT(0);                          // math::clear<NV>
		auto& branch11 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                         // Stack_impl::branch11_t<NV>
		auto& chain200 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0);                 // Stack_impl::chain200_t<NV>
		auto& global_cable176 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).getT(0);  // Stack_impl::global_cable176_t<NV>
		auto& add170 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).getT(1);           // math::add<NV>
		auto& chain201 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(1);                 // Stack_impl::chain201_t<NV>
		auto& global_cable177 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(1).getT(0);  // Stack_impl::global_cable177_t<NV>
		auto& add171 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(1).getT(1);           // math::add<NV>
		auto& chain202 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(2);                 // Stack_impl::chain202_t<NV>
		auto& global_cable178 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(2).getT(0);  // Stack_impl::global_cable178_t<NV>
		auto& add172 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(2).getT(1);           // math::add<NV>
		auto& chain203 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(3);                 // Stack_impl::chain203_t<NV>
		auto& global_cable179 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(3).getT(0);  // Stack_impl::global_cable179_t<NV>
		auto& add173 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(3).getT(1);           // math::add<NV>
		auto& chain204 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(4);                 // Stack_impl::chain204_t<NV>
		auto& global_cable180 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(4).getT(0);  // Stack_impl::global_cable180_t<NV>
		auto& add174 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(4).getT(1);           // math::add<NV>
		auto& chain205 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(5);                 // Stack_impl::chain205_t<NV>
		auto& global_cable181 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(5).getT(0);  // Stack_impl::global_cable181_t<NV>
		auto& add175 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(5).getT(1);           // math::add<NV>
		auto& chain206 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(6);                 // Stack_impl::chain206_t<NV>
		auto& global_cable182 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(6).getT(0);  // Stack_impl::global_cable182_t<NV>
		auto& add176 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(6).getT(1);           // math::add<NV>
		auto& chain207 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(7);                 // Stack_impl::chain207_t<NV>
		auto& global_cable183 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(7).getT(0);  // Stack_impl::global_cable183_t<NV>
		auto& add177 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(7).getT(1);           // math::add<NV>
		auto& chain208 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(8);                 // Stack_impl::chain208_t<NV>
		auto& global_cable184 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(8).getT(0);  // Stack_impl::global_cable184_t<NV>
		auto& add178 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(8).getT(1);           // math::add<NV>
		auto& chain209 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(9);                 // Stack_impl::chain209_t<NV>
		auto& global_cable185 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(9).getT(0);  // Stack_impl::global_cable185_t<NV>
		auto& add179 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(9).getT(1);           // math::add<NV>
		auto& chain210 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(10);                // Stack_impl::chain210_t<NV>
		auto& global_cable186 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(10).getT(0); // Stack_impl::global_cable186_t<NV>
		auto& add180 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(10).getT(1);          // math::add<NV>
		auto& chain211 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(11);                // Stack_impl::chain211_t<NV>
		auto& global_cable187 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(11).getT(0); // Stack_impl::global_cable187_t<NV>
		auto& add181 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(11).getT(1);          // math::add<NV>
		auto& chain212 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(12);                // Stack_impl::chain212_t<NV>
		auto& global_cable188 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(12).getT(0); // Stack_impl::global_cable188_t<NV>
		auto& add182 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(12).getT(1);          // math::add<NV>
		auto& chain213 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(13);                // Stack_impl::chain213_t<NV>
		auto& global_cable189 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(13).getT(0); // Stack_impl::global_cable189_t<NV>
		auto& add183 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(13).getT(1);          // math::add<NV>
		auto& chain214 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(14);                // Stack_impl::chain214_t<NV>
		auto& global_cable190 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(14).getT(0); // Stack_impl::global_cable190_t<NV>
		auto& add184 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(14).getT(1);          // math::add<NV>
		auto& chain215 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(15);                // Stack_impl::chain215_t<NV>
		auto& global_cable191 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(15).getT(0); // Stack_impl::global_cable191_t<NV>
		auto& add185 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(15).getT(1);          // math::add<NV>
		auto& peak13 = this->getT(0).getT(0).getT(1).getT(5).getT(2);                           // Stack_impl::peak13_t<NV>
		auto& pma19 = this->getT(0).getT(0).getT(1).getT(5).getT(3);                            // Stack_impl::pma19_t<NV>
		auto& clear22 = this->getT(0).getT(0).getT(1).getT(5).getT(4);                          // math::clear<NV>
		auto& chain233 = this->getT(0).getT(0).getT(1).getT(6);                                 // Stack_impl::chain233_t<NV>
		auto& clear25 = this->getT(0).getT(0).getT(1).getT(6).getT(0);                          // math::clear<NV>
		auto& branch13 = this->getT(0).getT(0).getT(1).getT(6).getT(1);                         // Stack_impl::branch13_t<NV>
		auto& chain234 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(0);                 // Stack_impl::chain234_t<NV>
		auto& global_cable208 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(0).getT(0);  // Stack_impl::global_cable208_t<NV>
		auto& add202 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(0).getT(1);           // math::add<NV>
		auto& chain235 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(1);                 // Stack_impl::chain235_t<NV>
		auto& global_cable209 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(1).getT(0);  // Stack_impl::global_cable209_t<NV>
		auto& add203 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(1).getT(1);           // math::add<NV>
		auto& chain236 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(2);                 // Stack_impl::chain236_t<NV>
		auto& global_cable210 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(2).getT(0);  // Stack_impl::global_cable210_t<NV>
		auto& add204 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(2).getT(1);           // math::add<NV>
		auto& chain237 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(3);                 // Stack_impl::chain237_t<NV>
		auto& global_cable211 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(3).getT(0);  // Stack_impl::global_cable211_t<NV>
		auto& add205 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(3).getT(1);           // math::add<NV>
		auto& chain238 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(4);                 // Stack_impl::chain238_t<NV>
		auto& global_cable212 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(4).getT(0);  // routing::global_cable<global_cable212_t_index, parameter::empty>
		auto& add206 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(4).getT(1);           // math::add<NV>
		auto& chain239 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(5);                 // Stack_impl::chain239_t<NV>
		auto& global_cable213 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(5).getT(0);  // Stack_impl::global_cable213_t<NV>
		auto& add207 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(5).getT(1);           // math::add<NV>
		auto& chain240 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(6);                 // Stack_impl::chain240_t<NV>
		auto& global_cable214 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(6).getT(0);  // Stack_impl::global_cable214_t<NV>
		auto& add208 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(6).getT(1);           // math::add<NV>
		auto& chain241 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(7);                 // Stack_impl::chain241_t<NV>
		auto& global_cable215 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(7).getT(0);  // Stack_impl::global_cable215_t<NV>
		auto& add209 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(7).getT(1);           // math::add<NV>
		auto& chain242 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(8);                 // Stack_impl::chain242_t<NV>
		auto& global_cable216 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(8).getT(0);  // Stack_impl::global_cable216_t<NV>
		auto& add210 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(8).getT(1);           // math::add<NV>
		auto& chain243 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(9);                 // Stack_impl::chain243_t<NV>
		auto& global_cable217 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(9).getT(0);  // Stack_impl::global_cable217_t<NV>
		auto& add211 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(9).getT(1);           // math::add<NV>
		auto& chain244 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(10);                // Stack_impl::chain244_t<NV>
		auto& global_cable218 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(10).getT(0); // Stack_impl::global_cable218_t<NV>
		auto& add212 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(10).getT(1);          // math::add<NV>
		auto& chain245 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(11);                // Stack_impl::chain245_t<NV>
		auto& global_cable219 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(11).getT(0); // Stack_impl::global_cable219_t<NV>
		auto& add213 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(11).getT(1);          // math::add<NV>
		auto& chain246 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(12);                // Stack_impl::chain246_t<NV>
		auto& global_cable220 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(12).getT(0); // Stack_impl::global_cable220_t<NV>
		auto& add214 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(12).getT(1);          // math::add<NV>
		auto& chain247 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(13);                // Stack_impl::chain247_t<NV>
		auto& global_cable221 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(13).getT(0); // Stack_impl::global_cable221_t<NV>
		auto& add215 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(13).getT(1);          // math::add<NV>
		auto& chain248 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(14);                // Stack_impl::chain248_t<NV>
		auto& global_cable222 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(14).getT(0); // Stack_impl::global_cable222_t<NV>
		auto& add216 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(14).getT(1);          // math::add<NV>
		auto& chain249 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(15);                // Stack_impl::chain249_t<NV>
		auto& global_cable223 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(15).getT(0); // Stack_impl::global_cable223_t<NV>
		auto& add217 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(15).getT(1);          // math::add<NV>
		auto& peak15 = this->getT(0).getT(0).getT(1).getT(6).getT(2);                           // Stack_impl::peak15_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(1).getT(6).getT(3);                          // Stack_impl::chain14_t<NV>
		auto& clear2 = this->getT(0).getT(0).getT(1).getT(6).getT(3).getT(0);                   // math::clear<NV>
		auto& branch14 = this->getT(0).getT(0).getT(1).getT(6).getT(3).getT(1);                 // Stack_impl::branch14_t<NV>
		auto& chain15 = this->getT(0).getT(0).getT(1).getT(6).getT(3).getT(1).getT(0);          // Stack_impl::chain15_t<NV>
		auto& pma22 = this->getT(0).getT(0).getT(1).getT(6).                                    // Stack_impl::pma22_t<NV>
                      getT(3).getT(1).getT(0).getT(0);
		auto& add2 = this->getT(0).getT(0).getT(1).getT(6).                                     // math::add<NV>
                     getT(3).getT(1).getT(0).getT(1);
		auto& chain16 = this->getT(0).getT(0).getT(1).getT(6).getT(3).getT(1).getT(1);          // Stack_impl::chain16_t<NV>
		auto& pma23 = this->getT(0).getT(0).getT(1).getT(6).                                    // Stack_impl::pma23_t<NV>
                      getT(3).getT(1).getT(1).getT(0);
		auto& add3 = this->getT(0).getT(0).getT(1).getT(6).                                     // math::add<NV>
                     getT(3).getT(1).getT(1).getT(1);
		auto& peak1 = this->getT(0).getT(0).getT(1).getT(6).getT(3).getT(2);                    // Stack_impl::peak1_t
		auto& clear26 = this->getT(0).getT(0).getT(1).getT(6).getT(4);                          // math::clear<NV>
		auto& chain301 = this->getT(0).getT(0).getT(1).getT(7);                                 // Stack_impl::chain301_t<NV>
		auto& clear33 = this->getT(0).getT(0).getT(1).getT(7).getT(0);                          // math::clear<NV>
		auto& branch19 = this->getT(0).getT(0).getT(1).getT(7).getT(1);                         // Stack_impl::branch19_t<NV>
		auto& chain302 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(0);                 // Stack_impl::chain302_t<NV>
		auto& global_cable272 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(0).getT(0);  // Stack_impl::global_cable272_t<NV>
		auto& add266 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(0).getT(1);           // math::add<NV>
		auto& chain303 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(1);                 // Stack_impl::chain303_t<NV>
		auto& global_cable273 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(1).getT(0);  // Stack_impl::global_cable273_t<NV>
		auto& add267 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(1).getT(1);           // math::add<NV>
		auto& chain304 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(2);                 // Stack_impl::chain304_t<NV>
		auto& global_cable274 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(2).getT(0);  // Stack_impl::global_cable274_t<NV>
		auto& add268 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(2).getT(1);           // math::add<NV>
		auto& chain305 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(3);                 // Stack_impl::chain305_t<NV>
		auto& global_cable275 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(3).getT(0);  // Stack_impl::global_cable275_t<NV>
		auto& add269 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(3).getT(1);           // math::add<NV>
		auto& chain306 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(4);                 // Stack_impl::chain306_t<NV>
		auto& global_cable276 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(4).getT(0);  // Stack_impl::global_cable276_t<NV>
		auto& add270 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(4).getT(1);           // math::add<NV>
		auto& chain307 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(5);                 // Stack_impl::chain307_t<NV>
		auto& global_cable277 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(5).getT(0);  // Stack_impl::global_cable277_t<NV>
		auto& add271 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(5).getT(1);           // math::add<NV>
		auto& chain308 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(6);                 // Stack_impl::chain308_t<NV>
		auto& global_cable278 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(6).getT(0);  // Stack_impl::global_cable278_t<NV>
		auto& add272 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(6).getT(1);           // math::add<NV>
		auto& chain309 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(7);                 // Stack_impl::chain309_t<NV>
		auto& global_cable279 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(7).getT(0);  // Stack_impl::global_cable279_t<NV>
		auto& add273 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(7).getT(1);           // math::add<NV>
		auto& chain310 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(8);                 // Stack_impl::chain310_t<NV>
		auto& global_cable280 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(8).getT(0);  // Stack_impl::global_cable280_t<NV>
		auto& add274 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(8).getT(1);           // math::add<NV>
		auto& chain311 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(9);                 // Stack_impl::chain311_t<NV>
		auto& global_cable281 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(9).getT(0);  // Stack_impl::global_cable281_t<NV>
		auto& add275 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(9).getT(1);           // math::add<NV>
		auto& chain312 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(10);                // Stack_impl::chain312_t<NV>
		auto& global_cable282 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(10).getT(0); // Stack_impl::global_cable282_t<NV>
		auto& add276 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(10).getT(1);          // math::add<NV>
		auto& chain313 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(11);                // Stack_impl::chain313_t<NV>
		auto& global_cable283 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(11).getT(0); // Stack_impl::global_cable283_t<NV>
		auto& add277 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(11).getT(1);          // math::add<NV>
		auto& chain314 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(12);                // Stack_impl::chain314_t<NV>
		auto& global_cable284 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(12).getT(0); // Stack_impl::global_cable284_t<NV>
		auto& add278 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(12).getT(1);          // math::add<NV>
		auto& chain315 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(13);                // Stack_impl::chain315_t<NV>
		auto& global_cable285 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(13).getT(0); // Stack_impl::global_cable285_t<NV>
		auto& add279 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(13).getT(1);          // math::add<NV>
		auto& chain316 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(14);                // Stack_impl::chain316_t<NV>
		auto& global_cable286 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(14).getT(0); // Stack_impl::global_cable286_t<NV>
		auto& add280 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(14).getT(1);          // math::add<NV>
		auto& chain317 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(15);                // Stack_impl::chain317_t<NV>
		auto& global_cable287 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(15).getT(0); // Stack_impl::global_cable287_t<NV>
		auto& add281 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(15).getT(1);          // math::add<NV>
		auto& peak19 = this->getT(0).getT(0).getT(1).getT(7).getT(2);                           // Stack_impl::peak19_t<NV>
		auto& pma28 = this->getT(0).getT(0).getT(1).getT(7).getT(3);                            // Stack_impl::pma28_t<NV>
		auto& clear34 = this->getT(0).getT(0).getT(1).getT(7).getT(4);                          // math::clear<NV>
		auto& pack_resizer1 = this->getT(0).getT(0).getT(2);                                    // Stack_impl::pack_resizer1_t
		auto& modchain = this->getT(0).getT(1);                                                 // Stack_impl::modchain_t<NV>
		auto& split = this->getT(0).getT(1).getT(0);                                            // Stack_impl::split_t<NV>
		auto& xfader = this->getT(0).getT(1).getT(0).getT(0);                                   // Stack_impl::xfader_t<NV>
		auto& xfader1 = this->getT(0).getT(1).getT(0).getT(1);                                  // Stack_impl::xfader1_t<NV>
		auto& xfader2 = this->getT(0).getT(1).getT(0).getT(2);                                  // Stack_impl::xfader2_t<NV>
		auto& split16 = this->getT(0).getT(2);                                                  // Stack_impl::split16_t<NV>
		auto& chain24 = this->getT(0).getT(2).getT(0);                                          // Stack_impl::chain24_t<NV>
		auto& input_toggle16 = this->getT(0).getT(2).getT(0).getT(0);                           // Stack_impl::input_toggle16_t<NV>
		auto& input_toggle2 = this->getT(0).getT(2).getT(0).getT(1);                            // Stack_impl::input_toggle2_t<NV>
		auto& oversample = this->getT(0).getT(2).getT(0).getT(2);                               // Stack_impl::oversample_t<NV>
		auto& chain19 = this->getT(0).getT(2).getT(0).getT(2).getT(0);                          // Stack_impl::chain19_t<NV>
		auto& event_data_reader1 = this->getT(0).getT(2).getT(0).getT(2).getT(0).getT(0);       // Stack_impl::event_data_reader1_t<NV>
		auto& minmax9 = this->getT(0).getT(2).getT(0).getT(2).getT(0).getT(1);                  // Stack_impl::minmax9_t<NV>
		auto& tempo_sync2 = this->getT(0).getT(2).getT(0).getT(2).getT(0).getT(2);              // Stack_impl::tempo_sync2_t<NV>
		auto& minmax8 = this->getT(0).getT(2).getT(0).getT(2).getT(0).getT(3);                  // Stack_impl::minmax8_t<NV>
		auto& granulator = this->getT(0).getT(2).getT(0).getT(2).getT(1);                       // Stack_impl::granulator_t
		auto& chain4 = this->getT(0).getT(2).getT(0).getT(3);                                   // Stack_impl::chain4_t<NV>
		auto& chain28 = this->getT(0).getT(2).getT(0).getT(3).getT(0);                          // Stack_impl::chain28_t<NV>
		auto& tempo_sync = this->getT(0).getT(2).getT(0).getT(3).getT(0).getT(0);               // Stack_impl::tempo_sync_t<NV>
		auto& tempo_sync1 = this->getT(0).getT(2).getT(0).getT(3).getT(0).getT(1);              // Stack_impl::tempo_sync1_t<NV>
		auto& faust = this->getT(0).getT(2).getT(0).getT(3).getT(0).getT(2);                    // project::PitchShifter<NV>
		auto& split1 = this->getT(0).getT(2).getT(0).getT(3).getT(1);                           // Stack_impl::split1_t<NV>
		auto& chain39 = this->getT(0).getT(2).getT(0).getT(3).getT(1).getT(0);                  // Stack_impl::chain39_t
		auto& chain43 = this->getT(0).getT(2).getT(0).getT(3).getT(1).getT(1);                  // Stack_impl::chain43_t<NV>
		auto& clear16 = this->getT(0).getT(2).getT(0).getT(3).getT(1).getT(1).getT(0);          // math::clear<NV>
		auto& branch1 = this->getT(0).getT(2).getT(0).getT(3).getT(1).getT(1).getT(1);          // Stack_impl::branch1_t<NV>
		auto& chain5 = this->getT(0).getT(2).getT(0).getT(3).                                   // Stack_impl::chain5_t<NV>
                       getT(1).getT(1).getT(1).getT(0);
		auto& add9 = this->getT(0).getT(2).getT(0).getT(3).                                   // math::add<NV>
                     getT(1).getT(1).getT(1).getT(0).
                     getT(0);
		auto& chain6 = this->getT(0).getT(2).getT(0).getT(3).                                 // Stack_impl::chain6_t<NV>
                       getT(1).getT(1).getT(1).getT(1);
		auto& add10 = this->getT(0).getT(2).getT(0).getT(3).                                  // math::add<NV>
                      getT(1).getT(1).getT(1).getT(1).
                      getT(0);
		auto& chain7 = this->getT(0).getT(2).getT(0).getT(3).                                 // Stack_impl::chain7_t<NV>
                       getT(1).getT(1).getT(1).getT(2);
		auto& add11 = this->getT(0).getT(2).getT(0).getT(3).                                  // math::add<NV>
                      getT(1).getT(1).getT(1).getT(2).
                      getT(0);
		auto& chain17 = this->getT(0).getT(2).getT(0).getT(3).                                // Stack_impl::chain17_t<NV>
                        getT(1).getT(1).getT(1).getT(3);
		auto& add18 = this->getT(0).getT(2).getT(0).getT(3).                                  // math::add<NV>
                      getT(1).getT(1).getT(1).getT(3).
                      getT(0);
		auto& peak4 = this->getT(0).getT(2).getT(0).getT(3).getT(1).getT(1).getT(2);          // Stack_impl::peak4_t<NV>
		auto& clear3 = this->getT(0).getT(2).getT(0).getT(3).getT(1).getT(1).getT(3);         // math::clear<NV>
		auto& cable_table16 = this->getT(0).getT(2).getT(0).getT(4);                          // Stack_impl::cable_table16_t
		auto& gain1 = this->getT(0).getT(2).getT(0).getT(5);                                  // core::gain<NV>
		auto& branch3 = this->getT(0).getT(2).getT(1);                                        // Stack_impl::branch3_t<NV>
		auto& chain12 = this->getT(0).getT(2).getT(1).getT(0);                                // Stack_impl::chain12_t
		auto& chain13 = this->getT(0).getT(2).getT(1).getT(1);                                // Stack_impl::chain13_t<NV>
		auto& split2 = this->getT(0).getT(2).getT(1).getT(1).getT(0);                         // Stack_impl::split2_t<NV>
		auto& chain42 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(0);                // Stack_impl::chain42_t<NV>
		auto& input_toggle34 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(0).getT(0); // Stack_impl::input_toggle34_t<NV>
		auto& input_toggle11 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(0).getT(1); // Stack_impl::input_toggle11_t<NV>
		auto& chain29 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(0).getT(2);        // Stack_impl::chain29_t<NV>
		auto& oversample1 = this->getT(0).getT(2).getT(1).getT(1).                            // Stack_impl::oversample1_t<NV>
                            getT(0).getT(0).getT(2).getT(0);
		auto& chain34 = this->getT(0).getT(2).getT(1).getT(1).                                // Stack_impl::chain34_t<NV>
                        getT(0).getT(0).getT(2).getT(0).
                        getT(0);
		auto& event_data_reader2 = this->getT(0).getT(2).getT(1).getT(1).getT(0).             // Stack_impl::event_data_reader2_t<NV>
                                   getT(0).getT(2).getT(0).getT(0).getT(0);
		auto& minmax10 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                       // Stack_impl::minmax10_t<NV>
                         getT(0).getT(2).getT(0).getT(0).getT(1);
		auto& tempo_sync10 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                   // Stack_impl::tempo_sync10_t<NV>
                             getT(0).getT(2).getT(0).getT(0).getT(2);
		auto& minmax11 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                       // Stack_impl::minmax11_t<NV>
                         getT(0).getT(2).getT(0).getT(0).getT(3);
		auto& granulator1 = this->getT(0).getT(2).getT(1).getT(1).                            // Stack_impl::granulator1_t
                            getT(0).getT(0).getT(2).getT(0).
                            getT(1);
		auto& tempo_sync3 = this->getT(0).getT(2).getT(1).getT(1).                            // Stack_impl::tempo_sync3_t<NV>
                            getT(0).getT(0).getT(2).getT(1);
		auto& tempo_sync8 = this->getT(0).getT(2).getT(1).getT(1).                            // Stack_impl::tempo_sync8_t<NV>
                            getT(0).getT(0).getT(2).getT(2);
		auto& faust1 = this->getT(0).getT(2).getT(1).getT(1).                                 // project::PitchShifter<NV>
                       getT(0).getT(0).getT(2).getT(3);
		auto& split7 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(0).getT(3);         // Stack_impl::split7_t<NV>
		auto& chain48 = this->getT(0).getT(2).getT(1).getT(1).                                // Stack_impl::chain48_t
                        getT(0).getT(0).getT(3).getT(0);
		auto& chain49 = this->getT(0).getT(2).getT(1).getT(1).                                // Stack_impl::chain49_t<NV>
                        getT(0).getT(0).getT(3).getT(1);
		auto& clear15 = this->getT(0).getT(2).getT(1).getT(1).                                // math::clear<NV>
                        getT(0).getT(0).getT(3).getT(1).
                        getT(0);
		auto& branch8 = this->getT(0).getT(2).getT(1).getT(1).                                // Stack_impl::branch8_t<NV>
                        getT(0).getT(0).getT(3).getT(1).
                        getT(1);
		auto& chain20 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                        // Stack_impl::chain20_t<NV>
                        getT(0).getT(3).getT(1).getT(1).getT(0);
		auto& add12 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                          // math::add<NV>
                      getT(0).getT(3).getT(1).getT(1).getT(0).
                      getT(0);
		auto& chain21 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                        // Stack_impl::chain21_t<NV>
                        getT(0).getT(3).getT(1).getT(1).getT(1);
		auto& add13 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                          // math::add<NV>
                      getT(0).getT(3).getT(1).getT(1).getT(1).
                      getT(0);
		auto& chain22 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                        // Stack_impl::chain22_t<NV>
                        getT(0).getT(3).getT(1).getT(1).getT(2);
		auto& add14 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                          // math::add<NV>
                      getT(0).getT(3).getT(1).getT(1).getT(2).
                      getT(0);
		auto& chain32 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                        // Stack_impl::chain32_t<NV>
                        getT(0).getT(3).getT(1).getT(1).getT(3);
		auto& add19 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                          // math::add<NV>
                      getT(0).getT(3).getT(1).getT(1).getT(3).
                      getT(0);
		auto& chain8 = this->getT(0).getT(2).getT(1).getT(1).                                 // Stack_impl::chain8_t<NV>
                       getT(0).getT(0).getT(3).getT(1).
                       getT(2);
		auto& peak5 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                          // Stack_impl::peak5_t<NV>
                      getT(0).getT(3).getT(1).getT(2).getT(0);
		auto& cable_table34 = this->getT(0).getT(2).getT(1).getT(1).                          // Stack_impl::cable_table34_t
                              getT(0).getT(0).getT(3).getT(1).
                              getT(3);
		auto& clear6 = this->getT(0).getT(2).getT(1).getT(1).                                 // math::clear<NV>
                       getT(0).getT(0).getT(3).getT(1).
                       getT(4);
		auto& gain2 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(0).getT(4);          // core::gain<NV>
		auto& chain41 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1);                // Stack_impl::chain41_t<NV>
		auto& input_toggle33 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1).getT(0); // Stack_impl::input_toggle33_t<NV>
		auto& input_toggle10 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1).getT(1); // Stack_impl::input_toggle10_t<NV>
		auto& chain30 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1).getT(2);        // Stack_impl::chain30_t<NV>
		auto& oversample3 = this->getT(0).getT(2).getT(1).getT(1).                            // Stack_impl::oversample3_t<NV>
                            getT(0).getT(1).getT(2).getT(0);
		auto& chain35 = this->getT(0).getT(2).getT(1).getT(1).                                // Stack_impl::chain35_t<NV>
                        getT(0).getT(1).getT(2).getT(0).
                        getT(0);
		auto& event_data_reader3 = this->getT(0).getT(2).getT(1).getT(1).getT(0).             // Stack_impl::event_data_reader3_t<NV>
                                   getT(1).getT(2).getT(0).getT(0).getT(0);
		auto& minmax12 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                       // Stack_impl::minmax12_t<NV>
                         getT(1).getT(2).getT(0).getT(0).getT(1);
		auto& tempo_sync11 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                   // Stack_impl::tempo_sync11_t<NV>
                             getT(1).getT(2).getT(0).getT(0).getT(2);
		auto& minmax13 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                       // Stack_impl::minmax13_t<NV>
                         getT(1).getT(2).getT(0).getT(0).getT(3);
		auto& granulator2 = this->getT(0).getT(2).getT(1).getT(1).                            // Stack_impl::granulator2_t
                            getT(0).getT(1).getT(2).getT(0).
                            getT(1);
		auto& tempo_sync5 = this->getT(0).getT(2).getT(1).getT(1).                            // Stack_impl::tempo_sync5_t<NV>
                            getT(0).getT(1).getT(2).getT(1);
		auto& tempo_sync6 = this->getT(0).getT(2).getT(1).getT(1).                            // Stack_impl::tempo_sync6_t<NV>
                            getT(0).getT(1).getT(2).getT(2);
		auto& faust2 = this->getT(0).getT(2).getT(1).getT(1).                                 // project::PitchShifter<NV>
                       getT(0).getT(1).getT(2).getT(3);
		auto& split6 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1).getT(3);         // Stack_impl::split6_t<NV>
		auto& chain46 = this->getT(0).getT(2).getT(1).getT(1).                                // Stack_impl::chain46_t
                        getT(0).getT(1).getT(3).getT(0);
		auto& chain47 = this->getT(0).getT(2).getT(1).getT(1).                                // Stack_impl::chain47_t<NV>
                        getT(0).getT(1).getT(3).getT(1);
		auto& chain23 = this->getT(0).getT(2).getT(1).getT(1).                                // Stack_impl::chain23_t<NV>
                        getT(0).getT(1).getT(3).getT(1).
                        getT(0);
		auto& clear18 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                        // math::clear<NV>
                        getT(1).getT(3).getT(1).getT(0).getT(0);
		auto& branch17 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                       // Stack_impl::branch17_t<NV>
                         getT(1).getT(3).getT(1).getT(0).getT(1);
		auto& chain25 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                        // Stack_impl::chain25_t<NV>
                        getT(1).getT(3).getT(1).getT(0).getT(1).
                        getT(0);
		auto& add15 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1).                  // math::add<NV>
                      getT(3).getT(1).getT(0).getT(1).getT(0).getT(0);
		auto& chain26 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                        // Stack_impl::chain26_t<NV>
                        getT(1).getT(3).getT(1).getT(0).getT(1).
                        getT(1);
		auto& add16 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1).                  // math::add<NV>
                      getT(3).getT(1).getT(0).getT(1).getT(1).getT(0);
		auto& chain27 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                        // Stack_impl::chain27_t<NV>
                        getT(1).getT(3).getT(1).getT(0).getT(1).
                        getT(2);
		auto& add17 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1).                  // math::add<NV>
                      getT(3).getT(1).getT(0).getT(1).getT(2).getT(0);
		auto& chain33 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                        // Stack_impl::chain33_t<NV>
                        getT(1).getT(3).getT(1).getT(0).getT(1).
                        getT(3);
		auto& add20 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1).                  // math::add<NV>
                      getT(3).getT(1).getT(0).getT(1).getT(3).getT(0);
		auto& peak10 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                         // Stack_impl::peak10_t<NV>
                       getT(1).getT(3).getT(1).getT(0).getT(2);
		auto& clear5 = this->getT(0).getT(2).getT(1).getT(1).                                 // math::clear<NV>
                       getT(0).getT(1).getT(3).getT(1).
                       getT(1);
		auto& cable_table33 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1).getT(4);  // Stack_impl::cable_table33_t
		auto& gain3 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1).getT(5);          // core::gain<NV>
		auto& chain40 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2);                // Stack_impl::chain40_t<NV>
		auto& input_toggle32 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2).getT(0); // Stack_impl::input_toggle32_t<NV>
		auto& input_toggle9 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2).getT(1);  // Stack_impl::input_toggle9_t<NV>
		auto& chain31 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2).getT(2);        // Stack_impl::chain31_t<NV>
		auto& oversample2 = this->getT(0).getT(2).getT(1).getT(1).                            // Stack_impl::oversample2_t<NV>
                            getT(0).getT(2).getT(2).getT(0);
		auto& chain36 = this->getT(0).getT(2).getT(1).getT(1).                               // Stack_impl::chain36_t<NV>
                        getT(0).getT(2).getT(2).getT(0).
                        getT(0);
		auto& event_data_reader4 = this->getT(0).getT(2).getT(1).getT(1).getT(0).            // Stack_impl::event_data_reader4_t<NV>
                                   getT(2).getT(2).getT(0).getT(0).getT(0);
		auto& minmax14 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                      // Stack_impl::minmax14_t<NV>
                         getT(2).getT(2).getT(0).getT(0).getT(1);
		auto& tempo_sync12 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                  // Stack_impl::tempo_sync12_t<NV>
                             getT(2).getT(2).getT(0).getT(0).getT(2);
		auto& minmax15 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                      // Stack_impl::minmax15_t<NV>
                         getT(2).getT(2).getT(0).getT(0).getT(3);
		auto& granulator3 = this->getT(0).getT(2).getT(1).getT(1).                           // Stack_impl::granulator3_t
                            getT(0).getT(2).getT(2).getT(0).
                            getT(1);
		auto& tempo_sync7 = this->getT(0).getT(2).getT(1).getT(1).                           // Stack_impl::tempo_sync7_t<NV>
                            getT(0).getT(2).getT(2).getT(1);
		auto& tempo_sync4 = this->getT(0).getT(2).getT(1).getT(1).                           // control::tempo_sync<NV>
                            getT(0).getT(2).getT(2).getT(2);
		auto& faust3 = this->getT(0).getT(2).getT(1).getT(1).                                // project::PitchShifter<NV>
                       getT(0).getT(2).getT(2).getT(3);
		auto& cable_table32 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2).getT(3); // Stack_impl::cable_table32_t
		auto& split5 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2).getT(4);        // Stack_impl::split5_t<NV>
		auto& chain44 = this->getT(0).getT(2).getT(1).getT(1).                               // Stack_impl::chain44_t
                        getT(0).getT(2).getT(4).getT(0);
		auto& chain45 = this->getT(0).getT(2).getT(1).getT(1).                       // Stack_impl::chain45_t<NV>
                        getT(0).getT(2).getT(4).getT(1);
		auto& clear17 = this->getT(0).getT(2).getT(1).getT(1).                       // math::clear<NV>
                        getT(0).getT(2).getT(4).getT(1).
                        getT(0);
		auto& chain1 = this->getT(0).getT(2).getT(1).getT(1).                        // Stack_impl::chain1_t<NV>
                       getT(0).getT(2).getT(4).getT(1).
                       getT(1);
		auto& branch = this->getT(0).getT(2).getT(1).getT(1).getT(0).                // Stack_impl::branch_t<NV>
                       getT(2).getT(4).getT(1).getT(1).getT(0);
		auto& chain = this->getT(0).getT(2).getT(1).getT(1).getT(0).                 // Stack_impl::chain_t<NV>
                      getT(2).getT(4).getT(1).getT(1).getT(0).
                      getT(0);
		auto& add6 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2).          // math::add<NV>
                     getT(4).getT(1).getT(1).getT(0).getT(0).getT(0);
		auto& chain2 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                // Stack_impl::chain2_t<NV>
                       getT(2).getT(4).getT(1).getT(1).getT(0).
                       getT(1);
		auto& add7 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2).          // math::add<NV>
                     getT(4).getT(1).getT(1).getT(0).getT(1).getT(0);
		auto& chain3 = this->getT(0).getT(2).getT(1).getT(1).getT(0).                // Stack_impl::chain3_t<NV>
                       getT(2).getT(4).getT(1).getT(1).getT(0).
                       getT(2);
		auto& add8 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2).          // math::add<NV>
                     getT(4).getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& chain18 = this->getT(0).getT(2).getT(1).getT(1).getT(0).               // Stack_impl::chain18_t<NV>
                        getT(2).getT(4).getT(1).getT(1).getT(0).
                        getT(3);
		auto& add21 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2).         // math::add<NV>
                      getT(4).getT(1).getT(1).getT(0).getT(3).getT(0);
		auto& peak3 = this->getT(0).getT(2).getT(1).getT(1).                         // Stack_impl::peak3_t<NV>
                      getT(0).getT(2).getT(4).getT(1).
                      getT(2);
		auto& clear4 = this->getT(0).getT(2).getT(1).getT(1).                        // math::clear<NV>
                       getT(0).getT(2).getT(4).getT(1).
                       getT(3);
		auto& gain4 = this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2).getT(5); // core::gain<NV>
		auto& gain = this->getT(1);                                                  // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		chain80.getParameterT(0).connectT(0, branch4);   // ModSrc -> branch4::Index
		chain114.getParameterT(0).connectT(0, branch6);  // ModSrc -> branch6::Index
		chain97.getParameterT(0).connectT(0, branch5);   // ModSrc -> branch5::Index
		chain131.getParameterT(0).connectT(0, branch7);  // ModSrc -> branch7::Index
		chain216.getParameterT(0).connectT(0, branch12); // ModSrc -> branch12::Index
		chain199.getParameterT(0).connectT(0, branch11); // ModSrc -> branch11::Index
		chain233.getParameterT(0).connectT(0, branch13); // ModSrc -> branch13::Index
		chain301.getParameterT(0).connectT(0, branch19); // ModSrc -> branch19::Index
		this->getParameterT(0).connectT(0, pma12);       // Position -> pma12::Add
		
		this->getParameterT(1).connectT(0, pma12); // PositionMod -> pma12::Multiply
		
		this->getParameterT(2).connectT(0, chain80); // PositionSrc -> chain80::ModSrc
		
		auto& PositionModMode_p = this->getParameterT(3);
		PositionModMode_p.connectT(0, input_toggle16); // PositionModMode -> input_toggle16::Input
		PositionModMode_p.connectT(1, input_toggle32); // PositionModMode -> input_toggle32::Input
		PositionModMode_p.connectT(2, input_toggle33); // PositionModMode -> input_toggle33::Input
		PositionModMode_p.connectT(3, input_toggle34); // PositionModMode -> input_toggle34::Input
		
		auto& PitchMod_p = this->getParameterT(4);
		PitchMod_p.connectT(0, pma);  // PitchMod -> pma::Multiply
		PitchMod_p.connectT(1, pma4); // PitchMod -> pma4::Multiply
		
		this->getParameterT(5).connectT(0, chain114); // PitchSrc -> chain114::ModSrc
		
		auto& PitchModMode_p = this->getParameterT(6);
		PitchModMode_p.connectT(0, input_toggle2);  // PitchModMode -> input_toggle2::Input
		PitchModMode_p.connectT(1, input_toggle10); // PitchModMode -> input_toggle10::Input
		PitchModMode_p.connectT(2, input_toggle9);  // PitchModMode -> input_toggle9::Input
		PitchModMode_p.connectT(3, input_toggle11); // PitchModMode -> input_toggle11::Input
		
		this->getParameterT(7).connectT(0, pma13); // Grain -> pma13::Add
		
		auto& GrainMod_p = this->getParameterT(8);
		GrainMod_p.connectT(0, pma13); // GrainMod -> pma13::Multiply
		GrainMod_p.connectT(1, pma21); // GrainMod -> pma21::Multiply
		
		this->getParameterT(9).connectT(0, chain97); // GrainSrc -> chain97::ModSrc
		
		auto& GrainSync_p = this->getParameterT(10);
		GrainSync_p.connectT(0, branch2);      // GrainSync -> branch2::Index
		GrainSync_p.connectT(1, tempo_sync12); // GrainSync -> tempo_sync12::Enabled
		GrainSync_p.connectT(2, tempo_sync11); // GrainSync -> tempo_sync11::Enabled
		GrainSync_p.connectT(3, tempo_sync10); // GrainSync -> tempo_sync10::Enabled
		GrainSync_p.connectT(4, tempo_sync2);  // GrainSync -> tempo_sync2::Enabled
		
		this->getParameterT(11).connectT(0, pma21); // GrainTempo -> pma21::Add
		
		auto& GrainDiv_p = this->getParameterT(12);
		GrainDiv_p.connectT(0, tempo_sync12); // GrainDiv -> tempo_sync12::Multiplier
		GrainDiv_p.connectT(1, tempo_sync11); // GrainDiv -> tempo_sync11::Multiplier
		GrainDiv_p.connectT(2, tempo_sync10); // GrainDiv -> tempo_sync10::Multiplier
		GrainDiv_p.connectT(3, tempo_sync2);  // GrainDiv -> tempo_sync2::Multiplier
		
		auto& GrainAnSlot_p = this->getParameterT(13);
		GrainAnSlot_p.connectT(0, event_data_reader1); // GrainAnSlot -> event_data_reader1::SlotIndex
		GrainAnSlot_p.connectT(1, event_data_reader2); // GrainAnSlot -> event_data_reader2::SlotIndex
		GrainAnSlot_p.connectT(2, event_data_reader4); // GrainAnSlot -> event_data_reader4::SlotIndex
		
		this->getParameterT(14).connectT(0, pma15); // Demse -> pma15::Add
		
		this->getParameterT(15).connectT(0, pma15); // DenseMod -> pma15::Multiply
		
		this->getParameterT(16).connectT(0, chain131); // DenseSrc -> chain131::ModSrc
		
		this->getParameterT(17).connectT(0, pma20); // Spread -> pma20::Add
		
		this->getParameterT(18).connectT(0, pma20); // SpreadMod -> pma20::Multiply
		
		this->getParameterT(19).connectT(0, chain216); // SpreadSrc -> chain216::ModSrc
		
		this->getParameterT(20).connectT(0, pma19); // Detune -> pma19::Add
		
		this->getParameterT(21).connectT(0, pma19); // DetuneMod -> pma19::Multiply
		
		this->getParameterT(22).connectT(0, chain199); // DetuneSrc -> chain199::ModSrc
		
		this->getParameterT(23).connectT(0, pma22); // WinTime -> pma22::Add
		
		this->getParameterT(24).connectT(0, pma23); // WinTempo -> pma23::Add
		
		auto& WinDiv_p = this->getParameterT(25);
		WinDiv_p.connectT(0, tempo_sync7); // WinDiv -> tempo_sync7::Multiplier
		WinDiv_p.connectT(1, tempo_sync5); // WinDiv -> tempo_sync5::Multiplier
		WinDiv_p.connectT(2, tempo_sync3); // WinDiv -> tempo_sync3::Multiplier
		WinDiv_p.connectT(3, tempo_sync);  // WinDiv -> tempo_sync::Multiplier
		WinDiv_p.connectT(4, tempo_sync1); // WinDiv -> tempo_sync1::Multiplier
		WinDiv_p.connectT(5, tempo_sync4); // WinDiv -> tempo_sync4::Multiplier
		WinDiv_p.connectT(6, tempo_sync6); // WinDiv -> tempo_sync6::Multiplier
		WinDiv_p.connectT(7, tempo_sync8); // WinDiv -> tempo_sync8::Multiplier
		
		auto& WinSync_p = this->getParameterT(26);
		WinSync_p.connectT(0, branch14);    // WinSync -> branch14::Index
		WinSync_p.connectT(1, tempo_sync);  // WinSync -> tempo_sync::Enabled
		WinSync_p.connectT(2, tempo_sync3); // WinSync -> tempo_sync3::Enabled
		WinSync_p.connectT(3, tempo_sync5); // WinSync -> tempo_sync5::Enabled
		WinSync_p.connectT(4, tempo_sync7); // WinSync -> tempo_sync7::Enabled
		WinSync_p.connectT(5, tempo_sync1); // WinSync -> tempo_sync1::Enabled
		WinSync_p.connectT(6, tempo_sync4); // WinSync -> tempo_sync4::Enabled
		WinSync_p.connectT(7, tempo_sync6); // WinSync -> tempo_sync6::Enabled
		WinSync_p.connectT(8, tempo_sync8); // WinSync -> tempo_sync8::Enabled
		
		auto& WinMod_p = this->getParameterT(27);
		WinMod_p.connectT(0, pma22); // WinMod -> pma22::Multiply
		WinMod_p.connectT(1, pma23); // WinMod -> pma23::Multiply
		
		this->getParameterT(28).connectT(0, chain233); // WinSrc -> chain233::ModSrc
		
		this->getParameterT(34).connectT(0, branch3); // Stack -> branch3::Index
		
		auto& XfMode_p = this->getParameterT(35);
		XfMode_p.connectT(0, branch1);  // XfMode -> branch1::Index
		XfMode_p.connectT(1, branch8);  // XfMode -> branch8::Index
		XfMode_p.connectT(2, branch17); // XfMode -> branch17::Index
		XfMode_p.connectT(3, branch);   // XfMode -> branch::Index
		
		this->getParameterT(36).connectT(0, pma28); // Xfade -> pma28::Add
		
		this->getParameterT(37).connectT(0, pma28); // XfadeMod -> pma28::Multiply
		
		this->getParameterT(38).connectT(0, chain301); // XfadeSrc -> chain301::ModSrc
		
		this->getParameterT(39).connectT(0, pma); // PitchStack -> pma::Add
		
		this->getParameterT(40).connectT(0, pma4); // Pitch -> pma4::Add
		
		auto& FadeTempo_p = this->getParameterT(41);
		FadeTempo_p.connectT(0, tempo_sync1); // FadeTempo -> tempo_sync1::Tempo
		FadeTempo_p.connectT(1, tempo_sync8); // FadeTempo -> tempo_sync8::Tempo
		FadeTempo_p.connectT(2, tempo_sync6); // FadeTempo -> tempo_sync6::Tempo
		FadeTempo_p.connectT(3, tempo_sync4); // FadeTempo -> tempo_sync4::Tempo
		
		auto& FadeTime_p = this->getParameterT(42);
		FadeTime_p.connectT(0, tempo_sync1); // FadeTime -> tempo_sync1::UnsyncedTime
		FadeTime_p.connectT(1, tempo_sync8); // FadeTime -> tempo_sync8::UnsyncedTime
		FadeTime_p.connectT(2, tempo_sync6); // FadeTime -> tempo_sync6::UnsyncedTime
		FadeTime_p.connectT(3, tempo_sync4); // FadeTime -> tempo_sync4::UnsyncedTime
		
		auto& over_p = this->getParameterT(43);
		over_p.connectT(0, oversample2); // over -> oversample2::Oversampling
		over_p.connectT(1, oversample3); // over -> oversample3::Oversampling
		over_p.connectT(2, oversample1); // over -> oversample1::Oversampling
		over_p.connectT(3, oversample);  // over -> oversample::Oversampling
		
		auto& Step_p = this->getParameterT(44);
		Step_p.connectT(0, minmax);  // Step -> minmax::Step
		Step_p.connectT(1, minmax1); // Step -> minmax1::Step
		Step_p.connectT(2, minmax7); // Step -> minmax7::Step
		Step_p.connectT(3, minmax6); // Step -> minmax6::Step
		Step_p.connectT(4, minmax5); // Step -> minmax5::Step
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable64.getWrappedObject().getParameter().connectT(0, add58);         // global_cable64 -> add58::Value
		global_cable65.getWrappedObject().getParameter().connectT(0, add59);         // global_cable65 -> add59::Value
		global_cable66.getWrappedObject().getParameter().connectT(0, add60);         // global_cable66 -> add60::Value
		global_cable67.getWrappedObject().getParameter().connectT(0, add61);         // global_cable67 -> add61::Value
		global_cable68.getWrappedObject().getParameter().connectT(0, add62);         // global_cable68 -> add62::Value
		global_cable69.getWrappedObject().getParameter().connectT(0, add63);         // global_cable69 -> add63::Value
		global_cable70.getWrappedObject().getParameter().connectT(0, add64);         // global_cable70 -> add64::Value
		global_cable71.getWrappedObject().getParameter().connectT(0, add65);         // global_cable71 -> add65::Value
		global_cable72.getWrappedObject().getParameter().connectT(0, add66);         // global_cable72 -> add66::Value
		global_cable73.getWrappedObject().getParameter().connectT(0, add67);         // global_cable73 -> add67::Value
		global_cable74.getWrappedObject().getParameter().connectT(0, add68);         // global_cable74 -> add68::Value
		global_cable75.getWrappedObject().getParameter().connectT(0, add69);         // global_cable75 -> add69::Value
		global_cable76.getWrappedObject().getParameter().connectT(0, add70);         // global_cable76 -> add70::Value
		global_cable77.getWrappedObject().getParameter().connectT(0, add71);         // global_cable77 -> add71::Value
		global_cable78.getWrappedObject().getParameter().connectT(0, add72);         // global_cable78 -> add72::Value
		global_cable79.getWrappedObject().getParameter().connectT(0, add73);         // global_cable79 -> add73::Value
		input_toggle16.getWrappedObject().getParameter().connectT(0, cable_table16); // input_toggle16 -> cable_table16::Value
		input_toggle16.getWrappedObject().getParameter().connectT(1, granulator);    // input_toggle16 -> granulator::Position
		input_toggle34.getWrappedObject().getParameter().connectT(0, cable_table34); // input_toggle34 -> cable_table34::Value
		input_toggle34.getWrappedObject().getParameter().connectT(1, granulator1);   // input_toggle34 -> granulator1::Position
		input_toggle33.getWrappedObject().getParameter().connectT(0, cable_table33); // input_toggle33 -> cable_table33::Value
		input_toggle33.getWrappedObject().getParameter().connectT(1, granulator2);   // input_toggle33 -> granulator2::Position
		input_toggle32.getWrappedObject().getParameter().connectT(0, cable_table32); // input_toggle32 -> cable_table32::Value
		input_toggle32.getWrappedObject().getParameter().connectT(1, granulator3);   // input_toggle32 -> granulator3::Position
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, input_toggle16);             // sliderbank -> input_toggle16::Value2
		sliderbank_p.getParameterT(1).connectT(0, input_toggle34);             // sliderbank -> input_toggle34::Value2
		sliderbank_p.getParameterT(2).connectT(0, input_toggle33);             // sliderbank -> input_toggle33::Value2
		sliderbank_p.getParameterT(3).connectT(0, input_toggle32);             // sliderbank -> input_toggle32::Value2
		pma12.getWrappedObject().getParameter().connectT(0, input_toggle16);   // pma12 -> input_toggle16::Value1
		pma12.getWrappedObject().getParameter().connectT(1, input_toggle34);   // pma12 -> input_toggle34::Value1
		pma12.getWrappedObject().getParameter().connectT(2, input_toggle33);   // pma12 -> input_toggle33::Value1
		pma12.getWrappedObject().getParameter().connectT(3, input_toggle32);   // pma12 -> input_toggle32::Value1
		pma12.getWrappedObject().getParameter().connectT(4, sliderbank);       // pma12 -> sliderbank::Value
		peak6.getParameter().connectT(0, pma12);                               // peak6 -> pma12::Value
		global_cable96.getWrappedObject().getParameter().connectT(0, add90);   // global_cable96 -> add90::Value
		global_cable97.getWrappedObject().getParameter().connectT(0, add91);   // global_cable97 -> add91::Value
		global_cable98.getWrappedObject().getParameter().connectT(0, add92);   // global_cable98 -> add92::Value
		global_cable99.getWrappedObject().getParameter().connectT(0, add93);   // global_cable99 -> add93::Value
		global_cable100.getWrappedObject().getParameter().connectT(0, add94);  // global_cable100 -> add94::Value
		global_cable101.getWrappedObject().getParameter().connectT(0, add95);  // global_cable101 -> add95::Value
		global_cable102.getWrappedObject().getParameter().connectT(0, add96);  // global_cable102 -> add96::Value
		global_cable103.getWrappedObject().getParameter().connectT(0, add97);  // global_cable103 -> add97::Value
		global_cable104.getWrappedObject().getParameter().connectT(0, add98);  // global_cable104 -> add98::Value
		global_cable105.getWrappedObject().getParameter().connectT(0, add99);  // global_cable105 -> add99::Value
		global_cable106.getWrappedObject().getParameter().connectT(0, add100); // global_cable106 -> add100::Value
		global_cable107.getWrappedObject().getParameter().connectT(0, add101); // global_cable107 -> add101::Value
		global_cable108.getWrappedObject().getParameter().connectT(0, add102); // global_cable108 -> add102::Value
		global_cable109.getWrappedObject().getParameter().connectT(0, add103); // global_cable109 -> add103::Value
		global_cable110.getWrappedObject().getParameter().connectT(0, add104); // global_cable110 -> add104::Value
		global_cable111.getWrappedObject().getParameter().connectT(0, add105); // global_cable111 -> add105::Value
		input_toggle2.getWrappedObject().getParameter().connectT(0, faust);    // input_toggle2 -> faust::shiftsemitones
		minmax1.getWrappedObject().getParameter().connectT(0, input_toggle2);  // minmax1 -> input_toggle2::Value2
		input_toggle11.getWrappedObject().getParameter().connectT(0, faust1);  // input_toggle11 -> faust1::shiftsemitones
		minmax7.getWrappedObject().getParameter().connectT(0, input_toggle11); // minmax7 -> input_toggle11::Value2
		input_toggle10.getWrappedObject().getParameter().connectT(0, faust2);  // input_toggle10 -> faust2::shiftsemitones
		minmax6.getWrappedObject().getParameter().connectT(0, input_toggle10); // minmax6 -> input_toggle10::Value2
		input_toggle9.getWrappedObject().getParameter().connectT(0, faust3);   // input_toggle9 -> faust3::shiftsemitones
		minmax5.getWrappedObject().getParameter().connectT(0, input_toggle9);  // minmax5 -> input_toggle9::Value2
		auto& sliderbank1_p = sliderbank1.getWrappedObject().getParameter();
		sliderbank1_p.getParameterT(0).connectT(0, minmax1);                        // sliderbank1 -> minmax1::Value
		sliderbank1_p.getParameterT(1).connectT(0, minmax7);                        // sliderbank1 -> minmax7::Value
		sliderbank1_p.getParameterT(2).connectT(0, minmax6);                        // sliderbank1 -> minmax6::Value
		sliderbank1_p.getParameterT(3).connectT(0, minmax5);                        // sliderbank1 -> minmax5::Value
		pma.getWrappedObject().getParameter().connectT(0, sliderbank1);             // pma -> sliderbank1::Value
		pma_unscaled.getWrappedObject().getParameter().connectT(0, input_toggle2);  // pma_unscaled -> input_toggle2::Value1
		pma_unscaled.getWrappedObject().getParameter().connectT(1, input_toggle9);  // pma_unscaled -> input_toggle9::Value1
		pma_unscaled.getWrappedObject().getParameter().connectT(2, input_toggle10); // pma_unscaled -> input_toggle10::Value1
		pma_unscaled.getWrappedObject().getParameter().connectT(3, input_toggle11); // pma_unscaled -> input_toggle11::Value1
		minmax.getWrappedObject().getParameter().connectT(0, pma_unscaled);         // minmax -> pma_unscaled::Add
		pma4.getWrappedObject().getParameter().connectT(0, minmax);                 // pma4 -> minmax::Value
		peak8.getParameter().connectT(0, pma);                                      // peak8 -> pma::Value
		peak8.getParameter().connectT(1, pma4);                                     // peak8 -> pma4::Value
		global_cable80.getWrappedObject().getParameter().connectT(0, add74);        // global_cable80 -> add74::Value
		global_cable81.getWrappedObject().getParameter().connectT(0, add75);        // global_cable81 -> add75::Value
		global_cable82.getWrappedObject().getParameter().connectT(0, add76);        // global_cable82 -> add76::Value
		global_cable83.getWrappedObject().getParameter().connectT(0, add77);        // global_cable83 -> add77::Value
		global_cable84.getWrappedObject().getParameter().connectT(0, add78);        // global_cable84 -> add78::Value
		global_cable85.getWrappedObject().getParameter().connectT(0, add79);        // global_cable85 -> add79::Value
		global_cable86.getWrappedObject().getParameter().connectT(0, add80);        // global_cable86 -> add80::Value
		global_cable87.getWrappedObject().getParameter().connectT(0, add81);        // global_cable87 -> add81::Value
		global_cable88.getWrappedObject().getParameter().connectT(0, add82);        // global_cable88 -> add82::Value
		global_cable89.getWrappedObject().getParameter().connectT(0, add83);        // global_cable89 -> add83::Value
		global_cable90.getWrappedObject().getParameter().connectT(0, add84);        // global_cable90 -> add84::Value
		global_cable91.getWrappedObject().getParameter().connectT(0, add85);        // global_cable91 -> add85::Value
		global_cable92.getWrappedObject().getParameter().connectT(0, add86);        // global_cable92 -> add86::Value
		global_cable93.getWrappedObject().getParameter().connectT(0, add87);        // global_cable93 -> add87::Value
		global_cable94.getWrappedObject().getParameter().connectT(0, add88);        // global_cable94 -> add88::Value
		global_cable95.getWrappedObject().getParameter().connectT(0, add89);        // global_cable95 -> add89::Value
		pma13.getWrappedObject().getParameter().connectT(0, add);                   // pma13 -> add::Value
		pma21.getWrappedObject().getParameter().connectT(0, add1);                  // pma21 -> add1::Value
		peak7.getParameter().connectT(0, pma13);                                    // peak7 -> pma13::Value
		peak7.getParameter().connectT(1, pma21);                                    // peak7 -> pma21::Value
		minmax8.getWrappedObject().getParameter().connectT(0, granulator);          // minmax8 -> granulator::GrainSize
		tempo_sync2.getParameter().connectT(0, minmax8);                            // tempo_sync2 -> minmax8::Minimum
		minmax15.getWrappedObject().getParameter().connectT(0, granulator3);        // minmax15 -> granulator3::GrainSize
		tempo_sync12.getParameter().connectT(0, minmax15);                          // tempo_sync12 -> minmax15::Minimum
		minmax13.getWrappedObject().getParameter().connectT(0, granulator2);        // minmax13 -> granulator2::GrainSize
		tempo_sync11.getParameter().connectT(0, minmax13);                          // tempo_sync11 -> minmax13::Minimum
		minmax11.getWrappedObject().getParameter().connectT(0, granulator1);        // minmax11 -> granulator1::GrainSize
		tempo_sync10.getParameter().connectT(0, minmax11);                          // tempo_sync10 -> minmax11::Minimum
		minmax14.getWrappedObject().getParameter().connectT(0, tempo_sync12);       // minmax14 -> tempo_sync12::UnsyncedTime
		minmax12.getWrappedObject().getParameter().connectT(0, tempo_sync11);       // minmax12 -> tempo_sync11::UnsyncedTime
		minmax10.getWrappedObject().getParameter().connectT(0, tempo_sync10);       // minmax10 -> tempo_sync10::UnsyncedTime
		minmax9.getWrappedObject().getParameter().connectT(0, tempo_sync2);         // minmax9 -> tempo_sync2::UnsyncedTime
		peak.getParameter().connectT(0, tempo_sync2);                               // peak -> tempo_sync2::Tempo
		peak.getParameter().connectT(1, tempo_sync12);                              // peak -> tempo_sync12::Tempo
		peak.getParameter().connectT(2, tempo_sync11);                              // peak -> tempo_sync11::Tempo
		peak.getParameter().connectT(3, tempo_sync10);                              // peak -> tempo_sync10::Tempo
		peak.getParameter().connectT(4, minmax14);                                  // peak -> minmax14::Value
		peak.getParameter().connectT(5, minmax12);                                  // peak -> minmax12::Value
		peak.getParameter().connectT(6, minmax10);                                  // peak -> minmax10::Value
		peak.getParameter().connectT(7, minmax9);                                   // peak -> minmax9::Value
		global_cable112.getWrappedObject().getParameter().connectT(0, add106);      // global_cable112 -> add106::Value
		global_cable113.getWrappedObject().getParameter().connectT(0, add107);      // global_cable113 -> add107::Value
		global_cable114.getWrappedObject().getParameter().connectT(0, add108);      // global_cable114 -> add108::Value
		global_cable115.getWrappedObject().getParameter().connectT(0, add109);      // global_cable115 -> add109::Value
		global_cable116.getWrappedObject().getParameter().connectT(0, add110);      // global_cable116 -> add110::Value
		global_cable117.getWrappedObject().getParameter().connectT(0, add111);      // global_cable117 -> add111::Value
		global_cable118.getWrappedObject().getParameter().connectT(0, add112);      // global_cable118 -> add112::Value
		global_cable119.getWrappedObject().getParameter().connectT(0, add113);      // global_cable119 -> add113::Value
		global_cable120.getWrappedObject().getParameter().connectT(0, add114);      // global_cable120 -> add114::Value
		global_cable121.getWrappedObject().getParameter().connectT(0, add115);      // global_cable121 -> add115::Value
		global_cable122.getWrappedObject().getParameter().connectT(0, add116);      // global_cable122 -> add116::Value
		global_cable123.getWrappedObject().getParameter().connectT(0, add117);      // global_cable123 -> add117::Value
		global_cable124.getWrappedObject().getParameter().connectT(0, add118);      // global_cable124 -> add118::Value
		global_cable125.getWrappedObject().getParameter().connectT(0, add119);      // global_cable125 -> add119::Value
		global_cable126.getWrappedObject().getParameter().connectT(0, add120);      // global_cable126 -> add120::Value
		global_cable127.getWrappedObject().getParameter().connectT(0, add121);      // global_cable127 -> add121::Value
		pma15.getWrappedObject().getParameter().connectT(0, granulator);            // pma15 -> granulator::Density
		pma15.getWrappedObject().getParameter().connectT(1, granulator1);           // pma15 -> granulator1::Density
		pma15.getWrappedObject().getParameter().connectT(2, granulator2);           // pma15 -> granulator2::Density
		pma15.getWrappedObject().getParameter().connectT(3, granulator3);           // pma15 -> granulator3::Density
		peak9.getParameter().connectT(0, pma15);                                    // peak9 -> pma15::Value
		global_cable192.getWrappedObject().getParameter().connectT(0, add186);      // global_cable192 -> add186::Value
		global_cable193.getWrappedObject().getParameter().connectT(0, add187);      // global_cable193 -> add187::Value
		global_cable194.getWrappedObject().getParameter().connectT(0, add188);      // global_cable194 -> add188::Value
		global_cable195.getWrappedObject().getParameter().connectT(0, add189);      // global_cable195 -> add189::Value
		global_cable196.getWrappedObject().getParameter().connectT(0, add190);      // global_cable196 -> add190::Value
		global_cable197.getWrappedObject().getParameter().connectT(0, add191);      // global_cable197 -> add191::Value
		global_cable198.getWrappedObject().getParameter().connectT(0, add192);      // global_cable198 -> add192::Value
		global_cable199.getWrappedObject().getParameter().connectT(0, add193);      // global_cable199 -> add193::Value
		global_cable200.getWrappedObject().getParameter().connectT(0, add194);      // global_cable200 -> add194::Value
		global_cable201.getWrappedObject().getParameter().connectT(0, add195);      // global_cable201 -> add195::Value
		global_cable202.getWrappedObject().getParameter().connectT(0, add196);      // global_cable202 -> add196::Value
		global_cable203.getWrappedObject().getParameter().connectT(0, add197);      // global_cable203 -> add197::Value
		global_cable204.getWrappedObject().getParameter().connectT(0, add198);      // global_cable204 -> add198::Value
		global_cable205.getWrappedObject().getParameter().connectT(0, add199);      // global_cable205 -> add199::Value
		global_cable206.getWrappedObject().getParameter().connectT(0, add200);      // global_cable206 -> add200::Value
		global_cable207.getWrappedObject().getParameter().connectT(0, add201);      // global_cable207 -> add201::Value
		pma20.getWrappedObject().getParameter().connectT(0, granulator);            // pma20 -> granulator::Spread
		pma20.getWrappedObject().getParameter().connectT(1, granulator1);           // pma20 -> granulator1::Spread
		pma20.getWrappedObject().getParameter().connectT(2, granulator2);           // pma20 -> granulator2::Spread
		pma20.getWrappedObject().getParameter().connectT(3, granulator3);           // pma20 -> granulator3::Spread
		peak14.getParameter().connectT(0, pma20);                                   // peak14 -> pma20::Value
		global_cable176.getWrappedObject().getParameter().connectT(0, add170);      // global_cable176 -> add170::Value
		global_cable177.getWrappedObject().getParameter().connectT(0, add171);      // global_cable177 -> add171::Value
		global_cable178.getWrappedObject().getParameter().connectT(0, add172);      // global_cable178 -> add172::Value
		global_cable179.getWrappedObject().getParameter().connectT(0, add173);      // global_cable179 -> add173::Value
		global_cable180.getWrappedObject().getParameter().connectT(0, add174);      // global_cable180 -> add174::Value
		global_cable181.getWrappedObject().getParameter().connectT(0, add175);      // global_cable181 -> add175::Value
		global_cable182.getWrappedObject().getParameter().connectT(0, add176);      // global_cable182 -> add176::Value
		global_cable183.getWrappedObject().getParameter().connectT(0, add177);      // global_cable183 -> add177::Value
		global_cable184.getWrappedObject().getParameter().connectT(0, add178);      // global_cable184 -> add178::Value
		global_cable185.getWrappedObject().getParameter().connectT(0, add179);      // global_cable185 -> add179::Value
		global_cable186.getWrappedObject().getParameter().connectT(0, add180);      // global_cable186 -> add180::Value
		global_cable187.getWrappedObject().getParameter().connectT(0, add181);      // global_cable187 -> add181::Value
		global_cable188.getWrappedObject().getParameter().connectT(0, add182);      // global_cable188 -> add182::Value
		global_cable189.getWrappedObject().getParameter().connectT(0, add183);      // global_cable189 -> add183::Value
		global_cable190.getWrappedObject().getParameter().connectT(0, add184);      // global_cable190 -> add184::Value
		global_cable191.getWrappedObject().getParameter().connectT(0, add185);      // global_cable191 -> add185::Value
		pma19.getWrappedObject().getParameter().connectT(0, granulator);            // pma19 -> granulator::Detune
		pma19.getWrappedObject().getParameter().connectT(1, granulator3);           // pma19 -> granulator3::Detune
		pma19.getWrappedObject().getParameter().connectT(2, granulator2);           // pma19 -> granulator2::Detune
		pma19.getWrappedObject().getParameter().connectT(3, granulator1);           // pma19 -> granulator1::Detune
		peak13.getParameter().connectT(0, pma19);                                   // peak13 -> pma19::Value
		global_cable208.getWrappedObject().getParameter().connectT(0, add202);      // global_cable208 -> add202::Value
		global_cable209.getWrappedObject().getParameter().connectT(0, add203);      // global_cable209 -> add203::Value
		global_cable210.getWrappedObject().getParameter().connectT(0, add204);      // global_cable210 -> add204::Value
		global_cable211.getWrappedObject().getParameter().connectT(0, add205);      // global_cable211 -> add205::Value
		global_cable213.getWrappedObject().getParameter().connectT(0, add207);      // global_cable213 -> add207::Value
		global_cable214.getWrappedObject().getParameter().connectT(0, add208);      // global_cable214 -> add208::Value
		global_cable215.getWrappedObject().getParameter().connectT(0, add209);      // global_cable215 -> add209::Value
		global_cable216.getWrappedObject().getParameter().connectT(0, add210);      // global_cable216 -> add210::Value
		global_cable217.getWrappedObject().getParameter().connectT(0, add211);      // global_cable217 -> add211::Value
		global_cable218.getWrappedObject().getParameter().connectT(0, add212);      // global_cable218 -> add212::Value
		global_cable219.getWrappedObject().getParameter().connectT(0, add213);      // global_cable219 -> add213::Value
		global_cable220.getWrappedObject().getParameter().connectT(0, add214);      // global_cable220 -> add214::Value
		global_cable221.getWrappedObject().getParameter().connectT(0, add215);      // global_cable221 -> add215::Value
		global_cable222.getWrappedObject().getParameter().connectT(0, add216);      // global_cable222 -> add216::Value
		global_cable223.getWrappedObject().getParameter().connectT(0, add217);      // global_cable223 -> add217::Value
		tempo_sync.getParameter().connectT(0, faust);                               // tempo_sync -> faust::windowsamples
		tempo_sync3.getParameter().connectT(0, faust1);                             // tempo_sync3 -> faust1::windowsamples
		tempo_sync5.getParameter().connectT(0, faust2);                             // tempo_sync5 -> faust2::windowsamples
		tempo_sync7.getParameter().connectT(0, faust3);                             // tempo_sync7 -> faust3::windowsamples
		tempo_sync7.getParameter().connectT(1, faust3);                             // tempo_sync7 -> faust3::xfadesamples
		pma22.getWrappedObject().getParameter().connectT(0, add2);                  // pma22 -> add2::Value
		pma22.getWrappedObject().getParameter().connectT(1, tempo_sync);            // pma22 -> tempo_sync::UnsyncedTime
		pma22.getWrappedObject().getParameter().connectT(2, tempo_sync3);           // pma22 -> tempo_sync3::UnsyncedTime
		pma22.getWrappedObject().getParameter().connectT(3, tempo_sync5);           // pma22 -> tempo_sync5::UnsyncedTime
		pma22.getWrappedObject().getParameter().connectT(4, tempo_sync7);           // pma22 -> tempo_sync7::UnsyncedTime
		pma23.getWrappedObject().getParameter().connectT(0, add3);                  // pma23 -> add3::Value
		pma23.getWrappedObject().getParameter().connectT(1, tempo_sync7);           // pma23 -> tempo_sync7::Tempo
		pma23.getWrappedObject().getParameter().connectT(2, tempo_sync5);           // pma23 -> tempo_sync5::Tempo
		pma23.getWrappedObject().getParameter().connectT(3, tempo_sync3);           // pma23 -> tempo_sync3::Tempo
		pma23.getWrappedObject().getParameter().connectT(4, tempo_sync);            // pma23 -> tempo_sync::Tempo
		peak15.getParameter().connectT(0, pma22);                                   // peak15 -> pma22::Value
		peak15.getParameter().connectT(1, pma23);                                   // peak15 -> pma23::Value
		global_cable272.getWrappedObject().getParameter().connectT(0, add266);      // global_cable272 -> add266::Value
		global_cable273.getWrappedObject().getParameter().connectT(0, add267);      // global_cable273 -> add267::Value
		global_cable274.getWrappedObject().getParameter().connectT(0, add268);      // global_cable274 -> add268::Value
		global_cable275.getWrappedObject().getParameter().connectT(0, add269);      // global_cable275 -> add269::Value
		global_cable276.getWrappedObject().getParameter().connectT(0, add270);      // global_cable276 -> add270::Value
		global_cable277.getWrappedObject().getParameter().connectT(0, add271);      // global_cable277 -> add271::Value
		global_cable278.getWrappedObject().getParameter().connectT(0, add272);      // global_cable278 -> add272::Value
		global_cable279.getWrappedObject().getParameter().connectT(0, add273);      // global_cable279 -> add273::Value
		global_cable280.getWrappedObject().getParameter().connectT(0, add274);      // global_cable280 -> add274::Value
		global_cable281.getWrappedObject().getParameter().connectT(0, add275);      // global_cable281 -> add275::Value
		global_cable282.getWrappedObject().getParameter().connectT(0, add276);      // global_cable282 -> add276::Value
		global_cable283.getWrappedObject().getParameter().connectT(0, add277);      // global_cable283 -> add277::Value
		global_cable284.getWrappedObject().getParameter().connectT(0, add278);      // global_cable284 -> add278::Value
		global_cable285.getWrappedObject().getParameter().connectT(0, add279);      // global_cable285 -> add279::Value
		global_cable286.getWrappedObject().getParameter().connectT(0, add280);      // global_cable286 -> add280::Value
		global_cable287.getWrappedObject().getParameter().connectT(0, add281);      // global_cable287 -> add281::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, add10); // xfader -> add10::Value
		xfader_p.getParameterT(1).connectT(0, add13); // xfader -> add13::Value
		xfader_p.getParameterT(2).connectT(0, add16); // xfader -> add16::Value
		xfader_p.getParameterT(3).connectT(0, add7);  // xfader -> add7::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, add11); // xfader1 -> add11::Value
		xfader1_p.getParameterT(1).connectT(0, add14); // xfader1 -> add14::Value
		xfader1_p.getParameterT(2).connectT(0, add17); // xfader1 -> add17::Value
		xfader1_p.getParameterT(3).connectT(0, add8);  // xfader1 -> add8::Value
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(0).connectT(0, add18);                // xfader2 -> add18::Value
		xfader2_p.getParameterT(1).connectT(0, add19);                // xfader2 -> add19::Value
		xfader2_p.getParameterT(2).connectT(0, add20);                // xfader2 -> add20::Value
		xfader2_p.getParameterT(3).connectT(0, add21);                // xfader2 -> add21::Value
		pma28.getWrappedObject().getParameter().connectT(0, xfader);  // pma28 -> xfader::Value
		pma28.getWrappedObject().getParameter().connectT(1, xfader1); // pma28 -> xfader1::Value
		pma28.getWrappedObject().getParameter().connectT(2, xfader2); // pma28 -> xfader2::Value
		peak19.getParameter().connectT(0, pma28);                     // peak19 -> pma28::Value
		event_data_reader1.getParameter().connectT(0, minmax8);       // event_data_reader1 -> minmax8::Maximum
		event_data_reader1.getParameter().connectT(1, minmax9);       // event_data_reader1 -> minmax9::Maximum
		tempo_sync1.getParameter().connectT(0, faust);                // tempo_sync1 -> faust::xfadesamples
		peak4.getParameter().connectT(0, gain1);                      // peak4 -> gain1::Gain
		event_data_reader2.getParameter().connectT(0, minmax11);      // event_data_reader2 -> minmax11::Maximum
		event_data_reader2.getParameter().connectT(1, minmax10);      // event_data_reader2 -> minmax10::Maximum
		tempo_sync8.getParameter().connectT(0, faust1);               // tempo_sync8 -> faust1::xfadesamples
		peak5.getParameter().connectT(0, gain2);                      // peak5 -> gain2::Gain
		event_data_reader3.getParameter().connectT(0, minmax13);      // event_data_reader3 -> minmax13::Maximum
		event_data_reader3.getParameter().connectT(1, minmax12);      // event_data_reader3 -> minmax12::Maximum
		tempo_sync6.getParameter().connectT(0, faust2);               // tempo_sync6 -> faust2::xfadesamples
		peak10.getParameter().connectT(0, gain3);                     // peak10 -> gain3::Gain
		event_data_reader4.getParameter().connectT(0, minmax15);      // event_data_reader4 -> minmax15::Maximum
		event_data_reader4.getParameter().connectT(1, minmax14);      // event_data_reader4 -> minmax14::Maximum
		peak3.getParameter().connectT(0, gain4);                      // peak3 -> gain4::Gain
		
		// Default Values --------------------------------------------------------------------------
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // chain80::ModSrc is automated
		
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
		
		global_cable72.setParameterT(0, 1.); // routing::global_cable::Value
		
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
		
		; // add71::Value is automated
		
		global_cable78.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add72::Value is automated
		
		global_cable79.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add73::Value is automated
		
		; // pma12::Value is automated
		; // pma12::Multiply is automated
		; // pma12::Add is automated
		
		; // sliderbank::Value is automated
		
		clear8.setParameterT(0, 0.); // math::clear::Value
		
		; // chain114::ModSrc is automated
		
		clear11.setParameterT(0, 0.); // math::clear::Value
		
		; // branch6::Index is automated
		
		global_cable96.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add90::Value is automated
		
		global_cable97.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add91::Value is automated
		
		global_cable98.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add92::Value is automated
		
		global_cable99.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add93::Value is automated
		
		global_cable100.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add94::Value is automated
		
		global_cable101.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add95::Value is automated
		
		global_cable102.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add96::Value is automated
		
		global_cable103.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add97::Value is automated
		
		global_cable104.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add98::Value is automated
		
		global_cable105.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add99::Value is automated
		
		global_cable106.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add100::Value is automated
		
		global_cable107.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add101::Value is automated
		
		global_cable108.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add102::Value is automated
		
		global_cable109.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add103::Value is automated
		
		global_cable110.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add104::Value is automated
		
		global_cable111.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add105::Value is automated
		
		; // pma4::Value is automated
		; // pma4::Multiply is automated
		; // pma4::Add is automated
		
		;                              // minmax::Value is automated
		minmax.setParameterT(1, -24.); // control::minmax::Minimum
		minmax.setParameterT(2, 24.);  // control::minmax::Maximum
		minmax.setParameterT(3, 1.);   // control::minmax::Skew
		;                              // minmax::Step is automated
		minmax.setParameterT(5, 0.);   // control::minmax::Polarity
		
		pma_unscaled.setParameterT(0, 14.4164); // control::pma_unscaled::Value
		pma_unscaled.setParameterT(1, 0.);      // control::pma_unscaled::Multiply
		;                                       // pma_unscaled::Add is automated
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // sliderbank1::Value is automated
		
		;                               // minmax1::Value is automated
		minmax1.setParameterT(1, -36.); // control::minmax::Minimum
		minmax1.setParameterT(2, 36.);  // control::minmax::Maximum
		minmax1.setParameterT(3, 1.);   // control::minmax::Skew
		;                               // minmax1::Step is automated
		minmax1.setParameterT(5, 0.);   // control::minmax::Polarity
		
		;                               // minmax7::Value is automated
		minmax7.setParameterT(1, -24.); // control::minmax::Minimum
		minmax7.setParameterT(2, 24.);  // control::minmax::Maximum
		minmax7.setParameterT(3, 1.);   // control::minmax::Skew
		;                               // minmax7::Step is automated
		minmax7.setParameterT(5, 0.);   // control::minmax::Polarity
		
		;                               // minmax6::Value is automated
		minmax6.setParameterT(1, -36.); // control::minmax::Minimum
		minmax6.setParameterT(2, 36.);  // control::minmax::Maximum
		minmax6.setParameterT(3, 1.);   // control::minmax::Skew
		;                               // minmax6::Step is automated
		minmax6.setParameterT(5, 0.);   // control::minmax::Polarity
		
		;                               // minmax5::Value is automated
		minmax5.setParameterT(1, -36.); // control::minmax::Minimum
		minmax5.setParameterT(2, 36.);  // control::minmax::Maximum
		minmax5.setParameterT(3, 1.);   // control::minmax::Skew
		;                               // minmax5::Step is automated
		minmax5.setParameterT(5, 0.);   // control::minmax::Polarity
		
		clear12.setParameterT(0, 0.); // math::clear::Value
		
		; // chain97::ModSrc is automated
		
		clear9.setParameterT(0, 0.); // math::clear::Value
		
		; // branch5::Index is automated
		
		global_cable80.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add74::Value is automated
		
		global_cable81.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add75::Value is automated
		
		global_cable82.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add76::Value is automated
		
		global_cable83.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add77::Value is automated
		
		global_cable84.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add78::Value is automated
		
		global_cable85.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add79::Value is automated
		
		global_cable86.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add80::Value is automated
		
		global_cable87.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add81::Value is automated
		
		global_cable88.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add82::Value is automated
		
		global_cable89.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add83::Value is automated
		
		global_cable90.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add84::Value is automated
		
		global_cable91.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add85::Value is automated
		
		global_cable92.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add86::Value is automated
		
		global_cable93.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add87::Value is automated
		
		global_cable94.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add88::Value is automated
		
		global_cable95.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add89::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // branch2::Index is automated
		
		; // pma13::Value is automated
		; // pma13::Multiply is automated
		; // pma13::Add is automated
		
		; // add::Value is automated
		
		; // pma21::Value is automated
		; // pma21::Multiply is automated
		; // pma21::Add is automated
		
		; // add1::Value is automated
		
		clear10.setParameterT(0, 0.); // math::clear::Value
		
		; // chain131::ModSrc is automated
		
		clear13.setParameterT(0, 0.); // math::clear::Value
		
		; // branch7::Index is automated
		
		global_cable112.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add106::Value is automated
		
		global_cable113.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add107::Value is automated
		
		global_cable114.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add108::Value is automated
		
		global_cable115.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add109::Value is automated
		
		global_cable116.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add110::Value is automated
		
		global_cable117.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add111::Value is automated
		
		global_cable118.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add112::Value is automated
		
		global_cable119.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add113::Value is automated
		
		global_cable120.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add114::Value is automated
		
		global_cable121.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add115::Value is automated
		
		global_cable122.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add116::Value is automated
		
		global_cable123.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add117::Value is automated
		
		global_cable124.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add118::Value is automated
		
		global_cable125.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add119::Value is automated
		
		global_cable126.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add120::Value is automated
		
		global_cable127.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add121::Value is automated
		
		; // pma15::Value is automated
		; // pma15::Multiply is automated
		; // pma15::Add is automated
		
		clear14.setParameterT(0, 0.); // math::clear::Value
		
		; // chain216::ModSrc is automated
		
		clear23.setParameterT(0, 0.); // math::clear::Value
		
		; // branch12::Index is automated
		
		global_cable192.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add186::Value is automated
		
		global_cable193.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add187::Value is automated
		
		global_cable194.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add188::Value is automated
		
		global_cable195.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add189::Value is automated
		
		global_cable196.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add190::Value is automated
		
		global_cable197.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add191::Value is automated
		
		global_cable198.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add192::Value is automated
		
		global_cable199.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add193::Value is automated
		
		global_cable200.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add194::Value is automated
		
		global_cable201.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add195::Value is automated
		
		global_cable202.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add196::Value is automated
		
		global_cable203.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add197::Value is automated
		
		global_cable204.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add198::Value is automated
		
		global_cable205.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add199::Value is automated
		
		global_cable206.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add200::Value is automated
		
		global_cable207.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add201::Value is automated
		
		; // pma20::Value is automated
		; // pma20::Multiply is automated
		; // pma20::Add is automated
		
		clear24.setParameterT(0, 0.); // math::clear::Value
		
		; // chain199::ModSrc is automated
		
		clear21.setParameterT(0, 0.); // math::clear::Value
		
		; // branch11::Index is automated
		
		global_cable176.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add170::Value is automated
		
		global_cable177.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add171::Value is automated
		
		global_cable178.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add172::Value is automated
		
		global_cable179.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add173::Value is automated
		
		global_cable180.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add174::Value is automated
		
		global_cable181.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add175::Value is automated
		
		global_cable182.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add176::Value is automated
		
		global_cable183.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add177::Value is automated
		
		global_cable184.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add178::Value is automated
		
		global_cable185.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add179::Value is automated
		
		global_cable186.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add180::Value is automated
		
		global_cable187.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add181::Value is automated
		
		global_cable188.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add182::Value is automated
		
		global_cable189.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add183::Value is automated
		
		global_cable190.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add184::Value is automated
		
		global_cable191.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add185::Value is automated
		
		; // pma19::Value is automated
		; // pma19::Multiply is automated
		; // pma19::Add is automated
		
		clear22.setParameterT(0, 0.); // math::clear::Value
		
		; // chain233::ModSrc is automated
		
		clear25.setParameterT(0, 0.); // math::clear::Value
		
		; // branch13::Index is automated
		
		global_cable208.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add202::Value is automated
		
		global_cable209.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add203::Value is automated
		
		global_cable210.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add204::Value is automated
		
		global_cable211.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add205::Value is automated
		
		global_cable212.setParameterT(0, 1.); // routing::global_cable::Value
		
		add206.setParameterT(0, 0.); // math::add::Value
		
		global_cable213.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add207::Value is automated
		
		global_cable214.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add208::Value is automated
		
		global_cable215.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add209::Value is automated
		
		global_cable216.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add210::Value is automated
		
		global_cable217.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add211::Value is automated
		
		global_cable218.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add212::Value is automated
		
		global_cable219.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add213::Value is automated
		
		global_cable220.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add214::Value is automated
		
		global_cable221.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add215::Value is automated
		
		global_cable222.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add216::Value is automated
		
		global_cable223.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add217::Value is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // branch14::Index is automated
		
		; // pma22::Value is automated
		; // pma22::Multiply is automated
		; // pma22::Add is automated
		
		; // add2::Value is automated
		
		; // pma23::Value is automated
		; // pma23::Multiply is automated
		; // pma23::Add is automated
		
		; // add3::Value is automated
		
		clear26.setParameterT(0, 0.); // math::clear::Value
		
		; // chain301::ModSrc is automated
		
		clear33.setParameterT(0, 0.); // math::clear::Value
		
		; // branch19::Index is automated
		
		global_cable272.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add266::Value is automated
		
		global_cable273.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add267::Value is automated
		
		global_cable274.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add268::Value is automated
		
		global_cable275.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add269::Value is automated
		
		global_cable276.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add270::Value is automated
		
		global_cable277.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add271::Value is automated
		
		global_cable278.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add272::Value is automated
		
		global_cable279.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add273::Value is automated
		
		global_cable280.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add274::Value is automated
		
		global_cable281.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add275::Value is automated
		
		global_cable282.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add276::Value is automated
		
		global_cable283.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add277::Value is automated
		
		global_cable284.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add278::Value is automated
		
		global_cable285.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add279::Value is automated
		
		global_cable286.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add280::Value is automated
		
		global_cable287.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add281::Value is automated
		
		; // pma28::Value is automated
		; // pma28::Multiply is automated
		; // pma28::Add is automated
		
		clear34.setParameterT(0, 0.); // math::clear::Value
		
		pack_resizer1.setParameterT(0, 4.); // control::pack_resizer::NumSliders
		
		; // xfader::Value is automated
		
		; // xfader1::Value is automated
		
		; // xfader2::Value is automated
		
		; // input_toggle16::Input is automated
		; // input_toggle16::Value1 is automated
		; // input_toggle16::Value2 is automated
		
		; // input_toggle2::Input is automated
		; // input_toggle2::Value1 is automated
		; // input_toggle2::Value2 is automated
		
		;                                // oversample::Oversampling is automated
		oversample.setParameterT(1, 0.); // container::chain::FilterType
		
		;                                        // event_data_reader1::SlotIndex is automated
		event_data_reader1.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		;                                   // minmax9::Value is automated
		minmax9.setParameterT(1, 0.);       // control::minmax::Minimum
		;                                   // minmax9::Maximum is automated
		minmax9.setParameterT(3, 0.167797); // control::minmax::Skew
		minmax9.setParameterT(4, 0.);       // control::minmax::Step
		minmax9.setParameterT(5, 0.);       // control::minmax::Polarity
		
		; // tempo_sync2::Tempo is automated
		; // tempo_sync2::Multiplier is automated
		; // tempo_sync2::Enabled is automated
		; // tempo_sync2::UnsyncedTime is automated
		
		minmax8.setParameterT(0, 0.);  // control::minmax::Value
		;                              // minmax8::Minimum is automated
		;                              // minmax8::Maximum is automated
		minmax8.setParameterT(3, 0.2); // control::minmax::Skew
		minmax8.setParameterT(4, 0.);  // control::minmax::Step
		minmax8.setParameterT(5, 0.);  // control::minmax::Polarity
		
		;                                // granulator::Position is automated
		granulator.setParameterT(1, 1.); // core::granulator::Pitch
		;                                // granulator::GrainSize is automated
		;                                // granulator::Density is automated
		;                                // granulator::Spread is automated
		;                                // granulator::Detune is automated
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		; // tempo_sync1::Tempo is automated
		; // tempo_sync1::Multiplier is automated
		; // tempo_sync1::Enabled is automated
		; // tempo_sync1::UnsyncedTime is automated
		
		; // faust::shiftsemitones is automated
		; // faust::windowsamples is automated
		; // faust::xfadesamples is automated
		
		clear16.setParameterT(0, 0.); // math::clear::Value
		
		; // branch1::Index is automated
		
		add9.setParameterT(0, 1.); // math::add::Value
		
		; // add10::Value is automated
		
		; // add11::Value is automated
		
		; // add18::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table16::Value is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch3::Index is automated
		
		; // input_toggle34::Input is automated
		; // input_toggle34::Value1 is automated
		; // input_toggle34::Value2 is automated
		
		; // input_toggle11::Input is automated
		; // input_toggle11::Value1 is automated
		; // input_toggle11::Value2 is automated
		
		;                                 // oversample1::Oversampling is automated
		oversample1.setParameterT(1, 0.); // container::chain::FilterType
		
		;                                        // event_data_reader2::SlotIndex is automated
		event_data_reader2.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		;                                    // minmax10::Value is automated
		minmax10.setParameterT(1, 0.);       // control::minmax::Minimum
		;                                    // minmax10::Maximum is automated
		minmax10.setParameterT(3, 0.215226); // control::minmax::Skew
		minmax10.setParameterT(4, 0.);       // control::minmax::Step
		minmax10.setParameterT(5, 0.);       // control::minmax::Polarity
		
		; // tempo_sync10::Tempo is automated
		; // tempo_sync10::Multiplier is automated
		; // tempo_sync10::Enabled is automated
		; // tempo_sync10::UnsyncedTime is automated
		
		minmax11.setParameterT(0, 0.);       // control::minmax::Value
		;                                    // minmax11::Minimum is automated
		;                                    // minmax11::Maximum is automated
		minmax11.setParameterT(3, 0.167797); // control::minmax::Skew
		minmax11.setParameterT(4, 0.);       // control::minmax::Step
		minmax11.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                                 // granulator1::Position is automated
		granulator1.setParameterT(1, 1.); // core::granulator::Pitch
		;                                 // granulator1::GrainSize is automated
		;                                 // granulator1::Density is automated
		;                                 // granulator1::Spread is automated
		;                                 // granulator1::Detune is automated
		
		; // tempo_sync3::Tempo is automated
		; // tempo_sync3::Multiplier is automated
		; // tempo_sync3::Enabled is automated
		; // tempo_sync3::UnsyncedTime is automated
		
		; // tempo_sync8::Tempo is automated
		; // tempo_sync8::Multiplier is automated
		; // tempo_sync8::Enabled is automated
		; // tempo_sync8::UnsyncedTime is automated
		
		; // faust1::shiftsemitones is automated
		; // faust1::windowsamples is automated
		; // faust1::xfadesamples is automated
		
		clear15.setParameterT(0, 0.); // math::clear::Value
		
		; // branch8::Index is automated
		
		add12.setParameterT(0, 1.); // math::add::Value
		
		; // add13::Value is automated
		
		; // add14::Value is automated
		
		; // add19::Value is automated
		
		; // cable_table34::Value is automated
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		;                            // gain2::Gain is automated
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // input_toggle33::Input is automated
		; // input_toggle33::Value1 is automated
		; // input_toggle33::Value2 is automated
		
		; // input_toggle10::Input is automated
		; // input_toggle10::Value1 is automated
		; // input_toggle10::Value2 is automated
		
		;                                 // oversample3::Oversampling is automated
		oversample3.setParameterT(1, 0.); // container::chain::FilterType
		
		event_data_reader3.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader3.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		;                                    // minmax12::Value is automated
		minmax12.setParameterT(1, 0.);       // control::minmax::Minimum
		;                                    // minmax12::Maximum is automated
		minmax12.setParameterT(3, 0.167797); // control::minmax::Skew
		minmax12.setParameterT(4, 0.);       // control::minmax::Step
		minmax12.setParameterT(5, 0.);       // control::minmax::Polarity
		
		; // tempo_sync11::Tempo is automated
		; // tempo_sync11::Multiplier is automated
		; // tempo_sync11::Enabled is automated
		; // tempo_sync11::UnsyncedTime is automated
		
		minmax13.setParameterT(0, 0.);       // control::minmax::Value
		;                                    // minmax13::Minimum is automated
		;                                    // minmax13::Maximum is automated
		minmax13.setParameterT(3, 0.167797); // control::minmax::Skew
		minmax13.setParameterT(4, 0.);       // control::minmax::Step
		minmax13.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                                 // granulator2::Position is automated
		granulator2.setParameterT(1, 1.); // core::granulator::Pitch
		;                                 // granulator2::GrainSize is automated
		;                                 // granulator2::Density is automated
		;                                 // granulator2::Spread is automated
		;                                 // granulator2::Detune is automated
		
		; // tempo_sync5::Tempo is automated
		; // tempo_sync5::Multiplier is automated
		; // tempo_sync5::Enabled is automated
		; // tempo_sync5::UnsyncedTime is automated
		
		; // tempo_sync6::Tempo is automated
		; // tempo_sync6::Multiplier is automated
		; // tempo_sync6::Enabled is automated
		; // tempo_sync6::UnsyncedTime is automated
		
		; // faust2::shiftsemitones is automated
		; // faust2::windowsamples is automated
		; // faust2::xfadesamples is automated
		
		clear18.setParameterT(0, 0.); // math::clear::Value
		
		; // branch17::Index is automated
		
		add15.setParameterT(0, 1.); // math::add::Value
		
		; // add16::Value is automated
		
		; // add17::Value is automated
		
		; // add20::Value is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table33::Value is automated
		
		;                            // gain3::Gain is automated
		gain3.setParameterT(1, 20.); // core::gain::Smoothing
		gain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // input_toggle32::Input is automated
		; // input_toggle32::Value1 is automated
		; // input_toggle32::Value2 is automated
		
		; // input_toggle9::Input is automated
		; // input_toggle9::Value1 is automated
		; // input_toggle9::Value2 is automated
		
		;                                 // oversample2::Oversampling is automated
		oversample2.setParameterT(1, 0.); // container::chain::FilterType
		
		;                                        // event_data_reader4::SlotIndex is automated
		event_data_reader4.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		;                                    // minmax14::Value is automated
		minmax14.setParameterT(1, 0.);       // control::minmax::Minimum
		;                                    // minmax14::Maximum is automated
		minmax14.setParameterT(3, 0.167797); // control::minmax::Skew
		minmax14.setParameterT(4, 0.);       // control::minmax::Step
		minmax14.setParameterT(5, 0.);       // control::minmax::Polarity
		
		; // tempo_sync12::Tempo is automated
		; // tempo_sync12::Multiplier is automated
		; // tempo_sync12::Enabled is automated
		; // tempo_sync12::UnsyncedTime is automated
		
		minmax15.setParameterT(0, 0.);       // control::minmax::Value
		;                                    // minmax15::Minimum is automated
		;                                    // minmax15::Maximum is automated
		minmax15.setParameterT(3, 0.167797); // control::minmax::Skew
		minmax15.setParameterT(4, 0.);       // control::minmax::Step
		minmax15.setParameterT(5, 0.);       // control::minmax::Polarity
		
		;                                 // granulator3::Position is automated
		granulator3.setParameterT(1, 1.); // core::granulator::Pitch
		;                                 // granulator3::GrainSize is automated
		;                                 // granulator3::Density is automated
		;                                 // granulator3::Spread is automated
		;                                 // granulator3::Detune is automated
		
		; // tempo_sync7::Tempo is automated
		; // tempo_sync7::Multiplier is automated
		; // tempo_sync7::Enabled is automated
		; // tempo_sync7::UnsyncedTime is automated
		
		; // tempo_sync4::Tempo is automated
		; // tempo_sync4::Multiplier is automated
		; // tempo_sync4::Enabled is automated
		; // tempo_sync4::UnsyncedTime is automated
		
		; // faust3::shiftsemitones is automated
		; // faust3::windowsamples is automated
		; // faust3::xfadesamples is automated
		
		; // cable_table32::Value is automated
		
		clear17.setParameterT(0, 0.); // math::clear::Value
		
		; // branch::Index is automated
		
		add6.setParameterT(0, 1.); // math::add::Value
		
		; // add7::Value is automated
		
		; // add8::Value is automated
		
		; // add21::Value is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		;                            // gain4::Gain is automated
		gain4.setParameterT(1, 20.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		gain.setParameterT(0, 0.);  // core::gain::Gain
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 6.66134e-16);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 4.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 2.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 10.);
		this->setParameterT(12, 10.);
		this->setParameterT(13, 0.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 0.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 0.);
		this->setParameterT(18, 0.);
		this->setParameterT(19, 1.);
		this->setParameterT(20, 0.);
		this->setParameterT(21, 0.);
		this->setParameterT(22, 1.);
		this->setParameterT(23, 6031.59);
		this->setParameterT(24, 10.);
		this->setParameterT(25, 16.);
		this->setParameterT(26, 0.);
		this->setParameterT(27, 0.);
		this->setParameterT(28, 4.);
		this->setParameterT(29, 14.);
		this->setParameterT(30, 0.);
		this->setParameterT(31, -34.);
		this->setParameterT(32, 20.);
		this->setParameterT(33, 0.);
		this->setParameterT(34, 0.);
		this->setParameterT(35, 1.);
		this->setParameterT(36, 0.);
		this->setParameterT(37, 0.84);
		this->setParameterT(38, 4.);
		this->setParameterT(39, 0.5);
		this->setParameterT(40, -1.);
		this->setParameterT(41, 10.);
		this->setParameterT(42, 1000.);
		this->setParameterT(43, 1.);
		this->setParameterT(44, 0.);
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
		
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable64_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable65_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable66_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable67_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable68_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable69_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable70_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable71_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable72_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable73_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable74_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable75_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable76_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable77_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable78_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable79_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable96_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable97_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable98_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable99_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable100_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable101_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable102_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable103_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable104_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable105_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable106_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable107_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable108_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable109_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable110_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable111_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable80_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable81_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable82_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable83_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable84_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable85_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable86_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable87_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable88_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable89_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable90_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable91_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable92_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable93_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable94_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable95_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable112_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable113_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable114_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable115_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable116_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable117_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable118_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable119_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable120_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable121_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable122_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable123_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable124_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable125_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable126_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable127_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable192_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable193_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable194_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable195_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable196_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable197_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable198_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable199_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable200_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable201_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable202_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable203_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable204_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable205_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable206_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable207_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable176_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable177_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable178_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable179_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable180_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable181_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable182_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable183_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable184_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable185_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable186_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable187_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable188_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable189_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable190_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable191_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable208_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable209_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable210_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable211_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // routing::global_cable<global_cable212_t_index, parameter::empty>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable213_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable214_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable215_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable216_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable217_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable218_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable219_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable220_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable221_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable222_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable223_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable272_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable273_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable274_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable275_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable276_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable277_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable278_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable279_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable280_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // Stack_impl::global_cable281_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable282_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable283_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable284_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable285_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable286_t<NV>
		this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // Stack_impl::global_cable287_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(0).getT(2).setExternalData(b, index);                 // Stack_impl::peak6_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(4).setExternalData(b, index);                 // Stack_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(2).setExternalData(b, index);                 // Stack_impl::peak8_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(7).setExternalData(b, index);                 // Stack_impl::sliderbank1_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(2).setExternalData(b, index);                 // Stack_impl::peak7_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(3).getT(2).setExternalData(b, index);         // Stack_impl::peak_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(2).setExternalData(b, index);                 // Stack_impl::peak9_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).getT(2).setExternalData(b, index);                 // Stack_impl::peak14_t<NV>
		this->getT(0).getT(0).getT(1).getT(5).getT(2).setExternalData(b, index);                 // Stack_impl::peak13_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(2).setExternalData(b, index);                 // Stack_impl::peak15_t<NV>
		this->getT(0).getT(0).getT(1).getT(6).getT(3).getT(2).setExternalData(b, index);         // Stack_impl::peak1_t
		this->getT(0).getT(0).getT(1).getT(7).getT(2).setExternalData(b, index);                 // Stack_impl::peak19_t<NV>
		this->getT(0).getT(0).getT(2).setExternalData(b, index);                                 // Stack_impl::pack_resizer1_t
		this->getT(0).getT(2).getT(0).getT(2).getT(1).setExternalData(b, index);                 // Stack_impl::granulator_t
		this->getT(0).getT(2).getT(0).getT(3).getT(1).getT(1).getT(2).setExternalData(b, index); // Stack_impl::peak4_t<NV>
		this->getT(0).getT(2).getT(0).getT(4).setExternalData(b, index);                         // Stack_impl::cable_table16_t
		this->getT(0).getT(2).getT(1).getT(1).                                                   // Stack_impl::granulator1_t
        getT(0).getT(0).getT(2).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(2).getT(1).getT(1).getT(0).                                           // Stack_impl::peak5_t<NV>
        getT(0).getT(3).getT(1).getT(2).getT(0).setExternalData(b, index);
		this->getT(0).getT(2).getT(1).getT(1).                                                   // Stack_impl::cable_table34_t
        getT(0).getT(0).getT(3).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(0).getT(2).getT(1).getT(1).                                                   // Stack_impl::granulator2_t
        getT(0).getT(1).getT(2).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(2).getT(1).getT(1).getT(0).                                           // Stack_impl::peak10_t<NV>
        getT(1).getT(3).getT(1).getT(0).getT(2).setExternalData(b, index);
		this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(1).getT(4).setExternalData(b, index); // Stack_impl::cable_table33_t
		this->getT(0).getT(2).getT(1).getT(1).                                                   // Stack_impl::granulator3_t
        getT(0).getT(2).getT(2).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(2).getT(1).getT(1).getT(0).getT(2).getT(3).setExternalData(b, index); // Stack_impl::cable_table32_t
		this->getT(0).getT(2).getT(1).getT(1).                                                   // Stack_impl::peak3_t<NV>
        getT(0).getT(2).getT(4).getT(1).
        getT(2).setExternalData(b, index);
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
using Stack = wrap::node<Stack_impl::instance<NV>>;
}


