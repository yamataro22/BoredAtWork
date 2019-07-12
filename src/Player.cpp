#include "Player.h"

Player::Player(std::string & p_name):m_name(p_name), m_remainingHp(30)
{

}

void Player::getHit(int p_hp)
{
    m_remainingHp -= p_hp;
}
