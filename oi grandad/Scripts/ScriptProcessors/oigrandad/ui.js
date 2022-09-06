Content.makeFrontInterface(865, 737);
Engine.loadAudioFilesIntoPool();
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
const var gmulti1 = Content.getComponent("gmulti1");
const var grs1 = Synth.getEffect("gran");

inline function ongsync1Control(number, value)
{
		grainsizesync1.showControl(value); 
		gmulti1.showControl(value); 
        grainsize1.showControl(1-value);
      
       grs1.setAttribute(grs1.gsync, 0);
       grs1.setAttribute(grs1.gsync, 1-value);
}


gsync1.setControlCallback(ongsync1Control);

const var gsync2 = Content.getComponent("gsync2");
const var grainsize2 = Content.getComponent("grainsize2");
const var grainsizesync2 = Content.getComponent("grainsizesync2");
const var gmulti2 = Content.getComponent("gmulti2");
const var grs2 = Synth.getEffect("gran2");

inline function ongsync2Control(number, value)
{
		grainsizesync2.showControl(value); 
		gmulti2.showControl(value); 
        grainsize2.showControl(1-value);
        
      
       grs2.setAttribute(grs2.gsync, 0);
       grs2.setAttribute(grs2.gsync, 1-value);
}


gsync2.setControlCallback(ongsync2Control);

const var gsync3 = Content.getComponent("gsync3");
const var grainsize3 = Content.getComponent("grainsize3");
const var grainsizesync3 = Content.getComponent("grainsizesync3");
const var gmulti3 = Content.getComponent("gmulti3");
const var grs3 = Synth.getEffect("gran3");

inline function ongsync3Control(number, value)
{
		grainsizesync3.showControl(value); 
		gmulti3.showControl(value); 
        grainsize3.showControl(1-value);
      
       grs3.setAttribute(grs3.gsync, 0);
       grs3.setAttribute(grs3.gsync, 1-value);
}


gsync3.setControlCallback(ongsync3Control);

const var gsync4 = Content.getComponent("gsync4");
const var grainsize4 = Content.getComponent("grainsize4");
const var grainsizesync4 = Content.getComponent("grainsizesync4");
const var gmulti4 = Content.getComponent("gmulti4");

const var grs4 = Synth.getEffect("gran4");

inline function ongsync4Control(number, value)
{
		grainsizesync4.showControl(value); 
		gmulti4.showControl(value); 
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

//sample loadi

const var Granular1 = Synth.getAudioSampleProcessor("gran");
const var Granular2 = Synth.getAudioSampleProcessor("gran2");
const var Granular3 = Synth.getAudioSampleProcessor("gran3");
const var Granular4 = Synth.getAudioSampleProcessor("gran4");

const samples = ["Chords/AIR.wav",
"Chords/AIR.wav",
"Chords/BANGER.wav",
"Chords/Bad Guy m7_9.wav",
"Chords/Bad Guy_m7th.wav",
"Chords/DW_Dom7.wav",
"Chords/Eggz_AugMaj7.wav",
"Chords/FormerWoosher_sus7_9.wav",
"Chords/Hardly_MajMin7.wav",
"Chords/MIGHT.wav",
"Chords/Mod_AugDom7.wav",
"Chords/Synthetic_Dom.wav",
"Chords/USBnoise.wav",
"Chords/Wonk_maj-7-11-*9.wav",
"Chords/disaster.wav",
"Chords/edust_maj-7-9-11-13.wav",
"Chords/fast_maj7-*9-11-13.wav",
"Chords/glassy_min7.wav",
"Chords/modaldrony.wav",
"Chords/mover1.wav",
"Chords/mover2.wav",
"Chords/mover3.wav",
"Chords/mover4.wav",
"Chords/mover5.wav",
"Chords/shiv01.wav",
"Chords/shiv2.wav",
"Chords/shiv3.wav"
];

const chains = ["Chains/basschain-0.wav",
"Chains/basschain-0.wav",
"Chains/basschain-_1.wav",
"Chains/basschain-_2.wav",
"Chains/basschain-_3.wav",
"Chains/chordchain01.wav",
"Chains/cs1.wav",
"Chains/fx.wav",
"Chains/hats.wav",
"Chains/kick.wav",
"Chains/loopch01.wav",
"Chains/ms01.wav",
"Chains/perc.wav",
"Chains/ps2-drums.wav",
"Chains/ps2Chords.wav",
"Chains/ps2orchestra.wav",
"Chains/random13001.wav",
"Chains/simple.wav",
"Chains/snare.wav"
];



const sweeps = ["Sweeps/1012n.wav",
"Sweeps/1012n.wav",
"Sweeps/4tri.wav",
"Sweeps/60-EHUC.aif",
"Sweeps/60-S21W.aif",
"Sweeps/60-VI9W.aif",
"Sweeps/60-YUYI.aif",
"Sweeps/BrdsATL.wav",
"Sweeps/FOLDFM.wav",
"Sweeps/FoldSine.wav",
"Sweeps/FoldSwitch.wav",
"Sweeps/HQFM.wav",
"Sweeps/HQsqr.wav",
"Sweeps/MWT.wav",
"Sweeps/SQR_AM.wav",
"Sweeps/WTLFO.wav",
"Sweeps/bigwt.wav",
"Sweeps/dfamsqrlp.wav",
"Sweeps/fm01.wav",
"Sweeps/fsaw.wav",
"Sweeps/hgsaw.wav",
"Sweeps/hrsqr.wav",
"Sweeps/mring.wav",
"Sweeps/mstring.wav",
"Sweeps/noisyrandomseq01.wav",
"Sweeps/nstring.wav",
"Sweeps/pita.wav",
"Sweeps/rmfilt.wav",
"Sweeps/shpmod.wav",
"Sweeps/syncf.wav",
"Sweeps/toy.wav",
"Sweeps/triresr.wav",
"Sweeps/usub.wav",
"Sweeps/vowel.wav",
];

const loops = ["Loops/1bnce=01.wav",
"Loops/1bnce=01.wav",
"Loops/1bnce=02.wav",
"Loops/1bnce=03.wav",
"Loops/74cc.wav",
"Loops/8note.wav",
"Loops/AJ-01.wav",
"Loops/AJ-02.wav",
"Loops/BellWithFreind.wav",
"Loops/ClickyBass133.wav",
"Loops/DFKick-135#03.3.wav",
"Loops/DFKick-135#05.3.wav",
"Loops/DFKickA-125.wav",
"Loops/DFKickB-125#02.1.wav",
"Loops/Dragger.wav",
"Loops/Gbellls-2.wav",
"Loops/Gbellls-3.wav",
"Loops/Gbellls.wav",
"Loops/GigaMoth.wav",
"Loops/Grumbler-1.wav",
"Loops/Harpy.wav",
"Loops/Hey Consumer-3.wav",
"Loops/Leaf Blower Stack.wav",
"Loops/Little Chord-1.wav",
"Loops/MEMEME-1.wav",
"Loops/Multi-1.wav",
"Loops/NoiseBeat135.wav",
"Loops/SubKick125_2.wav",
"Loops/TF82-01.wav",
"Loops/TF82-02.wav",
"Loops/Trex.wav",
"Loops/TuneMe90.wav",
"Loops/UniSqr - mod.wav",
"Loops/UniSqr - no mod.wav",
"Loops/arpthenmodwith.wav",
"Loops/bells1.wav",
"Loops/bells2.wav",
"Loops/bells3.wav",
"Loops/bellsB.wav",
"Loops/bigdeal.wav",
"Loops/blondechord.wav",
"Loops/bounce.wav",
"Loops/brash.wav",
"Loops/break.wav",
"Loops/bytemod.wav",
"Loops/daft-1.wav",
"Loops/deepbeeps.wav",
"Loops/df-quant.wav",
"Loops/dile-1.wav",
"Loops/dropsy.wav",
"Loops/electro135.wav",
"Loops/epic.wav",
"Loops/freemoontrip.wav",
"Loops/glassy.wav",
"Loops/grace.wav",
"Loops/grace2.wav",
"Loops/greatest.wav",
"Loops/hot.wav",
"Loops/hp-bass.wav",
"Loops/hp-perc.wav",
"Loops/latin90.wav",
"Loops/make.wav",
"Loops/melbrass.wav",
"Loops/micro.wav",
"Loops/minor fireworks-1.wav",
"Loops/organ.wav",
"Loops/pens.wav",
"Loops/perc133.wav",
"Loops/perc2133.wav",
"Loops/restperiod.wav",
"Loops/rico.wav",
"Loops/rings-pluck.wav",
"Loops/rock88.wav",
"Loops/roundsharp.wav",
"Loops/simple mod saw.wav",
"Loops/slightchords135.wav",
"Loops/slowbrain.wav",
"Loops/snakey-1.wav",
"Loops/spacedancer.wav",
"Loops/sqrdance.wav",
"Loops/squeakdroid.wav",
"Loops/stack.wav",
"Loops/swing70.wav",
"Loops/tortoiseshell.wav",
"Loops/waltz110.wav",
"Loops/weaver.wav"
];
const stems= ["Stems/4sel84-01.wav",
"Stems/4sel84-01.wav",
"Stems/4sel84-02.wav",
"Stems/4sel84-03.wav",
"Stems/Birdlike - mod.wav",
"Stems/Birdlike - porto.wav",
"Stems/Birdlike.wav",
"Stems/ClimA76-01.wav",
"Stems/ClimA76-02.wav",
"Stems/ClimA76-03.wav",
"Stems/ClimA76-04.wav",
"Stems/Climb121-01.wav",
"Stems/Climb121-02.wav",
"Stems/Climb121-03.wav",
"Stems/Climb121-04.wav",
"Stems/Climb121-05.wav",
"Stems/Climb121-06.wav",
"Stems/Climb121-07.wav",
"Stems/Climb121-08.wav",
"Stems/Climb121-09.wav",
"Stems/Climb121-10.wav",
"Stems/Climb121-11.wav",
"Stems/Climb121-12.wav",
"Stems/GhostOfMD-01.wav",
"Stems/GhostOfMD-02.wav",
"Stems/GhostOfMD-03.wav",
"Stems/GhostOfMD-04.wav",
"Stems/GhostOfMD-05.wav",
"Stems/GhostOfMD-06.wav",
"Stems/JJ-01.wav",
"Stems/JJ-02.wav",
"Stems/JJ-03.wav",
"Stems/JJ-04.wav",
"Stems/JJ-05.wav",
"Stems/JJ-06.wav",
"Stems/MidCreeper-01.wav",
"Stems/MidCreeper-02.wav",
"Stems/MidCreeper-03.wav",
"Stems/MidCreeper-04.wav",
"Stems/PercT130-01.wav",
"Stems/PercT130-02.wav",
"Stems/PercT130-03.wav",
"Stems/PercT130-04.wav",
"Stems/PercT130-05.wav",
"Stems/PercT130-06.wav",
"Stems/PercT130-07.wav",
"Stems/PercT130-08.wav",
"Stems/PercT130-09.wav",
"Stems/SimpleDirty124-01.wav",
"Stems/SimpleDirty124-02.wav",
"Stems/SimpleDirty124-03.wav",
"Stems/SimpleDirty124-04.wav",
"Stems/SomethingInTheWater-01.wav",
"Stems/SomethingInTheWater-02.wav",
"Stems/SomethingInTheWater-03.wav",
"Stems/SomethingInTheWater-04.wav",
"Stems/SomethingInTheWater-05.wav",
"Stems/SomethingInTheWater-06.wav",
"Stems/SomethingInTheWater-07.wav",
"Stems/SomethingInTheWater-08.wav",
"Stems/SomethingInTheWater-09.wav",
"Stems/SomethingInTheWater-10.wav",
"Stems/TempoMucker-01.wav",
"Stems/TempoMucker-02.wav",
"Stems/TempoMucker-03.wav",
"Stems/TempoMucker-04.wav",
"Stems/TempoMucker-05.wav",
"Stems/TempoMucker-06.wav",
"Stems/TempoMucker-07.wav",
"Stems/TempoMucker-08.wav",
"Stems/TempoMucker-09.wav",
"Stems/TempoMucker-10.wav",
"Stems/TempoMucker-11.wav",
"Stems/TempoMucker-12.wav",
"Stems/TempoMucker-13.wav",
"Stems/TempoMucker-14.wav",
"Stems/TempoMucker-15.wav",
"Stems/TempoMucker-16.wav",
"Stems/Tree126-01.wav",
"Stems/Tree126-04.wav",
"Stems/grilla-02.wav",
"Stems/grilla-15.wav",
"Stems/grilla-16.wav",
"Stems/grilla-17.wav",
"Stems/holo-04.wav",
"Stems/holo-07.wav",
"Stems/holo-09.wav",
"Stems/holo-15.wav",
"Stems/inseen90-01.wav",
"Stems/inseen90-02.wav",
"Stems/inseen90-03.wav",
"Stems/inseen90-05.wav",
"Stems/maribass175-01.wav",
"Stems/maribass175-02.wav",
"Stems/maribass175-03.wav",
"Stems/maribass175-04.wav",
"Stems/maribass175-05.wav",
"Stems/maribass175-06.wav",
"Stems/maribass175-07.wav",
"Stems/maribass175-08.wav",
];


const var wavesel1 = Content.getComponent("wavesel1");
inline function onwavesel1Control(component, value)
{
    Synth.getAudioSampleProcessor("gran").setFile("{PROJECT_FOLDER}"+samples[value]);
};
Content.getComponent("wavesel1").setControlCallback(onwavesel1Control);

const var chains1 = Content.getComponent("chains1");
inline function onchains1Control(component, value)
{
    Synth.getAudioSampleProcessor("gran").setFile("{PROJECT_FOLDER}"+chains[value]);
};
Content.getComponent("chains1").setControlCallback(onchains1Control);

const var sweeps1 = Content.getComponent("sweeps1");
inline function onsweeps1Control(component, value)
{
    Synth.getAudioSampleProcessor("gran").setFile("{PROJECT_FOLDER}"+sweeps[value]);
};
Content.getComponent("sweeps1").setControlCallback(onsweeps1Control);

const var loops1 = Content.getComponent("loops1");
inline function onloops1Control(component, value)
{
    Synth.getAudioSampleProcessor("gran").setFile("{PROJECT_FOLDER}"+loops[value]);
};
Content.getComponent("loops1").setControlCallback(onloops1Control);

const var stems1 = Content.getComponent("stems1");
inline function onstems1Control(component, value)
{
    Synth.getAudioSampleProcessor("gran").setFile("{PROJECT_FOLDER}"+stems[value]);
};
Content.getComponent("stems1").setControlCallback(onstems1Control);

const var wavesel2 = Content.getComponent("wavesel2");
inline function onwavesel2Control(component, value)
{
    Synth.getAudioSampleProcessor("gran2").setFile("{PROJECT_FOLDER}"+samples[value]);
};
Content.getComponent("wavesel2").setControlCallback(onwavesel2Control);

const var chains2 = Content.getComponent("chains2");
inline function onchains2Control(component, value)
{
    Synth.getAudioSampleProcessor("gran2").setFile("{PROJECT_FOLDER}"+chains[value]);
};
Content.getComponent("chains2").setControlCallback(onchains2Control);

const var sweeps2 = Content.getComponent("sweeps2");
inline function onsweeps2Control(component, value)
{
    Synth.getAudioSampleProcessor("gran2").setFile("{PROJECT_FOLDER}"+sweeps[value]);
};
Content.getComponent("sweeps2").setControlCallback(onsweeps2Control);

const var loops2 = Content.getComponent("loops2");
inline function onloops2Control(component, value)
{
    Synth.getAudioSampleProcessor("gran2").setFile("{PROJECT_FOLDER}"+loops[value]);
};
Content.getComponent("loops2").setControlCallback(onloops2Control);

const var stems2 = Content.getComponent("stems2");
inline function onstems2Control(component, value)
{
    Synth.getAudioSampleProcessor("gran2").setFile("{PROJECT_FOLDER}"+stems[value]);
};
Content.getComponent("stems2").setControlCallback(onstems2Control);

const var wavesel3 = Content.getComponent("wavesel3");
inline function onwavesel3Control(component, value)
{
    Synth.getAudioSampleProcessor("gran3").setFile("{PROJECT_FOLDER}"+samples[value]);
};
Content.getComponent("wavesel3").setControlCallback(onwavesel3Control);

const var chains3 = Content.getComponent("chains3");
inline function onchains3Control(component, value)
{
    Synth.getAudioSampleProcessor("gran3").setFile("{PROJECT_FOLDER}"+chains[value]);
};
Content.getComponent("chains3").setControlCallback(onchains3Control);

const var sweeps3 = Content.getComponent("sweeps3");
inline function onsweeps3Control(component, value)
{
    Synth.getAudioSampleProcessor("gran3").setFile("{PROJECT_FOLDER}"+sweeps[value]);
};
Content.getComponent("sweeps3").setControlCallback(onsweeps3Control);

const var loops3 = Content.getComponent("loops3");
inline function onloops3Control(component, value)
{
    Synth.getAudioSampleProcessor("gran3").setFile("{PROJECT_FOLDER}"+loops[value]);
};
Content.getComponent("loops3").setControlCallback(onloops3Control);

const var stems3 = Content.getComponent("stems3");
inline function onstems3Control(component, value)
{
    Synth.getAudioSampleProcessor("gran3").setFile("{PROJECT_FOLDER}"+stems[value]);
};
Content.getComponent("stems3").setControlCallback(onstems3Control);

const var wavesel4 = Content.getComponent("wavesel4");
inline function onwavesel4Control(component, value)
{
    Synth.getAudioSampleProcessor("gran4").setFile("{PROJECT_FOLDER}"+samples[value]);
};
Content.getComponent("wavesel4").setControlCallback(onwavesel4Control);

const var chains4 = Content.getComponent("chains4");
inline function onchains4Control(component, value)
{
    Synth.getAudioSampleProcessor("gran4").setFile("{PROJECT_FOLDER}"+chains[value]);
};
Content.getComponent("chains4").setControlCallback(onchains4Control);

const var sweeps4 = Content.getComponent("sweeps4");
inline function onsweeps4Control(component, value)
{
    Synth.getAudioSampleProcessor("gran4").setFile("{PROJECT_FOLDER}"+sweeps[value]);
};
Content.getComponent("sweeps4").setControlCallback(onsweeps4Control);

const var loops4 = Content.getComponent("loops4");
inline function onloops4Control(component, value)
{
    Synth.getAudioSampleProcessor("gran4").setFile("{PROJECT_FOLDER}"+loops[value]);
};
Content.getComponent("loops4").setControlCallback(onloops4Control);

const var stems4 = Content.getComponent("stems4");
inline function onstems4Control(component, value)
{
    Synth.getAudioSampleProcessor("gran4").setFile("{PROJECT_FOLDER}"+stems[value]);
};
Content.getComponent("stems4").setControlCallback(onstems4Control);


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
 