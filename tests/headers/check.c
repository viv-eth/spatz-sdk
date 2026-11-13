// Copyright 2026 ETH Zurich and University of Bologna.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include "spatz.h"

uint32_t check_spatz(const uint32_t *blob, uint32_t *flag) {
    spatz_pace_on(blob);
    spatz_pace_load(blob);
    spatz_pace_off();
    spatz_flag_clear(flag);
    spatz_flag_publish(flag);
    spatz_flag_wait(flag);
    return (uint32_t)spatz_flag_ready(flag) + SPATZ_CORE_HARTID +
           SPATZ_PEAK_FMA_OPS_PER_CYCLE_FP32 +
           SPATZ_UTILIZATION_PERMILLE(1000u,
                                      SPATZ_PEAK_FMA_OPS_PER_CYCLE_FP64) +
           SPATZ_VLEN_BITS + SPATZ_HAS_RVF + SPATZ_HAS_RVD + SPATZ_NUM_CORES +
           SPATZ_PACE_BLOB_WORDS;
}
