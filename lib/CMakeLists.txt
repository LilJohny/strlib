cmake_minimum_required(VERSION 3.15)
project(strlib C)

set(CMAKE_C_STANDARD 99)

add_library(strlib SHARED library.c library.h)