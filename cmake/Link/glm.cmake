# Find needed libraries
message(STATUS "Looking for GLM...")
find_package(GLM REQUIRED)

message(STATUS "GLM include folder found: ${GLM_INCLUDE_DIR}")

include_directories(${GLM_INCLUDE_DIR})
