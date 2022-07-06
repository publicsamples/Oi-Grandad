Content.makeFrontInterface(900, 800); 


inline function onHoldControl(component, value)

 {
     if (value)
 	    Synth.playNote(60, 127);
 	  else
	    Engine.allNotesOff();
};
 
Content.getComponent("Hold").setControlCallback(onHoldControl);

function onNoteOn()
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
 