cmake_minimum_required(VERSION 3.20)
project(ThreadSafe_Queue)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main)

target_source(main
	PRIVATE
		src/main.cc
		src/safe_queue.cc
		src/thread_pool.cc
)

target_include_directories(main
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)
