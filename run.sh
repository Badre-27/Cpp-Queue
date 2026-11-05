#!/bin/sh
#
# Build and run script for Linux/macOS
#
# This script compiles your C++ program using g++ and runs it.
# Usage: ./run.sh

set -e # Exit early if any commands fail

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Navigate to the script's directory (project root when downloaded)
cd "$(dirname "$0")"

echo "=== Queue ==="
echo ""

# Check for C++ compiler
COMPILER=""
if command -v g++ >/dev/null 2>&1; then
    COMPILER="g++"
elif command -v clang++ >/dev/null 2>&1; then
    COMPILER="clang++"
elif command -v c++ >/dev/null 2>&1; then
    COMPILER="c++"
fi

if [ -z "$COMPILER" ]; then
    echo "${RED}Error: No C++ compiler found${NC}"
    echo ""
    echo "Install compiler:"
    echo "  macOS:  xcode-select --install"
    echo "  Ubuntu: sudo apt install build-essential"
    echo ""
    exit 1
fi

echo "${GREEN}✓${NC} Using compiler: $COMPILER"
echo ""

# Compile the program
echo "Compiling main.cpp..."
if ! $COMPILER -std=c++17 -Wall -o queue main.cpp; then
    echo ""
    echo "${RED}Error: Compilation failed${NC}"
    exit 1
fi

echo ""
echo "${GREEN}=== Build Complete! ===${NC}"
echo ""
echo "Running: ./queue"
echo "---"
echo ""

# Run the program
exec ./queue "$@"
