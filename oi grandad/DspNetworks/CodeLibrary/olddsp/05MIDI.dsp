declare options "[midi:on]";

import("stdfaust.lib");

freq = hslider("freq", 440, 20, 1000, 0.001);
gain = hslider("gain", 0.0, 0.0, 1.0, 0.001);
gate = button("gate");
sustain = hslider("Sustain[OWL:A]", 5.0, 1.0, 10.0, 0.01);

process = sy.combString(freq, gain * sustain, gate);
