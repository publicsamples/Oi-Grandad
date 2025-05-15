Content.makeFrontInterface(860, 690);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

include("RR.js");
include("rec.js");

//include("MultiChannel.js");
include("ModControls.js");
include("Rect.js");

include("GeneralLAF.js");
include("KnobLAF.js");
include("KnobLAF4.js");
include("KnobLAF2.js");
include("KnobLAF3.js");
include("Voice1.js");
include("Voice2.js");
include("Voice3.js");
include("Voice4.js");

include("Files.js");

include("macros.js");


const var BoxItems = Content.getComponent("BoxItems");

//Tabs

const var NUM_BUTTONS = 6;
const var buttons = [];
const var panels = [];

for (i = 0; i < NUM_BUTTONS; i++)
{
    buttons[i] = Content.getComponent("VOICE" + (i));
    panels[i] = Content.getComponent("V" + (i));
    buttons[i].setControlCallback(onButtonControl);
}

inline function onButtonControl(component, value)
{
	local idx = buttons.indexOf(component);
		
	for (i = 0; i < panels.length; i++)
    {
        panels[i].showControl(idx == i);
        buttons[i].setValue(i == idx && value);
        BoxItems.showControl(0);
    }
}

onButtonControl(buttons[0], true);


//AnFile1.referToData(AudioWaveform);

 //
 const var gran = Synth.getEffect("gran");
 const var gran2 = Synth.getEffect("gran2");
 const var gran3 = Synth.getEffect("gran3");
 const var gran4 = Synth.getEffect("gran4");

const var psync1 = Content.getComponent("psync1");
const var pitch8 = Content.getComponent("pitch8");
const var ps1 = Synth.getEffect("gran");
const var pmod1 = Content.getComponent("pmod1");
const var PmodSel1 = Content.getComponent("PmodSel1");





//links

const var UPP = Content.getComponent("UPP");


UPP.setMouseCallback(function(event)
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

const var PlgInPk = Content.getComponent("PlgInPk");

PlgInPk.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/esioxy");
  } 
  else 
  {
    link_hover = event.hover;
    this.repaint();
  }
});


const var BoxItem1 = Content.getComponent("BoxItem1");

BoxItem1.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/gyckl/vjdyz48");
  } 
  else 
  {
 //   link_hover = event.hover;
    this.repaint();
  }
});

const var BoxItem2 = Content.getComponent("BoxItem2");

BoxItem2.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/lybce/1qhl90k");
  } 
  else 
  {
 //   link_hover = event.hover;
    this.repaint();
  }
});

const var BoxItem3 = Content.getComponent("BoxItem3");

BoxItem3.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/lybce/1qhl90k");
  } 
  else 
  {
  //  link_hover = event.hover;
    this.repaint();
  }
});

const var BoxItem4 = Content.getComponent("BoxItem4");

BoxItem4.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://github.com/publicsamples/Oi-Grandad/discussions/6");
  } 
  else 
  {
 //   link_hover = event.hover;
    this.repaint();
  }
});

const var BoxItem5 = Content.getComponent("BoxItem5");

BoxItem5.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://github.com/publicsamples/Oi-Grandad/discussions/31");
  } 
  else 
  {
 //   link_hover = event.hover;
    this.repaint();
  }
});

const var ScriptPanel15 = Content.getComponent("ScriptPanel15");

ScriptPanel15.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  } 
  else 
  {
 //   link_hover = event.hover;
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


//mystrey box
const var BoxItem =[];

BoxItem[0] = Content.getComponent("BoxItem1");
BoxItem[1] = Content.getComponent("BoxItem2");
BoxItem[2] = Content.getComponent("BoxItem3");
BoxItem[3] = Content.getComponent("BoxItem4");
BoxItem[4] = Content.getComponent("BoxItem5");

const var BoxSel = Content.getComponent("BoxSel");


inline function onBoxSelControl(component, value)
{

for (i = 0; i < BoxItem.length; i++)
        BoxItem[i].showControl(value - 1 == i);
    }
    

Content.getComponent("BoxSel").setControlCallback(onBoxSelControl);





inline function onCloseBoxControl(component, value)
{
	BoxItems.showControl(0);
};

Content.getComponent("CloseBox").setControlCallback(onCloseBoxControl);



inline function onScriptButton1Control(component, value)
{
if(value == 1)
{
	
	BoxItems.fadeComponent(1, 1000);
	BoxSel.setValue(Math.randInt(1, 6));
	BoxSel.changed();
	
	}
	
};

Content.getComponent("ScriptButton1").setControlCallback(onScriptButton1Control);

inline function onScriptButton2Control(component, value)
{
	if(value == 1)
	{

	BoxItems.fadeComponent(1, 1000);
	BoxSel.setValue(Math.randInt(1, 6));
	BoxSel.changed();
	
	}
	
};

Content.getComponent("ScriptButton2").setControlCallback(onScriptButton2Control);


inline function onScriptButton3Control(component, value)
{
	BoxItems.fadeComponent(1, 1000);
	BoxSel.setValue(Math.randInt(1, 6));
	BoxSel.changed();
	
};

Content.getComponent("ScriptButton3").setControlCallback(onScriptButton3Control);



inline function onScriptButton4Control(component, value)
{
	BoxItems.fadeComponent(1, 1000);
	BoxSel.setValue(Math.randInt(1, 6));
	BoxSel.changed();
	
};

Content.getComponent("ScriptButton4").setControlCallback(onScriptButton4Control);

/*
	This snippet implements a stereo audio recorder
	The final audio file is written to a file and loaded into an Audio Loop Player
*/

const var RecBuffer = Synth.getAudioSampleProcessor("RecBuffer");
const var afSlot = RecBuffer.getAudioFile(0);

const var Record = Content.getComponent("Record");
const var MidiNote = Content.getComponent("MidiNote");

global g_record = false; // the processBlock is waiting for this flag
global g_accumulator = []; // will be reserved for a 30sec length in prepareToPlay to prevent allocating too much in the audio thread (at least for 30sec...)


inline function onHoldControl(component, value)

 {
     if (value)
 	    Synth.playNote(MidiNote.getValue(), 127);
 	  else
	    Engine.allNotesOff();
};
 
Content.getComponent("Hold").setControlCallback(onHoldControl);



inline function onRecordControl(component, value)
{
	g_record = value;
	
	if (value == 1)
	{
	 Synth.playNote(MidiNote.getValue()+24, 127);
//	 Synth.addNoteOn(1, MidiNote.getValue()+12, 64, 0);
	 	
		
	//	return;
	}
	Console.startBenchmark();
	
	// no need to create a file at compile time...
	if (g_accumulator.length > 0)
		reconstructFromAccumulator();
		
	Console.stopBenchmark();
	if (value == 0)
	{
	///	Synth.addNoteOff(1, 64, 10000);
	  Engine.allNotesOff();
	    }
	
};

Content.getComponent("Record").setControlCallback(onRecordControl);


inline function reconstructFromAccumulator()
{
	// The length of the final audio file
	local s = g_accumulator.length * Engine.getBufferSize();
	
	// prepare a stereo buffer holder
	local audioDataStereo = [Buffer.create(s), Buffer.create(s)];
	
	// iterate over the stereo accumulator
	for (st in g_accumulator)
	{
		local st_idx = g_accumulator.indexOf(st); // index of the current blockSize buffer stereo array
		
		// pair of buffers
		for (b in st)
		{
			local b_idx = st.indexOf(b); // so left/right
			
			// we take a slice reference of the buffer we want to write into (accumulator left or right, from sample idx, numSamples).
			local tempBuffer = Buffer.referTo(audioDataStereo[b_idx], st_idx * b.length, b.length);
			
			b >> tempBuffer; // here we write in the reference slice so it gets "copied" to the audioDataStereo buffer automatically
		}
	}
	
	// clean for next time
	g_accumulator.clear();
	
	exportAndLoadAudioFile(audioDataStereo);
}

const var RecLabel = Content.getComponent("RecLabel");


inline function exportAndLoadAudioFile(audioData)
{
		
	// append the timestamp to filename to get a unique file
//	local filename = "OG_" +  + ".wav";
	
	// prepare and write the audio file in the project folder
	local f = FileSystem.getFolder(FileSystem.AudioFiles).getChildFile("Recordings/" + RecLabel.getValue() + ".wav");
	f.writeAudioFile(audioData, Engine.getSampleRate(), 24);
	
	// inform there's a new file
	Engine.loadAudioFilesIntoPool();
	
	// load
	if (f.isFile())
		afSlot.loadFile("{PROJECT_FOLDER}" + "Recordings" + f.toString(f.Filename));
}


const var Hold = Content.getComponent("Hold");
const var ShowFolder = Content.getComponent("ShowFolder");

inline function onRecEnable1Control(component, value)
{
	Record.showControl(value);
	Record.setValue(0);
	Record.changed();
	ShowFolder.showControl(value);
	RecLabel.showControl(value);
	Hold.showControl(value-1);
	Hold.setValue(0);
	Hold.changed();
};

Content.getComponent("RecEnable1").setControlCallback(onRecEnable1Control);



inline function onShowFolderControl(component, value)
{
	if (value)
		return;
		
	local dir = FileSystem.getFolder(FileSystem.AudioFiles).getChildFile("Recordings");
	
	if (isDefined(dir) && dir.isDirectory())
		dir.show();	

};

Content.getComponent("ShowFolder").setControlCallback(onShowFolderControl);

//OverSample Menus


inline function onOS1Control(component, value)
{
	Engine.allNotesOff();

	gran.setAttribute(gran.over, value);
};

Content.getComponent("OS1").setControlCallback(onOS1Control);


inline function onOS2Control(component, value)
{
		Engine.allNotesOff();

	gran2.setAttribute(gran2.over, value);
};

Content.getComponent("OS2").setControlCallback(onOS2Control);


inline function onOS3Control(component, value)
{
	Engine.allNotesOff();
	
	gran3.setAttribute(gran3.over, value);
};

Content.getComponent("OS3").setControlCallback(onOS3Control);


inline function onOS4Control(component, value)
{
	Engine.allNotesOff();
	
	gran4.setAttribute(gran4.over, value);
};

Content.getComponent("OS4").setControlCallback(onOS4Control);

//presets

const var cmbPresets = Content.getComponent("cmbPresets");
cmbPresets.setControlCallback(oncmbPresetsControl);

inline function oncmbPresetsControl(component, value)
{
	if (!value)
		return;

	local itemText = Engine.getUserPresetList()[value - 1] + ".preset";
	
	Engine.loadUserPreset(itemText);
	Console.print(itemText);
}

populatePresetsMenu();

inline function populatePresetsMenu()
{
	cmbPresets.set("items", "");

	for (x in Engine.getUserPresetList())
	{
		local arr = x.split("/");			
		local item = "";
		
		for (i = 0; i < arr.length; i++)
		{
			item += arr[i];
			
			if (i < arr.length - 1)
				item += "::";
		}

		cmbPresets.addItem(item);
	}
}
function onNoteOn()
{
// the index is zero based like everything else in good
	// programming, so we need to add one to get the actual
	// channel number
	local d = rrIndex+1;
	
	
	// Store the value in the MIDIList for the note on
	EventIdStack.push(noteOnChannels, Message.getEventId(), d);
	Console.print(d);
for (i = 1; i < RrLed.length; i++)
	        RrLed[i].setValue(d - 0 == i);
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
 