
cmake_minimum_required(VERSION 3.5)

project(Reductions-visitors-broadcasting)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.reduction 1.reduction.cpp) 
add_executable(2.norm 2.norm.cpp) 
add_executable(3.bool_reduction 3.bool_reduction.cpp) 
add_executable(4.visitors 4.visitors.cpp) 
add_executable(5.partial_reduction 5.partial_reduction.cpp) 
add_executable(6.broadcasting 6.broadcasting.cpp) 
add_executable(7.broadcasting_app 7.broadcasting_app.cpp) 

