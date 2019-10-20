cmake_minimum_required(VERSION 3.13.4)
project(str C)
include_directories(${CMAKE_SOURCE_DIR}/lib)
link_directories(${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_C_STANDARD 99)

add_executable(example example/main.c lib/library.c lib/library.h)
target_link_libraries(example str)
add_library(str SHARED lib/library.c lib/library.h)