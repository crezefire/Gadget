# Gadgets

A library for common utilities.

## Getting Started
- Run `get_latest_deps.sh` to pull down 3rd party dependencies from Github. Use `[-s|--ssh]` to use ssh.
- `mkdir build && cd build`
- `cmake -G "Your Favourite Build Type" ../` Supported options are (OFF by default): `-D<OPTION>=ON`
  - GADGET_ENABLE_BENCHMARKING - Creates sample Google Benchmark project
  - GADGET_ENABLE_TESTING - Creats sample Google Test project
  - GADGET_USE_LIBCXX - Sets `-stdlib=libc++` for Clang only
