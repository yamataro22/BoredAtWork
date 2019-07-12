
#include "Monster.h"
#include "time.h"

Monster::Monster(int p_posX, int p_posY)
{
    //auto scale = WINDOW_WIDTH /  WINDOW_HEIGHT;

    m_positionX = p_posX;
    m_positionY = p_posY;
    m_firePower = generateRandomFirepower();
    m_sizeX = 0.75 * m_firePower;
    m_sizeY = m_firePower;
    m_rotation = 0;

    //m_speed form 0 to 10
    //max firepower form 10 to 80

    auto newSize = - m_firePower + MAX_SIZE;

    //@TODO kill myself

    m_speed = (((newSize - 10) * (10 - 1)) / (MAX_SIZE - 10)) + 1;
}

int Monster::generateRandomFirepower() {
    return rand() % MAX_SIZE + 10;
}

bool Monster::didApprochedMob(const std::shared_ptr<Renderable>& p_mobToApproach)
{
    return isColliding(*p_mobToApproach);
}

int Monster::getFirePower() const
{
    return m_firePower;
}

void Monster::makeAMove(const std::shared_ptr<Renderable> sharedPtr, std::vector<std::shared_ptr<Monster>> &others)
{
    int backupX = m_positionX;
    int backupY = m_positionY;

    makeAMove(std::move(sharedPtr));

    for(auto& other : others)
    {
        if(this != other.get() and isColliding(*other))
        {
            m_positionX = backupX;
            m_positionY = backupY;
            return;
        }
    }
}
