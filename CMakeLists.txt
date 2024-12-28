cmake_minimum_required(VERSION 3.10)
project(untitled11)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled11 main.cpp calculator.cpp)
add_executable(tests test_calculator.cpp calculator.cpp)
