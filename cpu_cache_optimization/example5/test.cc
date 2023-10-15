#include <math.h>
#include <omp.h>

#include <cstring>
#include <memory>
#include <thread>
#include <vector>

#include "benchmark/benchmark.h"

std::vector<float> data(1L << 30);  // 1G

static void fetch_add_one(benchmark::State& state) {
  for (auto _ : state) {
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] += 1;
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(fetch_add_one);

static void fetch_add_one_parallel(benchmark::State& state) {
  omp_set_num_threads(4);
  for (auto _ : state) {
#pragma omp parallel for
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] += 1;
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(fetch_add_one_parallel);

BENCHMARK_MAIN();