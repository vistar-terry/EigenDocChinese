
cmake_minimum_required(VERSION 3.5)

project(basic_slicing)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(basic_slicing Basic-slicing.cpp) 


