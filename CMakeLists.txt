cmake_minimum_required(VERSION 4.0)
project(C++Suffering)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")

#=========================
# Suffering 1 – The Basics
#=========================

# Лабораторная работа 1
add_subdirectory(Suf1/lab01)

# Лабораторная работа 2
add_subdirectory(Suf1/lab02)

# Лабораторная работа 3
add_subdirectory(Suf1/lab03)

#Лабораторная работа 4
add_subdirectory(Suf1/lab04)

#Лабораторная работа 5
add_subdirectory(Suf1/lab05)

#Лабораторная работа 6
add_subdirectory(Suf1/lab06)

#Лабораторная работа 7
add_subdirectory(Suf1/lab07)

#Лабораторная работа 8
add_subdirectory(Suf1/lab08)

#Лабораторная работа 9
add_subdirectory(Suf1/lab09)

#Лабораторная работа 10
add_subdirectory(Suf1/lab10)

#Лабораторная работа 11
add_subdirectory(Suf1/lab11)

#Лабораторная работа 12
add_subdirectory(Suf1/lab12)

#Лабораторная работа 13
add_subdirectory(Suf1/lab13)

#=================================
#Suffering 2 – The Object Oriented
#=================================

#Лабораторная работа 1
add_subdirectory(Suf2/lab01)

#Лабораторная работа 2
add_subdirectory(Suf2/lab02)

#Лабораторная работа 3
add_subdirectory(Suf2/lab03)

#Лабораторная работа 4
add_subdirectory(Suf2/lab04)

#Лабораторная работа 5
add_subdirectory(Suf2/lab05)

#Трэш
set(CURSES_INCLUDE_DIR /opt/homebrew/opt/ncurses/include)
set(CURSES_LIBRARIES /opt/homebrew/opt/ncurses/lib/libncurses.dylib)

add_executable(trash trash.cpp)

target_include_directories(trash PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(trash PRIVATE ${CURSES_LIBRARIES})