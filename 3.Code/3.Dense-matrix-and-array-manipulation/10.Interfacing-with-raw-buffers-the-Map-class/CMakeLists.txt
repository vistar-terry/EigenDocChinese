
cmake_minimum_required(VERSION 3.5)

project(Map)
set(CMAKE_BUILD_TYPE "Release")

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.map-variables 1.map-variables.cpp)
add_executable(2.using-map-variables 2.using-map-variables.cpp)
add_executable(3.change-mapped-array 3.change-mapped-array.cpp)
