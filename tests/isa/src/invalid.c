// Copyright 2026 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Kai Berszin <kberszin@iis.ee.ethz.ch>
// Illegal instructions must trap; the default trap restarts the core silently.

#include "vector_macros.h"

// Return mcause in t1 and skip the trapping instruction
asm(".text\n"
    ".align 4\n"
    "invalid_trap:\n"
    "  csrr t1, mcause\n"
    "  csrr t0, mepc\n"
    "  addi t0, t0, 4\n"
    "  csrw mepc, t0\n"
    "  mret\n");

#define TRAP_CAUSE(insn, cause)                                                \
  asm volatile("la t0, invalid_trap\n"                                         \
               "csrrw %[old], mtvec, t0\n"                                     \
               "li t1, 0\n" insn "\n"                                          \
               "mv %[c], t1\n"                                                 \
               "csrw mtvec, %[old]\n"                                          \
               : [old] "=&r"(old), [c] "=&r"(cause)                            \
               :                                                               \
               : "t0", "t1", "memory")

void TEST_CASE1(void) {
  uint32_t old, cause;
  // Illegal in the core itself
  TRAP_CAUSE(".word 0x00000000", cause);
  XCMP(1, cause, 2);
  // Offloaded over XIF and rejected by Spatz (no divider)
  TRAP_CAUSE("vfdiv.vv v1, v2, v3", cause);
  XCMP(2, cause, 2);
}

int main(void) {
  if (!snrt_is_spatz_core()) return 0;
  INIT_CHECK();
  enable_vec();
  enable_fp();

  TEST_CASE1();

  EXIT_CHECK();
}
