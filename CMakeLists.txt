cmake_minimum_required(VERSION 3.10)
project(NaTddExercises CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic )
add_executable(projekt main.cpp testClass.cpp RGB.cpp HSV.cpp)
