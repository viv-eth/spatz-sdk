// Copyright 2026 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Generated with golden values from a Python model, in the style of the
// vendored tests. Operands: vs2 = v8, vs1 = v16, scalar/immediate = -3.

#include "vector_macros.h"

void TEST_CASE1(void) {
  VSET(16, e8, m4);
  VLOAD_8(v8, 0xff, 0xfd, 0x7f, 0x1, 0xfd, 0xff, 0x7d, 0x4e, 0x7f, 0x8, 0x72,
          0x42, 0x4, 0xfd, 0x1, 0xb7);
  VLOAD_8(v16, 0xac, 0xea, 0x80, 0xfd, 0xfd, 0x63, 0x7d, 0xc5, 0x7f, 0x20, 0x7d,
          0x7f, 0xfd, 0xfd, 0xf0, 0x17);
  VCLEAR(v2);
  asm volatile("vmseq.vv v2, v8, v16");
  VSET(1, e16, m1);
  VCMP_U16(1, v2, 0x2150);
  VSET(16, e16, m4);
  VLOAD_16(v8, 0xffff, 0x7fff, 0x51ac, 0x488, 0x7fff, 0x0, 0xc8ad, 0x1ec6,
           0x7fff, 0x1cb, 0x7fff, 0x8e03, 0x17aa, 0x1e9c, 0xffff, 0x3210);
  VLOAD_16(v16, 0xd833, 0x8000, 0x51ac, 0x488, 0x0, 0x0, 0xc8ad, 0xa1a7, 0x7fff,
           0x63e8, 0x733d, 0xfffd, 0x8ba6, 0x4ffb, 0x8000, 0x2385);
  VCLEAR(v2);
  asm volatile("vmseq.vv v2, v8, v16");
  VSET(1, e16, m1);
  VCMP_U16(2, v2, 0x016c);
  VSET(16, e32, m4);
  VLOAD_32(v8, 0x7fffffff, 0xfffffffd, 0xff0a674d, 0x99a90675, 0x57d3a0ae,
           0x61bda755, 0x80000000, 0x4812ab06, 0x6cd28f49, 0xd58d8582, 0x1,
           0x7fffffff, 0xee6f79d6, 0xe38b526, 0xffffffff, 0xffffffff);
  VLOAD_32(v16, 0x7fffffff, 0x1360be92, 0xbab31bbc, 0xffffffff, 0xfffffffd,
           0x61bda755, 0xf20f9b45, 0x80000000, 0x6cd28f49, 0xd58d8582,
           0x80000000, 0x7fffffff, 0xee6f79d6, 0xe38b526, 0x73a8aa33,
           0x5ccfe4fc);
  VCLEAR(v2);
  asm volatile("vmseq.vv v2, v8, v16");
  VSET(1, e16, m1);
  VCMP_U16(3, v2, 0x3b21);
#if ELEN == 64
  VSET(16, e64, m4);
  VLOAD_64(v8, 0x1cecdeeea1560927, 0x84506350afd60b62, 0xf0a6383e6aaf1061,
           0xacb0327c10570e51, 0x16c0e921f3358da9, 0x7fffffffffffffff,
           0x8000000000000000, 0x64426ad365a2a36c, 0x7fffffffffffffff,
           0x25bed805bdba1fd, 0x8cd1d2602dd08d38, 0x7fffffffffffffff,
           0x8000000000000000, 0x2c3b26ac379f922a, 0xcc73ba7e280b7fad,
           0x2d39196991b89fb7);
  VLOAD_64(v16, 0x1dc6946a2605e3ff, 0xdf661185b57b173a, 0xf0a6383e6aaf1061,
           0x7fffffffffffffff, 0x16c0e921f3358da9, 0x7fffffffffffffff,
           0x34ce9d0983daa9f9, 0x64426ad365a2a36c, 0x57af7c99dc7bdf05,
           0x4375b754ba97c467, 0x50790cc3640a2ab6, 0x2dd909020231f35a,
           0x44b7fd709d2a6bdd, 0x1, 0xf282fa7a905663c9, 0xffffffffffffffff);
  VCLEAR(v2);
  asm volatile("vmseq.vv v2, v8, v16");
  VSET(1, e16, m1);
  VCMP_U16(4, v2, 0x00b4);
#endif
}

void TEST_CASE2(void) {
  VSET(16, e8, m4);
  VLOAD_8(v8, 0xfd, 0xfd, 0x0, 0x80, 0x7f, 0xfd, 0x80, 0x1, 0xb4, 0x47, 0xfd,
          0x9c, 0x65, 0xfd, 0xf9, 0xfd);
  VLOAD_8(v16, 0x80, 0xb9, 0x0, 0x80, 0x34, 0xf4, 0x8d, 0x1, 0x7a, 0x47, 0xfd,
          0x1, 0x65, 0xfd, 0xf9, 0xc8);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vv v2, v8, v16, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(5, v2, 0x2288);
  VSET(16, e16, m4);
  VLOAD_16(v8, 0x18a6, 0xfffd, 0x7fff, 0x77b9, 0xc57, 0x58ec, 0xa579, 0x215e,
           0x24cf, 0xb5dd, 0x60d7, 0x1, 0xffff, 0x6cb9, 0x4f78, 0x3f9f);
  VLOAD_16(v16, 0xfffd, 0xf74f, 0xb43e, 0x77b9, 0x0, 0xfffd, 0x93e7, 0xb678,
           0x24cf, 0xb5dd, 0x60d7, 0xffff, 0x0, 0x1, 0x7fff, 0x5618);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vv v2, v8, v16, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(6, v2, 0x0208);
  VSET(16, e32, m4);
  VLOAD_32(v8, 0xe86079cb, 0x65e94b51, 0xfffffffd, 0xbe278ff, 0xffffffff,
           0xfffffffd, 0x78df906a, 0xfffffffd, 0x582f96fb, 0x4b9727fb, 0x1,
           0x4b86441b, 0x4d200699, 0x2b3b437f, 0xa6d9be87, 0x0);
  VLOAD_32(v16, 0xe86079cb, 0x3e8374c2, 0x80000000, 0xd13bd703, 0x0, 0x79e627d1,
           0xfffffffd, 0x7fffffff, 0x582f96fb, 0x4b9727fb, 0xd7137d9,
           0x4b86441b, 0xb8fd59a2, 0x2b3b437f, 0xe77114ee, 0x44dc6812);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vv v2, v8, v16, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(7, v2, 0x2a00);
#if ELEN == 64
  VSET(16, e64, m4);
  VLOAD_64(v8, 0x0, 0xf686a5474162f31d, 0x95f4f9ce1ef61b9f, 0xfffffffffffffffd,
           0x542c66f81c423e16, 0xdccc20ad8318ee3, 0x8fef0588c5bcb6e3,
           0xd6897a12b3032ebb, 0x95d6077e71758aa9, 0x7fffffffffffffff,
           0x7fffffffffffffff, 0xf2a6c3b1ad165f91, 0xfffffffffffffffd,
           0x270ae52d24ec30e1, 0xffffffffffffffff, 0xfffffffffffffffd);
  VLOAD_64(v16, 0x4e7d58e2560532a8, 0xffffffffffffffff, 0xfffffffffffffffd,
           0x3831c15a56f993ef, 0xb0a944eca6ec5c7f, 0xdccc20ad8318ee3,
           0x8fef0588c5bcb6e3, 0x2445255d8025bb9c, 0x9f879d9a3666cf99,
           0xaf0a0ce2d489b608, 0x7fffffffffffffff, 0xffffffffffffffff,
           0xfffffffffffffffd, 0x270ae52d24ec30e1, 0xffffffffffffffff,
           0xdf6c93e9c10b8cf1);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vv v2, v8, v16, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(8, v2, 0x2020);
#endif
}

void TEST_CASE3(void) {
  int64_t scalar = -3;
  VSET(16, e8, m4);
  VLOAD_8(v8, 0xfd, 0x1, 0x2, 0x6a, 0xfd, 0xfd, 0x7f, 0x7f, 0xfd, 0xcd, 0xfd,
          0x1, 0x1, 0x4d, 0xfd, 0xfd);
  VCLEAR(v2);
  asm volatile("vmseq.vx v2, v8, %[A]" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(9, v2, 0xc531);
  VSET(16, e16, m4);
  VLOAD_16(v8, 0xfffd, 0x73c8, 0x8000, 0x54d, 0xfffd, 0xfffd, 0xf5d, 0x9333,
           0xffff, 0x9eb5, 0xfffd, 0x13cf, 0x46bf, 0xbfbb, 0x147f, 0xfffd);
  VCLEAR(v2);
  asm volatile("vmseq.vx v2, v8, %[A]" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(10, v2, 0x8431);
  VSET(16, e32, m4);
  VLOAD_32(v8, 0xfffffffd, 0x73f04feb, 0xa905ebe7, 0x80000000, 0x0, 0xfffffffd,
           0xc5324bca, 0x5a887a19, 0x4a4d7b78, 0x0, 0xfffffffd, 0x6ae4de10,
           0xe0c0dafa, 0x7fffffff, 0x4a5b524c, 0xfffffffd);
  VCLEAR(v2);
  asm volatile("vmseq.vx v2, v8, %[A]" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(11, v2, 0x8421);
#if ELEN == 64
  VSET(16, e64, m4);
  VLOAD_64(v8, 0xfffffffffffffffd, 0xfffffffffffffffd, 0x823c4fdf6c23bf51, 0x0,
           0x8000000000000000, 0xfffffffffffffffd, 0x79b7fa02283da808,
           0x8ea5e8d8d5001b76, 0x43e465a41eb40584, 0x7fffffffffffffff,
           0xfffffffffffffffd, 0x8000000000000000, 0xcce4aab58c6e4907,
           0x9e8c5a7520f9b04d, 0x1, 0xfffffffffffffffd);
  VCLEAR(v2);
  asm volatile("vmseq.vx v2, v8, %[A]" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(12, v2, 0x8423);
#endif
}

void TEST_CASE4(void) {
  int64_t scalar = -3;
  VSET(16, e8, m4);
  VLOAD_8(v8, 0xfd, 0xfd, 0xda, 0x5b, 0x5c, 0xfd, 0xac, 0xff, 0xfd, 0x72, 0xfd,
          0x6, 0x92, 0xff, 0xff, 0xfd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vx v2, v8, %[A], v0.t" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(13, v2, 0x8022);
  VSET(16, e16, m4);
  VLOAD_16(v8, 0xfffd, 0x0, 0x85a1, 0xf37f, 0xfffd, 0xfffd, 0x1, 0xf61c, 0x7fff,
           0xe7a9, 0xfffd, 0xfffd, 0x94b1, 0xfffd, 0x43c8, 0xfffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vx v2, v8, %[A], v0.t" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(14, v2, 0xa820);
  VSET(16, e32, m4);
  VLOAD_32(v8, 0xfffffffd, 0x176fd4df, 0x7fffffff, 0xbde3da31, 0x5d0870c2,
           0xfffffffd, 0x7a65eca4, 0xbf3464d, 0xfffffffd, 0x2d570bfe,
           0xfffffffd, 0xd94180d7, 0xd50148ed, 0x85bbdc98, 0x44868357,
           0xfffffffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vx v2, v8, %[A], v0.t" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(15, v2, 0x8020);
#if ELEN == 64
  VSET(16, e64, m4);
  VLOAD_64(v8, 0xfffffffffffffffd, 0x7fffffffffffffff, 0xfffffffffffffffd,
           0xc4b5efd3ff939464, 0x8000000000000000, 0xfffffffffffffffd,
           0x3f5704b7b6783b3c, 0x7b2cf215b5660818, 0x6e8c3183a484ca7,
           0xfffffffffffffffd, 0xfffffffffffffffd, 0x7fffffffffffffff,
           0xb7280c6e79ea5276, 0x623413c9ade2960, 0x1, 0xfffffffffffffffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vx v2, v8, %[A], v0.t" ::[A] "r"(scalar));
  VSET(1, e16, m1);
  VCMP_U16(16, v2, 0x8220);
#endif
}

void TEST_CASE5(void) {
  VSET(16, e8, m4);
  VLOAD_8(v8, 0xfd, 0x1, 0x1, 0x1, 0x80, 0xfd, 0xb6, 0x6, 0x7f, 0xcf, 0xfd,
          0xff, 0x7f, 0x1d, 0x51, 0xfd);
  VCLEAR(v2);
  asm volatile("vmseq.vi v2, v8, -3");
  VSET(1, e16, m1);
  VCMP_U16(17, v2, 0x8421);
  VSET(16, e16, m4);
  VLOAD_16(v8, 0xfffd, 0x1621, 0x62bb, 0x93f8, 0x2a01, 0xfffd, 0x7b4b, 0xf287,
           0x8422, 0x17bd, 0xfffd, 0x82b4, 0x7fff, 0x7af6, 0xf040, 0xfffd);
  VCLEAR(v2);
  asm volatile("vmseq.vi v2, v8, -3");
  VSET(1, e16, m1);
  VCMP_U16(18, v2, 0x8421);
  VSET(16, e32, m4);
  VLOAD_32(v8, 0xfffffffd, 0xfffffffd, 0x65352f24, 0x1, 0x2b8219fd, 0xfffffffd,
           0x0, 0xf7913fa4, 0xfffffffd, 0x72eebb41, 0xfffffffd, 0x1, 0xfffffffd,
           0xfffffffd, 0x80000000, 0xfffffffd);
  VCLEAR(v2);
  asm volatile("vmseq.vi v2, v8, -3");
  VSET(1, e16, m1);
  VCMP_U16(19, v2, 0xb523);
#if ELEN == 64
  VSET(16, e64, m4);
  VLOAD_64(v8, 0xfffffffffffffffd, 0xd2c4f754772741c, 0x9c650ddceeaec149, 0x1,
           0x48bbe88ed06612b6, 0xfffffffffffffffd, 0x8000000000000000,
           0x2e6ee4b1baf37d0e, 0x7fffffffffffffff, 0xfffffffffffffffd,
           0xfffffffffffffffd, 0xfffffffffffffffd, 0x2423198ebb29914e,
           0xb9960b3b05a4196e, 0x40074bef8b4a501c, 0xfffffffffffffffd);
  VCLEAR(v2);
  asm volatile("vmseq.vi v2, v8, -3");
  VSET(1, e16, m1);
  VCMP_U16(20, v2, 0x8e21);
#endif
}

void TEST_CASE6(void) {
  VSET(16, e8, m4);
  VLOAD_8(v8, 0xfd, 0xb3, 0xfd, 0xfd, 0x7b, 0xfd, 0xfd, 0x3e, 0xc5, 0xfd, 0xfd,
          0x89, 0x0, 0xfd, 0x2d, 0xfd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vi v2, v8, -3, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(21, v2, 0xa228);
  VSET(16, e16, m4);
  VLOAD_16(v8, 0xfffd, 0x8816, 0x8000, 0xfffd, 0xfffd, 0xfffd, 0xfffd, 0x60a3,
           0x7fff, 0x9e72, 0xfffd, 0x1ad8, 0xfa63, 0x5b01, 0x5a59, 0xfffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vi v2, v8, -3, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(22, v2, 0x8028);
  VSET(16, e32, m4);
  VLOAD_32(v8, 0xfffffffd, 0xffffffff, 0x80000000, 0x270c3016, 0x0, 0xfffffffd,
           0xdea21f53, 0x0, 0x6485b90, 0x8fd93994, 0xfffffffd, 0x684b6e85,
           0xfffffffd, 0xfffffffd, 0xfffffffd, 0xfffffffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vi v2, v8, -3, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(23, v2, 0xa020);
#if ELEN == 64
  VSET(16, e64, m4);
  VLOAD_64(v8, 0xfffffffffffffffd, 0xffffffffffffffff, 0xa35023af46f18e9f,
           0x4199299c2d780368, 0xc18060b63adf4516, 0xfffffffffffffffd,
           0xdcdab413f30b641a, 0xe8b146545071a0d, 0x35d8822a23692617,
           0x3120a020bd797293, 0xfffffffffffffffd, 0x80da57478d953521,
           0x704bab3a45bef22e, 0x0, 0x48924927fdfd79cb, 0xfffffffffffffffd);
  VLOAD_8(v0, 0xaa, 0xaa);
  VCLEAR(v2);
  asm volatile("vmseq.vi v2, v8, -3, v0.t");
  VSET(1, e16, m1);
  VCMP_U16(24, v2, 0x8020);
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
  TEST_CASE5();
  TEST_CASE6();

  EXIT_CHECK();
}
