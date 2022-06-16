cmake_minimum_required(VERSION 3.17)
project(CArray C)

set(CMAKE_C_STANDARD 11)

add_executable(CArray main.c carray.h error.h)