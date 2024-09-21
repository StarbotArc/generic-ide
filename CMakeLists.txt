cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(generic-ide)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Using GLOB_RECURSE to find source files and those that are in subfolders,
# with configure depends to check if there are new sources.
file(GLOB_RECURSE SOURCE_CODE RELATIVE ${CMAKE_SOURCE_DIR} CONFIGURE_DEPENDS
	"source/*.cpp"
	"source/gfx/*.cpp"
)

message(${SOURCE_CODE})

add_executable(generic-ide ${SOURCE_CODE})

target_link_libraries(generic-ide PUBLIC OpenGL glfw)
