#include "Engine.hpp"

#include "GameState.h"
#include "Renderer.h"

#include <GLFW/glfw3.h>

namespace
{

std::weak_ptr<InputObserver> g_activeObserver;
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    RegisteredKeyState keyState;
    keyState.pressedW = glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
    keyState.pressedS = glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
    keyState.pressedA = glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
    keyState.pressedD = glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;
    if(auto activeObserver = g_activeObserver.lock())
        activeObserver->inputChanged(keyState);
}

}

Engine::Engine()
{
    initGLFW("Window");
    m_renderer = std::make_shared<Renderer>();
    m_gameState = std::make_shared<GameState>(m_renderer);
    m_gameState->addPlayer("Borys");
    m_gameState->initState(10);
    g_activeObserver = m_gameState;
    glfwSetKeyCallback(m_window, keyCallback);
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

    m_window = glfwCreateWindow(1600, 1000, p_windowName.c_str(), NULL, NULL);
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
