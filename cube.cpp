#include "cube.h"
#include <iostream>

Cube::Cube()
{
    m_drawCount = 36;

    Vertex vertices[] = { Vertex(Vector3f(-1.0f, -1.0f, 1.0f)),
                          Vertex(Vector3f(-1.0f,-1.0f, 1.0f)),
                          Vertex(Vector3f(-1.0f, 1.0f, 1.0f)),
                          Vertex(Vector3f( 1.0f, 1.0f,-1.0f)),
                          Vertex(Vector3f(-1.0f,-1.0f,-1.0f)),
                          Vertex(Vector3f(-1.0f, 1.0f,-1.0f)),
                          Vertex(Vector3f(1.0f,-1.0f, 1.0f)),
                          Vertex(Vector3f(-1.0f,-1.0f,-1.0f)),
                          Vertex(Vector3f(1.0f,-1.0f,-1.0f)),
                          Vertex(Vector3f(1.0f, 1.0f,-1.0f)),
                          Vertex(Vector3f(1.0f,-1.0f,-1.0f)),
                          Vertex(Vector3f(-1.0f,-1.0f,-1.0f)),
                          Vertex(Vector3f(-1.0f,-1.0f,-1.0f)),
                          Vertex(Vector3f(-1.0f, 1.0f, 1.0f)),
                          Vertex(Vector3f(-1.0f, 1.0f,-1.0f)),
                          Vertex(Vector3f(1.0f,-1.0f, 1.0f)),
                          Vertex(Vector3f(-1.0f,-1.0f, 1.0f)),
                          Vertex(Vector3f(-1.0f,-1.0f,-1.0f)),
                          Vertex(Vector3f(-1.0f, 1.0f, 1.0f)),
                          Vertex(Vector3f(-1.0f,-1.0f, 1.0f)),
                          Vertex(Vector3f(1.0f,-1.0f, 1.0f)),
                          Vertex(Vector3f(1.0f, 1.0f, 1.0f)),
                          Vertex(Vector3f(1.0f,-1.0f,-1.0f)),
                          Vertex(Vector3f(1.0f, 1.0f,-1.0f)),
                          Vertex(Vector3f(1.0f,-1.0f,-1.0f)),
                          Vertex(Vector3f(1.0f, 1.0f, 1.0f)),
                          Vertex(Vector3f(1.0f,-1.0f, 1.0f)),
                          Vertex(Vector3f(1.0f, 1.0f, 1.0f)),
                          Vertex(Vector3f(1.0f, 1.0f,-1.0f)),
                          Vertex(Vector3f(-1.0f, 1.0f,-1.0f)),
                          Vertex(Vector3f(1.0f, 1.0f, 1.0f)),
                          Vertex(Vector3f(-1.0f, 1.0f,-1.0f)),
                          Vertex(Vector3f(-1.0f, 1.0f, 1.0f)),
                          Vertex(Vector3f(1.0f, 1.0f, 1.0f)),
                          Vertex(Vector3f(-1.0f, 1.0f, 1.0f)),
                          Vertex(Vector3f(1.0f,-1.0f, 1.0f)) };

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    std::vector<Vector3f> positions;
    positions.reserve(m_drawCount);

    for(int i = 0; i < m_drawCount; i++)
    {
        positions.push_back(vertices[i].getPosition());
    }

    glGenBuffers(1, m_vertexBufferObject);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[0]);
    glBufferData(GL_ARRAY_BUFFER, m_drawCount * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    std::cout << "Cube created" << std::endl;
}

void Cube::draw()
{
    m_transform->update();

    glBindVertexArray(m_vertexArrayObject);
    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
    glBindVertexArray(0);
}

Cube::~Cube()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);

    std::cout << "Cube destroyed" << std::endl;
}
