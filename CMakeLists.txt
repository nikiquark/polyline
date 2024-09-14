cmake_minimum_required(VERSION 3.10)

project(poissonsoft CXX)

set(CMAKE_CXX_STANDARD 23) 
set(SOURCE_EXE main.cpp)

enable_testing()

include_directories(./Vector3)
add_subdirectory(./Vector3)

include_directories(./Polyline)
add_subdirectory(./Polyline)

include_directories(./Solver)
add_subdirectory(./Solver)

add_executable(PolylineSolver ${SOURCE_EXE})
target_link_libraries(PolylineSolver Vector3 Polyline Solver)