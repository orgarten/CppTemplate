//
// Created by ogarten on 06/05/2020.
//

#include <benchmark/benchmark.h>

int main(int argc, char **argv) {

  benchmark::Initialize(&argc, argv);
  if (benchmark::ReportUnrecognizedArguments(argc, argv))
    return 1;

  benchmark::RunSpecifiedBenchmarks();
}