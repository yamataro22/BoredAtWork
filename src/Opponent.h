#pragma once
#include "Renderable.hpp"

class Opponent : public Renderable
{
public:
    Opponent(float, float);

    void makeAMove(int d_x, int d_y) override;
};
