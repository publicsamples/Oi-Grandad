/* ------------------------------------------------------------
author: "Adapted from sfIter by Christophe Lebreton"
name: "Granulator"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _granul -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___granul_H__
#define  ___granul_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _granul
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


struct _granul final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider0;
	float fVec0[2];
	float fRec1[2];
	float fConst4;
	int iRec3[2];
	float fRec5[2];
	float fVec1[2];
	int IOTA0;
	int iVec2[128];
	FAUSTFLOAT fHslider1;
	float fVec3[2];
	float fRec6[2];
	float fRec7[2];
	int iVec4[2];
	FAUSTFLOAT fHslider2;
	float fRec4[2];
	float fRec2[2];
	float fRec0[2];
	
	_granul() {
	}
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.2.0");
		m->declare("author", "Adapted from sfIter by Christophe Lebreton");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.19.1");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _granul -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("filename", "granul.dsp");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "Granulator");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.4.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
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
		fConst1 = 1.0f / std::tan(3.1415927f / fConst0);
		fConst2 = 1.0f / (fConst1 + 1.0f);
		fConst3 = 1.0f - fConst1;
		fConst4 = 1.0f / fConst0;
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1e+01f);
		fHslider1 = FAUSTFLOAT(7e+01f);
		fHslider2 = FAUSTFLOAT(2e+02f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iRec3[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fVec1[l4] = 0.0f;
		}
		IOTA0 = 0;
		for (int l5 = 0; l5 < 128; l5 = l5 + 1) {
			iVec2[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fVec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec6[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			iVec4[l9] = 0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec4[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec2[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec0[l12] = 0.0f;
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
	
	_granul* clone() {
		return new _granul();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Granulator");
		ui_interface->openHorizontalBox("Granulator");
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->declare(&fHslider2, "BELA", "ANALOG_0");
		ui_interface->addHorizontalSlider("GrainSize", &fHslider2, FAUSTFLOAT(2e+02f), FAUSTFLOAT(5.0f), FAUSTFLOAT(2205.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->declare(&fHslider0, "BELA", "ANALOG_1");
		ui_interface->addHorizontalSlider("Speed", &fHslider0, FAUSTFLOAT(1e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.0001f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->declare(&fHslider1, "BELA", "ANALOG_2");
		ui_interface->addHorizontalSlider("Probability", &fHslider1, FAUSTFLOAT(7e+01f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(1.0f, std::min<float>(2e+01f, float(fHslider0)));
		float fSlow1 = std::max<float>(5e+01f, std::min<float>(1e+02f, float(fHslider1)));
		float fSlow2 = 1.0f / std::max<float>(5.0f, std::min<float>(2205.0f, float(fHslider2)));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fVec0[0] = fSlow0;
			fRec1[0] = -(fConst2 * (fConst3 * fRec1[1] - (fSlow0 + fVec0[1])));
			float fTemp0 = 0.0625f / fRec1[0];
			int iTemp1 = std::fabs(fTemp0) < 1.1920929e-07f;
			float fTemp2 = ((iTemp1) ? 0.0f : std::exp(-(fConst4 / ((iTemp1) ? 1.0f : fTemp0))));
			float fTemp3 = 1.0f - fTemp2;
			iRec3[0] = 1103515245 * iRec3[1] + 12345;
			float fTemp4 = float(iRec3[0]);
			fRec5[0] = std::fmod(fRec5[1] + fConst4 * fRec1[0], 1.0f);
			float fTemp5 = fRec5[0] + -0.001f;
			fVec1[0] = fTemp5;
			iVec2[IOTA0 & 127] = fTemp5 < 0.5f;
			fVec3[0] = fSlow1;
			fRec6[0] = fConst2 * (0.01f * (fSlow1 + fVec3[1]) - fConst3 * fRec6[1]);
			int iTemp6 = (fVec1[1] <= 0.0f) & (fTemp5 > 0.0f);
			fRec7[0] = fRec7[1] * float(1 - iTemp6) + std::fabs(4.656613e-10f * fTemp4) * float(iTemp6);
			int iTemp7 = iVec2[(IOTA0 - 100) & 127] * (fRec6[0] > fRec7[0]);
			iVec4[0] = iTemp7;
			fRec4[0] = fRec4[1] + float((iTemp7 - iVec4[1]) > 0) - fSlow2 * float(fRec4[1] > 0.0f);
			float fTemp8 = std::fabs(4.656613e-10f * fTemp4 * float(fRec4[0] > 0.0f));
			fRec2[0] = std::max<float>(fTemp8, fTemp2 * fRec2[1] + fTemp3 * fTemp8);
			fRec0[0] = fTemp3 * fRec2[0] + fTemp2 * fRec0[1];
			output0[i0] = FAUSTFLOAT(fRec0[0] * float(input0[i0]));
			output1[i0] = FAUSTFLOAT(fRec0[0] * float(input1[i0]));
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			iRec3[1] = iRec3[0];
			fRec5[1] = fRec5[0];
			fVec1[1] = fVec1[0];
			IOTA0 = IOTA0 + 1;
			fVec3[1] = fVec3[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			iVec4[1] = iVec4[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "granul.dsp"
	#define FAUST_CLASS_NAME "_granul"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _granul -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 3
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Granulator/Granulator/GrainSize", fHslider2, 2e+02f, 5.0f, 2205.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("Granulator/Granulator/Speed", fHslider0, 1e+01f, 1.0f, 2e+01f, 0.0001f);
	FAUST_ADDHORIZONTALSLIDER("Granulator/Granulator/Probability", fHslider1, 7e+01f, 5e+01f, 1e+02f, 1.0f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, GrainSize, "Granulator/Granulator/GrainSize", fHslider2, 2e+02f, 5.0f, 2205.0f, 1.0f) \
		p(HORIZONTALSLIDER, Speed, "Granulator/Granulator/Speed", fHslider0, 1e+01f, 1.0f, 2e+01f, 0.0001f) \
		p(HORIZONTALSLIDER, Probability, "Granulator/Granulator/Probability", fHslider1, 7e+01f, 5e+01f, 1e+02f, 1.0f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
