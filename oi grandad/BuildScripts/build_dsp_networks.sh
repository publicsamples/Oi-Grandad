#!/usr/bin/env bash
set -euo pipefail

echo "Building DSP networks..."
# TODO: replace this with the exact command(s) you run locally to compile networks
# Examples might be: a HISE headless export tool, a CMake build, a Makefile, etc.
# ./tools/build_networks --release

echo "Checking output folder..."
ls -la "DspNetworks/Binaries/dll"

# sanity check: fail if nothing was produced
if [ -z "$(ls -A "DspNetworks/Binaries/dll" 2>/dev/null)" ]; then
  echo "ERROR: DspNetworks/Binaries/dll is empty after build."
  exit 1
fi

echo "DSP networks build OK."