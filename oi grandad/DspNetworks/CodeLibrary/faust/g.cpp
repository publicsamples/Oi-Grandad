/* ------------------------------------------------------------
author: "Mayank Sanganeria"
name: "Granulator"
version: "1.0"
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

class mydspSIG0 {
	
  private:
	
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			table[i1] = 0.0f;
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }


class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	float ftbl0[192000];
	int iVec0[2];
	FAUSTFLOAT fHslider1;
	int iRec0[2];
	FAUSTFLOAT fHslider2;
	int iRec2[2];
	int iRec4[2];
	int iRec3[2];
	int iRec1[2];
	int iRec21[2];
	int iRec20[2];
	int iRec23[2];
	int iRec22[2];
	int iRec25[2];
	int iRec24[2];
	int iRec27[2];
	int iRec26[2];
	int iRec29[2];
	int iRec28[2];
	int iRec31[2];
	int iRec30[2];
	int iRec33[2];
	int iRec32[2];
	int iRec35[2];
	int iRec34[2];
	int iRec37[2];
	int iRec36[2];
	int iRec39[2];
	int iRec38[2];
	int iRec41[2];
	int iRec40[2];
	int iRec43[2];
	int iRec42[2];
	int iRec45[2];
	int iRec44[2];
	int iRec47[2];
	int iRec46[2];
	int iRec49[2];
	int iRec48[2];
	int fSampleRate;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "Mayank Sanganeria");
		m->declare("compile_options", "-lang cpp -es 1 -mcd 16 -single -ftz 0");
		m->declare("filename", "g.dsp");
		m->declare("name", "Granulator");
		m->declare("version", "1.0");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(192000, ftbl0);
		deletemydspSIG0(sig0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(4.0f);
		fHslider2 = FAUSTFLOAT(0.1f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec0[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iRec2[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec4[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			iRec3[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iRec1[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			iRec21[l6] = 0;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iRec20[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			iRec23[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			iRec22[l9] = 0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			iRec25[l10] = 0;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iRec24[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			iRec27[l12] = 0;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			iRec26[l13] = 0;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			iRec29[l14] = 0;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			iRec28[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			iRec31[l16] = 0;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			iRec30[l17] = 0;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			iRec33[l18] = 0;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			iRec32[l19] = 0;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			iRec35[l20] = 0;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			iRec34[l21] = 0;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			iRec37[l22] = 0;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			iRec36[l23] = 0;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			iRec39[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			iRec38[l25] = 0;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			iRec41[l26] = 0;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			iRec40[l27] = 0;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			iRec43[l28] = 0;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			iRec42[l29] = 0;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			iRec45[l30] = 0;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			iRec44[l31] = 0;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			iRec47[l32] = 0;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			iRec46[l33] = 0;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			iRec49[l34] = 0;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			iRec48[l35] = 0;
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
		ui_interface->openVerticalBox("Granulator");
		ui_interface->declare(&fHslider1, "OWL", "PARAMETER_C");
		ui_interface->addHorizontalSlider("Delay", &fHslider1, FAUSTFLOAT(4.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider0, "OWL", "PARAMETER_A");
		ui_interface->addHorizontalSlider("Density", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(16.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "OWL", "PARAMETER_B");
		ui_interface->addHorizontalSlider("Size", &fHslider2, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.01f), FAUSTFLOAT(0.5f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = 1.0f / fSlow0;
		float fSlow2 = float(0.0f < fSlow0);
		int iSlow3 = int(4.8e+04f * float(fHslider1));
		int iSlow4 = int(4.8e+04f * float(fHslider2));
		float fSlow5 = float(iSlow4 + -1);
		float fSlow6 = 1.0f / fSlow5;
		float fSlow7 = 0.5f * float(iSlow3);
		float fSlow8 = 6.28318f / fSlow5;
		float fSlow9 = float(2.0f < fSlow0);
		float fSlow10 = float(4.0f < fSlow0);
		float fSlow11 = float(6.0f < fSlow0);
		float fSlow12 = float(8.0f < fSlow0);
		float fSlow13 = float(1e+01f < fSlow0);
		float fSlow14 = float(12.0f < fSlow0);
		float fSlow15 = float(14.0f < fSlow0);
		float fSlow16 = float(1.0f < fSlow0);
		float fSlow17 = float(3.0f < fSlow0);
		float fSlow18 = float(5.0f < fSlow0);
		float fSlow19 = float(7.0f < fSlow0);
		float fSlow20 = float(9.0f < fSlow0);
		float fSlow21 = float(11.0f < fSlow0);
		float fSlow22 = float(13.0f < fSlow0);
		float fSlow23 = float(15.0f < fSlow0);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			iRec0[0] = (iRec0[1] + 1) % iSlow3;
			ftbl0[iRec0[0] % iSlow3] = float(input0[i0]);
			iRec2[0] = (iRec2[1] + 1) % iSlow4;
			int iTemp0 = 1 - iVec0[1];
			int iTemp1 = 1103515245 * (iRec4[1] + 12345);
			int iTemp2 = 1103515245 * (iTemp1 + 12345);
			int iTemp3 = 1103515245 * (iTemp2 + 12345);
			int iTemp4 = 1103515245 * (iTemp3 + 12345);
			int iTemp5 = 1103515245 * (iTemp4 + 12345);
			int iTemp6 = 1103515245 * (iTemp5 + 12345);
			int iTemp7 = 1103515245 * (iTemp6 + 12345);
			int iTemp8 = 1103515245 * (iTemp7 + 12345);
			int iTemp9 = 1103515245 * (iTemp8 + 12345);
			int iTemp10 = 1103515245 * (iTemp9 + 12345);
			int iTemp11 = 1103515245 * (iTemp10 + 12345);
			int iTemp12 = 1103515245 * (iTemp11 + 12345);
			int iTemp13 = 1103515245 * (iTemp12 + 12345);
			int iTemp14 = 1103515245 * (iTemp13 + 12345);
			int iTemp15 = 1103515245 * (iTemp14 + 12345);
			int iTemp16 = 1103515245 * (iTemp15 + 12345);
			iRec4[0] = 1103515245 * (iTemp16 + 12345);
			int iRec5 = iTemp16;
			int iRec6 = iTemp15;
			int iRec7 = iTemp14;
			int iRec8 = iTemp13;
			int iRec9 = iTemp12;
			int iRec10 = iTemp11;
			int iRec11 = iTemp10;
			int iRec12 = iTemp9;
			int iRec13 = iTemp8;
			int iRec14 = iTemp7;
			int iRec15 = iTemp6;
			int iRec16 = iTemp5;
			int iRec17 = iTemp4;
			int iRec18 = iTemp3;
			int iRec19 = iTemp2;
			int iTemp17 = int(fSlow7 * (1.0f - float(iRec4[0])));
			iRec3[0] = iVec0[1] * iRec3[1] + iTemp0 * iTemp17;
			int iTemp18 = (iRec2[0] + iRec3[0]) % iSlow4;
			float fTemp19 = float(iTemp18);
			int iTemp20 = int(fSlow6 * fTemp19);
			iRec1[0] = iRec1[1] * (1 - iTemp20) + iTemp17 * iTemp20;
			int iTemp21 = int(fSlow7 * (1.0f - float(iRec6)));
			iRec21[0] = iVec0[1] * iRec21[1] + iTemp0 * iTemp21;
			int iTemp22 = (iRec2[0] + iRec21[0]) % iSlow4;
			float fTemp23 = float(iTemp22);
			int iTemp24 = int(fSlow6 * fTemp23);
			iRec20[0] = iRec20[1] * (1 - iTemp24) + iTemp21 * iTemp24;
			int iTemp25 = int(fSlow7 * (1.0f - float(iRec8)));
			iRec23[0] = iVec0[1] * iRec23[1] + iTemp0 * iTemp25;
			int iTemp26 = (iRec2[0] + iRec23[0]) % iSlow4;
			float fTemp27 = float(iTemp26);
			int iTemp28 = int(fSlow6 * fTemp27);
			iRec22[0] = iRec22[1] * (1 - iTemp28) + iTemp25 * iTemp28;
			int iTemp29 = int(fSlow7 * (1.0f - float(iRec10)));
			iRec25[0] = iVec0[1] * iRec25[1] + iTemp0 * iTemp29;
			int iTemp30 = (iRec2[0] + iRec25[0]) % iSlow4;
			float fTemp31 = float(iTemp30);
			int iTemp32 = int(fSlow6 * fTemp31);
			iRec24[0] = iRec24[1] * (1 - iTemp32) + iTemp29 * iTemp32;
			int iTemp33 = int(fSlow7 * (1.0f - float(iRec12)));
			iRec27[0] = iVec0[1] * iRec27[1] + iTemp0 * iTemp33;
			int iTemp34 = (iRec2[0] + iRec27[0]) % iSlow4;
			float fTemp35 = float(iTemp34);
			int iTemp36 = int(fSlow6 * fTemp35);
			iRec26[0] = iRec26[1] * (1 - iTemp36) + iTemp33 * iTemp36;
			int iTemp37 = int(fSlow7 * (1.0f - float(iRec14)));
			iRec29[0] = iVec0[1] * iRec29[1] + iTemp0 * iTemp37;
			int iTemp38 = (iRec2[0] + iRec29[0]) % iSlow4;
			float fTemp39 = float(iTemp38);
			int iTemp40 = int(fSlow6 * fTemp39);
			iRec28[0] = iRec28[1] * (1 - iTemp40) + iTemp37 * iTemp40;
			int iTemp41 = int(fSlow7 * (1.0f - float(iRec16)));
			iRec31[0] = iVec0[1] * iRec31[1] + iTemp0 * iTemp41;
			int iTemp42 = (iRec2[0] + iRec31[0]) % iSlow4;
			float fTemp43 = float(iTemp42);
			int iTemp44 = int(fSlow6 * fTemp43);
			iRec30[0] = iRec30[1] * (1 - iTemp44) + iTemp41 * iTemp44;
			int iTemp45 = int(fSlow7 * (1.0f - float(iRec18)));
			iRec33[0] = iVec0[1] * iRec33[1] + iTemp0 * iTemp45;
			int iTemp46 = (iRec2[0] + iRec33[0]) % iSlow4;
			float fTemp47 = float(iTemp46);
			int iTemp48 = int(fSlow6 * fTemp47);
			iRec32[0] = iRec32[1] * (1 - iTemp48) + iTemp45 * iTemp48;
			output0[i0] = FAUSTFLOAT(fSlow1 * (fSlow2 * ftbl0[(iRec1[0] + iTemp18) % iSlow3] * std::sin(fSlow8 * fTemp19) + fSlow9 * ftbl0[(iRec20[0] + iTemp22) % iSlow3] * std::sin(fSlow8 * fTemp23) + fSlow10 * ftbl0[(iRec22[0] + iTemp26) % iSlow3] * std::sin(fSlow8 * fTemp27) + fSlow11 * ftbl0[(iRec24[0] + iTemp30) % iSlow3] * std::sin(fSlow8 * fTemp31) + fSlow12 * ftbl0[(iRec26[0] + iTemp34) % iSlow3] * std::sin(fSlow8 * fTemp35) + fSlow13 * ftbl0[(iRec28[0] + iTemp38) % iSlow3] * std::sin(fSlow8 * fTemp39) + fSlow14 * ftbl0[(iRec30[0] + iTemp42) % iSlow3] * std::sin(fSlow8 * fTemp43) + fSlow15 * ftbl0[(iRec32[0] + iTemp46) % iSlow3] * std::sin(fSlow8 * fTemp47)));
			int iTemp49 = int(fSlow7 * (1.0f - float(iRec5)));
			iRec35[0] = iVec0[1] * iRec35[1] + iTemp0 * iTemp49;
			int iTemp50 = (iRec2[0] + iRec35[0]) % iSlow4;
			float fTemp51 = float(iTemp50);
			int iTemp52 = int(fSlow6 * fTemp51);
			iRec34[0] = iRec34[1] * (1 - iTemp52) + iTemp49 * iTemp52;
			int iTemp53 = int(fSlow7 * (1.0f - float(iRec7)));
			iRec37[0] = iVec0[1] * iRec37[1] + iTemp0 * iTemp53;
			int iTemp54 = (iRec2[0] + iRec37[0]) % iSlow4;
			float fTemp55 = float(iTemp54);
			int iTemp56 = int(fSlow6 * fTemp55);
			iRec36[0] = iRec36[1] * (1 - iTemp56) + iTemp53 * iTemp56;
			int iTemp57 = int(fSlow7 * (1.0f - float(iRec9)));
			iRec39[0] = iVec0[1] * iRec39[1] + iTemp0 * iTemp57;
			int iTemp58 = (iRec2[0] + iRec39[0]) % iSlow4;
			float fTemp59 = float(iTemp58);
			int iTemp60 = int(fSlow6 * fTemp59);
			iRec38[0] = iRec38[1] * (1 - iTemp60) + iTemp57 * iTemp60;
			int iTemp61 = int(fSlow7 * (1.0f - float(iRec11)));
			iRec41[0] = iVec0[1] * iRec41[1] + iTemp0 * iTemp61;
			int iTemp62 = (iRec2[0] + iRec41[0]) % iSlow4;
			float fTemp63 = float(iTemp62);
			int iTemp64 = int(fSlow6 * fTemp63);
			iRec40[0] = iRec40[1] * (1 - iTemp64) + iTemp61 * iTemp64;
			int iTemp65 = int(fSlow7 * (1.0f - float(iRec13)));
			iRec43[0] = iVec0[1] * iRec43[1] + iTemp0 * iTemp65;
			int iTemp66 = (iRec2[0] + iRec43[0]) % iSlow4;
			float fTemp67 = float(iTemp66);
			int iTemp68 = int(fSlow6 * fTemp67);
			iRec42[0] = iRec42[1] * (1 - iTemp68) + iTemp65 * iTemp68;
			int iTemp69 = int(fSlow7 * (1.0f - float(iRec15)));
			iRec45[0] = iVec0[1] * iRec45[1] + iTemp0 * iTemp69;
			int iTemp70 = (iRec2[0] + iRec45[0]) % iSlow4;
			float fTemp71 = float(iTemp70);
			int iTemp72 = int(fSlow6 * fTemp71);
			iRec44[0] = iRec44[1] * (1 - iTemp72) + iTemp69 * iTemp72;
			int iTemp73 = int(fSlow7 * (1.0f - float(iRec17)));
			iRec47[0] = iVec0[1] * iRec47[1] + iTemp0 * iTemp73;
			int iTemp74 = (iRec2[0] + iRec47[0]) % iSlow4;
			float fTemp75 = float(iTemp74);
			int iTemp76 = int(fSlow6 * fTemp75);
			iRec46[0] = iRec46[1] * (1 - iTemp76) + iTemp73 * iTemp76;
			int iTemp77 = int(fSlow7 * (1.0f - float(iRec19)));
			iRec49[0] = iVec0[1] * iRec49[1] + iTemp0 * iTemp77;
			int iTemp78 = (iRec2[0] + iRec49[0]) % iSlow4;
			float fTemp79 = float(iTemp78);
			int iTemp80 = int(fSlow6 * fTemp79);
			iRec48[0] = iRec48[1] * (1 - iTemp80) + iTemp77 * iTemp80;
			output1[i0] = FAUSTFLOAT(fSlow1 * (fSlow16 * ftbl0[(iRec34[0] + iTemp50) % iSlow3] * std::sin(fSlow8 * fTemp51) + fSlow17 * ftbl0[(iRec36[0] + iTemp54) % iSlow3] * std::sin(fSlow8 * fTemp55) + fSlow18 * ftbl0[(iRec38[0] + iTemp58) % iSlow3] * std::sin(fSlow8 * fTemp59) + fSlow19 * ftbl0[(iRec40[0] + iTemp62) % iSlow3] * std::sin(fSlow8 * fTemp63) + fSlow20 * ftbl0[(iRec42[0] + iTemp66) % iSlow3] * std::sin(fSlow8 * fTemp67) + fSlow21 * ftbl0[(iRec44[0] + iTemp70) % iSlow3] * std::sin(fSlow8 * fTemp71) + fSlow22 * ftbl0[(iRec46[0] + iTemp74) % iSlow3] * std::sin(fSlow8 * fTemp75) + fSlow23 * ftbl0[(iRec48[0] + iTemp78) % iSlow3] * std::sin(fSlow8 * fTemp79)));
			iVec0[1] = iVec0[0];
			iRec0[1] = iRec0[0];
			iRec2[1] = iRec2[0];
			iRec4[1] = iRec4[0];
			iRec3[1] = iRec3[0];
			iRec1[1] = iRec1[0];
			iRec21[1] = iRec21[0];
			iRec20[1] = iRec20[0];
			iRec23[1] = iRec23[0];
			iRec22[1] = iRec22[0];
			iRec25[1] = iRec25[0];
			iRec24[1] = iRec24[0];
			iRec27[1] = iRec27[0];
			iRec26[1] = iRec26[0];
			iRec29[1] = iRec29[0];
			iRec28[1] = iRec28[0];
			iRec31[1] = iRec31[0];
			iRec30[1] = iRec30[0];
			iRec33[1] = iRec33[0];
			iRec32[1] = iRec32[0];
			iRec35[1] = iRec35[0];
			iRec34[1] = iRec34[0];
			iRec37[1] = iRec37[0];
			iRec36[1] = iRec36[0];
			iRec39[1] = iRec39[0];
			iRec38[1] = iRec38[0];
			iRec41[1] = iRec41[0];
			iRec40[1] = iRec40[0];
			iRec43[1] = iRec43[0];
			iRec42[1] = iRec42[0];
			iRec45[1] = iRec45[0];
			iRec44[1] = iRec44[0];
			iRec47[1] = iRec47[0];
			iRec46[1] = iRec46[0];
			iRec49[1] = iRec49[0];
			iRec48[1] = iRec48[0];
		}
	}

};

#endif
