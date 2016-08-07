#include "shader_manager.h"

ShaderManager::ShaderManager(const std::string &VS, const std::string &FS)
{
    m_vertexShaderString = loadTextFromFile(VS);
    m_fragmentShaderString = loadTextFromFile(FS);

    m_shaderLoader = new ShaderLoader(m_vertexShaderString.c_str(), m_fragmentShaderString.c_str());

    std::cout << "ShaderManager created" << std::endl;
}

std::string ShaderManager::loadTextFromFile(const std::string &fileName)
{
    std::string content;
    std::ifstream fileStream(fileName.c_str(), std::ios::in);

    if(!fileStream.is_open())
    {
        std::cerr << "Unable to read file: " << fileName << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof())
    {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();

    return content;
}

GLuint ShaderManager::getProgramHandle()
{
    return m_shaderLoader->getProgramHandle();
}

ShaderManager::~ShaderManager()
{
    delete m_shaderLoader;

    std::cout << "ShaderManager destroyed" << std::endl;
}
