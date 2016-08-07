#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL/glew.h>
#include <iostream>
#include <vector>
#include "vertex.h"
#include "entity.h"

class Triangle : public Entity
{
public:
    Triangle();
    ~Triangle();

    void draw();

private:
    GLuint m_vertexArrayObject;
    GLuint m_vertexBufferObject[2];
    unsigned int m_drawCount;
};

#endif // TRIANGLE_H
