cmake_minimum_required(VERSION 3.14)

set(CURSES_INCLUDE_DIR /opt/homebrew/opt/ncurses/include)
set(CURSES_LIBRARIES /opt/homebrew/opt/ncurses/lib/libncurses.dylib)

add_executable(radio
        radio_submit/radio.h
        radio_submit/radio.cpp
        radio_submit/main.cpp
)

target_include_directories(radio PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(radio PRIVATE ${CURSES_LIBRARIES})

set(CURSES_INCLUDE_DIR /opt/homebrew/opt/ncurses/include)
set(CURSES_LIBRARIES /opt/homebrew/opt/ncurses/lib/libncurses.dylib)

add_executable(fifteen_submit
        fifteen_submit/fifteen.h
        fifteen_submit/fifteen.cpp
        fifteen_submit/main.cpp
)

target_include_directories(fifteen_submit PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(fifteen_submit PRIVATE ${CURSES_LIBRARIES})

add_executable(statistics_submit
        statistics_submit/main.cpp
        statistics_submit/statistics.cpp
        statistics_submit/statistics.h
)