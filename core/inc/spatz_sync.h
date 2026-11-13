// Copyright 2026 ETH Zurich and University of Bologna.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <stdint.h>

#include "spatz_cfg.h"

// The cluster barrier does not wait for Spatz stores: hand results over with a flag in every bank
#define SPATZ_FLAG_BYTES (SNRT_TCDM_BANK_NUM * SNRT_TCDM_BANK_WIDTH)
#define SPATZ_FLAG_WORDS (SPATZ_FLAG_BYTES / 4)
#define SPATZ_FLAG_STRIDE (SNRT_TCDM_BANK_WIDTH / 4)

#if SNRT_CLUSTER_HAS_SPATZ &&                                \
    (SPATZ_FLAG_BYTES != 512 || SNRT_TCDM_BANK_WIDTH != 8 || \
     SNRT_CLUSTER_SPATZ_VLEN_BITS < 512)
#error "spatz_sync.h needs 64 TCDM banks of 8 B and a VLEN of 512 or more"
#endif

// Spatz core, after its data stores: 1 into every word of the flag, in VLSU order
static inline void spatz_flag_publish(uint32_t *flag) {
    __asm__ volatile(
        "li t0, 64\n"
        "vsetvli x0, t0, e32, m4, ta, ma\n"
        "vmv.v.i v12, 1\n"
        "vse32.v v12, (%0)\n"
        "vse32.v v12, (%1)\n"
        :
        : "r"(flag), "r"(flag + 64)
        : "t0", "memory");
}

// Other cores: 1 once the flag reads 1 in every bank, checking the last-written word first
static inline int spatz_flag_ready(volatile uint32_t *f) {
    if (f[SPATZ_FLAG_WORDS - 2] != 1u) return 0;
    uint32_t all = 1u;
    for (int i = 0; i < SPATZ_FLAG_WORDS; i += 16)
        all &= f[i] & f[i + 2] & f[i + 4] & f[i + 6] & f[i + 8] & f[i + 10] &
               f[i + 12] & f[i + 14];
    return all == 1u;
}

static inline void spatz_flag_wait(volatile uint32_t *f) {
    for (int i = 0; i < SPATZ_FLAG_WORDS; i += SPATZ_FLAG_STRIDE)
        while (f[i] != 1u) {
        }
}

static inline void spatz_flag_clear(volatile uint32_t *f) {
    for (int i = 0; i < SPATZ_FLAG_WORDS; i += SPATZ_FLAG_STRIDE) f[i] = 0;
}
