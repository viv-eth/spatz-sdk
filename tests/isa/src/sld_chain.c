// Copyright 2026 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Back-to-back move/merge/slide instructions, which used to degrade one after
// the other (partial writes, no writes, then illegal-instruction traps).

#include "vector_macros.h"

#define N 16

static uint32_t *src, *out[7];

static void setup(void) {
  src = (uint32_t *)snrt_l1_alloc(N * sizeof(uint32_t));
  for (int i = 0; i < 7; i++)
    out[i] = (uint32_t *)snrt_l1_alloc(N * sizeof(uint32_t));
  for (int i = 0; i < N; i++) src[i] = i + 1;
}

static void run(unsigned int vl) {
  for (int i = 0; i < 7; i++)
    for (int j = 0; j < N; j++) out[i][j] = 0xdeadbeef;
  asm volatile("fence" ::: "memory");
  // One block, so nothing else runs between the slide-unit instructions;
  // v0 = 0x5555 selects the vmerge scalar on even elements.
  asm volatile("vsetvli zero, %[n], e32, m1, ta, ma\n"
               "vle32.v v8, (%[src])\n"
               "li t0, 0x5555\n"
               "vmv.s.x v0, t0\n"
               "vsetvli zero, %[vl], e32, m1, tu, mu\n"
               "vmv.v.v v16, v8\n"
               "vmv.v.x v17, %[x]\n"
               "vmv.v.i v18, -7\n"
               "vmerge.vxm v19, v8, %[x], v0\n"
               "vmv.v.v v20, v8\n"
               "vsetvli zero, %[vl], e32, m1, tu, mu\n"
               "vmv.s.x v20, %[x]\n"
               "vslide1up.vx v21, v8, %[x]\n"
               "vslide1down.vx v22, v8, %[x]\n"
               "vse32.v v16, (%[o0])\n"
               "vse32.v v17, (%[o1])\n"
               "vse32.v v18, (%[o2])\n"
               "vse32.v v19, (%[o3])\n"
               "vse32.v v20, (%[o4])\n"
               "vse32.v v21, (%[o5])\n"
               "vse32.v v22, (%[o6])\n" ::[n] "r"(N),
               [vl] "r"(vl), [src] "r"(src), [x] "r"(0x11223344),
               [o0] "r"(out[0]), [o1] "r"(out[1]), [o2] "r"(out[2]),
               [o3] "r"(out[3]), [o4] "r"(out[4]), [o5] "r"(out[5]),
               [o6] "r"(out[6])
               : "t0", "memory");
  asm volatile("fence" ::: "memory");
}

static uint32_t expected(int op, int i, unsigned int vl) {
  const uint32_t x = 0x11223344;
  if (i >= (int)vl) return 0xdeadbeef; // not stored
  switch (op) {
  case 0: return src[i];                             // vmv.v.v
  case 1: return x;                                  // vmv.v.x
  case 2: return (uint32_t)-7;                       // vmv.v.i
  case 3: return (i % 2 == 0) ? x : src[i];          // vmerge.vxm
  case 4: return i == 0 ? x : src[i];                // vmv.s.x
  case 5: return i == 0 ? x : src[i - 1];            // vslide1up.vx
  default: return i == (int)vl - 1 ? x : src[i + 1]; // vslide1down.vx
  }
}

static void check(int casenum, unsigned int vl) {
  static const char *names[] = {"vmv.v.v",   "vmv.v.x", "vmv.v.i",
                                "vmerge.vxm", "vmv.s.x", "vslide1up.vx",
                                "vslide1down.vx"};
  for (int op = 0; op < 7; op++)
    for (int i = 0; i < N; i++)
      if (out[op][i] != expected(op, i, vl)) {
        printf("[TC %d] Index %d FAILED (%s). Got 0x%08x, expected 0x%08x.\n",
               casenum, i, names[op], out[op][i], expected(op, i, vl));
        num_failed++;
        return;
      }
  printf("[TC %d] PASSED.\n", casenum);
}

void TEST_CASE1(void) {
  const unsigned int vls[] = {16, 4, 16, 1, 7};
  for (int k = 0; k < 5; k++) {
    run(vls[k]);
    check(1 + k, vls[k]);
  }
}

int main(void) {
  if (!snrt_is_spatz_core()) return 0;
  INIT_CHECK();
  enable_vec();
  setup();

  TEST_CASE1();

  EXIT_CHECK();
}
