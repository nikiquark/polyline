cmake_minimum_required(VERSION 3.10)
project(Polyline)

set(SOURCE_LIB PolylineParser.cpp)

add_library(Polyline STATIC ${SOURCE_LIB})