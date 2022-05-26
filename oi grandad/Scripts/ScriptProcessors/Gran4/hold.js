Content.makeFrontInterface(900, 800); 

inline function onHold1Control(component, value)

 {
     if (value)
 	    Synth.playNote(60, 127);
 	  else
	    Engine.allNotesOff();
};
 
Content.getComponent("Hold1").setControlCallback(onHold1Control);function onNoteOn()
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
 