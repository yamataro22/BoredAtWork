#include "GameState.h"

#include "GameInformer.hpp"
#include "Player.h"
#include <memory>
#include "time.h"
#include <vector>
#include <algorithm>

GameState::GameState(std::shared_ptr<GameInformer> p_informer): m_informer(std::move(p_informer))
{
    srand(time(NULL));
}

void GameState::initState(int p_opponentNb)
{
    m_player->setPosition(WIDTH/2,HEIGHT/2);

    for(int i = 0; i < p_opponentNb; i++)
    {
        auto l_positions = generateRandomPosition();
        m_monsters.push_back(std::make_shared<Monster>(std::get<0>(l_positions), std::get<1>(l_positions)));
    }
}

void GameState::addPlayer(std::string p_playerName)
{
    m_player = std::make_shared<Player>(p_playerName);
}

void GameState::updateState()
{
    performMoves();

    m_informer->defineObject(m_player);

    for(const auto& monster : m_monsters)
    {
        m_informer->defineObject(monster);
    }
}

std::tuple<int, int> GameState::generateRandomPosition()
{
    return std::tuple<int, int>{generatePos(), generatePos()};
}

void GameState::performMoves()
{
    auto l_monster = std::begin(m_monsters);

    while (l_monster != std::end(m_monsters))
    {
        if((*l_monster)->approachAnotherMob(m_player))
        {
            m_player->getHit((*l_monster)->FIRE_POWER);
            l_monster = m_monsters.erase(l_monster);
        }
        else
            ++l_monster;
    }


    for(auto& monster : m_monsters)
    {
        if(monster->approachAnotherMob(m_player))
        {
            m_player->getHit(monster->FIRE_POWER);
        }
    }
}

int GameState::generatePos()
{
    auto l_posX = rand() % WIDTH;
    while(not isPositionOk(l_posX))
    {
        l_posX = rand() % WIDTH;
    }
    return l_posX;
}

bool GameState::isPositionOk(int p_newPos)
{
    return    p_newPos < m_player->m_positionX - SAFE_ZONE
           or p_newPos > m_player->m_positionY + SAFE_ZONE;
}

void GameState::inputChanged(const RegisteredKeyState & keyState)
{
    m_registeredKeyState = keyState;
}
