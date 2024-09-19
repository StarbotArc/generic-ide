cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(generic-ide)

file(GLOB_RECURSE SOURCE_CODE RELATIVE ${CMAKE_SOURCE_DIR} "source/*.cpp")

add_executable(generic-ide ${SOURCE_CODE})
