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

const var gran = Synth.getChildSynth("Granular1");
const var gran1 = Synth.getChildSynth("Granular2");
const var gran2 = Synth.getChildSynth("Granular3");
const var gran3 = Synth.getChildSynth("Granular4");

// Delay ensures processors exist after compile
Content.callAfterDelay(10, function()
{
    slot1.loadFile(defaultRef);
 //   slot2.loadFile(defaultRef);
 //   slot3.loadFile(defaultRef);
 //   slot4.loadFile(defaultRef);
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
const var Post1 = Content.getComponent("Post1");
const var ShowRandom1 = Content.getComponent("ShowRandom1");
const var ShowRandom2 = Content.getComponent("ShowRandom2");
const var ShowRandom3 = Content.getComponent("ShowRandom3");
const var ShowRandom4 = Content.getComponent("ShowRandom4");


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
    
    Post1.showControl(idx < 4);
    RandomControls1.showControl(0);
    RandomControls2.showControl(0);
    RandomControls3.showControl(0);
    RandomControls4.showControl(0);
    ShowRandom1.setValue(0);
    ShowRandom2.setValue(0);
    ShowRandom3.setValue(0);
    ShowRandom4.setValue(0);

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

inline function onVoiceNumberControl(component, value)
{
	if(value == 1)
	{

	VOICE0.showControl(1); 
	VOICE1.showControl(0); 
	VOICE2.showControl(0); 
	VOICE3.showControl(0); 
	gran.setBypassed(0);
	gran1.setBypassed(1);
	gran2.setBypassed(1);
	gran3.setBypassed(1);
	
	}
	
	if(value == 2)
	{
	
	VOICE0.showControl(1); 
	VOICE1.showControl(1); 
	VOICE2.showControl(0); 
	VOICE3.showControl(0); 
	gran.setBypassed(0);
	gran1.setBypassed(0);
	gran2.setBypassed(1);
	gran3.setBypassed(1);
	
	}
	
	if(value == 3)
	{
	
	VOICE0.showControl(1); 
	VOICE1.showControl(1); 
	VOICE2.showControl(1); 
	VOICE3.showControl(0); 
	gran.setBypassed(0);
	gran1.setBypassed(0);
	gran2.setBypassed(0);
	gran3.setBypassed(1);
	
	}
	
	if(value == 4)
	{
	
	VOICE0.showControl(1); 
	VOICE1.showControl(1); 
	VOICE2.showControl(1); 
	VOICE3.showControl(1); 
	gran.setBypassed(0);
	gran1.setBypassed(0);
	gran2.setBypassed(0);
	gran3.setBypassed(0);
	
	}
};

Content.getComponent("VoiceNumber").setControlCallback(onVoiceNumberControl);


inline function onPolyControl(component, value)
{
		gran.setAttribute(gran.VoiceLimit, value);
		gran1.setAttribute(gran1.VoiceLimit, value);
		gran2.setAttribute(gran2.VoiceLimit, value);
		gran3.setAttribute(gran3.VoiceLimit, value);
};

Content.getComponent("Poly").setControlCallback(onPolyControl);


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




//FX MENUS

const var FxLabelA1 = Content.getComponent("FxLabelA1");
const var FxLabelA2 = Content.getComponent("FxLabelA2");

inline function onResMode1Control(component, value)
{

	if(value == 1)
	{
	 gran.setAttribute(gran.delMode, 1);
	 FxLabelA1.setValue("OFF");
	 FxLabelA2.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  gran.setAttribute(gran.delMode, 2);
	  FxLabelA1.setValue("CUT");
	  FxLabelA2.setValue("Q");
	  }
	  if(value == 3)
	  {
	   gran.setAttribute(gran.delMode, 3);
	   FxLabelA1.setValue("CUT");
	   FxLabelA2.setValue("Q");
	   }
	   if(value == 4)
	   {
	    gran.setAttribute(gran.delMode, 4);
	    FxLabelA1.setValue("CUT");
	    FxLabelA2.setValue("Q");
	    }	
		if(value == 5)
	   {
	    gran.setAttribute(gran.delMode, 5);
	      FxLabelA1.setValue("CUT");
	    FxLabelA2.setValue("Q");
	    }
	    if(value == 6)
	       {
	        gran.setAttribute(gran.delMode, 6);
	          FxLabelA1.setValue("FREQ");
	    FxLabelA2.setValue("Q");
	        }
	    if(value == 7)
	       {
	        gran.setAttribute(gran.delMode, 7);
	          FxLabelA1.setValue("TRASH");
	    FxLabelA2.setValue("LP");
	        } 
	   if(value == 8)
	      {
	       gran.setAttribute(gran.delMode, 8);
	       FxLabelA1.setValue("Pitch");
	       FxLabelA2.setValue("LP");
	       }  
	   if(value == 9)
	   	      {
	   	       gran.setAttribute(gran.delMode, 9);
	   	       FxLabelA1.setValue("Pitch");
	       FxLabelA2.setValue("LP");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       gran.setAttribute(gran.delMode, 10);
	   	 	       FxLabelA1.setValue("Bit");
	   	 	       FxLabelA2.setValue("S&H");
	   	 	       }                                
	        
};

Content.getComponent("ResMode1").setControlCallback(onResMode1Control);

const var FxLabelA4 = Content.getComponent("FxLabelA4");
const var FxLabelA2 = Content.getComponent("FxLabelA2");

inline function onResMode2Control(component, value)
{

	if(value == 1)
	{
	 gran1.setAttribute(gran1.delMode, 1);
	 FxLabelA4.setValue("OFF");
	 FxLabelA2.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  gran1.setAttribute(gran1.delMode, 2);
	  FxLabelA4.setValue("CUT");
	  FxLabelA2.setValue("Q");
	  }
	  if(value == 3)
	  {
	   gran1.setAttribute(gran1.delMode, 3);
	   FxLabelA4.setValue("CUT");
	   FxLabelA2.setValue("Q");
	   }
	   if(value == 4)
	   {
	    gran1.setAttribute(gran1.delMode, 4);
	    FxLabelA4.setValue("CUT");
	    FxLabelA2.setValue("Q");
	    }	
		if(value == 5)
	   {
	    gran1.setAttribute(gran1.delMode, 5);
	      FxLabelA4.setValue("CUT");
	    FxLabelA2.setValue("Q");
	    }
	    if(value == 6)
	       {
	        gran1.setAttribute(gran1.delMode, 6);
	          FxLabelA4.setValue("FREQ");
	    FxLabelA2.setValue("Q");
	        }
	    if(value == 7)
	       {
	        gran1.setAttribute(gran1.delMode, 7);
	          FxLabelA4.setValue("TRASH");
	    FxLabelA2.setValue("LP");
	        } 
	   if(value == 8)
	      {
	       gran1.setAttribute(gran1.delMode, 8);
	       FxLabelA4.setValue("Pitch");
	       FxLabelA2.setValue("LP");
	       }  
	   if(value == 9)
	   	      {
	   	       gran1.setAttribute(gran1.delMode, 9);
	   	       FxLabelA4.setValue("Pitch");
	       FxLabelA2.setValue("LP");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       gran1.setAttribute(gran1.delMode, 10);
	   	 	       FxLabelA4.setValue("Bit");
	   	 	       FxLabelA2.setValue("S&H");
	   	 	       }                                
	        
};

Content.getComponent("ResMode2").setControlCallback(onResMode2Control);

const var FxLabelA3 = Content.getComponent("FxLabelA3");
const var FxLabelA4 = Content.getComponent("FxLabelA4");

inline function onResMode2Control(component, value)
{

	if(value == 1)
	{
	 gran1.setAttribute(gran1.delMode, 1);
	 FxLabelA3.setValue("OFF");
	 FxLabelA4.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  gran1.setAttribute(gran1.delMode, 2);
	  FxLabelA3.setValue("CUT");
	  FxLabelA4.setValue("Q");
	  }
	  if(value == 3)
	  {
	   gran1.setAttribute(gran1.delMode, 3);
	   FxLabelA3.setValue("CUT");
	   FxLabelA4.setValue("Q");
	   }
	   if(value == 4)
	   {
	    gran1.setAttribute(gran1.delMode, 4);
	    FxLabelA3.setValue("CUT");
	    FxLabelA4.setValue("Q");
	    }	
		if(value == 5)
	   {
	    gran1.setAttribute(gran1.delMode, 5);
	      FxLabelA3.setValue("CUT");
	    FxLabelA4.setValue("Q");
	    }
	    if(value == 6)
	       {
	        gran1.setAttribute(gran1.delMode, 6);
	          FxLabelA3.setValue("FREQ");
	    FxLabelA4.setValue("Q");
	        }
	    if(value == 7)
	       {
	        gran1.setAttribute(gran1.delMode, 7);
	          FxLabelA3.setValue("TRASH");
	    FxLabelA4.setValue("LP");
	        } 
	   if(value == 8)
	      {
	       gran1.setAttribute(gran1.delMode, 8);
	       FxLabelA3.setValue("Pitch");
	       FxLabelA4.setValue("LP");
	       }  
	   if(value == 9)
	   	      {
	   	       gran1.setAttribute(gran1.delMode, 9);
	   	       FxLabelA3.setValue("Pitch");
	       FxLabelA4.setValue("LP");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       gran1.setAttribute(gran1.delMode, 10);
	   	 	       FxLabelA3.setValue("Bit");
	   	 	       FxLabelA4.setValue("S&H");
	   	 	       }                                
	        
};

Content.getComponent("ResMode2").setControlCallback(onResMode2Control);

const var FxLabelA5 = Content.getComponent("FxLabelA5");
const var FxLabelA6 = Content.getComponent("FxLabelA6");

inline function onResMode3Control(component, value)
{

	if(value == 1)
	{
	 gran2.setAttribute(gran2.delMode, 1);
	 FxLabelA5.setValue("OFF");
	 FxLabelA6.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  gran2.setAttribute(gran2.delMode, 2);
	  FxLabelA5.setValue("CUT");
	  FxLabelA6.setValue("Q");
	  }
	  if(value == 3)
	  {
	   gran2.setAttribute(gran2.delMode, 3);
	   FxLabelA5.setValue("CUT");
	   FxLabelA6.setValue("Q");
	   }
	   if(value == 4)
	   {
	    gran2.setAttribute(gran2.delMode, 4);
	    FxLabelA5.setValue("CUT");
	    FxLabelA6.setValue("Q");
	    }	
		if(value == 5)
	   {
	    gran2.setAttribute(gran2.delMode, 5);
	      FxLabelA5.setValue("CUT");
	    FxLabelA6.setValue("Q");
	    }
	    if(value == 6)
	       {
	        gran2.setAttribute(gran2.delMode, 6);
	          FxLabelA5.setValue("FREQ");
	    FxLabelA6.setValue("Q");
	        }
	    if(value == 7)
	       {
	        gran2.setAttribute(gran2.delMode, 7);
	          FxLabelA5.setValue("TRASH");
	    FxLabelA6.setValue("LP");
	        } 
	   if(value == 8)
	      {
	       gran2.setAttribute(gran2.delMode, 8);
	       FxLabelA5.setValue("Pitch");
	       FxLabelA6.setValue("LP");
	       }  
	   if(value == 9)
	   	      {
	   	       gran2.setAttribute(gran2.delMode, 9);
	   	       FxLabelA5.setValue("Pitch");
	       FxLabelA6.setValue("LP");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       gran2.setAttribute(gran2.delMode, 10);
	   	 	       FxLabelA5.setValue("Bit");
	   	 	       FxLabelA6.setValue("S&H");
	   	 	       }                                
	        
};

Content.getComponent("ResMode3").setControlCallback(onResMode3Control);

const var FxLabelA7 = Content.getComponent("FxLabelA7");
const var FxLabelA8 = Content.getComponent("FxLabelA8");

inline function onResMode4Control(component, value)
{

	if(value == 1)
	{
	 gran3.setAttribute(gran3.delMode, 1);
	 FxLabelA7.setValue("OFF");
	 FxLabelA8.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  gran3.setAttribute(gran3.delMode, 2);
	  FxLabelA7.setValue("CUT");
	  FxLabelA8.setValue("Q");
	  }
	  if(value == 3)
	  {
	   gran3.setAttribute(gran3.delMode, 3);
	   FxLabelA7.setValue("CUT");
	   FxLabelA8.setValue("Q");
	   }
	   if(value == 4)
	   {
	    gran3.setAttribute(gran3.delMode, 4);
	    FxLabelA7.setValue("CUT");
	    FxLabelA8.setValue("Q");
	    }	
		if(value == 5)
	   {
	    gran3.setAttribute(gran3.delMode, 5);
	      FxLabelA7.setValue("CUT");
	    FxLabelA8.setValue("Q");
	    }
	    if(value == 6)
	       {
	        gran3.setAttribute(gran3.delMode, 6);
	          FxLabelA7.setValue("FREQ");
	    FxLabelA8.setValue("Q");
	        }
	    if(value == 7)
	       {
	        gran3.setAttribute(gran3.delMode, 7);
	          FxLabelA7.setValue("TRASH");
	    FxLabelA8.setValue("LP");
	        } 
	   if(value == 8)
	      {
	       gran3.setAttribute(gran3.delMode, 8);
	       FxLabelA7.setValue("Pitch");
	       FxLabelA8.setValue("LP");
	       }  
	   if(value == 9)
	   	      {
	   	       gran3.setAttribute(gran3.delMode, 9);
	   	       FxLabelA7.setValue("Pitch");
	       FxLabelA8.setValue("LP");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       gran3.setAttribute(gran3.delMode, 10);
	   	 	       FxLabelA7.setValue("Bit");
	   	 	       FxLabelA8.setValue("S&H");
	   	 	       }                                
	        
};

Content.getComponent("ResMode4").setControlCallback(onResMode4Control);

const var FxLabelB1 = Content.getComponent("FxLabelB1");
const var FxLabelB2 = Content.getComponent("FxLabelB2");
const var FxLabelB3 = Content.getComponent("FxLabelB3");

const var Final1 = Synth.getEffect("Final1");

inline function onPostMode1Control(component, value)
{
		if(value == 1)
	{
	 Final1.setAttribute(Final1.delMode, 1);
	 FxLabelB1.setValue("OFF");
	 FxLabelB2.setValue("OFF");
	 FxLabelB3.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  Final1.setAttribute(Final1.delMode, 2);
	  FxLabelB1.setValue("LP");
	  FxLabelB2.setValue("Q");
	  FxLabelB3.setValue("HP");
	  }
	  if(value == 3)
	  {
	   Final1.setAttribute(Final1.delMode, 3);
	   FxLabelB1.setValue("HP");
	   FxLabelB2.setValue("Q");
	   FxLabelB3.setValue("LP");
	   }
	   if(value == 4)
	   {
	    Final1.setAttribute(Final1.delMode, 4);
	    FxLabelB1.setValue("BP");
	    FxLabelB2.setValue("Q");
	    FxLabelB3.setValue("LP");
	    }	
		if(value == 5)
	   {
	    Final1.setAttribute(Final1.delMode, 5);
	      FxLabelB1.setValue("BP");
	    FxLabelB2.setValue("Q");
	    FxLabelB3.setValue("HP");
	    }
	    if(value == 6)
	       {
	        Final1.setAttribute(Final1.delMode, 6);
	          FxLabelB1.setValue("CUT");
	    FxLabelB2.setValue("Q");
	    FxLabelB3.setValue("GAIN");
	        }
	    if(value == 7)
	       {
	        Final1.setAttribute(Final1.delMode, 7);
	          FxLabelB1.setValue("CUT");
	    FxLabelB2.setValue("Q");
	    FxLabelB3.setValue("GAIN");
	        } 
	   if(value == 8)
	      {
	       Final1.setAttribute(Final1.delMode, 8);
	       FxLabelB1.setValue("AP");
	       FxLabelB2.setValue("Q");
	       FxLabelB3.setValue("HP");
	       }  
	   if(value == 9)
	   	      {
	   	       Final1.setAttribute(Final1.delMode, 9);
	   	       FxLabelB1.setValue("Time");
	       FxLabelB2.setValue("LP");
	       FxLabelB3.setValue("FEED");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       Final1.setAttribute(Final1.delMode, 10);
	   	 	       FxLabelB1.setValue("DELAY");
	   	 	       FxLabelB2.setValue("LP");
	   	 	       FxLabelB3.setValue("FEED");
	   	 	       }                                
	     if(value == 11)
	     	   	 	      {
	     	   	 	       Final1.setAttribute(Final1.delMode, 11);
	     	   	 	       FxLabelB1.setValue("SIZE");
	     	   	 	       FxLabelB2.setValue("DAMP");
	     	   	 	       FxLabelB3.setValue("WIDTH");
	     	   	 	       }         

};

Content.getComponent("PostMode1").setControlCallback(onPostMode1Control);


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
 