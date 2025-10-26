cmake_minimum_required(VERSION 4.0)
project(C++Suffering)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")

# Лабораторная работа 1
add_executable(lab01_task7 lab01/task7.cpp)