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
using minmax_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<cable_table_t<NV>, 0>, 
                                    parameter::plain<cable_table17_t<NV>, 0>, 
                                    parameter::plain<cable_table16_t<NV>, 0>, 
                                    parameter::plain<cable_table15_t<NV>, 0>, 
                                    parameter::plain<cable_pack_t<NV>, 0>, 
                                    parameter::plain<cable_pack7_t<NV>, 0>, 
                                    parameter::plain<cable_pack6_t<NV>, 0>, 
                                    parameter::plain<cable_pack5_t<NV>, 0>>;

template <int NV>
using minmax_t = control::minmax<NV, minmax_mod<NV>>;
template <int NV>
using input_toggle3_t = control::input_toggle<parameter::plain<minmax_t<NV>, 0>>;
template <int NV>
using ramp_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 1>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using resetter_t = control::resetter<parameter::plain<ramp_t<NV>, 2>>;
template <int NV>
using input_toggle1_t = control::input_toggle<parameter::plain<resetter_t<NV>, 0>>;
template <int NV>
using ahdsr_multimod = parameter::list<parameter::plain<input_toggle1_t<NV>, 2>, 
                                       parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;
template <int NV>
using input_toggle2_t = control::input_toggle<parameter::plain<ahdsr_t<NV>, 8>>;
template <int NV>
using ahdsr1_multimod = parameter::list<parameter::empty, 
                                        parameter::plain<input_toggle2_t<NV>, 2>>;

template <int NV>
using ahdsr1_t = wrap::no_data<envelope::ahdsr<NV, ahdsr1_multimod<NV>>>;

struct cable_table3_t_data
{
	span<float, 512> data =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 0.f, 0.f, 0.f, 0.f,
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
		0.f, 0.f
	};
};

template <int NV>
using cable_table3_t = wrap::data<control::cable_table<parameter::plain<input_toggle2_t<NV>, 0>>, 
                                  data::embedded::table<cable_table3_t_data>>;
using global_cable32_t_index = runtime_target::indexers::fix_hash<1120565314>;

template <int NV>
using global_cable32_t = routing::global_cable<global_cable32_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable32_t<NV>>, 
                                   math::add<NV>>;
using global_cable33_t_index = runtime_target::indexers::fix_hash<1120565315>;

template <int NV>
using global_cable33_t = routing::global_cable<global_cable33_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable33_t<NV>>, 
                                   math::add<NV>>;
using global_cable34_t_index = runtime_target::indexers::fix_hash<1120565316>;

template <int NV>
using global_cable34_t = routing::global_cable<global_cable34_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable34_t<NV>>, 
                                   math::add<NV>>;
using global_cable35_t_index = runtime_target::indexers::fix_hash<1120565317>;

template <int NV>
using global_cable35_t = routing::global_cable<global_cable35_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable35_t<NV>>, 
                                   math::add<NV>>;
using global_cable36_t_index = runtime_target::indexers::fix_hash<1120565318>;

template <int NV>
using global_cable36_t = routing::global_cable<global_cable36_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable36_t<NV>>, 
                                   math::add<NV>>;
using global_cable37_t_index = runtime_target::indexers::fix_hash<1120565319>;

template <int NV>
using global_cable37_t = routing::global_cable<global_cable37_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable37_t<NV>>, 
                                   math::add<NV>>;
using global_cable38_t_index = runtime_target::indexers::fix_hash<1120565320>;

template <int NV>
using global_cable38_t = routing::global_cable<global_cable38_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable38_t<NV>>, 
                                   math::add<NV>>;
using global_cable39_t_index = runtime_target::indexers::fix_hash<1120565321>;

template <int NV>
using global_cable39_t = routing::global_cable<global_cable39_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable39_t<NV>>, 
                                   math::add<NV>>;
using global_cable40_t_index = runtime_target::indexers::fix_hash<1120565322>;

template <int NV>
using global_cable40_t = routing::global_cable<global_cable40_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable40_t<NV>>, 
                                   math::add<NV>>;
using global_cable41_t_index = runtime_target::indexers::fix_hash<377786414>;

template <int NV>
using global_cable41_t = routing::global_cable<global_cable41_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable41_t<NV>>, 
                                   math::add<NV>>;
using global_cable42_t_index = runtime_target::indexers::fix_hash<377786415>;

template <int NV>
using global_cable42_t = routing::global_cable<global_cable42_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable42_t<NV>>, 
                                   math::add<NV>>;
using global_cable43_t_index = runtime_target::indexers::fix_hash<377786416>;

template <int NV>
using global_cable43_t = routing::global_cable<global_cable43_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable43_t<NV>>, 
                                   math::add<NV>>;
using global_cable44_t_index = runtime_target::indexers::fix_hash<377786417>;

template <int NV>
using global_cable44_t = routing::global_cable<global_cable44_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable44_t<NV>>, 
                                   math::add<NV>>;
using global_cable45_t_index = runtime_target::indexers::fix_hash<377786418>;

template <int NV>
using global_cable45_t = routing::global_cable<global_cable45_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable45_t<NV>>, 
                                   math::add<NV>>;
using global_cable46_t_index = runtime_target::indexers::fix_hash<377786419>;

template <int NV>
using global_cable46_t = routing::global_cable<global_cable46_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable46_t<NV>>, 
                                   math::add<NV>>;
using global_cable47_t_index = runtime_target::indexers::fix_hash<377786420>;

template <int NV>
using global_cable47_t = routing::global_cable<global_cable47_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable47_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain47_t<NV>>, 
                                    chain48_t<NV>, 
                                    chain49_t<NV>, 
                                    chain50_t<NV>, 
                                    chain51_t<NV>, 
                                    chain52_t<NV>, 
                                    chain53_t<NV>, 
                                    chain54_t<NV>, 
                                    chain55_t<NV>, 
                                    chain56_t<NV>, 
                                    chain57_t<NV>, 
                                    chain58_t<NV>, 
                                    chain59_t<NV>, 
                                    chain60_t<NV>, 
                                    chain61_t<NV>, 
                                    chain62_t<NV>>;

template <int NV>
using peak4_t = wrap::mod<parameter::plain<input_toggle2_t<NV>, 1>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   branch2_t<NV>, 
                                   peak4_t<NV>, 
                                   math::clear<NV>>;

DECLARE_PARAMETER_RANGE_STEP(cable_table1_modRange, 
                             0., 
                             15., 
                             1.);

template <int NV>
using cable_table1_mod = parameter::from0To1<branch2_t<NV>, 
                                             0, 
                                             cable_table1_modRange>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 0.851273f, 0.000348806f,
		0.00266814f, 0.00498748f, 0.00730681f, 0.00962621f, 0.0119455f, 0.0142649f,
		0.0165842f, 0.0189036f, 0.0212229f, 0.0235423f, 0.0258616f, 0.028181f,
		0.0305003f, 0.0328196f, 0.035139f, 0.0374583f, 0.0397776f, 0.042097f,
		0.0444164f, 0.0467357f, 0.049055f, 0.0513744f, 0.0536937f, 0.0560131f,
		0.0583324f, 0.0606518f, 0.0629711f, 0.0652905f, 0.0676098f, 0.0699292f,
		0.0722485f, 0.0745679f, 0.0768872f, 0.0792065f, 0.0815259f, 0.0838453f,
		0.0861645f, 0.0884839f, 0.0908033f, 0.0931226f, 0.0954419f, 0.0977613f,
		0.100081f, 0.1024f, 0.104719f, 0.107039f, 0.109358f, 0.111677f,
		0.113997f, 0.116316f, 0.118635f, 0.120955f, 0.123274f, 0.125593f,
		0.127913f, 0.130232f, 0.132551f, 0.134871f, 0.13719f, 0.139509f,
		0.141829f, 0.144148f, 0.146468f, 0.148787f, 0.151106f, 0.153426f,
		0.155745f, 0.158064f, 0.160384f, 0.162703f, 0.165022f, 0.167342f,
		0.169661f, 0.17198f, 0.1743f, 0.176619f, 0.178938f, 0.181258f,
		0.183577f, 0.185896f, 0.188216f, 0.190535f, 0.192854f, 0.195174f,
		0.197493f, 0.199812f, 0.202132f, 0.204451f, 0.206771f, 0.20909f,
		0.211409f, 0.213729f, 0.216048f, 0.218367f, 0.220687f, 0.223006f,
		0.225325f, 0.227645f, 0.229964f, 0.232283f, 0.234603f, 0.236922f,
		0.239241f, 0.241561f, 0.24388f, 0.246199f, 0.248519f, 0.250838f,
		0.253157f, 0.255477f, 0.257796f, 0.260115f, 0.262435f, 0.264754f,
		0.267073f, 0.269393f, 0.271712f, 0.274032f, 0.276351f, 0.27867f,
		0.28099f, 0.283309f, 0.285628f, 0.287948f, 0.290267f, 0.292586f,
		0.294906f, 0.297225f, 0.299544f, 0.301864f, 0.304183f, 0.306502f,
		0.308822f, 0.311141f, 0.31346f, 0.31578f, 0.318099f, 0.320418f,
		0.322738f, 0.325057f, 0.327376f, 0.329696f, 0.332015f, 0.334334f,
		0.336654f, 0.338973f, 0.341293f, 0.343612f, 0.345931f, 0.348251f,
		0.35057f, 0.352889f, 0.355209f, 0.357528f, 0.359847f, 0.362167f,
		0.364486f, 0.366805f, 0.369125f, 0.371444f, 0.373763f, 0.376083f,
		0.378402f, 0.380721f, 0.383041f, 0.38536f, 0.387679f, 0.389999f,
		0.392318f, 0.394637f, 0.396957f, 0.399276f, 0.401595f, 0.403915f,
		0.406234f, 0.408553f, 0.410873f, 0.413192f, 0.415511f, 0.417831f,
		0.42015f, 0.422469f, 0.424789f, 0.427108f, 0.429428f, 0.431747f,
		0.434066f, 0.436386f, 0.438705f, 0.441024f, 0.443344f, 0.445663f,
		0.447982f, 0.450302f, 0.452621f, 0.45494f, 0.45726f, 0.459579f,
		0.461898f, 0.464218f, 0.466537f, 0.468856f, 0.471176f, 0.473495f,
		0.475814f, 0.478134f, 0.480453f, 0.482773f, 0.485092f, 0.487411f,
		0.489731f, 0.49205f, 0.494369f, 0.496689f, 0.499008f, 0.501327f,
		0.503647f, 0.505966f, 0.508285f, 0.510605f, 0.512924f, 0.515243f,
		0.517563f, 0.519882f, 0.522201f, 0.524521f, 0.52684f, 0.529159f,
		0.531479f, 0.533798f, 0.536117f, 0.538437f, 0.540756f, 0.543075f,
		0.545395f, 0.547714f, 0.550034f, 0.552353f, 0.554672f, 0.556992f,
		0.559311f, 0.56163f, 0.56395f, 0.566269f, 0.568588f, 0.570908f,
		0.573227f, 0.575546f, 0.577866f, 0.580185f, 0.582504f, 0.584824f,
		0.587143f, 0.589462f, 0.591782f, 0.594101f, 0.59642f, 0.59874f,
		0.601059f, 0.603378f, 0.605698f, 0.608017f, 0.610337f, 0.612656f,
		0.614975f, 0.617294f, 0.619614f, 0.621933f, 0.624252f, 0.626572f,
		0.628891f, 0.631211f, 0.63353f, 0.635849f, 0.638169f, 0.640488f,
		0.642807f, 0.645127f, 0.647446f, 0.649765f, 0.652085f, 0.654404f,
		0.656723f, 0.659043f, 0.661362f, 0.663681f, 0.666001f, 0.66832f,
		0.670639f, 0.672959f, 0.675278f, 0.677597f, 0.679917f, 0.682236f,
		0.684556f, 0.686875f, 0.689194f, 0.691514f, 0.693833f, 0.696152f,
		0.698472f, 0.700791f, 0.70311f, 0.70543f, 0.707749f, 0.710068f,
		0.712388f, 0.714707f, 0.717026f, 0.719346f, 0.721665f, 0.723984f,
		0.726304f, 0.728623f, 0.730942f, 0.733262f, 0.735581f, 0.7379f,
		0.74022f, 0.742539f, 0.744859f, 0.747178f, 0.749497f, 0.751817f,
		0.754136f, 0.756455f, 0.758775f, 0.761094f, 0.763413f, 0.765733f,
		0.768052f, 0.770371f, 0.772691f, 0.77501f, 0.777329f, 0.779649f,
		0.781968f, 0.784287f, 0.786607f, 0.788926f, 0.791245f, 0.793565f,
		0.795884f, 0.798203f, 0.800523f, 0.802842f, 0.805161f, 0.807481f,
		0.8098f, 0.812119f, 0.814439f, 0.816758f, 0.819077f, 0.821397f,
		0.823716f, 0.826035f, 0.828355f, 0.830674f, 0.832994f, 0.835313f,
		0.837632f, 0.839952f, 0.842271f, 0.84459f, 0.84691f, 0.849229f,
		0.851548f, 0.853868f, 0.856187f, 0.858506f, 0.860826f, 0.863145f,
		0.865464f, 0.867784f, 0.870103f, 0.872422f, 0.874742f, 0.877061f,
		0.87938f, 0.8817f, 0.884019f, 0.886338f, 0.888658f, 0.890977f,
		0.893297f, 0.895616f, 0.897935f, 0.900255f, 0.902574f, 0.904893f,
		0.907213f, 0.909532f, 0.911851f, 0.914171f, 0.91649f, 0.918809f,
		0.921129f, 0.923448f, 0.925767f, 0.928087f, 0.930406f, 0.932725f,
		0.935045f, 0.937364f, 0.939683f, 0.942003f, 0.944322f, 0.946642f,
		0.948961f, 0.95128f, 0.9536f, 0.955919f, 0.958238f, 0.960558f,
		0.962877f, 0.965196f, 0.967516f, 0.969835f, 0.972154f, 0.974474f,
		0.976793f, 0.979112f, 0.981432f, 0.983751f, 0.98607f, 0.98839f,
		0.990709f, 0.993028f, 0.995348f, 0.997667f, 0.999986f, 1.f,
		1.f, 0.494382f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<cable_table1_mod<NV>>, 
                                  data::embedded::table<cable_table1_t_data>>;

DECLARE_PARAMETER_RANGE_SKEW(cable_table2_modRange, 
                             0., 
                             1., 
                             0.001);

template <int NV>
using cable_table2_mod = parameter::from0To1<input_toggle1_t<NV>, 
                                             0, 
                                             cable_table2_modRange>;

struct cable_table2_t_data
{
	span<float, 512> data =
	{
		1.f, 0.922926f, 0.845853f, 0.768779f, 0.691706f, 0.614632f,
		0.537558f, 0.460485f, 0.383411f, 0.306337f, 0.229264f, 0.15219f,
		0.0751166f, 0.000285864f, 0.0125904f, 0.0621254f, 0.11166f, 0.161195f,
		0.21073f, 0.260265f, 0.3098f, 0.359335f, 0.40887f, 0.458405f,
		0.50794f, 0.557475f, 0.60701f, 0.656545f, 0.70608f, 0.755615f,
		0.80515f, 0.854685f, 0.90422f, 0.953754f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table2_t = wrap::data<control::cable_table<cable_table2_mod<NV>>, 
                                  data::embedded::table<cable_table2_t_data>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, ahdsr1_t<NV>>, 
                                      cable_table3_t<NV>, 
                                      input_toggle2_t<NV>, 
                                      chain46_t<NV>, 
                                      cable_table1_t<NV>, 
                                      ahdsr_t<NV>, 
                                      cable_table2_t<NV>, 
                                      input_toggle1_t<NV>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;
using global_cable48_t_index = global_cable32_t_index;

template <int NV>
using global_cable48_t = routing::global_cable<global_cable48_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable48_t<NV>>, 
                                   math::add<NV>>;
using global_cable49_t_index = global_cable33_t_index;

template <int NV>
using global_cable49_t = routing::global_cable<global_cable49_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable49_t<NV>>, 
                                   math::add<NV>>;
using global_cable50_t_index = global_cable34_t_index;

template <int NV>
using global_cable50_t = routing::global_cable<global_cable50_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable50_t<NV>>, 
                                   math::add<NV>>;
using global_cable51_t_index = global_cable35_t_index;

template <int NV>
using global_cable51_t = routing::global_cable<global_cable51_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable51_t<NV>>, 
                                   math::add<NV>>;
using global_cable52_t_index = global_cable36_t_index;

template <int NV>
using global_cable52_t = routing::global_cable<global_cable52_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable52_t<NV>>, 
                                   math::add<NV>>;
using global_cable53_t_index = global_cable37_t_index;

template <int NV>
using global_cable53_t = routing::global_cable<global_cable53_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable53_t<NV>>, 
                                   math::add<NV>>;
using global_cable54_t_index = global_cable38_t_index;

template <int NV>
using global_cable54_t = routing::global_cable<global_cable54_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable54_t<NV>>, 
                                   math::add<NV>>;
using global_cable55_t_index = global_cable39_t_index;

template <int NV>
using global_cable55_t = routing::global_cable<global_cable55_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable55_t<NV>>, 
                                   math::add<NV>>;
using global_cable56_t_index = global_cable40_t_index;

template <int NV>
using global_cable56_t = routing::global_cable<global_cable56_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain72_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable56_t<NV>>, 
                                   math::add<NV>>;
using global_cable57_t_index = global_cable41_t_index;

template <int NV>
using global_cable57_t = routing::global_cable<global_cable57_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable57_t<NV>>, 
                                   math::add<NV>>;
using global_cable58_t_index = global_cable42_t_index;

template <int NV>
using global_cable58_t = routing::global_cable<global_cable58_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain74_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable58_t<NV>>, 
                                   math::add<NV>>;
using global_cable59_t_index = global_cable43_t_index;

template <int NV>
using global_cable59_t = routing::global_cable<global_cable59_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain75_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable59_t<NV>>, 
                                   math::add<NV>>;
using global_cable60_t_index = global_cable44_t_index;

template <int NV>
using global_cable60_t = routing::global_cable<global_cable60_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain76_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable60_t<NV>>, 
                                   math::add<NV>>;
using global_cable61_t_index = global_cable45_t_index;

template <int NV>
using global_cable61_t = routing::global_cable<global_cable61_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain77_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable61_t<NV>>, 
                                   math::add<NV>>;
using global_cable62_t_index = global_cable46_t_index;

template <int NV>
using global_cable62_t = routing::global_cable<global_cable62_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable62_t<NV>>, 
                                   math::add<NV>>;
using global_cable63_t_index = global_cable47_t_index;

template <int NV>
using global_cable63_t = routing::global_cable<global_cable63_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable63_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain64_t<NV>>, 
                                    chain65_t<NV>, 
                                    chain66_t<NV>, 
                                    chain67_t<NV>, 
                                    chain68_t<NV>, 
                                    chain69_t<NV>, 
                                    chain70_t<NV>, 
                                    chain71_t<NV>, 
                                    chain72_t<NV>, 
                                    chain73_t<NV>, 
                                    chain74_t<NV>, 
                                    chain75_t<NV>, 
                                    chain76_t<NV>, 
                                    chain77_t<NV>, 
                                    chain78_t<NV>, 
                                    chain79_t<NV>>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using clock_ramp1_t = wrap::mod<parameter::plain<input_toggle3_t<NV>, 2>, 
                                wrap::no_data<core::clock_ramp<NV, false>>>;
DECLARE_PARAMETER_RANGE_STEP(pma1_mod_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma1_mod_0 = parameter::from0To1<tempo_sync_t<NV>, 
                                       0, 
                                       pma1_mod_0Range>;

template <int NV>
using pma1_mod_1 = parameter::from0To1<clock_ramp1_t<NV>, 
                                       0, 
                                       pma1_mod_0Range>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  pma1_mod_0<NV>, 
                                  pma1_mod_1<NV>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using peak5_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   branch3_t<NV>, 
                                   peak5_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, chain63_t<NV>>, 
                                 pma1_t<NV>, 
                                 tempo_sync_t<NV>>;
using global_cable64_t_index = global_cable32_t_index;

template <int NV>
using global_cable64_t = routing::global_cable<global_cable64_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain81_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable64_t<NV>>, 
                                   math::add<NV>>;
using global_cable65_t_index = global_cable33_t_index;

template <int NV>
using global_cable65_t = routing::global_cable<global_cable65_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain82_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable65_t<NV>>, 
                                   math::add<NV>>;
using global_cable66_t_index = global_cable34_t_index;

template <int NV>
using global_cable66_t = routing::global_cable<global_cable66_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable66_t<NV>>, 
                                   math::add<NV>>;
using global_cable67_t_index = global_cable35_t_index;

template <int NV>
using global_cable67_t = routing::global_cable<global_cable67_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain84_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable67_t<NV>>, 
                                   math::add<NV>>;
using global_cable68_t_index = global_cable36_t_index;

template <int NV>
using global_cable68_t = routing::global_cable<global_cable68_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain85_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable68_t<NV>>, 
                                   math::add<NV>>;
using global_cable69_t_index = global_cable37_t_index;

template <int NV>
using global_cable69_t = routing::global_cable<global_cable69_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain86_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable69_t<NV>>, 
                                   math::add<NV>>;
using global_cable70_t_index = global_cable38_t_index;

template <int NV>
using global_cable70_t = routing::global_cable<global_cable70_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain87_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable70_t<NV>>, 
                                   math::add<NV>>;
using global_cable71_t_index = global_cable39_t_index;

template <int NV>
using global_cable71_t = routing::global_cable<global_cable71_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain88_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable71_t<NV>>, 
                                   math::add<NV>>;
using global_cable72_t_index = global_cable40_t_index;

template <int NV>
using global_cable72_t = routing::global_cable<global_cable72_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain89_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable72_t<NV>>, 
                                   math::add<NV>>;
using global_cable73_t_index = global_cable41_t_index;

template <int NV>
using global_cable73_t = routing::global_cable<global_cable73_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable73_t<NV>>, 
                                   math::add<NV>>;
using global_cable74_t_index = global_cable42_t_index;

template <int NV>
using global_cable74_t = routing::global_cable<global_cable74_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain91_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable74_t<NV>>, 
                                   math::add<NV>>;
using global_cable75_t_index = global_cable43_t_index;

template <int NV>
using global_cable75_t = routing::global_cable<global_cable75_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain92_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable75_t<NV>>, 
                                   math::add<NV>>;
using global_cable76_t_index = global_cable44_t_index;

template <int NV>
using global_cable76_t = routing::global_cable<global_cable76_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain93_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable76_t<NV>>, 
                                   math::add<NV>>;
using global_cable77_t_index = global_cable45_t_index;

template <int NV>
using global_cable77_t = routing::global_cable<global_cable77_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain94_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable77_t<NV>>, 
                                   math::add<NV>>;
using global_cable78_t_index = global_cable46_t_index;

template <int NV>
using global_cable78_t = routing::global_cable<global_cable78_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain95_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable78_t<NV>>, 
                                   math::add<NV>>;
using global_cable79_t_index = global_cable47_t_index;

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
using cable_pack1_t = wrap::data<control::cable_pack<parameter::empty>, 
                                 data::external::sliderpack<5>>;
DECLARE_PARAMETER_RANGE(pma_mod_2Range, 
                        0.1, 
                        1.);

using pma_mod_2 = parameter::from0To1<cable_pack1_t, 
                                      0, 
                                      pma_mod_2Range>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<xfader_t<NV>, 0>, 
                                 parameter::plain<xfader1_t<NV>, 0>, 
                                 pma_mod_2>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
DECLARE_PARAMETER_RANGE(peak6_modRange, 
                        0.1, 
                        0.8);

template <int NV>
using peak6_mod = parameter::from0To1<pma_t<NV>, 
                                      0, 
                                      peak6_modRange>;

template <int NV>
using peak6_t = wrap::mod<peak6_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain80_t = container::chain<parameter::empty, 
                                   wrap::fix<1, wrap::no_process<math::clear<NV>>>, 
                                   branch4_t<NV>, 
                                   peak6_t<NV>, 
                                   math::clear<NV>>;

struct cable_table4_t_data
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
		0.240707f, 0.491196f, 0.741684f, 0.992172f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table4_t = wrap::data<control::cable_table<parameter::plain<input_toggle3_t<NV>, 0>>, 
                                  data::embedded::table<cable_table4_t_data>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_table4_t<NV>>, 
                                  resetter_t<NV>, 
                                  clock_ramp1_t<NV>, 
                                  ramp_t<NV>, 
                                  input_toggle3_t<NV>, 
                                  minmax_t<NV>, 
                                  math::clear<NV>, 
                                  cable_pack1_t>;

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
}

template <int NV>
using softbypass_switch3_t = container::chain<parameter::plain<DspNetwork_impl::switcher_t<NV>, 0>, 
                                              wrap::fix<1, switcher_t<NV>>, 
                                              sb_container_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain1_t<NV>>, 
                                 softbypass_switch3_t<NV>>;

using global_cable16_t_index = global_cable32_t_index;
using peak2_mod = parameter::plain<routing::global_cable<global_cable16_t_index, parameter::empty>, 
                                   0>;
using peak2_t = wrap::mod<peak2_mod, 
                          wrap::no_data<core::peak>>;

using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak2_t>, 
                                   routing::global_cable<global_cable16_t_index, parameter::empty>>;

using global_cable17_t_index = global_cable33_t_index;
using peak7_mod = parameter::plain<routing::global_cable<global_cable17_t_index, parameter::empty>, 
                                   0>;
using peak7_t = wrap::mod<peak7_mod, 
                          wrap::no_data<core::peak>>;

using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak7_t>, 
                                   routing::global_cable<global_cable17_t_index, parameter::empty>>;

using global_cable18_t_index = global_cable34_t_index;
using peak_mod = parameter::plain<routing::global_cable<global_cable18_t_index, parameter::empty>, 
                                  0>;
using peak_t = wrap::mod<peak_mod, 
                         wrap::no_data<core::peak>>;

using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak_t>, 
                                   routing::global_cable<global_cable18_t_index, parameter::empty>>;

using global_cable19_t_index = global_cable35_t_index;
using peak11_mod = parameter::plain<routing::global_cable<global_cable19_t_index, parameter::empty>, 
                                    0>;
using peak11_t = wrap::mod<peak11_mod, 
                           wrap::no_data<core::peak>>;

using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak11_t>, 
                                   routing::global_cable<global_cable19_t_index, parameter::empty>>;

using global_cable20_t_index = global_cable36_t_index;
using peak10_mod = parameter::plain<routing::global_cable<global_cable20_t_index, parameter::empty>, 
                                    0>;
using peak10_t = wrap::mod<peak10_mod, 
                           wrap::no_data<core::peak>>;

using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak10_t>, 
                                   routing::global_cable<global_cable20_t_index, parameter::empty>>;

using global_cable21_t_index = global_cable37_t_index;
using peak8_mod = parameter::plain<routing::global_cable<global_cable21_t_index, parameter::empty>, 
                                   0>;
using peak8_t = wrap::mod<peak8_mod, 
                          wrap::no_data<core::peak>>;

using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak8_t>, 
                                   routing::global_cable<global_cable21_t_index, parameter::empty>>;

using global_cable22_t_index = global_cable38_t_index;
using peak12_mod = parameter::plain<routing::global_cable<global_cable22_t_index, parameter::empty>, 
                                    0>;
using peak12_t = wrap::mod<peak12_mod, 
                           wrap::no_data<core::peak>>;

using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak12_t>, 
                                   routing::global_cable<global_cable22_t_index, parameter::empty>>;

using global_cable23_t_index = global_cable39_t_index;
using peak9_mod = parameter::plain<routing::global_cable<global_cable23_t_index, parameter::empty>, 
                                   0>;
using peak9_t = wrap::mod<peak9_mod, 
                          wrap::no_data<core::peak>>;

using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak9_t>, 
                                   routing::global_cable<global_cable23_t_index, parameter::empty>>;

using global_cable24_t_index = global_cable40_t_index;
using peak16_mod = parameter::plain<routing::global_cable<global_cable24_t_index, parameter::empty>, 
                                    0>;
using peak16_t = wrap::mod<peak16_mod, 
                           wrap::no_data<core::peak>>;

using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak16_t>, 
                                   routing::global_cable<global_cable24_t_index, parameter::empty>>;

using global_cable25_t_index = global_cable41_t_index;
using peak15_mod = parameter::plain<routing::global_cable<global_cable25_t_index, parameter::empty>, 
                                    0>;
using peak15_t = wrap::mod<peak15_mod, 
                           wrap::no_data<core::peak>>;

using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak15_t>, 
                                   routing::global_cable<global_cable25_t_index, parameter::empty>>;

using global_cable26_t_index = global_cable42_t_index;
using peak14_mod = parameter::plain<routing::global_cable<global_cable26_t_index, parameter::empty>, 
                                    0>;
using peak14_t = wrap::mod<peak14_mod, 
                           wrap::no_data<core::peak>>;

using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak14_t>, 
                                   routing::global_cable<global_cable26_t_index, parameter::empty>>;

using global_cable27_t_index = global_cable43_t_index;
using peak17_mod = parameter::plain<routing::global_cable<global_cable27_t_index, parameter::empty>, 
                                    0>;
using peak17_t = wrap::mod<peak17_mod, 
                           wrap::no_data<core::peak>>;

using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak17_t>, 
                                   routing::global_cable<global_cable27_t_index, parameter::empty>>;

using global_cable28_t_index = global_cable44_t_index;
using peak13_mod = parameter::plain<routing::global_cable<global_cable28_t_index, parameter::empty>, 
                                    0>;
using peak13_t = wrap::mod<peak13_mod, 
                           wrap::no_data<core::peak>>;

using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak13_t>, 
                                   routing::global_cable<global_cable28_t_index, parameter::empty>>;

using global_cable29_t_index = global_cable45_t_index;
using peak20_mod = parameter::plain<routing::global_cable<global_cable29_t_index, parameter::empty>, 
                                    0>;
using peak20_t = wrap::mod<peak20_mod, 
                           wrap::no_data<core::peak>>;

using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak20_t>, 
                                   routing::global_cable<global_cable29_t_index, parameter::empty>>;

using global_cable30_t_index = global_cable46_t_index;
using peak19_mod = parameter::plain<routing::global_cable<global_cable30_t_index, parameter::empty>, 
                                    0>;
using peak19_t = wrap::mod<peak19_mod, 
                           wrap::no_data<core::peak>>;

using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak19_t>, 
                                   routing::global_cable<global_cable30_t_index, parameter::empty>>;

using global_cable31_t_index = global_cable47_t_index;
using peak18_mod = parameter::plain<routing::global_cable<global_cable31_t_index, parameter::empty>, 
                                    0>;
using peak18_t = wrap::mod<peak18_mod, 
                           wrap::no_data<core::peak>>;

using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak18_t>, 
                                   routing::global_cable<global_cable31_t_index, parameter::empty>>;
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain30_t>, 
                                    chain31_t, 
                                    chain32_t, 
                                    chain33_t, 
                                    chain34_t, 
                                    chain35_t, 
                                    chain36_t, 
                                    chain37_t, 
                                    chain38_t, 
                                    chain39_t, 
                                    chain40_t, 
                                    chain41_t, 
                                    chain42_t, 
                                    chain43_t, 
                                    chain44_t, 
                                    chain45_t>;

using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch1_t>>;

namespace DspNetwork_t_parameters
{
// Parameter list for DspNetwork_impl::DspNetwork_t ------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(tempo_InputRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using tempo = parameter::chain<tempo_InputRange, 
                               parameter::plain<DspNetwork_impl::pma1_t<NV>, 2>>;

template <int NV>
using multi = parameter::chain<ranges::Identity, 
                               parameter::plain<DspNetwork_impl::tempo_sync_t<NV>, 1>, 
                               parameter::plain<DspNetwork_impl::clock_ramp1_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(tempomod_InputRange, 
                        5.55112e-17, 
                        1.);
DECLARE_PARAMETER_RANGE(tempomod_0Range, 
                        -1., 
                        1.);

template <int NV>
using tempomod_0 = parameter::from0To1<DspNetwork_impl::pma1_t<NV>, 
                                       1, 
                                       tempomod_0Range>;

template <int NV>
using tempomod = parameter::chain<tempomod_InputRange, tempomod_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(moddest_InputRange, 
                             0., 
                             16., 
                             0.1);
template <int NV>
using moddest_0 = parameter::from0To1<DspNetwork_impl::branch3_t<NV>, 
                                      0, 
                                      DspNetwork_impl::cable_table1_modRange>;

template <int NV>
using moddest = parameter::chain<moddest_InputRange, moddest_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP_INV(type_InputRange, 
                                 0., 
                                 1., 
                                 0.1);

template <int NV>
using type = parameter::chain<type_InputRange, 
                              parameter::plain<DspNetwork_impl::softbypass_switch3_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(keysync_InputRange, 
                             0., 
                             19., 
                             0.1);

template <int NV>
using keysync = parameter::chain<keysync_InputRange, 
                                 parameter::plain<DspNetwork_impl::cable_table1_t<NV>, 0>, 
                                 parameter::plain<DspNetwork_impl::cable_table2_t<NV>, 0>, 
                                 parameter::plain<DspNetwork_impl::cable_table3_t<NV>, 0>, 
                                 parameter::plain<DspNetwork_impl::cable_table4_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(morph_InputRange, 
                        1., 
                        4.);

template <int NV>
using morph = parameter::chain<morph_InputRange, 
                               parameter::plain<DspNetwork_impl::pma_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(morphmod_InputRange, 
                        5.55112e-17, 
                        1.);
template <int NV>
using morphmod_0 = parameter::from0To1<DspNetwork_impl::pma_t<NV>, 
                                       1, 
                                       tempomod_0Range>;

template <int NV>
using morphmod = parameter::chain<morphmod_InputRange, morphmod_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(morphmodest_InputRange, 
                             0., 
                             16., 
                             0.1);
template <int NV>
using morphmodest_0 = parameter::from0To1<DspNetwork_impl::branch4_t<NV>, 
                                          0, 
                                          DspNetwork_impl::cable_table1_modRange>;

template <int NV>
using morphmodest = parameter::chain<morphmodest_InputRange, morphmodest_0<NV>>;

template <int NV>
using dir = parameter::plain<DspNetwork_impl::minmax_t<NV>, 
                             5>;
template <int NV>
using onshot = parameter::plain<DspNetwork_impl::ramp_t<NV>, 
                                1>;
using Out = parameter::plain<DspNetwork_impl::branch1_t, 
                             0>;
template <int NV>
using DspNetwork_t_plist = parameter::list<tempo<NV>, 
                                           multi<NV>, 
                                           tempomod<NV>, 
                                           moddest<NV>, 
                                           type<NV>, 
                                           dir<NV>, 
                                           keysync<NV>, 
                                           onshot<NV>, 
                                           morph<NV>, 
                                           morphmod<NV>, 
                                           morphmodest<NV>, 
                                           Out>;
}

template <int NV>
using DspNetwork_t_ = container::chain<DspNetwork_t_parameters::DspNetwork_t_plist<NV>, 
                                       wrap::fix<1, midichain_t<NV>>, 
                                       chain_t<NV>, 
                                       chain80_t<NV>, 
                                       pma_t<NV>, 
                                       split_t<NV>, 
                                       chain29_t>;

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
		SNEX_METADATA_ENCODED_PARAMETERS(194)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x756D, 0x746C, 0x0069, 0x0000, 0x3F80, 0x0000, 
            0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x025B, 
            0x0000, 0x7400, 0x6D65, 0x6F70, 0x6F6D, 0x0064, 0x0000, 0x2480, 
            0x0000, 0x3F80, 0x0000, 0x3F00, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x035B, 0x0000, 0x6D00, 0x646F, 0x6564, 0x7473, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x0041, 0x0000, 0x0000, 0x8000, 0xCD3F, 0xCCCC, 
            0x5B3D, 0x0004, 0x0000, 0x7974, 0x6570, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 
            0x0005, 0x0000, 0x6964, 0x0072, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x065B, 0x0000, 
            0x6B00, 0x7965, 0x7973, 0x636E, 0x0000, 0x0000, 0x0000, 0x9800, 
            0x0041, 0x8000, 0x003F, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x0007, 
            0x0000, 0x6E6F, 0x6873, 0x746F, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0008, 
            0x0000, 0x6F6D, 0x7072, 0x0068, 0x0000, 0x3F80, 0x0000, 0x4080, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x095B, 0x0000, 
            0x6D00, 0x726F, 0x6870, 0x6F6D, 0x0064, 0x0000, 0x2480, 0x0000, 
            0x3F80, 0x0000, 0x3F00, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 
            0x0000, 0x6D00, 0x726F, 0x6870, 0x6F6D, 0x6564, 0x7473, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x0041, 0x8000, 0x0040, 0x8000, 0xCD3F, 
            0xCCCC, 0x5B3D, 0x000B, 0x0000, 0x754F, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x4170, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& midichain = this->getT(0);                                               // DspNetwork_impl::midichain_t<NV>
		auto& ahdsr1 = this->getT(0).getT(0);                                          // DspNetwork_impl::ahdsr1_t<NV>
		auto& cable_table3 = this->getT(0).getT(1);                                    // DspNetwork_impl::cable_table3_t<NV>
		auto& input_toggle2 = this->getT(0).getT(2);                                   // DspNetwork_impl::input_toggle2_t<NV>
		auto& chain46 = this->getT(0).getT(3);                                         // DspNetwork_impl::chain46_t<NV>
		auto& clear4 = this->getT(0).getT(3).getT(0);                                  // math::clear<NV>
		auto& branch2 = this->getT(0).getT(3).getT(1);                                 // DspNetwork_impl::branch2_t<NV>
		auto& chain47 = this->getT(0).getT(3).getT(1).getT(0);                         // DspNetwork_impl::chain47_t<NV>
		auto& global_cable32 = this->getT(0).getT(3).getT(1).getT(0).getT(0);          // DspNetwork_impl::global_cable32_t<NV>
		auto& add26 = this->getT(0).getT(3).getT(1).getT(0).getT(1);                   // math::add<NV>
		auto& chain48 = this->getT(0).getT(3).getT(1).getT(1);                         // DspNetwork_impl::chain48_t<NV>
		auto& global_cable33 = this->getT(0).getT(3).getT(1).getT(1).getT(0);          // DspNetwork_impl::global_cable33_t<NV>
		auto& add27 = this->getT(0).getT(3).getT(1).getT(1).getT(1);                   // math::add<NV>
		auto& chain49 = this->getT(0).getT(3).getT(1).getT(2);                         // DspNetwork_impl::chain49_t<NV>
		auto& global_cable34 = this->getT(0).getT(3).getT(1).getT(2).getT(0);          // DspNetwork_impl::global_cable34_t<NV>
		auto& add28 = this->getT(0).getT(3).getT(1).getT(2).getT(1);                   // math::add<NV>
		auto& chain50 = this->getT(0).getT(3).getT(1).getT(3);                         // DspNetwork_impl::chain50_t<NV>
		auto& global_cable35 = this->getT(0).getT(3).getT(1).getT(3).getT(0);          // DspNetwork_impl::global_cable35_t<NV>
		auto& add29 = this->getT(0).getT(3).getT(1).getT(3).getT(1);                   // math::add<NV>
		auto& chain51 = this->getT(0).getT(3).getT(1).getT(4);                         // DspNetwork_impl::chain51_t<NV>
		auto& global_cable36 = this->getT(0).getT(3).getT(1).getT(4).getT(0);          // DspNetwork_impl::global_cable36_t<NV>
		auto& add30 = this->getT(0).getT(3).getT(1).getT(4).getT(1);                   // math::add<NV>
		auto& chain52 = this->getT(0).getT(3).getT(1).getT(5);                         // DspNetwork_impl::chain52_t<NV>
		auto& global_cable37 = this->getT(0).getT(3).getT(1).getT(5).getT(0);          // DspNetwork_impl::global_cable37_t<NV>
		auto& add31 = this->getT(0).getT(3).getT(1).getT(5).getT(1);                   // math::add<NV>
		auto& chain53 = this->getT(0).getT(3).getT(1).getT(6);                         // DspNetwork_impl::chain53_t<NV>
		auto& global_cable38 = this->getT(0).getT(3).getT(1).getT(6).getT(0);          // DspNetwork_impl::global_cable38_t<NV>
		auto& add32 = this->getT(0).getT(3).getT(1).getT(6).getT(1);                   // math::add<NV>
		auto& chain54 = this->getT(0).getT(3).getT(1).getT(7);                         // DspNetwork_impl::chain54_t<NV>
		auto& global_cable39 = this->getT(0).getT(3).getT(1).getT(7).getT(0);          // DspNetwork_impl::global_cable39_t<NV>
		auto& add33 = this->getT(0).getT(3).getT(1).getT(7).getT(1);                   // math::add<NV>
		auto& chain55 = this->getT(0).getT(3).getT(1).getT(8);                         // DspNetwork_impl::chain55_t<NV>
		auto& global_cable40 = this->getT(0).getT(3).getT(1).getT(8).getT(0);          // DspNetwork_impl::global_cable40_t<NV>
		auto& add34 = this->getT(0).getT(3).getT(1).getT(8).getT(1);                   // math::add<NV>
		auto& chain56 = this->getT(0).getT(3).getT(1).getT(9);                         // DspNetwork_impl::chain56_t<NV>
		auto& global_cable41 = this->getT(0).getT(3).getT(1).getT(9).getT(0);          // DspNetwork_impl::global_cable41_t<NV>
		auto& add35 = this->getT(0).getT(3).getT(1).getT(9).getT(1);                   // math::add<NV>
		auto& chain57 = this->getT(0).getT(3).getT(1).getT(10);                        // DspNetwork_impl::chain57_t<NV>
		auto& global_cable42 = this->getT(0).getT(3).getT(1).getT(10).getT(0);         // DspNetwork_impl::global_cable42_t<NV>
		auto& add36 = this->getT(0).getT(3).getT(1).getT(10).getT(1);                  // math::add<NV>
		auto& chain58 = this->getT(0).getT(3).getT(1).getT(11);                        // DspNetwork_impl::chain58_t<NV>
		auto& global_cable43 = this->getT(0).getT(3).getT(1).getT(11).getT(0);         // DspNetwork_impl::global_cable43_t<NV>
		auto& add37 = this->getT(0).getT(3).getT(1).getT(11).getT(1);                  // math::add<NV>
		auto& chain59 = this->getT(0).getT(3).getT(1).getT(12);                        // DspNetwork_impl::chain59_t<NV>
		auto& global_cable44 = this->getT(0).getT(3).getT(1).getT(12).getT(0);         // DspNetwork_impl::global_cable44_t<NV>
		auto& add38 = this->getT(0).getT(3).getT(1).getT(12).getT(1);                  // math::add<NV>
		auto& chain60 = this->getT(0).getT(3).getT(1).getT(13);                        // DspNetwork_impl::chain60_t<NV>
		auto& global_cable45 = this->getT(0).getT(3).getT(1).getT(13).getT(0);         // DspNetwork_impl::global_cable45_t<NV>
		auto& add39 = this->getT(0).getT(3).getT(1).getT(13).getT(1);                  // math::add<NV>
		auto& chain61 = this->getT(0).getT(3).getT(1).getT(14);                        // DspNetwork_impl::chain61_t<NV>
		auto& global_cable46 = this->getT(0).getT(3).getT(1).getT(14).getT(0);         // DspNetwork_impl::global_cable46_t<NV>
		auto& add40 = this->getT(0).getT(3).getT(1).getT(14).getT(1);                  // math::add<NV>
		auto& chain62 = this->getT(0).getT(3).getT(1).getT(15);                        // DspNetwork_impl::chain62_t<NV>
		auto& global_cable47 = this->getT(0).getT(3).getT(1).getT(15).getT(0);         // DspNetwork_impl::global_cable47_t<NV>
		auto& add41 = this->getT(0).getT(3).getT(1).getT(15).getT(1);                  // math::add<NV>
		auto& peak4 = this->getT(0).getT(3).getT(2);                                   // DspNetwork_impl::peak4_t<NV>
		auto& clear2 = this->getT(0).getT(3).getT(3);                                  // math::clear<NV>
		auto& cable_table1 = this->getT(0).getT(4);                                    // DspNetwork_impl::cable_table1_t<NV>
		auto& ahdsr = this->getT(0).getT(5);                                           // DspNetwork_impl::ahdsr_t<NV>
		auto& cable_table2 = this->getT(0).getT(6);                                    // DspNetwork_impl::cable_table2_t<NV>
		auto& input_toggle1 = this->getT(0).getT(7);                                   // DspNetwork_impl::input_toggle1_t<NV>
		auto& chain = this->getT(1);                                                   // DspNetwork_impl::chain_t<NV>
		auto& chain63 = this->getT(1).getT(0);                                         // DspNetwork_impl::chain63_t<NV>
		auto& clear5 = this->getT(1).getT(0).getT(0);                                  // math::clear<NV>
		auto& branch3 = this->getT(1).getT(0).getT(1);                                 // DspNetwork_impl::branch3_t<NV>
		auto& chain64 = this->getT(1).getT(0).getT(1).getT(0);                         // DspNetwork_impl::chain64_t<NV>
		auto& global_cable48 = this->getT(1).getT(0).getT(1).getT(0).getT(0);          // DspNetwork_impl::global_cable48_t<NV>
		auto& add42 = this->getT(1).getT(0).getT(1).getT(0).getT(1);                   // math::add<NV>
		auto& chain65 = this->getT(1).getT(0).getT(1).getT(1);                         // DspNetwork_impl::chain65_t<NV>
		auto& global_cable49 = this->getT(1).getT(0).getT(1).getT(1).getT(0);          // DspNetwork_impl::global_cable49_t<NV>
		auto& add43 = this->getT(1).getT(0).getT(1).getT(1).getT(1);                   // math::add<NV>
		auto& chain66 = this->getT(1).getT(0).getT(1).getT(2);                         // DspNetwork_impl::chain66_t<NV>
		auto& global_cable50 = this->getT(1).getT(0).getT(1).getT(2).getT(0);          // DspNetwork_impl::global_cable50_t<NV>
		auto& add44 = this->getT(1).getT(0).getT(1).getT(2).getT(1);                   // math::add<NV>
		auto& chain67 = this->getT(1).getT(0).getT(1).getT(3);                         // DspNetwork_impl::chain67_t<NV>
		auto& global_cable51 = this->getT(1).getT(0).getT(1).getT(3).getT(0);          // DspNetwork_impl::global_cable51_t<NV>
		auto& add45 = this->getT(1).getT(0).getT(1).getT(3).getT(1);                   // math::add<NV>
		auto& chain68 = this->getT(1).getT(0).getT(1).getT(4);                         // DspNetwork_impl::chain68_t<NV>
		auto& global_cable52 = this->getT(1).getT(0).getT(1).getT(4).getT(0);          // DspNetwork_impl::global_cable52_t<NV>
		auto& add46 = this->getT(1).getT(0).getT(1).getT(4).getT(1);                   // math::add<NV>
		auto& chain69 = this->getT(1).getT(0).getT(1).getT(5);                         // DspNetwork_impl::chain69_t<NV>
		auto& global_cable53 = this->getT(1).getT(0).getT(1).getT(5).getT(0);          // DspNetwork_impl::global_cable53_t<NV>
		auto& add47 = this->getT(1).getT(0).getT(1).getT(5).getT(1);                   // math::add<NV>
		auto& chain70 = this->getT(1).getT(0).getT(1).getT(6);                         // DspNetwork_impl::chain70_t<NV>
		auto& global_cable54 = this->getT(1).getT(0).getT(1).getT(6).getT(0);          // DspNetwork_impl::global_cable54_t<NV>
		auto& add48 = this->getT(1).getT(0).getT(1).getT(6).getT(1);                   // math::add<NV>
		auto& chain71 = this->getT(1).getT(0).getT(1).getT(7);                         // DspNetwork_impl::chain71_t<NV>
		auto& global_cable55 = this->getT(1).getT(0).getT(1).getT(7).getT(0);          // DspNetwork_impl::global_cable55_t<NV>
		auto& add49 = this->getT(1).getT(0).getT(1).getT(7).getT(1);                   // math::add<NV>
		auto& chain72 = this->getT(1).getT(0).getT(1).getT(8);                         // DspNetwork_impl::chain72_t<NV>
		auto& global_cable56 = this->getT(1).getT(0).getT(1).getT(8).getT(0);          // DspNetwork_impl::global_cable56_t<NV>
		auto& add50 = this->getT(1).getT(0).getT(1).getT(8).getT(1);                   // math::add<NV>
		auto& chain73 = this->getT(1).getT(0).getT(1).getT(9);                         // DspNetwork_impl::chain73_t<NV>
		auto& global_cable57 = this->getT(1).getT(0).getT(1).getT(9).getT(0);          // DspNetwork_impl::global_cable57_t<NV>
		auto& add51 = this->getT(1).getT(0).getT(1).getT(9).getT(1);                   // math::add<NV>
		auto& chain74 = this->getT(1).getT(0).getT(1).getT(10);                        // DspNetwork_impl::chain74_t<NV>
		auto& global_cable58 = this->getT(1).getT(0).getT(1).getT(10).getT(0);         // DspNetwork_impl::global_cable58_t<NV>
		auto& add52 = this->getT(1).getT(0).getT(1).getT(10).getT(1);                  // math::add<NV>
		auto& chain75 = this->getT(1).getT(0).getT(1).getT(11);                        // DspNetwork_impl::chain75_t<NV>
		auto& global_cable59 = this->getT(1).getT(0).getT(1).getT(11).getT(0);         // DspNetwork_impl::global_cable59_t<NV>
		auto& add53 = this->getT(1).getT(0).getT(1).getT(11).getT(1);                  // math::add<NV>
		auto& chain76 = this->getT(1).getT(0).getT(1).getT(12);                        // DspNetwork_impl::chain76_t<NV>
		auto& global_cable60 = this->getT(1).getT(0).getT(1).getT(12).getT(0);         // DspNetwork_impl::global_cable60_t<NV>
		auto& add54 = this->getT(1).getT(0).getT(1).getT(12).getT(1);                  // math::add<NV>
		auto& chain77 = this->getT(1).getT(0).getT(1).getT(13);                        // DspNetwork_impl::chain77_t<NV>
		auto& global_cable61 = this->getT(1).getT(0).getT(1).getT(13).getT(0);         // DspNetwork_impl::global_cable61_t<NV>
		auto& add55 = this->getT(1).getT(0).getT(1).getT(13).getT(1);                  // math::add<NV>
		auto& chain78 = this->getT(1).getT(0).getT(1).getT(14);                        // DspNetwork_impl::chain78_t<NV>
		auto& global_cable62 = this->getT(1).getT(0).getT(1).getT(14).getT(0);         // DspNetwork_impl::global_cable62_t<NV>
		auto& add56 = this->getT(1).getT(0).getT(1).getT(14).getT(1);                  // math::add<NV>
		auto& chain79 = this->getT(1).getT(0).getT(1).getT(15);                        // DspNetwork_impl::chain79_t<NV>
		auto& global_cable63 = this->getT(1).getT(0).getT(1).getT(15).getT(0);         // DspNetwork_impl::global_cable63_t<NV>
		auto& add57 = this->getT(1).getT(0).getT(1).getT(15).getT(1);                  // math::add<NV>
		auto& peak5 = this->getT(1).getT(0).getT(2);                                   // DspNetwork_impl::peak5_t<NV>
		auto& clear6 = this->getT(1).getT(0).getT(3);                                  // math::clear<NV>
		auto& pma1 = this->getT(1).getT(1);                                            // DspNetwork_impl::pma1_t<NV>
		auto& tempo_sync = this->getT(1).getT(2);                                      // DspNetwork_impl::tempo_sync_t<NV>
		auto& chain80 = this->getT(2);                                                 // DspNetwork_impl::chain80_t<NV>
		auto& clear7 = this->getT(2).getT(0);                                          // wrap::no_process<math::clear<NV>>
		auto& branch4 = this->getT(2).getT(1);                                         // DspNetwork_impl::branch4_t<NV>
		auto& chain81 = this->getT(2).getT(1).getT(0);                                 // DspNetwork_impl::chain81_t<NV>
		auto& global_cable64 = this->getT(2).getT(1).getT(0).getT(0);                  // DspNetwork_impl::global_cable64_t<NV>
		auto& add58 = this->getT(2).getT(1).getT(0).getT(1);                           // math::add<NV>
		auto& chain82 = this->getT(2).getT(1).getT(1);                                 // DspNetwork_impl::chain82_t<NV>
		auto& global_cable65 = this->getT(2).getT(1).getT(1).getT(0);                  // DspNetwork_impl::global_cable65_t<NV>
		auto& add59 = this->getT(2).getT(1).getT(1).getT(1);                           // math::add<NV>
		auto& chain83 = this->getT(2).getT(1).getT(2);                                 // DspNetwork_impl::chain83_t<NV>
		auto& global_cable66 = this->getT(2).getT(1).getT(2).getT(0);                  // DspNetwork_impl::global_cable66_t<NV>
		auto& add60 = this->getT(2).getT(1).getT(2).getT(1);                           // math::add<NV>
		auto& chain84 = this->getT(2).getT(1).getT(3);                                 // DspNetwork_impl::chain84_t<NV>
		auto& global_cable67 = this->getT(2).getT(1).getT(3).getT(0);                  // DspNetwork_impl::global_cable67_t<NV>
		auto& add61 = this->getT(2).getT(1).getT(3).getT(1);                           // math::add<NV>
		auto& chain85 = this->getT(2).getT(1).getT(4);                                 // DspNetwork_impl::chain85_t<NV>
		auto& global_cable68 = this->getT(2).getT(1).getT(4).getT(0);                  // DspNetwork_impl::global_cable68_t<NV>
		auto& add62 = this->getT(2).getT(1).getT(4).getT(1);                           // math::add<NV>
		auto& chain86 = this->getT(2).getT(1).getT(5);                                 // DspNetwork_impl::chain86_t<NV>
		auto& global_cable69 = this->getT(2).getT(1).getT(5).getT(0);                  // DspNetwork_impl::global_cable69_t<NV>
		auto& add63 = this->getT(2).getT(1).getT(5).getT(1);                           // math::add<NV>
		auto& chain87 = this->getT(2).getT(1).getT(6);                                 // DspNetwork_impl::chain87_t<NV>
		auto& global_cable70 = this->getT(2).getT(1).getT(6).getT(0);                  // DspNetwork_impl::global_cable70_t<NV>
		auto& add64 = this->getT(2).getT(1).getT(6).getT(1);                           // math::add<NV>
		auto& chain88 = this->getT(2).getT(1).getT(7);                                 // DspNetwork_impl::chain88_t<NV>
		auto& global_cable71 = this->getT(2).getT(1).getT(7).getT(0);                  // DspNetwork_impl::global_cable71_t<NV>
		auto& add65 = this->getT(2).getT(1).getT(7).getT(1);                           // math::add<NV>
		auto& chain89 = this->getT(2).getT(1).getT(8);                                 // DspNetwork_impl::chain89_t<NV>
		auto& global_cable72 = this->getT(2).getT(1).getT(8).getT(0);                  // DspNetwork_impl::global_cable72_t<NV>
		auto& add66 = this->getT(2).getT(1).getT(8).getT(1);                           // math::add<NV>
		auto& chain90 = this->getT(2).getT(1).getT(9);                                 // DspNetwork_impl::chain90_t<NV>
		auto& global_cable73 = this->getT(2).getT(1).getT(9).getT(0);                  // DspNetwork_impl::global_cable73_t<NV>
		auto& add67 = this->getT(2).getT(1).getT(9).getT(1);                           // math::add<NV>
		auto& chain91 = this->getT(2).getT(1).getT(10);                                // DspNetwork_impl::chain91_t<NV>
		auto& global_cable74 = this->getT(2).getT(1).getT(10).getT(0);                 // DspNetwork_impl::global_cable74_t<NV>
		auto& add68 = this->getT(2).getT(1).getT(10).getT(1);                          // math::add<NV>
		auto& chain92 = this->getT(2).getT(1).getT(11);                                // DspNetwork_impl::chain92_t<NV>
		auto& global_cable75 = this->getT(2).getT(1).getT(11).getT(0);                 // DspNetwork_impl::global_cable75_t<NV>
		auto& add69 = this->getT(2).getT(1).getT(11).getT(1);                          // math::add<NV>
		auto& chain93 = this->getT(2).getT(1).getT(12);                                // DspNetwork_impl::chain93_t<NV>
		auto& global_cable76 = this->getT(2).getT(1).getT(12).getT(0);                 // DspNetwork_impl::global_cable76_t<NV>
		auto& add70 = this->getT(2).getT(1).getT(12).getT(1);                          // math::add<NV>
		auto& chain94 = this->getT(2).getT(1).getT(13);                                // DspNetwork_impl::chain94_t<NV>
		auto& global_cable77 = this->getT(2).getT(1).getT(13).getT(0);                 // DspNetwork_impl::global_cable77_t<NV>
		auto& add71 = this->getT(2).getT(1).getT(13).getT(1);                          // math::add<NV>
		auto& chain95 = this->getT(2).getT(1).getT(14);                                // DspNetwork_impl::chain95_t<NV>
		auto& global_cable78 = this->getT(2).getT(1).getT(14).getT(0);                 // DspNetwork_impl::global_cable78_t<NV>
		auto& add72 = this->getT(2).getT(1).getT(14).getT(1);                          // math::add<NV>
		auto& chain96 = this->getT(2).getT(1).getT(15);                                // DspNetwork_impl::chain96_t<NV>
		auto& global_cable79 = this->getT(2).getT(1).getT(15).getT(0);                 // DspNetwork_impl::global_cable79_t<NV>
		auto& add73 = this->getT(2).getT(1).getT(15).getT(1);                          // math::add<NV>
		auto& peak6 = this->getT(2).getT(2);                                           // DspNetwork_impl::peak6_t<NV>
		auto& clear8 = this->getT(2).getT(3);                                          // math::clear<NV>
		auto& pma = this->getT(3);                                                     // DspNetwork_impl::pma_t<NV>
		auto& split = this->getT(4);                                                   // DspNetwork_impl::split_t<NV>
		auto& chain1 = this->getT(4).getT(0);                                          // DspNetwork_impl::chain1_t<NV>
		auto& cable_table4 = this->getT(4).getT(0).getT(0);                            // DspNetwork_impl::cable_table4_t<NV>
		auto& resetter = this->getT(4).getT(0).getT(1);                                // DspNetwork_impl::resetter_t<NV>
		auto& clock_ramp1 = this->getT(4).getT(0).getT(2);                             // DspNetwork_impl::clock_ramp1_t<NV>
		auto& ramp = this->getT(4).getT(0).getT(3);                                    // DspNetwork_impl::ramp_t<NV>
		auto& input_toggle3 = this->getT(4).getT(0).getT(4);                           // DspNetwork_impl::input_toggle3_t<NV>
		auto& minmax = this->getT(4).getT(0).getT(5);                                  // DspNetwork_impl::minmax_t<NV>
		auto& clear = this->getT(4).getT(0).getT(6);                                   // math::clear<NV>
		auto& cable_pack1 = this->getT(4).getT(0).getT(7);                             // DspNetwork_impl::cable_pack1_t
		auto& softbypass_switch3 = this->getT(4).getT(1);                              // DspNetwork_impl::softbypass_switch3_t<NV>
		auto& switcher = this->getT(4).getT(1).getT(0);                                // DspNetwork_impl::switcher_t<NV>
		auto& sb_container = this->getT(4).getT(1).getT(1);                            // DspNetwork_impl::sb_container_t<NV>
		auto& sb1 = this->getT(4).getT(1).getT(1).getT(0);                             // DspNetwork_impl::sb1_t<NV>
		auto& chain2 = this->getT(4).getT(1).getT(1).getT(0).getT(0);                  // DspNetwork_impl::chain2_t<NV>
		auto& xfader = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(0);          // DspNetwork_impl::xfader_t<NV>
		auto& split1 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(1);          // DspNetwork_impl::split1_t<NV>
		auto& chain3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(1).getT(0);  // DspNetwork_impl::chain3_t<NV>
		auto& cable_table = this->getT(4).getT(1).getT(1).getT(0).                     // DspNetwork_impl::cable_table_t<NV>
                            getT(0).getT(1).getT(0).getT(0);
		auto& add1 = this->getT(4).getT(1).getT(1).getT(0).                            // math::add<NV>
                     getT(0).getT(1).getT(0).getT(1);
		auto& gain = this->getT(4).getT(1).getT(1).getT(0).                            // core::gain<NV>
                     getT(0).getT(1).getT(0).getT(2);
		auto& chain17 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(1).getT(1); // DspNetwork_impl::chain17_t<NV>
		auto& cable_table17 = this->getT(4).getT(1).getT(1).getT(0).                   // DspNetwork_impl::cable_table17_t<NV>
                              getT(0).getT(1).getT(1).getT(0);
		auto& add15 = this->getT(4).getT(1).getT(1).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& gain14 = this->getT(4).getT(1).getT(1).getT(0).                          // core::gain<NV>
                       getT(0).getT(1).getT(1).getT(2);
		auto& chain16 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(1).getT(2); // DspNetwork_impl::chain16_t<NV>
		auto& cable_table16 = this->getT(4).getT(1).getT(1).getT(0).                   // DspNetwork_impl::cable_table16_t<NV>
                              getT(0).getT(1).getT(2).getT(0);
		auto& add14 = this->getT(4).getT(1).getT(1).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(2).getT(1);
		auto& gain13 = this->getT(4).getT(1).getT(1).getT(0).                          // core::gain<NV>
                       getT(0).getT(1).getT(2).getT(2);
		auto& chain15 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(1).getT(3); // DspNetwork_impl::chain15_t<NV>
		auto& cable_table15 = this->getT(4).getT(1).getT(1).getT(0).                   // DspNetwork_impl::cable_table15_t<NV>
                              getT(0).getT(1).getT(3).getT(0);
		auto& add13 = this->getT(4).getT(1).getT(1).getT(0).                           // math::add<NV>
                      getT(0).getT(1).getT(3).getT(1);
		auto& gain12 = this->getT(4).getT(1).getT(1).getT(0).                          // core::gain<NV>
                       getT(0).getT(1).getT(3).getT(2);
		auto& peak3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(2);           // DspNetwork_impl::peak3_t<NV>
		auto& clear3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(3);          // math::clear<NV>
		auto& add3 = this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(4);            // math::add<NV>
		auto& sb2 = this->getT(4).getT(1).getT(1).getT(1);                             // DspNetwork_impl::sb2_t<NV>
		auto& chain18 = this->getT(4).getT(1).getT(1).getT(1).getT(0);                 // DspNetwork_impl::chain18_t<NV>
		auto& xfader1 = this->getT(4).getT(1).getT(1).getT(1).getT(0).getT(0);         // DspNetwork_impl::xfader1_t<NV>
		auto& split2 = this->getT(4).getT(1).getT(1).getT(1).getT(0).getT(1);          // DspNetwork_impl::split2_t<NV>
		auto& chain19 = this->getT(4).getT(1).getT(1).getT(1).getT(0).getT(1).getT(0); // DspNetwork_impl::chain19_t<NV>
		auto& cable_pack = this->getT(4).getT(1).getT(1).getT(1).                      // DspNetwork_impl::cable_pack_t<NV>
                           getT(0).getT(1).getT(0).getT(0);
		auto& add16 = this->getT(4).getT(1).getT(1).getT(1).                           // math::add<NV>
                      getT(0).getT(1).getT(0).getT(1);
		auto& gain15 = this->getT(4).getT(1).getT(1).getT(1).                          // core::gain<NV>
                       getT(0).getT(1).getT(0).getT(2);
		auto& chain26 = this->getT(4).getT(1).getT(1).getT(1).getT(0).getT(1).getT(1); // DspNetwork_impl::chain26_t<NV>
		auto& cable_pack7 = this->getT(4).getT(1).getT(1).getT(1).                     // DspNetwork_impl::cable_pack7_t<NV>
                            getT(0).getT(1).getT(1).getT(0);
		auto& add23 = this->getT(4).getT(1).getT(1).getT(1).                           // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& gain22 = this->getT(4).getT(1).getT(1).getT(1).                          // core::gain<NV>
                       getT(0).getT(1).getT(1).getT(2);
		auto& chain25 = this->getT(4).getT(1).getT(1).getT(1).getT(0).getT(1).getT(2); // DspNetwork_impl::chain25_t<NV>
		auto& cable_pack6 = this->getT(4).getT(1).getT(1).getT(1).                     // DspNetwork_impl::cable_pack6_t<NV>
                            getT(0).getT(1).getT(2).getT(0);
		auto& add22 = this->getT(4).getT(1).getT(1).getT(1).                           // math::add<NV>
                      getT(0).getT(1).getT(2).getT(1);
		auto& gain21 = this->getT(4).getT(1).getT(1).getT(1).                          // core::gain<NV>
                       getT(0).getT(1).getT(2).getT(2);
		auto& chain24 = this->getT(4).getT(1).getT(1).getT(1).getT(0).getT(1).getT(3); // DspNetwork_impl::chain24_t<NV>
		auto& cable_pack5 = this->getT(4).getT(1).getT(1).getT(1).                     // DspNetwork_impl::cable_pack5_t<NV>
                            getT(0).getT(1).getT(3).getT(0);
		auto& add21 = this->getT(4).getT(1).getT(1).getT(1).                  // math::add<NV>
                      getT(0).getT(1).getT(3).getT(1);
		auto& gain20 = this->getT(4).getT(1).getT(1).getT(1).                 // core::gain<NV>
                       getT(0).getT(1).getT(3).getT(2);
		auto& peak1 = this->getT(4).getT(1).getT(1).getT(1).getT(0).getT(2);  // DspNetwork_impl::peak1_t<NV>
		auto& clear1 = this->getT(4).getT(1).getT(1).getT(1).getT(0).getT(3); // math::clear<NV>
		auto& add2 = this->getT(4).getT(1).getT(1).getT(1).getT(0).getT(4);   // math::add<NV>
		auto& chain29 = this->getT(5);                                        // DspNetwork_impl::chain29_t
		auto& branch1 = this->getT(5).getT(0);                                // DspNetwork_impl::branch1_t
		auto& chain30 = this->getT(5).getT(0).getT(0);                        // DspNetwork_impl::chain30_t
		auto& peak2 = this->getT(5).getT(0).getT(0).getT(0);                  // DspNetwork_impl::peak2_t
		auto& global_cable16 = this->getT(5).getT(0).getT(0).getT(1);         // routing::global_cable<global_cable16_t_index, parameter::empty>
		auto& chain31 = this->getT(5).getT(0).getT(1);                        // DspNetwork_impl::chain31_t
		auto& peak7 = this->getT(5).getT(0).getT(1).getT(0);                  // DspNetwork_impl::peak7_t
		auto& global_cable17 = this->getT(5).getT(0).getT(1).getT(1);         // routing::global_cable<global_cable17_t_index, parameter::empty>
		auto& chain32 = this->getT(5).getT(0).getT(2);                        // DspNetwork_impl::chain32_t
		auto& peak = this->getT(5).getT(0).getT(2).getT(0);                   // DspNetwork_impl::peak_t
		auto& global_cable18 = this->getT(5).getT(0).getT(2).getT(1);         // routing::global_cable<global_cable18_t_index, parameter::empty>
		auto& chain33 = this->getT(5).getT(0).getT(3);                        // DspNetwork_impl::chain33_t
		auto& peak11 = this->getT(5).getT(0).getT(3).getT(0);                 // DspNetwork_impl::peak11_t
		auto& global_cable19 = this->getT(5).getT(0).getT(3).getT(1);         // routing::global_cable<global_cable19_t_index, parameter::empty>
		auto& chain34 = this->getT(5).getT(0).getT(4);                        // DspNetwork_impl::chain34_t
		auto& peak10 = this->getT(5).getT(0).getT(4).getT(0);                 // DspNetwork_impl::peak10_t
		auto& global_cable20 = this->getT(5).getT(0).getT(4).getT(1);         // routing::global_cable<global_cable20_t_index, parameter::empty>
		auto& chain35 = this->getT(5).getT(0).getT(5);                        // DspNetwork_impl::chain35_t
		auto& peak8 = this->getT(5).getT(0).getT(5).getT(0);                  // DspNetwork_impl::peak8_t
		auto& global_cable21 = this->getT(5).getT(0).getT(5).getT(1);         // routing::global_cable<global_cable21_t_index, parameter::empty>
		auto& chain36 = this->getT(5).getT(0).getT(6);                        // DspNetwork_impl::chain36_t
		auto& peak12 = this->getT(5).getT(0).getT(6).getT(0);                 // DspNetwork_impl::peak12_t
		auto& global_cable22 = this->getT(5).getT(0).getT(6).getT(1);         // routing::global_cable<global_cable22_t_index, parameter::empty>
		auto& chain37 = this->getT(5).getT(0).getT(7);                        // DspNetwork_impl::chain37_t
		auto& peak9 = this->getT(5).getT(0).getT(7).getT(0);                  // DspNetwork_impl::peak9_t
		auto& global_cable23 = this->getT(5).getT(0).getT(7).getT(1);         // routing::global_cable<global_cable23_t_index, parameter::empty>
		auto& chain38 = this->getT(5).getT(0).getT(8);                        // DspNetwork_impl::chain38_t
		auto& peak16 = this->getT(5).getT(0).getT(8).getT(0);                 // DspNetwork_impl::peak16_t
		auto& global_cable24 = this->getT(5).getT(0).getT(8).getT(1);         // routing::global_cable<global_cable24_t_index, parameter::empty>
		auto& chain39 = this->getT(5).getT(0).getT(9);                        // DspNetwork_impl::chain39_t
		auto& peak15 = this->getT(5).getT(0).getT(9).getT(0);                 // DspNetwork_impl::peak15_t
		auto& global_cable25 = this->getT(5).getT(0).getT(9).getT(1);         // routing::global_cable<global_cable25_t_index, parameter::empty>
		auto& chain40 = this->getT(5).getT(0).getT(10);                       // DspNetwork_impl::chain40_t
		auto& peak14 = this->getT(5).getT(0).getT(10).getT(0);                // DspNetwork_impl::peak14_t
		auto& global_cable26 = this->getT(5).getT(0).getT(10).getT(1);        // routing::global_cable<global_cable26_t_index, parameter::empty>
		auto& chain41 = this->getT(5).getT(0).getT(11);                       // DspNetwork_impl::chain41_t
		auto& peak17 = this->getT(5).getT(0).getT(11).getT(0);                // DspNetwork_impl::peak17_t
		auto& global_cable27 = this->getT(5).getT(0).getT(11).getT(1);        // routing::global_cable<global_cable27_t_index, parameter::empty>
		auto& chain42 = this->getT(5).getT(0).getT(12);                       // DspNetwork_impl::chain42_t
		auto& peak13 = this->getT(5).getT(0).getT(12).getT(0);                // DspNetwork_impl::peak13_t
		auto& global_cable28 = this->getT(5).getT(0).getT(12).getT(1);        // routing::global_cable<global_cable28_t_index, parameter::empty>
		auto& chain43 = this->getT(5).getT(0).getT(13);                       // DspNetwork_impl::chain43_t
		auto& peak20 = this->getT(5).getT(0).getT(13).getT(0);                // DspNetwork_impl::peak20_t
		auto& global_cable29 = this->getT(5).getT(0).getT(13).getT(1);        // routing::global_cable<global_cable29_t_index, parameter::empty>
		auto& chain44 = this->getT(5).getT(0).getT(14);                       // DspNetwork_impl::chain44_t
		auto& peak19 = this->getT(5).getT(0).getT(14).getT(0);                // DspNetwork_impl::peak19_t
		auto& global_cable30 = this->getT(5).getT(0).getT(14).getT(1);        // routing::global_cable<global_cable30_t_index, parameter::empty>
		auto& chain45 = this->getT(5).getT(0).getT(15);                       // DspNetwork_impl::chain45_t
		auto& peak18 = this->getT(5).getT(0).getT(15).getT(0);                // DspNetwork_impl::peak18_t
		auto& global_cable31 = this->getT(5).getT(0).getT(15).getT(1);        // routing::global_cable<global_cable31_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		softbypass_switch3.getParameterT(0).connectT(0, switcher); // Switch -> switcher::Value
		this->getParameterT(0).connectT(0, pma1);                  // tempo -> pma1::Add
		
		auto& multi_p = this->getParameterT(1);
		multi_p.connectT(0, tempo_sync);  // multi -> tempo_sync::Multiplier
		multi_p.connectT(1, clock_ramp1); // multi -> clock_ramp1::Multiplier
		
		this->getParameterT(2).connectT(0, pma1); // tempomod -> pma1::Multiply
		
		this->getParameterT(3).connectT(0, branch3); // moddest -> branch3::Index
		
		this->getParameterT(4).connectT(0, softbypass_switch3); // type -> softbypass_switch3::Switch
		
		this->getParameterT(5).connectT(0, minmax); // dir -> minmax::Polarity
		
		auto& keysync_p = this->getParameterT(6);
		keysync_p.connectT(0, cable_table1); // keysync -> cable_table1::Value
		keysync_p.connectT(1, cable_table2); // keysync -> cable_table2::Value
		keysync_p.connectT(2, cable_table3); // keysync -> cable_table3::Value
		keysync_p.connectT(3, cable_table4); // keysync -> cable_table4::Value
		
		this->getParameterT(7).connectT(0, ramp); // onshot -> ramp::LoopStart
		
		this->getParameterT(8).connectT(0, pma); // morph -> pma::Add
		
		this->getParameterT(9).connectT(0, pma); // morphmod -> pma::Multiply
		
		this->getParameterT(10).connectT(0, branch4); // morphmodest -> branch4::Index
		
		this->getParameterT(11).connectT(0, branch1); // Out -> branch1::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		cable_table.getWrappedObject().getParameter().connectT(0, add1);       // cable_table -> add1::Value
		cable_table17.getWrappedObject().getParameter().connectT(0, add15);    // cable_table17 -> add15::Value
		cable_table16.getWrappedObject().getParameter().connectT(0, add14);    // cable_table16 -> add14::Value
		cable_table15.getWrappedObject().getParameter().connectT(0, add13);    // cable_table15 -> add13::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add16);       // cable_pack -> add16::Value
		cable_pack7.getWrappedObject().getParameter().connectT(0, add23);      // cable_pack7 -> add23::Value
		cable_pack6.getWrappedObject().getParameter().connectT(0, add22);      // cable_pack6 -> add22::Value
		cable_pack5.getWrappedObject().getParameter().connectT(0, add21);      // cable_pack5 -> add21::Value
		minmax.getWrappedObject().getParameter().connectT(0, cable_table);     // minmax -> cable_table::Value
		minmax.getWrappedObject().getParameter().connectT(1, cable_table17);   // minmax -> cable_table17::Value
		minmax.getWrappedObject().getParameter().connectT(2, cable_table16);   // minmax -> cable_table16::Value
		minmax.getWrappedObject().getParameter().connectT(3, cable_table15);   // minmax -> cable_table15::Value
		minmax.getWrappedObject().getParameter().connectT(4, cable_pack);      // minmax -> cable_pack::Value
		minmax.getWrappedObject().getParameter().connectT(5, cable_pack7);     // minmax -> cable_pack7::Value
		minmax.getWrappedObject().getParameter().connectT(6, cable_pack6);     // minmax -> cable_pack6::Value
		minmax.getWrappedObject().getParameter().connectT(7, cable_pack5);     // minmax -> cable_pack5::Value
		input_toggle3.getWrappedObject().getParameter().connectT(0, minmax);   // input_toggle3 -> minmax::Value
		ramp.getParameter().connectT(0, input_toggle3);                        // ramp -> input_toggle3::Value1
		resetter.getWrappedObject().getParameter().connectT(0, ramp);          // resetter -> ramp::Gate
		input_toggle1.getWrappedObject().getParameter().connectT(0, resetter); // input_toggle1 -> resetter::Value
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, input_toggle1);                // ahdsr -> input_toggle1::Value2
		input_toggle2.getWrappedObject().getParameter().connectT(0, ahdsr); // input_toggle2 -> ahdsr::Gate
		auto& ahdsr1_p = ahdsr1.getWrappedObject().getParameter();
		ahdsr1_p.getParameterT(1).connectT(0, input_toggle2);                      // ahdsr1 -> input_toggle2::Value2
		cable_table3.getWrappedObject().getParameter().connectT(0, input_toggle2); // cable_table3 -> input_toggle2::Input
		global_cable32.getWrappedObject().getParameter().connectT(0, add26);       // global_cable32 -> add26::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add27);       // global_cable33 -> add27::Value
		global_cable34.getWrappedObject().getParameter().connectT(0, add28);       // global_cable34 -> add28::Value
		global_cable35.getWrappedObject().getParameter().connectT(0, add29);       // global_cable35 -> add29::Value
		global_cable36.getWrappedObject().getParameter().connectT(0, add30);       // global_cable36 -> add30::Value
		global_cable37.getWrappedObject().getParameter().connectT(0, add31);       // global_cable37 -> add31::Value
		global_cable38.getWrappedObject().getParameter().connectT(0, add32);       // global_cable38 -> add32::Value
		global_cable39.getWrappedObject().getParameter().connectT(0, add33);       // global_cable39 -> add33::Value
		global_cable40.getWrappedObject().getParameter().connectT(0, add34);       // global_cable40 -> add34::Value
		global_cable41.getWrappedObject().getParameter().connectT(0, add35);       // global_cable41 -> add35::Value
		global_cable42.getWrappedObject().getParameter().connectT(0, add36);       // global_cable42 -> add36::Value
		global_cable43.getWrappedObject().getParameter().connectT(0, add37);       // global_cable43 -> add37::Value
		global_cable44.getWrappedObject().getParameter().connectT(0, add38);       // global_cable44 -> add38::Value
		global_cable45.getWrappedObject().getParameter().connectT(0, add39);       // global_cable45 -> add39::Value
		global_cable46.getWrappedObject().getParameter().connectT(0, add40);       // global_cable46 -> add40::Value
		global_cable47.getWrappedObject().getParameter().connectT(0, add41);       // global_cable47 -> add41::Value
		peak4.getParameter().connectT(0, input_toggle2);                           // peak4 -> input_toggle2::Value1
		cable_table1.getWrappedObject().getParameter().connectT(0, branch2);       // cable_table1 -> branch2::Index
		cable_table2.getWrappedObject().getParameter().connectT(0, input_toggle1); // cable_table2 -> input_toggle1::Input
		global_cable48.getWrappedObject().getParameter().connectT(0, add42);       // global_cable48 -> add42::Value
		global_cable49.getWrappedObject().getParameter().connectT(0, add43);       // global_cable49 -> add43::Value
		global_cable50.getWrappedObject().getParameter().connectT(0, add44);       // global_cable50 -> add44::Value
		global_cable51.getWrappedObject().getParameter().connectT(0, add45);       // global_cable51 -> add45::Value
		global_cable52.getWrappedObject().getParameter().connectT(0, add46);       // global_cable52 -> add46::Value
		global_cable53.getWrappedObject().getParameter().connectT(0, add47);       // global_cable53 -> add47::Value
		global_cable54.getWrappedObject().getParameter().connectT(0, add48);       // global_cable54 -> add48::Value
		global_cable55.getWrappedObject().getParameter().connectT(0, add49);       // global_cable55 -> add49::Value
		global_cable56.getWrappedObject().getParameter().connectT(0, add50);       // global_cable56 -> add50::Value
		global_cable57.getWrappedObject().getParameter().connectT(0, add51);       // global_cable57 -> add51::Value
		global_cable58.getWrappedObject().getParameter().connectT(0, add52);       // global_cable58 -> add52::Value
		global_cable59.getWrappedObject().getParameter().connectT(0, add53);       // global_cable59 -> add53::Value
		global_cable60.getWrappedObject().getParameter().connectT(0, add54);       // global_cable60 -> add54::Value
		global_cable61.getWrappedObject().getParameter().connectT(0, add55);       // global_cable61 -> add55::Value
		global_cable62.getWrappedObject().getParameter().connectT(0, add56);       // global_cable62 -> add56::Value
		global_cable63.getWrappedObject().getParameter().connectT(0, add57);       // global_cable63 -> add57::Value
		tempo_sync.getParameter().connectT(0, ramp);                               // tempo_sync -> ramp::PeriodTime
		clock_ramp1.getParameter().connectT(0, input_toggle3);                     // clock_ramp1 -> input_toggle3::Value2
		pma1.getWrappedObject().getParameter().connectT(0, tempo_sync);            // pma1 -> tempo_sync::Tempo
		pma1.getWrappedObject().getParameter().connectT(1, clock_ramp1);           // pma1 -> clock_ramp1::Tempo
		peak5.getParameter().connectT(0, pma1);                                    // peak5 -> pma1::Value
		global_cable64.getWrappedObject().getParameter().connectT(0, add58);       // global_cable64 -> add58::Value
		global_cable65.getWrappedObject().getParameter().connectT(0, add59);       // global_cable65 -> add59::Value
		global_cable66.getWrappedObject().getParameter().connectT(0, add60);       // global_cable66 -> add60::Value
		global_cable67.getWrappedObject().getParameter().connectT(0, add61);       // global_cable67 -> add61::Value
		global_cable68.getWrappedObject().getParameter().connectT(0, add62);       // global_cable68 -> add62::Value
		global_cable69.getWrappedObject().getParameter().connectT(0, add63);       // global_cable69 -> add63::Value
		global_cable70.getWrappedObject().getParameter().connectT(0, add64);       // global_cable70 -> add64::Value
		global_cable71.getWrappedObject().getParameter().connectT(0, add65);       // global_cable71 -> add65::Value
		global_cable72.getWrappedObject().getParameter().connectT(0, add66);       // global_cable72 -> add66::Value
		global_cable73.getWrappedObject().getParameter().connectT(0, add67);       // global_cable73 -> add67::Value
		global_cable74.getWrappedObject().getParameter().connectT(0, add68);       // global_cable74 -> add68::Value
		global_cable75.getWrappedObject().getParameter().connectT(0, add69);       // global_cable75 -> add69::Value
		global_cable76.getWrappedObject().getParameter().connectT(0, add70);       // global_cable76 -> add70::Value
		global_cable77.getWrappedObject().getParameter().connectT(0, add71);       // global_cable77 -> add71::Value
		global_cable78.getWrappedObject().getParameter().connectT(0, add72);       // global_cable78 -> add72::Value
		global_cable79.getWrappedObject().getParameter().connectT(0, add73);       // global_cable79 -> add73::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);   // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain14); // xfader -> gain14::Gain
		xfader_p.getParameterT(2).connectT(0, gain13); // xfader -> gain13::Gain
		xfader_p.getParameterT(3).connectT(0, gain12); // xfader -> gain12::Gain
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain15);                            // xfader1 -> gain15::Gain
		xfader1_p.getParameterT(1).connectT(0, gain22);                            // xfader1 -> gain22::Gain
		xfader1_p.getParameterT(2).connectT(0, gain21);                            // xfader1 -> gain21::Gain
		xfader1_p.getParameterT(3).connectT(0, gain20);                            // xfader1 -> gain20::Gain
		pma.getWrappedObject().getParameter().connectT(0, xfader);                 // pma -> xfader::Value
		pma.getWrappedObject().getParameter().connectT(1, xfader1);                // pma -> xfader1::Value
		pma.getWrappedObject().getParameter().connectT(2, cable_pack1);            // pma -> cable_pack1::Value
		peak6.getParameter().connectT(0, pma);                                     // peak6 -> pma::Value
		cable_table4.getWrappedObject().getParameter().connectT(0, input_toggle3); // cable_table4 -> input_toggle3::Input
		peak3.getParameter().connectT(0, add3);                                    // peak3 -> add3::Value
		peak1.getParameter().connectT(0, add2);                                    // peak1 -> add2::Value
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1);      // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2);      // switcher -> sb2::Bypassed
		peak2.getParameter().connectT(0, global_cable16);  // peak2 -> global_cable16::Value
		peak7.getParameter().connectT(0, global_cable17);  // peak7 -> global_cable17::Value
		peak.getParameter().connectT(0, global_cable18);   // peak -> global_cable18::Value
		peak11.getParameter().connectT(0, global_cable19); // peak11 -> global_cable19::Value
		peak10.getParameter().connectT(0, global_cable20); // peak10 -> global_cable20::Value
		peak8.getParameter().connectT(0, global_cable21);  // peak8 -> global_cable21::Value
		peak12.getParameter().connectT(0, global_cable22); // peak12 -> global_cable22::Value
		peak9.getParameter().connectT(0, global_cable23);  // peak9 -> global_cable23::Value
		peak16.getParameter().connectT(0, global_cable24); // peak16 -> global_cable24::Value
		peak15.getParameter().connectT(0, global_cable25); // peak15 -> global_cable25::Value
		peak14.getParameter().connectT(0, global_cable26); // peak14 -> global_cable26::Value
		peak17.getParameter().connectT(0, global_cable27); // peak17 -> global_cable27::Value
		peak13.getParameter().connectT(0, global_cable28); // peak13 -> global_cable28::Value
		peak20.getParameter().connectT(0, global_cable29); // peak20 -> global_cable29::Value
		peak19.getParameter().connectT(0, global_cable30); // peak19 -> global_cable30::Value
		peak18.getParameter().connectT(0, global_cable31); // peak18 -> global_cable31::Value
		
		// Default Values --------------------------------------------------------------------------
		
		ahdsr1.setParameterT(0, 0.);    // envelope::ahdsr::Attack
		ahdsr1.setParameterT(1, 1.);    // envelope::ahdsr::AttackLevel
		ahdsr1.setParameterT(2, 0.);    // envelope::ahdsr::Hold
		ahdsr1.setParameterT(3, 335.1); // envelope::ahdsr::Decay
		ahdsr1.setParameterT(4, 0.);    // envelope::ahdsr::Sustain
		ahdsr1.setParameterT(5, 0.);    // envelope::ahdsr::Release
		ahdsr1.setParameterT(6, 0.5);   // envelope::ahdsr::AttackCurve
		ahdsr1.setParameterT(7, 0.);    // envelope::ahdsr::Retrigger
		ahdsr1.setParameterT(8, 1.);    // envelope::ahdsr::Gate
		
		; // cable_table3::Value is automated
		
		; // input_toggle2::Input is automated
		; // input_toggle2::Value1 is automated
		; // input_toggle2::Value2 is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		; // branch2::Index is automated
		
		global_cable32.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		global_cable33.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		global_cable34.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add28::Value is automated
		
		global_cable35.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add29::Value is automated
		
		global_cable36.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add30::Value is automated
		
		global_cable37.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add31::Value is automated
		
		global_cable38.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		global_cable39.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add33::Value is automated
		
		global_cable40.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add34::Value is automated
		
		global_cable41.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add35::Value is automated
		
		global_cable42.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add36::Value is automated
		
		global_cable43.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add37::Value is automated
		
		global_cable44.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add38::Value is automated
		
		global_cable45.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add39::Value is automated
		
		global_cable46.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add40::Value is automated
		
		global_cable47.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add41::Value is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table1::Value is automated
		
		ahdsr.setParameterT(0, 0.);   // envelope::ahdsr::Attack
		ahdsr.setParameterT(1, 1.);   // envelope::ahdsr::AttackLevel
		ahdsr.setParameterT(2, 0.);   // envelope::ahdsr::Hold
		ahdsr.setParameterT(3, 27.2); // envelope::ahdsr::Decay
		ahdsr.setParameterT(4, 0.);   // envelope::ahdsr::Sustain
		ahdsr.setParameterT(5, 0.);   // envelope::ahdsr::Release
		ahdsr.setParameterT(6, 0.);   // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);   // envelope::ahdsr::Retrigger
		;                             // ahdsr::Gate is automated
		
		; // cable_table2::Value is automated
		
		;                                   // input_toggle1::Input is automated
		input_toggle1.setParameterT(1, 0.); // control::input_toggle::Value1
		;                                   // input_toggle1::Value2 is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // branch3::Index is automated
		
		global_cable48.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add42::Value is automated
		
		global_cable49.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add43::Value is automated
		
		global_cable50.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add44::Value is automated
		
		global_cable51.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add45::Value is automated
		
		global_cable52.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add46::Value is automated
		
		global_cable53.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add47::Value is automated
		
		global_cable54.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add48::Value is automated
		
		global_cable55.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add49::Value is automated
		
		global_cable56.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add50::Value is automated
		
		global_cable57.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add51::Value is automated
		
		global_cable58.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add52::Value is automated
		
		global_cable59.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add53::Value is automated
		
		global_cable60.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add54::Value is automated
		
		global_cable61.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add55::Value is automated
		
		global_cable62.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add56::Value is automated
		
		global_cable63.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add57::Value is automated
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		;                                // tempo_sync::Tempo is automated
		;                                // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.); // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 0.); // control::tempo_sync::UnsyncedTime
		
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
		
		clear8.setParameterT(0, 0.); // math::clear::Value
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		; // cable_table4::Value is automated
		
		; // resetter::Value is automated
		
		;                                 // clock_ramp1::Tempo is automated
		;                                 // clock_ramp1::Multiplier is automated
		clock_ramp1.setParameterT(2, 0.); // core::clock_ramp::AddToSignal
		clock_ramp1.setParameterT(3, 0.); // core::clock_ramp::UpdateMode
		clock_ramp1.setParameterT(4, 0.); // core::clock_ramp::Inactive
		
		; // ramp::PeriodTime is automated
		; // ramp::LoopStart is automated
		; // ramp::Gate is automated
		
		; // input_toggle3::Input is automated
		; // input_toggle3::Value1 is automated
		; // input_toggle3::Value2 is automated
		
		;                                  // minmax::Value is automated
		minmax.setParameterT(1, 0.);       // control::minmax::Minimum
		minmax.setParameterT(2, 1.);       // control::minmax::Maximum
		minmax.setParameterT(3, 0.992434); // control::minmax::Skew
		minmax.setParameterT(4, 0.);       // control::minmax::Step
		;                                  // minmax::Polarity is automated
		
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
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // add2::Value is automated
		
		; // branch1::Index is automated
		
		; // global_cable16::Value is automated
		
		; // global_cable17::Value is automated
		
		; // global_cable18::Value is automated
		
		; // global_cable19::Value is automated
		
		; // global_cable20::Value is automated
		
		; // global_cable21::Value is automated
		
		; // global_cable22::Value is automated
		
		; // global_cable23::Value is automated
		
		; // global_cable24::Value is automated
		
		; // global_cable25::Value is automated
		
		; // global_cable26::Value is automated
		
		; // global_cable27::Value is automated
		
		; // global_cable28::Value is automated
		
		; // global_cable29::Value is automated
		
		; // global_cable30::Value is automated
		
		; // global_cable31::Value is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 0.5);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 0.5);
		this->setParameterT(10, 4.);
		this->setParameterT(11, 0.);
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
	
	static constexpr bool isSuspendedOnSilence() { return true; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable32_t<NV>
		this->getT(0).getT(3).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable33_t<NV>
		this->getT(0).getT(3).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable34_t<NV>
		this->getT(0).getT(3).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable35_t<NV>
		this->getT(0).getT(3).getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable36_t<NV>
		this->getT(0).getT(3).getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable37_t<NV>
		this->getT(0).getT(3).getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable38_t<NV>
		this->getT(0).getT(3).getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable39_t<NV>
		this->getT(0).getT(3).getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable40_t<NV>
		this->getT(0).getT(3).getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable41_t<NV>
		this->getT(0).getT(3).getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable42_t<NV>
		this->getT(0).getT(3).getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable43_t<NV>
		this->getT(0).getT(3).getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable44_t<NV>
		this->getT(0).getT(3).getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable45_t<NV>
		this->getT(0).getT(3).getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable46_t<NV>
		this->getT(0).getT(3).getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable47_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable48_t<NV>
		this->getT(1).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable49_t<NV>
		this->getT(1).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable50_t<NV>
		this->getT(1).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable51_t<NV>
		this->getT(1).getT(0).getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable52_t<NV>
		this->getT(1).getT(0).getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable53_t<NV>
		this->getT(1).getT(0).getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable54_t<NV>
		this->getT(1).getT(0).getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable55_t<NV>
		this->getT(1).getT(0).getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable56_t<NV>
		this->getT(1).getT(0).getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);  // DspNetwork_impl::global_cable57_t<NV>
		this->getT(1).getT(0).getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable58_t<NV>
		this->getT(1).getT(0).getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable59_t<NV>
		this->getT(1).getT(0).getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable60_t<NV>
		this->getT(1).getT(0).getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable61_t<NV>
		this->getT(1).getT(0).getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable62_t<NV>
		this->getT(1).getT(0).getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c); // DspNetwork_impl::global_cable63_t<NV>
		this->getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);          // DspNetwork_impl::global_cable64_t<NV>
		this->getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);          // DspNetwork_impl::global_cable65_t<NV>
		this->getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);          // DspNetwork_impl::global_cable66_t<NV>
		this->getT(2).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);          // DspNetwork_impl::global_cable67_t<NV>
		this->getT(2).getT(1).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);          // DspNetwork_impl::global_cable68_t<NV>
		this->getT(2).getT(1).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);          // DspNetwork_impl::global_cable69_t<NV>
		this->getT(2).getT(1).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);          // DspNetwork_impl::global_cable70_t<NV>
		this->getT(2).getT(1).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);          // DspNetwork_impl::global_cable71_t<NV>
		this->getT(2).getT(1).getT(8).getT(0).connectToRuntimeTarget(addConnection, c);          // DspNetwork_impl::global_cable72_t<NV>
		this->getT(2).getT(1).getT(9).getT(0).connectToRuntimeTarget(addConnection, c);          // DspNetwork_impl::global_cable73_t<NV>
		this->getT(2).getT(1).getT(10).getT(0).connectToRuntimeTarget(addConnection, c);         // DspNetwork_impl::global_cable74_t<NV>
		this->getT(2).getT(1).getT(11).getT(0).connectToRuntimeTarget(addConnection, c);         // DspNetwork_impl::global_cable75_t<NV>
		this->getT(2).getT(1).getT(12).getT(0).connectToRuntimeTarget(addConnection, c);         // DspNetwork_impl::global_cable76_t<NV>
		this->getT(2).getT(1).getT(13).getT(0).connectToRuntimeTarget(addConnection, c);         // DspNetwork_impl::global_cable77_t<NV>
		this->getT(2).getT(1).getT(14).getT(0).connectToRuntimeTarget(addConnection, c);         // DspNetwork_impl::global_cable78_t<NV>
		this->getT(2).getT(1).getT(15).getT(0).connectToRuntimeTarget(addConnection, c);         // DspNetwork_impl::global_cable79_t<NV>
		this->getT(5).getT(0).getT(0).getT(1).connectToRuntimeTarget(addConnection, c);          // routing::global_cable<global_cable16_t_index, parameter::empty>
		this->getT(5).getT(0).getT(1).getT(1).connectToRuntimeTarget(addConnection, c);          // routing::global_cable<global_cable17_t_index, parameter::empty>
		this->getT(5).getT(0).getT(2).getT(1).connectToRuntimeTarget(addConnection, c);          // routing::global_cable<global_cable18_t_index, parameter::empty>
		this->getT(5).getT(0).getT(3).getT(1).connectToRuntimeTarget(addConnection, c);          // routing::global_cable<global_cable19_t_index, parameter::empty>
		this->getT(5).getT(0).getT(4).getT(1).connectToRuntimeTarget(addConnection, c);          // routing::global_cable<global_cable20_t_index, parameter::empty>
		this->getT(5).getT(0).getT(5).getT(1).connectToRuntimeTarget(addConnection, c);          // routing::global_cable<global_cable21_t_index, parameter::empty>
		this->getT(5).getT(0).getT(6).getT(1).connectToRuntimeTarget(addConnection, c);          // routing::global_cable<global_cable22_t_index, parameter::empty>
		this->getT(5).getT(0).getT(7).getT(1).connectToRuntimeTarget(addConnection, c);          // routing::global_cable<global_cable23_t_index, parameter::empty>
		this->getT(5).getT(0).getT(8).getT(1).connectToRuntimeTarget(addConnection, c);          // routing::global_cable<global_cable24_t_index, parameter::empty>
		this->getT(5).getT(0).getT(9).getT(1).connectToRuntimeTarget(addConnection, c);          // routing::global_cable<global_cable25_t_index, parameter::empty>
		this->getT(5).getT(0).getT(10).getT(1).connectToRuntimeTarget(addConnection, c);         // routing::global_cable<global_cable26_t_index, parameter::empty>
		this->getT(5).getT(0).getT(11).getT(1).connectToRuntimeTarget(addConnection, c);         // routing::global_cable<global_cable27_t_index, parameter::empty>
		this->getT(5).getT(0).getT(12).getT(1).connectToRuntimeTarget(addConnection, c);         // routing::global_cable<global_cable28_t_index, parameter::empty>
		this->getT(5).getT(0).getT(13).getT(1).connectToRuntimeTarget(addConnection, c);         // routing::global_cable<global_cable29_t_index, parameter::empty>
		this->getT(5).getT(0).getT(14).getT(1).connectToRuntimeTarget(addConnection, c);         // routing::global_cable<global_cable30_t_index, parameter::empty>
		this->getT(5).getT(0).getT(15).getT(1).connectToRuntimeTarget(addConnection, c);         // routing::global_cable<global_cable31_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).setExternalData(b, index);                                 // DspNetwork_impl::ahdsr1_t<NV>
		this->getT(0).getT(1).setExternalData(b, index);                                 // DspNetwork_impl::cable_table3_t<NV>
		this->getT(0).getT(3).getT(2).setExternalData(b, index);                         // DspNetwork_impl::peak4_t<NV>
		this->getT(0).getT(4).setExternalData(b, index);                                 // DspNetwork_impl::cable_table1_t<NV>
		this->getT(0).getT(5).setExternalData(b, index);                                 // DspNetwork_impl::ahdsr_t<NV>
		this->getT(0).getT(6).setExternalData(b, index);                                 // DspNetwork_impl::cable_table2_t<NV>
		this->getT(1).getT(0).getT(2).setExternalData(b, index);                         // DspNetwork_impl::peak5_t<NV>
		this->getT(2).getT(2).setExternalData(b, index);                                 // DspNetwork_impl::peak6_t<NV>
		this->getT(4).getT(0).getT(0).setExternalData(b, index);                         // DspNetwork_impl::cable_table4_t<NV>
		this->getT(4).getT(0).getT(2).setExternalData(b, index);                         // DspNetwork_impl::clock_ramp1_t<NV>
		this->getT(4).getT(0).getT(3).setExternalData(b, index);                         // DspNetwork_impl::ramp_t<NV>
		this->getT(4).getT(0).getT(7).setExternalData(b, index);                         // DspNetwork_impl::cable_pack1_t
		this->getT(4).getT(1).getT(1).getT(0).                                           // DspNetwork_impl::cable_table_t<NV>
        getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(4).getT(1).getT(1).getT(0).                                           // DspNetwork_impl::cable_table17_t<NV>
        getT(0).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(4).getT(1).getT(1).getT(0).                                           // DspNetwork_impl::cable_table16_t<NV>
        getT(0).getT(1).getT(2).getT(0).setExternalData(b, index);
		this->getT(4).getT(1).getT(1).getT(0).                                           // DspNetwork_impl::cable_table15_t<NV>
        getT(0).getT(1).getT(3).getT(0).setExternalData(b, index);
		this->getT(4).getT(1).getT(1).getT(0).getT(0).getT(2).setExternalData(b, index); // DspNetwork_impl::peak3_t<NV>
		this->getT(4).getT(1).getT(1).getT(1).                                           // DspNetwork_impl::cable_pack_t<NV>
        getT(0).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(4).getT(1).getT(1).getT(1).                                           // DspNetwork_impl::cable_pack7_t<NV>
        getT(0).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(4).getT(1).getT(1).getT(1).                                           // DspNetwork_impl::cable_pack6_t<NV>
        getT(0).getT(1).getT(2).getT(0).setExternalData(b, index);
		this->getT(4).getT(1).getT(1).getT(1).                                           // DspNetwork_impl::cable_pack5_t<NV>
        getT(0).getT(1).getT(3).getT(0).setExternalData(b, index);
		this->getT(4).getT(1).getT(1).getT(1).getT(0).getT(2).setExternalData(b, index); // DspNetwork_impl::peak1_t<NV>
		this->getT(5).getT(0).getT(0).getT(0).setExternalData(b, index);                 // DspNetwork_impl::peak2_t
		this->getT(5).getT(0).getT(1).getT(0).setExternalData(b, index);                 // DspNetwork_impl::peak7_t
		this->getT(5).getT(0).getT(2).getT(0).setExternalData(b, index);                 // DspNetwork_impl::peak_t
		this->getT(5).getT(0).getT(3).getT(0).setExternalData(b, index);                 // DspNetwork_impl::peak11_t
		this->getT(5).getT(0).getT(4).getT(0).setExternalData(b, index);                 // DspNetwork_impl::peak10_t
		this->getT(5).getT(0).getT(5).getT(0).setExternalData(b, index);                 // DspNetwork_impl::peak8_t
		this->getT(5).getT(0).getT(6).getT(0).setExternalData(b, index);                 // DspNetwork_impl::peak12_t
		this->getT(5).getT(0).getT(7).getT(0).setExternalData(b, index);                 // DspNetwork_impl::peak9_t
		this->getT(5).getT(0).getT(8).getT(0).setExternalData(b, index);                 // DspNetwork_impl::peak16_t
		this->getT(5).getT(0).getT(9).getT(0).setExternalData(b, index);                 // DspNetwork_impl::peak15_t
		this->getT(5).getT(0).getT(10).getT(0).setExternalData(b, index);                // DspNetwork_impl::peak14_t
		this->getT(5).getT(0).getT(11).getT(0).setExternalData(b, index);                // DspNetwork_impl::peak17_t
		this->getT(5).getT(0).getT(12).getT(0).setExternalData(b, index);                // DspNetwork_impl::peak13_t
		this->getT(5).getT(0).getT(13).getT(0).setExternalData(b, index);                // DspNetwork_impl::peak20_t
		this->getT(5).getT(0).getT(14).getT(0).setExternalData(b, index);                // DspNetwork_impl::peak19_t
		this->getT(5).getT(0).getT(15).getT(0).setExternalData(b, index);                // DspNetwork_impl::peak18_t
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


