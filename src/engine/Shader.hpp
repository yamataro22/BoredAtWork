#pragma once

#include <string>

class Shader
{
public:
    Shader();
    ~Shader();

    void activate();

private:
    unsigned long m_shaderID;

    std::string getErrorStringForShader(int shaderId);
};
