/** Macro Plugin Parameter Example.

This snippet demonstrates how to use the macro control system for a dynamic plugin parameter assignment
so that the user can assign any control to a plugin parameter.

In order for this to work, you will need to add two preprocessor macros to your ExtraDefinitions fields in the project settings:

HISE_MACROS_ARE_PLUGIN_PARAMETERS=1
HISE_NUM_MACROS=4

Obviously you can use any number instead of 4, but for this snippet we'll keep it lean...

*/



namespace MacroParameterHandling
{

// Use EXACTLY as many names as you define with HISE_NUM_MACROS in your extra definitions here
Engine.setFrontendMacros(["Slot 1", "Slot 2", "Slot 3", "Slot 4", "Slot 5", "Slot 6", "Slot 7", "Slot 8"]);

const var mh = Engine.createMacroHandler();

// This command will make sure that you can't assign more than one parameter to a macro slot
// (omit this if you want to keep this, but usually you want a 1:1 connection to plugin parameters)
mh.setExclusiveMode(false);

//Note that macro assignments are part of the user preset data model, so they will be 
// restored correctly when loading a DAW session. However if you want to keep the 
// macro assignments consistent across user preset browsing, you will have to implement 
// this manually by saving and restoring the macro connection data
const var uph = Engine.createUserPresetHandler();

reg currentMacroConnections;

// This will be executed before a preset is loaded
uph.setPreCallback(function(presetData)
{
	// checks if the preset load is coming from a user trying to load a preset
	// (as opposed to the DAW restoring the project session)
	if(!uph.isInternalPresetLoad())
	{
		// Store the current macro connections as a JSON object.
		currentMacroConnections = mh.getMacroDataObject();
	}
});

// This will be executed after a preset load and will restore the macro connection objects
// when the user loads a preset so they stay consistent across browsing presets.
uph.setPostCallback(function(presetFile)
{
	if(!uph.isInternalPresetLoad() && isDefined(currentMacroConnections))
	{
		mh.setMacroDataFromObject(currentMacroConnections);
	}
});
	
}

const var posoffset1 = Content.getComponent("posoffset1");
const var posoffset2 = Content.getComponent("posoffset2");
const var posoffset3 = Content.getComponent("posoffset3");
const var posoffset4 = Content.getComponent("posoffset4");

inline function onMacroPos1Control(component, value)
{
	pos.setValue(value);
	pos.changed();
	posoffset1.setValue(value);
	posoffset1.changed();
};

Content.getComponent("MacroPos1").setControlCallback(onMacroPos1Control);

inline function onMacroPos2Control(component, value)
{
	pos1.setValue(value);
	pos1.changed();
	posoffset2.setValue(value);
	posoffset2.changed();
};

Content.getComponent("MacroPos2").setControlCallback(onMacroPos2Control);


inline function onMacroPos3Control(component, value)
{
	pos2.setValue(value);
	pos2.changed();
	posoffset3.setValue(value);
	posoffset3.changed();
};

Content.getComponent("MacroPos3").setControlCallback(onMacroPos3Control);


inline function onMacroPos4Control(component, value)
{
	pos3.setValue(value);
	pos3.changed();
	posoffset4.setValue(value);
	posoffset4.changed();
};

Content.getComponent("MacroPos4").setControlCallback(onMacroPos4Control);

const var pitchoffset1 = Content.getComponent("pitchoffset1");
const var pitchoffset2 = Content.getComponent("pitchoffset2");
const var pitchoffset3 = Content.getComponent("pitchoffset3");
const var pitchoffset4 = Content.getComponent("pitchoffset4");


inline function onMacroPitch1Control(component, value)
{
		pitchoffset1.setValue(value);
		pitchoffset1.changed();
		pitch.setValueNormalized(value);
		pitch.changed();
};

Content.getComponent("MacroPitch1").setControlCallback(onMacroPitch1Control);


inline function onMacroPitch2Control(component, value)
{
	pitchoffset2.setValue(value);
		pitchoffset2.changed();
		pitch1.setValueNormalized(value);
		pitch1.changed();
};

Content.getComponent("MacroPitch2").setControlCallback(onMacroPitch2Control);


inline function onMacroPitch3Control(component, value)
{
		pitchoffset3.setValue(value);
		pitchoffset3.changed();
		pitch2.setValueNormalized(value);
		pitch2.changed();
};

Content.getComponent("MacroPitch3").setControlCallback(onMacroPitch3Control);


inline function onMacroPitch4Control(component, value)
{
		pitchoffset4.setValue(value);
		pitchoffset4.changed();
		pitch3.setValueNormalized(value);
		pitch3.changed();
};

Content.getComponent("MacroPitch4").setControlCallback(onMacroPitch4Control);

const var Vol0 = Content.getComponent("Vol0");
const var Vol1 = Content.getComponent("Vol1");
const var Vol2 = Content.getComponent("Vol2");
const var Vol3 = Content.getComponent("Vol3");


inline function onMacroGainControl(component, value)
{
	Vol0.setValueNormalized(value);
	Vol0.changed();
};

Content.getComponent("MacroGain").setControlCallback(onMacroGainControl);


inline function onMacroGain1Control(component, value)
{
	Vol1.setValueNormalized(value);
	Vol1.changed();
};

Content.getComponent("MacroGain1").setControlCallback(onMacroGain1Control);


inline function onMacroGain2Control(component, value)
{
	Vol2.setValueNormalized(value);
	Vol2.changed();
};

Content.getComponent("MacroGain2").setControlCallback(onMacroGain2Control);


inline function onMacroGain3Control(component, value)
{
	Vol3.setValueNormalized(value);
	Vol3.changed();
};

Content.getComponent("MacroGain3").setControlCallback(onMacroGain3Control);




