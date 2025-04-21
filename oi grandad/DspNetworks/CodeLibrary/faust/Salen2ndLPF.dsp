// Faust Source File: Salen2ndLPF
// Created with HISE on 2025-01-07
import("stdfaust.lib");


Q = hslider("Q",1,0.5,10,0.01);
normFreq = hslider("freq",0.5,0,1,0.001):si.smoo;


process = ve.sallenKey2ndOrderLPF(normFreq,Q) <:_,_;
