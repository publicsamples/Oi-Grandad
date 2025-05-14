import("stdfaust.lib");

pitchshifter = vgroup("Pitch Shifter", ef.transpose(
                                    hslider("window (samples)", 1000, 50, 10000, 1),
                                    hslider("xfade (samples)", 10, 1, 10000, 1),
                                    hslider("shift (frequency) ", 40, 40, 10000, 1)
                                  )
                );

process = pitchshifter, pitchshifter;