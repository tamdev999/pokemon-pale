#!/bin/bash
# Run all Lua verifiers in sequence
#
# Usage: ./tools/harness/scripts/run_all.sh
#
# Exits with code 1 if any verifier fails.

set -uo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
HARNESS_DIR="$(dirname "$SCRIPT_DIR")"

TOTAL=0
PASSED=0
FAILED=0
FAILED_NAMES=()

for verifier in "$HARNESS_DIR/lua/"*.lua; do
    if [ ! -f "$verifier" ]; then
        echo "No verifiers found in $HARNESS_DIR/lua/"
        exit 1
    fi

    name="$(basename "$verifier" .lua)"
    TOTAL=$((TOTAL + 1))

    echo "========================================"
    echo "Running: $name"
    echo "========================================"

    if "$SCRIPT_DIR/run_verifier.sh" "$name"; then
        PASSED=$((PASSED + 1))
    else
        FAILED=$((FAILED + 1))
        FAILED_NAMES+=("$name")
    fi

    echo ""
done

echo "========================================"
echo "RESULTS: $PASSED/$TOTAL passed, $FAILED failed"
echo "========================================"

if [ $FAILED -gt 0 ]; then
    echo "Failed verifiers:"
    for name in "${FAILED_NAMES[@]}"; do
        echo "  ✗ $name"
    done
    exit 1
fi

echo "All verifiers passed! ✓"
exit 0
