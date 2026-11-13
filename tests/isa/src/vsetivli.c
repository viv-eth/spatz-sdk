// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matteo Perotti <mperotti@iis.ee.ethz.ch>
//
// Konark: 32-bit variables (RV32 core), golden vlmul matching the
// instruction, expected vl checked against VLEN = 512, and uimm = 0 cases.

#include "vector_macros.h"

#define CHECK_VSET(casenum, vl_rd, vlmul, vsew, vta, vma, exp_vl)             \
  do {                                                                         \
    uint32_t vtype_csr, vl_csr;                                                \
    uint32_t golden = (vlmul) | (vsew) << 3 | (vta) << 6 | (vma) << 7;         \
    read_vtype(vtype_csr);                                                     \
    read_vl(vl_csr);                                                           \
    if (vtype_csr != golden || vl_csr != (exp_vl) || (vl_rd) != (exp_vl)) {    \
      printf("[TC %d] FAILED. vtype = %x (exp %x), vl = %d, rd = %d (exp "     \
             "%d)\n",                                                          \
             casenum, vtype_csr, golden, vl_csr, vl_rd, exp_vl);               \
      num_failed++;                                                            \
      return;                                                                  \
    }                                                                          \
    printf("[TC %d] PASSED.\n", casenum);                                      \
  } while (0)

void TEST_CASE1(void) {
  uint32_t vl;
  asm volatile("vsetivli %[VL], 16, e8, m2, ta, ma" : [VL] "=r"(vl));
  CHECK_VSET(1, vl, 1, 0, 1, 1, 16);
}

void TEST_CASE2(void) {
  uint32_t vl;
  // AVL above VLMAX (512 / 32 * 2 = 32) is not reachable with uimm, use 31
  asm volatile("vsetivli %[VL], 31, e32, m2, tu, ma" : [VL] "=r"(vl));
  CHECK_VSET(2, vl, 1, 2, 0, 1, 31);
  // uimm above VLMAX (512 / 64 = 8)
  asm volatile("vsetivli %[VL], 20, e64, m1, ta, mu" : [VL] "=r"(vl));
  CHECK_VSET(3, vl, 0, 3, 1, 0, 8);
}

// Zero AVL: unlike vsetvli with rs1 = x0, this is not VLMAX
void TEST_CASE3(void) {
  uint32_t vl;
  asm volatile("vsetivli %[VL], 0, e64, m8, tu, mu" : [VL] "=r"(vl));
  CHECK_VSET(4, vl, 3, 3, 0, 0, 0);
  // With rd = x0 too, vl is still set (not kept)
  asm volatile("vsetivli %[VL], 4, e8, m1, ta, ma" : [VL] "=r"(vl));
  asm volatile("vsetivli zero, 0, e16, m1, ta, ma");
  CHECK_VSET(5, 0, 0, 1, 1, 1, 0);
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
