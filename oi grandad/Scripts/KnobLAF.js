const var KnobLaf = Content.createLocalLookAndFeel();



KnobLaf.registerFunction("drawRotarySlider", function(g, obj)
{
	var underDrag = Content.getComponentUnderDrag() == obj.id;
	

	var textArea = Rect.removeFromBottom(obj.area, obj.area[3] - obj.area[2]);


	var isBipolar = obj.min < 0 && obj.id != "Knob1";
	var start = isBipolar ? 0 : -2.7;
	var modStart = isBipolar ? (-2.7 + obj.valueNormalized * 2 * 2.7) : -2.7;

	g.setColour(0x00000000);

	var radius = 40 - obj.clicked;

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
	
	
///	p.addArc([0.0, 0.0, 1.0, 1.0], modStart, -2.66 + Math.max(0.01, modValue) * 2 * 2.66);
	
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

const var pos13 =[];

for (i = 0; i < 3; i++)
{
    pos13[i] = Content.getComponent("pos"+(i+1)).setLocalLookAndFeel(KnobLaf);

}  
	
Content.getComponent("pos").setLocalLookAndFeel(KnobLaf);

const var WindowTempo =[];

for (i = 0; i < 4; i++)
{
    WindowTempo[i] = Content.getComponent("WindowTempo"+(i+1)).setLocalLookAndFeel(KnobLaf);

}  	

const var Window =[];

for (i = 0; i < 4; i++)
{
    Window[i] = Content.getComponent("Window"+(i+1)).setLocalLookAndFeel(KnobLaf);

}  	

const var grainsize =[];

for (i = 0; i < 4; i++)
{
    grainsize[i] = Content.getComponent("grainsize"+(i+1)).setLocalLookAndFeel(KnobLaf);

}  	

Content.getComponent("pitch").setLocalLookAndFeel(KnobLaf);

const var pitch24 =[];

for (i = 0; i < 3; i++)
{
    pitch24[i] = Content.getComponent("pitch"+(i+1)).setLocalLookAndFeel(KnobLaf);

}  


 
const var DelayTime =[];

for (i = 0; i < 4; i++)
{
    DelayTime[i] = Content.getComponent("DelayTime"+(i+1)).setLocalLookAndFeel(KnobLaf);

}  

const var Xf =[];

for (i = 0; i < 4; i++)
{
    Xf[i] = Content.getComponent("Xf"+(i+1)).setLocalLookAndFeel(KnobLaf);

}  

const var Dense =[];

for (i = 0; i < 4; i++)
{
    Dense[i] = Content.getComponent("Dense"+(i+1)).setLocalLookAndFeel(KnobLaf);

} 

const var cutoff =[];

for (i = 0; i < 4; i++)
{
    cutoff[i] = Content.getComponent("cutoff"+(i+1)).setLocalLookAndFeel(KnobLaf);

} 

const var graintempo =[];

for (i = 0; i < 4; i++)
{
    graintempo[i] = Content.getComponent("graintempo"+(i+1)).setLocalLookAndFeel(KnobLaf);

} 

Content.getComponent("det").setLocalLookAndFeel(KnobLaf);
const var detune =[];

for (i = 0; i < 3; i++)
{
    detune[i] = Content.getComponent("det"+(i+1)).setLocalLookAndFeel(KnobLaf);

} 

Content.getComponent("spread").setLocalLookAndFeel(KnobLaf);

const var spreads =[];

for (i = 0; i < 3; i++)
{
    spreads[i] = Content.getComponent("spread"+(i+1)).setLocalLookAndFeel(KnobLaf);

} 

Content.getComponent("spread").setLocalLookAndFeel(KnobLaf);

const var Winfade =[];

for (i = 0; i < 4; i++)
{
    Winfade[i] = Content.getComponent("Winfade"+(i+1)).setLocalLookAndFeel(KnobLaf);

} 

const var WinFadeTempo =[];

for (i = 0; i < 4; i++)
{
    WinFadeTempo[i] = Content.getComponent("WinFadeTempo"+(i+1)).setLocalLookAndFeel(KnobLaf);

} 

////////////////// CONSTANTS //////////////////

const var CONST_LABEL_Backbground = 0;



const CONST_DisabledIndicatorColour = 0xFFC8F9F7c;

const CONST_InactiveIndicatorColour = 0xFFC8F9F7c;
const STARTX = 0;
const STARTY = 1;
const WIDTH = 2;
const HEIGHT = 2;

var LAF_Button = Content.createLocalLookAndFeel();


LAF_Button.registerFunction("drawToggleButton", function(g, obj)
{

	var WidgetArea = obj.area;
	
	// Is the button enabled?
	var ButtonActive = obj.enabled;

	 if (ButtonActive) {
		var opacity = obj.over ? 1.0 - (obj.down * 0.2) : 0.8 - (obj.down * 0.2);
		g.setGradientFill([Colours.withAlpha(obj.itemColour1, opacity), WidgetArea[STARTX], WidgetArea[STARTY], Colours.withAlpha(obj.itemColour2, opacity), WidgetArea[STARTX], WidgetArea[HEIGHT]]);
	} else {
	//	g.setColour(CONST_InactiveSurfaceColour);
	}

	// Draw the surface.
//	g.fillRoundedRectangle(WidgetArea, 4);

	// ------------- Indicator Light
	
	// Choose the colour(s).
	if (ButtonActive) {
		if (obj.value) { var fillColour = obj.bgColour; } else { var fillColour = CONST_DisabledIndicatorColour; }
		g.setColour(Colours.withAlpha(fillColour, obj.over ? 1.0 : 0.7));
	} else {
		g.setColour(CONST_InactiveIndicatorColour);
	}
	
	// Draw the indicator.
	g.fillEllipse([WidgetArea[STARTX] + 8, WidgetArea[STARTY] + WidgetArea[HEIGHT] / 2 - 4, 8, 8]);
	});

///////////////// BUTTON DEFINITION ///////////////// 


const var winsync =[];

for (i = 0; i < 4; i++)
{
    winsync[i] = Content.getComponent("winsync"+(i+1)).setLocalLookAndFeel(LAF_Button);

}

const var GrainSync =[];

for (i = 0; i < 4; i++)
{
    GrainSync[i] = Content.getComponent("GrainSync"+(i+1)).setLocalLookAndFeel(LAF_Button);

}

const var Direction =[];

for (i = 0; i < 12; i++)
{
    Direction[i] = Content.getComponent("Direction"+(i+1)).setLocalLookAndFeel(LAF_Button);

}

const var OneShot =[];

for (i = 0; i < 12; i++)
{
    OneShot[i] = Content.getComponent("OneShot"+(i+1)).setLocalLookAndFeel(LAF_Button);

}

const var ModType =[];

for (i = 0; i < 12; i++)
{
    ModType[i] = Content.getComponent("ModType"+(i+1)).setLocalLookAndFeel(LAF_Button);

}

const var RrLeds =[];

for (i = 0; i < 4; i++)
{
    RrLeds[i] = Content.getComponent("RrLed"+(i)).setLocalLookAndFeel(LAF_Button);

}

const var RecEnableLaf = Content.getComponent("RecEnable1").setLocalLookAndFeel(LAF_Button);

const var DelMode1 = Content.getComponent("DelMode1").setLocalLookAndFeel(LAF_Button);
const var DelMode2 = Content.getComponent("DelMode2").setLocalLookAndFeel(LAF_Button);
const var DelMode3 = Content.getComponent("DelMode3").setLocalLookAndFeel(LAF_Button);
const var DelMode4 = Content.getComponent("DelMode4").setLocalLookAndFeel(LAF_Button);
const var DelMode5 = Content.getComponent("DelMode5").setLocalLookAndFeel(LAF_Button);
const var DelMode6 = Content.getComponent("DelMode6").setLocalLookAndFeel(LAF_Button);
const var DelMode7 = Content.getComponent("DelMode7").setLocalLookAndFeel(LAF_Button);
const var DelMode8 = Content.getComponent("DelMode8").setLocalLookAndFeel(LAF_Button);
const var DelMode9 = Content.getComponent("DelMode9").setLocalLookAndFeel(LAF_Button);
const var DelMode10 = Content.getComponent("DelMode10").setLocalLookAndFeel(LAF_Button);
const var DelMode11 = Content.getComponent("DelMode11").setLocalLookAndFeel(LAF_Button);
const var DelMode12 = Content.getComponent("DelMode12").setLocalLookAndFeel(LAF_Button);
