#include "RandomMonster.hpp"

void RandomMonster::makeAMove(const std::shared_ptr<Renderable> player)
{
    auto dir = rand() % 4;

    switch(dir)
    {
        case 0:
        {
            m_positionX += m_speed;
        }
        case 1:
        {
            m_positionX -= m_speed;
        }
        case 2:
        {
            m_positionY += m_speed;
        }
        case 3:
        {
            m_positionY -= m_speed;
        }
    }
}

RandomMonster::RandomMonster(int xPos, int yPos) : Monster(xPos, yPos)
{

}