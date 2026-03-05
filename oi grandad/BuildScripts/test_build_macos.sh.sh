#!/usr/bin/env bash
set -e

PROJECT="../Binaries/Builds/MacOSX/oi grandad.xcodeproj"

echo "Building VST3..."
xcodebuild \
-project "$PROJECT" \
-scheme "oi grandad - VST3" \
-configuration Release \
CODE_SIGNING_ALLOWED=NO \
build

echo "Building AU..."
xcodebuild \
-project "$PROJECT" \
-scheme "oi grandad - AU" \
-configuration Release \
CODE_SIGNING_ALLOWED=NO \
build

echo "Build complete."