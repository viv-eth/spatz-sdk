// Copyright 2026 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// vmul/vdiv/vrem/vmacc right after their loads at a small vl (e32, m1,
// vl = 4), a sequence that used to deadlock.

#include "vector_macros.h"

#define N 16

static int32_t *a, *b, *seed, *out[4];

static void setup(void) {
  a = (int32_t *)snrt_l1_alloc(N * sizeof(int32_t));
  b = (int32_t *)snrt_l1_alloc(N * sizeof(int32_t));
  seed = (int32_t *)snrt_l1_alloc(N * sizeof(int32_t));
  for (int i = 0; i < 4; i++)
    out[i] = (int32_t *)snrt_l1_alloc(N * sizeof(int32_t));
  for (int i = 0; i < N; i++) {
    a[i] = 2 + i;
    b[i] = 20 + i;
    seed[i] = 1;
  }
}

static void run(unsigned int vl) {
  for (int k = 0; k < 4; k++)
    for (int i = 0; i < N; i++) out[k][i] = -1;
  asm volatile("fence" ::: "memory");
  // As in the original test: one load-compute-store block per operation
  asm volatile("vsetvli zero, %[vl], e32, m1, ta, ma\n"
               "vle32.v v8, (%[a])\n"
               "vle32.v v12, (%[b])\n"
               "vmul.vv v16, v8, v12\n"
               "vse32.v v16, (%[o])\n" ::[vl] "r"(vl),
               [a] "r"(a), [b] "r"(b), [o] "r"(out[0])
               : "memory");
  asm volatile("vsetvli zero, %[vl], e32, m1, ta, ma\n"
               "vle32.v v8, (%[b])\n"
               "vdiv.vx v16, v8, %[s]\n"
               "vse32.v v16, (%[o])\n" ::[vl] "r"(vl),
               [b] "r"(b), [s] "r"(2), [o] "r"(out[1])
               : "memory");
  asm volatile("vsetvli zero, %[vl], e32, m1, ta, ma\n"
               "vle32.v v8, (%[b])\n"
               "vrem.vx v16, v8, %[s]\n"
               "vse32.v v16, (%[o])\n" ::[vl] "r"(vl),
               [b] "r"(b), [s] "r"(3), [o] "r"(out[2])
               : "memory");
  asm volatile("vsetvli zero, %[vl], e32, m1, ta, ma\n"
               "vle32.v v8, (%[a])\n"
               "vle32.v v12, (%[b])\n"
               "vle32.v v16, (%[seed])\n"
               "vmacc.vv v16, v8, v12\n"
               "vse32.v v16, (%[o])\n" ::[vl] "r"(vl),
               [a] "r"(a), [b] "r"(b), [seed] "r"(seed), [o] "r"(out[3])
               : "memory");
  asm volatile("fence" ::: "memory");
}

static void check(int casenum, unsigned int vl) {
  static const char *names[] = {"vmul.vv", "vdiv.vx", "vrem.vx", "vmacc.vv"};
  for (int k = 0; k < 4; k++)
    for (int i = 0; i < N; i++) {
      int32_t exp = i >= (int)vl ? -1
                    : k == 0     ? a[i] * b[i]
                    : k == 1     ? b[i] / 2
                    : k == 2     ? b[i] % 3
                                 : a[i] * b[i] + 1;
      if (out[k][i] != exp) {
        printf("[TC %d] Index %d FAILED (%s). Got %d, expected %d.\n",
               casenum, i, names[k], out[k][i], exp);
        num_failed++;
        return;
      }
    }
  printf("[TC %d] PASSED.\n", casenum);
}

void TEST_CASE1(void) {
  const unsigned int vls[] = {4, 1, 2, 3, 5, 16};
  for (int k = 0; k < 6; k++) {
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
