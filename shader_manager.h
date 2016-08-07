#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include "shader_loader.h"

class ShaderManager
{
public:
    ShaderManager(const std::string& VS, const std::string& FS);
    ~ShaderManager();

    GLuint getProgramHandle();
    std::string loadTextFromFile(const std::string& fileName);

private:
    ShaderLoader *m_shaderLoader;
    std::string m_vertexShaderString;
    std::string m_fragmentShaderString;

};

#endif // SHADER_MANAGER_H
