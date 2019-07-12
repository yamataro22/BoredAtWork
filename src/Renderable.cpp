#include "Renderable.hpp"

namespace
{
int nearx(const Renderable& r)
{
    return r.m_positionX - r.m_sizeX;
}

int farx(const Renderable& r)
{
    return r.m_positionX + r.m_sizeX;
}

int neary(const Renderable& r)
{
    return r.m_positionY - r.m_sizeY;
}

int fary(const Renderable& r)
{
    return r.m_positionY + r.m_sizeY;
}
}

Renderable::Renderable(int p_x, int p_y, int p_sizeX, int p_sizeY, int p_rot):
    m_positionX(p_x),
    m_positionY(p_y),
    m_sizeX(p_sizeX),
    m_sizeY(p_sizeY),
    m_rotation(p_rot)
{ }

Renderable::Renderable():
    m_positionX(0),
    m_positionY(0),
    m_sizeX(0),
    m_sizeY(0),
    m_rotation(0)
{ }

void Renderable::makeAMove(int dx, int dy)
{
    m_positionX += dx;
    m_positionY += dy;
}

void Renderable::setPosition(int posX, int posY)
{
    m_positionX = posX;
    m_positionY = posY;
    m_sizeX = 50;
    m_sizeY = 50;
    m_rotation = 0;
}

void Renderable::setPosition(int posX, int posY, int sizeX, int sizeY, int rot)
{
    m_positionX = posX;
    m_positionY = posY;
    m_sizeX = sizeX;
    m_sizeY = sizeY;
    m_rotation = rot;
}

glm::mat4 Renderable::createObjectMatrix()
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

bool Renderable::isColliding(const Renderable &other)
{
    const Renderable& me = *this;
    return nearx(me) < farx(other)
           and farx(me) > nearx(other)
           and neary(me) < fary(other)
           and fary(me) > neary(other);
}