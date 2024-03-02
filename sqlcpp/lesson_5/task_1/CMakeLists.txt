cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
project(task_1)

set(PostgreSQL_ADDITIONAL_VERSIONS "16.2")

set(CMAKE_PREFIX_PATH "D:\\PostgreSQL\\16")
add_subdirectory("..\\..\\..\\Libpqxx" pqxx-build)

#find_package(libpqxx REQUIRED)
find_package(PostgreSQL REQUIRED)

add_executable(task_1 main.cpp ControlDB.cpp ControlDB.hpp)
target_compile_options(task_1 PRIVATE -std=c++20)
target_compile_features(task_1 PRIVATE cxx_std_20)

target_link_libraries(task_1 pqxx)
