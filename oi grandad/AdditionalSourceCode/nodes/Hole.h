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

namespace Hole_impl
{
// ===================| Node & Parameter type declarations |===================

namespace Hole_t_parameters
{
// Parameter list for Hole_impl::Hole_t --------------------------------------

template <int NV>
using feed = parameter::plain<project::greyhole<NV>, 4>;
template <int NV>
using size = parameter::plain<project::greyhole<NV>, 2>;
template <int NV>
using diff = parameter::plain<project::greyhole<NV>, 3>;
template <int NV>
using damp = parameter::plain<project::greyhole<NV>, 1>;
template <int NV>
using Hole_t_plist = parameter::list<feed<NV>, 
                                     size<NV>, 
                                     diff<NV>, 
                                     damp<NV>>;
}

template <int NV>
using Hole_t_ = container::chain<Hole_t_parameters::Hole_t_plist<NV>, 
                                 wrap::fix<2, project::greyhole<NV>>>;

// ======================| Root node initialiser class |======================

template <int NV> struct instance: public Hole_impl::Hole_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Hole);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(62)
		{
			0x005B, 0x0000, 0x6600, 0x6565, 0x0064, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0xD70A, 0x3C23, 0x015B, 
            0x0000, 0x7300, 0x7A69, 0x0065, 0x0000, 0x3F00, 0x0000, 0x4040, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0xB717, 0x38D1, 0x025B, 0x0000, 
            0x6400, 0x6669, 0x0066, 0x0000, 0x0000, 0x70A4, 0x3F7D, 0x7319, 
            0x3F57, 0x0000, 0x3F80, 0xB717, 0x38D1, 0x035B, 0x0000, 0x6400, 
            0x6D61, 0x0070, 0x0000, 0x0000, 0x70A4, 0x3F7D, 0x70A4, 0x3F7D, 
            0x0000, 0x3F80, 0x126F, 0x3A83, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References ---------------------------------------------------
		
		auto& faust = this->getT(0); // project::greyhole<NV>
		
		// Parameter Connections ---------------------------------------------
		
		this->getParameterT(0).connectT(0, faust); // feed -> faust::feedback
		
		this->getParameterT(1).connectT(0, faust); // size -> faust::size
		
		this->getParameterT(2).connectT(0, faust); // diff -> faust::diffusion
		
		this->getParameterT(3).connectT(0, faust); // damp -> faust::damping
		
		// Default Values ----------------------------------------------------
		
		faust.setParameterT(0, 0.001); // core::faust::delayTime
		;                              // faust::damping is automated
		;                              // faust::size is automated
		;                              // faust::diffusion is automated
		;                              // faust::feedback is automated
		faust.setParameterT(5, 0.);    // core::faust::modDepth
		faust.setParameterT(6, 0.);    // core::faust::modFreq
		
		this->setParameterT(0, 1);
		this->setParameterT(1, 1);
		this->setParameterT(2, 0.8416);
		this->setParameterT(3, 0.99);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ===========================| Public Definition |===========================

namespace project
{
// polyphonic template declaration

template <int NV>
using Hole = wrap::node<Hole_impl::instance<NV>>;
}


