#pragma once


struct Renderable
{
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

    void virtual makeAMove(int d_x, int d_y)
    {
        m_positionX += d_x;
        m_positionY += d_y;
    }

    void setPosition(int posX, int posY)
    {
        m_positionX = posX;
        m_positionY = posY;
    }
};