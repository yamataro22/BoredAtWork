FIND_PATH(GLFW3_INCLUDE_DIR
	NAME GLFW/glfw3.h
	PATHS
    deps/include
    /usr/include
  DOC "The directory containing GLFW3 include files."
)

FIND_LIBRARY(GLFW3_LIBRARY
    NAME glfw
    PATHS
    deps/lib
    /usr/lib
    DOC "The GLFW3 compiled library."
)

if(GLFW3_INCLUDE_DIR AND GLFW3_LIBRARY)
    set(${GLFW3_FOUND} 1)
endif(GLFW3_INCLUDE_DIR AND GLFW3_LIBRARY)

