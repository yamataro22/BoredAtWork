#include "Player.h"

Player::Player(std::string & p_name):m_name(p_name), m_remainingHp(30)
{

}

void Player::getHit(int p_hp)
{
    m_remainingHp -= p_hp;
}

std::shared_ptr<Renderable> Player::getHealthbarRenderable()
{
    auto healthbar = std::make_shared<Renderable>();
    healthbar->m_sizeX = healthbar->m_positionX = m_remainingHp / 2;
    healthbar->m_sizeY = healthbar->m_positionY = 10;
    return healthbar;
}
