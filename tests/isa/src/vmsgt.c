// Copyright 2026 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Generated with golden values from a Python model, in the style of the
// vendored tests. Operands: vs2 = v8, vs1 = v16, scalar/immediate = -3.

#include "vector_macros.h"

void TEST_CASE1(void) {
  int64_t scalar = -3;
  VSET(16, e8, m4);
  VLOAD_8(v8, 0xfd, 0xfd, 0x7f, 0x1, 0xfd, 0xfd, 0x7d, 0x4e, 0x7f, 0x8, 0xfd,
          0x42, 0x4, 0xfd, 0x1, 0xfd);
  VCLEAR(v2);
  asm volatile("vmsgt.vx v2, v8, %[A]" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(1, v2, 0x5bcc);
  VSET(16, e16, m4);
  VLOAD_16(v8, 0xfffd, 0x7fff, 0x51ac, 0x488, 0x7fff, 0xfffd, 0xc8ad, 0x1ec6,
           0x7fff, 0x1cb, 0xfffd, 0x8e03, 0x17aa, 0x1e9c, 0xffff, 0xfffd);
  VCLEAR(v2);
  asm volatile("vmsgt.vx v2, v8, %[A]" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(2, v2, 0x739e);
  VSET(16, e32, m4);
  VLOAD_32(v8, 0xfffffffd, 0xfffffffd, 0xff0a674d, 0x99a90675, 0x57d3a0ae,
           0xfffffffd, 0x80000000, 0x4812ab06, 0x6cd28f49, 0xd58d8582,
           0xfffffffd, 0x7fffffff, 0xee6f79d6, 0xe38b526, 0xffffffff,
           0xfffffffd);
  VCLEAR(v2);
  asm volatile("vmsgt.vx v2, v8, %[A]" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(3, v2, 0x6990);
#if ELEN == 64
  VSET(16, e64, m4);
  VLOAD_64(v8, 0xfffffffffffffffd, 0x84506350afd60b62, 0xf0a6383e6aaf1061,
           0xacb0327c10570e51, 0x16c0e921f3358da9, 0xfffffffffffffffd,
           0x8000000000000000, 0x64426ad365a2a36c, 0x7fffffffffffffff,
           0x25bed805bdba1fd, 0xfffffffffffffffd, 0x7fffffffffffffff,
           0x8000000000000000, 0x2c3b26ac379f922a, 0xcc73ba7e280b7fad,
           0xfffffffffffffffd);
  VCLEAR(v2);
  asm volatile("vmsgt.vx v2, v8, %[A]" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(4, v2, 0x2b90);
#endif
}

void TEST_CASE2(void) {
  int64_t scalar = -3;
  VSET(16, e8, m4);
  VLOAD_8(v8, 0xfd, 0xfd, 0x0, 0x80, 0x7f, 0xfd, 0x80, 0x1, 0xb4, 0x47, 0xfd,
          0x9c, 0x65, 0xfd, 0xf9, 0xfd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmsgt.vx v2, v8, %[A], v0.t" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(5, v2, 0x0280);
  VSET(16, e16, m4);
  VLOAD_16(v8, 0xfffd, 0xfffd, 0x7fff, 0x77b9, 0xc57, 0xfffd, 0xa579, 0x215e,
           0x24cf, 0xb5dd, 0xfffd, 0x1, 0xffff, 0x6cb9, 0x4f78, 0xfffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmsgt.vx v2, v8, %[A], v0.t" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(6, v2, 0x2888);
  VSET(16, e32, m4);
  VLOAD_32(v8, 0xfffffffd, 0x65e94b51, 0xfffffffd, 0xbe278ff, 0xffffffff,
           0xfffffffd, 0x78df906a, 0xfffffffd, 0x582f96fb, 0x4b9727fb,
           0xfffffffd, 0x4b86441b, 0x4d200699, 0x2b3b437f, 0xa6d9be87,
           0xfffffffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmsgt.vx v2, v8, %[A], v0.t" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(7, v2, 0x2a0a);
#if ELEN == 64
  VSET(16, e64, m4);
  VLOAD_64(v8, 0xfffffffffffffffd, 0xf686a5474162f31d, 0x95f4f9ce1ef61b9f,
           0xfffffffffffffffd, 0x542c66f81c423e16, 0xfffffffffffffffd,
           0x8fef0588c5bcb6e3, 0xd6897a12b3032ebb, 0x95d6077e71758aa9,
           0x7fffffffffffffff, 0xfffffffffffffffd, 0xf2a6c3b1ad165f91,
           0xfffffffffffffffd, 0x270ae52d24ec30e1, 0xffffffffffffffff,
           0xfffffffffffffffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmsgt.vx v2, v8, %[A], v0.t" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(8, v2, 0x2200);
#endif
}

void TEST_CASE3(void) {
  VSET(16, e8, m4);
  VLOAD_8(v8, 0xfd, 0x1, 0x2, 0x6a, 0xfd, 0xfd, 0x7f, 0x7f, 0xfd, 0xcd, 0xfd,
          0x1, 0x1, 0x4d, 0xfd, 0xfd);
  VCLEAR(v2);
  asm volatile("vmsgt.vi v2, v8, -3");
  VSET(1, e16, m1);
  VCMP_U16(9, v2, 0x38ce);
  VSET(16, e16, m4);
  VLOAD_16(v8, 0xfffd, 0x73c8, 0x8000, 0x54d, 0xfffd, 0xfffd, 0xf5d, 0x9333,
           0xffff, 0x9eb5, 0xfffd, 0x13cf, 0x46bf, 0xbfbb, 0x147f, 0xfffd);
  VCLEAR(v2);
  asm volatile("vmsgt.vi v2, v8, -3");
  VSET(1, e16, m1);
  VCMP_U16(10, v2, 0x594a);
  VSET(16, e32, m4);
  VLOAD_32(v8, 0xfffffffd, 0x73f04feb, 0xa905ebe7, 0x80000000, 0x0, 0xfffffffd,
           0xc5324bca, 0x5a887a19, 0x4a4d7b78, 0x0, 0xfffffffd, 0x6ae4de10,
           0xe0c0dafa, 0x7fffffff, 0x4a5b524c, 0xfffffffd);
  VCLEAR(v2);
  asm volatile("vmsgt.vi v2, v8, -3");
  VSET(1, e16, m1);
  VCMP_U16(11, v2, 0x6b92);
#if ELEN == 64
  VSET(16, e64, m4);
  VLOAD_64(v8, 0xfffffffffffffffd, 0xfffffffffffffffd, 0x823c4fdf6c23bf51, 0x0,
           0x8000000000000000, 0xfffffffffffffffd, 0x79b7fa02283da808,
           0x8ea5e8d8d5001b76, 0x43e465a41eb40584, 0x7fffffffffffffff,
           0xfffffffffffffffd, 0x8000000000000000, 0xcce4aab58c6e4907,
           0x9e8c5a7520f9b04d, 0x1, 0xfffffffffffffffd);
  VCLEAR(v2);
  asm volatile("vmsgt.vi v2, v8, -3");
  VSET(1, e16, m1);
  VCMP_U16(12, v2, 0x4348);
#endif
}

void TEST_CASE4(void) {
  VSET(16, e8, m4);
  VLOAD_8(v8, 0xfd, 0xfd, 0xda, 0x5b, 0x5c, 0xfd, 0xac, 0xff, 0xfd, 0x72, 0xfd,
          0x6, 0x92, 0xff, 0xff, 0xfd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmsgt.vi v2, v8, -3, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(13, v2, 0x2a88);
  VSET(16, e16, m4);
  VLOAD_16(v8, 0xfffd, 0x0, 0x85a1, 0xf37f, 0xfffd, 0xfffd, 0x1, 0xf61c, 0x7fff,
           0xe7a9, 0xfffd, 0xfffd, 0x94b1, 0xfffd, 0x43c8, 0xfffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmsgt.vi v2, v8, -3, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(14, v2, 0x0002);
  VSET(16, e32, m4);
  VLOAD_32(v8, 0xfffffffd, 0x176fd4df, 0x7fffffff, 0xbde3da31, 0x5d0870c2,
           0xfffffffd, 0x7a65eca4, 0xbf3464d, 0xfffffffd, 0x2d570bfe,
           0xfffffffd, 0xd94180d7, 0xd50148ed, 0x85bbdc98, 0x44868357,
           0xfffffffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmsgt.vi v2, v8, -3, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(15, v2, 0x0282);
#if ELEN == 64
  VSET(16, e64, m4);
  VLOAD_64(v8, 0xfffffffffffffffd, 0x7fffffffffffffff, 0xfffffffffffffffd,
           0xc4b5efd3ff939464, 0x8000000000000000, 0xfffffffffffffffd,
           0x3f5704b7b6783b3c, 0x7b2cf215b5660818, 0x6e8c3183a484ca7,
           0xfffffffffffffffd, 0xfffffffffffffffd, 0x7fffffffffffffff,
           0xb7280c6e79ea5276, 0x623413c9ade2960, 0x1, 0xfffffffffffffffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmsgt.vi v2, v8, -3, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(16, v2, 0x2882);
#endif
}

int main(void) {
  if (!snrt_is_spatz_core()) return 0;
  INIT_CHECK();
  enable_vec();

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();

  EXIT_CHECK();
}
