#!/usr/bin/env bash
# Copyright 2026 ETH Zurich and University of Bologna.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
#
# Usage: check_headers.sh <llvm install>; compiles the headers as C and C++ for a Spatz cluster
set -euo pipefail
cc=$1/bin/clang
root=$(cd "$(dirname "$0")/.." && pwd)
out=$(mktemp -d)
trap 'rm -rf "$out"' EXIT
flags=(--target=riscv32-unknown-elf -march=rv32imafdv -mabi=ilp32d -mno-implicit-float -O2 -Wall
       -Wextra -Werror -I"$root/core/inc" -I"$root/tests/headers" -c)
"$cc" "${flags[@]}" -x c -std=c11 "$root/tests/headers/check.c" -o "$out/c.o"
"$cc" "${flags[@]}" -x c++ -std=c++17 "$root/tests/headers/check.c" -o "$out/cxx.o"
echo "spatz-sdk headers compile as C and C++"
