// Copyright 2026 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Generated with exact golden values (round to nearest, ties to even).
// Scalar FP instructions on the Spatz core are executed by Spatz; operands
// are copied to L1, where its FP loads and stores go.

#include "vector_macros.h"

static void *l1_copy(const void *src, size_t size) {
  void *dst = snrt_l1_alloc(size);
  memcpy(dst, src, size);
  asm volatile("fence" ::: "memory");
  return dst;
}

static const uint64_t fclass_d_s0[] = {0x0, 0x8000000000000000, 0x7ff0000000000000, 0xfff0000000000000, 0x7ff8000000000000, 0x1, 0x8000000000000001, 0x3ff0000000000000, 0xbff0000000000000, 0x7fefffffffffffff, 0x3fea6a3a6513270e, 0x3f9892f9d23f0824, 0xbfa0ed909531985d, 0x4011600a099950d8, 0xbff3d9c111e20b8f, 0xbfad3ac90f21ddb6, 0x4004000000000000, 0xc00c000000000000, 0x3fe0000000000000};
static const uint32_t fclass_d_e[] = {0x10, 0x8, 0x80, 0x1, 0x200, 0x20, 0x4, 0x40, 0x2, 0x40, 0x40, 0x40, 0x2, 0x40, 0x2, 0x2, 0x40, 0x2, 0x40};
static void test_fclass_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fclass_d_s0, sizeof(fclass_d_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 19; i++) {
    uint32_t r;
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fclass.d %[r], ft0\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fclass_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fclass_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 1, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fclass_d_e[i] >> 32), (uint32_t)fclass_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 1);
}

static const uint64_t fcvt_w_d_rne_s0[] = {0x0, 0x8000000000000000, 0x7ff0000000000000, 0xfff0000000000000, 0x7ff8000000000000, 0x1, 0x8000000000000001, 0x3ff0000000000000, 0xbff0000000000000, 0x7fefffffffffffff, 0x40239263f28c105d, 0x40395e6093bd04cf, 0x3ff3898df9ebdacc, 0x3f96b4cb4a23d596, 0x3fb4ef8a92276658, 0x4270000000000000, 0xc270000000000000, 0x3fe0000000000000, 0x3ff8000000000000, 0x4004000000000000, 0x400c000000000000, 0xbfe0000000000000, 0xbff8000000000000, 0xc004000000000000, 0xc00c000000000000};
static const uint32_t fcvt_w_d_rne_e[] = {0x0, 0x0, 0x7fffffff, 0x80000000, 0x7fffffff, 0x0, 0x0, 0x1, 0xffffffff, 0x7fffffff, 0xa, 0x19, 0x1, 0x0, 0x0, 0x7fffffff, 0x80000000, 0x0, 0x2, 0x2, 0x4, 0x0, 0xfffffffe, 0xfffffffe, 0xfffffffc};
static void test_fcvt_w_d_rne(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fcvt_w_d_rne_s0, sizeof(fcvt_w_d_rne_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 25; i++) {
    uint32_t r;
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fcvt.w.d %[r], ft0, rne\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_w_d_rne_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_w_d_rne). Got 0x%08x%08x, expected 0x%08x%08x\n", 2, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_w_d_rne_e[i] >> 32), (uint32_t)fcvt_w_d_rne_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 2);
}

static const uint64_t fcvt_wu_d_rne_s0[] = {0x0, 0x8000000000000000, 0x7ff0000000000000, 0xfff0000000000000, 0x7ff8000000000000, 0x1, 0x8000000000000001, 0x3ff0000000000000, 0xbff0000000000000, 0x7fefffffffffffff, 0x40239263f28c105d, 0x40395e6093bd04cf, 0x3ff3898df9ebdacc, 0x3f96b4cb4a23d596, 0x3fb4ef8a92276658, 0x4270000000000000, 0xc270000000000000, 0x3fe0000000000000, 0x3ff8000000000000, 0x4004000000000000, 0x400c000000000000, 0xbfe0000000000000, 0xbff8000000000000, 0xc004000000000000, 0xc00c000000000000};
static const uint32_t fcvt_wu_d_rne_e[] = {0x0, 0x0, 0xffffffff, 0x0, 0xffffffff, 0x0, 0x0, 0x1, 0x0, 0xffffffff, 0xa, 0x19, 0x1, 0x0, 0x0, 0xffffffff, 0x0, 0x0, 0x2, 0x2, 0x4, 0x0, 0x0, 0x0, 0x0};
static void test_fcvt_wu_d_rne(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fcvt_wu_d_rne_s0, sizeof(fcvt_wu_d_rne_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 25; i++) {
    uint32_t r;
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fcvt.wu.d %[r], ft0, rne\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_wu_d_rne_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_wu_d_rne). Got 0x%08x%08x, expected 0x%08x%08x\n", 3, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_wu_d_rne_e[i] >> 32), (uint32_t)fcvt_wu_d_rne_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 3);
}

static const uint64_t fcvt_w_d_rtz_s0[] = {0x0, 0x8000000000000000, 0x7ff0000000000000, 0xfff0000000000000, 0x7ff8000000000000, 0x1, 0x8000000000000001, 0x3ff0000000000000, 0xbff0000000000000, 0x7fefffffffffffff, 0x40239263f28c105d, 0x40395e6093bd04cf, 0x3ff3898df9ebdacc, 0x3f96b4cb4a23d596, 0x3fb4ef8a92276658, 0x4270000000000000, 0xc270000000000000, 0x3fe0000000000000, 0x3ff8000000000000, 0x4004000000000000, 0x400c000000000000, 0xbfe0000000000000, 0xbff8000000000000, 0xc004000000000000, 0xc00c000000000000};
static const uint32_t fcvt_w_d_rtz_e[] = {0x0, 0x0, 0x7fffffff, 0x80000000, 0x7fffffff, 0x0, 0x0, 0x1, 0xffffffff, 0x7fffffff, 0x9, 0x19, 0x1, 0x0, 0x0, 0x7fffffff, 0x80000000, 0x0, 0x1, 0x2, 0x3, 0x0, 0xffffffff, 0xfffffffe, 0xfffffffd};
static void test_fcvt_w_d_rtz(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fcvt_w_d_rtz_s0, sizeof(fcvt_w_d_rtz_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 25; i++) {
    uint32_t r;
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fcvt.w.d %[r], ft0, rtz\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_w_d_rtz_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_w_d_rtz). Got 0x%08x%08x, expected 0x%08x%08x\n", 4, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_w_d_rtz_e[i] >> 32), (uint32_t)fcvt_w_d_rtz_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 4);
}

static const uint64_t fcvt_wu_d_rtz_s0[] = {0x0, 0x8000000000000000, 0x7ff0000000000000, 0xfff0000000000000, 0x7ff8000000000000, 0x1, 0x8000000000000001, 0x3ff0000000000000, 0xbff0000000000000, 0x7fefffffffffffff, 0x40239263f28c105d, 0x40395e6093bd04cf, 0x3ff3898df9ebdacc, 0x3f96b4cb4a23d596, 0x3fb4ef8a92276658, 0x4270000000000000, 0xc270000000000000, 0x3fe0000000000000, 0x3ff8000000000000, 0x4004000000000000, 0x400c000000000000, 0xbfe0000000000000, 0xbff8000000000000, 0xc004000000000000, 0xc00c000000000000};
static const uint32_t fcvt_wu_d_rtz_e[] = {0x0, 0x0, 0xffffffff, 0x0, 0xffffffff, 0x0, 0x0, 0x1, 0x0, 0xffffffff, 0x9, 0x19, 0x1, 0x0, 0x0, 0xffffffff, 0x0, 0x0, 0x1, 0x2, 0x3, 0x0, 0x0, 0x0, 0x0};
static void test_fcvt_wu_d_rtz(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fcvt_wu_d_rtz_s0, sizeof(fcvt_wu_d_rtz_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 25; i++) {
    uint32_t r;
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fcvt.wu.d %[r], ft0, rtz\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_wu_d_rtz_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_wu_d_rtz). Got 0x%08x%08x, expected 0x%08x%08x\n", 5, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_wu_d_rtz_e[i] >> 32), (uint32_t)fcvt_wu_d_rtz_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 5);
}

static const uint32_t fcvt_d_w_s0[] = {0x0, 0x1, 0xffffffff, 0x7fffffff, 0x80000000, 0x3, 0xfffffffd, 0x3e8, 0x75bcd15, 0x1000001};
static const uint64_t fcvt_d_w_e[] = {0x0, 0x3ff0000000000000, 0xbff0000000000000, 0x41dfffffffc00000, 0xc1e0000000000000, 0x4008000000000000, 0xc008000000000000, 0x408f400000000000, 0x419d6f3454000000, 0x4170000010000000};
static void test_fcvt_d_w(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_d_w_s0, sizeof(fcvt_d_w_s0));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 10; i++) {
    asm volatile("fcvt.d.w ft0, %[x0]\n"
                 "fsd ft0, 0(%[o])\n"
                 : 
                 : [x0] "r"((uint32_t)s0[i]), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fcvt_d_w_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_d_w). Got 0x%08x%08x, expected 0x%08x%08x\n", 6, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_d_w_e[i] >> 32), (uint32_t)fcvt_d_w_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 6);
}

static const uint32_t fcvt_d_wu_s0[] = {0x0, 0x1, 0xffffffff, 0x7fffffff, 0x80000000, 0x3, 0xfffffffd, 0x3e8, 0x75bcd15, 0x1000001};
static const uint64_t fcvt_d_wu_e[] = {0x0, 0x3ff0000000000000, 0x41efffffffe00000, 0x41dfffffffc00000, 0x41e0000000000000, 0x4008000000000000, 0x41efffffffa00000, 0x408f400000000000, 0x419d6f3454000000, 0x4170000010000000};
static void test_fcvt_d_wu(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_d_wu_s0, sizeof(fcvt_d_wu_s0));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 10; i++) {
    asm volatile("fcvt.d.wu ft0, %[x0]\n"
                 "fsd ft0, 0(%[o])\n"
                 : 
                 : [x0] "r"((uint32_t)s0[i]), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fcvt_d_wu_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_d_wu). Got 0x%08x%08x, expected 0x%08x%08x\n", 7, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_d_wu_e[i] >> 32), (uint32_t)fcvt_d_wu_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 7);
}

static const uint32_t fclass_s_s0[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0x408d30ed, 0x412faab9, 0x3d483d38, 0x3cbf8a82, 0xc1e37c3b, 0xbf4af3b0, 0x40200000, 0xc0600000, 0x3f000000};
static const uint32_t fclass_s_e[] = {0x10, 0x8, 0x80, 0x1, 0x200, 0x20, 0x4, 0x40, 0x2, 0x40, 0x40, 0x40, 0x40, 0x40, 0x2, 0x2, 0x40, 0x2, 0x40};
static void test_fclass_s(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fclass_s_s0, sizeof(fclass_s_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 19; i++) {
    uint32_t r;
    asm volatile("flw ft0, 0(%[s0])\n"
                 "fclass.s %[r], ft0\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fclass_s_e[i]) {
      printf("[TC %d] Index %d FAILED (fclass_s). Got 0x%08x%08x, expected 0x%08x%08x\n", 8, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fclass_s_e[i] >> 32), (uint32_t)fclass_s_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 8);
}

static const uint32_t fcvt_w_s_rne_s0[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0xc0265ec3, 0x3e5978a6, 0x428a7a39, 0xc14339a3, 0xc05d5e76, 0x53800000, 0xd3800000, 0x3f000000, 0x3fc00000, 0x40200000, 0x40600000, 0xbf000000, 0xbfc00000, 0xc0200000, 0xc0600000};
static const uint32_t fcvt_w_s_rne_e[] = {0x0, 0x0, 0x7fffffff, 0x80000000, 0x7fffffff, 0x0, 0x0, 0x1, 0xffffffff, 0x7fffffff, 0xfffffffd, 0x0, 0x45, 0xfffffff4, 0xfffffffd, 0x7fffffff, 0x80000000, 0x0, 0x2, 0x2, 0x4, 0x0, 0xfffffffe, 0xfffffffe, 0xfffffffc};
static void test_fcvt_w_s_rne(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_w_s_rne_s0, sizeof(fcvt_w_s_rne_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 25; i++) {
    uint32_t r;
    asm volatile("flw ft0, 0(%[s0])\n"
                 "fcvt.w.s %[r], ft0, rne\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_w_s_rne_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_w_s_rne). Got 0x%08x%08x, expected 0x%08x%08x\n", 9, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_w_s_rne_e[i] >> 32), (uint32_t)fcvt_w_s_rne_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 9);
}

static const uint32_t fcvt_wu_s_rne_s0[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0xc0265ec3, 0x3e5978a6, 0x428a7a39, 0xc14339a3, 0xc05d5e76, 0x53800000, 0xd3800000, 0x3f000000, 0x3fc00000, 0x40200000, 0x40600000, 0xbf000000, 0xbfc00000, 0xc0200000, 0xc0600000};
static const uint32_t fcvt_wu_s_rne_e[] = {0x0, 0x0, 0xffffffff, 0x0, 0xffffffff, 0x0, 0x0, 0x1, 0x0, 0xffffffff, 0x0, 0x0, 0x45, 0x0, 0x0, 0xffffffff, 0x0, 0x0, 0x2, 0x2, 0x4, 0x0, 0x0, 0x0, 0x0};
static void test_fcvt_wu_s_rne(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_wu_s_rne_s0, sizeof(fcvt_wu_s_rne_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 25; i++) {
    uint32_t r;
    asm volatile("flw ft0, 0(%[s0])\n"
                 "fcvt.wu.s %[r], ft0, rne\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_wu_s_rne_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_wu_s_rne). Got 0x%08x%08x, expected 0x%08x%08x\n", 10, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_wu_s_rne_e[i] >> 32), (uint32_t)fcvt_wu_s_rne_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 10);
}

static const uint32_t fcvt_w_s_rtz_s0[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0xc0265ec3, 0x3e5978a6, 0x428a7a39, 0xc14339a3, 0xc05d5e76, 0x53800000, 0xd3800000, 0x3f000000, 0x3fc00000, 0x40200000, 0x40600000, 0xbf000000, 0xbfc00000, 0xc0200000, 0xc0600000};
static const uint32_t fcvt_w_s_rtz_e[] = {0x0, 0x0, 0x7fffffff, 0x80000000, 0x7fffffff, 0x0, 0x0, 0x1, 0xffffffff, 0x7fffffff, 0xfffffffe, 0x0, 0x45, 0xfffffff4, 0xfffffffd, 0x7fffffff, 0x80000000, 0x0, 0x1, 0x2, 0x3, 0x0, 0xffffffff, 0xfffffffe, 0xfffffffd};
static void test_fcvt_w_s_rtz(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_w_s_rtz_s0, sizeof(fcvt_w_s_rtz_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 25; i++) {
    uint32_t r;
    asm volatile("flw ft0, 0(%[s0])\n"
                 "fcvt.w.s %[r], ft0, rtz\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_w_s_rtz_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_w_s_rtz). Got 0x%08x%08x, expected 0x%08x%08x\n", 11, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_w_s_rtz_e[i] >> 32), (uint32_t)fcvt_w_s_rtz_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 11);
}

static const uint32_t fcvt_wu_s_rtz_s0[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0xc0265ec3, 0x3e5978a6, 0x428a7a39, 0xc14339a3, 0xc05d5e76, 0x53800000, 0xd3800000, 0x3f000000, 0x3fc00000, 0x40200000, 0x40600000, 0xbf000000, 0xbfc00000, 0xc0200000, 0xc0600000};
static const uint32_t fcvt_wu_s_rtz_e[] = {0x0, 0x0, 0xffffffff, 0x0, 0xffffffff, 0x0, 0x0, 0x1, 0x0, 0xffffffff, 0x0, 0x0, 0x45, 0x0, 0x0, 0xffffffff, 0x0, 0x0, 0x1, 0x2, 0x3, 0x0, 0x0, 0x0, 0x0};
static void test_fcvt_wu_s_rtz(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_wu_s_rtz_s0, sizeof(fcvt_wu_s_rtz_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 25; i++) {
    uint32_t r;
    asm volatile("flw ft0, 0(%[s0])\n"
                 "fcvt.wu.s %[r], ft0, rtz\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_wu_s_rtz_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_wu_s_rtz). Got 0x%08x%08x, expected 0x%08x%08x\n", 12, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_wu_s_rtz_e[i] >> 32), (uint32_t)fcvt_wu_s_rtz_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 12);
}

static const uint32_t fcvt_s_w_s0[] = {0x0, 0x1, 0xffffffff, 0x7fffffff, 0x80000000, 0x3, 0xfffffffd, 0x3e8, 0x75bcd15, 0x1000001};
static const uint32_t fcvt_s_w_e[] = {0x0, 0x3f800000, 0xbf800000, 0x4f000000, 0xcf000000, 0x40400000, 0xc0400000, 0x447a0000, 0x4ceb79a3, 0x4b800000};
static void test_fcvt_s_w(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_s_w_s0, sizeof(fcvt_s_w_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 10; i++) {
    asm volatile("fcvt.s.w ft0, %[x0], rne\n"
                 "fsw ft0, 0(%[o])\n"
                 : 
                 : [x0] "r"((uint32_t)s0[i]), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint32_t got = *o;
    if (got != fcvt_s_w_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_s_w). Got 0x%08x%08x, expected 0x%08x%08x\n", 13, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_s_w_e[i] >> 32), (uint32_t)fcvt_s_w_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 13);
}

static const uint32_t fcvt_s_wu_s0[] = {0x0, 0x1, 0xffffffff, 0x7fffffff, 0x80000000, 0x3, 0xfffffffd, 0x3e8, 0x75bcd15, 0x1000001};
static const uint32_t fcvt_s_wu_e[] = {0x0, 0x3f800000, 0x4f800000, 0x4f000000, 0x4f000000, 0x40400000, 0x4f800000, 0x447a0000, 0x4ceb79a3, 0x4b800000};
static void test_fcvt_s_wu(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_s_wu_s0, sizeof(fcvt_s_wu_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 10; i++) {
    asm volatile("fcvt.s.wu ft0, %[x0], rne\n"
                 "fsw ft0, 0(%[o])\n"
                 : 
                 : [x0] "r"((uint32_t)s0[i]), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint32_t got = *o;
    if (got != fcvt_s_wu_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_s_wu). Got 0x%08x%08x, expected 0x%08x%08x\n", 14, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_s_wu_e[i] >> 32), (uint32_t)fcvt_s_wu_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 14);
}

static const uint16_t fclass_h_s0[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x1, 0x8001, 0x3c00, 0xbc00, 0x7bff, 0xc26f, 0x2a0c, 0x3f07, 0x3bbb, 0xc028, 0x4f0e, 0x4100, 0xc300, 0x3800};
static const uint32_t fclass_h_e[] = {0x10, 0x8, 0x80, 0x1, 0x200, 0x20, 0x4, 0x40, 0x2, 0x40, 0x2, 0x40, 0x40, 0x40, 0x2, 0x40, 0x40, 0x2, 0x40};
static void test_fclass_h(void) {
  const uint16_t *s0 = (uint16_t *)l1_copy(fclass_h_s0, sizeof(fclass_h_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 19; i++) {
    uint32_t r;
    asm volatile("flh ft0, 0(%[s0])\n"
                 "fclass.h %[r], ft0\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fclass_h_e[i]) {
      printf("[TC %d] Index %d FAILED (fclass_h). Got 0x%08x%08x, expected 0x%08x%08x\n", 15, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fclass_h_e[i] >> 32), (uint32_t)fclass_h_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 15);
}

static const uint16_t fcvt_w_h_rne_s0[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x1, 0x8001, 0x3c00, 0xbc00, 0x7bff, 0xc55c, 0xd260, 0xc046, 0xa9e5, 0x503e, 0x3800, 0x3e00, 0x4100, 0x4300, 0xb800, 0xbe00, 0xc100, 0xc300};
static const uint32_t fcvt_w_h_rne_e[] = {0x0, 0x0, 0x7fffffff, 0x80000000, 0x7fffffff, 0x0, 0x0, 0x1, 0xffffffff, 0xffe0, 0xfffffffb, 0xffffffcd, 0xfffffffe, 0x0, 0x22, 0x0, 0x2, 0x2, 0x4, 0x0, 0xfffffffe, 0xfffffffe, 0xfffffffc};
static void test_fcvt_w_h_rne(void) {
  const uint16_t *s0 = (uint16_t *)l1_copy(fcvt_w_h_rne_s0, sizeof(fcvt_w_h_rne_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 23; i++) {
    uint32_t r;
    asm volatile("flh ft0, 0(%[s0])\n"
                 "fcvt.w.h %[r], ft0, rne\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_w_h_rne_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_w_h_rne). Got 0x%08x%08x, expected 0x%08x%08x\n", 16, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_w_h_rne_e[i] >> 32), (uint32_t)fcvt_w_h_rne_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 16);
}

static const uint16_t fcvt_wu_h_rne_s0[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x1, 0x8001, 0x3c00, 0xbc00, 0x7bff, 0xc55c, 0xd260, 0xc046, 0xa9e5, 0x503e, 0x3800, 0x3e00, 0x4100, 0x4300, 0xb800, 0xbe00, 0xc100, 0xc300};
static const uint32_t fcvt_wu_h_rne_e[] = {0x0, 0x0, 0xffffffff, 0x0, 0xffffffff, 0x0, 0x0, 0x1, 0x0, 0xffe0, 0x0, 0x0, 0x0, 0x0, 0x22, 0x0, 0x2, 0x2, 0x4, 0x0, 0x0, 0x0, 0x0};
static void test_fcvt_wu_h_rne(void) {
  const uint16_t *s0 = (uint16_t *)l1_copy(fcvt_wu_h_rne_s0, sizeof(fcvt_wu_h_rne_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 23; i++) {
    uint32_t r;
    asm volatile("flh ft0, 0(%[s0])\n"
                 "fcvt.wu.h %[r], ft0, rne\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_wu_h_rne_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_wu_h_rne). Got 0x%08x%08x, expected 0x%08x%08x\n", 17, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_wu_h_rne_e[i] >> 32), (uint32_t)fcvt_wu_h_rne_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 17);
}

static const uint16_t fcvt_w_h_rtz_s0[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x1, 0x8001, 0x3c00, 0xbc00, 0x7bff, 0xc55c, 0xd260, 0xc046, 0xa9e5, 0x503e, 0x3800, 0x3e00, 0x4100, 0x4300, 0xb800, 0xbe00, 0xc100, 0xc300};
static const uint32_t fcvt_w_h_rtz_e[] = {0x0, 0x0, 0x7fffffff, 0x80000000, 0x7fffffff, 0x0, 0x0, 0x1, 0xffffffff, 0xffe0, 0xfffffffb, 0xffffffcd, 0xfffffffe, 0x0, 0x21, 0x0, 0x1, 0x2, 0x3, 0x0, 0xffffffff, 0xfffffffe, 0xfffffffd};
static void test_fcvt_w_h_rtz(void) {
  const uint16_t *s0 = (uint16_t *)l1_copy(fcvt_w_h_rtz_s0, sizeof(fcvt_w_h_rtz_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 23; i++) {
    uint32_t r;
    asm volatile("flh ft0, 0(%[s0])\n"
                 "fcvt.w.h %[r], ft0, rtz\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_w_h_rtz_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_w_h_rtz). Got 0x%08x%08x, expected 0x%08x%08x\n", 18, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_w_h_rtz_e[i] >> 32), (uint32_t)fcvt_w_h_rtz_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 18);
}

static const uint16_t fcvt_wu_h_rtz_s0[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x1, 0x8001, 0x3c00, 0xbc00, 0x7bff, 0xc55c, 0xd260, 0xc046, 0xa9e5, 0x503e, 0x3800, 0x3e00, 0x4100, 0x4300, 0xb800, 0xbe00, 0xc100, 0xc300};
static const uint32_t fcvt_wu_h_rtz_e[] = {0x0, 0x0, 0xffffffff, 0x0, 0xffffffff, 0x0, 0x0, 0x1, 0x0, 0xffe0, 0x0, 0x0, 0x0, 0x0, 0x21, 0x0, 0x1, 0x2, 0x3, 0x0, 0x0, 0x0, 0x0};
static void test_fcvt_wu_h_rtz(void) {
  const uint16_t *s0 = (uint16_t *)l1_copy(fcvt_wu_h_rtz_s0, sizeof(fcvt_wu_h_rtz_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 23; i++) {
    uint32_t r;
    asm volatile("flh ft0, 0(%[s0])\n"
                 "fcvt.wu.h %[r], ft0, rtz\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_wu_h_rtz_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_wu_h_rtz). Got 0x%08x%08x, expected 0x%08x%08x\n", 19, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_wu_h_rtz_e[i] >> 32), (uint32_t)fcvt_wu_h_rtz_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 19);
}

static const uint32_t fcvt_h_w_s0[] = {0x0, 0x1, 0xffffffff, 0x7fffffff, 0x80000000, 0x3, 0xfffffffd, 0x3e8, 0x75bcd15, 0x1000001};
static const uint16_t fcvt_h_w_e[] = {0x0, 0x3c00, 0xbc00, 0x7c00, 0xfc00, 0x4200, 0xc200, 0x63d0, 0x7c00, 0x7c00};
static void test_fcvt_h_w(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_h_w_s0, sizeof(fcvt_h_w_s0));
  uint16_t *o = (uint16_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 10; i++) {
    asm volatile("fcvt.h.w ft0, %[x0], rne\n"
                 "fsh ft0, 0(%[o])\n"
                 : 
                 : [x0] "r"((uint32_t)s0[i]), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint16_t got = *o;
    if (got != fcvt_h_w_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_h_w). Got 0x%08x%08x, expected 0x%08x%08x\n", 20, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_h_w_e[i] >> 32), (uint32_t)fcvt_h_w_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 20);
}

static const uint32_t fcvt_h_wu_s0[] = {0x0, 0x1, 0xffffffff, 0x7fffffff, 0x80000000, 0x3, 0xfffffffd, 0x3e8, 0x75bcd15, 0x1000001};
static const uint16_t fcvt_h_wu_e[] = {0x0, 0x3c00, 0x7c00, 0x7c00, 0x7c00, 0x4200, 0x7c00, 0x63d0, 0x7c00, 0x7c00};
static void test_fcvt_h_wu(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_h_wu_s0, sizeof(fcvt_h_wu_s0));
  uint16_t *o = (uint16_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 10; i++) {
    asm volatile("fcvt.h.wu ft0, %[x0], rne\n"
                 "fsh ft0, 0(%[o])\n"
                 : 
                 : [x0] "r"((uint32_t)s0[i]), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint16_t got = *o;
    if (got != fcvt_h_wu_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_h_wu). Got 0x%08x%08x, expected 0x%08x%08x\n", 21, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_h_wu_e[i] >> 32), (uint32_t)fcvt_h_wu_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 21);
}

static const uint8_t fclass_b_s0[] = {0x0, 0x80, 0x7c, 0xfc, 0x7e, 0x1, 0x81, 0x3c, 0xbc, 0x7b, 0xd2, 0xc9, 0xd3, 0xcc, 0xc0, 0x49, 0x41, 0xc3, 0x38};
static const uint32_t fclass_b_e[] = {0x10, 0x8, 0x80, 0x1, 0x200, 0x20, 0x4, 0x40, 0x2, 0x40, 0x2, 0x2, 0x2, 0x2, 0x2, 0x40, 0x40, 0x2, 0x40};
static void test_fclass_b(void) {
  const uint8_t *s0 = (uint8_t *)l1_copy(fclass_b_s0, sizeof(fclass_b_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 19; i++) {
    uint32_t r;
    asm volatile("flb ft0, 0(%[s0])\n"
                 "fclass.b %[r], ft0\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fclass_b_e[i]) {
      printf("[TC %d] Index %d FAILED (fclass_b). Got 0x%08x%08x, expected 0x%08x%08x\n", 22, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fclass_b_e[i] >> 32), (uint32_t)fclass_b_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 22);
}

static const uint8_t fcvt_w_b_rne_s0[] = {0x0, 0x80, 0x7c, 0xfc, 0x7e, 0x1, 0x81, 0x3c, 0xbc, 0x7b, 0x27, 0x36, 0xb1, 0x40, 0xc2, 0x38, 0x3e, 0x41, 0x43, 0xb8, 0xbe, 0xc1, 0xc3};
static const uint32_t fcvt_w_b_rne_e[] = {0x0, 0x0, 0x7fffffff, 0x80000000, 0x7fffffff, 0x0, 0x0, 0x1, 0xffffffff, 0xe000, 0x0, 0x0, 0x0, 0x2, 0xfffffffd, 0x0, 0x2, 0x2, 0x4, 0x0, 0xfffffffe, 0xfffffffe, 0xfffffffc};
static void test_fcvt_w_b_rne(void) {
  const uint8_t *s0 = (uint8_t *)l1_copy(fcvt_w_b_rne_s0, sizeof(fcvt_w_b_rne_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 23; i++) {
    uint32_t r;
    asm volatile("flb ft0, 0(%[s0])\n"
                 "fcvt.w.b %[r], ft0\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_w_b_rne_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_w_b_rne). Got 0x%08x%08x, expected 0x%08x%08x\n", 23, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_w_b_rne_e[i] >> 32), (uint32_t)fcvt_w_b_rne_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 23);
}

static const uint8_t fcvt_wu_b_rne_s0[] = {0x0, 0x80, 0x7c, 0xfc, 0x7e, 0x1, 0x81, 0x3c, 0xbc, 0x7b, 0x27, 0x36, 0xb1, 0x40, 0xc2, 0x38, 0x3e, 0x41, 0x43, 0xb8, 0xbe, 0xc1, 0xc3};
static const uint32_t fcvt_wu_b_rne_e[] = {0x0, 0x0, 0xffffffff, 0x0, 0xffffffff, 0x0, 0x0, 0x1, 0x0, 0xe000, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x2, 0x2, 0x4, 0x0, 0x0, 0x0, 0x0};
static void test_fcvt_wu_b_rne(void) {
  const uint8_t *s0 = (uint8_t *)l1_copy(fcvt_wu_b_rne_s0, sizeof(fcvt_wu_b_rne_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 23; i++) {
    uint32_t r;
    asm volatile("flb ft0, 0(%[s0])\n"
                 "fcvt.wu.b %[r], ft0\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fcvt_wu_b_rne_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_wu_b_rne). Got 0x%08x%08x, expected 0x%08x%08x\n", 24, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_wu_b_rne_e[i] >> 32), (uint32_t)fcvt_wu_b_rne_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 24);
}

static const uint32_t fcvt_b_w_s0[] = {0x0, 0x1, 0xffffffff, 0x7fffffff, 0x80000000, 0x3, 0xfffffffd, 0x3e8, 0x75bcd15, 0x1000001};
static const uint8_t fcvt_b_w_e[] = {0x0, 0x3c, 0xbc, 0x7c, 0xfc, 0x42, 0xc2, 0x64, 0x7c, 0x7c};
static void test_fcvt_b_w(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_b_w_s0, sizeof(fcvt_b_w_s0));
  uint8_t *o = (uint8_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 10; i++) {
    asm volatile("fcvt.b.w ft0, %[x0]\n"
                 "fsb ft0, 0(%[o])\n"
                 : 
                 : [x0] "r"((uint32_t)s0[i]), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint8_t got = *o;
    if (got != fcvt_b_w_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_b_w). Got 0x%08x%08x, expected 0x%08x%08x\n", 25, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_b_w_e[i] >> 32), (uint32_t)fcvt_b_w_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 25);
}

static const uint32_t fcvt_b_wu_s0[] = {0x0, 0x1, 0xffffffff, 0x7fffffff, 0x80000000, 0x3, 0xfffffffd, 0x3e8, 0x75bcd15, 0x1000001};
static const uint8_t fcvt_b_wu_e[] = {0x0, 0x3c, 0x7c, 0x7c, 0x7c, 0x42, 0x7c, 0x64, 0x7c, 0x7c};
static void test_fcvt_b_wu(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_b_wu_s0, sizeof(fcvt_b_wu_s0));
  uint8_t *o = (uint8_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 10; i++) {
    asm volatile("fcvt.b.wu ft0, %[x0]\n"
                 "fsb ft0, 0(%[o])\n"
                 : 
                 : [x0] "r"((uint32_t)s0[i]), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint8_t got = *o;
    if (got != fcvt_b_wu_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_b_wu). Got 0x%08x%08x, expected 0x%08x%08x\n", 26, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_b_wu_e[i] >> 32), (uint32_t)fcvt_b_wu_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 26);
}

static const uint32_t fcvt_d_s_s0[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0x3ee8de29, 0xbfda6b35, 0xbfd76378, 0x3f935160, 0x3d135dbe, 0x3e018b48, 0x4021a1ae, 0x3e92a586};
static const uint64_t fcvt_d_s_e[] = {0x0, 0x8000000000000000, 0x7ff0000000000000, 0xfff0000000000000, 0x7ff8000000000000, 0x36a0000000000000, 0xb6a0000000000000, 0x3ff0000000000000, 0xbff0000000000000, 0x47efffffe0000000, 0x3fdd1bc520000000, 0xbffb4d66a0000000, 0xbffaec6f00000000, 0x3ff26a2c00000000, 0x3fa26bb7c0000000, 0x3fc0316900000000, 0x40043435c0000000, 0x3fd254b0c0000000};
static void test_fcvt_d_s(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_d_s_s0, sizeof(fcvt_d_s_s0));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 18; i++) {
    asm volatile("flw ft0, 0(%[s0])\n"
                 "fcvt.d.s ft1, ft0\n"
                 "fsd ft1, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fcvt_d_s_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_d_s). Got 0x%08x%08x, expected 0x%08x%08x\n", 27, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_d_s_e[i] >> 32), (uint32_t)fcvt_d_s_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 27);
}

static const uint64_t fcvt_s_d_s0[] = {0x0, 0x8000000000000000, 0x7ff0000000000000, 0xfff0000000000000, 0x7ff8000000000000, 0x1, 0x8000000000000001, 0x3ff0000000000000, 0xbff0000000000000, 0x7fefffffffffffff, 0xbff90fbb9c1caaf7, 0x3fedbf4ab0c4312d, 0x401e647c74e69a5d, 0xc056623765e7e423, 0x3ffa260c7b45145c, 0x3ff113db30cbc97d, 0xbfc1c244298cb3a5, 0x3fe000f41a358ca0};
static const uint32_t fcvt_s_d_e[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x0, 0x80000000, 0x3f800000, 0xbf800000, 0x7f800000, 0xbfc87ddd, 0x3f6dfa56, 0x40f323e4, 0xc2b311bb, 0x3fd13064, 0x3f889eda, 0xbe0e1221, 0x3f0007a1};
static void test_fcvt_s_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fcvt_s_d_s0, sizeof(fcvt_s_d_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 18; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fcvt.s.d ft1, ft0, rne\n"
                 "fsw ft1, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint32_t got = *o;
    if (got != fcvt_s_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_s_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 28, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_s_d_e[i] >> 32), (uint32_t)fcvt_s_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 28);
}

static const uint16_t fcvt_s_h_s0[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x1, 0x8001, 0x3c00, 0xbc00, 0x7bff, 0x4a25, 0xaa74, 0x277f, 0xb098, 0xcfd2, 0xb9e5, 0x2b65, 0xc1eb};
static const uint32_t fcvt_s_h_e[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x33800000, 0xb3800000, 0x3f800000, 0xbf800000, 0x477fe000, 0x4144a000, 0xbd4e8000, 0x3cefe000, 0xbe130000, 0xc1fa4000, 0xbf3ca000, 0x3d6ca000, 0xc03d6000};
static void test_fcvt_s_h(void) {
  const uint16_t *s0 = (uint16_t *)l1_copy(fcvt_s_h_s0, sizeof(fcvt_s_h_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 18; i++) {
    asm volatile("flh ft0, 0(%[s0])\n"
                 "fcvt.s.h ft1, ft0\n"
                 "fsw ft1, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint32_t got = *o;
    if (got != fcvt_s_h_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_s_h). Got 0x%08x%08x, expected 0x%08x%08x\n", 29, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_s_h_e[i] >> 32), (uint32_t)fcvt_s_h_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 29);
}

static const uint32_t fcvt_h_s_s0[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0xc00afe44, 0x3ddff550, 0xbf3d437b, 0x4242173f, 0x3cf9b9e5, 0xc092c3df, 0x42610ad4, 0xc0fd3f87};
static const uint16_t fcvt_h_s_e[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x0, 0x8000, 0x3c00, 0xbc00, 0x7c00, 0xc058, 0x2f00, 0xb9ea, 0x5211, 0x27ce, 0xc496, 0x5308, 0xc7ea};
static void test_fcvt_h_s(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fcvt_h_s_s0, sizeof(fcvt_h_s_s0));
  uint16_t *o = (uint16_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 18; i++) {
    asm volatile("flw ft0, 0(%[s0])\n"
                 "fcvt.h.s ft1, ft0, rne\n"
                 "fsh ft1, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint16_t got = *o;
    if (got != fcvt_h_s_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_h_s). Got 0x%08x%08x, expected 0x%08x%08x\n", 30, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_h_s_e[i] >> 32), (uint32_t)fcvt_h_s_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 30);
}

static const uint8_t fcvt_h_b_s0[] = {0x0, 0x80, 0x7c, 0xfc, 0x7e, 0x1, 0x81, 0x3c, 0xbc, 0x7b, 0x4e, 0xb7, 0xaf, 0xb2, 0x33, 0xb2, 0x54, 0xc5};
static const uint16_t fcvt_h_b_e[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x100, 0x8100, 0x3c00, 0xbc00, 0x7b00, 0x4e00, 0xb700, 0xaf00, 0xb200, 0x3300, 0xb200, 0x5400, 0xc500};
static void test_fcvt_h_b(void) {
  const uint8_t *s0 = (uint8_t *)l1_copy(fcvt_h_b_s0, sizeof(fcvt_h_b_s0));
  uint16_t *o = (uint16_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 18; i++) {
    asm volatile("flb ft0, 0(%[s0])\n"
                 "fcvt.h.b ft1, ft0\n"
                 "fsh ft1, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint16_t got = *o;
    if (got != fcvt_h_b_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_h_b). Got 0x%08x%08x, expected 0x%08x%08x\n", 31, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_h_b_e[i] >> 32), (uint32_t)fcvt_h_b_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 31);
}

static const uint16_t fcvt_b_h_s0[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x1, 0x8001, 0x3c00, 0xbc00, 0x7bff, 0x53f5, 0xa5e3, 0x36c5, 0xc9c9, 0xd7d1, 0x38e1, 0x29e1, 0xb0d1};
static const uint8_t fcvt_b_h_e[] = {0x0, 0x80, 0x7c, 0xfc, 0x7e, 0x0, 0x80, 0x3c, 0xbc, 0x7c, 0x54, 0xa6, 0x37, 0xca, 0xd8, 0x39, 0x2a, 0xb1};
static void test_fcvt_b_h(void) {
  const uint16_t *s0 = (uint16_t *)l1_copy(fcvt_b_h_s0, sizeof(fcvt_b_h_s0));
  uint8_t *o = (uint8_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 18; i++) {
    asm volatile("flh ft0, 0(%[s0])\n"
                 "fcvt.b.h ft1, ft0\n"
                 "fsb ft1, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint8_t got = *o;
    if (got != fcvt_b_h_e[i]) {
      printf("[TC %d] Index %d FAILED (fcvt_b_h). Got 0x%08x%08x, expected 0x%08x%08x\n", 32, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fcvt_b_h_e[i] >> 32), (uint32_t)fcvt_b_h_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 32);
}

int main(void) {
  if (!snrt_is_spatz_core()) return 0;
  INIT_CHECK();
  enable_vec();
  enable_fp();
  asm volatile("fsrmi 0");  // round to nearest, ties to even

  test_fclass_d();
  test_fcvt_w_d_rne();
  test_fcvt_wu_d_rne();
  test_fcvt_w_d_rtz();
  test_fcvt_wu_d_rtz();
  test_fcvt_d_w();
  test_fcvt_d_wu();
  test_fclass_s();
  test_fcvt_w_s_rne();
  test_fcvt_wu_s_rne();
  test_fcvt_w_s_rtz();
  test_fcvt_wu_s_rtz();
  test_fcvt_s_w();
  test_fcvt_s_wu();
  test_fclass_h();
  test_fcvt_w_h_rne();
  test_fcvt_wu_h_rne();
  test_fcvt_w_h_rtz();
  test_fcvt_wu_h_rtz();
  test_fcvt_h_w();
  test_fcvt_h_wu();
  test_fclass_b();
  test_fcvt_w_b_rne();
  test_fcvt_wu_b_rne();
  test_fcvt_b_w();
  test_fcvt_b_wu();
  test_fcvt_d_s();
  test_fcvt_s_d();
  test_fcvt_s_h();
  test_fcvt_h_s();
  test_fcvt_h_b();
  test_fcvt_b_h();

  EXIT_CHECK();
}
