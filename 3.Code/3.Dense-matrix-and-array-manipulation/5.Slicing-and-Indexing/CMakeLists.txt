cmake_minimum_required(VERSION 3.5)

project(Slicing-Indexing)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.basic_slicing 1.Basic-slicing.cpp)
add_executable(2.array_of_indices 2.Array-of-indices.cpp)
add_executable(3.Custom-index-list 3.Custom-index-list.cpp)
