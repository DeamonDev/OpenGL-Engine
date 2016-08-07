#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex
{
public:
    Vertex(const glm::vec3& pos)
    {
        m_vertexPosition = pos;
    }

    Vertex(const glm::vec3& pos, const glm::vec3& color)
    {
        m_vertexPosition = pos;
        m_vertexColor = color;
    }

    ~Vertex() { }

    inline glm::vec3 getPosition() const { return m_vertexPosition; }
    inline glm::vec3 getColor() const { return m_vertexColor; }

private:
    glm::vec3 m_vertexPosition;
    glm::vec3 m_vertexColor;

};

//Typedefs, for the sake of clearivity
typedef glm::vec3 Vector3f;
typedef glm::mat4 Matrix4x4;

#endif // VERTEX_H
