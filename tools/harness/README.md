# Pokémon Pale — Verification Harness

Lua-based testing harness for mGBA. Automates gameplay verification so we don't have to manually play through every change.

## Prerequisites
- [mGBA](https://mgba.io/) installed and accessible in PATH (or set `MGBA_PATH` env var)
- ROM built via `make modern` (output: `pokeemerald.gba`)

## Quick Start

```bash
# Build the ROM first
make modern

# Run a single verifier
./tools/harness/scripts/run_verifier.sh boot_check

# Run all verifiers
./tools/harness/scripts/run_all.sh
```

## Writing Verifiers

Add new `.lua` files to `tools/harness/lua/`. Each script should:
1. Define what it's testing in a comment header
2. Use frame callbacks to drive the game
3. Exit with code 0 (pass) or 1 (fail)
4. Print PASS/FAIL with a human-readable message

See `.kiro/steering/harness-guide.md` for the full API reference and patterns.

## Directory Structure

```
tools/harness/
├── lua/              # Verifier scripts (one per behavior)
├── scripts/          # Runner scripts
├── screenshots/      # Captured during verification (gitignored)
└── README.md         # This file
```
