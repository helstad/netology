cmake_minimum_required(VERSION 3.26)
project(lib)
set(source
        Greeter.h Greeter.cpp)
add_library(static STATIC ${source})