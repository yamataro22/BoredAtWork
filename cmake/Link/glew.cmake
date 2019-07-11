# Find needed libraries
message(STATUS "Looking for GLEW...")
find_package(GLEW REQUIRED)

message(STATUS "GLEW library found: ${GLEW_LIBRARY}")
message(STATUS "GLEW include folder found: ${GLEW_INCLUDE_DIR}")

include_directories(${GLEW_INCLUDE_DIR})
