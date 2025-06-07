const var pitch = Content.getComponent("pitch");

const var XfModControls1 = Content.getComponent("XfModControls1");
const var XfMode1 = Content.getComponent("XfMode1");

const var StackItem1 = [Content.getComponent("PosIndicator2"),
                        Content.getComponent("PosIndicator3"),
                        Content.getComponent("PosIndicator4"),
                        Content.getComponent("StagesPos1"),
                        Content.getComponent("PosOffsetLabel1"),
                        Content.getComponent("posoffset1"),
                        Content.getComponent("XfModeLabel1"),
                        Content.getComponent("XfMode1"),
                        Content.getComponent("StagesPitch1"),
                        Content.getComponent("PitchOffsetLabel1"),
                        Content.getComponent("pitchoffset1")];


inline function onStgSel1Control(component, value)
{

if(value == 0)
  {

     XfMode1.setValue(1);
             XfMode1.changed();
             
        gran.setAttribute(gran.Stack, 0);  
        gran.setAttribute(gran.PositionModMode, 0);
        gran.setAttribute(gran.PitchModMode, 0);
        pos.showControl(1);
        pitch.showControl(1);
        XfModControls1.showControl(0);
        BoxItems.showControl(0);
        
       for(s in StackItem1)
            s.showControl(0);
                   
	}
	
if(value == 1)
  {
			pos.showControl(0);
         gran.setAttribute(gran.Stack, 1);   
        gran.setAttribute(gran.PositionModMode, 1);
               gran.setAttribute(gran.PitchModMode, 1);
               pitch.showControl(0);
               BoxItems.showControl(0);

              for(s in StackItem1)
                  s.showControl(1);
              
	}
	

};

Content.getComponent("StgSel1").setControlCallback(onStgSel1Control);


const var pos = Content.getComponent("pos");


inline function onposoffset1Control(component, value)
{
		pos.setValue(value);
		pos.changed();
};

Content.getComponent("posoffset1").setControlCallback(onposoffset1Control);

const var pitchCont1 = Content.getComponent("pitch");

inline function onpitchoffset1Control(component, value)
{
		pitchCont1.setValue(value);
		pitchCont1.changed();
};

Content.getComponent("pitchoffset1").setControlCallback(onpitchoffset1Control);


const var GrainSyncUI1 = [Content.getComponent("graintempo1"),
                       Content.getComponent("ParamLabel50"),
                       Content.getComponent("graindiv1")];

const var grainsize1 = Content.getComponent("grainsize1");

inline function onGrainSync1Control(component, value)
{
	if(value == 0)
  {

     
        gran.setAttribute(gran.GrainSync, 0);  
     	grainsize1.showControl(1);
       
       	for(s in GrainSyncUI1)
                 s.showControl(0);             
	}
	
	if(value == 1)
	  {
	
	     
	        gran.setAttribute(gran.GrainSync, 1);  
	     	grainsize1.showControl(0);
	       
	       	for(s in GrainSyncUI1)
	                 s.showControl(1);             
	}
};

Content.getComponent("GrainSync1").setControlCallback(onGrainSync1Control);

const var WinSyncUI1 = [Content.getComponent("WindowTempo1"),
                        Content.getComponent("ParamLabel51"),
                        Content.getComponent("WinFadeTempo1"),
                        Content.getComponent("windowdiv1")];
                        
const var WinControls1 = [Content.getComponent("Winfade1"),
                          Content.getComponent("Window1")];



inline function onwinsync1Control(component, value)
{
if(value == 0)
  {

     
        gran.setAttribute(gran.WinSync, 0);  
     	for(s in WinControls1)
                 s.showControl(1);  
       
       
       	for(s in WinSyncUI1)
                 s.showControl(0);             
	}
	
	if(value == 1)
	  {
	
	     
	        gran.setAttribute(gran.WinSync, 1);  
	     for(s in WinControls1)
                 s.showControl(0); 
	       
	       	for(s in WinSyncUI1)
	                 s.showControl(1);             
	}
};

Content.getComponent("winsync1").setControlCallback(onwinsync1Control);

const var Mode1Settings1 = [Content.getComponent("VoiceParam6"),
                            Content.getComponent("VoiceParam5")];

const var TypeIIParams1 = Content.getComponent("TypeIIParams1");
const var PreGrainVerb1 = Content.getComponent("PreGrainVerb1");




inline function onXfMode1Control(component, value)
{
if(value == 1)
  {

     
        gran.setAttribute(gran.XfMode, 1);  
	    XfModControls1.showControl(0);    
	    BoxItems.showControl(0);                   
	}
if(value == 2)
  {

     
        gran.setAttribute(gran.XfMode, 2);  
	    XfModControls1.showControl(1);   
	    BoxItems.showControl(0);                    
	}
	
	if(value == 3)
	  {
	
	     
	        gran.setAttribute(gran.XfMode, 3);  
		    XfModControls1.showControl(1); 
		    BoxItems.showControl(0);                      
		}	
		
		
		if(value == 3)
		  {
		
		     
		        gran.setAttribute(gran.XfMode, 4);  
			    XfModControls1.showControl(1); 
			    BoxItems.showControl(0);                     
			}	
	
};

Content.getComponent("XfMode1").setControlCallback(onXfMode1Control);

//mystrey box
const var Dsync1 =[];

Dsync1[0] = Content.getComponent("DelayTime1");
Dsync1[1] = Content.getComponent("DelayTempo1");
Dsync1[2] = Content.getComponent("DelayPitch1");


const var DelayPitch1 = Content.getComponent("DelayPitch1");

const var Proc1 = Synth.getEffect("Proc1");

inline function onDelMode1Control(component, value)
{
	Proc1.setAttribute(Proc1.DelClockMode, value);  

	
//for (i = 0; i < Dsync1.length; i++)
 //       Dsync1[i].showControl(value - 1 == i);

if(value == 2)
  {

  //  deldiv1.showControl(1);           
            
   }
   else
   {
//	deldiv1.showControl(0);
	}

         
};

Content.getComponent("DelMode1").setControlCallback(onDelMode1Control);

