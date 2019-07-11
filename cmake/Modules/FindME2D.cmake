FIND_PATH(ME2D_INCLUDE_DIR
	NAME monich2d/MonichEngine.h
	PATHS
    deps/include
    /usr/include
  DOC "The directory containing MonichEngined2D include files."
)

FIND_LIBRARY(ME2D_LIBRARY
    NAME ME2D
    PATHS
    deps/lib
    /usr/lib
    DOC "MonichEngine2D compiled library."
)

if(ME2D_INCLUDE_DIR AND ME2D_LIBRARY)
    set(ME2D_FOUND 1)
endif(ME2D_INCLUDE_DIR AND ME2D_LIBRARY)



