#include "shader_loader.h"

ShaderLoader::ShaderLoader(const char *sourceVS, const char *sourceFS)
{
    glewExperimental = GL_TRUE;
    glewInit();

    m_programHandle = glCreateProgram();

    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, sourceVS);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, sourceFS);

    glAttachShader(m_programHandle, vertexShader);
    glAttachShader(m_programHandle, fragmentShader);

    glBindAttribLocation(m_programHandle, 0, "vertexPosition");
    glBindAttribLocation(m_programHandle, 1, "vertexColor");
    glBindAttribLocation(m_programHandle, 2, "ProjectionMatrix");
    glBindAttribLocation(m_programHandle, 3, "TransformMatrix");
    glBindAttribLocation(m_programHandle, 4, "uColor");

    glLinkProgram(m_programHandle);
    checkShaderError(m_programHandle, GL_LINK_STATUS, GL_TRUE, "GL_LINK_STATUS_ERROR: ");

    glUseProgram(m_programHandle);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

GLuint ShaderLoader::compileShader(GLenum shader, const char *source)
{
    GLuint shaderHandle = glCreateShader(shader);
    glShaderSource(shaderHandle, 1, &source, NULL);
    glCompileShader(shaderHandle);
    checkShaderError(shaderHandle, GL_COMPILE_STATUS, GL_FALSE, "GL_COMPILE_STATUS_ERROR: ");

    return shaderHandle;
}

GLuint ShaderLoader::getProgramHandle()
{
    return m_programHandle;
}

void ShaderLoader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const char *errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": " << error << std::endl;
    }
}

ShaderLoader::~ShaderLoader()
{

}
