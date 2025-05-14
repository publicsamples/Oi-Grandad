const var pitch3 = Content.getComponent("pitch3");

const var XfModControls4 = Content.getComponent("XfModControls4");
const var XfMode4 = Content.getComponent("XfMode4");

const var StackItem4 = [Content.getComponent("PosIndicator11"),
                        Content.getComponent("PosIndicator12"),
                        Content.getComponent("PosIndicator13"),
                        Content.getComponent("StagesPos4"),
                        Content.getComponent("PosOffsetLabel4"),
                        Content.getComponent("posoffset4"),
                        Content.getComponent("XfModeLabel4"),
                        Content.getComponent("XfMode4"),
                        Content.getComponent("StagesPitch4"),
                        Content.getComponent("PitchOffsetLabel4"),
                        Content.getComponent("pitchoffset4")];



inline function onStgSel4Control(component, value)
{

if(value == 0)
  {

     XfMode4.setValue(1);
             XfMode4.changed();
             
        gran4.setAttribute(gran4.Stack, 0);  
        gran4.setAttribute(gran4.PositionModMode, 0);
        gran4.setAttribute(gran4.PitchModMode, 0);
        pos3.showControl(1);
        pitch3.showControl(1);
        XfModControls4.showControl(0);
        
        
       for(s in StackItem4)
            s.showControl(0);
                   
	}
	
if(value == 1)
  {
			pos3.showControl(0);
         gran4.setAttribute(gran4.Stack, 1);   
        gran4.setAttribute(gran4.PositionModMode, 1);
               gran4.setAttribute(gran4.PitchModMode, 1);
               pitch3.showControl(0);
               
              for(s in StackItem4)
                  s.showControl(1);
              
	}
	

};

Content.getComponent("StgSel4").setControlCallback(onStgSel4Control);


const var pos3 = Content.getComponent("pos3");


inline function onposoffset4Control(component, value)
{
		pos3.setValue(value);
		pos3.changed();
};

Content.getComponent("posoffset4").setControlCallback(onposoffset4Control);

const var pitchCont4 = Content.getComponent("pitch3");

inline function onpitchoffset4Control(component, value)
{
		pitchCont4.setValue(value);
		pitchCont4.changed();
};

Content.getComponent("pitchoffset4").setControlCallback(onpitchoffset4Control);


const var GrainSyncUI4 = [Content.getComponent("graintempo4"),
						Content.getComponent("graindiv4")];

const var grainsize4 = Content.getComponent("grainsize4");

inline function onGrainSync4Control(component, value)
{
	if(value == 0)
  {

     
        gran4.setAttribute(gran4.GrainSync, 0);  
     	grainsize4.showControl(1);
       
       	for(s in GrainSyncUI4)
                 s.showControl(0);             
	}
	
	if(value == 1)
	  {
	
	     
	        gran4.setAttribute(gran4.GrainSync, 1);  
	     	grainsize4.showControl(0);
	       
	       	for(s in GrainSyncUI4)
	                 s.showControl(1);             
	}
};

Content.getComponent("GrainSync4").setControlCallback(onGrainSync4Control);

const var WinSyncUI4 = [Content.getComponent("WindowTempo4"), 
                        Content.getComponent("WinFadeTempo4"),
                        Content.getComponent("windowdiv4")];
                        
const var WinControls4 = [Content.getComponent("Winfade4"),
                          Content.getComponent("Window4")];



inline function onwinsync4Control(component, value)
{
if(value == 0)
  {

     
        gran4.setAttribute(gran4.WinSync, 0);  
     	for(s in WinControls4)
                 s.showControl(1);  
       
       
       	for(s in WinSyncUI4)
                 s.showControl(0);             
	}
	
	if(value == 1)
	  {
	
	     
	        gran4.setAttribute(gran4.WinSync, 1);  
	     for(s in WinControls4)
                 s.showControl(0); 
	       
	       	for(s in WinSyncUI4)
	                 s.showControl(1);             
	}
};

Content.getComponent("winsync4").setControlCallback(onwinsync4Control);


inline function onXfMode4Control(component, value)
{
if(value == 1)
  {

     
        gran4.setAttribute(gran4.XfMode, 1);  
	    XfModControls4.showControl(0);                       
	}
if(value == 2)
  {

     
        gran4.setAttribute(gran4.XfMode, 2);  
	    XfModControls4.showControl(1);                       
	}
	
	if(value == 3)
	  {
	
	     
	        gran4.setAttribute(gran4.XfMode, 4);  
		    XfModControls4.showControl(1);                       
		}	
	
};

Content.getComponent("XfMode4").setControlCallback(onXfMode4Control);

const var Dsync4 = [Content.getComponent("DelayTime4"),
                   Content.getComponent("deldiv2")];

const var DelayPitch4 = Content.getComponent("DelayPitch4");

const var Proc4 = Synth.getEffect("Proc4");

inline function onDelMode4Control(component, value)
{
if(value == 1)
  {
	for(s in Dsync4)
             s.showControl(1);   
    DelayPitch4.showControl(0);          
    Proc4.setAttribute(Proc4.delaymode, 1);   
             
             }
 if(value == 2)
   {
 	for(s in Dsync4)
              s.showControl(0);   
    DelayPitch4.showControl(1);           
    Proc4.setAttribute(Proc4.delaymode, 2);   
              }            
             
  if(value == 3)
    {
  	for(s in Dsync4)
              s.showControl(0);   
    DelayPitch4.showControl(1); 
    Proc4.setAttribute(Proc4.delaymode, 4);    
               }           
};

Content.getComponent("DelMode4").setControlCallback(onDelMode4Control);



