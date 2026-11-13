# Spatz ISA tests

Vendored from pulp-platform/spatz's test suite (`sw/riscvTests/isa/rv64uv`; the adaptation notes are in `src/`) and extended for Konark. Each test runs on the Spatz core and prints `PASSED: <file>!` (`EXIT_CHECK`) when all its checks pass.

## Coverage

- Every vector instruction the Spatz decoder accepts, including the masked (`v0.t`) forms. Tests not from upstream (integer compares, `vadc`, `vmv_x_s`, `vfwadd_special`, ...) are generated with golden values from a Python model.
- Scalar FP on the Spatz core: the Snitch `fp*_scalar` tests, plus FP64 arithmetic, conversions, moves and FP loads and stores (`fp64_*`, `fp_*`).
- `fence.c`: ordering between Spatz memory operations and scalar loads.
- `invalid.c`: illegal instructions trap.

## Building

The platform builds each `src/*.c` into one ELF against its runtime: as C++, because the runtime headers use C++ default arguments; with `-DELEN=64` for a Spatz with FP64 elements; with `-Wno-c++11-narrowing`, because the `VLOAD` macro brace-initialises narrow types with wider literals; and with riscv-opcodes' `encoding.h` on the include path.

## Notes

- A trapped Spatz core restarts and the simulation still ends successfully, so a test has passed only if it prints its `PASSED:` line.
- The checks read vector results back with scalar loads. `VCMP` and `VMCMP` start with a `fence`, which waits for outstanding Spatz memory operations and store acknowledgements.
- FP results are compared bit-exactly and printed in hex: printing a float needs `fdiv.d`, and this Spatz has no divide or square-root unit (so there are no `vfdiv` or `vfsqrt` tests either).
