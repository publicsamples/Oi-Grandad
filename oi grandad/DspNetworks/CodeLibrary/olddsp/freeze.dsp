bounce(d,f) = @(d) : *(f);
monoecho(d,f) = *(g) : +~bounce(d,f) with { g = 1 - max(0, f-l)/(1-l); l = 0.95; };
stereoecho(d,f) = monoecho(d,f), monoecho(d,f);

process = stereoecho(44100/4, hslider("feedback", 0, 0, 1, 0.01));