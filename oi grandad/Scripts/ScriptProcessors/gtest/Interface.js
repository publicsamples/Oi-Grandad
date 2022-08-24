Content.makeFrontInterface(600, 600);

const audio = Engine.createAndRegisterAudioFile(0);
const var synth = Synth.getAudioSampleProcessor("Scriptnode Syntesiser1");

const maps = Sampler.getSampleMapList();

const slot = synth.getAudioFile(0);

const var ComboBox1 = Content.getComponent("ComboBox1");
ComboBox1.set("items", "");
ComboBox1.set("items", maps.join("\n"));

inline function onComboBox1Control(component, value)
{
	slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
};

ComboBox1.setControlCallback(onComboBox1Control);function onNoteOn()
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
 