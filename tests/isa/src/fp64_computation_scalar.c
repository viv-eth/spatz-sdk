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

static const uint64_t fadd_d_s0[] = {0x3f91afc52cb0327c, 0x405dc803146e902c, 0xbffb8a6532c129e6, 0x3fdd1c55b2db3722, 0x3fd325d68a0afd77, 0x3f91afc52cb0327c, 0x3f9adf166726c87d, 0x3fd325d68a0afd77, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x8000000000000001};
static const uint64_t fadd_d_s1[] = {0xbffb8a6532c129e6, 0x3f9adf166726c87d, 0x40296c0ef3358da9, 0x3fd325d68a0afd77, 0x3fdd1c55b2db3722, 0x4009cecda1560927, 0x4009cecda1560927, 0x405dc803146e902c, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x1};
static const uint64_t fadd_d_e[] = {0xbffb43a61e0e691c, 0x405dc9b105d50299, 0x4025fac24cdd686c, 0x3fe821161e731a4c, 0x3fe821161e731a4c, 0x4009f22d2baf698c, 0x400a048bce2456b8, 0x405ddb28eaf89b29, 0x7ff8000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x0};
static void test_fadd_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fadd_d_s0, sizeof(fadd_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fadd_d_s1, sizeof(fadd_d_s1));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fadd.d ft2, ft0, ft1, rne\n"
                 "fsd ft2, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fadd_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fadd_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 1, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fadd_d_e[i] >> 32), (uint32_t)fadd_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 1);
}

static const uint64_t fsub_d_s0[] = {0x40296c0ef3358da9, 0x3fdd1c55b2db3722, 0x405dc803146e902c, 0x405dc803146e902c, 0x4009cecda1560927, 0xbffb8a6532c129e6, 0x405dc803146e902c, 0x405dc803146e902c, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x8000000000000001};
static const uint64_t fsub_d_s1[] = {0x4009cecda1560927, 0xbffb8a6532c129e6, 0x3fffcd4034194e29, 0x3fdd1c55b2db3722, 0xbffb8a6532c129e6, 0x405dc803146e902c, 0x3fa75584c509bba6, 0x405dc803146e902c, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x1};
static const uint64_t fsub_d_e[] = {0x4022f85b8ae00b5f, 0x400168bd4fbbfbd7, 0x405d48ce139e2af3, 0x405daae6bebbb4f5, 0x4013ca001d5b4f0d, 0xc05e362ca93994d4, 0x405dc51863d5eef5, 0x0, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x0, 0x8000000000000002};
static void test_fsub_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fsub_d_s0, sizeof(fsub_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fsub_d_s1, sizeof(fsub_d_s1));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fsub.d ft2, ft0, ft1, rne\n"
                 "fsd ft2, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fsub_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fsub_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 2, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fsub_d_e[i] >> 32), (uint32_t)fsub_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 2);
}

static const uint64_t fmul_d_s0[] = {0x405dc803146e902c, 0x3fdd1c55b2db3722, 0x3fa75584c509bba6, 0xbffb8a6532c129e6, 0x3f91afc52cb0327c, 0x40296c0ef3358da9, 0xbffb8a6532c129e6, 0x3f9adf166726c87d, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x8000000000000001};
static const uint64_t fmul_d_s1[] = {0x3fdd1c55b2db3722, 0xbffb8a6532c129e6, 0x3fdd1c55b2db3722, 0x3fdd1c55b2db3722, 0xbffb8a6532c129e6, 0x4009cecda1560927, 0x3fdd1c55b2db3722, 0x4009cecda1560927, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x1};
static const uint64_t fmul_d_e[] = {0x404b17a18ef2d6f2, 0xbfe90dce9016c350, 0x3f953a29a45171f5, 0xbfe90dce9016c350, 0xbf9e71989db23db4, 0x404480b6aaab4a60, 0xbfe90dce9016c350, 0x3fb5abf24d70830f, 0xfff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x8000000000000000, 0x0, 0x8000000000000000};
static void test_fmul_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fmul_d_s0, sizeof(fmul_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fmul_d_s1, sizeof(fmul_d_s1));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fmul.d ft2, ft0, ft1, rne\n"
                 "fsd ft2, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fmul_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fmul_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 3, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fmul_d_e[i] >> 32), (uint32_t)fmul_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 3);
}

static const uint64_t fmadd_d_s0[] = {0x3fffcd4034194e29, 0x3fffcd4034194e29, 0x3fd325d68a0afd77, 0x4009cecda1560927, 0x3fdd1c55b2db3722, 0x3f9adf166726c87d, 0x3fd325d68a0afd77, 0xbffb8a6532c129e6};
static const uint64_t fmadd_d_s1[] = {0x3f91afc52cb0327c, 0x40296c0ef3358da9, 0x4009cecda1560927, 0x40296c0ef3358da9, 0x3f9adf166726c87d, 0x3fd325d68a0afd77, 0x4009cecda1560927, 0x4009cecda1560927};
static const uint64_t fmadd_d_s2[] = {0x3fd325d68a0afd77, 0x3f9adf166726c87d, 0x3fdd1c55b2db3722, 0x3fffcd4034194e29, 0x3fd325d68a0afd77, 0x3f9adf166726c87d, 0xbffb8a6532c129e6, 0x3fa75584c509bba6};
static const uint64_t fmadd_d_e[] = {0x3fd5584d9ae3db76, 0x40394a75827d533b, 0x3ff6b863a8984975, 0x40457f20ac4c14d2, 0x3fd3e96645c9ccd1, 0x3fa1749a0d513e77, 0xbfe8322dedbf5c74, 0xc016076feb0636df};
static void test_fmadd_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fmadd_d_s0, sizeof(fmadd_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fmadd_d_s1, sizeof(fmadd_d_s1));
  const uint64_t *s2 = (uint64_t *)l1_copy(fmadd_d_s2, sizeof(fmadd_d_s2));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 8; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fld ft2, 0(%[s2])\n"
                 "fmadd.d ft3, ft0, ft1, ft2, rne\n"
                 "fsd ft3, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [s2] "r"(s2 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fmadd_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fmadd_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 4, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fmadd_d_e[i] >> 32), (uint32_t)fmadd_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 4);
}

static const uint64_t fmsub_d_s0[] = {0x3fd325d68a0afd77, 0x3fdd1c55b2db3722, 0x3f91afc52cb0327c, 0x3f91afc52cb0327c, 0x3f9adf166726c87d, 0x3fdd1c55b2db3722, 0x3f9adf166726c87d, 0x3f91afc52cb0327c};
static const uint64_t fmsub_d_s1[] = {0x4009cecda1560927, 0x4009cecda1560927, 0xbffb8a6532c129e6, 0x3fa75584c509bba6, 0x3fdd1c55b2db3722, 0x3f91afc52cb0327c, 0x3fdd1c55b2db3722, 0x3fd325d68a0afd77};
static const uint64_t fmsub_d_s2[] = {0x405dc803146e902c, 0x40296c0ef3358da9, 0xbffb8a6532c129e6, 0x3fa75584c509bba6, 0x40296c0ef3358da9, 0x3fffcd4034194e29, 0x3f9adf166726c87d, 0xbffb8a6532c129e6};
static const uint64_t fmsub_d_e[] = {0xc05d8a3ddb7f0a3d, 0xc0267cc665befe32, 0x3ffb109ed04a60ef, 0xbfa6ee57f51b2a69, 0xc02965f27557972e, 0xbfffad124c63c357, 0xbf8d4c355673a5af, 0x3ffb9f8fc085b7da};
static void test_fmsub_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fmsub_d_s0, sizeof(fmsub_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fmsub_d_s1, sizeof(fmsub_d_s1));
  const uint64_t *s2 = (uint64_t *)l1_copy(fmsub_d_s2, sizeof(fmsub_d_s2));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 8; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fld ft2, 0(%[s2])\n"
                 "fmsub.d ft3, ft0, ft1, ft2, rne\n"
                 "fsd ft3, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [s2] "r"(s2 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fmsub_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fmsub_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 5, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fmsub_d_e[i] >> 32), (uint32_t)fmsub_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 5);
}

static const uint64_t fnmsub_d_s0[] = {0xbffb8a6532c129e6, 0x4009cecda1560927, 0x3f91afc52cb0327c, 0x3f9adf166726c87d, 0x3fffcd4034194e29, 0x3fffcd4034194e29, 0x40296c0ef3358da9, 0x3f9adf166726c87d};
static const uint64_t fnmsub_d_s1[] = {0x40296c0ef3358da9, 0x3fffcd4034194e29, 0x4009cecda1560927, 0x3fd325d68a0afd77, 0x3fd325d68a0afd77, 0x3fffcd4034194e29, 0x4009cecda1560927, 0x3fa75584c509bba6};
static const uint64_t fnmsub_d_s2[] = {0x3fd325d68a0afd77, 0x3fa75584c509bba6, 0x3fffcd4034194e29, 0x3f91afc52cb0327c, 0x3f91afc52cb0327c, 0x3fffcd4034194e29, 0x3f91afc52cb0327c, 0x3fdd1c55b2db3722};
static const uint64_t fnmsub_d_e[] = {0x40362db65d37ae70, 0xc0197734c7b28dfd, 0x3ffee90640a28811, 0x3f834b4ef268fc17, 0xbfe279fa7d932f6a, 0xbfff686194016a9d, 0xc0447e80b205b45a, 0x3fdd08bd8aafdf4b};
static void test_fnmsub_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fnmsub_d_s0, sizeof(fnmsub_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fnmsub_d_s1, sizeof(fnmsub_d_s1));
  const uint64_t *s2 = (uint64_t *)l1_copy(fnmsub_d_s2, sizeof(fnmsub_d_s2));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 8; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fld ft2, 0(%[s2])\n"
                 "fnmsub.d ft3, ft0, ft1, ft2, rne\n"
                 "fsd ft3, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [s2] "r"(s2 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fnmsub_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fnmsub_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 6, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fnmsub_d_e[i] >> 32), (uint32_t)fnmsub_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 6);
}

static const uint64_t fnmadd_d_s0[] = {0x3fd325d68a0afd77, 0x3fdd1c55b2db3722, 0xbffb8a6532c129e6, 0x3f9adf166726c87d, 0x3fa75584c509bba6, 0x3fffcd4034194e29, 0x405dc803146e902c, 0x4009cecda1560927};
static const uint64_t fnmadd_d_s1[] = {0x3f9adf166726c87d, 0x405dc803146e902c, 0x3fdd1c55b2db3722, 0x3f91afc52cb0327c, 0x3fffcd4034194e29, 0x405dc803146e902c, 0x3fd325d68a0afd77, 0x3f91afc52cb0327c};
static const uint64_t fnmadd_d_s2[] = {0x3fdd1c55b2db3722, 0x4009cecda1560927, 0xbffb8a6532c129e6, 0xbffb8a6532c129e6, 0x3f91afc52cb0327c, 0x3fdd1c55b2db3722, 0x40296c0ef3358da9, 0x4009cecda1560927};
static const uint64_t fnmadd_d_e[] = {0xbfdd9cf78e12f269, 0xc04cb48e69083784, 0x400408a63d6645c7, 0x3ffb8889ef11a2bb, 0xbfbb9c7495a2b664, 0xc06da7563ae22870, 0xc0482cfc7e8c092c, 0xc00a40ea9b116c33};
static void test_fnmadd_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fnmadd_d_s0, sizeof(fnmadd_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fnmadd_d_s1, sizeof(fnmadd_d_s1));
  const uint64_t *s2 = (uint64_t *)l1_copy(fnmadd_d_s2, sizeof(fnmadd_d_s2));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 8; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fld ft2, 0(%[s2])\n"
                 "fnmadd.d ft3, ft0, ft1, ft2, rne\n"
                 "fsd ft3, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [s2] "r"(s2 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fnmadd_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fnmadd_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 7, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fnmadd_d_e[i] >> 32), (uint32_t)fnmadd_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 7);
}

static const uint64_t fmin_d_s0[] = {0x3f9adf166726c87d, 0x3fd325d68a0afd77, 0xbffb8a6532c129e6, 0x3f91afc52cb0327c, 0x3fa75584c509bba6, 0x40296c0ef3358da9, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x8000000000000001, 0x0, 0x7ff8000000000000};
static const uint64_t fmin_d_s1[] = {0x3f9adf166726c87d, 0x3fdd1c55b2db3722, 0x405dc803146e902c, 0x3fd325d68a0afd77, 0x405dc803146e902c, 0x3f9adf166726c87d, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x1, 0x8000000000000000, 0x7ff8000000000000};
static const uint64_t fmin_d_e[] = {0x3f9adf166726c87d, 0x3fd325d68a0afd77, 0xbffb8a6532c129e6, 0x3f91afc52cb0327c, 0x3fa75584c509bba6, 0x3f9adf166726c87d, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x8000000000000001, 0x8000000000000000, 0x7ff8000000000000};
static void test_fmin_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fmin_d_s0, sizeof(fmin_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fmin_d_s1, sizeof(fmin_d_s1));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fmin.d ft2, ft0, ft1\n"
                 "fsd ft2, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fmin_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fmin_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 8, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fmin_d_e[i] >> 32), (uint32_t)fmin_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 8);
}

static const uint64_t fmax_d_s0[] = {0xbffb8a6532c129e6, 0x3fd325d68a0afd77, 0x3fdd1c55b2db3722, 0x40296c0ef3358da9, 0x4009cecda1560927, 0x3fdd1c55b2db3722, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x8000000000000001, 0x0, 0x7ff8000000000000};
static const uint64_t fmax_d_s1[] = {0x4009cecda1560927, 0x3f9adf166726c87d, 0x3fa75584c509bba6, 0x3f9adf166726c87d, 0x3fdd1c55b2db3722, 0x405dc803146e902c, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x1, 0x8000000000000000, 0x7ff8000000000000};
static const uint64_t fmax_d_e[] = {0x4009cecda1560927, 0x3fd325d68a0afd77, 0x3fdd1c55b2db3722, 0x40296c0ef3358da9, 0x4009cecda1560927, 0x405dc803146e902c, 0x7ff0000000000000, 0x7ff0000000000000, 0x3fffcd4034194e29, 0x0, 0x8000000000000000, 0x1, 0x0, 0x7ff8000000000000};
static void test_fmax_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fmax_d_s0, sizeof(fmax_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fmax_d_s1, sizeof(fmax_d_s1));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fmax.d ft2, ft0, ft1\n"
                 "fsd ft2, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fmax_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fmax_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 9, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fmax_d_e[i] >> 32), (uint32_t)fmax_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 9);
}

static const uint64_t fsgnj_d_s0[] = {0xbffb8a6532c129e6, 0x3fd325d68a0afd77, 0x3f91afc52cb0327c, 0xbffb8a6532c129e6, 0xbffb8a6532c129e6, 0x4009cecda1560927, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x8000000000000001};
static const uint64_t fsgnj_d_s1[] = {0x3f91afc52cb0327c, 0xbffb8a6532c129e6, 0x40296c0ef3358da9, 0x3fd325d68a0afd77, 0x3f9adf166726c87d, 0x4009cecda1560927, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x1};
static const uint64_t fsgnj_d_e[] = {0x3ffb8a6532c129e6, 0xbfd325d68a0afd77, 0x3f91afc52cb0327c, 0x3ffb8a6532c129e6, 0x3ffb8a6532c129e6, 0x4009cecda1560927, 0xfff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x8000000000000000, 0x8000000000000000, 0x1};
static void test_fsgnj_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fsgnj_d_s0, sizeof(fsgnj_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fsgnj_d_s1, sizeof(fsgnj_d_s1));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 12; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fsgnj.d ft2, ft0, ft1\n"
                 "fsd ft2, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fsgnj_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fsgnj_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 10, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fsgnj_d_e[i] >> 32), (uint32_t)fsgnj_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 10);
}

static const uint64_t fsgnjn_d_s0[] = {0x4009cecda1560927, 0x3f9adf166726c87d, 0x3f91afc52cb0327c, 0xbffb8a6532c129e6, 0x3f91afc52cb0327c, 0x4009cecda1560927, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x8000000000000001};
static const uint64_t fsgnjn_d_s1[] = {0x3fdd1c55b2db3722, 0x40296c0ef3358da9, 0x3fffcd4034194e29, 0x40296c0ef3358da9, 0x3f91afc52cb0327c, 0x4009cecda1560927, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x1};
static const uint64_t fsgnjn_d_e[] = {0xc009cecda1560927, 0xbf9adf166726c87d, 0xbf91afc52cb0327c, 0xbffb8a6532c129e6, 0xbf91afc52cb0327c, 0xc009cecda1560927, 0x7ff0000000000000, 0xfff0000000000000, 0xfff8000000000000, 0x0, 0x0, 0x8000000000000001};
static void test_fsgnjn_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fsgnjn_d_s0, sizeof(fsgnjn_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fsgnjn_d_s1, sizeof(fsgnjn_d_s1));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 12; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fsgnjn.d ft2, ft0, ft1\n"
                 "fsd ft2, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fsgnjn_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fsgnjn_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 11, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fsgnjn_d_e[i] >> 32), (uint32_t)fsgnjn_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 11);
}

static const uint64_t fsgnjx_d_s0[] = {0x3fd325d68a0afd77, 0x3fd325d68a0afd77, 0x3fd325d68a0afd77, 0x3fd325d68a0afd77, 0x3fdd1c55b2db3722, 0x3f91afc52cb0327c, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x8000000000000001};
static const uint64_t fsgnjx_d_s1[] = {0x40296c0ef3358da9, 0x40296c0ef3358da9, 0x40296c0ef3358da9, 0x40296c0ef3358da9, 0x4009cecda1560927, 0x3f9adf166726c87d, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x1};
static const uint64_t fsgnjx_d_e[] = {0x3fd325d68a0afd77, 0x3fd325d68a0afd77, 0x3fd325d68a0afd77, 0x3fd325d68a0afd77, 0x3fdd1c55b2db3722, 0x3f91afc52cb0327c, 0xfff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x8000000000000000, 0x0, 0x8000000000000001};
static void test_fsgnjx_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fsgnjx_d_s0, sizeof(fsgnjx_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fsgnjx_d_s1, sizeof(fsgnjx_d_s1));
  uint64_t *o = (uint64_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 12; i++) {
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fsgnjx.d ft2, ft0, ft1\n"
                 "fsd ft2, 0(%[o])\n"
                 : 
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i), [o] "r"(o)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    asm volatile("fence" ::: "memory");
    uint64_t got = *o;
    if (got != fsgnjx_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fsgnjx_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 12, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fsgnjx_d_e[i] >> 32), (uint32_t)fsgnjx_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 12);
}

static const uint64_t feq_d_s0[] = {0x3f91afc52cb0327c, 0xbffb8a6532c129e6, 0x3fd325d68a0afd77, 0x3fd325d68a0afd77, 0x4009cecda1560927, 0x3fdd1c55b2db3722, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x8000000000000001, 0x3f91afc52cb0327c, 0x0};
static const uint64_t feq_d_s1[] = {0x405dc803146e902c, 0x405dc803146e902c, 0x3f91afc52cb0327c, 0x4009cecda1560927, 0x3f91afc52cb0327c, 0x3fa75584c509bba6, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x1, 0x3f91afc52cb0327c, 0x8000000000000000};
static const uint32_t feq_d_e[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x0, 0x1, 0x1};
static void test_feq_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(feq_d_s0, sizeof(feq_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(feq_d_s1, sizeof(feq_d_s1));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    uint32_t r;
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "feq.d %[r], ft0, ft1\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != feq_d_e[i]) {
      printf("[TC %d] Index %d FAILED (feq_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 13, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)feq_d_e[i] >> 32), (uint32_t)feq_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 13);
}

static const uint64_t flt_d_s0[] = {0x405dc803146e902c, 0x40296c0ef3358da9, 0x3fffcd4034194e29, 0x4009cecda1560927, 0x3f9adf166726c87d, 0x3fd325d68a0afd77, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x8000000000000001, 0x405dc803146e902c, 0x0};
static const uint64_t flt_d_s1[] = {0x3fdd1c55b2db3722, 0x3fd325d68a0afd77, 0x405dc803146e902c, 0x3f91afc52cb0327c, 0x3fd325d68a0afd77, 0xbffb8a6532c129e6, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x1, 0x405dc803146e902c, 0x8000000000000000};
static const uint32_t flt_d_e[] = {0x0, 0x0, 0x1, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0};
static void test_flt_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(flt_d_s0, sizeof(flt_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(flt_d_s1, sizeof(flt_d_s1));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    uint32_t r;
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "flt.d %[r], ft0, ft1\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != flt_d_e[i]) {
      printf("[TC %d] Index %d FAILED (flt_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 14, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)flt_d_e[i] >> 32), (uint32_t)flt_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 14);
}

static const uint64_t fle_d_s0[] = {0x405dc803146e902c, 0xbffb8a6532c129e6, 0x3fd325d68a0afd77, 0x3fd325d68a0afd77, 0x3fd325d68a0afd77, 0x3fdd1c55b2db3722, 0x7ff0000000000000, 0x7ff0000000000000, 0x7ff8000000000000, 0x0, 0x8000000000000000, 0x8000000000000001, 0x405dc803146e902c, 0x0};
static const uint64_t fle_d_s1[] = {0x3f91afc52cb0327c, 0x4009cecda1560927, 0xbffb8a6532c129e6, 0x3fffcd4034194e29, 0x3fa75584c509bba6, 0x4009cecda1560927, 0xfff0000000000000, 0x4009cecda1560927, 0x3fffcd4034194e29, 0x8000000000000000, 0x8000000000000000, 0x1, 0x405dc803146e902c, 0x8000000000000000};
static const uint32_t fle_d_e[] = {0x0, 0x1, 0x0, 0x1, 0x0, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1};
static void test_fle_d(void) {
  const uint64_t *s0 = (uint64_t *)l1_copy(fle_d_s0, sizeof(fle_d_s0));
  const uint64_t *s1 = (uint64_t *)l1_copy(fle_d_s1, sizeof(fle_d_s1));
  uint32_t *o = (uint32_t *)snrt_l1_alloc(8);
  for (int i = 0; i < 14; i++) {
    uint32_t r;
    asm volatile("fld ft0, 0(%[s0])\n"
                 "fld ft1, 0(%[s1])\n"
                 "fle.d %[r], ft0, ft1\n"
                 : [r] "=r"(r)
                 : [s0] "r"(s0 + i), [s1] "r"(s1 + i)
                 : "memory", "ft0", "ft1", "ft2", "ft3");
    uint32_t got = r;
    if (got != fle_d_e[i]) {
      printf("[TC %d] Index %d FAILED (fle_d). Got 0x%08x%08x, expected 0x%08x%08x\n", 15, i,
             (uint32_t)((uint64_t)got >> 32), (uint32_t)got,
             (uint32_t)((uint64_t)fle_d_e[i] >> 32), (uint32_t)fle_d_e[i]);
      num_failed++;
      return;
    }
  }
  printf("[TC %d] PASSED.\n", 15);
}

int main(void) {
  if (!snrt_is_spatz_core()) return 0;
  INIT_CHECK();
  enable_vec();
  enable_fp();
  asm volatile("fsrmi 0");  // round to nearest, ties to even

  test_fadd_d();
  test_fsub_d();
  test_fmul_d();
  test_fmadd_d();
  test_fmsub_d();
  test_fnmsub_d();
  test_fnmadd_d();
  test_fmin_d();
  test_fmax_d();
  test_fsgnj_d();
  test_fsgnjn_d();
  test_fsgnjx_d();
  test_feq_d();
  test_flt_d();
  test_fle_d();

  EXIT_CHECK();
}
