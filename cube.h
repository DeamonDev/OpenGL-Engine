#ifndef CUBE_H
#define CUBE_H

#include "entity.h"
#include <GL/glew.h>
#include <vector>

class Cube : public Entity
{
public:
    Cube();
    ~Cube();

    void draw();

private:
    GLuint m_vertexArrayObject;
    GLuint m_vertexBufferObject[2];
    unsigned int m_drawCount;

};

#endif // CUBE_H
