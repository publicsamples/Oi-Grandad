import("stdfaust.lib");
import("misceffects.lib");

nChans = 2;

process = dm.reverse_echo_demo(nChans);

reverse_echo_demo(nChans) =  ef.reverseEchoN(nChans,delMax) : ef.reverseEchoN(nChans) 
with {
    delMax = 2^int(nentry("Log2(Delay)",15,12,16,1)); // delay line length
};