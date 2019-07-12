#include "GameState.h"

#include "GameInformer.hpp"
#include "Player.h"

GameState::GameState(std::shared_ptr<GameInformer> p_informer): m_informer(std::move(p_informer))
{

}

void GameState::addPlayer(std::string playerName)
{

}