const var KnobLaf3 = Content.createLocalLookAndFeel();

inline function drawKnobModulationArc(g, obj, area, thickness)
{
	if(!obj.modulationActive)
		return;

	local n = Rectangle(0.0, 0.0, 1.0, 1.0);
	local actualValue = Math.range(obj.scaledValue + obj.addValue, 0.0, 1.0);
	local modRange = Content.createPath();
	modRange.setBounds(n);
	modRange.addArc(n, -2.66 + obj.modMinValue * 5.32, -2.66 + obj.modMaxValue * 5.32);

	g.setColour(0x55777575);
	g.drawPath(modRange, area, thickness);

	local valueArc = Content.createPath();
	valueArc.setBounds(n);
	valueArc.addArc(n, -2.66 + obj.valueNormalized * 5.32, -2.66 + actualValue * 5.32);

	g.setColour(0xFFBD4444);
	g.drawPath(valueArc, area, Math.max(2.0, thickness - 0.5));
}



KnobLaf3.registerFunction("drawRotarySlider", function(g, obj)
{
	var underDrag = Content.getComponentUnderDrag() == obj.id;
	

	var textArea = Rect.removeFromBottom(obj.area, obj.area[3] - obj.area[2]);


	var isBipolar = obj.min < 0 && obj.id != "Knob1";
	var start = isBipolar ? 0 : -2.7;
	var modStart = isBipolar ? (-2.7 + obj.valueNormalized * 2 * 2.7) : -2.7;

	g.setColour(0x00000000);

	var radius = 20 - obj.clicked;

	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 2));
	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 3));
	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 4));
	
	

	var p = Content.createPath();
	
//	p.startNewSubPath(0, 0);
//	p.startNewSubPath(1,1);
//	p.addArc([0.0, 0.0, 1.0, 1.0], -2.7, 2.7);
	
	g.setColour( obj.itemColour1);
	g.drawPath(p, Rect.reduced(obj.area, 5), 4);
	g.setColour(underDrag ? 0xFF303030 : 0xFF303030);
	g.drawPath(p, Rect.reduced(obj.area, 1), 2);

	p = Content.createPath();
		
	p.startNewSubPath(0, 0);
	p.startNewSubPath(1,1);
//	p.addArc([0.0, 0.0, 1.0, 1.0], start, -2.66 + Math.max(0.01, obj.valueNormalized) * 2 * 2.66);
	
	g.setColour(Colours.withAlpha(obj.itemColour1, obj.clicked ? 1.0 : 0.8));
	g.drawPath(p, Rect.reduced(obj.area, 5), 4);
	
	p = Content.createPath();
			
	p.startNewSubPath(0, 0);
	p.startNewSubPath(1,1);
//	var modValue = matrix.getModValue(obj.id);
	
	
//	p.addArc([0.0, 0.0, 1.0, 1.0], modStart, -2.66 + Math.max(0.01, modValue) * 2 * 2.66);
	
	g.setColour(Colours.withAlpha(obj.itemColour1, obj.clicked ? 0.8 : 0.5));
	g.drawPath(p, Rect.reduced(obj.area, 1), 2);

//	g.addDropShadowFromAlpha(0x44000000, 2);
	
	g.setGradientFill([obj.bgColour, 0.0, 0.0,
					   obj.bgColour, 0.0, obj.area[3], false]);
	g.fillEllipse(Rect.withSizeKeepingCentre(obj.area, radius, radius));
	
	g.setGradientFill([obj.itemColour2, 0.0, 0.0,
					   obj.itemColour2, 0.0, obj.area[3], true]);
	g.drawEllipse(Rect.withSizeKeepingCentre(obj.area, radius-3, radius-3), 3.5);
	drawKnobModulationArc(g, obj, Rect.withSizeKeepingCentre(obj.area, radius-3, radius-3), 4.5);
	
	if(underDrag)
	{
		g.setColour(0xFF515151);

		
		g.fillEllipse(Rect.reduced(obj.area, 6));
	}
	
	g.setColour(Colours.black);
	g.rotate(-2.66 + obj.valueNormalized * 2.66 * 2, Rect.getCentre(obj.area));
	g.fillRect(Rect.translated(Rect.withSizeKeepingCentre(obj.area, 2, 11), 0, -8));
	
	
	
	//g.drawAlignedText(obj.text, obj.area, "centred");
});
