CMAKE_MINIMUM_REQUIRED(VERSION 3.11.0)
PROJECT(MyProject)
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
IF (CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-std=c++17 -O3 -Wall -fPIC -funroll-loops -march=native)
ELSEIF (MSVC)
    # this currently works, but is not really the way to go..
    add_compile_options(/std:c++17 /Wall /arch:AVX)
ELSE ()
    add_compile_options(-std=c++17 -O3 -Wall -fPIC -funroll-loops -march=native)
ENDIF (CMAKE_COMPILER_IS_GNUCXX)


## Allows us the check whether a compiler accepts flags or not
INCLUDE(CheckCXXCompilerFlag)
## loads definitions for standard gnu install directories
INCLUDE(GNUInstallDirs)

###################################################################
# Handling options to find packages etc
###################################################################

# examplary use of option
IF (MYPROJECT_VAR1)
    #find_package(<somepackage> <version>)
ENDIF ()


###################################################################
# main libray target
###################################################################

add_library(myproject myproject/lib.h)
set_target_properties(myproject PROPERTIES LINKER_LANGUAGE CXX)

###################################################################
# Option dependent builds (e.g. testing, benchmarks, ...)
###################################################################

add_subdirectory(tests)
add_subdirectory(benchmarks)

###################################################################
# PACKAGING (create config files)
###################################################################

SET(MYPROJECT_VERSION_NUMBER 1.0.0)
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


