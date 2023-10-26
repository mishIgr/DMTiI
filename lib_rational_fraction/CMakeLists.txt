cmake_minimum_required(VERSION 3.25)
project(Lib)
add_library(
    rational_fraction_lib
    rational_fraction.cpp
    rational_fraction.h tests_rational_fraction.h
)
target_include_directories(
    rational_fraction_lib PUBLIC
    {CMAKE_CURRENT_SOURCE_DIR}
)
