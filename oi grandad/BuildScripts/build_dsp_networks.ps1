$ErrorActionPreference = "Stop"

Write-Host "Building DSP networks..."
# TODO: replace with the exact command(s) you run locally
# .\tools\build_networks.exe --release

Write-Host "Checking output folder..."
Get-ChildItem -Force "DspNetworks\Binaries\dll"

# sanity check
if (-not (Get-ChildItem -Force "DspNetworks\Binaries\dll" -ErrorAction SilentlyContinue)) {
  throw "DspNetworks\Binaries\dll is empty after build."
}

Write-Host "DSP networks build OK."