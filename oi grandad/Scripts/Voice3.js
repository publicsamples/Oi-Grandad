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

//rand samples
const var HiddenFiles3 = Content.getComponent("HiddenFiles3");

const var SampleMin3 = Content.getComponent("SampleMin3");
const var SampleMax3 = Content.getComponent("SampleMax3");

SampleMin3.set("min", 1);
SampleMin3.set("max", AudioList.length);
SampleMin3.set("stepSize", 1);

SampleMax3.set("min", 1);
SampleMax3.set("max", AudioList.length);
SampleMax3.set("stepSize", 1);

 //sensible defaults
SampleMin3.setValue(1);
SampleMax3.setValue(AudioList.length);

 
reg isSampleLoadBusy3 = false;
reg pendingSampleRandomise3 = false;
reg lastSampleIndex3 = -1;

inline function onHiddenFiles3Control(component, value)
{
    if (isSampleLoadBusy3)
        return;

    if (value <= 0 || value > AudioList.length)
        return;

    isSampleLoadBusy3 = true;
    slot3.loadFile(AudioList[value - 1]);

    Content.callAfterDelay(500, function()
    {
        isSampleLoadBusy3 = false;

        if (pendingSampleRandomise3)
        {
            pendingSampleRandomise3 = false;
            randomiseVoice3Sample();
        }
    });
};

Content.getComponent("HiddenFiles3").setControlCallback(onHiddenFiles3Control);

inline function randomiseVoice3Sample()
{
    if (isSampleLoadBusy3)
    {
        pendingSampleRandomise3 = true;
        return;
    }

    if (AudioList.length == 0)
        return;

    local minIdx = Math.round(SampleMin3.getValue());
    local maxIdx = Math.round(SampleMax3.getValue());

    // guard against reversed range
    if (minIdx > maxIdx)
    {
        local t = minIdx;
        minIdx = maxIdx;
        maxIdx = t;
    }

    // clamp to valid menu range
    minIdx = Math.max(1, minIdx);
    maxIdx = Math.min(AudioList.length, maxIdx);

    local newIndex = Math.randInt(minIdx, maxIdx + 1);

    if (maxIdx > minIdx)
    {
        while (newIndex == lastSampleIndex3)
            newIndex = Math.randInt(minIdx, maxIdx + 1);
    }

    lastSampleIndex3 = newIndex;
    HiddenFiles3.setValue(newIndex);
    HiddenFiles3.changed();
}

inline function onSampleMin3Control(component, value)
{
    if (value > SampleMax3.getValue())
        SampleMax3.setValue(value);
}
Content.getComponent("SampleMin3").setControlCallback(onSampleMin3Control);

inline function onSampleMax3Control(component, value)
{
    if (value < SampleMin3.getValue())
        SampleMin3.setValue(value);
}
Content.getComponent("SampleMax3").setControlCallback(onSampleMax3Control);

const var RandomiseSamples2 = Content.getComponent("RandomiseSamples2");


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
  //  randomiseIfUnlockedC(14, PostMeta7);
  //  randomiseIfUnlockedC(15, PostMeta8);
  //  randomiseIfUnlockedC(16, PostMeta9);
    
    if (RandomiseSamples2.getValue() == 0)
     {
     randomiseVoice3Sample();
     
     }
}

Content.getComponent("RANDOMISE3").setControlCallback(onRANDOMISE3Control);

const var RandomControls3 = Content.getComponent("RandomControls3");


inline function onShowRandom3Control(component, value)
{
	RandomControls3.showControl(value);
	Post1.showControl(value-1);
};

Content.getComponent("ShowRandom3").setControlCallback(onShowRandom3Control);


