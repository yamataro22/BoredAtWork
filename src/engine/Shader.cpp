#include "Shader.hpp"

#include <GL/glew.h>

#include <iostream>

Shader::Shader()
{
    int result;

    // Get the codes for shaders
    const char* vertexShaderCode = "#version 330 core\nin vec2 aVBOHandle;uniform mat4 uMVPMatrix;void main(){gl_Position=uMVPMatrix*vec4(aVBOHandle,0,1);}";
    const char* fragmentShaderCode = "#version 330 core\n;layout(location = 0) out vec3 color;void main(){color = vec3(1,0,0);}";

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
}

Shader::~Shader()
{
    glDeleteProgram(m_shaderID);
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
