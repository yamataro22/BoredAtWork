#pragma once

#include <list>
#include <memory>
#include <set>
#include <string>
#include <vector>

class Object;

struct GLFWwindow;

class Renderer
{
public:
    explicit Renderer(const std::string& p_windowName);
    ~Renderer();

    void Render(const Object& o);

private:
    GLFWwindow* m_window;
    unsigned m_vertexArrayObjectID;

    bool initGLFW(const std::string& windowName);
    bool initGLEW();
    bool initDevIL();
};
