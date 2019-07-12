#pragma once

#include "Mob.hpp"

class Opponent : public Mob
{
public:
    Opponent(Renderable&);
    void makeAMove(Renderable&) override;
private:
    Renderable m_position;
};
