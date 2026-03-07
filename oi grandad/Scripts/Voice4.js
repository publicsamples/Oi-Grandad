const var StackItem4 = [Content.getComponent("PosIndicator14"),
                        Content.getComponent("PosIndicator15"),
                        Content.getComponent("PosIndicator16")];
                        
const var VoiceParam4 = Content.getComponent("PosParam4");
const var VoiceParamB4 = Content.getComponent("PosParamB4");

  

inline function onStgSel4Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;



if(value == 1)
  {

  	VoiceParam4.showControl(1);
  	VoiceParamB4.showControl(0);
             
        gran3.setAttribute(gran3.scrubMode, 1);  
       // gran3.setAttribute(gran3.PositionModMode, 0);

      

       for(s in StackItem4)
            s.showControl(0);
                   
	}
	
if(value == 2)
  {
	VoiceParam4.showControl(0);
	VoiceParamB4.showControl(1);
	  	
	  	
          gran3.setAttribute(gran3.scrubMode, 2);  

              for(s in StackItem4)
                  s.showControl(1);
              
	}
if(value == 3)
  {

  	VoiceParam4.showControl(1);
  	VoiceParamB4.showControl(0);
             
        gran3.setAttribute(gran3.scrubMode, 3);  
       // gran3.setAttribute(gran3.PositionModMode, 0);

      

       for(s in StackItem4)
            s.showControl(0);
                   
	}
	
if(value == 4)
  {
	VoiceParam4.showControl(0);
	VoiceParamB4.showControl(1);
	  	
	  	
          gran3.setAttribute(gran3.scrubMode, 4);  

              for(s in StackItem4)
                  s.showControl(1);
              
	}	

};

Content.getComponent("StgSel4").setControlCallback(onStgSel4Control);

///Position Macros

const var pos3 = Content.getComponent("pos3");
const var posmod3 = Content.getComponent("posmod3");
const var pos1modsel3 = Content.getComponent("pos1modsel3");
const var MultPosA4 = Content.getComponent("MultPosA4");
const var MacroPos4 = Content.getComponent("MacroPos4");
const var PosHeadModA4 = Content.getComponent("PosHeadModA4");
const var PosHeadSrcA4 = Content.getComponent("PosHeadSrcA4");

inline function onMultPosA4Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;

	pos3.setValue(value);
	MacroPos4.setValue(value);
	pos3.changed();
};

Content.getComponent("MultPosA4").setControlCallback(onMultPosA4Control);


inline function onpos3Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;

	 gran3.setAttribute(gran3.Position, value); 
	 MultPosA4.setValue(value);
	 MacroPos4.setValue(value);
};

Content.getComponent("pos3").setControlCallback(onpos3Control);

inline function onMacroPos4Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;

	pos3.setValue(value);
	pos3.changed();
	MultPosA4.setValue(value);
	
};

Content.getComponent("MacroPos4").setControlCallback(onMacroPos4Control);



inline function onposmod3Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;

	gran3.setAttribute(gran3.PositionMod, value); 
	PosHeadModA4.setValue(value);
};

Content.getComponent("posmod3").setControlCallback(onposmod3Control);

inline function onPosHeadModA4Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;

	posmod3.setValue(value);
	posmod3.changed();
};

Content.getComponent("PosHeadModA4").setControlCallback(onPosHeadModA4Control);


inline function onpos1modsel3Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;

	gran3.setAttribute(gran3.PositionSrc, value); 
	PosHeadSrcA4.setValue(value);
};

Content.getComponent("pos1modsel3").setControlCallback(onpos1modsel3Control);


inline function onPosHeadSrcA4Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;

	pos1modsel3.setValue(value);
	pos1modsel3.changed();
};

Content.getComponent("PosHeadSrcA4").setControlCallback(onPosHeadSrcA4Control);

const var DenseLabel4 = Content.getComponent("DenseLabel4");
const var DenseLabelB4 = Content.getComponent("DenseLabelB4");



inline function onGrainXf4Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;

	gran3.setAttribute(gran3.scrubBlen, value); 
	
	if(value == 0)
	  {
	DenseLabel4.showControl(1);
	DenseLabelB4.showControl(0);
	}

	if(value == 1)
		  {
		DenseLabel4.showControl(0);
		DenseLabelB4.showControl(1);
		}
};

Content.getComponent("GrainXf4").setControlCallback(onGrainXf4Control);


const var graindiv4 = Content.getComponent("graindiv4");
const var graintempo4 = Content.getComponent("graintempo4");
const var grainsize4 = Content.getComponent("grainsize4");

inline function onGrainSync4Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;

	graindiv4.showControl(value);
	graintempo4.showControl(value);
	grainsize4.showControl(value-1);
	
	gran3.setAttribute(gran3.GrainSync, value);
};

Content.getComponent("GrainSync4").setControlCallback(onGrainSync4Control);

const var maxGrains4 = Content.getComponent("maxGrains4");

inline function onmaxGrains4Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;

if(value == 1)
	  {
	 gran3.setAttribute(gran3.MaxGrains, 4);
	 }
	 
	 if(value == 2)
	 	  {
	 	 gran3.setAttribute(gran3.MaxGrains, 8);
	 	 }
	 	 
	 	 if(value == 3)
	 	 	  {
	 	 	 gran3.setAttribute(gran3.MaxGrains, 16);
	 	 	 }
	 	 	 
	 	 if(value == 4)
	 	 	 	  {
	 	 	 	 gran3.setAttribute(gran3.MaxGrains, 32);
	 	 	 	 }	 
	 	 
};


Content.getComponent("maxGrains4").setControlCallback(onmaxGrains4Control);

const var DivLabel3 = Content.getComponent("DivLabel3");
const var PitchDiv4 = Content.getComponent("PitchDiv4");
const var DetuneLabel3 = Content.getComponent("DetuneLabel3");
const var PitchTempo4 = Content.getComponent("PitchTempo4");
const var det3 = Content.getComponent("det3");

inline function onPitchMode4Control(component, value)
{
	if (isDefined(g_isPresetLoadInProgress) && g_isPresetLoadInProgress)
		return;

	if(value == 1)
	  {
	 gran3.setAttribute(gran3.PitchMode, 1);
	 DivLabel3.showControl(0);
	 PitchDiv4.showControl(0);
	 PitchTempo4.showControl(0);;
	 det3.showControl(1);
	 DetuneLabel3.setValue("DETUNE");
	 }
	 
	 if(value == 2)
	 	  {
	 	 gran3.setAttribute(gran3.PitchMode, 2);
	 	 DivLabel3.showControl(0);
	 	 	 PitchDiv4.showControl(0);
	 	 	 PitchTempo4.showControl(0);;
	 	 	 det3.showControl(1);
	 	 	 DetuneLabel3.setValue("HARM.");
	 	 }
	 	 
	 if(value == 3)
	 	  {
	 	 gran3.setAttribute(gran3.PitchMode, 3);
	 	 DivLabel3.showControl(1);
	 	 PitchDiv4.showControl(1);
	 	 PitchTempo4.showControl(1);;
	 	 det3.showControl(0);
	 	 DetuneLabel3.setValue("TEMPO");
	 	 }	 
	 	 
};

Content.getComponent("PitchMode4").setControlCallback(onPitchMode4Control);

