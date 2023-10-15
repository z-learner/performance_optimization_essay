#include <math.h>
#include <omp.h>

#include <array>
#include <cstring>
#include <memory>
#include <thread>

#include "benchmark/benchmark.h"

std::array<float, 1L << 26> data{};  // 64MB

static void fetch_add_one(benchmark::State& state) {
  for (auto _ : state) {
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] = 1;
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(fetch_add_one);

template <typename T>
static T fun(T t) {
  return t * (t * t + 3.14 * t + 1 / (t + 1) + 42 / (2.718 - t));
}

static void calculate(benchmark::State& state) {
  for (auto _ : state) {
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] = fun(static_cast<float>(index));
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(calculate);

static void calculate_parallel(benchmark::State& state) {
  omp_set_num_threads(8);
  for (auto _ : state) {
#pragma omp parallel for
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] = fun(static_cast<float>(index));
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(calculate_parallel);

BENCHMARK_MAIN();