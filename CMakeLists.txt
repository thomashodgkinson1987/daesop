cmake_minimum_required(VERSION 3.10)
project(daesop VERSION 0.87.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(src)

set(SOURCES
    src/convert.c
    src/daesop.c
    src/damap.c
    src/dasm.c
    src/dblocks.c
    src/dict.c
    src/dvar.c
    src/rentry.c
    src/utils.c
)

add_executable(daesop ${SOURCES})

install(TARGETS daesop RUNTIME DESTINATION bin)
