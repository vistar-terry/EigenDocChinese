
cmake_minimum_required(VERSION 3.5)

project(STL)
set(CMAKE_BUILD_TYPE "Release")

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.stl 1.stl.cpp)

