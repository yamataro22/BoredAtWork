#pragma once

#include <memory>

class Renderable;

class GameInformer
{
public:
    virtual ~GameInformer() = default;

    virtual void defineObject(const std::shared_ptr<Renderable>& object) = 0;
};
