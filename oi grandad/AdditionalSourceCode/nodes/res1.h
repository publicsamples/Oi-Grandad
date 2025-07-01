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

namespace res1_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(ahdsr_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using ahdsr_c0 = parameter::from0To1<core::gain<NV>, 
                                     0, 
                                     ahdsr_c0Range>;

template <int NV>
using ahdsr_multimod = parameter::list<ahdsr_c0<NV>, parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;

template <int NV>
using midichain2_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, ahdsr_t<NV>>>;

template <int NV>
using midichain2_t = wrap::event<midichain2_t_<NV>>;

template <int NV>
using soft_bypass_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, midichain2_t<NV>>, 
                                        core::gain<NV>>;

template <int NV>
using soft_bypass_t = bypass::smoothed<20, soft_bypass_t_<NV>>;
template <int NV>
using xfader_c0 = parameter::bypass<soft_bypass_t<NV>>;

template <int NV> using ahdsr1_c0 = ahdsr_c0<NV>;

template <int NV>
using ahdsr1_multimod = parameter::list<ahdsr1_c0<NV>, parameter::empty>;

template <int NV>
using ahdsr1_t = wrap::no_data<envelope::ahdsr<NV, ahdsr1_multimod<NV>>>;

template <int NV>
using midichain3_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, ahdsr1_t<NV>>>;

template <int NV>
using midichain3_t = wrap::event<midichain3_t_<NV>>;

template <int NV>
using soft_bypass1_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, midichain3_t<NV>>, 
                                         core::gain<NV>>;

template <int NV>
using soft_bypass1_t = bypass::smoothed<20, soft_bypass1_t_<NV>>;
template <int NV>
using xfader_c1 = parameter::bypass<soft_bypass1_t<NV>>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::switcher>;
using global_cable336_t_index = runtime_target::indexers::fix_hash<1120565314>;

template <int NV>
using global_cable336_t = routing::global_cable<global_cable336_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain370_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable336_t<NV>>, 
                                    math::add<NV>>;
using global_cable337_t_index = runtime_target::indexers::fix_hash<1120565315>;

template <int NV>
using global_cable337_t = routing::global_cable<global_cable337_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain371_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable337_t<NV>>, 
                                    math::add<NV>>;
using global_cable338_t_index = runtime_target::indexers::fix_hash<1120565316>;

template <int NV>
using global_cable338_t = routing::global_cable<global_cable338_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain372_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable338_t<NV>>, 
                                    math::add<NV>>;
using global_cable339_t_index = runtime_target::indexers::fix_hash<1120565317>;

template <int NV>
using global_cable339_t = routing::global_cable<global_cable339_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain373_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable339_t<NV>>, 
                                    math::add<NV>>;
using global_cable340_t_index = runtime_target::indexers::fix_hash<1120565318>;

template <int NV>
using global_cable340_t = routing::global_cable<global_cable340_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain374_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable340_t<NV>>, 
                                    math::add<NV>>;
using global_cable341_t_index = runtime_target::indexers::fix_hash<1120565319>;

template <int NV>
using global_cable341_t = routing::global_cable<global_cable341_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain375_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable341_t<NV>>, 
                                    math::add<NV>>;
using global_cable342_t_index = runtime_target::indexers::fix_hash<1120565320>;

template <int NV>
using global_cable342_t = routing::global_cable<global_cable342_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain376_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable342_t<NV>>, 
                                    math::add<NV>>;
using global_cable343_t_index = runtime_target::indexers::fix_hash<1120565321>;

template <int NV>
using global_cable343_t = routing::global_cable<global_cable343_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain377_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable343_t<NV>>, 
                                    math::add<NV>>;
using global_cable344_t_index = runtime_target::indexers::fix_hash<1120565322>;

template <int NV>
using global_cable344_t = routing::global_cable<global_cable344_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain378_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable344_t<NV>>, 
                                    math::add<NV>>;
using global_cable345_t_index = runtime_target::indexers::fix_hash<377786414>;

template <int NV>
using global_cable345_t = routing::global_cable<global_cable345_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain379_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable345_t<NV>>, 
                                    math::add<NV>>;
using global_cable346_t_index = runtime_target::indexers::fix_hash<377786415>;

template <int NV>
using global_cable346_t = routing::global_cable<global_cable346_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain380_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable346_t<NV>>, 
                                    math::add<NV>>;
using global_cable347_t_index = runtime_target::indexers::fix_hash<377786416>;

template <int NV>
using global_cable347_t = routing::global_cable<global_cable347_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain381_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable347_t<NV>>, 
                                    math::add<NV>>;
using global_cable348_t_index = runtime_target::indexers::fix_hash<377786417>;

template <int NV>
using global_cable348_t = routing::global_cable<global_cable348_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain382_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable348_t<NV>>, 
                                    math::add<NV>>;
using global_cable349_t_index = runtime_target::indexers::fix_hash<377786418>;

template <int NV>
using global_cable349_t = routing::global_cable<global_cable349_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain383_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable349_t<NV>>, 
                                    math::add<NV>>;
using global_cable350_t_index = runtime_target::indexers::fix_hash<377786419>;

template <int NV>
using global_cable350_t = routing::global_cable<global_cable350_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain384_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable350_t<NV>>, 
                                    math::add<NV>>;
using global_cable351_t_index = runtime_target::indexers::fix_hash<377786420>;

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

template <int NV>
using minmax4_t = control::minmax<NV, 
                                  parameter::plain<fx::haas<NV>, 0>>;

template <int NV>
using input_toggle1_mod = parameter::chain<ranges::Identity, 
                                           parameter::plain<minmax4_t<NV>, 0>, 
                                           parameter::plain<fx::phase_delay<NV>, 0>, 
                                           parameter::plain<fx::phase_delay<NV>, 0>>;

template <int NV>
using input_toggle1_t = control::input_toggle<NV, input_toggle1_mod<NV>>;

template <int NV>
using input_toggle_mod = parameter::chain<ranges::Identity, 
                                          parameter::plain<core::fix_delay, 0>, 
                                          parameter::plain<jdsp::jdelay<NV>, 1>, 
                                          parameter::plain<core::fix_delay, 0>, 
                                          parameter::plain<core::fix_delay, 0>>;

template <int NV>
using input_toggle_t = control::input_toggle<NV, input_toggle_mod<NV>>;
template <int NV>
using minmax1_t = control::minmax<NV, 
                                  parameter::plain<input_toggle_t<NV>, 1>>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<project::granular<NV>, 4>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using cable_table_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                            0, 
                                            cable_table_modRange>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.00195694f, 0.00587082f,
		0.0097847f, 0.0136986f, 0.0176126f, 0.0215265f, 0.0254403f, 0.0293542f,
		0.0332681f, 0.037182f, 0.0410959f, 0.0450097f, 0.0489237f, 0.0528376f,
		0.0567515f, 0.0606654f, 0.0645792f, 0.0684931f, 0.072407f, 0.0763209f,
		0.0802349f, 0.0841488f, 0.0880626f, 0.0919765f, 0.0958904f, 0.0998043f,
		0.103718f, 0.107632f, 0.111546f, 0.11546f, 0.119374f, 0.123288f,
		0.127202f, 0.131115f, 0.135029f, 0.138943f, 0.142857f, 0.146771f,
		0.150685f, 0.154599f, 0.158513f, 0.162427f, 0.16634f, 0.170254f,
		0.174168f, 0.178082f, 0.181996f, 0.18591f, 0.189824f, 0.193738f,
		0.197652f, 0.201566f, 0.20548f, 0.209393f, 0.213307f, 0.217221f,
		0.221135f, 0.225049f, 0.228963f, 0.232877f, 0.236791f, 0.240705f,
		0.244618f, 0.248532f, 0.252446f, 0.25636f, 0.260274f, 0.264188f,
		0.268102f, 0.272016f, 0.27593f, 0.279843f, 0.283757f, 0.287671f,
		0.291585f, 0.295499f, 0.299413f, 0.303327f, 0.307241f, 0.311155f,
		0.315068f, 0.318982f, 0.322896f, 0.32681f, 0.330724f, 0.334638f,
		0.338552f, 0.342466f, 0.34638f, 0.350294f, 0.354207f, 0.358121f,
		0.362035f, 0.365949f, 0.369863f, 0.373777f, 0.377691f, 0.381605f,
		0.385519f, 0.389432f, 0.393346f, 0.39726f, 0.401174f, 0.405088f,
		0.409002f, 0.412916f, 0.41683f, 0.420744f, 0.424658f, 0.428571f,
		0.432485f, 0.436399f, 0.440313f, 0.444227f, 0.448141f, 0.452055f,
		0.455969f, 0.459883f, 0.463796f, 0.46771f, 0.471624f, 0.475538f,
		0.479452f, 0.483366f, 0.48728f, 0.491194f, 0.495108f, 0.499022f,
		0.502935f, 0.506849f, 0.510763f, 0.514677f, 0.518591f, 0.522505f,
		0.526419f, 0.530333f, 0.534247f, 0.53816f, 0.542074f, 0.545988f,
		0.549902f, 0.553816f, 0.55773f, 0.561644f, 0.565558f, 0.569472f,
		0.573385f, 0.577299f, 0.581213f, 0.585127f, 0.589041f, 0.592955f,
		0.596869f, 0.600783f, 0.604697f, 0.608611f, 0.612525f, 0.616438f,
		0.620352f, 0.624266f, 0.62818f, 0.632094f, 0.636008f, 0.639922f,
		0.643836f, 0.64775f, 0.651663f, 0.655577f, 0.659491f, 0.663405f,
		0.667319f, 0.671233f, 0.675147f, 0.679061f, 0.682975f, 0.686888f,
		0.690802f, 0.694716f, 0.69863f, 0.702544f, 0.706458f, 0.710372f,
		0.714286f, 0.7182f, 0.722113f, 0.726027f, 0.729941f, 0.733855f,
		0.737769f, 0.741683f, 0.745597f, 0.749511f, 0.753425f, 0.757339f,
		0.761252f, 0.765166f, 0.76908f, 0.772994f, 0.776908f, 0.780822f,
		0.784736f, 0.78865f, 0.792564f, 0.796477f, 0.800391f, 0.804305f,
		0.808219f, 0.812133f, 0.816047f, 0.819961f, 0.823875f, 0.827789f,
		0.831703f, 0.835616f, 0.83953f, 0.843444f, 0.847358f, 0.851272f,
		0.855186f, 0.8591f, 0.863014f, 0.866928f, 0.870842f, 0.874755f,
		0.878669f, 0.882583f, 0.886497f, 0.890411f, 0.894325f, 0.898239f,
		0.902153f, 0.906067f, 0.90998f, 0.913894f, 0.917808f, 0.921722f,
		0.925636f, 0.92955f, 0.933464f, 0.937378f, 0.941292f, 0.945205f,
		0.949119f, 0.953033f, 0.956947f, 0.960861f, 0.964775f, 0.968689f,
		0.972603f, 0.976517f, 0.98043f, 0.984344f, 0.988258f, 0.992172f,
		0.996086f, 1.f
	};
};

template <int NV>
using cable_table_t = wrap::data<control::cable_table<cable_table_mod<NV>>, 
                                 data::embedded::table<cable_table_t_data>>;

DECLARE_PARAMETER_RANGE_STEP(cable_table1_modRange, 
                             1., 
                             32., 
                             1.);

template <int NV>
using cable_table1_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                             1, 
                                             cable_table1_modRange>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		1.f, 0.996086f, 0.992172f, 0.988258f, 0.984344f, 0.980431f,
		0.976517f, 0.972603f, 0.968689f, 0.964775f, 0.960861f, 0.956947f,
		0.953033f, 0.949119f, 0.945205f, 0.941292f, 0.937378f, 0.933464f,
		0.92955f, 0.925636f, 0.921722f, 0.917808f, 0.913894f, 0.90998f,
		0.906067f, 0.902153f, 0.898239f, 0.894325f, 0.890411f, 0.886497f,
		0.882583f, 0.878669f, 0.874755f, 0.870842f, 0.866928f, 0.863014f,
		0.8591f, 0.855186f, 0.851272f, 0.847358f, 0.843444f, 0.83953f,
		0.835616f, 0.831703f, 0.827789f, 0.823875f, 0.819961f, 0.816047f,
		0.812133f, 0.808219f, 0.804305f, 0.800391f, 0.796477f, 0.792564f,
		0.78865f, 0.784736f, 0.780822f, 0.776908f, 0.772994f, 0.76908f,
		0.765166f, 0.761252f, 0.757339f, 0.753425f, 0.749511f, 0.745597f,
		0.741683f, 0.737769f, 0.733855f, 0.729941f, 0.726027f, 0.722113f,
		0.7182f, 0.714286f, 0.710372f, 0.706458f, 0.702544f, 0.69863f,
		0.694716f, 0.690802f, 0.686888f, 0.682975f, 0.679061f, 0.675147f,
		0.671233f, 0.667319f, 0.663405f, 0.659491f, 0.655577f, 0.651663f,
		0.64775f, 0.643836f, 0.639922f, 0.636008f, 0.632094f, 0.62818f,
		0.624266f, 0.620352f, 0.616438f, 0.612524f, 0.608611f, 0.604697f,
		0.600783f, 0.596869f, 0.592955f, 0.589041f, 0.585127f, 0.581213f,
		0.577299f, 0.573385f, 0.569472f, 0.565558f, 0.561644f, 0.55773f,
		0.553816f, 0.549902f, 0.545988f, 0.542074f, 0.53816f, 0.534247f,
		0.530333f, 0.526419f, 0.522505f, 0.518591f, 0.514677f, 0.510763f,
		0.506849f, 0.502935f, 0.499022f, 0.495108f, 0.491194f, 0.48728f,
		0.483366f, 0.479452f, 0.475538f, 0.471624f, 0.46771f, 0.463796f,
		0.459883f, 0.455969f, 0.452055f, 0.448141f, 0.444227f, 0.440313f,
		0.436399f, 0.432485f, 0.428571f, 0.424658f, 0.420744f, 0.41683f,
		0.412916f, 0.409002f, 0.405088f, 0.401174f, 0.39726f, 0.393346f,
		0.389432f, 0.385519f, 0.381605f, 0.377691f, 0.373777f, 0.369863f,
		0.365949f, 0.362035f, 0.358121f, 0.354207f, 0.350294f, 0.34638f,
		0.342466f, 0.338552f, 0.334638f, 0.330724f, 0.32681f, 0.322896f,
		0.318982f, 0.315068f, 0.311155f, 0.307241f, 0.303327f, 0.299413f,
		0.295499f, 0.291585f, 0.287671f, 0.283757f, 0.279843f, 0.27593f,
		0.272016f, 0.268102f, 0.264188f, 0.260274f, 0.25636f, 0.252446f,
		0.248532f, 0.244618f, 0.240704f, 0.236791f, 0.232877f, 0.228963f,
		0.225049f, 0.221135f, 0.217221f, 0.213307f, 0.209393f, 0.205479f,
		0.201566f, 0.197652f, 0.193738f, 0.189824f, 0.18591f, 0.181996f,
		0.178082f, 0.174168f, 0.170254f, 0.166341f, 0.162427f, 0.158513f,
		0.154599f, 0.150685f, 0.146771f, 0.142857f, 0.138943f, 0.135029f,
		0.131115f, 0.127202f, 0.123288f, 0.119374f, 0.11546f, 0.111546f,
		0.107632f, 0.103718f, 0.0998043f, 0.0958903f, 0.0919765f, 0.0880627f,
		0.0841488f, 0.0802348f, 0.0763209f, 0.072407f, 0.0684931f, 0.0645792f,
		0.0606654f, 0.0567515f, 0.0528376f, 0.0489237f, 0.0450097f, 0.0410959f,
		0.037182f, 0.0332682f, 0.0293542f, 0.0254403f, 0.0215264f, 0.0176125f,
		0.0136986f, 0.00978482f, 0.00587088f, 0.00195694f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 1.f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<cable_table1_mod<NV>>, 
                                  data::embedded::table<cable_table1_t_data>>;

template <int NV>
using pma32_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<input_toggle1_t<NV>, 2>, 
                                   parameter::plain<minmax1_t<NV>, 0>, 
                                   parameter::plain<cable_table_t<NV>, 0>, 
                                   parameter::plain<cable_table1_t<NV>, 0>>;

template <int NV>
using pma32_t = control::pma<NV, pma32_mod<NV>>;
template <int NV>
using peak23_t = wrap::mod<parameter::plain<pma32_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain369_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch23_t<NV>>, 
                                    peak23_t<NV>, 
                                    pma32_t<NV>, 
                                    input_toggle1_t<NV>, 
                                    math::clear<NV>>;
using global_cable368_t_index = global_cable336_t_index;

template <int NV>
using global_cable368_t = routing::global_cable<global_cable368_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain404_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable368_t<NV>>, 
                                    math::add<NV>>;
using global_cable369_t_index = global_cable337_t_index;

template <int NV>
using global_cable369_t = routing::global_cable<global_cable369_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain405_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable369_t<NV>>, 
                                    math::add<NV>>;
using global_cable370_t_index = global_cable338_t_index;

template <int NV>
using global_cable370_t = routing::global_cable<global_cable370_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain406_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable370_t<NV>>, 
                                    math::add<NV>>;
using global_cable371_t_index = global_cable339_t_index;

template <int NV>
using global_cable371_t = routing::global_cable<global_cable371_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain407_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable371_t<NV>>, 
                                    math::add<NV>>;
using global_cable372_t_index = global_cable340_t_index;

template <int NV>
using global_cable372_t = routing::global_cable<global_cable372_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain408_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable372_t<NV>>, 
                                    math::add<NV>>;
using global_cable373_t_index = global_cable341_t_index;

template <int NV>
using global_cable373_t = routing::global_cable<global_cable373_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain409_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable373_t<NV>>, 
                                    math::add<NV>>;
using global_cable374_t_index = global_cable342_t_index;

template <int NV>
using global_cable374_t = routing::global_cable<global_cable374_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain410_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable374_t<NV>>, 
                                    math::add<NV>>;
using global_cable375_t_index = global_cable343_t_index;

template <int NV>
using global_cable375_t = routing::global_cable<global_cable375_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain411_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable375_t<NV>>, 
                                    math::add<NV>>;
using global_cable376_t_index = global_cable344_t_index;

template <int NV>
using global_cable376_t = routing::global_cable<global_cable376_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain412_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable376_t<NV>>, 
                                    math::add<NV>>;
using global_cable377_t_index = global_cable345_t_index;

template <int NV>
using global_cable377_t = routing::global_cable<global_cable377_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain413_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable377_t<NV>>, 
                                    math::add<NV>>;
using global_cable378_t_index = global_cable346_t_index;

template <int NV>
using global_cable378_t = routing::global_cable<global_cable378_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain414_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable378_t<NV>>, 
                                    math::add<NV>>;
using global_cable379_t_index = global_cable347_t_index;

template <int NV>
using global_cable379_t = routing::global_cable<global_cable379_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain415_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable379_t<NV>>, 
                                    math::add<NV>>;
using global_cable380_t_index = global_cable348_t_index;

template <int NV>
using global_cable380_t = routing::global_cable<global_cable380_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain416_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable380_t<NV>>, 
                                    math::add<NV>>;
using global_cable381_t_index = global_cable349_t_index;

template <int NV>
using global_cable381_t = routing::global_cable<global_cable381_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain417_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable381_t<NV>>, 
                                    math::add<NV>>;
using global_cable382_t_index = global_cable350_t_index;

template <int NV>
using global_cable382_t = routing::global_cable<global_cable382_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain418_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable382_t<NV>>, 
                                    math::add<NV>>;
using global_cable383_t_index = global_cable351_t_index;

template <int NV>
using global_cable383_t = routing::global_cable<global_cable383_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain419_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable383_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch25_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain404_t<NV>>, 
                                     chain405_t<NV>, 
                                     chain406_t<NV>, 
                                     chain407_t<NV>, 
                                     chain408_t<NV>, 
                                     chain409_t<NV>, 
                                     chain410_t<NV>, 
                                     chain411_t<NV>, 
                                     chain412_t<NV>, 
                                     chain413_t<NV>, 
                                     chain414_t<NV>, 
                                     chain415_t<NV>, 
                                     chain416_t<NV>, 
                                     chain417_t<NV>, 
                                     chain418_t<NV>, 
                                     chain419_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma35_mod_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma35_mod_0 = parameter::from0To1<filters::one_pole<NV>, 
                                        0, 
                                        pma35_mod_0Range>;

template <int NV> using pma35_mod_1 = pma35_mod_0<NV>;

template <int NV> using pma35_mod_2 = pma35_mod_0<NV>;

DECLARE_PARAMETER_RANGE_STEP(pma35_mod_3Range, 
                             0.125, 
                             4., 
                             0.001);

template <int NV>
using pma35_mod_3 = parameter::from0To1<project::granular<NV>, 
                                        3, 
                                        pma35_mod_3Range>;

template <int NV>
using pma35_mod = parameter::chain<ranges::Identity, 
                                   pma35_mod_0<NV>, 
                                   pma35_mod_1<NV>, 
                                   pma35_mod_2<NV>, 
                                   pma35_mod_3<NV>>;

template <int NV>
using pma35_t = control::pma<NV, pma35_mod<NV>>;
template <int NV>
using peak25_t = wrap::mod<parameter::plain<pma35_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain403_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch25_t<NV>>, 
                                    peak25_t<NV>, 
                                    pma35_t<NV>, 
                                    math::clear<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain369_t<NV>>, 
                                  chain403_t<NV>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split5_t<NV>>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;

template <int NV>
using converter1_t = control::converter<parameter::plain<input_toggle_t<NV>, 2>, 
                                        conversion_logic::freq2ms>;
template <int NV>
using converter_t = control::converter<parameter::plain<converter1_t<NV>, 0>, 
                                       conversion_logic::midi2freq>;
template <int NV>
using midi_t = wrap::mod<parameter::plain<converter_t<NV>, 0>, 
                         control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<2, midi_t<NV>>, 
                                      converter_t<NV>, 
                                      converter1_t<NV>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, midichain_t<NV>>, 
                                  minmax1_t<NV>, 
                                  input_toggle_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, chain1_t<NV>>>;

template <int NV> using xfader1_c0 = ahdsr_c0<NV>;

template <int NV> using xfader1_c1 = ahdsr_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::cosine>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;
using stereo_cable = cable::block<2>;

using comp_t = wrap::no_data<dynamics::comp>;
template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<comp_t, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax4_t<NV>>, 
                                  fx::haas<NV>, 
                                  filters::one_pole<NV>, 
                                  minmax_t<NV>, 
                                  comp_t, 
                                  routing::send<stereo_cable>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, routing::receive<stereo_cable>>, 
                                  core::fix_delay, 
                                  chain8_t<NV>>;

template <int NV>
using dynamic_blocksize3_t_ = container::chain<parameter::empty, 
                                               wrap::fix<2, chain3_t<NV>>>;

template <int NV>
using dynamic_blocksize3_t = wrap::dynamic_blocksize<dynamic_blocksize3_t_<NV>>;

using comp2_t = comp_t;
template <int NV>
using minmax3_t = control::minmax<NV, 
                                  parameter::plain<comp2_t, 0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   core::fix_delay, 
                                   fx::phase_delay<NV>, 
                                   filters::one_pole<NV>, 
                                   minmax3_t<NV>, 
                                   comp2_t, 
                                   routing::send<stereo_cable>>;

template <int NV>
using dynamic_blocksize_t_ = container::chain<parameter::empty, 
                                              wrap::fix<2, chain13_t<NV>>>;

template <int NV>
using dynamic_blocksize_t = wrap::dynamic_blocksize<dynamic_blocksize_t_<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, jdsp::jdelay<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fx::phase_delay<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain15_t<NV>>, 
                                  chain16_t<NV>>;

using comp1_t = comp_t;
template <int NV>
using minmax2_t = control::minmax<NV, 
                                  parameter::plain<comp1_t, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<stereo_cable>>, 
                                   core::fix_delay, 
                                   split1_t<NV>, 
                                   filters::one_pole<NV>, 
                                   minmax2_t<NV>, 
                                   comp1_t, 
                                   routing::send<stereo_cable>>;

template <int NV>
using dynamic_blocksize2_t_ = container::chain<parameter::empty, 
                                               wrap::fix<2, chain14_t<NV>>>;

template <int NV>
using dynamic_blocksize2_t = wrap::dynamic_blocksize<dynamic_blocksize2_t_<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, cable_table_t<NV>>, 
                                  cable_table1_t<NV>, 
                                  tempo_sync_t<NV>, 
                                  project::granular<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<2, dynamic_blocksize3_t<NV>>, 
                                    dynamic_blocksize_t<NV>, 
                                    dynamic_blocksize2_t<NV>, 
                                    chain2_t<NV>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, branch3_t<NV>>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain5_t<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain6_t<NV>>, 
                                  chain7_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader1_t<NV>>, 
                                  split2_t<NV>>;

namespace res1_t_parameters
{
// Parameter list for res1_impl::res1_t ------------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(feed_3Range, 
                             0., 
                             2., 
                             0.001);

template <int NV>
using feed_3 = parameter::from0To1<project::granular<NV>, 
                                   1, 
                                   feed_3Range>;

template <int NV>
using feed = parameter::chain<ranges::Identity, 
                              parameter::plain<routing::receive<stereo_cable>, 0>, 
                              parameter::plain<routing::receive<stereo_cable>, 0>, 
                              parameter::plain<routing::receive<stereo_cable>, 0>, 
                              feed_3<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(Del_InputRange, 
                             0., 
                             1000., 
                             0.30103);
DECLARE_PARAMETER_RANGE(Del_0Range, 
                        5.55112e-17, 
                        1.);

template <int NV>
using Del_0 = parameter::from0To1<res1_impl::pma32_t<NV>, 
                                  2, 
                                  Del_0Range>;

template <int NV>
using Del = parameter::chain<Del_InputRange, Del_0<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(LP_InputRange, 
                             20., 
                             20000., 
                             0.229905);
template <int NV>
using LP_0 = parameter::from0To1<res1_impl::pma35_t<NV>, 
                                 2, 
                                 Del_0Range>;

template <int NV>
using LP = parameter::chain<LP_InputRange, LP_0<NV>>;

template <int NV>
using Freq = parameter::chain<ranges::Identity, 
                              parameter::plain<res1_impl::input_toggle1_t<NV>, 1>, 
                              parameter::plain<project::granular<NV>, 2>>;

template <int NV>
using Comp = parameter::chain<ranges::Identity, 
                              parameter::plain<res1_impl::minmax_t<NV>, 0>, 
                              parameter::plain<res1_impl::minmax3_t<NV>, 0>, 
                              parameter::plain<res1_impl::minmax2_t<NV>, 0>, 
                              parameter::plain<project::granular<NV>, 0>>;

template <int NV>
using mode = parameter::chain<ranges::Identity, 
                              parameter::plain<res1_impl::input_toggle_t<NV>, 0>, 
                              parameter::plain<res1_impl::input_toggle1_t<NV>, 0>>;

template <int NV>
using a = parameter::chain<ranges::Identity, 
                           parameter::plain<res1_impl::ahdsr1_t<NV>, 0>, 
                           parameter::plain<res1_impl::ahdsr_t<NV>, 0>>;

template <int NV>
using d = parameter::chain<ranges::Identity, 
                           parameter::plain<res1_impl::ahdsr1_t<NV>, 3>, 
                           parameter::plain<res1_impl::ahdsr_t<NV>, 3>, 
                           parameter::plain<res1_impl::ahdsr1_t<NV>, 5>, 
                           parameter::plain<res1_impl::ahdsr_t<NV>, 5>>;

template <int NV>
using s = parameter::chain<ranges::Identity, 
                           parameter::plain<res1_impl::ahdsr1_t<NV>, 4>, 
                           parameter::plain<res1_impl::ahdsr_t<NV>, 4>>;

DECLARE_PARAMETER_RANGE_STEP(Del1Src_InputRange, 
                             1., 
                             16., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Del1Src_0Range, 
                             0., 
                             15., 
                             1.);

template <int NV>
using Del1Src_0 = parameter::from0To1<res1_impl::branch23_t<NV>, 
                                      0, 
                                      Del1Src_0Range>;

template <int NV>
using Del1Src_1 = parameter::from0To1<res1_impl::chain369_t<NV>, 
                                      0, 
                                      Del1Src_0Range>;

template <int NV>
using Del1Src = parameter::chain<Del1Src_InputRange, 
                                 Del1Src_0<NV>, 
                                 Del1Src_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(LpSrc_InputRange, 
                             1., 
                             16., 
                             1.);
template <int NV>
using LpSrc_0 = parameter::from0To1<res1_impl::branch25_t<NV>, 
                                    0, 
                                    Del1Src_0Range>;

template <int NV>
using LpSrc_1 = parameter::from0To1<res1_impl::chain403_t<NV>, 
                                    0, 
                                    Del1Src_0Range>;

template <int NV>
using LpSrc = parameter::chain<LpSrc_InputRange, 
                               LpSrc_0<NV>, 
                               LpSrc_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(type_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(type_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using type_0 = parameter::from0To1<res1_impl::branch3_t<NV>, 
                                   0, 
                                   type_0Range>;

template <int NV>
using type = parameter::chain<type_InputRange, type_0<NV>>;

template <int NV>
using block = parameter::chain<ranges::Identity, 
                               parameter::plain<res1_impl::dynamic_blocksize3_t<NV>, 0>, 
                               parameter::plain<res1_impl::dynamic_blocksize_t<NV>, 0>, 
                               parameter::plain<res1_impl::dynamic_blocksize2_t<NV>, 0>>;

template <int NV>
using Del1Mod = parameter::plain<res1_impl::pma32_t<NV>, 1>;
template <int NV>
using LpMod = parameter::plain<res1_impl::pma35_t<NV>, 1>;
template <int NV>
using EnvPos = parameter::plain<res1_impl::xfader_t<NV>, 
                                0>;
template <int NV>
using Mix = parameter::plain<res1_impl::xfader1_t<NV>, 
                             0>;
template <int NV>
using res1_t_plist = parameter::list<feed<NV>, 
                                     Del<NV>, 
                                     LP<NV>, 
                                     Freq<NV>, 
                                     Comp<NV>, 
                                     mode<NV>, 
                                     a<NV>, 
                                     d<NV>, 
                                     s<NV>, 
                                     Del1Mod<NV>, 
                                     Del1Src<NV>, 
                                     LpMod<NV>, 
                                     LpSrc<NV>, 
                                     EnvPos<NV>, 
                                     type<NV>, 
                                     Mix<NV>, 
                                     block<NV>>;
}

template <int NV>
using res1_t_ = container::chain<res1_t_parameters::res1_t_plist<NV>, 
                                 wrap::fix<2, xfader_t<NV>>, 
                                 modchain3_t<NV>, 
                                 chain_t<NV>, 
                                 soft_bypass_t<NV>, 
                                 chain4_t<NV>, 
                                 soft_bypass1_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public res1_impl::res1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(res1);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(256)
		{
			0x005B, 0x0000, 0x6600, 0x6565, 0x0064, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x015B, 
            0x0000, 0x4400, 0x6C65, 0x0000, 0x0000, 0x0000, 0x7A00, 0x0044, 
            0xF380, 0x9B43, 0x9A20, 0xCD3E, 0xCCCC, 0x5B3D, 0x0002, 0x0000, 
            0x504C, 0x0000, 0xA000, 0x0041, 0x9C40, 0x0046, 0x9C40, 0x1A46, 
            0x6B6C, 0x003E, 0x0000, 0x5B00, 0x0003, 0x0000, 0x7246, 0x7165, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0004, 0x0000, 0x6F43, 0x706D, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0005, 0x0000, 0x6F6D, 0x6564, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0006, 0x0000, 0x0061, 0x0000, 0x0000, 0x4000, 0x461C, 
            0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x075B, 0x0000, 
            0x6400, 0x0000, 0x0000, 0x0000, 0x1C40, 0x0046, 0xFA00, 0x7244, 
            0x4A6A, 0xCD3E, 0xCCCC, 0x5B3D, 0x0008, 0x0000, 0x0073, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x095B, 0x0000, 0x4400, 0x6C65, 0x4D31, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x0A3F, 0x23D7, 0x00BC, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000A, 0x0000, 0x6544, 0x316C, 0x7253, 0x0063, 
            0x0000, 0x3F80, 0x0000, 0x4180, 0x0000, 0x40A0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0B5B, 0x0000, 0x4C00, 0x4D70, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000C, 0x0000, 0x704C, 0x7253, 0x0063, 0x0000, 
            0x3F80, 0x0000, 0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0D5B, 0x0000, 0x4500, 0x766E, 0x6F50, 0x0073, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0E5B, 0x0000, 0x7400, 0x7079, 0x0065, 0x0000, 0x3F80, 
            0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0F5B, 0x0000, 0x4D00, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0010, 
            0x0000, 0x6C62, 0x636F, 0x006B, 0x0000, 0x0000, 0x0000, 0x40E0, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& xfader = this->getT(0);                                                       // res1_impl::xfader_t<NV>
		auto& modchain3 = this->getT(1);                                                    // res1_impl::modchain3_t<NV>
		auto& split5 = this->getT(1).getT(0);                                               // res1_impl::split5_t<NV>
		auto& chain369 = this->getT(1).getT(0).getT(0);                                     // res1_impl::chain369_t<NV>
		auto& branch23 = this->getT(1).getT(0).getT(0).getT(0);                             // res1_impl::branch23_t<NV>
		auto& chain370 = this->getT(1).getT(0).getT(0).getT(0).getT(0);                     // res1_impl::chain370_t<NV>
		auto& global_cable336 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0);      // res1_impl::global_cable336_t<NV>
		auto& add330 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(1);               // math::add<NV>
		auto& chain371 = this->getT(1).getT(0).getT(0).getT(0).getT(1);                     // res1_impl::chain371_t<NV>
		auto& global_cable337 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(0);      // res1_impl::global_cable337_t<NV>
		auto& add331 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(1);               // math::add<NV>
		auto& chain372 = this->getT(1).getT(0).getT(0).getT(0).getT(2);                     // res1_impl::chain372_t<NV>
		auto& global_cable338 = this->getT(1).getT(0).getT(0).getT(0).getT(2).getT(0);      // res1_impl::global_cable338_t<NV>
		auto& add332 = this->getT(1).getT(0).getT(0).getT(0).getT(2).getT(1);               // math::add<NV>
		auto& chain373 = this->getT(1).getT(0).getT(0).getT(0).getT(3);                     // res1_impl::chain373_t<NV>
		auto& global_cable339 = this->getT(1).getT(0).getT(0).getT(0).getT(3).getT(0);      // res1_impl::global_cable339_t<NV>
		auto& add333 = this->getT(1).getT(0).getT(0).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& chain374 = this->getT(1).getT(0).getT(0).getT(0).getT(4);                     // res1_impl::chain374_t<NV>
		auto& global_cable340 = this->getT(1).getT(0).getT(0).getT(0).getT(4).getT(0);      // res1_impl::global_cable340_t<NV>
		auto& add334 = this->getT(1).getT(0).getT(0).getT(0).getT(4).getT(1);               // math::add<NV>
		auto& chain375 = this->getT(1).getT(0).getT(0).getT(0).getT(5);                     // res1_impl::chain375_t<NV>
		auto& global_cable341 = this->getT(1).getT(0).getT(0).getT(0).getT(5).getT(0);      // res1_impl::global_cable341_t<NV>
		auto& add335 = this->getT(1).getT(0).getT(0).getT(0).getT(5).getT(1);               // math::add<NV>
		auto& chain376 = this->getT(1).getT(0).getT(0).getT(0).getT(6);                     // res1_impl::chain376_t<NV>
		auto& global_cable342 = this->getT(1).getT(0).getT(0).getT(0).getT(6).getT(0);      // res1_impl::global_cable342_t<NV>
		auto& add336 = this->getT(1).getT(0).getT(0).getT(0).getT(6).getT(1);               // math::add<NV>
		auto& chain377 = this->getT(1).getT(0).getT(0).getT(0).getT(7);                     // res1_impl::chain377_t<NV>
		auto& global_cable343 = this->getT(1).getT(0).getT(0).getT(0).getT(7).getT(0);      // res1_impl::global_cable343_t<NV>
		auto& add337 = this->getT(1).getT(0).getT(0).getT(0).getT(7).getT(1);               // math::add<NV>
		auto& chain378 = this->getT(1).getT(0).getT(0).getT(0).getT(8);                     // res1_impl::chain378_t<NV>
		auto& global_cable344 = this->getT(1).getT(0).getT(0).getT(0).getT(8).getT(0);      // res1_impl::global_cable344_t<NV>
		auto& add338 = this->getT(1).getT(0).getT(0).getT(0).getT(8).getT(1);               // math::add<NV>
		auto& chain379 = this->getT(1).getT(0).getT(0).getT(0).getT(9);                     // res1_impl::chain379_t<NV>
		auto& global_cable345 = this->getT(1).getT(0).getT(0).getT(0).getT(9).getT(0);      // res1_impl::global_cable345_t<NV>
		auto& add339 = this->getT(1).getT(0).getT(0).getT(0).getT(9).getT(1);               // math::add<NV>
		auto& chain380 = this->getT(1).getT(0).getT(0).getT(0).getT(10);                    // res1_impl::chain380_t<NV>
		auto& global_cable346 = this->getT(1).getT(0).getT(0).getT(0).getT(10).getT(0);     // res1_impl::global_cable346_t<NV>
		auto& add340 = this->getT(1).getT(0).getT(0).getT(0).getT(10).getT(1);              // math::add<NV>
		auto& chain381 = this->getT(1).getT(0).getT(0).getT(0).getT(11);                    // res1_impl::chain381_t<NV>
		auto& global_cable347 = this->getT(1).getT(0).getT(0).getT(0).getT(11).getT(0);     // res1_impl::global_cable347_t<NV>
		auto& add341 = this->getT(1).getT(0).getT(0).getT(0).getT(11).getT(1);              // math::add<NV>
		auto& chain382 = this->getT(1).getT(0).getT(0).getT(0).getT(12);                    // res1_impl::chain382_t<NV>
		auto& global_cable348 = this->getT(1).getT(0).getT(0).getT(0).getT(12).getT(0);     // res1_impl::global_cable348_t<NV>
		auto& add342 = this->getT(1).getT(0).getT(0).getT(0).getT(12).getT(1);              // math::add<NV>
		auto& chain383 = this->getT(1).getT(0).getT(0).getT(0).getT(13);                    // res1_impl::chain383_t<NV>
		auto& global_cable349 = this->getT(1).getT(0).getT(0).getT(0).getT(13).getT(0);     // res1_impl::global_cable349_t<NV>
		auto& add343 = this->getT(1).getT(0).getT(0).getT(0).getT(13).getT(1);              // math::add<NV>
		auto& chain384 = this->getT(1).getT(0).getT(0).getT(0).getT(14);                    // res1_impl::chain384_t<NV>
		auto& global_cable350 = this->getT(1).getT(0).getT(0).getT(0).getT(14).getT(0);     // res1_impl::global_cable350_t<NV>
		auto& add344 = this->getT(1).getT(0).getT(0).getT(0).getT(14).getT(1);              // math::add<NV>
		auto& chain385 = this->getT(1).getT(0).getT(0).getT(0).getT(15);                    // res1_impl::chain385_t<NV>
		auto& global_cable351 = this->getT(1).getT(0).getT(0).getT(0).getT(15).getT(0);     // res1_impl::global_cable351_t<NV>
		auto& add345 = this->getT(1).getT(0).getT(0).getT(0).getT(15).getT(1);              // math::add<NV>
		auto& peak23 = this->getT(1).getT(0).getT(0).getT(1);                               // res1_impl::peak23_t<NV>
		auto& pma32 = this->getT(1).getT(0).getT(0).getT(2);                                // res1_impl::pma32_t<NV>
		auto& input_toggle1 = this->getT(1).getT(0).getT(0).getT(3);                        // res1_impl::input_toggle1_t<NV>
		auto& clear42 = this->getT(1).getT(0).getT(0).getT(4);                              // math::clear<NV>
		auto& chain403 = this->getT(1).getT(0).getT(1);                                     // res1_impl::chain403_t<NV>
		auto& branch25 = this->getT(1).getT(0).getT(1).getT(0);                             // res1_impl::branch25_t<NV>
		auto& chain404 = this->getT(1).getT(0).getT(1).getT(0).getT(0);                     // res1_impl::chain404_t<NV>
		auto& global_cable368 = this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(0);      // res1_impl::global_cable368_t<NV>
		auto& add362 = this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(1);               // math::add<NV>
		auto& chain405 = this->getT(1).getT(0).getT(1).getT(0).getT(1);                     // res1_impl::chain405_t<NV>
		auto& global_cable369 = this->getT(1).getT(0).getT(1).getT(0).getT(1).getT(0);      // res1_impl::global_cable369_t<NV>
		auto& add363 = this->getT(1).getT(0).getT(1).getT(0).getT(1).getT(1);               // math::add<NV>
		auto& chain406 = this->getT(1).getT(0).getT(1).getT(0).getT(2);                     // res1_impl::chain406_t<NV>
		auto& global_cable370 = this->getT(1).getT(0).getT(1).getT(0).getT(2).getT(0);      // res1_impl::global_cable370_t<NV>
		auto& add364 = this->getT(1).getT(0).getT(1).getT(0).getT(2).getT(1);               // math::add<NV>
		auto& chain407 = this->getT(1).getT(0).getT(1).getT(0).getT(3);                     // res1_impl::chain407_t<NV>
		auto& global_cable371 = this->getT(1).getT(0).getT(1).getT(0).getT(3).getT(0);      // res1_impl::global_cable371_t<NV>
		auto& add365 = this->getT(1).getT(0).getT(1).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& chain408 = this->getT(1).getT(0).getT(1).getT(0).getT(4);                     // res1_impl::chain408_t<NV>
		auto& global_cable372 = this->getT(1).getT(0).getT(1).getT(0).getT(4).getT(0);      // res1_impl::global_cable372_t<NV>
		auto& add366 = this->getT(1).getT(0).getT(1).getT(0).getT(4).getT(1);               // math::add<NV>
		auto& chain409 = this->getT(1).getT(0).getT(1).getT(0).getT(5);                     // res1_impl::chain409_t<NV>
		auto& global_cable373 = this->getT(1).getT(0).getT(1).getT(0).getT(5).getT(0);      // res1_impl::global_cable373_t<NV>
		auto& add367 = this->getT(1).getT(0).getT(1).getT(0).getT(5).getT(1);               // math::add<NV>
		auto& chain410 = this->getT(1).getT(0).getT(1).getT(0).getT(6);                     // res1_impl::chain410_t<NV>
		auto& global_cable374 = this->getT(1).getT(0).getT(1).getT(0).getT(6).getT(0);      // res1_impl::global_cable374_t<NV>
		auto& add368 = this->getT(1).getT(0).getT(1).getT(0).getT(6).getT(1);               // math::add<NV>
		auto& chain411 = this->getT(1).getT(0).getT(1).getT(0).getT(7);                     // res1_impl::chain411_t<NV>
		auto& global_cable375 = this->getT(1).getT(0).getT(1).getT(0).getT(7).getT(0);      // res1_impl::global_cable375_t<NV>
		auto& add369 = this->getT(1).getT(0).getT(1).getT(0).getT(7).getT(1);               // math::add<NV>
		auto& chain412 = this->getT(1).getT(0).getT(1).getT(0).getT(8);                     // res1_impl::chain412_t<NV>
		auto& global_cable376 = this->getT(1).getT(0).getT(1).getT(0).getT(8).getT(0);      // res1_impl::global_cable376_t<NV>
		auto& add370 = this->getT(1).getT(0).getT(1).getT(0).getT(8).getT(1);               // math::add<NV>
		auto& chain413 = this->getT(1).getT(0).getT(1).getT(0).getT(9);                     // res1_impl::chain413_t<NV>
		auto& global_cable377 = this->getT(1).getT(0).getT(1).getT(0).getT(9).getT(0);      // res1_impl::global_cable377_t<NV>
		auto& add371 = this->getT(1).getT(0).getT(1).getT(0).getT(9).getT(1);               // math::add<NV>
		auto& chain414 = this->getT(1).getT(0).getT(1).getT(0).getT(10);                    // res1_impl::chain414_t<NV>
		auto& global_cable378 = this->getT(1).getT(0).getT(1).getT(0).getT(10).getT(0);     // res1_impl::global_cable378_t<NV>
		auto& add372 = this->getT(1).getT(0).getT(1).getT(0).getT(10).getT(1);              // math::add<NV>
		auto& chain415 = this->getT(1).getT(0).getT(1).getT(0).getT(11);                    // res1_impl::chain415_t<NV>
		auto& global_cable379 = this->getT(1).getT(0).getT(1).getT(0).getT(11).getT(0);     // res1_impl::global_cable379_t<NV>
		auto& add373 = this->getT(1).getT(0).getT(1).getT(0).getT(11).getT(1);              // math::add<NV>
		auto& chain416 = this->getT(1).getT(0).getT(1).getT(0).getT(12);                    // res1_impl::chain416_t<NV>
		auto& global_cable380 = this->getT(1).getT(0).getT(1).getT(0).getT(12).getT(0);     // res1_impl::global_cable380_t<NV>
		auto& add374 = this->getT(1).getT(0).getT(1).getT(0).getT(12).getT(1);              // math::add<NV>
		auto& chain417 = this->getT(1).getT(0).getT(1).getT(0).getT(13);                    // res1_impl::chain417_t<NV>
		auto& global_cable381 = this->getT(1).getT(0).getT(1).getT(0).getT(13).getT(0);     // res1_impl::global_cable381_t<NV>
		auto& add375 = this->getT(1).getT(0).getT(1).getT(0).getT(13).getT(1);              // math::add<NV>
		auto& chain418 = this->getT(1).getT(0).getT(1).getT(0).getT(14);                    // res1_impl::chain418_t<NV>
		auto& global_cable382 = this->getT(1).getT(0).getT(1).getT(0).getT(14).getT(0);     // res1_impl::global_cable382_t<NV>
		auto& add376 = this->getT(1).getT(0).getT(1).getT(0).getT(14).getT(1);              // math::add<NV>
		auto& chain419 = this->getT(1).getT(0).getT(1).getT(0).getT(15);                    // res1_impl::chain419_t<NV>
		auto& global_cable383 = this->getT(1).getT(0).getT(1).getT(0).getT(15).getT(0);     // res1_impl::global_cable383_t<NV>
		auto& add377 = this->getT(1).getT(0).getT(1).getT(0).getT(15).getT(1);              // math::add<NV>
		auto& peak25 = this->getT(1).getT(0).getT(1).getT(1);                               // res1_impl::peak25_t<NV>
		auto& pma35 = this->getT(1).getT(0).getT(1).getT(2);                                // res1_impl::pma35_t<NV>
		auto& clear45 = this->getT(1).getT(0).getT(1).getT(3);                              // math::clear<NV>
		auto& chain = this->getT(2);                                                        // res1_impl::chain_t<NV>
		auto& chain1 = this->getT(2).getT(0);                                               // res1_impl::chain1_t<NV>
		auto& midichain = this->getT(2).getT(0).getT(0);                                    // res1_impl::midichain_t<NV>
		auto& midi = this->getT(2).getT(0).getT(0).getT(0);                                 // res1_impl::midi_t<NV>
		auto& converter = this->getT(2).getT(0).getT(0).getT(1);                            // res1_impl::converter_t<NV>
		auto& converter1 = this->getT(2).getT(0).getT(0).getT(2);                           // res1_impl::converter1_t<NV>
		auto& minmax1 = this->getT(2).getT(0).getT(1);                                      // res1_impl::minmax1_t<NV>
		auto& input_toggle = this->getT(2).getT(0).getT(2);                                 // res1_impl::input_toggle_t<NV>
		auto& soft_bypass = this->getT(3);                                                  // res1_impl::soft_bypass_t<NV>
		auto& midichain2 = this->getT(3).getT(0);                                           // res1_impl::midichain2_t<NV>
		auto& ahdsr = this->getT(3).getT(0).getT(0);                                        // res1_impl::ahdsr_t<NV>
		auto& gain1 = this->getT(3).getT(1);                                                // core::gain<NV>
		auto& chain4 = this->getT(4);                                                       // res1_impl::chain4_t<NV>
		auto& xfader1 = this->getT(4).getT(0);                                              // res1_impl::xfader1_t<NV>
		auto& split2 = this->getT(4).getT(1);                                               // res1_impl::split2_t<NV>
		auto& chain6 = this->getT(4).getT(1).getT(0);                                       // res1_impl::chain6_t<NV>
		auto& gain4 = this->getT(4).getT(1).getT(0).getT(0);                                // core::gain<NV>
		auto& chain7 = this->getT(4).getT(1).getT(1);                                       // res1_impl::chain7_t<NV>
		auto& chain5 = this->getT(4).getT(1).getT(1).getT(0);                               // res1_impl::chain5_t<NV>
		auto& branch3 = this->getT(4).getT(1).getT(1).getT(0).getT(0);                      // res1_impl::branch3_t<NV>
		auto& dynamic_blocksize3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(0);   // res1_impl::dynamic_blocksize3_t<NV>
		auto& chain3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(0).getT(0);       // res1_impl::chain3_t<NV>
		auto& receive = this->getT(4).getT(1).getT(1).getT(0).                              // routing::receive<stereo_cable>
                        getT(0).getT(0).getT(0).getT(0);
		auto& fix_delay = this->getT(4).getT(1).getT(1).getT(0).                            // core::fix_delay
                          getT(0).getT(0).getT(0).getT(1);
		auto& chain8 = this->getT(4).getT(1).getT(1).getT(0).                               // res1_impl::chain8_t<NV>
                       getT(0).getT(0).getT(0).getT(2);
		auto& minmax4 = this->getT(4).getT(1).getT(1).getT(0).                              // res1_impl::minmax4_t<NV>
                        getT(0).getT(0).getT(0).getT(2).
                        getT(0);
		auto& haas = this->getT(4).getT(1).getT(1).getT(0).                                 // fx::haas<NV>
                     getT(0).getT(0).getT(0).getT(2).
                     getT(1);
		auto& one_pole145 = this->getT(4).getT(1).getT(1).getT(0).                          // filters::one_pole<NV>
                            getT(0).getT(0).getT(0).getT(2).
                            getT(2);
		auto& minmax = this->getT(4).getT(1).getT(1).getT(0).                               // res1_impl::minmax_t<NV>
                       getT(0).getT(0).getT(0).getT(2).
                       getT(3);
		auto& comp = this->getT(4).getT(1).getT(1).getT(0).                                 // res1_impl::comp_t
                     getT(0).getT(0).getT(0).getT(2).
                     getT(4);
		auto& send3 = this->getT(4).getT(1).getT(1).getT(0).                                // routing::send<stereo_cable>
                      getT(0).getT(0).getT(0).getT(2).
                      getT(5);
		auto& dynamic_blocksize = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(1);    // res1_impl::dynamic_blocksize_t<NV>
		auto& chain13 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(1).getT(0);      // res1_impl::chain13_t<NV>
		auto& receive1 = this->getT(4).getT(1).getT(1).getT(0).                             // routing::receive<stereo_cable>
                         getT(0).getT(1).getT(0).getT(0);
		auto& fix_delay1 = this->getT(4).getT(1).getT(1).getT(0).                           // core::fix_delay
                           getT(0).getT(1).getT(0).getT(1);
		auto& phase_delay1 = this->getT(4).getT(1).getT(1).getT(0).                         // fx::phase_delay<NV>
                             getT(0).getT(1).getT(0).getT(2);
		auto& one_pole147 = this->getT(4).getT(1).getT(1).getT(0).                          // filters::one_pole<NV>
                            getT(0).getT(1).getT(0).getT(3);
		auto& minmax3 = this->getT(4).getT(1).getT(1).getT(0).                              // res1_impl::minmax3_t<NV>
                        getT(0).getT(1).getT(0).getT(4);
		auto& comp2 = this->getT(4).getT(1).getT(1).getT(0).                                // res1_impl::comp2_t
                      getT(0).getT(1).getT(0).getT(5);
		auto& send = this->getT(4).getT(1).getT(1).getT(0).                                 // routing::send<stereo_cable>
                     getT(0).getT(1).getT(0).getT(6);
		auto& dynamic_blocksize2 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(2);   // res1_impl::dynamic_blocksize2_t<NV>
		auto& chain14 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(2).getT(0);      // res1_impl::chain14_t<NV>
		auto& receive2 = this->getT(4).getT(1).getT(1).getT(0).                             // routing::receive<stereo_cable>
                         getT(0).getT(2).getT(0).getT(0);
		auto& fix_delay3 = this->getT(4).getT(1).getT(1).getT(0).                           // core::fix_delay
                           getT(0).getT(2).getT(0).getT(1);
		auto& split1 = this->getT(4).getT(1).getT(1).getT(0).                               // res1_impl::split1_t<NV>
                       getT(0).getT(2).getT(0).getT(2);
		auto& chain15 = this->getT(4).getT(1).getT(1).getT(0).                              // res1_impl::chain15_t<NV>
                        getT(0).getT(2).getT(0).getT(2).
                        getT(0);
		auto& jdelay3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                      // jdsp::jdelay<NV>
                        getT(2).getT(0).getT(2).getT(0).getT(0);
		auto& gain2 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                        // core::gain<NV>
                      getT(2).getT(0).getT(2).getT(0).getT(1);
		auto& chain16 = this->getT(4).getT(1).getT(1).getT(0).                              // res1_impl::chain16_t<NV>
                        getT(0).getT(2).getT(0).getT(2).
                        getT(1);
		auto& phase_delay3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                 // fx::phase_delay<NV>
                             getT(2).getT(0).getT(2).getT(1).getT(0);
		auto& gain3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).                        // core::gain<NV>
                      getT(2).getT(0).getT(2).getT(1).getT(1);
		auto& one_pole146 = this->getT(4).getT(1).getT(1).getT(0).                          // filters::one_pole<NV>
                            getT(0).getT(2).getT(0).getT(3);
		auto& minmax2 = this->getT(4).getT(1).getT(1).getT(0).                              // res1_impl::minmax2_t<NV>
                        getT(0).getT(2).getT(0).getT(4);
		auto& comp1 = this->getT(4).getT(1).getT(1).getT(0).                                // res1_impl::comp1_t
                      getT(0).getT(2).getT(0).getT(5);
		auto& send1 = this->getT(4).getT(1).getT(1).getT(0).                                // routing::send<stereo_cable>
                      getT(0).getT(2).getT(0).getT(6);
		auto& chain2 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(3);               // res1_impl::chain2_t<NV>
		auto& cable_table = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(3).getT(0);  // res1_impl::cable_table_t<NV>
		auto& cable_table1 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(3).getT(1); // res1_impl::cable_table1_t<NV>
		auto& tempo_sync = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(3).getT(2);   // res1_impl::tempo_sync_t<NV>
		auto& faust = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(3).getT(3);        // project::granular<NV>
		auto& gain5 = this->getT(4).getT(1).getT(1).getT(1);                                // core::gain<NV>
		auto& soft_bypass1 = this->getT(5);                                                 // res1_impl::soft_bypass1_t<NV>
		auto& midichain3 = this->getT(5).getT(0);                                           // res1_impl::midichain3_t<NV>
		auto& ahdsr1 = this->getT(5).getT(0).getT(0);                                       // res1_impl::ahdsr1_t<NV>
		auto& gain = this->getT(5).getT(1);                                                 // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& feed_p = this->getParameterT(0);
		feed_p.connectT(0, receive);  // feed -> receive::Feedback
		feed_p.connectT(1, receive1); // feed -> receive1::Feedback
		feed_p.connectT(2, receive2); // feed -> receive2::Feedback
		feed_p.connectT(3, faust);    // feed -> faust::feedback
		
		this->getParameterT(1).connectT(0, pma32); // Del -> pma32::Add
		
		this->getParameterT(2).connectT(0, pma35); // LP -> pma35::Add
		
		auto& Freq_p = this->getParameterT(3);
		Freq_p.connectT(0, input_toggle1); // Freq -> input_toggle1::Value1
		Freq_p.connectT(1, faust);         // Freq -> faust::population
		
		auto& Comp_p = this->getParameterT(4);
		Comp_p.connectT(0, minmax);  // Comp -> minmax::Value
		Comp_p.connectT(1, minmax3); // Comp -> minmax3::Value
		Comp_p.connectT(2, minmax2); // Comp -> minmax2::Value
		Comp_p.connectT(3, faust);   // Comp -> faust::decal
		
		auto& mode_p = this->getParameterT(5);
		mode_p.connectT(0, input_toggle);  // mode -> input_toggle::Input
		mode_p.connectT(1, input_toggle1); // mode -> input_toggle1::Input
		
		auto& a_p = this->getParameterT(6);
		a_p.connectT(0, ahdsr1); // a -> ahdsr1::Attack
		a_p.connectT(1, ahdsr);  // a -> ahdsr::Attack
		
		auto& d_p = this->getParameterT(7);
		d_p.connectT(0, ahdsr1); // d -> ahdsr1::Decay
		d_p.connectT(1, ahdsr);  // d -> ahdsr::Decay
		d_p.connectT(2, ahdsr1); // d -> ahdsr1::Release
		d_p.connectT(3, ahdsr);  // d -> ahdsr::Release
		
		auto& s_p = this->getParameterT(8);
		s_p.connectT(0, ahdsr1); // s -> ahdsr1::Sustain
		s_p.connectT(1, ahdsr);  // s -> ahdsr::Sustain
		
		this->getParameterT(9).connectT(0, pma32); // Del1Mod -> pma32::Multiply
		
		auto& Del1Src_p = this->getParameterT(10);
		Del1Src_p.connectT(0, branch23); // Del1Src -> branch23::Index
		Del1Src_p.connectT(1, chain369); // Del1Src -> chain369::ModSrc
		
		this->getParameterT(11).connectT(0, pma35); // LpMod -> pma35::Multiply
		
		auto& LpSrc_p = this->getParameterT(12);
		LpSrc_p.connectT(0, branch25); // LpSrc -> branch25::Index
		LpSrc_p.connectT(1, chain403); // LpSrc -> chain403::ModSrc
		
		this->getParameterT(13).connectT(0, xfader); // EnvPos -> xfader::Value
		
		this->getParameterT(14).connectT(0, branch3); // type -> branch3::Index
		
		this->getParameterT(15).connectT(0, xfader1); // Mix -> xfader1::Value
		
		auto& block_p = this->getParameterT(16);
		block_p.connectT(0, dynamic_blocksize3); // block -> dynamic_blocksize3::BlockSize
		block_p.connectT(1, dynamic_blocksize);  // block -> dynamic_blocksize::BlockSize
		block_p.connectT(2, dynamic_blocksize2); // block -> dynamic_blocksize2::BlockSize
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, gain1); // ahdsr -> gain1::Gain
		auto& ahdsr1_p = ahdsr1.getWrappedObject().getParameter();
		ahdsr1_p.getParameterT(0).connectT(0, gain); // ahdsr1 -> gain::Gain
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, soft_bypass);                        // xfader -> soft_bypass::Bypassed
		xfader_p.getParameterT(1).connectT(0, soft_bypass1);                       // xfader -> soft_bypass1::Bypassed
		global_cable336.getWrappedObject().getParameter().connectT(0, add330);     // global_cable336 -> add330::Value
		global_cable337.getWrappedObject().getParameter().connectT(0, add331);     // global_cable337 -> add331::Value
		global_cable338.getWrappedObject().getParameter().connectT(0, add332);     // global_cable338 -> add332::Value
		global_cable339.getWrappedObject().getParameter().connectT(0, add333);     // global_cable339 -> add333::Value
		global_cable340.getWrappedObject().getParameter().connectT(0, add334);     // global_cable340 -> add334::Value
		global_cable341.getWrappedObject().getParameter().connectT(0, add335);     // global_cable341 -> add335::Value
		global_cable342.getWrappedObject().getParameter().connectT(0, add336);     // global_cable342 -> add336::Value
		global_cable343.getWrappedObject().getParameter().connectT(0, add337);     // global_cable343 -> add337::Value
		global_cable344.getWrappedObject().getParameter().connectT(0, add338);     // global_cable344 -> add338::Value
		global_cable345.getWrappedObject().getParameter().connectT(0, add339);     // global_cable345 -> add339::Value
		global_cable346.getWrappedObject().getParameter().connectT(0, add340);     // global_cable346 -> add340::Value
		global_cable347.getWrappedObject().getParameter().connectT(0, add341);     // global_cable347 -> add341::Value
		global_cable348.getWrappedObject().getParameter().connectT(0, add342);     // global_cable348 -> add342::Value
		global_cable349.getWrappedObject().getParameter().connectT(0, add343);     // global_cable349 -> add343::Value
		global_cable350.getWrappedObject().getParameter().connectT(0, add344);     // global_cable350 -> add344::Value
		global_cable351.getWrappedObject().getParameter().connectT(0, add345);     // global_cable351 -> add345::Value
		minmax4.getWrappedObject().getParameter().connectT(0, haas);               // minmax4 -> haas::Position
		input_toggle1.getWrappedObject().getParameter().connectT(0, minmax4);      // input_toggle1 -> minmax4::Value
		input_toggle1.getWrappedObject().getParameter().connectT(1, phase_delay1); // input_toggle1 -> phase_delay1::Frequency
		input_toggle1.getWrappedObject().getParameter().connectT(2, phase_delay3); // input_toggle1 -> phase_delay3::Frequency
		input_toggle.getWrappedObject().getParameter().connectT(0, fix_delay);     // input_toggle -> fix_delay::DelayTime
		input_toggle.getWrappedObject().getParameter().connectT(1, jdelay3);       // input_toggle -> jdelay3::DelayTime
		input_toggle.getWrappedObject().getParameter().connectT(2, fix_delay3);    // input_toggle -> fix_delay3::DelayTime
		input_toggle.getWrappedObject().getParameter().connectT(3, fix_delay1);    // input_toggle -> fix_delay1::DelayTime
		minmax1.getWrappedObject().getParameter().connectT(0, input_toggle);       // minmax1 -> input_toggle::Value1
		tempo_sync.getParameter().connectT(0, faust);                              // tempo_sync -> faust::taille
		cable_table.getWrappedObject().getParameter().connectT(0, tempo_sync);     // cable_table -> tempo_sync::Tempo
		cable_table1.getWrappedObject().getParameter().connectT(0, tempo_sync);    // cable_table1 -> tempo_sync::Multiplier
		pma32.getWrappedObject().getParameter().connectT(0, input_toggle1);        // pma32 -> input_toggle1::Value2
		pma32.getWrappedObject().getParameter().connectT(1, minmax1);              // pma32 -> minmax1::Value
		pma32.getWrappedObject().getParameter().connectT(2, cable_table);          // pma32 -> cable_table::Value
		pma32.getWrappedObject().getParameter().connectT(3, cable_table1);         // pma32 -> cable_table1::Value
		peak23.getParameter().connectT(0, pma32);                                  // peak23 -> pma32::Value
		global_cable368.getWrappedObject().getParameter().connectT(0, add362);     // global_cable368 -> add362::Value
		global_cable369.getWrappedObject().getParameter().connectT(0, add363);     // global_cable369 -> add363::Value
		global_cable370.getWrappedObject().getParameter().connectT(0, add364);     // global_cable370 -> add364::Value
		global_cable371.getWrappedObject().getParameter().connectT(0, add365);     // global_cable371 -> add365::Value
		global_cable372.getWrappedObject().getParameter().connectT(0, add366);     // global_cable372 -> add366::Value
		global_cable373.getWrappedObject().getParameter().connectT(0, add367);     // global_cable373 -> add367::Value
		global_cable374.getWrappedObject().getParameter().connectT(0, add368);     // global_cable374 -> add368::Value
		global_cable375.getWrappedObject().getParameter().connectT(0, add369);     // global_cable375 -> add369::Value
		global_cable376.getWrappedObject().getParameter().connectT(0, add370);     // global_cable376 -> add370::Value
		global_cable377.getWrappedObject().getParameter().connectT(0, add371);     // global_cable377 -> add371::Value
		global_cable378.getWrappedObject().getParameter().connectT(0, add372);     // global_cable378 -> add372::Value
		global_cable379.getWrappedObject().getParameter().connectT(0, add373);     // global_cable379 -> add373::Value
		global_cable380.getWrappedObject().getParameter().connectT(0, add374);     // global_cable380 -> add374::Value
		global_cable381.getWrappedObject().getParameter().connectT(0, add375);     // global_cable381 -> add375::Value
		global_cable382.getWrappedObject().getParameter().connectT(0, add376);     // global_cable382 -> add376::Value
		global_cable383.getWrappedObject().getParameter().connectT(0, add377);     // global_cable383 -> add377::Value
		pma35.getWrappedObject().getParameter().connectT(0, one_pole145);          // pma35 -> one_pole145::Frequency
		pma35.getWrappedObject().getParameter().connectT(1, one_pole147);          // pma35 -> one_pole147::Frequency
		pma35.getWrappedObject().getParameter().connectT(2, one_pole146);          // pma35 -> one_pole146::Frequency
		pma35.getWrappedObject().getParameter().connectT(3, faust);                // pma35 -> faust::speed
		peak25.getParameter().connectT(0, pma35);                                  // peak25 -> pma35::Value
		converter1.getWrappedObject().getParameter().connectT(0, input_toggle);    // converter1 -> input_toggle::Value2
		converter.getWrappedObject().getParameter().connectT(0, converter1);       // converter -> converter1::Value
		midi.getParameter().connectT(0, converter);                                // midi -> converter::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain4);                // xfader1 -> gain4::Gain
		xfader1_p.getParameterT(1).connectT(0, gain5);                // xfader1 -> gain5::Gain
		minmax.getWrappedObject().getParameter().connectT(0, comp);   // minmax -> comp::Threshhold
		minmax3.getWrappedObject().getParameter().connectT(0, comp2); // minmax3 -> comp2::Threshhold
		minmax2.getWrappedObject().getParameter().connectT(0, comp1); // minmax2 -> comp1::Threshhold
		
		// Send Connections ------------------------------------------------------------------------
		
		send3.connect(receive);
		send.connect(receive1);
		send1.connect(receive2);
		
		// Default Values --------------------------------------------------------------------------
		
		; // xfader::Value is automated
		
		; // chain369::ModSrc is automated
		
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
		
		; // input_toggle1::Input is automated
		; // input_toggle1::Value1 is automated
		; // input_toggle1::Value2 is automated
		
		clear42.setParameterT(0, 0.); // math::clear::Value
		
		; // chain403::ModSrc is automated
		
		; // branch25::Index is automated
		
		global_cable368.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add362::Value is automated
		
		global_cable369.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add363::Value is automated
		
		global_cable370.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add364::Value is automated
		
		global_cable371.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add365::Value is automated
		
		global_cable372.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add366::Value is automated
		
		global_cable373.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add367::Value is automated
		
		global_cable374.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add368::Value is automated
		
		global_cable375.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add369::Value is automated
		
		global_cable376.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add370::Value is automated
		
		global_cable377.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add371::Value is automated
		
		global_cable378.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add372::Value is automated
		
		global_cable379.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add373::Value is automated
		
		global_cable380.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add374::Value is automated
		
		global_cable381.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add375::Value is automated
		
		global_cable382.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add376::Value is automated
		
		global_cable383.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add377::Value is automated
		
		; // pma35::Value is automated
		; // pma35::Multiply is automated
		; // pma35::Add is automated
		
		clear45.setParameterT(0, 0.); // math::clear::Value
		
		; // converter::Value is automated
		
		; // converter1::Value is automated
		
		;                                   // minmax1::Value is automated
		minmax1.setParameterT(1, 0.);       // control::minmax::Minimum
		minmax1.setParameterT(2, 1000.);    // control::minmax::Maximum
		minmax1.setParameterT(3, 0.366302); // control::minmax::Skew
		minmax1.setParameterT(4, 0.);       // control::minmax::Step
		minmax1.setParameterT(5, 1.);       // control::minmax::Polarity
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		;                            // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		ahdsr.setParameterT(2, 20.); // envelope::ahdsr::Hold
		;                            // ahdsr::Decay is automated
		;                            // ahdsr::Sustain is automated
		;                            // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		ahdsr.setParameterT(8, 0.);  // envelope::ahdsr::Gate
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader1::Value is automated
		
		;                            // gain4::Gain is automated
		gain4.setParameterT(1, 20.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch3::Index is automated
		
		; // dynamic_blocksize3::BlockSize is automated
		
		; // receive::Feedback is automated
		
		;                                 // fix_delay::DelayTime is automated
		fix_delay.setParameterT(1, 401.); // core::fix_delay::FadeTime
		
		;                                   // minmax4::Value is automated
		minmax4.setParameterT(1, 0.);       // control::minmax::Minimum
		minmax4.setParameterT(2, 1.);       // control::minmax::Maximum
		minmax4.setParameterT(3, 0.426193); // control::minmax::Skew
		minmax4.setParameterT(4, 0.);       // control::minmax::Step
		minmax4.setParameterT(5, 1.);       // control::minmax::Polarity
		
		; // haas::Position is automated
		
		;                                   // one_pole145::Frequency is automated
		one_pole145.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole145.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole145.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole145.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole145.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                 // minmax::Value is automated
		minmax.setParameterT(1, -100.);   // control::minmax::Minimum
		minmax.setParameterT(2, 0.);      // control::minmax::Maximum
		minmax.setParameterT(3, 5.42227); // control::minmax::Skew
		minmax.setParameterT(4, 0.1);     // control::minmax::Step
		minmax.setParameterT(5, 1.);      // control::minmax::Polarity
		
		;                             // comp::Threshhold is automated
		comp.setParameterT(1, 25.9);  // dynamics::comp::Attack
		comp.setParameterT(2, 109.7); // dynamics::comp::Release
		comp.setParameterT(3, 2.8);   // dynamics::comp::Ratio
		comp.setParameterT(4, 0.);    // dynamics::comp::Sidechain
		
		; // dynamic_blocksize::BlockSize is automated
		
		; // receive1::Feedback is automated
		
		;                                  // fix_delay1::DelayTime is automated
		fix_delay1.setParameterT(1, 401.); // core::fix_delay::FadeTime
		
		; // phase_delay1::Frequency is automated
		
		;                                   // one_pole147::Frequency is automated
		one_pole147.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole147.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole147.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole147.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole147.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                  // minmax3::Value is automated
		minmax3.setParameterT(1, -100.);   // control::minmax::Minimum
		minmax3.setParameterT(2, 0.);      // control::minmax::Maximum
		minmax3.setParameterT(3, 5.42227); // control::minmax::Skew
		minmax3.setParameterT(4, 0.1);     // control::minmax::Step
		minmax3.setParameterT(5, 1.);      // control::minmax::Polarity
		
		;                              // comp2::Threshhold is automated
		comp2.setParameterT(1, 21.1);  // dynamics::comp::Attack
		comp2.setParameterT(2, 109.7); // dynamics::comp::Release
		comp2.setParameterT(3, 2.8);   // dynamics::comp::Ratio
		comp2.setParameterT(4, 0.);    // dynamics::comp::Sidechain
		
		; // dynamic_blocksize2::BlockSize is automated
		
		; // receive2::Feedback is automated
		
		;                                   // fix_delay3::DelayTime is automated
		fix_delay3.setParameterT(1, 1024.); // core::fix_delay::FadeTime
		
		jdelay3.setParameterT(0, 1000.); // jdsp::jdelay::Limit
		;                                // jdelay3::DelayTime is automated
		
		gain2.setParameterT(0, -8.9); // core::gain::Gain
		gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		gain2.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // phase_delay3::Frequency is automated
		
		gain3.setParameterT(0, -2.4); // core::gain::Gain
		gain3.setParameterT(1, 20.);  // core::gain::Smoothing
		gain3.setParameterT(2, 0.);   // core::gain::ResetValue
		
		;                                   // one_pole146::Frequency is automated
		one_pole146.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole146.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole146.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole146.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole146.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                  // minmax2::Value is automated
		minmax2.setParameterT(1, -100.);   // control::minmax::Minimum
		minmax2.setParameterT(2, 0.);      // control::minmax::Maximum
		minmax2.setParameterT(3, 5.42227); // control::minmax::Skew
		minmax2.setParameterT(4, 0.1);     // control::minmax::Step
		minmax2.setParameterT(5, 1.);      // control::minmax::Polarity
		
		;                              // comp1::Threshhold is automated
		comp1.setParameterT(1, 25.9);  // dynamics::comp::Attack
		comp1.setParameterT(2, 109.7); // dynamics::comp::Release
		comp1.setParameterT(3, 2.8);   // dynamics::comp::Ratio
		comp1.setParameterT(4, 0.);    // dynamics::comp::Sidechain
		
		; // cable_table::Value is automated
		
		; // cable_table1::Value is automated
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // faust::decal is automated
		; // faust::feedback is automated
		; // faust::population is automated
		; // faust::speed is automated
		; // faust::taille is automated
		
		;                            // gain5::Gain is automated
		gain5.setParameterT(1, 20.); // core::gain::Smoothing
		gain5.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                             // ahdsr1::Attack is automated
		ahdsr1.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		ahdsr1.setParameterT(2, 20.); // envelope::ahdsr::Hold
		;                             // ahdsr1::Decay is automated
		;                             // ahdsr1::Sustain is automated
		;                             // ahdsr1::Release is automated
		ahdsr1.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr1.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		ahdsr1.setParameterT(8, 1.);  // envelope::ahdsr::Gate
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 487.);
		this->setParameterT(2, 20000.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 2000.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, -0.01);
		this->setParameterT(10, 5.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 0.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 1.);
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
		
		this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable336_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable337_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable338_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable339_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable340_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable341_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable342_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable343_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable344_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable345_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable346_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable347_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable348_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable349_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable350_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable351_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable368_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable369_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable370_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable371_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable372_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable373_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable374_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable375_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable376_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // res1_impl::global_cable377_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable378_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable379_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable380_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable381_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable382_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // res1_impl::global_cable383_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);                         // res1_impl::peak23_t<NV>
		this->getT(1).getT(0).getT(1).getT(1).setExternalData(b, index);                         // res1_impl::peak25_t<NV>
		this->getT(3).getT(0).getT(0).setExternalData(b, index);                                 // res1_impl::ahdsr_t<NV>
		this->getT(4).getT(1).getT(1).getT(0).                                                   // res1_impl::comp_t
        getT(0).getT(0).getT(0).getT(2).
        getT(4).setExternalData(b, index);
		this->getT(4).getT(1).getT(1).getT(0).                                                   // res1_impl::comp2_t
        getT(0).getT(1).getT(0).getT(5).setExternalData(b, index);
		this->getT(4).getT(1).getT(1).getT(0).                                                   // res1_impl::comp1_t
        getT(0).getT(2).getT(0).getT(5).setExternalData(b, index);
		this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(3).getT(0).setExternalData(b, index); // res1_impl::cable_table_t<NV>
		this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(3).getT(1).setExternalData(b, index); // res1_impl::cable_table1_t<NV>
		this->getT(5).getT(0).getT(0).setExternalData(b, index);                                 // res1_impl::ahdsr1_t<NV>
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
using res1 = wrap::node<res1_impl::instance<NV>>;
}


