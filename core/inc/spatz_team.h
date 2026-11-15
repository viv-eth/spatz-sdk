// Copyright 2026 ETH Zurich and University of Bologna.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <stdint.h>

#include "spatz_cfg.h"

// Needs snitch-sdk's team.h; the platform's snrt.h includes this header after it
static inline uint32_t __attribute__((const)) snrt_cluster_spatz_core_num() {
    return SNRT_CLUSTER_HAS_SPATZ;
}

static inline int __attribute__((const)) snrt_is_spatz_core() {
    return SNRT_CLUSTER_HAS_SPATZ &&
           snrt_cluster_core_idx() == SNRT_CLUSTER_SPATZ_CORE_IDX;
}
