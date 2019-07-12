
#include "Monster.h"


Monster::Monster(float p_posX, float p_posY)
{
    float m_positionX = p_posX;
    float m_positionY = p_posY;
}

bool Monster::approchAnotherMob(const std::shared_ptr<Renderable> p_mobToApproach)
{
    if(p_mobToApproach->m_positionX != m_positionX)
    {
        m_positionY < p_mobToApproach->m_positionX ? m_positionY++ : m_positionY--;
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
