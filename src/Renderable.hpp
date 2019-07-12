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

    Renderable(int p_x, int p_y, int p_sizeX, int p_sizeY, int p_rot):
             m_positionX(p_x),
             m_positionY(p_y),
             m_sizeX(p_sizeX),
             m_sizeY(p_sizeY),
             m_rotation(p_rot)
    { }

    Renderable():
            m_positionX(0),
            m_positionY(0),
            m_sizeX(0),
            m_sizeY(0),
            m_rotation(0)
    { }

    virtual bool approachPosition(const std::shared_ptr<Renderable>)
    {
        m_positionX += 1;
        m_positionY += 1;

        return false;
    }

    virtual void makeAMove(int dx, int dy)
    {
        m_positionX += dx;
        m_positionY += dy;
    }

    void setPosition(int posX, int posY)
    {
        m_positionX = posX;
        m_positionY = posY;
        m_sizeX = 50;
        m_sizeY = 50;
        m_rotation = 0;
    }

    void setPosition(int posX, int posY, int sizeX, int sizeY, int rot)
    {
        m_positionX = posX;
        m_positionY = posY;
        m_sizeX = sizeX;
        m_sizeY = sizeY;
        m_rotation = rot;
    }

    glm::mat4 createObjectMatrix()
    {
        using namespace glm;

        mat4 matrix = scale(vec3(m_sizeX, m_sizeY, 1)) * mat4(1);
        //rotation
        vec3 vertex = vec3(0, 0, 1);
        float d_2_r = M_PI / 180;
        matrix = rotate(m_rotation * d_2_r, vertex) * matrix;
        //transformation
        matrix = translate(vec3(m_positionX, m_positionY, 0)) * matrix;

        return matrix;
    }
};