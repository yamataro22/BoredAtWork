#include "Engine.hpp"

#include "GameState.h"
#include "Renderer.h"

Engine::Engine()
{
    m_renderer = std::make_shared<Renderer>("Window");
    m_gameState = std::make_shared<GameState>(m_renderer);
}
