#include "Renderable.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#define _USE_MATH_DEFINES

#include <glm/gtx/transform.hpp>

#include <math.h>

glm::mat4 Renderable::GenerateObjectMatrix()
{
    using namespace glm;

    mat4 matrix;
    matrix = glm::scale(vec3(sizeX, sizeY, 1)) * mat4(1);
    vec3 vertex = vec3(0, 0, 1);
    float d_2_r = M_PI / 180;
    matrix = rotate(rotation * d_2_r, vertex) * matrix;
    matrix = translate(vec3(positionX, positionY, 0)) * matrix;

    return matrix;
}
