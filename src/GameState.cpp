#include "GameState.h"

#include "GameInformer.hpp"
#include "Player.h"
#include <memory>
#include "time.h"
#include <vector>
#include <algorithm>
#include "FollowerMonster.hpp"
#include "MonsterFabric.hpp"

GameState::GameState(std::shared_ptr<GameInformer> p_informer): m_informer(std::move(p_informer))
{
    srand(time(NULL));
}

void GameState::initState(int p_opponentNb)
{
    m_player->setPosition(WIDTH/2,HEIGHT/2, 28, 40, 0);

    MonsterFabric mf;
    m_monsters = mf.generateMonsters(p_opponentNb);
}

void GameState::addPlayer(std::string p_playerName)
{
    m_player = std::make_shared<Player>(p_playerName);
}

void GameState::updateState()
{
    performPlayerMove();
    performMonsterMoves();

    m_informer->defineObject(m_player);
    m_informer->defineObject(m_player->getHealthbarRenderable());

    for(const auto& monster : m_monsters)
    {
        m_informer->defineObject(monster);
    }
}

void GameState::performMonsterMoves()
{
    auto l_monster = std::begin(m_monsters);

    while (l_monster != std::end(m_monsters))
    {
        (*l_monster)->makeAMove(m_player, m_monsters);

        if((*l_monster)->didApprochedMob(m_player))
        {
            m_player->getHit((*l_monster)->getFirePower());
            l_monster = m_monsters.erase(l_monster);
        }
        else
            ++l_monster;
    }
}


void GameState::inputChanged(const RegisteredKeyState & keyState)
{
    m_registeredKeyState = keyState;
}

void GameState::performPlayerMove()
{
    auto dX = 0;
    auto dY = 0;

    if(m_registeredKeyState.pressedA) dX -= 10;
    if(m_registeredKeyState.pressedW) dY += 10;
    if(m_registeredKeyState.pressedD) dX += 10;
    if(m_registeredKeyState.pressedS) dY -= 10;

    m_player->makeAMove(dX, dY);
}

void GameState::mouseClicked(int x, int y)
{

}
