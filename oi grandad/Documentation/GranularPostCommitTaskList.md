# Granular Engine Task List After Last Commit

This document summarizes the useful granular-engine work discussed after the last commit and before the Saturday-night experimentation went off track. It excludes repeated attempts, abandoned branches, and changes that did not prove useful.

## 1. Re-establish a stable "Density is mix, not grain count" model

Density should behave as a true modulation-friendly weighting / crossfade control, while `MaxGrains` remains the only control that determines how many grains exist.

Targets:

- keep grains up to `MaxGrains` logically active
- use Density only for weighting / emphasis / coverage
- avoid obvious stepped grain on/off behaviour when Density moves
- preserve a very small internal skip threshold only if needed for CPU safety

Why this is first:

- it directly affects playability, modulation quality, and CPU predictability
- it was one of the clearest improvements discussed

## 2. Rebuild the note-on "cloud bloom" behaviour

The most promising decorrelation behaviour came from gradually bringing the grain ensemble into motion over roughly the first 100-300 ms of a note, similar to the effect heard when ramping `MaxGrains` manually.

Targets:

- avoid fully uniform grain initialization on note start
- introduce a short bloom period after note-on
- let grains enter with slightly different phase / identity over that bloom
- keep this subtle enough that it does not become pitch wobble or instability

Why it matters:

- it reduced the rigid rhythmic locking of the cloud
- it got closer to the "smooth while moving MaxGrains" sound without requiring manual performance tricks

Current decision:

- keep bloom / note-on decorrelation internal and static for now
- revisit exposing a dedicated control only if later testing shows a real need

## 3. Keep the performance fixes that do not cost sound quality

The clearest low-risk engine optimizations were:

- remove per-sample scatter randomization from the hot loop
- use a cheap deterministic integer hash instead of `std::sin()` for seeded pseudo-random values
- cache detune sine values per grain
- precompute scale ratios instead of recalculating `pow(2.0, semis / 12.0)`
- flatten small helper/lambda overhead in the render path where practical

Why it matters:

- these changes improved CPU use without changing the feature set
- they are worth preserving or reapplying early in any rebuild

## 4. Keep the 5-lane slider-pack mode layout

Moving the mode switches into one slider pack was a useful structural cleanup and freed parameter space.

Slider-pack layout:

- Slider 1: `PitchMode`
- Slider 2: `ScrubMode`
- Slider 3: `ScrubBlend`
- Slider 4: playback preset / transport selector
- Slider 5: spare or future mode lane

Why it matters:

- it simplified the node interface
- it made room for separating behaviours that were previously bundled together

## 5. Preserve the separated motion / spread controls

The useful separation that emerged was:

- `Density`: weighting / mix only
- `PhaseScatter`: source-start spread only
- `Respawn`: reroll amount only
- `Drift`: slow internal gain-motion / shimmer only
- `Diffusion`: output diffusion only

Why it matters:

- this made the engine easier to reason about
- it allowed each behaviour to be judged in isolation instead of being buried in one overloaded control

## 6. Keep the simplified playback preset structure

The most useful playback preset set was:

- `Stretch + Varispeed`
- `Stretch + Time Invariant`
- `Latch + Varispeed`
- `Latch + Time Invariant`
- `Fade + Varispeed`

Notes:

- time-invariant modes benefited from the smooth wrap treatment
- direct / hybrid transport branches did not prove worthwhile

Why it matters:

- this was a cleaner and more understandable replacement for the earlier transport/read branching

## 7. Reapply the time-invariant smoothing work

Time-invariant playback became more usable when wrap smoothing / micro-crossfading was added around internal read wraps.

Targets:

- keep grain size fixed
- reduce clicks at read-wrap points
- keep pitch changes and playback behaviour stable

Why it matters:

- this was one of the few clearly useful fixes for the time-invariant modes

## 8. Tame the PhaseScatter range

One recurring conclusion was that `PhaseScatter` had too broad an effective range when allowed to span most of the file.

Targets:

- make low values subtle and local
- make broad scatter a later part of the range
- keep reroll behaviour under `Respawn`, not `PhaseScatter`

Why it matters:

- it improves predictability
- it prevents the control from jumping too quickly into chaotic territory

## 9. Revisit homogeneous-cloud behaviour as a dedicated mode, not a global change

The desire for a more homogeneous cloud was valid, but it should not replace the baseline engine globally.

What to preserve conceptually:

- a separate mode or preset for reduced grain-clock coherence
- focus on grain-window phase distribution rather than just source scatter or gain drift

Important constraint:

- this should be isolated as a dedicated playback option so the existing punchier / loop-like behaviour remains available

Current status:

- the first cloud-mode implementation has been parked
- playback preset slot 6 currently falls back to the stable loop baseline
- `CloudAmount` is intentionally inert until the mode is redesigned from first principles

## 10. Keep the "one useful behaviour per control" discipline

The chat repeatedly converged on a better design rule:

- do not overload a single control with unrelated movement, spread, gating, and reroll logic
- when testing a new idea, isolate it first
- if a behaviour changes the core character of the engine, keep it behind a dedicated mode

Why it matters:

- this is the clearest lesson from the period between the last commit and Saturday night
- it will reduce the risk of repeating the same kind of regression spiral

## Suggested rebuild order

1. Restore the density model and CPU-safe performance fixes.
2. Rebuild note-on cloud bloom / decorrelation.
3. Re-establish the separated controls and slider-pack mode structure.
4. Reapply the simplified playback presets and time-invariant smoothing.
5. Reapply pitch-mode improvements.
6. Only then explore any new homogeneous-cloud mode in isolation.
