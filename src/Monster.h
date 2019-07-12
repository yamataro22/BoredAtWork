#pragma once
#include "Renderable.hpp"
#include <memory>
#include <vector>

class Monster : public Renderable
{
public:

    Monster(int, int);

    bool didApprochedMob(const std::shared_ptr<Renderable>& sharedPtr);
    int getFirePower() const;
    virtual void makeAMove(const std::shared_ptr<Renderable> sharedPtr) = 0;
    virtual void makeAMove(const std::shared_ptr<Renderable> sharedPtr, std::vector<std::shared_ptr<Monster>>& others);

protected:

    const int MAX_SIZE = 70;

    int m_speed;
    int m_firePower;
    int generateRandomFirepower();
};
