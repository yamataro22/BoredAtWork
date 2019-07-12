#include "FollowerMonster.hpp"

void FollowerMonster::makeAMove(const std::shared_ptr<Renderable> sharedPtr)
{
    approachPosition(std::move(sharedPtr));
}

FollowerMonster::FollowerMonster(int xPos, int yPos) : Monster(xPos, yPos)
{

}

void FollowerMonster::approachPosition(const std::shared_ptr<Renderable> p_positionToApproach)
{
    if(p_positionToApproach->m_positionX != m_positionX)
    {
        m_positionX < p_positionToApproach->m_positionX ? m_positionX += m_speed : m_positionX -= m_speed;
    }

    if(p_positionToApproach->m_positionY != m_positionY)
    {
        m_positionY < p_positionToApproach->m_positionY ? m_positionY += m_speed  : m_positionY -= m_speed;
    }
}