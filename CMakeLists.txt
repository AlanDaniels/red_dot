cmake_minimum_required(VERSION 3.30)
project(red_dot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(red_dot main.cpp
        main.hpp
        dot_collection.hpp
        dot_collection.cpp
        constants.hpp
        linear_lerp.hpp
        linear_lerp.cpp)
target_include_directories(red_dot PRIVATE "~/GitRepos/raylib/src")
target_link_directories(red_dot PRIVATE "~/GitRepos/raylib/src")
target_link_libraries(red_dot raylib)