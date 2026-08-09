# Homogeneous Cloud Mode Plan

This plan is for a new playback preset only. The existing granular engine must remain intact outside this mode.

## Rules

- The current engine behaviour stays unchanged for the existing playback presets.
- All experimental scheduler / overlap / clouding changes live only inside the new playback preset.
- Do not repurpose existing controls globally in ways that change the other presets.
- Prefer slider-pack controls for any extra mode-specific control rather than adding more normal node parameters.

## Why the earlier attempts failed

The useful conclusion from the earlier experiments is that the problem was attacked at the wrong layer.

What did not solve it:

- source-start scatter
- gain drift
- simple window-shape offset
- making `PhaseScatter` behave differently everywhere
- changing baseline scheduler logic globally

Why those failed:

- they changed timbre or source position, but not the deeper grain-loop coherence
- some of them were too close to the existing stretch scheduler to sound meaningfully different
- others introduced clicks because envelope timing stopped lining up cleanly with read continuity

## Working hypothesis

The homogeneous cloud target is mainly about reducing shared periodicity between grains while keeping overlap smooth.

The mode should focus on:

- grain-envelope phase distribution
- grain respawn / re-entry distribution
- overlap normalization

It should avoid relying on:

- random source jumps
- broad source scatter
- ongoing drift modulation

## Proposed new playback preset

Add one new playback preset on slider-pack lane 4.

Suggested user-facing name:

- `Cloud`

Alternative names if needed:

- `Wash`
- `Diffuse`
- `Bloom`

`Cloud` should be a dedicated branch in the playback-preset logic, not a modification of the existing presets.

## What `Cloud` mode should change

Only inside this mode:

1. Replace the normal scheduler phase pattern with a cloud-specific phase layout.
2. Distribute grain launches across the full grain cycle in a deliberate overlap pattern.
3. Apply controlled respawn de-coherence so grains do not keep re-entering in one obvious pulse.
4. Compensate summed overlap so spreading grains does not simply make the loop more obvious.

What should remain unchanged:

- source-start scatter logic in the normal presets
- pitch behaviour
- density weighting model
- note-on bloom behaviour
- one-shot modes

## Control strategy

Do not add a new normal node parameter for this first pass.

Use the existing spare slider-pack lane 5 for a mode-specific control:

- lane 5 becomes `Cloud Amount`

Interpretation:

- `0.0`: preset behaves close to the current baseline for comparison
- `0.5`: clear even crossfade-style phase distribution
- `1.0`: stronger de-coherence / redistribution inside the cloud mode

Outside `Cloud` mode, lane 5 does nothing.

If one control is not enough later, add a second slider pack rather than more normal parameters.

## First implementation target

The first version should be intentionally narrow:

1. Add `Cloud` as a sixth playback preset.
2. In `Cloud`, keep source-start scatter off or minimal by default.
3. Use `Cloud Amount` to control deterministic grain-envelope spacing across the full grain cycle.
4. Keep the existing note-on bloom.
5. Add overlap compensation only inside this mode.
6. Do not add random rerolling yet unless the deterministic version still sounds too clocked.

This first pass should answer one question only:

- can we get closer to the crossfaded overlap shape in the diagram without damaging the rest of the engine?

## Second-pass options if needed

Only if the first pass is too static or still too pulse-like:

- add light respawn redistribution inside `Cloud`
- add blue-noise style or low-discrepancy re-entry spacing
- add cloud-only read-phase de-coherence
- add cloud-only overlap-law tuning

These should all remain scoped to `Cloud` mode.

## Parameter / UI note

From the HISE source checked locally, I did not find a confirmed hard 16 or 18 normal-parameter cap in the areas inspected.

What I did find:

- dynamic slider packs default to 16 sliders and then resize from `NumParameters`
- see [DynamicComplexData.h](/Users/rick/Documents/GitHub/Oi-Grandad/HISE/hi_scripting/scripting/scriptnode/dynamic_elements/DynamicComplexData.h:157)
- and [DynamicComplexData.cpp](/Users/rick/Documents/GitHub/Oi-Grandad/HISE/hi_scripting/scripting/scriptnode/dynamic_elements/DynamicComplexData.cpp:224)

So the safe design choice remains:

- keep normal node parameters lean
- use slider packs for additional mode-specific controls

## Implementation order

1. Remove `Drift` and keep the current rebuild stable.
2. Add the `Cloud` playback preset branch only.
3. Use slider-pack lane 5 as `Cloud Amount`.
4. Implement deterministic full-cycle phase distribution in `Cloud`.
5. Add cloud-only overlap compensation if the spread exposes the loop rather than hiding it.
6. Test against sustained tonal material first, then loops and drums.
