/* ------------------------------------------------------------
name: "Folder"
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

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec5[2];
	FAUSTFLOAT fHslider1;
	float fRec6[2];
	float fVec0[2];
	float fVec1[2];
	float fRec4[2];
	float fRec3[3];
	float fRec2[3];
	float fVec2[2];
	float fRec9[2];
	float fRec8[3];
	float fRec7[3];
	float fVec3[2];
	float fRec12[2];
	float fRec11[3];
	float fRec10[3];
	float fVec4[2];
	float fRec15[2];
	float fRec14[3];
	float fRec13[3];
	float fVec5[2];
	float fRec18[2];
	float fRec17[3];
	float fRec16[3];
	float fRec21[2];
	float fRec20[3];
	float fRec19[3];
	float fVec6[2];
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider2;
	float fRec22[2];
	float fRec1[2];
	float fVec7[2];
	float fConst5;
	float fRec0[2];
	float fVec8[2];
	float fVec9[2];
	float fRec27[2];
	float fRec26[3];
	float fRec25[3];
	float fVec10[2];
	float fRec30[2];
	float fRec29[3];
	float fRec28[3];
	float fVec11[2];
	float fRec33[2];
	float fRec32[3];
	float fRec31[3];
	float fVec12[2];
	float fRec36[2];
	float fRec35[3];
	float fRec34[3];
	float fVec13[2];
	float fRec39[2];
	float fRec38[3];
	float fRec37[3];
	float fRec42[2];
	float fRec41[3];
	float fRec40[3];
	float fVec14[2];
	float fRec24[2];
	float fVec15[2];
	float fRec23[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.8");
		m->declare("compile_options", "-lang cpp -es 1 -mcd 16 -single -ftz 0");
		m->declare("filename", "Folder.dsp");
		m->declare("filters.lib/dcblockerat:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblockerat:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblockerat:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "Folder");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.3");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = 31.415926f / fConst0;
		fConst2 = 1.0f / (fConst1 + 1.0f);
		fConst3 = 3.1415927f / fConst0;
		fConst4 = 0.3846154f * fConst0 + -1.3e+03f;
		fConst5 = 1.0f - fConst1;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec5[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec6[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = l5 + 1) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = l6 + 1) {
			fRec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec9[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = l9 + 1) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = l10 + 1) {
			fRec7[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fVec3[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec12[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = l13 + 1) {
			fRec11[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = l14 + 1) {
			fRec10[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fVec4[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec15[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 3; l17 = l17 + 1) {
			fRec14[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 3; l18 = l18 + 1) {
			fRec13[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fVec5[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec18[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 3; l21 = l21 + 1) {
			fRec17[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 3; l22 = l22 + 1) {
			fRec16[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec21[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 3; l24 = l24 + 1) {
			fRec20[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 3; l25 = l25 + 1) {
			fRec19[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fVec6[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec22[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec1[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fVec7[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec0[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fVec8[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fVec9[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec27[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 3; l34 = l34 + 1) {
			fRec26[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 3; l35 = l35 + 1) {
			fRec25[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fVec10[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec30[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 3; l38 = l38 + 1) {
			fRec29[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 3; l39 = l39 + 1) {
			fRec28[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fVec11[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec33[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 3; l42 = l42 + 1) {
			fRec32[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 3; l43 = l43 + 1) {
			fRec31[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fVec12[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fRec36[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 3; l46 = l46 + 1) {
			fRec35[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 3; l47 = l47 + 1) {
			fRec34[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fVec13[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec39[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 3; l50 = l50 + 1) {
			fRec38[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 3; l51 = l51 + 1) {
			fRec37[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec42[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 3; l53 = l53 + 1) {
			fRec41[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 3; l54 = l54 + 1) {
			fRec40[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			fVec14[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec24[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fVec15[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fRec23[l58] = 0.0f;
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
		ui_interface->openVerticalBox("Folder");
		ui_interface->addHorizontalSlider("fold", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("lowpass", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("offset", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = 0.001f * float(fHslider0);
		float fSlow1 = 0.001f * float(fHslider1);
		float fSlow2 = 0.001f * mydsp_faustpower2_f(float(fHslider2));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec5[0] = fSlow0 + 0.999f * fRec5[1];
			float fTemp0 = 19.0f * fRec5[0] + 1.0f;
			fRec6[0] = fSlow1 + 0.999f * fRec6[1];
			float fTemp1 = 5.46f * (1.0f - (fRec6[0] + 1.0f));
			float fTemp2 = 0.6f * float(input0[i0]) * fTemp0 - fTemp1;
			fVec0[0] = fTemp2;
			float fTemp3 = std::fabs(fTemp2);
			float fTemp4 = float((fTemp2 > 0.0f) - (fTemp2 < 0.0f));
			float fThen0 = 0.6f * fTemp4;
			float fTemp5 = ((fTemp3 > 0.6f) ? fTemp2 : fThen0);
			float fTemp6 = 0.0f - 12.0f * (fTemp5 - 0.6f * float((fTemp5 > 0.0f) - (fTemp5 < 0.0f)));
			fVec1[0] = fTemp6;
			fRec4[0] = 0.6041931f * (fTemp6 + fVec1[1]) - 0.45006347f * fRec4[1];
			fRec3[0] = fRec4[0] - (0.9743205f * fRec3[1] + 0.3016787f * fRec3[2]);
			fRec2[0] = 1.1379995f * fRec3[1] + 0.56899977f * (fRec3[0] + fRec3[2]) - (1.242428f * fRec2[1] + 0.6598665f * fRec2[2]);
			float fThen1 = 2.994f * fTemp4;
			float fTemp7 = ((fTemp3 > 2.994f) ? fTemp2 : fThen1);
			float fTemp8 = 0.0f - 27.777f * (fTemp7 - 2.994f * float((fTemp7 > 0.0f) - (fTemp7 < 0.0f)));
			fVec2[0] = fTemp8;
			fRec9[0] = 0.273175f * (fTemp8 + fVec2[1]) - 0.45006347f * fRec9[1];
			fRec8[0] = fRec9[0] - (0.9743205f * fRec8[1] + 0.3016787f * fRec8[2]);
			fRec7[0] = 1.1379995f * fRec8[1] + 0.56899977f * (fRec8[0] + fRec8[2]) - (1.242428f * fRec7[1] + 0.6598665f * fRec7[2]);
			float fThen2 = 5.46f * fTemp4;
			float fTemp9 = ((fTemp3 > 5.46f) ? fTemp2 : fThen2);
			float fTemp10 = 0.0f - 21.428f * (fTemp9 - 5.46f * float((fTemp9 > 0.0f) - (fTemp9 < 0.0f)));
			fVec3[0] = fTemp10;
			fRec12[0] = 0.20510091f * (fTemp10 + fVec3[1]) - 0.45006347f * fRec12[1];
			fRec11[0] = fRec12[0] - (0.9743205f * fRec11[1] + 0.3016787f * fRec11[2]);
			fRec10[0] = 1.1379995f * fRec11[1] + 0.56899977f * (fRec11[0] + fRec11[2]) - (1.242428f * fRec10[1] + 0.6598665f * fRec10[2]);
			float fThen3 = 1.8f * fTemp4;
			float fTemp11 = ((fTemp3 > 1.8f) ? fTemp2 : fThen3);
			float fTemp12 = fTemp11 - 1.8f * float((fTemp11 > 0.0f) - (fTemp11 < 0.0f));
			fVec4[0] = fTemp12;
			fRec15[0] = 7.34827f * (fTemp12 + fVec4[1]) - 0.45006347f * fRec15[1];
			fRec14[0] = fRec15[0] - (0.9743205f * fRec14[1] + 0.3016787f * fRec14[2]);
			fRec13[0] = 1.1379995f * fRec14[1] + 0.56899977f * (fRec14[0] + fRec14[2]) - (1.242428f * fRec13[1] + 0.6598665f * fRec13[2]);
			float fThen4 = 4.08f * fTemp4;
			float fTemp13 = ((fTemp3 > 4.08f) ? fTemp2 : fThen4);
			float fTemp14 = fTemp13 - 4.08f * float((fTemp13 > 0.0f) - (fTemp13 < 0.0f));
			fVec5[0] = fTemp14;
			fRec18[0] = 7.048144f * (fTemp14 + fVec5[1]) - 0.45006347f * fRec18[1];
			fRec17[0] = fRec18[0] - (0.9743205f * fRec17[1] + 0.3016787f * fRec17[2]);
			fRec16[0] = 1.1379995f * fRec17[1] + 0.56899977f * (fRec17[0] + fRec17[2]) - (1.242428f * fRec16[1] + 0.6598665f * fRec16[2]);
			fRec21[0] = 3.6251585f * (fTemp2 + fVec0[1]) - 0.45006347f * fRec21[1];
			fRec20[0] = fRec21[0] - (0.9743205f * fRec20[1] + 0.3016787f * fRec20[2]);
			fRec19[0] = 1.1379995f * fRec20[1] + 0.56899977f * (fRec20[0] + fRec20[2]) - (1.242428f * fRec19[1] + 0.6598665f * fRec19[2]);
			float fTemp15 = 0.7255736f * (fRec2[0] + fRec2[2] + fRec7[0] + fRec7[2] + fRec10[0] + fRec10[2] + fRec13[0] + fRec13[2] + fRec16[0] + fRec16[2] + fRec19[0] + fRec19[2]) + 1.4511472f * (fRec2[1] + fRec7[1] + fRec10[1] + fRec13[1] + fRec16[1] + fRec19[1]);
			fVec6[0] = fTemp15;
			fRec22[0] = fSlow2 + 0.999f * fRec22[1];
			float fTemp16 = 1.0f / std::tan(fConst3 * (fConst4 * fRec22[0] + 1.3e+03f));
			float fTemp17 = 1.0f - fTemp16;
			float fTemp18 = fTemp16 + 1.0f;
			fRec1[0] = (fTemp15 + fVec6[1] - fRec1[1] * fTemp17) / fTemp18;
			float fTemp19 = std::max<float>(-1.0f, std::min<float>(1.0f, 0.16666667f * fRec1[0]));
			float fTemp20 = fTemp19 * (1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp19));
			fVec7[0] = fTemp20;
			fRec0[0] = fConst2 * (fTemp20 - fVec7[1] + fConst5 * fRec0[1]);
			output0[i0] = FAUSTFLOAT(fRec0[0]);
			float fTemp21 = 0.6f * float(input1[i0]) * fTemp0 - fTemp1;
			fVec8[0] = fTemp21;
			float fTemp22 = std::fabs(fTemp21);
			float fTemp23 = float((fTemp21 > 0.0f) - (fTemp21 < 0.0f));
			float fThen5 = 0.6f * fTemp23;
			float fTemp24 = ((fTemp22 > 0.6f) ? fTemp21 : fThen5);
			float fTemp25 = 0.0f - 12.0f * (fTemp24 - 0.6f * float((fTemp24 > 0.0f) - (fTemp24 < 0.0f)));
			fVec9[0] = fTemp25;
			fRec27[0] = 0.6041931f * (fTemp25 + fVec9[1]) - 0.45006347f * fRec27[1];
			fRec26[0] = fRec27[0] - (0.9743205f * fRec26[1] + 0.3016787f * fRec26[2]);
			fRec25[0] = 1.1379995f * fRec26[1] + 0.56899977f * (fRec26[0] + fRec26[2]) - (1.242428f * fRec25[1] + 0.6598665f * fRec25[2]);
			float fThen6 = 2.994f * fTemp23;
			float fTemp26 = ((fTemp22 > 2.994f) ? fTemp21 : fThen6);
			float fTemp27 = 0.0f - 27.777f * (fTemp26 - 2.994f * float((fTemp26 > 0.0f) - (fTemp26 < 0.0f)));
			fVec10[0] = fTemp27;
			fRec30[0] = 0.273175f * (fTemp27 + fVec10[1]) - 0.45006347f * fRec30[1];
			fRec29[0] = fRec30[0] - (0.9743205f * fRec29[1] + 0.3016787f * fRec29[2]);
			fRec28[0] = 1.1379995f * fRec29[1] + 0.56899977f * (fRec29[0] + fRec29[2]) - (1.242428f * fRec28[1] + 0.6598665f * fRec28[2]);
			float fThen7 = 5.46f * fTemp23;
			float fTemp28 = ((fTemp22 > 5.46f) ? fTemp21 : fThen7);
			float fTemp29 = 0.0f - 21.428f * (fTemp28 - 5.46f * float((fTemp28 > 0.0f) - (fTemp28 < 0.0f)));
			fVec11[0] = fTemp29;
			fRec33[0] = 0.20510091f * (fTemp29 + fVec11[1]) - 0.45006347f * fRec33[1];
			fRec32[0] = fRec33[0] - (0.9743205f * fRec32[1] + 0.3016787f * fRec32[2]);
			fRec31[0] = 1.1379995f * fRec32[1] + 0.56899977f * (fRec32[0] + fRec32[2]) - (1.242428f * fRec31[1] + 0.6598665f * fRec31[2]);
			float fThen8 = 1.8f * fTemp23;
			float fTemp30 = ((fTemp22 > 1.8f) ? fTemp21 : fThen8);
			float fTemp31 = fTemp30 - 1.8f * float((fTemp30 > 0.0f) - (fTemp30 < 0.0f));
			fVec12[0] = fTemp31;
			fRec36[0] = 7.34827f * (fTemp31 + fVec12[1]) - 0.45006347f * fRec36[1];
			fRec35[0] = fRec36[0] - (0.9743205f * fRec35[1] + 0.3016787f * fRec35[2]);
			fRec34[0] = 1.1379995f * fRec35[1] + 0.56899977f * (fRec35[0] + fRec35[2]) - (1.242428f * fRec34[1] + 0.6598665f * fRec34[2]);
			float fThen9 = 4.08f * fTemp23;
			float fTemp32 = ((fTemp22 > 4.08f) ? fTemp21 : fThen9);
			float fTemp33 = fTemp32 - 4.08f * float((fTemp32 > 0.0f) - (fTemp32 < 0.0f));
			fVec13[0] = fTemp33;
			fRec39[0] = 7.048144f * (fTemp33 + fVec13[1]) - 0.45006347f * fRec39[1];
			fRec38[0] = fRec39[0] - (0.9743205f * fRec38[1] + 0.3016787f * fRec38[2]);
			fRec37[0] = 1.1379995f * fRec38[1] + 0.56899977f * (fRec38[0] + fRec38[2]) - (1.242428f * fRec37[1] + 0.6598665f * fRec37[2]);
			fRec42[0] = 3.6251585f * (fTemp21 + fVec8[1]) - 0.45006347f * fRec42[1];
			fRec41[0] = fRec42[0] - (0.9743205f * fRec41[1] + 0.3016787f * fRec41[2]);
			fRec40[0] = 1.1379995f * fRec41[1] + 0.56899977f * (fRec41[0] + fRec41[2]) - (1.242428f * fRec40[1] + 0.6598665f * fRec40[2]);
			float fTemp34 = 1.4511472f * (fRec25[1] + fRec28[1] + fRec31[1] + fRec34[1] + fRec37[1] + fRec40[1]) + 0.7255736f * (fRec25[0] + fRec25[2] + fRec28[0] + fRec28[2] + fRec31[0] + fRec31[2] + fRec34[0] + fRec34[2] + fRec37[0] + fRec37[2] + fRec40[0] + fRec40[2]);
			fVec14[0] = fTemp34;
			fRec24[0] = 0.0f - (fTemp17 * fRec24[1] - (fTemp34 + fVec14[1])) / fTemp18;
			float fTemp35 = std::max<float>(-1.0f, std::min<float>(1.0f, 0.16666667f * fRec24[0]));
			float fTemp36 = fTemp35 * (1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp35));
			fVec15[0] = fTemp36;
			fRec23[0] = fConst2 * (fTemp36 - fVec15[1] + fConst5 * fRec23[1]);
			output1[i0] = FAUSTFLOAT(fRec23[0]);
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fVec0[1] = fVec0[0];
			fVec1[1] = fVec1[0];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fVec2[1] = fVec2[0];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fVec3[1] = fVec3[0];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fVec4[1] = fVec4[0];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fVec5[1] = fVec5[0];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec21[1] = fRec21[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fVec6[1] = fVec6[0];
			fRec22[1] = fRec22[0];
			fRec1[1] = fRec1[0];
			fVec7[1] = fVec7[0];
			fRec0[1] = fRec0[0];
			fVec8[1] = fVec8[0];
			fVec9[1] = fVec9[0];
			fRec27[1] = fRec27[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fVec10[1] = fVec10[0];
			fRec30[1] = fRec30[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fVec11[1] = fVec11[0];
			fRec33[1] = fRec33[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fVec12[1] = fVec12[0];
			fRec36[1] = fRec36[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fVec13[1] = fVec13[0];
			fRec39[1] = fRec39[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec42[1] = fRec42[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fVec14[1] = fVec14[0];
			fRec24[1] = fRec24[0];
			fVec15[1] = fVec15[0];
			fRec23[1] = fRec23[0];
		}
	}

};

#endif
