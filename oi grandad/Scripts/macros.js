const var pitch = Content.getComponent("pitch");
const var pitch1 = Content.getComponent("pitch1");
const var pitch2 = Content.getComponent("pitch2");
const var pitch3 = Content.getComponent("pitch3");

const var MacroPitch1 = Content.getComponent("MacroPitch1");
const var MacroPitch2 = Content.getComponent("MacroPitch2");
const var MacroPitch3 = Content.getComponent("MacroPitch3");
const var MacroPitch4 = Content.getComponent("MacroPitch4");
const var MacroGain = Content.getComponent("MacroGain");
const var MacroGain1 = Content.getComponent("MacroGain1");
const var MacroGain2 = Content.getComponent("MacroGain2");
const var MacroGain3 = Content.getComponent("MacroGain3");


inline function onpitchControl(component, value)
{
	gran.setAttribute(gran.Pitch, value);
	MacroPitch1.setValue(value);
};

Content.getComponent("pitch").setControlCallback(onpitchControl);


inline function onMacroPitch1Control(component, value)
{
	
		pitch.setValue(value);
		pitch.changed();
};

Content.getComponent("MacroPitch1").setControlCallback(onMacroPitch1Control);


inline function onpitch1Control(component, value)
{
	gran1.setAttribute(gran1.Pitch, value);
	MacroPitch2.setValue(value);
};

Content.getComponent("pitch1").setControlCallback(onpitch1Control);


inline function onMacroPitch2Control(component, value)
{
	
		pitch1.setValue(value);
		pitch1.changed();
};

Content.getComponent("MacroPitch2").setControlCallback(onMacroPitch2Control);


inline function onpitch2Control(component, value)
{
	gran2.setAttribute(gran2.Pitch, value);
	MacroPitch3.setValue(value);
};

Content.getComponent("pitch2").setControlCallback(onpitch2Control);


inline function onMacroPitch3Control(component, value)
{
	
		pitch2.setValue(value);
		pitch2.changed();
};

Content.getComponent("MacroPitch3").setControlCallback(onMacroPitch3Control);


inline function onpitch3Control(component, value)
{
	gran3.setAttribute(gran3.Pitch, value);
	MacroPitch4.setValue(value);
};

Content.getComponent("pitch3").setControlCallback(onpitch3Control);


inline function onMacroPitch4Control(component, value)
{
	
		pitch3.setValue(value);
		pitch3.changed();
};

Content.getComponent("MacroPitch4").setControlCallback(onMacroPitch4Control);

const var Vol0 = Content.getComponent("Vol0");
const var Vol1 = Content.getComponent("Vol1");
const var Vol2 = Content.getComponent("Vol2");
const var Vol3 = Content.getComponent("Vol3");


inline function onVol0Control(component, value)
{
	gran.setAttribute(gran.Vol, value);
		MacroGain.setValue(value);
};

Content.getComponent("Vol0").setControlCallback(onVol0Control);


inline function onMacroGainControl(component, value)
{
	

	Vol0.setValueNormalized(value);
	Vol0.changed();
};

Content.getComponent("MacroGain").setControlCallback(onMacroGainControl);


inline function onVol1Control(component, value)
{
	gran1.setAttribute(gran1.Vol, value);
		MacroGain1.setValue(value);
};

Content.getComponent("Vol1").setControlCallback(onVol1Control);


inline function onMacroGain1Control(component, value)
{
	

	Vol1.setValueNormalized(value);
	Vol1.changed();
};

Content.getComponent("MacroGain1").setControlCallback(onMacroGain1Control);


inline function onVol2Control(component, value)
{
	gran2.setAttribute(gran2.Vol, value);
		MacroGain2.setValue(value);
};

Content.getComponent("Vol2").setControlCallback(onVol2Control);


inline function onMacroGain2Control(component, value)
{
	

	Vol2.setValueNormalized(value);
	Vol2.changed();
};

Content.getComponent("MacroGain2").setControlCallback(onMacroGain2Control);


inline function onVol3Control(component, value)
{
		gran3.setAttribute(gran3.Vol, value);
		MacroGain3.setValue(value);
};

Content.getComponent("Vol3").setControlCallback(onVol3Control);


inline function onMacroGain3Control(component, value)
{

	Vol3.setValueNormalized(value);
	Vol3.changed();
};

Content.getComponent("MacroGain3").setControlCallback(onMacroGain3Control);


inline function shouldExcludeMatrixTarget(componentId)
{
	if(componentId == "")
		return true;

	local excludedIds =
	[
		"MacroGain",
		"MacroGain1",
		"MacroGain2",
		"MacroGain3"
	];

	if(excludedIds.contains(componentId))
		return true;

	if(componentId.indexOf("MacroPos") == 0 || componentId.indexOf("MacroPitch") == 0)
	{
		local suffix = componentId.replace("MacroPos", "").replace("MacroPitch", "");
		local index = parseInt(suffix);
		return index >= 1 && index <= 4;
	}

	if(componentId.indexOf("MacroMod") == 0 || componentId.indexOf("Macro") == 0)
	{
		local suffix = componentId.replace("MacroMod", "").replace("Macro", "");
		local index = parseInt(suffix);
		return index >= 1 && index <= 8;
	}

	return false;
}

inline function autoRegisterMatrixTargets()
{
	local all = Content.getAllComponents(".*");
	local registeredTargets = {};

	for (c in all)
	{
		if (c.get("type") != "ScriptSlider")
			continue;

		local componentId = c.getId();

		if (shouldExcludeMatrixTarget(componentId))
			continue;

		local processorId = c.get("processorId");
		local parameterId = c.get("parameterId");

		local targetId = "";

		if (processorId != "" && parameterId != "")
			targetId = processorId + "_" + parameterId;
		else if (componentId != "")
			targetId = componentId;

		if (targetId == "")
			continue;

		c.set("matrixTargetId", targetId);
		registeredTargets[targetId] =
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		};
	}

	return registeredTargets;
}

const var matrixDefaultTargetValues = autoRegisterMatrixTargets();

// Let's create a matrix handler object that can be used to programmatically change
// query the modulation connections.
// Note that as soon as you create this object it will also write the modulation connections into the user preset
// so that they are restored correctly.
const var matrixHandler = Engine.createModulationMatrix("Global Modulator Container1");

inline function hideModulationDragBackground(g, obj)
{
}

inline function hideModulationDragger(g, obj)
{
}

inline function getHiddenModulatorDragData(obj)
{
	return obj;
}

inline function installMatrixHoverSuppressor(lafObject)
{
	if(!isDefined(lafObject))
		return;

	lafObject.registerFunction("drawModulationDragBackground", hideModulationDragBackground);
	lafObject.registerFunction("drawModulationDragger", hideModulationDragger);
	lafObject.registerFunction("getModulatorDragData", getHiddenModulatorDragData);
}

installMatrixHoverSuppressor(KnobLaf);
installMatrixHoverSuppressor(KnobLaf2);
installMatrixHoverSuppressor(KnobLaf3);
installMatrixHoverSuppressor(KnobLaf4);
installMatrixHoverSuppressor(KnobLaf5);

matrixHandler.setMatrixModulationProperties({
	DefaultInitValues: matrixDefaultTargetValues
});

inline function connectMatrixSourceToComponent(sourceId, component)
{
	local targetId = matrixHandler.getTargetId(component);

	if(targetId != "")
		matrixHandler.connect(sourceId, targetId, true);
}
