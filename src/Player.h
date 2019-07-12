#pragma once

#include <iostream>
#include "Renderable.hpp"

class Player : public Renderable
{
public:
    Player(std::string&);
private:
    std::string m_name;
};
