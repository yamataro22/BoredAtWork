#pragma once
#include "Renderable.hpp"
#include <memory>

class Monster : public Renderable
{
public:
    const int FIRE_POWER = 10;

    Monster(int, int);

    bool approachAnotherMob(const std::shared_ptr<Renderable>) override;
    bool didApprochedMob(const std::shared_ptr<Renderable> sharedPtr);

private:
    const int SIZE = 80;
};
