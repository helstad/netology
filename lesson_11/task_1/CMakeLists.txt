cmake_minimum_required(VERSION 3.26)
project(StaticApp)

include_directories(lib)

add_executable(static_lib main.cpp)
add_subdirectory(lib)

target_link_libraries(static_lib static)