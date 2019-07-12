#include "Player.h"

constexpr unsigned MAX_HP = 30;

Player::Player(std::string & p_name):m_name(p_name), m_remainingHp(MAX_HP)
{

}

void Player::getHit(int p_hp)
{
    m_remainingHp -= p_hp;
}

std::shared_ptr<Renderable> Player::getHealthbarRenderable()
{
    auto healthbar = std::make_shared<Renderable>();
    if(m_remainingHp > 0)
    {
        healthbar->m_sizeX = healthbar->m_positionX = 2000 * m_remainingHp / 2 / MAX_HP;
        healthbar->m_sizeY = healthbar->m_positionY = 10;
    }
    return healthbar;
}
