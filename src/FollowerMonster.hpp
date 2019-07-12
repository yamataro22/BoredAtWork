#pragma once
#include <memory>
#include "Monster.h"

class FollowerMonster : public Monster {

public:
    FollowerMonster(int, int);
    void makeAMove(const std::shared_ptr<Renderable> sharedPtr) override;
private:
    void approachPosition(const std::shared_ptr<Renderable>);
};

