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
    void initState(int);
    void updateState();

private:

    const int WIDTH = 2000;
    const int HEIGHT = 2000;
    const int MAX_SIZE = 20;

    std::shared_ptr<GameInformer> m_informer;
    std::unique_ptr<Player> m_player;
    std::vector<std::unique_ptr<Mob>> m_monsters;
    Renderable generateRandomPosition();
};

