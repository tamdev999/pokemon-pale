---
inclusion: always
---

# Pokémon Pale — Project Overview

## Base
pokeemerald-expansion (rh-hideout fork). All code is C targeting GBA via devkitARM.

## Premise
Fifty years after Pokémon X/Y. The Gym system is gone. Society follows spiritual traditions centered on the Pale — a realm the dead pass through. AZ's machine damaged the boundary between life and death. Zygarde kept the rupture sealed until the Pale Order captured it and split its power into three key fragments.

The player and their twin were born during the first major reopening of the Pale. Their mother entered a tear threatening Lavender Town and sacrificed herself to seal it. Years later, the seal fails.

The player seeks to enter the Pale, find their mother, and restore balance. Their twin joins the Pale Order, determined to conquer death itself.

## Setting
Kanto and Johto unified as the Indigo Region. Ten-act structure.

## Core Mechanics
- **Starters:** Gastly, Litwick, Duskull
- **Regional Dex:** Ghost, Psychic, Dark, Fairy focused
- **Permadeath:** Pokémon can permanently die in battle
- **Surrender:** Player can forfeit a battle (but not in Pale Battles)
- **Pale Battles:** Ceremonial battles — no switching, no surrender
- **Pale Forms:** Temporary power-up triggered at the edge of death
- **Pale-Touched:** Permanent enhancement after surviving a Pale Form trigger; grants Z-Move-style techniques
- **Resurrection:** Requires restored Zygarde + maximum friendship
- **Six Petals:** Knowledge · Emotion · Will · Life · Death · Order (replace Gym Badges)
- **Three Zygarde Key Fragments:** Recovered across the journey

## Visual Style
- Monochrome GBA graphics
- Portrait-based story dialogue

## Music
- Fully custom soundtrack (MIDI → GBA pipeline)

## Repository Layout (Custom additions)
- `.kiro/steering/` — Project context for AI-assisted development
- `tools/harness/` — Lua-based verification harness for mGBA testing
- `tools/harness/lua/` — Individual Lua verifier scripts
- `tools/harness/scripts/` — Shell scripts for harness automation
