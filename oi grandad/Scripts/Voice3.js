const var StackItem3 = [Content.getComponent("PosIndicator10"),
                        Content.getComponent("PosIndicator11"),
                        Content.getComponent("PosIndicator12")];
                        
const var VoiceParam3 = Content.getComponent("PosParam3");
const var VoiceParamB3 = Content.getComponent("PosParamB3");

  

inline function onStgSel3Control(component, value)
{
	


if(value == 1)
  {

  	VoiceParam3.showControl(1);
  	VoiceParamB3.showControl(0);
             
        gran2.setAttribute(gran2.scrubMode, 1);  
       // gran2.setAttribute(gran2.PositionModMode, 0);

      

       for(s in StackItem3)
            s.showControl(0);
                   
	}
	
if(value == 2)
  {
	VoiceParam3.showControl(0);
	VoiceParamB3.showControl(1);
	  	
	  	
          gran2.setAttribute(gran2.scrubMode, 2);  

              for(s in StackItem3)
                  s.showControl(1);
              
	}
	
	if(value == 3)
	  {
	
	  	VoiceParam3.showControl(1);
	  	VoiceParamB3.showControl(0);
	             
	        gran2.setAttribute(gran2.scrubMode, 3);  
	       // gran2.setAttribute(gran2.PositionModMode, 0);
	
	      
	
	       for(s in StackItem3)
	            s.showControl(0);
	                   
		}
		
	if(value == 4)
	  {
		VoiceParam3.showControl(0);
		VoiceParamB3.showControl(1);
		  	
		  	
	          gran2.setAttribute(gran2.scrubMode, 4);  
	
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
	 gran2.setAttribute(gran2.MaxGrains, 4);
	 }
	 
	 if(value == 2)
	 	  {
	 	 gran2.setAttribute(gran2.MaxGrains, 8);
	 	 }
	 	 
	 	 if(value == 3)
	 	 	  {
	 	 	 gran2.setAttribute(gran2.MaxGrains, 16);
	 	 	 }
	 	 	 
	 	 	 if(value == 4)
	 	 	 	 	 	  {
	 	 	 	 	 	 gran2.setAttribute(gran2.MaxGrains, 32);
	 	 	 	 	 	 }
	 	  	 
	 	 
};

Content.getComponent("maxGrains3").setControlCallback(onmaxGrains3Control);


const var DivLabel2 = Content.getComponent("DivLabel2");
const var PitchDiv3 = Content.getComponent("PitchDiv3");
const var DetuneLabel2 = Content.getComponent("DetuneLabel2");
const var PitchTempo3 = Content.getComponent("PitchTempo3");
const var det2 = Content.getComponent("det2");

inline function onPitchMode3Control(component, value)
{
	

	if(value == 1)
	  {
	 gran2.setAttribute(gran2.PitchMode, 1);
	 DivLabel2.showControl(0);
	 PitchDiv3.showControl(0);
	 PitchTempo3.showControl(0);;
	 det2.showControl(1);
	 DetuneLabel2.setValue("DETUNE");
	 }
	 
	 if(value == 2)
	 	  {
	 	 gran2.setAttribute(gran2.PitchMode, 2);
	 	 DivLabel2.showControl(0);
	 	 	 PitchDiv3.showControl(0);
	 	 	 PitchTempo3.showControl(0);;
	 	 	 det2.showControl(1);
	 	 	 DetuneLabel2.setValue("HARM.");
	 	 }
	 	 
	 if(value == 3)
	 	  {
	 	 gran2.setAttribute(gran2.PitchMode, 3);
	 	 DivLabel2.showControl(1);
	 	 PitchDiv3.showControl(1);
	 	 PitchTempo3.showControl(1);;
	 	 det2.showControl(0);
	 	 DetuneLabel2.setValue("TEMPO");
	 	 }	
	 	 
	 	  
	 	 
};

Content.getComponent("PitchMode3").setControlCallback(onPitchMode3Control);

// RANDOM
const var pos2 = Content.getComponent("pos2");
const var MultPosA3 = Content.getComponent("MultPosA3");
const var MultPosB3 = Content.getComponent("MultPosB3");
const var MultPosC3 = Content.getComponent("MultPosC3");
const var MultPosD3 = Content.getComponent("MultPosD3");
const var MacroPos3 = Content.getComponent("MacroPos3");

const var pitchCont3 = Content.getComponent("pitch2");
const var det2 = Content.getComponent("det2");
const var spreadCont3 = Content.getComponent("spread2");
const var graintempo3 = Content.getComponent("graintempo3");
const var grainsize3 = Content.getComponent("grainsize3");
const var WindowTempo3 = Content.getComponent("WindowTempo3");
const var Jitter3 = Content.getComponent("Jitter3");
const var Dense3 = Content.getComponent("Dense3");
const var DelayTime3 = Content.getComponent("DelayTime3");
const var delcut3 = Content.getComponent("delcut3");
const var delmix3 = Content.getComponent("delmix3");
const var PostMeta7 = Content.getComponent("PostMeta7");
const var PostMeta8 = Content.getComponent("PostMeta8");
const var PostMix1 = Content.getComponent("PostMix1");
const var PostMeta9 = Content.getComponent("PostMeta9");

const var RandLockC = [];
const var RandMinC = [];
const var RandMaxC = [];

for (i = 0; i < 17; i++)
{
    RandLockC[i] = Content.getComponent("RandLock" + (i + 35));
    RandMinC[i] = Content.getComponent("RandMin" + (i + 35));
    RandMaxC[i] = Content.getComponent("RandMax" + (i + 35));
}

inline function randRangeC(min, max)
{
    return min + Math.random() * (max - min);
}

inline function randomiseIfUnlockedC(lockIndex, target)
{
    if (RandLockC[lockIndex].getValue() == 0)
    {
        target.setValue(randRangeC(
            RandMinC[lockIndex].getValue(),
            RandMaxC[lockIndex].getValue()
        ));
        target.changed();
    }
}

inline function onRANDOMISE3Control(component, value)
{
    if (value != 1)
        return;

    // Position group
    if (RandLockC[0].getValue() == 0)
    {
        local v = randRangeC(RandMinC[0].getValue(), RandMaxC[0].getValue());

        pos2.setValue(v);
        MultPosA3.setValue(v);
        MacroPos3.setValue(v);

        pos2.changed();
        MultPosA3.changed();
     //   MacroPos3.changed();
    }

    randomiseIfUnlockedC(1, MultPosB3);
    randomiseIfUnlockedC(2, MultPosC3);
    randomiseIfUnlockedC(3, MultPosD3);
    randomiseIfUnlockedC(4, pitchCont3);
    randomiseIfUnlockedC(5, det2);
    randomiseIfUnlockedC(6, spreadCont3);
    randomiseIfUnlockedC(7, grainsize3);
    randomiseIfUnlockedC(8, graintempo3);
    randomiseIfUnlockedC(9, WindowTempo3);
    randomiseIfUnlockedC(10, Jitter3);
    randomiseIfUnlockedC(11, Dense3);
    randomiseIfUnlockedC(12, DelayTime3);
    randomiseIfUnlockedC(13, delcut3);
    randomiseIfUnlockedC(14, PostMeta7);
    randomiseIfUnlockedC(15, PostMeta8);
    randomiseIfUnlockedC(16, PostMeta9);
}

Content.getComponent("RANDOMISE3").setControlCallback(onRANDOMISE3Control);

const var RandomControls3 = Content.getComponent("RandomControls3");


inline function onShowRandom3Control(component, value)
{
	RandomControls3.showControl(value);
};

Content.getComponent("ShowRandom3").setControlCallback(onShowRandom3Control);


//FX MENUS

const var FxLabelA5 = Content.getComponent("FxLabelA5");
const var FxLabelA6 = Content.getComponent("FxLabelA6");

inline function onResMode3Control(component, value)
{

	if(value == 1)
	{
	 gran2.setAttribute(gran2.delMode, 1);
	 FxLabelA5.setValue("OFF");
	 FxLabelA6.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  gran2.setAttribute(gran2.delMode, 2);
	  FxLabelA5.setValue("CUT");
	  FxLabelA6.setValue("Q");
	  }
	  if(value == 3)
	  {
	   gran2.setAttribute(gran2.delMode, 3);
	   FxLabelA5.setValue("CUT");
	   FxLabelA6.setValue("Q");
	   }
	   if(value == 4)
	   {
	    gran2.setAttribute(gran2.delMode, 4);
	    FxLabelA5.setValue("CUT");
	    FxLabelA6.setValue("Q");
	    }	
		if(value == 5)
	   {
	    gran2.setAttribute(gran2.delMode, 5);
	      FxLabelA5.setValue("CUT");
	    FxLabelA6.setValue("Q");
	    }
	    if(value == 6)
	       {
	        gran2.setAttribute(gran2.delMode, 6);
	          FxLabelA5.setValue("FREQ");
	    FxLabelA6.setValue("Q");
	        }
	    if(value == 7)
	       {
	        gran2.setAttribute(gran2.delMode, 7);
	          FxLabelA5.setValue("TRASH");
	    FxLabelA6.setValue("LP");
	        } 
	   if(value == 8)
	      {
	       gran2.setAttribute(gran2.delMode, 8);
	       FxLabelA5.setValue("Pitch");
	       FxLabelA6.setValue("LP");
	       }  
	   if(value == 9)
	   	      {
	   	       gran2.setAttribute(gran2.delMode, 9);
	   	       FxLabelA5.setValue("Pitch");
	       FxLabelA6.setValue("LP");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       gran2.setAttribute(gran2.delMode, 10);
	   	 	       FxLabelA5.setValue("Bit");
	   	 	       FxLabelA6.setValue("S&H");
	   	 	       }                                
	        
};

Content.getComponent("ResMode3").setControlCallback(onResMode3Control);

const var FxLabelB7 = Content.getComponent("FxLabelB7");
const var FxLabelB8 = Content.getComponent("FxLabelB8");
const var FxLabelB9 = Content.getComponent("FxLabelB9");

const var Final3 = Synth.getEffect("Final3");

inline function onPostMode3Control(component, value)
{
		if(value == 1)
	{
	 Final3.setAttribute(Final3.delMode, 1);
	 FxLabelB7.setValue("OFF");
	 FxLabelB8.setValue("OFF");
	 FxLabelB9.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  Final3.setAttribute(Final3.delMode, 2);
	  FxLabelB7.setValue("LP");
	  FxLabelB8.setValue("Q");
	  FxLabelB9.setValue("HP");
	  }
	  if(value == 3)
	  {
	   Final3.setAttribute(Final3.delMode, 3);
	   FxLabelB7.setValue("HP");
	   FxLabelB8.setValue("Q");
	   FxLabelB9.setValue("LP");
	   }
	   if(value == 4)
	   {
	    Final3.setAttribute(Final3.delMode, 4);
	    FxLabelB7.setValue("BP");
	    FxLabelB8.setValue("Q");
	    FxLabelB9.setValue("LP");
	    }	
		if(value == 5)
	   {
	    Final3.setAttribute(Final3.delMode, 5);
	      FxLabelB7.setValue("BP");
	    FxLabelB8.setValue("Q");
	    FxLabelB9.setValue("HP");
	    }
	    if(value == 6)
	       {
	        Final3.setAttribute(Final3.delMode, 6);
	          FxLabelB7.setValue("CUT");
	    FxLabelB8.setValue("Q");
	    FxLabelB9.setValue("GAIN");
	        }
	    if(value == 7)
	       {
	        Final3.setAttribute(Final3.delMode, 7);
	          FxLabelB7.setValue("CUT");
	    FxLabelB8.setValue("Q");
	    FxLabelB9.setValue("GAIN");
	        } 
	   if(value == 8)
	      {
	       Final3.setAttribute(Final3.delMode, 8);
	       FxLabelB7.setValue("AP");
	       FxLabelB8.setValue("Q");
	       FxLabelB9.setValue("HP");
	       }  
	   if(value == 9)
	   	      {
	   	       Final3.setAttribute(Final3.delMode, 9);
	   	       FxLabelB7.setValue("Time");
	       FxLabelB8.setValue("LP");
	       FxLabelB9.setValue("FEED");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       Final3.setAttribute(Final3.delMode, 10);
	   	 	       FxLabelB7.setValue("DELAY");
	   	 	       FxLabelB8.setValue("LP");
	   	 	       FxLabelB9.setValue("FEED");
	   	 	       }                                
	     if(value == 11)
	     	   	 	      {
	     	   	 	       Final3.setAttribute(Final3.delMode, 11);
	     	   	 	       FxLabelB7.setValue("SPACE");
	     	   	 	       FxLabelB8.setValue("DAMP");
	     	   	 	       FxLabelB9.setValue("WIDTH");
	     	   	 	       }         

};

Content.getComponent("PostMode3").setControlCallback(onPostMode3Control);



