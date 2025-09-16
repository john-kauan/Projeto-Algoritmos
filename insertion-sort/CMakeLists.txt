cmake_minimum_required(VERSION 4.0)
project(insertion-sort C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(insertion-sort src/main.c)

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    target_compile_options(insertion-sort PRIVATE -Wall -Wextra -pedantic)
endif()
