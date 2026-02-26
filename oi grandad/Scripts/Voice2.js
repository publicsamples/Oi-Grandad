const var StackItem2 = [Content.getComponent("PosIndicator6"),
                        Content.getComponent("PosIndicator7"),
                        Content.getComponent("PosIndicator8")];
                        
const var VoiceParam2 = Content.getComponent("VoiceParam7");
const var VoiceParamB2 = Content.getComponent("VoiceParamB2");

  

inline function onStgSel2Control(component, value)
{

if(value == 0)
  {

  	VoiceParam2.showControl(1);
  	VoiceParamB2.showControl(0);
             
        gran1.setAttribute(gran1.scrubMode, 1);  
       // gran1.setAttribute(gran1.PositionModMode, 0);

      

       for(s in StackItem2)
            s.showControl(0);
                   
	}
	
if(value == 1)
  {
	VoiceParam2.showControl(0);
	VoiceParamB2.showControl(1);
	  	
	  	
          gran1.setAttribute(gran1.scrubMode, 2);  

              for(s in StackItem2)
                  s.showControl(1);
              
	}
	

};

Content.getComponent("StgSel2").setControlCallback(onStgSel2Control);

///Position Macros

const var pos1 = Content.getComponent("pos1");
const var posmod1 = Content.getComponent("posmod1");
const var pos1modsel1 = Content.getComponent("pos1modsel1");
const var MultPosA2 = Content.getComponent("MultPosA2");
const var MacroPos2 = Content.getComponent("MacroPos2");
const var PosHeadModA2 = Content.getComponent("PosHeadModA2");
const var PosHeadSrcA2 = Content.getComponent("PosHeadSrcA2");

inline function onMultPosA2Control(component, value)
{
	pos1.setValue(value);
	MacroPos2.setValue(value);
	pos1.changed();
};

Content.getComponent("MultPosA2").setControlCallback(onMultPosA2Control);


inline function onpos1Control(component, value)
{
	 gran1.setAttribute(gran1.Position, value); 
	 MultPosA2.setValue(value);
	 MacroPos2.setValue(value);
};

Content.getComponent("pos1").setControlCallback(onpos1Control);

inline function onMacroPos2Control(component, value)
{
	pos1.setValue(value);
	pos1.changed();
	MultPosA2.setValue(value);
	
};

Content.getComponent("MacroPos2").setControlCallback(onMacroPos2Control);



inline function onposmod1Control(component, value)
{
	gran1.setAttribute(gran1.PositionMod, value); 
	PosHeadModA2.setValue(value);
};

Content.getComponent("posmod1").setControlCallback(onposmod1Control);

inline function onPosHeadModA2Control(component, value)
{
	posmod1.setValue(value);
	posmod1.changed();
};

Content.getComponent("PosHeadModA2").setControlCallback(onPosHeadModA2Control);


inline function onpos1modsel1Control(component, value)
{
	gran1.setAttribute(gran1.PositionSrc, value); 
	PosHeadSrcA2.setValue(value);
};

Content.getComponent("pos1modsel1").setControlCallback(onpos1modsel1Control);


inline function onPosHeadSrcA2Control(component, value)
{
	pos1modsel1.setValue(value);
	pos1modsel1.changed();
};

Content.getComponent("PosHeadSrcA2").setControlCallback(onPosHeadSrcA2Control);

const var DenseLabel2 = Content.getComponent("DenseLabel2");
const var DenseLabelB2 = Content.getComponent("DenseLabelB2");



inline function onGrainXf2Control(component, value)
{
	gran1.setAttribute(gran1.scrubBlen, value); 
	
	if(value == 0)
	  {
	DenseLabel2.showControl(1);
	DenseLabelB2.showControl(0);
	}

	if(value == 1)
		  {
		DenseLabel2.showControl(0);
		DenseLabelB2.showControl(1);
		}
};

Content.getComponent("GrainXf2").setControlCallback(onGrainXf2Control);


const var graindiv2 = Content.getComponent("graindiv2");
const var graintempo2 = Content.getComponent("graintempo2");
const var grainsize2 = Content.getComponent("grainsize2");

inline function onGrainSync2Control(component, value)
{
	graindiv2.showControl(value);
	graintempo2.showControl(value);
	grainsize2.showControl(value-1);
	
	gran1.setAttribute(gran1.GrainSync, value);
};

Content.getComponent("GrainSync2").setControlCallback(onGrainSync2Control);

const var maxGrains2 = Content.getComponent("maxGrains2");

inline function onmaxGrains2Control(component, value)
{
if(value == 1)
	  {
	 gran1.setAttribute(gran1.MaxGrains, 2);
	 }
	 
	 if(value == 2)
	 	  {
	 	 gran1.setAttribute(gran1.MaxGrains, 4);
	 	 }
	 	 
	 	 if(value == 3)
	 	 	  {
	 	 	 gran1.setAttribute(gran1.MaxGrains, 8);
	 	 	 }
};

Content.getComponent("maxGrains2").setControlCallback(onmaxGrains2Control);


