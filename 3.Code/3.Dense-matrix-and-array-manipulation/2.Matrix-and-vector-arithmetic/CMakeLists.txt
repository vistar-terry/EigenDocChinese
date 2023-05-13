
cmake_minimum_required(VERSION 3.5)

project(Matrix-vector-arithmetic)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.Addition-subtraction 1.Addition-subtraction.cpp)
add_executable(2.Scalar-multiplication-division 2.Scalar-multiplication-division.cpp)
add_executable(3.Transposition-conjugation 3.Transposition-conjugation.cpp)
add_executable(4.Multiplication 4.Multiplication.cpp)
add_executable(5.Dot-product-cross-product 5.Dot-product-cross-product.cpp)
add_executable(6.Basic-arithmetic-reduction 6.Basic-arithmetic-reduction.cpp)
