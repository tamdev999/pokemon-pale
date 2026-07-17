# Pokemon Pale - Start Testing Environment
# Launches mGBA (dev) with socket server + mGBA-http
# After this runs, Kiro can control mGBA via HTTP at localhost:5000
#
# Usage: .\tools\harness\scripts\start_testing.ps1 [rom_path]

param(
    [string]$RomPath = ""
)

$ErrorActionPreference = "Stop"

# Paths
$ProjectRoot = (Resolve-Path "$PSScriptRoot\..\..\..").Path
$MgbaDevExe = "C:\Tools\mGBA-dev\current\mGBA.exe"
$MgbaStableExe = "C:\Tools\mGBA\mGBA-0.10.5-win64\mGBA.exe"
$MgbaHttpExe = "C:\Tools\mGBA-http\mGBA-http.exe"
$SocketServerLua = "C:\Tools\mGBA-http\mGBASocketServer.lua"

# Use dev build if available (supports --script), fall back to stable
if (Test-Path $MgbaDevExe) {
    $MgbaExe = $MgbaDevExe
    $SupportsScript = $true
} else {
    $MgbaExe = $MgbaStableExe
    $SupportsScript = $false
}

# Default ROM path
if (-not $RomPath) {
    $RomPath = "$ProjectRoot\build-output\pokeemerald.gba"
}

if (!(Test-Path $RomPath)) {
    Write-Error "ROM not found: $RomPath"
    exit 1
}

if (!(Test-Path $MgbaHttpExe)) {
    Write-Error "mGBA-http not found at $MgbaHttpExe"
    exit 1
}

if (!(Test-Path $SocketServerLua)) {
    Write-Error "mGBASocketServer.lua not found at $SocketServerLua"
    exit 1
}

# Kill any existing instances
Stop-Process -Name "mGBA" -Force -ErrorAction SilentlyContinue
Stop-Process -Name "mGBA-http" -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 1

Write-Host "=== Pokemon Pale Testing Environment ==="
Write-Host ""

# Launch mGBA
if ($SupportsScript) {
    Write-Host "[1/3] Launching mGBA (dev) with --script autoload..."
    Start-Process -FilePath $MgbaExe -ArgumentList "--script", $SocketServerLua, $RomPath
} else {
    Write-Host "[1/3] Launching mGBA (stable)..."
    Write-Host "  >>> You must manually load the socket server script! <<<"
    Write-Host "  >>> Tools > Scripting > File > Load: $SocketServerLua <<<"
    Start-Process -FilePath $MgbaExe -ArgumentList $RomPath
}

Write-Host "  Waiting for mGBA to start..."
Start-Sleep -Seconds 4

# Launch mGBA-http
Write-Host "[2/3] Starting mGBA-http server..."
Start-Process -FilePath $MgbaHttpExe -WindowStyle Minimized
Start-Sleep -Seconds 3

# Verify connection
Write-Host "[3/3] Verifying connection..."
try {
    $title = Invoke-RestMethod -Uri "http://localhost:5000/core/getgametitle" -Method Get -TimeoutSec 5
    Write-Host ""
    Write-Host "=== READY ==="
    Write-Host "  Game: $title"
    Write-Host "  API:  http://localhost:5000"
    Write-Host "  Swagger: http://localhost:5000/index.html"
    Write-Host ""
    Write-Host "Kiro can now control mGBA via HTTP."
} catch {
    Write-Host ""
    Write-Host "WARNING: Could not connect to mGBA-http."
    Write-Host "  Make sure the socket server script is loaded in mGBA."
    Write-Host "  Error: $_"
}
