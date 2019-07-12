#pragma once
#include "Renderable.hpp"
#include <memory>

class Monster : public Renderable
{
public:
    const int FIRE_POWER = 10;

    Monster(float, float);
    bool approchAnotherMob(const std::shared_ptr<Renderable>) override;
    bool didApprochedMob(const std::shared_ptr<Renderable> sharedPtr);
};
