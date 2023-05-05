
cmake_minimum_required(VERSION 3.5)

project(The-Matrix-class)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.Coefficient_accessors 1.Coefficient-accessors.cpp)
add_executable(2.Resizing 2.Resizing.cpp)

