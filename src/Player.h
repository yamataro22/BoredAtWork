#pragma once

#include <iostream>
#include "Mob.hpp"

class Player : public Renderable
{
public:
    Player(std::string&);
    void makeAMove(Position& newPos);
private:
    std::string m_name;
};
