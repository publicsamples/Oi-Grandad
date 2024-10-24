import("stdfaust.lib");

//Average filter
filterLength = 500;
movingAvg(x) = par(i, filterLength, x@(i)):>_/filterLength;

//Delay handle delay
delayAvg = delMs * (ma.SR/1000) : movingAvg;
delSec = delMs / 1000;

//Measured tape speed= 8ips = 0.203 m/s
//headDist = 0.203 * delSec; //[m] Not used

//creating an angular frequency
pulse(freq) = os.lf_saw(freq) * (ma.PI);

//phasenoise frequency is related to drift freq: i want smooth changes->freq has to be lower for 
//low freq drift while noise amplitude has to be higher 
delDrift1 = sin(sinArg) * ampliSec * ma.SR //Capstan: Observed amplitude = 0.15 ms
with
{
    phaseNoise = (no.noise*5) : fi.lowpass6e(100); //adding noise to phase
    freq = 26;
    phase = ma.PI * 3/2 + phaseNoise;
    sinArg = pulse(freq) + phase;
    ampliSec = 0.00015;
}; 
delDrift2 = sin(sinArg) * ampliSec * ma.SR //Pinch wheel1: Observed amplitude = 0.15 ms
with
{
    phaseNoise = (no.noise*7) : fi.lowpass6e(35); //adding noise to phase
    freq = 5;
    phase = 0 + phaseNoise; //not visible in paper
    sinArg = pulse(freq) + phase;
    ampliSec = 0.00010 * delSec;
};   
delDrift3 = sin(sinArg) * ampliSec * ma.SR //Pinch wheel2: Observed amplitude = 0.75 ms
with
{
    phaseNoise = (no.noise*20) : fi.lowpass6e(20); //adding noise to phase
    freq = 2.5;
    phase = ma.PI * 3/4 + phaseNoise;
    sinArg = pulse(freq) + phase;
    ampliSec = 0.00075 * delSec;
};  

//Noise
delNoise = (no.noise* noiseAmp * ma.SR) : LPfilter
with
{
    //Noise is proportional to head separation.
    noiseAmp = 0.00075 * delSec;
    LPfilter = fi.lowpass3e(70);
};

//0.75 is a factor to make the overall variation level similar to the paper
delayTotal = ((delDrift1 + delDrift2 + delDrift3 + delNoise)*0.75) + delayAvg;

//Variable comb filter
pole = 0.9999;
filterDel = startFactor + ((endFactor-startFactor) * delSec) : int
with
{   //48000 hardcoded SR, for some reason it does not work with ma.SR
    firstNotchFreqStart = 7.5; //[Hz]
    firstNotchFreqEnd = 2;
    startFactor = 48000/(2 * firstNotchFreqStart);
    endFactor = 48000/(2 * firstNotchFreqEnd);
};
ffComb(delay, pole) = _<:_, _@delay*pole :> _/2; 

delayProcessed = delayTotal : ffComb(filterDel, pole) : int;

//Actual Delay + feedback
delayFunction(n, d, x) = x @ min(n, max(0, d));
feedback(x) = (x : tapeSat + x ~ (delay * repeats)) : filter
with
{
    tapeSat = co.limiter_1176_R4_mono;
    delay = delayFunction(50000, delayProcessed, x);
   filter = fi.lowpass(2,7000);
};

//Nonlinear distortion
//amplifier(g) = ef.cubicnl_nodc(g, 0.1); //Not used

//User params
delMs = hslider("delay(ms)", 300, 1, 1000, 1);
repeats = vslider("feedback[style:knob]", 0.5, 0, 2, 0.01);
//echoLevel = vslider("Echo Volume[style:knob]", 0.5, 0, 1, 0.01); //Not used

delay_module(dtime,phase) = rwtable(MAX_DELAY,0.0,indexphasor(dtime,phase):int,_,indexphasor(dtime,phase+1):int):window with{
  window =  *( sin(0.5*ma.PI* phasor_phase(dtime,phase)/dtime));
};//init have to be 0.0 floating point
reversedelay_mono(dtime) = _<:delay_module(dtime,0),delay_module(dtime,dtime/2):>_;

/*Process*/
process = feedback(_) <: _, _;