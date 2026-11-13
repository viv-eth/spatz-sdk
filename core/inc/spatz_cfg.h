// Copyright 2025 ETH Zurich and University of Bologna.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// Authors: Sergio Mazzola <smazzola@iis.ee.ethz.ch>

#pragma once

#include <stdint.h>

#include "snitch_cluster_cfg.h"

#ifndef SNRT_CLUSTER_HAS_SPATZ
#error "snitch_cluster_cfg.h does not define SNRT_CLUSTER_HAS_SPATZ"
#endif

// Only 1 Spatz core per cluster
#define SPATZ_NUM_CORES SNRT_CLUSTER_HAS_SPATZ
#define SPATZ_CORE_IDX SNRT_CLUSTER_SPATZ_CORE_IDX
#define SPATZ_CORE_HARTID (SNRT_BASE_HARTID + SPATZ_CORE_IDX)

#define SPATZ_VLEN_BITS SNRT_CLUSTER_SPATZ_VLEN_BITS
#define SPATZ_NUM_FPU SNRT_CLUSTER_SPATZ_N_FPU
#define SPATZ_HAS_RVF SNRT_CLUSTER_SPATZ_HAS_RVF
#define SPATZ_HAS_RVD SNRT_CLUSTER_SPATZ_HAS_RVD

// Peak FMA operations per cycle: each 64-bit FPU does one FP64 or two FP32 FMAs
#define SPATZ_PEAK_FMA_OPS_PER_CYCLE_FP64 (2u * SPATZ_NUM_FPU)
#define SPATZ_PEAK_FMA_OPS_PER_CYCLE_FP32 (4u * SPATZ_NUM_FPU)

// Utilisation in per mille, from a performance in operations per 1000 cycles
#define SPATZ_UTILIZATION_PERMILLE(performance_kops, peak_ops_per_cycle) \
    ((performance_kops) / (peak_ops_per_cycle))
