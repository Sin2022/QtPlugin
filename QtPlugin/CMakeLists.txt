cmake_minimum_required(VERSION 3.26)
project(QtPlugin)

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CircleProgressBar)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Loading)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/WaterProgressBar)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ClockWidget)