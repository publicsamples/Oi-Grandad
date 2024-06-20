# Faust Tutorial 1: Getting Started

## Overview
Faust is a functional programming language for Sound Synthesis and Audio Processing. The Faust compiler can compile Faust programs to a wide range of languages including C++, Java and WebAssembly. The Faust compiler also supports the OWL firmware as a compilation target.

When writing Faust programs we use elements (sometimes called *blocks*) to make a process chain.

Speaking of *process*, every Faust program has a *process* function which gives us access to audio inputs and outputs. Let's do a simple example:

## First Program
```c
import("stdfaust.lib");
import("owl.lib");

process = no.noise;
``` 

Just write this to a new file, save it as a **.dsp** file and upload it to the [Patch Library](https://www.rebeltech.org/patch-library/create-patch). Hit compile and load or store it onto your device. You should now hear static noise at your device's output. (To test and develop your Faust programs, you can use the [Faust Online IDE](https://faustide.grame.fr/). You can also use the 'Edit' and 'Compile' functions in the patch library.)

### Explanation

The `no.noise` function produces random values. Because the noise element is at the end of the chain, its output gets directly send to the audio output.

## Noise Shaping
Okay, to be honest, this is quite boring. Let's do something about it. Maybe shape the sound. But first, the noise might be quite loud. We can lower the amplitude by simply multiplying the signal with a number between 0 and 1.0.
```c
process = no.noise * 0.5;
```

To shape the sound, we might wanna add a filter, in this case a bandpass filter. The function `fi.resonbp(freq, q, g)` takes three parameters for us to control:
* `freq`: the center frequency
* `q`: the q factor
* `g`: the filter gain

In our program, we use the so called *sequential composition operator `:`* to connect the outcoming noise signal to input of the filter. Our program looks like this.
```c
import("stdfaust.lib");
import("owl.lib");

process = no.noise * 0.5 : fi.resonbp(1000, 5, 1);
```

First of all, do you hear this? Our signal seems to be only coming out of one side. Let's fix this by having the signal split into two parallel lines to create a two channel output. We use this notation:
```c
process = no.noise * 0.5 : fi.resonbp(1000, 5, 1) <: _,_;
```
And second, let's put the filter parameters in their own variable (spoiler: might be helpful later).
```c
import("stdfaust.lib");
import("owl.lib");

f = 1000;
q = 5;
gain = 1;

process = no.noise * 0.5 : fi.resonbp(f, q, gain) <: _,_;
```

## Interactivity
Why not control the filter frequency manually? No problem! Inside our Faust program we can define *UI elements* which let us control variables and parameters with our hardware knobs and switches.
The most common UI element is the **hslider**. Its definition looks like that: `hslider("paramName", default, min, max, step)`. To make our filter frequency adjustable we modify our program like so:
```c
import("stdfaust.lib");
import("owl.lib");

f = hslider("Frequency",1000,10,3000,0.01);
q = 5;
gain = 1;

process = no.noise * 0.5 : fi.resonbp(f, q, gain) <: _,_;
```
We replaced the fixed frequency value with the hslider definition. To map this *hslider* to one of our knobs we have to add a special flag to our parameter name: `[OWL:A]`. In our case let's map the A knob from our device to the frequency. Our modified code looks like this:

```c
import("stdfaust.lib");
import("owl.lib");

f = hslider("Frequency[OWL:A]",1000,10,3000,0.01);
q = 5;
gain = 1;

process = no.noise * 0.5 : fi.resonbp(f, q, gain) <: _,_;
```

## Final Program
To finish, we can rewrite our program to filter differently for the right and left output. To do so, we use *parallel composition* to combine blocks in a parallel manner.
```c
import("stdfaust.lib");
import("owl.lib");

f = hslider("Frequency[OWL:A]",1000,10,3000,0.01);
diff = hslider("Difference[OWL:B]",0.5,0,1,0.01);
q = 5;
gain = 1;

process = no.noise * 0.5 <: fi.resonbp(f * diff, q, gain), fi.resonbp(f * (1-diff), q, gain);
```

We have now built a little stereo noise box with control over the filter frequency and stereo panning.

## Additional Sources 
* [Offical Faust Website](https://faust.grame.fr/)
* [Faust Online IDE for Prototyping](https://faustide.grame.fr/)
* [In-Depth Faust Manual](https://faustdoc.grame.fr/manual/introduction/)
* [Faust Library Documentation](https://faustlibraries.grame.fr/)
