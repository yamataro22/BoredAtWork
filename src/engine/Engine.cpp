#include "Engine.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <IL/il.h>
#include <IL/ilu.h>

#include <iostream>

Engine::Engine(const std::string& p_windowName)
{
    bool l_status = initGLFW(p_windowName) and initGLEW() and initDevIL();
    if(l_status)
        std::cout << "Engine init successful" << std::endl;
    else std::cout << "Engine init FAILED" << std::endl;
}

Engine::~Engine()
{
    glDeleteVertexArrays(1, &m_vertexArrayObjectID);
    glfwTerminate();
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

bool Engine::initGLEW()
{
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        return false;
    }

    glGenVertexArrays(1, &m_vertexArrayObjectID);
    glBindVertexArray(m_vertexArrayObjectID);

    return true;
}

bool Engine::initDevIL()
{
    ilInit();
    ilClearColour(255, 255, 255, 000);

    return ilGetError() == IL_NO_ERROR;
}
