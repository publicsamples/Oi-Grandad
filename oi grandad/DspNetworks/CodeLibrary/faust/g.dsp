declare name "Granulator";
declare author "Mayank Sanganeria";
declare version "1.0";

// Controls
N = hslider("grain density", 1, 1, maxN, 1);
gLength = hslider("grain length", 0.1, 0.01, 0.5, 0.01);
dLength = hslider("delay length", 10, 0.5, 10, 0.1);

// Globals
SR = fconstant(int fSamplingFreq, <math.h>);
counter = +(1)%delayLength~_; // to iterate through the delay line
delayBufferSize = 480000;
maxN = 64;

//Granular synth variables
grainLength = int(SR*gLength);
delayLength = int(SR*dLength);


//Noise Generator

S(1,F) = F;
S(i,F) = F <: S(i-1,F),_ ;
Divide(n,k) = par(i, n, /(k)) ;
random = +(12345) : *(1103515245) ;
RANDMAX = 2^32 - 1 ;
chain(n) = S(n,random) ~ _;
NoiseN(n) = chain(n) : Divide(n,RANDMAX);

noiser = NoiseN(maxN+1);                          //multi channel noiser

NoiseChan(n,0) = noiser:>_,par( j, n-1 , !);
NoiseChan(n,i) = noiser:>par( j, i , !) , _, par( j, n-i-1,!);

noise(i) = (NoiseChan(maxN+1,i) + 1) / 2; //get nth channel of multi-channel noiser
//-------------Noise Generator End

//Sample & Hold
SH(trig,x) = (*(1 - trig) + x * trig) ~ _;


//Grain Positions
grainOffset(i) = int(SH(1-1',int(delayLength*noise(i)))) ;
grainCounterMaster = +(1)%grainLength~_;      // universal counter for all grains
grainCounter(i) = (grainCounterMaster + grainOffset(i) ) % grainLength;
grainRandomStartPos(i) = int(SH(int(grainCounter(i)/(grainLength-1)),int(delayLength*noise(i))));
grainPosition(i) = grainCounter(i) + grainRandomStartPos(i);

//Delay Line
buffer(write,read,x) = rwtable(delayBufferSize, 0.0, write%delayLength, x, read%delayLength);

//sin wave for windowing
window(i) = sin(2*3.14159*grainCounter(i)/(grainLength-1));

process = _<: par(i,maxN,buffer(counter, grainPosition(i))*window(i)*(i<N)/N) :> _,_;