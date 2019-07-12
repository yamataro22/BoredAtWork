#pragma once

#include <iostream>
#include "Renderable.hpp"

class Player : public Renderable
{
public:

    Player(std::string&);
    void getHit(int);

    std::shared_ptr<Renderable> getHealthbarRenderable();

private:
    std::string m_name;
    int m_remainingHp;
};
