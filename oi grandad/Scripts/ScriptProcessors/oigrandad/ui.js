Content.makeFrontInterface(892, 785);

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
		pitch8.showControl(1-value); 
		pitch8.showControl(value); 
		pmod1.showControl(1-value); 
		pmod1.showControl(value); 
		PmodSel1.showControl(1-value); 
		PmodSel1.showControl(value); 
  gran.setAttribute(ps1.gsync, value);  
    
       
}


psync1.setControlCallback(onpsync1Control);

const var psync2 = Content.getComponent("psync2");
const var pitch11 = Content.getComponent("pitch11");
const var pmod2 = Content.getComponent("pmod2");
const var PmodSel2 = Content.getComponent("PmodSel2");




const var ps2 = Synth.getEffect("gran2");

inline function onpsync2Control(number, value)
{
		pitch11.showControl(1-value);
		pitch11.showControl(value); 
        ps2.setAttribute(ps2.gsync, value);   
        pmod2.showControl(1-value); 
        	pmod2.showControl(value); 
        	PmodSel2.showControl(1-value); 
        	PmodSel2.showControl(value); 
       
}


psync2.setControlCallback(onpsync2Control);

const var psync3 = Content.getComponent("psync3");
const var pitch13 = Content.getComponent("pitch13");
const var pmod3 = Content.getComponent("pmod3");
const var PmodSel3 = Content.getComponent("PmodSel3");



const var ps3 = Synth.getEffect("gran3");

inline function onpsync3Control(number, value)
{
		pitch13.showControl(1-value);    
		pitch13.showControl(value); 
        ps3.setAttribute(ps3.gsync, value);
   		pmod3.showControl(1-value); 
       	pmod3.showControl(value); 
       	PmodSel3.showControl(1-value); 
       	PmodSel3.showControl(value); 
       
}


psync3.setControlCallback(onpsync3Control);

const var psync4 = Content.getComponent("psync4");
const var pitch15 = Content.getComponent("pitch15");
const var pmod4 = Content.getComponent("pmod4");
const var PmodSel4 = Content.getComponent("PmodSel4");




const var ps4 = Synth.getEffect("gran4");

inline function onpsync4Control(number, value)
{
		pitch15.showControl(1-value);
		pitch15.showControl(value); 
        ps4.setAttribute(ps4.gsync, value); 
		pmod4.showControl(1-value); 
        pmod4.showControl(value); 
        PmodSel4.showControl(1-value); 
        PmodSel4.showControl(value); 
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
};

Content.getComponent("ClosePreset").setControlCallback(onClosePresetControl);


//presets
const var Pbox = [];

Pbox[0] = Content.getComponent("settings");
Pbox[1] = Content.getComponent("blank1");
Pbox[2] = Content.getComponent("blank2");

const var pre= Content.getComponent("presets");

inline function onpresetsControl(component, value)
{
    if(value == 1)
    {
	settings.showControl(1);
	}

	
};

Content.getComponent("presets").setControlCallback(onpresetsControl);






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
 