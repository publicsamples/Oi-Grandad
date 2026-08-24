#pragma once

#include "granular_player_stepquant_density_hybrid_native.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace MatrixTest2_impl
{
// ==============================| Node & Parameter type declarations |==============================

using pitch_mod_t_index = runtime_target::indexers::fix_hash<90001>;

template <int NV>
using converter_mod = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                       0>;
template <int NV>
using converter_t = control::converter<converter_mod<NV>, 
                                       conversion_logic::pitch2st>;
template <int NV>
using pitch_mod_t = wrap::mod<parameter::plain<converter_t<NV>, 0>, 
                              wrap::no_data<core::pitch_mod<NV, pitch_mod_t_index>>>;
using extra_mod2_t_index = runtime_target::indexers::fix_hash<5000>;
using extra_mod2_t_config = modulation::config::constant<false, 
                                                         modulation::TargetMode::Raw>;

template <int NV>
using tempo_sync_mod = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                        2>;
template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(extra_mod2_modRange, 
                             1, 
                             500., 
                             0.1);

template <int NV>
using extra_mod2_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                           3, 
                                           extra_mod2_modRange>;

template <int NV>
using extra_mod2_t = wrap::mod<extra_mod2_mod<NV>, 
                               wrap::no_data<core::extra_mod<NV, extra_mod2_t_index, extra_mod2_t_config>>>;
using extra_mod6_t_index = extra_mod2_t_index;
using extra_mod6_t_config = extra_mod2_t_config;

DECLARE_PARAMETER_RANGE_STEP(cable_table5_modRange, 
                             4., 
                             16., 
                             0.1);

template <int NV>
using cable_table5_mod = parameter::from0To1<fx::bitcrush<NV>, 
                                             0, 
                                             cable_table5_modRange>;

struct cable_table5_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998043f, 0.996086f, 0.994129f, 0.992172f, 0.990215f,
		0.988258f, 0.986301f, 0.984344f, 0.982387f, 0.980431f, 0.978474f,
		0.976517f, 0.97456f, 0.972603f, 0.970646f, 0.968689f, 0.966732f,
		0.964775f, 0.962818f, 0.960861f, 0.958904f, 0.956947f, 0.95499f,
		0.953033f, 0.951076f, 0.949119f, 0.947162f, 0.945205f, 0.943249f,
		0.941292f, 0.939335f, 0.937378f, 0.935421f, 0.933464f, 0.931507f,
		0.92955f, 0.927593f, 0.925636f, 0.923679f, 0.921722f, 0.919765f,
		0.917808f, 0.915851f, 0.913894f, 0.911937f, 0.90998f, 0.908023f,
		0.906067f, 0.90411f, 0.902153f, 0.900196f, 0.898239f, 0.896282f,
		0.894325f, 0.892368f, 0.890411f, 0.888454f, 0.886497f, 0.88454f,
		0.882583f, 0.880626f, 0.878669f, 0.876712f, 0.874755f, 0.872798f,
		0.870842f, 0.868885f, 0.866928f, 0.864971f, 0.863014f, 0.861057f,
		0.8591f, 0.857143f, 0.855186f, 0.853229f, 0.851272f, 0.849315f,
		0.847358f, 0.845401f, 0.843444f, 0.841487f, 0.83953f, 0.837573f,
		0.835616f, 0.833659f, 0.831703f, 0.829746f, 0.827789f, 0.825832f,
		0.823875f, 0.821918f, 0.819961f, 0.818004f, 0.816047f, 0.81409f,
		0.812133f, 0.810176f, 0.808219f, 0.806262f, 0.804305f, 0.802348f,
		0.800391f, 0.798434f, 0.796477f, 0.794521f, 0.792564f, 0.790607f,
		0.78865f, 0.786693f, 0.784736f, 0.782779f, 0.780822f, 0.778865f,
		0.776908f, 0.774951f, 0.772994f, 0.771037f, 0.76908f, 0.767123f,
		0.765166f, 0.763209f, 0.761252f, 0.759295f, 0.757339f, 0.755382f,
		0.753425f, 0.751468f, 0.749511f, 0.747554f, 0.745597f, 0.74364f,
		0.741683f, 0.739726f, 0.737769f, 0.735812f, 0.733855f, 0.731898f,
		0.729941f, 0.727984f, 0.726027f, 0.72407f, 0.722113f, 0.720157f,
		0.7182f, 0.716243f, 0.714286f, 0.712329f, 0.710372f, 0.708415f,
		0.706458f, 0.704501f, 0.702544f, 0.700587f, 0.69863f, 0.696673f,
		0.694716f, 0.692759f, 0.690802f, 0.688845f, 0.686888f, 0.684932f,
		0.682975f, 0.681018f, 0.679061f, 0.677104f, 0.675147f, 0.67319f,
		0.671233f, 0.669276f, 0.667319f, 0.665362f, 0.663405f, 0.661448f,
		0.659491f, 0.657534f, 0.655577f, 0.65362f, 0.651663f, 0.649706f,
		0.64775f, 0.645793f, 0.643836f, 0.641879f, 0.639922f, 0.637965f,
		0.636008f, 0.634051f, 0.632094f, 0.630137f, 0.62818f, 0.626223f,
		0.624266f, 0.622309f, 0.620352f, 0.618395f, 0.616438f, 0.614481f,
		0.612524f, 0.610568f, 0.608611f, 0.606654f, 0.604697f, 0.60274f,
		0.600783f, 0.598826f, 0.596869f, 0.594912f, 0.592955f, 0.590998f,
		0.589041f, 0.587084f, 0.585127f, 0.58317f, 0.581213f, 0.579256f,
		0.577299f, 0.575342f, 0.573385f, 0.571429f, 0.569472f, 0.567515f,
		0.565558f, 0.563601f, 0.561644f, 0.559687f, 0.55773f, 0.555773f,
		0.553816f, 0.551859f, 0.549902f, 0.547945f, 0.545988f, 0.544031f,
		0.542074f, 0.540117f, 0.53816f, 0.536204f, 0.534247f, 0.53229f,
		0.530333f, 0.528376f, 0.526419f, 0.524462f, 0.522505f, 0.520548f,
		0.518591f, 0.516634f, 0.514677f, 0.51272f, 0.510763f, 0.508806f,
		0.506849f, 0.504892f, 0.502935f, 0.500978f, 0.499022f, 0.497065f,
		0.495108f, 0.493151f, 0.491194f, 0.489237f, 0.48728f, 0.485323f,
		0.483366f, 0.481409f, 0.479452f, 0.477495f, 0.475538f, 0.473581f,
		0.471624f, 0.469667f, 0.46771f, 0.465753f, 0.463796f, 0.46184f,
		0.459883f, 0.457926f, 0.455969f, 0.454012f, 0.452055f, 0.450098f,
		0.448141f, 0.446184f, 0.444227f, 0.44227f, 0.440313f, 0.438356f,
		0.436399f, 0.434442f, 0.432485f, 0.430528f, 0.428571f, 0.426614f,
		0.424658f, 0.422701f, 0.420744f, 0.418787f, 0.41683f, 0.414873f,
		0.412916f, 0.410959f, 0.409002f, 0.407045f, 0.405088f, 0.403131f,
		0.401174f, 0.399217f, 0.39726f, 0.395303f, 0.393346f, 0.391389f,
		0.389432f, 0.387476f, 0.385519f, 0.383562f, 0.381605f, 0.379648f,
		0.377691f, 0.375734f, 0.373777f, 0.37182f, 0.369863f, 0.367906f,
		0.365949f, 0.363992f, 0.362035f, 0.360078f, 0.358121f, 0.356164f,
		0.354207f, 0.352251f, 0.350294f, 0.348337f, 0.34638f, 0.344423f,
		0.342466f, 0.340509f, 0.338552f, 0.336595f, 0.334638f, 0.332681f,
		0.330724f, 0.328767f, 0.32681f, 0.324853f, 0.322896f, 0.320939f,
		0.318982f, 0.317025f, 0.315068f, 0.313112f, 0.311155f, 0.309198f,
		0.307241f, 0.305284f, 0.303327f, 0.30137f, 0.299413f, 0.297456f,
		0.295499f, 0.293542f, 0.291585f, 0.289628f, 0.287671f, 0.285714f,
		0.283757f, 0.2818f, 0.279843f, 0.277887f, 0.27593f, 0.273973f,
		0.272016f, 0.270059f, 0.268102f, 0.266145f, 0.264188f, 0.262231f,
		0.260274f, 0.258317f, 0.25636f, 0.254403f, 0.252446f, 0.250489f,
		0.248532f, 0.246575f, 0.244618f, 0.242661f, 0.240704f, 0.238748f,
		0.236791f, 0.234834f, 0.232877f, 0.23092f, 0.228963f, 0.227006f,
		0.225049f, 0.223092f, 0.221135f, 0.219178f, 0.217221f, 0.215264f,
		0.213307f, 0.21135f, 0.209393f, 0.207436f, 0.205479f, 0.203523f,
		0.201566f, 0.199609f, 0.197652f, 0.195695f, 0.193738f, 0.191781f,
		0.189824f, 0.187867f, 0.18591f, 0.183953f, 0.181996f, 0.180039f,
		0.178082f, 0.176125f, 0.174168f, 0.172211f, 0.170254f, 0.168297f,
		0.166341f, 0.164384f, 0.162427f, 0.16047f, 0.158513f, 0.156556f,
		0.154599f, 0.152642f, 0.150685f, 0.148728f, 0.146771f, 0.144814f,
		0.142857f, 0.1409f, 0.138943f, 0.136986f, 0.135029f, 0.133072f,
		0.131115f, 0.129158f, 0.127202f, 0.125245f, 0.123288f, 0.121331f,
		0.119374f, 0.117417f, 0.11546f, 0.113503f, 0.111546f, 0.109589f,
		0.107632f, 0.105675f, 0.103718f, 0.101761f, 0.0998043f, 0.0978474f,
		0.0958903f, 0.0939335f, 0.0919765f, 0.0900196f, 0.0880627f, 0.0861056f,
		0.0841488f, 0.0821917f, 0.0802348f, 0.0782779f, 0.0763209f, 0.0743641f,
		0.072407f, 0.0704501f, 0.0684931f, 0.0665362f, 0.0645792f, 0.0626223f,
		0.0606654f, 0.0587084f, 0.0567515f, 0.0547945f, 0.0528376f, 0.0508806f,
		0.0489237f, 0.0469668f, 0.0450097f, 0.0430529f, 0.0410959f, 0.039139f,
		0.037182f, 0.035225f, 0.0332682f, 0.0313111f, 0.0293542f, 0.0273973f,
		0.0254403f, 0.0234835f, 0.0215264f, 0.0195695f, 0.0176125f, 0.0156556f,
		0.0136986f, 0.0117417f, 0.00978482f, 0.00782776f, 0.00587088f, 0.00391382f,
		0.00195694f, 0.f
	};
};

template <int NV>
using cable_table5_t = wrap::data<control::cable_table<cable_table5_mod<NV>>, 
                                  data::embedded::table<cable_table5_t_data>>;

// Apply the pitch modulation to the delay time ----------------------------------------------------

template <int NV>
using pma_unscaled4_t = control::pma_unscaled<NV, 
                                              parameter::plain<filters::allpass<NV>, 0>>;

template <int NV>
using converter7_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<wrap::no_process<core::fix_delay>, 0>, 
                                        parameter::plain<jdsp::jdelay_thiran<NV>, 1>>;

template <int NV>
using converter7_t = control::converter<converter7_mod<NV>, 
                                        conversion_logic::freq2ms>;
// Apply the pitch modulation to the delay time ----------------------------------------------------

template <int NV>
using pma_unscaled3_t = control::pma_unscaled<NV, 
                                              parameter::plain<converter7_t<NV>, 0>>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::fmod<NV>, 0>, 
                                  parameter::plain<math::div<NV>, 0>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
DECLARE_PARAMETER_RANGE_SKEW(cable_table6_modRange, 
                             0., 
                             0.3, 
                             0.253636);

template <int NV>
using cable_table6_mod = parameter::from0To1<pma1_t<NV>, 
                                             2, 
                                             cable_table6_modRange>;

struct cable_table6_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998043f, 0.996086f, 0.994129f, 0.992172f, 0.990215f,
		0.988258f, 0.986301f, 0.984344f, 0.982387f, 0.980431f, 0.978474f,
		0.976517f, 0.97456f, 0.972603f, 0.970646f, 0.968689f, 0.966732f,
		0.964775f, 0.962818f, 0.960861f, 0.958904f, 0.956947f, 0.95499f,
		0.953033f, 0.951076f, 0.949119f, 0.947162f, 0.945205f, 0.943249f,
		0.941292f, 0.939335f, 0.937378f, 0.935421f, 0.933464f, 0.931507f,
		0.92955f, 0.927593f, 0.925636f, 0.923679f, 0.921722f, 0.919765f,
		0.917808f, 0.915851f, 0.913894f, 0.911937f, 0.90998f, 0.908023f,
		0.906067f, 0.90411f, 0.902153f, 0.900196f, 0.898239f, 0.896282f,
		0.894325f, 0.892368f, 0.890411f, 0.888454f, 0.886497f, 0.88454f,
		0.882583f, 0.880626f, 0.878669f, 0.876712f, 0.874755f, 0.872798f,
		0.870842f, 0.868885f, 0.866928f, 0.864971f, 0.863014f, 0.861057f,
		0.8591f, 0.857143f, 0.855186f, 0.853229f, 0.851272f, 0.849315f,
		0.847358f, 0.845401f, 0.843444f, 0.841487f, 0.83953f, 0.837573f,
		0.835616f, 0.833659f, 0.831703f, 0.829746f, 0.827789f, 0.825832f,
		0.823875f, 0.821918f, 0.819961f, 0.818004f, 0.816047f, 0.81409f,
		0.812133f, 0.810176f, 0.808219f, 0.806262f, 0.804305f, 0.802348f,
		0.800391f, 0.798434f, 0.796477f, 0.794521f, 0.792564f, 0.790607f,
		0.78865f, 0.786693f, 0.784736f, 0.782779f, 0.780822f, 0.778865f,
		0.776908f, 0.774951f, 0.772994f, 0.771037f, 0.76908f, 0.767123f,
		0.765166f, 0.763209f, 0.761252f, 0.759295f, 0.757339f, 0.755382f,
		0.753425f, 0.751468f, 0.749511f, 0.747554f, 0.745597f, 0.74364f,
		0.741683f, 0.739726f, 0.737769f, 0.735812f, 0.733855f, 0.731898f,
		0.729941f, 0.727984f, 0.726027f, 0.72407f, 0.722113f, 0.720157f,
		0.7182f, 0.716243f, 0.714286f, 0.712329f, 0.710372f, 0.708415f,
		0.706458f, 0.704501f, 0.702544f, 0.700587f, 0.69863f, 0.696673f,
		0.694716f, 0.692759f, 0.690802f, 0.688845f, 0.686888f, 0.684932f,
		0.682975f, 0.681018f, 0.679061f, 0.677104f, 0.675147f, 0.67319f,
		0.671233f, 0.669276f, 0.667319f, 0.665362f, 0.663405f, 0.661448f,
		0.659491f, 0.657534f, 0.655577f, 0.65362f, 0.651663f, 0.649706f,
		0.64775f, 0.645793f, 0.643836f, 0.641879f, 0.639922f, 0.637965f,
		0.636008f, 0.634051f, 0.632094f, 0.630137f, 0.62818f, 0.626223f,
		0.624266f, 0.622309f, 0.620352f, 0.618395f, 0.616438f, 0.614481f,
		0.612524f, 0.610568f, 0.608611f, 0.606654f, 0.604697f, 0.60274f,
		0.600783f, 0.598826f, 0.596869f, 0.594912f, 0.592955f, 0.590998f,
		0.589041f, 0.587084f, 0.585127f, 0.58317f, 0.581213f, 0.579256f,
		0.577299f, 0.575342f, 0.573385f, 0.571429f, 0.569472f, 0.567515f,
		0.565558f, 0.563601f, 0.561644f, 0.559687f, 0.55773f, 0.555773f,
		0.553816f, 0.551859f, 0.549902f, 0.547945f, 0.545988f, 0.544031f,
		0.542074f, 0.540117f, 0.53816f, 0.536204f, 0.534247f, 0.53229f,
		0.530333f, 0.528376f, 0.526419f, 0.524462f, 0.522505f, 0.520548f,
		0.518591f, 0.516634f, 0.514677f, 0.51272f, 0.510763f, 0.508806f,
		0.506849f, 0.504892f, 0.502935f, 0.500978f, 0.499022f, 0.497065f,
		0.495108f, 0.493151f, 0.491194f, 0.489237f, 0.48728f, 0.485323f,
		0.483366f, 0.481409f, 0.479452f, 0.477495f, 0.475538f, 0.473581f,
		0.471624f, 0.469667f, 0.46771f, 0.465753f, 0.463796f, 0.46184f,
		0.459883f, 0.457926f, 0.455969f, 0.454012f, 0.452055f, 0.450098f,
		0.448141f, 0.446184f, 0.444227f, 0.44227f, 0.440313f, 0.438356f,
		0.436399f, 0.434442f, 0.432485f, 0.430528f, 0.428571f, 0.426614f,
		0.424658f, 0.422701f, 0.420744f, 0.418787f, 0.41683f, 0.414873f,
		0.412916f, 0.410959f, 0.409002f, 0.407045f, 0.405088f, 0.403131f,
		0.401174f, 0.399217f, 0.39726f, 0.395303f, 0.393346f, 0.391389f,
		0.389432f, 0.387476f, 0.385519f, 0.383562f, 0.381605f, 0.379648f,
		0.377691f, 0.375734f, 0.373777f, 0.37182f, 0.369863f, 0.367906f,
		0.365949f, 0.363992f, 0.362035f, 0.360078f, 0.358121f, 0.356164f,
		0.354207f, 0.352251f, 0.350294f, 0.348337f, 0.34638f, 0.344423f,
		0.342466f, 0.340509f, 0.338552f, 0.336595f, 0.334638f, 0.332681f,
		0.330724f, 0.328767f, 0.32681f, 0.324853f, 0.322896f, 0.320939f,
		0.318982f, 0.317025f, 0.315068f, 0.313112f, 0.311155f, 0.309198f,
		0.307241f, 0.305284f, 0.303327f, 0.30137f, 0.299413f, 0.297456f,
		0.295499f, 0.293542f, 0.291585f, 0.289628f, 0.287671f, 0.285714f,
		0.283757f, 0.2818f, 0.279843f, 0.277887f, 0.27593f, 0.273973f,
		0.272016f, 0.270059f, 0.268102f, 0.266145f, 0.264188f, 0.262231f,
		0.260274f, 0.258317f, 0.25636f, 0.254403f, 0.252446f, 0.250489f,
		0.248532f, 0.246575f, 0.244618f, 0.242661f, 0.240704f, 0.238748f,
		0.236791f, 0.234834f, 0.232877f, 0.23092f, 0.228963f, 0.227006f,
		0.225049f, 0.223092f, 0.221135f, 0.219178f, 0.217221f, 0.215264f,
		0.213307f, 0.21135f, 0.209393f, 0.207436f, 0.205479f, 0.203523f,
		0.201566f, 0.199609f, 0.197652f, 0.195695f, 0.193738f, 0.191781f,
		0.189824f, 0.187867f, 0.18591f, 0.183953f, 0.181996f, 0.180039f,
		0.178082f, 0.176125f, 0.174168f, 0.172211f, 0.170254f, 0.168297f,
		0.166341f, 0.164384f, 0.162427f, 0.16047f, 0.158513f, 0.156556f,
		0.154599f, 0.152642f, 0.150685f, 0.148728f, 0.146771f, 0.144814f,
		0.142857f, 0.1409f, 0.138943f, 0.136986f, 0.135029f, 0.133072f,
		0.131115f, 0.129158f, 0.127202f, 0.125245f, 0.123288f, 0.121331f,
		0.119374f, 0.117417f, 0.11546f, 0.113503f, 0.111546f, 0.109589f,
		0.107632f, 0.105675f, 0.103718f, 0.101761f, 0.0998043f, 0.0978474f,
		0.0958903f, 0.0939335f, 0.0919765f, 0.0900196f, 0.0880627f, 0.0861056f,
		0.0841488f, 0.0821917f, 0.0802348f, 0.0782779f, 0.0763209f, 0.0743641f,
		0.072407f, 0.0704501f, 0.0684931f, 0.0665362f, 0.0645792f, 0.0626223f,
		0.0606654f, 0.0587084f, 0.0567515f, 0.0547945f, 0.0528376f, 0.0508806f,
		0.0489237f, 0.0469668f, 0.0450097f, 0.0430529f, 0.0410959f, 0.039139f,
		0.037182f, 0.035225f, 0.0332682f, 0.0313111f, 0.0293542f, 0.0273973f,
		0.0254403f, 0.0234835f, 0.0215264f, 0.0195695f, 0.0176125f, 0.0156556f,
		0.0136986f, 0.0117417f, 0.00978482f, 0.00782776f, 0.00587088f, 0.00391382f,
		0.00195694f, 0.f
	};
};

template <int NV>
using cable_table6_t = wrap::data<control::cable_table<cable_table6_mod<NV>>, 
                                  data::embedded::table<cable_table6_t_data>>;
DECLARE_PARAMETER_RANGE_SKEW(extra_mod6_mod_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using extra_mod6_mod_0 = parameter::from0To1<filters::svf<NV>, 
                                             0, 
                                             extra_mod6_mod_0Range>;

template <int NV>
using extra_mod6_mod_1 = parameter::from0To1<filters::biquad<NV>, 
                                             0, 
                                             extra_mod6_mod_0Range>;

template <int NV> using extra_mod6_mod_2 = extra_mod6_mod_0<NV>;

template <int NV> using extra_mod6_mod_3 = extra_mod6_mod_0<NV>;

template <int NV>
using extra_mod6_mod_4 = parameter::from0To1<filters::ring_mod<NV>, 
                                             0, 
                                             extra_mod6_mod_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(extra_mod6_mod_6Range, 
                             0.5, 
                             2., 
                             0.63093);

template <int NV>
using extra_mod6_mod_6 = parameter::from0To1<pma_unscaled4_t<NV>, 
                                             1, 
                                             extra_mod6_mod_6Range>;

template <int NV>
using extra_mod6_mod_7 = parameter::from0To1<pma_unscaled3_t<NV>, 
                                             1, 
                                             extra_mod6_mod_6Range>;

DECLARE_PARAMETER_RANGE(extra_mod6_mod_9Range, 
                        0.03, 
                        1.);

template <int NV>
using extra_mod6_mod_9 = parameter::from0To1<pma1_t<NV>, 
                                             1, 
                                             extra_mod6_mod_9Range>;

template <int NV>
using extra_mod6_mod = parameter::chain<ranges::Identity, 
                                        extra_mod6_mod_0<NV>, 
                                        extra_mod6_mod_1<NV>, 
                                        extra_mod6_mod_2<NV>, 
                                        extra_mod6_mod_3<NV>, 
                                        extra_mod6_mod_4<NV>, 
                                        parameter::plain<cable_table5_t<NV>, 0>, 
                                        extra_mod6_mod_6<NV>, 
                                        extra_mod6_mod_7<NV>, 
                                        parameter::plain<cable_table6_t<NV>, 0>, 
                                        extra_mod6_mod_9<NV>>;

template <int NV>
using extra_mod6_t = wrap::mod<extra_mod6_mod<NV>, 
                               wrap::no_data<core::extra_mod<NV, extra_mod6_t_index, extra_mod6_t_config>>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, pitch_mod_t<NV>>, 
                                 extra_mod2_t<NV>, 
                                 extra_mod6_t<NV>>;
using extra_mod1_t_index = extra_mod2_t_index;
using extra_mod1_t_config = extra_mod2_t_config;

template <int NV>
using extra_mod1_mod = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                        1>;
template <int NV>
using extra_mod1_t = wrap::mod<extra_mod1_mod<NV>, 
                               wrap::no_data<core::extra_mod<NV, extra_mod1_t_index, extra_mod1_t_config>>>;
using extra_mod4_t_index = extra_mod2_t_index;
using extra_mod4_t_config = extra_mod2_t_config;

template <int NV>
using extra_mod4_mod = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                        13>;
template <int NV>
using extra_mod4_t = wrap::mod<extra_mod4_mod<NV>, 
                               wrap::no_data<core::extra_mod<NV, extra_mod4_t_index, extra_mod4_t_config>>>;
using extra_mod3_t_index = extra_mod2_t_index;
using extra_mod3_t_config = extra_mod2_t_config;

template <int NV>
using extra_mod3_mod = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                        14>;
template <int NV>
using extra_mod3_t = wrap::mod<extra_mod3_mod<NV>, 
                               wrap::no_data<core::extra_mod<NV, extra_mod3_t_index, extra_mod3_t_config>>>;
using extra_mod5_t_index = extra_mod2_t_index;
using extra_mod5_t_config = extra_mod2_t_config;

template <int NV>
using extra_mod5_mod = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                        15>;
template <int NV>
using extra_mod5_t = wrap::mod<extra_mod5_mod<NV>, 
                               wrap::no_data<core::extra_mod<NV, extra_mod5_t_index, extra_mod5_t_config>>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, extra_mod1_t<NV>>, 
                                  extra_mod4_t<NV>, 
                                  extra_mod3_t<NV>, 
                                  extra_mod5_t<NV>>;
using extra_mod7_t_index = extra_mod2_t_index;
using extra_mod7_t_config = extra_mod2_t_config;

using global_cable4_t_index = runtime_target::indexers::fix_hash<-573680734>;
using extra_mod7_mod = parameter::plain<routing::global_cable<global_cable4_t_index, parameter::empty>, 
                                        0>;
template <int NV>
using extra_mod7_t = wrap::mod<extra_mod7_mod, 
                               wrap::no_data<core::extra_mod<NV, extra_mod7_t_index, extra_mod7_t_config>>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, extra_mod7_t<NV>>, 
                                  routing::global_cable<global_cable4_t_index, parameter::empty>>;
using extra_mod8_t_index = extra_mod2_t_index;
using extra_mod8_t_config = extra_mod2_t_config;

using global_cable5_t_index = runtime_target::indexers::fix_hash<-573680733>;
using extra_mod8_mod = parameter::plain<routing::global_cable<global_cable5_t_index, parameter::empty>, 
                                        0>;
template <int NV>
using extra_mod8_t = wrap::mod<extra_mod8_mod, 
                               wrap::no_data<core::extra_mod<NV, extra_mod8_t_index, extra_mod8_t_config>>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, extra_mod8_t<NV>>, 
                                   routing::global_cable<global_cable5_t_index, parameter::empty>>;
using extra_mod9_t_index = extra_mod2_t_index;
using extra_mod9_t_config = extra_mod2_t_config;

using global_cable6_t_index = runtime_target::indexers::fix_hash<-573680732>;
using extra_mod9_mod = parameter::plain<routing::global_cable<global_cable6_t_index, parameter::empty>, 
                                        0>;
template <int NV>
using extra_mod9_t = wrap::mod<extra_mod9_mod, 
                               wrap::no_data<core::extra_mod<NV, extra_mod9_t_index, extra_mod9_t_config>>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, extra_mod9_t<NV>>, 
                                  routing::global_cable<global_cable6_t_index, parameter::empty>>;
using extra_mod10_t_index = extra_mod2_t_index;
using extra_mod10_t_config = extra_mod2_t_config;

using global_cable7_t_index = runtime_target::indexers::fix_hash<-573680731>;
using extra_mod10_mod = parameter::plain<routing::global_cable<global_cable7_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod10_t = wrap::mod<extra_mod10_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod10_t_index, extra_mod10_t_config>>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, extra_mod10_t<NV>>, 
                                  routing::global_cable<global_cable7_t_index, parameter::empty>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain4_t<NV>>, 
                                  chain10_t<NV>, 
                                  chain9_t<NV>, 
                                  chain8_t<NV>>;
using extra_mod11_t_index = extra_mod2_t_index;
using extra_mod11_t_config = extra_mod2_t_config;

using global_cable8_t_index = runtime_target::indexers::fix_hash<-573680703>;
using extra_mod11_mod = parameter::plain<routing::global_cable<global_cable8_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod11_t = wrap::mod<extra_mod11_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod11_t_index, extra_mod11_t_config>>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, extra_mod11_t<NV>>, 
                                  routing::global_cable<global_cable8_t_index, parameter::empty>>;
using extra_mod12_t_index = extra_mod2_t_index;
using extra_mod12_t_config = extra_mod2_t_config;

using global_cable9_t_index = runtime_target::indexers::fix_hash<-573680702>;
using extra_mod12_mod = parameter::plain<routing::global_cable<global_cable9_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod12_t = wrap::mod<extra_mod12_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod12_t_index, extra_mod12_t_config>>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, extra_mod12_t<NV>>, 
                                   routing::global_cable<global_cable9_t_index, parameter::empty>>;
using extra_mod13_t_index = extra_mod2_t_index;
using extra_mod13_t_config = extra_mod2_t_config;

using global_cable10_t_index = runtime_target::indexers::fix_hash<-573680701>;
using extra_mod13_mod = parameter::plain<routing::global_cable<global_cable10_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod13_t = wrap::mod<extra_mod13_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod13_t_index, extra_mod13_t_config>>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, extra_mod13_t<NV>>, 
                                   routing::global_cable<global_cable10_t_index, parameter::empty>>;
using extra_mod14_t_index = extra_mod2_t_index;
using extra_mod14_t_config = extra_mod2_t_config;

using global_cable11_t_index = runtime_target::indexers::fix_hash<-573680700>;
using extra_mod14_mod = parameter::plain<routing::global_cable<global_cable11_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod14_t = wrap::mod<extra_mod14_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod14_t_index, extra_mod14_t_config>>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, extra_mod14_t<NV>>, 
                                   routing::global_cable<global_cable11_t_index, parameter::empty>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain5_t<NV>>, 
                                   chain11_t<NV>, 
                                   chain12_t<NV>, 
                                   chain13_t<NV>>;
using extra_mod15_t_index = extra_mod2_t_index;
using extra_mod15_t_config = extra_mod2_t_config;

using global_cable12_t_index = runtime_target::indexers::fix_hash<-573680672>;
using extra_mod15_mod = parameter::plain<routing::global_cable<global_cable12_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod15_t = wrap::mod<extra_mod15_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod15_t_index, extra_mod15_t_config>>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, extra_mod15_t<NV>>, 
                                  routing::global_cable<global_cable12_t_index, parameter::empty>>;
using extra_mod16_t_index = extra_mod2_t_index;
using extra_mod16_t_config = extra_mod2_t_config;

using global_cable13_t_index = runtime_target::indexers::fix_hash<-573680671>;
using extra_mod16_mod = parameter::plain<routing::global_cable<global_cable13_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod16_t = wrap::mod<extra_mod16_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod16_t_index, extra_mod16_t_config>>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, extra_mod16_t<NV>>, 
                                   routing::global_cable<global_cable13_t_index, parameter::empty>>;
using extra_mod17_t_index = extra_mod2_t_index;
using extra_mod17_t_config = extra_mod2_t_config;

using global_cable14_t_index = runtime_target::indexers::fix_hash<-573680670>;
using extra_mod17_mod = parameter::plain<routing::global_cable<global_cable14_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod17_t = wrap::mod<extra_mod17_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod17_t_index, extra_mod17_t_config>>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, extra_mod17_t<NV>>, 
                                   routing::global_cable<global_cable14_t_index, parameter::empty>>;
using extra_mod18_t_index = extra_mod2_t_index;
using extra_mod18_t_config = extra_mod2_t_config;

using global_cable15_t_index = runtime_target::indexers::fix_hash<-573680669>;
using extra_mod18_mod = parameter::plain<routing::global_cable<global_cable15_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod18_t = wrap::mod<extra_mod18_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod18_t_index, extra_mod18_t_config>>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, extra_mod18_t<NV>>, 
                                   routing::global_cable<global_cable15_t_index, parameter::empty>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain6_t<NV>>, 
                                   chain14_t<NV>, 
                                   chain15_t<NV>, 
                                   chain25_t<NV>>;
using extra_mod19_t_index = extra_mod2_t_index;
using extra_mod19_t_config = extra_mod2_t_config;

using global_cable16_t_index = runtime_target::indexers::fix_hash<-573680641>;
using extra_mod19_mod = parameter::plain<routing::global_cable<global_cable16_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod19_t = wrap::mod<extra_mod19_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod19_t_index, extra_mod19_t_config>>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, extra_mod19_t<NV>>, 
                                  routing::global_cable<global_cable16_t_index, parameter::empty>>;
using extra_mod20_t_index = extra_mod2_t_index;
using extra_mod20_t_config = extra_mod2_t_config;

using global_cable17_t_index = runtime_target::indexers::fix_hash<-573680640>;
using extra_mod20_mod = parameter::plain<routing::global_cable<global_cable17_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod20_t = wrap::mod<extra_mod20_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod20_t_index, extra_mod20_t_config>>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, extra_mod20_t<NV>>, 
                                   routing::global_cable<global_cable17_t_index, parameter::empty>>;
using extra_mod21_t_index = extra_mod2_t_index;
using extra_mod21_t_config = extra_mod2_t_config;

using global_cable18_t_index = runtime_target::indexers::fix_hash<-573680639>;
using extra_mod21_mod = parameter::plain<routing::global_cable<global_cable18_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod21_t = wrap::mod<extra_mod21_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod21_t_index, extra_mod21_t_config>>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, extra_mod21_t<NV>>, 
                                   routing::global_cable<global_cable18_t_index, parameter::empty>>;
using extra_mod22_t_index = extra_mod2_t_index;
using extra_mod22_t_config = extra_mod2_t_config;

using global_cable19_t_index = runtime_target::indexers::fix_hash<-573680638>;
using extra_mod22_mod = parameter::plain<routing::global_cable<global_cable19_t_index, parameter::empty>, 
                                         0>;
template <int NV>
using extra_mod22_t = wrap::mod<extra_mod22_mod, 
                                wrap::no_data<core::extra_mod<NV, extra_mod22_t_index, extra_mod22_t_config>>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, extra_mod22_t<NV>>, 
                                   routing::global_cable<global_cable19_t_index, parameter::empty>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain7_t<NV>>, 
                                   chain26_t<NV>, 
                                   chain27_t<NV>, 
                                   chain28_t<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, split9_t<NV>>, 
                                    split10_t<NV>, 
                                    split11_t<NV>, 
                                    split12_t<NV>>;

template <int NV>
using tempo_sync1_mod = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                         17>;
template <int NV>
using tempo_sync1_t = wrap::mod<tempo_sync1_mod<NV>, 
                                control::tempo_sync<NV>>;

template <int NV>
using minmax_mod = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                    4>;
template <int NV>
using minmax_t = control::minmax<NV, minmax_mod<NV>>;

template <int NV>
using tempo_sync3_mod = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                         16>;
template <int NV>
using tempo_sync3_t = wrap::mod<tempo_sync3_mod<NV>, 
                                control::tempo_sync<NV>>;
using pack_resizer_t = wrap::data<control::pack_resizer, 
                                  data::external::sliderpack<0>>;
using pack8_writer_t = wrap::data<control::pack8_writer, 
                                  data::external::sliderpack<0>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split_t<NV>>, 
                                     split8_t<NV>, 
                                     branch2_t<NV>, 
                                     converter_t<NV>, 
                                     tempo_sync_t<NV>, 
                                     tempo_sync1_t<NV>, 
                                     minmax_t<NV>, 
                                     tempo_sync3_t<NV>, 
                                     pack_resizer_t, 
                                     pack8_writer_t>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

using global_cable_t_index = runtime_target::indexers::fix_hash<2615364>;
using peak_mod = parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 
                                  0>;
using peak_t = wrap::mod<peak_mod, 
                         wrap::no_data<core::peak>>;

using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, peak_t>, 
                                 routing::global_cable<global_cable_t_index, parameter::empty>>;

using global_cable1_t_index = runtime_target::indexers::fix_hash<2615365>;
using peak1_mod = parameter::plain<routing::global_cable<global_cable1_t_index, parameter::empty>, 
                                   0>;
using peak1_t = wrap::mod<peak1_mod, 
                          wrap::no_data<core::peak>>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, peak1_t>, 
                                  routing::global_cable<global_cable1_t_index, parameter::empty>>;

using global_cable2_t_index = runtime_target::indexers::fix_hash<2615366>;
using peak2_mod = parameter::plain<routing::global_cable<global_cable2_t_index, parameter::empty>, 
                                   0>;
using peak2_t = wrap::mod<peak2_mod, 
                          wrap::no_data<core::peak>>;

using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, peak2_t>, 
                                  routing::global_cable<global_cable2_t_index, parameter::empty>>;

using global_cable3_t_index = runtime_target::indexers::fix_hash<2615367>;
using peak3_mod = parameter::plain<routing::global_cable<global_cable3_t_index, parameter::empty>, 
                                   0>;
using peak3_t = wrap::mod<peak3_mod, 
                          wrap::no_data<core::peak>>;

using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, peak3_t>, 
                                  routing::global_cable<global_cable3_t_index, parameter::empty>>;
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain_t>, 
                                   chain1_t, 
                                   chain2_t, 
                                   chain3_t>;

template <int NV>
using fix32_block_t = container::chain<parameter::empty, 
                                       wrap::fix<2, modchain_t<NV>>, 
                                       project::granular_player_stepquant_density_hybrid_native<NV>, 
                                       branch_t>;

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
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>>;

using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::svf<NV>>>;

template <int NV> using chain43_t = chain38_t<NV>;

template <int NV> using chain45_t = chain38_t<NV>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::biquad<NV>>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::ring_mod<NV>>>;

using chain17_t = chain20_t;

template <int NV>
using peak12_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::sig2mod<NV>>, 
                                   math::fmod<NV>, 
                                   peak12_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain17_t>, 
                                  chain24_t<NV>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, pma1_t<NV>>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, split3_t<NV>>, 
                                       cable_table6_t<NV>, 
                                       modchain1_t<NV>, 
                                       math::fmod<NV>, 
                                       math::div<NV>, 
                                       core::gain<NV>, 
                                       filters::one_pole<NV>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fix8_block_t<NV>>>;

template <int NV>
using converter6_t = control::converter<parameter::plain<pma_unscaled3_t<NV>, 0>, 
                                        conversion_logic::midi2freq>;
template <int NV>
using midi3_t = wrap::mod<parameter::plain<converter6_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using wrapmidi31_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, midi3_t<NV>>>;

template <int NV>
using wrapmidi31_t = wrap::event<wrapmidi31_t_<NV>>;

template <int NV>
using offline2_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, converter6_t<NV>>, 
                                     converter7_t<NV>>;

template <int NV>
using offline2_t = wrap::offline<offline2_t_<NV>>;

// Calculate the delay time from the incoming note number ------------------------------------------

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrapmidi31_t<NV>>, 
                                   offline2_t<NV>>;
template <int NV>
using stereo_frame_cable = cable::frame<NV, 2>;

template <int NV>
using frame2_block1_t_ = container::chain<parameter::empty, 
                                          wrap::fix<2, pma_unscaled3_t<NV>>, 
                                          routing::receive<NV, stereo_frame_cable<NV>>, 
                                          filters::one_pole<NV>, 
                                          wrap::no_process<core::fix_delay>, 
                                          jdsp::jdelay_thiran<NV>, 
                                          routing::send<NV, stereo_frame_cable<NV>>, 
                                          filters::one_pole<NV>>;

template <int NV>
using frame2_block1_t = wrap::frame<2, frame2_block1_t_<NV>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain41_t<NV>>, 
                                   frame2_block1_t<NV>>;

template <int NV>
using converter8_t = control::converter<parameter::plain<pma_unscaled4_t<NV>, 0>, 
                                        conversion_logic::midi2freq>;
template <int NV>
using midi4_t = wrap::mod<parameter::plain<converter8_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using wrapmidi41_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, midi4_t<NV>>>;

template <int NV>
using wrapmidi41_t = wrap::event<wrapmidi41_t_<NV>>;

template <int NV>
using offline3_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, converter8_t<NV>>>;

template <int NV>
using offline3_t = wrap::offline<offline3_t_<NV>>;

// Calculate the delay time from the incoming note number ------------------------------------------

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrapmidi41_t<NV>>, 
                                   offline3_t<NV>>;

template <int NV>
using frame2_block2_t_ = container::chain<parameter::empty, 
                                          wrap::fix<2, filters::allpass<NV>>, 
                                          filters::one_pole<NV>>;

template <int NV>
using frame2_block2_t = wrap::frame<2, frame2_block2_t_<NV>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain42_t<NV>>, 
                                   pma_unscaled4_t<NV>, 
                                   frame2_block2_t<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table5_t<NV>>, 
                                   fx::bitcrush<NV>, 
                                   fx::sampleandhold<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain20_t>, 
                                    chain38_t<NV>, 
                                    chain43_t<NV>, 
                                    chain45_t<NV>, 
                                    chain39_t<NV>, 
                                    chain44_t<NV>, 
                                    chain46_t<NV>, 
                                    chain18_t<NV>, 
                                    chain21_t<NV>, 
                                    chain23_t<NV>>;

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

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader_t<NV>>, 
                                   chain16_t<NV>, 
                                   core::gain<NV>, 
                                   jdsp::jpanner<NV>>;

namespace MatrixTest2_t_parameters
{
// Parameter list for MatrixTest2_impl::MatrixTest2_t ----------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(ScatterRange, 
                             0., 
                             1., 
                             0.432768);

template <int NV>
using Scatter = parameter::from0To1<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                    12, 
                                    ScatterRange>;

DECLARE_PARAMETER_RANGE_STEP(PitchMode_InputRange, 
                             1., 
                             8., 
                             1.);

using PitchMode = parameter::chain<PitchMode_InputRange, 
                                   parameter::plain<MatrixTest2_impl::pack8_writer_t, 0>>;

DECLARE_PARAMETER_RANGE_STEP(TransportMode_InputRange, 
                             1., 
                             4., 
                             1.);

using TransportMode = parameter::chain<TransportMode_InputRange, 
                                       parameter::plain<MatrixTest2_impl::pack8_writer_t, 3>>;

DECLARE_PARAMETER_RANGE_STEP(FxMode_InputRange, 
                             1., 
                             10., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(FxMode_0Range, 
                             0., 
                             9., 
                             1.);

template <int NV>
using FxMode_0 = parameter::from0To1<MatrixTest2_impl::branch1_t<NV>, 
                                     0, 
                                     FxMode_0Range>;

template <int NV>
using FxMode = parameter::chain<FxMode_InputRange, FxMode_0<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(Resonance_InputRange, 
                             0., 
                             1., 
                             0.858947);
DECLARE_PARAMETER_RANGE_SKEW(Resonance_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using Resonance_0 = parameter::from0To1<filters::svf<NV>, 
                                        1, 
                                        Resonance_0Range>;

template <int NV> using Resonance_1 = Resonance_0<NV>;

template <int NV> using Resonance_2 = Resonance_0<NV>;

template <int NV>
using Resonance_3 = parameter::from0To1<filters::biquad<NV>, 
                                        1, 
                                        Resonance_0Range>;

template <int NV>
using Resonance_4 = parameter::from0To1<filters::ring_mod<NV>, 
                                        1, 
                                        Resonance_0Range>;

template <int NV>
using Resonance_5 = parameter::from0To1<filters::one_pole<NV>, 
                                        0, 
                                        MatrixTest2_impl::extra_mod6_mod_0Range>;

template <int NV> using Resonance_6 = Resonance_5<NV>;

template <int NV>
using Resonance_7 = parameter::from0To1<filters::allpass<NV>, 
                                        1, 
                                        Resonance_0Range>;

DECLARE_PARAMETER_RANGE_STEP(Resonance_8Range, 
                             1., 
                             64., 
                             1.);

template <int NV>
using Resonance_8 = parameter::from0To1<fx::sampleandhold<NV>, 
                                        0, 
                                        Resonance_8Range>;

DECLARE_PARAMETER_RANGE(Resonance_9Range, 
                        0.9, 
                        1.);

template <int NV>
using Resonance_9 = parameter::from0To1<routing::receive<NV, stereo_frame_cable<NV>>, 
                                        0, 
                                        Resonance_9Range>;

template <int NV>
using Resonance = parameter::chain<Resonance_InputRange, 
                                   Resonance_0<NV>, 
                                   Resonance_1<NV>, 
                                   Resonance_2<NV>, 
                                   Resonance_3<NV>, 
                                   Resonance_4<NV>, 
                                   Resonance_5<NV>, 
                                   Resonance_6<NV>, 
                                   Resonance_7<NV>, 
                                   Resonance_8<NV>, 
                                   Resonance_9<NV>>;

DECLARE_PARAMETER_RANGE_STEP(PhaseScatterShape_InputRange, 
                             1., 
                             5., 
                             1.);

using PhaseScatterShape = parameter::chain<PhaseScatterShape_InputRange, 
                                           parameter::plain<MatrixTest2_impl::pack8_writer_t, 6>>;

DECLARE_PARAMETER_RANGE_STEP(GrainTravelShape_InputRange, 
                             1., 
                             4., 
                             1.);

using GrainTravelShape = parameter::chain<GrainTravelShape_InputRange, 
                                          parameter::plain<MatrixTest2_impl::pack8_writer_t, 7>>;

using Scrub = parameter::empty;
using GrainSize = Scrub;
template <int NV>
using GrainMix = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                  3>;
template <int NV>
using WindowShape = parameter::plain<MatrixTest2_impl::minmax_t<NV>, 
                                     0>;
template <int NV>
using PanSpread = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                   5>;
template <int NV>
using PitchSpread = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                     7>;
template <int NV>
using MaxGrains = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                   8>;
using ScrubMode = parameter::plain<MatrixTest2_impl::pack8_writer_t, 
                                   1>;
using ScrubBlend = parameter::plain<MatrixTest2_impl::pack8_writer_t, 
                                    2>;
template <int NV>
using Direction = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                   11>;
using ScrubB = Scrub;
using ScrubC = Scrub;
using ScrubD = Scrub;
using ModOut1 = parameter::plain<MatrixTest2_impl::branch_t, 
                                 0>;
template <int NV>
using FxMix = parameter::plain<MatrixTest2_impl::xfader_t<NV>, 
                               0>;
using FxMeta1 = Scrub;
using ModOut2 = Scrub;
template <int NV>
using Pan = parameter::plain<jdsp::jpanner<NV>, 0>;
template <int NV>
using Vol = parameter::plain<core::gain<NV>, 0>;
template <int NV>
using GrainSync = parameter::plain<MatrixTest2_impl::tempo_sync_t<NV>, 
                                   2>;
template <int NV>
using GrainDiv = parameter::plain<MatrixTest2_impl::tempo_sync_t<NV>, 
                                  1>;
template <int NV>
using GrainTempo = parameter::plain<MatrixTest2_impl::tempo_sync_t<NV>, 
                                    0>;
template <int NV>
using PitchDivide = parameter::plain<MatrixTest2_impl::tempo_sync1_t<NV>, 
                                     1>;
template <int NV>
using PitchTempo = parameter::plain<MatrixTest2_impl::tempo_sync1_t<NV>, 
                                    0>;
template <int NV>
using Respawn = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                 6>;
template <int NV>
using Diffusion = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                   9>;
using PitchSync = parameter::plain<MatrixTest2_impl::pack8_writer_t, 
                                   4>;
using Glide = parameter::plain<MatrixTest2_impl::pack8_writer_t, 
                               5>;
template <int NV>
using BloomOn = parameter::plain<project::granular_player_stepquant_density_hybrid_native<NV>, 
                                 10>;
template <int NV>
using BloomDiv = parameter::plain<MatrixTest2_impl::tempo_sync3_t<NV>, 
                                  1>;
template <int NV>
using IndOut = parameter::plain<MatrixTest2_impl::branch2_t<NV>, 
                                0>;
template <int NV>
using MatrixTest2_t_plist = parameter::list<Scrub, 
                                            GrainSize, 
                                            GrainMix<NV>, 
                                            Scatter<NV>, 
                                            WindowShape<NV>, 
                                            PanSpread<NV>, 
                                            PitchMode, 
                                            PitchSpread<NV>, 
                                            MaxGrains<NV>, 
                                            ScrubMode, 
                                            ScrubBlend, 
                                            Direction<NV>, 
                                            ScrubB, 
                                            ScrubC, 
                                            ScrubD, 
                                            TransportMode, 
                                            ModOut1, 
                                            FxMix<NV>, 
                                            FxMode<NV>, 
                                            FxMeta1, 
                                            Resonance<NV>, 
                                            ModOut2, 
                                            Pan<NV>, 
                                            Vol<NV>, 
                                            GrainSync<NV>, 
                                            GrainDiv<NV>, 
                                            GrainTempo<NV>, 
                                            PitchDivide<NV>, 
                                            PitchTempo<NV>, 
                                            Respawn<NV>, 
                                            Diffusion<NV>, 
                                            PitchSync, 
                                            Glide, 
                                            PhaseScatterShape, 
                                            GrainTravelShape, 
                                            BloomOn<NV>, 
                                            BloomDiv<NV>, 
                                            IndOut<NV>>;
}

template <int NV>
using MatrixTest2_t_ = container::chain<MatrixTest2_t_parameters::MatrixTest2_t_plist<NV>, 
                                        wrap::fix<2, fix32_block_t<NV>>, 
                                        chain33_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public MatrixTest2_impl::MatrixTest2_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(MatrixTest2);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(692)
		{
			0x005C, 0x0000, 0x0000, 0x6353, 0x7572, 0x0062, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x6F3F, 0x537A, 0x003D, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x0100, 0x0000, 0x4700, 0x6172, 0x6E69, 0x6953, 0x657A, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x43FA, 0x8638, 0x43D8, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0002, 0x0000, 0x7247, 0x6961, 
            0x4D6E, 0x7869, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0003, 0x0000, 
            0x6353, 0x7461, 0x6574, 0x0072, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0400, 
            0x0000, 0x5700, 0x6E69, 0x6F64, 0x5377, 0x6168, 0x6570, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x2C86, 0x3DF8, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0005, 0x0000, 0x6150, 0x536E, 0x7270, 
            0x6165, 0x0064, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0600, 0x0000, 0x5000, 
            0x7469, 0x6863, 0x6F4D, 0x6564, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x4100, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x0007, 0x0000, 0x6950, 0x6374, 0x5368, 0x7270, 0x6165, 0x0064, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x0800, 0x0000, 0x4D00, 0x7861, 0x7247, 
            0x6961, 0x736E, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 
            0x4200, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0009, 0x0000, 
            0x6353, 0x7572, 0x4D62, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x8000, 0xCD3F, 0xDCCC, 0x003B, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x0A00, 0x0000, 0x5300, 0x7263, 0x6275, 0x6C42, 0x6E65, 0x0064, 
            0x0000, 0x0000, 0x0000, 0x8000, 0xCD3F, 0xACCC, 0x003B, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x0B00, 0x0000, 0x4400, 0x7269, 0x6365, 
            0x6974, 0x6E6F, 0x0000, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000C, 0x0000, 
            0x6353, 0x7572, 0x4262, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0xA3D6, 0x3EFA, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000D, 
            0x0000, 0x6353, 0x7572, 0x4362, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3E01, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x000E, 0x0000, 0x6353, 0x7572, 0x4462, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3AC0, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x000F, 0x0000, 0x7254, 0x6E61, 0x7073, 0x726F, 0x4D74, 
            0x646F, 0x0065, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x1000, 0x0000, 0x4D00, 
            0x646F, 0x754F, 0x3174, 0x0000, 0x0000, 0x0000, 0x0000, 0x4040, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0011, 
            0x0000, 0x7846, 0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1200, 
            0x0000, 0x4600, 0x4D78, 0x646F, 0x0065, 0x0000, 0x8000, 0x003F, 
            0x2000, 0x0041, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x1300, 0x0000, 0x4600, 0x4D78, 0x7465, 0x3161, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0014, 0x0000, 0x6552, 0x6F73, 0x616E, 0x636E, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0xED3F, 
            0x5BE3, 0x003F, 0x0000, 0x5C00, 0x1500, 0x0000, 0x4D00, 0x646F, 
            0x754F, 0x3274, 0x0000, 0x0000, 0x0000, 0x0000, 0x4040, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0016, 0x0000, 
            0x6150, 0x006E, 0x0000, 0x8000, 0x00BF, 0x8000, 0x663F, 0xCE66, 
            0x003C, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1706, 0x0000, 0x5600, 
            0x6C6F, 0x0000, 0x0000, 0xC2C8, 0x0000, 0x0000, 0x9994, 0xC019, 
            0x833E, 0x40AD, 0xCCCD, 0x3DCC, 0x005C, 0x0018, 0x0000, 0x7247, 
            0x6961, 0x536E, 0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x1900, 
            0x0000, 0x4700, 0x6172, 0x6E69, 0x6944, 0x0076, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0042, 0xE800, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x1A00, 0x0000, 0x4700, 0x6172, 0x6E69, 0x6554, 0x706D, 
            0x006F, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0xA000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x5C3F, 0x1B00, 0x0000, 0x5000, 0x7469, 
            0x6863, 0x6944, 0x6976, 0x6564, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x001C, 0x0000, 0x6950, 0x6374, 0x5468, 0x6D65, 0x6F70, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x4040, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x001D, 0x0000, 0x6552, 0x7073, 0x7761, 
            0x006E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x1E00, 0x0000, 0x4400, 0x6669, 
            0x7566, 0x6973, 0x6E6F, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x990B, 0x3E96, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x001F, 
            0x0000, 0x6950, 0x6374, 0x5368, 0x6E79, 0x0063, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x2000, 0x0000, 0x4700, 0x696C, 0x6564, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0xB333, 0x3E4B, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0021, 0x0000, 0x6850, 0x7361, 0x5365, 0x6163, 
            0x7474, 0x7265, 0x6853, 0x7061, 0x0065, 0x0000, 0x8000, 0x003F, 
            0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x2200, 0x0000, 0x4700, 0x6172, 0x6E69, 0x7254, 0x7661, 0x6C65, 
            0x6853, 0x7061, 0x0065, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 
            0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x2300, 0x0000, 
            0x4200, 0x6F6C, 0x6D6F, 0x6E4F, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xAC85, 0x3F7E, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x0024, 0x0000, 0x6C42, 0x6F6F, 0x446D, 0x7669, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0025, 0x0000, 0x6E49, 0x4F64, 0x7475, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x4040, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(20)
		{
			0x3C3B, 0x0100, 0x0202, 0x013C, 0x0101, 0x0200, 0x013C, 0x010C, 
            0x0200, 0x013C, 0x010D, 0x0200, 0x013C, 0x010E, 0x0200, 0x013C, 
            0x0113, 0x0200, 0x3E3D, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix32_block = this->getT(0);                                                   // MatrixTest2_impl::fix32_block_t<NV>
		auto& modchain = this->getT(0).getT(0);                                              // MatrixTest2_impl::modchain_t<NV>
		auto& split = this->getT(0).getT(0).getT(0);                                         // MatrixTest2_impl::split_t<NV>
		auto& pitch_mod = this->getT(0).getT(0).getT(0).getT(0);                             // MatrixTest2_impl::pitch_mod_t<NV>
		auto& extra_mod2 = this->getT(0).getT(0).getT(0).getT(1);                            // MatrixTest2_impl::extra_mod2_t<NV>
		auto& extra_mod6 = this->getT(0).getT(0).getT(0).getT(2);                            // MatrixTest2_impl::extra_mod6_t<NV>
		auto& split8 = this->getT(0).getT(0).getT(1);                                        // MatrixTest2_impl::split8_t<NV>
		auto& extra_mod1 = this->getT(0).getT(0).getT(1).getT(0);                            // MatrixTest2_impl::extra_mod1_t<NV>
		auto& extra_mod4 = this->getT(0).getT(0).getT(1).getT(1);                            // MatrixTest2_impl::extra_mod4_t<NV>
		auto& extra_mod3 = this->getT(0).getT(0).getT(1).getT(2);                            // MatrixTest2_impl::extra_mod3_t<NV>
		auto& extra_mod5 = this->getT(0).getT(0).getT(1).getT(3);                            // MatrixTest2_impl::extra_mod5_t<NV>
		auto& branch2 = this->getT(0).getT(0).getT(2);                                       // MatrixTest2_impl::branch2_t<NV>
		auto& split9 = this->getT(0).getT(0).getT(2).getT(0);                                // MatrixTest2_impl::split9_t<NV>
		auto& chain4 = this->getT(0).getT(0).getT(2).getT(0).getT(0);                        // MatrixTest2_impl::chain4_t<NV>
		auto& extra_mod7 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0);            // MatrixTest2_impl::extra_mod7_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1);         // routing::global_cable<global_cable4_t_index, parameter::empty>
		auto& chain10 = this->getT(0).getT(0).getT(2).getT(0).getT(1);                       // MatrixTest2_impl::chain10_t<NV>
		auto& extra_mod8 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0);            // MatrixTest2_impl::extra_mod8_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1);         // routing::global_cable<global_cable5_t_index, parameter::empty>
		auto& chain9 = this->getT(0).getT(0).getT(2).getT(0).getT(2);                        // MatrixTest2_impl::chain9_t<NV>
		auto& extra_mod9 = this->getT(0).getT(0).getT(2).getT(0).getT(2).getT(0);            // MatrixTest2_impl::extra_mod9_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(2).getT(0).getT(2).getT(1);         // routing::global_cable<global_cable6_t_index, parameter::empty>
		auto& chain8 = this->getT(0).getT(0).getT(2).getT(0).getT(3);                        // MatrixTest2_impl::chain8_t<NV>
		auto& extra_mod10 = this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(0);           // MatrixTest2_impl::extra_mod10_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(1);         // routing::global_cable<global_cable7_t_index, parameter::empty>
		auto& split10 = this->getT(0).getT(0).getT(2).getT(1);                               // MatrixTest2_impl::split10_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(2).getT(1).getT(0);                        // MatrixTest2_impl::chain5_t<NV>
		auto& extra_mod11 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);           // MatrixTest2_impl::extra_mod11_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);         // routing::global_cable<global_cable8_t_index, parameter::empty>
		auto& chain11 = this->getT(0).getT(0).getT(2).getT(1).getT(1);                       // MatrixTest2_impl::chain11_t<NV>
		auto& extra_mod12 = this->getT(0).getT(0).getT(2).getT(1).getT(1).getT(0);           // MatrixTest2_impl::extra_mod12_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(2).getT(1).getT(1).getT(1);         // routing::global_cable<global_cable9_t_index, parameter::empty>
		auto& chain12 = this->getT(0).getT(0).getT(2).getT(1).getT(2);                       // MatrixTest2_impl::chain12_t<NV>
		auto& extra_mod13 = this->getT(0).getT(0).getT(2).getT(1).getT(2).getT(0);           // MatrixTest2_impl::extra_mod13_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(2).getT(1).getT(2).getT(1);        // routing::global_cable<global_cable10_t_index, parameter::empty>
		auto& chain13 = this->getT(0).getT(0).getT(2).getT(1).getT(3);                       // MatrixTest2_impl::chain13_t<NV>
		auto& extra_mod14 = this->getT(0).getT(0).getT(2).getT(1).getT(3).getT(0);           // MatrixTest2_impl::extra_mod14_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(2).getT(1).getT(3).getT(1);        // routing::global_cable<global_cable11_t_index, parameter::empty>
		auto& split11 = this->getT(0).getT(0).getT(2).getT(2);                               // MatrixTest2_impl::split11_t<NV>
		auto& chain6 = this->getT(0).getT(0).getT(2).getT(2).getT(0);                        // MatrixTest2_impl::chain6_t<NV>
		auto& extra_mod15 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(0);           // MatrixTest2_impl::extra_mod15_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(1);        // routing::global_cable<global_cable12_t_index, parameter::empty>
		auto& chain14 = this->getT(0).getT(0).getT(2).getT(2).getT(1);                       // MatrixTest2_impl::chain14_t<NV>
		auto& extra_mod16 = this->getT(0).getT(0).getT(2).getT(2).getT(1).getT(0);           // MatrixTest2_impl::extra_mod16_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(2).getT(2).getT(1).getT(1);        // routing::global_cable<global_cable13_t_index, parameter::empty>
		auto& chain15 = this->getT(0).getT(0).getT(2).getT(2).getT(2);                       // MatrixTest2_impl::chain15_t<NV>
		auto& extra_mod17 = this->getT(0).getT(0).getT(2).getT(2).getT(2).getT(0);           // MatrixTest2_impl::extra_mod17_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(2).getT(2).getT(2).getT(1);        // routing::global_cable<global_cable14_t_index, parameter::empty>
		auto& chain25 = this->getT(0).getT(0).getT(2).getT(2).getT(3);                       // MatrixTest2_impl::chain25_t<NV>
		auto& extra_mod18 = this->getT(0).getT(0).getT(2).getT(2).getT(3).getT(0);           // MatrixTest2_impl::extra_mod18_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(2).getT(2).getT(3).getT(1);        // routing::global_cable<global_cable15_t_index, parameter::empty>
		auto& split12 = this->getT(0).getT(0).getT(2).getT(3);                               // MatrixTest2_impl::split12_t<NV>
		auto& chain7 = this->getT(0).getT(0).getT(2).getT(3).getT(0);                        // MatrixTest2_impl::chain7_t<NV>
		auto& extra_mod19 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(0);           // MatrixTest2_impl::extra_mod19_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(1);        // routing::global_cable<global_cable16_t_index, parameter::empty>
		auto& chain26 = this->getT(0).getT(0).getT(2).getT(3).getT(1);                       // MatrixTest2_impl::chain26_t<NV>
		auto& extra_mod20 = this->getT(0).getT(0).getT(2).getT(3).getT(1).getT(0);           // MatrixTest2_impl::extra_mod20_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(2).getT(3).getT(1).getT(1);        // routing::global_cable<global_cable17_t_index, parameter::empty>
		auto& chain27 = this->getT(0).getT(0).getT(2).getT(3).getT(2);                       // MatrixTest2_impl::chain27_t<NV>
		auto& extra_mod21 = this->getT(0).getT(0).getT(2).getT(3).getT(2).getT(0);           // MatrixTest2_impl::extra_mod21_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(2).getT(3).getT(2).getT(1);        // routing::global_cable<global_cable18_t_index, parameter::empty>
		auto& chain28 = this->getT(0).getT(0).getT(2).getT(3).getT(3);                       // MatrixTest2_impl::chain28_t<NV>
		auto& extra_mod22 = this->getT(0).getT(0).getT(2).getT(3).getT(3).getT(0);           // MatrixTest2_impl::extra_mod22_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(2).getT(3).getT(3).getT(1);        // routing::global_cable<global_cable19_t_index, parameter::empty>
		auto& converter = this->getT(0).getT(0).getT(3);                                     // MatrixTest2_impl::converter_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(4);                                    // MatrixTest2_impl::tempo_sync_t<NV>
		auto& tempo_sync1 = this->getT(0).getT(0).getT(5);                                   // MatrixTest2_impl::tempo_sync1_t<NV>
		auto& minmax = this->getT(0).getT(0).getT(6);                                        // MatrixTest2_impl::minmax_t<NV>
		auto& tempo_sync3 = this->getT(0).getT(0).getT(7);                                   // MatrixTest2_impl::tempo_sync3_t<NV>
		auto& pack_resizer = this->getT(0).getT(0).getT(8);                                  // MatrixTest2_impl::pack_resizer_t
		auto& pack8_writer = this->getT(0).getT(0).getT(9);                                  // MatrixTest2_impl::pack8_writer_t
		auto& granular_player_stepquant_density_hybrid_native = this->getT(0).getT(1);       // project::granular_player_stepquant_density_hybrid_native<NV>
		auto& branch = this->getT(0).getT(2);                                                // MatrixTest2_impl::branch_t
		auto& chain = this->getT(0).getT(2).getT(0);                                         // MatrixTest2_impl::chain_t
		auto& peak = this->getT(0).getT(2).getT(0).getT(0);                                  // MatrixTest2_impl::peak_t
		auto& global_cable = this->getT(0).getT(2).getT(0).getT(1);                          // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& chain1 = this->getT(0).getT(2).getT(1);                                        // MatrixTest2_impl::chain1_t
		auto& peak1 = this->getT(0).getT(2).getT(1).getT(0);                                 // MatrixTest2_impl::peak1_t
		auto& global_cable1 = this->getT(0).getT(2).getT(1).getT(1);                         // routing::global_cable<global_cable1_t_index, parameter::empty>
		auto& chain2 = this->getT(0).getT(2).getT(2);                                        // MatrixTest2_impl::chain2_t
		auto& peak2 = this->getT(0).getT(2).getT(2).getT(0);                                 // MatrixTest2_impl::peak2_t
		auto& global_cable2 = this->getT(0).getT(2).getT(2).getT(1);                         // routing::global_cable<global_cable2_t_index, parameter::empty>
		auto& chain3 = this->getT(0).getT(2).getT(3);                                        // MatrixTest2_impl::chain3_t
		auto& peak3 = this->getT(0).getT(2).getT(3).getT(0);                                 // MatrixTest2_impl::peak3_t
		auto& global_cable3 = this->getT(0).getT(2).getT(3).getT(1);                         // routing::global_cable<global_cable3_t_index, parameter::empty>
		auto& chain33 = this->getT(1);                                                       // MatrixTest2_impl::chain33_t<NV>
		auto& xfader = this->getT(1).getT(0);                                                // MatrixTest2_impl::xfader_t<NV>
		auto& chain16 = this->getT(1).getT(1);                                               // MatrixTest2_impl::chain16_t<NV>
		auto& split1 = this->getT(1).getT(1).getT(0);                                        // MatrixTest2_impl::split1_t<NV>
		auto& chain22 = this->getT(1).getT(1).getT(0).getT(0);                               // MatrixTest2_impl::chain22_t<NV>
		auto& gain = this->getT(1).getT(1).getT(0).getT(0).getT(0);                          // core::gain<NV>
		auto& chain19 = this->getT(1).getT(1).getT(0).getT(1);                               // MatrixTest2_impl::chain19_t<NV>
		auto& branch1 = this->getT(1).getT(1).getT(0).getT(1).getT(0);                       // MatrixTest2_impl::branch1_t<NV>
		auto& chain20 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(0);               // MatrixTest2_impl::chain20_t
		auto& chain38 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(1);               // MatrixTest2_impl::chain38_t<NV>
		auto& svf = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(1).getT(0);           // filters::svf<NV>
		auto& chain43 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(2);               // MatrixTest2_impl::chain43_t<NV>
		auto& svf5 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(2).getT(0);          // filters::svf<NV>
		auto& chain45 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(3);               // MatrixTest2_impl::chain45_t<NV>
		auto& svf6 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(3).getT(0);          // filters::svf<NV>
		auto& chain39 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(4);               // MatrixTest2_impl::chain39_t<NV>
		auto& biquad = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(4).getT(0);        // filters::biquad<NV>
		auto& chain44 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(5);               // MatrixTest2_impl::chain44_t<NV>
		auto& ring_mod = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(5).getT(0);      // filters::ring_mod<NV>
		auto& chain46 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(6);               // MatrixTest2_impl::chain46_t<NV>
		auto& fix8_block = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(6).getT(0);    // MatrixTest2_impl::fix8_block_t<NV>
		auto& split3 = this->getT(1).getT(1).getT(0).getT(1).                                // MatrixTest2_impl::split3_t<NV>
                       getT(0).getT(6).getT(0).getT(0);
		auto& chain17 = this->getT(1).getT(1).getT(0).getT(1).                               // MatrixTest2_impl::chain17_t
                        getT(0).getT(6).getT(0).getT(0).
                        getT(0);
		auto& chain24 = this->getT(1).getT(1).getT(0).getT(1).                               // MatrixTest2_impl::chain24_t<NV>
                        getT(0).getT(6).getT(0).getT(0).
                        getT(1);
		auto& sig2mod = this->getT(1).getT(1).getT(0).getT(1).getT(0).                       // math::sig2mod<NV>
                        getT(6).getT(0).getT(0).getT(1).getT(0);
		auto& fmod1 = this->getT(1).getT(1).getT(0).getT(1).getT(0).                         // math::fmod<NV>
                      getT(6).getT(0).getT(0).getT(1).getT(1);
		auto& peak12 = this->getT(1).getT(1).getT(0).getT(1).getT(0).                        // MatrixTest2_impl::peak12_t<NV>
                       getT(6).getT(0).getT(0).getT(1).getT(2);
		auto& clear1 = this->getT(1).getT(1).getT(0).getT(1).getT(0).                        // math::clear<NV>
                       getT(6).getT(0).getT(0).getT(1).getT(3);
		auto& cable_table6 = this->getT(1).getT(1).getT(0).getT(1).                          // MatrixTest2_impl::cable_table6_t<NV>
                             getT(0).getT(6).getT(0).getT(1);
		auto& modchain1 = this->getT(1).getT(1).getT(0).getT(1).                             // MatrixTest2_impl::modchain1_t<NV>
                          getT(0).getT(6).getT(0).getT(2);
		auto& pma1 = this->getT(1).getT(1).getT(0).getT(1).                                  // MatrixTest2_impl::pma1_t<NV>
                     getT(0).getT(6).getT(0).getT(2).
                     getT(0);
		auto& fmod = this->getT(1).getT(1).getT(0).getT(1).                                  // math::fmod<NV>
                     getT(0).getT(6).getT(0).getT(3);
		auto& div = this->getT(1).getT(1).getT(0).getT(1).                                   // math::div<NV>
                    getT(0).getT(6).getT(0).getT(4);
		auto& gain2 = this->getT(1).getT(1).getT(0).getT(1).                                 // core::gain<NV>
                      getT(0).getT(6).getT(0).getT(5);
		auto& one_pole = this->getT(1).getT(1).getT(0).getT(1).                              // filters::one_pole<NV>
                         getT(0).getT(6).getT(0).getT(6);
		auto& chain18 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(7);               // MatrixTest2_impl::chain18_t<NV>
		auto& chain41 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(7).getT(0);       // MatrixTest2_impl::chain41_t<NV>
		auto& wrapmidi31 = this->getT(1).getT(1).getT(0).getT(1).                            // MatrixTest2_impl::wrapmidi31_t<NV>
                           getT(0).getT(7).getT(0).getT(0);
		auto& midi3 = this->getT(1).getT(1).getT(0).getT(1).                                 // MatrixTest2_impl::midi3_t<NV>
                      getT(0).getT(7).getT(0).getT(0).
                      getT(0);
		auto& offline2 = this->getT(1).getT(1).getT(0).getT(1).                              // MatrixTest2_impl::offline2_t<NV>
                         getT(0).getT(7).getT(0).getT(1);
		auto& converter6 = this->getT(1).getT(1).getT(0).getT(1).                            // MatrixTest2_impl::converter6_t<NV>
                           getT(0).getT(7).getT(0).getT(1).
                           getT(0);
		auto& converter7 = this->getT(1).getT(1).getT(0).getT(1).                            // MatrixTest2_impl::converter7_t<NV>
                           getT(0).getT(7).getT(0).getT(1).
                           getT(1);
		auto& frame2_block1 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(7).getT(1); // MatrixTest2_impl::frame2_block1_t<NV>
		auto& pma_unscaled3 = this->getT(1).getT(1).getT(0).getT(1).                         // MatrixTest2_impl::pma_unscaled3_t<NV>
                              getT(0).getT(7).getT(1).getT(0);
		auto& receive3 = this->getT(1).getT(1).getT(0).getT(1).                              // routing::receive<NV, stereo_frame_cable<NV>>
                         getT(0).getT(7).getT(1).getT(1);
		auto& one_pole5 = this->getT(1).getT(1).getT(0).getT(1).                             // filters::one_pole<NV>
                          getT(0).getT(7).getT(1).getT(2);
		auto& fix_delay = this->getT(1).getT(1).getT(0).getT(1).                             // wrap::no_process<core::fix_delay>
                          getT(0).getT(7).getT(1).getT(3);
		auto& jdelay_thiran3 = this->getT(1).getT(1).getT(0).getT(1).                        // jdsp::jdelay_thiran<NV>
                               getT(0).getT(7).getT(1).getT(4);
		auto& send3 = this->getT(1).getT(1).getT(0).getT(1).                                 // routing::send<NV, stereo_frame_cable<NV>>
                      getT(0).getT(7).getT(1).getT(5);
		auto& one_pole3 = this->getT(1).getT(1).getT(0).getT(1).                             // filters::one_pole<NV>
                          getT(0).getT(7).getT(1).getT(6);
		auto& chain21 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(8);               // MatrixTest2_impl::chain21_t<NV>
		auto& chain42 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(8).getT(0);       // MatrixTest2_impl::chain42_t<NV>
		auto& wrapmidi41 = this->getT(1).getT(1).getT(0).getT(1).                            // MatrixTest2_impl::wrapmidi41_t<NV>
                           getT(0).getT(8).getT(0).getT(0);
		auto& midi4 = this->getT(1).getT(1).getT(0).getT(1).                                 // MatrixTest2_impl::midi4_t<NV>
                      getT(0).getT(8).getT(0).getT(0).
                      getT(0);
		auto& offline3 = this->getT(1).getT(1).getT(0).getT(1).                              // MatrixTest2_impl::offline3_t<NV>
                         getT(0).getT(8).getT(0).getT(1);
		auto& converter8 = this->getT(1).getT(1).getT(0).getT(1).                            // MatrixTest2_impl::converter8_t<NV>
                           getT(0).getT(8).getT(0).getT(1).
                           getT(0);
		auto& pma_unscaled4 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(8).getT(1); // MatrixTest2_impl::pma_unscaled4_t<NV>
		auto& frame2_block2 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(8).getT(2); // MatrixTest2_impl::frame2_block2_t<NV>
		auto& allpass = this->getT(1).getT(1).getT(0).getT(1).                               // filters::allpass<NV>
                        getT(0).getT(8).getT(2).getT(0);
		auto& one_pole4 = this->getT(1).getT(1).getT(0).getT(1).                             // filters::one_pole<NV>
                          getT(0).getT(8).getT(2).getT(1);
		auto& chain23 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(9);               // MatrixTest2_impl::chain23_t<NV>
		auto& cable_table5 = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(9).getT(0);  // MatrixTest2_impl::cable_table5_t<NV>
		auto& bitcrush = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(9).getT(1);      // fx::bitcrush<NV>
		auto& sampleandhold = this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(9).getT(2); // fx::sampleandhold<NV>
		auto& gain1 = this->getT(1).getT(1).getT(0).getT(1).getT(1);                         // core::gain<NV>
		auto& gain3 = this->getT(1).getT(2);                                                 // core::gain<NV>
		auto& jpanner = this->getT(1).getT(3);                                               // jdsp::jpanner<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(2).connectT(0, granular_player_stepquant_density_hybrid_native); // GrainMix -> granular_player_stepquant_density_hybrid_native::Density
		
		this->getParameterT(3).connectT(0, granular_player_stepquant_density_hybrid_native); // Scatter -> granular_player_stepquant_density_hybrid_native::PhaseScatter
		
		this->getParameterT(4).connectT(0, minmax); // WindowShape -> minmax::Value
		
		this->getParameterT(5).connectT(0, granular_player_stepquant_density_hybrid_native); // PanSpread -> granular_player_stepquant_density_hybrid_native::PanSpread
		
		this->getParameterT(6).connectT(0, pack8_writer); // PitchMode -> pack8_writer::Value1
		
		this->getParameterT(7).connectT(0, granular_player_stepquant_density_hybrid_native); // PitchSpread -> granular_player_stepquant_density_hybrid_native::PitchSpread
		
		this->getParameterT(8).connectT(0, granular_player_stepquant_density_hybrid_native); // MaxGrains -> granular_player_stepquant_density_hybrid_native::MaxGrains
		
		this->getParameterT(9).connectT(0, pack8_writer); // ScrubMode -> pack8_writer::Value2
		
		this->getParameterT(10).connectT(0, pack8_writer); // ScrubBlend -> pack8_writer::Value3
		
		this->getParameterT(11).connectT(0, granular_player_stepquant_density_hybrid_native); // Direction -> granular_player_stepquant_density_hybrid_native::DirectionMode
		
		this->getParameterT(15).connectT(0, pack8_writer); // TransportMode -> pack8_writer::Value4
		
		this->getParameterT(16).connectT(0, branch); // ModOut1 -> branch::Index
		
		this->getParameterT(17).connectT(0, xfader); // FxMix -> xfader::Value
		
		this->getParameterT(18).connectT(0, branch1); // FxMode -> branch1::Index
		
		auto& Resonance_p = this->getParameterT(20);
		Resonance_p.connectT(0, svf);           // Resonance -> svf::Q
		Resonance_p.connectT(1, svf5);          // Resonance -> svf5::Q
		Resonance_p.connectT(2, svf6);          // Resonance -> svf6::Q
		Resonance_p.connectT(3, biquad);        // Resonance -> biquad::Q
		Resonance_p.connectT(4, ring_mod);      // Resonance -> ring_mod::Q
		Resonance_p.connectT(5, one_pole);      // Resonance -> one_pole::Frequency
		Resonance_p.connectT(6, one_pole5);     // Resonance -> one_pole5::Frequency
		Resonance_p.connectT(7, allpass);       // Resonance -> allpass::Q
		Resonance_p.connectT(8, sampleandhold); // Resonance -> sampleandhold::Counter
		Resonance_p.connectT(9, receive3);      // Resonance -> receive3::Feedback
		
		this->getParameterT(22).connectT(0, jpanner); // Pan -> jpanner::Pan
		
		this->getParameterT(23).connectT(0, gain3); // Vol -> gain3::Gain
		
		this->getParameterT(24).connectT(0, tempo_sync); // GrainSync -> tempo_sync::Enabled
		
		this->getParameterT(25).connectT(0, tempo_sync); // GrainDiv -> tempo_sync::Multiplier
		
		this->getParameterT(26).connectT(0, tempo_sync); // GrainTempo -> tempo_sync::Tempo
		
		this->getParameterT(27).connectT(0, tempo_sync1); // PitchDivide -> tempo_sync1::Multiplier
		
		this->getParameterT(28).connectT(0, tempo_sync1); // PitchTempo -> tempo_sync1::Tempo
		
		this->getParameterT(29).connectT(0, granular_player_stepquant_density_hybrid_native); // Respawn -> granular_player_stepquant_density_hybrid_native::Respawn
		
		this->getParameterT(30).connectT(0, granular_player_stepquant_density_hybrid_native); // Diffusion -> granular_player_stepquant_density_hybrid_native::Diffusion
		
		this->getParameterT(31).connectT(0, pack8_writer); // PitchSync -> pack8_writer::Value5
		
		this->getParameterT(32).connectT(0, pack8_writer); // Glide -> pack8_writer::Value6
		
		this->getParameterT(33).connectT(0, pack8_writer); // PhaseScatterShape -> pack8_writer::Value7
		
		this->getParameterT(34).connectT(0, pack8_writer); // GrainTravelShape -> pack8_writer::Value8
		
		this->getParameterT(35).connectT(0, granular_player_stepquant_density_hybrid_native); // BloomOn -> granular_player_stepquant_density_hybrid_native::CloudAmount
		
		this->getParameterT(36).connectT(0, tempo_sync3); // BloomDiv -> tempo_sync3::Multiplier
		
		this->getParameterT(37).connectT(0, branch2); // IndOut -> branch2::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		converter.getWrappedObject().getParameter().connectT(0, granular_player_stepquant_density_hybrid_native); // converter -> granular_player_stepquant_density_hybrid_native::PitchSemitones
		pitch_mod.getParameter().connectT(0, converter);                                                          // pitch_mod -> converter::Value
		tempo_sync.getParameter().connectT(0, granular_player_stepquant_density_hybrid_native);                   // tempo_sync -> granular_player_stepquant_density_hybrid_native::GrainMs
		extra_mod2.getParameter().connectT(0, tempo_sync);                                                        // extra_mod2 -> tempo_sync::UnsyncedTime
		cable_table5.getWrappedObject().getParameter().connectT(0, bitcrush);                                     // cable_table5 -> bitcrush::BitDepth
		pma_unscaled4.getWrappedObject().getParameter().connectT(0, allpass);                                     // pma_unscaled4 -> allpass::Frequency
		converter7.getWrappedObject().getParameter().connectT(0, fix_delay);                                      // converter7 -> fix_delay::DelayTime
		converter7.getWrappedObject().getParameter().connectT(1, jdelay_thiran3);                                 // converter7 -> jdelay_thiran3::DelayTime
		pma_unscaled3.getWrappedObject().getParameter().connectT(0, converter7);                                  // pma_unscaled3 -> converter7::Value
		pma1.getWrappedObject().getParameter().connectT(0, fmod);                                                 // pma1 -> fmod::Value
		pma1.getWrappedObject().getParameter().connectT(1, div);                                                  // pma1 -> div::Value
		cable_table6.getWrappedObject().getParameter().connectT(0, pma1);                                         // cable_table6 -> pma1::Add
		extra_mod6.getParameter().connectT(0, svf);                                                               // extra_mod6 -> svf::Frequency
		extra_mod6.getParameter().connectT(1, biquad);                                                            // extra_mod6 -> biquad::Frequency
		extra_mod6.getParameter().connectT(2, svf6);                                                              // extra_mod6 -> svf6::Frequency
		extra_mod6.getParameter().connectT(3, svf5);                                                              // extra_mod6 -> svf5::Frequency
		extra_mod6.getParameter().connectT(4, ring_mod);                                                          // extra_mod6 -> ring_mod::Frequency
		extra_mod6.getParameter().connectT(5, cable_table5);                                                      // extra_mod6 -> cable_table5::Value
		extra_mod6.getParameter().connectT(6, pma_unscaled4);                                                     // extra_mod6 -> pma_unscaled4::Multiply
		extra_mod6.getParameter().connectT(7, pma_unscaled3);                                                     // extra_mod6 -> pma_unscaled3::Multiply
		extra_mod6.getParameter().connectT(8, cable_table6);                                                      // extra_mod6 -> cable_table6::Value
		extra_mod6.getParameter().connectT(9, pma1);                                                              // extra_mod6 -> pma1::Multiply
		extra_mod1.getParameter().connectT(0, granular_player_stepquant_density_hybrid_native);                   // extra_mod1 -> granular_player_stepquant_density_hybrid_native::Scrub
		extra_mod4.getParameter().connectT(0, granular_player_stepquant_density_hybrid_native);                   // extra_mod4 -> granular_player_stepquant_density_hybrid_native::ScrubB
		extra_mod3.getParameter().connectT(0, granular_player_stepquant_density_hybrid_native);                   // extra_mod3 -> granular_player_stepquant_density_hybrid_native::ScrubC
		extra_mod5.getParameter().connectT(0, granular_player_stepquant_density_hybrid_native);                   // extra_mod5 -> granular_player_stepquant_density_hybrid_native::ScrubD
		extra_mod7.getParameter().connectT(0, global_cable4);                                                     // extra_mod7 -> global_cable4::Value
		extra_mod8.getParameter().connectT(0, global_cable5);                                                     // extra_mod8 -> global_cable5::Value
		extra_mod9.getParameter().connectT(0, global_cable6);                                                     // extra_mod9 -> global_cable6::Value
		extra_mod10.getParameter().connectT(0, global_cable7);                                                    // extra_mod10 -> global_cable7::Value
		extra_mod11.getParameter().connectT(0, global_cable8);                                                    // extra_mod11 -> global_cable8::Value
		extra_mod12.getParameter().connectT(0, global_cable9);                                                    // extra_mod12 -> global_cable9::Value
		extra_mod13.getParameter().connectT(0, global_cable10);                                                   // extra_mod13 -> global_cable10::Value
		extra_mod14.getParameter().connectT(0, global_cable11);                                                   // extra_mod14 -> global_cable11::Value
		extra_mod15.getParameter().connectT(0, global_cable12);                                                   // extra_mod15 -> global_cable12::Value
		extra_mod16.getParameter().connectT(0, global_cable13);                                                   // extra_mod16 -> global_cable13::Value
		extra_mod17.getParameter().connectT(0, global_cable14);                                                   // extra_mod17 -> global_cable14::Value
		extra_mod18.getParameter().connectT(0, global_cable15);                                                   // extra_mod18 -> global_cable15::Value
		extra_mod19.getParameter().connectT(0, global_cable16);                                                   // extra_mod19 -> global_cable16::Value
		extra_mod20.getParameter().connectT(0, global_cable17);                                                   // extra_mod20 -> global_cable17::Value
		extra_mod21.getParameter().connectT(0, global_cable18);                                                   // extra_mod21 -> global_cable18::Value
		extra_mod22.getParameter().connectT(0, global_cable19);                                                   // extra_mod22 -> global_cable19::Value
		tempo_sync1.getParameter().connectT(0, granular_player_stepquant_density_hybrid_native);                  // tempo_sync1 -> granular_player_stepquant_density_hybrid_native::PitchSyncInput
		minmax.getWrappedObject().getParameter().connectT(0, granular_player_stepquant_density_hybrid_native);    // minmax -> granular_player_stepquant_density_hybrid_native::WindowShape
		tempo_sync3.getParameter().connectT(0, granular_player_stepquant_density_hybrid_native);                  // tempo_sync3 -> granular_player_stepquant_density_hybrid_native::BloomDuration
		peak.getParameter().connectT(0, global_cable);                                                            // peak -> global_cable::Value
		peak1.getParameter().connectT(0, global_cable1);                                                          // peak1 -> global_cable1::Value
		peak2.getParameter().connectT(0, global_cable2);                                                          // peak2 -> global_cable2::Value
		peak3.getParameter().connectT(0, global_cable3);                                                          // peak3 -> global_cable3::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                             // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);                            // xfader -> gain1::Gain
		peak12.getParameter().connectT(0, pma1);                                 // peak12 -> pma1::Value
		converter6.getWrappedObject().getParameter().connectT(0, pma_unscaled3); // converter6 -> pma_unscaled3::Value
		midi3.getParameter().connectT(0, converter6);                            // midi3 -> converter6::Value
		converter8.getWrappedObject().getParameter().connectT(0, pma_unscaled4); // converter8 -> pma_unscaled4::Value
		midi4.getParameter().connectT(0, converter8);                            // midi4 -> converter8::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send3.connect(receive3);
		
		// Default Values --------------------------------------------------------------------------
		
		pitch_mod.setParameterT(0, 0.); // core::pitch_mod::ProcessSignal
		
		extra_mod2.setParameterT(0, 1.); // core::extra_mod::Index
		extra_mod2.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		extra_mod6.setParameterT(0, 5.); // core::extra_mod::Index
		extra_mod6.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		extra_mod1.setParameterT(0, 0.); // core::extra_mod::Index
		extra_mod1.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		extra_mod4.setParameterT(0, 2.); // core::extra_mod::Index
		extra_mod4.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		extra_mod3.setParameterT(0, 3.); // core::extra_mod::Index
		extra_mod3.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		extra_mod5.setParameterT(0, 4.); // core::extra_mod::Index
		extra_mod5.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // branch2::Index is automated
		
		extra_mod7.setParameterT(0, 0.); // core::extra_mod::Index
		extra_mod7.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable4::Value is automated
		
		extra_mod8.setParameterT(0, 2.); // core::extra_mod::Index
		extra_mod8.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable5::Value is automated
		
		extra_mod9.setParameterT(0, 3.); // core::extra_mod::Index
		extra_mod9.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable6::Value is automated
		
		extra_mod10.setParameterT(0, 4.); // core::extra_mod::Index
		extra_mod10.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable7::Value is automated
		
		extra_mod11.setParameterT(0, 0.); // core::extra_mod::Index
		extra_mod11.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable8::Value is automated
		
		extra_mod12.setParameterT(0, 2.); // core::extra_mod::Index
		extra_mod12.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable9::Value is automated
		
		extra_mod13.setParameterT(0, 3.); // core::extra_mod::Index
		extra_mod13.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable10::Value is automated
		
		extra_mod14.setParameterT(0, 4.); // core::extra_mod::Index
		extra_mod14.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable11::Value is automated
		
		extra_mod15.setParameterT(0, 0.); // core::extra_mod::Index
		extra_mod15.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable12::Value is automated
		
		extra_mod16.setParameterT(0, 2.); // core::extra_mod::Index
		extra_mod16.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable13::Value is automated
		
		extra_mod17.setParameterT(0, 3.); // core::extra_mod::Index
		extra_mod17.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable14::Value is automated
		
		extra_mod18.setParameterT(0, 4.); // core::extra_mod::Index
		extra_mod18.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable15::Value is automated
		
		extra_mod19.setParameterT(0, 0.); // core::extra_mod::Index
		extra_mod19.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable16::Value is automated
		
		extra_mod20.setParameterT(0, 2.); // core::extra_mod::Index
		extra_mod20.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable17::Value is automated
		
		extra_mod21.setParameterT(0, 3.); // core::extra_mod::Index
		extra_mod21.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable18::Value is automated
		
		extra_mod22.setParameterT(0, 4.); // core::extra_mod::Index
		extra_mod22.setParameterT(1, 0.); // core::extra_mod::ProcessSignal
		
		; // global_cable19::Value is automated
		
		; // converter::Value is automated
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		;                                   // tempo_sync1::Tempo is automated
		;                                   // tempo_sync1::Multiplier is automated
		tempo_sync1.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                                  // minmax::Value is automated
		minmax.setParameterT(1, 0.);       // control::minmax::Minimum
		minmax.setParameterT(2, 0.991969); // control::minmax::Maximum
		minmax.setParameterT(3, 1.);       // control::minmax::Skew
		minmax.setParameterT(4, 0.);       // control::minmax::Step
		minmax.setParameterT(5, 0.);       // control::minmax::Polarity
		
		tempo_sync3.setParameterT(0, 14.);   // control::tempo_sync::Tempo
		;                                    // tempo_sync3::Multiplier is automated
		tempo_sync3.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync3.setParameterT(3, 852.7); // control::tempo_sync::UnsyncedTime
		
		pack_resizer.setParameterT(0, 8.); // control::pack_resizer::NumSliders
		
		; // pack8_writer::Value1 is automated
		; // pack8_writer::Value2 is automated
		; // pack8_writer::Value3 is automated
		; // pack8_writer::Value4 is automated
		; // pack8_writer::Value5 is automated
		; // pack8_writer::Value6 is automated
		; // pack8_writer::Value7 is automated
		; // pack8_writer::Value8 is automated
		
		; // granular_player_stepquant_density_hybrid_native::PitchSemitones is automated
		; // granular_player_stepquant_density_hybrid_native::Scrub is automated
		; // granular_player_stepquant_density_hybrid_native::GrainMs is automated
		; // granular_player_stepquant_density_hybrid_native::Density is automated
		; // granular_player_stepquant_density_hybrid_native::WindowShape is automated
		; // granular_player_stepquant_density_hybrid_native::PanSpread is automated
		; // granular_player_stepquant_density_hybrid_native::Respawn is automated
		; // granular_player_stepquant_density_hybrid_native::PitchSpread is automated
		; // granular_player_stepquant_density_hybrid_native::MaxGrains is automated
		; // granular_player_stepquant_density_hybrid_native::Diffusion is automated
		; // granular_player_stepquant_density_hybrid_native::CloudAmount is automated
		; // granular_player_stepquant_density_hybrid_native::DirectionMode is automated
		; // granular_player_stepquant_density_hybrid_native::PhaseScatter is automated
		; // granular_player_stepquant_density_hybrid_native::ScrubB is automated
		; // granular_player_stepquant_density_hybrid_native::ScrubC is automated
		; // granular_player_stepquant_density_hybrid_native::ScrubD is automated
		; // granular_player_stepquant_density_hybrid_native::BloomDuration is automated
		; // granular_player_stepquant_density_hybrid_native::PitchSyncInput is automated
		
		; // branch::Index is automated
		
		; // global_cable::Value is automated
		
		; // global_cable1::Value is automated
		
		; // global_cable2::Value is automated
		
		; // global_cable3::Value is automated
		
		; // xfader::Value is automated
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 10.3);  // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // branch1::Index is automated
		
		;                                 // svf::Frequency is automated
		;                                 // svf::Q is automated
		svf.setParameterT(2, 0.);         // filters::svf::Gain
		svf.setParameterT(3, 0.00118434); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);         // filters::svf::Mode
		svf.setParameterT(5, 1.);         // filters::svf::Enabled
		
		;                                  // svf5::Frequency is automated
		;                                  // svf5::Q is automated
		svf5.setParameterT(2, 0.);         // filters::svf::Gain
		svf5.setParameterT(3, 0.00154763); // filters::svf::Smoothing
		svf5.setParameterT(4, 1.);         // filters::svf::Mode
		svf5.setParameterT(5, 1.);         // filters::svf::Enabled
		
		;                            // svf6::Frequency is automated
		;                            // svf6::Q is automated
		svf6.setParameterT(2, 0.);   // filters::svf::Gain
		svf6.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf6.setParameterT(4, 2.);   // filters::svf::Mode
		svf6.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                              // biquad::Frequency is automated
		;                              // biquad::Q is automated
		biquad.setParameterT(2, 0.);   // filters::biquad::Gain
		biquad.setParameterT(3, 0.01); // filters::biquad::Smoothing
		biquad.setParameterT(4, 5.);   // filters::biquad::Mode
		biquad.setParameterT(5, 1.);   // filters::biquad::Enabled
		
		;                                // ring_mod::Frequency is automated
		;                                // ring_mod::Q is automated
		ring_mod.setParameterT(2, 0.);   // filters::ring_mod::Gain
		ring_mod.setParameterT(3, 0.01); // filters::ring_mod::Smoothing
		ring_mod.setParameterT(4, 0.);   // filters::ring_mod::Mode
		ring_mod.setParameterT(5, 1.);   // filters::ring_mod::Enabled
		
		sig2mod.setParameterT(0, 0.); // math::sig2mod::Value
		
		fmod1.setParameterT(0, 0.520276); // math::fmod::Value
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table6::Value is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // fmod::Value is automated
		
		; // div::Value is automated
		
		gain2.setParameterT(0, -11.); // core::gain::Gain
		gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		gain2.setParameterT(2, 0.);   // core::gain::ResetValue
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // converter6::Value is automated
		
		; // converter7::Value is automated
		
		;                                   // pma_unscaled3::Value is automated
		;                                   // pma_unscaled3::Multiply is automated
		pma_unscaled3.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // receive3::Feedback is automated
		
		;                                 // one_pole5::Frequency is automated
		one_pole5.setParameterT(1, 9.9);  // filters::one_pole::Q
		one_pole5.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole5.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole5.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole5.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                  // fix_delay::DelayTime is automated
		fix_delay.setParameterT(1, 1024.); // core::fix_delay::FadeTime
		
		jdelay_thiran3.setParameterT(0, 30.); // jdsp::jdelay_thiran::Limit
		;                                     // jdelay_thiran3::DelayTime is automated
		
		one_pole3.setParameterT(0, 53.4697); // filters::one_pole::Frequency
		one_pole3.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole3.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole3.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole3.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole3.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		; // converter8::Value is automated
		
		;                                   // pma_unscaled4::Value is automated
		;                                   // pma_unscaled4::Multiply is automated
		pma_unscaled4.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		;                               // allpass::Frequency is automated
		;                               // allpass::Q is automated
		allpass.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		one_pole4.setParameterT(0, 50.);  // filters::one_pole::Frequency
		one_pole4.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole4.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole4.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole4.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole4.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // cable_table5::Value is automated
		
		;                              // bitcrush::BitDepth is automated
		bitcrush.setParameterT(1, 0.); // fx::bitcrush::Mode
		
		; // sampleandhold::Counter is automated
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 11.6);  // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // gain3::Gain is automated
		gain3.setParameterT(1, 2.3);  // core::gain::Smoothing
		gain3.setParameterT(2, -9.4); // core::gain::ResetValue
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		this->setParameterT(0, 0.0516304);
		this->setParameterT(1, 433.049);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 0.121179);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 32.);
		this->setParameterT(9, 0.00673828);
		this->setParameterT(10, 0.00527344);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 0.489531);
		this->setParameterT(13, 0.125977);
		this->setParameterT(14, 0.00146484);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 7.);
		this->setParameterT(19, 0.);
		this->setParameterT(20, 1.);
		this->setParameterT(21, 0.);
		this->setParameterT(22, 0.0251953);
		this->setParameterT(23, -2.4);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 29.);
		this->setParameterT(26, 5.);
		this->setParameterT(27, 1.);
		this->setParameterT(28, 3.);
		this->setParameterT(29, 0.);
		this->setParameterT(30, 0.294136);
		this->setParameterT(31, 1.);
		this->setParameterT(32, 0.198926);
		this->setParameterT(33, 1.);
		this->setParameterT(34, 3.);
		this->setParameterT(35, 0.99482);
		this->setParameterT(36, 1.);
		this->setParameterT(37, 0.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);                 // MatrixTest2_impl::pitch_mod_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).connectToRuntimeTarget(addConnection, c);                 // MatrixTest2_impl::extra_mod2_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).connectToRuntimeTarget(addConnection, c);                 // MatrixTest2_impl::extra_mod6_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);                 // MatrixTest2_impl::extra_mod1_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).connectToRuntimeTarget(addConnection, c);                 // MatrixTest2_impl::extra_mod4_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).connectToRuntimeTarget(addConnection, c);                 // MatrixTest2_impl::extra_mod3_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).connectToRuntimeTarget(addConnection, c);                 // MatrixTest2_impl::extra_mod5_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod7_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable4_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod8_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable5_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod9_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(2).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable6_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod10_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable7_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod11_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable8_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod12_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(1).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable9_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod13_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(2).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable10_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod14_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(3).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable11_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod15_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable12_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(2).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod16_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(1).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable13_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(2).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod17_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(2).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable14_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(2).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod18_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(3).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable15_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod19_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable16_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(3).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod20_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).getT(1).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable17_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(3).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod21_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).getT(2).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable18_t_index, parameter::empty>
		this->getT(0).getT(0).getT(2).getT(3).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // MatrixTest2_impl::extra_mod22_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).getT(3).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable19_t_index, parameter::empty>
		this->getT(0).getT(2).getT(0).getT(1).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(0).getT(2).getT(1).getT(1).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable1_t_index, parameter::empty>
		this->getT(0).getT(2).getT(2).getT(1).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable2_t_index, parameter::empty>
		this->getT(0).getT(2).getT(3).getT(1).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable3_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);                         // MatrixTest2_impl::pitch_mod_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);                         // MatrixTest2_impl::extra_mod2_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).setExternalData(b, index);                         // MatrixTest2_impl::extra_mod6_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);                         // MatrixTest2_impl::extra_mod1_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);                         // MatrixTest2_impl::extra_mod4_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).setExternalData(b, index);                         // MatrixTest2_impl::extra_mod3_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).setExternalData(b, index);                         // MatrixTest2_impl::extra_mod5_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod7_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod8_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(2).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod9_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod10_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod11_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(1).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod12_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(2).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod13_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(3).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod14_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod15_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(1).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod16_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(2).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod17_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(3).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod18_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod19_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).getT(1).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod20_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).getT(2).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod21_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).getT(3).getT(0).setExternalData(b, index);         // MatrixTest2_impl::extra_mod22_t<NV>
		this->getT(0).getT(0).getT(8).setExternalData(b, index);                                 // MatrixTest2_impl::pack_resizer_t
		this->getT(0).getT(0).getT(9).setExternalData(b, index);                                 // MatrixTest2_impl::pack8_writer_t
		this->getT(0).getT(1).setExternalData(b, index);                                         // project::granular_player_stepquant_density_hybrid_native<NV>
		this->getT(0).getT(2).getT(0).getT(0).setExternalData(b, index);                         // MatrixTest2_impl::peak_t
		this->getT(0).getT(2).getT(1).getT(0).setExternalData(b, index);                         // MatrixTest2_impl::peak1_t
		this->getT(0).getT(2).getT(2).getT(0).setExternalData(b, index);                         // MatrixTest2_impl::peak2_t
		this->getT(0).getT(2).getT(3).getT(0).setExternalData(b, index);                         // MatrixTest2_impl::peak3_t
		this->getT(1).getT(1).getT(0).getT(1).getT(0).                                           // MatrixTest2_impl::peak12_t<NV>
        getT(6).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index);
		this->getT(1).getT(1).getT(0).getT(1).                                                   // MatrixTest2_impl::cable_table6_t<NV>
        getT(0).getT(6).getT(0).getT(1).setExternalData(b, index);
		this->getT(1).getT(1).getT(0).getT(1).getT(0).getT(9).getT(0).setExternalData(b, index); // MatrixTest2_impl::cable_table5_t<NV>
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
using MatrixTest2 = wrap::node<MatrixTest2_impl::instance<NV>>;
}


