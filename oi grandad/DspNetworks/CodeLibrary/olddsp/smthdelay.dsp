//-----------------------------------------------
// 				A 1000 ms Stereo Echo
//-----------------------------------------------

echo(d,f) = + ~ (@(d) : *(f));

echo1s = echo(delay,fback) with {
		delay = hslider("Delay[OWL:PARAMETER_A]", 0, 0, 1000, 0.10)*millisec;
		fback = hslider("Feedback[OWL:PARAMETER_B]", 0, 0, 1, 0.01);
		millisec = 48;
	};

process = vgroup("stereoecho", (echo1s, echo1s));
