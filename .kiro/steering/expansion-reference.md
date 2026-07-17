---
inclusion: always
---

# pokeemerald-expansion Technical Reference

## Build System

| Target | What it does |
|--------|-------------|
| `make` / `make all` / `make modern` | Build ROM (all aliases for the same thing) |
| `make check` | Build test ROM + run tests via mgba-rom-test-hydra |
| `make debug` | Build with `-Og -g` debug flags |
| `make release` | Optimized + LTO build |
| `make clean` | Full clean |
| `make tidy` | Remove ROM + obj dirs only |

Key variables: `TEST=1`, `DEBUG=1`, `RELEASE=1`, `LTO=1`

Build pipeline: C → cpp → preproc (charmap) → cc1 (GCC ARM) → as → .o → ld → ELF → objcopy → GBA → gbafix

## Project Layout

### Source (`src/`)
- Battle: `battle_main.c`, `battle_script_commands.c`, `battle_util.c`, `battle_ai_*.c`, `battle_dynamax.c`, `battle_terastal.c`, `battle_z_move.c`, `battle_gimmick.c`
- Pokemon: `pokemon.c`, `pokemon_storage_system.c`
- Overworld: `overworld.c`, `fieldmap.c`, `field_*.c`, `event_object_movement.c`
- UI: `party_menu.c`, `pokemon_summary_screen.c`, `pokedex.c`, `start_menu.c`
- Scripts: `script.c`, `scrcmd.c`
- Data hub: `data.c` (includes everything from `src/data/`)

### Data (`src/data/`)
- `pokemon/species_info/gen_X_families.h` — Species definitions
- `pokemon/level_up_learnsets/` — Learnsets per generation
- `moves_info.h` — All move data
- `abilities.h` — Ability metadata
- `trainers.party` — Trainer defs (Showdown format)
- `wild_encounters.json` — Wild encounters
- `items.h` — Item data

### Maps (`data/maps/`)
Each map: `{MapName}/map.json` + `{MapName}/scripts.inc`
Groups: `data/maps/map_groups.json`
Layouts: `data/layouts/{LayoutName}/`

### Constants (`include/constants/`)
`species.h`, `moves.h`, `abilities.h`, `items.h`, `maps.h`, `flags.h`, `vars.h`, `trainers.h`, `songs.h`

### Config (`include/config/`)
Feature toggles via `#define`. Key files:
- `battle.h` — Battle mechanics (set to GEN_LATEST, GEN_3, etc.)
- `pokemon.h` — Species behavior
- `species_enabled.h` — Toggle Pokemon families/generations/forms
- `overworld.h`, `item.h`, `ai.h`, `debug.h`

### Graphics (`graphics/`)
- `pokemon/{name}/` — front.png, back.png, icon.png, palettes
- `trainers/`, `items/`, `object_events/`, `battle_anims/`, `types/`

### Sound (`sound/`)
- `songs/midi/` — MIDI files (mus_*.mid for BGM, se_*.mid for SFX)
- `song_table.inc` — Song registration
- `voicegroups/` — Instruments
- `direct_sound_samples/` — WAV samples
- Constants: `include/constants/songs.h`

## Common Tasks

### Change Starters
Edit `src/starter_choose.c`:
```c
#define GRASS_STARTER SPECIES_TREECKO
#define FIRE_STARTER  SPECIES_TORCHIC
#define WATER_STARTER SPECIES_MUDKIP
```

### Add a New Pokemon Species
1. `include/constants/species.h` — enum entry
2. `src/data/pokemon/species_info/gen_X_families.h` — full struct
3. `src/data/pokemon/level_up_learnsets/` — learnset
4. `graphics/pokemon/{name}/` — sprites + palettes
5. `include/config/species_enabled.h` — family flag

### Add a New Move
1. `include/constants/moves.h` — enum entry
2. `src/data/moves_info.h` — move data struct
3. `data/battle_anim_scripts.s` — animation
4. `src/data/battle_move_effects.h` — if new effect type

### Add a New Ability
1. `include/constants/abilities.h` — enum
2. `src/data/abilities.h` — info struct
3. `src/battle_util.c` / `src/battle_script_commands.c` — logic
4. Assign to species in species_info

### Modify Battle Mechanics
- Damage formula: `src/battle_util.c`
- Move effects: `src/battle_script_commands.c` + `data/battle_scripts_1.s`
- Type chart: `src/data/types_info.h`
- Config toggles: `include/config/battle.h`
- End-of-turn: `src/battle_end_turn.c`

### Add/Edit Maps
1. Use **Porymap** editor
2. `data/maps/{MapName}/map.json` — metadata, events, warps
3. `data/maps/{MapName}/scripts.inc` — scripts
4. `data/maps/map_groups.json` — registration

### Define Trainers
Edit `src/data/trainers.party`:
```
=== TRAINER_MY_GUY ===
Name: MY GUY
Class: Ace Trainer
Pic: Ace Trainer M
Music: Male
AI: Check Bad Move / Try To Faint

Gardevoir (F) @ Choice Specs
Level: 50
Ability: Trace
Nature: Timid
- Psychic
- Moonblast
```

### Add Music
1. MIDI → `sound/songs/midi/mus_name.mid`
2. Register in `sound/song_table.inc`
3. Add to `include/constants/songs.h`

### Toggle Features
Edit `include/config/` files. Examples:
- `P_GEN_4_POKEMON FALSE` — disable all Gen 4 species
- `B_CRIT_CHANCE GEN_3` — use Gen 3 crit rates
- `P_MEGA_EVOLUTIONS FALSE` — disable Mega Evolution

## Species Data Format (Struct Fields)
```
baseHP, baseAttack, baseDefense, baseSpeed, baseSpAttack, baseSpDefense
types, catchRate, expYield, evYield_*, genderRatio, eggCycles
friendship, growthRate, eggGroups, abilities[3]
bodyColor, speciesName, cryId, natDexNum, categoryName
height, weight, description
frontPic, backPic, palette, shinyPalette, iconSprite
levelUpLearnset, teachableLearnset, eggMoveLearnset
evolutions (EVOLUTION macro)
```

## Move Data Format (Struct Fields)
```
name, description, effect, power, type, accuracy, pp
target, priority, category (PHYSICAL/SPECIAL/STATUS)
flags: makesContact, isPulseMove, isBombMove, etc.
contestEffect, contestCategory
battleAnimScript
```

## Test System
Tests live in `test/battle/` using a DSL:
```c
SINGLE_BATTLE_TEST("Move X does Y") {
    GIVEN { PLAYER(SPECIES_A); OPPONENT(SPECIES_B); }
    WHEN { TURN { MOVE(player, MOVE_X); } }
    SCENE { HP_BAR(opponent, damage: 50); }
}
```
Run with `make check` or filter: `make check TESTS="battle/ability/intimidate"`
