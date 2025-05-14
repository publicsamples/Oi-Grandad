const var pitch1 = Content.getComponent("pitch1");

const var XfModControls2 = Content.getComponent("XfModControls2");
const var XfMode2 = Content.getComponent("XfMode2");

const var StackItem2 = [Content.getComponent("PosIndicator5"),
                        Content.getComponent("PosIndicator6"),
                        Content.getComponent("PosIndicator7"),
                        Content.getComponent("StagesPos2"),
                        Content.getComponent("PosOffsetLabel2"),
                        Content.getComponent("posoffset2"),
                        Content.getComponent("XfModeLabel2"),
                        Content.getComponent("XfMode2"),
                        Content.getComponent("StagesPitch2"),
                        Content.getComponent("PitchOffsetLabel2"),
                        Content.getComponent("pitchoffset2")];



inline function onStgSel2Control(component, value)
{

if(value == 0)
  {

     XfMode2.setValue(1);
             XfMode2.changed();
             
        gran2.setAttribute(gran2.Stack, 0);  
        gran2.setAttribute(gran2.PositionModMode, 0);
        gran2.setAttribute(gran2.PitchModMode, 0);
        pos1.showControl(1);
        pitch1.showControl(1);
        XfModControls2.showControl(0);
        
        
       for(s in StackItem2)
            s.showControl(0);
                   
	}
	
if(value == 1)
  {
			pos1.showControl(0);
         gran2.setAttribute(gran2.Stack, 1);   
        gran2.setAttribute(gran2.PositionModMode, 1);
               gran2.setAttribute(gran2.PitchModMode, 1);
               pitch1.showControl(0);
               
              for(s in StackItem2)
                  s.showControl(1);
              
	}
	

};

Content.getComponent("StgSel2").setControlCallback(onStgSel2Control);


const var pos1 = Content.getComponent("pos1");


inline function onposoffset2Control(component, value)
{
		pos1.setValue(value);
		pos1.changed();
};

Content.getComponent("posoffset2").setControlCallback(onposoffset2Control);

const var pitch1Cont2 = Content.getComponent("pitch1");

inline function onpitchoffset2Control(component, value)
{
		pitch1Cont2.setValue(value);
		pitch1Cont2.changed();
};

Content.getComponent("pitchoffset2").setControlCallback(onpitchoffset2Control);


const var GrainSyncUI2 = [Content.getComponent("graintempo2"),
					    Content.getComponent("ParamLabel187"),
						Content.getComponent("graindiv2")];

const var grainsize2 = Content.getComponent("grainsize2");

inline function onGrainSync2Control(component, value)
{
	if(value == 0)
  {

     
        gran2.setAttribute(gran2.GrainSync, 0);  
     	grainsize2.showControl(1);
       
       	for(s in GrainSyncUI2)
                 s.showControl(0);             
	}
	
	if(value == 1)
	  {
	
	     
	        gran2.setAttribute(gran2.GrainSync, 1);  
	     	grainsize2.showControl(0);
	       
	       	for(s in GrainSyncUI2)
	                 s.showControl(1);             
	}
};

Content.getComponent("GrainSync2").setControlCallback(onGrainSync2Control);

const var WinSyncUI2 = [Content.getComponent("WindowTempo2"), 
                        Content.getComponent("WinFadeTempo2"),
                        Content.getComponent("ParamLabel82"),
                        Content.getComponent("windowdiv2")];
                        
const var WinControls2 = [Content.getComponent("Winfade2"),
                          Content.getComponent("Window2")];



inline function onwinsync2Control(component, value)
{
if(value == 0)
  {

     
        gran2.setAttribute(gran2.WinSync, 0);  
     	for(s in WinControls2)
                 s.showControl(1);  
       
       
       	for(s in WinSyncUI2)
                 s.showControl(0);             
	}
	
	if(value == 1)
	  {
	
	     
	        gran2.setAttribute(gran2.WinSync, 1);  
	     for(s in WinControls2)
                 s.showControl(0); 
	       
	       	for(s in WinSyncUI2)
	                 s.showControl(1);             
	}
};

Content.getComponent("winsync2").setControlCallback(onwinsync2Control);


inline function onXfMode2Control(component, value)
{
if(value == 1)
  {

     
        gran2.setAttribute(gran2.XfMode, 1);  
	    XfModControls2.showControl(0);                       
	}
if(value == 2)
  {

     
        gran2.setAttribute(gran2.XfMode, 2);  
	    XfModControls2.showControl(1);                       
	}
	
	if(value == 3)
	  {
	
	     
	        gran2.setAttribute(gran2.XfMode, 3);  
		    XfModControls2.showControl(1);                       
		}	
	
};

Content.getComponent("XfMode2").setControlCallback(onXfMode2Control);

const var Dsync2 = [Content.getComponent("DelayTime2"),
                   Content.getComponent("deldiv2")];

const var DelayPitch2 = Content.getComponent("DelayPitch2");

const var Proc2 = Synth.getEffect("Proc2");

inline function onDelMode2Control(component, value)
{
if(value == 1)
  {
	for(s in Dsync2)
             s.showControl(1);   
    DelayPitch2.showControl(0);          
    Proc2.setAttribute(Proc2.delaymode, 1);   
             
             }
 if(value == 2)
   {
 	for(s in Dsync2)
              s.showControl(0);   
    DelayPitch2.showControl(1);           
    Proc2.setAttribute(Proc2.delaymode, 2);   
              }            
             
  if(value == 3)
    {
  	for(s in Dsync2)
              s.showControl(0);   
    DelayPitch2.showControl(1); 
    Proc2.setAttribute(Proc2.delaymode, 3);    
               }           
};

Content.getComponent("DelMode2").setControlCallback(onDelMode2Control);





