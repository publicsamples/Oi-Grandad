Content.makeFrontInterface(900, 800);
 const var muters = [[Synth.getMidiProcessor("MidiMuter1"), Synth.getMidiProcessor("MidiMuter5")],
                     [Synth.getMidiProcessor("MidiMuter2"), Synth.getMidiProcessor("MidiMuter6")],
                     [Synth.getMidiProcessor("MidiMuter3"), Synth.getMidiProcessor("MidiMuter7")],
                     [Synth.getMidiProcessor("MidiMuter4"), Synth.getMidiProcessor("MidiMuter8")]]
                 
 reg rrIndex = 0;    
 
 function onNoteOn()
 {
     local index = 0;
     
 	for(pair in muters)
     {
         for(m in pair)
         {
             m.setAttribute(0, rrIndex != index);
         }
         
         // Move the incrementation here or it will be incremented 6 times instead of two
         index++;
     }
     
     rrIndex++;
     
     if(rrIndex == muters.length)
         rrIndex = 0;
 }function onNoteOff()
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
 