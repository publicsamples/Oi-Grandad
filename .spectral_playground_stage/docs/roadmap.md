# Roadmap

## Immediate

1. Stabilize the analysis/export format.
2. Verify FFT size, hop size, and exported frame counts behave as expected.
3. Add simple analysis diagnostics:
   - frame count
   - last meaningful frame time
   - average frame energy
   - partial count per frame
4. Improve preview/playback alignment.

## Near Term

1. Improve partial tracking.
2. Make transient handling more coherent with partial energy.
3. Add visualization for:
   - frame energy
   - transient strength
   - partial density
4. Compare multiple playback approaches:
   - sparse additive partials
   - harmonic projection
   - residual-enhanced models

## Later

1. Add residual extraction instead of synthetic noise.
2. Add true transient layer experiments.
3. Consider a binary cache format once the JSON schema is stable.
4. Decide whether the project becomes:
   - a dedicated spectral instrument
   - a research tool only
   - a feeder project for other instruments
