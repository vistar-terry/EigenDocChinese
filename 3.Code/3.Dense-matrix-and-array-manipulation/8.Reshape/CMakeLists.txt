
cmake_minimum_required(VERSION 3.5)

project(Reshape)
set(CMAKE_BUILD_TYPE "Release")

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.reshape 1.reshape.cpp) 
add_executable(2.reshapeInPlace 2.reshapeInPlace.cpp) 

