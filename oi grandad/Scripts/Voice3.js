const var pitch2 = Content.getComponent("pitch2");

const var XfModControls3 = Content.getComponent("XfModControls3");
const var XfMode3 = Content.getComponent("XfMode3");

const var StackItem3 = [Content.getComponent("PosIndicator10"),
                        Content.getComponent("PosIndicator11"),
                        Content.getComponent("PosIndicator12"),
                        Content.getComponent("StagesPos3"),
                        Content.getComponent("PosOffsetLabel3"),
                        Content.getComponent("posoffset3"),
                        Content.getComponent("XfModeLabel3"),
                        Content.getComponent("XfMode3"),
                        Content.getComponent("StagesPitch3"),
                        Content.getComponent("PitchOffsetLabel3"),
                        Content.getComponent("pitchoffset3")];



inline function onStgSel3Control(component, value)
{

if(value == 0)
  {

     XfMode3.setValue(1);
             XfMode3.changed();
             
        gran3.setAttribute(gran3.Stack, 0);  
        gran3.setAttribute(gran3.PositionModMode, 0);
        gran3.setAttribute(gran3.PitchModMode, 0);
        pos2.showControl(1);
        pitch2.showControl(1);
        XfModControls3.showControl(0);
        
        
       for(s in StackItem3)
            s.showControl(0);
                   
	}
	
if(value == 1)
  {
			pos2.showControl(0);
         gran3.setAttribute(gran3.Stack, 1);   
        gran3.setAttribute(gran3.PositionModMode, 1);
               gran3.setAttribute(gran3.PitchModMode, 1);
               pitch2.showControl(0);
               
              for(s in StackItem3)
                  s.showControl(1);
              
	}
	

};

Content.getComponent("StgSel3").setControlCallback(onStgSel3Control);


const var pos2 = Content.getComponent("pos2");


inline function onposoffset3Control(component, value)
{
		pos2.setValue(value);
		pos2.changed();
};

Content.getComponent("posoffset3").setControlCallback(onposoffset3Control);

const var pitchCont3 = Content.getComponent("pitch2");

inline function onpitchoffset3Control(component, value)
{
		pitchCont3.setValue(value);
		pitchCont3.changed();
};

Content.getComponent("pitchoffset3").setControlCallback(onpitchoffset3Control);


const var GrainSyncUI3 = [Content.getComponent("graintempo3"),
						Content.getComponent("graindiv3")];

const var grainsize3 = Content.getComponent("grainsize3");

inline function onGrainSync3Control(component, value)
{
	if(value == 0)
  {

     
        gran3.setAttribute(gran3.GrainSync, 0);  
     	grainsize3.showControl(1);
       
       	for(s in GrainSyncUI3)
                 s.showControl(0);             
	}
	
	if(value == 1)
	  {
	
	     
	        gran3.setAttribute(gran3.GrainSync, 1);  
	     	grainsize3.showControl(0);
	       
	       	for(s in GrainSyncUI3)
	                 s.showControl(1);             
	}
};

Content.getComponent("GrainSync3").setControlCallback(onGrainSync3Control);

const var WinSyncUI3 = [Content.getComponent("WindowTempo3"), 
                        Content.getComponent("WinFadeTempo3"),
                        Content.getComponent("windowdiv3")];
                        
const var WinControls3 = [Content.getComponent("Winfade3"),
                          Content.getComponent("Window3")];



inline function onwinsync3Control(component, value)
{
if(value == 0)
  {

     
        gran3.setAttribute(gran3.WinSync, 0);  
     	for(s in WinControls3)
                 s.showControl(1);  
       
       
       	for(s in WinSyncUI3)
                 s.showControl(0);             
	}
	
	if(value == 1)
	  {
	
	     
	        gran3.setAttribute(gran3.WinSync, 1);  
	     for(s in WinControls3)
                 s.showControl(0); 
	       
	       	for(s in WinSyncUI3)
	                 s.showControl(1);             
	}
};

Content.getComponent("winsync3").setControlCallback(onwinsync3Control);


inline function onXfMode3Control(component, value)
{
if(value == 1)
  {

     
        gran3.setAttribute(gran3.XfMode, 1);  
	    XfModControls3.showControl(0);                       
	}
if(value == 2)
  {

     
        gran3.setAttribute(gran3.XfMode, 2);  
	    XfModControls3.showControl(1);                       
	}
	
	if(value == 3)
	  {
	
	     
	        gran3.setAttribute(gran3.XfMode, 3);  
		    XfModControls3.showControl(1);                       
		}	
	
};

Content.getComponent("XfMode3").setControlCallback(onXfMode3Control);

const var Dsync3 = [Content.getComponent("DelayTime3"),
                   Content.getComponent("deldiv2")];

const var DelayPitch3 = Content.getComponent("DelayPitch3");

const var Proc3 = Synth.getEffect("Proc3");

inline function onDelMode3Control(component, value)
{
if(value == 1)
  {
	for(s in Dsync3)
             s.showControl(1);   
    DelayPitch3.showControl(0);          
    Proc3.setAttribute(Proc3.delaymode, 1);   
             
             }
 if(value == 2)
   {
 	for(s in Dsync3)
              s.showControl(0);   
    DelayPitch3.showControl(1);           
    Proc3.setAttribute(Proc3.delaymode, 2);   
              }            
             
  if(value == 3)
    {
  	for(s in Dsync3)
              s.showControl(0);   
    DelayPitch3.showControl(1); 
    Proc3.setAttribute(Proc3.delaymode, 3);    
               }           
};

Content.getComponent("DelMode3").setControlCallback(onDelMode3Control);



