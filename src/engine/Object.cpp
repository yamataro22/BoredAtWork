#include "Object.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>


glm::mat4 Object::PrepareModelMatrix(const glm::vec2& position, const float rotation, const glm::vec2& scale)
{
    using namespace glm;

    mat4 matrix;
    matrix = glm::scale(vec3(scale, 1)) * mat4(1);
	vec3 vertex = vec3(0, 0, 1);
	float d_2_r = M_PI / 180;
	matrix = rotate(rotation * d_2_r, vertex) * matrix;
	matrix = translate(vec3(position, 0)) * matrix;

	return matrix;
}
