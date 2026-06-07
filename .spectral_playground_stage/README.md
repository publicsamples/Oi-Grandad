# SpectralPlayground

`SpectralPlayground` is an open-source JUCE app for exploring spectral analysis and resynthesis ideas outside HISE.

The goal is not to ship a polished end-user instrument immediately. The goal is to provide a sandbox where different analysis and playback techniques can be compared, listened to, and understood, then later adapted into other projects.

## Current Scope

- load audio files
- inspect a waveform and choose an analysis range
- analyze the selection into sparse spectral partial frames
- audition the source and analyzed result
- export `.spectral.json` assets

## Project Intent

This repository exists to answer questions like:

- how do different FFT sizes sound?
- how do peak picking and partial tracking choices affect the result?
- what playback models preserve timing, body, and transients best?
- when does a spectral model become musically useful?

## Build

Current build setup expects a sibling JUCE checkout via the existing HISE JUCE fork:

- `../HISE/JUCE`

Configure and build:

```bash
cmake -S . -B build
cmake --build build
```

## Docs

- [`docs/overview.md`](docs/overview.md)
- [`docs/roadmap.md`](docs/roadmap.md)
- [`docs/next-chat-prompt.md`](docs/next-chat-prompt.md)
