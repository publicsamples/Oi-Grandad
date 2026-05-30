const var XfModControls1 = Content.getComponent("XfModControls1");

const var StackItem1 = [Content.getComponent("PosIndicator2"),
                        Content.getComponent("PosIndicator3"),
                        Content.getComponent("PosIndicator4")];
                        
const var VoiceParam1 = Content.getComponent("PosParam1");
const var VoiceParamB1 = Content.getComponent("PosParamB1");

inline function onStgSel1Control(component, value)
{


if(value == 1)
  {

  	VoiceParam1.showControl(1);
  	VoiceParamB1.showControl(0);
             
        gran.setAttribute(gran.scrubMode, 1);  
      
       for(s in StackItem1)
            s.showControl(0);
                   
	}
	
if(value == 2)
  {
	VoiceParam1.showControl(0);
	VoiceParamB1.showControl(1);
	  	
	  	
          gran.setAttribute(gran.scrubMode, 2);  

              for(s in StackItem1)
                  s.showControl(1);
              
	}
	
	if(value == 3)
	  {
	
	  	VoiceParam1.showControl(1);
	  	VoiceParamB1.showControl(0);
	             
	        gran.setAttribute(gran.scrubMode, 3);  
	      
	       for(s in StackItem1)
	            s.showControl(0);
	                   
		}
		
		if(value == 4)
		  {
			VoiceParam1.showControl(0);
			VoiceParamB1.showControl(1);
			  	
			  	
		          gran.setAttribute(gran.scrubMode, 4);  
		
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
	 gran.setAttribute(gran.MaxGrains, 4);
	 }
	 
	 if(value == 2)
	 	  {
	 	 gran.setAttribute(gran.MaxGrains, 8);
	 	 }
	 	 
	 	 if(value == 3)
	 	 	  {
	 	 gran.setAttribute(gran.MaxGrains, 16);
	 	 	 }
	 	 	 
	 	 if(value == 4)
	 	 	 	 	  {
	 	 	 	 gran.setAttribute(gran.MaxGrains, 32);
	 	 	 	 	 }	 
	 	 
};

Content.getComponent("maxGrains1").setControlCallback(onmaxGrains1Control);

const var DivLabel = Content.getComponent("DivLabel");
const var PitchDiv1 = Content.getComponent("PitchDiv1");
const var DetuneLabel = Content.getComponent("DetuneLabel");
const var PitchTempo1 = Content.getComponent("PitchTempo1");
const var det = Content.getComponent("det");


inline function onPitchMode1Control(component, value)
{
	

	if(value == 1)
	  {
	 gran.setAttribute(gran.PitchMode, 1);
	 DivLabel.showControl(0);
	 PitchDiv1.showControl(0);
	 PitchTempo1.showControl(0);;
	 det.showControl(1);
	 DetuneLabel.setValue("DETUNE");
	 }
	 
	 if(value == 2)
	 	  {
	 	 gran.setAttribute(gran.PitchMode, 2);
	 	 DivLabel.showControl(0);
	 	 	 PitchDiv1.showControl(0);
	 	 	 PitchTempo1.showControl(0);;
	 	 	 det.showControl(1);
	 	 	 DetuneLabel.setValue("HARM.");
	 	 }
	 	 
	 if(value == 3)
	 	  {
	 	 gran.setAttribute(gran.PitchMode, 3);
	 	 DivLabel.showControl(1);
	 	 PitchDiv1.showControl(1);
	 	 PitchTempo1.showControl(1);;
	 	 det.showControl(0);
	 	 DetuneLabel.setValue("TEMPO");
	 	 }	 
	 	 
	 	 if(value == 4)
	 	 	 	  {
	 	 	 	 gran.setAttribute(gran.PitchMode, 4);
	 	 	 	 DivLabel.showControl(0);
	 	 	 	 	 PitchDiv1.showControl(0);
	 	 	 	 	 PitchTempo1.showControl(0);;
	 	 	 	 	 det.showControl(1);
	 	 	 	 	 DetuneLabel.setValue("HARM.");
	 	 	 	 }
	 	 
};

Content.getComponent("PitchMode1").setControlCallback(onPitchMode1Control);

// RANDOM
const var pos = Content.getComponent("pos");
const var MultPosA1 = Content.getComponent("MultPosA1");
const var MultPosB1 = Content.getComponent("MultPosB1");
const var MultPosC1 = Content.getComponent("MultPosC1");
const var MultPosD1 = Content.getComponent("MultPosD1");
const var MacroPos1 = Content.getComponent("MacroPos1");

const var pitchCont = Content.getComponent("pitch");
const var det = Content.getComponent("det");
const var spreadCont1 = Content.getComponent("spread");
const var graintempo1 = Content.getComponent("graintempo1");
const var grainsize1 = Content.getComponent("grainsize1");
const var WindowTempo1 = Content.getComponent("WindowTempo1");
const var Jitter1 = Content.getComponent("Jitter1");
const var Dense1 = Content.getComponent("Dense1");
const var DelayTime1 = Content.getComponent("DelayTime1");
const var delcut1 = Content.getComponent("delcut1");
const var delmix1 = Content.getComponent("delmix1");
const var PostMeta1 = Content.getComponent("PostMeta1");
const var PostMeta2 = Content.getComponent("PostMeta2");
const var PostMix1 = Content.getComponent("PostMix1");
const var PostMeta3 = Content.getComponent("PostMeta3");

const var RandLockA = [];
const var RandMinA = [];
const var RandMaxA = [];

for (i = 0; i < 17; i++)
{
    RandLockA[i] = Content.getComponent("RandLock" + (i + 1));
    RandMinA[i] = Content.getComponent("RandMin" + (i + 1));
    RandMaxA[i] = Content.getComponent("RandMax" + (i + 1));
}

inline function randRange(min, max)
{
    return min + Math.random() * (max - min);
}

inline function randomiseIfUnlocked(lockIndex, target)
{
    if (RandLockA[lockIndex].getValue() == 0)
    {
        target.setValue(randRange(
            RandMinA[lockIndex].getValue(),
            RandMaxA[lockIndex].getValue()
        ));
        target.changed();
    }
}

inline function onRANDOMISE1Control(component, value)
{
    if (value != 1)
        return;

    // Position group
    if (RandLockA[0].getValue() == 0)
    {
        local v = randRange(RandMinA[0].getValue(), RandMaxA[0].getValue());

        pos.setValue(v);
        MultPosA1.setValue(v);
        MacroPos1.setValue(v);

        pos.changed();
        MultPosA1.changed();
        MacroPos1.changed();
    }

    randomiseIfUnlocked(1, MultPosB1);
    randomiseIfUnlocked(2, MultPosC1);
    randomiseIfUnlocked(3, MultPosD1);
    randomiseIfUnlocked(4, pitchCont);
    randomiseIfUnlocked(5, det);
    randomiseIfUnlocked(6, spreadCont1);
    randomiseIfUnlocked(7, grainsize1);
    randomiseIfUnlocked(8, graintempo1);
    randomiseIfUnlocked(9, WindowTempo1);
    randomiseIfUnlocked(10, Jitter1);
    randomiseIfUnlocked(11, Dense1);
    randomiseIfUnlocked(12, DelayTime1);
    randomiseIfUnlocked(13, delcut1);
    randomiseIfUnlocked(14, PostMeta1);
    randomiseIfUnlocked(15, PostMeta2);
    randomiseIfUnlocked(16, PostMeta3);
    
    if (RandomiseSamples.getValue() == 1)
        randomiseSampleForVoice(1);
}

Content.getComponent("RANDOMISE1").setControlCallback(onRANDOMISE1Control);

const var RandomControls1 = Content.getComponent("RandomControls1");


inline function onShowRandom1Control(component, value)
{
	RandomControls1.showControl(value);
};

Content.getComponent("ShowRandom1").setControlCallback(onShowRandom1Control);


const var RandomiseSamples = Content.getComponent("RandomiseSamples");

inline function isDefaultOrEmpty(path)
{
    return path == "" || path == defaultRef || path.endsWith("OGInit.wav");
}

inline function getAudioFilesFromFolder(folder)
{
    local files = [];
    local children = folder.findChildFiles("*.wav", true);

    for (f in children)
        files.push(f);

    return files;
}


//FX MENUS

const var FxLabelA1 = Content.getComponent("FxLabelA1");
const var FxLabelA2 = Content.getComponent("FxLabelA2");

inline function onResMode1Control(component, value)
{

	if(value == 1)
	{
	 gran.setAttribute(gran.delMode, 1);
	 FxLabelA1.setValue("OFF");
	 FxLabelA2.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  gran.setAttribute(gran.delMode, 2);
	  FxLabelA1.setValue("CUT");
	  FxLabelA2.setValue("Q");
	  }
	  if(value == 3)
	  {
	   gran.setAttribute(gran.delMode, 3);
	   FxLabelA1.setValue("CUT");
	   FxLabelA2.setValue("Q");
	   }
	   if(value == 4)
	   {
	    gran.setAttribute(gran.delMode, 4);
	    FxLabelA1.setValue("CUT");
	    FxLabelA2.setValue("Q");
	    }	
		if(value == 5)
	   {
	    gran.setAttribute(gran.delMode, 5);
	      FxLabelA1.setValue("CUT");
	    FxLabelA2.setValue("Q");
	    }
	    if(value == 6)
	       {
	        gran.setAttribute(gran.delMode, 6);
	          FxLabelA1.setValue("FREQ");
	    FxLabelA2.setValue("Q");
	        }
	    if(value == 7)
	       {
	        gran.setAttribute(gran.delMode, 7);
	          FxLabelA1.setValue("TRASH");
	    FxLabelA2.setValue("LP");
	        } 
	   if(value == 8)
	      {
	       gran.setAttribute(gran.delMode, 8);
	       FxLabelA1.setValue("Pitch");
	       FxLabelA2.setValue("LP");
	       }  
	   if(value == 9)
	   	      {
	   	       gran.setAttribute(gran.delMode, 9);
	   	       FxLabelA1.setValue("Pitch");
	       FxLabelA2.setValue("LP");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       gran.setAttribute(gran.delMode, 10);
	   	 	       FxLabelA1.setValue("Bit");
	   	 	       FxLabelA2.setValue("S&H");
	   	 	       }                                
	        
};

Content.getComponent("ResMode1").setControlCallback(onResMode1Control);

const var FxLabelB1 = Content.getComponent("FxLabelB1");
const var FxLabelB2 = Content.getComponent("FxLabelB2");
const var FxLabelB3 = Content.getComponent("FxLabelB3");

const var Final1 = Synth.getEffect("Final1");

inline function onPostMode1Control(component, value)
{
		if(value == 1)
	{
	 Final1.setAttribute(Final1.delMode, 1);
	 FxLabelB1.setValue("OFF");
	 FxLabelB2.setValue("OFF");
	 FxLabelB3.setValue("OFF");
	 }
	 if(value == 2)
	 {
	  Final1.setAttribute(Final1.delMode, 2);
	  FxLabelB1.setValue("LP");
	  FxLabelB2.setValue("Q");
	  FxLabelB3.setValue("HP");
	  }
	  if(value == 3)
	  {
	   Final1.setAttribute(Final1.delMode, 3);
	   FxLabelB1.setValue("HP");
	   FxLabelB2.setValue("Q");
	   FxLabelB3.setValue("LP");
	   }
	   if(value == 4)
	   {
	    Final1.setAttribute(Final1.delMode, 4);
	    FxLabelB1.setValue("BP");
	    FxLabelB2.setValue("Q");
	    FxLabelB3.setValue("LP");
	    }	
		if(value == 5)
	   {
	    Final1.setAttribute(Final1.delMode, 5);
	      FxLabelB1.setValue("BP");
	    FxLabelB2.setValue("Q");
	    FxLabelB3.setValue("HP");
	    }
	    if(value == 6)
	       {
	        Final1.setAttribute(Final1.delMode, 6);
	          FxLabelB1.setValue("CUT");
	    FxLabelB2.setValue("Q");
	    FxLabelB3.setValue("GAIN");
	        }
	    if(value == 7)
	       {
	        Final1.setAttribute(Final1.delMode, 7);
	          FxLabelB1.setValue("CUT");
	    FxLabelB2.setValue("Q");
	    FxLabelB3.setValue("GAIN");
	        } 
	   if(value == 8)
	      {
	       Final1.setAttribute(Final1.delMode, 8);
	       FxLabelB1.setValue("AP");
	       FxLabelB2.setValue("Q");
	       FxLabelB3.setValue("HP");
	       }  
	   if(value == 9)
	   	      {
	   	       Final1.setAttribute(Final1.delMode, 9);
	   	       FxLabelB1.setValue("Time");
	       FxLabelB2.setValue("LP");
	       FxLabelB3.setValue("FEED");
	   	       }   
	   	 if(value == 10)
	   	 	      {
	   	 	       Final1.setAttribute(Final1.delMode, 10);
	   	 	       FxLabelB1.setValue("DELAY");
	   	 	       FxLabelB2.setValue("LP");
	   	 	       FxLabelB3.setValue("FEED");
	   	 	       }                                
	     if(value == 11)
	     	   	 	      {
	     	   	 	       Final1.setAttribute(Final1.delMode, 11);
	     	   	 	       FxLabelB1.setValue("SPACE");
	     	   	 	       FxLabelB2.setValue("DAMP");
	     	   	 	       FxLabelB3.setValue("WIDTH");
	     	   	 	       }         

};

Content.getComponent("PostMode1").setControlCallback(onPostMode1Control);



