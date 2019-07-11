# Find needed libraries
message(STATUS "Looking for GLFW3...")
find_package(GLFW3 REQUIRED)

message(STATUS "GLFW3 library found: ${GLFW3_LIBRARY}")
message(STATUS "GLFW3 include folder found: ${GLFW3_INCLUDE_DIR}")

include_directories(${GLFW3_INCLUDE_DIR})
