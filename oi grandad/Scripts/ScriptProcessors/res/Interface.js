Content.makeFrontInterface(600, 600);

      

const EqQ = Engine.createAndRegisterSliderPackData(0);     
const var EqQSp = Synth.getSliderPackProcessor("Reso").getSliderPack(1);
EqQ.linkTo(EqQSp);
        
const var EqReso =[];

for (i = 0; i < 8; i++)
{
    EqReso[i] = Content.getComponent("EqRes"+(i+1));
    EqReso[i].setControlCallback(EqQMode);
}
     
     inline function EqQMode(component, value)
     {    
         local idx = EqReso.indexOf(component); 
        
         {  
         
         	EqQ.setValueWithUndo(idx, value);
       
     }
     
}     

const EqGain = Engine.createAndRegisterSliderPackData(0);     
const var EqGainSp = Synth.getSliderPackProcessor("Reso").getSliderPack(2);
EqGain.linkTo(EqGainSp);
        
const var gainEq =[];

for (i = 0; i < 8; i++)
{
    gainEq[i] = Content.getComponent("EqGain"+(i+1));
    gainEq[i].setControlCallback(EqGainMode);
}
     
     inline function EqGainMode(component, value)
     {    
         local idx = gainEq.indexOf(component); 
        
         {  
         
         	EqGain.setValueWithUndo(idx, value);
       
     }
     
}       function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 