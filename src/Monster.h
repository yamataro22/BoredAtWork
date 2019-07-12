#pragma once
#include "Renderable.hpp"
#include <memory>

class Monster : public Renderable
{
public:


    Monster(int, int);

    bool approachAnotherMob(const std::shared_ptr<Renderable>) override;
    bool didApprochedMob(const std::shared_ptr<Renderable> sharedPtr);
    int getFirePower() const;

private:

    const int MAX_SIZE = 70;

    int m_firePower;
    int generateRandomFirepower();
};
