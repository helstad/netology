cmake_minimum_required(VERSION 3.26)
project(task_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(task_3 main.cpp
        figures/Figure.cpp
        figures/Figure.h
        Figures.h
        figures/Triangle.cpp
        figures/Triangle.h
        figures/RightAngledTriangle.cpp
        figures/RightAngledTriangle.h
        figures/IsoscelesTriangle.cpp
        figures/IsoscelesTriangle.h
        figures/EquilateralTriangle.cpp
        figures/EquilateralTriangle.h
        figures/Quadrangle.cpp
        figures/Quadrangle.h
        figures/Rectangle.cpp
        figures/Rectangle.h
        figures/Square.cpp
        figures/Square.h
        figures/Parallelogram.cpp
        figures/Parallelogram.h
        figures/Rhombus.cpp
        figures/Rhombus.h)
