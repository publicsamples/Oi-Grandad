const var XfModControls1 = Content.getComponent("XfModControls1");

const var StackItem1 = [Content.getComponent("PosIndicator2"),
                        Content.getComponent("PosIndicator3"),
                        Content.getComponent("PosIndicator4")];
                        
const var VoiceParam1 = Content.getComponent("VoiceParam1");
const var VoiceParamB1 = Content.getComponent("VoiceParamB1");

inline function onStgSel1Control(component, value)
{

if(value == 0)
  {

  	VoiceParam1.showControl(1);
  	VoiceParamB1.showControl(0);
             
        gran.setAttribute(gran.scrubMode, 1);  
      
       for(s in StackItem1)
            s.showControl(0);
                   
	}
	
if(value == 1)
  {
	VoiceParam1.showControl(0);
	VoiceParamB1.showControl(1);
	  	
	  	
          gran.setAttribute(gran.scrubMode, 2);  

              for(s in StackItem1)
                  s.showControl(1);
              
	}
	

};

Content.getComponent("StgSel1").setControlCallback(onStgSel1Control);

///Position Macros

const var pos = Content.getComponent("pos");
const var posmod = Content.getComponent("posmod");
const var pos1modsel = Content.getComponent("pos1modsel");
const var MultPosA1 = Content.getComponent("MultPosA1");
const var MacroPos1 = Content.getComponent("MacroPos1");
const var PosHeadModA1 = Content.getComponent("PosHeadModA1");
const var PosHeadSrcA1 = Content.getComponent("PosHeadSrcA1");

inline function onMultPosA1Control(component, value)
{
	pos.setValue(value);
	MacroPos1.setValue(value);
	pos.changed();
};

Content.getComponent("MultPosA1").setControlCallback(onMultPosA1Control);


inline function onposControl(component, value)
{
	 gran.setAttribute(gran.Position, value); 
	 MultPosA1.setValue(value);
	 MacroPos1.setValue(value);
};

Content.getComponent("pos").setControlCallback(onposControl);

inline function onMacroPos1Control(component, value)
{
	pos.setValue(value);
	pos.changed();
	MultPosA1.setValue(value);
	
};

Content.getComponent("MacroPos1").setControlCallback(onMacroPos1Control);



inline function onposmodControl(component, value)
{
	gran.setAttribute(gran.PositionMod, value); 
	PosHeadModA1.setValue(value);
};

Content.getComponent("posmod").setControlCallback(onposmodControl);

inline function onPosHeadModA1Control(component, value)
{
	posmod.setValue(value);
	posmod.changed();
};

Content.getComponent("PosHeadModA1").setControlCallback(onPosHeadModA1Control);


inline function onpos1modselControl(component, value)
{
	gran.setAttribute(gran.PositionSrc, value); 
	PosHeadSrcA1.setValue(value);
};

Content.getComponent("pos1modsel").setControlCallback(onpos1modselControl);


inline function onPosHeadSrcA1Control(component, value)
{
	pos1modsel.setValue(value);
	pos1modsel.changed();
};

Content.getComponent("PosHeadSrcA1").setControlCallback(onPosHeadSrcA1Control);

const var DenseLabel1 = Content.getComponent("DenseLabel1");
const var DenseLabelB1 = Content.getComponent("DenseLabelB1");



inline function onGrainXf1Control(component, value)
{
	gran.setAttribute(gran.scrubBlen, value); 
	
	if(value == 0)
	  {
	DenseLabel1.showControl(1);
	DenseLabelB1.showControl(0);
	}

	if(value == 1)
		  {
		DenseLabel1.showControl(0);
		DenseLabelB1.showControl(1);
		}
};

Content.getComponent("GrainXf1").setControlCallback(onGrainXf1Control);





const var pitchCont1 = Content.getComponent("pitch");

inline function onpitchoffset1Control(component, value)
{
		pitchCont1.setValue(value);
		pitchCont1.changed();
};

Content.getComponent("pitchoffset1").setControlCallback(onpitchoffset1Control);

const var graindiv1 = Content.getComponent("graindiv1");
const var graintempo1 = Content.getComponent("graintempo1");
const var grainsize1 = Content.getComponent("grainsize1");





inline function onGrainSync1Control(component, value)
{
	graindiv1.showControl(value);
	graintempo1.showControl(value);
	grainsize1.showControl(value-1);
	
	gran.setAttribute(gran.GrainSync, value);
};

Content.getComponent("GrainSync1").setControlCallback(onGrainSync1Control);

const var maxGrains1 = Content.getComponent("maxGrains1");

inline function onmaxGrains1Control(component, value)
{
if(value == 1)
	  {
	 gran.setAttribute(gran.MaxGrains, 2);
	 }
	 
	 if(value == 2)
	 	  {
	 	 gran.setAttribute(gran.MaxGrains, 4);
	 	 }
	 	 
	 	 if(value == 3)
	 	 	  {
	 	 	 gran.setAttribute(gran.MaxGrains, 8);
	 	 	 }
};

Content.getComponent("maxGrains1").setControlCallback(onmaxGrains1Control);

