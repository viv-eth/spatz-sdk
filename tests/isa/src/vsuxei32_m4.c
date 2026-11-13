// Copyright 2026 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Indexed accesses at e32/m4/vl=64 with a reversed index (FFT-style
// permutation), which used to misplace and drop elements.

#include "vector_macros.h"

#define N 64

static uint32_t *src, *idx, *dst;

static void setup(void) {
  src = (uint32_t *)snrt_l1_alloc(N * sizeof(uint32_t));
  idx = (uint32_t *)snrt_l1_alloc(N * sizeof(uint32_t));
  dst = (uint32_t *)snrt_l1_alloc(N * sizeof(uint32_t));
  for (int g = 0; g < N; g++) {
    src[g] = 1000 + g;
    idx[g] = (N - 1 - g) * sizeof(uint32_t);
  }
}

static void clear_dst(void) {
  for (int g = 0; g < N; g++) dst[g] = 0xdeadbeef;
  asm volatile("fence" ::: "memory");
}

static void check(int casenum, int gather) {
  asm volatile("fence" ::: "memory");
  for (int g = 0; g < N; g++) {
    uint32_t exp = gather ? 1000 + (N - 1 - g) : 1000 + g;
    uint32_t got = gather ? dst[g] : dst[N - 1 - g];
    if (got != exp) {
      printf("[TC %d] Index %d FAILED. Got %u, expected %u.\n", casenum, g,
             got, exp);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", casenum);
}

// Unordered and ordered indexed stores (scatter)
void TEST_CASE1(void) {
  clear_dst();
  asm volatile("vsetvli zero, %[n], e32, m4, ta, ma\n"
               "vle32.v v8, (%[src])\n"
               "vle32.v v16, (%[idx])\n"
               "vsuxei32.v v8, (%[dst]), v16\n" ::[n] "r"(N),
               [src] "r"(src), [idx] "r"(idx), [dst] "r"(dst)
               : "memory");
  check(1, 0);
  clear_dst();
  asm volatile("vsetvli zero, %[n], e32, m4, ta, ma\n"
               "vle32.v v8, (%[src])\n"
               "vle32.v v16, (%[idx])\n"
               "vsoxei32.v v8, (%[dst]), v16\n" ::[n] "r"(N),
               [src] "r"(src), [idx] "r"(idx), [dst] "r"(dst)
               : "memory");
  check(2, 0);
}

// Indexed load (gather) and unit-stride store
void TEST_CASE2(void) {
  clear_dst();
  asm volatile("vsetvli zero, %[n], e32, m4, ta, ma\n"
               "vle32.v v16, (%[idx])\n"
               "vluxei32.v v8, (%[src]), v16\n"
               "vse32.v v8, (%[dst])\n" ::[n] "r"(N),
               [src] "r"(src), [idx] "r"(idx), [dst] "r"(dst)
               : "memory");
  check(3, 1);
}

// Several stores sharing one index register
void TEST_CASE3(void) {
  for (int k = 0; k < 4; k++) {
    clear_dst();
    asm volatile("vsetvli zero, %[n], e32, m4, ta, ma\n"
                 "vle32.v v8, (%[src])\n"
                 "vle32.v v16, (%[idx])\n"
                 "vsuxei32.v v8, (%[dst]), v16\n"
                 "vsuxei32.v v8, (%[dst]), v16\n" ::[n] "r"(N),
                 [src] "r"(src), [idx] "r"(idx), [dst] "r"(dst)
                 : "memory");
    check(4 + k, 0);
  }
}

int main(void) {
  if (!snrt_is_spatz_core()) return 0;
  INIT_CHECK();
  enable_vec();
  setup();

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();

  EXIT_CHECK();
}
