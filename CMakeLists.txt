cmake_minimum_required(VERSION 3.29)
project(untitled11)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled11 main.cpp calculator.cpp calculator.h)
add_executable(tests test_calculator.cpp calculator.cpp
        main.cpp)
