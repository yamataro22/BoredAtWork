
#include "Monster.h"


Monster::Monster(int p_posX, int p_posY)
{
    //@TODO implement proper scaling

    m_positionX = p_posX;
    m_positionY = p_posY;
    m_sizeX = SIZE - 25;
    m_sizeY = SIZE;
    m_rotation = 0;
}

bool Monster::approachAnotherMob(const std::shared_ptr<Renderable> p_mobToApproach)
{
    if(p_mobToApproach->m_positionX != m_positionX)
    {
        m_positionX < p_mobToApproach->m_positionX ? m_positionX++ : m_positionX--;
    }

    if(p_mobToApproach->m_positionY != m_positionY)
    {
        m_positionY < p_mobToApproach->m_positionY ? m_positionY++ : m_positionY--;
    }

    return didApprochedMob(p_mobToApproach);
}

bool Monster::didApprochedMob(const std::shared_ptr<Renderable> p_mobToApproach) {
    return p_mobToApproach->m_positionX == m_positionX and p_mobToApproach->m_positionY == m_positionY;
}
