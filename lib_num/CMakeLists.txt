cmake_minimum_required(VERSION 3.25)
project(Lib)
add_library(
    num_lib
    num.cpp
    num.h tests_num.h
)
target_include_directories(
    num_lib PUBLIC
    {CMAKE_CURRENT_SOURCE_DIR}
)
