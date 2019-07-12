#pragma once

class Renderable;

class GameInformer
{
public:
    virtual ~GameInformer() = default;

    virtual void defineObject(const Renderable& r) = 0;
};
