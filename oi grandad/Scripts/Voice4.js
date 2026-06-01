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

//rand samples
const var HiddenFiles4 = Content.getComponent("HiddenFiles4");

const var SampleMin4 = Content.getComponent("SampleMin4");
const var SampleMax4 = Content.getComponent("SampleMax4");

SampleMin4.set("min", 1);
SampleMin4.set("max", AudioList.length);
SampleMin4.set("stepSize", 1);

SampleMax4.set("min", 1);
SampleMax4.set("max", AudioList.length);
SampleMax4.set("stepSize", 1);

 //sensible defaults
SampleMin4.setValue(1);
SampleMax4.setValue(AudioList.length);

 
reg isSampleLoadBusy4 = false;
reg pendingSampleRandomise4 = false;
reg lastSampleIndex4 = -1;

inline function onHiddenFiles4Control(component, value)
{
    if (isSampleLoadBusy4)
        return;

    if (value <= 0 || value > AudioList.length)
        return;

    isSampleLoadBusy4 = true;
    slot4.loadFile(HiddenFiles4.getItemText());

    Content.callAfterDelay(500, function()
    {
        isSampleLoadBusy4 = false;

        if (pendingSampleRandomise4)
        {
            pendingSampleRandomise4 = false;
            randomiseVoice4Sample();
        }
    });
};

Content.getComponent("HiddenFiles4").setControlCallback(onHiddenFiles4Control);

inline function randomiseVoice4Sample()
{
    if (isSampleLoadBusy4)
    {
        pendingSampleRandomise4 = true;
        return;
    }

    if (AudioList.length == 0)
        return;

    local minIdx = Math.round(SampleMin4.getValue());
    local maxIdx = Math.round(SampleMax4.getValue());

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
        while (newIndex == lastSampleIndex4)
            newIndex = Math.randInt(minIdx, maxIdx + 1);
    }

    lastSampleIndex4 = newIndex;
    HiddenFiles4.setValue(newIndex);
    HiddenFiles4.changed();
}

inline function onSampleMin4Control(component, value)
{
    if (value > SampleMax4.getValue())
        SampleMax4.setValue(value);
}
Content.getComponent("SampleMin4").setControlCallback(onSampleMin4Control);

inline function onSampleMax4Control(component, value)
{
    if (value < SampleMin4.getValue())
        SampleMin4.setValue(value);
}
Content.getComponent("SampleMax4").setControlCallback(onSampleMax4Control);

const var RandomiseSamples3 = Content.getComponent("RandomiseSamples3");


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
 //   randomiseIfUnlockedD(14, PostMeta10);
 //   randomiseIfUnlockedD(15, PostMeta11);
 //   randomiseIfUnlockedD(16, PostMeta12);
    
    
       if (RandomiseSamples3.getValue() == 0)
        {
        randomiseVoice4Sample();
        
        }
        
}

Content.getComponent("RANDOMISE4").setControlCallback(onRANDOMISE4Control);

const var RandomControls4 = Content.getComponent("RandomControls4");


inline function onShowRandom4Control(component, value)
{
	RandomControls4.showControl(value);
	Post1.showControl(value-1);
};

Content.getComponent("ShowRandom4").setControlCallback(onShowRandom4Control);


