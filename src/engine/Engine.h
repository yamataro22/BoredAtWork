#pragma once

#include <list>
#include <memory>
#include <set>
#include <string>
#include <vector>

struct GLFWwindow;

class Engine
{
public:
    explicit Engine(const std::string& p_windowName);
    ~Engine() = default;

private:
    GLFWwindow* m_window;
    unsigned m_vertexArrayObjectID;

    bool initGLFW(const std::string& windowName);
    bool initGLEW();
    bool initDevIL();
};
