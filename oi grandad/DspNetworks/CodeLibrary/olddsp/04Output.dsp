import("stdfaust.lib");
import("owl.lib");

freq     = hslider("Frequency[OWL:A]", 60, 60, 440, 1);
lfo_freq = hslider("LFO frequency[OWL:B]", 0.3, 0.01, 1.0, 0.01) : si.smoo;
lfo_out  = hbargraph("LFO>[OWL:C]", -1, 1);

process = attach(os.osc(freq), os.osc(lfo_freq) : lfo_out);
