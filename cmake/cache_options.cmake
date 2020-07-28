option(MYPROJECT_VAR1 "Boolen project variable" ON)
set(MYPROJECT_VAR2 "" CACHE STRING "string project variable")

option(BUILD_TEST "Build test cases" ON)
option(BUILD_BENCHMARK "Build benchmarks cases" ON)
option(BUILD_EXAMPLES "Build examples" ON)

message("========================================")
message("= Configuring blazeRT:                 =")
message(" * Build test:      ${BUILD_TEST}")
message(" * Build benchmark: ${BUILD_BENCHMARK}")
message(" * Build examples:  ${BUILD_EXAMPLES}")
message("========================================")