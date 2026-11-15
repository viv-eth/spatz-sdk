# Spatz-SDK

The software layer for Snitch clusters with a [Spatz](https://github.com/pulp-platform/spatz) vector core, on top of [snitch-sdk](https://github.com/viv-eth/snitch-sdk). It holds what Spatz code needs beyond the Snitch runtime: the Spatz parameters, PACE setup, the handover of Spatz results to the other cores, and the Spatz ISA tests. Konark is the first cluster that uses it.

## Contents

| Path | Contents |
|---|---|
| `core/inc/spatz_cfg.h` | Spatz parameters from the cluster configuration, peak FMA rates, utilisation |
| `core/inc/spatz_pace.h` | `spatz_pace_on(blob)`, or `spatz_pace_enable()` and `spatz_pace_load(blob)`, and `spatz_pace_off()`, for PACE, the piecewise-polynomial unit behind `vfmul.vv` |
| `core/inc/spatz_sync.h` | `spatz_flag_publish()` on the Spatz core; `spatz_flag_ready()`, `spatz_flag_wait()` and `spatz_flag_clear()` on the other cores |
| `core/inc/spatz.h` | all of the above |
| `core/inc/spatz_team.h` | `snrt_is_spatz_core()` and `snrt_cluster_spatz_core_num()`; the platform's `snrt.h` includes it after snitch-sdk's `team.h` |
| `tests/isa/` | the Spatz ISA test suite |
| `tests/headers/` | a compile check of the headers, with an example `snitch_cluster_cfg.h` |

## Platform contract

The platform's `snitch_cluster_cfg.h`, generated from its cluster configuration, defines:

- `SNRT_CLUSTER_HAS_SPATZ` and, when it is 1, `SNRT_CLUSTER_SPATZ_CORE_IDX`, `SNRT_CLUSTER_SPATZ_VLEN_BITS`, `SNRT_CLUSTER_SPATZ_N_FPU`, `SNRT_CLUSTER_SPATZ_HAS_RVF` and `SNRT_CLUSTER_SPATZ_HAS_RVD`;
- `SNRT_BASE_HARTID`, `SNRT_TCDM_BANK_NUM` and `SNRT_TCDM_BANK_WIDTH`;
- optionally `SNRT_CLUSTER_SPATZ_PACE_CSR`, the PACE control register (0xBA0 if absent).

`spatz_sync.h` supports 64 TCDM banks of 8 B and a VLEN of at least 512 bits, and stops the build on any other cluster.

`scripts/check_headers.sh <llvm install>` compiles the headers as C and C++ against `tests/headers/snitch_cluster_cfg.h`.

## Rules for Spatz code

Each of these gives wrong results without any error. They were measured on the RTL of pulp-platform/spatz_vpu `smazzola/konark` (a35563d8) and on GVSoC's Spatz model.

1. The cluster barrier releases when the Spatz core arrives, not when its stores have landed. Hand results over with `spatz_flag_publish()` after the data stores, and `spatz_flag_wait()` or `spatz_flag_ready()` on the reader.
2. Never read back on the Spatz core: a scalar read-back deadlocks the RTL, and a vector read-back corrupts a later load.
3. A scalar register that feeds a vector instruction must stay unchanged until the vector unit has used it. GVSoC reads it when the instruction executes, and the RTL reads a store's address register long after the scalar core has moved on. Keep a vector instruction and its scalar operands in one `asm` block, and pass a computed value off the Spatz core with a scalar store and a `fence`.
4. A vector instruction right after a scalar load into its base register uses the register's old value. Put a scalar ALU instruction (`add rX, rX, zero`) between them.
5. Write `vsetvli`'s result to `x0` unless the code reads it: an unread `vl` variable can share its register with the next load's base address.
6. Memory operations with 8-bit elements (`vle8`, `vse8`, their strided and indexed forms, `vlm`, `vsm`, `vl1re8`, `vs1r`) access the wrong address on the RTL. GVSoC runs them correctly.
7. `vmerge` and the integer compares write zeros. Build selects from sign-bit masks (`vsra.vi 31`, `vand`, `vor`); `vmax.vx` and `vmin.vx` work.
8. Not decoded, so they trap: `vnsrl`, `vnsra`, `vnclip`, `vrgather`, `vcompress`, `vsext`, `vzext`. The Spatz core has no divide or square root: no `fdiv`, `fsqrt`, `vfdiv` or `vfsqrt`.
9. Strided and indexed loads and stores work on the RTL but abort in GVSoC.
10. When LMUL=1 instructions build a register group that an LMUL>1 instruction reads next, write the group's base register last.
11. In GVSoC, a `.vi` instruction does not wait for a load into its source register: after a load, use the `.vv` form.

## License

All code is licensed under Apache 2.0 (see LICENSE), except the tests in `tests/isa/` vendored from pulp-platform/spatz, which keep their Solderpad Hardware License 0.51 headers.
