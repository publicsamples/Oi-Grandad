import("stdfaust.lib");

freq = hslider("Frequency[OWL:A]", 60, 60, 440, 1);

process = os.osc(freq);
