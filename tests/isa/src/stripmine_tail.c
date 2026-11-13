// Copyright 2026 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Stripmined loops whose last vl is not a multiple of 8 (e.g. 100 elements =
// 64 + 36 at e32/m4), whose tail elements used to come out as X.

#include "vector_macros.h"

#define MAXN 100

static uint32_t *a, *b, *out;

static void setup(void) {
  a = (uint32_t *)snrt_l1_alloc(MAXN * sizeof(uint32_t));
  b = (uint32_t *)snrt_l1_alloc(MAXN * sizeof(uint32_t));
  out = (uint32_t *)snrt_l1_alloc(MAXN * sizeof(uint32_t));
}

static void fill(int fp) {
  for (int i = 0; i < MAXN; i++) {
    // Small integers, exactly representable as float
    a[i] = fp ? 0x3f800000 + ((uint32_t)i << 16) : 3 * i + 1;
    b[i] = fp ? 0x3f800000 : 1000 + i;
    out[i] = 0xdeadbeef;
  }
  asm volatile("fence" ::: "memory");
}

static void run(int n, int fp) {
  uint32_t *pa = a, *pb = b, *po = out;
  for (int left = n; left > 0;) {
    unsigned int vl;
    asm volatile("vsetvli %[vl], %[avl], e32, m4, ta, ma"
                 : [vl] "=r"(vl)
                 : [avl] "r"(left));
    asm volatile("vle32.v v8, (%0)" ::"r"(pa) : "memory");
    asm volatile("vle32.v v16, (%0)" ::"r"(pb) : "memory");
    if (fp)
      asm volatile("vfadd.vv v24, v8, v16");
    else
      asm volatile("vadd.vv v24, v8, v16");
    asm volatile("vse32.v v24, (%0)" ::"r"(po) : "memory");
    pa += vl;
    pb += vl;
    po += vl;
    left -= vl;
  }
  asm volatile("fence" ::: "memory");
}

static void check(int casenum, int n, int fp) {
  for (int i = 0; i < MAXN; i++) {
    // 1 + i/128 plus 1 in float: exponent 1, the same mantissa
    uint32_t exp = i >= n ? 0xdeadbeef
                   : fp   ? 0x40000000 + ((uint32_t)i << 15)
                          : 3 * i + 1 + 1000 + i;
    if (out[i] != exp) {
      printf("[TC %d] Index %d FAILED. Got 0x%08x, expected 0x%08x.\n",
             casenum, i, out[i], exp);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", casenum);
}

void TEST_CASE1(void) {
  const int sizes[] = {100, 36, 4, 70, 65, 1, 99};
  for (int k = 0; k < (int)(sizeof(sizes) / sizeof(sizes[0])); k++) {
    fill(0);
    run(sizes[k], 0);
    check(1 + k, sizes[k], 0);
  }
}

void TEST_CASE2(void) {
  const int sizes[] = {100, 36, 4, 70};
  for (int k = 0; k < (int)(sizeof(sizes) / sizeof(sizes[0])); k++) {
    fill(1);
    run(sizes[k], 1);
    check(8 + k, sizes[k], 1);
  }
}

int main(void) {
  if (!snrt_is_spatz_core()) return 0;
  INIT_CHECK();
  enable_vec();
  enable_fp();
  setup();

  TEST_CASE1();
  TEST_CASE2();

  EXIT_CHECK();
}
