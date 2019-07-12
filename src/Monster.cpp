
#include "Monster.h"
#include "time.h"

Monster::Monster(int p_posX, int p_posY)
{
    //@TODO implement proper scaling

    //auto scale = WINDOW_WIDTH /  WINDOW_HEIGHT;

    m_positionX = p_posX;
    m_positionY = p_posY;
    m_firePower = generateRandomFirepower();
    m_sizeX = 0.75 * m_firePower;
    m_sizeY = m_firePower;
    m_rotation = 0;
}

int Monster::generateRandomFirepower() {
    return rand() % MAX_SIZE + 10;
}

bool Monster::approachPosition(const std::shared_ptr<Renderable> p_positionToApproach)
{
    if(p_positionToApproach->m_positionX != m_positionX)
    {
        m_positionX < p_positionToApproach->m_positionX ? m_positionX++ : m_positionX--;
    }

    if(p_positionToApproach->m_positionY != m_positionY)
    {
        m_positionY < p_positionToApproach->m_positionY ? m_positionY++ : m_positionY--;
    }

    return didApprochedMob(p_positionToApproach);
}

bool Monster::didApprochedMob(const std::shared_ptr<Renderable> p_mobToApproach) {
    return p_mobToApproach->m_positionX == m_positionX and p_mobToApproach->m_positionY == m_positionY;
}

int Monster::getFirePower() const {
    return m_firePower;
}


