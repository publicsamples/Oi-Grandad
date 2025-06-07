import("stdfaust.lib");

t60 = hslider("t60",0,0,100,0.01);

freq = hslider("freq",0,0,1,0.01);
gain = hslider("gain",0,0,1,0.01);

process = pm.modeFilter(t60,gain,freq), pm.modeFilter(t60,gain,freq);
