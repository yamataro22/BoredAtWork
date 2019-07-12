#pragma once

#include <glm/glm.hpp>

#include <string>

class Shader
{
public:
    Shader();
    ~Shader();

    void activate();
    void loadMvpMatrix(glm::mat4 mvpMatrix);
    void render();

private:
    unsigned long m_shaderID;
    unsigned long m_vboHandleIn;
    unsigned long m_mvpMatrixUni;
    unsigned m_vboMeshDefinitionID;
    unsigned m_indicesBufferID;

    std::string getErrorStringForShader(int shaderId);
};
