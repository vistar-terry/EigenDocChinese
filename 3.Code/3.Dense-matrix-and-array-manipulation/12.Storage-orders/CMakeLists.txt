
cmake_minimum_required(VERSION 3.5)

project(Storage-orders)
# set(CMAKE_BUILD_TYPE "Release")
# add_definitions(-DEIGEN_NO_DEBUG)
add_compile_definitions(EIGEN_NO_DEBUG)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.Column-major-row-major 1.Column-major-row-major.cpp)
