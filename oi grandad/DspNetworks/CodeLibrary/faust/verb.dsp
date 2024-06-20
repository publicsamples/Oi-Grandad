declare name "Dual Pitch Shifter";
declare description "Dual Channel pitch shifter, based on Faust pitch_shifter.dsp by Grame";
declare author "Oli Larkin (contact@olilarkin.co.uk)";
declare copyright "Oliver Larkin";
declare version "0.1";
declare licence "GPL";

import("stdfaust.lib");

msec = ma.SR/1000.0;
shiftl = hslider("Shift L [unit:Hz] [OWL:PARAMETER_A]", 440,50,2000,0.1);
shiftr = hslider("Shift R [unit:Hz] [OWL:PARAMETER_B]", 440,50,2000,0.1);
ws = hslider("Window Size [unit:ms] [OWL:PARAMETER_C]", 50, 20, 1000, 1) * msec : si.smooth(ba.tau2pole(0.005));
mix = hslider("Mix[OWL:PARAMETER_D]", 0.5, 0, 1, 0.01) : si.smooth(ba.tau2pole(0.005));

xf = 20 * msec;

transpose (w, x, s, sig) = de.fdelay(65536, d,sig)*ma.fmin(d/x,1) + de.fdelay(65536,d+w,sig)*(1-ma.fmin(d/x,1))
with {
  i = 1 - pow(2, s/12);
  d = i : (+ : +(w) : fmod(_,w)) ~ _;
};
	
process(l,r) = l,r <: *(1-mix), *(1-mix), transpose(ws, xf, shiftl, l)*mix, transpose(ws, xf, shiftr, r)*mix :> _,_;
