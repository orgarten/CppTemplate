## If BUILD_BENCHMARKS is true, we try to find google benchmark, collect the sources and add the corresponding target.

IF (BUILD_BENCHMARK)
    # find google benchmark
    FIND_PACKAGE(benchmark)
    file(GLOB_RECURSE BENCHMARK_SRC ${CMAKE_SOURCE_DIR}/benchmarks/*)
    add_executable(benchmark_MyProject ${BENCHMARK_SRC})
    TARGET_INCLUDE_DIRECTORIES(benchmark_MyProject PUBLIC ${CMAKE_SOURCE_DIR})
    target_link_libraries(benchmark_MyProject PUBLIC benchmark::benchmark)
ENDIF ()