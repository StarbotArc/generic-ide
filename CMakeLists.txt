cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(generic-ide)

# We'll be needing
#	OpenGL - for the core renderer of generic-ide.
#	GLFW (most recent) - for creating the window, and doing rendering.
#	Freetype - for loading TTFs and is a dependency for font rendering.

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Freetype REQUIRED)

# Using GLOB_RECURSE to find source files and those that are in subfolders,
# with configure depends to check if there are new sources.
file(GLOB_RECURSE SOURCE_CODE RELATIVE ${CMAKE_SOURCE_DIR} CONFIGURE_DEPENDS
	"source/*.cpp"
	"source/*/*.cpp"
)
list(FILTER SOURCE_CODE EXCLUDE REGEX "source/gfx/")

# This variable should be able to be adjusted to what renderer the user wants to build.
set(GIDE_RENDERER "gl3" "lgl" CACHE STRING "The type of renderer that will be used.")

# This is our testing environment.
make_directory("environment")

# This will create a symlink towards the resource directory in the binary directory.
file(CREATE_LINK ../resource ./resource SYMBOLIC)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_executable(generic-ide ${SOURCE_CODE} "source/gfx/renderer_${GIDE_RENDERER}.cpp")

target_link_libraries(generic-ide PUBLIC
	${OPENGL_LIBRARIES}
# Since GLFW is weird, we use glfw
	glfw
	${FREETYPE_LIBRARIES}
)
target_include_directories(generic-ide PUBLIC
	${OPENGL_INCLUDE_DIRS}
	${FREETYPE_INCLUDE_DIRS}
)
