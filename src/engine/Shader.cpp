#include "Shader.hpp"

#include <GL/glew.h>

#include <iostream>

Shader::Shader()
{
    int result;

    // Get the codes for shaders
    const char* vertexShaderCode = "#version 330 core\nin vec2 aVBOHandle;uniform mat4 uMVPMatrix;void main(){gl_Position=uMVPMatrix*vec4(aVBOHandle,0,1);}";
    const char* fragmentShaderCode = "#version 330 core\nlayout(location = 0) out vec3 color;void main(){color = vec3(1,0,0);}";

    // Create the shaders on the gpu
    unsigned long vertexShaderGPUID = glCreateShader(GL_VERTEX_SHADER);
    unsigned long fragmentShaderGPUID = glCreateShader(GL_FRAGMENT_SHADER);

    // Compile Vertex Shader
    glShaderSource(vertexShaderGPUID, 1, &vertexShaderCode, NULL);
    glCompileShader(vertexShaderGPUID);

    // Check Vertex Shader
    glGetShaderiv(vertexShaderGPUID, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        std::string errLog = getErrorStringForShader(vertexShaderGPUID);

        glDeleteShader(vertexShaderGPUID);
        glDeleteShader(fragmentShaderGPUID);
        std::cout << "VShader compilation failed, output: " << errLog;

        return;
    }

    // Compile Fragment Shader
    glShaderSource(fragmentShaderGPUID, 1, &fragmentShaderCode, NULL);
    glCompileShader(fragmentShaderGPUID);

    // Check Fragment Shader
    glGetShaderiv(fragmentShaderGPUID, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        std::string errLog = getErrorStringForShader(fragmentShaderGPUID);

        glDeleteShader(vertexShaderGPUID);
        glDeleteShader(fragmentShaderGPUID);
        std::cout << "FShader compilation failed, output: " << errLog << std::endl;

        return;
    }

    // Link the program
    m_shaderID = glCreateProgram();
    glAttachShader(m_shaderID, vertexShaderGPUID);
    glAttachShader(m_shaderID, fragmentShaderGPUID);
    glLinkProgram(m_shaderID);

    // Check the program
    glGetProgramiv(m_shaderID, GL_LINK_STATUS, &result);
    if (result == GL_FALSE)
    {
        int logLenght;
        glGetProgramiv(m_shaderID, GL_INFO_LOG_LENGTH, &logLenght);
        char* errorString = new char[logLenght];
        glGetProgramInfoLog(m_shaderID, logLenght, NULL, &errorString[0]);

        std::cout << "GPUProgram linkage failed, output: " << errorString << std::endl;

        delete[] errorString;
    }

    //detach and delete shaders no matter the result is
    glDetachShader(m_shaderID, vertexShaderGPUID);
    glDetachShader(m_shaderID, fragmentShaderGPUID);

    glDeleteShader(vertexShaderGPUID);
    glDeleteShader(fragmentShaderGPUID);

    m_vboHandleIn = glGetAttribLocation(m_shaderID, "aVBOHandle");
    m_mvpMatrixUni = glGetUniformLocation(m_shaderID, "uMVPMatrix");

    // mesh definition
    glm::vec2 vertices[4] = {
        {-1, -1},
        {1, -1},
        {1, 1},
        {-1, 1}
    };
    unsigned indices[6] = {0, 1, 2, 3, 2, 0};

    glGenBuffers(1, &m_vboMeshDefinitionID);
    glGenBuffers(1, &m_indicesBufferID);

    glBindBuffer(GL_ARRAY_BUFFER, m_vboMeshDefinitionID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indicesBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);
}

Shader::~Shader()
{
    glDeleteProgram(m_shaderID);
    glDeleteBuffers(1, &m_vboMeshDefinitionID);
    glDeleteBuffers(1, &m_indicesBufferID);
}

void Shader::activate()
{
    glUseProgram(m_shaderID);
}

void Shader::loadMvpMatrix(glm::mat4 mvpMatrix)
{
    glUniformMatrix4fv(m_mvpMatrixUni, 1, GL_FALSE, &mvpMatrix[0][0]);
}

void Shader::render()
{
    glEnableVertexAttribArray(m_vboHandleIn);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboMeshDefinitionID);

    glVertexAttribPointer(
        m_vboHandleIn,               // address
        2,                                      // size
        GL_FLOAT,                               // type
        GL_FALSE,                               // normalized?
        0,                                      // stride
        (void*)0                                // array buffer offset
    );

    // indexing
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indicesBufferID);
    glDrawElements(0x0004, 6, GL_UNSIGNED_INT, (void*)0);

    glDisableVertexAttribArray(m_vboHandleIn);
}

std::string Shader::getErrorStringForShader(int shaderId)
{
    int logLenght;
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLenght);

    //this will get deleted in upper function
    char* errorString = new char[logLenght];
    glGetShaderInfoLog(shaderId, logLenght, NULL, &errorString[0]);

    std::string result = errorString;
    delete[] errorString;

    return result;
}
