const var PosIndicator1 = Content.getComponent("PosIndicator1");
const var PosIndicator5 = Content.getComponent("PosIndicator5");
const var PosIndicator9 = Content.getComponent("PosIndicator9");
const var PosIndicator13 = Content.getComponent("PosIndicator13");
const var PosIndicator17 = Content.getComponent("PosIndicator17");
const var PosIndicator21 = Content.getComponent("PosIndicator21");
const var PosIndicator25 = Content.getComponent("PosIndicator25");
const var PosIndicator29 = Content.getComponent("PosIndicator29");

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

inline function getModulatorIndicatorValue(modulator, fallbackComponent)
{
	if (isDefined(modulator))
		return clampIndicatorValue(modulator.getCurrentLevel());

	return clampIndicatorValue(fallbackComponent.getValue());
}

inline function drawScrubHeads(g, area, isMulti, a, b, c, d)
{
	var centreY = area[1] + area[3] * 0.5;
	var top = area[1] + 2;
	var bottom = area[1] + area[3] - 2;
	var radius = 7.0;
	var values = [a, b, c, d];
	var colours = [0xFBFF9B9B, 0xFFFFD6A5, 0xFFFFFEC4, 0xFFCBFFA9];
	var widths = [2.0, 1.25, 1.25, 1.25];
	var headCount = isMulti ? 4 : 1;

	for (i = 0; i < headCount; i++)
	{
		var x = area[0] + clampIndicatorValue(values[i]) * area[2];
		g.setColour(colours[i]);
		g.drawLine(x, x, top, bottom, widths[i]);
		g.fillEllipse([x - radius, centreY - radius, radius * 2.0, radius * 2.0]);
		g.setColour(0xFF1F252C);
		g.setFont("Montserrat", 11.0);
		g.drawAlignedText((i + 1) + "", [x - radius, centreY - radius - 1, radius * 2.0, radius * 2.0], "centred");
	}
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

PosIndicator1.setPaintRoutine(function(g)
{
	var area = this.getLocalBounds(0);
	var isMulti = StgSel1.getValue() == 2 || StgSel1.getValue() == 4;

	drawScrubHeads(g,
				   area,
				   isMulti,
				   getModulatorIndicatorValue(Voice_1_PositionA, MultPosA1),
				   getModulatorIndicatorValue(Voice_1_PositionB, MultPosB1),
				   getModulatorIndicatorValue(Voice_1_PositionC, MultPosC1),
				   getModulatorIndicatorValue(Voice_1_PositionD, MultPosD1));
});

PosIndicator1.setTimerCallback(function()
{
	this.repaint();
});

PosIndicator1.startTimer(66);

PosIndicator5.setPaintRoutine(function(g)
{
	var area = this.getLocalBounds(0);
	var isMulti = StgSel2.getValue() == 2 || StgSel2.getValue() == 4;

	drawScrubHeads(g,
				   area,
				   isMulti,
				   getModulatorIndicatorValue(Voice_2_PositionA, MultPosA2),
				   getModulatorIndicatorValue(Voice_2_PositionB, MultPosB2),
				   getModulatorIndicatorValue(Voice_2_PositionC, MultPosC2),
				   getModulatorIndicatorValue(Voice_2_PositionD, MultPosD2));
});

PosIndicator5.setTimerCallback(function()
{
	this.repaint();
});

PosIndicator5.startTimer(33);

PosIndicator9.setPaintRoutine(function(g)
{
	var area = this.getLocalBounds(0);
	var isMulti = StgSel3.getValue() == 2 || StgSel3.getValue() == 4;

	drawScrubHeads(g,
				   area,
				   isMulti,
				   getModulatorIndicatorValue(Voice_3_PositionA, MultPosA3),
				   getModulatorIndicatorValue(Voice_3_PositionB, MultPosB3),
				   getModulatorIndicatorValue(Voice_3_PositionC, MultPosC3),
				   getModulatorIndicatorValue(Voice_3_PositionD, MultPosD3));
});

PosIndicator9.setTimerCallback(function()
{
	this.repaint();
});

PosIndicator9.startTimer(33);

PosIndicator13.setPaintRoutine(function(g)
{
	var area = this.getLocalBounds(0);
	var isMulti = StgSel4.getValue() == 2 || StgSel4.getValue() == 4;

	drawScrubHeads(g,
				   area,
				   isMulti,
				   getModulatorIndicatorValue(Voice_4_PositionA, MultPosA4),
				   getModulatorIndicatorValue(Voice_4_PositionB, MultPosB4),
				   getModulatorIndicatorValue(Voice_4_PositionC, MultPosC4),
				   getModulatorIndicatorValue(Voice_4_PositionD, MultPosD4));
});

PosIndicator13.setTimerCallback(function()
{
	this.repaint();
});

PosIndicator13.startTimer(33);

PosIndicator17.setPaintRoutine(function(g)
{
	var area = this.getLocalBounds(0);
	var isMulti = StgSel1.getValue() == 2 || StgSel1.getValue() == 4;

	drawOverviewScrubHeads(g,
						   area,
						   isMulti,
						   getModulatorIndicatorValue(Voice_1_PositionA, MultPosA1),
						   getModulatorIndicatorValue(Voice_1_PositionB, MultPosB1),
						   getModulatorIndicatorValue(Voice_1_PositionC, MultPosC1),
						   getModulatorIndicatorValue(Voice_1_PositionD, MultPosD1));
});

PosIndicator17.setTimerCallback(function()
{
	this.repaint();
});

PosIndicator17.startTimer(33);

PosIndicator21.setPaintRoutine(function(g)
{
	var area = this.getLocalBounds(0);
	var isMulti = StgSel2.getValue() == 2 || StgSel2.getValue() == 4;

	drawOverviewScrubHeads(g,
						   area,
						   isMulti,
						   getModulatorIndicatorValue(Voice_2_PositionA, MultPosA2),
						   getModulatorIndicatorValue(Voice_2_PositionB, MultPosB2),
						   getModulatorIndicatorValue(Voice_2_PositionC, MultPosC2),
						   getModulatorIndicatorValue(Voice_2_PositionD, MultPosD2));
});

PosIndicator21.setTimerCallback(function()
{
	this.repaint();
});

PosIndicator21.startTimer(33);

PosIndicator25.setPaintRoutine(function(g)
{
	var area = this.getLocalBounds(0);
	var isMulti = StgSel3.getValue() == 2 || StgSel3.getValue() == 4;

	drawOverviewScrubHeads(g,
						   area,
						   isMulti,
						   getModulatorIndicatorValue(Voice_3_PositionA, MultPosA3),
						   getModulatorIndicatorValue(Voice_3_PositionB, MultPosB3),
						   getModulatorIndicatorValue(Voice_3_PositionC, MultPosC3),
						   getModulatorIndicatorValue(Voice_3_PositionD, MultPosD3));
});

PosIndicator25.setTimerCallback(function()
{
	this.repaint();
});

PosIndicator25.startTimer(33);

PosIndicator29.setPaintRoutine(function(g)
{
	var area = this.getLocalBounds(0);
	var isMulti = StgSel4.getValue() == 2 || StgSel4.getValue() == 4;

	drawOverviewScrubHeads(g,
						   area,
						   isMulti,
						   getModulatorIndicatorValue(Voice_4_PositionA, MultPosA4),
						   getModulatorIndicatorValue(Voice_4_PositionB, MultPosB4),
						   getModulatorIndicatorValue(Voice_4_PositionC, MultPosC4),
						   getModulatorIndicatorValue(Voice_4_PositionD, MultPosD4));
});

PosIndicator29.setTimerCallback(function()
{
	this.repaint();
});

PosIndicator29.startTimer(33);
