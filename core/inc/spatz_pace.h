// Copyright 2026 ETH Zurich and University of Bologna.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <stdint.h>

#include "spatz_cfg.h"

#ifdef SNRT_CLUSTER_SPATZ_PACE_CSR
#define SPATZ_PACE_CSR SNRT_CLUSTER_SPATZ_PACE_CSR
#else
#define SPATZ_PACE_CSR 0xBA0
#endif

#define SPATZ_PACE_ENABLE (1u << 1)
#define SPATZ_PACE_DEGREE(d) ((uint32_t)(d) << 2)

// The two blob loads read words 0 to 127 and 64 to 191
#define SPATZ_PACE_BLOB_WORDS 192

// Spatz core only: PACE on, with a degree-2 polynomial
static inline void spatz_pace_enable(void) {
    __asm__ volatile("csrw %0, %1" ::"i"(SPATZ_PACE_CSR),
                     "rK"(SPATZ_PACE_ENABLE | SPATZ_PACE_DEGREE(2)));
}

// Spatz core only: the two overlapping loads that give PACE its coefficient blob
static inline void spatz_pace_load(const uint32_t *blob) {
    __asm__ volatile(
        "li t0, 64\n"
        "vsetvli x0, t0, e64, m8, ta, ma\n"
        "vle64.v v0, (%0)\n"
        "vle64.v v0, (%1)\n"
        :
        : "r"(blob), "r"(blob + 64)
        : "t0", "memory");
}

// While PACE is on, vfmul.vv evaluates the blob's polynomial instead of multiplying
static inline void spatz_pace_on(const uint32_t *blob) {
    spatz_pace_enable();
    spatz_pace_load(blob);
}

static inline void spatz_pace_off(void) {
    __asm__ volatile("csrw %0, zero" ::"i"(SPATZ_PACE_CSR) : "memory");
}
