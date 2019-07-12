#pragma once
#include <iostream>
#include <memory>

class GameInformer;
class Player;

class GameState
{
public:
    GameState(std::shared_ptr<GameInformer>);
    void addPlayer(std::string playerName);
    
    void updateState();

private:

    std::shared_ptr<GameInformer> m_informer;
    std::unique_ptr<Player> m_player;
};
