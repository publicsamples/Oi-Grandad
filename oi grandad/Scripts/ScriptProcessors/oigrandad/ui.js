Content.makeFrontInterface(860, 690);

Engine.loadAudioFilesIntoPool();

reg g_isPresetLoadInProgress = false;
reg g_isUpdatingTabButtons = false;

////Engine.setMaximumBlockSize(512);

const var defaultRef = "{PROJECT_FOLDER}OGInit.wav";

const var g1 = Synth.getAudioSampleProcessor("Granular1");
const var g2 = Synth.getAudioSampleProcessor("Granular2");
const var g3 = Synth.getAudioSampleProcessor("Granular3");
const var g4 = Synth.getAudioSampleProcessor("Granular4");

const var slot1 = g1.getAudioFile(0);
const var slot2 = g2.getAudioFile(0);
const var slot3 = g3.getAudioFile(0);
const var slot4 = g4.getAudioFile(0);

// Delay ensures processors exist after compile
Content.callAfterDelay(10, function()
{
    slot1.loadFile(defaultRef);
    slot2.loadFile(defaultRef);
    slot3.loadFile(defaultRef);
    slot4.loadFile(defaultRef);
});

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

include("RR.js");
include("rec.js");

//include("MultiChannel.js");
include("ModControls.js");
include("Rect.js");

include("GeneralLAF.js");

//main knobs
include("KnobLAF.js");

include("KnobLAF2.js");

//regular mods
include("KnobLAF3.js");

//mini
include("KnobLAF4.js");

//Mini Mods
include("KnobLAF5.js");


include("Voice1.js");
include("Voice2.js");
include("Voice3.js");
include("Voice4.js");


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
	if (g_isPresetLoadInProgress || g_isUpdatingTabButtons)
		return;

	g_isUpdatingTabButtons = true;

	local idx = buttons.indexOf(component);
		
	for (i = 0; i < panels.length; i++)
    {
        panels[i].showControl(idx == i);
		local shouldBeOn = (i == idx && value);
		if (buttons[i].getValue() != shouldBeOn)
        	buttons[i].setValue(shouldBeOn);
    }

	g_isUpdatingTabButtons = false;
}

onButtonControl(buttons[0], true);


//AnFile1.referToData(AudioWaveform);

 //

 const var gran = Synth.getChildSynth("Granular1");
 const var gran1 = Synth.getChildSynth("Granular2");
 const var gran2 = Synth.getChildSynth("Granular3");
 const var gran3 = Synth.getChildSynth("Granular4");


const var psync1 = Content.getComponent("psync1");
const var pitch8 = Content.getComponent("pitch8");
const var ps1 = Synth.getChildSynth("Granular1");
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


//Playback Menu



const var Filter1 = Synth.getMidiProcessor("Filter1");
const var Filter2 = Synth.getMidiProcessor("Filter2");
const var Filter3 = Synth.getMidiProcessor("Filter3");
const var Filter4 = Synth.getMidiProcessor("Filter4");

const var LedPanel = Content.getComponent("LedPanel");


const var Playback = Content.getComponent("Playback");

const var XFcont = Content.getComponent("XFcont");

const var xf1 = Synth.getEffect("Xf1");
const var xf2 = Synth.getEffect("Xf2");
const var xf3 = Synth.getEffect("Xf3");
const var xf4 = Synth.getEffect("Xf4");

const var xfade = Synth.getModulator("xfade");

const var VOICE0 = Content.getComponent("VOICE0");
const var VOICE1 = Content.getComponent("VOICE1");
const var VOICE2 = Content.getComponent("VOICE2");
const var VOICE3 = Content.getComponent("VOICE3");


inline function onPlaybackControl(component, value)
{
	//standard
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
	VOICE0.showControl(1); 
	VOICE1.showControl(1); 
	VOICE2.showControl(1); 
	VOICE3.showControl(1); 
	gran.setBypassed(0);
	gran1.setBypassed(0);
	gran2.setBypassed(0);
	gran3.setBypassed(0);
	gran.setAttribute(gran.VoiceLimit, 1);
	gran1.setAttribute(gran1.VoiceLimit, 1);
	gran2.setAttribute(gran2.VoiceLimit, 1);
	gran3.setAttribute(gran3.VoiceLimit, 1);
	
	}
	
	//Round Robin
	
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
	VOICE0.showControl(1); 
		VOICE1.showControl(1); 
		VOICE2.showControl(1); 
		VOICE3.showControl(1); 
		gran.setBypassed(0);
		gran1.setBypassed(0);
		gran2.setBypassed(0);
		gran3.setBypassed(0);
		gran.setAttribute(gran.VoiceLimit, 1);
		gran1.setAttribute(gran1.VoiceLimit, 1);
		gran2.setAttribute(gran2.VoiceLimit, 1);
		gran3.setAttribute(gran3.VoiceLimit, 1);
	}
	
	//xfade
	
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
	VOICE0.showControl(1); 
		VOICE1.showControl(1); 
		VOICE2.showControl(1); 
		VOICE3.showControl(1); 
		gran.setBypassed(0);
		gran1.setBypassed(0);
		gran2.setBypassed(0);
		gran3.setBypassed(0);
		gran.setAttribute(gran.VoiceLimit, 1);
		gran1.setAttribute(gran1.VoiceLimit, 1);
		gran2.setAttribute(gran2.VoiceLimit, 1);
		gran3.setAttribute(gran3.VoiceLimit, 1);

	}
	
	

	if(value == 4)
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
	VOICE0.showControl(1); 
	VOICE0.setValue(1); 
	VOICE0.changed(); 
	VOICE1.showControl(1); 
	VOICE2.showControl(1); 
	VOICE3.showControl(1); 
	gran.setBypassed(0);
	gran1.setBypassed(0);
	gran2.setBypassed(0);
	gran3.setBypassed(0);
	gran.setAttribute(gran.VoiceLimit, 4);
	gran1.setAttribute(gran1.VoiceLimit, 4);
	gran2.setAttribute(gran2.VoiceLimit, 4);
	gran3.setAttribute(gran3.VoiceLimit, 4);
	
	
	}
	
	if(value == 5)
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
	VOICE0.showControl(1); 
	VOICE0.setValue(1); 
	VOICE0.changed(); 
	VOICE1.showControl(1); 
	VOICE2.showControl(0); 
	VOICE3.showControl(0); 
	gran.setBypassed(0);
	gran1.setBypassed(0);
	gran2.setBypassed(1);
	gran3.setBypassed(1);
	gran.setAttribute(gran.VoiceLimit, 6);
	gran1.setAttribute(gran1.VoiceLimit, 6);
	gran2.setAttribute(gran2.VoiceLimit, 1);
	gran3.setAttribute(gran3.VoiceLimit, 1);
	
	}
	
	if(value == 6)
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
		VOICE0.showControl(1); 
		VOICE0.setValue(1); 
		VOICE0.changed(); 
		VOICE1.showControl(0); 
		VOICE2.showControl(0); 
		VOICE3.showControl(0); 
		gran.setBypassed(0);
		gran1.setBypassed(1);
		gran2.setBypassed(1);
		gran3.setBypassed(1);
		gran.setAttribute(gran.VoiceLimit, 8);
		gran1.setAttribute(gran1.VoiceLimit, 1);
		gran2.setAttribute(gran2.VoiceLimit, 1);
		gran3.setAttribute(gran3.VoiceLimit, 1);
		
		}
	
};

Content.getComponent("Playback").setControlCallback(onPlaybackControl);


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
	 if (g_isPresetLoadInProgress)
	 	return;

     if (value)
 	    Synth.playNote(MidiNote.getValue()+23, 127);
 	  else
	    Engine.allNotesOff();
};
 
Content.getComponent("Hold").setControlCallback(onHoldControl);



inline function onRecordControl(component, value)
{
	if (g_isPresetLoadInProgress)
		return;

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
	if (g_isPresetLoadInProgress)
		return;

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
	if (g_isPresetLoadInProgress)
		return;

	if (value)
		return;
		
	local dir = FileSystem.getFolder(FileSystem.AudioFiles).getChildFile("Recordings");
	
	if (isDefined(dir) && dir.isDirectory())
		dir.show();	

};

Content.getComponent("ShowFolder").setControlCallback(onShowFolderControl);

//OverSample Menus





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
 