cmake_minimum_required(VERSION 3.5)

project(Advanced-initialization)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.Comma-initializer 1.Comma-initializer.cpp)
add_executable(2.Special-matrices-arrays 2.Special-matrices-arrays.cpp)
add_executable(3.Temporary-objects 3.Temporary-objects.cpp)

