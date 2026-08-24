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
//gran.setAttribute(gran.Pitch, value);
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
//	gran.setAttribute(gran.Vol, value);
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
//	gran1.setAttribute(gran1.Vol, value);
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
//	gran2.setAttribute(gran2.Vol, value);
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
	//	gran3.setAttribute(gran3.Vol, value);
		MacroGain3.setValue(value);
};

Content.getComponent("Vol3").setControlCallback(onVol3Control);


inline function onMacroGain3Control(component, value)
{

	Vol3.setValueNormalized(value);
	Vol3.changed();
};

Content.getComponent("MacroGain3").setControlCallback(onMacroGain3Control);


inline function shouldExcludeMatrixTarget(component)
{
	local componentId = component.getId();

	if(componentId == "")
		return true;

	if(componentId.indexOf("RandMin") == 0 || componentId.indexOf("RandMax") == 0)
		return true;

	if(componentId.indexOf("SampleMin") == 0 || componentId.indexOf("SampleMax") == 0)
		return true;

	if(componentId.indexOf("ScrubDisplay") == 0)
		return true;

	if(componentId.indexOf("Matrix") != -1)
		return true;

	local processorId = component.get("processorId");

	if(processorId.indexOf("Matrix") != -1)
		return true;

	if(componentId.indexOf("MultPosA") == 0 || componentId.indexOf("MultPosB") == 0 || componentId.indexOf("MultPosC") == 0 || componentId.indexOf("MultPosD") == 0)
		return true;

	local excludedIds =
	[
		"pos",
		"pos1",
		"pos2",
		"pos3",
		"pitch",
		"pitch1",
		"pitch2",
		"pitch3",
		"grainsize1",
		"grainsize2",
		"grainsize3",
		"grainsize4",
		"PolyMeta1",
		"PolyMeta2",
		"PolyMeta3",
		"PolyMeta4",
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

	return false;
}

inline function autoRegisterMatrixTargets()
{
	local all = Content.getAllComponents(".*");
	local registeredTargets = {};
	local manualTargets =
	{
		"Voice_1_Pitch":
		{
			Intensity: 1.0,
			Mode: "Bipolar",
			IsNormalized: false
		},
		"Voice_1_Volume":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_1_PositionA":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_1_PositionB":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_1_PositionC":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_1_PositionD":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_1_GrainMs":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_1_GrainDivide":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_1_GrainTempo":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_1_WindowShape":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_1_Meta1":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_2_Pitch":
		{
			Intensity: 1.0,
			Mode: "Bipolar",
			IsNormalized: false
		},
		"Voice_2_Volume":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_2_PositionA":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_2_PositionB":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_2_PositionC":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_2_PositionD":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_2_GrainMs":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_2_GrainDivide":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_2_GrainTempo":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_2_WindowShape":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_2_Meta":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_3_Pitch":
		{
			Intensity: 1.0,
			Mode: "Bipolar",
			IsNormalized: false
		},
		"Voice_3_Volume":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_3_PositionA":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_3_PositionB":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_3_PositionC":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_3_PositionD":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_3_GrainMs":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_3_GrainDivide":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_3_GrainTempo":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_3_WindowShape":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_3_Meta":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_4_Pitch":
		{
			Intensity: 1.0,
			Mode: "Bipolar",
			IsNormalized: false
		},
		"Voice_4_Volume":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_4_PositionA":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_4_PositionB":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_4_PositionC":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_4_PositionD":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_4_GrainMs":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_4_GrainDivide":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_4_GrainTempo":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: false
		},
		"Voice_4_WindowShape":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		},
		"Voice_4_Meta":
		{
			Intensity: 1.0,
			Mode: "Unipolar",
			IsNormalized: true
		}
	};

	for (c in all)
	{
		if (c.get("type") != "ScriptSlider")
			continue;

		local componentId = c.getId();

		if (shouldExcludeMatrixTarget(c))
			continue;

		local existingTargetId = c.get("matrixTargetId");
		local processorId = c.get("processorId");
		local parameterId = c.get("parameterId");
		local minValue = c.get("min");
		local maxValue = c.get("max");

		local targetId = "";

		if (existingTargetId != "")
			targetId = existingTargetId;
		else if (processorId != "" && parameterId != "")
			targetId = processorId + "_" + parameterId;
		else if (componentId != "")
			targetId = componentId;

		if (targetId == "")
			continue;

		if (existingTargetId == "")
			c.set("matrixTargetId", targetId);

		local isNormalized = (minValue == 0.0 && maxValue == 1.0);
		local mode = minValue < 0.0 ? "Bipolar" : "Unipolar";

		registeredTargets[targetId] =
		{
			Intensity: 1.0,
			Mode: mode,
			IsNormalized: isNormalized
		};
	}

	for(targetId in manualTargets)
		registeredTargets[targetId] = manualTargets[targetId];

	return registeredTargets;
}

const var matrixDefaultTargetValues = autoRegisterMatrixTargets();

inline function autoRegisterMatrixRangeProperties()
{
	local all = Content.getAllComponents(".*");
	local rangeProperties = {};

	for (c in all)
	{
		if (c.get("type") != "ScriptSlider")
			continue;

		if (shouldExcludeMatrixTarget(c))
			continue;

		local targetId = c.get("matrixTargetId");

		if (targetId == "")
			continue;

		local minValue = c.get("min");
		local maxValue = c.get("max");
		local middlePosition = c.get("middlePosition");
		local stepSize = c.get("stepSize");
		local mode = c.get("mode");

		if (middlePosition == 0.0 && minValue < maxValue)
			middlePosition = minValue + ((maxValue - minValue) * 0.5);

		if (mode == "")
		{
			if (minValue == 0.0 && maxValue == 1.0)
				mode = "NormalizedPercentage";
			else
				mode = "Plain";
		}

		rangeProperties[targetId] =
		{
			InputRange:
			{
				min: minValue,
				max: maxValue,
				middlePosition: middlePosition,
				mode: mode,
				stepSize: stepSize
			},
			OutputRange:
			{
				min: minValue,
				max: maxValue,
				middlePosition: middlePosition,
				stepSize: stepSize,
				UseMidPositionAsZero: minValue < 0.0
			}
		};
	}

	return rangeProperties;
}

const var matrixRangeProperties = autoRegisterMatrixRangeProperties();

// Let's create a matrix handler object that can be used to programmatically change
// query the modulation connections.
// Note that as soon as you create this object it will also write the modulation connections into the user preset
// so that they are restored correctly.
const var matrixHandler = Engine.createModulationMatrix("Global Modulator Container1");
const var matrixSourceModulators = {};
const var matrixTargetModulators = {};
const var matrixHoldButton = Content.getComponent("Hold");
const var matrixPresetHandler = Engine.createUserPresetHandler();
const var MatrixRouteTable = Content.getComponent("MatrixRouteTable");
const var matrixEditorRoutes = [];
const var matrixRouteOrder = [];
reg matrixEditorUpdating = false;
reg matrixEditorMutating = false;
// HISE restores the matrix on its sample-loading thread while connection
// callbacks run on the Javascript thread, so keep all matrix reads paused.
reg matrixPresetLoadInProgress = false;

MatrixRouteTable.setTableMode({
	"MultiColumnMode": true,
	"HeaderHeight": 0,
	"RowHeight": 30,
	"ScrollOnDrag": false,
	"CallbackOnSliderDrag": true
});

MatrixRouteTable.setTableColumns([
	{ "ID": "Source", "Type": "ComboBox", "Label": "SOURCE", "Width": 95, "ValueMode": "ID" },
	{ "ID": "Target", "Type": "ComboBox", "Label": "TARGET", "Width": 95, "ValueMode": "ID" },
	{ "ID": "Mode", "Type": "ComboBox", "Label": "MODE", "Width": 65, "ValueMode": "ID" },
	{ "ID": "Invert", "Type": "Button", "Label": "INV", "Width": 35, "Toggle": true },
	{ "ID": "Amount", "Type": "Slider", "Label": "AMT", "Width": 120, "MinValue": -1.0, "MaxValue": 1.0, "StepSize": 0.01 },
	{ "ID": "AuxSource", "Type": "ComboBox", "Label": "AUX", "Width": 95, "ValueMode": "ID" },
	{ "ID": "AuxAmount", "Type": "Slider", "Label": "AUX AMT", "Width": 100, "MinValue": 0.0, "MaxValue": 1.0, "StepSize": 0.01 },
	{ "ID": "Remove", "Type": "Button", "Label": "X", "Width": 35, "Toggle": false, "Text": "X" }
]);

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

const var MatrixHiddenSliderLaf = Content.createLocalLookAndFeel();
const var MatrixRouteTableLaf = Content.createLocalLookAndFeel();
const var MatrixHiddenSliderIds = [
	"MultPosA1", "MultPosB1", "MultPosC1", "MultPosD1",
	"MultPosA2", "MultPosB2", "MultPosC2", "MultPosD2",
	"MultPosA3", "MultPosB3", "MultPosC3", "MultPosD3",
	"MultPosA4", "MultPosB4", "MultPosC4", "MultPosD4",
	"FinVol1", "FinVol2", "FinVol3", "FinVol4", "MasterVol"
];

installMatrixHoverSuppressor(MatrixHiddenSliderLaf);

MatrixRouteTableLaf.registerFunction("drawTableRowBackground", function(g, obj)
{
	g.setColour(0xFF354259);
	g.fillRect(obj.area);
});

MatrixRouteTableLaf.registerFunction("drawTableCell", function(g, obj)
{
	if(obj.hover)
	{
		g.setColour(0x145E6270);
		g.fillRect(obj.area);
	}
});

MatrixRouteTableLaf.registerFunction("drawComboBox", function(g, obj)
{
	var area = Rect.reduced(obj.area, 3.0);
	g.setColour(0xFF5E6270);
	g.fillRoundedRectangle(area, 3.0);
	g.setColour(0xFFEDE6D5);
	g.setFont("Montserrat", 12.0);
	g.drawAlignedText(obj.text, area, "centred");
});

MatrixRouteTableLaf.registerFunction("drawLinearSlider", function(g, obj)
{
	var area = Rect.reduced(obj.area, 3.0);
	var value = obj.valueNormalized;

	g.setColour(0xFF5E6270);
	g.fillRoundedRectangle(area, 3.0);
	g.setColour(0xFFFF8A8A);

	if(obj.min < 0.0)
	{
		var centre = area[0] + area[2] * 0.5;
		var width = Math.abs(value - 0.5) * area[2];
		g.fillRoundedRectangle(value < 0.5 ? [centre - width, area[1] + 4.0, width, area[3] - 8.0] : [centre, area[1] + 4.0, width, area[3] - 8.0], 2.0);
	}
	else
	{
		g.fillRoundedRectangle([area[0] + 3.0, area[1] + 4.0, Math.max(2.0, (area[2] - 6.0) * value), area[3] - 8.0], 2.0);
	}

	// The native table slider has no value popup, so keep the amount readable in-cell.
	g.setColour(0xFFEDE6D5);
	g.setFont("Montserrat", 10.0);
	g.drawAlignedText(obj.valueSuffixString, area, "centred");
});

MatrixRouteTableLaf.registerFunction("drawToggleButton", function(g, obj)
{
	var area = Rect.reduced(obj.area, 3.0);
	g.setColour(obj.value ? 0xFF999999 : 0xFF5E6270);
	g.fillRoundedRectangle(area, 3.0);
	g.setColour(obj.value ? 0xFF354259 : 0xFFC96868);
	g.setFont("Montserrat", 12.0);
	g.drawAlignedText(obj.text, area, "centred");
});

for(sliderId in MatrixHiddenSliderIds)
{
	local slider = Content.getComponent(sliderId);

	if(isDefined(slider))
		slider.setLocalLookAndFeel(MatrixHiddenSliderLaf);
}

inline function buildMatrixSourceModulatorMap()
{
	local sources = matrixHandler.getSourceList();

	for(sourceId in sources)
	{
		local mod = Synth.getModulator(sourceId);

		if(isDefined(mod))
			matrixSourceModulators[sourceId] = mod;
	}
}

inline function buildMatrixTargetModulatorMap()
{
	local all = Content.getAllComponents(".*");

	for(c in all)
	{
		if(c.get("type") != "ScriptSlider")
			continue;

		local targetId = c.get("matrixTargetId");
		local processorId = c.get("processorId");

		if(targetId == "" || processorId == "" || processorId != targetId)
			continue;

		if(isDefined(matrixTargetModulators[targetId]))
			continue;

		local mod = Synth.getModulator(targetId);

		if(isDefined(mod))
			matrixTargetModulators[targetId] = mod;
	}
}

inline function getMatrixSourceRouteCount(sourceId)
{
	local count = 0;
	local targets = matrixHandler.getTargetList();
	local sources = matrixHandler.getSourceList();
	local sourceIndex = sources.indexOf(sourceId);

	for(targetId in targets)
	{
		if(!matrixHandler.canConnect(sourceId, targetId))
			count += 1;
			
		for(primarySourceId in sources)
		{
			local auxSourceId = matrixHandler.getConnectionProperty(primarySourceId, targetId, "Aux");
			
			if(!isDefined(auxSourceId) || auxSourceId == "")
				auxSourceId = matrixHandler.getConnectionProperty(primarySourceId, targetId, "AuxSource");
				
			if(auxSourceId == sourceId)
			{
				count += 1;
				continue;
			}
			
			if(sourceIndex != -1)
			{
				local auxIndex = matrixHandler.getConnectionProperty(primarySourceId, targetId, "AuxIndex");
				
				if(isDefined(auxIndex) && auxIndex == sourceIndex)
					count += 1;
			}
		}
	}

	return count;
}

inline function setMatrixSourceEnabledState(sourceId, shouldEnable)
{
	local mod = matrixSourceModulators[sourceId];

	if(!isDefined(mod))
		return;

	// The script API exposes bypass state directly, so we mirror the desired enabled state here.
	mod.setBypassed(!shouldEnable);
}

inline function refreshMatrixSourceEnabledState(sourceId)
{
	setMatrixSourceEnabledState(sourceId, getMatrixSourceRouteCount(sourceId) > 0);
}

inline function refreshAllMatrixSourceEnabledStates()
{
	local sources = matrixHandler.getSourceList();

	for(sourceId in sources)
		refreshMatrixSourceEnabledState(sourceId);
}

inline function refreshMatrixTargetEnabledState(targetId)
{
	local mod = matrixTargetModulators[targetId];

	if(!isDefined(mod))
		return;

	// Dedicated target modulators are also used as the live base-value path for some controls.
	// Keep them active so disconnecting a route does not leave the UI control pointing at a bypassed modulator.
	mod.setBypassed(false);
}

inline function refreshAllMatrixTargetEnabledStates()
{
	local targets = matrixHandler.getTargetList();

	for(targetId in targets)
		refreshMatrixTargetEnabledState(targetId);
}

inline function syncAllMatrixEnabledStates()
{
	refreshAllMatrixSourceEnabledStates();
	refreshAllMatrixTargetEnabledStates();
}

inline function resetMatrixHold()
{
	if(isDefined(matrixHoldButton))
		matrixHoldButton.setValue(0);
}

inline function refreshMatrixEditorRoutes()
{
	local connectedRoutes = [];

	local sources = matrixHandler.getSourceList();
	local targets = matrixHandler.getTargetList();

	for(targetId in targets)
	{
		for(sourceId in sources)
		{
			if(!matrixHandler.canConnect(sourceId, targetId))
				connectedRoutes.push({ Source: sourceId, Target: targetId });
		}
	}

	// Retain insertion order while reconciling routes restored from presets or changed elsewhere.
	local reconciledOrder = [];

	for(orderedRoute in matrixRouteOrder)
	{
		for(connectedRoute in connectedRoutes)
		{
			if(orderedRoute.Source == connectedRoute.Source && orderedRoute.Target == connectedRoute.Target)
			{
				reconciledOrder.push(connectedRoute);
				break;
			}
		}
	}

	for(connectedRoute in connectedRoutes)
	{
		local found = false;

		for(orderedRoute in reconciledOrder)
		{
			if(orderedRoute.Source == connectedRoute.Source && orderedRoute.Target == connectedRoute.Target)
			{
				found = true;
				break;
			}
		}

		if(!found)
			reconciledOrder.push(connectedRoute);
	}

	matrixRouteOrder.clear();
	matrixEditorRoutes.clear();

	for(orderedRoute in reconciledOrder)
	{
		matrixRouteOrder.push(orderedRoute);
		matrixEditorRoutes.push(orderedRoute);
	}
}

inline function updateMatrixRouteOrder(sourceId, targetId, wasAdded)
{
	if(wasAdded)
	{
		for(route in matrixRouteOrder)
		{
			if(route.Source == sourceId && route.Target == targetId)
				return;
		}

		matrixRouteOrder.push({ Source: sourceId, Target: targetId });
		return;
	}

	for(routeIndex = matrixRouteOrder.length - 1; routeIndex >= 0; routeIndex--)
	{
		local route = matrixRouteOrder[routeIndex];

		if(route.Source == sourceId && route.Target == targetId)
			matrixRouteOrder.removeElement(routeIndex);
	}
}

inline function rebuildMatrixEditor()
{
	if(!isDefined(MatrixRouteTable))
		return;

	refreshMatrixEditorRoutes();

	local sources = matrixHandler.getSourceList();
	local targets = matrixHandler.getTargetList();
	local auxSources = ["None"];

	for(sourceId in sources)
		auxSources.push(sourceId);

	local rows = [];

	matrixEditorUpdating = true;

	for(route in matrixEditorRoutes)
	{
		local intensity = matrixHandler.getConnectionProperty(route.Source, route.Target, "Intensity");
		local mode = matrixHandler.getConnectionProperty(route.Source, route.Target, "Mode");
		local inverted = matrixHandler.getConnectionProperty(route.Source, route.Target, "Inverted");
		local auxIndex = matrixHandler.getConnectionProperty(route.Source, route.Target, "AuxIndex");
		local auxIntensity = matrixHandler.getConnectionProperty(route.Source, route.Target, "AuxIntensity");

		if(!isDefined(intensity)) intensity = 0.0;
		intensity = parseFloat(intensity);
		if(!isDefined(mode)) mode = 0;
		mode = parseInt(mode);
		if(!isDefined(inverted)) inverted = false;
		inverted = parseInt(inverted);
		if(!isDefined(auxIndex)) auxIndex = -1;
		auxIndex = parseInt(auxIndex);
		if(!isDefined(auxIntensity)) auxIntensity = 0.0;
		auxIntensity = parseFloat(auxIntensity);

		rows.push({
			"Source": { "items": sources, "Value": sources.indexOf(route.Source) + 1 },
			"Target": { "items": targets, "Value": targets.indexOf(route.Target) + 1 },
			"Mode": { "items": ["Scale", "Unipolar", "Bipolar"], "Value": mode + 1 },
			"Invert": inverted,
			"Amount": intensity,
			"AuxSource": { "items": auxSources, "Value": auxIndex + 2 },
			"AuxAmount": auxIntensity,
			"Remove": false
		});
	}

	MatrixRouteTable.setTableRowData(rows);
	matrixEditorUpdating = false;
}

inline function finishMatrixEditorMutation()
{
	matrixEditorMutating = false;
	resetMatrixHold();
	syncAllMatrixEnabledStates();
	rebuildMatrixEditor();
}

inline function getMatrixEditorRoute(rowIndex)
{
	if(rowIndex < 0 || rowIndex >= matrixEditorRoutes.length)
		return {};

	return matrixEditorRoutes[rowIndex];
}

inline function replaceMatrixRouteSource(rowIndex, newSourceId)
{
	local route = getMatrixEditorRoute(rowIndex);

	if(!isDefined(route.Source) || route.Source == newSourceId || !matrixHandler.canConnect(newSourceId, route.Target))
	{
		rebuildMatrixEditor();
		return;
	}

	local intensity = matrixHandler.getConnectionProperty(route.Source, route.Target, "Intensity");
	local mode = matrixHandler.getConnectionProperty(route.Source, route.Target, "Mode");
	mode = parseInt(mode);
	local inverted = matrixHandler.getConnectionProperty(route.Source, route.Target, "Inverted");
	local auxIndex = matrixHandler.getConnectionProperty(route.Source, route.Target, "AuxIndex");
	local auxIntensity = matrixHandler.getConnectionProperty(route.Source, route.Target, "AuxIntensity");

	matrixEditorMutating = true;
	matrixHandler.connect(route.Source, route.Target, false);
	matrixHandler.connect(newSourceId, route.Target, true);
	matrixHandler.setConnectionProperty(newSourceId, route.Target, "Intensity", intensity);
	matrixHandler.setConnectionProperty(newSourceId, route.Target, "Mode", mode);
	matrixHandler.setConnectionProperty(newSourceId, route.Target, "Inverted", inverted);
	matrixHandler.setConnectionProperty(newSourceId, route.Target, "AuxIndex", auxIndex);
	matrixHandler.setConnectionProperty(newSourceId, route.Target, "AuxIntensity", auxIntensity);
	finishMatrixEditorMutation();
}

inline function replaceMatrixRouteTarget(rowIndex, newTargetId)
{
	local route = getMatrixEditorRoute(rowIndex);

	if(!isDefined(route.Target) || route.Target == newTargetId || !matrixHandler.canConnect(route.Source, newTargetId))
	{
		rebuildMatrixEditor();
		return;
	}

	local intensity = matrixHandler.getConnectionProperty(route.Source, route.Target, "Intensity");
	local mode = matrixHandler.getConnectionProperty(route.Source, route.Target, "Mode");
	mode = parseInt(mode);
	local inverted = matrixHandler.getConnectionProperty(route.Source, route.Target, "Inverted");
	local auxIndex = matrixHandler.getConnectionProperty(route.Source, route.Target, "AuxIndex");
	local auxIntensity = matrixHandler.getConnectionProperty(route.Source, route.Target, "AuxIntensity");

	matrixEditorMutating = true;
	matrixHandler.connect(route.Source, route.Target, false);
	matrixHandler.connect(route.Source, newTargetId, true);
	matrixHandler.setConnectionProperty(route.Source, newTargetId, "Intensity", intensity);
	matrixHandler.setConnectionProperty(route.Source, newTargetId, "Mode", mode);
	matrixHandler.setConnectionProperty(route.Source, newTargetId, "Inverted", inverted);
	matrixHandler.setConnectionProperty(route.Source, newTargetId, "AuxIndex", auxIndex);
	matrixHandler.setConnectionProperty(route.Source, newTargetId, "AuxIntensity", auxIntensity);
	finishMatrixEditorMutation();
}

inline function setMatrixRouteProperty(rowIndex, propertyId, value)
{
	local route = getMatrixEditorRoute(rowIndex);

	if(!isDefined(route.Source))
		return;

	matrixHandler.setConnectionProperty(route.Source, route.Target, propertyId, value);

	// Repainting the complete row on every drag callback writes values back into the
	// rotary controls and makes their movement look unstable.
	if(propertyId == "AuxIndex")
	{
		syncAllMatrixEnabledStates();
		rebuildMatrixEditor();
	}
	else if(propertyId == "Mode")
	{
		rebuildMatrixEditor();
	}
}

inline function onMatrixRouteTable(event)
{
	if(matrixEditorUpdating || event.rowIndex < 0)
		return;

	local rowIndex = event.rowIndex;
	local columnId = event.columnID;
	local value = event.value;

	if(columnId == "Source")
	{
		local sources = matrixHandler.getSourceList();
		local sourceIndex = parseInt(value) - 1;

		if(sourceIndex >= 0 && sourceIndex < sources.length)
			replaceMatrixRouteSource(rowIndex, sources[sourceIndex]);
	}
	else if(columnId == "Target")
	{
		local targets = matrixHandler.getTargetList();
		local targetIndex = parseInt(value) - 1;

		if(targetIndex >= 0 && targetIndex < targets.length)
			replaceMatrixRouteTarget(rowIndex, targets[targetIndex]);
	}
	else if(columnId == "Mode")
	{
		setMatrixRouteProperty(rowIndex, "Mode", parseInt(value) - 1);
	}
	else if(columnId == "Invert")
	{
		setMatrixRouteProperty(rowIndex, "Inverted", parseInt(value));
	}
	else if(columnId == "Amount")
	{
		setMatrixRouteProperty(rowIndex, "Intensity", parseFloat(value));
	}
	else if(columnId == "AuxSource")
	{
		setMatrixRouteProperty(rowIndex, "AuxIndex", parseInt(value) - 2);
	}
	else if(columnId == "AuxAmount")
	{
		setMatrixRouteProperty(rowIndex, "AuxIntensity", parseFloat(value));
	}
	else if(columnId == "Remove" && event.Type == "Button")
	{
		local route = getMatrixEditorRoute(rowIndex);

		if(isDefined(route.Source))
		{
			matrixEditorMutating = true;
			matrixHandler.connect(route.Source, route.Target, false);
			finishMatrixEditorMutation();
		}
	}
}

matrixHandler.setMatrixModulationProperties({
	DefaultInitValues: matrixDefaultTargetValues,
	RangeProperties: matrixRangeProperties
});

buildMatrixSourceModulatorMap();
buildMatrixTargetModulatorMap();

matrixHandler.setConnectionCallback(function(source, target, wasAdded)
{
	if(matrixEditorMutating || matrixPresetLoadInProgress)
		return;

	updateMatrixRouteOrder(source, target, wasAdded);
	resetMatrixHold();
	syncAllMatrixEnabledStates();
	rebuildMatrixEditor();
});

refreshAllMatrixSourceEnabledStates();
refreshAllMatrixTargetEnabledStates();

MatrixRouteTable.setTableCallback(onMatrixRouteTable);
MatrixRouteTable.setLocalLookAndFeel(MatrixRouteTableLaf);

matrixPresetHandler.setPreCallback(function(presetFile)
{
	matrixPresetLoadInProgress = true;
});

matrixPresetHandler.setPostCallback(function(presetFile)
{
	matrixPresetLoadInProgress = false;
	syncAllMatrixEnabledStates();
	rebuildMatrixEditor();
});

rebuildMatrixEditor();

inline function connectMatrixSourceToComponent(sourceId, component)
{
	local targetId = matrixHandler.getTargetId(component);

	if(targetId != "")
		matrixHandler.connect(sourceId, targetId, true);
}
