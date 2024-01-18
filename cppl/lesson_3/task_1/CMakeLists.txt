cmake_minimum_required(VERSION 3.27)
project(task_1)

set(CMAKE_CXX_STANDARD 17)

# add_executable(task_1 main.cpp)

add_subdirectory(../../../Catch2 Catch2-build)
add_executable(Test test_main.cpp List.cpp List.hpp)
target_link_libraries(Test PRIVATE Catch2::Catch2)