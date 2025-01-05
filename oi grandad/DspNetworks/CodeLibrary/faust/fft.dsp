declare name "dattorro";
declare version "0.1";
declare author "Jakob Zerbian";
declare description "Dattorro demo application.";

import("stdfaust.lib");

process = dm.mth_octave_filterbank_demo(8), dm.mth_octave_filterbank_demo(8);	