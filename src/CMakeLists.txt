message(STATUS "Gathering project files")

file(GLOB_RECURSE FILE_MAIN "src/*.cpp")

message(STATUS "Linking project")

add_executable(BoredAtWork ${FILE_MAIN})

include_directories(src)

