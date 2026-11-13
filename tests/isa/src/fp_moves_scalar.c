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

static const uint32_t fmv_x_s_s0[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0x3e2f5ab0, 0xc150179a, 0x414d8449, 0xbca13283};
static const uint32_t fmv_x_s_e[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0x3e2f5ab0, 0xc150179a, 0x414d8449, 0xbca13283};
static void test_fmv_x_s(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fmv_x_s_s0, sizeof(fmv_x_s_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    uint32_t r;
    asm volatile("flw ft0, 0(%[s0])\n"
                 "fmv.x.s %[r], ft0\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fmv_x_s_e[i]) {
      printf("[TC %d] Index %d FAILED (fmv_x_s). Got 0x%08x%08x, expected 0x%08x%08x\n", 1, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fmv_x_s_e[i] >> 32), (uint32_t)fmv_x_s_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 1);
}

static const uint32_t fmv_s_x_s0[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0x3e2f5ab0, 0xc150179a, 0x414d8449, 0xbca13283};
static const uint32_t fmv_s_x_e[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0x3e2f5ab0, 0xc150179a, 0x414d8449, 0xbca13283};
static void test_fmv_s_x(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fmv_s_x_s0, sizeof(fmv_s_x_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("fmv.s.x ft0, %[x0]\n"
                 "fsw ft0, 0(%[o])\n"
                 : 
                 : [x0] "r"((uint32_t)s0[i]), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint32_t got = *o;
    if (got != fmv_s_x_e[i]) {
      printf("[TC %d] Index %d FAILED (fmv_s_x). Got 0x%08x%08x, expected 0x%08x%08x\n", 2, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fmv_s_x_e[i] >> 32), (uint32_t)fmv_s_x_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 2);
}

static const uint32_t nanbox_flw_s0[] = {0x0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0x1, 0x80000001, 0x3f800000, 0xbf800000, 0x7f7fffff, 0x3e2f5ab0, 0xc150179a, 0x414d8449, 0xbca13283};
static const uint64_t nanbox_flw_e[] = {0xffffffff00000000, 0xffffffff80000000, 0xffffffff7f800000, 0xffffffffff800000, 0xffffffff7fc00000, 0xffffffff00000001, 0xffffffff80000001, 0xffffffff3f800000, 0xffffffffbf800000, 0xffffffff7f7fffff, 0xffffffff3e2f5ab0, 0xffffffffc150179a, 0xffffffff414d8449, 0xffffffffbca13283};
static void test_nanbox_flw(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(nanbox_flw_s0, sizeof(nanbox_flw_s0));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("flw ft0, 0(%[s0])\n"
                 "fsd ft0, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != nanbox_flw_e[i]) {
      printf("[TC %d] Index %d FAILED (nanbox_flw). Got 0x%08x%08x, expected 0x%08x%08x\n", 3, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)nanbox_flw_e[i] >> 32), (uint32_t)nanbox_flw_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 3);
}

static const uint16_t fmv_x_h_s0[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x1, 0x8001, 0x3c00, 0xbc00, 0x7bff, 0x44c4, 0xd229, 0xc596, 0x4ced};
static const uint32_t fmv_x_h_e[] = {0x0, 0xffff8000, 0x7c00, 0xfffffc00, 0x7e00, 0x1, 0xffff8001, 0x3c00, 0xffffbc00, 0x7bff, 0x44c4, 0xffffd229, 0xffffc596, 0x4ced};
static void test_fmv_x_h(void) {
  const uint16_t *s0 = (uint16_t *)l1_copy(fmv_x_h_s0, sizeof(fmv_x_h_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    uint32_t r;
    asm volatile("flh ft0, 0(%[s0])\n"
                 "fmv.x.h %[r], ft0\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fmv_x_h_e[i]) {
      printf("[TC %d] Index %d FAILED (fmv_x_h). Got 0x%08x%08x, expected 0x%08x%08x\n", 4, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fmv_x_h_e[i] >> 32), (uint32_t)fmv_x_h_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 4);
}

static const uint32_t fmv_h_x_s0[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x1, 0x8001, 0x3c00, 0xbc00, 0x7bff, 0x44c4, 0xd229, 0xc596, 0x4ced};
static const uint16_t fmv_h_x_e[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x1, 0x8001, 0x3c00, 0xbc00, 0x7bff, 0x44c4, 0xd229, 0xc596, 0x4ced};
static void test_fmv_h_x(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fmv_h_x_s0, sizeof(fmv_h_x_s0));
  uint16_t *o = (uint16_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("fmv.h.x ft0, %[x0]\n"
                 "fsh ft0, 0(%[o])\n"
                 : 
                 : [x0] "r"((uint32_t)s0[i]), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint16_t got = *o;
    if (got != fmv_h_x_e[i]) {
      printf("[TC %d] Index %d FAILED (fmv_h_x). Got 0x%08x%08x, expected 0x%08x%08x\n", 5, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fmv_h_x_e[i] >> 32), (uint32_t)fmv_h_x_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 5);
}

static const uint16_t nanbox_flh_s0[] = {0x0, 0x8000, 0x7c00, 0xfc00, 0x7e00, 0x1, 0x8001, 0x3c00, 0xbc00, 0x7bff, 0x44c4, 0xd229, 0xc596, 0x4ced};
static const uint64_t nanbox_flh_e[] = {0xffffffffffff0000, 0xffffffffffff8000, 0xffffffffffff7c00, 0xfffffffffffffc00, 0xffffffffffff7e00, 0xffffffffffff0001, 0xffffffffffff8001, 0xffffffffffff3c00, 0xffffffffffffbc00, 0xffffffffffff7bff, 0xffffffffffff44c4, 0xffffffffffffd229, 0xffffffffffffc596, 0xffffffffffff4ced};
static void test_nanbox_flh(void) {
  const uint16_t *s0 = (uint16_t *)l1_copy(nanbox_flh_s0, sizeof(nanbox_flh_s0));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("flh ft0, 0(%[s0])\n"
                 "fsd ft0, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != nanbox_flh_e[i]) {
      printf("[TC %d] Index %d FAILED (nanbox_flh). Got 0x%08x%08x, expected 0x%08x%08x\n", 6, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)nanbox_flh_e[i] >> 32), (uint32_t)nanbox_flh_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 6);
}

static const uint8_t fmv_x_b_s0[] = {0x0, 0x80, 0x7c, 0xfc, 0x7e, 0x1, 0x81, 0x3c, 0xbc, 0x7b, 0x4f, 0xc6, 0x24, 0x55};
static const uint32_t fmv_x_b_e[] = {0x0, 0xffffff80, 0x7c, 0xfffffffc, 0x7e, 0x1, 0xffffff81, 0x3c, 0xffffffbc, 0x7b, 0x4f, 0xffffffc6, 0x24, 0x55};
static void test_fmv_x_b(void) {
  const uint8_t *s0 = (uint8_t *)l1_copy(fmv_x_b_s0, sizeof(fmv_x_b_s0));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    uint32_t r;
    asm volatile("flb ft0, 0(%[s0])\n"
                 "fmv.x.b %[r], ft0\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fmv_x_b_e[i]) {
      printf("[TC %d] Index %d FAILED (fmv_x_b). Got 0x%08x%08x, expected 0x%08x%08x\n", 7, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fmv_x_b_e[i] >> 32), (uint32_t)fmv_x_b_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 7);
}

static const uint32_t fmv_b_x_s0[] = {0x0, 0x80, 0x7c, 0xfc, 0x7e, 0x1, 0x81, 0x3c, 0xbc, 0x7b, 0x4f, 0xc6, 0x24, 0x55};
static const uint8_t fmv_b_x_e[] = {0x0, 0x80, 0x7c, 0xfc, 0x7e, 0x1, 0x81, 0x3c, 0xbc, 0x7b, 0x4f, 0xc6, 0x24, 0x55};
static void test_fmv_b_x(void) {
  const uint32_t *s0 = (uint32_t *)l1_copy(fmv_b_x_s0, sizeof(fmv_b_x_s0));
  uint8_t *o = (uint8_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("fmv.b.x ft0, %[x0]\n"
                 "fsb ft0, 0(%[o])\n"
                 : 
                 : [x0] "r"((uint32_t)s0[i]), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint8_t got = *o;
    if (got != fmv_b_x_e[i]) {
      printf("[TC %d] Index %d FAILED (fmv_b_x). Got 0x%08x%08x, expected 0x%08x%08x\n", 8, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fmv_b_x_e[i] >> 32), (uint32_t)fmv_b_x_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 8);
}

static const uint8_t nanbox_flb_s0[] = {0x0, 0x80, 0x7c, 0xfc, 0x7e, 0x1, 0x81, 0x3c, 0xbc, 0x7b, 0x4f, 0xc6, 0x24, 0x55};
static const uint64_t nanbox_flb_e[] = {0xffffffffffffff00, 0xffffffffffffff80, 0xffffffffffffff7c, 0xfffffffffffffffc, 0xffffffffffffff7e, 0xffffffffffffff01, 0xffffffffffffff81, 0xffffffffffffff3c, 0xffffffffffffffbc, 0xffffffffffffff7b, 0xffffffffffffff4f, 0xffffffffffffffc6, 0xffffffffffffff24, 0xffffffffffffff55};
static void test_nanbox_flb(void) {
  const uint8_t *s0 = (uint8_t *)l1_copy(nanbox_flb_s0, sizeof(nanbox_flb_s0));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("flb ft0, 0(%[s0])\n"
                 "fsd ft0, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != nanbox_flb_e[i]) {
      printf("[TC %d] Index %d FAILED (nanbox_flb). Got 0x%08x%08x, expected 0x%08x%08x\n", 9, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)nanbox_flb_e[i] >> 32), (uint32_t)nanbox_flb_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 9);
}

static const uint64_t fld_fsd_s0[] = {0x0, 0x8000000000000000, 0x7ff0000000000000, 0xfff0000000000000, 0x7ff8000000000000, 0x1, 0x8000000000000001, 0x3ff0000000000000, 0xbff0000000000000, 0x7fefffffffffffff, 0x405dd933d2d58443, 0xbfdb804d98418117, 0xbffba667651c5253, 0xc05ef829f6ced90a};
static const uint64_t fld_fsd_e[] = {0x0, 0x8000000000000000, 0x7ff0000000000000, 0xfff0000000000000, 0x7ff8000000000000, 0x1, 0x8000000000000001, 0x3ff0000000000000, 0xbff0000000000000, 0x7fefffffffffffff, 0x405dd933d2d58443, 0xbfdb804d98418117, 0xbffba667651c5253, 0xc05ef829f6ced90a};
static void test_fld_fsd(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fld_fsd_s0, sizeof(fld_fsd_s0));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fsd ft0, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fld_fsd_e[i]) {
      printf("[TC %d] Index %d FAILED (fld_fsd). Got 0x%08x%08x, expected 0x%08x%08x\n", 10, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fld_fsd_e[i] >> 32), (uint32_t)fld_fsd_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 10);
}

int main(void) {
  if (!snrt_is_spatz_core()) return 0;
  INIT_CHECK();
  enable_vec();
  enable_fp();
  asm volatile("fsrmi 0");  // round to nearest, ties to even

  test_fmv_x_s();
  test_fmv_s_x();
  test_nanbox_flw();
  test_fmv_x_h();
  test_fmv_h_x();
  test_nanbox_flh();
  test_fmv_x_b();
  test_fmv_b_x();
  test_nanbox_flb();
  test_fld_fsd();

  EXIT_CHECK();
}
