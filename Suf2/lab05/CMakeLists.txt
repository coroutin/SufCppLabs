cmake_minimum_required(VERSION 3.14)

# --- Статическая библиотека ---
add_library(FractionLib STATIC
        FractionLib/Fraction.cpp
        Indexer/Indexer.cpp
)
target_include_directories(FractionLib PUBLIC Indexer/)
target_include_directories(FractionLib PUBLIC FractionLib/)

# --- Google Test ---
include(FetchContent)
        FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

# --- Тесты ---
add_executable(FractionTests
        FractionUnitTest/FractionTest.cpp
)

target_link_libraries(FractionTests PRIVATE
        FractionLib
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(FractionTests)