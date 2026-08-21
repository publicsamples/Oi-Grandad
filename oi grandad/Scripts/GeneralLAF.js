

//Draw Combobox

const var cBLaf = Content.createLocalLookAndFeel();
const var laf = Engine.createGlobalScriptLookAndFeel();
const var posIndicatorLaf1 = Content.createLocalLookAndFeel();
const var posIndicatorLaf2 = Content.createLocalLookAndFeel();
const var posIndicatorLaf3 = Content.createLocalLookAndFeel();
const var posIndicatorLaf4 = Content.createLocalLookAndFeel();

inline function setLookAndFeelForIds(ids, localLookAndFeel)
{
	for (id in ids)
	{
		var component = Content.getComponent(id);
		
		if (isDefined(component))
			component.setLocalLookAndFeel(localLookAndFeel);
	}
}

laf.registerFunction("drawToggleButton", function(g, obj)
{
    g.setColour(obj.bgColour);   
    g.fillRoundedRectangle(obj.area, 4.0);
    
    if(obj.over)
        g.fillRoundedRectangle(obj.area, 4.0);
    
    if(obj.down)
        g.fillRoundedRectangle(obj.area, 4.0);
        
    g.setColour(Colours.withAlpha(obj.textColour, obj.value ? 1.0 : 0.3));
    g.setFont("Montserrat", 18.0);
    g.drawAlignedText(obj.text, obj.area, "centred");
});

cBLaf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 1.5);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 1.0));
    g.setFont("Montserrat", 14.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});

laf.registerFunction("drawSliderPack", function(g, obj)
{
    g.fillRoundedRectangle(obj.area, 8.0);
        g.rotate(90, 90);
       g.setFont("Montserrat", 16.0);


});

laf.registerFunction("drawPresetBrowserListItem", function(g, obj)
{
    if(obj.selected)
    {
        g.setColour(0x22FFFFFF);
        g.fillRoundedRectangle(obj.area, 5.0);
        
       g.setFont("Montserrat", 16.0);
    }
   
    g.setColour(obj.textColour);
    g.setFont("Montserrat", 16.0);
    g.drawAlignedText(obj.text, obj.area, "centred");
});


posIndicatorLaf1.registerFunction("drawTableRuler", function(g, obj)
{
    var x = obj.area[0] + (obj.position * obj.area[2]);
    var top = obj.area[1];
    var bottom = obj.area[1] + obj.area[3];
    var centreY = obj.area[1] + (obj.area[3] * 0.5);
    var circleSize = 16.0;
    var circleArea = [x - (circleSize * 0.5), centreY - (circleSize * 0.5), circleSize, circleSize];

    g.setColour(0xFBFF9B9B);
    g.drawLine(x, x, top + 2.0, bottom - 2.0, 2.0);
    g.fillEllipse(circleArea);
    g.setColour(0xFF1F252C);
    g.setFont("Montserrat", 11.0);
    g.drawAlignedText("1", circleArea, "centred");
});

posIndicatorLaf2.registerFunction("drawTableRuler", function(g, obj)
{
    var x = obj.area[0] + (obj.position * obj.area[2]);
    var top = obj.area[1];
    var bottom = obj.area[1] + obj.area[3];
    var centreY = obj.area[1] + (obj.area[3] * 0.5);
    var circleSize = 16.0;
    var circleArea = [x - (circleSize * 0.5), centreY - (circleSize * 0.5), circleSize, circleSize];

    g.setColour(0xFFFFD6A5);
    g.drawLine(x, x, top + 2.0, bottom - 2.0, 2.0);
    g.fillEllipse(circleArea);
    g.setColour(0xFF1F252C);
    g.setFont("Montserrat", 11.0);
    g.drawAlignedText("2", circleArea, "centred");
});

posIndicatorLaf3.registerFunction("drawTableRuler", function(g, obj)
{
    var x = obj.area[0] + (obj.position * obj.area[2]);
    var top = obj.area[1];
    var bottom = obj.area[1] + obj.area[3];
    var centreY = obj.area[1] + (obj.area[3] * 0.5);
    var circleSize = 16.0;
    var circleArea = [x - (circleSize * 0.5), centreY - (circleSize * 0.5), circleSize, circleSize];

    g.setColour(0xFFFFFEC4);
    g.drawLine(x, x, top + 2.0, bottom - 2.0, 2.0);
    g.fillEllipse(circleArea);
    g.setColour(0xFF1F252C);
    g.setFont("Montserrat", 11.0);
    g.drawAlignedText("3", circleArea, "centred");
});

posIndicatorLaf4.registerFunction("drawTableRuler", function(g, obj)
{
    var x = obj.area[0] + (obj.position * obj.area[2]);
    var top = obj.area[1];
    var bottom = obj.area[1] + obj.area[3];
    var centreY = obj.area[1] + (obj.area[3] * 0.5);
    var circleSize = 16.0;
    var circleArea = [x - (circleSize * 0.5), centreY - (circleSize * 0.5), circleSize, circleSize];

    g.setColour(0xFFCBFFA9);
    g.drawLine(x, x, top + 2.0, bottom - 2.0, 2.0);
    g.fillEllipse(circleArea);
    g.setColour(0xFF1F252C);
    g.setFont("Montserrat", 11.0);
    g.drawAlignedText("4", circleArea, "centred");
});



         


const var ModeMenuIds1 = ["OutputSelector", "maxGrains1", "PostMode1", "PostMode2", "PostMode3", "PostMode4", "PitchMode1", "PitchMode2", "PitchMode3", "PitchMode4"];
const var ModeMenuIds2 = ["maxGrains2", "OutputSelector1"];
const var ModeMenuIds3 = ["maxGrains3", "OutputSelector2"];
const var ModeMenuIds4 = ["maxGrains4", "OutputSelector3"];
const var GlobalMenuIds = ["MidiNote", "Playback", "VoiceNumber", "Poly", "ModPage", "cmbPresets"];
const var ResModeIds = ["ResMode1", "ResMode2", "ResMode3", "ResMode4"];
const var PlaybackModeIds = ["StgSel1", "StgSel2", "StgSel3", "StgSel4"];
const var TriggerSelectorIds = ["TrigSel1", "TrigSel2", "TrigSel3", "TrigSel4", "TrigSel5", "TrigSel6", "TrigSel7", "TrigSel8", "TrigSel9", "TrigSel10", "TrigSel11", "TrigSel12"];
const var VoiceMenuIds = ["TransPort1", "TransPort2", "TransPort3", "TransPort4", "GrainDirMode1", "GrainDirMode2", "GrainDirMode3", "GrainDirMode4", "SpreadDirMode1", "SpreadDirMode2", "SpreadDirMode3", "SpreadDirMode4"];
const var TrackMenus = ["EnvVoiceSel5", "EnvVoiceSel6", "EnvVoiceSel7", "EnvVoiceSel8"];
const var PosIndicatorLane1Ids = ["PosIndicatorLaneA1", "PosIndicatorLaneA2", "PosIndicatorLaneA3", "PosIndicatorLaneA4"];
const var PosIndicatorLane2Ids = ["PosIndicatorLaneB1", "PosIndicatorLaneB2", "PosIndicatorLaneB3", "PosIndicatorLaneB4"];
const var PosIndicatorLane3Ids = ["PosIndicatorLaneC1", "PosIndicatorLaneC2", "PosIndicatorLaneC3", "PosIndicatorLaneC4"];
const var PosIndicatorLane4Ids = ["PosIndicatorLaneD1", "PosIndicatorLaneD2", "PosIndicatorLaneD3", "PosIndicatorLaneD4"];


setLookAndFeelForIds(ModeMenuIds1, cBLaf);
setLookAndFeelForIds(ModeMenuIds2, cBLaf);
setLookAndFeelForIds(ModeMenuIds3, cBLaf);
setLookAndFeelForIds(ModeMenuIds4, cBLaf);
setLookAndFeelForIds(GlobalMenuIds, cBLaf);
setLookAndFeelForIds(ResModeIds, cBLaf);
setLookAndFeelForIds(PlaybackModeIds, cBLaf);
setLookAndFeelForIds(TriggerSelectorIds, cBLaf);
setLookAndFeelForIds(VoiceMenuIds, cBLaf);
setLookAndFeelForIds(TrackMenus, cBLaf);
setLookAndFeelForIds(PosIndicatorLane1Ids, posIndicatorLaf1);
setLookAndFeelForIds(PosIndicatorLane2Ids, posIndicatorLaf2);
setLookAndFeelForIds(PosIndicatorLane3Ids, posIndicatorLaf3);
setLookAndFeelForIds(PosIndicatorLane4Ids, posIndicatorLaf4);     

                            
