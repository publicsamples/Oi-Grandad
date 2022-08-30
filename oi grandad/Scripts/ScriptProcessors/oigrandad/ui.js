Content.makeFrontInterface(854, 730);

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.fillRoundedRectangle(obj.area, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
    g.setFont("Avenir", 16.0);
   
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});
// Get a reference to the master container
const var MultiChannelTest = Synth.getChildSynth("oi grandad");

// Get a reference to its routing matrix
const var matrix = MultiChannelTest.getRoutingMatrix();

const var SucessLabel = Content.getComponent("SucessLabel");
const var SucessLabel1 = Content.getComponent("SucessLabel1");
const var SucessLabel2 = Content.getComponent("SucessLabel2");
const var SucessLabel3 = Content.getComponent("SucessLabel3");


inline function onOutputSelectorControl(component, value)
{
	
	// this variable checks if the output channel exists.
	local success = true;
	
	switch(value)
    {
        case 1: // Routes the first two input channels (= sine wave);
                // to the first to output channels
            matrix.addConnection(0, 0);
            matrix.addConnection(1, 1);
            break;
        case 2: // Routes the first two input channels
                // to the second stereo output
            matrix.addConnection(0, 2);
            
            // addConnection returns true if the connection could be added
            // if the host doesn't support multichannels, this returns false
            // and you can reset the connections to default later (see below)
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
        // Reset to Channel 1+2 in case of an error
        matrix.addConnection(0, 0);
        matrix.addConnection(1, 1);
    }
    
    SucessLabel.set("text", success ? "OK" : "Error");
};

Content.getComponent("OutputSelector").setControlCallback(onOutputSelectorControl);


inline function onOutputSelector1Control(component, value)
{
	// this variable checks if the output channel exists.
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
	// this variable checks if the output channel exists.
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
	// this variable checks if the output channel exists.
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
"Chords/shiv3.wav",
"Chords/sto_maj5911.wav",
"Chords/water_HalfDim.wav",
"Chords/wobbldrone01.wav",
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
"Chains/snare.wav",
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
"Loops/Grumbler-2.wav",
"Loops/Harpy.wav",
"Loops/Hey Consumer-3.wav",
"Loops/Hey Consumer-4.wav",
"Loops/Leaf Blower Stack.wav",
"Loops/Little Chord-1.wav",
"Loops/Little Chord-4.wav",
"Loops/MEMEME-1.wav",
"Loops/MEMEME-2.wav",
"Loops/MEMEME-3.wav",
"Loops/MEMEME-4.wav",
"Loops/MEMEME-5.wav",
"Loops/MEMEME-6.wav",
"Loops/MEMEME-7.3.wav",
"Loops/Multi-1.wav",
"Loops/Multi-2.wav",
"Loops/Multi-3.wav",
"Loops/Multi-4.wav",
"Loops/Multi-5.wav",
"Loops/Multi-6.wav",
"Loops/NoiseBeat135.wav",
"Loops/SubKick125_2.wav",
"Loops/TF82-01.wav",
"Loops/TF82-02.wav",
"Loops/Trex 2.wav",
"Loops/Trex 3.wav",
"Loops/Trex 4.wav",
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
"Loops/daft-2.wav",
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
"Loops/make-2.wav",
"Loops/make-3.wav",
"Loops/make-4.wav",
"Loops/make.wav",
"Loops/melbrass.wav",
"Loops/micro-2.wav",
"Loops/micro-3.wav",
"Loops/micro-4.wav",
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
"Loops/snakey-2.wav",
"Loops/snakey-3.wav",
"Loops/spacedancer.wav",
"Loops/sqrdance.wav",
"Loops/squeakdroid.wav",
"Loops/stack.wav",
"Loops/swing70.wav",
"Loops/tortoiseshell.wav",
"Loops/waltz110.wav",
"Loops/weaver.wav",
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
"Stems/MiniTaurCKDemo-01.wav",
"Stems/MiniTaurCKDemo-02.wav",
"Stems/MiniTaurCKDemo-03.wav",
"Stems/MiniTaurCKDemo-04.wav",
"Stems/MiniTaurCKDemo-05.wav",
"Stems/MiniTaurCKDemo-06.wav",
"Stems/MiniTaurCKDemo-07.wav",
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
"Stems/dxd-1.wav",
"Stems/dxd-10.wav",
"Stems/dxd-11.wav",
"Stems/dxd-12.wav",
"Stems/dxd-13.wav",
"Stems/dxd-14.wav",
"Stems/dxd-15.wav",
"Stems/dxd-16.wav",
"Stems/dxd-17.wav",
"Stems/dxd-19.wav",
"Stems/dxd-2.wav",
"Stems/dxd-20.wav",
"Stems/dxd-21.wav",
"Stems/dxd-22.wav",
"Stems/dxd-23.wav",
"Stems/dxd-24.wav",
"Stems/dxd-25.wav",
"Stems/dxd-26.wav",
"Stems/dxd-27.wav",
"Stems/dxd-28.wav",
"Stems/dxd-29.wav",
"Stems/dxd-3.wav",
"Stems/dxd-30.wav",
"Stems/dxd-4.wav",
"Stems/dxd-5.wav",
"Stems/dxd-6.wav",
"Stems/dxd-7.wav",
"Stems/dxd-8.wav",
"Stems/dxd-9.wav",
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
"Stems/vlid89-01.wav",
"Stems/vlid89-02.wav",
"Stems/vlid89-03.wav",
"Stems/vlid89-04.wav",
"Stems/vlid89-05.wav",
"Stems/vlid89-06.wav",
"Stems/vlid89-07.wav",
"Stems/vlid89-08.wav", 
];



const var wavesel1 = Content.getComponent("wavesel1");
inline function onwavesel1Control(component, value)
{
    Synth.getAudioSampleProcessor("gran").setFile("{PROJECT_FOLDER}"+samples[value]);
};
Content.getComponent("wavesel1").setControlCallback(onwavesel1Control);

const var wavesel2 = Content.getComponent("wavesel2");
inline function onwavesel2Control(component, value)
{
    Synth.getAudioSampleProcessor("gran2").setFile("{PROJECT_FOLDER}"+samples[value]);
};
Content.getComponent("wavesel2").setControlCallback(onwavesel2Control);


const var wavesel3 = Content.getComponent("wavesel3");
inline function onwavesel3Control(component, value)
{
    Synth.getAudioSampleProcessor("gran3").setFile("{PROJECT_FOLDER}"+samples[value]);
};
Content.getComponent("wavesel3").setControlCallback(onwavesel3Control);


const var wavesel4 = Content.getComponent("wavesel4");
inline function onwavesel4Control(component, value)
{
    Synth.getAudioSampleProcessor("gran4").setFile("{PROJECT_FOLDER}"+samples[value]);
};
Content.getComponent("wavesel4").setControlCallback(onwavesel4Control);
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
 