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


const var res =[];

for (i = 0; i < 4; i++)
{
    res[i] = Content.getComponent("res"+(i+1)).setLocalLookAndFeel(KnobLaf2);

} 

const var mix =[];

for (i = 0; i < 4; i++)
{
    mix[i] = Content.getComponent("mix"+(i+1)).setLocalLookAndFeel(KnobLaf2);

} 

const var feed =[];

for (i = 0; i < 4; i++)
{
    feed[i] = Content.getComponent("feed"+(i+1)).setLocalLookAndFeel(KnobLaf2);

} 

const var delmix =[];

for (i = 0; i < 4; i++)
{
    delmix[i] = Content.getComponent("delmix"+(i+1)).setLocalLookAndFeel(KnobLaf2);

} 

const var delsmth =[];

for (i = 0; i < 4; i++)
{
    delsmth[i] = Content.getComponent("delsmth"+(i+1)).setLocalLookAndFeel(KnobLaf2);

} 

const var delcut =[];

for (i = 0; i < 4; i++)
{
    delcut[i] = Content.getComponent("delcut"+(i+1)).setLocalLookAndFeel(KnobLaf2);

} 

const var Vol =[];

for (i = 0; i < 4; i++)
{
    Vol[i] = Content.getComponent("Vol"+(i)).setLocalLookAndFeel(KnobLaf2);

} 


const var pan =[];

for (i = 0; i < 4; i++)
{
    pan[i] = Content.getComponent("pan"+(i)).setLocalLookAndFeel(KnobLaf2);

} 

const var attack =[];

for (i = 0; i < 4; i++)
{
    attack[i] = Content.getComponent("attack"+(i)).setLocalLookAndFeel(KnobLaf2);

} 


const var decay =[];

for (i = 0; i < 4; i++)
{
    decay[i] = Content.getComponent("decay"+(i)).setLocalLookAndFeel(KnobLaf2);

} 

const var sustain =[];

for (i = 0; i < 4; i++)
{
    sustain[i] = Content.getComponent("sustain"+(i)).setLocalLookAndFeel(KnobLaf2);

} 

const var tempo =[];

for (i = 0; i < 12; i++)
{
    tempo[i] = Content.getComponent("tempo"+(i+1)).setLocalLookAndFeel(KnobLaf2);

} 

const var Div =[];

for (i = 0; i < 12; i++)
{
    Div[i] = Content.getComponent("Div"+(i+1)).setLocalLookAndFeel(KnobLaf2);

} 

const var deldiv =[];

for (i = 0; i < 4; i++)
{
    deldiv[i] = Content.getComponent("deldiv"+(i+1)).setLocalLookAndFeel(KnobLaf2);

} 

const var Stage =[];

for (i = 0; i < 12; i++)
{
    Stage[i] = Content.getComponent("Stage"+(i+1)).setLocalLookAndFeel(KnobLaf2);

} 



const var DelayTimes =[];

for (i = 0; i < 4; i++)
{
    DelayTimes[i] = Content.getComponent("DelayTime"+(i+1)).setLocalLookAndFeel(KnobLaf2);

} 


const var MacroSliders = [Content.getComponent("MacroPos1"),
                          Content.getComponent("Macro1"),
                          Content.getComponent("Macro3"),
                          Content.getComponent("MacroPos2"),
                          Content.getComponent("MacroPitch2"),
                          Content.getComponent("MacroGain1"),
                          Content.getComponent("Macro4"),
                          Content.getComponent("Macro5"),
                          Content.getComponent("Macro6"),
                          Content.getComponent("MacroPitch1"),
                          Content.getComponent("MacroGain"),
                          Content.getComponent("Macro2"),
                          Content.getComponent("MacroPitch3"),
                          Content.getComponent("MacroPos3"),
                          Content.getComponent("MacroGain2"),
                          Content.getComponent("MacroGain3"),
                          Content.getComponent("MacroPitch4"),
                          Content.getComponent("Macro8"),
                          Content.getComponent("Macro7"),
                          Content.getComponent("MacroPos4")];
                

for(s in MacroSliders)
      s.setLocalLookAndFeel(KnobLaf2);
      
      