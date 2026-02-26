const var StackItem3 = [Content.getComponent("PosIndicator10"),
                        Content.getComponent("PosIndicator11"),
                        Content.getComponent("PosIndicator12")];
                        
const var VoiceParam3 = Content.getComponent("VoiceParam28");
const var VoiceParamB3 = Content.getComponent("VoiceParamB3");

  

inline function onStgSel3Control(component, value)
{

if(value == 0)
  {

  	VoiceParam3.showControl(1);
  	VoiceParamB3.showControl(0);
             
        gran2.setAttribute(gran2.scrubMode, 1);  
       // gran2.setAttribute(gran2.PositionModMode, 0);

      

       for(s in StackItem3)
            s.showControl(0);
                   
	}
	
if(value == 1)
  {
	VoiceParam3.showControl(0);
	VoiceParamB3.showControl(1);
	  	
	  	
          gran2.setAttribute(gran2.scrubMode, 2);  

              for(s in StackItem3)
                  s.showControl(1);
              
	}
	

};

Content.getComponent("StgSel3").setControlCallback(onStgSel3Control);

///Position Macros

const var pos2 = Content.getComponent("pos2");
const var posmod2 = Content.getComponent("posmod2");
const var pos1modsel2 = Content.getComponent("pos1modsel2");
const var MultPosA3 = Content.getComponent("MultPosA3");
const var MacroPos3 = Content.getComponent("MacroPos3");
const var PosHeadModA3 = Content.getComponent("PosHeadModA3");
const var PosHeadSrcA3 = Content.getComponent("PosHeadSrcA3");

inline function onMultPosA3Control(component, value)
{
	pos2.setValue(value);
	MacroPos3.setValue(value);
	pos2.changed();
};

Content.getComponent("MultPosA3").setControlCallback(onMultPosA3Control);


inline function onpos2Control(component, value)
{
	 gran2.setAttribute(gran2.Position, value); 
	 MultPosA3.setValue(value);
	 MacroPos3.setValue(value);
};

Content.getComponent("pos2").setControlCallback(onpos2Control);

inline function onMacroPos3Control(component, value)
{
	pos2.setValue(value);
	pos2.changed();
	MultPosA3.setValue(value);
	
};

Content.getComponent("MacroPos3").setControlCallback(onMacroPos3Control);



inline function onposmod2Control(component, value)
{
	gran2.setAttribute(gran2.PositionMod, value); 
	PosHeadModA3.setValue(value);
};

Content.getComponent("posmod2").setControlCallback(onposmod2Control);

inline function onPosHeadModA3Control(component, value)
{
	posmod2.setValue(value);
	posmod2.changed();
};

Content.getComponent("PosHeadModA3").setControlCallback(onPosHeadModA3Control);


inline function onpos1modsel2Control(component, value)
{
	gran2.setAttribute(gran2.PositionSrc, value); 
	PosHeadSrcA3.setValue(value);
};

Content.getComponent("pos1modsel2").setControlCallback(onpos1modsel2Control);


inline function onPosHeadSrcA3Control(component, value)
{
	pos1modsel2.setValue(value);
	pos1modsel2.changed();
};

Content.getComponent("PosHeadSrcA3").setControlCallback(onPosHeadSrcA3Control);

const var DenseLabel3 = Content.getComponent("DenseLabel3");
const var DenseLabelB3 = Content.getComponent("DenseLabelB3");



inline function onGrainXf3Control(component, value)
{
	gran2.setAttribute(gran2.scrubBlen, value); 
	
	if(value == 0)
	  {
	DenseLabel3.showControl(1);
	DenseLabelB3.showControl(0);
	}

	if(value == 1)
		  {
		DenseLabel3.showControl(0);
		DenseLabelB3.showControl(1);
		}
};

Content.getComponent("GrainXf3").setControlCallback(onGrainXf3Control);


const var graindiv3 = Content.getComponent("graindiv3");
const var graintempo3 = Content.getComponent("graintempo3");
const var grainsize3 = Content.getComponent("grainsize3");

inline function onGrainSync3Control(component, value)
{
	graindiv3.showControl(value);
	graintempo3.showControl(value);
	grainsize3.showControl(value-1);
	
	gran2.setAttribute(gran2.GrainSync, value);
};

Content.getComponent("GrainSync3").setControlCallback(onGrainSync3Control);

const var maxGrains3 = Content.getComponent("maxGrains3");

inline function onmaxGrains3Control(component, value)
{
if(value == 1)
	  {
	 gran2.setAttribute(gran2.MaxGrains, 2);
	 }
	 
	 if(value == 2)
	 	  {
	 	 gran2.setAttribute(gran2.MaxGrains, 4);
	 	 }
	 	 
	 	 if(value == 3)
	 	 	  {
	 	 	 gran2.setAttribute(gran2.MaxGrains, 8);
	 	 	 }
};

Content.getComponent("maxGrains3").setControlCallback(onmaxGrains3Control);


