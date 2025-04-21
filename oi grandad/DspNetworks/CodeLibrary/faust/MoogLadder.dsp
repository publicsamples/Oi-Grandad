import("stdfaust.lib");


Q = hslider("Q",1,0.7072,25,0.01);
normFreq = hslider("freq",0.1,0,1,0.001):si.smoo;


process = ve.moogLadder(normFreq,Q) <:_,_;
