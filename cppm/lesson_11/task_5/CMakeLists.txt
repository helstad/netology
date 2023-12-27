cmake_minimum_required(VERSION 3.26)
project(task_5)

set(CMAKE_CXX_STANDARD 17)

set(source_dll figures/ExportImport.h
        figures/EquilateralTriangle.cpp
        figures/Triangle.cpp
        figures/Figure.cpp
        figures/IsoscelesTriangle.cpp
        figures/Parallelogram.cpp
        figures/Quadrangle.cpp
        figures/Rectangle.cpp
        figures/Rhombus.cpp
        figures/RightAngledTriangle.cpp
        figures/Square.cpp)

add_library(figures SHARED ${source_dll})
add_executable(task_5 main.cpp)

target_link_libraries(task_5 figures)