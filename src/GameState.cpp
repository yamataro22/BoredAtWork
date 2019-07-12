#include "GameState.h"

#include "GameInformer.hpp"
#include "Player.h"
#include <memory>
#include "time.h"

GameState::GameState(std::shared_ptr<GameInformer> p_informer): m_informer(std::move(p_informer))
{
    srand(time(NULL));
    initState(10);
}

void GameState::initState(int p_opponentNb)
{
    Renderable l_initialPositon{1000,1000,10,10,0};
    m_player->makeAMove(l_initialPositon);

    for(int i = 0; i < p_opponentNb; i++)
    {
        m_monsters.push_back(std::make_unique<Opponent>(generateRandomPosition()));
    }
}

void GameState::addPlayer(std::string p_playerName)
{
    m_player = std::make_unique<Player>(p_playerName);
}

void GameState::updateState()
{
    //m_informer->defineObject(m_player->getPositon());
}

Renderable GameState::generateRandomPosition()
{
    Renderable pos = Renderable{static_cast<float>(rand() % WIDTH),      static_cast<float>(rand() % HEIGHT),
                            static_cast<float>(rand()%MAX_SIZE + 1), static_cast<float>(rand()%MAX_SIZE + 1),
                            static_cast<float>(rand()%361)};
    return pos;
}
