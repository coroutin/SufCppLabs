cmake_minimum_required(VERSION 3.14)

# --- Статическая библиотека ---
add_library(LinearEquationLib STATIC
    LinearEquation.cpp
)
target_include_directories(LinearEquationLib PUBLIC .)

# --- Google Test ---
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

# --- Тесты ---
add_executable(LinearEquationTests
    GTests.cpp
)

target_link_libraries(LinearEquationTests PRIVATE
    LinearEquationLib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(LinearEquationTests)
