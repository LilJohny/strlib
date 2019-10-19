cmake_minimum_required(VERSION 3.15)
project(wraper)

set(CMAKE_CXX_STANDARD 14)

add_library(wrapper SHARED library.cpp library.h)
