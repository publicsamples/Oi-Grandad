Content.makeFrontInterface(865, 750);


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


const var VolMod1 = [];

VolMod1[0] = Content.getComponent("vol1lfo1");
VolMod1[1] = Content.getComponent("vol1lfo2");
VolMod1[2] = Content.getComponent("vol1lfo3");
VolMod1[3] = Content.getComponent("vol1lfo4");
VolMod1[4] = Content.getComponent("vol1lfo5");
VolMod1[5] = Content.getComponent("vol1lfo6");
VolMod1[6] = Content.getComponent("vol1lfo7");
VolMod1[7] = Content.getComponent("vol1lfo8");
VolMod1[8] = Content.getComponent("vol1lfo9");
VolMod1[9] = Content.getComponent("vol1lfo10");

const var cmbPanel= Content.getComponent("vol1modsel");

inline function onvol1modselControl(component, value)
{
    for (i = 0; i < VolMod1.length; i++)
        VolMod1[i].showControl(value - 1 == i);
};

Content.getComponent("vol1modsel").setControlCallback(onvol1modselControl);



const var posMod1 = [];

posMod1[0] = Content.getComponent("pos1lfo1");
posMod1[1] = Content.getComponent("pos1lfo2");
posMod1[2] = Content.getComponent("pos1lfo3");
posMod1[3] = Content.getComponent("pos1lfo4");
posMod1[4] = Content.getComponent("pos1lfo5");
posMod1[5] = Content.getComponent("pos1lfo6");
posMod1[6] = Content.getComponent("pos1lfo7");
posMod1[7] = Content.getComponent("pos1lfo8");
posMod1[8] = Content.getComponent("pos1lfo9");
posMod1[9] = Content.getComponent("pos1lfo10");

const var cmbPanel2= Content.getComponent("pos1modsel");

inline function onpos1modselControl(component, value)
{
    for (i = 0; i < posMod1.length; i++)
        posMod1[i].showControl(value - 1 == i);
};

Content.getComponent("pos1modsel").setControlCallback(onpos1modselControl);

const var grainMod1 = [];

grainMod1[0] = Content.getComponent("grain1lfo1");
grainMod1[1] = Content.getComponent("grain1lfo2");
grainMod1[2] = Content.getComponent("grain1lfo3");
grainMod1[3] = Content.getComponent("grain1lfo4");
grainMod1[4] = Content.getComponent("grain1lfo5");
grainMod1[5] = Content.getComponent("grain1lfo6");
grainMod1[6] = Content.getComponent("grain1lfo7");
grainMod1[7] = Content.getComponent("grain1lfo8");
grainMod1[8] = Content.getComponent("grain1lfo9");
grainMod1[9] = Content.getComponent("grain1lfo10");

const var cmbPanel3= Content.getComponent("grain1modsel");

inline function ongrain1modselControl(component, value)
{
    for (i = 0; i < grainMod1.length; i++)
        grainMod1[i].showControl(value - 1 == i);
};

Content.getComponent("grain1modsel").setControlCallback(ongrain1modselControl);


const var cutMod1 = [];

cutMod1[0] = Content.getComponent("cut1lfo1");
cutMod1[1] = Content.getComponent("cut1lfo2");
cutMod1[2] = Content.getComponent("cut1lfo3");
cutMod1[3] = Content.getComponent("cut1lfo4");
cutMod1[4] = Content.getComponent("cut1lfo5");
cutMod1[5] = Content.getComponent("cut1lfo6");
cutMod1[6] = Content.getComponent("cut1lfo7");
cutMod1[7] = Content.getComponent("cut1lfo8");
cutMod1[8] = Content.getComponent("cut1lfo9");
cutMod1[9] = Content.getComponent("cut1lfo10");


const var cmbPanel4= Content.getComponent("cut1modsel");

inline function oncut1modselControl(component, value)
{
    for (i = 0; i < cutMod1.length; i++)
        cutMod1[i].showControl(value - 1 == i);
};

Content.getComponent("cut1modsel").setControlCallback(oncut1modselControl);





const var VolMod2 = [];

VolMod2[0] = Content.getComponent("vol1lfo11");
VolMod2[1] = Content.getComponent("vol1lfo12");
VolMod2[2] = Content.getComponent("vol1lfo13");
VolMod2[3] = Content.getComponent("vol1lfo14");
VolMod2[4] = Content.getComponent("vol1lfo15");
VolMod2[5] = Content.getComponent("vol1lfo16");
VolMod2[6] = Content.getComponent("vol1lfo17");
VolMod2[7] = Content.getComponent("vol1lfo18");
VolMod2[8] = Content.getComponent("vol1lfo19");
VolMod2[9] = Content.getComponent("vol1lfo20");

const var cmbPanel6= Content.getComponent("vol2modsel");

inline function onvol2modselControl(component, value)
{
    for (i = 0; i < VolMod2.length; i++)
        VolMod2[i].showControl(value - 1 == i);
};

Content.getComponent("vol2modsel").setControlCallback(onvol2modselControl);



const var posMod2 = [];

posMod2[0] = Content.getComponent("pos1lfo11");
posMod2[1] = Content.getComponent("pos1lfo12");
posMod2[2] = Content.getComponent("pos1lfo13");
posMod2[3] = Content.getComponent("pos1lfo14");
posMod2[4] = Content.getComponent("pos1lfo15");
posMod2[5] = Content.getComponent("pos1lfo16");
posMod2[6] = Content.getComponent("pos1lfo17");
posMod2[7] = Content.getComponent("pos1lfo18");
posMod2[8] = Content.getComponent("pos1lfo19");
posMod2[9] = Content.getComponent("pos1lfo20");

const var cmbPanel7= Content.getComponent("pos2modsel");

inline function onpos2modselControl(component, value)
{
    for (i = 0; i < posMod2.length; i++)
        posMod2[i].showControl(value - 1 == i);
};

Content.getComponent("pos2modsel").setControlCallback(onpos2modselControl);

const var grainMod2 = [];

grainMod2[0] = Content.getComponent("grain1lfo11");
grainMod2[1] = Content.getComponent("grain1lfo12");
grainMod2[2] = Content.getComponent("grain1lfo13");
grainMod2[3] = Content.getComponent("grain1lfo14");
grainMod2[4] = Content.getComponent("grain1lfo15");
grainMod2[5] = Content.getComponent("grain1lfo16");
grainMod2[6] = Content.getComponent("grain1lfo17");
grainMod2[7] = Content.getComponent("grain1lfo18");
grainMod2[8] = Content.getComponent("grain1lfo19");
grainMod2[9] = Content.getComponent("grain1lfo20");

const var cmbPanel8= Content.getComponent("grain2modsel");

inline function ongrain2modselControl(component, value)
{
    for (i = 0; i < grainMod2.length; i++)
        grainMod2[i].showControl(value - 1 == i);
};

Content.getComponent("grain2modsel").setControlCallback(ongrain2modselControl);


const var cutMod2 = [];

cutMod2[0] = Content.getComponent("cut1lfo11");
cutMod2[1] = Content.getComponent("cut1lfo12");
cutMod2[2] = Content.getComponent("cut1lfo13");
cutMod2[3] = Content.getComponent("cut1lfo14");
cutMod2[4] = Content.getComponent("cut1lfo15");
cutMod2[5] = Content.getComponent("cut1lfo16");
cutMod2[6] = Content.getComponent("cut1lfo17");
cutMod2[7] = Content.getComponent("cut1lfo18");
cutMod2[8] = Content.getComponent("cut1lfo19");
cutMod2[9] = Content.getComponent("cut1lfo20");

const var cmbPanel9= Content.getComponent("cut2modsel");

inline function oncut2modselControl(component, value)
{
    for (i = 0; i < cutMod2.length; i++)
        cutMod2[i].showControl(value - 1 == i);
};

Content.getComponent("cut2modsel").setControlCallback(oncut2modselControl);

const var VolMod3 = [];

VolMod3[0] = Content.getComponent("vol1lfo21");
VolMod3[1] = Content.getComponent("vol1lfo22");
VolMod3[2] = Content.getComponent("vol1lfo23");
VolMod3[3] = Content.getComponent("vol1lfo24");
VolMod3[4] = Content.getComponent("vol1lfo25");
VolMod3[5] = Content.getComponent("vol1lfo26");
VolMod3[6] = Content.getComponent("vol1lfo27");
VolMod3[7] = Content.getComponent("vol1lfo28");
VolMod3[8] = Content.getComponent("vol1lfo29");
VolMod3[9] = Content.getComponent("vol1lfo30");

const var cmbPanel11= Content.getComponent("vol3modsel");

inline function onvol3modselControl(component, value)
{
    for (i = 0; i < VolMod3.length; i++)
        VolMod3[i].showControl(value - 1 == i);
};

Content.getComponent("vol3modsel").setControlCallback(onvol3modselControl);

const var posMod3 = [];

posMod3[0] = Content.getComponent("pos1lfo21");
posMod3[1] = Content.getComponent("pos1lfo22");
posMod3[2] = Content.getComponent("pos1lfo23");
posMod3[3] = Content.getComponent("pos1lfo24");
posMod3[4] = Content.getComponent("pos1lfo25");
posMod3[5] = Content.getComponent("pos1lfo26");
posMod3[6] = Content.getComponent("pos1lfo27");
posMod3[7] = Content.getComponent("pos1lfo28");
posMod3[8] = Content.getComponent("pos1lfo29");
posMod3[9] = Content.getComponent("pos1lfo30");

const var cmbPanel12= Content.getComponent("pos3modsel");

inline function onpos3modselControl(component, value)
{
    for (i = 0; i < posMod3.length; i++)
        posMod3[i].showControl(value - 1 == i);
};

Content.getComponent("pos3modsel").setControlCallback(onpos3modselControl);

const var grainMod3 = [];

grainMod3[0] = Content.getComponent("grain1lfo21");
grainMod3[1] = Content.getComponent("grain1lfo22");
grainMod3[2] = Content.getComponent("grain1lfo23");
grainMod3[3] = Content.getComponent("grain1lfo24");
grainMod3[4] = Content.getComponent("grain1lfo25");
grainMod3[5] = Content.getComponent("grain1lfo26");
grainMod3[6] = Content.getComponent("grain1lfo27");
grainMod3[7] = Content.getComponent("grain1lfo28");
grainMod3[8] = Content.getComponent("grain1lfo29");
grainMod3[9] = Content.getComponent("grain1lfo30");

const var cmbPanel13= Content.getComponent("grain3modsel");

inline function ongrain3modselControl(component, value)
{
    for (i = 0; i < grainMod3.length; i++)
        grainMod3[i].showControl(value - 1 == i);
};

Content.getComponent("grain3modsel").setControlCallback(ongrain3modselControl);


const var cutMod3 = [];

cutMod3[0] = Content.getComponent("cut1lfo21");
cutMod3[1] = Content.getComponent("cut1lfo22");
cutMod3[2] = Content.getComponent("cut1lfo23");
cutMod3[3] = Content.getComponent("cut1lfo24");
cutMod3[4] = Content.getComponent("cut1lfo25");
cutMod3[5] = Content.getComponent("cut1lfo26");
cutMod3[6] = Content.getComponent("cut1lfo27");
cutMod3[7] = Content.getComponent("cut1lfo28");
cutMod3[8] = Content.getComponent("cut1lfo29");
cutMod3[9] = Content.getComponent("cut1lfo30");

const var cmbPanel14= Content.getComponent("cut3modsel");

inline function oncut3modselControl(component, value)
{
    for (i = 0; i < cutMod3.length; i++)
        cutMod3[i].showControl(value - 1 == i);
};

Content.getComponent("cut3modsel").setControlCallback(oncut3modselControl);


const var VolMod4 = [];

VolMod4[0] = Content.getComponent("vol1lfo31");
VolMod4[1] = Content.getComponent("vol1lfo32");
VolMod4[2] = Content.getComponent("vol1lfo33");
VolMod4[3] = Content.getComponent("vol1lfo34");
VolMod4[4] = Content.getComponent("vol1lfo35");
VolMod4[5] = Content.getComponent("vol1lfo36");
VolMod4[6] = Content.getComponent("vol1lfo37");
VolMod4[7] = Content.getComponent("vol1lfo38");
VolMod4[8] = Content.getComponent("vol1lfo39");
VolMod4[9] = Content.getComponent("vol1lfo40");

const var cmbPanel16= Content.getComponent("vol4modsel");

inline function onvol4modselControl(component, value)
{
    for (i = 0; i < VolMod4.length; i++)
        VolMod4[i].showControl(value - 1 == i);
};

Content.getComponent("vol4modsel").setControlCallback(onvol4modselControl);



const var posMod4 = [];

posMod4[0] = Content.getComponent("pos1lfo31");
posMod4[1] = Content.getComponent("pos1lfo32");
posMod4[2] = Content.getComponent("pos1lfo33");
posMod4[3] = Content.getComponent("pos1lfo34");
posMod4[4] = Content.getComponent("pos1lfo35");
posMod4[5] = Content.getComponent("pos1lfo36");
posMod4[6] = Content.getComponent("pos1lfo37");
posMod4[7] = Content.getComponent("pos1lfo38");
posMod4[8] = Content.getComponent("pos1lfo39");
posMod4[9] = Content.getComponent("pos1lfo40");

const var cmbPanel17= Content.getComponent("pos4modsel");

inline function onpos4modselControl(component, value)
{
    for (i = 0; i < posMod4.length; i++)
        posMod4[i].showControl(value - 1 == i);
};

Content.getComponent("pos4modsel").setControlCallback(onpos4modselControl);

const var grainMod4 = [];

grainMod4[0] = Content.getComponent("grain1lfo31");
grainMod4[1] = Content.getComponent("grain1lfo32");
grainMod4[2] = Content.getComponent("grain1lfo33");
grainMod4[3] = Content.getComponent("grain1lfo34");
grainMod4[4] = Content.getComponent("grain1lfo35");
grainMod4[5] = Content.getComponent("grain1lfo36");
grainMod4[6] = Content.getComponent("grain1lfo37");
grainMod4[7] = Content.getComponent("grain1lfo38");
grainMod4[8] = Content.getComponent("grain1lfo39");
grainMod4[9] = Content.getComponent("grain1lfo40");


const var cmbPanel18= Content.getComponent("grain4modsel");

inline function ongrain4modselControl(component, value)
{
    for (i = 0; i < grainMod4.length; i++)
        grainMod4[i].showControl(value - 1 == i);
};

Content.getComponent("grain4modsel").setControlCallback(ongrain4modselControl);


const var cutMod4 = [];

cutMod4[0] = Content.getComponent("cut1lfo31");
cutMod4[1] = Content.getComponent("cut1lfo32");
cutMod4[2] = Content.getComponent("cut1lfo33");
cutMod4[3] = Content.getComponent("cut1lfo34");
cutMod4[4] = Content.getComponent("cut1lfo35");
cutMod4[5] = Content.getComponent("cut1lfo36");
cutMod4[6] = Content.getComponent("cut1lfo37");
cutMod4[7] = Content.getComponent("cut1lfo38");
cutMod4[8] = Content.getComponent("cut1lfo39");
cutMod4[9] = Content.getComponent("cut1lfo40");

const var cmbPanel19= Content.getComponent("cut4modsel");

inline function oncut4modselControl(component, value)
{
    for (i = 0; i < cutMod4.length; i++)
        cutMod4[i].showControl(value - 1 == i);
};

Content.getComponent("cut4modsel").setControlCallback(oncut4modselControl);

//Delay Links

const var Delay1 = Synth.getEffect("Delay1");

inline function onDelayTime1Control(component, value)
{
    Delay1.setAttribute(Delay1.DelayTimeLeft, value);
    Delay1.setAttribute(Delay1.DelayTimeRight, value);
};

Content.getComponent("DelayTime1").setControlCallback(onDelayTime1Control);

inline function onFeed1Control(component, value)
{
    Delay1.setAttribute(Delay1.FeedbackLeft, value);
    Delay1.setAttribute(Delay1.FeedbackRight, value);
};

Content.getComponent("Feed1").setControlCallback(onFeed1Control);


const var Delay2 = Synth.getEffect("Delay2");

inline function onDelayTime2Control(component, value)
{
    Delay2.setAttribute(Delay2.DelayTimeLeft, value);
    Delay2.setAttribute(Delay2.DelayTimeRight, value);
};

Content.getComponent("DelayTime2").setControlCallback(onDelayTime2Control);

inline function onFeed2Control(component, value)
{
    Delay2.setAttribute(Delay2.FeedbackLeft, value);
    Delay2.setAttribute(Delay2.FeedbackRight, value);
};

Content.getComponent("Feed2").setControlCallback(onFeed2Control);



const var Delay3 = Synth.getEffect("Delay3");

inline function onDelayTime3Control(component, value)
{
    Delay3.setAttribute(Delay3.DelayTimeLeft, value);
    Delay3.setAttribute(Delay3.DelayTimeRight, value);
};

Content.getComponent("DelayTime3").setControlCallback(onDelayTime3Control);

inline function onFeed3Control(component, value)
{
    Delay3.setAttribute(Delay3.FeedbackLeft, value);
    Delay3.setAttribute(Delay3.FeedbackRight, value);
};

Content.getComponent("Feed3").setControlCallback(onFeed3Control);



const var Delay4 = Synth.getEffect("Delay4");

inline function onDelayTime4Control(component, value)
{
    Delay4.setAttribute(Delay4.DelayTimeLeft, value);
    Delay4.setAttribute(Delay4.DelayTimeRight, value);
};

Content.getComponent("DelayTime4").setControlCallback(onDelayTime4Control);

inline function onFeed4Control(component, value)
{
    Delay4.setAttribute(Delay4.FeedbackLeft, value);
    Delay4.setAttribute(Delay4.FeedbackRight, value);
};

Content.getComponent("Feed4").setControlCallback(onFeed4Control);

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
 