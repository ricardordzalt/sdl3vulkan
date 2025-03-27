#!/bin/bash
set -e

echo "[1/4] Updating submodules..."
git submodule update --init --recursive

echo "[2/4] Bootstrapping vcpkg..."
./external/vcpkg/bootstrap-vcpkg.sh

echo "[3/4] Configuring project using CMake preset..."
cmake --preset default

echo "[4/4] Building project..."
cmake --build --preset default
