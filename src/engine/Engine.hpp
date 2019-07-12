#pragma once

#include <memory>

class GameState;
class Renderer;

struct GLFWwindow;

class Engine
{
public:
    Engine();
    ~Engine();

    void launch();
private:
    std::shared_ptr<Renderer> m_renderer;
    std::shared_ptr<GameState> m_gameState;
    GLFWwindow* m_window;

    bool initGLFW(const std::string& windowName);
    bool shouldClose();
};



