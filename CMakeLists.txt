cmake_minimum_required(VERSION 4.0)
project(C++Suffering)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")

# Лабораторная работа 1
add_executable(lab01_task6 lab01/task6.cpp)
add_executable(lab01_task7 lab01/task7.cpp)
# Лабораторная работа 2
add_executable(lab02_task15 lab02/task15.cpp)
# Лабораторная работа 3
add_executable(lab03_task19 lab03/task19.cpp)
add_executable(lab03_task20 lab03/task20.cpp)
#Трэш
add_executable(trash sufTrash/trash.cpp)