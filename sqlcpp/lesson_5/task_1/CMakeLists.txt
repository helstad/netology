cmake_minimum_required(VERSION 3.20)
project(task_1)
set(CMAKE_CXX_STANDARD 17)

set(PostgreSQL_ADDITIONAL_VERSIONS "16.2")

#set(CMAKE_PREFIX_PATH "D:\\_dev\\LIB\\libpqxx-7.9.0")
set(CMAKE_PREFIX_PATH "D:\\PostgreSQL\\16")
add_subdirectory("..\\..\\..\\Libpqxx" pqxx-build)

#find_package(libpqxx REQUIRED)
find_package(PostgreSQL REQUIRED)

add_executable(task_1 main.cpp)

target_compile_features(task_1 PRIVATE cxx_std_17)

#target_link_libraries(task_1 PRIVATE pqxx pq)
target_link_libraries(task_1 pqxx)
