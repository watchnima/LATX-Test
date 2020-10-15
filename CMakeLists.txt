cmake_minimum_required(VERSION 3.10)

project(LATX-Test)

# x86-insn-generator library
add_subdirectory(x86-insn-generator)

SET(srcdir ${CMAKE_CURRENT_SOURCE_DIR})
SET(CMAKE_C_FLAGS "-g -O0 -Wall -DHAVE_CONFIG_H")

include_directories(${srcdir}
                    ${srcdir}/x86-insn-generator
                    ${srcdir}/x86-insn-generator/include
                    ${srcdir}/x86-insn-generator/x86
                    ${srcdir}/x86-insn-generator/asm
                    ${srcdir}/include)
add_subdirectory(output)
add_subdirectory(unit-tests)
