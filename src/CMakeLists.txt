message(STATUS "Gathering project files")

file(GLOB_RECURSE FILE_MAIN "src/*.cpp")
include("${CMAKE_SOURCE_DIR}/src/engine/CMakeLists.txt")

message(STATUS "Linking project")

add_executable(BoredAtWork ${FILE_MAIN} ${ENGINE_CPP} src/GameState.cpp src/GameState.h src/Monster.cpp src/Monster.h src/Renderable.hpp src/FollowerMonster.cpp src/FollowerMonster.hpp)

target_link_libraries(BoredAtWork ${DEVIL_LIBRARY_1} ${DEVIL_LIBRARY_2} ${DEVIL_LIBRARY_3})
target_link_libraries(BoredAtWork ${GLEW_LIBRARY})
target_link_libraries(BoredAtWork ${GLFW3_LIBRARY})
target_link_libraries(BoredAtWork GL)

include_directories(src)

