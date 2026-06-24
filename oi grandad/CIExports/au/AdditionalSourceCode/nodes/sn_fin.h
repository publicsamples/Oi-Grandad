#pragma once

#include "res2.h"
#include "res2.h"
#include "res2.h"
#include "res2.h"
#include "res2.h"
#include "res2.h"
#include "res2.h"
#include "res2.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace sn_fin_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable222_t_index = runtime_target::indexers::fix_hash<1120565314>;

template <int NV>
using global_cable222_t = routing::global_cable<global_cable222_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain237_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable222_t<NV>>, 
                                    math::add<NV>>;
using global_cable223_t_index = runtime_target::indexers::fix_hash<1120565315>;

template <int NV>
using global_cable223_t = routing::global_cable<global_cable223_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain238_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable223_t<NV>>, 
                                    math::add<NV>>;
using global_cable224_t_index = runtime_target::indexers::fix_hash<1120565316>;

template <int NV>
using global_cable224_t = routing::global_cable<global_cable224_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain239_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable224_t<NV>>, 
                                    math::add<NV>>;
using global_cable225_t_index = runtime_target::indexers::fix_hash<1120565317>;

template <int NV>
using global_cable225_t = routing::global_cable<global_cable225_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain240_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable225_t<NV>>, 
                                    math::add<NV>>;
using global_cable226_t_index = runtime_target::indexers::fix_hash<1120565318>;

template <int NV>
using global_cable226_t = routing::global_cable<global_cable226_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain241_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable226_t<NV>>, 
                                    math::add<NV>>;
using global_cable227_t_index = runtime_target::indexers::fix_hash<1120565319>;

template <int NV>
using global_cable227_t = routing::global_cable<global_cable227_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain242_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable227_t<NV>>, 
                                    math::add<NV>>;
using global_cable228_t_index = runtime_target::indexers::fix_hash<1120565320>;

template <int NV>
using global_cable228_t = routing::global_cable<global_cable228_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain243_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable228_t<NV>>, 
                                    math::add<NV>>;
using global_cable229_t_index = runtime_target::indexers::fix_hash<1120565321>;

template <int NV>
using global_cable229_t = routing::global_cable<global_cable229_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain244_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable229_t<NV>>, 
                                    math::add<NV>>;
using global_cable230_t_index = runtime_target::indexers::fix_hash<1120565322>;

template <int NV>
using global_cable230_t = routing::global_cable<global_cable230_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain245_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable230_t<NV>>, 
                                    math::add<NV>>;
using global_cable231_t_index = runtime_target::indexers::fix_hash<377786414>;

template <int NV>
using global_cable231_t = routing::global_cable<global_cable231_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain246_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable231_t<NV>>, 
                                    math::add<NV>>;
using global_cable232_t_index = runtime_target::indexers::fix_hash<377786415>;

template <int NV>
using global_cable232_t = routing::global_cable<global_cable232_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain247_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable232_t<NV>>, 
                                    math::add<NV>>;
using global_cable233_t_index = runtime_target::indexers::fix_hash<377786416>;

template <int NV>
using global_cable233_t = routing::global_cable<global_cable233_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain248_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable233_t<NV>>, 
                                    math::add<NV>>;
using global_cable254_t_index = runtime_target::indexers::fix_hash<377786417>;

template <int NV>
using global_cable254_t = routing::global_cable<global_cable254_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain249_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable254_t<NV>>, 
                                    math::add<NV>>;
using global_cable235_t_index = runtime_target::indexers::fix_hash<377786418>;

template <int NV>
using global_cable235_t = routing::global_cable<global_cable235_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain250_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable235_t<NV>>, 
                                    math::add<NV>>;
using global_cable236_t_index = runtime_target::indexers::fix_hash<377786419>;

template <int NV>
using global_cable236_t = routing::global_cable<global_cable236_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain251_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable236_t<NV>>, 
                                    math::add<NV>>;
using global_cable237_t_index = runtime_target::indexers::fix_hash<377786420>;

template <int NV>
using global_cable237_t = routing::global_cable<global_cable237_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain252_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable237_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch14_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain237_t<NV>>, 
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
                                     chain249_t<NV>, 
                                     chain250_t<NV>, 
                                     chain251_t<NV>, 
                                     chain252_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::rms>;
template <int NV>
using pma15_t = control::pma<NV, 
                             parameter::plain<xfader_t<NV>, 0>>;
template <int NV>
using peak14_t = wrap::mod<parameter::plain<pma15_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain236_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch14_t<NV>>, 
                                    peak14_t<NV>, 
                                    math::clear<NV>, 
                                    pma15_t<NV>>;
using global_cable238_t_index = global_cable222_t_index;

template <int NV>
using global_cable238_t = routing::global_cable<global_cable238_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain254_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable238_t<NV>>, 
                                    math::add<NV>>;
using global_cable239_t_index = global_cable223_t_index;

template <int NV>
using global_cable239_t = routing::global_cable<global_cable239_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain255_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable239_t<NV>>, 
                                    math::add<NV>>;
using global_cable240_t_index = global_cable224_t_index;

template <int NV>
using global_cable240_t = routing::global_cable<global_cable240_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain256_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable240_t<NV>>, 
                                    math::add<NV>>;
using global_cable241_t_index = global_cable225_t_index;

template <int NV>
using global_cable241_t = routing::global_cable<global_cable241_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain257_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable241_t<NV>>, 
                                    math::add<NV>>;
using global_cable242_t_index = global_cable226_t_index;

template <int NV>
using global_cable242_t = routing::global_cable<global_cable242_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain258_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable242_t<NV>>, 
                                    math::add<NV>>;
using global_cable243_t_index = global_cable227_t_index;

template <int NV>
using global_cable243_t = routing::global_cable<global_cable243_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain259_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable243_t<NV>>, 
                                    math::add<NV>>;
using global_cable244_t_index = global_cable228_t_index;

template <int NV>
using global_cable244_t = routing::global_cable<global_cable244_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain260_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable244_t<NV>>, 
                                    math::add<NV>>;
using global_cable245_t_index = global_cable229_t_index;

template <int NV>
using global_cable245_t = routing::global_cable<global_cable245_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain261_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable245_t<NV>>, 
                                    math::add<NV>>;
using global_cable246_t_index = global_cable230_t_index;

template <int NV>
using global_cable246_t = routing::global_cable<global_cable246_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain262_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable246_t<NV>>, 
                                    math::add<NV>>;
using global_cable247_t_index = global_cable231_t_index;

template <int NV>
using global_cable247_t = routing::global_cable<global_cable247_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain263_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable247_t<NV>>, 
                                    math::add<NV>>;
using global_cable248_t_index = global_cable232_t_index;

template <int NV>
using global_cable248_t = routing::global_cable<global_cable248_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain264_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable248_t<NV>>, 
                                    math::add<NV>>;
using global_cable249_t_index = global_cable233_t_index;

template <int NV>
using global_cable249_t = routing::global_cable<global_cable249_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain265_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable249_t<NV>>, 
                                    math::add<NV>>;
using global_cable250_t_index = global_cable254_t_index;

template <int NV>
using global_cable250_t = routing::global_cable<global_cable250_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain266_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable250_t<NV>>, 
                                    math::add<NV>>;
using global_cable251_t_index = global_cable235_t_index;

template <int NV>
using global_cable251_t = routing::global_cable<global_cable251_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain267_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable251_t<NV>>, 
                                    math::add<NV>>;
using global_cable252_t_index = global_cable236_t_index;

template <int NV>
using global_cable252_t = routing::global_cable<global_cable252_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain268_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable252_t<NV>>, 
                                    math::add<NV>>;
using global_cable253_t_index = global_cable237_t_index;

template <int NV>
using global_cable253_t = routing::global_cable<global_cable253_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain269_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable253_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch15_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain254_t<NV>>, 
                                     chain255_t<NV>, 
                                     chain256_t<NV>, 
                                     chain257_t<NV>, 
                                     chain258_t<NV>, 
                                     chain259_t<NV>, 
                                     chain260_t<NV>, 
                                     chain261_t<NV>, 
                                     chain262_t<NV>, 
                                     chain263_t<NV>, 
                                     chain264_t<NV>, 
                                     chain265_t<NV>, 
                                     chain266_t<NV>, 
                                     chain267_t<NV>, 
                                     chain268_t<NV>, 
                                     chain269_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(clone_cable_modRange, 
                             0., 
                             1000., 
                             0.30103);

template <int NV>
using clone_cable_mod = parameter::from0To1<project::res2<NV>, 
                                            1, 
                                            clone_cable_modRange>;

template <int NV>
using clone_cable_t = control::clone_cable<parameter::cloned<clone_cable_mod<NV>>, 
                                           duplilogic::spread>;
DECLARE_PARAMETER_RANGE_SKEW(pma16_mod_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma16_mod_0 = parameter::from0To1<filters::svf<NV>, 
                                        0, 
                                        pma16_mod_0Range>;

template <int NV> using pma16_mod_1 = pma16_mod_0<NV>;

template <int NV> using pma16_mod_2 = pma16_mod_0<NV>;

template <int NV> using pma16_mod_3 = pma16_mod_0<NV>;

template <int NV>
using pma16_mod_4 = parameter::from0To1<filters::svf_eq<NV>, 
                                        0, 
                                        pma16_mod_0Range>;

template <int NV> using pma16_mod_5 = pma16_mod_4<NV>;

template <int NV>
using pma16_mod_6 = parameter::from0To1<jdsp::jdelay_cubic<NV>, 
                                        1, 
                                        clone_cable_modRange>;

template <int NV>
using pma16_mod_8 = parameter::from0To1<filters::allpass<NV>, 
                                        0, 
                                        pma16_mod_0Range>;

DECLARE_PARAMETER_RANGE(pma16_mod_9Range, 
                        -1., 
                        1.);

template <int NV>
using pma16_mod_9 = parameter::from0To1<clone_cable_t<NV>, 
                                        1, 
                                        pma16_mod_9Range>;

template <int NV>
using pma16_mod = parameter::chain<ranges::Identity, 
                                   pma16_mod_0<NV>, 
                                   pma16_mod_1<NV>, 
                                   pma16_mod_2<NV>, 
                                   pma16_mod_3<NV>, 
                                   pma16_mod_4<NV>, 
                                   pma16_mod_5<NV>, 
                                   pma16_mod_6<NV>, 
                                   parameter::plain<fx::reverb, 2>, 
                                   pma16_mod_8<NV>, 
                                   pma16_mod_9<NV>>;

template <int NV>
using pma16_t = control::pma<NV, pma16_mod<NV>>;
template <int NV>
using peak15_t = wrap::mod<parameter::plain<pma16_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain253_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch15_t<NV>>, 
                                    peak15_t<NV>, 
                                    math::clear<NV>, 
                                    pma16_t<NV>>;
using global_cable270_t_index = global_cable222_t_index;

template <int NV>
using global_cable270_t = routing::global_cable<global_cable270_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain288_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable270_t<NV>>, 
                                    math::add<NV>>;
using global_cable271_t_index = global_cable223_t_index;

template <int NV>
using global_cable271_t = routing::global_cable<global_cable271_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain289_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable271_t<NV>>, 
                                    math::add<NV>>;
using global_cable272_t_index = global_cable224_t_index;

template <int NV>
using global_cable272_t = routing::global_cable<global_cable272_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain290_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable272_t<NV>>, 
                                    math::add<NV>>;
using global_cable273_t_index = global_cable225_t_index;

template <int NV>
using global_cable273_t = routing::global_cable<global_cable273_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain291_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable273_t<NV>>, 
                                    math::add<NV>>;
using global_cable274_t_index = global_cable226_t_index;

template <int NV>
using global_cable274_t = routing::global_cable<global_cable274_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain292_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable274_t<NV>>, 
                                    math::add<NV>>;
using global_cable275_t_index = global_cable227_t_index;

template <int NV>
using global_cable275_t = routing::global_cable<global_cable275_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain293_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable275_t<NV>>, 
                                    math::add<NV>>;
using global_cable276_t_index = global_cable228_t_index;

template <int NV>
using global_cable276_t = routing::global_cable<global_cable276_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain294_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable276_t<NV>>, 
                                    math::add<NV>>;
using global_cable277_t_index = global_cable229_t_index;

template <int NV>
using global_cable277_t = routing::global_cable<global_cable277_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain295_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable277_t<NV>>, 
                                    math::add<NV>>;
using global_cable278_t_index = global_cable230_t_index;

template <int NV>
using global_cable278_t = routing::global_cable<global_cable278_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain296_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable278_t<NV>>, 
                                    math::add<NV>>;
using global_cable279_t_index = global_cable231_t_index;

template <int NV>
using global_cable279_t = routing::global_cable<global_cable279_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain297_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable279_t<NV>>, 
                                    math::add<NV>>;
using global_cable280_t_index = global_cable232_t_index;

template <int NV>
using global_cable280_t = routing::global_cable<global_cable280_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain298_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable280_t<NV>>, 
                                    math::add<NV>>;
using global_cable281_t_index = global_cable233_t_index;

template <int NV>
using global_cable281_t = routing::global_cable<global_cable281_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain299_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable281_t<NV>>, 
                                    math::add<NV>>;
using global_cable282_t_index = global_cable254_t_index;

template <int NV>
using global_cable282_t = routing::global_cable<global_cable282_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain300_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable282_t<NV>>, 
                                    math::add<NV>>;
using global_cable283_t_index = global_cable235_t_index;

template <int NV>
using global_cable283_t = routing::global_cable<global_cable283_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain301_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable283_t<NV>>, 
                                    math::add<NV>>;
using global_cable284_t_index = global_cable236_t_index;

template <int NV>
using global_cable284_t = routing::global_cable<global_cable284_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain302_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable284_t<NV>>, 
                                    math::add<NV>>;
using global_cable285_t_index = global_cable237_t_index;

template <int NV>
using global_cable285_t = routing::global_cable<global_cable285_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain303_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable285_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch17_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain288_t<NV>>, 
                                     chain289_t<NV>, 
                                     chain290_t<NV>, 
                                     chain291_t<NV>, 
                                     chain292_t<NV>, 
                                     chain293_t<NV>, 
                                     chain294_t<NV>, 
                                     chain295_t<NV>, 
                                     chain296_t<NV>, 
                                     chain297_t<NV>, 
                                     chain298_t<NV>, 
                                     chain299_t<NV>, 
                                     chain300_t<NV>, 
                                     chain301_t<NV>, 
                                     chain302_t<NV>, 
                                     chain303_t<NV>>;

template <int NV>
using clone_cable1_t = control::clone_cable<parameter::cloned<parameter::plain<project::res2<NV>, 3>>, 
                                            duplilogic::fixed>;
template <int NV>
using pma18_mod_0 = parameter::from0To1<filters::one_pole<NV>, 
                                        0, 
                                        pma16_mod_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(pma18_mod_2Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using pma18_mod_2 = parameter::from0To1<filters::allpass<NV>, 
                                        1, 
                                        pma18_mod_2Range>;

template <int NV>
using pma18_mod_3 = parameter::from0To1<filters::svf<NV>, 
                                        1, 
                                        pma18_mod_2Range>;

template <int NV> using pma18_mod_4 = pma18_mod_3<NV>;

template <int NV> using pma18_mod_5 = pma18_mod_3<NV>;

template <int NV> using pma18_mod_6 = pma18_mod_3<NV>;

template <int NV> using pma18_mod_7 = pma18_mod_3<NV>;

template <int NV> using pma18_mod_8 = pma18_mod_3<NV>;

template <int NV> using pma18_mod_9 = pma18_mod_3<NV>;

template <int NV> using pma18_mod_10 = pma18_mod_3<NV>;

template <int NV>
using pma18_mod_11 = parameter::from0To1<filters::svf_eq<NV>, 
                                         1, 
                                         pma18_mod_2Range>;

template <int NV> using pma18_mod_12 = pma18_mod_11<NV>;

template <int NV>
using pma18_mod = parameter::chain<ranges::Identity, 
                                   pma18_mod_0<NV>, 
                                   parameter::plain<clone_cable1_t<NV>, 1>, 
                                   pma18_mod_2<NV>, 
                                   pma18_mod_3<NV>, 
                                   pma18_mod_4<NV>, 
                                   pma18_mod_5<NV>, 
                                   pma18_mod_6<NV>, 
                                   pma18_mod_7<NV>, 
                                   pma18_mod_8<NV>, 
                                   pma18_mod_9<NV>, 
                                   pma18_mod_10<NV>, 
                                   pma18_mod_11<NV>, 
                                   pma18_mod_12<NV>, 
                                   parameter::plain<fx::reverb, 0>>;

template <int NV>
using pma18_t = control::pma<NV, pma18_mod<NV>>;
template <int NV>
using peak17_t = wrap::mod<parameter::plain<pma18_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain287_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch17_t<NV>>, 
                                    peak17_t<NV>, 
                                    math::clear<NV>, 
                                    pma18_t<NV>>;
using global_cable302_t_index = global_cable222_t_index;

template <int NV>
using global_cable302_t = routing::global_cable<global_cable302_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain322_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable302_t<NV>>, 
                                    math::add<NV>>;
using global_cable303_t_index = global_cable223_t_index;

template <int NV>
using global_cable303_t = routing::global_cable<global_cable303_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain323_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable303_t<NV>>, 
                                    math::add<NV>>;
using global_cable304_t_index = global_cable224_t_index;

template <int NV>
using global_cable304_t = routing::global_cable<global_cable304_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain324_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable304_t<NV>>, 
                                    math::add<NV>>;
using global_cable305_t_index = global_cable225_t_index;

template <int NV>
using global_cable305_t = routing::global_cable<global_cable305_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain325_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable305_t<NV>>, 
                                    math::add<NV>>;
using global_cable306_t_index = global_cable226_t_index;

template <int NV>
using global_cable306_t = routing::global_cable<global_cable306_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain326_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable306_t<NV>>, 
                                    math::add<NV>>;
using global_cable307_t_index = global_cable227_t_index;

template <int NV>
using global_cable307_t = routing::global_cable<global_cable307_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain327_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable307_t<NV>>, 
                                    math::add<NV>>;
using global_cable308_t_index = global_cable228_t_index;

template <int NV>
using global_cable308_t = routing::global_cable<global_cable308_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain328_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable308_t<NV>>, 
                                    math::add<NV>>;
using global_cable309_t_index = global_cable229_t_index;

template <int NV>
using global_cable309_t = routing::global_cable<global_cable309_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain329_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable309_t<NV>>, 
                                    math::add<NV>>;
using global_cable310_t_index = global_cable230_t_index;

template <int NV>
using global_cable310_t = routing::global_cable<global_cable310_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain330_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable310_t<NV>>, 
                                    math::add<NV>>;
using global_cable311_t_index = global_cable231_t_index;

template <int NV>
using global_cable311_t = routing::global_cable<global_cable311_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain331_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable311_t<NV>>, 
                                    math::add<NV>>;
using global_cable312_t_index = global_cable232_t_index;

template <int NV>
using global_cable312_t = routing::global_cable<global_cable312_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain332_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable312_t<NV>>, 
                                    math::add<NV>>;
using global_cable313_t_index = global_cable233_t_index;

template <int NV>
using global_cable313_t = routing::global_cable<global_cable313_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain333_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable313_t<NV>>, 
                                    math::add<NV>>;
using global_cable314_t_index = global_cable254_t_index;

template <int NV>
using global_cable314_t = routing::global_cable<global_cable314_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain334_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable314_t<NV>>, 
                                    math::add<NV>>;
using global_cable315_t_index = global_cable235_t_index;

template <int NV>
using global_cable315_t = routing::global_cable<global_cable315_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain335_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable315_t<NV>>, 
                                    math::add<NV>>;
using global_cable316_t_index = global_cable236_t_index;

template <int NV>
using global_cable316_t = routing::global_cable<global_cable316_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain336_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable316_t<NV>>, 
                                    math::add<NV>>;
using global_cable317_t_index = global_cable237_t_index;

template <int NV>
using global_cable317_t = routing::global_cable<global_cable317_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain337_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable317_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch19_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain322_t<NV>>, 
                                     chain323_t<NV>, 
                                     chain324_t<NV>, 
                                     chain325_t<NV>, 
                                     chain326_t<NV>, 
                                     chain327_t<NV>, 
                                     chain328_t<NV>, 
                                     chain329_t<NV>, 
                                     chain330_t<NV>, 
                                     chain331_t<NV>, 
                                     chain332_t<NV>, 
                                     chain333_t<NV>, 
                                     chain334_t<NV>, 
                                     chain335_t<NV>, 
                                     chain336_t<NV>, 
                                     chain337_t<NV>>;

template <int NV>
using stereo_frame_cable = cable::frame<NV, 2>;

template <int NV>
using clone_cable2_t = control::clone_cable<parameter::cloned<parameter::plain<project::res2<NV>, 0>>, 
                                            duplilogic::fixed>;
template <int NV> using pma20_mod_0 = pma16_mod_0<NV>;

template <int NV> using pma20_mod_1 = pma16_mod_0<NV>;

template <int NV> using pma20_mod_2 = pma16_mod_0<NV>;

template <int NV> using pma20_mod_3 = pma16_mod_0<NV>;

DECLARE_PARAMETER_RANGE(pma20_mod_4Range, 
                        -18., 
                        18.);

template <int NV>
using pma20_mod_4 = parameter::from0To1<filters::svf_eq<NV>, 
                                        2, 
                                        pma20_mod_4Range>;

template <int NV> using pma20_mod_5 = pma20_mod_4<NV>;

DECLARE_PARAMETER_RANGE_SKEW(pma20_mod_6Range, 
                             50., 
                             20000., 
                             0.229905);

template <int NV>
using pma20_mod_6 = parameter::from0To1<filters::one_pole<NV>, 
                                        0, 
                                        pma20_mod_6Range>;

template <int NV>
using pma20_mod = parameter::chain<ranges::Identity, 
                                   pma20_mod_0<NV>, 
                                   pma20_mod_1<NV>, 
                                   pma20_mod_2<NV>, 
                                   pma20_mod_3<NV>, 
                                   pma20_mod_4<NV>, 
                                   pma20_mod_5<NV>, 
                                   pma20_mod_6<NV>, 
                                   parameter::plain<routing::receive<NV, stereo_frame_cable<NV>>, 0>, 
                                   parameter::plain<clone_cable2_t<NV>, 1>, 
                                   parameter::plain<fx::reverb, 1>>;

template <int NV>
using pma20_t = control::pma<NV, pma20_mod<NV>>;
template <int NV>
using peak19_t = wrap::mod<parameter::plain<pma20_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain321_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch19_t<NV>>, 
                                    peak19_t<NV>, 
                                    math::clear<NV>, 
                                    pma20_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain236_t<NV>>, 
                                 chain253_t<NV>, 
                                 chain287_t<NV>, 
                                 chain321_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using fix8_block_t = container::chain<parameter::empty, 
                                      wrap::fix<2, modchain_t<NV>>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>>;

using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::svf<NV>>, 
                                  filters::svf<NV>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain1_t<NV>>>;

template <int NV> using chain43_t = chain1_t<NV>;

template <int NV> using chain40_t = chain1_t<NV>;

template <int NV> using chain39_t = chain1_t<NV>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::svf_eq<NV>>>;

template <int NV> using chain42_t = chain41_t<NV>;

template <int NV>
using frame2_block2_t_ = container::chain<parameter::empty, 
                                          wrap::fix<2, filters::allpass<NV>>, 
                                          filters::one_pole<NV>>;

template <int NV>
using frame2_block2_t = wrap::frame<2, frame2_block2_t_<NV>>;

template <int NV>
using frame2_block1_t_ = container::chain<parameter::empty, 
                                          wrap::fix<2, routing::receive<NV, stereo_frame_cable<NV>>>, 
                                          jdsp::jdelay_cubic<NV>, 
                                          filters::one_pole<NV>, 
                                          routing::send<NV, stereo_frame_cable<NV>>, 
                                          filters::one_pole<NV>>;

template <int NV>
using frame2_block1_t = wrap::frame<2, frame2_block1_t_<NV>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, frame2_block1_t<NV>>>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, project::res2<NV>>, 
                                       core::gain<NV>>;
template <int NV>
using clone_t = wrap::fix_clonecopy<clone_child_t<NV>, 8>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, clone_cable_t<NV>>, 
                                   clone_cable1_t<NV>, 
                                   clone_cable2_t<NV>, 
                                   clone_t<NV>, 
                                   filters::one_pole<NV>>;

using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, fx::reverb>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain20_t>, 
                                    chain38_t<NV>, 
                                    chain43_t<NV>, 
                                    chain40_t<NV>, 
                                    chain39_t<NV>, 
                                    chain41_t<NV>, 
                                    chain42_t<NV>, 
                                    frame2_block2_t<NV>, 
                                    chain18_t<NV>, 
                                    chain17_t<NV>, 
                                    chain_t>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch1_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain22_t<NV>>, 
                                  chain19_t<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split1_t<NV>>>;

namespace sn_fin_t_parameters
{
// Parameter list for sn_fin_impl::sn_fin_t --------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(ResoSrc_InputRange, 
                             1., 
                             16., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(ResoSrc_0Range, 
                             0., 
                             15., 
                             1.);

template <int NV>
using ResoSrc_0 = parameter::from0To1<sn_fin_impl::branch14_t<NV>, 
                                      0, 
                                      ResoSrc_0Range>;

template <int NV>
using ResoSrc = parameter::chain<ResoSrc_InputRange, ResoSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ResPitchSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using ResPitchSrc_0 = parameter::from0To1<sn_fin_impl::branch15_t<NV>, 
                                          0, 
                                          ResoSrc_0Range>;

template <int NV>
using ResPitchSrc = parameter::chain<ResPitchSrc_InputRange, ResPitchSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ResLpSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using ResLpSrc_0 = parameter::from0To1<sn_fin_impl::branch17_t<NV>, 
                                       0, 
                                       ResoSrc_0Range>;

template <int NV>
using ResLpSrc = parameter::chain<ResLpSrc_InputRange, ResLpSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(delMode_InputRange, 
                             1., 
                             11., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(delMode_0Range, 
                             0., 
                             10., 
                             1.);

template <int NV>
using delMode_0 = parameter::from0To1<sn_fin_impl::branch1_t<NV>, 
                                      0, 
                                      delMode_0Range>;

template <int NV>
using delMode = parameter::chain<delMode_InputRange, delMode_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(MetaSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using MetaSrc_0 = parameter::from0To1<sn_fin_impl::branch19_t<NV>, 
                                      0, 
                                      ResoSrc_0Range>;

template <int NV>
using MetaSrc = parameter::chain<MetaSrc_InputRange, MetaSrc_0<NV>>;

template <int NV>
using ResoMix = parameter::plain<sn_fin_impl::pma15_t<NV>, 
                                 2>;
template <int NV>
using ResoMixMod = parameter::plain<sn_fin_impl::pma15_t<NV>, 
                                    1>;
template <int NV>
using ResPitch = parameter::plain<sn_fin_impl::pma16_t<NV>, 
                                  2>;
template <int NV>
using RespPitchMod = parameter::plain<sn_fin_impl::pma16_t<NV>, 
                                      1>;
template <int NV>
using ResLp = parameter::plain<sn_fin_impl::pma18_t<NV>, 
                               2>;
template <int NV>
using ResLpMod = parameter::plain<sn_fin_impl::pma18_t<NV>, 
                                  1>;
template <int NV>
using Meta = parameter::plain<sn_fin_impl::pma20_t<NV>, 
                              2>;
template <int NV>
using MetaMod = parameter::plain<sn_fin_impl::pma20_t<NV>, 
                                 1>;
template <int NV>
using sn_fin_t_plist = parameter::list<ResoMix<NV>, 
                                       ResoMixMod<NV>, 
                                       ResoSrc<NV>, 
                                       ResPitch<NV>, 
                                       RespPitchMod<NV>, 
                                       ResPitchSrc<NV>, 
                                       ResLp<NV>, 
                                       ResLpMod<NV>, 
                                       ResLpSrc<NV>, 
                                       delMode<NV>, 
                                       Meta<NV>, 
                                       MetaMod<NV>, 
                                       MetaSrc<NV>>;
}

template <int NV>
using sn_fin_t_ = container::chain<sn_fin_t_parameters::sn_fin_t_plist<NV>, 
                                   wrap::fix<2, fix8_block_t<NV>>, 
                                   xfader_t<NV>, 
                                   chain16_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public sn_fin_impl::sn_fin_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(sn_fin);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(234)
		{
			0x005C, 0x0000, 0x0000, 0x6552, 0x6F73, 0x694D, 0x0078, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x0100, 0x0000, 0x5200, 0x7365, 0x4D6F, 0x7869, 
            0x6F4D, 0x0064, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0200, 0x0000, 0x5200, 
            0x7365, 0x536F, 0x6372, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4180, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0003, 
            0x0000, 0x6552, 0x5073, 0x7469, 0x6863, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0xF4DF, 0x3E50, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0004, 0x0000, 0x6552, 0x7073, 0x6950, 0x6374, 0x4D68, 
            0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0005, 0x0000, 0x6552, 
            0x5073, 0x7469, 0x6863, 0x7253, 0x0063, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0041, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x0600, 0x0000, 0x5200, 0x7365, 0x704C, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0007, 0x0000, 0x6552, 0x4C73, 0x4D70, 0x646F, 0x0000, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0008, 0x0000, 0x6552, 0x4C73, 0x5370, 
            0x6372, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0009, 0x0000, 0x6564, 
            0x4D6C, 0x646F, 0x0065, 0x0000, 0x8000, 0x003F, 0x3000, 0x0041, 
            0x2000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0A00, 0x0000, 
            0x4D00, 0x7465, 0x0061, 0x0000, 0x0000, 0x0000, 0x8000, 0x9C3F, 
            0x6BDE, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0B00, 0x0000, 
            0x4D00, 0x7465, 0x4D61, 0x646F, 0x0000, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x000C, 0x0000, 0x654D, 0x6174, 0x7253, 0x0063, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block = this->getT(0);                                                       // sn_fin_impl::fix8_block_t<NV>
		auto& modchain = this->getT(0).getT(0);                                                 // sn_fin_impl::modchain_t<NV>
		auto& split = this->getT(0).getT(0).getT(0);                                            // sn_fin_impl::split_t<NV>
		auto& chain236 = this->getT(0).getT(0).getT(0).getT(0);                                 // sn_fin_impl::chain236_t<NV>
		auto& branch14 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                         // sn_fin_impl::branch14_t<NV>
		auto& chain237 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);                 // sn_fin_impl::chain237_t<NV>
		auto& global_cable222 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);  // sn_fin_impl::global_cable222_t<NV>
		auto& add222 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain238 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);                 // sn_fin_impl::chain238_t<NV>
		auto& global_cable223 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);  // sn_fin_impl::global_cable223_t<NV>
		auto& add223 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain239 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);                 // sn_fin_impl::chain239_t<NV>
		auto& global_cable224 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(0);  // sn_fin_impl::global_cable224_t<NV>
		auto& add224 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain240 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3);                 // sn_fin_impl::chain240_t<NV>
		auto& global_cable225 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(0);  // sn_fin_impl::global_cable225_t<NV>
		auto& add225 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain241 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4);                 // sn_fin_impl::chain241_t<NV>
		auto& global_cable226 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(0);  // sn_fin_impl::global_cable226_t<NV>
		auto& add226 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain242 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5);                 // sn_fin_impl::chain242_t<NV>
		auto& global_cable227 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(0);  // sn_fin_impl::global_cable227_t<NV>
		auto& add227 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain243 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(6);                 // sn_fin_impl::chain243_t<NV>
		auto& global_cable228 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(6).getT(0);  // sn_fin_impl::global_cable228_t<NV>
		auto& add228 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain244 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(7);                 // sn_fin_impl::chain244_t<NV>
		auto& global_cable229 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(7).getT(0);  // sn_fin_impl::global_cable229_t<NV>
		auto& add229 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain245 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(8);                 // sn_fin_impl::chain245_t<NV>
		auto& global_cable230 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(8).getT(0);  // sn_fin_impl::global_cable230_t<NV>
		auto& add230 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain246 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(9);                 // sn_fin_impl::chain246_t<NV>
		auto& global_cable231 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(9).getT(0);  // sn_fin_impl::global_cable231_t<NV>
		auto& add231 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain247 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(10);                // sn_fin_impl::chain247_t<NV>
		auto& global_cable232 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(10).getT(0); // sn_fin_impl::global_cable232_t<NV>
		auto& add232 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain248 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(11);                // sn_fin_impl::chain248_t<NV>
		auto& global_cable233 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(11).getT(0); // sn_fin_impl::global_cable233_t<NV>
		auto& add233 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain249 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(12);                // sn_fin_impl::chain249_t<NV>
		auto& global_cable254 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(12).getT(0); // sn_fin_impl::global_cable254_t<NV>
		auto& add234 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain250 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(13);                // sn_fin_impl::chain250_t<NV>
		auto& global_cable235 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(13).getT(0); // sn_fin_impl::global_cable235_t<NV>
		auto& add235 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain251 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(14);                // sn_fin_impl::chain251_t<NV>
		auto& global_cable236 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(14).getT(0); // sn_fin_impl::global_cable236_t<NV>
		auto& add236 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain252 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(15);                // sn_fin_impl::chain252_t<NV>
		auto& global_cable237 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(15).getT(0); // sn_fin_impl::global_cable237_t<NV>
		auto& add237 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak14 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                           // sn_fin_impl::peak14_t<NV>
		auto& clear14 = this->getT(0).getT(0).getT(0).getT(0).getT(2);                          // math::clear<NV>
		auto& pma15 = this->getT(0).getT(0).getT(0).getT(0).getT(3);                            // sn_fin_impl::pma15_t<NV>
		auto& chain253 = this->getT(0).getT(0).getT(0).getT(1);                                 // sn_fin_impl::chain253_t<NV>
		auto& branch15 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                         // sn_fin_impl::branch15_t<NV>
		auto& chain254 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);                 // sn_fin_impl::chain254_t<NV>
		auto& global_cable238 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);  // sn_fin_impl::global_cable238_t<NV>
		auto& add238 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain255 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);                 // sn_fin_impl::chain255_t<NV>
		auto& global_cable239 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);  // sn_fin_impl::global_cable239_t<NV>
		auto& add239 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain256 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);                 // sn_fin_impl::chain256_t<NV>
		auto& global_cable240 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2).getT(0);  // sn_fin_impl::global_cable240_t<NV>
		auto& add240 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain257 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(3);                 // sn_fin_impl::chain257_t<NV>
		auto& global_cable241 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(3).getT(0);  // sn_fin_impl::global_cable241_t<NV>
		auto& add241 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain258 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(4);                 // sn_fin_impl::chain258_t<NV>
		auto& global_cable242 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(4).getT(0);  // sn_fin_impl::global_cable242_t<NV>
		auto& add242 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain259 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(5);                 // sn_fin_impl::chain259_t<NV>
		auto& global_cable243 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(5).getT(0);  // sn_fin_impl::global_cable243_t<NV>
		auto& add243 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain260 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(6);                 // sn_fin_impl::chain260_t<NV>
		auto& global_cable244 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(6).getT(0);  // sn_fin_impl::global_cable244_t<NV>
		auto& add244 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain261 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(7);                 // sn_fin_impl::chain261_t<NV>
		auto& global_cable245 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(7).getT(0);  // sn_fin_impl::global_cable245_t<NV>
		auto& add245 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain262 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(8);                 // sn_fin_impl::chain262_t<NV>
		auto& global_cable246 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(8).getT(0);  // sn_fin_impl::global_cable246_t<NV>
		auto& add246 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain263 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(9);                 // sn_fin_impl::chain263_t<NV>
		auto& global_cable247 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(9).getT(0);  // sn_fin_impl::global_cable247_t<NV>
		auto& add247 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain264 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(10);                // sn_fin_impl::chain264_t<NV>
		auto& global_cable248 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(10).getT(0); // sn_fin_impl::global_cable248_t<NV>
		auto& add248 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain265 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(11);                // sn_fin_impl::chain265_t<NV>
		auto& global_cable249 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(11).getT(0); // sn_fin_impl::global_cable249_t<NV>
		auto& add249 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain266 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(12);                // sn_fin_impl::chain266_t<NV>
		auto& global_cable250 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(12).getT(0); // sn_fin_impl::global_cable250_t<NV>
		auto& add250 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain267 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(13);                // sn_fin_impl::chain267_t<NV>
		auto& global_cable251 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(13).getT(0); // sn_fin_impl::global_cable251_t<NV>
		auto& add251 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain268 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(14);                // sn_fin_impl::chain268_t<NV>
		auto& global_cable252 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(14).getT(0); // sn_fin_impl::global_cable252_t<NV>
		auto& add252 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain269 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(15);                // sn_fin_impl::chain269_t<NV>
		auto& global_cable253 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(15).getT(0); // sn_fin_impl::global_cable253_t<NV>
		auto& add253 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak15 = this->getT(0).getT(0).getT(0).getT(1).getT(1);                           // sn_fin_impl::peak15_t<NV>
		auto& clear15 = this->getT(0).getT(0).getT(0).getT(1).getT(2);                          // math::clear<NV>
		auto& pma16 = this->getT(0).getT(0).getT(0).getT(1).getT(3);                            // sn_fin_impl::pma16_t<NV>
		auto& chain287 = this->getT(0).getT(0).getT(0).getT(2);                                 // sn_fin_impl::chain287_t<NV>
		auto& branch17 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                         // sn_fin_impl::branch17_t<NV>
		auto& chain288 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0);                 // sn_fin_impl::chain288_t<NV>
		auto& global_cable270 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0).getT(0);  // sn_fin_impl::global_cable270_t<NV>
		auto& add270 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain289 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1);                 // sn_fin_impl::chain289_t<NV>
		auto& global_cable271 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1).getT(0);  // sn_fin_impl::global_cable271_t<NV>
		auto& add271 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain290 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2);                 // sn_fin_impl::chain290_t<NV>
		auto& global_cable272 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2).getT(0);  // sn_fin_impl::global_cable272_t<NV>
		auto& add272 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain291 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(3);                 // sn_fin_impl::chain291_t<NV>
		auto& global_cable273 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(3).getT(0);  // sn_fin_impl::global_cable273_t<NV>
		auto& add273 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain292 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(4);                 // sn_fin_impl::chain292_t<NV>
		auto& global_cable274 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(4).getT(0);  // sn_fin_impl::global_cable274_t<NV>
		auto& add274 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain293 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(5);                 // sn_fin_impl::chain293_t<NV>
		auto& global_cable275 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(5).getT(0);  // sn_fin_impl::global_cable275_t<NV>
		auto& add275 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain294 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(6);                 // sn_fin_impl::chain294_t<NV>
		auto& global_cable276 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(6).getT(0);  // sn_fin_impl::global_cable276_t<NV>
		auto& add276 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain295 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(7);                 // sn_fin_impl::chain295_t<NV>
		auto& global_cable277 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(7).getT(0);  // sn_fin_impl::global_cable277_t<NV>
		auto& add277 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain296 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(8);                 // sn_fin_impl::chain296_t<NV>
		auto& global_cable278 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(8).getT(0);  // sn_fin_impl::global_cable278_t<NV>
		auto& add278 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain297 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(9);                 // sn_fin_impl::chain297_t<NV>
		auto& global_cable279 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(9).getT(0);  // sn_fin_impl::global_cable279_t<NV>
		auto& add279 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain298 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(10);                // sn_fin_impl::chain298_t<NV>
		auto& global_cable280 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(10).getT(0); // sn_fin_impl::global_cable280_t<NV>
		auto& add280 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain299 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(11);                // sn_fin_impl::chain299_t<NV>
		auto& global_cable281 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(11).getT(0); // sn_fin_impl::global_cable281_t<NV>
		auto& add281 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain300 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(12);                // sn_fin_impl::chain300_t<NV>
		auto& global_cable282 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(12).getT(0); // sn_fin_impl::global_cable282_t<NV>
		auto& add282 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain301 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(13);                // sn_fin_impl::chain301_t<NV>
		auto& global_cable283 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(13).getT(0); // sn_fin_impl::global_cable283_t<NV>
		auto& add283 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain302 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(14);                // sn_fin_impl::chain302_t<NV>
		auto& global_cable284 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(14).getT(0); // sn_fin_impl::global_cable284_t<NV>
		auto& add284 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain303 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(15);                // sn_fin_impl::chain303_t<NV>
		auto& global_cable285 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(15).getT(0); // sn_fin_impl::global_cable285_t<NV>
		auto& add285 = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak17 = this->getT(0).getT(0).getT(0).getT(2).getT(1);                           // sn_fin_impl::peak17_t<NV>
		auto& clear17 = this->getT(0).getT(0).getT(0).getT(2).getT(2);                          // math::clear<NV>
		auto& pma18 = this->getT(0).getT(0).getT(0).getT(2).getT(3);                            // sn_fin_impl::pma18_t<NV>
		auto& chain321 = this->getT(0).getT(0).getT(0).getT(3);                                 // sn_fin_impl::chain321_t<NV>
		auto& branch19 = this->getT(0).getT(0).getT(0).getT(3).getT(0);                         // sn_fin_impl::branch19_t<NV>
		auto& chain322 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0);                 // sn_fin_impl::chain322_t<NV>
		auto& global_cable302 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0).getT(0);  // sn_fin_impl::global_cable302_t<NV>
		auto& add302 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0).getT(1);           // math::add<NV>
		auto& chain323 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1);                 // sn_fin_impl::chain323_t<NV>
		auto& global_cable303 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1).getT(0);  // sn_fin_impl::global_cable303_t<NV>
		auto& add303 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1).getT(1);           // math::add<NV>
		auto& chain324 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2);                 // sn_fin_impl::chain324_t<NV>
		auto& global_cable304 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2).getT(0);  // sn_fin_impl::global_cable304_t<NV>
		auto& add304 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain325 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(3);                 // sn_fin_impl::chain325_t<NV>
		auto& global_cable305 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(3).getT(0);  // sn_fin_impl::global_cable305_t<NV>
		auto& add305 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain326 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(4);                 // sn_fin_impl::chain326_t<NV>
		auto& global_cable306 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(4).getT(0);  // sn_fin_impl::global_cable306_t<NV>
		auto& add306 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& chain327 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(5);                 // sn_fin_impl::chain327_t<NV>
		auto& global_cable307 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(5).getT(0);  // sn_fin_impl::global_cable307_t<NV>
		auto& add307 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(5).getT(1);           // math::add<NV>
		auto& chain328 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(6);                 // sn_fin_impl::chain328_t<NV>
		auto& global_cable308 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(6).getT(0);  // sn_fin_impl::global_cable308_t<NV>
		auto& add308 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain329 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(7);                 // sn_fin_impl::chain329_t<NV>
		auto& global_cable309 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(7).getT(0);  // sn_fin_impl::global_cable309_t<NV>
		auto& add309 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain330 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(8);                 // sn_fin_impl::chain330_t<NV>
		auto& global_cable310 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(8).getT(0);  // sn_fin_impl::global_cable310_t<NV>
		auto& add310 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& chain331 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(9);                 // sn_fin_impl::chain331_t<NV>
		auto& global_cable311 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(9).getT(0);  // sn_fin_impl::global_cable311_t<NV>
		auto& add311 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(9).getT(1);           // math::add<NV>
		auto& chain332 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(10);                // sn_fin_impl::chain332_t<NV>
		auto& global_cable312 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(10).getT(0); // sn_fin_impl::global_cable312_t<NV>
		auto& add312 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(10).getT(1);          // math::add<NV>
		auto& chain333 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(11);                // sn_fin_impl::chain333_t<NV>
		auto& global_cable313 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(11).getT(0); // sn_fin_impl::global_cable313_t<NV>
		auto& add313 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(11).getT(1);          // math::add<NV>
		auto& chain334 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(12);                // sn_fin_impl::chain334_t<NV>
		auto& global_cable314 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(12).getT(0); // sn_fin_impl::global_cable314_t<NV>
		auto& add314 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(12).getT(1);          // math::add<NV>
		auto& chain335 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(13);                // sn_fin_impl::chain335_t<NV>
		auto& global_cable315 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(13).getT(0); // sn_fin_impl::global_cable315_t<NV>
		auto& add315 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(13).getT(1);          // math::add<NV>
		auto& chain336 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(14);                // sn_fin_impl::chain336_t<NV>
		auto& global_cable316 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(14).getT(0); // sn_fin_impl::global_cable316_t<NV>
		auto& add316 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(14).getT(1);          // math::add<NV>
		auto& chain337 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(15);                // sn_fin_impl::chain337_t<NV>
		auto& global_cable317 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(15).getT(0); // sn_fin_impl::global_cable317_t<NV>
		auto& add317 = this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(15).getT(1);          // math::add<NV>
		auto& peak19 = this->getT(0).getT(0).getT(0).getT(3).getT(1);                           // sn_fin_impl::peak19_t<NV>
		auto& clear19 = this->getT(0).getT(0).getT(0).getT(3).getT(2);                          // math::clear<NV>
		auto& pma20 = this->getT(0).getT(0).getT(0).getT(3).getT(3);                            // sn_fin_impl::pma20_t<NV>
		auto& xfader = this->getT(1);                                                           // sn_fin_impl::xfader_t<NV>
		auto& chain16 = this->getT(2);                                                          // sn_fin_impl::chain16_t<NV>
		auto& split1 = this->getT(2).getT(0);                                                   // sn_fin_impl::split1_t<NV>
		auto& chain22 = this->getT(2).getT(0).getT(0);                                          // sn_fin_impl::chain22_t<NV>
		auto& gain = this->getT(2).getT(0).getT(0).getT(0);                                     // core::gain<NV>
		auto& chain19 = this->getT(2).getT(0).getT(1);                                          // sn_fin_impl::chain19_t<NV>
		auto& branch1 = this->getT(2).getT(0).getT(1).getT(0);                                  // sn_fin_impl::branch1_t<NV>
		auto& chain20 = this->getT(2).getT(0).getT(1).getT(0).getT(0);                          // sn_fin_impl::chain20_t
		auto& chain38 = this->getT(2).getT(0).getT(1).getT(0).getT(1);                          // sn_fin_impl::chain38_t<NV>
		auto& chain1 = this->getT(2).getT(0).getT(1).getT(0).getT(1).getT(0);                   // sn_fin_impl::chain1_t<NV>
		auto& svf = this->getT(2).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0);              // filters::svf<NV>
		auto& svf1 = this->getT(2).getT(0).getT(1).getT(0).getT(1).getT(0).getT(1);             // filters::svf<NV>
		auto& chain43 = this->getT(2).getT(0).getT(1).getT(0).getT(2);                          // sn_fin_impl::chain43_t<NV>
		auto& svf5 = this->getT(2).getT(0).getT(1).getT(0).getT(2).getT(0);                     // filters::svf<NV>
		auto& svf7 = this->getT(2).getT(0).getT(1).getT(0).getT(2).getT(1);                     // filters::svf<NV>
		auto& chain40 = this->getT(2).getT(0).getT(1).getT(0).getT(3);                          // sn_fin_impl::chain40_t<NV>
		auto& svf4 = this->getT(2).getT(0).getT(1).getT(0).getT(3).getT(0);                     // filters::svf<NV>
		auto& svf8 = this->getT(2).getT(0).getT(1).getT(0).getT(3).getT(1);                     // filters::svf<NV>
		auto& chain39 = this->getT(2).getT(0).getT(1).getT(0).getT(4);                          // sn_fin_impl::chain39_t<NV>
		auto& svf3 = this->getT(2).getT(0).getT(1).getT(0).getT(4).getT(0);                     // filters::svf<NV>
		auto& svf9 = this->getT(2).getT(0).getT(1).getT(0).getT(4).getT(1);                     // filters::svf<NV>
		auto& chain41 = this->getT(2).getT(0).getT(1).getT(0).getT(5);                          // sn_fin_impl::chain41_t<NV>
		auto& svf_eq1 = this->getT(2).getT(0).getT(1).getT(0).getT(5).getT(0);                  // filters::svf_eq<NV>
		auto& chain42 = this->getT(2).getT(0).getT(1).getT(0).getT(6);                          // sn_fin_impl::chain42_t<NV>
		auto& svf_eq2 = this->getT(2).getT(0).getT(1).getT(0).getT(6).getT(0);                  // filters::svf_eq<NV>
		auto& frame2_block2 = this->getT(2).getT(0).getT(1).getT(0).getT(7);                    // sn_fin_impl::frame2_block2_t<NV>
		auto& allpass = this->getT(2).getT(0).getT(1).getT(0).getT(7).getT(0);                  // filters::allpass<NV>
		auto& one_pole4 = this->getT(2).getT(0).getT(1).getT(0).getT(7).getT(1);                // filters::one_pole<NV>
		auto& chain18 = this->getT(2).getT(0).getT(1).getT(0).getT(8);                          // sn_fin_impl::chain18_t<NV>
		auto& frame2_block1 = this->getT(2).getT(0).getT(1).getT(0).getT(8).getT(0);            // sn_fin_impl::frame2_block1_t<NV>
		auto& receive = this->getT(2).getT(0).getT(1).getT(0).getT(8).getT(0).getT(0);          // routing::receive<NV, stereo_frame_cable<NV>>
		auto& jdelay_cubic = this->getT(2).getT(0).getT(1).getT(0).getT(8).getT(0).getT(1);     // jdsp::jdelay_cubic<NV>
		auto& one_pole5 = this->getT(2).getT(0).getT(1).getT(0).getT(8).getT(0).getT(2);        // filters::one_pole<NV>
		auto& send = this->getT(2).getT(0).getT(1).getT(0).getT(8).getT(0).getT(3);             // routing::send<NV, stereo_frame_cable<NV>>
		auto& one_pole3 = this->getT(2).getT(0).getT(1).getT(0).getT(8).getT(0).getT(4);        // filters::one_pole<NV>
		auto& chain17 = this->getT(2).getT(0).getT(1).getT(0).getT(9);                          // sn_fin_impl::chain17_t<NV>
		auto& clone_cable = this->getT(2).getT(0).getT(1).getT(0).getT(9).getT(0);              // sn_fin_impl::clone_cable_t<NV>
		auto& clone_cable1 = this->getT(2).getT(0).getT(1).getT(0).getT(9).getT(1);             // sn_fin_impl::clone_cable1_t<NV>
		auto& clone_cable2 = this->getT(2).getT(0).getT(1).getT(0).getT(9).getT(2);             // sn_fin_impl::clone_cable2_t<NV>
		auto& clone = this->getT(2).getT(0).getT(1).getT(0).getT(9).getT(3);                    // sn_fin_impl::clone_t<NV>                    // sn_fin_impl::clone_child_t<NV>
		auto res2 = this->getT(2).getT(0).getT(1).getT(0).getT(9).getT(3).getT(0);              // project::res2<NV>
		auto gain2 = this->getT(2).getT(0).getT(1).getT(0).getT(9).getT(3).getT(1);             // core::gain<NV>
		auto& one_pole2 = this->getT(2).getT(0).getT(1).getT(0).getT(9).getT(4);                // filters::one_pole<NV>
		auto& chain = this->getT(2).getT(0).getT(1).getT(0).getT(10);                           // sn_fin_impl::chain_t
		auto& reverb = this->getT(2).getT(0).getT(1).getT(0).getT(10).getT(0);                  // fx::reverb
		auto& gain1 = this->getT(2).getT(0).getT(1).getT(1);                                    // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma15); // ResoMix -> pma15::Add
		
		this->getParameterT(1).connectT(0, pma15); // ResoMixMod -> pma15::Multiply
		
		this->getParameterT(2).connectT(0, branch14); // ResoSrc -> branch14::Index
		
		this->getParameterT(3).connectT(0, pma16); // ResPitch -> pma16::Add
		
		this->getParameterT(4).connectT(0, pma16); // RespPitchMod -> pma16::Multiply
		
		this->getParameterT(5).connectT(0, branch15); // ResPitchSrc -> branch15::Index
		
		this->getParameterT(6).connectT(0, pma18); // ResLp -> pma18::Add
		
		this->getParameterT(7).connectT(0, pma18); // ResLpMod -> pma18::Multiply
		
		this->getParameterT(8).connectT(0, branch17); // ResLpSrc -> branch17::Index
		
		this->getParameterT(9).connectT(0, branch1); // delMode -> branch1::Index
		
		this->getParameterT(10).connectT(0, pma20); // Meta -> pma20::Add
		
		this->getParameterT(11).connectT(0, pma20); // MetaMod -> pma20::Multiply
		
		this->getParameterT(12).connectT(0, branch19); // MetaSrc -> branch19::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable222.getWrappedObject().getParameter().connectT(0, add222); // global_cable222 -> add222::Value
		global_cable223.getWrappedObject().getParameter().connectT(0, add223); // global_cable223 -> add223::Value
		global_cable224.getWrappedObject().getParameter().connectT(0, add224); // global_cable224 -> add224::Value
		global_cable225.getWrappedObject().getParameter().connectT(0, add225); // global_cable225 -> add225::Value
		global_cable226.getWrappedObject().getParameter().connectT(0, add226); // global_cable226 -> add226::Value
		global_cable227.getWrappedObject().getParameter().connectT(0, add227); // global_cable227 -> add227::Value
		global_cable228.getWrappedObject().getParameter().connectT(0, add228); // global_cable228 -> add228::Value
		global_cable229.getWrappedObject().getParameter().connectT(0, add229); // global_cable229 -> add229::Value
		global_cable230.getWrappedObject().getParameter().connectT(0, add230); // global_cable230 -> add230::Value
		global_cable231.getWrappedObject().getParameter().connectT(0, add231); // global_cable231 -> add231::Value
		global_cable232.getWrappedObject().getParameter().connectT(0, add232); // global_cable232 -> add232::Value
		global_cable233.getWrappedObject().getParameter().connectT(0, add233); // global_cable233 -> add233::Value
		global_cable254.getWrappedObject().getParameter().connectT(0, add234); // global_cable254 -> add234::Value
		global_cable235.getWrappedObject().getParameter().connectT(0, add235); // global_cable235 -> add235::Value
		global_cable236.getWrappedObject().getParameter().connectT(0, add236); // global_cable236 -> add236::Value
		global_cable237.getWrappedObject().getParameter().connectT(0, add237); // global_cable237 -> add237::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                           // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);                          // xfader -> gain1::Gain
		pma15.getWrappedObject().getParameter().connectT(0, xfader);           // pma15 -> xfader::Value
		peak14.getParameter().connectT(0, pma15);                              // peak14 -> pma15::Value
		global_cable238.getWrappedObject().getParameter().connectT(0, add238); // global_cable238 -> add238::Value
		global_cable239.getWrappedObject().getParameter().connectT(0, add239); // global_cable239 -> add239::Value
		global_cable240.getWrappedObject().getParameter().connectT(0, add240); // global_cable240 -> add240::Value
		global_cable241.getWrappedObject().getParameter().connectT(0, add241); // global_cable241 -> add241::Value
		global_cable242.getWrappedObject().getParameter().connectT(0, add242); // global_cable242 -> add242::Value
		global_cable243.getWrappedObject().getParameter().connectT(0, add243); // global_cable243 -> add243::Value
		global_cable244.getWrappedObject().getParameter().connectT(0, add244); // global_cable244 -> add244::Value
		global_cable245.getWrappedObject().getParameter().connectT(0, add245); // global_cable245 -> add245::Value
		global_cable246.getWrappedObject().getParameter().connectT(0, add246); // global_cable246 -> add246::Value
		global_cable247.getWrappedObject().getParameter().connectT(0, add247); // global_cable247 -> add247::Value
		global_cable248.getWrappedObject().getParameter().connectT(0, add248); // global_cable248 -> add248::Value
		global_cable249.getWrappedObject().getParameter().connectT(0, add249); // global_cable249 -> add249::Value
		global_cable250.getWrappedObject().getParameter().connectT(0, add250); // global_cable250 -> add250::Value
		global_cable251.getWrappedObject().getParameter().connectT(0, add251); // global_cable251 -> add251::Value
		global_cable252.getWrappedObject().getParameter().connectT(0, add252); // global_cable252 -> add252::Value
		global_cable253.getWrappedObject().getParameter().connectT(0, add253); // global_cable253 -> add253::Value
		clone_cable.getWrappedObject().getParameter().connectT(0, res2);       // clone_cable -> res2::DELAY
		pma16.getWrappedObject().getParameter().connectT(0, svf);              // pma16 -> svf::Frequency
		pma16.getWrappedObject().getParameter().connectT(1, svf5);             // pma16 -> svf5::Frequency
		pma16.getWrappedObject().getParameter().connectT(2, svf4);             // pma16 -> svf4::Frequency
		pma16.getWrappedObject().getParameter().connectT(3, svf3);             // pma16 -> svf3::Frequency
		pma16.getWrappedObject().getParameter().connectT(4, svf_eq1);          // pma16 -> svf_eq1::Frequency
		pma16.getWrappedObject().getParameter().connectT(5, svf_eq2);          // pma16 -> svf_eq2::Frequency
		pma16.getWrappedObject().getParameter().connectT(6, jdelay_cubic);     // pma16 -> jdelay_cubic::DelayTime
		pma16.getWrappedObject().getParameter().connectT(7, reverb);           // pma16 -> reverb::Size
		pma16.getWrappedObject().getParameter().connectT(8, allpass);          // pma16 -> allpass::Frequency
		pma16.getWrappedObject().getParameter().connectT(9, clone_cable);      // pma16 -> clone_cable::Value
		peak15.getParameter().connectT(0, pma16);                              // peak15 -> pma16::Value
		global_cable270.getWrappedObject().getParameter().connectT(0, add270); // global_cable270 -> add270::Value
		global_cable271.getWrappedObject().getParameter().connectT(0, add271); // global_cable271 -> add271::Value
		global_cable272.getWrappedObject().getParameter().connectT(0, add272); // global_cable272 -> add272::Value
		global_cable273.getWrappedObject().getParameter().connectT(0, add273); // global_cable273 -> add273::Value
		global_cable274.getWrappedObject().getParameter().connectT(0, add274); // global_cable274 -> add274::Value
		global_cable275.getWrappedObject().getParameter().connectT(0, add275); // global_cable275 -> add275::Value
		global_cable276.getWrappedObject().getParameter().connectT(0, add276); // global_cable276 -> add276::Value
		global_cable277.getWrappedObject().getParameter().connectT(0, add277); // global_cable277 -> add277::Value
		global_cable278.getWrappedObject().getParameter().connectT(0, add278); // global_cable278 -> add278::Value
		global_cable279.getWrappedObject().getParameter().connectT(0, add279); // global_cable279 -> add279::Value
		global_cable280.getWrappedObject().getParameter().connectT(0, add280); // global_cable280 -> add280::Value
		global_cable281.getWrappedObject().getParameter().connectT(0, add281); // global_cable281 -> add281::Value
		global_cable282.getWrappedObject().getParameter().connectT(0, add282); // global_cable282 -> add282::Value
		global_cable283.getWrappedObject().getParameter().connectT(0, add283); // global_cable283 -> add283::Value
		global_cable284.getWrappedObject().getParameter().connectT(0, add284); // global_cable284 -> add284::Value
		global_cable285.getWrappedObject().getParameter().connectT(0, add285); // global_cable285 -> add285::Value
		clone_cable1.getWrappedObject().getParameter().connectT(0, res2);      // clone_cable1 -> res2::lp
		pma18.getWrappedObject().getParameter().connectT(0, one_pole5);        // pma18 -> one_pole5::Frequency
		pma18.getWrappedObject().getParameter().connectT(1, clone_cable1);     // pma18 -> clone_cable1::Value
		pma18.getWrappedObject().getParameter().connectT(2, allpass);          // pma18 -> allpass::Q
		pma18.getWrappedObject().getParameter().connectT(3, svf);              // pma18 -> svf::Q
		pma18.getWrappedObject().getParameter().connectT(4, svf1);             // pma18 -> svf1::Q
		pma18.getWrappedObject().getParameter().connectT(5, svf5);             // pma18 -> svf5::Q
		pma18.getWrappedObject().getParameter().connectT(6, svf7);             // pma18 -> svf7::Q
		pma18.getWrappedObject().getParameter().connectT(7, svf4);             // pma18 -> svf4::Q
		pma18.getWrappedObject().getParameter().connectT(8, svf8);             // pma18 -> svf8::Q
		pma18.getWrappedObject().getParameter().connectT(9, svf3);             // pma18 -> svf3::Q
		pma18.getWrappedObject().getParameter().connectT(10, svf9);            // pma18 -> svf9::Q
		pma18.getWrappedObject().getParameter().connectT(11, svf_eq1);         // pma18 -> svf_eq1::Q
		pma18.getWrappedObject().getParameter().connectT(12, svf_eq2);         // pma18 -> svf_eq2::Q
		pma18.getWrappedObject().getParameter().connectT(13, reverb);          // pma18 -> reverb::Damping
		peak17.getParameter().connectT(0, pma18);                              // peak17 -> pma18::Value
		global_cable302.getWrappedObject().getParameter().connectT(0, add302); // global_cable302 -> add302::Value
		global_cable303.getWrappedObject().getParameter().connectT(0, add303); // global_cable303 -> add303::Value
		global_cable304.getWrappedObject().getParameter().connectT(0, add304); // global_cable304 -> add304::Value
		global_cable305.getWrappedObject().getParameter().connectT(0, add305); // global_cable305 -> add305::Value
		global_cable306.getWrappedObject().getParameter().connectT(0, add306); // global_cable306 -> add306::Value
		global_cable307.getWrappedObject().getParameter().connectT(0, add307); // global_cable307 -> add307::Value
		global_cable308.getWrappedObject().getParameter().connectT(0, add308); // global_cable308 -> add308::Value
		global_cable309.getWrappedObject().getParameter().connectT(0, add309); // global_cable309 -> add309::Value
		global_cable310.getWrappedObject().getParameter().connectT(0, add310); // global_cable310 -> add310::Value
		global_cable311.getWrappedObject().getParameter().connectT(0, add311); // global_cable311 -> add311::Value
		global_cable312.getWrappedObject().getParameter().connectT(0, add312); // global_cable312 -> add312::Value
		global_cable313.getWrappedObject().getParameter().connectT(0, add313); // global_cable313 -> add313::Value
		global_cable314.getWrappedObject().getParameter().connectT(0, add314); // global_cable314 -> add314::Value
		global_cable315.getWrappedObject().getParameter().connectT(0, add315); // global_cable315 -> add315::Value
		global_cable316.getWrappedObject().getParameter().connectT(0, add316); // global_cable316 -> add316::Value
		global_cable317.getWrappedObject().getParameter().connectT(0, add317); // global_cable317 -> add317::Value
		clone_cable2.getWrappedObject().getParameter().connectT(0, res2);      // clone_cable2 -> res2::FB
		pma20.getWrappedObject().getParameter().connectT(0, svf1);             // pma20 -> svf1::Frequency
		pma20.getWrappedObject().getParameter().connectT(1, svf7);             // pma20 -> svf7::Frequency
		pma20.getWrappedObject().getParameter().connectT(2, svf8);             // pma20 -> svf8::Frequency
		pma20.getWrappedObject().getParameter().connectT(3, svf9);             // pma20 -> svf9::Frequency
		pma20.getWrappedObject().getParameter().connectT(4, svf_eq1);          // pma20 -> svf_eq1::Gain
		pma20.getWrappedObject().getParameter().connectT(5, svf_eq2);          // pma20 -> svf_eq2::Gain
		pma20.getWrappedObject().getParameter().connectT(6, one_pole4);        // pma20 -> one_pole4::Frequency
		pma20.getWrappedObject().getParameter().connectT(7, receive);          // pma20 -> receive::Feedback
		pma20.getWrappedObject().getParameter().connectT(8, clone_cable2);     // pma20 -> clone_cable2::Value
		pma20.getWrappedObject().getParameter().connectT(9, reverb);           // pma20 -> reverb::Width
		peak19.getParameter().connectT(0, pma20);                              // peak19 -> pma20::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch14::Index is automated
		
		global_cable222.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add222::Value is automated
		
		global_cable223.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add223::Value is automated
		
		global_cable224.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add224::Value is automated
		
		global_cable225.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add225::Value is automated
		
		global_cable226.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add226::Value is automated
		
		global_cable227.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add227::Value is automated
		
		global_cable228.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add228::Value is automated
		
		global_cable229.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add229::Value is automated
		
		global_cable230.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add230::Value is automated
		
		global_cable231.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add231::Value is automated
		
		global_cable232.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add232::Value is automated
		
		global_cable233.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add233::Value is automated
		
		global_cable254.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add234::Value is automated
		
		global_cable235.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add235::Value is automated
		
		global_cable236.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add236::Value is automated
		
		global_cable237.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add237::Value is automated
		
		clear14.setParameterT(0, 0.); // math::clear::Value
		
		; // pma15::Value is automated
		; // pma15::Multiply is automated
		; // pma15::Add is automated
		
		; // branch15::Index is automated
		
		global_cable238.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add238::Value is automated
		
		global_cable239.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add239::Value is automated
		
		global_cable240.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add240::Value is automated
		
		global_cable241.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add241::Value is automated
		
		global_cable242.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add242::Value is automated
		
		global_cable243.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add243::Value is automated
		
		global_cable244.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add244::Value is automated
		
		global_cable245.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add245::Value is automated
		
		global_cable246.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add246::Value is automated
		
		global_cable247.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add247::Value is automated
		
		global_cable248.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add248::Value is automated
		
		global_cable249.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add249::Value is automated
		
		global_cable250.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add250::Value is automated
		
		global_cable251.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add251::Value is automated
		
		global_cable252.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add252::Value is automated
		
		global_cable253.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add253::Value is automated
		
		clear15.setParameterT(0, 0.); // math::clear::Value
		
		; // pma16::Value is automated
		; // pma16::Multiply is automated
		; // pma16::Add is automated
		
		; // branch17::Index is automated
		
		global_cable270.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add270::Value is automated
		
		global_cable271.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add271::Value is automated
		
		global_cable272.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add272::Value is automated
		
		global_cable273.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add273::Value is automated
		
		global_cable274.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add274::Value is automated
		
		global_cable275.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add275::Value is automated
		
		global_cable276.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add276::Value is automated
		
		global_cable277.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add277::Value is automated
		
		global_cable278.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add278::Value is automated
		
		global_cable279.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add279::Value is automated
		
		global_cable280.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add280::Value is automated
		
		global_cable281.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add281::Value is automated
		
		global_cable282.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add282::Value is automated
		
		global_cable283.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add283::Value is automated
		
		global_cable284.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add284::Value is automated
		
		global_cable285.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add285::Value is automated
		
		clear17.setParameterT(0, 0.); // math::clear::Value
		
		; // pma18::Value is automated
		; // pma18::Multiply is automated
		; // pma18::Add is automated
		
		; // branch19::Index is automated
		
		global_cable302.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add302::Value is automated
		
		global_cable303.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add303::Value is automated
		
		global_cable304.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add304::Value is automated
		
		global_cable305.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add305::Value is automated
		
		global_cable306.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add306::Value is automated
		
		global_cable307.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add307::Value is automated
		
		global_cable308.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add308::Value is automated
		
		global_cable309.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add309::Value is automated
		
		global_cable310.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add310::Value is automated
		
		global_cable311.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add311::Value is automated
		
		global_cable312.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add312::Value is automated
		
		global_cable313.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add313::Value is automated
		
		global_cable314.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add314::Value is automated
		
		global_cable315.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add315::Value is automated
		
		global_cable316.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add316::Value is automated
		
		global_cable317.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add317::Value is automated
		
		clear19.setParameterT(0, 0.); // math::clear::Value
		
		; // pma20::Value is automated
		; // pma20::Multiply is automated
		; // pma20::Add is automated
		
		; // xfader::Value is automated
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 10.3);  // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // branch1::Index is automated
		
		;                           // svf::Frequency is automated
		;                           // svf::Q is automated
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);   // filters::svf::Mode
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf1.setParameterT(4, 1.);   // filters::svf::Mode
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf5::Frequency is automated
		;                            // svf5::Q is automated
		svf5.setParameterT(2, 0.);   // filters::svf::Gain
		svf5.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf5.setParameterT(4, 1.);   // filters::svf::Mode
		svf5.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf7::Frequency is automated
		;                            // svf7::Q is automated
		svf7.setParameterT(2, 0.);   // filters::svf::Gain
		svf7.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf7.setParameterT(4, 0.);   // filters::svf::Mode
		svf7.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf4::Frequency is automated
		;                            // svf4::Q is automated
		svf4.setParameterT(2, 0.);   // filters::svf::Gain
		svf4.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf4.setParameterT(4, 2.);   // filters::svf::Mode
		svf4.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf8::Frequency is automated
		;                            // svf8::Q is automated
		svf8.setParameterT(2, 0.);   // filters::svf::Gain
		svf8.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf8.setParameterT(4, 0.);   // filters::svf::Mode
		svf8.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf3::Frequency is automated
		;                            // svf3::Q is automated
		svf3.setParameterT(2, 0.);   // filters::svf::Gain
		svf3.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf3.setParameterT(4, 2.);   // filters::svf::Mode
		svf3.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf9::Frequency is automated
		;                            // svf9::Q is automated
		svf9.setParameterT(2, 0.);   // filters::svf::Gain
		svf9.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf9.setParameterT(4, 1.);   // filters::svf::Mode
		svf9.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                               // svf_eq1::Frequency is automated
		;                               // svf_eq1::Q is automated
		;                               // svf_eq1::Gain is automated
		svf_eq1.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq1.setParameterT(4, 2.);   // filters::svf_eq::Mode
		svf_eq1.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		;                               // svf_eq2::Frequency is automated
		;                               // svf_eq2::Q is automated
		;                               // svf_eq2::Gain is automated
		svf_eq2.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq2.setParameterT(4, 3.);   // filters::svf_eq::Mode
		svf_eq2.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		;                               // allpass::Frequency is automated
		;                               // allpass::Q is automated
		allpass.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		;                                 // one_pole4::Frequency is automated
		one_pole4.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole4.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole4.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole4.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole4.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // receive::Feedback is automated
		
		jdelay_cubic.setParameterT(0, 1000.); // jdsp::jdelay_cubic::Limit
		;                                     // jdelay_cubic::DelayTime is automated
		
		;                                 // one_pole5::Frequency is automated
		one_pole5.setParameterT(1, 9.9);  // filters::one_pole::Q
		one_pole5.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole5.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole5.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole5.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		one_pole3.setParameterT(0, 50.);  // filters::one_pole::Frequency
		one_pole3.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole3.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole3.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole3.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole3.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                 // clone_cable::NumClones is deactivated
		;                                 // clone_cable::Value is automated
		clone_cable.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable1::NumClones is deactivated
		;                                  // clone_cable1::Value is automated
		clone_cable1.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable2::NumClones is deactivated
		;                                  // clone_cable2::Value is automated
		clone_cable2.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone.setParameterT(0, 8.); // container::clone::NumClones
		clone.setParameterT(1, 2.); // container::clone::SplitSignal
		
		;                           // res2::FB is automated
		;                           // res2::DELAY is automated
		res2.setParameterT(2, 0.2); // project::res2::HASS
		;                           // res2::lp is automated
		
		gain2.setParameterT(0, -17.); // core::gain::Gain
		gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		gain2.setParameterT(2, 0.);   // core::gain::ResetValue
		
		one_pole2.setParameterT(0, 50.);  // filters::one_pole::Frequency
		one_pole2.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole2.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole2.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole2.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole2.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // reverb::Damping is automated
		; // reverb::Width is automated
		; // reverb::Size is automated
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 11.6);  // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.204059);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 6.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 10.);
		this->setParameterT(10, 0.921365);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 1.);
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
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable222_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable223_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable224_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable225_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable226_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable227_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable228_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable229_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable230_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable231_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable232_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable233_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable254_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable235_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable236_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable237_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable238_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable239_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable240_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable241_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable242_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable243_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable244_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable245_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable246_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable247_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable248_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable249_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable250_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable251_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable252_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable253_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable270_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable271_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable272_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable273_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable274_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable275_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable276_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable277_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable278_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable279_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable280_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable281_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable282_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable283_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable284_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable285_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable302_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable303_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable304_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable305_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable306_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable307_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable308_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable309_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable310_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // sn_fin_impl::global_cable311_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable312_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable313_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable314_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable315_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable316_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // sn_fin_impl::global_cable317_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index); // sn_fin_impl::peak14_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index); // sn_fin_impl::peak15_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).setExternalData(b, index); // sn_fin_impl::peak17_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(1).setExternalData(b, index); // sn_fin_impl::peak19_t<NV>
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
using sn_fin = wrap::node<sn_fin_impl::instance<NV>>;
}


