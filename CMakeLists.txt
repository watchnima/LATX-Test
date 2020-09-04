cmake_minimum_required(VERSION 3.10)

project(LATX-Test)

include_directories(include)

SET(CMAKE_C_FLAGS "-m32 -g -O0 -Wall")
add_subdirectory(generator)
add_subdirectory(tools)
add_subdirectory(unit-tests)

# distorm library
SET(CMAKE_C_FLAGS "-m32 -g -O2 -Wall")
file(GLOB DISTORM_SRCS distorm/src/*.c)
add_library(distorm3 STATIC ${DISTORM_SRCS})
