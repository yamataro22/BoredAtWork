#include "GameState.h"

#include "GameInformer.hpp"
#include "Player.h"
#include <memory>
#include "time.h"

GameState::GameState(std::shared_ptr<GameInformer> p_informer): m_informer(std::move(p_informer))
{
    srand(time(NULL));
}

void GameState::initState(int p_opponentNb)
{
    m_player->setPosition(WIDTH/2,HEIGHT/2);

    for(int i = 0; i < p_opponentNb; i++)
    {
        auto l_positons = generateRandomPosition();
        m_monsters.push_back(std::make_shared<Opponent>(std::get<0>(l_positons), std::get<1>(l_positons)));
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
    return std::tuple<int, int>{rand() % WIDTH, rand() % HEIGHT};
}

void GameState::performMoves()
{
    for(auto& monster : m_monsters)
    {
        monster->makeAMove(m_player->m_positionX, m_player->m_positionY);
    }
}
