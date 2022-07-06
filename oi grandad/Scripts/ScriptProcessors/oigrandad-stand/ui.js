Content.makeFrontInterface(865, 750);

const var SliderPack3 = Content.getComponent("SliderPack3");

inline function onSliderPack3Control(component, value)
{
	//Add your custom logic here...
};

Content.getComponent("SliderPack3").setControlCallback(onSliderPack3Control);

//presets
const var Pbox = [];

Pbox[0] = Content.getComponent("settings");
Pbox[1] = Content.getComponent("blank1");
Pbox[2] = Content.getComponent("blank2");

const var pre= Content.getComponent("presets");

inline function onpresetsControl(component, value)
{
    for (i = 0; i < Pbox.length; i++)
        Pbox[i].showControl(value - 1 == i);
};

Content.getComponent("presets").setControlCallback(onpresetsControl);

//reverb
const var Rbox = [];

Rbox[0] = Content.getComponent("settings1");
Rbox[1] = Content.getComponent("blank1");
Rbox[2] = Content.getComponent("blank2");

const var rev= Content.getComponent("REVERButton");

inline function onREVERButtonControl(component, value)
{
    for (i = 0; i < Rbox.length; i++)
        Rbox[i].showControl(value - 1 == i);
};

Content.getComponent("REVERButton").setControlCallback(onREVERButtonControl);

//mod
const var Mbox = [];

Mbox[0] = Content.getComponent("settings2");
Mbox[1] = Content.getComponent("blank1");
Mbox[2] = Content.getComponent("blank2");

const var modbut= Content.getComponent("MOD");

inline function onMODControl(component, value)
{
    for (i = 0; i < Mbox.length; i++)
        Mbox[i].showControl(value - 1 == i);
};

Content.getComponent("MOD").setControlCallback(onMODControl);

//settings
const var Sbox = [];

Sbox[0] = Content.getComponent("settings3");
Sbox[1] = Content.getComponent("blank1");
Sbox[2] = Content.getComponent("blank2");

const var set= Content.getComponent("SETTINGS");

inline function onSETTINGSControl(component, value)
{
    for (i = 0; i < Sbox.length; i++)
        Sbox[i].showControl(value - 1 == i);
};

Content.getComponent("SETTINGS").setControlCallback(onSETTINGSControl);

function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 