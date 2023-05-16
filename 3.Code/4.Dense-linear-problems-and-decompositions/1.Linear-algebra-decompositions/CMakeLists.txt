
cmake_minimum_required(VERSION 3.5)

project(Linear-algebra-decompositions)
# set(CMAKE_BUILD_TYPE "Release")
# add_definitions(-DEIGEN_NO_DEBUG)
add_compile_definitions(EIGEN_NO_DEBUG)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.Basic-linear-colPivHouseholderQr 1.Basic-linear-colPivHouseholderQr.cpp)
add_executable(2.Basic-linear-ldlt 2.Basic-linear-ldlt.cpp)
add_executable(3.Least-squares 3.Least-squares.cpp)
add_executable(4.Checking-matrix-singular 4.Checking-matrix-singular.cpp)
add_executable(5.Eigenvalues-eigenvectors 5.Eigenvalues-eigenvectors.cpp)
add_executable(6.Inverse-determinant 6.Inverse-determinant.cpp)
add_executable(7.Separating-computation-construction 7.Separating-computation-construction.cpp)
add_executable(8.Rank-revealing 8.Rank-revealing.cpp)
