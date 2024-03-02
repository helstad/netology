cmake_minimum_required(VERSION 3.20)
#set(CMAKE_C_COMPILER "C:\\Program Files\\llvm-mingw\\bin\\gcc.exe")
#set(CMAKE_CXX_COMPILER "C:\\Program Files\\llvm-mingw\\bin\\g++.exe")
set(CMAKE_CXX_STANDARD 17)
project(task_1)

set(PostgreSQL_ADDITIONAL_VERSIONS "16.2")

set(CMAKE_PREFIX_PATH "D:\\PostgreSQL\\16")
add_subdirectory("..\\..\\..\\Libpqxx" pqxx-build)

#find_package(libpqxx REQUIRED)
find_package(PostgreSQL REQUIRED)

add_executable(task_1 main.cpp DB/DB.cpp DB/DB.hpp)
target_compile_options(task_1 PRIVATE -std=c++17)
target_compile_features(task_1 PRIVATE cxx_std_17)

#target_link_libraries(task_1 PRIVATE pqxx pq)
target_link_libraries(task_1 pqxx)
