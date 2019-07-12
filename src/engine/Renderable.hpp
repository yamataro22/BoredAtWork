#pragma once

#include <glm/glm.hpp>

struct Renderable
{
    float positionX;
    float positionY;
    float sizeX;
    float sizeY;
    float rotation;

    glm::mat4 GenerateObjectMatrix();
};



