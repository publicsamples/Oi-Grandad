const var AudioWaveform1 = Content.getComponent("AudioWaveform1");
const var Analyze = Content.getComponent("Analyze");

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

const var CurrentCacheFile = FileSystem.getFolder(FileSystem.AudioFiles).getChildFile("spectral_cache_current.json");

function writeDebugSpectralCache()
{
	var obj = {};
	obj.version = 1;
	obj.sourceFile = SpecAudioFile.getCurrentlyLoadedFile();
	obj.sampleRate = 44100;
	obj.durationSeconds = 0.03;
	obj.rootHz = 220.0;
	obj.hopTime = 0.01;
	obj.timedomain = "seconds";
	obj.frameCount = 4;
	obj.maxPartials = 4;
	obj.frames = [];

	var f0 = {};
	f0.time = 0.00;
	f0.gains = [1.0, 0.5, 0.2];
	f0.phases = [0.0, 0.0, 0.0];
	f0.bandwidth = [0.0, 0.0, 0.0];
	obj.frames.push(f0);

	var f1 = {};
	f1.time = 0.01;
	f1.gains = [0.7, 0.9, 0.1];
	f1.phases = [0.0, 0.5, 1.0];
	f1.bandwidth = [0.0, 0.1, 0.2];
	obj.frames.push(f1);

	var f2 = {};
	f2.time = 0.02;
	f2.gains = [0.3, 1.0, 0.6];
	f2.phases = [0.2, 1.0, 1.7];
	f2.bandwidth = [0.1, 0.2, 0.4];
	obj.frames.push(f2);

	var f3 = {};
	f3.time = 0.03;
	f3.gains = [0.1, 0.3, 1.0, 0.5];
	f3.phases = [0.4, 1.3, 2.0, 2.4];
	f3.bandwidth = [0.2, 0.3, 0.6, 0.8];
	obj.frames.push(f3);

	CurrentCacheFile.writeString(JSON.stringify(obj, null, "  "));
	Console.print("Wrote cache: " + CurrentCacheFile.toString(0));
}

inline function onAnalyzeControl(component, value)
{
	Console.print("Analyze changed: " + value);
	
	if (!value)
		return;

	writeDebugSpectralCache();
	component.setValue(0);
}

Analyze.setControlCallback(onAnalyzeControl);

inline function onAudioWaveform1Control(component, value)
{
	Console.print("Waveform changed");
	printSpecFileState();
}

AudioWaveform1.setControlCallback(onAudioWaveform1Control);