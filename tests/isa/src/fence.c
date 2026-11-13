// Copyright 2026 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51

#include "vector_macros.h"

// A scalar load right after a vector store must see the stored data once a
// fence separates them.
void TEST_CASE1(void) {
  VSET(16, e8, m1);
  volatile uint8_t ALIGNED_I8[16];
  VLOAD_8(v1, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x11, 0x22, 0x33,
          0x44, 0x55, 0x66, 0x77, 0x88);
  asm volatile("vse8.v v1, (%0)" ::"r"(ALIGNED_I8));
  VVCMP_U8(1, ALIGNED_I8, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x11,
           0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88);
}

// Vector memory operations with vl=0 must not leave the fence waiting forever.
void TEST_CASE2(void) {
  volatile uint8_t ALIGNED_I8[16] = {0};
  VSET(16, e8, m1);
  VLOAD_8(v2, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0, 0xb0,
          0xc0, 0xd0, 0xe0, 0xf0, 0xff);
  // VSET(0, ...) would pass x0 as AVL, which selects VLMAX instead of vl=0
  asm volatile("li t0, 0\n"
               "vsetvli t1, t0, e8, m1, ta, ma\n" ::: "t0", "t1");
  asm volatile("vse8.v v2, (%0)" ::"r"(ALIGNED_I8));
  asm volatile("vle8.v v3, (%0)" ::"r"(ALIGNED_I8));
  asm volatile("fence" ::: "memory");
  VSET(16, e8, m1);
  asm volatile("vse8.v v2, (%0)" ::"r"(ALIGNED_I8));
  VVCMP_U8(2, ALIGNED_I8, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90,
           0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xf0, 0xff);
}

int main(void) {
  if (!snrt_is_spatz_core()) return 0;
  INIT_CHECK();
  enable_vec();

  TEST_CASE1();
  TEST_CASE2();

  EXIT_CHECK();
}
