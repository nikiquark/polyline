cmake_minimum_required(VERSION 3.10)
project(Solver)

set(SOURCE_LIB Solver.cpp)

add_subdirectory(./tests)

add_library(Solver STATIC ${SOURCE_LIB})

target_link_libraries(Solver PUBLIC Vector3 Polyline)