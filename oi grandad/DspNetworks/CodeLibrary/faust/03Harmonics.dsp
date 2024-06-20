import("stdfaust.lib");

freq = hslider("Base frequency[OWL:AA]", 80, 60, 120, 0.01);

process = par(
    i,
    8, 
    hslider("Harmonic %i[OWL:%i]", 1 / (1 + i), 0, 1, 0.001) * os.oscs(i * freq + freq)
) :> _ : *(0.125) <: _, _;