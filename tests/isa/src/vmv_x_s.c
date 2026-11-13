// Copyright 2026 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// vmv.x.s: element 0 is sign-extended to XLEN (32 bits on this core), or
// truncated to XLEN when SEW > XLEN.

#include "vector_macros.h"

void TEST_CASE1(void) {
  uint32_t x;

  VSET(16, e8, m1);
  VLOAD_8(v8, 0x85, 0x01, 0x02, 0x03);
  asm volatile("vmv.x.s %[x], v8" : [x] "=r"(x));
  XCMP(1, x, 0xffffff85);

  VSET(16, e16, m1);
  VLOAD_16(v8, 0x7123, 0x8001, 0x0002, 0x0003);
  asm volatile("vmv.x.s %[x], v8" : [x] "=r"(x));
  XCMP(2, x, 0x00007123);

  VSET(16, e32, m1);
  VLOAD_32(v8, 0x80000001, 0x00000002, 0x00000003, 0x00000004);
  asm volatile("vmv.x.s %[x], v8" : [x] "=r"(x));
  XCMP(3, x, 0x80000001);

#if ELEN == 64
  VSET(8, e64, m1);
  VLOAD_64(v8, 0x1234567887654321, 0x0000000000000002);
  asm volatile("vmv.x.s %[x], v8" : [x] "=r"(x));
  XCMP(4, x, 0x87654321);
#endif
}

// The scalar result is used by the very next instructions
void TEST_CASE2(void) {
  uint32_t x, y;

  VSET(16, e32, m4);
  VLOAD_32(v8, 0x00000010, 0x00000020);
  VLOAD_32(v12, 0x00000100, 0x00000200);
  asm volatile("vmv.x.s %[x], v8\n"
               "addi %[x], %[x], 1\n"
               "vmv.x.s %[y], v12\n"
               "add %[y], %[y], %[x]\n"
               : [x] "=&r"(x), [y] "=&r"(y));
  XCMP(5, x, 0x11);
  XCMP(6, y, 0x111);
}

// vmv.x.s ignores vl and also executes with vl = 0
void TEST_CASE3(void) {
  uint32_t x;

  VSET(16, e32, m1);
  VLOAD_32(v8, 0x0000abcd, 0x00000002);
  // AVL in a register: x0 as AVL would select VLMAX
  asm volatile("li t0, 0\n"
               "vsetvli t1, t0, e32, m1, ta, ma\n"
               "vmv.x.s %[x], v8\n"
               : [x] "=r"(x)
               :
               : "t0", "t1");
  XCMP(7, x, 0xabcd);
}

int main(void) {
  if (!snrt_is_spatz_core()) return 0;
  INIT_CHECK();
  enable_vec();

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();

  EXIT_CHECK();
}
