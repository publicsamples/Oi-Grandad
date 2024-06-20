/* ------------------------------------------------------------
name: "03Harmonics"
Code generated with Faust 2.50.6 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
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


class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int iVec0[2];
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fRec2[2];
	float fRec1[2];
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	float fConst2;
	float fRec5[2];
	float fRec4[2];
	float fRec3[2];
	FAUSTFLOAT fHslider3;
	float fConst3;
	float fRec8[2];
	float fRec7[2];
	float fRec6[2];
	FAUSTFLOAT fHslider4;
	float fConst4;
	float fRec11[2];
	float fRec10[2];
	float fRec9[2];
	FAUSTFLOAT fHslider5;
	float fConst5;
	float fRec14[2];
	float fRec13[2];
	float fRec12[2];
	FAUSTFLOAT fHslider6;
	float fConst6;
	float fRec17[2];
	float fRec16[2];
	float fRec15[2];
	FAUSTFLOAT fHslider7;
	float fConst7;
	float fRec20[2];
	float fRec19[2];
	float fRec18[2];
	FAUSTFLOAT fHslider8;
	float fConst8;
	float fRec23[2];
	float fRec22[2];
	float fRec21[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -mcd 16 -single -ftz 0");
		m->declare("filename", "03Harmonics.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "03Harmonics");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.3");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 18.849556f / fConst0;
		fConst2 = 6.2831855f / fConst0;
		fConst3 = 12.566371f / fConst0;
		fConst4 = 50.265484f / fConst0;
		fConst5 = 25.132742f / fConst0;
		fConst6 = 43.982296f / fConst0;
		fConst7 = 31.415926f / fConst0;
		fConst8 = 37.699112f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.33333334f);
		fHslider1 = FAUSTFLOAT(8e+01f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(0.5f);
		fHslider4 = FAUSTFLOAT(0.125f);
		fHslider5 = FAUSTFLOAT(0.25f);
		fHslider6 = FAUSTFLOAT(0.14285715f);
		fHslider7 = FAUSTFLOAT(0.2f);
		fHslider8 = FAUSTFLOAT(0.16666667f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec0[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec8[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec6[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec11[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec9[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec14[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec12[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec17[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec16[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec15[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec20[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec19[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec18[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec23[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec22[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec21[l24] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("03Harmonics");
		ui_interface->declare(&fHslider1, "OWL", "AA");
		ui_interface->addHorizontalSlider("Base frequency", &fHslider1, FAUSTFLOAT(8e+01f), FAUSTFLOAT(6e+01f), FAUSTFLOAT(1.2e+02f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "OWL", "0");
		ui_interface->addHorizontalSlider("Harmonic 0", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider3, "OWL", "1");
		ui_interface->addHorizontalSlider("Harmonic 1", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider0, "OWL", "2");
		ui_interface->addHorizontalSlider("Harmonic 2", &fHslider0, FAUSTFLOAT(0.33333334f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider5, "OWL", "3");
		ui_interface->addHorizontalSlider("Harmonic 3", &fHslider5, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider7, "OWL", "4");
		ui_interface->addHorizontalSlider("Harmonic 4", &fHslider7, FAUSTFLOAT(0.2f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider8, "OWL", "5");
		ui_interface->addHorizontalSlider("Harmonic 5", &fHslider8, FAUSTFLOAT(0.16666667f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider6, "OWL", "6");
		ui_interface->addHorizontalSlider("Harmonic 6", &fHslider6, FAUSTFLOAT(0.14285715f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider4, "OWL", "7");
		ui_interface->addHorizontalSlider("Harmonic 7", &fHslider4, FAUSTFLOAT(0.125f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fHslider1);
		float fSlow2 = fConst1 * fSlow1;
		float fSlow3 = float(fHslider2);
		float fSlow4 = fConst2 * fSlow1;
		float fSlow5 = float(fHslider3);
		float fSlow6 = fConst3 * fSlow1;
		float fSlow7 = float(fHslider4);
		float fSlow8 = fConst4 * fSlow1;
		float fSlow9 = float(fHslider5);
		float fSlow10 = fConst5 * fSlow1;
		float fSlow11 = float(fHslider6);
		float fSlow12 = fConst6 * fSlow1;
		float fSlow13 = float(fHslider7);
		float fSlow14 = fConst7 * fSlow1;
		float fSlow15 = float(fHslider8);
		float fSlow16 = fConst8 * fSlow1;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			float fTemp0 = float(1 - iVec0[1]);
			fRec2[0] = fRec2[1] + fSlow2 * (0.0f - fRec0[1]);
			fRec1[0] = fTemp0 + fRec1[1] + fSlow2 * fRec2[0];
			fRec0[0] = fRec1[0];
			fRec5[0] = fRec5[1] + fSlow4 * (0.0f - fRec3[1]);
			fRec4[0] = fTemp0 + fRec4[1] + fSlow4 * fRec5[0];
			fRec3[0] = fRec4[0];
			fRec8[0] = fRec8[1] + fSlow6 * (0.0f - fRec6[1]);
			fRec7[0] = fTemp0 + fRec7[1] + fSlow6 * fRec8[0];
			fRec6[0] = fRec7[0];
			fRec11[0] = fRec11[1] + fSlow8 * (0.0f - fRec9[1]);
			fRec10[0] = fTemp0 + fRec10[1] + fSlow8 * fRec11[0];
			fRec9[0] = fRec10[0];
			fRec14[0] = fRec14[1] + fSlow10 * (0.0f - fRec12[1]);
			fRec13[0] = fTemp0 + fRec13[1] + fSlow10 * fRec14[0];
			fRec12[0] = fRec13[0];
			fRec17[0] = fRec17[1] + fSlow12 * (0.0f - fRec15[1]);
			fRec16[0] = fTemp0 + fRec16[1] + fSlow12 * fRec17[0];
			fRec15[0] = fRec16[0];
			fRec20[0] = fRec20[1] + fSlow14 * (0.0f - fRec18[1]);
			fRec19[0] = fTemp0 + fRec19[1] + fSlow14 * fRec20[0];
			fRec18[0] = fRec19[0];
			fRec23[0] = fRec23[1] + fSlow16 * (0.0f - fRec21[1]);
			fRec22[0] = fTemp0 + fRec22[1] + fSlow16 * fRec23[0];
			fRec21[0] = fRec22[0];
			float fTemp1 = 0.125f * (fSlow0 * fRec0[0] + fSlow3 * fRec3[0] + fSlow5 * fRec6[0] + fSlow7 * fRec9[0] + fSlow9 * fRec12[0] + fSlow11 * fRec15[0] + fSlow13 * fRec18[0] + fSlow15 * fRec21[0]);
			output0[i0] = FAUSTFLOAT(fTemp1);
			output1[i0] = FAUSTFLOAT(fTemp1);
			iVec0[1] = iVec0[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
		}
	}

};

#endif
