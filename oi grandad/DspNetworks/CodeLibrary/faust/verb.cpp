/* ------------------------------------------------------------
author: "Oli Larkin (contact@olilarkin.co.uk)"
copyright: "Oliver Larkin"
name: "Blipper"
version: "0.2"
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
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	int iVec0[2];
	float fRec0[2];
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider1;
	float fRec2[2];
	float fRec1[2];
	float fConst5;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	float fRec6[2];
	float fRec4[2];
	float fVec1[2];
	int IOTA0;
	float fVec2[4096];
	float fConst8;
	float fRec3[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.2");
		m->declare("author", "Oli Larkin (contact@olilarkin.co.uk)");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.8");
		m->declare("compile_options", "-lang cpp -es 1 -mcd 16 -single -ftz 0");
		m->declare("copyright", "Oliver Larkin");
		m->declare("description", "Envelope Follower controlling pitch of a triangle oscillator, good with percussive input");
		m->declare("filename", "verb.dsp");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("licence", "GPL");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "Blipper");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.3");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.3");
		m->declare("version", "0.2");
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
		fConst1 = std::exp(0.0f - 2e+02f / fConst0);
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.76e+03f / fConst0;
		fConst4 = 1.0f / fConst0;
		fConst5 = 0.25f * fConst0;
		fConst6 = std::exp(0.0f - 1e+02f / fConst0);
		fConst7 = 1.0f - fConst6;
		fConst8 = 0.5f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(2e+01f);
		fHslider2 = FAUSTFLOAT(6e+01f);
		fHslider3 = FAUSTFLOAT(24.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec4[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fVec1[l7] = 0.0f;
		}
		IOTA0 = 0;
		for (int l8 = 0; l8 < 4096; l8 = l8 + 1) {
			fVec2[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec3[l9] = 0.0f;
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
		ui_interface->openVerticalBox("Blipper");
		ui_interface->declare(&fHslider2, "OWL", "PARAMETER_A");
		ui_interface->declare(&fHslider2, "unit", "semitones");
		ui_interface->addHorizontalSlider("BasePitch", &fHslider2, FAUSTFLOAT(6e+01f), FAUSTFLOAT(24.0f), FAUSTFLOAT(96.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider0, "OWL", "PARAMETER_D");
		ui_interface->addHorizontalSlider("Mix", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "OWL", "PARAMETER_B");
		ui_interface->declare(&fHslider3, "unit", "semitones");
		ui_interface->addHorizontalSlider("PitchMod", &fHslider3, FAUSTFLOAT(24.0f), FAUSTFLOAT(-64.0f), FAUSTFLOAT(64.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "OWL", "PARAMETER_C");
		ui_interface->declare(&fHslider1, "unit", "ms");
		ui_interface->addHorizontalSlider("Release", &fHslider1, FAUSTFLOAT(2e+01f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst2 * float(fHslider0);
		float fSlow1 = std::max<float>(fConst4, 0.001f * float(fHslider1));
		int iSlow2 = std::fabs(fSlow1) < 1.1920929e-07f;
		float fThen1 = std::exp(0.0f - fConst4 / ((iSlow2) ? 1.0f : fSlow1));
		float fSlow3 = ((iSlow2) ? 0.0f : fThen1);
		float fSlow4 = 1.0f - fSlow3;
		float fSlow5 = fConst7 * float(fHslider2);
		float fSlow6 = fConst2 * float(fHslider3);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]);
			iVec0[0] = 1;
			fRec0[0] = fSlow0 + fConst1 * fRec0[1];
			float fTemp1 = 1.0f - fRec0[0];
			float fTemp2 = float(input1[i0]);
			float fTemp3 = std::fabs(fTemp0 + fTemp2);
			fRec2[0] = std::max<float>(fTemp3, fRec2[1] * fSlow3 + fTemp3 * fSlow4);
			fRec1[0] = fConst2 * fRec2[0] + fConst1 * fRec1[1];
			fRec5[0] = fSlow5 + fConst6 * fRec5[1];
			fRec6[0] = fSlow6 + fConst1 * fRec6[1];
			float fTemp4 = std::pow(2.0f, 0.083333336f * (fRec5[0] + fRec6[0] * fRec1[0] + -69.0f));
			float fTemp5 = std::max<float>(4.4e+02f * fTemp4, 23.44895f);
			float fTemp6 = std::max<float>(2e+01f, std::fabs(fTemp5));
			float fTemp7 = fRec4[1] + fConst4 * fTemp6;
			fRec4[0] = fTemp7 - std::floor(fTemp7);
			float fTemp8 = mydsp_faustpower2_f(2.0f * fRec4[0] + -1.0f);
			fVec1[0] = fTemp8;
			float fTemp9 = float(iVec0[1]) * (fTemp8 - fVec1[1]) / fTemp6;
			fVec2[IOTA0 & 4095] = fTemp9;
			float fTemp10 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fTemp5));
			int iTemp11 = int(fTemp10);
			float fTemp12 = std::floor(fTemp10);
			fRec3[0] = 0.999f * fRec3[1] + fConst5 * (fTemp9 - fVec2[(IOTA0 - iTemp11) & 4095] * (fTemp12 + (1.0f - fTemp10)) - (fTemp10 - fTemp12) * fVec2[(IOTA0 - (iTemp11 + 1)) & 4095]);
			float fTemp13 = fConst3 * fRec0[0] * fRec1[0] * fRec3[0] * fTemp4;
			output0[i0] = FAUSTFLOAT(fTemp0 * fTemp1 + fTemp13);
			output1[i0] = FAUSTFLOAT(fTemp2 * fTemp1 + fTemp13);
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fVec1[1] = fVec1[0];
			IOTA0 = IOTA0 + 1;
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
