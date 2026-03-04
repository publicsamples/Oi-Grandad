

//Draw Combobox

const var cBLaf = Content.createLocalLookAndFeel();


const var laf = Engine.createGlobalScriptLookAndFeel();

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
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
    g.setFont("Montserrat", 16.0);
   
  
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

laf.registerFunction("drawTableRuler", function(g, obj)
{
    g.setColour(Colours.withAlpha(obj.bgColour, 2.1));
    
    var x = obj.position * obj.area[2];
    
    g.drawLine(x, x, 0, obj.area[3], 10.0);
    g.setColour(obj.bgColour);
    g.drawLine(x, x, 0, obj.area[3], 1);
});

const var ModulationMenus = [Content.getComponent("TempoModSel1"),
					  Content.getComponent("TempoModSel2"),
					  Content.getComponent("TempoModSel3"),
					  Content.getComponent("TempoModSel4"),
					  Content.getComponent("TempoModSel5"),
					  Content.getComponent("TempoModSel6"),
					  Content.getComponent("TempoModSel7"),
					  Content.getComponent("TempoModSel8"),
					  Content.getComponent("TempoModSel9"),
					  Content.getComponent("TempoModSel10"),
					  Content.getComponent("TempoModSel11"),
					  Content.getComponent("TempoModSel12"),
                      Content.getComponent("MorphModSel1"),
                      Content.getComponent("MorphModSel2"),
                      Content.getComponent("MorphModSel3"),
                      Content.getComponent("MorphModSel4"),
                      Content.getComponent("MorphModSel5"),
                      Content.getComponent("MorphModSel6"),
                      Content.getComponent("MorphModSel7"),
                      Content.getComponent("MorphModSel8"),
                      Content.getComponent("MorphModSel9"),
                      Content.getComponent("MorphModSel10"),
                      Content.getComponent("MorphModSel11"),
                      Content.getComponent("MorphModSel12"),
                      Content.getComponent("TrigSel1"),
                      Content.getComponent("TrigSel2"),
                      Content.getComponent("TrigSel3"),
                      Content.getComponent("TrigSel4"),
                      Content.getComponent("TrigSel5"),
                      Content.getComponent("TrigSel6"),
                      Content.getComponent("TrigSel7"),
                      Content.getComponent("TrigSel8"),
                      Content.getComponent("TrigSel9"),
                      Content.getComponent("TrigSel10"),
                      Content.getComponent("TrigSel11"),
                      Content.getComponent("TrigSel12")];

for(s in ModulationMenus)
       s.setLocalLookAndFeel(cBLaf); 

const var ModMenus1 = [Content.getComponent("PosHeadSrcA1"),
                       Content.getComponent("PosHeadSrcA2"),
                       Content.getComponent("PosHeadSrcA4"),
                       Content.getComponent("PosHeadSrcA3"),
                       Content.getComponent("pos1modsel"),
                       Content.getComponent("PmodSel1"),
                       Content.getComponent("detmodsel"),
                       Content.getComponent("spreadmodsel4"),
                       Content.getComponent("densemodsel"),
                       Content.getComponent("spreadmodsel"),
                       Content.getComponent("winmodsrc1"),
                       Content.getComponent("GrainModSel1"),
                       Content.getComponent("cut1modsel"),
                       Content.getComponent("delmodsel1"),
                       Content.getComponent("redmodsel1"),
                       Content.getComponent("delmodsel5"),
                       Content.getComponent("cut1modselB1"),
                       Content.getComponent("ampmodsel"),
                       Content.getComponent("PanModSel1")];

for(s in ModMenus1)
       s.setLocalLookAndFeel(cBLaf); 
       
const var ModeMenus1 = [Content.getComponent("type"),
                        Content.getComponent("type4"),
                        Content.getComponent("OutputSelector"),
                        Content.getComponent("maxGrains1"),
                        Content.getComponent("PitchMode1"),
                        Content.getComponent("Voices1")];


for(s in ModeMenus1)
       s.setLocalLookAndFeel(cBLaf); 
  
const var ModMenus2 = [Content.getComponent("PmodSel2"),
                       Content.getComponent("detmodsel1"),
                       Content.getComponent("spreadmodsel5"),
                       Content.getComponent("spread1"),
                       Content.getComponent("pos1modsel1"),
                       Content.getComponent("densemodsel1"),
                       Content.getComponent("GrainModSel2"),
                       Content.getComponent("winmodsrc2"),
                       Content.getComponent("spreadmodsel1"),
                       Content.getComponent("ampmodsel1"),
                       Content.getComponent("PanModSel2"),
                       Content.getComponent("cut1modselB2"),
                       Content.getComponent("delmodsel2"),
                       Content.getComponent("redmodsel2"),
                       Content.getComponent("delmodsel6"),
                       Content.getComponent("cut1modsel1")];
                       
for(s in ModMenus2)
       s.setLocalLookAndFeel(cBLaf);  
       
       
const var ModeMenus2 = [Content.getComponent("maxGrains2"),
                        Content.getComponent("Voices2"),
                        Content.getComponent("OutputSelector1"),
                        Content.getComponent("type5"),
                        Content.getComponent("PitchMode2"),
                        Content.getComponent("type1")];


 for(s in ModeMenus2)
        s.setLocalLookAndFeel(cBLaf);  
        
const var ModMenus3 = [Content.getComponent("PosHeadSrcA9"),
                       Content.getComponent("PosHeadSrcA10"),
                       Content.getComponent("PosHeadSrcA12"),
                       Content.getComponent("PosHeadSrcA11"),
                       Content.getComponent("densemodsel2"),
                       Content.getComponent("spreadmodsel6"),
                       Content.getComponent("detmodsel2"),
                       Content.getComponent("PmodSel3"),
                       Content.getComponent("spreadmodsel2"),
                       Content.getComponent("pos1modsel2"),
                       Content.getComponent("GrainModSel3"),
                       Content.getComponent("winmodsrc3"),
                       Content.getComponent("cut1modselB3"),
                       Content.getComponent("delmodsel3"),
                       Content.getComponent("redmodsel3"),
                       Content.getComponent("delmodsel7"),
                       Content.getComponent("cut1modsel2"),
                       Content.getComponent("ampmodsel2"),
                       Content.getComponent("PanModSel3")];

       for(s in ModMenus3)
              s.setLocalLookAndFeel(cBLaf);      

const var ModeMenus3 = [Content.getComponent("maxGrains3"),
                        Content.getComponent("Voices3"),
                        Content.getComponent("OutputSelector2"),
                        Content.getComponent("PitchMode3"),
                        Content.getComponent("type6"),
                        Content.getComponent("type2")];

for(s in ModeMenus3)
       s.setLocalLookAndFeel(cBLaf);  
       
const var ModMenus4 = [Content.getComponent("PosHeadSrcA13"),
                       Content.getComponent("PosHeadSrcA14"),
                       Content.getComponent("PosHeadSrcA16"),
                       Content.getComponent("PosHeadSrcA15"),
                       Content.getComponent("densemodsel3"),
                       Content.getComponent("GrainModSel4"),
                       Content.getComponent("winmodsrc4"),
                       Content.getComponent("pos1modsel3"),
                       Content.getComponent("spreadmodsel3"),
                       Content.getComponent("spreadmodsel7"),
                       Content.getComponent("PmodSel4"),
                       Content.getComponent("detmodsel3"),
                       Content.getComponent("cut1modselB4"),
                       Content.getComponent("ampmodsel3"),
                       Content.getComponent("PanModSel4"),
                       Content.getComponent("cut1modsel3"),
                       Content.getComponent("delmodsel4"),
                       Content.getComponent("redmodsel4"),
                       Content.getComponent("delmodsel8")];

for(s in ModMenus4)
       s.setLocalLookAndFeel(cBLaf);

const var ModeMenus4 = [Content.getComponent("maxGrains4"),
                        Content.getComponent("Voices4"),
                        Content.getComponent("type7"),
                        Content.getComponent("type3"),
                        Content.getComponent("PitchMode4"),
                        Content.getComponent("OutputSelector3")];
  

for(s in ModeMenus4)
       s.setLocalLookAndFeel(cBLaf);
       
const var GlbMenus = [Content.getComponent("MidiNote"),
                      Content.getComponent("Playback"),
                      Content.getComponent("ModPage"),
                      Content.getComponent("cmbPresets")];

  for(s in GlbMenus)
         s.setLocalLookAndFeel(cBLaf);      
         
const var macroMods = [Content.getComponent("MacroScr1"),
                       Content.getComponent("MacroScr2"),
                       Content.getComponent("MacroScr3"),
                       Content.getComponent("MacroScr4"),
                       Content.getComponent("MacroScr5"),
                       Content.getComponent("MacroScr6"),
                       Content.getComponent("MacroScr7"),
                       Content.getComponent("MacroScr8")];
 
 for(s in macroMods)
         s.setLocalLookAndFeel(cBLaf);       
       
       
const var ResMode = [Content.getComponent("ResMode1"),
                      Content.getComponent("ResMode2"),
                      Content.getComponent("ResMode3"),
                      Content.getComponent("ResMode4")];
                      
                      
   
   for(s in ResMode)
           s.setLocalLookAndFeel(cBLaf);       
                            