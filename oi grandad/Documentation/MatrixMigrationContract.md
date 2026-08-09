# Matrix Modulation Migration Contract

## Goal

Replace the legacy modulation system built around `global_cable`, selector branches, `peak`, and `pma`
with a single project-wide modulation contract based on the HISE modulation matrix and scriptnode
`core.matrix_mod`.

## Core Rule

The UI matrix owns:

- source registration
- connection persistence
- target registration
- polarity / mode selection
- per-connection intensity

Scriptnode owns:

- base parameter value
- DSP-rate modulation reception
- final scaling into the target's real unit domain

## Canonical Target Types

### 1. Direct matrix target

Use this when a target can safely be modulated by the HISE parameter layer.

Examples:

- non-sensitive normalized controls
- UI-facing controls where repaint resolution is acceptable
- parameters where control-rate stepping is not audible

Pattern:

- UI control gets a `matrixTargetId`
- `Engine.createModulationMatrix(...)` connects sources to that target ID
- no scriptnode `core.matrix_mod` node is required

### 2. Scriptnode matrix target

Use this when a target must be modulated inside DSP.

Examples:

- pitch
- scrub / position
- FM-like or phase-sensitive destinations
- anything where control-rate stepping is audible

Pattern:

- base value remains an ordinary parameter connection
- modulation enters scriptnode through `core.matrix_mod`
- `core.matrix_mod` feeds a `control.pma` or equivalent scaling stage
- the scaled output modulates the final scriptnode parameter

## Recommended Node Pattern

### Normalized target in DSP

Use for 0..1 targets such as scrub / position when smooth in-DSP modulation is required.

Pattern:

- `PositionBase` -> target parameter base connection
- `PositionSource` -> `core.matrix_mod.SourceIndex`
- `core.matrix_mod.Mode = unipolar`
- `core.matrix_mod` output -> target parameter modulation input

Optional:

- add a toggle for A/B testing against direct UI parameter modulation

### Pitch target in DSP

Use for semitone or other unit-based pitch modulation.

Pattern:

- `PitchBase` -> target parameter base connection
- `PitchSource` -> `core.matrix_mod.SourceIndex`
- `core.matrix_mod.Mode = bipolar`
- `core.matrix_mod` -> `control.pma.Value`
- `PitchModDepth` -> `control.pma.Multiply`
- `control.pma` output -> target parameter modulation input

Why:

- `core.matrix_mod` provides the normalized modulation signal
- `pma` converts that signal into semitone depth
- base pitch and modulation depth remain independently controllable

## Naming Contract

Every mod destination should have a stable target ID that is independent of the current UI layout.

Recommended form:

- `voice1_pitch`
- `voice1_position`
- `voice2_grain_ms`
- `filter1_cutoff`

Rules:

- UI component IDs may change
- matrix target IDs should not
- scriptnode node IDs may change
- exported target IDs should not

## What To Remove Over Time

As destinations migrate to the matrix contract, remove:

- 16-way `branch` banks used only to select `Modulator1..16`
- `global_cable` fans used as modulation source selectors
- `peak` nodes used only as relay taps
- `pma` nodes whose only job is reproducing matrix intensity semantics already handled by HISE

Keep `pma` only where it is needed to convert normalized modulation into a target unit domain.

## Migration Sequence

1. Define stable target IDs for all existing modulation destinations.
2. Convert UI modulation assignment to matrix targets.
3. Convert sensitive scriptnode destinations to `core.matrix_mod`.
4. Keep legacy routing alive in parallel while validating behavior.
5. Remove legacy selector banks after all consumers have moved.

## Validation Rules

Each migrated target must be checked for:

- correct polarity
- correct modulation depth
- correct base-value behavior
- preset recall
- polyphonic behavior where relevant
- absence of audible stepping for sensitive targets

## Reference Test Network

`/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/DspNetworks/Networks/MatrixTest.xml`

This file now demonstrates:

- a normalized in-DSP position target
- a pitch target using `core.matrix_mod + control.pma`

Use it as the reference pattern before touching the larger synth and FX graphs.
