#pragma once

#include "Monster.h"

class RandomMonster : public Monster
{
public:
    RandomMonster(int, int);
    void makeAMove(std::shared_ptr<Renderable> sharedPtr) override;
};