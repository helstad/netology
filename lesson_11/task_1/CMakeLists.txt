cmake_minimum_required(VERSION 3.26)
project(StaticLibApp)

add_subdirectory(lib)
add_executable(Executable main.cpp)
target_link_libraries(Executable Library)