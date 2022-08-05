Content.makeFrontInterface(854, 690);

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

function onControl(number, value)
{
    if(number == widget1)
    {
        Module1.setAttribute(Module1.Parameter, value);
    }
    else if (number == widget2)
    {
        Module2.setAttribute(Module2.Parameter, value);
    }
}

const var envbutton = Content.getComponent("envelopes1");
const var table = Content.getComponent("MOD1");
const var step = Content.getComponent("MOD2");


inline function onenvelopes1Control(number, value)
{
        table.showControl(value);
        step.showControl(1-value); 
     
}

envbutton.setControlCallback(onenvelopes1Control);

const var button1 = Content.getComponent("seq1type1");
const var table1 = Content.getComponent("ScriptTable1");
const var step1 = Content.getComponent("SliderPackA");
const var s1 = Synth.getModulator("s1");

inline function onseq1typeControl(number, value)
{
        step1.showControl(value);
        table1.showControl(1-value); 
        s1.setAttribute(s1.type, 1-value);
        s2.setAttribute(s2.type, 0);
}


button1.setControlCallback(onseq1typeControl);



const var button2 = Content.getComponent("seq1type2");
const var table2 = Content.getComponent("ScriptTable2");
const var step2 = Content.getComponent("SliderPackB");
const var s2 = Synth.getModulator("s2");

inline function onseq1type2Control(number, value)
{
        step2.showControl(value);
        table2.showControl(1-value); 
        s2.setAttribute(s2.type, 0);
        s2.setAttribute(s2.type, 1-value);
}


button2.setControlCallback(onseq1type2Control);



const var button3 = Content.getComponent("seqtype3");
const var table3 = Content.getComponent("ScriptTable3");
const var step3 = Content.getComponent("SliderPackC");
const var s3 = Synth.getModulator("s3");

inline function onseqtype3Control(number, value)
{
        step3.showControl(value);
        table3.showControl(1-value); 
        s3.setAttribute(s3.type, 0);
        s3.setAttribute(s3.type, 1-value);
}


button3.setControlCallback(onseqtype3Control);



const var button4 = Content.getComponent("seqtype4");
const var table4 = Content.getComponent("ScriptTable4");
const var step4 = Content.getComponent("SliderPackD");
const var s4 = Synth.getModulator("s4");

inline function onseqtype4Control(number, value)
{
        step4.showControl(value);
        table4.showControl(1-value); 
        s4.setAttribute(s4.type, 0);
        s4.setAttribute(s4.type, 1-value);
}


button4.setControlCallback(onseqtype4Control);



const var button5 = Content.getComponent("seqtype5");
const var table5 = Content.getComponent("ScriptTable5");
const var step5 = Content.getComponent("SliderPackE");
const var s5 = Synth.getModulator("s5");

inline function onseqtype5Control(number, value)
{
        step5.showControl(value);
        table5.showControl(1-value); 
        s5.setAttribute(s5.type, 0);
        s5.setAttribute(s5.type, 1-value);
}


button5.setControlCallback(onseqtype5Control);




const var button6 = Content.getComponent("seqtype6");
const var table6 = Content.getComponent("ScriptTable6");
const var step6 = Content.getComponent("SliderPackF");
const var s6 = Synth.getModulator("s6");

inline function onseqtype6Control(number, value)
{
        step6.showControl(value);
        table6.showControl(1-value); 
        s6.setAttribute(s6.type, 0);
        s6.setAttribute(s6.type, 1-value);
}


button6.setControlCallback(onseqtype6Control);


const var button7 = Content.getComponent("stype1");
const var table7 = Content.getComponent("ScriptTable7");
const var step7 = Content.getComponent("SliderPackA1");
const var s7 = Synth.getModulator("s7");

inline function onstype1Control(number, value)
{
        step7.showControl(value);
        table7.showControl(1-value); 
        s7.setAttribute(s7.type, 1-value);
        s8.setAttribute(s8.type, 0);
}


button7.setControlCallback(onstype1Control);



const var button8 = Content.getComponent("stype2");
const var table8 = Content.getComponent("ScriptTable8");
const var step8 = Content.getComponent("SliderPackB1");
const var s8 = Synth.getModulator("s8");

inline function onstype2Control(number, value)
{
        step8.showControl(value);
        table8.showControl(1-value); 
        s8.setAttribute(s8.type, 0);
        s8.setAttribute(s8.type, 1-value);
}


button8.setControlCallback(onstype2Control);



const var button9 = Content.getComponent("stype3");
const var table9 = Content.getComponent("ScriptTable9");
const var step9 = Content.getComponent("SliderPackC1");
const var s9 = Synth.getModulator("s9");

inline function onstype3Control(number, value)
{
        step9.showControl(value);
        table9.showControl(1-value); 
        s9.setAttribute(s9.type, 0);
        s9.setAttribute(s9.type, 1-value);
}


button9.setControlCallback(onstype3Control);



const var button10 = Content.getComponent("stype4");
const var table10 = Content.getComponent("ScriptTable10");
const var step10 = Content.getComponent("SliderPackD1");
const var s10 = Synth.getModulator("s10");

inline function onstype4Control(number, value)
{
        step10.showControl(value);
        table10.showControl(1-value); 
        s10.setAttribute(s10.type, 0);
        s10.setAttribute(s10.type, 1-value);
}


button10.setControlCallback(onstype4Control);



const var button11 = Content.getComponent("stype5");
const var table11 = Content.getComponent("ScriptTable11");
const var step11 = Content.getComponent("SliderPackE1");
const var s11 = Synth.getModulator("s11");

inline function onstype5Control(number, value)
{
        step11.showControl(value);
        table11.showControl(1-value); 
        s11.setAttribute(s11.type, 0);
        s11.setAttribute(s11.type, 1-value);
}


button11.setControlCallback(onstype5Control);




const var button12 = Content.getComponent("stype6");
const var table12 = Content.getComponent("ScriptTable12");
const var step12 = Content.getComponent("SliderPackF1");
const var s12 = Synth.getModulator("s12");

inline function onstype6Control(number, value)
{
        step12.showControl(value);
        table12.showControl(1-value); 
        s12.setAttribute(s12.type, 0);
        s12.setAttribute(s12.type, 1-value);
}


button12.setControlCallback(onstype6Control);

const var ulp = Content.getComponent("ULPbox");


ulp.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/TdDvx");
  } 
  else 
  {
    link_hover = event.hover;
    this.repaint();
  }
});

const var meta = Content.getComponent("METAbox");


meta.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://github.com/publicsamples/Metasynth-Loops");
  } 
  else 
  {
    link_hover = event.hover;
    this.repaint();
  }
});

const var modloops = Content.getComponent("MLbox");


modloops.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://github.com/publicsamples/Modular-Loops/releases/tag/1.0");
  } 
  else 
  {
    link_hover = event.hover;
    this.repaint();
  }
});
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
 