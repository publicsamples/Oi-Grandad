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
using stereo_frame_cable = cable::frame<NV, 2>;

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
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, frame2_block1_t<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fix8_block_t<NV>>>;

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

template <int NV>
using clone_cable1_t = control::clone_cable<parameter::cloned<parameter::plain<project::res2<NV>, 3>>, 
                                            duplilogic::fixed>;

template <int NV>
using clone_cable2_t = control::clone_cable<parameter::cloned<parameter::plain<project::res2<NV>, 0>>, 
                                            duplilogic::fixed>;

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

DECLARE_PARAMETER_RANGE_SKEW(ResPitch_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using ResPitch_0 = parameter::from0To1<filters::svf<NV>, 
                                       0, 
                                       ResPitch_0Range>;

template <int NV> using ResPitch_1 = ResPitch_0<NV>;

template <int NV> using ResPitch_2 = ResPitch_0<NV>;

template <int NV> using ResPitch_3 = ResPitch_0<NV>;

template <int NV>
using ResPitch_4 = parameter::from0To1<filters::svf_eq<NV>, 
                                       0, 
                                       ResPitch_0Range>;

template <int NV> using ResPitch_5 = ResPitch_4<NV>;

template <int NV>
using ResPitch_6 = parameter::from0To1<filters::allpass<NV>, 
                                       0, 
                                       ResPitch_0Range>;

template <int NV>
using ResPitch_7 = parameter::from0To1<jdsp::jdelay_cubic<NV>, 
                                       1, 
                                       sn_fin_impl::clone_cable_modRange>;

DECLARE_PARAMETER_RANGE(ResPitch_9Range, 
                        -1., 
                        1.);

template <int NV>
using ResPitch_9 = parameter::from0To1<sn_fin_impl::clone_cable_t<NV>, 
                                       1, 
                                       ResPitch_9Range>;

template <int NV>
using ResPitch = parameter::chain<ranges::Identity, 
                                  ResPitch_0<NV>, 
                                  ResPitch_1<NV>, 
                                  ResPitch_2<NV>, 
                                  ResPitch_3<NV>, 
                                  ResPitch_4<NV>, 
                                  ResPitch_5<NV>, 
                                  ResPitch_6<NV>, 
                                  ResPitch_7<NV>, 
                                  parameter::plain<fx::reverb, 2>, 
                                  ResPitch_9<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(ResLp_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using ResLp_0 = parameter::from0To1<filters::svf<NV>, 
                                    1, 
                                    ResLp_0Range>;

template <int NV> using ResLp_1 = ResLp_0<NV>;

template <int NV> using ResLp_2 = ResLp_0<NV>;

template <int NV> using ResLp_3 = ResLp_0<NV>;

template <int NV> using ResLp_4 = ResLp_0<NV>;

template <int NV> using ResLp_5 = ResLp_0<NV>;

template <int NV> using ResLp_6 = ResLp_0<NV>;

template <int NV> using ResLp_7 = ResLp_0<NV>;

template <int NV>
using ResLp_8 = parameter::from0To1<filters::svf_eq<NV>, 
                                    1, 
                                    ResLp_0Range>;

template <int NV> using ResLp_9 = ResLp_8<NV>;

template <int NV>
using ResLp_10 = parameter::from0To1<filters::allpass<NV>, 
                                     1, 
                                     ResLp_0Range>;

template <int NV>
using ResLp_11 = parameter::from0To1<filters::one_pole<NV>, 
                                     1, 
                                     ResLp_0Range>;

template <int NV>
using ResLp_12 = parameter::from0To1<filters::one_pole<NV>, 
                                     0, 
                                     ResPitch_0Range>;

template <int NV>
using ResLp = parameter::chain<ranges::Identity, 
                               ResLp_0<NV>, 
                               ResLp_1<NV>, 
                               ResLp_2<NV>, 
                               ResLp_3<NV>, 
                               ResLp_4<NV>, 
                               ResLp_5<NV>, 
                               ResLp_6<NV>, 
                               ResLp_7<NV>, 
                               ResLp_8<NV>, 
                               ResLp_9<NV>, 
                               ResLp_10<NV>, 
                               ResLp_11<NV>, 
                               ResLp_12<NV>, 
                               parameter::plain<sn_fin_impl::clone_cable1_t<NV>, 1>, 
                               parameter::plain<fx::reverb, 0>>;

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

template <int NV> using Meta_0 = ResPitch_0<NV>;

template <int NV> using Meta_1 = ResPitch_0<NV>;

DECLARE_PARAMETER_RANGE_STEP(Meta_2Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using Meta_2 = parameter::from0To1<filters::svf<NV>, 
                                   4, 
                                   Meta_2Range>;

template <int NV> using Meta_3 = ResPitch_0<NV>;

template <int NV> using Meta_4 = ResPitch_0<NV>;

DECLARE_PARAMETER_RANGE_SKEW(Meta_5Range, 
                             50., 
                             20000., 
                             0.229905);

template <int NV>
using Meta_5 = parameter::from0To1<filters::one_pole<NV>, 
                                   0, 
                                   Meta_5Range>;

template <int NV>
using Meta = parameter::chain<ranges::Identity, 
                              Meta_0<NV>, 
                              Meta_1<NV>, 
                              Meta_2<NV>, 
                              Meta_3<NV>, 
                              Meta_4<NV>, 
                              Meta_5<NV>, 
                              parameter::plain<sn_fin_impl::clone_cable2_t<NV>, 1>, 
                              parameter::plain<fx::reverb, 1>, 
                              parameter::plain<routing::receive<NV, stereo_frame_cable<NV>>, 0>>;

template <int NV>
using ResoMix = parameter::plain<sn_fin_impl::xfader_t<NV>, 
                                 0>;
template <int NV>
using sn_fin_t_plist = parameter::list<ResoMix<NV>, 
                                       ResPitch<NV>, 
                                       ResLp<NV>, 
                                       delMode<NV>, 
                                       Meta<NV>>;
}

template <int NV>
using sn_fin_t_ = container::chain<sn_fin_t_parameters::sn_fin_t_plist<NV>, 
                                   wrap::fix<2, xfader_t<NV>>, 
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
		SNEX_METADATA_ENCODED_PARAMETERS(86)
		{
			0x005C, 0x0000, 0x0000, 0x6552, 0x6F73, 0x694D, 0x0078, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x0100, 0x0000, 0x5200, 0x7365, 0x6950, 0x6374, 
            0x0068, 0x0000, 0x0000, 0x0000, 0x8000, 0xDF3F, 0x50F4, 0x003E, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x0200, 0x0000, 0x5200, 0x7365, 
            0x704C, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0003, 0x0000, 0x6564, 
            0x4D6C, 0x646F, 0x0065, 0x0000, 0x8000, 0x003F, 0x3000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0400, 0x0000, 
            0x4D00, 0x7465, 0x0061, 0x0000, 0x0000, 0x0000, 0x8000, 0x9C3F, 
            0x6BDE, 0x003F, 0x8000, 0x003F, 0x0000, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(2)
		{
			0x3D3B, 0x003E
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& xfader = this->getT(0);                                                        // sn_fin_impl::xfader_t<NV>
		auto& chain16 = this->getT(1);                                                       // sn_fin_impl::chain16_t<NV>
		auto& split1 = this->getT(1).getT(0);                                                // sn_fin_impl::split1_t<NV>
		auto& chain22 = this->getT(1).getT(0).getT(0);                                       // sn_fin_impl::chain22_t<NV>
		auto& gain = this->getT(1).getT(0).getT(0).getT(0);                                  // core::gain<NV>
		auto& chain19 = this->getT(1).getT(0).getT(1);                                       // sn_fin_impl::chain19_t<NV>
		auto& branch1 = this->getT(1).getT(0).getT(1).getT(0);                               // sn_fin_impl::branch1_t<NV>
		auto& chain20 = this->getT(1).getT(0).getT(1).getT(0).getT(0);                       // sn_fin_impl::chain20_t
		auto& chain38 = this->getT(1).getT(0).getT(1).getT(0).getT(1);                       // sn_fin_impl::chain38_t<NV>
		auto& chain1 = this->getT(1).getT(0).getT(1).getT(0).getT(1).getT(0);                // sn_fin_impl::chain1_t<NV>
		auto& svf = this->getT(1).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0);           // filters::svf<NV>
		auto& svf1 = this->getT(1).getT(0).getT(1).getT(0).getT(1).getT(0).getT(1);          // filters::svf<NV>
		auto& chain43 = this->getT(1).getT(0).getT(1).getT(0).getT(2);                       // sn_fin_impl::chain43_t<NV>
		auto& svf5 = this->getT(1).getT(0).getT(1).getT(0).getT(2).getT(0);                  // filters::svf<NV>
		auto& svf7 = this->getT(1).getT(0).getT(1).getT(0).getT(2).getT(1);                  // filters::svf<NV>
		auto& chain40 = this->getT(1).getT(0).getT(1).getT(0).getT(3);                       // sn_fin_impl::chain40_t<NV>
		auto& svf4 = this->getT(1).getT(0).getT(1).getT(0).getT(3).getT(0);                  // filters::svf<NV>
		auto& svf8 = this->getT(1).getT(0).getT(1).getT(0).getT(3).getT(1);                  // filters::svf<NV>
		auto& chain39 = this->getT(1).getT(0).getT(1).getT(0).getT(4);                       // sn_fin_impl::chain39_t<NV>
		auto& svf3 = this->getT(1).getT(0).getT(1).getT(0).getT(4).getT(0);                  // filters::svf<NV>
		auto& svf9 = this->getT(1).getT(0).getT(1).getT(0).getT(4).getT(1);                  // filters::svf<NV>
		auto& chain41 = this->getT(1).getT(0).getT(1).getT(0).getT(5);                       // sn_fin_impl::chain41_t<NV>
		auto& svf_eq1 = this->getT(1).getT(0).getT(1).getT(0).getT(5).getT(0);               // filters::svf_eq<NV>
		auto& chain42 = this->getT(1).getT(0).getT(1).getT(0).getT(6);                       // sn_fin_impl::chain42_t<NV>
		auto& svf_eq2 = this->getT(1).getT(0).getT(1).getT(0).getT(6).getT(0);               // filters::svf_eq<NV>
		auto& frame2_block2 = this->getT(1).getT(0).getT(1).getT(0).getT(7);                 // sn_fin_impl::frame2_block2_t<NV>
		auto& allpass = this->getT(1).getT(0).getT(1).getT(0).getT(7).getT(0);               // filters::allpass<NV>
		auto& one_pole4 = this->getT(1).getT(0).getT(1).getT(0).getT(7).getT(1);             // filters::one_pole<NV>
		auto& chain18 = this->getT(1).getT(0).getT(1).getT(0).getT(8);                       // sn_fin_impl::chain18_t<NV>
		auto& fix8_block = this->getT(1).getT(0).getT(1).getT(0).getT(8).getT(0);            // sn_fin_impl::fix8_block_t<NV>
		auto& frame2_block1 = this->getT(1).getT(0).getT(1).getT(0).getT(8).getT(0).getT(0); // sn_fin_impl::frame2_block1_t<NV>
		auto& receive = this->getT(1).getT(0).getT(1).getT(0).                               // routing::receive<NV, stereo_frame_cable<NV>>
                        getT(8).getT(0).getT(0).getT(0);
		auto& jdelay_cubic = this->getT(1).getT(0).getT(1).getT(0).                 // jdsp::jdelay_cubic<NV>
                             getT(8).getT(0).getT(0).getT(1);
		auto& one_pole5 = this->getT(1).getT(0).getT(1).getT(0).                    // filters::one_pole<NV>
                          getT(8).getT(0).getT(0).getT(2);
		auto& send = this->getT(1).getT(0).getT(1).getT(0).                         // routing::send<NV, stereo_frame_cable<NV>>
                     getT(8).getT(0).getT(0).getT(3);
		auto& one_pole3 = this->getT(1).getT(0).getT(1).getT(0).                    // filters::one_pole<NV>
                          getT(8).getT(0).getT(0).getT(4);
		auto& chain17 = this->getT(1).getT(0).getT(1).getT(0).getT(9);              // sn_fin_impl::chain17_t<NV>
		auto& clone_cable = this->getT(1).getT(0).getT(1).getT(0).getT(9).getT(0);  // sn_fin_impl::clone_cable_t<NV>
		auto& clone_cable1 = this->getT(1).getT(0).getT(1).getT(0).getT(9).getT(1); // sn_fin_impl::clone_cable1_t<NV>
		auto& clone_cable2 = this->getT(1).getT(0).getT(1).getT(0).getT(9).getT(2); // sn_fin_impl::clone_cable2_t<NV>
		auto& clone = this->getT(1).getT(0).getT(1).getT(0).getT(9).getT(3);        // sn_fin_impl::clone_t<NV>        // sn_fin_impl::clone_child_t<NV>
		auto res2 = this->getT(1).getT(0).getT(1).getT(0).getT(9).getT(3).getT(0);  // project::res2<NV>
		auto gain2 = this->getT(1).getT(0).getT(1).getT(0).getT(9).getT(3).getT(1); // core::gain<NV>
		auto& one_pole2 = this->getT(1).getT(0).getT(1).getT(0).getT(9).getT(4);    // filters::one_pole<NV>
		auto& chain = this->getT(1).getT(0).getT(1).getT(0).getT(10);               // sn_fin_impl::chain_t
		auto& reverb = this->getT(1).getT(0).getT(1).getT(0).getT(10).getT(0);      // fx::reverb
		auto& gain1 = this->getT(1).getT(0).getT(1).getT(1);                        // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, xfader); // ResoMix -> xfader::Value
		
		auto& ResPitch_p = this->getParameterT(1);
		ResPitch_p.connectT(0, svf);          // ResPitch -> svf::Frequency
		ResPitch_p.connectT(1, svf5);         // ResPitch -> svf5::Frequency
		ResPitch_p.connectT(2, svf4);         // ResPitch -> svf4::Frequency
		ResPitch_p.connectT(3, svf3);         // ResPitch -> svf3::Frequency
		ResPitch_p.connectT(4, svf_eq1);      // ResPitch -> svf_eq1::Frequency
		ResPitch_p.connectT(5, svf_eq2);      // ResPitch -> svf_eq2::Frequency
		ResPitch_p.connectT(6, allpass);      // ResPitch -> allpass::Frequency
		ResPitch_p.connectT(7, jdelay_cubic); // ResPitch -> jdelay_cubic::DelayTime
		ResPitch_p.connectT(8, reverb);       // ResPitch -> reverb::Size
		ResPitch_p.connectT(9, clone_cable);  // ResPitch -> clone_cable::Value
		
		auto& ResLp_p = this->getParameterT(2);
		ResLp_p.connectT(0, svf);           // ResLp -> svf::Q
		ResLp_p.connectT(1, svf1);          // ResLp -> svf1::Q
		ResLp_p.connectT(2, svf5);          // ResLp -> svf5::Q
		ResLp_p.connectT(3, svf7);          // ResLp -> svf7::Q
		ResLp_p.connectT(4, svf4);          // ResLp -> svf4::Q
		ResLp_p.connectT(5, svf8);          // ResLp -> svf8::Q
		ResLp_p.connectT(6, svf3);          // ResLp -> svf3::Q
		ResLp_p.connectT(7, svf9);          // ResLp -> svf9::Q
		ResLp_p.connectT(8, svf_eq1);       // ResLp -> svf_eq1::Q
		ResLp_p.connectT(9, svf_eq2);       // ResLp -> svf_eq2::Q
		ResLp_p.connectT(10, allpass);      // ResLp -> allpass::Q
		ResLp_p.connectT(11, one_pole4);    // ResLp -> one_pole4::Q
		ResLp_p.connectT(12, one_pole5);    // ResLp -> one_pole5::Frequency
		ResLp_p.connectT(13, clone_cable1); // ResLp -> clone_cable1::Value
		ResLp_p.connectT(14, reverb);       // ResLp -> reverb::Damping
		
		this->getParameterT(3).connectT(0, branch1); // delMode -> branch1::Index
		
		auto& Meta_p = this->getParameterT(4);
		Meta_p.connectT(0, svf1);         // Meta -> svf1::Frequency
		Meta_p.connectT(1, svf7);         // Meta -> svf7::Frequency
		Meta_p.connectT(2, svf5);         // Meta -> svf5::Mode
		Meta_p.connectT(3, svf8);         // Meta -> svf8::Frequency
		Meta_p.connectT(4, svf9);         // Meta -> svf9::Frequency
		Meta_p.connectT(5, one_pole4);    // Meta -> one_pole4::Frequency
		Meta_p.connectT(6, clone_cable2); // Meta -> clone_cable2::Value
		Meta_p.connectT(7, reverb);       // Meta -> reverb::Width
		Meta_p.connectT(8, receive);      // Meta -> receive::Feedback
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                      // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);                     // xfader -> gain1::Gain
		clone_cable.getWrappedObject().getParameter().connectT(0, res2);  // clone_cable -> res2::DELAY
		clone_cable1.getWrappedObject().getParameter().connectT(0, res2); // clone_cable1 -> res2::lp
		clone_cable2.getWrappedObject().getParameter().connectT(0, res2); // clone_cable2 -> res2::FB
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		
		// Default Values --------------------------------------------------------------------------
		
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
		;                            // svf5::Mode is automated
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
		svf_eq1.setParameterT(2, 0.);   // filters::svf_eq::Gain
		svf_eq1.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq1.setParameterT(4, 2.);   // filters::svf_eq::Mode
		svf_eq1.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		;                               // svf_eq2::Frequency is automated
		;                               // svf_eq2::Q is automated
		svf_eq2.setParameterT(2, 0.);   // filters::svf_eq::Gain
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
		;                                 // one_pole4::Q is automated
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
		
		one_pole3.setParameterT(0, 25.);  // filters::one_pole::Frequency
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
		this->setParameterT(1, 0.204059);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.921365);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
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


