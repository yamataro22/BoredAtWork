#pragma once

#include "GameInformer.hpp"
#include "Renderable.hpp"

#include <list>
#include <string>

class Renderer : public GameInformer
{
public:
    explicit Renderer();
    ~Renderer();

    void defineObject(
        float positionX,
        float positionY,
        float sizeX,
        float sizeY,
        float rotation
    ) override;

    void render();

private:

    unsigned m_vertexArrayObjectID;

    std::list<Renderable> m_objectList;

    bool initGLEW();
    bool initDevIL();
};
