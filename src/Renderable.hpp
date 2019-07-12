#pragma once


struct Renderable
{
    float m_positionX;
    float m_positionY;
    float m_sizeX;
    float m_sizeY;
    float m_rotation;

    Renderable(float p_x, float p_y, float p_sizeX, float p_sizeY, float p_rot):
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

    void makeAMove(float p_x, float p_y){}
};