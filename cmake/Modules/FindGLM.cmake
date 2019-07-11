FIND_PATH(GLM_INCLUDE_DIR
	NAMES glm/glm.hpp
	PATHS
    deps/include
    /usr/include
  DOC "The directory containing glm headers."
)

if(GLM_INCLUDE_DIR)
    set(${GLM_FOUND} 1)
endif(GLM_INCLUDE_DIR)

