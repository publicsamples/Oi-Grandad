# Faust Tutorial 2: Dual VCA and Envelope Follower
The first tutorial can be found in the [GitHub repository](https://github.com/pingdynasty/OpenWareLab/blob/master/Faust/FaustTutorial1_GettingStarted.md) or on the [OpenWareLab website](https://www.openwarelab.org/Faust/FaustTutorial1_GettingStarted.html)

**Note:** this tutorial / Faust program was developed and tested on the Lich.

### Uploading and Testing
Save the program as a **.dsp** file and upload it at the [Rebeltech Patch Library](https://www.rebeltech.org/patch-library/create-patch). Hit compile and load or store it onto your device. To test and develop your Faust programs, you can use the [Faust Online IDE](https://faustide.grame.fr/).

## Goal
The goal for this tutorial is to create a VCA (voltage controlled amplifier). Because the Lich has two audio inputs, we simply can implement a two channel VCA.

## Audio Input and Output
When we want to access the audio inputs we just see them as coming from the left side of the process function.
This program passes both inputs to the outputs.
```c
import("stdfaust.lib");
import("owl.lib");

process = _,_;
```
To attenuate the input signals, we can multiply the them by a constant.
```c
import("stdfaust.lib");
import("owl.lib");

process = 0.5 * _ , 0.2 * _;
```

## Voltage Control
To make the attenuation / amplification voltage controllable, we again utilise the `hslider` UI element. In this case we can define the maximum amplification to 1. The controls are binded to input **A** and **B** using the special `[OWL:#]` flag.
```c
import("stdfaust.lib");
import("owl.lib");
vca_a = hslider("VCA_A[OWL:A]",0,0,1,0.001);
vca_b = hslider("VCA_B[OWL:B]",0,0,1,0.001);

process = vca_a * _ , vca_b * _;
```
We could call it a day now, but I wanted to use the two buttons and the CV outputs of the Lich.

## Mute Buttons
Faust implements another UI element, the `button("name")`. It outputs a *0* when not pressed and a *1* when pressed. We can use this to multiply the signal by the button state. To make button mute the channel when pressed we have to invert the button state. We can do this with the statement:
```c
b1 = button("Button 1");
s = 1 - b1;
```
`s` is 1 when the button is not pressed and 0 when pressed. We include this into our program this way.
```c
import("stdfaust.lib");
import("owl.lib");
vca_a = hslider("VCA_A[OWL:A]",0,0,1,0.001);
vca_b = hslider("VCA_B[OWL:B]",0,0,1,0.001);
b1 = button("A_MUTE[OWL:B1]");
b2 = button("B_MUTE[OWL:B2]");

process = (vca_a * (1-b1) * _), (vca_b * (1-b2) * _);
```

## Envelope Follower Output
The Lich and Magus feature CV outputs. Adressing thoose and sending a signal is not so easy in Faust, but still possible. First, we use the `hbargraph("name",min,max)` UI element to define a kind of output port. To map it to the physical output we have to include **>[OWL:X]** where **X** is the output parameter. On Lich and Wizard, this must be `F` or `G`, corresponding to CV out 1 and 2 respectively. On Magus, any of the 20 CV ports can be either an input or an output. To designate the parameter as an output, we add a `>` right angle to the end of the parameter name.

Second, we have to route a signal to the `hbargraph`. We do this with the `attach()` function. You can read the [documentation](https://faustdoc.grame.fr/manual/syntax/#attach-primitive) to see how it works in detail.

To generate the envelope from the sound we take the absolute value of the signal value and smooth the signal to prevent heavy jumps. This code snippet demonstrates how we can use these dirfferent parts to build an evelope output.
```c
env_out = hbargraph("ENV>[OWL:F]",0,1);
env = _ <:attach(_, abs : si.smoo : env_out);
process = env;
```
Because the Lich has four inputs, I added two more `hslider` for scaling the envelope-follow signal.

## Final Program
The final patch can be found in the [Rebeltech Patch Library](https://www.rebeltech.org/patch-library/patch/_Lich_2xVCA_EnvFollow/). Note that buttons b1 and b2 are in this version toggleable mute buttons and switch between mute and unmute.
```c
import("stdfaust.lib");
import("owl.lib");

vca_a = hslider("VCA_A[OWL:A]",0,0,1,0.001);
vca_b = hslider("VCA_B[OWL:B]",0,0,1,0.001);
env1_scale = hslider("ENV_SCALE1[OWL:C]",1, 0.5, 5, 0.01);
env2_scale = hslider("ENV_SCALE2[OWL:D]",1, 0.5, 5, 0.01);
b1 = button("A_MUTE[OWL:B1]") : ba.impulsify : ba.toggle;
b2 = button("B_MUTE[OWL:B2]") : ba.impulsify : ba.toggle;

env1_out = hbargraph("ENV_A>[OWL:F]", 0, 1);
env2_out = hbargraph("ENV_B>[OWL:G]", 0, 1);

env1 = _ <:attach(_, abs : si.smoo * env1_scale : env1_out);
env2 = _ <:attach(_, abs : si.smoo * env2_scale : env2_out);

process = (vca_a * (1-b1) * _), (vca_b * (1-b2) * _) : env1, env2;
```


## Additional Sources 
* [Offical Faust Website](https://faust.grame.fr/)
* [Faust Online IDE for Prototyping](https://faustide.grame.fr/)
* [In-Depth Faust Manual](https://faustdoc.grame.fr/manual/introduction/)
* [Faust Library Documentation](https://faustlibraries.grame.fr/)
