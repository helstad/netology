cmake_minimum_required(VERSION 3.26)
project(static_lib)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE main.cpp)
set(SOURCE_LIB lib/Greeter.cpp)

add_library(greeter_lib STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})

target_link_libraries(main greeter_lib)
