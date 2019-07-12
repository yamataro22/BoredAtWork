#include "Engine.hpp"

#include "GameState.h"
#include "Renderer.h"

#include <GLFW/glfw3.h>

Engine::Engine()
{
    initGLFW("Window");
    m_renderer = std::make_shared<Renderer>();
    m_gameState = std::make_shared<GameState>(m_renderer);
}

Engine::~Engine() {
    glfwTerminate();
}

void Engine::launch()
{
    while (not shouldClose())
    {
        m_gameState->updateState();
        m_renderer->render();
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}

bool Engine::initGLFW(const std::string& p_windowName)
{
    if (!glfwInit())
    {
        return false;
    }

    glfwWindowHint(GLFW_SAMPLES, 4); //multisampling x4
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL version 3...
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //.3
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(480u, 320u, p_windowName.c_str(), NULL, NULL);
    if (m_window == NULL)
    {
        return false;
    }

    glfwMakeContextCurrent(m_window);

    return true;
}

bool Engine::shouldClose()
{
    glfwWindowShouldClose(m_window);
}
