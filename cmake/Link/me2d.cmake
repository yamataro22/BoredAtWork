# Find needed libraries
message(STATUS "Looking for MonichEngine2D files...")
find_package(ME2D REQUIRED)

message(STATUS "MonichEngine2D library found: ${ME2D_LIBRARY}")
message(STATUS "MonichEngine2D include folder found: ${ME2D_INCLUDE_DIR}")

include_directories(${ME2D_INCLUDE_DIR})

