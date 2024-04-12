cmake_minimum_required(VERSION 3.16.3)
project(Shapes)

add_executable(shapes main.cpp)

target_sources(shapes PRIVATE
    line.cpp
    rectangle.cpp
    cube.cpp
    circle.cpp
    cylinder.cpp
)

target_include_directories(shapes PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
