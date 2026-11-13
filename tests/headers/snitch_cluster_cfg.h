// Copyright 2026 ETH Zurich and University of Bologna.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

// The Spatz part of a cluster configuration, as Konark's generates it
#pragma once

#define SNRT_BASE_HARTID 1
#define SNRT_TCDM_BANK_WIDTH 8
#define SNRT_TCDM_BANK_NUM 64

#define SNRT_CLUSTER_HAS_SPATZ 1
#define SNRT_CLUSTER_SPATZ_CORE_IDX 1
#define SNRT_CLUSTER_SPATZ_VLEN_BITS 512
#define SNRT_CLUSTER_SPATZ_N_FPU 4
#define SNRT_CLUSTER_SPATZ_HAS_RVF 1
#define SNRT_CLUSTER_SPATZ_HAS_RVD 1
