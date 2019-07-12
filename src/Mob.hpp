#pragma once
#include "Renderable.hpp"

class Mob
{
public:
    virtual void makeAMove(Renderable& newPos) = 0;
protected:
    Renderable m_position;
};

