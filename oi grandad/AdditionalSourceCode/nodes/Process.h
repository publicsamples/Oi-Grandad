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

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, modchain3_t<NV>>, 
                                 xfader_t<NV>, 
                                 split_t<NV>, 
                                 jdsp::jpanner<NV>, 
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

DECLARE_PARAMETER_RANGE(cutRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using cut = parameter::from0To1<Process_impl::pma26_t<NV>, 
                                2, 
                                cutRange>;

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

template <int NV>
using Pan = parameter::from0To1<Process_impl::pma32_t<NV>, 
                                2, 
                                cutRange>;

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

DECLARE_PARAMETER_RANGE_SKEW(gain_InputRange, 
                             -100., 
                             0., 
                             5.42227);
template <int NV>
using gain_0 = parameter::from0To1<Process_impl::pma33_t<NV>, 
                                   2, 
                                   cutRange>;

template <int NV>
using gain = parameter::chain<gain_InputRange, gain_0<NV>>;

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
using deltempo = parameter::empty;
using deldiv = deltempo;
using delmix = deltempo;
using pitch = deltempo;
using delmod = deltempo;
using delsrc = deltempo;
using DelLP = deltempo;
using LpMod = deltempo;
using LpSrc = deltempo;
template <int NV>
using PanMod = parameter::plain<Process_impl::pma32_t<NV>, 
                                1>;
using smooth = deltempo;
using feed = deltempo;
using a = deltempo;
using d = deltempo;
using sr = deltempo;
using delaymode = deltempo;
template <int NV>
using GainMod = parameter::plain<Process_impl::pma33_t<NV>, 
                                 1>;
template <int NV>
using GainSmooth = parameter::plain<core::gain<NV>, 1>;
template <int NV>
using GainReset = parameter::plain<core::gain<NV>, 2>;
using Snap = deltempo;
using DelFreqOffset = deltempo;
using DelClockMode = deltempo;
using DelMs = deltempo;
using Blk = deltempo;
template <int NV>
using Process_t_plist = parameter::list<cut<NV>, 
                                        q<NV>, 
                                        mix<NV>, 
                                        cutmod<NV>, 
                                        cutsrc<NV>, 
                                        deltempo, 
                                        deldiv, 
                                        delmix, 
                                        pitch, 
                                        delmod, 
                                        delsrc, 
                                        DelLP, 
                                        LpMod, 
                                        LpSrc, 
                                        Pan<NV>, 
                                        PanMod<NV>, 
                                        PanSrc<NV>, 
                                        smooth, 
                                        feed, 
                                        fmode<NV>, 
                                        a, 
                                        d, 
                                        sr, 
                                        gain<NV>, 
                                        delaymode, 
                                        GainMod<NV>, 
                                        GainSrc<NV>, 
                                        GainSmooth<NV>, 
                                        GainReset<NV>, 
                                        Snap, 
                                        DelFreqOffset, 
                                        DelClockMode, 
                                        DelMs, 
                                        Blk>;
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
		SNEX_METADATA_ENCODED_PARAMETERS(538)
		{
			0x005B, 0x0000, 0x6300, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x843F, 0x6E96, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x0071, 0x999A, 0x3E99, 0x6666, 0x411E, 0x999A, 0x3E99, 
            0x8918, 0x3E87, 0x0000, 0x0000, 0x025B, 0x0000, 0x6D00, 0x7869, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0003, 0x0000, 0x7563, 0x6D74, 0x646F, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0xA43F, 0x1C30, 0x00BD, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0004, 0x0000, 0x7563, 0x7374, 0x6372, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0005, 0x0000, 0x6564, 0x746C, 0x6D65, 
            0x6F70, 0x0000, 0x8000, 0x003F, 0x9000, 0xAC41, 0x036A, 0x0041, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 0x6564, 0x646C, 
            0x7669, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 0x0000, 0x6564, 0x6D6C, 
            0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0008, 0x0000, 0x6970, 0x6374, 
            0x0068, 0x0000, 0xC1C0, 0x0000, 0x41C0, 0x47AE, 0x40D1, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x095B, 0x0000, 0x6400, 0x6C65, 0x6F6D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0A5B, 0x0000, 0x6400, 0x6C65, 0x7273, 
            0x0063, 0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0B5B, 0x0000, 0x4400, 0x6C65, 0x504C, 
            0x0000, 0x0000, 0x0000, 0x8000, 0xBD3F, 0x11E9, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000C, 0x0000, 0x704C, 0x6F4D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0D5B, 0x0000, 0x4C00, 0x5370, 0x6372, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0041, 0x0000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x000E, 0x0000, 0x6150, 0x006E, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F00, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0F5B, 0x0000, 0x5000, 0x6E61, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x105B, 0x0000, 0x5000, 0x6E61, 0x7253, 0x0063, 0x0000, 0x3F80, 
            0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x115B, 0x0000, 0x7300, 0x6F6D, 0x746F, 0x0068, 0xCCCD, 0x3DCC, 
            0x0000, 0x447A, 0x0000, 0x3F80, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 
            0x125B, 0x0000, 0x6600, 0x6565, 0x0064, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x135B, 
            0x0000, 0x6600, 0x6F6D, 0x6564, 0x0000, 0x8000, 0x003F, 0x4000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0014, 
            0x0000, 0x0061, 0x0000, 0x0000, 0x4000, 0x461C, 0x0000, 0x0000, 
            0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x155B, 0x0000, 0x6400, 0x0000, 
            0x0000, 0x0000, 0x1C40, 0x0046, 0xFA00, 0x7244, 0x4A6A, 0xCD3E, 
            0xCCCC, 0x5B3D, 0x0016, 0x0000, 0x7273, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0017, 0x0000, 0x6167, 0x6E69, 0x0000, 0xC800, 0x00C2, 0x0000, 
            0x6500, 0x4E66, 0x3EC1, 0xAD83, 0xCD40, 0xCCCC, 0x5B3D, 0x0018, 
            0x0000, 0x6564, 0x616C, 0x6D79, 0x646F, 0x0065, 0x0000, 0x3F80, 
            0x0000, 0x4040, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x195B, 0x0000, 0x4700, 0x6961, 0x4D6E, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x001A, 0x0000, 0x6147, 0x6E69, 0x7253, 0x0063, 0x0000, 
            0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x1B5B, 0x0000, 0x4700, 0x6961, 0x536E, 0x6F6D, 0x746F, 
            0x0068, 0x0000, 0x0000, 0x0000, 0x447A, 0x6667, 0x4086, 0x209B, 
            0x3E9A, 0xCCCD, 0x3DCC, 0x1C5B, 0x0000, 0x4700, 0x6961, 0x526E, 
            0x7365, 0x7465, 0x0000, 0xC800, 0x00C2, 0x0000, 0xCB00, 0x2CCC, 
            0x3EC1, 0xAD83, 0xCD40, 0xCCCC, 0x5B3D, 0x001D, 0x0000, 0x6E53, 
            0x7061, 0x0000, 0x0000, 0x0000, 0x8000, 0xBD3F, 0xE9E9, 0x003D, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x001E, 0x0000, 0x6544, 0x466C, 
            0x6572, 0x4F71, 0x6666, 0x6573, 0x0074, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x4859, 0x3F27, 0x0000, 0x3F80, 0x0000, 0x0000, 0x1F5B, 
            0x0000, 0x4400, 0x6C65, 0x6C43, 0x636F, 0x4D6B, 0x646F, 0x0065, 
            0x0000, 0x3F80, 0x0000, 0x4040, 0x0000, 0x4040, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x205B, 0x0000, 0x4400, 0x6C65, 0x734D, 0x0000, 
            0x0000, 0x0000, 0x7A00, 0x2144, 0x1191, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0021, 0x0000, 0x6C42, 0x006B, 0x0000, 0x3F80, 
            0x0000, 0x4100, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain20 = this->getT(0);                                                  // Process_impl::chain20_t<NV>
		auto& midichain = this->getT(0).getT(0);                                        // Process_impl::midichain_t<NV>
		auto& chain = this->getT(0).getT(0).getT(0);                                    // Process_impl::chain_t<NV>
		auto& modchain3 = this->getT(0).getT(0).getT(0).getT(0);                        // Process_impl::modchain3_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                   // Process_impl::split5_t<NV>
		auto& chain267 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);         // Process_impl::chain267_t<NV>
		auto& clear29 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);  // math::clear<NV>
		auto& branch17 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(1); // Process_impl::branch17_t<NV>
		auto& chain268 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain268_t<NV>
                         getT(0).getT(0).getT(1).getT(0);
		auto& global_cable240 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable240_t<NV>
                                getT(0).getT(0).getT(1).getT(0).
                                getT(0);
		auto& add234 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(1);
		auto& chain269 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain269_t<NV>
                         getT(0).getT(0).getT(1).getT(1);
		auto& global_cable241 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable241_t<NV>
                                getT(0).getT(0).getT(1).getT(1).
                                getT(0);
		auto& add235 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(1);
		auto& chain270 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain270_t<NV>
                         getT(0).getT(0).getT(1).getT(2);
		auto& global_cable242 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable242_t<NV>
                                getT(0).getT(0).getT(1).getT(2).
                                getT(0);
		auto& add236 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(1);
		auto& chain271 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain271_t<NV>
                         getT(0).getT(0).getT(1).getT(3);
		auto& global_cable243 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable243_t<NV>
                                getT(0).getT(0).getT(1).getT(3).
                                getT(0);
		auto& add237 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(3).
                       getT(1);
		auto& chain272 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain272_t<NV>
                         getT(0).getT(0).getT(1).getT(4);
		auto& global_cable244 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable244_t<NV>
                                getT(0).getT(0).getT(1).getT(4).
                                getT(0);
		auto& add238 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(4).
                       getT(1);
		auto& chain273 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain273_t<NV>
                         getT(0).getT(0).getT(1).getT(5);
		auto& global_cable245 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable245_t<NV>
                                getT(0).getT(0).getT(1).getT(5).
                                getT(0);
		auto& add239 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(5).
                       getT(1);
		auto& chain274 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain274_t<NV>
                         getT(0).getT(0).getT(1).getT(6);
		auto& global_cable246 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable246_t<NV>
                                getT(0).getT(0).getT(1).getT(6).
                                getT(0);
		auto& add240 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(6).
                       getT(1);
		auto& chain275 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain275_t<NV>
                         getT(0).getT(0).getT(1).getT(7);
		auto& global_cable247 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable247_t<NV>
                                getT(0).getT(0).getT(1).getT(7).
                                getT(0);
		auto& add241 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(7).
                       getT(1);
		auto& chain276 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain276_t<NV>
                         getT(0).getT(0).getT(1).getT(8);
		auto& global_cable248 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable248_t<NV>
                                getT(0).getT(0).getT(1).getT(8).
                                getT(0);
		auto& add242 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(8).
                       getT(1);
		auto& chain277 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain277_t<NV>
                         getT(0).getT(0).getT(1).getT(9);
		auto& global_cable249 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable249_t<NV>
                                getT(0).getT(0).getT(1).getT(9).
                                getT(0);
		auto& add243 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(9).
                       getT(1);
		auto& chain278 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain278_t<NV>
                         getT(0).getT(0).getT(1).getT(10);
		auto& global_cable250 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable250_t<NV>
                                getT(0).getT(0).getT(1).getT(10).
                                getT(0);
		auto& add244 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(10).
                       getT(1);
		auto& chain279 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain279_t<NV>
                         getT(0).getT(0).getT(1).getT(11);
		auto& global_cable251 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable251_t<NV>
                                getT(0).getT(0).getT(1).getT(11).
                                getT(0);
		auto& add245 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(11).
                       getT(1);
		auto& chain280 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain280_t<NV>
                         getT(0).getT(0).getT(1).getT(12);
		auto& global_cable252 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable252_t<NV>
                                getT(0).getT(0).getT(1).getT(12).
                                getT(0);
		auto& add246 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(12).
                       getT(1);
		auto& chain281 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain281_t<NV>
                         getT(0).getT(0).getT(1).getT(13);
		auto& global_cable253 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable253_t<NV>
                                getT(0).getT(0).getT(1).getT(13).
                                getT(0);
		auto& add247 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(13).
                       getT(1);
		auto& chain282 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain282_t<NV>
                         getT(0).getT(0).getT(1).getT(14);
		auto& global_cable254 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable254_t<NV>
                                getT(0).getT(0).getT(1).getT(14).
                                getT(0);
		auto& add248 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(14).
                       getT(1);
		auto& chain283 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain283_t<NV>
                         getT(0).getT(0).getT(1).getT(15);
		auto& global_cable255 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable255_t<NV>
                                getT(0).getT(0).getT(1).getT(15).
                                getT(0);
		auto& add249 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(0).getT(1).getT(15).
                       getT(1);
		auto& peak17 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);   // Process_impl::peak17_t<NV>
		auto& pma26 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(3);    // Process_impl::pma26_t<NV>
		auto& clear30 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(4);  // math::clear<NV>
		auto& chain369 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);         // Process_impl::chain369_t<NV>
		auto& clear41 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);  // math::clear<NV>
		auto& branch23 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(1); // Process_impl::branch23_t<NV>
		auto& chain370 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain370_t<NV>
                         getT(0).getT(1).getT(1).getT(0);
		auto& global_cable336 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable336_t<NV>
                                getT(0).getT(1).getT(1).getT(0).
                                getT(0);
		auto& add330 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(0).
                       getT(1);
		auto& chain371 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain371_t<NV>
                         getT(0).getT(1).getT(1).getT(1);
		auto& global_cable337 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable337_t<NV>
                                getT(0).getT(1).getT(1).getT(1).
                                getT(0);
		auto& add331 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(1).
                       getT(1);
		auto& chain372 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain372_t<NV>
                         getT(0).getT(1).getT(1).getT(2);
		auto& global_cable338 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable338_t<NV>
                                getT(0).getT(1).getT(1).getT(2).
                                getT(0);
		auto& add332 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(2).
                       getT(1);
		auto& chain373 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain373_t<NV>
                         getT(0).getT(1).getT(1).getT(3);
		auto& global_cable339 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable339_t<NV>
                                getT(0).getT(1).getT(1).getT(3).
                                getT(0);
		auto& add333 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(3).
                       getT(1);
		auto& chain374 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain374_t<NV>
                         getT(0).getT(1).getT(1).getT(4);
		auto& global_cable340 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable340_t<NV>
                                getT(0).getT(1).getT(1).getT(4).
                                getT(0);
		auto& add334 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(4).
                       getT(1);
		auto& chain375 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain375_t<NV>
                         getT(0).getT(1).getT(1).getT(5);
		auto& global_cable341 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable341_t<NV>
                                getT(0).getT(1).getT(1).getT(5).
                                getT(0);
		auto& add335 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(5).
                       getT(1);
		auto& chain376 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain376_t<NV>
                         getT(0).getT(1).getT(1).getT(6);
		auto& global_cable342 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable342_t<NV>
                                getT(0).getT(1).getT(1).getT(6).
                                getT(0);
		auto& add336 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(6).
                       getT(1);
		auto& chain377 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain377_t<NV>
                         getT(0).getT(1).getT(1).getT(7);
		auto& global_cable343 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable343_t<NV>
                                getT(0).getT(1).getT(1).getT(7).
                                getT(0);
		auto& add337 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(7).
                       getT(1);
		auto& chain378 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain378_t<NV>
                         getT(0).getT(1).getT(1).getT(8);
		auto& global_cable344 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable344_t<NV>
                                getT(0).getT(1).getT(1).getT(8).
                                getT(0);
		auto& add338 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(8).
                       getT(1);
		auto& chain379 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain379_t<NV>
                         getT(0).getT(1).getT(1).getT(9);
		auto& global_cable345 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable345_t<NV>
                                getT(0).getT(1).getT(1).getT(9).
                                getT(0);
		auto& add339 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(9).
                       getT(1);
		auto& chain380 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain380_t<NV>
                         getT(0).getT(1).getT(1).getT(10);
		auto& global_cable346 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable346_t<NV>
                                getT(0).getT(1).getT(1).getT(10).
                                getT(0);
		auto& add340 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(10).
                       getT(1);
		auto& chain381 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain381_t<NV>
                         getT(0).getT(1).getT(1).getT(11);
		auto& global_cable347 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable347_t<NV>
                                getT(0).getT(1).getT(1).getT(11).
                                getT(0);
		auto& add341 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(11).
                       getT(1);
		auto& chain382 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain382_t<NV>
                         getT(0).getT(1).getT(1).getT(12);
		auto& global_cable348 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable348_t<NV>
                                getT(0).getT(1).getT(1).getT(12).
                                getT(0);
		auto& add342 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(12).
                       getT(1);
		auto& chain383 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain383_t<NV>
                         getT(0).getT(1).getT(1).getT(13);
		auto& global_cable349 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable349_t<NV>
                                getT(0).getT(1).getT(1).getT(13).
                                getT(0);
		auto& add343 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(13).
                       getT(1);
		auto& chain384 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain384_t<NV>
                         getT(0).getT(1).getT(1).getT(14);
		auto& global_cable350 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable350_t<NV>
                                getT(0).getT(1).getT(1).getT(14).
                                getT(0);
		auto& add344 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(14).
                       getT(1);
		auto& chain385 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain385_t<NV>
                         getT(0).getT(1).getT(1).getT(15);
		auto& global_cable351 = this->getT(0).getT(0).getT(0).getT(0).                  // Process_impl::global_cable351_t<NV>
                                getT(0).getT(1).getT(1).getT(15).
                                getT(0);
		auto& add345 = this->getT(0).getT(0).getT(0).getT(0).                           // math::add<NV>
                       getT(0).getT(1).getT(1).getT(15).
                       getT(1);
		auto& peak23 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);   // Process_impl::peak23_t<NV>
		auto& pma32 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);    // Process_impl::pma32_t<NV>
		auto& clear42 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(4);  // math::clear<NV>
		auto& chain386 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);         // Process_impl::chain386_t<NV>
		auto& clear43 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(0);  // math::clear<NV>
		auto& branch24 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(1); // Process_impl::branch24_t<NV>
		auto& chain387 = this->getT(0).getT(0).getT(0).getT(0).                         // Process_impl::chain387_t<NV>
                         getT(0).getT(2).getT(1).getT(0);
		auto& global_cable352 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable352_t<NV>
                                getT(0).getT(2).getT(1).getT(0).
                                getT(0);
		auto& add346 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(0).
                       getT(1);
		auto& chain388 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain388_t<NV>
                         getT(0).getT(2).getT(1).getT(1);
		auto& global_cable353 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable353_t<NV>
                                getT(0).getT(2).getT(1).getT(1).
                                getT(0);
		auto& add347 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(1).
                       getT(1);
		auto& chain389 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain389_t<NV>
                         getT(0).getT(2).getT(1).getT(2);
		auto& global_cable354 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable354_t<NV>
                                getT(0).getT(2).getT(1).getT(2).
                                getT(0);
		auto& add348 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(2).
                       getT(1);
		auto& chain390 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain390_t<NV>
                         getT(0).getT(2).getT(1).getT(3);
		auto& global_cable355 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable355_t<NV>
                                getT(0).getT(2).getT(1).getT(3).
                                getT(0);
		auto& add349 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(3).
                       getT(1);
		auto& chain391 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain391_t<NV>
                         getT(0).getT(2).getT(1).getT(4);
		auto& global_cable356 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable356_t<NV>
                                getT(0).getT(2).getT(1).getT(4).
                                getT(0);
		auto& add350 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(4).
                       getT(1);
		auto& chain392 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain392_t<NV>
                         getT(0).getT(2).getT(1).getT(5);
		auto& global_cable357 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable357_t<NV>
                                getT(0).getT(2).getT(1).getT(5).
                                getT(0);
		auto& add351 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(5).
                       getT(1);
		auto& chain393 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain393_t<NV>
                         getT(0).getT(2).getT(1).getT(6);
		auto& global_cable358 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable358_t<NV>
                                getT(0).getT(2).getT(1).getT(6).
                                getT(0);
		auto& add352 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(6).
                       getT(1);
		auto& chain394 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain394_t<NV>
                         getT(0).getT(2).getT(1).getT(7);
		auto& global_cable359 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable359_t<NV>
                                getT(0).getT(2).getT(1).getT(7).
                                getT(0);
		auto& add353 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(7).
                       getT(1);
		auto& chain395 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain395_t<NV>
                         getT(0).getT(2).getT(1).getT(8);
		auto& global_cable360 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable360_t<NV>
                                getT(0).getT(2).getT(1).getT(8).
                                getT(0);
		auto& add354 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(8).
                       getT(1);
		auto& chain396 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain396_t<NV>
                         getT(0).getT(2).getT(1).getT(9);
		auto& global_cable361 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable361_t<NV>
                                getT(0).getT(2).getT(1).getT(9).
                                getT(0);
		auto& add355 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(9).
                       getT(1);
		auto& chain397 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain397_t<NV>
                         getT(0).getT(2).getT(1).getT(10);
		auto& global_cable362 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable362_t<NV>
                                getT(0).getT(2).getT(1).getT(10).
                                getT(0);
		auto& add356 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(10).
                       getT(1);
		auto& chain398 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain398_t<NV>
                         getT(0).getT(2).getT(1).getT(11);
		auto& global_cable363 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable363_t<NV>
                                getT(0).getT(2).getT(1).getT(11).
                                getT(0);
		auto& add357 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(11).
                       getT(1);
		auto& chain399 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain399_t<NV>
                         getT(0).getT(2).getT(1).getT(12);
		auto& global_cable364 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable364_t<NV>
                                getT(0).getT(2).getT(1).getT(12).
                                getT(0);
		auto& add358 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(12).
                       getT(1);
		auto& chain400 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain400_t<NV>
                         getT(0).getT(2).getT(1).getT(13);
		auto& global_cable365 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable365_t<NV>
                                getT(0).getT(2).getT(1).getT(13).
                                getT(0);
		auto& add359 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(13).
                       getT(1);
		auto& chain401 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain401_t<NV>
                         getT(0).getT(2).getT(1).getT(14);
		auto& global_cable366 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable366_t<NV>
                                getT(0).getT(2).getT(1).getT(14).
                                getT(0);
		auto& add360 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(14).
                       getT(1);
		auto& chain402 = this->getT(0).getT(0).getT(0).getT(0).                        // Process_impl::chain402_t<NV>
                         getT(0).getT(2).getT(1).getT(15);
		auto& global_cable367 = this->getT(0).getT(0).getT(0).getT(0).                 // Process_impl::global_cable367_t<NV>
                                getT(0).getT(2).getT(1).getT(15).
                                getT(0);
		auto& add361 = this->getT(0).getT(0).getT(0).getT(0).                          // math::add<NV>
                       getT(0).getT(2).getT(1).getT(15).
                       getT(1);
		auto& peak24 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(2);  // Process_impl::peak24_t<NV>
		auto& pma33 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(3);   // Process_impl::pma33_t<NV>
		auto& clear44 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(4); // math::clear<NV>
		auto& xfader = this->getT(0).getT(0).getT(0).getT(1);                          // Process_impl::xfader_t<NV>
		auto& split = this->getT(0).getT(0).getT(0).getT(2);                           // Process_impl::split_t<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                  // Process_impl::chain2_t<NV>
		auto& gain = this->getT(0).getT(0).getT(0).getT(2).getT(0).getT(0);            // core::gain<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(2).getT(1);                  // Process_impl::chain3_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0);          // Process_impl::branch_t<NV>
		auto& svf = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);     // filters::svf<NV>
		auto& svf1 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);    // filters::svf<NV>
		auto& svf2 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(2);    // filters::svf<NV>
		auto& gain1 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1);           // core::gain<NV>
		auto& jpanner = this->getT(0).getT(0).getT(0).getT(3);                         // jdsp::jpanner<NV>
		auto& gain4 = this->getT(0).getT(0).getT(0).getT(4);                           // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		chain267.getParameterT(0).connectT(0, branch17); // ModSrc -> branch17::Index
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
		
		this->getParameterT(14).connectT(0, pma32); // Pan -> pma32::Add
		
		this->getParameterT(15).connectT(0, pma32); // PanMod -> pma32::Multiply
		
		this->getParameterT(16).connectT(0, chain369); // PanSrc -> chain369::ModSrc
		
		this->getParameterT(19).connectT(0, branch); // fmode -> branch::Index
		
		this->getParameterT(23).connectT(0, pma33); // gain -> pma33::Add
		
		this->getParameterT(25).connectT(0, pma33); // GainMod -> pma33::Multiply
		
		this->getParameterT(26).connectT(0, chain386); // GainSrc -> chain386::ModSrc
		
		this->getParameterT(27).connectT(0, gain4); // GainSmooth -> gain4::Smoothing
		
		this->getParameterT(28).connectT(0, gain4); // GainReset -> gain4::ResetValue
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable240.getWrappedObject().getParameter().connectT(0, add234); // global_cable240 -> add234::Value
		global_cable241.getWrappedObject().getParameter().connectT(0, add235); // global_cable241 -> add235::Value
		global_cable242.getWrappedObject().getParameter().connectT(0, add236); // global_cable242 -> add236::Value
		global_cable243.getWrappedObject().getParameter().connectT(0, add237); // global_cable243 -> add237::Value
		global_cable244.getWrappedObject().getParameter().connectT(0, add238); // global_cable244 -> add238::Value
		global_cable245.getWrappedObject().getParameter().connectT(0, add239); // global_cable245 -> add239::Value
		global_cable246.getWrappedObject().getParameter().connectT(0, add240); // global_cable246 -> add240::Value
		global_cable247.getWrappedObject().getParameter().connectT(0, add241); // global_cable247 -> add241::Value
		global_cable248.getWrappedObject().getParameter().connectT(0, add242); // global_cable248 -> add242::Value
		global_cable249.getWrappedObject().getParameter().connectT(0, add243); // global_cable249 -> add243::Value
		global_cable250.getWrappedObject().getParameter().connectT(0, add244); // global_cable250 -> add244::Value
		global_cable251.getWrappedObject().getParameter().connectT(0, add245); // global_cable251 -> add245::Value
		global_cable252.getWrappedObject().getParameter().connectT(0, add246); // global_cable252 -> add246::Value
		global_cable253.getWrappedObject().getParameter().connectT(0, add247); // global_cable253 -> add247::Value
		global_cable254.getWrappedObject().getParameter().connectT(0, add248); // global_cable254 -> add248::Value
		global_cable255.getWrappedObject().getParameter().connectT(0, add249); // global_cable255 -> add249::Value
		pma26.getWrappedObject().getParameter().connectT(0, svf);              // pma26 -> svf::Frequency
		pma26.getWrappedObject().getParameter().connectT(1, svf1);             // pma26 -> svf1::Frequency
		pma26.getWrappedObject().getParameter().connectT(2, svf2);             // pma26 -> svf2::Frequency
		peak17.getParameter().connectT(0, pma26);                              // peak17 -> pma26::Value
		global_cable336.getWrappedObject().getParameter().connectT(0, add330); // global_cable336 -> add330::Value
		global_cable337.getWrappedObject().getParameter().connectT(0, add331); // global_cable337 -> add331::Value
		global_cable338.getWrappedObject().getParameter().connectT(0, add332); // global_cable338 -> add332::Value
		global_cable339.getWrappedObject().getParameter().connectT(0, add333); // global_cable339 -> add333::Value
		global_cable340.getWrappedObject().getParameter().connectT(0, add334); // global_cable340 -> add334::Value
		global_cable341.getWrappedObject().getParameter().connectT(0, add335); // global_cable341 -> add335::Value
		global_cable342.getWrappedObject().getParameter().connectT(0, add336); // global_cable342 -> add336::Value
		global_cable343.getWrappedObject().getParameter().connectT(0, add337); // global_cable343 -> add337::Value
		global_cable344.getWrappedObject().getParameter().connectT(0, add338); // global_cable344 -> add338::Value
		global_cable345.getWrappedObject().getParameter().connectT(0, add339); // global_cable345 -> add339::Value
		global_cable346.getWrappedObject().getParameter().connectT(0, add340); // global_cable346 -> add340::Value
		global_cable347.getWrappedObject().getParameter().connectT(0, add341); // global_cable347 -> add341::Value
		global_cable348.getWrappedObject().getParameter().connectT(0, add342); // global_cable348 -> add342::Value
		global_cable349.getWrappedObject().getParameter().connectT(0, add343); // global_cable349 -> add343::Value
		global_cable350.getWrappedObject().getParameter().connectT(0, add344); // global_cable350 -> add344::Value
		global_cable351.getWrappedObject().getParameter().connectT(0, add345); // global_cable351 -> add345::Value
		pma32.getWrappedObject().getParameter().connectT(0, jpanner);          // pma32 -> jpanner::Pan
		peak23.getParameter().connectT(0, pma32);                              // peak23 -> pma32::Value
		global_cable352.getWrappedObject().getParameter().connectT(0, add346); // global_cable352 -> add346::Value
		global_cable353.getWrappedObject().getParameter().connectT(0, add347); // global_cable353 -> add347::Value
		global_cable354.getWrappedObject().getParameter().connectT(0, add348); // global_cable354 -> add348::Value
		global_cable355.getWrappedObject().getParameter().connectT(0, add349); // global_cable355 -> add349::Value
		global_cable356.getWrappedObject().getParameter().connectT(0, add350); // global_cable356 -> add350::Value
		global_cable357.getWrappedObject().getParameter().connectT(0, add351); // global_cable357 -> add351::Value
		global_cable358.getWrappedObject().getParameter().connectT(0, add352); // global_cable358 -> add352::Value
		global_cable359.getWrappedObject().getParameter().connectT(0, add353); // global_cable359 -> add353::Value
		global_cable360.getWrappedObject().getParameter().connectT(0, add354); // global_cable360 -> add354::Value
		global_cable361.getWrappedObject().getParameter().connectT(0, add355); // global_cable361 -> add355::Value
		global_cable362.getWrappedObject().getParameter().connectT(0, add356); // global_cable362 -> add356::Value
		global_cable363.getWrappedObject().getParameter().connectT(0, add357); // global_cable363 -> add357::Value
		global_cable364.getWrappedObject().getParameter().connectT(0, add358); // global_cable364 -> add358::Value
		global_cable365.getWrappedObject().getParameter().connectT(0, add359); // global_cable365 -> add359::Value
		global_cable366.getWrappedObject().getParameter().connectT(0, add360); // global_cable366 -> add360::Value
		global_cable367.getWrappedObject().getParameter().connectT(0, add361); // global_cable367 -> add361::Value
		pma33.getWrappedObject().getParameter().connectT(0, gain4);            // pma33 -> gain4::Gain
		peak24.getParameter().connectT(0, pma33);                              // peak24 -> pma33::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);  // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1); // xfader -> gain1::Gain
		
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
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		; // gain4::Gain is automated
		; // gain4::Smoothing is automated
		; // gain4::ResetValue is automated
		
		this->setParameterT(0, 0.931984);
		this->setParameterT(1, 0.3);
		this->setParameterT(2, 0.);
		this->setParameterT(3, -0.0381323);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 8.21354);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 6.54);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 0.569973);
		this->setParameterT(12, 0.);
		this->setParameterT(13, 2.);
		this->setParameterT(14, 0.5);
		this->setParameterT(15, 0.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 1);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 1.);
		this->setParameterT(20, 0.);
		this->setParameterT(21, 2000.);
		this->setParameterT(22, 1.);
		this->setParameterT(23, -12.);
		this->setParameterT(24, 3.);
		this->setParameterT(25, 0.);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 4.2);
		this->setParameterT(28, -10.);
		this->setParameterT(29, 0.114215);
		this->setParameterT(30, 0.653448);
		this->setParameterT(31, 3.);
		this->setParameterT(32, 0.568621);
		this->setParameterT(33, 1.);
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
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable336_t<NV>
        getT(0).getT(1).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable337_t<NV>
        getT(0).getT(1).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable338_t<NV>
        getT(0).getT(1).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable339_t<NV>
        getT(0).getT(1).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable340_t<NV>
        getT(0).getT(1).getT(1).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable341_t<NV>
        getT(0).getT(1).getT(1).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable342_t<NV>
        getT(0).getT(1).getT(1).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable343_t<NV>
        getT(0).getT(1).getT(1).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable344_t<NV>
        getT(0).getT(1).getT(1).getT(8).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable345_t<NV>
        getT(0).getT(1).getT(1).getT(9).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable346_t<NV>
        getT(0).getT(1).getT(1).getT(10).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable347_t<NV>
        getT(0).getT(1).getT(1).getT(11).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable348_t<NV>
        getT(0).getT(1).getT(1).getT(12).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable349_t<NV>
        getT(0).getT(1).getT(1).getT(13).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable350_t<NV>
        getT(0).getT(1).getT(1).getT(14).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable351_t<NV>
        getT(0).getT(1).getT(1).getT(15).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable352_t<NV>
        getT(0).getT(2).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable353_t<NV>
        getT(0).getT(2).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable354_t<NV>
        getT(0).getT(2).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable355_t<NV>
        getT(0).getT(2).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable356_t<NV>
        getT(0).getT(2).getT(1).getT(4).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable357_t<NV>
        getT(0).getT(2).getT(1).getT(5).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable358_t<NV>
        getT(0).getT(2).getT(1).getT(6).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable359_t<NV>
        getT(0).getT(2).getT(1).getT(7).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable360_t<NV>
        getT(0).getT(2).getT(1).getT(8).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable361_t<NV>
        getT(0).getT(2).getT(1).getT(9).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable362_t<NV>
        getT(0).getT(2).getT(1).getT(10).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable363_t<NV>
        getT(0).getT(2).getT(1).getT(11).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable364_t<NV>
        getT(0).getT(2).getT(1).getT(12).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable365_t<NV>
        getT(0).getT(2).getT(1).getT(13).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable366_t<NV>
        getT(0).getT(2).getT(1).getT(14).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).  // Process_impl::global_cable367_t<NV>
        getT(0).getT(2).getT(1).getT(15).
        getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // Process_impl::peak17_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index); // Process_impl::peak23_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(2).setExternalData(b, index); // Process_impl::peak24_t<NV>
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


