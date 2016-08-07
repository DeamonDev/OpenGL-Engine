#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H

#include <GL/glew.h>
#include <iostream>

class ShaderLoader
{
public:
    ShaderLoader(const char *sourceVS, const char *sourceFS);
    ~ShaderLoader();

    GLuint getProgramHandle();
    void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const char *errorMessage);

private:
    GLuint m_programHandle;
    GLuint compileShader(GLenum shader, const char *source);
};

#endif // SHADER_LOADER_H
