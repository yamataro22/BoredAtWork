
#include "Opponent.h"


Opponent::Opponent(float p_posX, float p_posY)
{
    float m_positionX = p_posX;
    float m_positionY = p_posY;
}

void Opponent::makeAMove(int p_playerPosX, int p_playerPosY)
{
    m_positionY < p_playerPosY ? m_positionY++ : m_positionY--;
    m_positionX < p_playerPosX ? m_positionX++ : m_positionX--;
}
