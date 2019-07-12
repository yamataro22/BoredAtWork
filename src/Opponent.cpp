
#include "Opponent.h"

Opponent::Opponent(Renderable & p_initialPosition) : m_position(p_initialPosition)
{

}

void Opponent::makeAMove(Renderable &p_playerPosition) {
    m_position.m_positionX++;
    m_position.m_positionY--;
}
