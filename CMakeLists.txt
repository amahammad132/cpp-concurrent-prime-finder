cmake_minimum_required(VERSION 3.16)
project(cppfastprime)

set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_CXX_STANDARD 20)

add_executable(cppfastprime main.cpp)
