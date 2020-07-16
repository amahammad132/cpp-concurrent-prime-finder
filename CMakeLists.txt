#cmake_minimum_required(VERSION 3.16)
#project(cppfastprime)
#
#set(GCC_COVERAGE_COMPILE_FLAGS "-pthread -Ofast -funroll-loops")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
#set(CMAKE_CXX_STANDARD 20)
#
#add_executable(cppfastprime main.cpp useful_functions.h)

cmake_minimum_required(VERSION 3.5)
project(cppfastprime)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread -Ofast -funroll-loops")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp qt_parts.h)
find_package(Qt5Widgets REQUIRED)

add_executable(cppfastprime ${SOURCE_FILES})

target_link_libraries(cppfastprime Qt5::Widgets)