#!/bin/bash
# Pokémon Pale — WSL2 Build Environment Setup
#
# Run this script inside WSL2 (Ubuntu) to install all dependencies
# needed to build the pokeemerald-expansion ROM.
#
# Usage (from WSL):
#   chmod +x tools/setup_wsl.sh
#   ./tools/setup_wsl.sh
#
# After running, build with:
#   make modern -j$(nproc)

set -euo pipefail

echo "=== Pokémon Pale: WSL2 Build Environment Setup ==="
echo ""

# 1. Update packages
echo "[1/4] Updating system packages..."
sudo apt-get update -qq
sudo apt-get upgrade -y -qq

# 2. Install build dependencies
echo "[2/4] Installing build dependencies..."
sudo apt-get install -y -qq \
    gcc \
    g++ \
    make \
    git \
    libpng-dev \
    binutils-arm-none-eabi \
    wget \
    curl \
    pkg-config

# 3. Install devkitPro (devkitARM)
echo "[3/4] Installing devkitPro (devkitARM)..."

# Check if already installed
if [ -d "/opt/devkitpro/devkitARM" ]; then
    echo "  devkitARM already installed at /opt/devkitpro/devkitARM"
else
    # Add devkitPro repository
    wget -q https://apt.devkitpro.org/install-devkitpro-pacman -O /tmp/install-devkitpro-pacman
    chmod +x /tmp/install-devkitpro-pacman
    sudo /tmp/install-devkitpro-pacman -y

    # Install GBA dev tools
    sudo dkp-pacman -S --noconfirm gba-dev

    echo "  devkitARM installed successfully"
fi

# 4. Set up environment variables
echo "[4/4] Configuring environment..."

DEVKIT_ENV='
# devkitPro environment (for pokeemerald-expansion builds)
export DEVKITPRO=/opt/devkitpro
export DEVKITARM=/opt/devkitpro/devkitARM
export PATH=$DEVKITPRO/tools/bin:$DEVKITARM/bin:$PATH
'

# Add to .bashrc if not already present
if ! grep -q "DEVKITPRO" ~/.bashrc; then
    echo "$DEVKIT_ENV" >> ~/.bashrc
    echo "  Added devkitPro paths to ~/.bashrc"
else
    echo "  devkitPro paths already in ~/.bashrc"
fi

# Source it for the current session
export DEVKITPRO=/opt/devkitpro
export DEVKITARM=/opt/devkitpro/devkitARM
export PATH=$DEVKITPRO/tools/bin:$DEVKITARM/bin:$PATH

echo ""
echo "=== Setup Complete ==="
echo ""
echo "Build the ROM with:"
echo "  make modern -j\$(nproc)"
echo ""
echo "Run tests with:"
echo "  make test"
echo ""
echo "If this is a fresh terminal, run 'source ~/.bashrc' first."
