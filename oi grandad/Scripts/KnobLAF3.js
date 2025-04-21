const var KnobLaf3 = Content.createLocalLookAndFeel();



KnobLaf3.registerFunction("drawRotarySlider", function(g, obj)
{
	var underDrag = Content.getComponentUnderDrag() == obj.id;
	

	var textArea = Rect.removeFromBottom(obj.area, obj.area[3] - obj.area[2]);


	var isBipolar = obj.min < 0 && obj.id != "Knob1";
	var start = isBipolar ? 0 : -2.7;
	var modStart = isBipolar ? (-2.7 + obj.valueNormalized * 2 * 2.7) : -2.7;

	g.setColour(obj.textColour);

	var radius = 25 - obj.clicked;

	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 2));
	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 3));
	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 4));
	
	

	var p = Content.createPath();
	
//	p.startNewSubPath(0, 0);
//	p.startNewSubPath(1,1);
//	p.addArc([0.0, 0.0, 1.0, 1.0], -2.7, 2.7);
	
	g.setColour( obj.itemColour1);
	g.drawPath(p, Rect.reduced(obj.area, 5), 4);
	g.setColour(underDrag ? obj.itemColour2 : obj.textColour);
	g.drawPath(p, Rect.reduced(obj.area, 1), 2);

	p = Content.createPath();
		
//	p.startNewSubPath(0, 0);
//	p.startNewSubPath(1,1);
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
	
	if(underDrag)
	{
		g.setColour(obj.itemColour2);

		
		g.fillEllipse(Rect.reduced(obj.area, 6));
	}
	
	g.setColour(obj.textColour);
	g.rotate(-2.66 + obj.valueNormalized * 2.66 * 2, Rect.getCentre(obj.area));
	g.fillRect(Rect.translated(Rect.withSizeKeepingCentre(obj.area, 2, 11), 0, -8));
	
	
	
	//g.drawAlignedText(obj.text, obj.area, "centred");
});




Content.getComponent("posmod").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("pmod1").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("GrainMod1").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("winmod1").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("densemod").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("InputGainMod1").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("RatioMod1").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("cutmod1").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("delmod1").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("delcutmod1").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("volmod").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("PanMod1").setLocalLookAndFeel(KnobLaf3);

Content.getComponent("TempoMod1").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("TempoMod2").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("TempoMod3").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("TempoMod4").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("TempoMod5").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("TempoMod6").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("TempoMod7").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("TempoMod8").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("TempoMod9").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("TempoMod10").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("TempoMod11").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("TempoMod12").setLocalLookAndFeel(KnobLaf3);


Content.getComponent("MorphMod1").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("MorphMod2").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("MorphMod3").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("MorphMod4").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("MorphMod5").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("MorphMod6").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("MorphMod7").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("MorphMod8").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("MorphMod9").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("MorphMod10").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("MorphMod11").setLocalLookAndFeel(KnobLaf3);
Content.getComponent("MorphMod12").setLocalLookAndFeel(KnobLaf3);

