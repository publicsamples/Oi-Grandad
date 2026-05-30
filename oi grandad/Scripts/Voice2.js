const var StackItem2 = [Content.getComponent("PosIndicator6"),
                        Content.getComponent("PosIndicator7"),
                        Content.getComponent("PosIndicator8")];
                        
const var VoiceParam2 = Content.getComponent("PosParam2");
const var VoiceParamB2 = Content.getComponent("PosParamB2");

  

inline function onStgSel2Control(component, value)
{
	


if(value == 1)
  {

  	VoiceParam2.showControl(1);
  	VoiceParamB2.showControl(0);
             
        gran1.setAttribute(gran1.scrubMode, 1);  
       // gran1.setAttribute(gran1.PositionModMode, 0);

      

       for(s in StackItem2)
            s.showControl(0);
                   
	}
	
if(value == 2)
  {
	VoiceParam2.showControl(0);
	VoiceParamB2.showControl(1);
	  	
	  	
          gran1.setAttribute(gran1.scrubMode, 2);  

              for(s in StackItem2)
                  s.showControl(1);
              
	}
	
if(value == 3)
  {

  	VoiceParam2.showControl(1);
  	VoiceParamB2.showControl(0);
             
        gran1.setAttribute(gran1.scrubMode, 3);  
       // gran1.setAttribute(gran1.PositionModMode, 0);

      

       for(s in StackItem2)
            s.showControl(0);
                   
	}
	
if(value == 4)
  {
	VoiceParam2.showControl(0);
	VoiceParamB2.showControl(1);
	  	
	  	
          gran1.setAttribute(gran1.scrubMode, 4);  

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
	 gran1.setAttribute(gran1.MaxGrains, 4);
	 }
	 
	 if(value == 2)
	 	  {
	 	 gran1.setAttribute(gran1.MaxGrains, 8);
	 	 }
	 	 
	 	 if(value == 3)
	 	 	  {
	 	 	 gran1.setAttribute(gran1.MaxGrains, 16);
	 	 	 }
	 	 	 
	 	 if(value == 4)
	 	 	 	 	  {
	 	 	 	 	 gran1.setAttribute(gran1.MaxGrains, 32);
	 	 	 	 	 }		 	 	 	 
};

Content.getComponent("maxGrains2").setControlCallback(onmaxGrains2Control);

const var DivLabel1 = Content.getComponent("DivLabel1");
const var PitchDiv2 = Content.getComponent("PitchDiv2");
const var DetuneLabel1 = Content.getComponent("DetuneLabel1");
const var PitchTempo2 = Content.getComponent("PitchTempo2");
const var det1 = Content.getComponent("det1");


inline function onPitchMode2Control(component, value)
{
	

	if(value == 1)
	  {
	 gran1.setAttribute(gran1.PitchMode, 1);
	 DivLabel1.showControl(0);
	 PitchDiv2.showControl(0);
	 PitchTempo2.showControl(0);;
	 det1.showControl(1);
	 DetuneLabel1.setValue("DETUNE");
	 }
	 
	 if(value == 2)
	 	  {
	 	 gran1.setAttribute(gran1.PitchMode, 2);
	 	 DivLabel1.showControl(0);
	 	 	 PitchDiv2.showControl(0);
	 	 	 PitchTempo2.showControl(0);;
	 	 	 det1.showControl(1);
	 	 	 DetuneLabel1.setValue("HARM.");
	 	 }
	 	 
	 if(value == 3)
	 	  {
	 	 gran1.setAttribute(gran1.PitchMode, 3);
	 	 DivLabel1.showControl(1);
	 	 PitchDiv2.showControl(1);
	 	 PitchTempo2.showControl(1);;
	 	 det1.showControl(0);
	 	 DetuneLabel1.setValue("TEMPO");
	 	 }	 
	 	 
};

Content.getComponent("PitchMode2").setControlCallback(onPitchMode2Control);

// RANDOM
const var pos1 = Content.getComponent("pos1");
const var MultPosA2 = Content.getComponent("MultPosA2");
const var MultPosB2 = Content.getComponent("MultPosB2");
const var MultPosC2 = Content.getComponent("MultPosC2");
const var MultPosD2 = Content.getComponent("MultPosD2");
const var MacroPos2 = Content.getComponent("MacroPos2");

const var pitchCont = Content.getComponent("pitch1");
const var det1 = Content.getComponent("det1");
const var spreadCont2 = Content.getComponent("spread1");
const var graintempo2 = Content.getComponent("graintempo2");
const var grainsize2 = Content.getComponent("grainsize2");
const var WindowTempo2 = Content.getComponent("WindowTempo2");
const var Jitter2 = Content.getComponent("Jitter2");
const var Dense2 = Content.getComponent("Dense2");
const var DelayTime2 = Content.getComponent("DelayTime2");
const var delcut2 = Content.getComponent("delcut2");
const var delmix2 = Content.getComponent("delmix2");
const var PostMeta4 = Content.getComponent("PostMeta4");
const var PostMeta5 = Content.getComponent("PostMeta5");
const var PostMix1 = Content.getComponent("PostMix1");
const var PostMeta6 = Content.getComponent("PostMeta6");

const var RandLockB = [];
const var RandMinB = [];
const var RandMaxB = [];

for (i = 0; i < 17; i++)
{
    RandLockB[i] = Content.getComponent("RandLock" + (i + 18));
    RandMinB[i] = Content.getComponent("RandMin" + (i + 18));
    RandMaxB[i] = Content.getComponent("RandMax" + (i + 18));
}

inline function randRangeB(min, max)
{
    return min + Math.random() * (max - min);
}

inline function randomiseIfUnlockedB(lockIndex, target)
{
    if (RandLockB[lockIndex].getValue() == 0)
    {
        target.setValue(randRangeB(
            RandMinB[lockIndex].getValue(),
            RandMaxB[lockIndex].getValue()
        ));
        target.changed();
    }
}

inline function onRANDOMISE2Control(component, value)
{
    if (value != 1)
        return;

    // Position group
    if (RandLockB[0].getValue() == 0)
    {
        local v = randRangeB(RandMinB[0].getValue(), RandMaxB[0].getValue());

        pos1.setValue(v);
        MultPosA2.setValue(v);
        MacroPos2.setValue(v);

        pos1.changed();
        MultPosA2.changed();
     //  MacroPos2.changed();
    }

    randomiseIfUnlockedB(1, MultPosB2);
    randomiseIfUnlockedB(2, MultPosC2);
    randomiseIfUnlockedB(3, MultPosD2);
    randomiseIfUnlockedB(4, pitchCont);
    randomiseIfUnlockedB(5, det1);
    randomiseIfUnlockedB(6, spreadCont2);
    randomiseIfUnlockedB(7, grainsize2);
    randomiseIfUnlockedB(8, graintempo2);
    randomiseIfUnlockedB(9, WindowTempo2);
    randomiseIfUnlockedB(10, Jitter2);
    randomiseIfUnlockedB(11, Dense2);
    randomiseIfUnlockedB(12, DelayTime2);
    randomiseIfUnlockedB(13, delcut2);
    randomiseIfUnlockedB(14, PostMeta4);
    randomiseIfUnlockedB(15, PostMeta5);
    randomiseIfUnlockedB(16, PostMeta6);
}

Content.getComponent("RANDOMISE2").setControlCallback(onRANDOMISE2Control);

const var RandomControls2 = Content.getComponent("RandomControls2");


inline function onShowRandom2Control(component, value)
{
	RandomControls2.showControl(value);
};

Content.getComponent("ShowRandom2").setControlCallback(onShowRandom2Control);


//FX MENUS

const var FxLabelA3 = Content.getComponent("FxLabelA3");
const var FxLabelA4 = Content.getComponent("FxLabelA4");

inline function onResMode2Control(component, value)
{

	if(value == 1)
	{
	 gran1.setAttribute(gran1.delMode, 1);
	 FxLabelA3.setValue("OFF");
	 FxLabelA4.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  gran1.setAttribute(gran1.delMode, 2);
	  FxLabelA3.setValue("CUT");
	  FxLabelA4.setValue("Q");
	  }
	  if(value == 3)
	  {
	   gran1.setAttribute(gran1.delMode, 3);
	   FxLabelA3.setValue("CUT");
	   FxLabelA4.setValue("Q");
	   }
	   if(value == 4)
	   {
	    gran1.setAttribute(gran1.delMode, 4);
	    FxLabelA3.setValue("CUT");
	    FxLabelA4.setValue("Q");
	    }	
		if(value == 5)
	   {
	    gran1.setAttribute(gran1.delMode, 5);
	      FxLabelA3.setValue("CUT");
	    FxLabelA4.setValue("Q");
	    }
	    if(value == 6)
	       {
	        gran1.setAttribute(gran1.delMode, 6);
	          FxLabelA3.setValue("FREQ");
	    FxLabelA4.setValue("Q");
	        }
	    if(value == 7)
	       {
	        gran1.setAttribute(gran1.delMode, 7);
	          FxLabelA3.setValue("TRASH");
	    FxLabelA4.setValue("LP");
	        } 
	   if(value == 8)
	      {
	       gran1.setAttribute(gran1.delMode, 8);
	       FxLabelA3.setValue("Pitch");
	       FxLabelA4.setValue("LP");
	       }  
	   if(value == 9)
	   	      {
	   	       gran1.setAttribute(gran1.delMode, 9);
	   	       FxLabelA3.setValue("Pitch");
	       FxLabelA4.setValue("LP");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       gran1.setAttribute(gran1.delMode, 10);
	   	 	       FxLabelA3.setValue("Bit");
	   	 	       FxLabelA4.setValue("S&H");
	   	 	       }                                
	        
};

Content.getComponent("ResMode2").setControlCallback(onResMode2Control);

const var FxLabelB4 = Content.getComponent("FxLabelB4");
const var FxLabelB5 = Content.getComponent("FxLabelB5");
const var FxLabelB6 = Content.getComponent("FxLabelB6");

const var Final2 = Synth.getEffect("Final2");

inline function onPostMode2Control(component, value)
{
		if(value == 1)
	{
	 Final2.setAttribute(Final2.delMode, 1);
	 FxLabelB4.setValue("OFF");
	 FxLabelB5.setValue("OFF");
	 FxLabelB6.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  Final2.setAttribute(Final2.delMode, 2);
	  FxLabelB4.setValue("LP");
	  FxLabelB5.setValue("Q");
	  FxLabelB6.setValue("HP");
	  }
	  if(value == 3)
	  {
	   Final2.setAttribute(Final2.delMode, 3);
	   FxLabelB4.setValue("HP");
	   FxLabelB5.setValue("Q");
	   FxLabelB6.setValue("LP");
	   }
	   if(value == 4)
	   {
	    Final2.setAttribute(Final2.delMode, 4);
	    FxLabelB4.setValue("BP");
	    FxLabelB5.setValue("Q");
	    FxLabelB6.setValue("LP");
	    }	
		if(value == 5)
	   {
	    Final2.setAttribute(Final2.delMode, 5);
	      FxLabelB4.setValue("BP");
	    FxLabelB5.setValue("Q");
	    FxLabelB6.setValue("HP");
	    }
	    if(value == 6)
	       {
	        Final2.setAttribute(Final2.delMode, 6);
	          FxLabelB4.setValue("CUT");
	    FxLabelB5.setValue("Q");
	    FxLabelB6.setValue("GAIN");
	        }
	    if(value == 7)
	       {
	        Final2.setAttribute(Final2.delMode, 7);
	          FxLabelB4.setValue("CUT");
	    FxLabelB5.setValue("Q");
	    FxLabelB6.setValue("GAIN");
	        } 
	   if(value == 8)
	      {
	       Final2.setAttribute(Final2.delMode, 8);
	       FxLabelB4.setValue("AP");
	       FxLabelB5.setValue("Q");
	       FxLabelB6.setValue("HP");
	       }  
	   if(value == 9)
	   	      {
	   	       Final2.setAttribute(Final2.delMode, 9);
	   	       FxLabelB4.setValue("Time");
	       FxLabelB5.setValue("LP");
	       FxLabelB6.setValue("FEED");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       Final2.setAttribute(Final2.delMode, 10);
	   	 	       FxLabelB4.setValue("DELAY");
	   	 	       FxLabelB5.setValue("LP");
	   	 	       FxLabelB6.setValue("FEED");
	   	 	       }                                
	     if(value == 11)
	     	   	 	      {
	     	   	 	       Final2.setAttribute(Final2.delMode, 11);
	     	   	 	       FxLabelB4.setValue("SPACE");
	     	   	 	       FxLabelB5.setValue("DAMP");
	     	   	 	       FxLabelB6.setValue("WIDTH");
	     	   	 	       }         

};

Content.getComponent("PostMode2").setControlCallback(onPostMode2Control);



