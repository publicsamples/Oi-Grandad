/* ------------------------------------------------------------
name: "07VoctOut"
Code generated with Faust 2.50.6 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>
#include <owl.h>

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
	int iRec1[2];
	float fConst2;
	int iVec1[2];
	int iRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.8");
		m->declare("compile_options", "-lang cpp -es 1 -mcd 16 -single -ftz 0");
		m->declare("filename", "07VoctOut.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "07VoctOut");
		m->declare("owl", "[voct:output]");
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
		fConst1 = 3e+01f * fConst0;
		fConst2 = 15.0f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(1.2e+02f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec1[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iVec1[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec0[l3] = 0;
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
		ui_interface->openVerticalBox("07VoctOut");
		ui_interface->declare(&fHslider1, "OWL", "B");
		ui_interface->addHorizontalSlider("BPM", &fHslider1, FAUSTFLOAT(1.2e+02f), FAUSTFLOAT(8e+01f), FAUSTFLOAT(1.6e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider0, "OWL", "A");
		ui_interface->addHorizontalSlider("Tune", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = 0.083333336f * float(int(float(fHslider0)));
		float fSlow1 = float(fHslider1);
		int iSlow2 = int(fConst1 / fSlow1);
		float fSlow3 = fConst2 / fSlow1;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			iRec1[0] = (iVec0[1] + iRec1[1]) % iSlow2;
			int iTemp0 = float(iRec1[0]) < fSlow3;
			iVec1[0] = iTemp0;
			int iTemp1 = iTemp0 - iVec1[1];
			iRec0[0] = (iTemp1 * (iTemp1 > 0) + iRec0[1]) % 8;
			int iThen2 = ((iRec0[0] >= 1) ? 40 : 36);
			int iElse2 = ((iRec0[0] >= 3) ? 47 : 43);
			int iThen5 = ((iRec0[0] >= 5) ? 47 : 48);
			int iElse5 = ((iRec0[0] >= 7) ? 40 : 43);
			int iThen6 = ((iRec0[0] >= 2) ? iElse2 : iThen2);
			int iElse6 = ((iRec0[0] >= 6) ? iElse5 : iThen5);
			output0[i0] = FAUSTFLOAT(hertz2sample(fSlow0, 4.4e+02f * std::pow(2.0f, 0.083333336f * (float(((iRec0[0] >= 4) ? iElse6 : iThen6)) + -69.0f))));
			output1[i0] = FAUSTFLOAT(iTemp0);
			iVec0[1] = iVec0[0];
			iRec1[1] = iRec1[0];
			iVec1[1] = iVec1[0];
			iRec0[1] = iRec0[0];
		}
	}

};

#endif
