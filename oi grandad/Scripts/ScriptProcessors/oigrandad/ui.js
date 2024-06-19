Content.makeFrontInterface(910, 790);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

include("RR.js");
include("MultiChannel.js");
include("ModControls.js");
include("MasterControls.js");


 //
 const var gran = Synth.getEffect("gran");
 const var gran2 = Synth.getEffect("gran2");
 const var gran3 = Synth.getEffect("gran3");
 const var gran4 = Synth.getEffect("gran4");

 const var Hold = Content.getComponent("Hold");
 const var Proc = Synth.getEffect("Proc");
 const var Proc2 = Synth.getEffect("Proc2");
 const var Proc3 = Synth.getEffect("Proc3");
 const var Proc4 = Synth.getEffect("Proc4");
 
 inline function onHoldControl(component, value)
 
  {
      if (value)
  	    Synth.playNote(60, 127);
  	  else
 	    Engine.allNotesOff();
 };
  
 Content.getComponent("Hold").setControlCallback(onHoldControl);
 
 
 
 inline function onrouteControl(component, value)
 {
	 Hold.setValue(0);
	 Proc.setAttribute(Proc.Routing, value);
	 Engine.allNotesOff();
	
 };
 
 Content.getComponent("route").setControlCallback(onrouteControl);
 
 inline function onroute2Control(component, value)
 {
 	 Hold.setValue(0);
 	 Proc2.setAttribute(Proc2.Routing, value);
 	
 };
 
 Content.getComponent("route2").setControlCallback(onroute2Control);

 inline function onroute3Control(component, value)
 {
 	 Hold.setValue(0);
 	 Proc3.setAttribute(Proc3.Routing, value);
 	 Engine.allNotesOff();
 	
 };
 
 Content.getComponent("route3").setControlCallback(onroute3Control);
 
 inline function onroute4Control(component, value)
 {
 	 Hold.setValue(0);
 	 Proc4.setAttribute(Proc4.Routing, value);
 	 Engine.allNotesOff();
 	
 };
 
 Content.getComponent("route4").setControlCallback(onroute4Control);
 
 

const var psync1 = Content.getComponent("psync1");
const var pitch8 = Content.getComponent("pitch8");
const var ps1 = Synth.getEffect("gran");
const var pmod1 = Content.getComponent("pmod1");
const var PmodSel1 = Content.getComponent("PmodSel1");

inline function onpsync1Control(number, value)

{
	if(value == 1)
		{

		pitch8.showControl(0); 
		 gran.setAttribute(gran.max, 0);   
		 gran.setAttribute(gran.step, 1);   
    }
    
    	if(value == 2)
    		{
    
    		pitch8.showControl(1); 
    		gran.setAttribute(gran.max, 1);  
    		gran.setAttribute(gran.step, 0);      
        }
        
        if(value == 3)
            		{
            
            		pitch8.showControl(0); 
            		gran.setAttribute(gran.max, 2); 
            		gran.setAttribute(gran.step, 1);               
                }
       
       if(value == 4)
               		{
               
               		pitch8.showControl(0); 
               		gran.setAttribute(gran.max, 3);  
                 	gran.setAttribute(gran.step, 1); 
                   }
}


psync1.setControlCallback(onpsync1Control);

const var psync2 = Content.getComponent("psync2");
const var pitch11 = Content.getComponent("pitch11");
const var pmod2 = Content.getComponent("pmod2");
const var PmodSel2 = Content.getComponent("PmodSel2");

inline function onpsync2Control(number, value)

{
	if(value == 1)
		{

		pitch11.showControl(0); 
		 gran2.setAttribute(gran2.max, 0);    
		 gran2.setAttribute(gran2.step, 1); 
    }
    
    	if(value == 2)
    		{
    
    		pitch11.showControl(1); 
    		gran2.setAttribute(gran2.max, 1);
    		gran2.setAttribute(gran2.step, 0);         
        }
        
        if(value == 3)
            		{
            
            		pitch11.showControl(0); 
            		gran2.setAttribute(gran2.max, 2); 
            		gran2.setAttribute(gran2.step, 1);                
                }
       
       if(value == 4)
               		{
               
               		pitch11.showControl(0); 
               		 gran2.setAttribute(gran2.max, 3);  
               		 gran2.setAttribute(gran2.step, 1); 
                 
                   }
}


psync2.setControlCallback(onpsync2Control);


const var psync3 = Content.getComponent("psync3");
const var pitch13 = Content.getComponent("pitch13");
const var pmod3 = Content.getComponent("pmod3");
const var PmodSel3 = Content.getComponent("PmodSel3");



const var ps3 = Synth.getEffect("gran3");

inline function onpsync3Control(number, value)

{
	if(value == 1)
		{

		pitch13.showControl(0); 
		 gran3.setAttribute(gran3.max, 0);
		 gran3.setAttribute(gran3.step, 1);     
    }
    
    	if(value == 2)
    		{
    
    		pitch13.showControl(1); 
    		gran3.setAttribute(gran3.max, 1);      
    		gran3.setAttribute(gran3.step, 0);     
        }
        
        if(value == 3)
            		{
            
            		pitch13.showControl(0); 
            		gran3.setAttribute(gran3.max, 2); 
            		gran3.setAttribute(gran3.step, 1);                  
                }
       
       if(value == 4)
               		{
               
               		pitch13.showControl(0); 
               		 gran3.setAttribute(gran3.max, 3); 
               		 gran3.setAttribute(gran3.step, 1);    
                 
                   }
}


psync3.setControlCallback(onpsync3Control);

const var psync4 = Content.getComponent("psync4");
const var pitch15 = Content.getComponent("pitch15");
const var pmod4 = Content.getComponent("pmod4");
const var PmodSel4 = Content.getComponent("PmodSel4");




const var ps4 = Synth.getEffect("gran4");

inline function onpsync4Control(number, value)

{
	if(value == 1)
		{

		pitch15.showControl(0); 
		 gran4.setAttribute(gran4.max, 0);  
		 gran4.setAttribute(gran4.step, 1);     
    }
    
    	if(value == 2)
    		{
    
    		pitch15.showControl(1); 
    		gran4.setAttribute(gran4.max, 1);   
    		gran4.setAttribute(gran4.step, 0);      
        }
        
        if(value == 3)
            		{
            
            		pitch15.showControl(0); 
            		gran4.setAttribute(gran4.max, 2); 
            		gran4.setAttribute(gran4.step, 1);                
                }
       
       if(value == 4)
               		{
               
               		pitch15.showControl(0); 
               		 gran4.setAttribute(gran4.max, 3);  
               		 gran4.setAttribute(gran4.step, 1); 
                 
                   }
}


psync4.setControlCallback(onpsync4Control);
//Draw Combobox

const var laf = Engine.createGlobalScriptLookAndFeel();
laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
    g.setFont("Montserrat", 16.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});

laf.registerFunction("drawSliderPack", function(g, obj)
{
    g.fillRoundedRectangle(obj.area, 8.0);
        g.rotate(90, 90);
       g.setFont("Montserrat", 16.0);


});

laf.registerFunction("drawPresetBrowserListItem", function(g, obj)
{
    if(obj.selected)
    {
        g.setColour(0x22FFFFFF);
        g.fillRoundedRectangle(obj.area, 5.0);
        
       g.setFont("Montserrat", 16.0);
    }
   
    g.setColour(obj.textColour);
    g.setFont("Montserrat", 16.0);
    g.drawAlignedText(obj.text, obj.area, "centred");
});

laf.registerFunction("drawTableRuler", function(g, obj)
{
    g.setColour(Colours.withAlpha(obj.bgColour, 0.1));
    
    var x = obj.position * obj.area[2];
    
    g.drawLine(x, x, 0, obj.area[3], 10.0);
    g.setColour(obj.bgColour);
    g.drawLine(x, x, 0, obj.area[3], 1);
});

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


//Playback Menu



const var Filter1 = Synth.getMidiProcessor("Filter1");
const var Filter2 = Synth.getMidiProcessor("Filter2");
const var Filter3 = Synth.getMidiProcessor("Filter3");
const var Filter4 = Synth.getMidiProcessor("Filter4");

const var LedPanel = Content.getComponent("LedPanel");


const var Playback = Content.getComponent("Playback");

const var XFcont = Content.getComponent("XFcont");
const var xf1 = Synth.getEffect("xf1");
const var xf2 = Synth.getEffect("xf2");
const var xf3 = Synth.getEffect("xf3");
const var xf4 = Synth.getEffect("xf4");
const var xfade = Synth.getModulator("xfade");

inline function onPlaybackControl(component, value)
{

	if(value == 1)
	{
	XFcont.showControl(0); 
	LedPanel.showControl(0); 
	xf1.setBypassed(1);
	xf2.setBypassed(1);
	xf3.setBypassed(1);
	xf4.setBypassed(1);
	xfade.setBypassed(1);
	Filter1.setBypassed(1);
	Filter2.setBypassed(1);
	Filter3.setBypassed(1);
	Filter4.setBypassed(1);
	}
	
		if(value == 2)
	{
	XFcont.showControl(0); 
	LedPanel.showControl(1); 
	xf1.setBypassed(1);
	xf2.setBypassed(1);
	xf3.setBypassed(1);
	xf4.setBypassed(1);
	xfade.setBypassed(1);
	Filter1.setBypassed(0);
	Filter2.setBypassed(0);
	Filter3.setBypassed(0);
	Filter4.setBypassed(0);
	}
	
	
		if(value == 3)
	{
	XFcont.showControl(1); 
	LedPanel.showControl(0); 
	xf1.setBypassed(0);
	xf2.setBypassed(0);
	xf3.setBypassed(0);
	xf4.setBypassed(0);
	xfade.setBypassed(0);
	Filter1.setBypassed(1);
	Filter2.setBypassed(1);
	Filter3.setBypassed(1);
	Filter4.setBypassed(1);

	}

	
	
};

Content.getComponent("Playback").setControlCallback(onPlaybackControl);

const var settings = Content.getComponent("settings");


inline function onClosePresetControl(component, value)
{
	settings.showControl(0);
	presets.setValue(0);
	presets.changed();
};

Content.getComponent("ClosePreset").setControlCallback(onClosePresetControl);

const var voice5 = Content.getComponent("voice5");
const var presets = Content.getComponent("presets");

const var Master = Content.getComponent("Master");


inline function onClosePreset1Control(component, value)
{
	voice5.showControl(0);
	Master.setValue(0);
	Master.changed();
};

Content.getComponent("ClosePreset1").setControlCallback(onClosePreset1Control);


inline function onpresetsControl(component, value)
{
 if(value == 0)
     {
	settings.showControl(0);


}

if(value == 1)
    {
	settings.showControl(1);
	voice5.showControl(0);
	Master.setValue(0);
	Master.changed();

}
	
};

Content.getComponent("presets").setControlCallback(onpresetsControl);


inline function onMasterControl(component, value)
{
    if(value == 0)
    {

	voice5.showControl(0);

	
	}
	if(value == 1)
{
	settings.showControl(0);
	voice5.showControl(1);
	presets.setValue(0);
	presets.changed();
	
	}	
};

Content.getComponent("Master").setControlCallback(onMasterControl);


const var granWav1 = Synth.getAudioSampleProcessor("gran");

const var AudioWaveform = Content.getComponent("AudioWaveform");




inline function onAudioWaveformControl(component, value)
{

if (granWav1.getSampleLength() < 352800){
   //change soft bypass here to 1
   Console.print('bad');
}
if (granWav1.getSampleLength() >= 352800){
   //change soft bypass here 0
   Console.print('ok');

}
};

Content.getComponent("AudioWaveform").setControlCallback(onAudioWaveformControl);


const var Stages1 = Content.getComponent("Stages1");
const var Stages2 = Content.getComponent("Stages2");
const var Stages3 = Content.getComponent("Stages3");
const var Stages4 = Content.getComponent("Stages4");

const var Stages5 = Content.getComponent("Stages5");
const var Stages6 = Content.getComponent("Stages6");
const var Stages7 = Content.getComponent("Stages7");
const var Stages8 = Content.getComponent("Stages8");


const var Pos1 = Content.getComponent("ScriptTable13");
const var Pos2 = Content.getComponent("ScriptTable14");
const var Pos3 = Content.getComponent("ScriptTable15");
const var Pos4 = Content.getComponent("ScriptTable16");                            

const var Pos5 = Content.getComponent("ScriptTable17");
const var Pos6 = Content.getComponent("ScriptTable18");
const var Pos7 = Content.getComponent("ScriptTable19");
const var Pos8 = Content.getComponent("ScriptTable20");

const var Pos9 = Content.getComponent("ScriptTable21");
const var Pos10 = Content.getComponent("ScriptTable22");
const var Pos11 = Content.getComponent("ScriptTable23");
const var Pos12 = Content.getComponent("ScriptTable24");

const var Pos13 = Content.getComponent("ScriptTable25");
const var Pos14 = Content.getComponent("ScriptTable26");
const var Pos15 = Content.getComponent("ScriptTable27");
const var Pos16 = Content.getComponent("ScriptTable28");

const var PosB1 = Content.getComponent("ScriptTable29");
const var PosB2 = Content.getComponent("ScriptTable30");
const var PosB3 = Content.getComponent("ScriptTable31");
const var PosB4 = Content.getComponent("ScriptTable32");                            

const var PosB5 = Content.getComponent("ScriptTable33");
const var PosB6 = Content.getComponent("ScriptTable34");
const var PosB7 = Content.getComponent("ScriptTable35");
const var PosB8 = Content.getComponent("ScriptTable36");

const var PosB9 = Content.getComponent("ScriptTable37");
const var PosB10 = Content.getComponent("ScriptTable38");
const var PosB11 = Content.getComponent("ScriptTable39");
const var PosB12 = Content.getComponent("ScriptTable40");

const var PosB13 = Content.getComponent("ScriptTable41");
const var PosB14 = Content.getComponent("ScriptTable42");
const var PosB15 = Content.getComponent("ScriptTable43");
const var PosB16 = Content.getComponent("ScriptTable44");


inline function onStgSel1Control(component, value)
{

if(value == 1)
  {

        Pos1.showControl(1);
        Pos2.showControl(0);
        Pos3.showControl(0);
        Pos4.showControl(0);
        PosB1.showControl(1);
        PosB2.showControl(0);
        PosB3.showControl(0);
        PosB4.showControl(0);
        gran.setAttribute(gran.min, 0.20);    
	}
if(value == 2)
  {

      Pos1.showControl(1);
        Pos2.showControl(1);
        Pos3.showControl(0);
        Pos4.showControl(0);
        PosB1.showControl(1);
              PosB2.showControl(1);
              PosB3.showControl(0);
              PosB4.showControl(0);
        gran.setAttribute(gran.min, 0.40);   
	}
	
if(value == 3)
  {

    Pos1.showControl(1);
        Pos2.showControl(1);
        Pos3.showControl(1);
        Pos4.showControl(0);
        PosB1.showControl(1);
              PosB2.showControl(1);
              PosB3.showControl(1);
              PosB4.showControl(0);
        gran.setAttribute(gran.min, 0.80);   
	}
	if(value == 4)
	  {
	
 Pos1.showControl(1);
        Pos2.showControl(1);
        Pos3.showControl(1);
        Pos4.showControl(1);
        gran.setAttribute(gran.min, 1);
        PosB1.showControl(1);
              PosB2.showControl(1);
              PosB3.showControl(1);
              PosB4.showControl(1);   
		}
};

Content.getComponent("StgSel1").setControlCallback(onStgSel1Control);

inline function onStgSel2Control(component, value)
{

if(value == 1)
  {

        Pos5.showControl(1);
        Pos6.showControl(0);
        Pos7.showControl(0);
        Pos8.showControl(0);
        PosB5.showControl(1);
        PosB6.showControl(0);
        PosB7.showControl(0);
        PosB8.showControl(0);  
        gran2.setAttribute(gran2.min, 0.20);    
	}
if(value == 2)
  {

      Pos5.showControl(1);
        Pos6.showControl(1);
        Pos7.showControl(0);
        Pos8.showControl(0);
        PosB5.showControl(1);
        PosB6.showControl(1);
        PosB7.showControl(0);
        PosB8.showControl(0);
        gran2.setAttribute(gran2.min, 0.40);   
	}
	
if(value == 3)
  {

    Pos5.showControl(1);
        Pos6.showControl(1);
        Pos7.showControl(1);
        Pos8.showControl(0);
        PosB5.showControl(1);
        PosB6.showControl(1);
        PosB7.showControl(1);
        PosB8.showControl(0);
        gran2.setAttribute(gran2.min, 0.80);   
	}
	if(value == 4)
	  {
	
 Pos5.showControl(1);
        Pos6.showControl(1);
        Pos7.showControl(1);
        Pos8.showControl(1);
        PosB5.showControl(1);
        PosB6.showControl(1);
        PosB7.showControl(1);
        PosB8.showControl(1);
        gran2.setAttribute(gran2.min, 1);   
		}
};

Content.getComponent("StgSel2").setControlCallback(onStgSel2Control);


inline function onStgSel3Control(component, value)
{

if(value == 1)
  {

        Pos9.showControl(1);
        Pos10.showControl(0);
        Pos11.showControl(0);
        Pos12.showControl(0);
		PosB9.showControl(1);
        PosB10.showControl(0);
        PosB11.showControl(0);
        PosB12.showControl(0);
        gran3.setAttribute(gran3.min, 0.20);    
	}
if(value == 2)
  {

      Pos9.showControl(1);
        Pos10.showControl(1);
        Pos11.showControl(0);
        Pos12.showControl(0);
		PosB9.showControl(1);
        PosB10.showControl(1);
        PosB11.showControl(0);
        PosB12.showControl(0);
        gran3.setAttribute(gran3.min, 0.40);   
	}
	
if(value == 3)
  {

    Pos9.showControl(1);
        Pos10.showControl(1);
        Pos11.showControl(1);
        Pos12.showControl(0);
		PosB9.showControl(1);
        PosB10.showControl(1);
        PosB11.showControl(1);
        PosB12.showControl(0); 
        gran3.setAttribute(gran3.min, 0.80);   
	}
	if(value == 4)
	  {
	
 Pos9.showControl(1);
        Pos10.showControl(1);
        Pos11.showControl(1);
        Pos12.showControl(1);
		PosB9.showControl(1);
        PosB10.showControl(1);
        PosB11.showControl(1);
        PosB12.showControl(1); 
        gran3.setAttribute(gran3.min, 1);   
		}
};

Content.getComponent("StgSel3").setControlCallback(onStgSel3Control);



inline function onStgSel4Control(component, value)
{

if(value == 1)
  {

        Pos13.showControl(1);
        Pos14.showControl(0);
        Pos15.showControl(0);
        Pos16.showControl(0);
        PosB13.showControl(1);
        PosB14.showControl(0);
        PosB15.showControl(0);
        PosB16.showControl(0);
        gran4.setAttribute(gran4.min, 0.20);    
	}
if(value == 2)
  {

      Pos13.showControl(1);
        Pos14.showControl(1);
        Pos15.showControl(0);
        Pos16.showControl(0);
        PosB13.showControl(1);
        PosB14.showControl(1);
        PosB15.showControl(0);
        PosB16.showControl(0);
        gran4.setAttribute(gran4.min, 0.40);   
	}
	
if(value == 3)
  {

    Pos13.showControl(1);
        Pos14.showControl(1);
        Pos15.showControl(1);
        Pos16.showControl(0);
        PosB13.showControl(1);
        PosB14.showControl(1);
        PosB15.showControl(1);
        PosB16.showControl(0);
        gran4.setAttribute(gran4.min, 0.80);   
	}
	if(value == 4)
	  {
	
 Pos13.showControl(1);
        Pos14.showControl(1);
        Pos15.showControl(1);
        Pos16.showControl(1);
        PosB13.showControl(1);
        PosB14.showControl(1);
        PosB15.showControl(1);
        PosB16.showControl(1);
        gran4.setAttribute(gran4.min, 1);   
		}
};

Content.getComponent("StgSel4").setControlCallback(onStgSel4Control);


inline function onposmode1Control(component, value)
{
	gran.setAttribute(gran.posmode, value);
	
	if(value == 1)
	  {
	
	 Stages1.showControl(0);
	 Stages5.showControl(0);
	
		}
	
	if(value == 2)
	  {
	
	 Stages1.showControl(0);
	 Stages5.showControl(0);
	
		}
		
	if(value == 3)
	  {
	
	 Stages1.showControl(0);
	 Stages5.showControl(0);
	
		}
	if(value == 4)
	  {
	
	 Stages1.showControl(1);
	 Stages5.showControl(1);
	
		}	
													
};

Content.getComponent("posmode1").setControlCallback(onposmode1Control);


inline function onposmode2Control(component, value)
{
	gran2.setAttribute(gran2.posmode, value);
	
	if(value == 1)
	  {
	
	 Stages2.showControl(0);
	 Stages6.showControl(0);
	
		}
	
	if(value == 2)
	  {
	
	 Stages2.showControl(0);
	 Stages6.showControl(0);
	
		}
		
	if(value == 3)
	  {
	
	 Stages2.showControl(0);
	 Stages6.showControl(0);
	
		}
	if(value == 4)
	  {
	
	 Stages2.showControl(1);
	 Stages6.showControl(1);
	
		}	
													
};

Content.getComponent("posmode2").setControlCallback(onposmode2Control);


inline function onposmode3Control(component, value)
{
	gran3.setAttribute(gran3.posmode, value);
	
	if(value == 1)
	  {
	
	 Stages3.showControl(0);
	 Stages7.showControl(0);
	
		}
	
	if(value == 2)
	  {
	
	 Stages3.showControl(0);
	 Stages7.showControl(0);
	
		}
		
	if(value == 3)
	  {
	
	 Stages3.showControl(0);
	 Stages7.showControl(0);
	
		}
	if(value == 4)
	  {
	
	 Stages3.showControl(1);
	 Stages7.showControl(1);
	
		}	
													
};

Content.getComponent("posmode3").setControlCallback(onposmode3Control);


inline function onposmode4Control(component, value)
{
	gran4.setAttribute(gran4.posmode, value);
	
	if(value == 1)
	  {
	
	 Stages4.showControl(0);
	 Stages8.showControl(0);
	
		}
	
	if(value == 2)
	  {
	
	 Stages4.showControl(0);
	 Stages8.showControl(0);
	
		}
		
	if(value == 3)
	  {
	
	 Stages4.showControl(0);
	 Stages8.showControl(0);
	
		}
	if(value == 4)
	  {
	
	 Stages4.showControl(1);
	 Stages8.showControl(1);
	
		}	
													
};

Content.getComponent("posmode4").setControlCallback(onposmode4Control);


function onNoteOn()
{
// the index is zero based like everything else in good
	// programming, so we need to add one to get the actual
	// channel number
	local d = rrIndex+1;
	
	
	// Store the value in the MIDIList for the note on
	EventIdStack.push(noteOnChannels, Message.getEventId(), d);
	Console.print(d);
for (i = 0; i < RrLed.length; i++)
	        RrLed[i].setValue(d - 1 == i);
	Message.setChannel(d);
	
	
	
	// Cycle through the round robin amount
	if(rrIndex++ >= 3)
	    rrIndex = 0;

}
 
function onNoteOff()
{
    local c = EventIdStack.pop(noteOnChannels, Message.getEventId());
	Message.setChannel(c);
   
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
 