cmake_minimum_required(VERSION 3.15...4.1)
project(red_dot)

project(red_dot
        VERSION 1.0
        DESCRIPTION "A simple click-the-dot game"
        LANGUAGES CXX)

IF(NOT DEFINED ENV{RAYLIB_INC})
    MESSAGE(FATAL_ERROR "You need to set the \"RAYLIB_INC\" environment variable.")
ENDIF()

IF(NOT DEFINED ENV{RAYLIB_DIR})
    MESSAGE(FATAL_ERROR "You need to set the \"RAYLIB_DIR\" environment variable.")
ENDIF()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(red_dot
        src/main.cpp
        src/main.hpp
        src/dot_collection.hpp
        src/dot_collection.cpp
        src/constants.hpp
        src/linear_lerp.hpp
        src/linear_lerp.cpp)

target_compile_options(red_dot PRIVATE -Wall -Wextra -Wshadow -Wswitch-default -Wswitch-enum -Wunreachable-code)
target_include_directories(red_dot PRIVATE $ENV{RAYLIB_INC})
target_link_directories(red_dot PRIVATE $ENV{RAYLIB_DIR})
target_link_libraries(red_dot raylib)