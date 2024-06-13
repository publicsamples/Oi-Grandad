Content.makeFrontInterface(865, 737);

// Hide or show pitch mod options

const var psync1 = Content.getComponent("psync1");
const var pmodblank1 = Content.getComponent("pmodblank1");
const var pitchmodcont1 = Content.getComponent("pitchmodcont1");
const var ps1 = Synth.getEffect("gran");

inline function onpsync1Control(number, value)
{
		pitchmodcont1.showControl(value); 
        pmodblank1.showControl(1-value);
      
       ps1.setAttribute(ps1.psync, 0);
       ps1.setAttribute(ps1.psync, 1-value);
}


psync1.setControlCallback(onpsync1Control);

const var psync2 = Content.getComponent("psync2");
const var pmodblank2 = Content.getComponent("pmodblank2");
const var pitchmodcont2 = Content.getComponent("pitchmodcont2");


const var ps2 = Synth.getEffect("gran2");

inline function onpsync2Control(number, value)
{
		pitchmodcont2.showControl(value); 
        pmodblank2.showControl(1-value);
      
       ps2.setAttribute(ps2.psync, 0);
       ps2.setAttribute(ps2.psync, 1-value);
}


psync2.setControlCallback(onpsync2Control);

const var psync3 = Content.getComponent("psync3");
const var pmodblank3 = Content.getComponent("pmodblank3");
const var pitchmodcont3 = Content.getComponent("pitchmodcont3");


const var ps3 = Synth.getEffect("gran3");

inline function onpsync3Control(number, value)
{
		pitchmodcont3.showControl(value); 
        pmodblank3.showControl(1-value);
      
       ps3.setAttribute(ps3.psync, 0);
       ps3.setAttribute(ps3.psync, 1-value);
}


psync3.setControlCallback(onpsync3Control);

const var psync4 = Content.getComponent("psync4");
const var pmodblank4 = Content.getComponent("pmodblank4");
const var pitchmodcont4 = Content.getComponent("pitchmodcont4");


const var ps4 = Synth.getEffect("gran4");

inline function onpsync4Control(number, value)
{
		pitchmodcont4.showControl(value); 
        pmodblank4.showControl(1-value);
      
       ps4.setAttribute(ps4.psync, 0);
       ps4.setAttribute(ps4.psync, 1-value);
}


psync4.setControlCallback(onpsync4Control);

// Switch grain slider

const var gsync1 = Content.getComponent("gsync1");
const var grainsize1 = Content.getComponent("grainsize1");
const var grainsizesync1 = Content.getComponent("grainsizesync1");
const var grs1 = Synth.getEffect("gran");

inline function ongsync1Control(number, value)
{
		grainsizesync1.showControl(value); 
        grainsize1.showControl(1-value);
      
       grs1.setAttribute(grs1.gsync, 0);
       grs1.setAttribute(grs1.gsync, 1-value);
}


gsync1.setControlCallback(ongsync1Control);

const var gsync2 = Content.getComponent("gsync2");
const var grainsize2 = Content.getComponent("grainsize2");
const var grainsizesync2 = Content.getComponent("grainsizesync2");
const var grs2 = Synth.getEffect("gran2");

inline function ongsync2Control(number, value)
{
		grainsizesync2.showControl(value); 
        grainsize2.showControl(1-value);
        
      
       grs2.setAttribute(grs2.gsync, 0);
       grs2.setAttribute(grs2.gsync, 1-value);
}


gsync2.setControlCallback(ongsync2Control);

const var gsync3 = Content.getComponent("gsync3");
const var grainsize3 = Content.getComponent("grainsize3");
const var grainsizesync3 = Content.getComponent("grainsizesync3");
const var grs3 = Synth.getEffect("gran3");

inline function ongsync3Control(number, value)
{
		grainsizesync3.showControl(value); 
        grainsize3.showControl(1-value);
      
       grs3.setAttribute(grs3.gsync, 0);
       grs3.setAttribute(grs3.gsync, 1-value);
}


gsync3.setControlCallback(ongsync3Control);

const var gsync4 = Content.getComponent("gsync4");
const var grainsize4 = Content.getComponent("grainsize4");
const var grainsizesync4 = Content.getComponent("grainsizesync4");

const var grs4 = Synth.getEffect("gran4");

inline function ongsync4Control(number, value)
{
		grainsizesync4.showControl(value); 
        grainsize4.showControl(1-value);
      
       grs4.setAttribute(grs4.gsync, 0);
       grs4.setAttribute(grs4.gsync, 1-value);
}


gsync4.setControlCallback(ongsync4Control);

// Switch delay slider

const var delaysync1 = Content.getComponent("delaysync1");
const var DelayTime1 = Content.getComponent("DelayTime1");
const var DelayTimesync1 = Content.getComponent("DelayTimesync1");
const var dt1 = Synth.getEffect("del1");

inline function ondelaysync1Control(number, value)
{
		DelayTimesync1.showControl(value); 
        DelayTime1.showControl(1-value);
      
       dt1.setAttribute(dt1.delaysync, 0);
       dt1.setAttribute(dt1.delaysync, 1-value);
}


delaysync1.setControlCallback(ondelaysync1Control);

const var delaysync2 = Content.getComponent("delaysync2");
const var DelayTime2 = Content.getComponent("DelayTime2");
const var DelayTimesync2 = Content.getComponent("DelayTimesync2");


const var dt2 = Synth.getEffect("del2");

inline function ondelaysync2Control(number, value)
{
		DelayTimesync2.showControl(value); 
        DelayTime2.showControl(1-value);
      
      dt2.setAttribute(dt2.delaysync, 0);
       dt2.setAttribute(dt2.delaysync, 1-value);
    
}


delaysync2.setControlCallback(ondelaysync2Control);

const var delaysync3 = Content.getComponent("delaysync3");
const var DelayTime3 = Content.getComponent("DelayTime3");
const var DelayTimesync3 = Content.getComponent("DelayTimesync3");


const var dt3 = Synth.getEffect("del3");

inline function ondelaysync3Control(number, value)
{
		DelayTimesync3.showControl(value); 
        DelayTime3.showControl(1-value);
      
       dt3.setAttribute(dt3.delaysync, 0);
       dt3.setAttribute(dt3.delaysync, 1-value);
}


delaysync3.setControlCallback(ondelaysync3Control);

const var delaysync4 = Content.getComponent("delaysync4");
const var DelayTime4 = Content.getComponent("DelayTime4");
const var DelayTimesync4 = Content.getComponent("DelayTimesync4");


const var dt4 = Synth.getEffect("del4");

inline function ondelaysync4Control(number, value)
{
		DelayTimesync4.showControl(value); 
        DelayTime4.showControl(1-value);
      
       dt4.setAttribute(dt4.delaysync, 0);
       dt4.setAttribute(dt4.delaysync, 1-value);
}


delaysync4.setControlCallback(ondelaysync4Control);


//Draw Combobox

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
    g.setFont("Avenir", 16.0);
   
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});

laf.registerFunction("drawPresetBrowserListItem", function(g, obj)
{
    if(obj.selected)
    {
        g.setColour(0x22FFFFFF);
        g.fillRoundedRectangle(obj.area, 5.0);
        
       g.setFont("Avenir", 16.0);
    }
   
    g.setColour(obj.textColour);
    g.setFont("Avenir", 16.0);
    g.drawAlignedText(obj.text, obj.area, "centred");
});

// Multichannel menus
const var MultiChannelTest = Synth.getChildSynth("oi grandad");


const var matrix = MultiChannelTest.getRoutingMatrix();

const var SucessLabel = Content.getComponent("SucessLabel");
const var SucessLabel1 = Content.getComponent("SucessLabel1");
const var SucessLabel2 = Content.getComponent("SucessLabel2");
const var SucessLabel3 = Content.getComponent("SucessLabel3");


inline function onOutputSelectorControl(component, value)
{
	
	local success = true;
	
	switch(value)
    {
        case 1: 
            matrix.addConnection(0, 0);
            matrix.addConnection(1, 1);
            break;
        case 2: 
            matrix.addConnection(0, 2);
            
          
            success = matrix.addConnection(1, 3);
            break;
        case 3:
            matrix.addConnection(0, 4);
            success = matrix.addConnection(1, 5);
            break;
        case 4:
            matrix.addConnection(0, 6);
            success = matrix.addConnection(1, 7);
            break;
    }
    
    if(!success)
    {
        matrix.addConnection(0, 0);
        matrix.addConnection(1, 1);
    }
    
    SucessLabel.set("text", success ? "OK" : "Error");
};

Content.getComponent("OutputSelector").setControlCallback(onOutputSelectorControl);


inline function onOutputSelector1Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(2, 0);
            matrix.addConnection(3, 1);
            break;
        case 2:
            matrix.addConnection(2, 2);
            success = matrix.addConnection(3, 3);
            break;
        case 3:
            matrix.addConnection(2, 4);
            success = matrix.addConnection(3, 5);
            break;
        case 4:
            matrix.addConnection(2, 6);
            success = matrix.addConnection(3, 7);
            break;
    }
    
    if(!success)
    {
        matrix.addConnection(2, 0);
        matrix.addConnection(3, 1);
    }
    
    SucessLabel1.set("text", success ? "OK" : "Error");
};

Content.getComponent("OutputSelector1").setControlCallback(onOutputSelector1Control);



inline function onOutputSelector2Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(4, 0);
            matrix.addConnection(5, 1);
            break;
        case 2:
            matrix.addConnection(4, 2);
            success = matrix.addConnection(5, 3);
            break;
        case 3:
            matrix.addConnection(4, 4);
            success = matrix.addConnection(5, 5);
            break;
        case 4:
            matrix.addConnection(4, 6);
            success = matrix.addConnection(5, 7);
            break;
    }
    
    if(!success)
    {
        matrix.addConnection(4, 0);
        matrix.addConnection(5, 1);
    }
    
    SucessLabel2.set("text", success ? "OK" : "Error");
};

Content.getComponent("OutputSelector2").setControlCallback(onOutputSelector2Control);



inline function onOutputSelector3Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(6, 0);
            matrix.addConnection(7, 1);
            break;
        case 2:
            matrix.addConnection(6, 2);
            success = matrix.addConnection(7, 3);
            break;
        case 3:
            matrix.addConnection(6, 4);
            success = matrix.addConnection(7, 5);
            break;
        case 4:
            matrix.addConnection(6, 6);
            success = matrix.addConnection(7, 7);
            break;
    }
    
    if(!success)
    {
        matrix.addConnection(6, 0);
        matrix.addConnection(7, 1);
    }
    
    SucessLabel3.set("text", success ? "OK" : "Error");
};

Content.getComponent("OutputSelector3").setControlCallback(onOutputSelector3Control);


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
//show hide env params
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

//links

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

const var yop = Content.getComponent("YOPbox");


yop.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/gyckl");
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
 