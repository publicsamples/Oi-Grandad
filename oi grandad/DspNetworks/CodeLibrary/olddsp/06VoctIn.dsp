declare owl "[voct:input]";

import("stdfaust.lib");
import("owl.lib");

tune = hslider("Tune[OWL:A]", 0, -2, 2, 0.01);

process = sample2hertz(tune) : os.oscs;
