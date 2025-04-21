const var KnobLaf2 = Content.createLocalLookAndFeel();



KnobLaf2.registerFunction("drawRotarySlider", function(g, obj)
{
	var underDrag = Content.getComponentUnderDrag() == obj.id;
	

	var textArea = Rect.removeFromBottom(obj.area, obj.area[3] - obj.area[2]);


	var isBipolar = obj.min < 0 && obj.id != "Knob1";
	var start = isBipolar ? 0 : -2.7;
	var modStart = isBipolar ? (-2.7 + obj.valueNormalized * 2 * 2.7) : -2.7;

	g.setColour(0x00000000);

	var radius = 30 - obj.clicked;

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




Content.getComponent("WinFadeTempo1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Winfade1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("InputGain1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Ratio1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("res1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("mix1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("feed1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("delmix1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("delcut1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("delsmth1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("deldiv1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Vol").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("pan").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("attack").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("decay").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("sustain").setLocalLookAndFeel(KnobLaf2);


Content.getComponent("tempo1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage1").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("tempo2").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div2").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage2").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("tempo3").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div3").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage3").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("tempo4").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div4").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage4").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("tempo5").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div5").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage5").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("tempo6").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div6").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage6").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("tempo7").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div7").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage7").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("tempo8").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div8").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage8").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("tempo9").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div9").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage9").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("tempo10").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div10").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage10").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("tempo11").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div11").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage11").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("tempo12").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Div12").setLocalLookAndFeel(KnobLaf2);
Content.getComponent("Stage12").setLocalLookAndFeel(KnobLaf2);

