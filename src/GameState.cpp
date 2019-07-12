#include "GameState.h"

#include "GameInformer.hpp"
#include "Player.h"
#include <memory>

GameState::GameState(std::shared_ptr<GameInformer> p_informer): m_informer(std::move(p_informer))
{

}

void GameState::addPlayer(std::string p_playerName)
{
    m_player = std::make_unique<Player>(p_playerName);
}