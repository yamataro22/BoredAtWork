#pragma once
#include <iostream>
#include <memory>
#include "Player.h"
#include "Opponent.h"
#include <vector>

class GameInformer;

class GameState
{
public:
    GameState(std::shared_ptr<GameInformer>);
    void addPlayer(std::string playerName);
    void initState();
    void updateState();

private:

    std::shared_ptr<GameInformer> m_informer;
    std::unique_ptr<Player> m_player;
    std::vector<std::unique_ptr<Opponent>> m_monsters;

};

