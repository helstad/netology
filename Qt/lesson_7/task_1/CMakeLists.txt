cmake_minimum_required(VERSION 3.5)

project(PreGraphic VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(
    Qt6 COMPONENTS
    Widgets
    Concurrent
    Charts
    REQUIRED
)

include_directories(
    ${Qt6Widgets_INCLUDE_DIRS}
    ${Qt6Concurrent_INCLUDE_DIRS}
    ${Qt6Charts_INCLUDE_DIRS})

link_directories(
    ${Qt6Widgets_LIBRARY_DIRS}
    ${Qt6Concurrent_LIBRARY_DIRS}
    ${Qt6Charts_LIBRARY_DIRS})

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)


add_executable(PreGraphic
    ${PROJECT_SOURCES}
)


target_link_libraries(
    PreGraphic PRIVATE
    Qt6::Widgets
    Qt6::Concurrent
    Qt6::Charts
)

qt_finalize_executable(PreGraphic)
