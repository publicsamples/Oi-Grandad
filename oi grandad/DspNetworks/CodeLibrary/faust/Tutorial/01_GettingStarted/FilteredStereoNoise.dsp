import("stdfaust.lib");
import("owl.lib");

f = hslider("Frequency[OWL:A]",1000,10,3000,0.01);
diff = hslider("Difference[OWL:B]",0.5,0,1,0.01);
q = 5;
gain = 1;

process = no.noise * 0.5 <: fi.resonbp(f * diff, q, gain), fi.resonbp(f * (1-diff), q, gain);

