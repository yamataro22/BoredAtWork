#pragma once
#include "Renderable.hpp"
#include <memory>

class Monster : public Renderable
{
public:

    Monster(int, int);

    bool didApprochedMob(const std::shared_ptr<Renderable> sharedPtr);
    int getFirePower() const;
    virtual void makeAMove(const std::shared_ptr<Renderable> sharedPtr) = 0;

protected:

    const int MAX_SIZE = 70;

    int m_speed;
    int m_firePower;
    int generateRandomFirepower();
};
