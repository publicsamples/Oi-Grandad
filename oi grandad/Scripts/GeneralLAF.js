

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

const var cBLaf = Content.createLocalLookAndFeel();

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



         


const var ModeMenus1 = [Content.getComponent("OutputSelector"),
                        Content.getComponent("maxGrains1"),
                        Content.getComponent("PitchMode1")];


for(s in ModeMenus1)
       s.setLocalLookAndFeel(cBLaf); 
  

       
       
const var ModeMenus2 = [Content.getComponent("maxGrains2"),
                       
                        Content.getComponent("OutputSelector1")];


 for(s in ModeMenus2)
        s.setLocalLookAndFeel(cBLaf);  
        

const var ModeMenus3 = [Content.getComponent("maxGrains3"),
                        
                        Content.getComponent("OutputSelector2")];

for(s in ModeMenus3)
       s.setLocalLookAndFeel(cBLaf);  
       


const var ModeMenus4 = [Content.getComponent("maxGrains4"),
                        Content.getComponent("OutputSelector3")];
  
  for(s in ModeMenus4)
         s.setLocalLookAndFeel(cBLaf);
         
 
       
const var GlbMenus = [Content.getComponent("MidiNote"),
                      Content.getComponent("Playback"),
                      Content.getComponent("VoiceNumber"),
                      Content.getComponent("Poly"),
                      Content.getComponent("ModPage"),
                      Content.getComponent("cmbPresets")];

  for(s in GlbMenus)
         s.setLocalLookAndFeel(cBLaf);      
         
       
       
const var ResMode = [Content.getComponent("ResMode1"),
                      Content.getComponent("ResMode2"),
                      Content.getComponent("ResMode3"),
                      Content.getComponent("ResMode4")];
                      
                      
   
   for(s in ResMode)
           s.setLocalLookAndFeel(cBLaf);      
           

 
 const var Pb = [Content.getComponent("StgSel1"),
            Content.getComponent("StgSel2"),
            Content.getComponent("StgSel3"),
            Content.getComponent("StgSel4")];    

        
            
            
for(s in Pb)
       s.setLocalLookAndFeel(cBLaf);        
       
const var ModeMenus = [Content.getComponent("TransPort1"),
Content.getComponent("TransPort2"),
Content.getComponent("TransPort3"),
Content.getComponent("TransPort4"),
                       Content.getComponent("Read1"),
                       Content.getComponent("Read2"),
                       Content.getComponent("Read3"),
                       Content.getComponent("Read4") ];
    
    for(s in ModeMenus)
           s.setLocalLookAndFeel(cBLaf);            
       

                            