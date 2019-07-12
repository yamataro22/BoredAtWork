#pragma once

#include <vector>
#include <memory>

class Monster;

class MonsterFabric
{
public:

    std::vector<std::shared_ptr<Monster>> generateMonsters(int);

private:

    const int WIDTH = 2000;
    const int HEIGHT = 2000;
    const int SAFE_ZONE = 200;

    std::tuple<int, int> generateRandomPosition();
    int generatePos();
    bool isPositionOk(int x);
};
