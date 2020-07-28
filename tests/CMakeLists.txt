## if build test is specified, we build the tests
if (BUILD_TEST)
    enable_testing()
    message("Build testing")
    find_package(doctest)
    file(GLOB_RECURSE TEST_SRC ${CMAKE_SOURCE_DIR}/tests/*.cpp)
    add_executable(test_MyProject ${TEST_SRC})
    target_include_directories(test_MyProject PUBLIC ${CMAKE_SOURCE_DIR})
    set_target_properties(test_MyProject PROPERTIES LINKER_LANGUAGE CXX)
    add_test(main test_MyProject)

    # standard compiler warnings
    include(../cmake/compiler_warnings.cmake)
    set_project_warnings(test_MyProject PRIVATE)
endif()