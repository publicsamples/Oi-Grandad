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

namespace Process_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable240_t_index = runtime_target::indexers::fix_hash<1120565314>;

template <int NV>
using global_cable240_t = routing::global_cable<global_cable240_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain268_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable240_t<NV>>, 
                                    math::add<NV>>;
using global_cable241_t_index = runtime_target::indexers::fix_hash<1120565315>;

template <int NV>
using global_cable241_t = routing::global_cable<global_cable241_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain269_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable241_t<NV>>, 
                                    math::add<NV>>;
using global_cable242_t_index = runtime_target::indexers::fix_hash<1120565316>;

template <int NV>
using global_cable242_t = routing::global_cable<global_cable242_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain270_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable242_t<NV>>, 
                                    math::add<NV>>;
using global_cable243_t_index = runtime_target::indexers::fix_hash<1120565317>;

template <int NV>
using global_cable243_t = routing::global_cable<global_cable243_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain271_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable243_t<NV>>, 
                                    math::add<NV>>;
using global_cable244_t_index = runtime_target::indexers::fix_hash<1120565318>;

template <int NV>
using global_cable244_t = routing::global_cable<global_cable244_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain272_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable244_t<NV>>, 
                                    math::add<NV>>;
using global_cable245_t_index = runtime_target::indexers::fix_hash<1120565319>;

template <int NV>
using global_cable245_t = routing::global_cable<global_cable245_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain273_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable245_t<NV>>, 
                                    math::add<NV>>;
using global_cable246_t_index = runtime_target::indexers::fix_hash<1120565320>;

template <int NV>
using global_cable246_t = routing::global_cable<global_cable246_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain274_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable246_t<NV>>, 
                                    math::add<NV>>;
using global_cable247_t_index = runtime_target::indexers::fix_hash<1120565321>;

template <int NV>
using global_cable247_t = routing::global_cable<global_cable247_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain275_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable247_t<NV>>, 
                                    math::add<NV>>;
using global_cable248_t_index = runtime_target::indexers::fix_hash<1120565322>;

template <int NV>
using global_cable248_t = routing::global_cable<global_cable248_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain276_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable248_t<NV>>, 
                                    math::add<NV>>;
using global_cable249_t_index = runtime_target::indexers::fix_hash<377786414>;

template <int NV>
using global_cable249_t = routing::global_cable<global_cable249_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain277_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable249_t<NV>>, 
                                    math::add<NV>>;
using global_cable250_t_index = runtime_target::indexers::fix_hash<377786415>;

template <int NV>
using global_cable250_t = routing::global_cable<global_cable250_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain278_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable250_t<NV>>, 
                                    math::add<NV>>;
using global_cable251_t_index = runtime_target::indexers::fix_hash<377786416>;

template <int NV>
using global_cable251_t = routing::global_cable<global_cable251_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain279_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable251_t<NV>>, 
                                    math::add<NV>>;
using global_cable252_t_index = runtime_target::indexers::fix_hash<377786417>;

template <int NV>
using global_cable252_t = routing::global_cable<global_cable252_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain280_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable252_t<NV>>, 
                                    math::add<NV>>;
using global_cable253_t_index = runtime_target::indexers::fix_hash<377786418>;

template <int NV>
using global_cable253_t = routing::global_cable<global_cable253_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain281_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable253_t<NV>>, 
                                    math::add<NV>>;
using global_cable254_t_index = runtime_target::indexers::fix_hash<377786419>;

template <int NV>
using global_cable254_t = routing::global_cable<global_cable254_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain282_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable254_t<NV>>, 
                                    math::add<NV>>;
using global_cable255_t_index = runtime_target::indexers::fix_hash<377786420>;

template <int NV>
using global_cable255_t = routing::global_cable<global_cable255_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain283_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable255_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch17_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain268_t<NV>>, 
                                     chain269_t<NV>, 
                                     chain270_t<NV>, 
                                     chain271_t<NV>, 
                                     chain272_t<NV>, 
                                     chain273_t<NV>, 
                                     chain274_t<NV>, 
                                     chain275_t<NV>, 
                                     chain276_t<NV>, 
                                     chain277_t<NV>, 
                                     chain278_t<NV>, 
                                     chain279_t<NV>, 
                                     chain280_t<NV>, 
                                     chain281_t<NV>, 
                                     chain282_t<NV>, 
                                     chain283_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma26_mod_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma26_mod_0 = parameter::from0To1<filters::svf<NV>, 
                                        0, 
                                        pma26_mod_0Range>;

template <int NV> using pma26_mod_1 = pma26_mod_0<NV>;

template <int NV> using pma26_mod_2 = pma26_mod_0<NV>;

template <int NV>
using pma26_mod = parameter::chain<ranges::Identity, 
                                   pma26_mod_0<NV>, 
                                   pma26_mod_1<NV>, 
                                   pma26_mod_2<NV>>;

template <int NV>
using pma26_t = control::pma<NV, pma26_mod<NV>>;
template <int NV>
using peak17_t = wrap::mod<parameter::plain<pma26_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

namespace chain267_t_parameters
{
}

template <int NV>
using chain267_t = container::chain<parameter::plain<Process_impl::branch17_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch17_t<NV>, 
                                    peak17_t<NV>, 
                                    pma26_t<NV>, 
                                    math::clear<NV>>;
using global_cable320_t_index = global_cable240_t_index;

template <int NV>
using global_cable320_t = routing::global_cable<global_cable320_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain353_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable320_t<NV>>, 
                                    math::add<NV>>;
using global_cable321_t_index = global_cable241_t_index;

template <int NV>
using global_cable321_t = routing::global_cable<global_cable321_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain354_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable321_t<NV>>, 
                                    math::add<NV>>;
using global_cable322_t_index = global_cable242_t_index;

template <int NV>
using global_cable322_t = routing::global_cable<global_cable322_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain355_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable322_t<NV>>, 
                                    math::add<NV>>;
using global_cable323_t_index = global_cable243_t_index;

template <int NV>
using global_cable323_t = routing::global_cable<global_cable323_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain356_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable323_t<NV>>, 
                                    math::add<NV>>;
using global_cable324_t_index = global_cable244_t_index;

template <int NV>
using global_cable324_t = routing::global_cable<global_cable324_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain357_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable324_t<NV>>, 
                                    math::add<NV>>;
using global_cable325_t_index = global_cable245_t_index;

template <int NV>
using global_cable325_t = routing::global_cable<global_cable325_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain358_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable325_t<NV>>, 
                                    math::add<NV>>;
using global_cable326_t_index = global_cable246_t_index;

template <int NV>
using global_cable326_t = routing::global_cable<global_cable326_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain359_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable326_t<NV>>, 
                                    math::add<NV>>;
using global_cable327_t_index = global_cable247_t_index;

template <int NV>
using global_cable327_t = routing::global_cable<global_cable327_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain360_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable327_t<NV>>, 
                                    math::add<NV>>;
using global_cable328_t_index = global_cable248_t_index;

template <int NV>
using global_cable328_t = routing::global_cable<global_cable328_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain361_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable328_t<NV>>, 
                                    math::add<NV>>;
using global_cable329_t_index = global_cable249_t_index;

template <int NV>
using global_cable329_t = routing::global_cable<global_cable329_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain362_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable329_t<NV>>, 
                                    math::add<NV>>;
using global_cable330_t_index = global_cable250_t_index;

template <int NV>
using global_cable330_t = routing::global_cable<global_cable330_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain363_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable330_t<NV>>, 
                                    math::add<NV>>;
using global_cable331_t_index = global_cable251_t_index;

template <int NV>
using global_cable331_t = routing::global_cable<global_cable331_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain364_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable331_t<NV>>, 
                                    math::add<NV>>;
using global_cable332_t_index = global_cable252_t_index;

template <int NV>
using global_cable332_t = routing::global_cable<global_cable332_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain365_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable332_t<NV>>, 
                                    math::add<NV>>;
using global_cable333_t_index = global_cable253_t_index;

template <int NV>
using global_cable333_t = routing::global_cable<global_cable333_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain366_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable333_t<NV>>, 
                                    math::add<NV>>;
using global_cable334_t_index = global_cable254_t_index;

template <int NV>
using global_cable334_t = routing::global_cable<global_cable334_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain367_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable334_t<NV>>, 
                                    math::add<NV>>;
using global_cable335_t_index = global_cable255_t_index;

template <int NV>
using global_cable335_t = routing::global_cable<global_cable335_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain368_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable335_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch22_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain353_t<NV>>, 
                                     chain354_t<NV>, 
                                     chain355_t<NV>, 
                                     chain356_t<NV>, 
                                     chain357_t<NV>, 
                                     chain358_t<NV>, 
                                     chain359_t<NV>, 
                                     chain360_t<NV>, 
                                     chain361_t<NV>, 
                                     chain362_t<NV>, 
                                     chain363_t<NV>, 
                                     chain364_t<NV>, 
                                     chain365_t<NV>, 
                                     chain366_t<NV>, 
                                     chain367_t<NV>, 
                                     chain368_t<NV>>;

template <int NV>
using converter3_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<wrap::no_process<core::fix_delay>, 0>, 
                                        parameter::plain<wrap::no_process<jdsp::jdelay<NV>>, 1>, 
                                        parameter::plain<jdsp::jdelay_thiran<NV>, 1>>;

template <int NV>
using converter3_t = control::converter<converter3_mod<NV>, 
                                        conversion_logic::ms2freq>;

template <int NV>
using converter2_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<converter3_t<NV>, 0>, 
                                        parameter::plain<filters::allpass<NV>, 0>>;

template <int NV>
using converter2_t = control::converter<converter2_mod<NV>, 
                                        conversion_logic::midi2freq>;
template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<converter2_t<NV>, 0>>;
DECLARE_PARAMETER_RANGE_STEP(pma31_mod_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma31_mod_0 = parameter::from0To1<control::tempo_sync<NV>, 
                                        0, 
                                        pma31_mod_0Range>;

DECLARE_PARAMETER_RANGE(pma31_mod_1Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using pma31_mod_1 = parameter::from0To1<pma_t<NV>, 
                                        2, 
                                        pma31_mod_1Range>;

template <int NV>
using pma31_mod = parameter::chain<ranges::Identity, 
                                   pma31_mod_0<NV>, 
                                   pma31_mod_1<NV>>;

template <int NV>
using pma31_t = control::pma<NV, pma31_mod<NV>>;
template <int NV>
using peak22_t = wrap::mod<parameter::plain<pma31_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

namespace chain352_t_parameters
{
}

template <int NV>
using chain352_t = container::chain<parameter::plain<Process_impl::branch22_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch22_t<NV>, 
                                    peak22_t<NV>, 
                                    pma31_t<NV>, 
                                    math::clear<NV>>;
using global_cable304_t_index = global_cable240_t_index;

template <int NV>
using global_cable304_t = routing::global_cable<global_cable304_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain336_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable304_t<NV>>, 
                                    math::add<NV>>;
using global_cable305_t_index = global_cable241_t_index;

template <int NV>
using global_cable305_t = routing::global_cable<global_cable305_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain337_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable305_t<NV>>, 
                                    math::add<NV>>;
using global_cable306_t_index = global_cable242_t_index;

template <int NV>
using global_cable306_t = routing::global_cable<global_cable306_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain338_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable306_t<NV>>, 
                                    math::add<NV>>;
using global_cable307_t_index = global_cable243_t_index;

template <int NV>
using global_cable307_t = routing::global_cable<global_cable307_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain339_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable307_t<NV>>, 
                                    math::add<NV>>;
using global_cable308_t_index = global_cable244_t_index;

template <int NV>
using global_cable308_t = routing::global_cable<global_cable308_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain340_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable308_t<NV>>, 
                                    math::add<NV>>;
using global_cable309_t_index = global_cable245_t_index;

template <int NV>
using global_cable309_t = routing::global_cable<global_cable309_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain341_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable309_t<NV>>, 
                                    math::add<NV>>;
using global_cable310_t_index = global_cable246_t_index;

template <int NV>
using global_cable310_t = routing::global_cable<global_cable310_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain342_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable310_t<NV>>, 
                                    math::add<NV>>;
using global_cable311_t_index = global_cable247_t_index;

template <int NV>
using global_cable311_t = routing::global_cable<global_cable311_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain343_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable311_t<NV>>, 
                                    math::add<NV>>;
using global_cable312_t_index = global_cable248_t_index;

template <int NV>
using global_cable312_t = routing::global_cable<global_cable312_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain344_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable312_t<NV>>, 
                                    math::add<NV>>;
using global_cable313_t_index = global_cable249_t_index;

template <int NV>
using global_cable313_t = routing::global_cable<global_cable313_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain345_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable313_t<NV>>, 
                                    math::add<NV>>;
using global_cable314_t_index = global_cable250_t_index;

template <int NV>
using global_cable314_t = routing::global_cable<global_cable314_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain346_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable314_t<NV>>, 
                                    math::add<NV>>;
using global_cable315_t_index = global_cable251_t_index;

template <int NV>
using global_cable315_t = routing::global_cable<global_cable315_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain347_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable315_t<NV>>, 
                                    math::add<NV>>;
using global_cable316_t_index = global_cable252_t_index;

template <int NV>
using global_cable316_t = routing::global_cable<global_cable316_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain348_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable316_t<NV>>, 
                                    math::add<NV>>;
using global_cable317_t_index = global_cable253_t_index;

template <int NV>
using global_cable317_t = routing::global_cable<global_cable317_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain349_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable317_t<NV>>, 
                                    math::add<NV>>;
using global_cable318_t_index = global_cable254_t_index;

template <int NV>
using global_cable318_t = routing::global_cable<global_cable318_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain350_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable318_t<NV>>, 
                                    math::add<NV>>;
using global_cable319_t_index = global_cable255_t_index;

template <int NV>
using global_cable319_t = routing::global_cable<global_cable319_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain351_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable319_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch21_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain336_t<NV>>, 
                                     chain337_t<NV>, 
                                     chain338_t<NV>, 
                                     chain339_t<NV>, 
                                     chain340_t<NV>, 
                                     chain341_t<NV>, 
                                     chain342_t<NV>, 
                                     chain343_t<NV>, 
                                     chain344_t<NV>, 
                                     chain345_t<NV>, 
                                     chain346_t<NV>, 
                                     chain347_t<NV>, 
                                     chain348_t<NV>, 
                                     chain349_t<NV>, 
                                     chain350_t<NV>, 
                                     chain351_t<NV>>;

template <int NV>
using peak21_mod = parameter::plain<control::pma_unscaled<NV, parameter::empty>, 
                                    0>;
template <int NV>
using peak21_t = wrap::mod<peak21_mod<NV>, 
                           wrap::no_data<core::peak>>;

namespace chain335_t_parameters
{
}

template <int NV>
using chain335_t = container::chain<parameter::plain<Process_impl::branch21_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch21_t<NV>, 
                                    peak21_t<NV>, 
                                    control::pma_unscaled<NV, parameter::empty>, 
                                    math::clear<NV>>;
using global_cable272_t_index = global_cable240_t_index;

template <int NV>
using global_cable272_t = routing::global_cable<global_cable272_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain302_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable272_t<NV>>, 
                                    math::add<NV>>;
using global_cable273_t_index = global_cable241_t_index;

template <int NV>
using global_cable273_t = routing::global_cable<global_cable273_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain303_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable273_t<NV>>, 
                                    math::add<NV>>;
using global_cable274_t_index = global_cable242_t_index;

template <int NV>
using global_cable274_t = routing::global_cable<global_cable274_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain304_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable274_t<NV>>, 
                                    math::add<NV>>;
using global_cable275_t_index = global_cable243_t_index;

template <int NV>
using global_cable275_t = routing::global_cable<global_cable275_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain305_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable275_t<NV>>, 
                                    math::add<NV>>;
using global_cable276_t_index = global_cable244_t_index;

template <int NV>
using global_cable276_t = routing::global_cable<global_cable276_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain306_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable276_t<NV>>, 
                                    math::add<NV>>;
using global_cable277_t_index = global_cable245_t_index;

template <int NV>
using global_cable277_t = routing::global_cable<global_cable277_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain307_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable277_t<NV>>, 
                                    math::add<NV>>;
using global_cable278_t_index = global_cable246_t_index;

template <int NV>
using global_cable278_t = routing::global_cable<global_cable278_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain308_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable278_t<NV>>, 
                                    math::add<NV>>;
using global_cable279_t_index = global_cable247_t_index;

template <int NV>
using global_cable279_t = routing::global_cable<global_cable279_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain309_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable279_t<NV>>, 
                                    math::add<NV>>;
using global_cable280_t_index = global_cable248_t_index;

template <int NV>
using global_cable280_t = routing::global_cable<global_cable280_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain310_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable280_t<NV>>, 
                                    math::add<NV>>;
using global_cable281_t_index = global_cable249_t_index;

template <int NV>
using global_cable281_t = routing::global_cable<global_cable281_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain311_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable281_t<NV>>, 
                                    math::add<NV>>;
using global_cable282_t_index = global_cable250_t_index;

template <int NV>
using global_cable282_t = routing::global_cable<global_cable282_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain312_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable282_t<NV>>, 
                                    math::add<NV>>;
using global_cable283_t_index = global_cable251_t_index;

template <int NV>
using global_cable283_t = routing::global_cable<global_cable283_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain313_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable283_t<NV>>, 
                                    math::add<NV>>;
using global_cable284_t_index = global_cable252_t_index;

template <int NV>
using global_cable284_t = routing::global_cable<global_cable284_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain314_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable284_t<NV>>, 
                                    math::add<NV>>;
using global_cable285_t_index = global_cable253_t_index;

template <int NV>
using global_cable285_t = routing::global_cable<global_cable285_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain315_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable285_t<NV>>, 
                                    math::add<NV>>;
using global_cable286_t_index = global_cable254_t_index;

template <int NV>
using global_cable286_t = routing::global_cable<global_cable286_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain316_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable286_t<NV>>, 
                                    math::add<NV>>;
using global_cable287_t_index = global_cable255_t_index;

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
using pma28_mod_0 = parameter::from0To1<filters::one_pole<NV>, 
                                        0, 
                                        pma26_mod_0Range>;

template <int NV> using pma28_mod_1 = pma28_mod_0<NV>;

template <int NV> using pma28_mod_2 = pma28_mod_0<NV>;

template <int NV>
using pma28_mod = parameter::chain<ranges::Identity, 
                                   pma28_mod_0<NV>, 
                                   pma28_mod_1<NV>, 
                                   pma28_mod_2<NV>>;

template <int NV>
using pma28_t = control::pma<NV, pma28_mod<NV>>;
template <int NV>
using peak19_t = wrap::mod<parameter::plain<pma28_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

namespace chain301_t_parameters
{
}

template <int NV>
using chain301_t = container::chain<parameter::plain<Process_impl::branch19_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch19_t<NV>, 
                                    peak19_t<NV>, 
                                    pma28_t<NV>, 
                                    math::clear<NV>>;
using global_cable336_t_index = global_cable240_t_index;

template <int NV>
using global_cable336_t = routing::global_cable<global_cable336_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain370_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable336_t<NV>>, 
                                    math::add<NV>>;
using global_cable337_t_index = global_cable241_t_index;

template <int NV>
using global_cable337_t = routing::global_cable<global_cable337_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain371_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable337_t<NV>>, 
                                    math::add<NV>>;
using global_cable338_t_index = global_cable242_t_index;

template <int NV>
using global_cable338_t = routing::global_cable<global_cable338_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain372_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable338_t<NV>>, 
                                    math::add<NV>>;
using global_cable339_t_index = global_cable243_t_index;

template <int NV>
using global_cable339_t = routing::global_cable<global_cable339_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain373_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable339_t<NV>>, 
                                    math::add<NV>>;
using global_cable340_t_index = global_cable244_t_index;

template <int NV>
using global_cable340_t = routing::global_cable<global_cable340_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain374_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable340_t<NV>>, 
                                    math::add<NV>>;
using global_cable341_t_index = global_cable245_t_index;

template <int NV>
using global_cable341_t = routing::global_cable<global_cable341_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain375_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable341_t<NV>>, 
                                    math::add<NV>>;
using global_cable342_t_index = global_cable246_t_index;

template <int NV>
using global_cable342_t = routing::global_cable<global_cable342_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain376_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable342_t<NV>>, 
                                    math::add<NV>>;
using global_cable343_t_index = global_cable247_t_index;

template <int NV>
using global_cable343_t = routing::global_cable<global_cable343_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain377_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable343_t<NV>>, 
                                    math::add<NV>>;
using global_cable344_t_index = global_cable248_t_index;

template <int NV>
using global_cable344_t = routing::global_cable<global_cable344_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain378_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable344_t<NV>>, 
                                    math::add<NV>>;
using global_cable345_t_index = global_cable249_t_index;

template <int NV>
using global_cable345_t = routing::global_cable<global_cable345_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain379_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable345_t<NV>>, 
                                    math::add<NV>>;
using global_cable346_t_index = global_cable250_t_index;

template <int NV>
using global_cable346_t = routing::global_cable<global_cable346_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain380_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable346_t<NV>>, 
                                    math::add<NV>>;
using global_cable347_t_index = global_cable251_t_index;

template <int NV>
using global_cable347_t = routing::global_cable<global_cable347_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain381_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable347_t<NV>>, 
                                    math::add<NV>>;
using global_cable348_t_index = global_cable252_t_index;

template <int NV>
using global_cable348_t = routing::global_cable<global_cable348_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain382_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable348_t<NV>>, 
                                    math::add<NV>>;
using global_cable349_t_index = global_cable253_t_index;

template <int NV>
using global_cable349_t = routing::global_cable<global_cable349_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain383_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable349_t<NV>>, 
                                    math::add<NV>>;
using global_cable350_t_index = global_cable254_t_index;

template <int NV>
using global_cable350_t = routing::global_cable<global_cable350_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain384_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable350_t<NV>>, 
                                    math::add<NV>>;
using global_cable351_t_index = global_cable255_t_index;

template <int NV>
using global_cable351_t = routing::global_cable<global_cable351_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain385_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable351_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch23_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain370_t<NV>>, 
                                     chain371_t<NV>, 
                                     chain372_t<NV>, 
                                     chain373_t<NV>, 
                                     chain374_t<NV>, 
                                     chain375_t<NV>, 
                                     chain376_t<NV>, 
                                     chain377_t<NV>, 
                                     chain378_t<NV>, 
                                     chain379_t<NV>, 
                                     chain380_t<NV>, 
                                     chain381_t<NV>, 
                                     chain382_t<NV>, 
                                     chain383_t<NV>, 
                                     chain384_t<NV>, 
                                     chain385_t<NV>>;

DECLARE_PARAMETER_RANGE(pma32_modRange, 
                        -1., 
                        1.);

template <int NV>
using pma32_mod = parameter::from0To1<jdsp::jpanner<NV>, 
                                      0, 
                                      pma32_modRange>;

template <int NV>
using pma32_t = control::pma<NV, pma32_mod<NV>>;
template <int NV>
using peak23_t = wrap::mod<parameter::plain<pma32_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

namespace chain369_t_parameters
{
}

template <int NV>
using chain369_t = container::chain<parameter::plain<Process_impl::branch23_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch23_t<NV>, 
                                    peak23_t<NV>, 
                                    pma32_t<NV>, 
                                    math::clear<NV>>;
using global_cable352_t_index = global_cable240_t_index;

template <int NV>
using global_cable352_t = routing::global_cable<global_cable352_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain387_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable352_t<NV>>, 
                                    math::add<NV>>;
using global_cable353_t_index = global_cable241_t_index;

template <int NV>
using global_cable353_t = routing::global_cable<global_cable353_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain388_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable353_t<NV>>, 
                                    math::add<NV>>;
using global_cable354_t_index = global_cable242_t_index;

template <int NV>
using global_cable354_t = routing::global_cable<global_cable354_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain389_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable354_t<NV>>, 
                                    math::add<NV>>;
using global_cable355_t_index = global_cable243_t_index;

template <int NV>
using global_cable355_t = routing::global_cable<global_cable355_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain390_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable355_t<NV>>, 
                                    math::add<NV>>;
using global_cable356_t_index = global_cable244_t_index;

template <int NV>
using global_cable356_t = routing::global_cable<global_cable356_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain391_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable356_t<NV>>, 
                                    math::add<NV>>;
using global_cable357_t_index = global_cable245_t_index;

template <int NV>
using global_cable357_t = routing::global_cable<global_cable357_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain392_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable357_t<NV>>, 
                                    math::add<NV>>;
using global_cable358_t_index = global_cable246_t_index;

template <int NV>
using global_cable358_t = routing::global_cable<global_cable358_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain393_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable358_t<NV>>, 
                                    math::add<NV>>;
using global_cable359_t_index = global_cable247_t_index;

template <int NV>
using global_cable359_t = routing::global_cable<global_cable359_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain394_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable359_t<NV>>, 
                                    math::add<NV>>;
using global_cable360_t_index = global_cable248_t_index;

template <int NV>
using global_cable360_t = routing::global_cable<global_cable360_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain395_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable360_t<NV>>, 
                                    math::add<NV>>;
using global_cable361_t_index = global_cable249_t_index;

template <int NV>
using global_cable361_t = routing::global_cable<global_cable361_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain396_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable361_t<NV>>, 
                                    math::add<NV>>;
using global_cable362_t_index = global_cable250_t_index;

template <int NV>
using global_cable362_t = routing::global_cable<global_cable362_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain397_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable362_t<NV>>, 
                                    math::add<NV>>;
using global_cable363_t_index = global_cable251_t_index;

template <int NV>
using global_cable363_t = routing::global_cable<global_cable363_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain398_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable363_t<NV>>, 
                                    math::add<NV>>;
using global_cable364_t_index = global_cable252_t_index;

template <int NV>
using global_cable364_t = routing::global_cable<global_cable364_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain399_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable364_t<NV>>, 
                                    math::add<NV>>;
using global_cable365_t_index = global_cable253_t_index;

template <int NV>
using global_cable365_t = routing::global_cable<global_cable365_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain400_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable365_t<NV>>, 
                                    math::add<NV>>;
using global_cable366_t_index = global_cable254_t_index;

template <int NV>
using global_cable366_t = routing::global_cable<global_cable366_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain401_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable366_t<NV>>, 
                                    math::add<NV>>;
using global_cable367_t_index = global_cable255_t_index;

template <int NV>
using global_cable367_t = routing::global_cable<global_cable367_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain402_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable367_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch24_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain387_t<NV>>, 
                                     chain388_t<NV>, 
                                     chain389_t<NV>, 
                                     chain390_t<NV>, 
                                     chain391_t<NV>, 
                                     chain392_t<NV>, 
                                     chain393_t<NV>, 
                                     chain394_t<NV>, 
                                     chain395_t<NV>, 
                                     chain396_t<NV>, 
                                     chain397_t<NV>, 
                                     chain398_t<NV>, 
                                     chain399_t<NV>, 
                                     chain400_t<NV>, 
                                     chain401_t<NV>, 
                                     chain402_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma33_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using pma33_mod = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      pma33_modRange>;

template <int NV>
using pma33_t = control::pma<NV, pma33_mod<NV>>;
template <int NV>
using peak24_t = wrap::mod<parameter::plain<pma33_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

namespace chain386_t_parameters
{
}

template <int NV>
using chain386_t = container::chain<parameter::plain<Process_impl::branch24_t<NV>, 0>, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    branch24_t<NV>, 
                                    peak24_t<NV>, 
                                    pma33_t<NV>, 
                                    math::clear<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain267_t<NV>>, 
                                  chain352_t<NV>, 
                                  chain335_t<NV>, 
                                  chain301_t<NV>, 
                                  chain369_t<NV>, 
                                  chain386_t<NV>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split5_t<NV>>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;

template <int NV> using xfader_c0 = pma33_mod<NV>;

template <int NV> using xfader_c1 = pma33_mod<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, filters::svf<NV>>, 
                                   filters::svf<NV>, 
                                   filters::svf<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, branch_t<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain2_t<NV>>, 
                                 chain3_t<NV>>;

template <int NV> using xfader1_c0 = pma33_mod<NV>;

template <int NV> using xfader1_c1 = pma33_mod<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

template <int NV> using chain5_t = chain2_t<NV>;

template <int NV>
using midi2_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using midichain2_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, midi2_t<NV>>>;

template <int NV>
using midichain2_t = wrap::event<midichain2_t_<NV>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, pma_t<NV>>, 
                                      converter2_t<NV>, 
                                      converter3_t<NV>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;
using stereo_cable = cable::block<2>;

template <int NV>
using smoothed_parameter_unscaled1_t = wrap::mod<parameter::plain<core::fix_delay, 0>, 
                                                 control::smoothed_parameter_unscaled<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, control::tempo_sync<NV>>, 
                                  routing::receive<stereo_cable>, 
                                  smoothed_parameter_unscaled1_t<NV>, 
                                  core::fix_delay, 
                                  filters::one_pole<NV>, 
                                  routing::send<stereo_cable>>;
using stereo_frame_cable = cable::frame<2>;

template <int NV>
using frame1_block_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, routing::receive<stereo_frame_cable>>, 
                                         jdsp::jdelay_thiran<NV>, 
                                         wrap::no_process<jdsp::jdelay<NV>>, 
                                         wrap::no_process<core::fix_delay>, 
                                         filters::one_pole<NV>, 
                                         routing::send<stereo_frame_cable>>;

template <int NV>
using frame1_block_t = wrap::frame<2, frame1_block_t_<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, frame1_block_t<NV>>, 
                                  filters::one_pole<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::allpass<NV>>, 
                                  filters::one_pole<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain1_t<NV>>, 
                                    chain8_t<NV>, 
                                    chain9_t<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, midichain2_t<NV>>, 
                                  modchain2_t<NV>, 
                                  branch1_t<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain6_t<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain5_t<NV>>, 
                                  chain7_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader1_t<NV>>, 
                                  split1_t<NV>>;

using ahdsr_multimod = parameter::list<parameter::empty, parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, modchain3_t<NV>>, 
                                 xfader_t<NV>, 
                                 split_t<NV>, 
                                 chain4_t<NV>, 
                                 jdsp::jpanner<NV>, 
                                 ahdsr_t<NV>, 
                                 core::gain<NV>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<2, chain_t<NV>>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, midichain_t<NV>>>;

namespace Process_t_parameters
{
// Parameter list for Process_impl::Process_t ------------------------------------------------------

template <int NV>
using cut = parameter::from0To1<Process_impl::pma26_t<NV>, 
                                2, 
                                Process_impl::pma31_mod_1Range>;

template <int NV>
using q = parameter::chain<ranges::Identity, 
                           parameter::plain<filters::svf<NV>, 1>, 
                           parameter::plain<filters::svf<NV>, 1>, 
                           parameter::plain<filters::svf<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(cutsrc_InputRange, 
                             1., 
                             16., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(cutsrc_0Range, 
                             0., 
                             15., 
                             1.);

template <int NV>
using cutsrc_0 = parameter::from0To1<Process_impl::chain267_t<NV>, 
                                     0, 
                                     cutsrc_0Range>;

template <int NV>
using cutsrc = parameter::chain<cutsrc_InputRange, cutsrc_0<NV>>;

DECLARE_PARAMETER_RANGE(deltempo_InputRange, 
                        1., 
                        18.);
template <int NV>
using deltempo_0 = parameter::from0To1<Process_impl::pma31_t<NV>, 
                                       2, 
                                       Process_impl::pma31_mod_1Range>;

template <int NV>
using deltempo = parameter::chain<deltempo_InputRange, deltempo_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(deldivRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using deldiv = parameter::from0To1<control::tempo_sync<NV>, 
                                   1, 
                                   deldivRange>;

DECLARE_PARAMETER_RANGE(delmod_InputRange, 
                        -1., 
                        1.);
template <int NV>
using delmod_0 = parameter::from0To1<Process_impl::pma31_t<NV>, 
                                     1, 
                                     Process_impl::pma32_modRange>;

DECLARE_PARAMETER_RANGE(delmod_1Range, 
                        -36., 
                        36.);

template <int NV>
using delmod_1 = parameter::from0To1<control::pma_unscaled<NV, parameter::empty>, 
                                     1, 
                                     delmod_1Range>;

template <int NV>
using delmod = parameter::chain<delmod_InputRange, 
                                delmod_0<NV>, 
                                delmod_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(delsrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using delsrc_0 = parameter::from0To1<Process_impl::chain335_t<NV>, 
                                     0, 
                                     cutsrc_0Range>;

template <int NV>
using delsrc_1 = parameter::from0To1<Process_impl::chain352_t<NV>, 
                                     0, 
                                     cutsrc_0Range>;

template <int NV>
using delsrc = parameter::chain<delsrc_InputRange, 
                                delsrc_0<NV>, 
                                delsrc_1<NV>>;

template <int NV>
using DelLP = parameter::from0To1<Process_impl::pma28_t<NV>, 
                                  2, 
                                  Process_impl::pma31_mod_1Range>;

DECLARE_PARAMETER_RANGE_STEP(LpSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using LpSrc_0 = parameter::from0To1<Process_impl::chain301_t<NV>, 
                                    0, 
                                    cutsrc_0Range>;

template <int NV>
using LpSrc = parameter::chain<LpSrc_InputRange, LpSrc_0<NV>>;

template <int NV>
using Pan = parameter::from0To1<Process_impl::pma32_t<NV>, 
                                2, 
                                Process_impl::pma31_mod_1Range>;

DECLARE_PARAMETER_RANGE_STEP(PanSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using PanSrc_0 = parameter::from0To1<Process_impl::chain369_t<NV>, 
                                     0, 
                                     cutsrc_0Range>;

template <int NV>
using PanSrc = parameter::chain<PanSrc_InputRange, PanSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(feed_2Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using feed_2 = parameter::from0To1<filters::allpass<NV>, 
                                   1, 
                                   feed_2Range>;

template <int NV>
using feed = parameter::chain<ranges::Identity, 
                              parameter::plain<routing::receive<stereo_cable>, 0>, 
                              parameter::plain<routing::receive<stereo_frame_cable>, 0>, 
                              feed_2<NV>>;

DECLARE_PARAMETER_RANGE_STEP(fmode_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(fmode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using fmode_0 = parameter::from0To1<Process_impl::branch_t<NV>, 
                                    0, 
                                    fmode_0Range>;

template <int NV>
using fmode = parameter::chain<fmode_InputRange, fmode_0<NV>>;

template <int NV>
using d = parameter::chain<ranges::Identity, 
                           parameter::plain<Process_impl::ahdsr_t<NV>, 3>, 
                           parameter::plain<Process_impl::ahdsr_t<NV>, 5>>;

DECLARE_PARAMETER_RANGE_SKEW(gain_InputRange, 
                             -100., 
                             0., 
                             5.42227);
template <int NV>
using gain_0 = parameter::from0To1<Process_impl::pma33_t<NV>, 
                                   2, 
                                   Process_impl::pma31_mod_1Range>;

template <int NV>
using gain = parameter::chain<gain_InputRange, gain_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(delaymode_InputRange, 
                             1., 
                             3., 
                             1.);
template <int NV>
using delaymode_0 = parameter::from0To1<Process_impl::branch1_t<NV>, 
                                        0, 
                                        fmode_0Range>;

template <int NV>
using delaymode = parameter::chain<delaymode_InputRange, delaymode_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(GainSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using GainSrc_0 = parameter::from0To1<Process_impl::chain386_t<NV>, 
                                      0, 
                                      cutsrc_0Range>;

template <int NV>
using GainSrc = parameter::chain<GainSrc_InputRange, GainSrc_0<NV>>;

template <int NV>
using mix = parameter::plain<Process_impl::xfader_t<NV>, 
                             0>;
template <int NV>
using cutmod = parameter::plain<Process_impl::pma26_t<NV>, 
                                1>;
template <int NV>
using delmix = parameter::plain<Process_impl::xfader1_t<NV>, 
                                0>;
template <int NV>
using pitch = parameter::plain<control::pma_unscaled<NV, parameter::empty>, 
                               2>;
template <int NV>
using LpMod = parameter::plain<Process_impl::pma28_t<NV>, 
                               1>;
template <int NV>
using PanMod = parameter::plain<Process_impl::pma32_t<NV>, 
                                1>;
template <int NV>
using smooth = parameter::plain<Process_impl::smoothed_parameter_unscaled1_t<NV>, 
                                1>;
template <int NV>
using a = parameter::plain<Process_impl::ahdsr_t<NV>, 
                           0>;
template <int NV>
using sr = parameter::plain<Process_impl::ahdsr_t<NV>, 
                            4>;
template <int NV>
using GainMod = parameter::plain<Process_impl::pma33_t<NV>, 
                                 1>;
template <int NV>
using GainSmooth = parameter::plain<core::gain<NV>, 1>;
template <int NV>
using GainReset = parameter::plain<core::gain<NV>, 2>;
template <int NV>
using Process_t_plist = parameter::list<cut<NV>, 
                                        q<NV>, 
                                        mix<NV>, 
                                        cutmod<NV>, 
                                        cutsrc<NV>, 
                                        deltempo<NV>, 
                                        deldiv<NV>, 
                                        delmix<NV>, 
                                        pitch<NV>, 
                                        delmod<NV>, 
                                        delsrc<NV>, 
                                        DelLP<NV>, 
                                        LpMod<NV>, 
                                        LpSrc<NV>, 
                                        Pan<NV>, 
                                        PanMod<NV>, 
                                        PanSrc<NV>, 
                                        smooth<NV>, 
                                        feed<NV>, 
                                        fmode<NV>, 
                                        a<NV>, 
                                        d<NV>, 
                                        sr<NV>, 
                                        gain<NV>, 
                                        delaymode<NV>, 
                                        GainMod<NV>, 
                                        GainSrc<NV>, 
                                        GainSmooth<NV>, 
                                        GainReset<NV>>;
}

template <int NV>
using Process_t_ = container::chain<Process_t_parameters::Process_t_plist<NV>, 
                                    wrap::fix<2, chain20_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Process_impl::Process_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Process);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(454)
		{
			0x005B, 0x0000, 0x6300, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x643F, 0x28A1, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x0071, 0x999A, 0x3E99, 0x6666, 0x411E, 0x008B, 0x4041, 
            0x8918, 0x3E87, 0x0000, 0x0000, 0x025B, 0x0000, 0x6D00, 0x7869, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0003, 0x0000, 0x7563, 0x6D74, 0x646F, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0004, 0x0000, 0x7563, 0x7374, 0x6372, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0005, 0x0000, 0x6564, 0x746C, 0x6D65, 
            0x6F70, 0x0000, 0x8000, 0x003F, 0x9000, 0x0041, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 0x6564, 0x646C, 
            0x7669, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 0x0000, 0x6564, 0x6D6C, 
            0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0008, 0x0000, 0x6970, 0x6374, 
            0x0068, 0x0000, 0xC1C0, 0x0000, 0x41C0, 0x1BD3, 0xC14A, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x095B, 0x0000, 0x6400, 0x6C65, 0x6F6D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0A5B, 0x0000, 0x6400, 0x6C65, 0x7273, 
            0x0063, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0B5B, 0x0000, 0x4400, 0x6C65, 0x504C, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000C, 0x0000, 0x704C, 0x6F4D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0D5B, 0x0000, 0x4C00, 0x5370, 0x6372, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x000E, 0x0000, 0x6150, 0x006E, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0F5B, 0x0000, 0x5000, 0x6E61, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0xA6F5, 0x3F72, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x105B, 0x0000, 0x5000, 0x6E61, 0x7253, 0x0063, 0x0000, 0x3F80, 
            0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x115B, 0x0000, 0x7300, 0x6F6D, 0x746F, 0x0068, 0xCCCD, 0x3DCC, 
            0x0000, 0x447A, 0x3333, 0x440F, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 
            0x125B, 0x0000, 0x6600, 0x6565, 0x0064, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x135B, 
            0x0000, 0x6600, 0x6F6D, 0x6564, 0x0000, 0x8000, 0x003F, 0x4000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0014, 
            0x0000, 0x0061, 0x0000, 0x0000, 0x4000, 0x461C, 0x1333, 0x443B, 
            0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x155B, 0x0000, 0x6400, 0x0000, 
            0x0000, 0x0000, 0x1C40, 0x0046, 0x5CF0, 0x7245, 0x4A6A, 0xCD3E, 
            0xCCCC, 0x5B3D, 0x0016, 0x0000, 0x7273, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0017, 0x0000, 0x6167, 0x6E69, 0x0000, 0xC800, 0x00C2, 0x0000, 
            0xFF00, 0x57FF, 0x3EC1, 0xAD83, 0xCD40, 0xCCCC, 0x5B3D, 0x0018, 
            0x0000, 0x6564, 0x616C, 0x6D79, 0x646F, 0x0065, 0x0000, 0x3F80, 
            0x0000, 0x4040, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x195B, 0x0000, 0x4700, 0x6961, 0x4D6E, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x001A, 0x0000, 0x6147, 0x6E69, 0x7253, 0x0063, 0x0000, 
            0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x1B5B, 0x0000, 0x4700, 0x6961, 0x536E, 0x6F6D, 0x746F, 
            0x0068, 0x0000, 0x0000, 0x0000, 0x447A, 0x0000, 0x0000, 0x209B, 
            0x3E9A, 0xCCCD, 0x3DCC, 0x1C5B, 0x0000, 0x4700, 0x6961, 0x526E, 
            0x7365, 0x7465, 0x0000, 0xC800, 0x00C2, 0x0000, 0x0000, 0x0000, 
            0x3E00, 0xAD83, 0xCD40, 0xCCCC, 0x003D, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain20 = this->getT(0);                                                       // Process_impl::chain20_t<NV>
		auto& midichain = this->getT(0).getT(0);                                             // Process_impl::midichain_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0);                                         // Process_impl::chain_t<NV>
		auto& modchain3 = this->getT(0).getT(0).getT(0).getT(0);                             // Process_impl::modchain3_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                        // Process_impl::split5_t<NV>
		auto& chain267 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);              // Process_impl::chain267_t<NV>
		auto& clear29 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);       // math::clear<NV>
		auto& branch17 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);      // Process_impl::branch17_t<NV>
		auto& chain268 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain268_t<NV>
                         getT(0).getT(0).getT(1).getT(0);
		auto& global_cable240 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable240_t<NV>
                                getT(0).getT(0).getT(1).getT(0).
                                getT(0);
		auto& add234 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(1);
		auto& chain269 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain269_t<NV>
                         getT(0).getT(0).getT(1).getT(1);
		auto& global_cable241 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable241_t<NV>
                                getT(0).getT(0).getT(1).getT(1).
                                getT(0);
		auto& add235 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(1);
		auto& chain270 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain270_t<NV>
                         getT(0).getT(0).getT(1).getT(2);
		auto& global_cable242 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable242_t<NV>
                                getT(0).getT(0).getT(1).getT(2).
                                getT(0);
		auto& add236 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(1);
		auto& chain271 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain271_t<NV>
                         getT(0).getT(0).getT(1).getT(3);
		auto& global_cable243 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable243_t<NV>
                                getT(0).getT(0).getT(1).getT(3).
                                getT(0);
		auto& add237 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(3).
                       getT(1);
		auto& chain272 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain272_t<NV>
                         getT(0).getT(0).getT(1).getT(4);
		auto& global_cable244 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable244_t<NV>
                                getT(0).getT(0).getT(1).getT(4).
                                getT(0);
		auto& add238 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(4).
                       getT(1);
		auto& chain273 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain273_t<NV>
                         getT(0).getT(0).getT(1).getT(5);
		auto& global_cable245 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable245_t<NV>
                                getT(0).getT(0).getT(1).getT(5).
                                getT(0);
		auto& add239 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(5).
                       getT(1);
		auto& chain274 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain274_t<NV>
                         getT(0).getT(0).getT(1).getT(6);
		auto& global_cable246 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable246_t<NV>
                                getT(0).getT(0).getT(1).getT(6).
                                getT(0);
		auto& add240 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(6).
                       getT(1);
		auto& chain275 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain275_t<NV>
                         getT(0).getT(0).getT(1).getT(7);
		auto& global_cable247 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable247_t<NV>
                                getT(0).getT(0).getT(1).getT(7).
                                getT(0);
		auto& add241 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(7).
                       getT(1);
		auto& chain276 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain276_t<NV>
                         getT(0).getT(0).getT(1).getT(8);
		auto& global_cable248 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable248_t<NV>
                                getT(0).getT(0).getT(1).getT(8).
                                getT(0);
		auto& add242 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(8).
                       getT(1);
		auto& chain277 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain277_t<NV>
                         getT(0).getT(0).getT(1).getT(9);
		auto& global_cable249 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable249_t<NV>
                                getT(0).getT(0).getT(1).getT(9).
                                getT(0);
		auto& add243 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(9).
                       getT(1);
		auto& chain278 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain278_t<NV>
                         getT(0).getT(0).getT(1).getT(10);
		auto& global_cable250 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable250_t<NV>
                                getT(0).getT(0).getT(1).getT(10).
                                getT(0);
		auto& add244 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(10).
                       getT(1);
		auto& chain279 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain279_t<NV>
                         getT(0).getT(0).getT(1).getT(11);
		auto& global_cable251 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable251_t<NV>
                                getT(0).getT(0).getT(1).getT(11).
                                getT(0);
		auto& add245 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(11).
                       getT(1);
		auto& chain280 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain280_t<NV>
                         getT(0).getT(0).getT(1).getT(12);
		auto& global_cable252 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable252_t<NV>
                                getT(0).getT(0).getT(1).getT(12).
                                getT(0);
		auto& add246 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(12).
                       getT(1);
		auto& chain281 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain281_t<NV>
                         getT(0).getT(0).getT(1).getT(13);
		auto& global_cable253 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable253_t<NV>
                                getT(0).getT(0).getT(1).getT(13).
                                getT(0);
		auto& add247 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(13).
                       getT(1);
		auto& chain282 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain282_t<NV>
                         getT(0).getT(0).getT(1).getT(14);
		auto& global_cable254 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable254_t<NV>
                                getT(0).getT(0).getT(1).getT(14).
                                getT(0);
		auto& add248 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(14).
                       getT(1);
		auto& chain283 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain283_t<NV>
                         getT(0).getT(0).getT(1).getT(15);
		auto& global_cable255 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable255_t<NV>
                                getT(0).getT(0).getT(1).getT(15).
                                getT(0);
		auto& add249 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(15).
                       getT(1);
		auto& peak17 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);        // Process_impl::peak17_t<NV>
		auto& pma26 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(3);         // Process_impl::pma26_t<NV>
		auto& clear30 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(4);       // math::clear<NV>
		auto& chain352 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);              // Process_impl::chain352_t<NV>
		auto& clear39 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);       // math::clear<NV>
		auto& branch22 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);      // Process_impl::branch22_t<NV>
		auto& chain353 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain353_t<NV>
                         getT(0).getT(1).getT(1).getT(0);
		auto& global_cable320 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable320_t<NV>
                                getT(0).getT(1).getT(1).getT(0).
                                getT(0);
		auto& add314 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(0).
                       getT(1);
		auto& chain354 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain354_t<NV>
                         getT(0).getT(1).getT(1).getT(1);
		auto& global_cable321 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable321_t<NV>
                                getT(0).getT(1).getT(1).getT(1).
                                getT(0);
		auto& add315 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(1).
                       getT(1);
		auto& chain355 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain355_t<NV>
                         getT(0).getT(1).getT(1).getT(2);
		auto& global_cable322 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable322_t<NV>
                                getT(0).getT(1).getT(1).getT(2).
                                getT(0);
		auto& add316 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(2).
                       getT(1);
		auto& chain356 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain356_t<NV>
                         getT(0).getT(1).getT(1).getT(3);
		auto& global_cable323 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable323_t<NV>
                                getT(0).getT(1).getT(1).getT(3).
                                getT(0);
		auto& add317 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(3).
                       getT(1);
		auto& chain357 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain357_t<NV>
                         getT(0).getT(1).getT(1).getT(4);
		auto& global_cable324 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable324_t<NV>
                                getT(0).getT(1).getT(1).getT(4).
                                getT(0);
		auto& add318 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(4).
                       getT(1);
		auto& chain358 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain358_t<NV>
                         getT(0).getT(1).getT(1).getT(5);
		auto& global_cable325 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable325_t<NV>
                                getT(0).getT(1).getT(1).getT(5).
                                getT(0);
		auto& add319 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(5).
                       getT(1);
		auto& chain359 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain359_t<NV>
                         getT(0).getT(1).getT(1).getT(6);
		auto& global_cable326 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable326_t<NV>
                                getT(0).getT(1).getT(1).getT(6).
                                getT(0);
		auto& add320 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(6).
                       getT(1);
		auto& chain360 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain360_t<NV>
                         getT(0).getT(1).getT(1).getT(7);
		auto& global_cable327 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable327_t<NV>
                                getT(0).getT(1).getT(1).getT(7).
                                getT(0);
		auto& add321 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(7).
                       getT(1);
		auto& chain361 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain361_t<NV>
                         getT(0).getT(1).getT(1).getT(8);
		auto& global_cable328 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable328_t<NV>
                                getT(0).getT(1).getT(1).getT(8).
                                getT(0);
		auto& add322 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(8).
                       getT(1);
		auto& chain362 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain362_t<NV>
                         getT(0).getT(1).getT(1).getT(9);
		auto& global_cable329 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable329_t<NV>
                                getT(0).getT(1).getT(1).getT(9).
                                getT(0);
		auto& add323 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(9).
                       getT(1);
		auto& chain363 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain363_t<NV>
                         getT(0).getT(1).getT(1).getT(10);
		auto& global_cable330 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable330_t<NV>
                                getT(0).getT(1).getT(1).getT(10).
                                getT(0);
		auto& add324 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(10).
                       getT(1);
		auto& chain364 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain364_t<NV>
                         getT(0).getT(1).getT(1).getT(11);
		auto& global_cable331 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable331_t<NV>
                                getT(0).getT(1).getT(1).getT(11).
                                getT(0);
		auto& add325 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(11).
                       getT(1);
		auto& chain365 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain365_t<NV>
                         getT(0).getT(1).getT(1).getT(12);
		auto& global_cable332 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable332_t<NV>
                                getT(0).getT(1).getT(1).getT(12).
                                getT(0);
		auto& add326 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(12).
                       getT(1);
		auto& chain366 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain366_t<NV>
                         getT(0).getT(1).getT(1).getT(13);
		auto& global_cable333 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable333_t<NV>
                                getT(0).getT(1).getT(1).getT(13).
                                getT(0);
		auto& add327 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(13).
                       getT(1);
		auto& chain367 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain367_t<NV>
                         getT(0).getT(1).getT(1).getT(14);
		auto& global_cable334 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable334_t<NV>
                                getT(0).getT(1).getT(1).getT(14).
                                getT(0);
		auto& add328 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(14).
                       getT(1);
		auto& chain368 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain368_t<NV>
                         getT(0).getT(1).getT(1).getT(15);
		auto& global_cable335 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable335_t<NV>
                                getT(0).getT(1).getT(1).getT(15).
                                getT(0);
		auto& add329 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(15).
                       getT(1);
		auto& peak22 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);        // Process_impl::peak22_t<NV>
		auto& pma31 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);         // Process_impl::pma31_t<NV>
		auto& clear40 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(4);       // math::clear<NV>
		auto& chain335 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);              // Process_impl::chain335_t<NV>
		auto& clear37 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(0);       // math::clear<NV>
		auto& branch21 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(1);      // Process_impl::branch21_t<NV>
		auto& chain336 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain336_t<NV>
                         getT(0).getT(2).getT(1).getT(0);
		auto& global_cable304 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable304_t<NV>
                                getT(0).getT(2).getT(1).getT(0).
                                getT(0);
		auto& add298 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(0).
                       getT(1);
		auto& chain337 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain337_t<NV>
                         getT(0).getT(2).getT(1).getT(1);
		auto& global_cable305 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable305_t<NV>
                                getT(0).getT(2).getT(1).getT(1).
                                getT(0);
		auto& add299 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(1).
                       getT(1);
		auto& chain338 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain338_t<NV>
                         getT(0).getT(2).getT(1).getT(2);
		auto& global_cable306 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable306_t<NV>
                                getT(0).getT(2).getT(1).getT(2).
                                getT(0);
		auto& add300 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(2).
                       getT(1);
		auto& chain339 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain339_t<NV>
                         getT(0).getT(2).getT(1).getT(3);
		auto& global_cable307 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable307_t<NV>
                                getT(0).getT(2).getT(1).getT(3).
                                getT(0);
		auto& add301 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(3).
                       getT(1);
		auto& chain340 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain340_t<NV>
                         getT(0).getT(2).getT(1).getT(4);
		auto& global_cable308 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable308_t<NV>
                                getT(0).getT(2).getT(1).getT(4).
                                getT(0);
		auto& add302 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(4).
                       getT(1);
		auto& chain341 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain341_t<NV>
                         getT(0).getT(2).getT(1).getT(5);
		auto& global_cable309 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable309_t<NV>
                                getT(0).getT(2).getT(1).getT(5).
                                getT(0);
		auto& add303 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(5).
                       getT(1);
		auto& chain342 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain342_t<NV>
                         getT(0).getT(2).getT(1).getT(6);
		auto& global_cable310 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable310_t<NV>
                                getT(0).getT(2).getT(1).getT(6).
                                getT(0);
		auto& add304 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(6).
                       getT(1);
		auto& chain343 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain343_t<NV>
                         getT(0).getT(2).getT(1).getT(7);
		auto& global_cable311 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable311_t<NV>
                                getT(0).getT(2).getT(1).getT(7).
                                getT(0);
		auto& add305 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(7).
                       getT(1);
		auto& chain344 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain344_t<NV>
                         getT(0).getT(2).getT(1).getT(8);
		auto& global_cable312 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable312_t<NV>
                                getT(0).getT(2).getT(1).getT(8).
                                getT(0);
		auto& add306 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(8).
                       getT(1);
		auto& chain345 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain345_t<NV>
                         getT(0).getT(2).getT(1).getT(9);
		auto& global_cable313 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable313_t<NV>
                                getT(0).getT(2).getT(1).getT(9).
                                getT(0);
		auto& add307 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(9).
                       getT(1);
		auto& chain346 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain346_t<NV>
                         getT(0).getT(2).getT(1).getT(10);
		auto& global_cable314 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable314_t<NV>
                                getT(0).getT(2).getT(1).getT(10).
                                getT(0);
		auto& add308 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(10).
                       getT(1);
		auto& chain347 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain347_t<NV>
                         getT(0).getT(2).getT(1).getT(11);
		auto& global_cable315 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable315_t<NV>
                                getT(0).getT(2).getT(1).getT(11).
                                getT(0);
		auto& add309 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(11).
                       getT(1);
		auto& chain348 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain348_t<NV>
                         getT(0).getT(2).getT(1).getT(12);
		auto& global_cable316 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable316_t<NV>
                                getT(0).getT(2).getT(1).getT(12).
                                getT(0);
		auto& add310 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(12).
                       getT(1);
		auto& chain349 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain349_t<NV>
                         getT(0).getT(2).getT(1).getT(13);
		auto& global_cable317 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable317_t<NV>
                                getT(0).getT(2).getT(1).getT(13).
                                getT(0);
		auto& add311 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(13).
                       getT(1);
		auto& chain350 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain350_t<NV>
                         getT(0).getT(2).getT(1).getT(14);
		auto& global_cable318 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable318_t<NV>
                                getT(0).getT(2).getT(1).getT(14).
                                getT(0);
		auto& add312 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(14).
                       getT(1);
		auto& chain351 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain351_t<NV>
                         getT(0).getT(2).getT(1).getT(15);
		auto& global_cable319 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable319_t<NV>
                                getT(0).getT(2).getT(1).getT(15).
                                getT(0);
		auto& add313 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(15).
                       getT(1);
		auto& peak21 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(2);        // Process_impl::peak21_t<NV>
		auto& pma_unscaled = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(3);  // control::pma_unscaled<NV, parameter::empty>
		auto& clear38 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(4);       // math::clear<NV>
		auto& chain301 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3);              // Process_impl::chain301_t<NV>
		auto& clear33 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(0);       // math::clear<NV>
		auto& branch19 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(1);      // Process_impl::branch19_t<NV>
		auto& chain302 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain302_t<NV>
                         getT(0).getT(3).getT(1).getT(0);
		auto& global_cable272 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable272_t<NV>
                                getT(0).getT(3).getT(1).getT(0).
                                getT(0);
		auto& add266 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(0).
                       getT(1);
		auto& chain303 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain303_t<NV>
                         getT(0).getT(3).getT(1).getT(1);
		auto& global_cable273 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable273_t<NV>
                                getT(0).getT(3).getT(1).getT(1).
                                getT(0);
		auto& add267 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(1).
                       getT(1);
		auto& chain304 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain304_t<NV>
                         getT(0).getT(3).getT(1).getT(2);
		auto& global_cable274 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable274_t<NV>
                                getT(0).getT(3).getT(1).getT(2).
                                getT(0);
		auto& add268 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(2).
                       getT(1);
		auto& chain305 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain305_t<NV>
                         getT(0).getT(3).getT(1).getT(3);
		auto& global_cable275 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable275_t<NV>
                                getT(0).getT(3).getT(1).getT(3).
                                getT(0);
		auto& add269 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(3).
                       getT(1);
		auto& chain306 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain306_t<NV>
                         getT(0).getT(3).getT(1).getT(4);
		auto& global_cable276 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable276_t<NV>
                                getT(0).getT(3).getT(1).getT(4).
                                getT(0);
		auto& add270 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(4).
                       getT(1);
		auto& chain307 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain307_t<NV>
                         getT(0).getT(3).getT(1).getT(5);
		auto& global_cable277 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable277_t<NV>
                                getT(0).getT(3).getT(1).getT(5).
                                getT(0);
		auto& add271 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(5).
                       getT(1);
		auto& chain308 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain308_t<NV>
                         getT(0).getT(3).getT(1).getT(6);
		auto& global_cable278 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable278_t<NV>
                                getT(0).getT(3).getT(1).getT(6).
                                getT(0);
		auto& add272 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(6).
                       getT(1);
		auto& chain309 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain309_t<NV>
                         getT(0).getT(3).getT(1).getT(7);
		auto& global_cable279 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable279_t<NV>
                                getT(0).getT(3).getT(1).getT(7).
                                getT(0);
		auto& add273 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(7).
                       getT(1);
		auto& chain310 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain310_t<NV>
                         getT(0).getT(3).getT(1).getT(8);
		auto& global_cable280 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable280_t<NV>
                                getT(0).getT(3).getT(1).getT(8).
                                getT(0);
		auto& add274 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(8).
                       getT(1);
		auto& chain311 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain311_t<NV>
                         getT(0).getT(3).getT(1).getT(9);
		auto& global_cable281 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable281_t<NV>
                                getT(0).getT(3).getT(1).getT(9).
                                getT(0);
		auto& add275 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(9).
                       getT(1);
		auto& chain312 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain312_t<NV>
                         getT(0).getT(3).getT(1).getT(10);
		auto& global_cable282 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable282_t<NV>
                                getT(0).getT(3).getT(1).getT(10).
                                getT(0);
		auto& add276 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(10).
                       getT(1);
		auto& chain313 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain313_t<NV>
                         getT(0).getT(3).getT(1).getT(11);
		auto& global_cable283 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable283_t<NV>
                                getT(0).getT(3).getT(1).getT(11).
                                getT(0);
		auto& add277 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(11).
                       getT(1);
		auto& chain314 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain314_t<NV>
                         getT(0).getT(3).getT(1).getT(12);
		auto& global_cable284 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable284_t<NV>
                                getT(0).getT(3).getT(1).getT(12).
                                getT(0);
		auto& add278 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(12).
                       getT(1);
		auto& chain315 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain315_t<NV>
                         getT(0).getT(3).getT(1).getT(13);
		auto& global_cable285 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable285_t<NV>
                                getT(0).getT(3).getT(1).getT(13).
                                getT(0);
		auto& add279 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(13).
                       getT(1);
		auto& chain316 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain316_t<NV>
                         getT(0).getT(3).getT(1).getT(14);
		auto& global_cable286 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable286_t<NV>
                                getT(0).getT(3).getT(1).getT(14).
                                getT(0);
		auto& add280 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(14).
                       getT(1);
		auto& chain317 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain317_t<NV>
                         getT(0).getT(3).getT(1).getT(15);
		auto& global_cable287 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable287_t<NV>
                                getT(0).getT(3).getT(1).getT(15).
                                getT(0);
		auto& add281 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(15).
                       getT(1);
		auto& peak19 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(2);        // Process_impl::peak19_t<NV>
		auto& pma28 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(3);         // Process_impl::pma28_t<NV>
		auto& clear34 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(4);       // math::clear<NV>
		auto& chain369 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4);              // Process_impl::chain369_t<NV>
		auto& clear41 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(0);       // math::clear<NV>
		auto& branch23 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(1);      // Process_impl::branch23_t<NV>
		auto& chain370 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain370_t<NV>
                         getT(0).getT(4).getT(1).getT(0);
		auto& global_cable336 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable336_t<NV>
                                getT(0).getT(4).getT(1).getT(0).
                                getT(0);
		auto& add330 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(0).
                       getT(1);
		auto& chain371 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain371_t<NV>
                         getT(0).getT(4).getT(1).getT(1);
		auto& global_cable337 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable337_t<NV>
                                getT(0).getT(4).getT(1).getT(1).
                                getT(0);
		auto& add331 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(1).
                       getT(1);
		auto& chain372 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain372_t<NV>
                         getT(0).getT(4).getT(1).getT(2);
		auto& global_cable338 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable338_t<NV>
                                getT(0).getT(4).getT(1).getT(2).
                                getT(0);
		auto& add332 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(2).
                       getT(1);
		auto& chain373 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain373_t<NV>
                         getT(0).getT(4).getT(1).getT(3);
		auto& global_cable339 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable339_t<NV>
                                getT(0).getT(4).getT(1).getT(3).
                                getT(0);
		auto& add333 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(3).
                       getT(1);
		auto& chain374 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain374_t<NV>
                         getT(0).getT(4).getT(1).getT(4);
		auto& global_cable340 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable340_t<NV>
                                getT(0).getT(4).getT(1).getT(4).
                                getT(0);
		auto& add334 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(4).
                       getT(1);
		auto& chain375 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain375_t<NV>
                         getT(0).getT(4).getT(1).getT(5);
		auto& global_cable341 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable341_t<NV>
                                getT(0).getT(4).getT(1).getT(5).
                                getT(0);
		auto& add335 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(5).
                       getT(1);
		auto& chain376 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain376_t<NV>
                         getT(0).getT(4).getT(1).getT(6);
		auto& global_cable342 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable342_t<NV>
                                getT(0).getT(4).getT(1).getT(6).
                                getT(0);
		auto& add336 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(6).
                       getT(1);
		auto& chain377 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain377_t<NV>
                         getT(0).getT(4).getT(1).getT(7);
		auto& global_cable343 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable343_t<NV>
                                getT(0).getT(4).getT(1).getT(7).
                                getT(0);
		auto& add337 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(7).
                       getT(1);
		auto& chain378 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain378_t<NV>
                         getT(0).getT(4).getT(1).getT(8);
		auto& global_cable344 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable344_t<NV>
                                getT(0).getT(4).getT(1).getT(8).
                                getT(0);
		auto& add338 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(8).
                       getT(1);
		auto& chain379 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain379_t<NV>
                         getT(0).getT(4).getT(1).getT(9);
		auto& global_cable345 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable345_t<NV>
                                getT(0).getT(4).getT(1).getT(9).
                                getT(0);
		auto& add339 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(9).
                       getT(1);
		auto& chain380 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain380_t<NV>
                         getT(0).getT(4).getT(1).getT(10);
		auto& global_cable346 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable346_t<NV>
                                getT(0).getT(4).getT(1).getT(10).
                                getT(0);
		auto& add340 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(10).
                       getT(1);
		auto& chain381 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain381_t<NV>
                         getT(0).getT(4).getT(1).getT(11);
		auto& global_cable347 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable347_t<NV>
                                getT(0).getT(4).getT(1).getT(11).
                                getT(0);
		auto& add341 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(11).
                       getT(1);
		auto& chain382 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain382_t<NV>
                         getT(0).getT(4).getT(1).getT(12);
		auto& global_cable348 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable348_t<NV>
                                getT(0).getT(4).getT(1).getT(12).
                                getT(0);
		auto& add342 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(12).
                       getT(1);
		auto& chain383 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain383_t<NV>
                         getT(0).getT(4).getT(1).getT(13);
		auto& global_cable349 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable349_t<NV>
                                getT(0).getT(4).getT(1).getT(13).
                                getT(0);
		auto& add343 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(13).
                       getT(1);
		auto& chain384 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain384_t<NV>
                         getT(0).getT(4).getT(1).getT(14);
		auto& global_cable350 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable350_t<NV>
                                getT(0).getT(4).getT(1).getT(14).
                                getT(0);
		auto& add344 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(14).
                       getT(1);
		auto& chain385 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain385_t<NV>
                         getT(0).getT(4).getT(1).getT(15);
		auto& global_cable351 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable351_t<NV>
                                getT(0).getT(4).getT(1).getT(15).
                                getT(0);
		auto& add345 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(15).
                       getT(1);
		auto& peak23 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(2);        // Process_impl::peak23_t<NV>
		auto& pma32 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(3);         // Process_impl::pma32_t<NV>
		auto& clear42 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(4);       // math::clear<NV>
		auto& chain386 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5);              // Process_impl::chain386_t<NV>
		auto& clear43 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(0);       // math::clear<NV>
		auto& branch24 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(1);      // Process_impl::branch24_t<NV>
		auto& chain387 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain387_t<NV>
                         getT(0).getT(5).getT(1).getT(0);
		auto& global_cable352 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable352_t<NV>
                                getT(0).getT(5).getT(1).getT(0).
                                getT(0);
		auto& add346 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(0).
                       getT(1);
		auto& chain388 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain388_t<NV>
                         getT(0).getT(5).getT(1).getT(1);
		auto& global_cable353 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable353_t<NV>
                                getT(0).getT(5).getT(1).getT(1).
                                getT(0);
		auto& add347 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(1).
                       getT(1);
		auto& chain389 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain389_t<NV>
                         getT(0).getT(5).getT(1).getT(2);
		auto& global_cable354 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable354_t<NV>
                                getT(0).getT(5).getT(1).getT(2).
                                getT(0);
		auto& add348 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(2).
                       getT(1);
		auto& chain390 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain390_t<NV>
                         getT(0).getT(5).getT(1).getT(3);
		auto& global_cable355 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable355_t<NV>
                                getT(0).getT(5).getT(1).getT(3).
                                getT(0);
		auto& add349 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(3).
                       getT(1);
		auto& chain391 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain391_t<NV>
                         getT(0).getT(5).getT(1).getT(4);
		auto& global_cable356 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable356_t<NV>
                                getT(0).getT(5).getT(1).getT(4).
                                getT(0);
		auto& add350 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(4).
                       getT(1);
		auto& chain392 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain392_t<NV>
                         getT(0).getT(5).getT(1).getT(5);
		auto& global_cable357 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable357_t<NV>
                                getT(0).getT(5).getT(1).getT(5).
                                getT(0);
		auto& add351 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(5).
                       getT(1);
		auto& chain393 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain393_t<NV>
                         getT(0).getT(5).getT(1).getT(6);
		auto& global_cable358 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable358_t<NV>
                                getT(0).getT(5).getT(1).getT(6).
                                getT(0);
		auto& add352 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(6).
                       getT(1);
		auto& chain394 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain394_t<NV>
                         getT(0).getT(5).getT(1).getT(7);
		auto& global_cable359 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable359_t<NV>
                                getT(0).getT(5).getT(1).getT(7).
                                getT(0);
		auto& add353 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(7).
                       getT(1);
		auto& chain395 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain395_t<NV>
                         getT(0).getT(5).getT(1).getT(8);
		auto& global_cable360 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable360_t<NV>
                                getT(0).getT(5).getT(1).getT(8).
                                getT(0);
		auto& add354 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(8).
                       getT(1);
		auto& chain396 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain396_t<NV>
                         getT(0).getT(5).getT(1).getT(9);
		auto& global_cable361 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable361_t<NV>
                                getT(0).getT(5).getT(1).getT(9).
                                getT(0);
		auto& add355 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(9).
                       getT(1);
		auto& chain397 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain397_t<NV>
                         getT(0).getT(5).getT(1).getT(10);
		auto& global_cable362 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable362_t<NV>
                                getT(0).getT(5).getT(1).getT(10).
                                getT(0);
		auto& add356 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(10).
                       getT(1);
		auto& chain398 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain398_t<NV>
                         getT(0).getT(5).getT(1).getT(11);
		auto& global_cable363 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable363_t<NV>
                                getT(0).getT(5).getT(1).getT(11).
                                getT(0);
		auto& add357 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(11).
                       getT(1);
		auto& chain399 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain399_t<NV>
                         getT(0).getT(5).getT(1).getT(12);
		auto& global_cable364 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable364_t<NV>
                                getT(0).getT(5).getT(1).getT(12).
                                getT(0);
		auto& add358 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(12).
                       getT(1);
		auto& chain400 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain400_t<NV>
                         getT(0).getT(5).getT(1).getT(13);
		auto& global_cable365 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable365_t<NV>
                                getT(0).getT(5).getT(1).getT(13).
                                getT(0);
		auto& add359 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(13).
                       getT(1);
		auto& chain401 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain401_t<NV>
                         getT(0).getT(5).getT(1).getT(14);
		auto& global_cable366 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable366_t<NV>
                                getT(0).getT(5).getT(1).getT(14).
                                getT(0);
		auto& add360 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(14).
                       getT(1);
		auto& chain402 = this->getT(0).getT(0).getT(0).getT(0).                              // Process_impl::chain402_t<NV>
                         getT(0).getT(5).getT(1).getT(15);
		auto& global_cable367 = this->getT(0).getT(0).getT(0).getT(0).                       // Process_impl::global_cable367_t<NV>
                                getT(0).getT(5).getT(1).getT(15).
                                getT(0);
		auto& add361 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                       getT(0).getT(5).getT(1).getT(15).
                       getT(1);
		auto& peak24 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(2);        // Process_impl::peak24_t<NV>
		auto& pma33 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(3);         // Process_impl::pma33_t<NV>
		auto& clear44 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(4);       // math::clear<NV>
		auto& xfader = this->getT(0).getT(0).getT(0).getT(1);                                // Process_impl::xfader_t<NV>
		auto& split = this->getT(0).getT(0).getT(0).getT(2);                                 // Process_impl::split_t<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                        // Process_impl::chain2_t<NV>
		auto& gain = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0);                  // core::gain<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(2).getT(1);                        // Process_impl::chain3_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0);                // Process_impl::branch_t<NV>
		auto& svf = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);           // filters::svf<NV>
		auto& svf1 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);          // filters::svf<NV>
		auto& svf2 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(2);          // filters::svf<NV>
		auto& gain1 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1);                 // core::gain<NV>
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(3);                                // Process_impl::chain4_t<NV>
		auto& xfader1 = this->getT(0).getT(0).getT(0).getT(3).getT(0);                       // Process_impl::xfader1_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(0).getT(3).getT(1);                        // Process_impl::split1_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0);                // Process_impl::chain5_t<NV>
		auto& gain2 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(0).getT(0);         // core::gain<NV>
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(1);                // Process_impl::chain7_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(1).getT(0);        // Process_impl::chain6_t<NV>
		auto& midichain2 = this->getT(0).getT(0).getT(0).getT(3).                            // Process_impl::midichain2_t<NV>
                           getT(1).getT(1).getT(0).getT(0);
		auto& midi2 = this->getT(0).getT(0).getT(0).getT(3).                                 // Process_impl::midi2_t<NV>
                      getT(1).getT(1).getT(0).getT(0).
                      getT(0);
		auto& modchain2 = this->getT(0).getT(0).getT(0).getT(3).                             // Process_impl::modchain2_t<NV>
                          getT(1).getT(1).getT(0).getT(1);
		auto& pma = this->getT(0).getT(0).getT(0).getT(3).                                   // Process_impl::pma_t<NV>
                    getT(1).getT(1).getT(0).getT(1).
                    getT(0);
		auto& converter2 = this->getT(0).getT(0).getT(0).getT(3).                            // Process_impl::converter2_t<NV>
                           getT(1).getT(1).getT(0).getT(1).
                           getT(1);
		auto& converter3 = this->getT(0).getT(0).getT(0).getT(3).                            // Process_impl::converter3_t<NV>
                           getT(1).getT(1).getT(0).getT(1).
                           getT(2);
		auto& branch1 = this->getT(0).getT(0).getT(0).getT(3).                               // Process_impl::branch1_t<NV>
                        getT(1).getT(1).getT(0).getT(2);
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(3).                                // Process_impl::chain1_t<NV>
                       getT(1).getT(1).getT(0).getT(2).
                       getT(0);
		auto& tempo_sync1 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                   // control::tempo_sync<NV>
                            getT(1).getT(0).getT(2).getT(0).getT(0);
		auto& receive1 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                      // routing::receive<stereo_cable>
                         getT(1).getT(0).getT(2).getT(0).getT(1);
		auto& smoothed_parameter_unscaled1 = this->getT(0).getT(0).getT(0).getT(3).getT(1).  // Process_impl::smoothed_parameter_unscaled1_t<NV>
                                             getT(1).getT(0).getT(2).getT(0).getT(2);
		auto& fix_delay1 = this->getT(0).getT(0).getT(0).getT(3).getT(1).            // core::fix_delay
                           getT(1).getT(0).getT(2).getT(0).getT(3);
		auto& one_pole2 = this->getT(0).getT(0).getT(0).getT(3).getT(1).             // filters::one_pole<NV>
                          getT(1).getT(0).getT(2).getT(0).getT(4);
		auto& send1 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                 // routing::send<stereo_cable>
                      getT(1).getT(0).getT(2).getT(0).getT(5);
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(3).                        // Process_impl::chain8_t<NV>
                       getT(1).getT(1).getT(0).getT(2).
                       getT(1);
		auto& frame1_block = this->getT(0).getT(0).getT(0).getT(3).getT(1).          // Process_impl::frame1_block_t<NV>
                             getT(1).getT(0).getT(2).getT(1).getT(0);
		auto& receive3 = this->getT(0).getT(0).getT(0).getT(3).getT(1).              // routing::receive<stereo_frame_cable>
                         getT(1).getT(0).getT(2).getT(1).getT(0).
                         getT(0);
		auto& jdelay_thiran = this->getT(0).getT(0).getT(0).getT(3).getT(1).         // jdsp::jdelay_thiran<NV>
                              getT(1).getT(0).getT(2).getT(1).getT(0).
                              getT(1);
		auto& jdelay = this->getT(0).getT(0).getT(0).getT(3).getT(1).                // wrap::no_process<jdsp::jdelay<NV>>
                       getT(1).getT(0).getT(2).getT(1).getT(0).
                       getT(2);
		auto& fix_delay3 = this->getT(0).getT(0).getT(0).getT(3).getT(1).            // wrap::no_process<core::fix_delay>
                           getT(1).getT(0).getT(2).getT(1).getT(0).
                           getT(3);
		auto& one_pole3 = this->getT(0).getT(0).getT(0).getT(3).getT(1).             // filters::one_pole<NV>
                          getT(1).getT(0).getT(2).getT(1).getT(0).
                          getT(4);
		auto& send3 = this->getT(0).getT(0).getT(0).getT(3).getT(1).                 // routing::send<stereo_frame_cable>
                      getT(1).getT(0).getT(2).getT(1).getT(0).
                      getT(5);
		auto& one_pole4 = this->getT(0).getT(0).getT(0).getT(3).getT(1).             // filters::one_pole<NV>
                          getT(1).getT(0).getT(2).getT(1).getT(1);
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(3).                        // Process_impl::chain9_t<NV>
                       getT(1).getT(1).getT(0).getT(2).
                       getT(2);
		auto& allpass = this->getT(0).getT(0).getT(0).getT(3).getT(1).               // filters::allpass<NV>
                        getT(1).getT(0).getT(2).getT(2).getT(0);
		auto& one_pole = this->getT(0).getT(0).getT(0).getT(3).getT(1).              // filters::one_pole<NV>
                         getT(1).getT(0).getT(2).getT(2).getT(1);
		auto& gain3 = this->getT(0).getT(0).getT(0).getT(3).getT(1).getT(1).getT(1); // core::gain<NV>
		auto& jpanner = this->getT(0).getT(0).getT(0).getT(4);                       // jdsp::jpanner<NV>
		auto& ahdsr = this->getT(0).getT(0).getT(0).getT(5);                         // Process_impl::ahdsr_t<NV>
		auto& gain4 = this->getT(0).getT(0).getT(0).getT(6);                         // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		chain267.getParameterT(0).connectT(0, branch17); // ModSrc -> branch17::Index
		chain352.getParameterT(0).connectT(0, branch22); // ModSrc -> branch22::Index
		chain335.getParameterT(0).connectT(0, branch21); // ModSrc -> branch21::Index
		chain301.getParameterT(0).connectT(0, branch19); // ModSrc -> branch19::Index
		chain369.getParameterT(0).connectT(0, branch23); // ModSrc -> branch23::Index
		chain386.getParameterT(0).connectT(0, branch24); // ModSrc -> branch24::Index
		this->getParameterT(0).connectT(0, pma26);       // cut -> pma26::Add
		
		auto& q_p = this->getParameterT(1);
		q_p.connectT(0, svf);  // q -> svf::Q
		q_p.connectT(1, svf1); // q -> svf1::Q
		q_p.connectT(2, svf2); // q -> svf2::Q
		
		this->getParameterT(2).connectT(0, xfader); // mix -> xfader::Value
		
		this->getParameterT(3).connectT(0, pma26); // cutmod -> pma26::Multiply
		
		this->getParameterT(4).connectT(0, chain267); // cutsrc -> chain267::ModSrc
		
		this->getParameterT(5).connectT(0, pma31); // deltempo -> pma31::Add
		
		this->getParameterT(6).connectT(0, tempo_sync1); // deldiv -> tempo_sync1::Multiplier
		
		this->getParameterT(7).connectT(0, xfader1); // delmix -> xfader1::Value
		
		this->getParameterT(8).connectT(0, pma_unscaled); // pitch -> pma_unscaled::Add
		
		auto& delmod_p = this->getParameterT(9);
		delmod_p.connectT(0, pma31);        // delmod -> pma31::Multiply
		delmod_p.connectT(1, pma_unscaled); // delmod -> pma_unscaled::Multiply
		
		auto& delsrc_p = this->getParameterT(10);
		delsrc_p.connectT(0, chain335); // delsrc -> chain335::ModSrc
		delsrc_p.connectT(1, chain352); // delsrc -> chain352::ModSrc
		
		this->getParameterT(11).connectT(0, pma28); // DelLP -> pma28::Add
		
		this->getParameterT(12).connectT(0, pma28); // LpMod -> pma28::Multiply
		
		this->getParameterT(13).connectT(0, chain301); // LpSrc -> chain301::ModSrc
		
		this->getParameterT(14).connectT(0, pma32); // Pan -> pma32::Add
		
		this->getParameterT(15).connectT(0, pma32); // PanMod -> pma32::Multiply
		
		this->getParameterT(16).connectT(0, chain369); // PanSrc -> chain369::ModSrc
		
		this->getParameterT(17).connectT(0, smoothed_parameter_unscaled1); // smooth -> smoothed_parameter_unscaled1::SmoothingTime
		
		auto& feed_p = this->getParameterT(18);
		feed_p.connectT(0, receive1); // feed -> receive1::Feedback
		feed_p.connectT(1, receive3); // feed -> receive3::Feedback
		feed_p.connectT(2, allpass);  // feed -> allpass::Q
		
		this->getParameterT(19).connectT(0, branch); // fmode -> branch::Index
		
		this->getParameterT(20).connectT(0, ahdsr); // a -> ahdsr::Attack
		
		auto& d_p = this->getParameterT(21);
		d_p.connectT(0, ahdsr); // d -> ahdsr::Decay
		d_p.connectT(1, ahdsr); // d -> ahdsr::Release
		
		this->getParameterT(22).connectT(0, ahdsr); // sr -> ahdsr::Sustain
		
		this->getParameterT(23).connectT(0, pma33); // gain -> pma33::Add
		
		this->getParameterT(24).connectT(0, branch1); // delaymode -> branch1::Index
		
		this->getParameterT(25).connectT(0, pma33); // GainMod -> pma33::Multiply
		
		this->getParameterT(26).connectT(0, chain386); // GainSrc -> chain386::ModSrc
		
		this->getParameterT(27).connectT(0, gain4); // GainSmooth -> gain4::Smoothing
		
		this->getParameterT(28).connectT(0, gain4); // GainReset -> gain4::ResetValue
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable240.getWrappedObject().getParameter().connectT(0, add234);   // global_cable240 -> add234::Value
		global_cable241.getWrappedObject().getParameter().connectT(0, add235);   // global_cable241 -> add235::Value
		global_cable242.getWrappedObject().getParameter().connectT(0, add236);   // global_cable242 -> add236::Value
		global_cable243.getWrappedObject().getParameter().connectT(0, add237);   // global_cable243 -> add237::Value
		global_cable244.getWrappedObject().getParameter().connectT(0, add238);   // global_cable244 -> add238::Value
		global_cable245.getWrappedObject().getParameter().connectT(0, add239);   // global_cable245 -> add239::Value
		global_cable246.getWrappedObject().getParameter().connectT(0, add240);   // global_cable246 -> add240::Value
		global_cable247.getWrappedObject().getParameter().connectT(0, add241);   // global_cable247 -> add241::Value
		global_cable248.getWrappedObject().getParameter().connectT(0, add242);   // global_cable248 -> add242::Value
		global_cable249.getWrappedObject().getParameter().connectT(0, add243);   // global_cable249 -> add243::Value
		global_cable250.getWrappedObject().getParameter().connectT(0, add244);   // global_cable250 -> add244::Value
		global_cable251.getWrappedObject().getParameter().connectT(0, add245);   // global_cable251 -> add245::Value
		global_cable252.getWrappedObject().getParameter().connectT(0, add246);   // global_cable252 -> add246::Value
		global_cable253.getWrappedObject().getParameter().connectT(0, add247);   // global_cable253 -> add247::Value
		global_cable254.getWrappedObject().getParameter().connectT(0, add248);   // global_cable254 -> add248::Value
		global_cable255.getWrappedObject().getParameter().connectT(0, add249);   // global_cable255 -> add249::Value
		pma26.getWrappedObject().getParameter().connectT(0, svf);                // pma26 -> svf::Frequency
		pma26.getWrappedObject().getParameter().connectT(1, svf1);               // pma26 -> svf1::Frequency
		pma26.getWrappedObject().getParameter().connectT(2, svf2);               // pma26 -> svf2::Frequency
		peak17.getParameter().connectT(0, pma26);                                // peak17 -> pma26::Value
		global_cable320.getWrappedObject().getParameter().connectT(0, add314);   // global_cable320 -> add314::Value
		global_cable321.getWrappedObject().getParameter().connectT(0, add315);   // global_cable321 -> add315::Value
		global_cable322.getWrappedObject().getParameter().connectT(0, add316);   // global_cable322 -> add316::Value
		global_cable323.getWrappedObject().getParameter().connectT(0, add317);   // global_cable323 -> add317::Value
		global_cable324.getWrappedObject().getParameter().connectT(0, add318);   // global_cable324 -> add318::Value
		global_cable325.getWrappedObject().getParameter().connectT(0, add319);   // global_cable325 -> add319::Value
		global_cable326.getWrappedObject().getParameter().connectT(0, add320);   // global_cable326 -> add320::Value
		global_cable327.getWrappedObject().getParameter().connectT(0, add321);   // global_cable327 -> add321::Value
		global_cable328.getWrappedObject().getParameter().connectT(0, add322);   // global_cable328 -> add322::Value
		global_cable329.getWrappedObject().getParameter().connectT(0, add323);   // global_cable329 -> add323::Value
		global_cable330.getWrappedObject().getParameter().connectT(0, add324);   // global_cable330 -> add324::Value
		global_cable331.getWrappedObject().getParameter().connectT(0, add325);   // global_cable331 -> add325::Value
		global_cable332.getWrappedObject().getParameter().connectT(0, add326);   // global_cable332 -> add326::Value
		global_cable333.getWrappedObject().getParameter().connectT(0, add327);   // global_cable333 -> add327::Value
		global_cable334.getWrappedObject().getParameter().connectT(0, add328);   // global_cable334 -> add328::Value
		global_cable335.getWrappedObject().getParameter().connectT(0, add329);   // global_cable335 -> add329::Value
		converter3.getWrappedObject().getParameter().connectT(0, fix_delay3);    // converter3 -> fix_delay3::DelayTime
		converter3.getWrappedObject().getParameter().connectT(1, jdelay);        // converter3 -> jdelay::DelayTime
		converter3.getWrappedObject().getParameter().connectT(2, jdelay_thiran); // converter3 -> jdelay_thiran::DelayTime
		converter2.getWrappedObject().getParameter().connectT(0, converter3);    // converter2 -> converter3::Value
		converter2.getWrappedObject().getParameter().connectT(1, allpass);       // converter2 -> allpass::Frequency
		pma.getWrappedObject().getParameter().connectT(0, converter2);           // pma -> converter2::Value
		pma31.getWrappedObject().getParameter().connectT(0, tempo_sync1);        // pma31 -> tempo_sync1::Tempo
		pma31.getWrappedObject().getParameter().connectT(1, pma);                // pma31 -> pma::Add
		peak22.getParameter().connectT(0, pma31);                                // peak22 -> pma31::Value
		global_cable304.getWrappedObject().getParameter().connectT(0, add298);   // global_cable304 -> add298::Value
		global_cable305.getWrappedObject().getParameter().connectT(0, add299);   // global_cable305 -> add299::Value
		global_cable306.getWrappedObject().getParameter().connectT(0, add300);   // global_cable306 -> add300::Value
		global_cable307.getWrappedObject().getParameter().connectT(0, add301);   // global_cable307 -> add301::Value
		global_cable308.getWrappedObject().getParameter().connectT(0, add302);   // global_cable308 -> add302::Value
		global_cable309.getWrappedObject().getParameter().connectT(0, add303);   // global_cable309 -> add303::Value
		global_cable310.getWrappedObject().getParameter().connectT(0, add304);   // global_cable310 -> add304::Value
		global_cable311.getWrappedObject().getParameter().connectT(0, add305);   // global_cable311 -> add305::Value
		global_cable312.getWrappedObject().getParameter().connectT(0, add306);   // global_cable312 -> add306::Value
		global_cable313.getWrappedObject().getParameter().connectT(0, add307);   // global_cable313 -> add307::Value
		global_cable314.getWrappedObject().getParameter().connectT(0, add308);   // global_cable314 -> add308::Value
		global_cable315.getWrappedObject().getParameter().connectT(0, add309);   // global_cable315 -> add309::Value
		global_cable316.getWrappedObject().getParameter().connectT(0, add310);   // global_cable316 -> add310::Value
		global_cable317.getWrappedObject().getParameter().connectT(0, add311);   // global_cable317 -> add311::Value
		global_cable318.getWrappedObject().getParameter().connectT(0, add312);   // global_cable318 -> add312::Value
		global_cable319.getWrappedObject().getParameter().connectT(0, add313);   // global_cable319 -> add313::Value
		peak21.getParameter().connectT(0, pma_unscaled);                         // peak21 -> pma_unscaled::Value
		global_cable272.getWrappedObject().getParameter().connectT(0, add266);   // global_cable272 -> add266::Value
		global_cable273.getWrappedObject().getParameter().connectT(0, add267);   // global_cable273 -> add267::Value
		global_cable274.getWrappedObject().getParameter().connectT(0, add268);   // global_cable274 -> add268::Value
		global_cable275.getWrappedObject().getParameter().connectT(0, add269);   // global_cable275 -> add269::Value
		global_cable276.getWrappedObject().getParameter().connectT(0, add270);   // global_cable276 -> add270::Value
		global_cable277.getWrappedObject().getParameter().connectT(0, add271);   // global_cable277 -> add271::Value
		global_cable278.getWrappedObject().getParameter().connectT(0, add272);   // global_cable278 -> add272::Value
		global_cable279.getWrappedObject().getParameter().connectT(0, add273);   // global_cable279 -> add273::Value
		global_cable280.getWrappedObject().getParameter().connectT(0, add274);   // global_cable280 -> add274::Value
		global_cable281.getWrappedObject().getParameter().connectT(0, add275);   // global_cable281 -> add275::Value
		global_cable282.getWrappedObject().getParameter().connectT(0, add276);   // global_cable282 -> add276::Value
		global_cable283.getWrappedObject().getParameter().connectT(0, add277);   // global_cable283 -> add277::Value
		global_cable284.getWrappedObject().getParameter().connectT(0, add278);   // global_cable284 -> add278::Value
		global_cable285.getWrappedObject().getParameter().connectT(0, add279);   // global_cable285 -> add279::Value
		global_cable286.getWrappedObject().getParameter().connectT(0, add280);   // global_cable286 -> add280::Value
		global_cable287.getWrappedObject().getParameter().connectT(0, add281);   // global_cable287 -> add281::Value
		pma28.getWrappedObject().getParameter().connectT(0, one_pole2);          // pma28 -> one_pole2::Frequency
		pma28.getWrappedObject().getParameter().connectT(1, one_pole3);          // pma28 -> one_pole3::Frequency
		pma28.getWrappedObject().getParameter().connectT(2, one_pole);           // pma28 -> one_pole::Frequency
		peak19.getParameter().connectT(0, pma28);                                // peak19 -> pma28::Value
		global_cable336.getWrappedObject().getParameter().connectT(0, add330);   // global_cable336 -> add330::Value
		global_cable337.getWrappedObject().getParameter().connectT(0, add331);   // global_cable337 -> add331::Value
		global_cable338.getWrappedObject().getParameter().connectT(0, add332);   // global_cable338 -> add332::Value
		global_cable339.getWrappedObject().getParameter().connectT(0, add333);   // global_cable339 -> add333::Value
		global_cable340.getWrappedObject().getParameter().connectT(0, add334);   // global_cable340 -> add334::Value
		global_cable341.getWrappedObject().getParameter().connectT(0, add335);   // global_cable341 -> add335::Value
		global_cable342.getWrappedObject().getParameter().connectT(0, add336);   // global_cable342 -> add336::Value
		global_cable343.getWrappedObject().getParameter().connectT(0, add337);   // global_cable343 -> add337::Value
		global_cable344.getWrappedObject().getParameter().connectT(0, add338);   // global_cable344 -> add338::Value
		global_cable345.getWrappedObject().getParameter().connectT(0, add339);   // global_cable345 -> add339::Value
		global_cable346.getWrappedObject().getParameter().connectT(0, add340);   // global_cable346 -> add340::Value
		global_cable347.getWrappedObject().getParameter().connectT(0, add341);   // global_cable347 -> add341::Value
		global_cable348.getWrappedObject().getParameter().connectT(0, add342);   // global_cable348 -> add342::Value
		global_cable349.getWrappedObject().getParameter().connectT(0, add343);   // global_cable349 -> add343::Value
		global_cable350.getWrappedObject().getParameter().connectT(0, add344);   // global_cable350 -> add344::Value
		global_cable351.getWrappedObject().getParameter().connectT(0, add345);   // global_cable351 -> add345::Value
		pma32.getWrappedObject().getParameter().connectT(0, jpanner);            // pma32 -> jpanner::Pan
		peak23.getParameter().connectT(0, pma32);                                // peak23 -> pma32::Value
		global_cable352.getWrappedObject().getParameter().connectT(0, add346);   // global_cable352 -> add346::Value
		global_cable353.getWrappedObject().getParameter().connectT(0, add347);   // global_cable353 -> add347::Value
		global_cable354.getWrappedObject().getParameter().connectT(0, add348);   // global_cable354 -> add348::Value
		global_cable355.getWrappedObject().getParameter().connectT(0, add349);   // global_cable355 -> add349::Value
		global_cable356.getWrappedObject().getParameter().connectT(0, add350);   // global_cable356 -> add350::Value
		global_cable357.getWrappedObject().getParameter().connectT(0, add351);   // global_cable357 -> add351::Value
		global_cable358.getWrappedObject().getParameter().connectT(0, add352);   // global_cable358 -> add352::Value
		global_cable359.getWrappedObject().getParameter().connectT(0, add353);   // global_cable359 -> add353::Value
		global_cable360.getWrappedObject().getParameter().connectT(0, add354);   // global_cable360 -> add354::Value
		global_cable361.getWrappedObject().getParameter().connectT(0, add355);   // global_cable361 -> add355::Value
		global_cable362.getWrappedObject().getParameter().connectT(0, add356);   // global_cable362 -> add356::Value
		global_cable363.getWrappedObject().getParameter().connectT(0, add357);   // global_cable363 -> add357::Value
		global_cable364.getWrappedObject().getParameter().connectT(0, add358);   // global_cable364 -> add358::Value
		global_cable365.getWrappedObject().getParameter().connectT(0, add359);   // global_cable365 -> add359::Value
		global_cable366.getWrappedObject().getParameter().connectT(0, add360);   // global_cable366 -> add360::Value
		global_cable367.getWrappedObject().getParameter().connectT(0, add361);   // global_cable367 -> add361::Value
		pma33.getWrappedObject().getParameter().connectT(0, gain4);              // pma33 -> gain4::Gain
		peak24.getParameter().connectT(0, pma33);                                // peak24 -> pma33::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);  // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1); // xfader -> gain1::Gain
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain2);                       // xfader1 -> gain2::Gain
		xfader1_p.getParameterT(1).connectT(0, gain3);                       // xfader1 -> gain3::Gain
		midi2.getParameter().connectT(0, pma);                               // midi2 -> pma::Value
		smoothed_parameter_unscaled1.getParameter().connectT(0, fix_delay1); // smoothed_parameter_unscaled1 -> fix_delay1::DelayTime
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		
		// Send Connections ------------------------------------------------------------------------
		
		send1.connect(receive1);
		send3.connect(receive3);
		
		// Default Values --------------------------------------------------------------------------
		
		; // chain267::ModSrc is automated
		
		clear29.setParameterT(0, 0.); // math::clear::Value
		
		; // branch17::Index is automated
		
		global_cable240.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add234::Value is automated
		
		global_cable241.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add235::Value is automated
		
		global_cable242.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add236::Value is automated
		
		global_cable243.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add237::Value is automated
		
		global_cable244.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add238::Value is automated
		
		global_cable245.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add239::Value is automated
		
		global_cable246.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add240::Value is automated
		
		global_cable247.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add241::Value is automated
		
		global_cable248.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add242::Value is automated
		
		global_cable249.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add243::Value is automated
		
		global_cable250.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add244::Value is automated
		
		global_cable251.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add245::Value is automated
		
		global_cable252.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add246::Value is automated
		
		global_cable253.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add247::Value is automated
		
		global_cable254.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add248::Value is automated
		
		global_cable255.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add249::Value is automated
		
		; // pma26::Value is automated
		; // pma26::Multiply is automated
		; // pma26::Add is automated
		
		clear30.setParameterT(0, 0.); // math::clear::Value
		
		; // chain352::ModSrc is automated
		
		clear39.setParameterT(0, 0.); // math::clear::Value
		
		; // branch22::Index is automated
		
		global_cable320.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add314::Value is automated
		
		global_cable321.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add315::Value is automated
		
		global_cable322.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add316::Value is automated
		
		global_cable323.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add317::Value is automated
		
		global_cable324.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add318::Value is automated
		
		global_cable325.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add319::Value is automated
		
		global_cable326.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add320::Value is automated
		
		global_cable327.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add321::Value is automated
		
		global_cable328.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add322::Value is automated
		
		global_cable329.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add323::Value is automated
		
		global_cable330.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add324::Value is automated
		
		global_cable331.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add325::Value is automated
		
		global_cable332.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add326::Value is automated
		
		global_cable333.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add327::Value is automated
		
		global_cable334.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add328::Value is automated
		
		global_cable335.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add329::Value is automated
		
		; // pma31::Value is automated
		; // pma31::Multiply is automated
		; // pma31::Add is automated
		
		clear40.setParameterT(0, 0.); // math::clear::Value
		
		; // chain335::ModSrc is automated
		
		clear37.setParameterT(0, 0.); // math::clear::Value
		
		; // branch21::Index is automated
		
		global_cable304.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add298::Value is automated
		
		global_cable305.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add299::Value is automated
		
		global_cable306.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add300::Value is automated
		
		global_cable307.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add301::Value is automated
		
		global_cable308.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add302::Value is automated
		
		global_cable309.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add303::Value is automated
		
		global_cable310.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add304::Value is automated
		
		global_cable311.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add305::Value is automated
		
		global_cable312.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add306::Value is automated
		
		global_cable313.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add307::Value is automated
		
		global_cable314.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add308::Value is automated
		
		global_cable315.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add309::Value is automated
		
		global_cable316.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add310::Value is automated
		
		global_cable317.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add311::Value is automated
		
		global_cable318.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add312::Value is automated
		
		global_cable319.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add313::Value is automated
		
		; // pma_unscaled::Value is automated
		; // pma_unscaled::Multiply is automated
		; // pma_unscaled::Add is automated
		
		clear38.setParameterT(0, 0.); // math::clear::Value
		
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
		
		; // chain369::ModSrc is automated
		
		clear41.setParameterT(0, 0.); // math::clear::Value
		
		; // branch23::Index is automated
		
		global_cable336.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add330::Value is automated
		
		global_cable337.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add331::Value is automated
		
		global_cable338.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add332::Value is automated
		
		global_cable339.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add333::Value is automated
		
		global_cable340.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add334::Value is automated
		
		global_cable341.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add335::Value is automated
		
		global_cable342.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add336::Value is automated
		
		global_cable343.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add337::Value is automated
		
		global_cable344.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add338::Value is automated
		
		global_cable345.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add339::Value is automated
		
		global_cable346.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add340::Value is automated
		
		global_cable347.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add341::Value is automated
		
		global_cable348.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add342::Value is automated
		
		global_cable349.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add343::Value is automated
		
		global_cable350.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add344::Value is automated
		
		global_cable351.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add345::Value is automated
		
		; // pma32::Value is automated
		; // pma32::Multiply is automated
		; // pma32::Add is automated
		
		clear42.setParameterT(0, 0.); // math::clear::Value
		
		; // chain386::ModSrc is automated
		
		clear43.setParameterT(0, 0.); // math::clear::Value
		
		; // branch24::Index is automated
		
		global_cable352.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add346::Value is automated
		
		global_cable353.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add347::Value is automated
		
		global_cable354.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add348::Value is automated
		
		global_cable355.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add349::Value is automated
		
		global_cable356.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add350::Value is automated
		
		global_cable357.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add351::Value is automated
		
		global_cable358.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add352::Value is automated
		
		global_cable359.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add353::Value is automated
		
		global_cable360.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add354::Value is automated
		
		global_cable361.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add355::Value is automated
		
		global_cable362.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add356::Value is automated
		
		global_cable363.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add357::Value is automated
		
		global_cable364.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add358::Value is automated
		
		global_cable365.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add359::Value is automated
		
		global_cable366.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add360::Value is automated
		
		global_cable367.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add361::Value is automated
		
		; // pma33::Value is automated
		; // pma33::Multiply is automated
		; // pma33::Add is automated
		
		clear44.setParameterT(0, 0.); // math::clear::Value
		
		; // xfader::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch::Index is automated
		
		;                               // svf::Frequency is automated
		;                               // svf::Q is automated
		svf.setParameterT(2, -1.24481); // filters::svf::Gain
		svf.setParameterT(3, 0.01);     // filters::svf::Smoothing
		svf.setParameterT(4, 0.);       // filters::svf::Mode
		svf.setParameterT(5, 1.);       // filters::svf::Enabled
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf1.setParameterT(4, 1.);   // filters::svf::Mode
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf2::Frequency is automated
		;                            // svf2::Q is automated
		svf2.setParameterT(2, 0.);   // filters::svf::Gain
		svf2.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf2.setParameterT(4, 2.);   // filters::svf::Mode
		svf2.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader1::Value is automated
		
		;                              // gain2::Gain is automated
		gain2.setParameterT(1, 20.);   // core::gain::Smoothing
		gain2.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                         // pma::Value is automated
		pma.setParameterT(1, 1.); // control::pma::Multiply
		;                         // pma::Add is automated
		
		; // converter2::Value is automated
		
		; // converter3::Value is automated
		
		; // branch1::Index is automated
		
		;                                   // tempo_sync1::Tempo is automated
		;                                   // tempo_sync1::Multiplier is automated
		tempo_sync1.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // receive1::Feedback is automated
		
		smoothed_parameter_unscaled1.setParameterT(0, 195.126); // control::smoothed_parameter_unscaled::Value
		;                                                       // smoothed_parameter_unscaled1::SmoothingTime is automated
		smoothed_parameter_unscaled1.setParameterT(2, 1.);      // control::smoothed_parameter_unscaled::Enabled
		
		;                                  // fix_delay1::DelayTime is automated
		fix_delay1.setParameterT(1, 512.); // core::fix_delay::FadeTime
		
		;                                 // one_pole2::Frequency is automated
		one_pole2.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole2.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole2.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole2.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole2.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // receive3::Feedback is automated
		
		jdelay_thiran.setParameterT(0, 1000.); // jdsp::jdelay_thiran::Limit
		;                                      // jdelay_thiran::DelayTime is automated
		
		jdelay.setParameterT(0, 1000.); // jdsp::jdelay::Limit
		;                               // jdelay::DelayTime is automated
		
		;                                   // fix_delay3::DelayTime is automated
		fix_delay3.setParameterT(1, 1024.); // core::fix_delay::FadeTime
		
		;                                 // one_pole3::Frequency is automated
		one_pole3.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole3.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole3.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole3.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole3.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		one_pole4.setParameterT(0, 20.);  // filters::one_pole::Frequency
		one_pole4.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole4.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole4.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole4.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole4.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                               // allpass::Frequency is automated
		;                               // allpass::Q is automated
		allpass.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 167.3); // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                            // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		ahdsr.setParameterT(2, 0.);  // envelope::ahdsr::Hold
		;                            // ahdsr::Decay is automated
		;                            // ahdsr::Sustain is automated
		;                            // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		ahdsr.setParameterT(8, 0.);  // envelope::ahdsr::Gate
		
		; // gain4::Gain is automated
		; // gain4::Smoothing is automated
		; // gain4::ResetValue is automated
		
		this->setParameterT(0, 0.658713);
		this->setParameterT(1, 3.01566);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, -12.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 0.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 0.94786);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 572.8);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 1.);
		this->setParameterT(20, 748.3);
		this->setParameterT(21, 3535.);
		this->setParameterT(22, 1.);
		this->setParameterT(23, -13.);
		this->setParameterT(24, 2.);
		this->setParameterT(25, 0.);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 0.);
		this->setParameterT(28, 0.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable240_t<NV>
        getT(0).getT(0).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable241_t<NV>
        getT(0).getT(0).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable242_t<NV>
        getT(0).getT(0).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable243_t<NV>
        getT(0).getT(0).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable244_t<NV>
        getT(0).getT(0).getT(1).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable245_t<NV>
        getT(0).getT(0).getT(1).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable246_t<NV>
        getT(0).getT(0).getT(1).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable247_t<NV>
        getT(0).getT(0).getT(1).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable248_t<NV>
        getT(0).getT(0).getT(1).getT(8).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable249_t<NV>
        getT(0).getT(0).getT(1).getT(9).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable250_t<NV>
        getT(0).getT(0).getT(1).getT(10).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable251_t<NV>
        getT(0).getT(0).getT(1).getT(11).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable252_t<NV>
        getT(0).getT(0).getT(1).getT(12).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable253_t<NV>
        getT(0).getT(0).getT(1).getT(13).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable254_t<NV>
        getT(0).getT(0).getT(1).getT(14).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable255_t<NV>
        getT(0).getT(0).getT(1).getT(15).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable320_t<NV>
        getT(0).getT(1).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable321_t<NV>
        getT(0).getT(1).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable322_t<NV>
        getT(0).getT(1).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable323_t<NV>
        getT(0).getT(1).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable324_t<NV>
        getT(0).getT(1).getT(1).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable325_t<NV>
        getT(0).getT(1).getT(1).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable326_t<NV>
        getT(0).getT(1).getT(1).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable327_t<NV>
        getT(0).getT(1).getT(1).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable328_t<NV>
        getT(0).getT(1).getT(1).getT(8).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable329_t<NV>
        getT(0).getT(1).getT(1).getT(9).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable330_t<NV>
        getT(0).getT(1).getT(1).getT(10).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable331_t<NV>
        getT(0).getT(1).getT(1).getT(11).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable332_t<NV>
        getT(0).getT(1).getT(1).getT(12).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable333_t<NV>
        getT(0).getT(1).getT(1).getT(13).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable334_t<NV>
        getT(0).getT(1).getT(1).getT(14).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable335_t<NV>
        getT(0).getT(1).getT(1).getT(15).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable304_t<NV>
        getT(0).getT(2).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable305_t<NV>
        getT(0).getT(2).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable306_t<NV>
        getT(0).getT(2).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable307_t<NV>
        getT(0).getT(2).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable308_t<NV>
        getT(0).getT(2).getT(1).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable309_t<NV>
        getT(0).getT(2).getT(1).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable310_t<NV>
        getT(0).getT(2).getT(1).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable311_t<NV>
        getT(0).getT(2).getT(1).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable312_t<NV>
        getT(0).getT(2).getT(1).getT(8).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable313_t<NV>
        getT(0).getT(2).getT(1).getT(9).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable314_t<NV>
        getT(0).getT(2).getT(1).getT(10).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable315_t<NV>
        getT(0).getT(2).getT(1).getT(11).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable316_t<NV>
        getT(0).getT(2).getT(1).getT(12).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable317_t<NV>
        getT(0).getT(2).getT(1).getT(13).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable318_t<NV>
        getT(0).getT(2).getT(1).getT(14).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable319_t<NV>
        getT(0).getT(2).getT(1).getT(15).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable272_t<NV>
        getT(0).getT(3).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable273_t<NV>
        getT(0).getT(3).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable274_t<NV>
        getT(0).getT(3).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable275_t<NV>
        getT(0).getT(3).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable276_t<NV>
        getT(0).getT(3).getT(1).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable277_t<NV>
        getT(0).getT(3).getT(1).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable278_t<NV>
        getT(0).getT(3).getT(1).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable279_t<NV>
        getT(0).getT(3).getT(1).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable280_t<NV>
        getT(0).getT(3).getT(1).getT(8).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable281_t<NV>
        getT(0).getT(3).getT(1).getT(9).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable282_t<NV>
        getT(0).getT(3).getT(1).getT(10).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable283_t<NV>
        getT(0).getT(3).getT(1).getT(11).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable284_t<NV>
        getT(0).getT(3).getT(1).getT(12).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable285_t<NV>
        getT(0).getT(3).getT(1).getT(13).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable286_t<NV>
        getT(0).getT(3).getT(1).getT(14).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable287_t<NV>
        getT(0).getT(3).getT(1).getT(15).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable336_t<NV>
        getT(0).getT(4).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable337_t<NV>
        getT(0).getT(4).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable338_t<NV>
        getT(0).getT(4).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable339_t<NV>
        getT(0).getT(4).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable340_t<NV>
        getT(0).getT(4).getT(1).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable341_t<NV>
        getT(0).getT(4).getT(1).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable342_t<NV>
        getT(0).getT(4).getT(1).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable343_t<NV>
        getT(0).getT(4).getT(1).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable344_t<NV>
        getT(0).getT(4).getT(1).getT(8).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable345_t<NV>
        getT(0).getT(4).getT(1).getT(9).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable346_t<NV>
        getT(0).getT(4).getT(1).getT(10).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable347_t<NV>
        getT(0).getT(4).getT(1).getT(11).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable348_t<NV>
        getT(0).getT(4).getT(1).getT(12).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable349_t<NV>
        getT(0).getT(4).getT(1).getT(13).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable350_t<NV>
        getT(0).getT(4).getT(1).getT(14).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable351_t<NV>
        getT(0).getT(4).getT(1).getT(15).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable352_t<NV>
        getT(0).getT(5).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable353_t<NV>
        getT(0).getT(5).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable354_t<NV>
        getT(0).getT(5).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable355_t<NV>
        getT(0).getT(5).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable356_t<NV>
        getT(0).getT(5).getT(1).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable357_t<NV>
        getT(0).getT(5).getT(1).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable358_t<NV>
        getT(0).getT(5).getT(1).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable359_t<NV>
        getT(0).getT(5).getT(1).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable360_t<NV>
        getT(0).getT(5).getT(1).getT(8).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable361_t<NV>
        getT(0).getT(5).getT(1).getT(9).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable362_t<NV>
        getT(0).getT(5).getT(1).getT(10).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable363_t<NV>
        getT(0).getT(5).getT(1).getT(11).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable364_t<NV>
        getT(0).getT(5).getT(1).getT(12).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable365_t<NV>
        getT(0).getT(5).getT(1).getT(13).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable366_t<NV>
        getT(0).getT(5).getT(1).getT(14).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable367_t<NV>
        getT(0).getT(5).getT(1).getT(15).
        getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // Process_impl::peak17_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index); // Process_impl::peak22_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(2).setExternalData(b, index); // Process_impl::peak21_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(2).setExternalData(b, index); // Process_impl::peak19_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(2).setExternalData(b, index); // Process_impl::peak23_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(2).setExternalData(b, index); // Process_impl::peak24_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).setExternalData(b, index);                         // Process_impl::ahdsr_t<NV>
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
using Process = wrap::node<Process_impl::instance<NV>>;
}


