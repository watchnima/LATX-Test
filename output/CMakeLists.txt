file(GLOB_RECURSE OUTPUT_SRCS *.c)

add_library(outputlib STATIC ${OUTPUT_SRCS})
