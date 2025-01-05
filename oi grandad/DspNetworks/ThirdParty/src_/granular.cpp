/* ------------------------------------------------------------
name: "granular"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _granular -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___granular_H__
#define  ___granular_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _granular
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

struct _granularSIG0 {
	
	int getNumInputs_granularSIG0() {
		return 0;
	}
	int getNumOutputs_granularSIG0() {
		return 1;
	}
	
	void instanceInit_granularSIG0(int sample_rate) {
	}
	
	void fill_granularSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			table[i1] = 0.0f;
		}
	}

};

static _granularSIG0* new_granularSIG0() { return (_granularSIG0*)new _granularSIG0(); }
static void delete_granularSIG0(_granularSIG0* dsp) { delete dsp; }


struct _granular final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int iRec3[2];
	int iVec0[2];
	float fConst4;
	float fRec4[2];
	float fRec2[2];
	float ftbl0[44100];
	int iRec5[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec7[2];
	float fRec6[2];
	int iRec8[2];
	int iVec1[2];
	float fRec10[2];
	float fRec9[2];
	int iRec11[2];
	float fRec13[2];
	float fRec12[2];
	int iVec2[2];
	float fRec15[2];
	float fRec14[2];
	int iRec16[2];
	float fRec18[2];
	float fRec17[2];
	int iVec3[2];
	float fRec20[2];
	float fRec19[2];
	int iRec21[2];
	float fRec23[2];
	float fRec22[2];
	float fVec4[2];
	float fRec1[2];
	float fRec0[2];
	float ftbl1[44100];
	float fVec5[2];
	float fRec25[2];
	float fRec24[2];
	
	_granular() {
	}
	
	void metadata(Meta* m) { 
		m->declare("aanl.lib/name", "Faust Antialiased Nonlinearities");
		m->declare("aanl.lib/version", "1.3.0");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.2.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/sAndH:author", "Romain Michon");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.19.1");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _granular -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "1.6.0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("demos.lib/name", "Faust Demos Library");
		m->declare("demos.lib/version", "1.2.0");
		m->declare("dx7.lib/version", "1.1.0");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.3.0");
		m->declare("fds.lib/author", "Romain Michon");
		m->declare("fds.lib/name", "Faust Finite Difference Schemes Library");
		m->declare("fds.lib/version", "1.1.0");
		m->declare("filename", "granular.dsp");
		m->declare("filters.lib/dcblockerat:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblockerat:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblockerat:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("hoa.lib/author", "Pierre Guillot");
		m->declare("hoa.lib/copyright", "2012-2013 Guillot, Paris, Colafrancesco, CICM labex art H2H, U. Paris 8, 2019 Wargreen, 2022 Bonardi, Goutmann");
		m->declare("hoa.lib/name", "High Order Ambisonics library");
		m->declare("hoa.lib/version", "1.4.0");
		m->declare("interpolators.lib/name", "Faust Interpolator Library");
		m->declare("interpolators.lib/version", "1.3.1");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("mi.lib/author", "Romain Michon");
		m->declare("mi.lib/copyright", "2018-2020 GRAME / GIPSA-Lab");
		m->declare("mi.lib/name", "Faust mass-interaction physical modelling library");
		m->declare("mi.lib/version", "1.1.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.5.0");
		m->declare("name", "granular");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.4.1");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.5.1");
		m->declare("phaflangers.lib/name", "Faust Phaser and Flanger Library");
		m->declare("phaflangers.lib/version", "1.1.0");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "1.1.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("quantizers.lib/name", "Faust Frequency Quantization Library");
		m->declare("quantizers.lib/version", "1.1.0");
		m->declare("reducemaps.lib/author", "Yann Orlarey");
		m->declare("reducemaps.lib/copyright", "Grame and Yann Orlarey");
		m->declare("reducemaps.lib/license", "LGPL with exception");
		m->declare("reducemaps.lib/name", "Reduce Library");
		m->declare("reducemaps.lib/version", "1.2.0");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.2.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("soundfiles.lib/name", "Faust Soundfile Library");
		m->declare("soundfiles.lib/version", "1.7.0");
		m->declare("spats.lib/name", "Faust Spatialization Library");
		m->declare("spats.lib/version", "1.1.0");
		m->declare("synths.lib/name", "Faust Synthesizer Library");
		m->declare("synths.lib/version", "1.1.0");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/version", "1.2.1");
		m->declare("wdmodels.lib/name", "Faust Wave Digital Model Library");
		m->declare("wdmodels.lib/version", "1.2.1");
		m->declare("webaudio.lib/author", "GRAME");
		m->declare("webaudio.lib/copyright", "GRAME");
		m->declare("webaudio.lib/license", "LGPL with exception");
		m->declare("webaudio.lib/name", "Faust WebAudio Filters Library");
		m->declare("webaudio.lib/version", "1.1.0");
	}

	static constexpr int getStaticNumInputs() {
		return 2;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 2;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 62.831852f / fConst0;
		fConst2 = 1.0f / (fConst1 + 1.0f);
		fConst3 = 1.0f - fConst1;
		fConst4 = 1.0f / fConst0;
		_granularSIG0* sig0 = new_granularSIG0();
		sig0->instanceInit_granularSIG0(sample_rate);
		sig0->fill_granularSIG0(44100, ftbl0);
		sig0->instanceInit_granularSIG0(sample_rate);
		sig0->fill_granularSIG0(44100, ftbl1);
		delete_granularSIG0(sig0);
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1e+01f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iRec3[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iVec0[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec4[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			iRec5[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec7[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iRec8[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			iVec1[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec10[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iRec11[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			iVec2[l14] = 0;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec15[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			iRec16[l17] = 0;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec18[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec17[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			iVec3[l20] = 0;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec20[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec19[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			iRec21[l23] = 0;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec23[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec22[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fVec4[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec1[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec0[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fVec5[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec25[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec24[l31] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	_granular* clone() {
		return new _granular();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("granular");
		ui_interface->addHorizontalSlider("decal", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("feedback", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.5f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("population", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("speed", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.125f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("taille", &fHslider0, FAUSTFLOAT(1e+01f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.28e+05f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(4.0f, std::min<float>(1.28e+05f, float(fHslider0)));
		int iSlow1 = int(fConst0 * fSlow0 * (0.01f * (1.0f - std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider1)))) + 0.001f));
		int iSlow2 = iSlow1 + -10;
		float fSlow3 = 1e+03f / fSlow0;
		float fSlow4 = std::max<float>(0.0f, std::min<float>(1.5f, float(fHslider2)));
		int iSlow5 = int(4.41e+04f * (1.0f - std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider3)))));
		float fSlow6 = std::max<float>(0.125f, std::min<float>(4.0f, float(fHslider4)));
		float fSlow7 = 0.33333334f * float(iSlow1);
		float fSlow8 = fSlow7 + 1e+01f;
		float fSlow9 = 0.33333334f * float(2 * iSlow1);
		float fSlow10 = fSlow9 + 1e+01f;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iRec3[0] = (iRec3[1] + 1) % iSlow1;
			int iTemp0 = ((iRec3[0] > iSlow2) ? 1 : 0);
			iVec0[0] = iTemp0;
			int iTemp1 = iTemp0 > iVec0[1];
			fRec4[0] = ((iTemp1) ? fSlow3 : fRec4[1]);
			float fTemp2 = fConst4 * fRec4[0];
			fRec2[0] = std::max<float>(0.0f, ((iTemp1) ? float(fTemp2 < 0.0f) : fRec2[1] + fTemp2));
			float fTemp3 = std::cos(6.2831855f * ((fRec2[0] > 1.0f) ? 0.0f : fRec2[0]) + 3.1415927f) + 1.0f;
			iRec5[0] = (iRec5[1] + 1) % 44100;
			ftbl0[iRec5[0]] = float(input0[i0]) + fSlow4 * fRec0[1];
			fRec7[0] = ((iTemp1) ? fSlow6 : fRec7[1]);
			fRec6[0] = std::max<float>(0.0f, ((iTemp1) ? float(fRec7[0] < 0.0f) : fRec7[0] + fRec6[1]));
			iRec8[0] = ((iTemp1) ? iRec5[0] : iRec8[1]);
			int iTemp4 = (iSlow5 + int(fRec6[0]) + iRec8[0]) % 44100;
			int iTemp5 = ((iRec3[0] < 10) ? 1 : 0);
			iVec1[0] = iTemp5;
			int iTemp6 = iTemp5 > iVec1[1];
			fRec10[0] = ((iTemp6) ? fSlow6 : fRec10[1]);
			fRec9[0] = std::max<float>(0.0f, ((iTemp6) ? float(fRec10[0] < 0.0f) : fRec10[0] + fRec9[1]));
			iRec11[0] = ((iTemp6) ? iRec5[0] : iRec11[1]);
			int iTemp7 = (iSlow5 + int(fRec9[0]) + iRec11[0]) % 44100;
			fRec13[0] = ((iTemp6) ? fSlow3 : fRec13[1]);
			float fTemp8 = fConst4 * fRec13[0];
			fRec12[0] = std::max<float>(0.0f, ((iTemp6) ? float(fTemp8 < 0.0f) : fRec12[1] + fTemp8));
			float fTemp9 = std::cos(6.2831855f * ((fRec12[0] > 1.0f) ? 0.0f : fRec12[0]) + 3.1415927f) + 1.0f;
			float fTemp10 = float(iRec3[0]);
			int iTemp11 = ((fTemp10 < fSlow8) ? ((fTemp10 > fSlow7) ? 1 : 0) : 0);
			iVec2[0] = iTemp11;
			int iTemp12 = iTemp11 > iVec2[1];
			fRec15[0] = ((iTemp12) ? fSlow6 : fRec15[1]);
			fRec14[0] = std::max<float>(0.0f, ((iTemp12) ? float(fRec15[0] < 0.0f) : fRec15[0] + fRec14[1]));
			iRec16[0] = ((iTemp12) ? iRec5[0] : iRec16[1]);
			int iTemp13 = (iSlow5 + int(fRec14[0]) + iRec16[0]) % 44100;
			fRec18[0] = ((iTemp12) ? fSlow3 : fRec18[1]);
			float fTemp14 = fConst4 * fRec18[0];
			fRec17[0] = std::max<float>(0.0f, ((iTemp12) ? float(fTemp14 < 0.0f) : fRec17[1] + fTemp14));
			float fTemp15 = std::cos(6.2831855f * ((fRec17[0] > 1.0f) ? 0.0f : fRec17[0]) + 3.1415927f) + 1.0f;
			int iTemp16 = ((fTemp10 < fSlow10) ? ((fTemp10 > fSlow9) ? 1 : 0) : 0);
			iVec3[0] = iTemp16;
			int iTemp17 = iTemp16 > iVec3[1];
			fRec20[0] = ((iTemp17) ? fSlow6 : fRec20[1]);
			fRec19[0] = std::max<float>(0.0f, ((iTemp17) ? float(fRec20[0] < 0.0f) : fRec20[0] + fRec19[1]));
			iRec21[0] = ((iTemp17) ? iRec5[0] : iRec21[1]);
			int iTemp18 = (iSlow5 + int(fRec19[0]) + iRec21[0]) % 44100;
			fRec23[0] = ((iTemp17) ? fSlow3 : fRec23[1]);
			float fTemp19 = fConst4 * fRec23[0];
			fRec22[0] = std::max<float>(0.0f, ((iTemp17) ? float(fTemp19 < 0.0f) : fRec22[1] + fTemp19));
			float fTemp20 = std::cos(6.2831855f * ((fRec22[0] > 1.0f) ? 0.0f : fRec22[0]) + 3.1415927f) + 1.0f;
			float fTemp21 = fTemp3 * ftbl0[iTemp4] + ftbl0[iTemp7] * fTemp9 + ftbl0[iTemp13] * fTemp15 + ftbl0[iTemp18] * fTemp20;
			fVec4[0] = fTemp21;
			fRec1[0] = fConst2 * (fConst3 * fRec1[1] + 0.1f * (fTemp21 - fVec4[1]));
			fRec0[0] = fRec1[0];
			output0[i0] = FAUSTFLOAT(fRec0[0]);
			ftbl1[iRec5[0]] = float(input1[i0]) + fSlow4 * fRec24[1];
			float fTemp22 = fTemp9 * ftbl1[iTemp7] + ftbl1[iTemp13] * fTemp15 + ftbl1[iTemp18] * fTemp20 + fTemp3 * ftbl1[iTemp4];
			fVec5[0] = fTemp22;
			fRec25[0] = fConst2 * (fConst3 * fRec25[1] + 0.1f * (fTemp22 - fVec5[1]));
			fRec24[0] = fRec25[0];
			output1[i0] = FAUSTFLOAT(fRec24[0]);
			iRec3[1] = iRec3[0];
			iVec0[1] = iVec0[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			iRec5[1] = iRec5[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			iRec8[1] = iRec8[0];
			iVec1[1] = iVec1[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			iRec11[1] = iRec11[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			iVec2[1] = iVec2[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			iRec16[1] = iRec16[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			iVec3[1] = iVec3[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			iRec21[1] = iRec21[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fVec4[1] = fVec4[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			fVec5[1] = fVec5[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "granular.dsp"
	#define FAUST_CLASS_NAME "_granular"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _granular -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 5
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("decal", fHslider3, 0.0f, 0.0f, 1.0f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("feedback", fHslider2, 0.0f, 0.0f, 1.5f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("population", fHslider1, 1.0f, 0.0f, 1.0f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("speed", fHslider4, 1.0f, 0.125f, 4.0f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("taille", fHslider0, 1e+01f, 4.0f, 1.28e+05f, 0.001f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, decal, "decal", fHslider3, 0.0f, 0.0f, 1.0f, 0.001f) \
		p(HORIZONTALSLIDER, feedback, "feedback", fHslider2, 0.0f, 0.0f, 1.5f, 0.001f) \
		p(HORIZONTALSLIDER, population, "population", fHslider1, 1.0f, 0.0f, 1.0f, 0.001f) \
		p(HORIZONTALSLIDER, speed, "speed", fHslider4, 1.0f, 0.125f, 4.0f, 0.001f) \
		p(HORIZONTALSLIDER, taille, "taille", fHslider0, 1e+01f, 4.0f, 1.28e+05f, 0.001f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
