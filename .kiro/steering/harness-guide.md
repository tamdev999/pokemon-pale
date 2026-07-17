---
inclusion: always
---

# Lua Verification Harness Guide

## Purpose
The harness uses mGBA's Lua scripting API (v0.10+) to automate gameplay testing.
Instead of manually playing through to verify changes, Lua scripts boot the ROM,
drive inputs, read memory, and assert expected behavior.

Inspired by Kyle Gill's Safari Gauntlet project which used ~40 Lua verifier scripts
to regression-test every behavior in an AI-built ROM hack.

## Architecture
```
tools/harness/
├── lua/                    # Individual verifier scripts
│   ├── boot_check.lua      # Verifies ROM boots to title screen
│   └── ...                 # One script per testable behavior
├── scripts/
│   ├── run_verifier.sh     # Launches mGBA with a Lua script
│   └── run_all.sh          # Runs all verifiers in sequence
├── screenshots/            # Captured during verification (gitignored)
└── README.md               # Harness documentation
```

## mGBA Scripting API (GBA-specific)

### Top-Level Objects
- `emu` — CoreAdapter instance (available when ROM is loaded)
- `C` — Constants table (includes `C.GBA_KEY`)
- `callbacks` — CallbackManager singleton
- `console` — Console singleton for logging

### Key Constants (C.GBA_KEY)
```lua
C.GBA_KEY.A      -- 0
C.GBA_KEY.B      -- 1
C.GBA_KEY.SELECT -- 2
C.GBA_KEY.START  -- 3
C.GBA_KEY.RIGHT  -- 4
C.GBA_KEY.LEFT   -- 5
C.GBA_KEY.UP     -- 6
C.GBA_KEY.DOWN   -- 7
C.GBA_KEY.R      -- 8
C.GBA_KEY.L      -- 9
```

### Core/Emu Methods
```lua
emu:runFrame()                  -- Advance one frame
emu:currentFrame()              -- Get current frame number
emu:addKey(key)                 -- Press a key (stays held)
emu:clearKey(key)               -- Release a key
emu:setKeys(bitmask)            -- Set all keys at once via bitmask
emu:getKeys()                   -- Get currently pressed keys bitmask
emu:read8(address)              -- Read byte from bus address
emu:read16(address)             -- Read 16-bit from bus address
emu:read32(address)             -- Read 32-bit from bus address
emu:write8(address, value)      -- Write byte to bus address
emu:write16(address, value)     -- Write 16-bit to bus address
emu:write32(address, value)     -- Write 32-bit to bus address
emu:screenshot(path)            -- Save screenshot to file
emu:reset()                     -- Reset emulation
emu:loadStateSlot(slot)         -- Load save state
emu:saveStateSlot(slot)         -- Save state to slot
```

### Memory Domains (GBA)
Access via `emu.memory`:
- `emu.memory.wram` — EWRAM (0x02000000, 256KB)
- `emu.memory.iwram` — IWRAM (0x03000000, 32KB)
- `emu.memory.cart0` — ROM (0x08000000)
- `emu.memory.vram` — VRAM (0x06000000)
- `emu.memory.palette` — Palette (0x05000000)
- `emu.memory.oam` — OAM (0x07000000)

Each domain has: `read8`, `read16`, `read32`, `write8`, `write16`, `write32`, `readRange`, `size`, `base`, `bound`

### Callbacks
```lua
callbacks:add("frame", function() ... end)      -- Every frame
callbacks:add("keysRead", function() ... end)   -- Before key read
callbacks:add("reset", function() ... end)      -- On reset
callbacks:add("crashed", function() ... end)    -- On crash
```

## How to Write a Verifier (Pattern from Safari Gauntlet)

Each Lua verifier script follows this proven pattern:

```lua
-- Verifier: <name>
-- Purpose: <one-line description>
-- Expected: <what constitutes PASS>

local log_path = "/tmp/pokemon-pale-<name>.log"
local screenshot_path = "/tmp/pokemon-pale-<name>.png"

local KEY = C.GBA_KEY

-- Memory addresses relevant to this test
local W = {
    -- Define addresses here
}

-- Logging
local f = io.open(log_path, "w")
local function log(msg)
    local line = string.format("[%08d] %s", emu:currentFrame(), msg)
    if f then f:write(line .. "\n"); f:flush() end
    console:log(line)
end

-- Input helpers
local function pulse_key(key, hold, wait)
    hold = hold or 4; wait = wait or 16
    emu:addKey(key)
    for _ = 1, hold do emu:runFrame() end
    emu:clearKey(key)
    for _ = 1, wait do emu:runFrame() end
end

-- === TEST LOGIC ===
log("Verifier loaded: <name>")

-- Drive the game to the state you want to test
-- Read memory to verify expected state
-- Log PASS or FAIL

emu:screenshot(screenshot_path)
if f then f:close() end
```

## Important pokeemerald-expansion Memory Addresses

These addresses are for the GBA bus. Many live in IWRAM (0x03000000 range):

```
gMain.callback2     = 0x030022C0  (active game state function pointer)
gMain.state         = 0x030022C4  (state machine counter)
```

Party, map, and custom mechanic addresses will be documented here as we
discover them during implementation. Use the pokeemerald-expansion .map file
(generated during build) to look up symbol addresses.

### Finding Addresses
After building with `make modern`, check `pokeemerald.map` for symbol addresses:
```bash
grep "gMain" pokeemerald.map
grep "gPlayerParty" pokeemerald.map
grep "gSaveBlock1" pokeemerald.map
```

## Running the Harness

### Quick Start (one command)
```powershell
.\tools\harness\scripts\start_testing.ps1
```
This launches mGBA (dev build with auto-loaded socket server) + mGBA-http.
After it's running, Kiro has full control via HTTP at `http://localhost:5000`.

### How It Works
1. **mGBA dev build** (0.11) launches with `--script mGBASocketServer.lua` (auto-loads the socket server)
2. **mGBA-http** connects to mGBA's socket and exposes a REST API
3. **Kiro/scripts** send HTTP requests to `localhost:5000` to control the emulator

### What We Can Do Via HTTP
```powershell
# Read game info
Invoke-RestMethod http://localhost:5000/core/getgametitle     # "POKEMON EMER"
Invoke-RestMethod http://localhost:5000/core/getgamecode      # "AGB-BPEE"
Invoke-RestMethod http://localhost:5000/core/currentframe     # frame number

# Press buttons
Invoke-RestMethod http://localhost:5000/mgba-http/button/tap?button=A -Method Post
Invoke-RestMethod http://localhost:5000/mgba-http/button/tap?button=Start -Method Post

# Read memory (address as decimal)
Invoke-RestMethod http://localhost:5000/core/read8?address=50331648    # read 1 byte
Invoke-RestMethod http://localhost:5000/core/read16?address=50331648   # read 2 bytes
Invoke-RestMethod http://localhost:5000/core/read32?address=50331648   # read 4 bytes

# Screenshots
Invoke-RestMethod "http://localhost:5000/core/screenshot?path=C:/path/to/output.png" -Method Post

# Load save state
Invoke-RestMethod "http://localhost:5000/core/loadstatefile?path=C:/path/to/state.ss1" -Method Post
```

### Swagger UI
Browse to `http://localhost:5000/index.html` for interactive API docs.

### Prerequisites
- **mGBA dev build (0.11+)** at `C:\Tools\mGBA-dev\current\` for `--script` auto-load
- **mGBA-http v0.8.2** at `C:\Tools\mGBA-http\`
  - `mGBA-http.exe` — HTTP server
  - `mGBASocketServer.lua` — socket bridge loaded into mGBA
- ROM at `build-output/pokeemerald.gba`

### Fallback (stable mGBA 0.10.5)
If using stable mGBA, manually load the socket server:
1. Open mGBA → load ROM
2. Tools → Scripting → File → Load Script → `C:\Tools\mGBA-http\mGBASocketServer.lua`
3. Run `C:\Tools\mGBA-http\mGBA-http.exe`

## Rules
- Each verifier tests ONE behavior
- Print PASS/FAIL with a description to the console
- Save a screenshot as evidence
- Log to /tmp/ for debugging
- Verifiers should complete within a reasonable frame count (< 10000 frames)
- Use bus addresses (0x02xxxxxx for EWRAM, 0x03xxxxxx for IWRAM) for reads
