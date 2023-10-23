cmake_minimum_required(VERSION 3.26)
project(dynamic_library)

set(CMAKE_CXX_STANDARD 17)
set(source_dll Leaver.h Leaver.cpp)

add_library(dynamic SHARED ${source_dll})
add_executable(task_2 main.cpp)

target_link_libraries(task_2 dynamic)
