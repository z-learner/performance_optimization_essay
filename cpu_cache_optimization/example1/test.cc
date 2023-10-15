#include <cstring>
#include <memory>
#include <thread>

#include "benchmark/benchmark.h"

static void WriteMemset(benchmark::State& state) {
  // Code inside this loop is measured repeatedly
  int a[10 * 1024];
  for (auto _ : state) {
    std::memset(a, 0, 10240);
  }
  benchmark::DoNotOptimize(a);
}
// Register the function as a benchmark
BENCHMARK(WriteMemset);

static void Write(benchmark::State& state) {
  // Code before the loop is not measured
  int a[10 * 1024];
  for (auto _ : state) {
    for (size_t index = 0; index < 10 * 1024; ++index) {
      a[index] = 0;
    }
  }
  benchmark::DoNotOptimize(a);
}
BENCHMARK(Write);

BENCHMARK_MAIN();