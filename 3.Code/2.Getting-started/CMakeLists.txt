
cmake_minimum_required(VERSION 3.5)

project(Getting_started)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(1.first_program 1.A-simple-first-program.cpp) 
add_executable(2.Matrices-and-vectors 2.Matrices-and-vectors.cpp) 
add_executable(3.Matrices-and-vectors 3.Matrices-and-vectors.cpp) 


