# Pokemon Pale - Run a Lua verifier against the built ROM (Windows)
#
# Usage: .\tools\harness\scripts\run_verifier.ps1 <verifier_name>
# Example: .\tools\harness\scripts\run_verifier.ps1 boot_verify_run
#
# Requires: mGBA dev build (0.11+) at C:\Tools\mGBA-dev\current\

param(
    [Parameter(Mandatory=$true)]
    [string]$VerifierName
)

$ErrorActionPreference = "Stop"

# Paths
$ProjectRoot = (Resolve-Path "$PSScriptRoot\..\..\..").Path
$HarnessDir = "$ProjectRoot\tools\harness"
$MgbaExe = "C:\Tools\mGBA-dev\current\mGBA.exe"
$RomPath = "$ProjectRoot\build-output\pokeemerald.gba"

# Validate
if (!(Test-Path $MgbaExe)) {
    Write-Error "mGBA dev build not found at $MgbaExe. Download from https://mgba.io/downloads.html (Development section)"
    exit 1
}

$LuaScript = "$HarnessDir\lua\$VerifierName.lua"
if (!(Test-Path $LuaScript)) {
    Write-Host "ERROR: Verifier not found: $LuaScript"
    Write-Host ""
    Write-Host "Available verifiers:"
    Get-ChildItem "$HarnessDir\lua\*.lua" | ForEach-Object { Write-Host "  $($_.BaseName)" }
    exit 1
}

if (!(Test-Path $RomPath)) {
    Write-Error "ROM not found at $RomPath. Download from GitHub Actions artifacts first."
    exit 1
}

# Check for BOM in the lua file (common Windows issue)
$bytes = [System.IO.File]::ReadAllBytes($LuaScript)
if ($bytes.Length -ge 3 -and $bytes[0] -eq 0xEF -and $bytes[1] -eq 0xBB -and $bytes[2] -eq 0xBF) {
    Write-Host "WARNING: Lua file has UTF-8 BOM. Stripping it..."
    $content = [System.IO.File]::ReadAllText($LuaScript)
    [System.IO.File]::WriteAllText($LuaScript, $content, (New-Object System.Text.UTF8Encoding $false))
}

Write-Host "================================"
Write-Host " Verifier: $VerifierName"
Write-Host " ROM: $RomPath"
Write-Host " Script: $LuaScript"
Write-Host "================================"
Write-Host ""

# Launch mGBA with script
& $MgbaExe --script $LuaScript $RomPath
