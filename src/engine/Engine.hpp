#pragma once

#include <memory>

class GameState;
class Renderer;

class Engine
{
    Engine();
private:
    std::shared_ptr<Renderer> m_renderer;
    std::shared_ptr<GameState> m_gameState;
};



