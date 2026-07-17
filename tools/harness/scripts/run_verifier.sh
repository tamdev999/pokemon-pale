#!/bin/bash
# Run a single Lua verifier against the built ROM
#
# Usage: ./tools/harness/scripts/run_verifier.sh <verifier_name>
# Example: ./tools/harness/scripts/run_verifier.sh boot_check
#
# Environment variables:
#   MGBA_PATH  - path to mGBA binary (default: searches common locations)
#   ROM_PATH   - path to ROM file (default: pokeemerald.gba in project root)

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
HARNESS_DIR="$(dirname "$SCRIPT_DIR")"
PROJECT_ROOT="$(dirname "$(dirname "$HARNESS_DIR")")"

# Find mGBA
if [ -n "${MGBA_PATH:-}" ]; then
    MGBA="$MGBA_PATH"
elif command -v mgba-qt &>/dev/null; then
    MGBA="mgba-qt"
elif command -v mgba &>/dev/null; then
    MGBA="mgba"
elif [ -f "/mnt/c/Program Files/mGBA/mGBA.exe" ]; then
    # WSL accessing Windows mGBA install
    MGBA="/mnt/c/Program Files/mGBA/mGBA.exe"
elif [ -f "/c/Program Files/mGBA/mGBA.exe" ]; then
    MGBA="/c/Program Files/mGBA/mGBA.exe"
else
    echo "ERROR: mGBA not found. Set MGBA_PATH or install mGBA."
    echo "  Download: https://mgba.io/downloads.html"
    exit 1
fi

ROM="${ROM_PATH:-$PROJECT_ROOT/pokeemerald.gba}"
VERIFIER_NAME="${1:-}"

if [ -z "$VERIFIER_NAME" ]; then
    echo "Usage: $0 <verifier_name>"
    echo ""
    echo "Available verifiers:"
    ls "$HARNESS_DIR/lua/"*.lua 2>/dev/null | xargs -I{} basename {} .lua | sed 's/^/  /'
    exit 1
fi

VERIFIER_SCRIPT="$HARNESS_DIR/lua/${VERIFIER_NAME}.lua"

if [ ! -f "$VERIFIER_SCRIPT" ]; then
    echo "ERROR: Verifier not found: $VERIFIER_SCRIPT"
    exit 1
fi

if [ ! -f "$ROM" ]; then
    echo "ERROR: ROM not found at $ROM"
    echo "Build first with: make modern -j\$(nproc)"
    exit 1
fi

# Create screenshots directory
mkdir -p "$HARNESS_DIR/screenshots"

echo "╔══════════════════════════════════════╗"
echo "║ Verifier: $VERIFIER_NAME"
echo "║ ROM: $ROM"
echo "║ Script: $VERIFIER_SCRIPT"
echo "╚══════════════════════════════════════╝"
echo ""

# Launch mGBA with the Lua script
# -l: load and run Lua script on start
"$MGBA" -l "$VERIFIER_SCRIPT" "$ROM"

EXIT_CODE=$?

echo ""
if [ $EXIT_CODE -eq 0 ]; then
    echo "✓ $VERIFIER_NAME PASSED"
else
    echo "✗ $VERIFIER_NAME FAILED (exit code: $EXIT_CODE)"
fi

exit $EXIT_CODE
