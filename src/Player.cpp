#include "Player.h"

Player::Player(std::string & p_name):m_name(p_name)
{

}

void Player::makeAMove(Renderable &newPos)
{
    m_position = newPos;
}
