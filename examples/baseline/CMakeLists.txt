add_executable(baseline main.cpp)
target_include_directories(baseline PUBLIC ${CMAKE_SOURCE_DIR})
set_target_properties(baseline PROPERTIES LINKER_LANGUAGE CXX)