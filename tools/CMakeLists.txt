file(GLOB TOOLS_SRCS *.c)

add_library(tools STATIC ${TOOLS_SRCS})
