cmake_minimum_required(VERSION 3.27)
project(task_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(task_3 main.cpp
        SimpleVector/SimpleVector.hpp
        SimpleVector/SimpleVector.tpp
)
