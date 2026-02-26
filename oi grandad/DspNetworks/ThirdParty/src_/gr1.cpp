/* ------------------------------------------------------------
author: "Dario Sanfilippo"
copyright: "Copyright (C) 2021 Dario Sanfilippo      <sanfilippo.dario@gmail.com>"
license: "MIT license"
name: "Concatenative Granular Processing"
version: "1.0"
Code generated with Faust 2.81.2 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _gr1 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___gr1_H__
#define  ___gr1_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _gr1
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

struct _gr1SIG0 {
	
	int getNumInputs_gr1SIG0() {
		return 0;
	}
	int getNumOutputs_gr1SIG0() {
		return 1;
	}
	
	void instanceInit_gr1SIG0(int sample_rate) {
	}
	
	void fill_gr1SIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			table[i1] = 0.0f;
		}
	}

};

static _gr1SIG0* new_gr1SIG0() { return (_gr1SIG0*)new _gr1SIG0(); }
static void delete_gr1SIG0(_gr1SIG0* dsp) { delete dsp; }


struct _gr1 final : public ::faust::dsp {
	
	FAUSTFLOAT fHslider0;
	int iVec0[2];
	int iRec5[2];
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider1;
	float fRec6[2];
	int iRec4[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec8[2];
	float fRec7[2];
	float ftbl0[1920000];
	int iRec9[2];
	FAUSTFLOAT fCheckbox0;
	int IOTA0;
	float fRec11[2097152];
	int iRec10[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	float fRec12[2];
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	float fRec13[2];
	float ftbl1[1920000];
	int iRec14[2];
	float ftbl2[1920000];
	float fRec3[2];
	int iRec15[2];
	float ftbl3[1920000];
	float fRec1[4];
	FAUSTFLOAT fHslider9;
	int iRec16[2];
	float fRec17[2];
	float fRec18[2];
	float fRec19[2];
	float fRec0[2];
	int iRec25[2];
	float fRec26[2];
	int iRec24[2];
	float fRec28[2];
	float fRec27[2];
	float ftbl4[1920000];
	float fRec30[2097152];
	int iRec29[2];
	float fRec31[2];
	float ftbl5[1920000];
	int iRec32[2];
	float ftbl6[1920000];
	float fRec23[2];
	int iRec33[2];
	float ftbl7[1920000];
	float fRec21[4];
	int iRec34[2];
	float fRec35[2];
	float fRec36[2];
	float fRec37[2];
	float fRec20[2];
	
	_gr1() {
	}
	
	void metadata(Meta* m) { 
		m->declare("author", "Dario Sanfilippo");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/sAndH:author", "Romain Michon");
		m->declare("basics.lib/version", "1.21.0");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _gr1 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("copyright", "Copyright (C) 2021 Dario Sanfilippo      <sanfilippo.dario@gmail.com>");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "gr1.dsp");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.7.1");
		m->declare("license", "MIT license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.1");
		m->declare("name", "Concatenative Granular Processing");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.6.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.2.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("version", "1.0");
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
		fConst0 = 0.001f * std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		_gr1SIG0* sig0 = new_gr1SIG0();
		sig0->instanceInit_gr1SIG0(sample_rate);
		sig0->fill_gr1SIG0(1920000, ftbl0);
		sig0->instanceInit_gr1SIG0(sample_rate);
		sig0->fill_gr1SIG0(1920000, ftbl1);
		sig0->instanceInit_gr1SIG0(sample_rate);
		sig0->fill_gr1SIG0(1920000, ftbl2);
		sig0->instanceInit_gr1SIG0(sample_rate);
		sig0->fill_gr1SIG0(1920000, ftbl3);
		sig0->instanceInit_gr1SIG0(sample_rate);
		sig0->fill_gr1SIG0(1920000, ftbl4);
		sig0->instanceInit_gr1SIG0(sample_rate);
		sig0->fill_gr1SIG0(1920000, ftbl5);
		sig0->instanceInit_gr1SIG0(sample_rate);
		sig0->fill_gr1SIG0(1920000, ftbl6);
		sig0->instanceInit_gr1SIG0(sample_rate);
		sig0->fill_gr1SIG0(1920000, ftbl7);
		delete_gr1SIG0(sig0);
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(1e+02f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(1.0f);
		fHslider7 = FAUSTFLOAT(0.0f);
		fHslider8 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(16.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec5[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec6[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec4[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec8[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec7[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			iRec9[l6] = 0;
		}
		IOTA0 = 0;
		for (int l7 = 0; l7 < 2097152; l7 = l7 + 1) {
			fRec11[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			iRec10[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec12[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec13[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iRec14[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec3[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			iRec15[l13] = 0;
		}
		for (int l14 = 0; l14 < 4; l14 = l14 + 1) {
			fRec1[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			iRec16[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec17[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec18[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec19[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec0[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			iRec25[l20] = 0;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec26[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			iRec24[l22] = 0;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec28[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec27[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2097152; l25 = l25 + 1) {
			fRec30[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			iRec29[l26] = 0;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec31[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			iRec32[l28] = 0;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec23[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			iRec33[l30] = 0;
		}
		for (int l31 = 0; l31 < 4; l31 = l31 + 1) {
			fRec21[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			iRec34[l32] = 0;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec35[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec36[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec37[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec20[l36] = 0.0f;
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
	
	_gr1* clone() {
		return new _gr1();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Concatenative Granular Processing");
		ui_interface->declare(&fHslider9, "00", "");
		ui_interface->addHorizontalSlider("Interpolation length (samples)", &fHslider9, FAUSTFLOAT(16.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(64.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "01", "");
		ui_interface->addHorizontalSlider("Grain length (ms)", &fHslider1, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(6.4e+03f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider5, "02", "");
		ui_interface->addHorizontalSlider("Buffer position", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e-06f));
		ui_interface->declare(&fHslider6, "03", "");
		ui_interface->addHorizontalSlider("Time transposition", &fHslider6, FAUSTFLOAT(1.0f), FAUSTFLOAT(-16.0f), FAUSTFLOAT(16.0f), FAUSTFLOAT(1e-06f));
		ui_interface->declare(&fHslider8, "04", "");
		ui_interface->addHorizontalSlider("Time async degree", &fHslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e-06f));
		ui_interface->declare(&fHslider7, "05", "");
		ui_interface->addHorizontalSlider("Time async depth", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.92e+06f), FAUSTFLOAT(1e-06f));
		ui_interface->declare(&fHslider2, "06", "");
		ui_interface->addHorizontalSlider("Pitch transposition", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(-16.0f), FAUSTFLOAT(16.0f), FAUSTFLOAT(1e-06f));
		ui_interface->declare(&fHslider4, "07", "");
		ui_interface->addHorizontalSlider("Pitch async degree", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e-06f));
		ui_interface->declare(&fHslider3, "08", "");
		ui_interface->addHorizontalSlider("Pitch async depth", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1e-06f));
		ui_interface->declare(&fCheckbox0, "09", "");
		ui_interface->addCheckButton("Freeze buffer", &fCheckbox0);
		ui_interface->declare(&fHslider0, "10", "");
		ui_interface->addHorizontalSlider("Volume", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e-06f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0)));
		float fSlow1 = fConst0 * std::max<float>(1.0f, std::min<float>(6.4e+03f, float(fHslider1)));
		float fSlow2 = std::max<float>(-16.0f, std::min<float>(16.0f, float(fHslider2)));
		float fSlow3 = std::max<float>(0.0f, std::min<float>(1e+03f, float(fHslider3)));
		float fSlow4 = std::exp(-3.1415927f * std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider4))));
		float fSlow5 = 1.0f - fSlow4;
		float fSlow6 = float(fCheckbox0);
		float fSlow7 = 1.0f - fSlow6;
		float fSlow8 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider5)));
		float fSlow9 = 5.2083334e-07f * std::max<float>(-16.0f, std::min<float>(16.0f, float(fHslider6)));
		float fSlow10 = std::max<float>(0.0f, std::min<float>(1.92e+06f, float(fHslider7)));
		float fSlow11 = std::exp(-3.1415927f * std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider8))));
		float fSlow12 = 1.0f - fSlow11;
		int iSlow13 = int(std::max<float>(4.0f, std::min<float>(64.0f, float(fHslider9))));
		float fSlow14 = 1.0f / float(-3 - iSlow13);
		float fSlow15 = 1.0f / float(-4 - iSlow13);
		float fSlow16 = 0.5f / float(-5 - iSlow13);
		float fSlow17 = float(-2 - iSlow13);
		float fSlow18 = 1.0f / fSlow17;
		float fSlow19 = 0.5f / (fSlow17 * float(-1 - iSlow13));
		float fSlow20 = float(iSlow13 + 1);
		float fSlow21 = float(iSlow13 + 2);
		float fSlow22 = float(iSlow13 + 3);
		float fSlow23 = 0.5f / (fSlow20 * fSlow21 * fSlow22);
		float fSlow24 = float(iSlow13);
		float fSlow25 = float(iSlow13 + 4);
		float fSlow26 = 1.0f / (fSlow21 * fSlow22 * fSlow25);
		float fSlow27 = 0.5f / (fSlow22 * fSlow25 * float(iSlow13 + 5));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			iRec5[0] = iRec5[1] * (1 - iRec4[1]) + 1;
			int iTemp0 = 1 - iVec0[1];
			fRec6[0] = ((iRec4[1] + iTemp0) ? fSlow1 : fRec6[1]);
			iRec4[0] = (float(iRec5[0]) >= fRec6[0]) & ((fRec1[1] * fRec1[2]) < 0.0f);
			fRec8[0] = fSlow4 * fRec8[1] + fSlow5 * fRec0[1];
			float fTemp1 = fSlow2 + fSlow3 * fRec8[0];
			fRec7[0] = ((iRec4[0] + iTemp0) ? ((fTemp1 < 0.0f) ? std::max<float>(-16.0f, std::min<float>(-0.0625f, fTemp1)) : std::min<float>(16.0f, std::max<float>(0.0625f, fTemp1))) : fRec7[1]);
			int iTemp2 = fRec7[0] > 0.0f;
			int iTemp3 = fRec7[0] < 0.0f;
			float fTemp4 = fRec1[1] - fRec1[2];
			iRec9[0] = (iVec0[1] + iRec9[1]) % 1920000;
			fRec11[IOTA0 & 2097151] = fSlow6 * fRec11[(IOTA0 - 1920000) & 2097151] + fSlow7 * float(input0[i0]);
			float fTemp5 = fRec11[IOTA0 & 2097151];
			float fTemp6 = fRec11[(IOTA0 - 1) & 2097151];
			int iTemp7 = (fTemp5 * fTemp6) < 0.0f;
			float fTemp8 = fTemp5 - fTemp6;
			iRec10[0] = ((iTemp7 & (fTemp8 < 0.0f)) ? iRec9[0] : iRec10[1]);
			ftbl0[iRec9[0]] = float(iRec10[0]);
			float fTemp9 = ((iTemp0) ? 0.0f : fSlow9 + fRec12[1]);
			fRec12[0] = fTemp9 - std::floor(fTemp9);
			float fTemp10 = 1.92e+06f * (fSlow8 + fRec12[0]);
			fRec13[0] = fSlow11 * fRec13[1] + fSlow12 * fRec0[1];
			int iTemp11 = int(std::fmod(std::fmod(fTemp10 + fSlow10 * fRec13[0], 1.92e+06f) + 1.92e+06f, 1.92e+06f));
			iRec14[0] = ((iTemp7 & (fTemp8 > 0.0f)) ? iRec9[0] : iRec14[1]);
			ftbl1[iRec9[0]] = float(iRec14[0]);
			float fTemp12 = (((float(iTemp2 - iTemp3) * fTemp4) > 0.0f) ? ftbl1[iTemp11] : ftbl0[iTemp11]);
			ftbl2[iRec9[0]] = fTemp8;
			float fTemp13 = ftbl2[int(std::fmod(std::fmod(fTemp12, 1.92e+06f) + 1.92e+06f, 1.92e+06f))];
			fRec3[0] = ((iRec4[0]) ? 0.5f * float(iTemp2 + (-1 - iTemp3)) + fTemp12 + fTemp4 / ((fTemp13 < 0.0f) ? std::min<float>(-1.1920929e-07f, fTemp13) : std::max<float>(1.1920929e-07f, fTemp13)) : fRec3[1]);
			int iTemp14 = 1 - iRec4[0];
			iRec15[0] = iTemp14 * iRec15[1] + iTemp14;
			float fTemp15 = fRec3[0] + fRec7[0] * float(iRec15[0]);
			float fTemp16 = std::floor(fTemp15);
			float fTemp17 = fTemp15 + (-2.0f - fTemp16);
			float fTemp18 = fTemp15 + (-1.0f - fTemp16);
			float fTemp19 = fTemp15 - fTemp16;
			float fTemp20 = fTemp15 + (2.0f - fTemp16);
			ftbl3[iRec9[0]] = fTemp5;
			int iTemp21 = int(fTemp15);
			float fTemp22 = fTemp15 + (1.0f - fTemp16);
			float fTemp23 = fTemp19 * fTemp20 * fTemp22;
			float fTemp24 = fTemp23 * fTemp18;
			float fTemp25 = (fTemp15 + (-3.0f - fTemp16)) * (fTemp17 * (fTemp18 * (fTemp19 * (0.041666668f * fTemp20 * ftbl3[((iTemp21 + -1) % 1920000 + 1920000) % 1920000] - 0.008333334f * fTemp22 * ftbl3[((iTemp21 + -2) % 1920000 + 1920000) % 1920000]) - 0.083333336f * fTemp20 * fTemp22 * ftbl3[(iTemp21 % 1920000 + 1920000) % 1920000]) + 0.083333336f * fTemp23 * ftbl3[((iTemp21 + 1) % 1920000 + 1920000) % 1920000]) - 0.041666668f * fTemp24 * ftbl3[((iTemp21 + 2) % 1920000 + 1920000) % 1920000]) + 0.008333334f * fTemp24 * fTemp17 * ftbl3[((iTemp21 + 3) % 1920000 + 1920000) % 1920000];
			fRec1[0] = fTemp25;
			iRec16[0] = std::min<int>(iSlow13, iTemp14 * iRec16[1] + iTemp14);
			float fTemp26 = float(iRec16[0] + -1 - iSlow13);
			float fTemp27 = float(iRec16[0] - iSlow13);
			float fTemp28 = float(iRec16[0] + 1);
			fRec17[0] = ((iRec4[0]) ? fRec1[3] : fRec17[1]);
			float fTemp29 = float(iRec16[0] + 2);
			fRec18[0] = ((iRec4[0]) ? fRec1[2] : fRec18[1]);
			float fTemp30 = float(iRec16[0] + 3);
			fRec19[0] = ((iRec4[0]) ? fRec1[1] : fRec19[1]);
			float fTemp31 = fTemp29 * fTemp28;
			float fTemp32 = fRec3[0] + fSlow24 * fRec7[0];
			float fTemp33 = std::floor(fTemp32);
			float fTemp34 = fTemp32 + (-2.0f - fTemp33);
			float fTemp35 = fTemp32 + (-1.0f - fTemp33);
			float fTemp36 = fTemp32 - fTemp33;
			float fTemp37 = fTemp32 + (2.0f - fTemp33);
			int iTemp38 = int(fTemp32);
			float fTemp39 = fTemp32 + (1.0f - fTemp33);
			float fTemp40 = fTemp36 * fTemp37 * fTemp39;
			float fTemp41 = fTemp40 * fTemp35;
			float fTemp42 = fTemp31 * fTemp27;
			float fTemp43 = fRec3[0] + fSlow20 * fRec7[0];
			float fTemp44 = std::floor(fTemp43);
			float fTemp45 = fTemp43 + (-2.0f - fTemp44);
			float fTemp46 = fTemp43 + (-1.0f - fTemp44);
			float fTemp47 = fTemp43 - fTemp44;
			float fTemp48 = fTemp43 + (2.0f - fTemp44);
			int iTemp49 = int(fTemp43);
			float fTemp50 = fTemp43 + (1.0f - fTemp44);
			float fTemp51 = fTemp47 * fTemp48 * fTemp50;
			float fTemp52 = fTemp51 * fTemp46;
			float fTemp53 = fRec3[0] + fSlow21 * fRec7[0];
			float fTemp54 = std::floor(fTemp53);
			float fTemp55 = fTemp53 + (-2.0f - fTemp54);
			float fTemp56 = fTemp53 + (-1.0f - fTemp54);
			float fTemp57 = fTemp53 - fTemp54;
			float fTemp58 = fTemp53 + (2.0f - fTemp54);
			int iTemp59 = int(fTemp53);
			float fTemp60 = fTemp53 + (1.0f - fTemp54);
			float fTemp61 = fTemp57 * fTemp58 * fTemp60;
			float fTemp62 = fTemp61 * fTemp56;
			float fRec2 = ((iRec16[0] < iSlow13) ? float(iRec16[0] + -2 - iSlow13) * (fTemp26 * (fSlow14 * fTemp27 * (fSlow15 * fTemp28 * (fSlow16 * fRec17[0] * fTemp29 - fSlow18 * fRec18[0] * fTemp30) + fSlow19 * fRec19[0] * fTemp29 * fTemp30) + fSlow23 * fTemp31 * fTemp30 * ((fTemp32 + (-3.0f - fTemp33)) * (fTemp34 * (fTemp35 * (fTemp36 * (0.041666668f * fTemp37 * ftbl3[((iTemp38 + -1) % 1920000 + 1920000) % 1920000] - 0.008333334f * fTemp39 * ftbl3[((iTemp38 + -2) % 1920000 + 1920000) % 1920000]) - 0.083333336f * fTemp37 * fTemp39 * ftbl3[(iTemp38 % 1920000 + 1920000) % 1920000]) + 0.083333336f * fTemp40 * ftbl3[((iTemp38 + 1) % 1920000 + 1920000) % 1920000]) - 0.041666668f * fTemp41 * ftbl3[((iTemp38 + 2) % 1920000 + 1920000) % 1920000]) + 0.008333334f * fTemp41 * fTemp34 * ftbl3[((iTemp38 + 3) % 1920000 + 1920000) % 1920000])) - fSlow26 * fTemp42 * fTemp30 * ((fTemp43 + (-3.0f - fTemp44)) * (fTemp45 * (fTemp46 * (fTemp47 * (0.041666668f * fTemp48 * ftbl3[((iTemp49 + -1) % 1920000 + 1920000) % 1920000] - 0.008333334f * fTemp50 * ftbl3[((iTemp49 + -2) % 1920000 + 1920000) % 1920000]) - 0.083333336f * fTemp48 * fTemp50 * ftbl3[(iTemp49 % 1920000 + 1920000) % 1920000]) + 0.083333336f * fTemp51 * ftbl3[((iTemp49 + 1) % 1920000 + 1920000) % 1920000]) - 0.041666668f * fTemp52 * ftbl3[((iTemp49 + 2) % 1920000 + 1920000) % 1920000]) + 0.008333334f * fTemp52 * fTemp45 * ftbl3[((iTemp49 + 3) % 1920000 + 1920000) % 1920000])) + fSlow27 * fTemp42 * fTemp26 * fTemp30 * ((fTemp53 + (-3.0f - fTemp54)) * (fTemp55 * (fTemp56 * (fTemp57 * (0.041666668f * fTemp58 * ftbl3[((iTemp59 + -1) % 1920000 + 1920000) % 1920000] - 0.008333334f * fTemp60 * ftbl3[((iTemp59 + -2) % 1920000 + 1920000) % 1920000]) - 0.083333336f * fTemp58 * fTemp60 * ftbl3[(iTemp59 % 1920000 + 1920000) % 1920000]) + 0.083333336f * fTemp61 * ftbl3[((iTemp59 + 1) % 1920000 + 1920000) % 1920000]) - 0.041666668f * fTemp62 * ftbl3[((iTemp59 + 2) % 1920000 + 1920000) % 1920000]) + 0.008333334f * fTemp62 * fTemp55 * ftbl3[((iTemp59 + 3) % 1920000 + 1920000) % 1920000]) : fTemp25);
			fRec0[0] = fRec2;
			output0[i0] = FAUSTFLOAT(fSlow0 * fRec0[0]);
			iRec25[0] = iRec25[1] * (1 - iRec24[1]) + 1;
			fRec26[0] = ((iRec24[1] + iTemp0) ? fSlow1 : fRec26[1]);
			iRec24[0] = (float(iRec25[0]) >= fRec26[0]) & ((fRec21[1] * fRec21[2]) < 0.0f);
			fRec28[0] = fSlow4 * fRec28[1] + fSlow5 * fRec20[1];
			float fTemp63 = fSlow2 + fSlow3 * fRec28[0];
			fRec27[0] = ((iRec24[0] + iTemp0) ? ((fTemp63 < 0.0f) ? std::max<float>(-16.0f, std::min<float>(-0.0625f, fTemp63)) : std::min<float>(16.0f, std::max<float>(0.0625f, fTemp63))) : fRec27[1]);
			int iTemp64 = fRec27[0] > 0.0f;
			int iTemp65 = fRec27[0] < 0.0f;
			float fTemp66 = fRec21[1] - fRec21[2];
			fRec30[IOTA0 & 2097151] = fSlow6 * fRec30[(IOTA0 - 1920000) & 2097151] + fSlow7 * float(input1[i0]);
			float fTemp67 = fRec30[IOTA0 & 2097151];
			float fTemp68 = fRec30[(IOTA0 - 1) & 2097151];
			int iTemp69 = (fTemp67 * fTemp68) < 0.0f;
			float fTemp70 = fTemp67 - fTemp68;
			iRec29[0] = ((iTemp69 & (fTemp70 < 0.0f)) ? iRec9[0] : iRec29[1]);
			ftbl4[iRec9[0]] = float(iRec29[0]);
			fRec31[0] = fSlow11 * fRec31[1] + fSlow12 * fRec20[1];
			int iTemp71 = int(std::fmod(std::fmod(fTemp10 + fSlow10 * fRec31[0], 1.92e+06f) + 1.92e+06f, 1.92e+06f));
			iRec32[0] = ((iTemp69 & (fTemp70 > 0.0f)) ? iRec9[0] : iRec32[1]);
			ftbl5[iRec9[0]] = float(iRec32[0]);
			float fTemp72 = (((float(iTemp64 - iTemp65) * fTemp66) > 0.0f) ? ftbl5[iTemp71] : ftbl4[iTemp71]);
			ftbl6[iRec9[0]] = fTemp70;
			float fTemp73 = ftbl6[int(std::fmod(std::fmod(fTemp72, 1.92e+06f) + 1.92e+06f, 1.92e+06f))];
			fRec23[0] = ((iRec24[0]) ? 0.5f * float(iTemp64 + (-1 - iTemp65)) + fTemp72 + fTemp66 / ((fTemp73 < 0.0f) ? std::min<float>(-1.1920929e-07f, fTemp73) : std::max<float>(1.1920929e-07f, fTemp73)) : fRec23[1]);
			int iTemp74 = 1 - iRec24[0];
			iRec33[0] = iTemp74 * iRec33[1] + iTemp74;
			float fTemp75 = fRec23[0] + fRec27[0] * float(iRec33[0]);
			float fTemp76 = std::floor(fTemp75);
			float fTemp77 = fTemp75 + (-2.0f - fTemp76);
			float fTemp78 = fTemp75 + (-1.0f - fTemp76);
			float fTemp79 = fTemp75 - fTemp76;
			float fTemp80 = fTemp75 + (2.0f - fTemp76);
			ftbl7[iRec9[0]] = fTemp67;
			int iTemp81 = int(fTemp75);
			float fTemp82 = fTemp75 + (1.0f - fTemp76);
			float fTemp83 = fTemp79 * fTemp80 * fTemp82;
			float fTemp84 = fTemp83 * fTemp78;
			float fTemp85 = (fTemp75 + (-3.0f - fTemp76)) * (fTemp77 * (fTemp78 * (fTemp79 * (0.041666668f * fTemp80 * ftbl7[((iTemp81 + -1) % 1920000 + 1920000) % 1920000] - 0.008333334f * fTemp82 * ftbl7[((iTemp81 + -2) % 1920000 + 1920000) % 1920000]) - 0.083333336f * fTemp80 * fTemp82 * ftbl7[(iTemp81 % 1920000 + 1920000) % 1920000]) + 0.083333336f * fTemp83 * ftbl7[((iTemp81 + 1) % 1920000 + 1920000) % 1920000]) - 0.041666668f * fTemp84 * ftbl7[((iTemp81 + 2) % 1920000 + 1920000) % 1920000]) + 0.008333334f * fTemp84 * fTemp77 * ftbl7[((iTemp81 + 3) % 1920000 + 1920000) % 1920000];
			fRec21[0] = fTemp85;
			iRec34[0] = std::min<int>(iSlow13, iTemp74 * iRec34[1] + iTemp74);
			float fTemp86 = float(iRec34[0] + -1 - iSlow13);
			float fTemp87 = float(iRec34[0] - iSlow13);
			float fTemp88 = float(iRec34[0] + 1);
			fRec35[0] = ((iRec24[0]) ? fRec21[3] : fRec35[1]);
			float fTemp89 = float(iRec34[0] + 2);
			fRec36[0] = ((iRec24[0]) ? fRec21[2] : fRec36[1]);
			float fTemp90 = float(iRec34[0] + 3);
			fRec37[0] = ((iRec24[0]) ? fRec21[1] : fRec37[1]);
			float fTemp91 = fTemp89 * fTemp88;
			float fTemp92 = fRec23[0] + fSlow24 * fRec27[0];
			float fTemp93 = std::floor(fTemp92);
			float fTemp94 = fTemp92 + (-2.0f - fTemp93);
			float fTemp95 = fTemp92 + (-1.0f - fTemp93);
			float fTemp96 = fTemp92 - fTemp93;
			float fTemp97 = fTemp92 + (2.0f - fTemp93);
			int iTemp98 = int(fTemp92);
			float fTemp99 = fTemp92 + (1.0f - fTemp93);
			float fTemp100 = fTemp96 * fTemp97 * fTemp99;
			float fTemp101 = fTemp100 * fTemp95;
			float fTemp102 = fTemp91 * fTemp87;
			float fTemp103 = fRec23[0] + fSlow20 * fRec27[0];
			float fTemp104 = std::floor(fTemp103);
			float fTemp105 = fTemp103 + (-2.0f - fTemp104);
			float fTemp106 = fTemp103 + (-1.0f - fTemp104);
			float fTemp107 = fTemp103 - fTemp104;
			float fTemp108 = fTemp103 + (2.0f - fTemp104);
			int iTemp109 = int(fTemp103);
			float fTemp110 = fTemp103 + (1.0f - fTemp104);
			float fTemp111 = fTemp107 * fTemp108 * fTemp110;
			float fTemp112 = fTemp111 * fTemp106;
			float fTemp113 = fRec23[0] + fSlow21 * fRec27[0];
			float fTemp114 = std::floor(fTemp113);
			float fTemp115 = fTemp113 + (-2.0f - fTemp114);
			float fTemp116 = fTemp113 + (-1.0f - fTemp114);
			float fTemp117 = fTemp113 - fTemp114;
			float fTemp118 = fTemp113 + (2.0f - fTemp114);
			int iTemp119 = int(fTemp113);
			float fTemp120 = fTemp113 + (1.0f - fTemp114);
			float fTemp121 = fTemp117 * fTemp118 * fTemp120;
			float fTemp122 = fTemp121 * fTemp116;
			float fRec22 = ((iRec34[0] < iSlow13) ? float(iRec34[0] + -2 - iSlow13) * (fTemp86 * (fSlow14 * fTemp87 * (fSlow15 * fTemp88 * (fSlow16 * fRec35[0] * fTemp89 - fSlow18 * fRec36[0] * fTemp90) + fSlow19 * fRec37[0] * fTemp89 * fTemp90) + fSlow23 * fTemp91 * fTemp90 * ((fTemp92 + (-3.0f - fTemp93)) * (fTemp94 * (fTemp95 * (fTemp96 * (0.041666668f * fTemp97 * ftbl7[((iTemp98 + -1) % 1920000 + 1920000) % 1920000] - 0.008333334f * fTemp99 * ftbl7[((iTemp98 + -2) % 1920000 + 1920000) % 1920000]) - 0.083333336f * fTemp97 * fTemp99 * ftbl7[(iTemp98 % 1920000 + 1920000) % 1920000]) + 0.083333336f * fTemp100 * ftbl7[((iTemp98 + 1) % 1920000 + 1920000) % 1920000]) - 0.041666668f * fTemp101 * ftbl7[((iTemp98 + 2) % 1920000 + 1920000) % 1920000]) + 0.008333334f * fTemp101 * fTemp94 * ftbl7[((iTemp98 + 3) % 1920000 + 1920000) % 1920000])) - fSlow26 * fTemp102 * fTemp90 * ((fTemp103 + (-3.0f - fTemp104)) * (fTemp105 * (fTemp106 * (fTemp107 * (0.041666668f * fTemp108 * ftbl7[((iTemp109 + -1) % 1920000 + 1920000) % 1920000] - 0.008333334f * fTemp110 * ftbl7[((iTemp109 + -2) % 1920000 + 1920000) % 1920000]) - 0.083333336f * fTemp108 * fTemp110 * ftbl7[(iTemp109 % 1920000 + 1920000) % 1920000]) + 0.083333336f * fTemp111 * ftbl7[((iTemp109 + 1) % 1920000 + 1920000) % 1920000]) - 0.041666668f * fTemp112 * ftbl7[((iTemp109 + 2) % 1920000 + 1920000) % 1920000]) + 0.008333334f * fTemp112 * fTemp105 * ftbl7[((iTemp109 + 3) % 1920000 + 1920000) % 1920000])) + fSlow27 * fTemp102 * fTemp86 * fTemp90 * ((fTemp113 + (-3.0f - fTemp114)) * (fTemp115 * (fTemp116 * (fTemp117 * (0.041666668f * fTemp118 * ftbl7[((iTemp119 + -1) % 1920000 + 1920000) % 1920000] - 0.008333334f * fTemp120 * ftbl7[((iTemp119 + -2) % 1920000 + 1920000) % 1920000]) - 0.083333336f * fTemp118 * fTemp120 * ftbl7[(iTemp119 % 1920000 + 1920000) % 1920000]) + 0.083333336f * fTemp121 * ftbl7[((iTemp119 + 1) % 1920000 + 1920000) % 1920000]) - 0.041666668f * fTemp122 * ftbl7[((iTemp119 + 2) % 1920000 + 1920000) % 1920000]) + 0.008333334f * fTemp122 * fTemp115 * ftbl7[((iTemp119 + 3) % 1920000 + 1920000) % 1920000]) : fTemp85);
			fRec20[0] = fRec22;
			output1[i0] = FAUSTFLOAT(fSlow0 * fRec20[0]);
			iVec0[1] = iVec0[0];
			iRec5[1] = iRec5[0];
			fRec6[1] = fRec6[0];
			iRec4[1] = iRec4[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			iRec9[1] = iRec9[0];
			IOTA0 = IOTA0 + 1;
			iRec10[1] = iRec10[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			iRec14[1] = iRec14[0];
			fRec3[1] = fRec3[0];
			iRec15[1] = iRec15[0];
			for (int j0 = 3; j0 > 0; j0 = j0 - 1) {
				fRec1[j0] = fRec1[j0 - 1];
			}
			iRec16[1] = iRec16[0];
			fRec17[1] = fRec17[0];
			fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
			fRec0[1] = fRec0[0];
			iRec25[1] = iRec25[0];
			fRec26[1] = fRec26[0];
			iRec24[1] = iRec24[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			iRec29[1] = iRec29[0];
			fRec31[1] = fRec31[0];
			iRec32[1] = iRec32[0];
			fRec23[1] = fRec23[0];
			iRec33[1] = iRec33[0];
			for (int j1 = 3; j1 > 0; j1 = j1 - 1) {
				fRec21[j1] = fRec21[j1 - 1];
			}
			iRec34[1] = iRec34[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec20[1] = fRec20[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "gr1.dsp"
	#define FAUST_CLASS_NAME "_gr1"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _gr1 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 11
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Interpolation length (samples)", fHslider9, 16.0f, 4.0f, 64.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("Grain length (ms)", fHslider1, 1e+02f, 1.0f, 6.4e+03f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("Buffer position", fHslider5, 0.0f, 0.0f, 1.0f, 1e-06f);
	FAUST_ADDHORIZONTALSLIDER("Time transposition", fHslider6, 1.0f, -16.0f, 16.0f, 1e-06f);
	FAUST_ADDHORIZONTALSLIDER("Time async degree", fHslider8, 0.0f, 0.0f, 1.0f, 1e-06f);
	FAUST_ADDHORIZONTALSLIDER("Time async depth", fHslider7, 0.0f, 0.0f, 1.92e+06f, 1e-06f);
	FAUST_ADDHORIZONTALSLIDER("Pitch transposition", fHslider2, 1.0f, -16.0f, 16.0f, 1e-06f);
	FAUST_ADDHORIZONTALSLIDER("Pitch async degree", fHslider4, 0.0f, 0.0f, 1.0f, 1e-06f);
	FAUST_ADDHORIZONTALSLIDER("Pitch async depth", fHslider3, 0.0f, 0.0f, 1e+03f, 1e-06f);
	FAUST_ADDCHECKBOX("Freeze buffer", fCheckbox0);
	FAUST_ADDHORIZONTALSLIDER("Volume", fHslider0, 0.0f, 0.0f, 1.0f, 1e-06f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, Interpolation_length_(samples), "Interpolation length (samples)", fHslider9, 16.0f, 4.0f, 64.0f, 1.0f) \
		p(HORIZONTALSLIDER, Grain_length_(ms), "Grain length (ms)", fHslider1, 1e+02f, 1.0f, 6.4e+03f, 0.001f) \
		p(HORIZONTALSLIDER, Buffer_position, "Buffer position", fHslider5, 0.0f, 0.0f, 1.0f, 1e-06f) \
		p(HORIZONTALSLIDER, Time_transposition, "Time transposition", fHslider6, 1.0f, -16.0f, 16.0f, 1e-06f) \
		p(HORIZONTALSLIDER, Time_async_degree, "Time async degree", fHslider8, 0.0f, 0.0f, 1.0f, 1e-06f) \
		p(HORIZONTALSLIDER, Time_async_depth, "Time async depth", fHslider7, 0.0f, 0.0f, 1.92e+06f, 1e-06f) \
		p(HORIZONTALSLIDER, Pitch_transposition, "Pitch transposition", fHslider2, 1.0f, -16.0f, 16.0f, 1e-06f) \
		p(HORIZONTALSLIDER, Pitch_async_degree, "Pitch async degree", fHslider4, 0.0f, 0.0f, 1.0f, 1e-06f) \
		p(HORIZONTALSLIDER, Pitch_async_depth, "Pitch async depth", fHslider3, 0.0f, 0.0f, 1e+03f, 1e-06f) \
		p(CHECKBOX, Freeze_buffer, "Freeze buffer", fCheckbox0, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(HORIZONTALSLIDER, Volume, "Volume", fHslider0, 0.0f, 0.0f, 1.0f, 1e-06f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
