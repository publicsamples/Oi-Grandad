# Overview

## Purpose

`SpectralPlayground` is a learning and prototyping environment for spectral analysis and playback.

It is intentionally separate from Oi, Grandad so that:

- analysis and playback can evolve without HISE-specific constraints
- experiments can be simpler to reason about
- successful techniques can later be transferred into another instrument or plugin

## Current Architecture

### 1. Analysis

The app:

- loads a source file
- converts it to mono
- runs FFT analysis over the selected time range
- picks peaks from each frame
- tracks peaks between frames

The result is a sparse description of the audio as partials over time.

### 2. Asset Format

The exported `.spectral.json` stores:

- source metadata
- FFT and hop settings
- frame times
- partial IDs
- partial frequencies
- partial amplitudes
- partial bandwidth estimates
- transient estimates

### 3. Playback Preview

The app also contains a direct preview renderer that:

- resynthesizes from exported partials
- applies a simple transient emphasis
- adds a synthetic noise layer from bandwidth estimates

This preview is the current reference playback path.

## Current Limitations

- residual/noise is synthetic, not true residual reconstruction
- transient handling is estimated, not sample-accurate transient playback
- partial tracking is still a first-pass implementation
- exported JSON is convenient, but not efficient for a final product

## Why This Repo Exists

This repo should make it easier to answer concrete DSP questions before committing to an instrument design:

- which analysis settings preserve source identity best?
- which resynthesis model sounds closest to the analysis preview?
- which controls are musically useful in realtime?
