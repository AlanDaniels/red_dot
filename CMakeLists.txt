cmake_minimum_required(VERSION 3.30)
project(red_dot)

IF(NOT DEFINED ENV{RAYLIB_INC})
    MESSAGE(FATAL_ERROR "You need to set the \"RAYLIB_INC\" environment variable.")
ENDIF()

IF(NOT DEFINED ENV{RAYLIB_DIR})
    MESSAGE(FATAL_ERROR "You need to set the \"RAYLIB_DIR\" environment variable.")
ENDIF()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(red_dot main.cpp
        main.hpp
        dot_collection.hpp
        dot_collection.cpp
        constants.hpp
        linear_lerp.hpp
        linear_lerp.cpp)
target_include_directories(red_dot PRIVATE $ENV{RAYLIB_INC})
target_link_directories(red_dot PRIVATE $ENV{RAYLIB_DIR})
target_link_libraries(red_dot raylib)