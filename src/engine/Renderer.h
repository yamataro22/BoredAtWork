#pragma once

#include "GameInformer.hpp"

#include <list>
#include <string>

struct GLFWwindow;

class Renderer : public GameInformer
{
public:
    explicit Renderer(const std::string& p_windowName);
    ~Renderer();

    void defineObject(
        float positionX,
        float positionY,
        float sizeX,
        float sizeY,
        float rotation
    ) override;

private:

    struct Renderable
    {
        float positionX;
        float positionY;
        float sizeX;
        float sizeY;
        float rotation;
    };

    GLFWwindow* m_window;
    unsigned m_vertexArrayObjectID;

    std::list<Renderable> m_objectList;

    bool initGLFW(const std::string& windowName);
    bool initGLEW();
    bool initDevIL();
};
