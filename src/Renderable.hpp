#pragma once

#define _USE_MATH_DEFINES
#define GLM_ENABLE_EXPERIMENTAL
#include <memory>


#include <glm/gtx/transform.hpp>

#include <math.h>

struct Renderable
{
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 1600;

    int m_positionX;
    int m_positionY;
    int m_sizeX;
    int m_sizeY;
    int m_rotation;

    Renderable(int p_x, int p_y, int p_sizeX, int p_sizeY, int p_rot);

    Renderable();

    virtual void makeAMove(int dx, int dy);

    void setPosition(int posX, int posY);
    void setPosition(int posX, int posY, int sizeX, int sizeY, int rot);

    glm::mat4 createObjectMatrix();
    bool isColliding(const Renderable &other);

};