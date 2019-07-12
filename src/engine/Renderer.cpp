#include "Renderer.h"

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <IL/il.h>
#include <IL/ilu.h>

#include <iostream>

Renderer::Renderer() :
    m_vertexArrayObjectID(0)
{
    bool l_status = initGLEW() and initDevIL();
    m_shader = std::make_unique<Shader>();
    if(l_status)
        std::cout << "Renderer init successful" << std::endl;
    else std::cout << "Renderer init FAILED" << std::endl;
}

Renderer::~Renderer()
{
    glDeleteVertexArrays(1, &m_vertexArrayObjectID);
}

void Renderer::defineObject(const std::shared_ptr<Renderable>& object)
{
    m_objectList.push_back(object);
}

void Renderer::render()
{
    glm::mat4 cameraMatrix = glm::ortho(0.f, 2000.f, 0.f, 2000.f);
    m_shader->activate();

    m_objectList.clear();
}

bool Renderer::initGLEW()
{
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        return false;
    }

    glGenVertexArrays(1, &m_vertexArrayObjectID);
    glBindVertexArray(m_vertexArrayObjectID);

    return true;
}

bool Renderer::initDevIL()
{
    ilInit();
    ilClearColour(255, 255, 255, 000);

    return ilGetError() == IL_NO_ERROR;
}
