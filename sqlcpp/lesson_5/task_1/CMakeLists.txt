cmake_minimum_required(VERSION 3.20)
project(task_1)
set(CMAKE_CXX_STANDARD 17)

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

find_package(libpqxx REQUIRED)
find_package(PostgreSQL REQUIRED)

#target_compile_features(task_1 PRIVATE cxx_std_20)

add_executable(task_1 main.cpp)

target_link_libraries(task_1 PRIVATE pqxx pq)
