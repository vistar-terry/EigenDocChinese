cmake_minimum_required(VERSION 3.5)

project(Block-operations)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.Using-block-operations 1.Using-block-operations.cpp)
add_executable(2.Columns-rows 2.Columns-rows.cpp)
add_executable(3.Corner-related-operations 3.Corner-related-operations.cpp)
add_executable(4.Block-operations-for-vectors 4.Block-operations-for-vectors.cpp)

