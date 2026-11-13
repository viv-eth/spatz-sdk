// Copyright 2026 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Unit-stride loads/stores and chained load-add-store sequences at every vl,
// which exercise how the two VLSU interfaces split a register group.

#include "vector_macros.h"

static uint32_t *a, *z, *o;

static void clear_out(void) {
  for (int i = 0; i < 128; i++) o[i] = 0xdeadbeef;
  asm volatile("fence" ::: "memory");
}

// Elements below vl must be i * mul
static int check(int casenum, int vl, int mul) {
  asm volatile("fence" ::: "memory");
  for (int i = 0; i < vl; i++)
    if (o[i] != (uint32_t)(mul * i)) {
      printf("[TC %d] vl %d, index %d FAILED. Got 0x%08x, expected 0x%08x.\n",
             casenum, vl, i, o[i], mul * i);
      num_failed++;
      return 1;
    }
  return 0;
}

// Load at vl into a register just written by a full load, store it all
void TEST_CASE1(void) {
  for (int vl = 1; vl <= 64; vl++) {
    clear_out();
    asm volatile("vsetvli zero, %[full], e32, m4, ta, ma\n"
                 "vle32.v v8, (%[z])\n"
                 "vsetvli zero, %[vl], e32, m4, ta, ma\n"
                 "vle32.v v8, (%[a])\n"
                 "vsetvli zero, %[full], e32, m4, ta, ma\n"
                 "vse32.v v8, (%[o])\n" ::[full] "r"(64),
                 [vl] "r"(vl), [a] "r"(a), [z] "r"(z), [o] "r"(o)
                 : "memory");
    if (check(1, vl, 1)) return;
  }
  printf("[TC 1] PASSED.\n");
}

// Store at vl from a fully loaded register
void TEST_CASE2(void) {
  for (int vl = 1; vl <= 64; vl++) {
    clear_out();
    asm volatile("vsetvli zero, %[full], e32, m4, ta, ma\n"
                 "vle32.v v8, (%[a])\n"
                 "vsetvli zero, %[vl], e32, m4, ta, ma\n"
                 "vse32.v v8, (%[o])\n" ::[full] "r"(64),
                 [vl] "r"(vl), [a] "r"(a), [o] "r"(o)
                 : "memory");
    if (check(2, vl, 1)) return;
  }
  printf("[TC 2] PASSED.\n");
}

// Chained load, add and store with the same vl
void TEST_CASE3(void) {
  for (int vl = 1; vl <= 64; vl++) {
    clear_out();
    asm volatile("vsetvli zero, %[vl], e32, m4, ta, ma\n"
                 "vle32.v v8, (%[a])\n"
                 "vadd.vv v16, v8, v8\n"
                 "vse32.v v16, (%[o])\n" ::[vl] "r"(vl),
                 [a] "r"(a), [o] "r"(o)
                 : "memory");
    if (check(3, vl, 2)) return;
  }
  printf("[TC 3] PASSED.\n");
}

void TEST_CASE4(void) {
  for (int vl = 60; vl <= 128; vl++) {
    clear_out();
    asm volatile("vsetvli zero, %[vl], e32, m8, ta, ma\n"
                 "vle32.v v8, (%[a])\n"
                 "vadd.vv v16, v8, v8\n"
                 "vse32.v v16, (%[o])\n" ::[vl] "r"(vl),
                 [a] "r"(a), [o] "r"(o)
                 : "memory");
    if (check(4, vl, 2)) return;
  }
  printf("[TC 4] PASSED.\n");
}

int main(void) {
  if (!snrt_is_spatz_core()) return 0;
  INIT_CHECK();
  enable_vec();
  a = (uint32_t *)snrt_l1_alloc(128 * sizeof(uint32_t));
  z = (uint32_t *)snrt_l1_alloc(128 * sizeof(uint32_t));
  o = (uint32_t *)snrt_l1_alloc(128 * sizeof(uint32_t));
  for (int i = 0; i < 128; i++) {
    a[i] = i;
    z[i] = 0xaaaaaaaa;
  }

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();

  EXIT_CHECK();
}
