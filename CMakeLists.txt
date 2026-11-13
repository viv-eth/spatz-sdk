# Copyright 2026 ETH Zurich and University of Bologna.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13)
project(spatz_sdk VERSION 0.1.0 LANGUAGES NONE)

add_library(spatz_sdk INTERFACE)
target_include_directories(spatz_sdk INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/core/inc)

set(SPATZ_SDK_ISA_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests/isa/src CACHE INTERNAL "Spatz ISA test sources")
