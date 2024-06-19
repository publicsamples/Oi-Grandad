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

namespace NewGran_impl
{
// ==============================| Node & Parameter type declarations |==============================

using pack4_writer_t = wrap::data<control::pack4_writer, 
                                  data::external::sliderpack<0>>;
using pack4_writer1_t = wrap::data<control::pack4_writer, 
                                   data::external::sliderpack<1>>;
using pack4_writer2_t = wrap::data<control::pack4_writer, 
                                   data::external::sliderpack<2>>;
using pack4_writer4_t = wrap::data<control::pack4_writer, 
                                   data::external::sliderpack<3>>;

using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, pack4_writer_t>, 
                                  pack4_writer1_t, 
                                  pack4_writer2_t, 
                                  pack4_writer4_t>;

using chain6_t = container::chain<parameter::empty, wrap::fix<2, split2_t>>;

using cable_table_t = wrap::data<control::cable_table<parameter::empty>, 
                                 data::external::table<0>>;
using input_toggle_t = control::input_toggle<parameter::plain<cable_table_t, 0>>;

using cable_table16_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<4>>;
using input_toggle16_t = control::input_toggle<parameter::plain<cable_table16_t, 0>>;
using clone_pack_cc = parameter::clonechain<parameter::cloned<parameter::plain<input_toggle_t, 0>>, 
                                            parameter::cloned<parameter::plain<input_toggle16_t, 0>>>;
using clone_pack_t = wrap::data<control::clone_pack<clone_pack_cc>, 
                                data::external::sliderpack<0>>;

using cable_table3_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<1>>;
using input_toggle3_t = control::input_toggle<parameter::plain<cable_table3_t, 0>>;

using cable_table18_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<5>>;
using input_toggle18_t = control::input_toggle<parameter::plain<cable_table18_t, 0>>;
using clone_pack3_cc = parameter::clonechain<parameter::cloned<parameter::plain<input_toggle3_t, 0>>, 
                                             parameter::cloned<parameter::plain<input_toggle18_t, 0>>>;
using clone_pack3_t = wrap::data<control::clone_pack<clone_pack3_cc>, 
                                 data::external::sliderpack<1>>;

using cable_table2_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<2>>;
using input_toggle2_t = control::input_toggle<parameter::plain<cable_table2_t, 0>>;

using cable_table17_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<6>>;
using input_toggle17_t = control::input_toggle<parameter::plain<cable_table17_t, 0>>;
using clone_pack2_cc = parameter::clonechain<parameter::cloned<parameter::plain<input_toggle2_t, 0>>, 
                                             parameter::cloned<parameter::plain<input_toggle17_t, 0>>>;
using clone_pack2_t = wrap::data<control::clone_pack<clone_pack2_cc>, 
                                 data::external::sliderpack<2>>;

using cable_table1_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<3>>;
using input_toggle1_t = control::input_toggle<parameter::plain<cable_table1_t, 0>>;

using cable_table19_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<7>>;
using input_toggle19_t = control::input_toggle<parameter::plain<cable_table19_t, 0>>;
using clone_pack1_cc = parameter::clonechain<parameter::cloned<parameter::plain<input_toggle1_t, 0>>, 
                                             parameter::cloned<parameter::plain<input_toggle19_t, 0>>>;
using clone_pack1_t = wrap::data<control::clone_pack<clone_pack1_cc>, 
                                 data::external::sliderpack<3>>;

using split9_t = container::split<parameter::empty, 
                                  wrap::fix<2, clone_pack_t>, 
                                  clone_pack3_t, 
                                  clone_pack2_t, 
                                  clone_pack1_t>;

using granulator_t = wrap::data<core::granulator, 
                                data::external::audiofile<0>>;
template <int NV>
using pma2_t = control::pma<NV, 
                            parameter::plain<granulator_t, 0>>;

template <int NV>
using input_toggle108_mod = parameter::chain<ranges::Identity, 
                                             parameter::plain<pma2_t<NV>, 2>, 
                                             parameter::plain<input_toggle_t, 1>, 
                                             parameter::plain<input_toggle3_t, 1>, 
                                             parameter::plain<input_toggle2_t, 1>, 
                                             parameter::plain<input_toggle1_t, 1>>;

template <int NV>
using input_toggle108_t = control::input_toggle<input_toggle108_mod<NV>>;
template <int NV>
using input_toggle106_t = control::input_toggle<parameter::plain<input_toggle108_t<NV>, 1>>;

struct cable_table105_t_data
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
		0.040634f, 0.205751f, 0.370867f, 0.535983f, 0.701101f, 0.866217f,
		0.988772f, 0.988801f, 0.988831f, 0.988861f, 0.98889f, 0.98892f,
		0.988949f, 0.988979f, 0.989009f, 0.989038f, 0.989068f, 0.989098f,
		0.989127f, 0.989157f, 0.989186f, 0.989216f, 0.989246f, 0.989275f,
		0.989305f, 0.989335f, 0.989364f, 0.989394f, 0.989423f, 0.989453f,
		0.989483f, 0.989512f, 0.989542f, 0.989572f, 0.989601f, 0.989631f,
		0.98966f, 0.98969f, 0.98972f, 0.989749f, 0.989779f, 0.989809f,
		0.989838f, 0.989868f, 0.989897f, 0.989927f, 0.989957f, 0.989986f,
		0.990016f, 0.990046f, 0.990075f, 0.990105f, 0.990134f, 0.990164f,
		0.990194f, 0.990223f, 0.990253f, 0.990283f, 0.990312f, 0.990342f,
		0.990372f, 0.990401f, 0.990431f, 0.99046f, 0.99049f, 0.99052f,
		0.990549f, 0.990579f, 0.990609f, 0.990638f, 0.990668f, 0.990697f,
		0.990727f, 0.990757f, 0.990786f, 0.990816f, 0.990846f, 0.990875f,
		0.990905f, 0.990934f, 0.990964f, 0.990994f, 0.991023f, 0.991053f,
		0.991083f, 0.991112f, 0.991142f, 0.991171f, 0.991201f, 0.991231f,
		0.99126f, 0.99129f, 0.99132f, 0.991349f, 0.991379f, 0.991408f,
		0.991438f, 0.991468f, 0.991497f, 0.991527f, 0.991557f, 0.991586f,
		0.991616f, 0.991645f, 0.991675f, 0.991705f, 0.991734f, 0.991764f,
		0.991794f, 0.991823f, 0.991853f, 0.991882f, 0.991912f, 0.991942f,
		0.991971f, 0.992001f, 0.992031f, 0.99206f, 0.99209f, 0.992119f,
		0.992149f, 0.992179f, 0.992208f, 0.992238f, 0.992268f, 0.992297f,
		0.992327f, 0.992356f, 0.992386f, 0.992416f, 0.992445f, 0.992475f,
		0.992505f, 0.992534f, 0.992564f, 0.992593f, 0.992623f, 0.992653f,
		0.992682f, 0.992712f, 0.992742f, 0.992771f, 0.992801f, 0.99283f,
		0.99286f, 0.99289f, 0.992919f, 0.992949f, 0.992979f, 0.993008f,
		0.993038f, 0.993068f, 0.993097f, 0.993127f, 0.993156f, 0.993186f,
		0.993216f, 0.993245f, 0.993275f, 0.993304f, 0.993334f, 0.993364f,
		0.993393f, 0.993423f, 0.993453f, 0.993482f, 0.993512f, 0.993541f,
		0.993571f, 0.993601f, 0.99363f, 0.99366f, 0.99369f, 0.993719f,
		0.993749f, 0.993779f, 0.993808f, 0.993838f, 0.993867f, 0.993897f,
		0.993927f, 0.993956f, 0.993986f, 0.994016f, 0.994045f, 0.994075f,
		0.994104f, 0.994134f, 0.994164f, 0.994193f, 0.994223f, 0.994253f,
		0.994282f, 0.994312f, 0.994341f, 0.994371f, 0.994401f, 0.99443f,
		0.99446f, 0.99449f, 0.994519f, 0.994549f, 0.994578f, 0.994608f,
		0.994638f, 0.994667f, 0.994697f, 0.994727f, 0.994756f, 0.994786f,
		0.994815f, 0.994845f, 0.994875f, 0.994904f, 0.994934f, 0.994964f,
		0.994993f, 0.995023f, 0.995052f, 0.995082f, 0.995112f, 0.995141f,
		0.995171f, 0.995201f, 0.99523f, 0.99526f, 0.995289f, 0.995319f,
		0.995349f, 0.995378f, 0.995408f, 0.995438f, 0.995467f, 0.995497f,
		0.995526f, 0.995556f, 0.995586f, 0.995615f, 0.995645f, 0.995675f,
		0.995704f, 0.995734f, 0.995763f, 0.995793f, 0.995823f, 0.995852f,
		0.995882f, 0.995912f, 0.995941f, 0.995971f, 0.996f, 0.99603f,
		0.99606f, 0.996089f, 0.996119f, 0.996149f, 0.996178f, 0.996208f,
		0.996237f, 0.996267f, 0.996297f, 0.996326f, 0.996356f, 0.996386f,
		0.996415f, 0.996445f, 0.996475f, 0.996504f, 0.996534f, 0.996563f,
		0.996593f, 0.996623f, 0.996652f, 0.996682f, 0.996711f, 0.996741f,
		0.996771f, 0.9968f, 0.99683f, 0.99686f, 0.996889f, 0.996919f,
		0.996948f, 0.996978f, 0.997008f, 0.997037f, 0.997067f, 0.997097f,
		0.997126f, 0.997156f, 0.997186f, 0.997215f, 0.997245f, 0.997274f,
		0.997304f, 0.997334f, 0.997363f, 0.997393f, 0.997423f, 0.997452f,
		0.997482f, 0.997511f, 0.997541f, 0.997571f, 0.9976f, 0.99763f,
		0.99766f, 0.997689f, 0.997719f, 0.997748f, 0.997778f, 0.997808f,
		0.997837f, 0.997867f, 0.997897f, 0.997926f, 0.997956f, 0.997985f,
		0.998015f, 0.998045f, 0.998074f, 0.998104f, 0.998134f, 0.998163f,
		0.998193f, 0.998222f, 0.998252f, 0.998282f, 0.998311f, 0.998341f,
		0.998371f, 0.9984f, 0.99843f, 0.998459f, 0.998489f, 0.998519f,
		0.998548f, 0.998578f, 0.998608f, 0.998637f, 0.998667f, 0.998696f,
		0.998726f, 0.998756f, 0.998785f, 0.998815f, 0.998845f, 0.998874f,
		0.998904f, 0.998933f, 0.998963f, 0.998993f, 0.999022f, 0.999052f,
		0.999082f, 0.999111f, 0.999141f, 0.99917f, 0.9992f, 0.99923f,
		0.999259f, 0.999289f, 0.999319f, 0.999348f, 0.999378f, 0.999407f,
		0.999437f, 0.999467f, 0.999496f, 0.999526f, 0.999556f, 0.999585f,
		0.999615f, 0.999644f, 0.999674f, 0.999704f, 0.999733f, 0.999763f,
		0.999793f, 0.999822f, 0.999852f, 0.999882f, 0.999911f, 0.999941f,
		0.99997f, 1.f
	};
};

template <int NV>
using cable_table105_t = wrap::data<control::cable_table<parameter::plain<input_toggle106_t<NV>, 0>>, 
                                    data::embedded::table<cable_table105_t_data>>;

struct cable_table107_t_data
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
		0.f, 0.123775f, 0.374268f, 0.624756f, 0.875244f, 1.f,
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
using cable_table107_t = wrap::data<control::cable_table<parameter::plain<input_toggle108_t<NV>, 0>>, 
                                    data::embedded::table<cable_table107_t_data>>;

template <int NV>
using input_toggle107_t = control::input_toggle<parameter::plain<input_toggle108_t<NV>, 2>>;

struct cable_table106_t_data
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
		0.f, 0.247223f, 0.581217f, 0.915202f, 1.f, 1.f,
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
using cable_table106_t = wrap::data<control::cable_table<parameter::plain<input_toggle107_t<NV>, 0>>, 
                                    data::embedded::table<cable_table106_t_data>>;
template <int NV>
using clone_cable_cc = parameter::clonechain<parameter::cloned<parameter::plain<cable_table105_t<NV>, 0>>, 
                                             parameter::cloned<parameter::plain<cable_table107_t<NV>, 0>>, 
                                             parameter::cloned<parameter::plain<cable_table106_t<NV>, 0>>>;
template <int NV>
using clone_cable_t = control::clone_cable<clone_cable_cc<NV>, duplilogic::fixed>;

template <int NV>
using clone_cable3_cable_mod = parameter::cloned<parameter::plain<input_toggle106_t<NV>, 1>>;
template <int NV>
using clone_cable3_t = control::clone_cable<clone_cable3_cable_mod<NV>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable2_cable_mod = parameter::cloned<parameter::plain<input_toggle106_t<NV>, 2>>;
template <int NV>
using clone_cable2_t = control::clone_cable<clone_cable2_cable_mod<NV>, 
                                            duplilogic::spread>;

template <int NV>
using clone_cable1_cable_mod = parameter::cloned<parameter::plain<input_toggle107_t<NV>, 1>>;
template <int NV>
using clone_cable1_t = control::clone_cable<clone_cable1_cable_mod<NV>, 
                                            duplilogic::nyquist>;

template <int NV>
using clone_pack5_cable_mod = parameter::cloned<parameter::plain<input_toggle107_t<NV>, 2>>;
template <int NV>
using clone_pack5_t = wrap::data<control::clone_pack<clone_pack5_cable_mod<NV>>, 
                                 data::external::sliderpack<4>>;

template <int NV>
using pos_t = container::split<parameter::empty, 
                               wrap::fix<2, clone_cable_t<NV>>, 
                               clone_cable3_t<NV>, 
                               clone_cable2_t<NV>, 
                               clone_cable1_t<NV>, 
                               clone_pack5_t<NV>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<granulator_t, 2>>;
template <int NV>
using clone_cable18_t = control::clone_cable<parameter::cloned<parameter::plain<minmax_t<NV>, 0>>, 
                                             duplilogic::fixed>;

using clone_cable19_t = control::clone_cable<parameter::cloned<parameter::plain<granulator_t, 3>>, 
                                             duplilogic::fixed>;

using clone_cable26_t = control::clone_cable<parameter::cloned<parameter::plain<granulator_t, 4>>, 
                                             duplilogic::fixed>;

using clone_cable25_t = control::clone_cable<parameter::cloned<parameter::plain<granulator_t, 5>>, 
                                             duplilogic::fixed>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<2, clone_cable18_t<NV>>, 
                                   control::clone_cable<parameter::empty>, 
                                   control::clone_cable<parameter::empty>, 
                                   clone_cable19_t, 
                                   clone_cable26_t, 
                                   clone_cable25_t>;

template <int NV>
using cables_t = container::chain<parameter::empty, 
                                  wrap::fix<2, split11_t<NV>>>;

using input_toggle32_t = control::input_toggle<parameter::plain<granulator_t, 1>>;
template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, 
                                             parameter::plain<input_toggle32_t, 1>>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<control::converter<parameter::empty>, 0>, 
                               control::tempo_sync<NV>>;
template <int NV>
using pma_unscaled1_t = control::pma_unscaled<NV, 
                                              parameter::plain<tempo_sync_t<NV>, 0>>;

template <int NV>
using input_toggle110_mod = parameter::chain<ranges::Identity, 
                                             parameter::plain<input_toggle16_t, 1>, 
                                             parameter::plain<input_toggle18_t, 1>, 
                                             parameter::plain<input_toggle17_t, 1>, 
                                             parameter::plain<input_toggle19_t, 1>, 
                                             parameter::plain<pma_unscaled_t<NV>, 2>, 
                                             parameter::plain<pma_unscaled1_t<NV>, 2>>;

template <int NV>
using input_toggle110_t = control::input_toggle<input_toggle110_mod<NV>>;
template <int NV>
using input_toggle109_t = control::input_toggle<parameter::plain<input_toggle110_t<NV>, 1>>;

struct cable_table108_t_data
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
		0.0410957f, 0.208089f, 0.375081f, 0.542074f, 0.709068f, 0.87606f,
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
using cable_table108_t = wrap::data<control::cable_table<parameter::plain<input_toggle109_t<NV>, 0>>, 
                                    data::embedded::table<cable_table108_t_data>>;

struct cable_table109_t_data
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
		0.f, 0.123775f, 0.374268f, 0.624756f, 0.875244f, 1.f,
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
using cable_table109_t = wrap::data<control::cable_table<parameter::plain<input_toggle110_t<NV>, 0>>, 
                                    data::embedded::table<cable_table109_t_data>>;

template <int NV>
using input_toggle111_t = control::input_toggle<parameter::plain<input_toggle110_t<NV>, 2>>;

struct cable_table110_t_data
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
		0.f, 0.247223f, 0.581217f, 0.915202f, 1.f, 1.f,
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
using cable_table110_t = wrap::data<control::cable_table<parameter::plain<input_toggle111_t<NV>, 0>>, 
                                    data::embedded::table<cable_table110_t_data>>;
template <int NV>
using clone_cable6_cc = parameter::clonechain<parameter::cloned<parameter::plain<cable_table108_t<NV>, 0>>, 
                                              parameter::cloned<parameter::plain<cable_table109_t<NV>, 0>>, 
                                              parameter::cloned<parameter::plain<cable_table110_t<NV>, 0>>>;
template <int NV>
using clone_cable6_t = control::clone_cable<clone_cable6_cc<NV>, duplilogic::fixed>;

template <int NV>
using clone_cable7_cable_mod = parameter::cloned<parameter::plain<input_toggle109_t<NV>, 1>>;
template <int NV>
using clone_cable7_t = control::clone_cable<clone_cable7_cable_mod<NV>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable9_cable_mod = parameter::cloned<parameter::plain<input_toggle109_t<NV>, 2>>;
template <int NV>
using clone_cable9_t = control::clone_cable<clone_cable9_cable_mod<NV>, 
                                            duplilogic::scale>;

template <int NV>
using clone_cable10_cable_mod = parameter::cloned<parameter::plain<input_toggle111_t<NV>, 1>>;
template <int NV>
using clone_cable10_t = control::clone_cable<clone_cable10_cable_mod<NV>, 
                                             duplilogic::harmonics>;

template <int NV>
using clone_cable8_cable_mod = parameter::cloned<parameter::plain<input_toggle111_t<NV>, 2>>;
template <int NV>
using clone_cable8_t = control::clone_cable<clone_cable8_cable_mod<NV>, 
                                            duplilogic::spread>;

template <int NV>
using clone_forward_t = control::clone_forward<parameter::cloned<parameter::plain<tempo_sync_t<NV>, 1>>>;

using clone_cable5_t = control::clone_cable<parameter::cloned<parameter::plain<input_toggle32_t, 0>>, 
                                            duplilogic::fixed>;

template <int NV>
using pitch_t = container::split<parameter::empty, 
                                 wrap::fix<2, clone_cable6_t<NV>>, 
                                 clone_cable7_t<NV>, 
                                 clone_cable9_t<NV>, 
                                 clone_cable10_t<NV>, 
                                 clone_cable8_t<NV>, 
                                 clone_forward_t<NV>, 
                                 clone_cable5_t>;

template <int NV>
using split72_t = container::split<parameter::empty, 
                                   wrap::fix<2, input_toggle106_t<NV>>, 
                                   input_toggle108_t<NV>, 
                                   input_toggle107_t<NV>>;

template <int NV>
using FourWaySwitch_t = container::chain<parameter::empty, 
                                         wrap::fix<2, cable_table105_t<NV>>, 
                                         cable_table107_t<NV>, 
                                         cable_table106_t<NV>, 
                                         split72_t<NV>>;

template <int NV>
using split73_t = container::split<parameter::empty, 
                                   wrap::fix<2, input_toggle109_t<NV>>, 
                                   input_toggle110_t<NV>, 
                                   input_toggle111_t<NV>>;

template <int NV>
using FourWaySwitch1_t = container::chain<parameter::empty, 
                                          wrap::fix<2, cable_table108_t<NV>>, 
                                          cable_table109_t<NV>, 
                                          cable_table110_t<NV>, 
                                          split73_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, FourWaySwitch_t<NV>>, 
                                 FourWaySwitch1_t<NV>>;

using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, input_toggle_t>, 
                                 cable_table_t>;

using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, input_toggle3_t>, 
                                  cable_table3_t>;

using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, input_toggle2_t>, 
                                  cable_table2_t>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, input_toggle1_t>, 
                                  cable_table1_t>;

using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain_t>, 
                                  chain3_t, 
                                  chain2_t, 
                                  chain1_t>;

using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle16_t>, 
                                   cable_table16_t>;

using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle18_t>, 
                                   cable_table18_t>;

using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle17_t>, 
                                   cable_table17_t>;

using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<2, input_toggle19_t>, 
                                   cable_table19_t>;

using split16_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain24_t>, 
                                   chain26_t, 
                                   chain25_t, 
                                   chain27_t>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, pma_unscaled_t<NV>>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, pma_unscaled1_t<NV>>>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain5_t<NV>>, 
                                   chain22_t<NV>>;

using converter8_t = control::converter<parameter::plain<input_toggle32_t, 2>, 
                                        conversion_logic::st2pitch>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, split15_t<NV>>, 
                                  tempo_sync_t<NV>, 
                                  control::converter<parameter::empty>, 
                                  converter8_t, 
                                  input_toggle32_t>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain4_t<NV>>>;

template <int NV>
using file_analyser_t = wrap::data<control::file_analyser<parameter::plain<minmax_t<NV>, 2>, file_analysers::length>, 
                                   data::external::audiofile<0>>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, split_t<NV>>, 
                                       split8_t, 
                                       split16_t, 
                                       split1_t<NV>, 
                                       file_analyser_t<NV>, 
                                       minmax_t<NV>, 
                                       pma2_t<NV>, 
                                       granulator_t, 
                                       core::gain<NV>>;
template <int NV>
using clone_t = wrap::fix_clonesplit<clone_child_t<NV>, 4>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<2, clone_t<NV>>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

namespace NewGran_t_parameters
{
// Parameter list for NewGran_impl::NewGran_t ------------------------------------------------------

template <int NV>
using Position = parameter::chain<ranges::Identity, 
                                  parameter::plain<NewGran_impl::clone_cable3_t<NV>, 1>, 
                                  parameter::plain<NewGran_impl::clone_cable2_t<NV>, 1>, 
                                  parameter::plain<NewGran_impl::clone_cable1_t<NV>, 1>, 
                                  parameter::plain<NewGran_impl::clone_pack5_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(Pitch_3Range, 
                        -1., 
                        1.);

template <int NV>
using Pitch_3 = parameter::from0To1<NewGran_impl::clone_cable8_t<NV>, 
                                    1, 
                                    Pitch_3Range>;

template <int NV>
using Pitch = parameter::chain<ranges::Identity, 
                               parameter::plain<NewGran_impl::clone_cable7_t<NV>, 1>, 
                               parameter::plain<NewGran_impl::clone_cable9_t<NV>, 1>, 
                               parameter::plain<NewGran_impl::clone_cable10_t<NV>, 1>, 
                               Pitch_3<NV>>;

DECLARE_PARAMETER_RANGE(PitchMode_InputRange, 
                        0., 
                        3.);

template <int NV>
using PitchMode = parameter::chain<PitchMode_InputRange, 
                                   parameter::plain<NewGran_impl::clone_cable6_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(DensityRange, 
                        0., 
                        0.8);

using Density = parameter::from0To1<NewGran_impl::clone_cable19_t, 
                                    1, 
                                    DensityRange>;

template <int NV>
using max = parameter::chain<ranges::Identity, 
                             parameter::plain<NewGran_impl::clone_cable3_t<NV>, 2>, 
                             parameter::plain<NewGran_impl::clone_cable2_t<NV>, 2>, 
                             parameter::plain<NewGran_impl::clone_cable1_t<NV>, 2>>;

template <int NV>
using step = parameter::chain<ranges::Identity, 
                              parameter::plain<NewGran_impl::clone_cable8_t<NV>, 2>, 
                              parameter::plain<NewGran_impl::clone_cable10_t<NV>, 2>, 
                              parameter::plain<NewGran_impl::clone_cable9_t<NV>, 2>, 
                              parameter::plain<NewGran_impl::clone_cable7_t<NV>, 2>>;

template <int NV>
using PositionMode = parameter::plain<NewGran_impl::clone_cable_t<NV>, 
                                      1>;
template <int NV>
using PitchMul = parameter::plain<NewGran_impl::clone_forward_t<NV>, 
                                  1>;
template <int NV>
using Grain = parameter::plain<NewGran_impl::clone_cable18_t<NV>, 
                               1>;
using Spread = parameter::plain<NewGran_impl::clone_cable26_t, 
                                1>;
using Detune = parameter::plain<NewGran_impl::clone_cable25_t, 
                                1>;
using min = parameter::empty;
using SyNc = parameter::plain<NewGran_impl::clone_cable5_t, 
                              1>;
template <int NV>
using NewGran_t_plist = parameter::list<Position<NV>, 
                                        PositionMode<NV>, 
                                        Pitch<NV>, 
                                        PitchMul<NV>, 
                                        PitchMode<NV>, 
                                        Grain<NV>, 
                                        Spread, 
                                        Detune, 
                                        Density, 
                                        min, 
                                        max<NV>, 
                                        step<NV>, 
                                        SyNc>;
}

template <int NV>
using NewGran_t_ = container::chain<NewGran_t_parameters::NewGran_t_plist<NV>, 
                                    wrap::fix<2, chain6_t>, 
                                    split9_t, 
                                    pos_t<NV>, 
                                    cables_t<NV>, 
                                    pitch_t<NV>, 
                                    midichain_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public NewGran_impl::NewGran_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 8;
		static const int NumSliderPacks = 5;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(NewGran);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(210)
		{
			0x005B, 0x0000, 0x5000, 0x736F, 0x7469, 0x6F69, 0x006E, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x012B, 0x3E3D, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x015B, 0x0000, 0x5000, 0x736F, 0x7469, 0x6F69, 0x4D6E, 
            0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x99F2, 0x3F05, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x5000, 0x7469, 
            0x6863, 0x0000, 0x0000, 0x0000, 0x8000, 0x183F, 0x84F2, 0x003E, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 0x0000, 0x6950, 0x6374, 
            0x4D68, 0x6C75, 0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0004, 0x0000, 0x6950, 
            0x6374, 0x4D68, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x4040, 
            0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 
            0x4700, 0x6172, 0x6E69, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 
            0x7053, 0x6572, 0x6461, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 0x0000, 
            0x6544, 0x7574, 0x656E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0008, 0x0000, 
            0x6544, 0x736E, 0x7469, 0x0079, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x095B, 0x0000, 
            0x6D00, 0x6E69, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000A, 0x0000, 0x616D, 
            0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0B5B, 0x0000, 0x7300, 0x6574, 0x0070, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0C5B, 0x0000, 0x5300, 0x4E79, 0x0063, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain6 = this->getT(0);                                                       // NewGran_impl::chain6_t
		auto& split2 = this->getT(0).getT(0);                                               // NewGran_impl::split2_t
		auto& pack4_writer = this->getT(0).getT(0).getT(0);                                 // NewGran_impl::pack4_writer_t
		auto& pack4_writer1 = this->getT(0).getT(0).getT(1);                                // NewGran_impl::pack4_writer1_t
		auto& pack4_writer2 = this->getT(0).getT(0).getT(2);                                // NewGran_impl::pack4_writer2_t
		auto& pack4_writer4 = this->getT(0).getT(0).getT(3);                                // NewGran_impl::pack4_writer4_t
		auto& split9 = this->getT(1);                                                       // NewGran_impl::split9_t
		auto& clone_pack = this->getT(1).getT(0);                                           // NewGran_impl::clone_pack_t
		auto& clone_pack3 = this->getT(1).getT(1);                                          // NewGran_impl::clone_pack3_t
		auto& clone_pack2 = this->getT(1).getT(2);                                          // NewGran_impl::clone_pack2_t
		auto& clone_pack1 = this->getT(1).getT(3);                                          // NewGran_impl::clone_pack1_t
		auto& pos = this->getT(2);                                                          // NewGran_impl::pos_t<NV>
		auto& clone_cable = this->getT(2).getT(0);                                          // NewGran_impl::clone_cable_t<NV>
		auto& clone_cable3 = this->getT(2).getT(1);                                         // NewGran_impl::clone_cable3_t<NV>
		auto& clone_cable2 = this->getT(2).getT(2);                                         // NewGran_impl::clone_cable2_t<NV>
		auto& clone_cable1 = this->getT(2).getT(3);                                         // NewGran_impl::clone_cable1_t<NV>
		auto& clone_pack5 = this->getT(2).getT(4);                                          // NewGran_impl::clone_pack5_t<NV>
		auto& cables = this->getT(3);                                                       // NewGran_impl::cables_t<NV>
		auto& split11 = this->getT(3).getT(0);                                              // NewGran_impl::split11_t<NV>
		auto& clone_cable18 = this->getT(3).getT(0).getT(0);                                // NewGran_impl::clone_cable18_t<NV>
		auto& clone_cable21 = this->getT(3).getT(0).getT(1);                                // control::clone_cable<parameter::empty>
		auto& clone_cable20 = this->getT(3).getT(0).getT(2);                                // control::clone_cable<parameter::empty>
		auto& clone_cable19 = this->getT(3).getT(0).getT(3);                                // NewGran_impl::clone_cable19_t
		auto& clone_cable26 = this->getT(3).getT(0).getT(4);                                // NewGran_impl::clone_cable26_t
		auto& clone_cable25 = this->getT(3).getT(0).getT(5);                                // NewGran_impl::clone_cable25_t
		auto& pitch = this->getT(4);                                                        // NewGran_impl::pitch_t<NV>
		auto& clone_cable6 = this->getT(4).getT(0);                                         // NewGran_impl::clone_cable6_t<NV>
		auto& clone_cable7 = this->getT(4).getT(1);                                         // NewGran_impl::clone_cable7_t<NV>
		auto& clone_cable9 = this->getT(4).getT(2);                                         // NewGran_impl::clone_cable9_t<NV>
		auto& clone_cable10 = this->getT(4).getT(3);                                        // NewGran_impl::clone_cable10_t<NV>
		auto& clone_cable8 = this->getT(4).getT(4);                                         // NewGran_impl::clone_cable8_t<NV>
		auto& clone_forward = this->getT(4).getT(5);                                        // NewGran_impl::clone_forward_t<NV>
		auto& clone_cable5 = this->getT(4).getT(6);                                         // NewGran_impl::clone_cable5_t
		auto& midichain = this->getT(5);                                                    // NewGran_impl::midichain_t<NV>
		auto& clone = this->getT(5).getT(0);                                                // NewGran_impl::clone_t<NV>                                                // NewGran_impl::clone_child_t<NV>
		auto split = this->getT(5).getT(0).getT(0);                                         // NewGran_impl::split_t<NV>
		auto FourWaySwitch = this->getT(5).getT(0).getT(0).getT(0);                         // NewGran_impl::FourWaySwitch_t<NV>
		auto cable_table105 = this->getT(5).getT(0).getT(0).getT(0).getT(0);                // NewGran_impl::cable_table105_t<NV>
		auto cable_table107 = this->getT(5).getT(0).getT(0).getT(0).getT(1);                // NewGran_impl::cable_table107_t<NV>
		auto cable_table106 = this->getT(5).getT(0).getT(0).getT(0).getT(2);                // NewGran_impl::cable_table106_t<NV>
		auto split72 = this->getT(5).getT(0).getT(0).getT(0).getT(3);                       // NewGran_impl::split72_t<NV>
		auto input_toggle106 = this->getT(5).getT(0).getT(0).getT(0).getT(3).getT(0);       // NewGran_impl::input_toggle106_t<NV>
		auto input_toggle108 = this->getT(5).getT(0).getT(0).getT(0).getT(3).getT(1);       // NewGran_impl::input_toggle108_t<NV>
		auto input_toggle107 = this->getT(5).getT(0).getT(0).getT(0).getT(3).getT(2);       // NewGran_impl::input_toggle107_t<NV>
		auto FourWaySwitch1 = this->getT(5).getT(0).getT(0).getT(1);                        // NewGran_impl::FourWaySwitch1_t<NV>
		auto cable_table108 = this->getT(5).getT(0).getT(0).getT(1).getT(0);                // NewGran_impl::cable_table108_t<NV>
		auto cable_table109 = this->getT(5).getT(0).getT(0).getT(1).getT(1);                // NewGran_impl::cable_table109_t<NV>
		auto cable_table110 = this->getT(5).getT(0).getT(0).getT(1).getT(2);                // NewGran_impl::cable_table110_t<NV>
		auto split73 = this->getT(5).getT(0).getT(0).getT(1).getT(3);                       // NewGran_impl::split73_t<NV>
		auto input_toggle109 = this->getT(5).getT(0).getT(0).getT(1).getT(3).getT(0);       // NewGran_impl::input_toggle109_t<NV>
		auto input_toggle110 = this->getT(5).getT(0).getT(0).getT(1).getT(3).getT(1);       // NewGran_impl::input_toggle110_t<NV>
		auto input_toggle111 = this->getT(5).getT(0).getT(0).getT(1).getT(3).getT(2);       // NewGran_impl::input_toggle111_t<NV>
		auto split8 = this->getT(5).getT(0).getT(1);                                        // NewGran_impl::split8_t
		auto chain = this->getT(5).getT(0).getT(1).getT(0);                                 // NewGran_impl::chain_t
		auto input_toggle = this->getT(5).getT(0).getT(1).getT(0).getT(0);                  // NewGran_impl::input_toggle_t
		auto cable_table = this->getT(5).getT(0).getT(1).getT(0).getT(1);                   // NewGran_impl::cable_table_t
		auto chain3 = this->getT(5).getT(0).getT(1).getT(1);                                // NewGran_impl::chain3_t
		auto input_toggle3 = this->getT(5).getT(0).getT(1).getT(1).getT(0);                 // NewGran_impl::input_toggle3_t
		auto cable_table3 = this->getT(5).getT(0).getT(1).getT(1).getT(1);                  // NewGran_impl::cable_table3_t
		auto chain2 = this->getT(5).getT(0).getT(1).getT(2);                                // NewGran_impl::chain2_t
		auto input_toggle2 = this->getT(5).getT(0).getT(1).getT(2).getT(0);                 // NewGran_impl::input_toggle2_t
		auto cable_table2 = this->getT(5).getT(0).getT(1).getT(2).getT(1);                  // NewGran_impl::cable_table2_t
		auto chain1 = this->getT(5).getT(0).getT(1).getT(3);                                // NewGran_impl::chain1_t
		auto input_toggle1 = this->getT(5).getT(0).getT(1).getT(3).getT(0);                 // NewGran_impl::input_toggle1_t
		auto cable_table1 = this->getT(5).getT(0).getT(1).getT(3).getT(1);                  // NewGran_impl::cable_table1_t
		auto split16 = this->getT(5).getT(0).getT(2);                                       // NewGran_impl::split16_t
		auto chain24 = this->getT(5).getT(0).getT(2).getT(0);                               // NewGran_impl::chain24_t
		auto input_toggle16 = this->getT(5).getT(0).getT(2).getT(0).getT(0);                // NewGran_impl::input_toggle16_t
		auto cable_table16 = this->getT(5).getT(0).getT(2).getT(0).getT(1);                 // NewGran_impl::cable_table16_t
		auto chain26 = this->getT(5).getT(0).getT(2).getT(1);                               // NewGran_impl::chain26_t
		auto input_toggle18 = this->getT(5).getT(0).getT(2).getT(1).getT(0);                // NewGran_impl::input_toggle18_t
		auto cable_table18 = this->getT(5).getT(0).getT(2).getT(1).getT(1);                 // NewGran_impl::cable_table18_t
		auto chain25 = this->getT(5).getT(0).getT(2).getT(2);                               // NewGran_impl::chain25_t
		auto input_toggle17 = this->getT(5).getT(0).getT(2).getT(2).getT(0);                // NewGran_impl::input_toggle17_t
		auto cable_table17 = this->getT(5).getT(0).getT(2).getT(2).getT(1);                 // NewGran_impl::cable_table17_t
		auto chain27 = this->getT(5).getT(0).getT(2).getT(3);                               // NewGran_impl::chain27_t
		auto input_toggle19 = this->getT(5).getT(0).getT(2).getT(3).getT(0);                // NewGran_impl::input_toggle19_t
		auto cable_table19 = this->getT(5).getT(0).getT(2).getT(3).getT(1);                 // NewGran_impl::cable_table19_t
		auto split1 = this->getT(5).getT(0).getT(3);                                        // NewGran_impl::split1_t<NV>
		auto chain4 = this->getT(5).getT(0).getT(3).getT(0);                                // NewGran_impl::chain4_t<NV>
		auto split15 = this->getT(5).getT(0).getT(3).getT(0).getT(0);                       // NewGran_impl::split15_t<NV>
		auto chain5 = this->getT(5).getT(0).getT(3).getT(0).getT(0).getT(0);                // NewGran_impl::chain5_t<NV>
		auto pma_unscaled = this->getT(5).getT(0).getT(3).getT(0).getT(0).getT(0).getT(0);  // NewGran_impl::pma_unscaled_t<NV>
		auto chain22 = this->getT(5).getT(0).getT(3).getT(0).getT(0).getT(1);               // NewGran_impl::chain22_t<NV>
		auto pma_unscaled1 = this->getT(5).getT(0).getT(3).getT(0).getT(0).getT(1).getT(0); // NewGran_impl::pma_unscaled1_t<NV>
		auto tempo_sync = this->getT(5).getT(0).getT(3).getT(0).getT(1);                    // NewGran_impl::tempo_sync_t<NV>
		auto converter = this->getT(5).getT(0).getT(3).getT(0).getT(2);                     // control::converter<parameter::empty>
		auto converter8 = this->getT(5).getT(0).getT(3).getT(0).getT(3);                    // NewGran_impl::converter8_t
		auto input_toggle32 = this->getT(5).getT(0).getT(3).getT(0).getT(4);                // NewGran_impl::input_toggle32_t
		auto file_analyser = this->getT(5).getT(0).getT(4);                                 // NewGran_impl::file_analyser_t<NV>
		auto minmax = this->getT(5).getT(0).getT(5);                                        // NewGran_impl::minmax_t<NV>
		auto pma2 = this->getT(5).getT(0).getT(6);                                          // NewGran_impl::pma2_t<NV>
		auto granulator = this->getT(5).getT(0).getT(7);                                    // NewGran_impl::granulator_t
		auto gain = this->getT(5).getT(0).getT(8);                                          // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& Position_p = this->getParameterT(0);
		Position_p.connectT(0, clone_cable3); // Position -> clone_cable3::Value
		Position_p.connectT(1, clone_cable2); // Position -> clone_cable2::Value
		Position_p.connectT(2, clone_cable1); // Position -> clone_cable1::Value
		Position_p.connectT(3, clone_pack5);  // Position -> clone_pack5::Value
		
		this->getParameterT(1).connectT(0, clone_cable); // PositionMode -> clone_cable::Value
		
		auto& Pitch_p = this->getParameterT(2);
		Pitch_p.connectT(0, clone_cable7);  // Pitch -> clone_cable7::Value
		Pitch_p.connectT(1, clone_cable9);  // Pitch -> clone_cable9::Value
		Pitch_p.connectT(2, clone_cable10); // Pitch -> clone_cable10::Value
		Pitch_p.connectT(3, clone_cable8);  // Pitch -> clone_cable8::Value
		
		this->getParameterT(3).connectT(0, clone_forward); // PitchMul -> clone_forward::Value
		
		this->getParameterT(4).connectT(0, clone_cable6); // PitchMode -> clone_cable6::Value
		
		this->getParameterT(5).connectT(0, clone_cable18); // Grain -> clone_cable18::Value
		
		this->getParameterT(6).connectT(0, clone_cable26); // Spread -> clone_cable26::Value
		
		this->getParameterT(7).connectT(0, clone_cable25); // Detune -> clone_cable25::Value
		
		this->getParameterT(8).connectT(0, clone_cable19); // Density -> clone_cable19::Value
		
		auto& max_p = this->getParameterT(10);
		max_p.connectT(0, clone_cable3); // max -> clone_cable3::Gamma
		max_p.connectT(1, clone_cable2); // max -> clone_cable2::Gamma
		max_p.connectT(2, clone_cable1); // max -> clone_cable1::Gamma
		
		auto& step_p = this->getParameterT(11);
		step_p.connectT(0, clone_cable8);  // step -> clone_cable8::Gamma
		step_p.connectT(1, clone_cable10); // step -> clone_cable10::Gamma
		step_p.connectT(2, clone_cable9);  // step -> clone_cable9::Gamma
		step_p.connectT(3, clone_cable7);  // step -> clone_cable7::Gamma
		
		this->getParameterT(12).connectT(0, clone_cable5); // SyNc -> clone_cable5::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		input_toggle.getWrappedObject().getParameter().connectT(0, cable_table);        // input_toggle -> cable_table::Value
		input_toggle16.getWrappedObject().getParameter().connectT(0, cable_table16);    // input_toggle16 -> cable_table16::Value
		clone_pack.getWrappedObject().getParameter().connectT(0, input_toggle);         // clone_pack -> input_toggle::Input
		clone_pack.getWrappedObject().getParameter().connectT(1, input_toggle16);       // clone_pack -> input_toggle16::Input
		input_toggle3.getWrappedObject().getParameter().connectT(0, cable_table3);      // input_toggle3 -> cable_table3::Value
		input_toggle18.getWrappedObject().getParameter().connectT(0, cable_table18);    // input_toggle18 -> cable_table18::Value
		clone_pack3.getWrappedObject().getParameter().connectT(0, input_toggle3);       // clone_pack3 -> input_toggle3::Input
		clone_pack3.getWrappedObject().getParameter().connectT(1, input_toggle18);      // clone_pack3 -> input_toggle18::Input
		input_toggle2.getWrappedObject().getParameter().connectT(0, cable_table2);      // input_toggle2 -> cable_table2::Value
		input_toggle17.getWrappedObject().getParameter().connectT(0, cable_table17);    // input_toggle17 -> cable_table17::Value
		clone_pack2.getWrappedObject().getParameter().connectT(0, input_toggle2);       // clone_pack2 -> input_toggle2::Input
		clone_pack2.getWrappedObject().getParameter().connectT(1, input_toggle17);      // clone_pack2 -> input_toggle17::Input
		input_toggle1.getWrappedObject().getParameter().connectT(0, cable_table1);      // input_toggle1 -> cable_table1::Value
		input_toggle19.getWrappedObject().getParameter().connectT(0, cable_table19);    // input_toggle19 -> cable_table19::Value
		clone_pack1.getWrappedObject().getParameter().connectT(0, input_toggle1);       // clone_pack1 -> input_toggle1::Input
		clone_pack1.getWrappedObject().getParameter().connectT(1, input_toggle19);      // clone_pack1 -> input_toggle19::Input
		pma2.getWrappedObject().getParameter().connectT(0, granulator);                 // pma2 -> granulator::Position
		input_toggle108.getWrappedObject().getParameter().connectT(0, pma2);            // input_toggle108 -> pma2::Add
		input_toggle108.getWrappedObject().getParameter().connectT(1, input_toggle);    // input_toggle108 -> input_toggle::Value1
		input_toggle108.getWrappedObject().getParameter().connectT(2, input_toggle3);   // input_toggle108 -> input_toggle3::Value1
		input_toggle108.getWrappedObject().getParameter().connectT(3, input_toggle2);   // input_toggle108 -> input_toggle2::Value1
		input_toggle108.getWrappedObject().getParameter().connectT(4, input_toggle1);   // input_toggle108 -> input_toggle1::Value1
		input_toggle106.getWrappedObject().getParameter().connectT(0, input_toggle108); // input_toggle106 -> input_toggle108::Value1
		cable_table105.getWrappedObject().getParameter().connectT(0, input_toggle106);  // cable_table105 -> input_toggle106::Input
		cable_table107.getWrappedObject().getParameter().connectT(0, input_toggle108);  // cable_table107 -> input_toggle108::Input
		input_toggle107.getWrappedObject().getParameter().connectT(0, input_toggle108); // input_toggle107 -> input_toggle108::Value2
		cable_table106.getWrappedObject().getParameter().connectT(0, input_toggle107);  // cable_table106 -> input_toggle107::Input
		clone_cable.getWrappedObject().getParameter().connectT(0, cable_table105);      // clone_cable -> cable_table105::Value
		clone_cable.getWrappedObject().getParameter().connectT(1, cable_table107);      // clone_cable -> cable_table107::Value
		clone_cable.getWrappedObject().getParameter().connectT(2, cable_table106);      // clone_cable -> cable_table106::Value
		clone_cable3.getWrappedObject().getParameter().connectT(0, input_toggle106);    // clone_cable3 -> input_toggle106::Value1
		clone_cable2.getWrappedObject().getParameter().connectT(0, input_toggle106);    // clone_cable2 -> input_toggle106::Value2
		clone_cable1.getWrappedObject().getParameter().connectT(0, input_toggle107);    // clone_cable1 -> input_toggle107::Value1
		clone_pack5.getWrappedObject().getParameter().connectT(0, input_toggle107);     // clone_pack5 -> input_toggle107::Value2
		minmax.getWrappedObject().getParameter().connectT(0, granulator);               // minmax -> granulator::GrainSize
		clone_cable18.getWrappedObject().getParameter().connectT(0, minmax);            // clone_cable18 -> minmax::Value
		clone_cable19.getWrappedObject().getParameter().connectT(0, granulator);        // clone_cable19 -> granulator::Density
		clone_cable26.getWrappedObject().getParameter().connectT(0, granulator);        // clone_cable26 -> granulator::Spread
		clone_cable25.getWrappedObject().getParameter().connectT(0, granulator);        // clone_cable25 -> granulator::Detune
		input_toggle32.getWrappedObject().getParameter().connectT(0, granulator);       // input_toggle32 -> granulator::Pitch
		pma_unscaled.getWrappedObject().getParameter().connectT(0, input_toggle32);     // pma_unscaled -> input_toggle32::Value1
		tempo_sync.getParameter().connectT(0, converter);                               // tempo_sync -> converter::Value
		pma_unscaled1.getWrappedObject().getParameter().connectT(0, tempo_sync);        // pma_unscaled1 -> tempo_sync::Tempo
		input_toggle110.getWrappedObject().getParameter().connectT(0, input_toggle16);  // input_toggle110 -> input_toggle16::Value1
		input_toggle110.getWrappedObject().getParameter().connectT(1, input_toggle18);  // input_toggle110 -> input_toggle18::Value1
		input_toggle110.getWrappedObject().getParameter().connectT(2, input_toggle17);  // input_toggle110 -> input_toggle17::Value1
		input_toggle110.getWrappedObject().getParameter().connectT(3, input_toggle19);  // input_toggle110 -> input_toggle19::Value1
		input_toggle110.getWrappedObject().getParameter().connectT(4, pma_unscaled);    // input_toggle110 -> pma_unscaled::Add
		input_toggle110.getWrappedObject().getParameter().connectT(5, pma_unscaled1);   // input_toggle110 -> pma_unscaled1::Add
		input_toggle109.getWrappedObject().getParameter().connectT(0, input_toggle110); // input_toggle109 -> input_toggle110::Value1
		cable_table108.getWrappedObject().getParameter().connectT(0, input_toggle109);  // cable_table108 -> input_toggle109::Input
		cable_table109.getWrappedObject().getParameter().connectT(0, input_toggle110);  // cable_table109 -> input_toggle110::Input
		input_toggle111.getWrappedObject().getParameter().connectT(0, input_toggle110); // input_toggle111 -> input_toggle110::Value2
		cable_table110.getWrappedObject().getParameter().connectT(0, input_toggle111);  // cable_table110 -> input_toggle111::Input
		clone_cable6.getWrappedObject().getParameter().connectT(0, cable_table108);     // clone_cable6 -> cable_table108::Value
		clone_cable6.getWrappedObject().getParameter().connectT(1, cable_table109);     // clone_cable6 -> cable_table109::Value
		clone_cable6.getWrappedObject().getParameter().connectT(2, cable_table110);     // clone_cable6 -> cable_table110::Value
		clone_cable7.getWrappedObject().getParameter().connectT(0, input_toggle109);    // clone_cable7 -> input_toggle109::Value1
		clone_cable9.getWrappedObject().getParameter().connectT(0, input_toggle109);    // clone_cable9 -> input_toggle109::Value2
		clone_cable10.getWrappedObject().getParameter().connectT(0, input_toggle111);   // clone_cable10 -> input_toggle111::Value1
		clone_cable8.getWrappedObject().getParameter().connectT(0, input_toggle111);    // clone_cable8 -> input_toggle111::Value2
		clone_forward.getWrappedObject().getParameter().connectT(0, tempo_sync);        // clone_forward -> tempo_sync::Multiplier
		clone_cable5.getWrappedObject().getParameter().connectT(0, input_toggle32);     // clone_cable5 -> input_toggle32::Input
		converter8.getWrappedObject().getParameter().connectT(0, input_toggle32);       // converter8 -> input_toggle32::Value2
		file_analyser.getWrappedObject().getParameter().connectT(0, minmax);            // file_analyser -> minmax::Maximum
		
		// Default Values --------------------------------------------------------------------------
		
		pack4_writer.setParameterT(0, 0.); // control::pack4_writer::Value1
		pack4_writer.setParameterT(1, 1.); // control::pack4_writer::Value2
		pack4_writer.setParameterT(2, 1.); // control::pack4_writer::Value3
		pack4_writer.setParameterT(3, 1.); // control::pack4_writer::Value4
		
		pack4_writer1.setParameterT(0, 1.); // control::pack4_writer::Value1
		pack4_writer1.setParameterT(1, 0.); // control::pack4_writer::Value2
		pack4_writer1.setParameterT(2, 1.); // control::pack4_writer::Value3
		pack4_writer1.setParameterT(3, 1.); // control::pack4_writer::Value4
		
		pack4_writer2.setParameterT(0, 1.); // control::pack4_writer::Value1
		pack4_writer2.setParameterT(1, 1.); // control::pack4_writer::Value2
		pack4_writer2.setParameterT(2, 0.); // control::pack4_writer::Value3
		pack4_writer2.setParameterT(3, 1.); // control::pack4_writer::Value4
		
		pack4_writer4.setParameterT(0, 1.); // control::pack4_writer::Value1
		pack4_writer4.setParameterT(1, 1.); // control::pack4_writer::Value2
		pack4_writer4.setParameterT(2, 1.); // control::pack4_writer::Value3
		pack4_writer4.setParameterT(3, 0.); // control::pack4_writer::Value4
		
		clone_pack.setParameterT(0, 4.); // control::clone_pack::NumClones
		clone_pack.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack3.setParameterT(0, 4.); // control::clone_pack::NumClones
		clone_pack3.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack2.setParameterT(0, 4.); // control::clone_pack::NumClones
		clone_pack2.setParameterT(1, 1.); // control::clone_pack::Value
		
		clone_pack1.setParameterT(0, 4.); // control::clone_pack::NumClones
		clone_pack1.setParameterT(1, 1.); // control::clone_pack::Value
		
		;                                 // clone_cable::NumClones is deactivated
		;                                 // clone_cable::Value is automated
		clone_cable.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // clone_cable3::NumClones is deactivated
		; // clone_cable3::Value is automated
		; // clone_cable3::Gamma is automated
		
		; // clone_cable2::NumClones is deactivated
		; // clone_cable2::Value is automated
		; // clone_cable2::Gamma is automated
		
		; // clone_cable1::NumClones is deactivated
		; // clone_cable1::Value is automated
		; // clone_cable1::Gamma is automated
		
		clone_pack5.setParameterT(0, 4.); // control::clone_pack::NumClones
		;                                 // clone_pack5::Value is automated
		
		;                                   // clone_cable18::NumClones is deactivated
		;                                   // clone_cable18::Value is automated
		clone_cable18.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable21::NumClones is deactivated
		clone_cable21.setParameterT(1, 0.); // control::clone_cable::Value
		clone_cable21.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable20::NumClones is deactivated
		clone_cable20.setParameterT(1, 0.); // control::clone_cable::Value
		clone_cable20.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable19::NumClones is deactivated
		;                                   // clone_cable19::Value is automated
		clone_cable19.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable26::NumClones is deactivated
		;                                   // clone_cable26::Value is automated
		clone_cable26.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                   // clone_cable25::NumClones is deactivated
		;                                   // clone_cable25::Value is automated
		clone_cable25.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable6::NumClones is deactivated
		;                                  // clone_cable6::Value is automated
		clone_cable6.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		; // clone_cable7::NumClones is deactivated
		; // clone_cable7::Value is automated
		; // clone_cable7::Gamma is automated
		
		; // clone_cable9::NumClones is deactivated
		; // clone_cable9::Value is automated
		; // clone_cable9::Gamma is automated
		
		; // clone_cable10::NumClones is deactivated
		; // clone_cable10::Value is automated
		; // clone_cable10::Gamma is automated
		
		; // clone_cable8::NumClones is deactivated
		; // clone_cable8::Value is automated
		; // clone_cable8::Gamma is automated
		
		clone_forward.setParameterT(0, 4.); // control::clone_forward::NumClones
		;                                   // clone_forward::Value is automated
		
		;                                  // clone_cable5::NumClones is deactivated
		;                                  // clone_cable5::Value is automated
		clone_cable5.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone.setParameterT(0, 4.); // container::clone::NumClones
		clone.setParameterT(1, 1.); // container::clone::SplitSignal
		
		; // cable_table105::Value is automated
		
		; // cable_table107::Value is automated
		
		; // cable_table106::Value is automated
		
		; // input_toggle106::Input is automated
		; // input_toggle106::Value1 is automated
		; // input_toggle106::Value2 is automated
		
		; // input_toggle108::Input is automated
		; // input_toggle108::Value1 is automated
		; // input_toggle108::Value2 is automated
		
		; // input_toggle107::Input is automated
		; // input_toggle107::Value1 is automated
		; // input_toggle107::Value2 is automated
		
		; // cable_table108::Value is automated
		
		; // cable_table109::Value is automated
		
		; // cable_table110::Value is automated
		
		; // input_toggle109::Input is automated
		; // input_toggle109::Value1 is automated
		; // input_toggle109::Value2 is automated
		
		; // input_toggle110::Input is automated
		; // input_toggle110::Value1 is automated
		; // input_toggle110::Value2 is automated
		
		; // input_toggle111::Input is automated
		; // input_toggle111::Value1 is automated
		; // input_toggle111::Value2 is automated
		
		;                                  // input_toggle::Input is automated
		;                                  // input_toggle::Value1 is automated
		input_toggle.setParameterT(2, 0.); // control::input_toggle::Value2
		
		; // cable_table::Value is automated
		
		;                                   // input_toggle3::Input is automated
		;                                   // input_toggle3::Value1 is automated
		input_toggle3.setParameterT(2, 0.); // control::input_toggle::Value2
		
		; // cable_table3::Value is automated
		
		;                                   // input_toggle2::Input is automated
		;                                   // input_toggle2::Value1 is automated
		input_toggle2.setParameterT(2, 0.); // control::input_toggle::Value2
		
		; // cable_table2::Value is automated
		
		;                                   // input_toggle1::Input is automated
		;                                   // input_toggle1::Value1 is automated
		input_toggle1.setParameterT(2, 0.); // control::input_toggle::Value2
		
		; // cable_table1::Value is automated
		
		;                                    // input_toggle16::Input is automated
		;                                    // input_toggle16::Value1 is automated
		input_toggle16.setParameterT(2, 0.); // control::input_toggle::Value2
		
		; // cable_table16::Value is automated
		
		;                                    // input_toggle18::Input is automated
		;                                    // input_toggle18::Value1 is automated
		input_toggle18.setParameterT(2, 0.); // control::input_toggle::Value2
		
		; // cable_table18::Value is automated
		
		;                                    // input_toggle17::Input is automated
		;                                    // input_toggle17::Value1 is automated
		input_toggle17.setParameterT(2, 0.); // control::input_toggle::Value2
		
		; // cable_table17::Value is automated
		
		;                                    // input_toggle19::Input is automated
		;                                    // input_toggle19::Value1 is automated
		input_toggle19.setParameterT(2, 0.); // control::input_toggle::Value2
		
		; // cable_table19::Value is automated
		
		pma_unscaled.setParameterT(0, 0.); // control::pma_unscaled::Value
		pma_unscaled.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                  // pma_unscaled::Add is automated
		
		pma_unscaled1.setParameterT(0, 0.); // control::pma_unscaled::Value
		pma_unscaled1.setParameterT(1, 1.); // control::pma_unscaled::Multiply
		;                                   // pma_unscaled1::Add is automated
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 15.4); // control::tempo_sync::UnsyncedTime
		
		; // converter::Value is automated
		
		converter8.setParameterT(0, 1.); // control::converter::Value
		
		; // input_toggle32::Input is automated
		; // input_toggle32::Value1 is automated
		; // input_toggle32::Value2 is automated
		
		;                                  // minmax::Value is automated
		minmax.setParameterT(1, 0.);       // control::minmax::Minimum
		;                                  // minmax::Maximum is automated
		minmax.setParameterT(3, 0.381441); // control::minmax::Skew
		minmax.setParameterT(4, 0.500017); // control::minmax::Step
		minmax.setParameterT(5, 0.);       // control::minmax::Polarity
		
		pma2.setParameterT(0, 0.); // control::pma::Value
		pma2.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma2::Add is automated
		
		; // granulator::Position is automated
		; // granulator::Pitch is automated
		; // granulator::GrainSize is automated
		; // granulator::Density is automated
		; // granulator::Spread is automated
		; // granulator::Detune is automated
		
		gain.setParameterT(0, -6.3); // core::gain::Gain
		gain.setParameterT(1, 20.);  // core::gain::Smoothing
		gain.setParameterT(2, 0.);   // core::gain::ResetValue
		
		this->setParameterT(0, 0.184575);
		this->setParameterT(1, 0.52188);
		this->setParameterT(2, 0.25966);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 3.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 0.);
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
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).setExternalData(b, index);                 // NewGran_impl::pack4_writer_t
		this->getT(0).getT(0).getT(1).setExternalData(b, index);                 // NewGran_impl::pack4_writer1_t
		this->getT(0).getT(0).getT(2).setExternalData(b, index);                 // NewGran_impl::pack4_writer2_t
		this->getT(0).getT(0).getT(3).setExternalData(b, index);                 // NewGran_impl::pack4_writer4_t
		this->getT(1).getT(0).setExternalData(b, index);                         // NewGran_impl::clone_pack_t
		this->getT(1).getT(1).setExternalData(b, index);                         // NewGran_impl::clone_pack3_t
		this->getT(1).getT(2).setExternalData(b, index);                         // NewGran_impl::clone_pack2_t
		this->getT(1).getT(3).setExternalData(b, index);                         // NewGran_impl::clone_pack1_t
		this->getT(2).getT(4).setExternalData(b, index);                         // NewGran_impl::clone_pack5_t<NV>
		this->getT(5).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // NewGran_impl::cable_table105_t<NV>
		this->getT(5).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index); // NewGran_impl::cable_table107_t<NV>
		this->getT(5).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // NewGran_impl::cable_table106_t<NV>
		this->getT(5).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index); // NewGran_impl::cable_table108_t<NV>
		this->getT(5).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index); // NewGran_impl::cable_table109_t<NV>
		this->getT(5).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index); // NewGran_impl::cable_table110_t<NV>
		this->getT(5).getT(0).getT(1).getT(0).getT(1).setExternalData(b, index); // NewGran_impl::cable_table_t
		this->getT(5).getT(0).getT(1).getT(1).getT(1).setExternalData(b, index); // NewGran_impl::cable_table3_t
		this->getT(5).getT(0).getT(1).getT(2).getT(1).setExternalData(b, index); // NewGran_impl::cable_table2_t
		this->getT(5).getT(0).getT(1).getT(3).getT(1).setExternalData(b, index); // NewGran_impl::cable_table1_t
		this->getT(5).getT(0).getT(2).getT(0).getT(1).setExternalData(b, index); // NewGran_impl::cable_table16_t
		this->getT(5).getT(0).getT(2).getT(1).getT(1).setExternalData(b, index); // NewGran_impl::cable_table18_t
		this->getT(5).getT(0).getT(2).getT(2).getT(1).setExternalData(b, index); // NewGran_impl::cable_table17_t
		this->getT(5).getT(0).getT(2).getT(3).getT(1).setExternalData(b, index); // NewGran_impl::cable_table19_t
		this->getT(5).getT(0).getT(4).setExternalData(b, index);                 // NewGran_impl::file_analyser_t<NV>
		this->getT(5).getT(0).getT(7).setExternalData(b, index);                 // NewGran_impl::granulator_t
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
using NewGran = wrap::node<NewGran_impl::instance<NV>>;
}


