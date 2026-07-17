---
inclusion: always
---

# Development Conventions

## Build System
- Build with `make` inside WSL2 (devkitARM toolchain)
- `make modern` for the modern build (preferred — enables warnings and modern C features)
- `make check` to verify ROM integrity
- `make test` to run the built-in C test suite

## File Locations (pokeemerald-expansion)
- Species definitions: `src/data/pokemon/` and `include/constants/species.h`
- Move data: `src/data/moves_info.h` and `include/constants/moves.h`
- Ability data: `src/data/abilities.h` and `include/constants/abilities.h`
- Battle engine: `src/battle_*.c`
- Maps: `data/maps/` (each map has map.json, scripts.pory/scripts.inc, events.json)
- Music: `sound/songs/` (MIDI files + voicegroups)
- Graphics/sprites: `graphics/pokemon/` for species art
- Trainers: `src/data/trainers/`
- Wild encounters: `src/data/wild_encounters.json`
- Constants: `include/constants/`
- Config flags: `include/config/`

## Naming Conventions
- Custom mechanics prefixed: `PALE_` for flags, `pale_` for functions
- Custom species use standard expansion naming: `SPECIES_PALE_GASTLY` for Pale Forms
- Custom moves: `MOVE_PALE_*` for Pale-Touched techniques
- Custom abilities: `ABILITY_PALE_*`

## Testing
- Always verify the ROM compiles after changes (`make modern`)
- Use the Lua harness (`tools/harness/`) to verify gameplay behavior
- Run built-in tests with `make test` for battle mechanic changes

## Git Workflow
- Work on feature branches off `master`
- Branch naming: `feature/<short-description>`, `mechanic/<name>`, `content/<area>`
- Commit messages: concise, prefixed with area (e.g., "battle: add permadeath flag check")
