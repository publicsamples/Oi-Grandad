//show hide env params
const var ModType1 = Content.getComponent("ModType1");
const var button1 = Content.getComponent("ModType1");
const var table1 = Content.getComponent("Table1");
const var step1 = Content.getComponent("Step1");
const var s1 = Synth.getModulator("s1");
inline function onModType1Control(number, value)
{
        step1.showControl(value);
        table1.showControl(1-value); 
        s1.setAttribute(s1.type, value);
 
}


button1.setControlCallback(onModType1Control);

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
        
        s1.setAttribute(s1. morph, value);
};


Content.getComponent("Stage1").setControlCallback(onStage1Control);

const var ModType2 = Content.getComponent("ModType2");
const var button2 = Content.getComponent("ModType2");
const var table2 = Content.getComponent("Table2");
const var step2 = Content.getComponent("Step2");
const var s2 = Synth.getModulator("s2");

inline function onModType2Control(number, value)
{
        step2.showControl(value);
        table2.showControl(1-value); 
        s2.setAttribute(s2.type, 1-value);
        s2.setAttribute(s2.type, 0);
}


button2.setControlCallback(onModType2Control);

const var mod2tables = []

mod2tables[0] = Content.getComponent("SliderPackB");
mod2tables[1] = Content.getComponent("SliderPackB1");
mod2tables[2] = Content.getComponent("SliderPackB2");
mod2tables[3] = Content.getComponent("SliderPackB3");


const var Mod2SPs = []

Mod2SPs[0] = Content.getComponent("ScriptTable2");
Mod2SPs[1] = Content.getComponent("ScriptTableB2");
Mod2SPs[2] = Content.getComponent("ScriptTableB3");
Mod2SPs[3] = Content.getComponent("ScriptTableB4");

const var Stage2 = Content.getComponent("Stage2");


inline function onStage2Control(component, value)
{
 for (i = 0; i < mod2tables.length; i++)
        mod2tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod2SPs.length; i++)
               Mod2SPs[i].fadeComponent(value - 1 == i, 1500);
        
        s2.setAttribute(s2. morph, value);
};


Content.getComponent("Stage2").setControlCallback(onStage2Control);

const var ModType3 = Content.getComponent("ModType3");
const var button3 = Content.getComponent("ModType3");
const var table3 = Content.getComponent("Table3");
const var step3 = Content.getComponent("Step3");
const var s3 = Synth.getModulator("s3");

inline function onModType3Control(number, value)
{
        step3.showControl(value);
        table3.showControl(1-value); 
        s3.setAttribute(s3.type, 1-value);
        s3.setAttribute(s3.type, 0);
}


button3.setControlCallback(onModType3Control);

const var mod3tables = []

mod3tables[0] = Content.getComponent("SliderPackC");
mod3tables[1] = Content.getComponent("SliderPackC1");
mod3tables[2] = Content.getComponent("SliderPackC2");
mod3tables[3] = Content.getComponent("SliderPackC3");


const var Mod32SPs = []

Mod32SPs[0] = Content.getComponent("ScriptTable3");
Mod32SPs[1] = Content.getComponent("ScriptTableC2");
Mod32SPs[2] = Content.getComponent("ScriptTableC3");
Mod32SPs[3] = Content.getComponent("ScriptTableC4");

const var Stage3 = Content.getComponent("Stage3");


inline function onStage3Control(component, value)
{
 for (i = 0; i < mod3tables.length; i++)
        mod3tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod32SPs.length; i++)
               Mod32SPs[i].fadeComponent(value - 1 == i, 1500);
        
        s3.setAttribute(s3. morph, value);
};


Content.getComponent("Stage3").setControlCallback(onStage3Control);

const var ModType4 = Content.getComponent("ModType4");
const var Table4 = Content.getComponent("Table4");
const var Step4 = Content.getComponent("Step4");
const var s4 = Synth.getModulator("s4");

inline function onModType4Control(number, value)
{
        Step4.showControl(value);
        Table4.showControl(1-value); 
        s4.setAttribute(s4.type, 1-value);
        s4.setAttribute(s4.type, 0);
}


ModType4.setControlCallback(onModType4Control);

const var mod4tables = []

mod4tables[0] = Content.getComponent("SliderPackD");
mod4tables[1] = Content.getComponent("SliderPackD1");
mod4tables[2] = Content.getComponent("SliderPackD2");
mod4tables[3] = Content.getComponent("SliderPackD3");


const var Mod4SPs = []

Mod4SPs[0] = Content.getComponent("ScriptTable4");
Mod4SPs[1] = Content.getComponent("ScriptTableD1");
Mod4SPs[2] = Content.getComponent("ScriptTableD2");
Mod4SPs[3] = Content.getComponent("ScriptTableD3");

const var Stage4 = Content.getComponent("Stage4");


inline function onStage4Control(component, value)
{
 for (i = 0; i < mod4tables.length; i++)
        mod4tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod4SPs.length; i++)
               Mod4SPs[i].fadeComponent(value - 1 == i, 1500);
        
        s4.setAttribute(s4. morph, value);
};


Content.getComponent("Stage4").setControlCallback(onStage4Control);

const var ModType5 = Content.getComponent("ModType5");
const var Table5 = Content.getComponent("Table5");
const var Step5 = Content.getComponent("Step5");
const var s5 = Synth.getModulator("s5");

inline function onModType5Control(number, value)
{
        Step5.showControl(value);
        Table5.showControl(1-value); 
        s5.setAttribute(s5.type, 1-value);
        s5.setAttribute(s5.type, 0);
}


ModType5.setControlCallback(onModType5Control);

const var mod5tables = []

mod5tables[0] = Content.getComponent("SliderPackE");
mod5tables[1] = Content.getComponent("SliderPackE1");
mod5tables[2] = Content.getComponent("SliderPackE2");
mod5tables[3] = Content.getComponent("SliderPackE3");


const var Mod5SPs = []

Mod5SPs[0] = Content.getComponent("ScriptTable5");
Mod5SPs[1] = Content.getComponent("ScriptTableE2");
Mod5SPs[2] = Content.getComponent("ScriptTableE3");
Mod5SPs[3] = Content.getComponent("ScriptTableE4");

const var Stage5 = Content.getComponent("Stage5");


inline function onStage5Control(component, value)
{
 for (i = 0; i < mod5tables.length; i++)
        mod5tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod5SPs.length; i++)
               Mod5SPs[i].fadeComponent(value - 1 == i, 1500);
        
        s5.setAttribute(s5. morph, value);
};


Content.getComponent("Stage5").setControlCallback(onStage5Control);

const var ModType6 = Content.getComponent("ModType6");
const var Table6 = Content.getComponent("Table6");
const var Step6 = Content.getComponent("Step6");
const var s6 = Synth.getModulator("s6");

inline function onModType6Control(number, value)
{
        Step6.showControl(value);
        Table6.showControl(1-value); 
        s6.setAttribute(s6.type, 1-value);
        s6.setAttribute(s6.type, 0);
}


ModType6.setControlCallback(onModType6Control);

const var mod6tables = []

mod6tables[0] = Content.getComponent("SliderPackF");
mod6tables[1] = Content.getComponent("SliderPackF1");
mod6tables[2] = Content.getComponent("SliderPackF2");
mod6tables[3] = Content.getComponent("SliderPackF3");


const var Mod6SPs = []

Mod6SPs[0] = Content.getComponent("ScriptTable6");
Mod6SPs[1] = Content.getComponent("ScriptTableF2");
Mod6SPs[2] = Content.getComponent("ScriptTableF3");
Mod6SPs[3] = Content.getComponent("ScriptTableF4");

const var Stage6 = Content.getComponent("Stage6");


inline function onStage6Control(component, value)
{
 for (i = 0; i < mod6tables.length; i++)
        mod6tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod6SPs.length; i++)
               Mod6SPs[i].fadeComponent(value - 1 == i, 1500);
        
        s6.setAttribute(s6. morph, value);
};


Content.getComponent("Stage6").setControlCallback(onStage6Control);

const var ModType7 = Content.getComponent("ModType7");
const var Table7 = Content.getComponent("Table7");
const var Step7 = Content.getComponent("Step7");
const var s7 = Synth.getModulator("s7");

inline function onModType7Control(number, value)
{
        Step7.showControl(value);
        Table7.showControl(1-value); 
        s7.setAttribute(s7.type, 1-value);
        s7.setAttribute(s7.type, 0);
}


ModType7.setControlCallback(onModType7Control);

const var mod7tables = []

mod7tables[0] = Content.getComponent("SliderPackG");
mod7tables[1] = Content.getComponent("SliderPackG1");
mod7tables[2] = Content.getComponent("SliderPackG2");
mod7tables[3] = Content.getComponent("SliderPackG3");


const var Mod7SPs = []

Mod7SPs[0] = Content.getComponent("ScriptTable7");
Mod7SPs[1] = Content.getComponent("ScriptTableG2");
Mod7SPs[2] = Content.getComponent("ScriptTableG3");
Mod7SPs[3] = Content.getComponent("ScriptTableG4");

const var Stage7 = Content.getComponent("Stage7");


inline function onStage7Control(component, value)
{
 for (i = 0; i < mod7tables.length; i++)
        mod7tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod7SPs.length; i++)
               Mod7SPs[i].fadeComponent(value - 1 == i, 1500);
        
        s7.setAttribute(s7. morph, value);
};


Content.getComponent("Stage7").setControlCallback(onStage7Control);

const var ModType8 = Content.getComponent("ModType8");
const var Table8 = Content.getComponent("Table8");
const var Step8 = Content.getComponent("Step8");
const var s8 = Synth.getModulator("s8");

inline function onModType8Control(number, value)
{
        Step8.showControl(value);
        Table8.showControl(1-value); 
        s8.setAttribute(s8.type, 1-value);
        s8.setAttribute(s8.type, 0);
}


ModType8.setControlCallback(onModType8Control);

const var mod8tables = []

mod8tables[0] = Content.getComponent("SliderPackH");
mod8tables[1] = Content.getComponent("SliderPackH1");
mod8tables[2] = Content.getComponent("SliderPackH2");
mod8tables[3] = Content.getComponent("SliderPackH3");


const var Mod8SPs = []

Mod8SPs[0] = Content.getComponent("ScriptTable8");
Mod8SPs[1] = Content.getComponent("ScriptTableH2");
Mod8SPs[2] = Content.getComponent("ScriptTableH3");
Mod8SPs[3] = Content.getComponent("ScriptTableH4");

const var Stage8 = Content.getComponent("Stage8");


inline function onStage8Control(component, value)
{
 for (i = 0; i < mod8tables.length; i++)
        mod8tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod8SPs.length; i++)
               Mod8SPs[i].fadeComponent(value - 1 == i, 1500);
        
        s8.setAttribute(s8. morph, value);
};


Content.getComponent("Stage8").setControlCallback(onStage8Control);
const var ModType9 = Content.getComponent("ModType9");
const var Table9 = Content.getComponent("Table9");
const var Step9 = Content.getComponent("Step9");
const var s9 = Synth.getModulator("s9");

inline function onModType9Control(number, value)
{
        Step9.showControl(value);
        Table9.showControl(1-value); 
        s9.setAttribute(s9.type, 1-value);
        s9.setAttribute(s9.type, 0);
}


ModType9.setControlCallback(onModType9Control);

const var mod9tables = []

mod9tables[0] = Content.getComponent("SliderPackI");
mod9tables[1] = Content.getComponent("SliderPackI1");
mod9tables[2] = Content.getComponent("SliderPackI2");
mod9tables[3] = Content.getComponent("SliderPackI3");


const var Mod9SPs = []

Mod9SPs[0] = Content.getComponent("ScriptTable9");
Mod9SPs[1] = Content.getComponent("ScriptTableI2");
Mod9SPs[2] = Content.getComponent("ScriptTableI3");
Mod9SPs[3] = Content.getComponent("ScriptTableI4");

const var Stage9 = Content.getComponent("Stage9");


inline function onStage9Control(component, value)
{
 for (i = 0; i < mod9tables.length; i++)
        mod9tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod9SPs.length; i++)
               Mod9SPs[i].fadeComponent(value - 1 == i, 1500);
        
        s9.setAttribute(s9. morph, value);
};


Content.getComponent("Stage9").setControlCallback(onStage9Control);

const var ModType10 = Content.getComponent("ModType10");
const var Table10 = Content.getComponent("Table10");
const var Step10 = Content.getComponent("Step10");
const var s10 = Synth.getModulator("s10");

inline function onModType10Control(number, value)
{
        Step10.showControl(value);
        Table10.showControl(1-value); 
        s10.setAttribute(s10.type, 1-value);
        s10.setAttribute(s10.type, 0);
}


ModType10.setControlCallback(onModType10Control);

const var mod10tables = []

mod10tables[0] = Content.getComponent("SliderPackJ");
mod10tables[1] = Content.getComponent("SliderPackJ1");
mod10tables[2] = Content.getComponent("SliderPackJ2");
mod10tables[3] = Content.getComponent("SliderPackJ3");


const var Mod10SPs = []

Mod10SPs[0] = Content.getComponent("ScriptTable10");
Mod10SPs[1] = Content.getComponent("ScriptTableJ2");
Mod10SPs[2] = Content.getComponent("ScriptTableJ3");
Mod10SPs[3] = Content.getComponent("ScriptTableJ4");

const var Stage10 = Content.getComponent("Stage10");


inline function onStage10Control(component, value)
{
 for (i = 0; i < mod10tables.length; i++)
        mod10tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod10SPs.length; i++)
               Mod10SPs[i].fadeComponent(value - 1 == i, 1500);
        
        s10.setAttribute(s10. morph, value);
};


Content.getComponent("Stage10").setControlCallback(onStage10Control);

const var ModType11 = Content.getComponent("ModType11");
const var Table11 = Content.getComponent("Table11");
const var Step11 = Content.getComponent("Step11");
const var s11 = Synth.getModulator("s11");

inline function onModType11Control(number, value)
{
        Step11.showControl(value);
        Table11.showControl(1-value); 
        s11.setAttribute(s11.type, 1-value);
        s11.setAttribute(s11.type, 0);
}


ModType11.setControlCallback(onModType11Control);

const var mod11tables = []

mod11tables[0] = Content.getComponent("SliderPackK");
mod11tables[1] = Content.getComponent("SliderPackK1");
mod11tables[2] = Content.getComponent("SliderPackK2");
mod11tables[3] = Content.getComponent("SliderPackK3");


const var Mod11SPs = []

Mod11SPs[0] = Content.getComponent("ScriptTable11");
Mod11SPs[1] = Content.getComponent("ScriptTableK2");
Mod11SPs[2] = Content.getComponent("ScriptTableK3");
Mod11SPs[3] = Content.getComponent("ScriptTableK4");

const var Stage11 = Content.getComponent("Stage11");


inline function onStage11Control(component, value)
{
 for (i = 0; i < mod11tables.length; i++)
        mod11tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod11SPs.length; i++)
               Mod11SPs[i].fadeComponent(value - 1 == i, 1500);
        
        s11.setAttribute(s11. morph, value);
};


Content.getComponent("Stage11").setControlCallback(onStage11Control);
const var ModType12 = Content.getComponent("ModType12");
const var Table12 = Content.getComponent("Table12");
const var Step12 = Content.getComponent("Step12");
const var s12 = Synth.getModulator("s12");

inline function onModType12Control(number, value)
{
        Step12.showControl(value);
        Table12.showControl(1-value); 
        s12.setAttribute(s12.type, 1-value);
        s12.setAttribute(s12.type, 0);
}


ModType12.setControlCallback(onModType12Control);

const var mod12tables = []

mod12tables[0] = Content.getComponent("SliderPackL");
mod12tables[1] = Content.getComponent("SliderPackL1");
mod12tables[2] = Content.getComponent("SliderPackL2");
mod12tables[3] = Content.getComponent("SliderPackL3");


const var Mod12SPs = []

Mod12SPs[0] = Content.getComponent("ScriptTable12");
Mod12SPs[1] = Content.getComponent("ScriptTableL2");
Mod12SPs[2] = Content.getComponent("ScriptTableL3");
Mod12SPs[3] = Content.getComponent("ScriptTableL4");

const var Stage12 = Content.getComponent("Stage12");


inline function onStage12Control(component, value)
{
 for (i = 0; i < mod12tables.length; i++)
        mod12tables[i].fadeComponent(value - 1 == i, 500);
        
  for (i = 0; i < Mod12SPs.length; i++)
               Mod12SPs[i].fadeComponent(value - 1 == i, 1500);
        
        s12.setAttribute(s12. morph, value);
};


Content.getComponent("Stage12").setControlCallback(onStage12Control);

const var ModPages = []
                      
ModPages[0] = Content.getComponent("MOD1");
ModPages[1] = Content.getComponent("MOD2");
ModPages[2] = Content.getComponent("MOD3");


inline function onModPageControl(component, value)
{
for (i = 0; i < ModPages.length; i++)
        ModPages[i].fadeComponent(value - 1 == i, 500);
};

Content.getComponent("ModPage").setControlCallback(onModPageControl);

