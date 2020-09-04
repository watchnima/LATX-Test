file(GLOB_RECURSE GENERATOR_SRCS *.c)

add_library(generator STATIC ${GENERATOR_SRCS})
