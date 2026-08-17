Content.makeFrontInterface(960, 720);

const var rm = Engine.getGlobalRoutingManager();


reg g_isPresetLoadInProgress = false;
reg g_isUpdatingTabButtons = false;



const var g1 = Synth.getAudioSampleProcessor("Granular1");
const var g2 = Synth.getAudioSampleProcessor("Granular2");
const var g3 = Synth.getAudioSampleProcessor("Granular3");
const var g4 = Synth.getAudioSampleProcessor("Granular4");



const var gran = Synth.getChildSynth("Granular1");
const var gran1 = Synth.getChildSynth("Granular2");
const var gran2 = Synth.getChildSynth("Granular3");
const var gran3 = Synth.getChildSynth("Granular4");



Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "Montserrat");

include("RR.js");
include("rec.js");

include("MultiChannel.js");
include("ModControls.js");
include("Rect.js");

include("GeneralLAF.js");

//main knobs
include("KnobLAF.js");

include("KnobLAF2.js");

//regular mods
//include("KnobLAF3.js");

//mini
include("KnobLAF4.js");

//Mini Mods
include("KnobLAF5.js");


include("Voice1.js");
include("Voice2.js");
include("Voice3.js");
include("Voice4.js");


include("macros.js");



//Tabs

const var NUM_BUTTONS = 6;
const var buttons = [];
const var panels = [];
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
    
  //  Post1.showControl(idx < 4);
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


const var ps1 = Synth.getChildSynth("Granular1");




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

const var XolLink = Content.getComponent("XolLink");

XolLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://github.com/publicsamples/Xolotl");
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

const var PolyFxLabels =
[
	[Content.getComponent("FxLabelA1"), Content.getComponent("FxLabelA2")],
	[Content.getComponent("FxLabelA1001"), Content.getComponent("FxLabelA1002")],
	[Content.getComponent("FxLabelA2001"), Content.getComponent("FxLabelA2002")],
	[Content.getComponent("FxLabelA3001"), Content.getComponent("FxLabelA3002")]
];

const var PostFxLabels =
[
	[Content.getComponent("FxLabelB1"), Content.getComponent("FxLabelB2"), Content.getComponent("FxLabelB3")],
	[Content.getComponent("FxLabelB1001"), Content.getComponent("FxLabelB1002"), Content.getComponent("FxLabelB1003")],
	[Content.getComponent("FxLabelB2001"), Content.getComponent("FxLabelB2002"), Content.getComponent("FxLabelB2003")],
	[Content.getComponent("FxLabelB3001"), Content.getComponent("FxLabelB3002"), Content.getComponent("FxLabelB3003")]
];

const var PolyFxText =
[
	["OFF", "OFF"],
	["CUT", "Q"],
	["CUT", "Q"],
	["CUT", "Q"],
	["CUT", "Q"],
	["FREQ", "Q"],
	["TRASH", "LP"],
	["Pitch", "LP"],
	["Pitch", "LP"],
	["Bit", "S&H"]
];

const var PostFxText =
[
	["OFF", "OFF", "OFF"],
	["LP", "Q", "HP"],
	["HP", "Q", "LP"],
	["BP", "Q", "LP"],
	["BP", "Q", "HP"],
	["CUT", "Q", "GAIN"],
	["CUT", "Q", "GAIN"],
	["AP", "Q", "HP"],
	["Time", "LP", "FEED"],
	["DELAY", "LP", "FEED"],
	["SIZE", "DAMP", "WIDTH"]
];

const var PolyFxProcessors = [gran, gran1, gran2, gran3];
const var PostFxProcessors = [Synth.getEffect("Final1"), Synth.getEffect("Final2"), Synth.getEffect("Final3"), Synth.getEffect("Final4")];

inline function setLabelTextArray(labels, values)
{
	for (i = 0; i < labels.length; i++)
		labels[i].set("text", values[i]);
}

inline function updatePolyFxMode(index, value)
{
	if (value < 1)
		return;

	PolyFxProcessors[index].setAttribute(PolyFxProcessors[index].FxMode, value);
	setLabelTextArray(PolyFxLabels[index], PolyFxText[value - 1]);
}

inline function updatePostFxMode(index, value)
{
	if (value < 1)
		return;

	PostFxProcessors[index].setAttribute(PostFxProcessors[index].delMode, value);
	setLabelTextArray(PostFxLabels[index], PostFxText[value - 1]);
}

inline function onResMode1Control(component, value) { updatePolyFxMode(0, value); }
inline function onResMode2Control(component, value) { updatePolyFxMode(1, value); }
inline function onResMode3Control(component, value) { updatePolyFxMode(2, value); }
inline function onResMode4Control(component, value) { updatePolyFxMode(3, value); }

inline function onPostMode1Control(component, value) { updatePostFxMode(0, value); }
inline function onPostMode2Control(component, value) { updatePostFxMode(1, value); }
inline function onPostMode3Control(component, value) { updatePostFxMode(2, value); }
inline function onPostMode4Control(component, value) { updatePostFxMode(3, value); }

Content.getComponent("ResMode1").setControlCallback(onResMode1Control);
Content.getComponent("ResMode2").setControlCallback(onResMode2Control);
Content.getComponent("ResMode3").setControlCallback(onResMode3Control);
Content.getComponent("ResMode4").setControlCallback(onResMode4Control);

Content.getComponent("PostMode1").setControlCallback(onPostMode1Control);
Content.getComponent("PostMode2").setControlCallback(onPostMode2Control);
Content.getComponent("PostMode3").setControlCallback(onPostMode3Control);
Content.getComponent("PostMode4").setControlCallback(onPostMode4Control);


const var Mgain1 = Synth.getEffect("Mgain1");
const var Mgain2 = Synth.getEffect("Mgain2");
const var Mgain3 = Synth.getEffect("Mgain3");
const var Mgain4 = Synth.getEffect("Mgain4");


inline function onMasterVolControl(component, value)
{
	Mgain1.setAttribute(Mgain1.Gain, value);
	Mgain2.setAttribute(Mgain2.Gain, value);
	Mgain3.setAttribute(Mgain3.Gain, value);
	Mgain4.setAttribute(Mgain4.Gain, value);
};

Content.getComponent("MasterVol").setControlCallback(onMasterVolControl);


const var ModulationMatrix = Content.getComponent("ModulationMatrix");
const var ModulationMatrixTile = Content.getComponent("ScriptFloatingTile1");
const var ModulationMatrixLaf = Content.createLocalLookAndFeel();

ModulationMatrixLaf.setInlineStyleSheet("
/** The background panel for the matrix. */
.matrix
{
	content: '';
	background: #354259;
	border-radius: 3px;
	padding-left:10px;
	padding-top:10px;
	color: #FFFF8A8A; 
	
}

/** If there are no connections we show a empty message. */
.matrix:empty { 
  color: #ccc; 
  content: 'No connections..'; 
}


/** The matrix table header. */
th { background: transparent; 
	padding:0px;
	margin-top: -40px;}

td { background: transparent; 
	padding:10px;
	height:30px;
	}
	


td, .targetLabel
{
	color: #999;
	font-size: 15px;
}

.targetLabel
{
	width: 130px;
}

.slider
{
	background: #5e6270;
	border-radius: 3px;
	margin: 2px;
	color: #B2F3EBE7;
	height:25px;
	width:80px;

}

.slider:empty
{
	color: #FFFF8A8A;
}

.slider::before
{
	content: '';
	width: calc(var(--value) * 100%);
	height: 100%;
	background-color: #FFFF8A8A;
	position: absolute;
	margin: 5px;
}

.unipolar::before, .bipolar::before
{
	
	
	/* this calculates the bipolar width with some advanced
	   CSS math expression skills. */
	width: max(calc(calc(0.5 - var(--value)) * 100%),  
	           calc(calc(var(--value) - 0.5) * 100%)); 
	           
	/* this calculates the leftmost position of the value rectangle. */
	left: min(calc(var(--value) * 100%), 50%);
}

select
{
	background: #5e6270;
	border-radius: 3px;
	color: ##EDE6D5;
	text-align: center;
	padding-left: 0px;
	width:90px;
	font-size:12px;
	height:25px;
}

/** Draw the drop down arrow. */
select::before
{
	/** CSS requires that you specify a content property for
	    any pseudo element that is supposed to be shown. */
	content: '';
	
	/** Pass in a Base64 string for any path using the standard HISE Path converter. */
	background-image: \"84.t0lavsBQ76.tCwF..VDQX+9fCw1WJBDQnj.cCwFp5YBQ3NhqCwly0w.QzMCcCwF..d.QTV.gCwFD6YBQpsevCwVtvsBQn.AtCwlavsBQ76.tCMVY\";
	
	background-color: rgba(255,255,255, 0.4);
	
	/** Set the position to absolute so that it won't cut into the text area. */
	position: absolute;
	width: 100vh;
	margin: 8px;
	right: 0px;
}

/** Make the arrow light up at hover. */
select::before:hover
{
	background-color: black;
}

.search
{
	background: #555;
	margin-bottom: 00px;
	padding: 0px;
	height: 0px;
	border-radius: 0px;
	padding-left: 0vh;
	color: #999;
}

.search::before
{
	content: '';
	background-image: var(--icon);
	background-color: #888;
	width: 0vh;
	margin: 0px;
}

#clearsearch
{
	background-color: #888;
	height: 0px;
	margin: 0px;
	margin-top: 10px;
}

button
{
	
	border-radius: 3px;
	background: #5e6270;
	color: #C96868;
	width:40px;
	height:25px;
	content: 'Off';
}

.modplotter
{
		background: #5e6270;
	color: #C96868;
	width:0px;
		height:0px;
}

/** The add/remove/clear buttons. */
.control-button
{
	width: 70px;
	/** Reset the content property so that the original text is displayed. */
	content: ''; 
}


button:checked
{
	background: #999;
	color: #333;
	content: 'On';
}


");


ModulationMatrix.setPaintRoutine(function(g)
{
	var area = this.getLocalBounds(0);
//	local padding = 2;
	var inner = [area[0] + padding, area[1] + padding, area[2] - padding * 2, area[3] - padding * q];
	var header = [inner[0], inner[1], inner[2], 40];
	var body = [inner[0], inner[1] + 30, inner[2], inner[3] - 30];

	g.setGradientFill([0xFF354259, inner[0], inner[1], 0xFF354259, inner[0], inner[1] + inner[3]]);
	g.fillRoundedRectangle(inner, 1.0);


	g.setColour(0xFFB7C0CC);
	g.setFont("Montserrat", 18.0);


//	g.setColour(0x16FFFFFF);
//	g.fillRoundedRectangle(body, 10.0);

});

ModulationMatrixTile.setLocalLookAndFeel(ModulationMatrixLaf);
function onNoteOn()
{
// the index is zero based like everything else in good
	// programming, so we need to add one to get the actual
	// channel number
	var d = rrIndex+1;
	
	
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
    var c = EventIdStack.pop(noteOnChannels, Message.getEventId());
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
 