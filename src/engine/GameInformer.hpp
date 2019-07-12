#pragma once

class Renderable;

class GameInformer
{
public:
    virtual ~GameInformer() = default;

    virtual void defineObject(Renderable& pos) = 0;
};
