const var PosIndicator17 = Content.getComponent("PosIndicator17");
const var PosIndicator21 = Content.getComponent("PosIndicator21");
const var PosIndicator25 = Content.getComponent("PosIndicator25");
const var PosIndicator29 = Content.getComponent("PosIndicator29");

const var PosIndicatorLaneA1 = Content.getComponent("PosIndicatorLaneA1");
const var PosIndicatorLaneB1 = Content.getComponent("PosIndicatorLaneB1");
const var PosIndicatorLaneC1 = Content.getComponent("PosIndicatorLaneC1");
const var PosIndicatorLaneD1 = Content.getComponent("PosIndicatorLaneD1");
const var PosIndicatorLaneA2 = Content.getComponent("PosIndicatorLaneA2");
const var PosIndicatorLaneB2 = Content.getComponent("PosIndicatorLaneB2");
const var PosIndicatorLaneC2 = Content.getComponent("PosIndicatorLaneC2");
const var PosIndicatorLaneD2 = Content.getComponent("PosIndicatorLaneD2");
const var PosIndicatorLaneA3 = Content.getComponent("PosIndicatorLaneA3");
const var PosIndicatorLaneB3 = Content.getComponent("PosIndicatorLaneB3");
const var PosIndicatorLaneC3 = Content.getComponent("PosIndicatorLaneC3");
const var PosIndicatorLaneD3 = Content.getComponent("PosIndicatorLaneD3");
const var PosIndicatorLaneA4 = Content.getComponent("PosIndicatorLaneA4");
const var PosIndicatorLaneB4 = Content.getComponent("PosIndicatorLaneB4");
const var PosIndicatorLaneC4 = Content.getComponent("PosIndicatorLaneC4");
const var PosIndicatorLaneD4 = Content.getComponent("PosIndicatorLaneD4");

const var MultPosA1 = Content.getComponent("MultPosA1");
const var MultPosB1 = Content.getComponent("MultPosB1");
const var MultPosC1 = Content.getComponent("MultPosC1");
const var MultPosD1 = Content.getComponent("MultPosD1");
const var MultPosA2 = Content.getComponent("MultPosA2");
const var MultPosB2 = Content.getComponent("MultPosB2");
const var MultPosC2 = Content.getComponent("MultPosC2");
const var MultPosD2 = Content.getComponent("MultPosD2");
const var MultPosA3 = Content.getComponent("MultPosA3");
const var MultPosB3 = Content.getComponent("MultPosB3");
const var MultPosC3 = Content.getComponent("MultPosC3");
const var MultPosD3 = Content.getComponent("MultPosD3");
const var MultPosA4 = Content.getComponent("MultPosA4");
const var MultPosB4 = Content.getComponent("MultPosB4");
const var MultPosC4 = Content.getComponent("MultPosC4");
const var MultPosD4 = Content.getComponent("MultPosD4");

const var StgSel1 = Content.getComponent("StgSel1");
const var StgSel2 = Content.getComponent("StgSel2");
const var StgSel3 = Content.getComponent("StgSel3");
const var StgSel4 = Content.getComponent("StgSel4");

const var Voice_1_PositionA = Synth.getModulator("Voice_1_PositionA");
const var Voice_1_PositionB = Synth.getModulator("Voice_1_PositionB");
const var Voice_1_PositionC = Synth.getModulator("Voice_1_PositionC");
const var Voice_1_PositionD = Synth.getModulator("Voice_1_PositionD");
const var Voice_2_PositionA = Synth.getModulator("Voice_2_PositionA");
const var Voice_2_PositionB = Synth.getModulator("Voice_2_PositionB");
const var Voice_2_PositionC = Synth.getModulator("Voice_2_PositionC");
const var Voice_2_PositionD = Synth.getModulator("Voice_2_PositionD");
const var Voice_3_PositionA = Synth.getModulator("Voice_3_PositionA");
const var Voice_3_PositionB = Synth.getModulator("Voice_3_PositionB");
const var Voice_3_PositionC = Synth.getModulator("Voice_3_PositionC");
const var Voice_3_PositionD = Synth.getModulator("Voice_3_PositionD");
const var Voice_4_PositionA = Synth.getModulator("Voice_4_PositionA");
const var Voice_4_PositionB = Synth.getModulator("Voice_4_PositionB");
const var Voice_4_PositionC = Synth.getModulator("Voice_4_PositionC");
const var Voice_4_PositionD = Synth.getModulator("Voice_4_PositionD");

inline function clampIndicatorValue(value)
{
	return Math.range(value, 0.0, 1.0);
}

inline function isMultiMode(selector)
{
	var value = selector.getValue();
	return value == 2 || value == 4;
}

inline function getModulatorIndicatorValue(modulator, fallbackComponent)
{
	if (isDefined(modulator))
		return clampIndicatorValue(modulator.getCurrentLevel());

	return clampIndicatorValue(fallbackComponent.getValue());
}

inline function drawOverviewScrubHeads(g, area, isMulti, a, b, c, d)
{
	var top = area[1] + 2;
	var bottom = area[1] + area[3] - 2;
	var values = [a, b, c, d];
	var colours = [0xFBFF9B9B, 0xFFFFD6A5, 0xFFFFFEC4, 0xFFCBFFA9];
	var headCount = isMulti ? 4 : 1;

	for (i = 0; i < headCount; i++)
	{
		var x = area[0] + clampIndicatorValue(values[i]) * area[2];
		g.setColour(colours[i]);
		g.drawLine(x, x, top, bottom, 2.0);
	}
}

inline function setVoiceIndicatorLaneVisibility(isMulti, laneB, laneC, laneD)
{
	laneB.showControl(isMulti);
	laneC.showControl(isMulti);
	laneD.showControl(isMulti);
}

inline function updateVoiceIndicatorTables()
{
	setVoiceIndicatorLaneVisibility(isMultiMode(StgSel1), PosIndicatorLaneB1, PosIndicatorLaneC1, PosIndicatorLaneD1);
	setVoiceIndicatorLaneVisibility(isMultiMode(StgSel2), PosIndicatorLaneB2, PosIndicatorLaneC2, PosIndicatorLaneD2);
	setVoiceIndicatorLaneVisibility(isMultiMode(StgSel3), PosIndicatorLaneB3, PosIndicatorLaneC3, PosIndicatorLaneD3);
	setVoiceIndicatorLaneVisibility(isMultiMode(StgSel4), PosIndicatorLaneB4, PosIndicatorLaneC4, PosIndicatorLaneD4);
}

inline function refreshPositionIndicators()
{
	updateVoiceIndicatorTables();
	PosIndicator17.repaint();
	PosIndicator21.repaint();
	PosIndicator25.repaint();
	PosIndicator29.repaint();
}

PosIndicator17.setPaintRoutine(function(g)
{
	drawOverviewScrubHeads(g,
						   this.getLocalBounds(0),
						   isMultiMode(StgSel1),
						   getModulatorIndicatorValue(Voice_1_PositionA, MultPosA1),
						   getModulatorIndicatorValue(Voice_1_PositionB, MultPosB1),
						   getModulatorIndicatorValue(Voice_1_PositionC, MultPosC1),
						   getModulatorIndicatorValue(Voice_1_PositionD, MultPosD1));
});

PosIndicator21.setPaintRoutine(function(g)
{
	drawOverviewScrubHeads(g,
						   this.getLocalBounds(0),
						   isMultiMode(StgSel2),
						   getModulatorIndicatorValue(Voice_2_PositionA, MultPosA2),
						   getModulatorIndicatorValue(Voice_2_PositionB, MultPosB2),
						   getModulatorIndicatorValue(Voice_2_PositionC, MultPosC2),
						   getModulatorIndicatorValue(Voice_2_PositionD, MultPosD2));
});

PosIndicator25.setPaintRoutine(function(g)
{
	drawOverviewScrubHeads(g,
						   this.getLocalBounds(0),
						   isMultiMode(StgSel3),
						   getModulatorIndicatorValue(Voice_3_PositionA, MultPosA3),
						   getModulatorIndicatorValue(Voice_3_PositionB, MultPosB3),
						   getModulatorIndicatorValue(Voice_3_PositionC, MultPosC3),
						   getModulatorIndicatorValue(Voice_3_PositionD, MultPosD3));
});

PosIndicator29.setPaintRoutine(function(g)
{
	drawOverviewScrubHeads(g,
						   this.getLocalBounds(0),
						   isMultiMode(StgSel4),
						   getModulatorIndicatorValue(Voice_4_PositionA, MultPosA4),
						   getModulatorIndicatorValue(Voice_4_PositionB, MultPosB4),
						   getModulatorIndicatorValue(Voice_4_PositionC, MultPosC4),
						   getModulatorIndicatorValue(Voice_4_PositionD, MultPosD4));
});

PosIndicator17.setTimerCallback(function()
{
	refreshPositionIndicators();
});

refreshPositionIndicators();
PosIndicator17.startTimer(33);
