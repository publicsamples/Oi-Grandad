declare owl "[voct:output]";

import("stdfaust.lib");
import("owl.lib");

notes = (36, 40, 43, 47, 48, 47, 43, 40);
notes_per_beat = 4;
total_notes = 8;

process = pitch, gate
with {
    tune     = hslider("Tune[OWL:A]", 0, -24, 24, 1) : int;
    bpm      = hslider("BPM[OWL:B]", 120, 80, 160, 0.1);
    beat_len = ba.tempo(bpm);
    gate     = ba.pulsen(beat_len / 4, beat_len / 2);
    step     = (ba.impulsify(gate) + _ : %(total_notes)) ~ _;
    seq_note = notes : ba.selectn(total_notes, step);
    pitch    = seq_note : ba.midikey2hz : hertz2sample(tune / 12);
};