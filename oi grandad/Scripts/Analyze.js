//waveform view
const var AudioWaveform1 = Content.getComponent("AudioWaveform1");


//Analyze button
const var Analyze = Content.getComponent("Analyze");


const var Spec = Synth.getChildSynth("Spec");
const var Specwav = Synth.getAudioSampleProcessor("Spec");
const var Loris = Engine.getLorisManager();
const var SpecAudioFile = Specwav.getAudioFile(0);

function getCurrentSpecFile()
{
	var ref = SpecAudioFile.getCurrentlyLoadedFile();
	
	if (ref == "")
		return undefined;
		
	return FileSystem.fromReferenceString(ref, FileSystem.AudioFiles);
}

function printSpecFileState()
{
	Console.print("Spec filename: " + Specwav.getFilename());
	Console.print("Spec ref: " + SpecAudioFile.getCurrentlyLoadedFile());
	Console.print("Spec samples: " + SpecAudioFile.getNumSamples());
}

function analyseOnly()
{
	var f = getCurrentSpecFile();
	
	printSpecFileState();
	
	if (f == undefined)
	{
		Console.print("No file loaded");
		return;
	}
	
	if (SpecAudioFile.getNumSamples() <= 0)
	{
		Console.print("Empty audio slot");
		return;
	}

	Loris.set("enablecache", false);
	Loris.set("timedomain", "0to1");
	Loris.set("hoptime", 0.05);
	Loris.set("croptime", 0.05);
	Loris.set("windowwidth", 1.0);

	var rootHz = 220.0;

	Console.print("About to analyse: " + SpecAudioFile.getCurrentlyLoadedFile());
	Console.print("Using rootHz: " + rootHz);

	Loris.analyse(f, rootHz);

	Console.print("Analyse returned");
}

inline function onAnalyzeControl(component, value)
{
	if (value)
	{
		analyseOnly();
		component.setValue(0);
	}
}

Analyze.setControlCallback(onAnalyzeControl);

function analyseAndSnapshot()
{
	var f = getCurrentSpecFile();
	
	if (f == undefined || SpecAudioFile.getNumSamples() <= 0)
	{
		Console.print("No valid file loaded");
		return;
	}

	Loris.set("enablecache", false);
	Loris.set("timedomain", "0to1");
	Loris.set("hoptime", 0.05);
	Loris.set("croptime", 0.05);
	Loris.set("windowwidth", 1.0);

	var rootHz = 220.0;

	Console.print("About to analyse");
	Loris.analyse(f, rootHz);
	Console.print("Analyse returned");

	var gains = Loris.createSnapshot(f, "gain", 0.5);
	Console.print("gain snapshot returned");

	var phases = Loris.createSnapshot(f, "phase", 0.5);
	Console.print("phase snapshot returned");

	var bandwidth = Loris.createSnapshot(f, "bandwidth", 0.5);
	Console.print("bandwidth snapshot returned");

	Console.print("gain channels: " + gains.length);
	Console.print("phase channels: " + phases.length);
	Console.print("bandwidth channels: " + bandwidth.length);

	if (gains.length > 0)
		Console.print("gain[0] harmonics: " + gains[0].length);

	if (phases.length > 0)
		Console.print("phase[0] harmonics: " + phases[0].length);

	if (bandwidth.length > 0)
		Console.print("bandwidth[0] harmonics: " + bandwidth[0].length);
}

function analyseAndSynth()
{
	var f = getCurrentSpecFile();
	
	if (f == undefined || SpecAudioFile.getNumSamples() <= 0)
	{
		Console.print("No valid file loaded");
		return;
	}

	Loris.set("enablecache", false);
	Loris.set("timedomain", "0to1");
	Loris.set("hoptime", 0.05);
	Loris.set("croptime", 0.05);
	Loris.set("windowwidth", 1.0);

	var rootHz = 220.0;

	Console.print("About to analyse");
	Loris.analyse(f, rootHz);
	Console.print("Analyse returned");

	var buffers = Loris.synthesise(f);

	Console.print("Synth returned");
	Console.print("buffer channels: " + buffers.length);

	if (buffers.length > 0)
	{
		Console.print("buffer samples: " + buffers[0].length);
		Console.print("first sample: " + buffers[0][0]);
		Console.print("sample 100: " + buffers[0][100]);
	}
}


inline function onAudioWaveform1Control(component, value)
{
	Console.print("Waveform changed");
	printSpecFileState();
}

AudioWaveform1.setControlCallback(onAudioWaveform1Control);
