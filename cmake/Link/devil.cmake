# Find needed libraries
message(STATUS "Looking for DevIL...")
find_package(DEVIL REQUIRED)

message(STATUS "DevIL library found: ${DEVIL_LIBRARY_1}")
message(STATUS "DevIL utilities found: ${DEVIL_LIBRARY_2}")
message(STATUS "DevIL UT library found: ${DEVIL_LIBRARY_3}")
message(STATUS "DevIL include folder found: ${DEVIL_INCLUDE_DIR}")

include_directories(${DEVIL_INCLUDE_DIR})
