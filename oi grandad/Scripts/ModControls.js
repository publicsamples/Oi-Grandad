//show hide env params
const var ModType1 = Content.getComponent("ModType1");
const var button1 = Content.getComponent("ModType1");
const var table1 = Content.getComponent("Table1");
const var step1 = Content.getComponent("Step1");
const var LFO1 = Synth.getModulator("LFO1");


inline function onModType1Control(component, value)
{
	

	   step1.showControl(value);
        table1.showControl(1-value); 
          
            if(value == 0)
        	{
              LFO1.setAttribute(LFO1.type, 1);
       }
       
       if(value == 1)
             	{
                   LFO1.setAttribute(LFO1.type, 0);
            }
};

Content.getComponent("ModType1").setControlCallback(onModType1Control);


const var mod1tables = []

mod1tables[0] = Content.getComponent("SliderPackA");
mod1tables[1] = Content.getComponent("SliderPackA1");
mod1tables[2] = Content.getComponent("SliderPackA2");
mod1tables[3] = Content.getComponent("SliderPackA3");


const var Mod1SPs = []

Mod1SPs[0] = Content.getComponent("ScriptTable1");
Mod1SPs[1] = Content.getComponent("ScriptTableA2");
Mod1SPs[2] = Content.getComponent("ScriptTableA3");
Mod1SPs[3] = Content.getComponent("ScriptTableA4");

const var Stage1 = Content.getComponent("Stage1");


inline function onStage1Control(component, value)
{
	

 for (i = 0; i < mod1tables.length; i++)
        mod1tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod1SPs.length; i++)
               Mod1SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO1.setAttribute(LFO1. morph, value);
};


Content.getComponent("Stage1").setControlCallback(onStage1Control);

const var ModType2 = Content.getComponent("ModType2");
const var button2 = Content.getComponent("ModType2");
const var table2 = Content.getComponent("Table2");
const var step2 = Content.getComponent("Step2");
const var LFO2 = Synth.getModulator("LFO2");

inline function onModType2Control(number, value)
{
	

        step2.showControl(value);
        table2.showControl(1-value); 

  
        
        if(value == 0)
        	{
              LFO2.setAttribute(LFO2.type, 1);
       }
       
       if(value == 1)
             	{
                   LFO2.setAttribute(LFO2.type, 0);
            }
}



Content.getComponent("ModType2").setControlCallback(onModType2Control);

const var mod2tables = []

mod2tables[0] = Content.getComponent("SliderPackA4");
mod2tables[1] = Content.getComponent("SliderPackA5");
mod2tables[2] = Content.getComponent("SliderPackA6");
mod2tables[3] = Content.getComponent("SliderPackA7");


const var Mod2SPs = []

Mod2SPs[0] = Content.getComponent("ScriptTable2");
Mod2SPs[1] = Content.getComponent("ScriptTableA5");
Mod2SPs[2] = Content.getComponent("ScriptTableA6");
Mod2SPs[3] = Content.getComponent("ScriptTableA7");

const var Stage2 = Content.getComponent("Stage2");


inline function onStage2Control(component, value)
{
	

 for (i = 0; i < mod2tables.length; i++)
        mod2tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod2SPs.length; i++)
               Mod2SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO2.setAttribute(LFO2. morph, value);
};


Content.getComponent("Stage2").setControlCallback(onStage2Control);

const var ModType3 = Content.getComponent("ModType3");
const var button3 = Content.getComponent("ModType3");
const var table3 = Content.getComponent("Table3");
const var step3 = Content.getComponent("Step3");
const var LFO3 = Synth.getModulator("LFO3");

inline function onModType3Control(number, value)
{
	

        step3.showControl(value);
        table3.showControl(1-value); 
            if(value == 0)
        	{
              LFO3.setAttribute(LFO3.type, 1);
       }
       
       if(value == 1)
             	{
                   LFO3.setAttribute(LFO3.type, 0);
            }

}


Content.getComponent("ModType3").setControlCallback(onModType3Control);

const var mod3tables = []

mod3tables[0] = Content.getComponent("SliderPackA8");
mod3tables[1] = Content.getComponent("SliderPackA9");
mod3tables[2] = Content.getComponent("SliderPackA10");
mod3tables[3] = Content.getComponent("SliderPackA11");


const var Mod32SPs = []

Mod32SPs[0] = Content.getComponent("ScriptTable3");
Mod32SPs[1] = Content.getComponent("ScriptTableA8");
Mod32SPs[2] = Content.getComponent("ScriptTableA9");
Mod32SPs[3] = Content.getComponent("ScriptTableA10");

const var Stage3 = Content.getComponent("Stage3");


inline function onStage3Control(component, value)
{
	

 for (i = 0; i < mod3tables.length; i++)
        mod3tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod32SPs.length; i++)
               Mod32SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO3.setAttribute(LFO3. morph, value);
};


Content.getComponent("Stage3").setControlCallback(onStage3Control);

const var ModType4 = Content.getComponent("ModType4");
const var Table4 = Content.getComponent("Table4");
const var Step4 = Content.getComponent("Step4");
const var LFO4 = Synth.getModulator("LFO4");

inline function onModType4Control(number, value)
{
	

        Step4.showControl(value);
        Table4.showControl(1-value); 
           
           if(value == 0)
        	{
              LFO4.setAttribute(LFO4.type, 1);
       }
       
       if(value == 1)
             	{
                   LFO4.setAttribute(LFO4.type, 0);
            }
}


Content.getComponent("ModType4").setControlCallback(onModType4Control);

const var mod4tables = []

mod4tables[0] = Content.getComponent("SliderPackA12");
mod4tables[1] = Content.getComponent("SliderPackA13");
mod4tables[2] = Content.getComponent("SliderPackA14");
mod4tables[3] = Content.getComponent("SliderPackA15");


const var Mod4SPs = []

Mod4SPs[0] = Content.getComponent("ScriptTable4");
Mod4SPs[1] = Content.getComponent("ScriptTableA11");
Mod4SPs[2] = Content.getComponent("ScriptTableA12");
Mod4SPs[3] = Content.getComponent("ScriptTableA13");

const var Stage4 = Content.getComponent("Stage4");


inline function onStage4Control(component, value)
{
	

 for (i = 0; i < mod4tables.length; i++)
        mod4tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod4SPs.length; i++)
               Mod4SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO4.setAttribute(LFO4. morph, value);
};


Content.getComponent("Stage4").setControlCallback(onStage4Control);

const var ModType5 = Content.getComponent("ModType5");
const var Table5 = Content.getComponent("Table5");
const var Step5 = Content.getComponent("Step5");
const var LFO5 = Synth.getModulator("LFO5");

inline function onModType5Control(number, value)
{
	

        Step5.showControl(value);
        Table5.showControl(1-value); 
          if(value == 0)
        	{
              LFO5.setAttribute(LFO5.type, 1);
       }
       
       if(value == 1)
             	{
                   LFO5.setAttribute(LFO5.type, 0);
            }
}


Content.getComponent("ModType5").setControlCallback(onModType5Control);

const var mod5tables = []

mod5tables[0] = Content.getComponent("SliderPackA16");
mod5tables[1] = Content.getComponent("SliderPackA17");
mod5tables[2] = Content.getComponent("SliderPackA18");
mod5tables[3] = Content.getComponent("SliderPackA19");


const var Mod5SPs = []

Mod5SPs[0] = Content.getComponent("ScriptTable5");
Mod5SPs[1] = Content.getComponent("ScriptTableA14");
Mod5SPs[2] = Content.getComponent("ScriptTableA15");
Mod5SPs[3] = Content.getComponent("ScriptTableA16");

const var Stage5 = Content.getComponent("Stage5");


inline function onStage5Control(component, value)
{
	

 for (i = 0; i < mod5tables.length; i++)
        mod5tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod5SPs.length; i++)
               Mod5SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO5.setAttribute(LFO5. morph, value);
};


Content.getComponent("Stage5").setControlCallback(onStage5Control);

const var ModType6 = Content.getComponent("ModType6");
const var Table6 = Content.getComponent("Table6");
const var Step6 = Content.getComponent("Step6");
const var LFO6 = Synth.getModulator("LFO6");

inline function onModType6Control(number, value)
{
	

        Step6.showControl(value);
        Table6.showControl(1-value); 
           if(value == 0)
        	{
              LFO6.setAttribute(LFO6.type, 1);
       }
       
       if(value == 1)
             	{
                   LFO6.setAttribute(LFO6.type, 0);
            }
}


Content.getComponent("ModType6").setControlCallback(onModType6Control);

const var mod6tables = []

mod6tables[0] = Content.getComponent("SliderPackA20");
mod6tables[1] = Content.getComponent("SliderPackA21");
mod6tables[2] = Content.getComponent("SliderPackA22");
mod6tables[3] = Content.getComponent("SliderPackA23");


const var Mod6SPs = []

Mod6SPs[0] = Content.getComponent("ScriptTable6");
Mod6SPs[1] = Content.getComponent("ScriptTableA17");
Mod6SPs[2] = Content.getComponent("ScriptTableA18");
Mod6SPs[3] = Content.getComponent("ScriptTableA19");

const var Stage6 = Content.getComponent("Stage6");


inline function onStage6Control(component, value)
{
	

 for (i = 0; i < mod6tables.length; i++)
        mod6tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod6SPs.length; i++)
               Mod6SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO6.setAttribute(LFO6. morph, value);
};


Content.getComponent("Stage6").setControlCallback(onStage6Control);

const var ModType7 = Content.getComponent("ModType7");
const var Table7 = Content.getComponent("Table7");
const var Step7 = Content.getComponent("Step7");
const var LFO7 = Synth.getModulator("LFO7");

inline function onModType7Control(number, value)
{
	

        Step7.showControl(value);
        Table7.showControl(1-value); 
           if(value == 0)
        	{
              LFO7.setAttribute(LFO7.type, 1);
       }
       
       if(value == 1)
             	{
                   LFO7.setAttribute(LFO7.type, 0);
            }
}


Content.getComponent("ModType7").setControlCallback(onModType7Control);

const var mod7tables = []

mod7tables[0] = Content.getComponent("SliderPackA24");
mod7tables[1] = Content.getComponent("SliderPackA25");
mod7tables[2] = Content.getComponent("SliderPackA26");
mod7tables[3] = Content.getComponent("SliderPackA27");


const var Mod7SPs = []

Mod7SPs[0] = Content.getComponent("ScriptTable7");
Mod7SPs[1] = Content.getComponent("ScriptTableA20");
Mod7SPs[2] = Content.getComponent("ScriptTableA21");
Mod7SPs[3] = Content.getComponent("ScriptTableA22");

const var Stage7 = Content.getComponent("Stage7");


inline function onStage7Control(component, value)
{
	

 for (i = 0; i < mod7tables.length; i++)
        mod7tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod7SPs.length; i++)
               Mod7SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO7.setAttribute(LFO7. morph, value);
};


Content.getComponent("Stage7").setControlCallback(onStage7Control);

const var ModType8 = Content.getComponent("ModType8");
const var Table8 = Content.getComponent("Table8");
const var Step8 = Content.getComponent("Step8");
const var LFO8 = Synth.getModulator("LFO8");

inline function onModType8Control(number, value)
{
	

        Step8.showControl(value);
        Table8.showControl(1-value); 
       if(value == 0)
           	{
                 LFO8.setAttribute(LFO8.type, 1);
          }
          
          if(value == 1)
                	{
                      LFO8.setAttribute(LFO8.type, 0);
               }
}


Content.getComponent("ModType8").setControlCallback(onModType8Control);

const var mod8tables = []

mod8tables[0] = Content.getComponent("SliderPackA28");
mod8tables[1] = Content.getComponent("SliderPackA29");
mod8tables[2] = Content.getComponent("SliderPackA30");
mod8tables[3] = Content.getComponent("SliderPackA31");


const var Mod8SPs = []

Mod8SPs[0] = Content.getComponent("ScriptTable8");
Mod8SPs[1] = Content.getComponent("ScriptTableA23");
Mod8SPs[2] = Content.getComponent("ScriptTableA24");
Mod8SPs[3] = Content.getComponent("ScriptTableA25");

const var Stage8 = Content.getComponent("Stage8");


inline function onStage8Control(component, value)
{
	

 for (i = 0; i < mod8tables.length; i++)
        mod8tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod8SPs.length; i++)
               Mod8SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO8.setAttribute(LFO8. morph, value);
};


Content.getComponent("Stage8").setControlCallback(onStage8Control);
const var ModType9 = Content.getComponent("ModType9");
const var Table9 = Content.getComponent("Table9");
const var Step9 = Content.getComponent("Step9");
const var LFO9 = Synth.getModulator("LFO9");

inline function onModType9Control(number, value)
{
	

        Step9.showControl(value);
        Table9.showControl(1-value); 
          if(value == 0)
        	{
              LFO9.setAttribute(LFO9.type, 1);
       }
       
       if(value == 1)
             	{
                   LFO9.setAttribute(LFO9.type, 0);
            }
}


Content.getComponent("ModType9").setControlCallback(onModType9Control);

const var mod9tables = []

mod9tables[0] = Content.getComponent("SliderPackA32");
mod9tables[1] = Content.getComponent("SliderPackA33");
mod9tables[2] = Content.getComponent("SliderPackA34");
mod9tables[3] = Content.getComponent("SliderPackA35");


const var Mod9SPs = []

Mod9SPs[0] = Content.getComponent("ScriptTable9");
Mod9SPs[1] = Content.getComponent("ScriptTableA26");
Mod9SPs[2] = Content.getComponent("ScriptTableA27");
Mod9SPs[3] = Content.getComponent("ScriptTableA28");

const var Stage9 = Content.getComponent("Stage9");


inline function onStage9Control(component, value)
{
	

 for (i = 0; i < mod9tables.length; i++)
        mod9tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod9SPs.length; i++)
               Mod9SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO9.setAttribute(LFO9. morph, value);
};


Content.getComponent("Stage9").setControlCallback(onStage9Control);

const var ModType10 = Content.getComponent("ModType10");
const var Table10 = Content.getComponent("Table10");
const var Step10 = Content.getComponent("Step10");
const var LFO10 = Synth.getModulator("LFO10");

inline function onModType10Control(number, value)
{
	

        Step10.showControl(value);
        Table10.showControl(1-value); 
            if(value == 0)
        	{
              LFO10.setAttribute(LFO10.type, 1);
       }
       
       if(value == 1)
             	{
                   LFO10.setAttribute(LFO10.type, 0);
            }
}


Content.getComponent("ModType10").setControlCallback(onModType10Control);

const var mod10tables = []

mod10tables[0] = Content.getComponent("SliderPackA36");
mod10tables[1] = Content.getComponent("SliderPackA37");
mod10tables[2] = Content.getComponent("SliderPackA38");
mod10tables[3] = Content.getComponent("SliderPackA39");


const var Mod10SPs = []

Mod10SPs[0] = Content.getComponent("ScriptTable10");
Mod10SPs[1] = Content.getComponent("ScriptTableA29");
Mod10SPs[2] = Content.getComponent("ScriptTableA30");
Mod10SPs[3] = Content.getComponent("ScriptTableA31");

const var Stage10 = Content.getComponent("Stage10");


inline function onStage10Control(component, value)
{
	

 for (i = 0; i < mod10tables.length; i++)
        mod10tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod10SPs.length; i++)
               Mod10SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO10.setAttribute(LFO10. morph, value);
};


Content.getComponent("Stage10").setControlCallback(onStage10Control);

const var ModType11 = Content.getComponent("ModType11");
const var Table11 = Content.getComponent("Table11");
const var Step11 = Content.getComponent("Step11");
const var LFO11 = Synth.getModulator("LFO11");

inline function onModType11Control(number, value)
{
	

        Step11.showControl(value);
        Table11.showControl(1-value); 
       if(value == 0)
        	{
              LFO11.setAttribute(LFO11.type, 1);
       }
       
       if(value == 1)
             	{
                   LFO11.setAttribute(LFO11.type, 0);
            }
}


Content.getComponent("ModType11").setControlCallback(onModType11Control);

const var mod11tables = []

mod11tables[0] = Content.getComponent("SliderPackA40");
mod11tables[1] = Content.getComponent("SliderPackA41");
mod11tables[2] = Content.getComponent("SliderPackA42");
mod11tables[3] = Content.getComponent("SliderPackA43");


const var Mod11SPs = []

Mod11SPs[0] = Content.getComponent("ScriptTable11");
Mod11SPs[1] = Content.getComponent("ScriptTableA32");
Mod11SPs[2] = Content.getComponent("ScriptTableA33");
Mod11SPs[3] = Content.getComponent("ScriptTableA34");

const var Stage11 = Content.getComponent("Stage11");


inline function onStage11Control(component, value)
{
	

 for (i = 0; i < mod11tables.length; i++)
        mod11tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod11SPs.length; i++)
               Mod11SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO11.setAttribute(LFO11. morph, value);
};


Content.getComponent("Stage11").setControlCallback(onStage11Control);
const var ModType12 = Content.getComponent("ModType12");
const var Table12 = Content.getComponent("Table12");
const var Step12 = Content.getComponent("Step12");
const var LFO12 = Synth.getModulator("LFO12");

inline function onModType12Control(number, value)
{
	

        Step12.showControl(value);
        Table12.showControl(1-value); 
          if(value == 0)
        	{
              LFO12.setAttribute(LFO12.type, 1);
       }
       
       if(value == 1)
             	{
                   LFO12.setAttribute(LFO12.type, 0);
            }
}


Content.getComponent("ModType12").setControlCallback(onModType12Control);

const var mod12tables = []

mod12tables[0] = Content.getComponent("SliderPackA44");
mod12tables[1] = Content.getComponent("SliderPackA45");
mod12tables[2] = Content.getComponent("SliderPackA46");
mod12tables[3] = Content.getComponent("SliderPackA47");


const var Mod12SPs = []

Mod12SPs[0] = Content.getComponent("ScriptTable12");
Mod12SPs[1] = Content.getComponent("ScriptTableA35");
Mod12SPs[2] = Content.getComponent("ScriptTableA36");
Mod12SPs[3] = Content.getComponent("ScriptTableA37");

const var Stage12 = Content.getComponent("Stage12");

inline function onStage12Control(component, value)
{
	

 for (i = 0; i < mod12tables.length; i++)
        mod12tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod12SPs.length; i++)
               Mod12SPs[i].fadeComponent(value - 1 == i, 1500);
        
        LFO12.setAttribute(LFO12. morph, value);
};


Content.getComponent("Stage12").setControlCallback(onStage12Control);

// External triggers are relevant only when the LFO uses its trigger branch.
const var TrigSel1 = Content.getComponent("TrigSel1");
const var ExtTrig1 = Content.getComponent("ExtTrig1");
const var TrigSel2 = Content.getComponent("TrigSel2");
const var ExtTrig2 = Content.getComponent("ExtTrig2");
const var TrigSel3 = Content.getComponent("TrigSel3");
const var ExtTrig3 = Content.getComponent("ExtTrig3");
const var TrigSel4 = Content.getComponent("TrigSel4");
const var ExtTrig4 = Content.getComponent("ExtTrig4");
const var TrigSel5 = Content.getComponent("TrigSel5");
const var ExtTrig5 = Content.getComponent("ExtTrig5");
const var TrigSel6 = Content.getComponent("TrigSel6");
const var ExtTrig6 = Content.getComponent("ExtTrig6");
const var TrigSel7 = Content.getComponent("TrigSel7");
const var ExtTrig7 = Content.getComponent("ExtTrig7");
const var TrigSel8 = Content.getComponent("TrigSel8");
const var ExtTrig8 = Content.getComponent("ExtTrig8");
const var TrigSel9 = Content.getComponent("TrigSel9");
const var ExtTrig9 = Content.getComponent("ExtTrig9");
const var TrigSel10 = Content.getComponent("TrigSel10");
const var ExtTrig10 = Content.getComponent("ExtTrig10");
const var TrigSel11 = Content.getComponent("TrigSel11");
const var ExtTrig11 = Content.getComponent("ExtTrig11");
const var TrigSel12 = Content.getComponent("TrigSel12");
const var ExtTrig12 = Content.getComponent("ExtTrig12");

inline function onTrigSel1Control(component, value) { LFO1.setAttribute(LFO1.keysync, value); ExtTrig1.showControl(value == 4); }
inline function onTrigSel2Control(component, value) { LFO2.setAttribute(LFO2.keysync, value); ExtTrig2.showControl(value == 4); }
inline function onTrigSel3Control(component, value) { LFO3.setAttribute(LFO3.keysync, value); ExtTrig3.showControl(value == 4); }
inline function onTrigSel4Control(component, value) { LFO4.setAttribute(LFO4.keysync, value); ExtTrig4.showControl(value == 4); }
inline function onTrigSel5Control(component, value) { LFO5.setAttribute(LFO5.keysync, value); ExtTrig5.showControl(value == 4); }
inline function onTrigSel6Control(component, value) { LFO6.setAttribute(LFO6.keysync, value); ExtTrig6.showControl(value == 4); }
inline function onTrigSel7Control(component, value) { LFO7.setAttribute(LFO7.keysync, value); ExtTrig7.showControl(value == 4); }
inline function onTrigSel8Control(component, value) { LFO8.setAttribute(LFO8.keysync, value); ExtTrig8.showControl(value == 4); }
inline function onTrigSel9Control(component, value) { LFO9.setAttribute(LFO9.keysync, value); ExtTrig9.showControl(value == 4); }
inline function onTrigSel10Control(component, value) { LFO10.setAttribute(LFO10.keysync, value); ExtTrig10.showControl(value == 4); }
inline function onTrigSel11Control(component, value) { LFO11.setAttribute(LFO11.keysync, value); ExtTrig11.showControl(value == 4); }
inline function onTrigSel12Control(component, value) { LFO12.setAttribute(LFO12.keysync, value); ExtTrig12.showControl(value == 4); }

inline function onExtTrig1Control(component, value) { LFO1.setAttribute(LFO1.ExtTrig, value); }
inline function onExtTrig2Control(component, value) { LFO2.setAttribute(LFO2.ExtTrig, value); }
inline function onExtTrig3Control(component, value) { LFO3.setAttribute(LFO3.ExtTrig, value); }
inline function onExtTrig4Control(component, value) { LFO4.setAttribute(LFO4.ExtTrig, value); }
inline function onExtTrig5Control(component, value) { LFO5.setAttribute(LFO5.ExtTrig, value); }
inline function onExtTrig6Control(component, value) { LFO6.setAttribute(LFO6.ExtTrig, value); }
inline function onExtTrig7Control(component, value) { LFO7.setAttribute(LFO7.ExtTrig, value); }
inline function onExtTrig8Control(component, value) { LFO8.setAttribute(LFO8.ExtTrig, value); }
inline function onExtTrig9Control(component, value) { LFO9.setAttribute(LFO9.ExtTrig, value); }
inline function onExtTrig10Control(component, value) { LFO10.setAttribute(LFO10.ExtTrig, value); }
inline function onExtTrig11Control(component, value) { LFO11.setAttribute(LFO11.ExtTrig, value); }
inline function onExtTrig12Control(component, value) { LFO12.setAttribute(LFO12.ExtTrig, value); }

TrigSel1.setControlCallback(onTrigSel1Control);
TrigSel2.setControlCallback(onTrigSel2Control);
TrigSel3.setControlCallback(onTrigSel3Control);
TrigSel4.setControlCallback(onTrigSel4Control);
TrigSel5.setControlCallback(onTrigSel5Control);
TrigSel6.setControlCallback(onTrigSel6Control);
TrigSel7.setControlCallback(onTrigSel7Control);
TrigSel8.setControlCallback(onTrigSel8Control);
TrigSel9.setControlCallback(onTrigSel9Control);
TrigSel10.setControlCallback(onTrigSel10Control);
TrigSel11.setControlCallback(onTrigSel11Control);
TrigSel12.setControlCallback(onTrigSel12Control);

ExtTrig1.setControlCallback(onExtTrig1Control);
ExtTrig2.setControlCallback(onExtTrig2Control);
ExtTrig3.setControlCallback(onExtTrig3Control);
ExtTrig4.setControlCallback(onExtTrig4Control);
ExtTrig5.setControlCallback(onExtTrig5Control);
ExtTrig6.setControlCallback(onExtTrig6Control);
ExtTrig7.setControlCallback(onExtTrig7Control);
ExtTrig8.setControlCallback(onExtTrig8Control);
ExtTrig9.setControlCallback(onExtTrig9Control);
ExtTrig10.setControlCallback(onExtTrig10Control);
ExtTrig11.setControlCallback(onExtTrig11Control);
ExtTrig12.setControlCallback(onExtTrig12Control);

TrigSel1.changed();
TrigSel2.changed();
TrigSel3.changed();
TrigSel4.changed();
TrigSel5.changed();
TrigSel6.changed();
TrigSel7.changed();
TrigSel8.changed();
TrigSel9.changed();
TrigSel10.changed();
TrigSel11.changed();
TrigSel12.changed();

ExtTrig1.changed();
ExtTrig2.changed();
ExtTrig3.changed();
ExtTrig4.changed();
ExtTrig5.changed();
ExtTrig6.changed();
ExtTrig7.changed();
ExtTrig8.changed();
ExtTrig9.changed();
ExtTrig10.changed();
ExtTrig11.changed();
ExtTrig12.changed();

const var EnvDisplayA1 = Content.getComponent("EnvDisplayA1");
const var EnvPeak1 = Content.getComponent("EnvPeak1");
const var TrigPeak1 = Content.getComponent("TrigPeak1");
const var TrigPeakLabel1 = Content.getComponent("TrigPeakLabel1");
const var EnvLoopLabel1 = Content.getComponent("EnvLoopLabel5");
const var EnvLoop1 = Content.getComponent("EnvLoop1");
const var EnvVoiceSel1 = Content.getComponent("EnvVoiceSel5");


const var ENV1 = Synth.getModulator("ENV1");




const var ModPages = []
                      
ModPages[0] = Content.getComponent("MOD1");
ModPages[1] = Content.getComponent("MOD2");
ModPages[2] = Content.getComponent("MOD3");
ModPages[3] = Content.getComponent("MOD4");
ModPages[4] = Content.getComponent("MOD5");


inline function onModPageControl(component, value)
{
	

for (i = 0; i < ModPages.length; i++)
        ModPages[i].fadeComponent(value - 1 == i, 500);
};

Content.getComponent("ModPage").setControlCallback(onModPageControl);


const var dp = Synth.getDisplayBufferSource("ENV1");
const var dpTr = Synth.getDisplayBufferSource("Track1");


const var rb = dpTr.getDisplayBuffer(1);
const var rb1 = dpTr.getDisplayBuffer(2);


const var BUFFER_LENGTH = 16384;


const var properties = {
  "BufferLength": BUFFER_LENGTH,
  "NumChannels": 1
};

//env peak

rb.setRingBufferProperties(properties);



//env dispA

rb1.setRingBufferProperties(properties);


EnvDisplayA1.setTimerCallback(function()
{

	this.data.buffer = rb1.createPath(this.getLocalBounds(0), 
									 [0, BUFFER_LENGTH, 0, 1.0],
									 0.0 
									 );
	this.repaint();
});

EnvDisplayA1.startTimer(300);

EnvDisplayA1.setPaintRoutine(function(g)
{
	g.fillAll(0xFFF6995C);
	g.setColour(0xFFBFCCFB);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

var dpB = Synth.getDisplayBufferSource("ENV2");
var dpTrB = Synth.getDisplayBufferSource("Track2");

const var rbB = dpTrB.getDisplayBuffer(1);
const var rbB1 = dpTrB.getDisplayBuffer(2);


//env peak



//env dispA

rbB1.setRingBufferProperties(properties);

const var EnvDisplayA2 = Content.getComponent("EnvDisplayA2");



EnvDisplayA2.setTimerCallback(function()
{

	this.data.buffer = rbB1.createPath(this.getLocalBounds(0), 
									 [0, BUFFER_LENGTH, 0, 1.0],
									 0.0 
									 );
	this.repaint();
});

EnvDisplayA2.startTimer(300);

EnvDisplayA2.setPaintRoutine(function(g)
{
	g.fillAll(0xFFF6995C);
	g.setColour(0xFFBFCCFB);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});


var dpC = Synth.getDisplayBufferSource("ENV3");
var dpTrC = Synth.getDisplayBufferSource("Track3");

const var rbC = dpTrC.getDisplayBuffer(1);
const var rbC1 = dpTrC.getDisplayBuffer(2);


//env peak

rbC.setRingBufferProperties(properties);

const var EnvPeak3 = Content.getComponent("EnvPeak3");
const var EnvDisplayA3 = Content.getComponent("EnvDisplayA3");





//env dispA

rbC1.setRingBufferProperties(properties);


EnvDisplayA3.setTimerCallback(function()
{

	this.data.buffer = rbC1.createPath(this.getLocalBounds(0), 
									 [0, BUFFER_LENGTH, 0, 1.0],
									 0.0 
									 );
	this.repaint();
});

EnvDisplayA3.startTimer(300);

EnvDisplayA3.setPaintRoutine(function(g)
{
	g.fillAll(0xFFF6995C);
	g.setColour(0xFFBFCCFB);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

var dpD = Synth.getDisplayBufferSource("ENV4");
var dpDTr = Synth.getDisplayBufferSource("Track4");

const var rbD = dpDTr.getDisplayBuffer(1);
const var rbD1 = dpDTr.getDisplayBuffer(2);


//env peak

rbD.setRingBufferProperties(properties);
const var EnvPeak4 = Content.getComponent("EnvPeak4");
const var EnvDisplayA4 = Content.getComponent("EnvDisplayA4");


//env dispA

rbD1.setRingBufferProperties(properties);


EnvDisplayA4.setTimerCallback(function()
{

	this.data.buffer = rbD1.createPath(this.getLocalBounds(0), 
									 [0, BUFFER_LENGTH, 0, 1.0],
									 0.0 
									 );
	this.repaint();
});

EnvDisplayA4.startTimer(300);

EnvDisplayA4.setPaintRoutine(function(g)
{
	g.fillAll(0xFFF6995C);
	g.setColour(0xFFBFCCFB);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

const var laf = Content.createLocalLookAndFeel();

//FLEX ENVS
laf.registerFunction("drawFlexAhdsrBackground", function(g, obj)
{
	g.fillAll(0xFFC96868);
});

laf.registerFunction("drawFlexAhdsrFullPath", function(g, obj)
{
	g.setColour(0xFFF6995C);
	g.drawPath(obj.path, obj.pathArea, 2.0);
});

laf.registerFunction("drawFlexAhdsrCurvePoint", function(g, obj)
{
	g.setColour(0xFFBFCCFB);
	g.fillEllipse([obj.curvePoint[0] -5, obj.curvePoint[1] - 5, 10, 10]);
});

laf.registerFunction("drawFlexAhdsrSegment", function(g, obj)
{
	g.setColour(obj.active ? 0xFF7EACB5 : 0x14058294);
	g.fillPath(obj.path, Rectangle(obj.area));
});

laf.registerFunction("drawFlexAhdsrPosition", function(g, obj)
{
	g.setColour(Colours.white);
	g.fillEllipse([obj.pointOnPath[0] -3, obj.pointOnPath[1] - 3, 6, 6]);
});

Content.getComponent("EnvDisplayB5").setLocalLookAndFeel(laf);
Content.getComponent("EnvDisplayB6").setLocalLookAndFeel(laf);
Content.getComponent("EnvDisplayB7").setLocalLookAndFeel(laf);
Content.getComponent("EnvDisplayB8").setLocalLookAndFeel(laf);
