#include "MonsterFabric.hpp"
#include "FollowerMonster.hpp"
#include "RandomMonster.hpp"

std::vector<std::shared_ptr<Monster>> MonsterFabric::generateMonsters(int p_quantity)
{
    std::vector<std::shared_ptr<Monster>> l_monsters;

    for(int i = 0; i < p_quantity; i++)
    {
        auto choice = rand() % 2;
        auto l_pos = generateRandomPosition();

        if(choice)  l_monsters.push_back(std::make_shared<FollowerMonster>(std::get<0>(l_pos), std::get<1>(l_pos)));
        else        l_monsters.push_back(std::make_shared<RandomMonster>(std::get<0>(l_pos), std::get<1>(l_pos)));
    }
    return std::move(l_monsters);
}

std::tuple<int, int> MonsterFabric::generateRandomPosition()
{
    return std::tuple<int, int>{generatePos(), generatePos()};
}

int MonsterFabric::generatePos()
{
    auto l_posX = rand() % WIDTH;
    while(not isPositionOk(l_posX))
    {
        l_posX = rand() % WIDTH;
    }
    return l_posX;
}

bool MonsterFabric::isPositionOk(int p_newPos)
{
    return    p_newPos < WIDTH/2 - SAFE_ZONE
              or p_newPos > HEIGHT/2 + SAFE_ZONE;
}