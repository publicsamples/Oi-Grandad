import("stdfaust.lib");
import("misceffects.lib");



process = dm.reverse_echo_demo(1);

reverse_echo_demo(nChans) =  ef.reverseEchoN(nChans,delMax) : ef.uniformPanToStereo(nChans) 
with {
    delMax = 2^int(nentry("Log2(Delay)",15,12,16,1)); // delay line length
};