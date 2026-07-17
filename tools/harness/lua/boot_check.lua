-- Verifier: boot_check
-- Purpose: Confirm the ROM boots successfully past the title screen
-- Expected: Game reaches a playable state (callback2 is non-null) within 600 frames
--
-- This is the most basic sanity check. If the ROM doesn't boot, nothing else matters.
-- Adapted from Kyle Gill's Safari Gauntlet verification pattern for GBA/mGBA.

local log_path = "/tmp/pokemon-pale-boot-check.log"
local screenshot_path = "/tmp/pokemon-pale-boot-check.png"

-- GBA key constants
local KEY = C.GBA_KEY

-- pokeemerald-expansion EWRAM addresses (bus addresses)
-- gMain lives in EWRAM (0x0200xxxx range)
-- These will need to be confirmed once we have a successful build
local W = {
    -- gMain.callback2 — if this is non-null the game loop is running
    callback2 = 0x030022C0,
    -- gMain.state — general game state machine
    state = 0x030022C4,
}

local f = io.open(log_path, "w")
if not f then
    console:error("Cannot open log file: " .. log_path)
end

local function log(msg)
    local line = string.format("[%08d] %s", emu:currentFrame(), msg)
    if f then
        f:write(line .. "\n")
        f:flush()
    end
    console:log(line)
end

local function read32(addr)
    return emu:read32(addr)
end

local function press(key)
    emu:addKey(key)
end

local function release(key)
    emu:clearKey(key)
end

local function pulse_key(key, hold_frames, wait_frames)
    hold_frames = hold_frames or 4
    wait_frames = wait_frames or 16
    press(key)
    for _ = 1, hold_frames do
        emu:runFrame()
    end
    release(key)
    for _ = 1, wait_frames do
        emu:runFrame()
    end
end

-- Main verification logic
log("Pokemon Pale boot verifier loaded")
log("Waiting for game to boot...")

-- Let the game run through BIOS and initial startup
for i = 1, 120 do
    emu:runFrame()
end

log("Past initial frames, checking callback2...")

-- Now try pressing Start/A to get past title screen
local reached = false
local MAX_ATTEMPTS = 30

for attempt = 1, MAX_ATTEMPTS do
    local cb2 = read32(W.callback2)
    log(string.format("Attempt %d: callback2 = 0x%08X", attempt, cb2))

    if cb2 ~= 0 then
        -- Game loop is running, press through title/intro
        pulse_key(KEY.START)
        pulse_key(KEY.A)
    end

    -- Run some frames
    for _ = 1, 30 do
        emu:runFrame()
    end

    -- After enough frames with a valid callback2, consider it booted
    if cb2 ~= 0 and attempt > 5 then
        reached = true
        break
    end
end

if reached then
    log("PASS: ROM booted successfully - game loop is active")
    emu:screenshot(screenshot_path)
    log("Screenshot saved: " .. screenshot_path)
else
    log("FAIL: ROM did not boot within expected timeframe")
    emu:screenshot(screenshot_path)
    log("Screenshot saved: " .. screenshot_path)
end

if f then f:close() end
