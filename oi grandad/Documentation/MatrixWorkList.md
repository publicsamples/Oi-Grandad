1. Modulator Auto-On/Off
Files:
[macros.js](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/Scripts/macros.js)
possibly [ModControls.js](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/Scripts/ModControls.js)
Work:
Add a single source-of-truth function that counts active matrix routes per mod source.
Enable a modulator when its route count is > 0.
Disable or bypass it when its route count is 0.
Hook this into matrix add/remove/clear operations and preset restore.
Decision confirmed:
“off” means Enabled = false.
2. Destination Hygiene Pass
Files:
[macros.js](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/Scripts/macros.js)
[oi grandadDesktop.xml](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/XmlPresetBackups/oi grandadUIData/oi grandadDesktop.xml)
Work:
Finalise exclusions for helper/meta/mirror controls.
Confirm every visible destination maps to a real audible target.
Keep mirror controls pointing at real matrix targets, not separate aliases.
3. Destination Naming Pass
Files:
[oi grandadDesktop.xml](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/XmlPresetBackups/oi grandadUIData/oi grandadDesktop.xml)
[macros.js](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/Scripts/macros.js)
Work:
Review user-facing target names in right-click menus and matrix panel.
Standardise voice naming: Voice_1_PositionA vs Voice_2_Position_A style inconsistency.
Remove any remaining internal-looking names from the UI.
4. Rename s1..s12 to LFO1..LFO12
Files:
[oi grandad.xml](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/XmlPresetBackups/oi grandad.xml)
[oi grandadDesktop.xml](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/XmlPresetBackups/oi grandadUIData/oi grandadDesktop.xml)
[ModControls.js](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/Scripts/ModControls.js)
Work:
Rename processor IDs.
Rename UI references and script lookups.
Verify matrix source labels update cleanly.
5. Rename MacroMod1..8 to MACRO1..8
Files:
[oi grandad.xml](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/XmlPresetBackups/oi grandad.xml)
[oi grandadDesktop.xml](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/XmlPresetBackups/oi grandadUIData/oi grandadDesktop.xml)
[macros.js](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/Scripts/macros.js)
[ModControls.js](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/Scripts/ModControls.js)
Work:
Rename processor IDs, component IDs, and script lookups.
Recheck any exclusion logic that keys off MacroMod / Macro.
6. Match seq2..seq12 to seq1
Files:
[oi grandadDesktop.xml](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/XmlPresetBackups/oi grandadUIData/oi grandadDesktop.xml)
Work:
Copy the visual structure of seq1.
Apply the same sizing, spacing, labels, and component styling to seq2..12.
Keep processor bindings unchanged.
7. Matrix Panel Styling Investigation
Files:
matrix-related script / LAF files, likely:[Matrix.js](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/Documentation/Matrix.js)
current LAF scripts in the project

Work:
Separate native matrix styling limits from actual bugs.
Test slider fill colour control.
Test plotter styling support.
Decide whether plotter stays intentionally disabled.
8. Small-Control Mod Indicator
Files:
current LAF script(s)
Work:
Add a compact modulation indicator for small controls.
Leave the existing larger arc style for medium and large knobs.
9. LAF Cleanup Pass
Files:
project LAF scripts
Work:
Group draw functions logically.
Remove dead style experiments.
Standardise naming and shared helpers.
10. Voice Replication
Files:
[oi grandad.xml](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/XmlPresetBackups/oi grandad.xml)
[oi grandadDesktop.xml](/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/XmlPresetBackups/oi grandadUIData/oi grandadDesktop.xml)
Work:
Once V0 is final, propagate the same structure to V1, V2, V3.
Verify module-tree target names and UI panels stay aligned.
Best place to start next is item 1, then item 2. Those two define the system behaviour before we spend time on naming and UI polish.
