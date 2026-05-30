const var StackItem4 = [Content.getComponent("PosIndicator14"),
                        Content.getComponent("PosIndicator15"),
                        Content.getComponent("PosIndicator16")];
                        
const var VoiceParam4 = Content.getComponent("PosParam4");
const var VoiceParamB4 = Content.getComponent("PosParamB4");

  

inline function onStgSel4Control(component, value)
{
	



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
	

	pos3.setValue(value);
	MacroPos4.setValue(value);
	pos3.changed();
};

Content.getComponent("MultPosA4").setControlCallback(onMultPosA4Control);


inline function onpos3Control(component, value)
{
	

	 gran3.setAttribute(gran3.Position, value); 
	 MultPosA4.setValue(value);
	 MacroPos4.setValue(value);
};

Content.getComponent("pos3").setControlCallback(onpos3Control);

inline function onMacroPos4Control(component, value)
{
	

	pos3.setValue(value);
	pos3.changed();
	MultPosA4.setValue(value);
	
};

Content.getComponent("MacroPos4").setControlCallback(onMacroPos4Control);



inline function onposmod3Control(component, value)
{
	

	gran3.setAttribute(gran3.PositionMod, value); 
	PosHeadModA4.setValue(value);
};

Content.getComponent("posmod3").setControlCallback(onposmod3Control);

inline function onPosHeadModA4Control(component, value)
{
	

	posmod3.setValue(value);
	posmod3.changed();
};

Content.getComponent("PosHeadModA4").setControlCallback(onPosHeadModA4Control);


inline function onpos1modsel3Control(component, value)
{
	

	gran3.setAttribute(gran3.PositionSrc, value); 
	PosHeadSrcA4.setValue(value);
};

Content.getComponent("pos1modsel3").setControlCallback(onpos1modsel3Control);


inline function onPosHeadSrcA4Control(component, value)
{
	

	pos1modsel3.setValue(value);
	pos1modsel3.changed();
};

Content.getComponent("PosHeadSrcA4").setControlCallback(onPosHeadSrcA4Control);

const var DenseLabel4 = Content.getComponent("DenseLabel4");
const var DenseLabelB4 = Content.getComponent("DenseLabelB4");



inline function onGrainXf4Control(component, value)
{
	

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
	

	graindiv4.showControl(value);
	graintempo4.showControl(value);
	grainsize4.showControl(value-1);
	
	gran3.setAttribute(gran3.GrainSync, value);
};

Content.getComponent("GrainSync4").setControlCallback(onGrainSync4Control);

const var maxGrains4 = Content.getComponent("maxGrains4");

inline function onmaxGrains4Control(component, value)
{
	

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

// RANDOM
const var pos3 = Content.getComponent("pos3");
const var MultPosA4 = Content.getComponent("MultPosA4");
const var MultPosB4 = Content.getComponent("MultPosB4");
const var MultPosC4 = Content.getComponent("MultPosC4");
const var MultPosD4 = Content.getComponent("MultPosD4");
const var MacroPos4 = Content.getComponent("MacroPos4");

const var pitchCont4 = Content.getComponent("pitch3");
const var det3 = Content.getComponent("det3");
const var spreadCont4 = Content.getComponent("spread3");
const var graintempo4 = Content.getComponent("graintempo4");
const var grainsize4 = Content.getComponent("grainsize4");
const var WindowTempo4 = Content.getComponent("WindowTempo4");
const var Jitter4 = Content.getComponent("Jitter4");
const var Dense4 = Content.getComponent("Dense4");
const var DelayTime4 = Content.getComponent("DelayTime4");
const var delcut4 = Content.getComponent("delcut4");
const var PostMeta10 = Content.getComponent("PostMeta10");
const var PostMeta11 = Content.getComponent("PostMeta11");
const var PostMeta12 = Content.getComponent("PostMeta12");

const var RandLockD = [];
const var RandMinD = [];
const var RandMaxD = [];

for (i = 0; i < 17; i++)
{
    RandLockD[i] = Content.getComponent("RandLock" + (i + 52));
    RandMinD[i] = Content.getComponent("RandMin" + (i + 52));
    RandMaxD[i] = Content.getComponent("RandMax" + (i + 52));
}

inline function randRangeD(min, max)
{
    return min + Math.random() * (max - min);
}

inline function randomiseIfUnlockedD(lockIndex, target)
{
    if (RandLockD[lockIndex].getValue() == 0)
    {
        target.setValue(randRangeD(
            RandMinD[lockIndex].getValue(),
            RandMaxD[lockIndex].getValue()
        ));
        target.changed();
    }
}

inline function onRANDOMISE4Control(component, value)
{
    if (value != 1)
        return;

    // Position group
    if (RandLockD[0].getValue() == 0)
    {
        local v = randRangeD(RandMinD[0].getValue(), RandMaxD[0].getValue());

        pos3.setValue(v);
        MultPosA4.setValue(v);
        MacroPos4.setValue(v);

        pos3.changed();
        MultPosA4.changed();
       // MacroPos4.changed();
    }

    randomiseIfUnlockedD(1, MultPosB4);
    randomiseIfUnlockedD(2, MultPosC4);
    randomiseIfUnlockedD(3, MultPosD4);
    randomiseIfUnlockedD(4, pitchCont4);
    randomiseIfUnlockedD(5, det3);
    randomiseIfUnlockedD(6, spreadCont4);
    randomiseIfUnlockedD(7, grainsize4);
    randomiseIfUnlockedD(8, graintempo4);
    randomiseIfUnlockedD(9, WindowTempo4);
    randomiseIfUnlockedD(10, Jitter4);
    randomiseIfUnlockedD(11, Dense4);
    randomiseIfUnlockedD(12, DelayTime4);
    randomiseIfUnlockedD(13, delcut3);
    randomiseIfUnlockedD(14, PostMeta10);
    randomiseIfUnlockedD(15, PostMeta11);
    randomiseIfUnlockedD(16, PostMeta12);
}

Content.getComponent("RANDOMISE4").setControlCallback(onRANDOMISE4Control);

const var RandomControls4 = Content.getComponent("RandomControls4");


inline function onShowRandom4Control(component, value)
{
	RandomControls4.showControl(value);
};

Content.getComponent("ShowRandom4").setControlCallback(onShowRandom4Control);


//FX MENUS

const var FxLabelA7 = Content.getComponent("FxLabelA7");
const var FxLabelA8 = Content.getComponent("FxLabelA8");

inline function onResMode4Control(component, value)
{

	if(value == 1)
	{
	 gran3.setAttribute(gran3.delMode, 1);
	 FxLabelA7.setValue("OFF");
	 FxLabelA8.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  gran3.setAttribute(gran3.delMode, 2);
	  FxLabelA7.setValue("CUT");
	  FxLabelA8.setValue("Q");
	  }
	  if(value == 3)
	  {
	   gran3.setAttribute(gran3.delMode, 4);
	   FxLabelA7.setValue("CUT");
	   FxLabelA8.setValue("Q");
	   }
	   if(value == 4)
	   {
	    gran3.setAttribute(gran3.delMode, 4);
	    FxLabelA7.setValue("CUT");
	    FxLabelA8.setValue("Q");
	    }	
		if(value == 5)
	   {
	    gran3.setAttribute(gran3.delMode, 5);
	      FxLabelA7.setValue("CUT");
	    FxLabelA8.setValue("Q");
	    }
	    if(value == 6)
	       {
	        gran3.setAttribute(gran3.delMode, 6);
	          FxLabelA7.setValue("FREQ");
	    FxLabelA8.setValue("Q");
	        }
	    if(value == 7)
	       {
	        gran3.setAttribute(gran3.delMode, 7);
	          FxLabelA7.setValue("TRASH");
	    FxLabelA8.setValue("LP");
	        } 
	   if(value == 8)
	      {
	       gran3.setAttribute(gran3.delMode, 8);
	       FxLabelA7.setValue("Pitch");
	       FxLabelA8.setValue("LP");
	       }  
	   if(value == 9)
	   	      {
	   	       gran3.setAttribute(gran3.delMode, 9);
	   	       FxLabelA7.setValue("Pitch");
	       FxLabelA8.setValue("LP");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       gran3.setAttribute(gran3.delMode, 10);
	   	 	       FxLabelA7.setValue("Bit");
	   	 	       FxLabelA8.setValue("S&H");
	   	 	       }                                
	        
};

Content.getComponent("ResMode4").setControlCallback(onResMode4Control);

const var FxLabelB10 = Content.getComponent("FxLabelB10");
const var FxLabelB11 = Content.getComponent("FxLabelB11");
const var FxLabelB12 = Content.getComponent("FxLabelB12");

const var Final4 = Synth.getEffect("Final4");

inline function onPostMode4Control(component, value)
{
		if(value == 1)
	{
	 Final4.setAttribute(Final4.delMode, 1);
	 FxLabelB10.setValue("OFF");
	 FxLabelB11.setValue("OFF");
	 FxLabelB12.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  Final4.setAttribute(Final4.delMode, 2);
	  FxLabelB10.setValue("LP");
	  FxLabelB11.setValue("Q");
	  FxLabelB12.setValue("HP");
	  }
	  if(value == 4)
	  {
	   Final4.setAttribute(Final4.delMode, 4);
	   FxLabelB10.setValue("HP");
	   FxLabelB11.setValue("Q");
	   FxLabelB12.setValue("LP");
	   }
	   if(value == 4)
	   {
	    Final4.setAttribute(Final4.delMode, 4);
	    FxLabelB10.setValue("BP");
	    FxLabelB11.setValue("Q");
	    FxLabelB12.setValue("LP");
	    }	
		if(value == 5)
	   {
	    Final4.setAttribute(Final4.delMode, 5);
	      FxLabelB10.setValue("BP");
	    FxLabelB11.setValue("Q");
	    FxLabelB12.setValue("HP");
	    }
	    if(value == 6)
	       {
	        Final4.setAttribute(Final4.delMode, 6);
	          FxLabelB10.setValue("CUT");
	    FxLabelB11.setValue("Q");
	    FxLabelB12.setValue("GAIN");
	        }
	    if(value == 7)
	       {
	        Final4.setAttribute(Final4.delMode, 7);
	          FxLabelB10.setValue("CUT");
	    FxLabelB11.setValue("Q");
	    FxLabelB12.setValue("GAIN");
	        } 
	   if(value == 8)
	      {
	       Final4.setAttribute(Final4.delMode, 8);
	       FxLabelB10.setValue("AP");
	       FxLabelB11.setValue("Q");
	       FxLabelB12.setValue("HP");
	       }  
	   if(value == 9)
	   	      {
	   	       Final4.setAttribute(Final4.delMode, 9);
	   	       FxLabelB10.setValue("Time");
	       FxLabelB11.setValue("LP");
	       FxLabelB12.setValue("FEED");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       Final4.setAttribute(Final4.delMode, 10);
	   	 	       FxLabelB10.setValue("DELAY");
	   	 	       FxLabelB11.setValue("LP");
	   	 	       FxLabelB12.setValue("FEED");
	   	 	       }                                
	     if(value == 11)
	     	   	 	      {
	     	   	 	       Final4.setAttribute(Final4.delMode, 11);
	     	   	 	       FxLabelB10.setValue("SPACE");
	     	   	 	       FxLabelB11.setValue("DAMP");
	     	   	 	       FxLabelB12.setValue("WIDTH");
	     	   	 	       }         

};

Content.getComponent("PostMode4").setControlCallback(onPostMode4Control);




