
cmake_minimum_required(VERSION 3.5)

project(Reshape)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(reshape reshape.cpp) 

