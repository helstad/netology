cmake_minimum_required(VERSION 3.26)
project(StaticApp)

set(CMAKE_CXX_STANDARD 17)

set(SRC main.cpp)
set(LIB lib/Greeter.cpp)

add_library(static_lib STATIC ${LIB})
add_executable(app ${SRC})
target_link_libraries(app static_lib)