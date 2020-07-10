CMAKE_MINIMUM_REQUIRED(VERSION 3.11.0)
PROJECT(MyProject)

SET(MYPROJECT_VAR1 true CACHE BOOL "Boolean project variable")
SET(MYPROJECT_VAR2 "" CACHE STRING "string project variable")

SET(BUILD_TEST true CACHE BOOL "Build test cases")

# Compiler Flags
set(CMAKE_CXX_STANDARD 17)
IF (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++17 -O3 -Wall -fPIC -funroll-loops -march=native ${COVERAGE_FLAGS}")
ELSEIF (MSVC)
    # this currently works, but is not really the way to go..
    set(CMAKE_CXX_FLAGS "/std:c++17 /Wall /arch:AVX")
ELSE ()
    set(CMAKE_CXX_FLAGS "-std=c++17 -O3 -Wall -fPIC -funroll-loops -march=native -fno-finite-math-only -fno-signed-zeros -freciprocal-math -ffp-contract=fast")
ENDIF (CMAKE_COMPILER_IS_GNUCXX)


INCLUDE(CheckCXXCompilerFlag)
INCLUDE(GNUInstallDirs)

# examplary use of option
IF (MYPROJECT_VAR1)
    find_package(<somepackage> <version>)
ENDIF ()



SET(MYPROJECT_VERSION_NUMBER 20.2.1)
SET(MYPROJECT_VERSION_STRING ${MYPROJECT_VERSION_NUMBER})
SET(MYPROJECT_DEFINITIONS "")
SET(MYPROJECT_INCLUDE_DIR "${CMAKE_INSTALL_PREFIX}/include")
SET(MYPROJECT_ROOT_DIR ${CMAKE_INSTALL_PREFIX})

INCLUDE(CMakePackageConfigHelpers)

CONFIGURE_PACKAGE_CONFIG_FILE(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/MyProject.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/MyProjectConfig.cmake
        PATH_VARS MYPROJECT_INCLUDE_DIR MYPROJECT_ROOT_DIR
        INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/MyProject/cmake
        NO_CHECK_REQUIRED_COMPONENTS_MACRO)

WRITE_BASIC_PACKAGE_VERSION_FILE(MyProjectConfigVersion.cmake VERSION ${MYPROJECT_VERSION_NUMBER} COMPATIBILITY SameMajorVersion)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/MyProjectConfig.cmake ${CMAKE_CURRENT_BINARY_DIR}/MyProjectConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_DATADIR}/MyProject/cmake)
INSTALL(DIRECTORY MyProject DESTINATION include)

IF (BUILD_TEST)
    ENABLE_TESTING()
    FILE(GLOB_RECURSE TEST_SRC ${CMAKE_SOURCE_DIR}/test/*.cpp)
    ADD_EXECUTABLE(test_MyProject ${TEST_SRC})
    TARGET_INCLUDE_DIRECTORIES(test_MyProject PUBLIC ${CMAKE_SOURCE_DIR})
    SET_TARGET_PROPERTIES(test_b PROPERTIES LINKER_LANGUAGE CXX)
    ADD_TEST(main test_MyProject)
ENDIF()


