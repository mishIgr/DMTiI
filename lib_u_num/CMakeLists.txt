cmake_minimum_required(VERSION 3.25)
project(Lib)
add_library(
    u_num_lib
    u_num.cpp
    u_num.h tests_u_num.h
)
target_include_directories(
    u_num_lib PUBLIC
    {CMAKE_CURRENT_SOURCE_DIR}
)
