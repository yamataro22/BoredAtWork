# Disable MS warnings for secure functions
add_definitions(-D_CRT_SECURE_NO_WARNINGS -DM2D_USE_CONSOLE)

# Set newest compiler version
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")

# Set modules path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Find needed libraries
include(cmake/Link/devil.cmake)
include(cmake/Link/glew.cmake)
include(cmake/Link/glfw3.cmake)
include(cmake/Link/glm.cmake)

