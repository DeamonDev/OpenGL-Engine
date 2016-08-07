#include "line.h"
#include "vertex.h"
#include <vector>

Line::Line(float x1, float y1, float x2, float y2) : m_drawCount(2)
{
    Vertex vertices[2] = { Vertex(Vector3f(x1, y1, 0.0f), Vector3f(1.0f, 0.0f, 0.0f)),
                           Vertex(Vector3f(x2, y2, 0.0f), Vector3f(0.0f, 1.0f, 0.0f)) };

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    std::vector<Vector3f> positions;
    positions.reserve(m_drawCount);

    std::vector<Vector3f> colors;
    colors.reserve(m_drawCount);

    for(int i = 0; i < m_drawCount; i++)
    {
        positions.push_back(vertices[i].getPosition());
        colors.push_back(vertices[i].getColor());
    }

    glGenBuffers(2, m_vertexBufferObject);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[0]);
    glBufferData(GL_ARRAY_BUFFER, m_drawCount * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[1]);
    glBufferData(GL_ARRAY_BUFFER, m_drawCount * sizeof(colors[0]), &colors[0], GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    std::cout << "Line created" << std::endl;
}

void Line::draw()
{
    m_transform->update();

    glBindVertexArray(m_vertexArrayObject);
    glDrawArrays(GL_LINES, 0, m_drawCount);
    glBindVertexArray(0);
}

Line::~Line()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);

    std::cout << "Line destroyed" << std::endl;
}
