message(STATUS "Constructing engine")

file(GLOB_RECURSE ENGINE_CPP "src/engine/*.cpp")

include_directories(src/engine)

