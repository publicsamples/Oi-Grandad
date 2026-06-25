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
             
        gran1.setAttribute(gran1.scrubMode, 0);  
       // gran1.setAttribute(gran1.PositionModMode, 0);

      

       for(s in StackItem2)
            s.showControl(0);
                   
	}
	
if(value == 2)
  {
	VoiceParam2.showControl(0);
	VoiceParamB2.showControl(1);
	  	
	  	
          gran1.setAttribute(gran1.scrubMode, 1);  

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
	 	 
	 	 if(value == 4)
	 	 	 	 	  {
	 	 	 	 	 gran1.setAttribute(gran1.PitchMode, 4);
	 	 	 	 	 DivLabel1.showControl(0);
	 	 	 	 	 	 PitchDiv2.showControl(0);
	 	 	 	 	 	 PitchTempo2.showControl(0);;
	 	 	 	 	 	 det1.showControl(1);
	 	 	 	 	 	 DetuneLabel1.setValue("TIME");
	 	 	 	 	 }
	 	 	 	 	 
	 	 	if(value == 5)
	 	 		 	 	 	  {
	 	 		 	 	 	 gran1.setAttribute(gran1.PitchMode, 5);
	 	 		 	 	 	 DivLabel1.showControl(0);
	 	 		 	 	 	 	 PitchDiv2.showControl(0);
	 	 		 	 	 	 	 PitchTempo2.showControl(0);;
	 	 		 	 	 	 	 det1.showControl(1);
	 	 		 	 	 	 	 DetuneLabel1.setValue("SPREAD");
	 	 		 	 	 	 } 	 
	 	 		 	 	 	 
	 	 	if(value == 6)
	 	 		 	 	 	  {
	 	 		 	 	 	 gran1.setAttribute(gran1.PitchMode, 6);
	 	 		 	 	 	 DivLabel1.showControl(0);
	 	 		 	 	 	 	 PitchDiv2.showControl(0);
	 	 		 	 	 	 	 PitchTempo2.showControl(0);;
	 	 		 	 	 	 	 det1.showControl(1);
	 	 		 	 	 	 	 DetuneLabel1.setValue("SPREAD");
	 	 		 	 	 	 }	 
	 	 		 	 	 	 
	 	 		 	 	 	 	 	 	 	 
	 	 	if(value == 7)
	 	 		 	 	 	  {
	 	 		 	 	 	 gran1.setAttribute(gran1.PitchMode, 7);
	 	 		 	 	 	 DivLabel1.showControl(0);
	 	 		 	 	 	 	 PitchDiv2.showControl(0);
	 	 		 	 	 	 	 PitchTempo2.showControl(0);;
	 	 		 	 	 	 	 det1.showControl(1);
	 	 		 	 	 	 	 DetuneLabel1.setValue("SPREAD");
	 	 		 	 	 	 } 
	 	 		 	 	 	 
	 	 	if(value == 8)
	 	 		 	 	 	  {
	 	 		 	 	 	 gran1.setAttribute(gran1.PitchMode, 8);
	 	 		 	 	 	 DivLabel1.showControl(0);
	 	 		 	 	 	 	 PitchDiv2.showControl(0);
	 	 		 	 	 	 	 PitchTempo2.showControl(0);;
	 	 		 	 	 	 	 det1.showControl(1);
	 	 		 	 	 	 	 DetuneLabel1.setValue("SPREAD");
	 	 		 	 	 	 }	 	 
	 	 		 	 	 	 
	 	 	if(value == 9)
	 	 		 	 	 	  {
	 	 		 	 	 	 gran1.setAttribute(gran1.PitchMode, 9);
	 	 		 	 	 	 DivLabel1.showControl(0);
	 	 		 	 	 	 	 PitchDiv2.showControl(0);
	 	 		 	 	 	 	 PitchTempo2.showControl(0);;
	 	 		 	 	 	 	 det1.showControl(1);
	 	 		 	 	 	 	 DetuneLabel1.setValue("SPREAD");
	 	 		 	 	 	 }	 	 
	 	 		 	 	 	 
	 	 	if(value ==10)
	 	 	 		 	 	 	  {
	 	 	 		 	 	 	 gran1.setAttribute(gran1.PitchMode, 10);
	 	 	 		 	 	 	 DivLabel1.showControl(0);
	 	 	 		 	 	 	 	 PitchDiv2.showControl(0);
	 	 	 		 	 	 	 	 PitchTempo2.showControl(0);;
	 	 	 		 	 	 	 	 det1.showControl(1);
	 	 	 		 	 	 	 	 DetuneLabel1.setValue("SPREAD");
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
const var PolyMeta2 = Content.getComponent("PolyMeta2");
const var PolyMetaB2 = Content.getComponent("PolyMetaB2");
const var PolyMix2 = Content.getComponent("PolyMix2");
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

//rand samples
const var HiddenFiles2 = Content.getComponent("HiddenFiles2");

const var SampleMin2 = Content.getComponent("SampleMin2");
const var SampleMax2 = Content.getComponent("SampleMax2");

SampleMin2.set("min", 1);
SampleMin2.set("max", AudioList.length);
SampleMin2.set("stepSize", 1);

SampleMax2.set("min", 1);
SampleMax2.set("max", AudioList.length);
SampleMax2.set("stepSize", 1);

 //sensible defaults
SampleMin2.setValue(1);
SampleMax2.setValue(AudioList.length);

 
reg isSampleLoadBusy2 = false;
reg pendingSampleRandomise2 = false;
reg lastSampleIndex2 = -1;

inline function onHiddenFiles2Control(component, value)
{
    if (isSampleLoadBusy2)
        return;

    if (value <= 0 || value > AudioList.length)
        return;

    isSampleLoadBusy2 = true;
    slot2.loadFile(AudioList[value - 1]);

    Content.callAfterDelay(500, function()
    {
        isSampleLoadBusy2 = false;

        if (pendingSampleRandomise2)
        {
            pendingSampleRandomise2 = false;
            randomiseVoice2Sample();
        }
    });
};

Content.getComponent("HiddenFiles2").setControlCallback(onHiddenFiles2Control);

inline function randomiseVoice2Sample()
{
    if (isSampleLoadBusy2)
    {
        pendingSampleRandomise2 = true;
        return;
    }

    if (AudioList.length == 0)
        return;

    local minIdx = Math.round(SampleMin2.getValue());
    local maxIdx = Math.round(SampleMax2.getValue());

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
        while (newIndex == lastSampleIndex2)
            newIndex = Math.randInt(minIdx, maxIdx + 1);
    }

    lastSampleIndex2 = newIndex;
    HiddenFiles2.setValue(newIndex);
    HiddenFiles2.changed();
}

inline function onSampleMin2Control(component, value)
{
    if (value > SampleMax2.getValue())
        SampleMax2.setValue(value);
}
Content.getComponent("SampleMin2").setControlCallback(onSampleMin2Control);

inline function onSampleMax2Control(component, value)
{
    if (value < SampleMin2.getValue())
        SampleMin2.setValue(value);
}
Content.getComponent("SampleMax2").setControlCallback(onSampleMax2Control);

const var RandomiseSamples1 = Content.getComponent("RandomiseSamples1");


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
    randomiseIfUnlockedB(12, PolyMeta2);
    randomiseIfUnlockedB(13, PolyMetaB2);
 //   randomiseIfUnlockedB(14, PostMeta4);
 //   randomiseIfUnlockedB(15, PostMeta5);
 //   randomiseIfUnlockedB(16, PostMeta6);
    
    if (RandomiseSamples1.getValue() == 0)
    {
    randomiseVoice2Sample();
    
    }
}

Content.getComponent("RANDOMISE2").setControlCallback(onRANDOMISE2Control);

const var RandomControls2 = Content.getComponent("RandomControls2");


inline function onShowRandom2Control(component, value)
{
	RandomControls2.showControl(value);
	Post1.showControl(value-1);
};

Content.getComponent("ShowRandom2").setControlCallback(onShowRandom2Control);




