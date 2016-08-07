#ifndef LINE_H
#define LINE_H

#include "entity.h"
#include <iostream>
#include <GL/glew.h>
#include "transform.h"

class Line : public Entity
{
public:
    Line(float x1, float y1, float x2, float y2);
    ~Line();

    void draw();

private:
    GLuint m_vertexArrayObject;
    GLuint m_vertexBufferObject[2];
    unsigned int m_drawCount;
};

#endif // LINE_H
