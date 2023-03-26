
cmake_minimum_required(VERSION 3.5)

project(Reductions-visitors-broadcasting)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(reduction 1.reduction.cpp) 
add_executable(norm 2.norm.cpp) 


