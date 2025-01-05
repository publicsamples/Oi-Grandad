import("stdfaust.lib");

pitchshifter = vgroup("Pitch Shifter", ef.transpose(
                                    hslider("window (samples)", 1000, 50, 10000, 1),
                                    hslider("xfade (samples)", 10, 1, 10000, 1),
                                    hslider("shift (semitones) ", 0, -24, +24, 0.1)
                                  )
                );

process = pitchshifter, pitchshifter;