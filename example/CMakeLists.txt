cmake_minimum_required(VERSION 3.15)
project(example C)
include_directories(${CMAKE_SOURCE_DIR}/../strlib/lib)
link_directories(${CMAKE_SOURCE_DIR}/../strlib/lib)
set(CMAKE_C_STANDARD 99)

add_executable(example main.c)
target_link_libraries(example str)