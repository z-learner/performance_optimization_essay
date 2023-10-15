#include <math.h>
#include <omp.h>

#include <cstring>
#include <memory>
#include <thread>
#include <vector>

#include "benchmark/benchmark.h"

std::vector<float> data(1L << 30);

static void write(benchmark::State& state) {
  for (auto _ : state) {
    for (size_t index = 0; index < data.size(); ++index) {
      data[index] = 1;
    }
  }
  benchmark::DoNotOptimize(data);
}
BENCHMARK(write);

BENCHMARK_MAIN();