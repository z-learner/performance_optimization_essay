#include <math.h>
#include <omp.h>

#include <array>
#include <cstring>
#include <memory>
#include <thread>

#include "benchmark/benchmark.h"

#define THREAD_NUM 12

std::array<float, 1L << 26> data{};  // 64MB

constexpr static float func_a(float x) { return x * std::sqrt(x); }
constexpr static float func_b(float x) {
  return x * (x * x + 3.14 * x + 1 / (x + 1) + 42 / (2.718 - x));
}
constexpr static float func_c(float x) {
  return x * std::sqrt(x + 1) + std::sin(x) + std::cos(x);
}

static void calculate_parallel_a(benchmark::State& state) {
  omp_set_num_threads(THREAD_NUM);
  for (auto _ : state) {
#pragma omp parallel for
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] = func_a(static_cast<float>(index));
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(calculate_parallel_a);

static void calculate_parallel_b(benchmark::State& state) {
  omp_set_num_threads(THREAD_NUM);
  for (auto _ : state) {
#pragma omp parallel for
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] = func_b(static_cast<float>(index));
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(calculate_parallel_b);

static void calculate_parallel_c(benchmark::State& state) {
  omp_set_num_threads(THREAD_NUM);
  for (auto _ : state) {
#pragma omp parallel for
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] = func_c(static_cast<float>(index));
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(calculate_parallel_c);

BENCHMARK_MAIN();