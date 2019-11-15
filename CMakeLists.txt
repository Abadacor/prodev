cmake_minimum_required(VERSION 3.3)

project(prodev)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
add_executable(prodev ${SOURCE_FILES})
target_link_libraries(prodev Qt5::Widgets)

