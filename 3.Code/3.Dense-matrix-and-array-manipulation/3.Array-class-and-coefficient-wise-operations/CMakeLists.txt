
cmake_minimum_required(VERSION 3.5)

project(Matrix-vector-arithmetic)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.Accessing-values 1.Accessing-values.cpp)
add_executable(2.Addition-subtraction 2.Addition-subtraction.cpp)
add_executable(3.Array-multiplication 3.Array-multiplication.cpp)
add_executable(4.Other-coefficient-wise-operations 4.Other-coefficient-wise-operations.cpp)
add_executable(5.Converting-mat-to-arr 5.Converting-mat-to-arr.cpp)
add_executable(6.Converting-arr-to-mat 6.Converting-arr-to-mat.cpp)
