
cmake_minimum_required(VERSION 3.5)

project(Aliasing)
# set(CMAKE_BUILD_TYPE "Release")
# add_definitions(-DEIGEN_NO_DEBUG)
add_compile_definitions(EIGEN_NO_DEBUG)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.examples 1.examples.cpp)
add_executable(2.Resolving-assertion 2.Resolving-assertion.cpp)
add_executable(3.Aliasing-component-wise 3.Aliasing-component-wise.cpp)
add_executable(4.Aliasing-matrix-multiplication 4.Aliasing-matrix-multiplication.cpp)
