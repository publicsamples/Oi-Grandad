# The Language

FAUST is a functional language for DSP. Please see its [main site](https://faust.grame.fr/) for documentation and library reference.

There's lots of detailed info and tutorials, so this document won't cover that. Instead we'll focus on features that are specific to OWL and the OpenWare firmware. But we have an ongoing tutorial series for learning FAUST on OWL, too:

 1. [Getting Started](Tutorial/01_GettingStarted)
 2. [Dual VCA](Tutorial/02_DualVCA)

Sample files are part of this repo and can be built and loaded quickly in any of three different ways:
 - Using our [online compiler](https://www.rebeltech.org/patch-library/patches/my-patches/)
 - Offline using [OwlProgram](https://github.com/pingdynasty/OwlProgram) Makefile
 - Offline using [OwlProgram](https://github.com/pingdynasty/OwlProgram) and the provided `upload.py` script

To compile a patch online (recommended), open the [Patch Library](https://www.rebeltech.org/patch-library/) with a Web MIDI enabled browser (e.g. Chrome), log in (create an account if necessary), go to [My Patches](https://www.rebeltech.org/patch-library/patches/my-patches/), click Create patch, and upload the Faust file or files that you want to try. Select compilation type `faust`. Click `Save and Compile`, wait for compilation to finish, click `Connect To Device`, and then click `Load` to run the patch on the device. If you want to store it in a memory slot, click `Store` and select which slot to store it in.

To compile a patch offline, download [OwlProgram](https://github.com/pingdynasty/OwlProgram) and follow the installation and usage instructions provided. You can then compile and run a patch on the device with this type of command:

```
make PATCHSOURCE=mypatchdirectory FAUST=mypatchname run
```

This compiles the patch and sends it to the device to run from RAM, without storing. Here `mypatchname` is the name of your `.dsp` file without the `.dsp`, and `mypatchdirectory` is the folder you've got your patch files in.

You can also use the provided upload.py script. Example call would be something like this:

```
./upload.py --owl=/path/to/OwlProgram --slot=5
```

This compiles the patch and stores it on the device in memory slot 5.


# Program examples

## Trivial patch

Simplest patch in FAUST would look like this:

```
process = _;
```

What it does is takes input from first audio channel and sends it to output without any modifications.

You can compile it with the online compiler at [patch library](https://www.rebeltech.org/patch-library) or build locally using [OwlLibrary](https://github.com/pingdynasty/OwlProgram)


## Display message on screen and make some noise

If your device has a screen, you can use it to display a short information message. Let's try this example:

```
declare message "Hello\nmake some noise";

import("stdfaust.lib");

process = no.noise : *(0.5);
```

Here the first line adds a metadata declaration, second line imports FAUST's standard library and the last line sends output from a white noise generator to output channel 1 with gain reduced by half.


## Parameter input

You can control patch parameters by binding them with FAUST UI controls. Let's look at an example patch:

```
import("stdfaust.lib");
freq = hslider("Frequency[OWL:A]", 60, 60, 440, 1);
process = os.osc(freq);
```

``[OWL:A]`` in parameter label is what binds your device's input to FAUST parameter. Parameter ranges that you can use are A-H, AA-AH, BA-BH, CA-CH and DA-DH. The buttons are assigned with B1, B2 et c. This is what FAUST patches support, but the actual parameters that have physical inputs on a particular device would be more limited. You would have to use MIDI to access those that don't have physical control on device.

It's also possible to specify variable as digit from ``[OWL:0]`` to ``[OWL:39]``. This is convenient if you want to use FAUST [variable substitution in labels](https://faustdoc.grame.fr/manual/syntax/#variable-parts-of-a-label)

Example:

```
import("stdfaust.lib");

freq = hslider("Base frequency[OWL:AA]", 80, 60, 120, 0.01);

process = par(
    i,
    8, 
    hslider("Harmonic %i[OWL:%i]", 1 / (1 + i), 0, 1, 0.001) * os.oscs(i * freq + freq)
) :> _ : *(0.125) <: _, _;
```

This patch renders first 8 partials from a wave with base frequency of 60 Hz by default. Each harmonic partial has editable gain. This is called a harmonic oscillator.

FAUST supports several variations for its UI widgets, but with hardware we're using either knobs (often with extra control by voltage) or buttons. So effectively using ``hslider``, ``vslider`` or ``numentry`` widget give us a variable limited by upper and lower limit, while ``button``, and ``checkbox`` give a boolean variable with on/off state. 

For boolean inputs, ``button`` is momentary, while ``checkbox`` provides a toggle. The toggle status is typically indicated on the hardware device by a button LED or similar.


## Parameter output

Some devices have support for CV outputs. This is also available to patches in FAUST. Let's see how it can be used:

```
import("stdfaust.lib");

freq     = hslider("Frequency[OWL:A]", 60, 60, 440, 1);
lfo_freq = hslider("LFO frequency[OWL:B]", 0.3, 0.01, 1.0, 0.01) : si.smoo;
lfo_out  = hbargraph("LFO>[OWL:F]", -1, 1);

process = attach(os.osc(freq), os.osc(lfo_freq) : lfo_out);
```

This patch produces a static sine wave tone initially. But if we connect output from patch point `F` with the input on patch point `A`, then we get a slow frequency modulation in our audio.

A typical way to use CV output works like ``attach(_, hbargraph(...))`` (or ``vbargraph``). This allows us to bypass incoming audio and just force sending data to bargraph widget. If you're not familiar with ``attach`` primitive, have a look at [information in FAUST docs](https://faustdoc.grame.fr/manual/syntax/#attach-primitive) . The general idea is that its first input is returned unchanged, while output is multiplied by 0. So second parameter is not used, but can force some sort of calculation to be performed. In our case it's generating LFO signal and sending it to widget bound to parameter F.
Note that output parameters are designated with a trailing '>' in the parameter name, as in `LFO>` above. On the Magus, any of the 20 parameters can be designated either inputs or outputs. On Wizard and Lich, there are two fixed CV outputs, assigned to parameters `F` and `G`.


## Gate and LED output

Gate outputs are controlled in the same way as CV outputs, e.g. with ``attach`` and ``hbargraph``. Furthermore, in many cases the hardware button LEDs can be controlled independently of the button input.

Here is an example that sends the inverted button value out to control the B1 LED:
```
import("music.lib");

btn1 = button("btn1[OWL:B1]");
led1 = hbargraph("led2>[OWL:B1]", 0, 1);

process = attach(osc(1000) * btn1, 1-btn1 : led1);
```

Gate outputs will have hardware specific assignments, e.g. on the Lich it is ``B3``, while the two gate outputs on the Witch are designated ``B5`` and ``B6``. You can also use ``PUSH`` as a more generic name for the first button or gate, and it works with both inputs and outputs.


## MIDI

It is possible to control your patches with MIDI. In fact, it's very easy to do so.

```
declare options "[midi:on]";

import("stdfaust.lib");

freq = hslider("freq", 440, 20, 1000, 0.001);
gain = hslider("gain", 0.0, 0.0, 1.0, 0.001);
gate = button("gate");
sustain = hslider("Sustain[OWL:A]", 5.0, 1.0, 10.0, 0.01);

process = sy.combString(freq, gain * sustain, gate);
```

First of all, you must enable MIDI with metadata declaration.

Then special variables are used to bind variables to MIDI note parameters. This is based on matching label used for your controls. In this case we use "freq"/"gain"/"gate". Note that "gate" must be a button, not a slider. Gain is based on note velocity. Other MIDI parameter you can use is "bend".

After connecting your MIDI controller, you should be able to play some notes and hear a string simulated by physical modeling. Current MIDI implementation is monophonic, so you won't be able to hear more than a single note at once.

## V/Oct control

You can also use the audio inputs and outputs for 1 Volt per octave CV, for tuning oscillators and filters, and CV sequencing. This works on devices with DC-coupled audio such as Lich, Magus and OWL Modular, and requires calibrating your device to have accurate V/Oct tracking.

Here's how you can use CV for controlling oscillator frequency:

```
declare owl "[voct:input]";

import("stdfaust.lib");
import("owl.lib");

tune = hslider("Tune[OWL:A]", 0, -2, 2, 0.01);

process = sample2hertz(tune) : os.oscs;
```

It's also possible to output CV.
Let's write a simple sequencer:

```
declare owl "[voct:output]";

import("stdfaust.lib");
import("owl.lib");

notes = (36, 40, 43, 47, 48, 47, 43, 40);
notes_per_beat = 4;
total_notes = 8;

process = pitch, gate
with {
    tune     = hslider("Tune[OWL:A]", 0, -24, 24, 1) : int;
    bpm      = hslider("BPM[OWL:B]", 120, 80, 160, 0.1);
    beat_len = ba.tempo(bpm);
    gate     = ba.pulsen(beat_len / 4, beat_len / 2);
    step     = (ba.impulsify(gate) + _ : %(total_notes)) ~ _;
    seq_note = notes : ba.selectn(total_notes, step);
    pitch    = seq_note : ba.midikey2hz : hertz2sample(tune / 12);
};
```

First output generates CV pitch, second generates gates. Base note and tempo can be changed with parameters.
