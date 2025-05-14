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
	g.fillRect(Rect.translated(Rect.withSizeKeepingCentre(obj.area, 5, 11), 0, -8));
	
	
	
	//g.drawAlignedText(obj.text, obj.area, "centred");
});

const var MacroMods = [Content.getComponent("MacroMod1"),
                       Content.getComponent("MacroMod2"),
                       Content.getComponent("MacroMod3"),
                       Content.getComponent("MacroMod4"),
                       Content.getComponent("MacroMod6"),
                       Content.getComponent("MacroMod5"),
                       Content.getComponent("MacroMod7"),
                       Content.getComponent("MacroMod8")];

for(s in MacroMods)
      s.setLocalLookAndFeel(KnobLaf3);



const var VoiceMods1 = [Content.getComponent("posmod"),
                        Content.getComponent("GrainMod1"),
                        Content.getComponent("densemod"),
                        Content.getComponent("pmod1"),
                        Content.getComponent("detmod"),
                        Content.getComponent("spreadmod"),
                        Content.getComponent("winmod1"),
                        Content.getComponent("cutmod1"),
                        Content.getComponent("delmod1"),
                        Content.getComponent("delcutmod1"),
                        Content.getComponent("PanMod1"),
                        Content.getComponent("volmod")];

for(s in VoiceMods1)
      s.setLocalLookAndFeel(KnobLaf3);

const var VoiceMods2 = [Content.getComponent("posmod1"),
                        Content.getComponent("GrainMod2"),
                        Content.getComponent("densemod1"),
                        Content.getComponent("detmod1"),
                        Content.getComponent("spreadmod1"),
                        Content.getComponent("winmod2"),
                        Content.getComponent("pmod2"),
                        Content.getComponent("delcutmod2"),
                        Content.getComponent("delmod2"),
                        Content.getComponent("cutmod2"),
                        Content.getComponent("PanMod2"),
                        Content.getComponent("volmod1")];


for(s in VoiceMods2)
      s.setLocalLookAndFeel(KnobLaf3);

const var VoiceMods3 = [Content.getComponent("posmod2"),
                        Content.getComponent("GrainMod3"),
                        Content.getComponent("densemod2"),
                        Content.getComponent("pmod3"),
                        Content.getComponent("detmod2"),
                        Content.getComponent("spreadmod2"),
                        Content.getComponent("winmod3"),
                        Content.getComponent("cutmod3"),
                        Content.getComponent("delmod3"),
                        Content.getComponent("delcutmod3"),
                        Content.getComponent("volmod2"),
                        Content.getComponent("PanMod3")];

for(s in VoiceMods3)
      s.setLocalLookAndFeel(KnobLaf3);
      
const var VoiceMods4 = [Content.getComponent("cutmod4"),
                        Content.getComponent("delmod4"),
                        Content.getComponent("delcutmod4"),
                        Content.getComponent("PanMod4"),
                        Content.getComponent("volmod3"),
                        Content.getComponent("MorphMod12"),
                        Content.getComponent("TempoMod12"),
                        Content.getComponent("spreadmod3"),
                        Content.getComponent("detmod3"),
                        Content.getComponent("winmod4"),
                        Content.getComponent("pmod4"),
                        Content.getComponent("densemod3"),
                        Content.getComponent("GrainMod4"),
                        Content.getComponent("posmod3")];

 for(s in VoiceMods4)
       s.setLocalLookAndFeel(KnobLaf3);     

      
      
const var TempoMod =[];

for (i = 0; i < 12; i++)
{
    TempoMod[i] = Content.getComponent("TempoMod"+(i+1)).setLocalLookAndFeel(KnobLaf3);

} 

const var MorphMod =[];

for (i = 0; i < 12; i++)
{
    MorphMod[i] = Content.getComponent("MorphMod"+(i+1)).setLocalLookAndFeel(KnobLaf3);

} 


