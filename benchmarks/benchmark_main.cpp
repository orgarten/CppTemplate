//
// Created by ogarten on 06/05/2020.
//

#include <benchmark/benchmark.h>
#include <iostream>
#include <string>

int main(int argc, char **argv) {

  benchmark::Initialize(&argc, argv);
  if (benchmark::ReportUnrecognizedArguments(argc, argv))
    return 1;

  benchmark::RunSpecifiedBenchmarks();
}

static void BM_myProject(benchmark::State &state) {
  /*
   * init sequence
   */
  std::string s{};
  for (auto _ : state) {
    /*
     * actual stuff to benchmark
     */

    s += "fuck yeah ";
  }
  /*
   * tear down
   */
}
BENCHMARK(BM_myProject)->DenseRange(2, 4, 1)->Unit(benchmark::kMillisecond);
