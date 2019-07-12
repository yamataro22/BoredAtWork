#pragma once
#include <iostream>
#include <memory>
#include "Player.h"
#include "Monster.h"
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
    const int SAFE_ZONE = 200;


    std::shared_ptr<GameInformer> m_informer;

    std::shared_ptr<Player> m_player;
    std::vector<std::shared_ptr<Monster>> m_monsters;

    std::tuple<int, int> generateRandomPosition();

    void performMoves();

    int generatePos();

    bool isPositionOk(int x);
};

