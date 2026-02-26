cmake_minimum_required(VERSION 3.10)
project(daesop VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

set(SOURCES
    src/convert.cpp
    src/daesop.cpp
    src/damap.cpp
    src/dasm.cpp
    src/dblocks.cpp
    src/dict.cpp
    src/dvar.cpp
    src/rentry.cpp
    src/utils.cpp
)

add_executable(daesop ${SOURCES})

install(TARGETS daesop RUNTIME DESTINATION bin)
