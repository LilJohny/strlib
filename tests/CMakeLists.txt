cmake_minimum_required(VERSION 3.15)
project(example C)
include_directories(${CMAKE_SOURCE_DIR}/../lib)
link_directories(${CMAKE_SOURCE_DIR}/../lib/bin)
set(CMAKE_C_STANDARD 99)

add_executable(tests testing.c)
target_link_libraries(tests str)