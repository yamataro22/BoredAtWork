FIND_PATH(DEVIL_INCLUDE_DIR
	NAME GLFW/glfw3.h
	PATHS
    deps/include
    /usr/include
  DOC "The directory containing DevIL include files."
)

FIND_LIBRARY(DEVIL_LIBRARY_1
    NAMES IL
    PATHS
    deps/lib
    /usr/lib
    DOC "The DevIL compiled library."
)

FIND_LIBRARY(DEVIL_LIBRARY_2
    NAMES ILU
    PATHS
    deps/lib
    /usr/lib
    DOC "The DevIL utility library."
)

FIND_LIBRARY(DEVIL_LIBRARY_3
    NAMES ILUT
    PATHS
    deps/lib
    /usr/lib
    DOC "The DevIL UT library."
)

if(DEVIL_INCLUDE_DIR AND DEVIL_LIBRARY_1 AND DEVIL_LIBRARY_2 AND DEVIL_LIBRARY_3)
    set(${DEVIL_FOUND} 1)
endif(DEVIL_INCLUDE_DIR AND DEVIL_LIBRARY_1 AND DEVIL_LIBRARY_2 AND DEVIL_LIBRARY_3)

