import("stdfaust.lib");


Q = hslider("Q",1,0.5,10,0.01);
normFreq = hslider("freq",0.5,0,1,0.001):si.smoo;


process = ve.oberheimBPF(normFreq,Q) <:_,_;
