#include <math.h>
#include <omp.h>

#include <array>
#include <cstring>
#include <memory>
#include <thread>

#include "benchmark/benchmark.h"

std::array<float, 1L << 26> data;  // 256M

static void fill(benchmark::State& state) {
  for (auto _ : state) {
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] = index;
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(fill);

static void fill_parallel(benchmark::State& state) {
  omp_set_num_threads(4);
  for (auto _ : state) {
#pragma omp parallel for
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] = index;
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(fill_parallel);

static void sine(benchmark::State& state) {
  for (auto _ : state) {
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] = std::sin(index);
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(sine);

static void sine_parallel(benchmark::State& state) {
  omp_set_num_threads(4);
  for (auto _ : state) {
#pragma omp parallel for
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] = std::sin(index);
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(sine_parallel);

BENCHMARK_MAIN();