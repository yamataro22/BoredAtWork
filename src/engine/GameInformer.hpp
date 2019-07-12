#pragma once

class GameInformer
{
public:
    virtual ~GameInformer() = default;

    virtual void defineObject(
        float positionX,
        float positionY,
        float sizeX,
        float sizeY,
        float rotation
        ) = 0;
};
