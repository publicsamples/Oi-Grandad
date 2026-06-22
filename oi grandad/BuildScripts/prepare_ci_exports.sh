#!/usr/bin/env bash
set -euo pipefail

usage() {
  cat <<'EOF'
prepare_ci_exports.sh

Generates CI-ready exported project files for both plugin and standalone modes
by invoking the HISE command line exporter twice and snapshotting the generated
Binaries state after each pass.

Usage:
  ./prepare_ci_exports.sh [options]

Options:
  --hise-bin PATH        Absolute path to the HISE executable or HISE.app bundle.
  --projucer-bin PATH    Absolute path to the Projucer executable or Projucer.app bundle.
  --project-dir PATH     Project directory. Default: parent of this script.
  --project-file PATH    Relative project XML/hip path. Default: XmlPresetBackups/oi grandad.xml
  --plugin-target TEXT   HISE -t value for plugin export. Default: instrument
  --vst3-format TEXT     HISE -p value for VST3 export. Default: VST3
  --au-format TEXT       HISE -p value for AU export. Default: AU
  --arch TEXT            HISE -a value. Default: x64
  --hise-source PATH     Absolute path to HISE source repository. Default: <project-dir>/../HISE
  --output-dir PATH      Output root for snapshots. Default: <project-dir>/CIExports
  --keep-active MODE     Leave live Binaries export as vst3|au|standalone. Default: standalone
  --skip-vst3            Do not export VST3 mode
  --skip-au              Do not export AU mode
  --skip-standalone      Do not export standalone mode
  --help                 Show this help

Notes:
  - HISE export_ci performs a build as part of export. This wrapper does not
    suppress compilation; it snapshots the generated files after each export.
  - The live Binaries folder is overwritten during the process because HISE only
    maintains one export tree at a time.
EOF
}

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
PROJECT_FILE="XmlPresetBackups/oi grandad.xml"
PLUGIN_TARGET="instrument"
VST3_FORMAT="VST3"
AU_FORMAT="AU"
ARCH="x64"
HISE_SOURCE_DIR=""
PROJUCER_BIN=""
OUTPUT_DIR="$PROJECT_DIR/CIExports"
KEEP_ACTIVE="standalone"
DO_VST3=1
DO_AU=1
DO_STANDALONE=1
HISE_BIN=""

while [[ $# -gt 0 ]]; do
  case "$1" in
    --hise-bin)
      HISE_BIN="${2:-}"
      shift 2
      ;;
    --project-dir)
      PROJECT_DIR="${2:-}"
      shift 2
      ;;
    --projucer-bin)
      PROJUCER_BIN="${2:-}"
      shift 2
      ;;
    --project-file)
      PROJECT_FILE="${2:-}"
      shift 2
      ;;
    --plugin-target)
      PLUGIN_TARGET="${2:-}"
      shift 2
      ;;
    --vst3-format)
      VST3_FORMAT="${2:-}"
      shift 2
      ;;
    --au-format)
      AU_FORMAT="${2:-}"
      shift 2
      ;;
    --arch)
      ARCH="${2:-}"
      shift 2
      ;;
    --hise-source)
      HISE_SOURCE_DIR="${2:-}"
      shift 2
      ;;
    --output-dir)
      OUTPUT_DIR="${2:-}"
      shift 2
      ;;
    --keep-active)
      KEEP_ACTIVE="${2:-}"
      shift 2
      ;;
    --skip-vst3)
      DO_VST3=0
      shift
      ;;
    --skip-au)
      DO_AU=0
      shift
      ;;
    --skip-standalone)
      DO_STANDALONE=0
      shift
      ;;
    --help|-h)
      usage
      exit 0
      ;;
    *)
      echo "Unknown option: $1" >&2
      usage
      exit 1
      ;;
  esac
done

if [[ "$DO_VST3" -eq 0 && "$DO_AU" -eq 0 && "$DO_STANDALONE" -eq 0 ]]; then
  echo "Nothing to do: all export modes are disabled." >&2
  exit 1
fi

if [[ "$KEEP_ACTIVE" != "vst3" && "$KEEP_ACTIVE" != "au" && "$KEEP_ACTIVE" != "standalone" ]]; then
  echo "--keep-active must be 'vst3', 'au', or 'standalone'." >&2
  exit 1
fi

detect_hise_bin() {
  local candidates=(
    "$PROJECT_DIR/../HISE/projects/standalone/Builds/MacOSX/build/Release/HISE.app/Contents/MacOS/HISE"
    "$PROJECT_DIR/../HISE/projects/standalone/Builds/MacOSX/build/Release with Faust/HISE.app/Contents/MacOS/HISE"
    "$PROJECT_DIR/../HISE/projects/standalone/Builds/LinuxMakefile/build/HISE"
    "$PROJECT_DIR/../HISE/projects/standalone/Builds/VisualStudio2022/x64/Release/App/HISE.exe"
    "$(command -v HISE 2>/dev/null || true)"
  )

  local candidate
  for candidate in "${candidates[@]}"; do
    if [[ -n "$candidate" && -x "$candidate" ]]; then
      HISE_BIN="$candidate"
      return 0
    fi
  done

  return 1
}

detect_projucer_bin() {
  local candidates=(
    "$HISE_SOURCE_DIR/JUCE/projucer/Projucer.app/Contents/MacOS/Projucer"
    "$HISE_SOURCE_DIR/tools/projucer/Projucer.app/Contents/MacOS/Projucer"
    "$HISE_SOURCE_DIR/JUCE/projucer/Projucer.exe"
    "$(command -v Projucer 2>/dev/null || true)"
  )

  local candidate
  for candidate in "${candidates[@]}"; do
    if [[ -n "$candidate" && -x "$candidate" ]]; then
      PROJUCER_BIN="$candidate"
      return 0
    fi
  done

  return 1
}

normalise_hise_bin() {
  if [[ -d "$HISE_BIN" && "$HISE_BIN" == *.app ]]; then
    local app_name
    app_name="$(basename "$HISE_BIN" .app)"
    local macos_bin="$HISE_BIN/Contents/MacOS/$app_name"

    if [[ -x "$macos_bin" ]]; then
      HISE_BIN="$macos_bin"
      return 0
    fi

    local fallback_bin
    fallback_bin="$(find "$HISE_BIN/Contents/MacOS" -maxdepth 1 -type f -perm -111 | head -n1 || true)"
    if [[ -n "$fallback_bin" && -x "$fallback_bin" ]]; then
      HISE_BIN="$fallback_bin"
      return 0
    fi
  fi

  return 0
}

normalise_app_bin() {
  local var_name="$1"
  local current_value="${!var_name}"

  if [[ -d "$current_value" && "$current_value" == *.app ]]; then
    local app_name
    app_name="$(basename "$current_value" .app)"
    local macos_bin="$current_value/Contents/MacOS/$app_name"

    if [[ -x "$macos_bin" ]]; then
      printf -v "$var_name" '%s' "$macos_bin"
      return 0
    fi

    local fallback_bin
    fallback_bin="$(find "$current_value/Contents/MacOS" -maxdepth 1 -type f -perm -111 | head -n1 || true)"
    if [[ -n "$fallback_bin" && -x "$fallback_bin" ]]; then
      printf -v "$var_name" '%s' "$fallback_bin"
      return 0
    fi
  fi

  return 0
}

if [[ -z "$HISE_BIN" ]]; then
  detect_hise_bin || {
    echo "Could not locate a runnable HISE executable. Pass --hise-bin PATH." >&2
    exit 1
  }
fi

normalise_hise_bin

if [[ ! -x "$HISE_BIN" ]]; then
  echo "HISE executable not found or not executable: $HISE_BIN" >&2
  exit 1
fi

PROJECT_DIR="$(cd "$PROJECT_DIR" && pwd)"
if [[ -z "$HISE_SOURCE_DIR" ]]; then
  HISE_SOURCE_DIR="$PROJECT_DIR/../HISE"
fi
HISE_SOURCE_DIR="$(cd "$HISE_SOURCE_DIR" && pwd)"

if [[ -z "$PROJUCER_BIN" ]]; then
  detect_projucer_bin || true
fi

normalise_app_bin PROJUCER_BIN

if [[ ! -d "$HISE_SOURCE_DIR/hi_core" || ! -d "$HISE_SOURCE_DIR/JUCE" ]]; then
  echo "HISE source folder does not look valid: $HISE_SOURCE_DIR" >&2
  exit 1
fi

if [[ -z "$PROJUCER_BIN" || ! -x "$PROJUCER_BIN" ]]; then
  echo "Could not locate a runnable Projucer executable. Pass --projucer-bin PATH." >&2
  exit 1
fi

PROJECT_FILE_ABS="$PROJECT_DIR/$PROJECT_FILE"
if [[ ! -f "$PROJECT_FILE_ABS" ]]; then
  echo "Project file not found: $PROJECT_FILE_ABS" >&2
  exit 1
fi

BINARY_ROOT="$PROJECT_DIR/Binaries"
if [[ ! -d "$BINARY_ROOT" ]]; then
  echo "Binaries directory not found: $BINARY_ROOT" >&2
  exit 1
fi

copy_export_snapshot() {
  local mode="$1"
  local dest="$OUTPUT_DIR/$mode"
  local shared_additional="$OUTPUT_DIR/AdditionalSourceCode"
  local shared_dsp_networks="$OUTPUT_DIR/DspNetworks"

  mkdir -p "$dest"
  rm -rf \
    "$dest/Builds" \
    "$dest/Source" \
    "$dest/AdditionalSourceCode" \
    "$dest/DspNetworks" \
    "$dest/JuceLibraryCode" \
    "$dest/Compiled"

  cp -R "$BINARY_ROOT/Builds" "$dest/Builds"
  cp -R "$BINARY_ROOT/Source" "$dest/Source"
  cp -R "$BINARY_ROOT/JuceLibraryCode" "$dest/JuceLibraryCode"
  cp -R "$PROJECT_DIR/AdditionalSourceCode" "$dest/AdditionalSourceCode"
  if [[ -d "$PROJECT_DIR/DspNetworks" ]]; then
    cp -R "$PROJECT_DIR/DspNetworks" "$dest/DspNetworks"
  fi

  if [[ -d "$BINARY_ROOT/Compiled" ]]; then
    cp -R "$BINARY_ROOT/Compiled" "$dest/Compiled"
  fi

  rm -rf "$shared_additional"
  cp -R "$PROJECT_DIR/AdditionalSourceCode" "$shared_additional"

  if [[ -d "$PROJECT_DIR/DspNetworks" ]]; then
    rm -rf "$shared_dsp_networks"
    cp -R "$PROJECT_DIR/DspNetworks" "$shared_dsp_networks"
  fi

  cp "$BINARY_ROOT/AutogeneratedProject.jucer" "$dest/AutogeneratedProject.jucer"

  if [[ -f "$BINARY_ROOT/batchCompileOSX" ]]; then
    cp "$BINARY_ROOT/batchCompileOSX" "$dest/batchCompileOSX"
  fi

  cat > "$dest/export-metadata.txt" <<EOF
mode=$mode
hise_bin=$HISE_BIN
project_dir=$PROJECT_DIR
project_file=$PROJECT_FILE
arch=$ARCH
plugin_target=$PLUGIN_TARGET
vst3_format=$VST3_FORMAT
au_format=$AU_FORMAT
hise_source_dir=$HISE_SOURCE_DIR
timestamp=$(date -u +"%Y-%m-%dT%H:%M:%SZ")
EOF
}

run_export() {
  local mode="$1"
  local target="$2"
  local format="${3:-}"

  local -a cmd=(
    "$HISE_BIN"
    export_ci
    "$PROJECT_FILE"
    "-h:$HISE_SOURCE_DIR"
    "-t:$target"
    "-a:$ARCH"
    -nolto
  )

  if [[ -n "$format" ]]; then
    cmd+=("-p:$format")
  fi

  echo "Setting HISE project folder: $PROJECT_DIR"
  "$HISE_BIN" set_project_folder "-p:$PROJECT_DIR"
  "$HISE_BIN" set_hise_folder "-p:$HISE_SOURCE_DIR"

  echo "Running HISE export for $mode"
  "${cmd[@]}"

  echo "Re-saving generated JUCER with Projucer for $mode"
  "$PROJUCER_BIN" --resave "$BINARY_ROOT/AutogeneratedProject.jucer"
}

mkdir -p "$OUTPUT_DIR"

if [[ "$DO_VST3" -eq 1 ]]; then
  run_export "vst3" "$PLUGIN_TARGET" "$VST3_FORMAT"
  copy_export_snapshot "vst3"
fi

if [[ "$DO_AU" -eq 1 ]]; then
  run_export "au" "$PLUGIN_TARGET" "$AU_FORMAT"
  copy_export_snapshot "au"
fi

if [[ "$DO_STANDALONE" -eq 1 ]]; then
  run_export "standalone" "standalone" ""
  copy_export_snapshot "standalone"
fi

if [[ "$KEEP_ACTIVE" == "vst3" && "$DO_VST3" -eq 1 ]]; then
  run_export "vst3" "$PLUGIN_TARGET" "$VST3_FORMAT"
fi

if [[ "$KEEP_ACTIVE" == "au" && "$DO_AU" -eq 1 ]]; then
  run_export "au" "$PLUGIN_TARGET" "$AU_FORMAT"
fi

echo "CI export snapshots written to: $OUTPUT_DIR"
if [[ "$DO_VST3" -eq 1 ]]; then
  echo "  vst3:        $OUTPUT_DIR/vst3"
fi
if [[ "$DO_AU" -eq 1 ]]; then
  echo "  au:          $OUTPUT_DIR/au"
fi
if [[ "$DO_STANDALONE" -eq 1 ]]; then
  echo "  standalone:  $OUTPUT_DIR/standalone"
fi
