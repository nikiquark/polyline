cmake_minimum_required(VERSION 3.10)

project(Vector3 CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(./tests)

set(SOURCE_LIB Vector3.cpp)

add_library(Vector3 STATIC ${SOURCE_LIB})
