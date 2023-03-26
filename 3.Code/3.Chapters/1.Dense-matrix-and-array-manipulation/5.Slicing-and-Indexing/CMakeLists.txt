
cmake_minimum_required(VERSION 3.5)

project(Slicing-Indexing)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(basic_slicing 1.Basic-slicing.cpp) 
add_executable(array_of_indices 2.Array-of-indices.cpp) 


