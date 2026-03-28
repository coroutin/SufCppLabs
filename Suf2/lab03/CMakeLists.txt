cmake_minimum_required(VERSION 3.14)

set(CURSES_INCLUDE_DIR /opt/homebrew/opt/ncurses/include)
set(CURSES_LIBRARIES /opt/homebrew/opt/ncurses/lib/libncurses.dylib)

add_executable(fifteen
        Fifteen/fifteen.h
        Fifteen/fifteen.cpp
        Fifteen/main.cpp
)

target_include_directories(fifteen PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(fifteen PRIVATE ${CURSES_LIBRARIES})