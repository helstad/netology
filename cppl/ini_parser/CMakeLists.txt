cmake_minimum_required(VERSION 3.27)
project(ini_parser)

set(CMAKE_CXX_STANDARD 20)

add_executable(ini_parser main.cpp
    Parser.cpp
    Parser.hpp
)