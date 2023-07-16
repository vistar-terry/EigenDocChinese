
cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME Sparse-matrix-manipulations)
project(${PROJECT_NAME})
# set(CMAKE_BUILD_TYPE "Release")
# add_definitions(-DEIGEN_NO_DEBUG)
add_compile_definitions(EIGEN_NO_DEBUG)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(1.First_example 1.First-example.cpp)
target_link_libraries(1.First_example PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

add_executable(2.SparseMatrix 2.SparseMatrix.cpp)
add_executable(3.Operators-functions 3.Operators-functions.cpp)
# target_link_libraries(3.Operators-functions PRIVATE Eigen3::Eigen)
