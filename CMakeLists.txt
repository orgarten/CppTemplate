cmake_minimum_required(VERSION 3.11.0)
project(MyProject)
enable_language(CXX)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

###################################################################
# define options which can be set by user
###################################################################

include(cmake/cache_options.cmake)

###################################################################
# Setting compiler flags regarding optimization etc for gcc, msvc, clang
###################################################################
# Compiler Flags
set(CMAKE_CXX_STANDARD 17)
if (CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-std=c++17 -O3 -Wall -fPIC -funroll-loops -march=native)
elseif (MSVC)
    # this currently works, but is not really the way to go..
    add_compile_options(/std:c++17 /Wall /arch:AVX)
else ()
    add_compile_options(-std=c++17 -O3 -Wall -fPIC -funroll-loops -march=native)
endif (CMAKE_COMPILER_IS_GNUCXX)


## Allows us the check whether a compiler accepts flags or not
include(CheckCXXCompilerFlag)
## loads definitions for standard gnu install directories
include(GNUInstallDirs)

###################################################################
# Handling options to find packages etc
###################################################################

# examplary use of option
if (MYPROJECT_VAR1)
    #find_package(<somepackage> <version>)
endif ()


###################################################################
# main libray target
###################################################################

add_library(myproject INTERFACE )
file(GLOB_RECURES SRC_FILES myproject/*.h)
target_sources(myproject INTERFACE ${SRC_FILES})
target_include_directories(myproject INTERFACE myproject/)
include(cmake/compiler_warnings.cmake)
set_project_warnings(myproject INTERFACE)

###################################################################
# Option dependent builds (e.g. testing, benchmarks, ...)
###################################################################

add_subdirectory(benchmarks)
add_subdirectory(examples)
if(BUILD_TEST)
    enable_testing()
    add_subdirectory(tests)
endif()


###################################################################
# PACKAGING (create config files)
###################################################################

set(MYPROJECT_VERSION_NUMBER 1.0.0)
set(MYPROJECT_VERSION_STRING ${MYPROJECT_VERSION_NUMBER})
set(MYPROJECT_DEFINITIONS "")
set(MYPROJECT_INCLUDE_DIR "${CMAKE_INSTALL_PREFIX}/include")
set(MYPROJECT_ROOT_DIR ${CMAKE_INSTALL_PREFIX})

include(CMakePackageConfigHelpers)

configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/MyProject.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/MyProjectConfig.cmake
        PATH_VARS MYPROJECT_INCLUDE_DIR MYPROJECT_ROOT_DIR
        INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/MyProject/cmake
        NO_CHECK_REQUIRED_COMPONENTS_MACRO)

write_basic_package_version_file(MyProjectConfigVersion.cmake VERSION ${MYPROJECT_VERSION_NUMBER} COMPATIBILITY SameMajorVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/MyProjectConfig.cmake ${CMAKE_CURRENT_BINARY_DIR}/MyProjectConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_DATADIR}/MyProject/cmake)
install(DIRECTORY MyProject DESTINATION include)


