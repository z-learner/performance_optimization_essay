# FindBenchmark.cmake
# Locate Benchmark library

find_path(BENCHMARK_INCLUDE_DIR NAMES benchmark/benchmark.h)
find_library(BENCHMARK_LIBRARY NAMES benchmark)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(benchmark DEFAULT_MSG BENCHMARK_LIBRARY BENCHMARK_INCLUDE_DIR)

if (BENCHMARK_FOUND)
  set(BENCHMARK_LIBRARIES ${BENCHMARK_LIBRARY})
  set(BENCHMARK_INCLUDE_DIRS ${BENCHMARK_INCLUDE_DIR})
endif()

mark_as_advanced(BENCHMARK_LIBRARY BENCHMARK_INCLUDE_DIR)
