#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "vertex.h"

class Transform
{
public:
    Transform(const Vector3f& pos = Vector3f(0.0f, 0.0f, 0.0f), const Vector3f& rot = Vector3f(), const Vector3f& scale = Vector3f(1.0f, 1.0f, 1.0f));

    inline Matrix4x4 getModel() const
    {
        Matrix4x4 positionMatrix = glm::translate(m_position);
        Matrix4x4 rotationXMatrix = glm::rotate(m_rotation.x, Vector3f(1.0f, 0.0f, 0.0f));
        Matrix4x4 rotationYMatrix = glm::rotate(m_rotation.y, Vector3f(0.0f, 1.0f, 0.0f));
        Matrix4x4 rotationZMatrix = glm::rotate(m_rotation.z, Vector3f(0.0f, 0.0f, 1.0f));
        Matrix4x4 scaleMatrix = glm::scale(m_scale);

        Matrix4x4 rotationMatrix = rotationZMatrix * rotationYMatrix * rotationXMatrix;

        return positionMatrix * rotationMatrix * scaleMatrix;
    }

    inline Vector3f& getPosition() { return m_position; }
    inline Vector3f& getRotation() { return m_rotation; }
    inline Vector3f& getScale() { return m_scale; }

    inline void setPosition(Vector3f& newPosition) { m_position = newPosition; }
    inline void setRotation(Vector3f& newRotation) { m_rotation = newRotation; }
    inline void setScale(Vector3f& newScale) { m_scale = newScale; }

    inline void changeScale(float delta) { m_scale = m_scale * delta; }

    inline void update() { glUniformMatrix4fv(0, 1, GL_FALSE, glm::value_ptr(getModel())); }

private:
    Vector3f m_position;
    Vector3f m_rotation;
    Vector3f m_scale;
};

#endif // TRANSFORM_H
