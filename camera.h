#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "vertex.h"

class Camera
{
public:
    Camera(const Vector3f& pos, float fov, float spect, float zNear, float zFar);

    inline Matrix4x4 getViewProjection() const
    {
        return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
    }

    void move(float delta);

private:
    Matrix4x4 m_perspective;
    Vector3f m_position;
    Vector3f m_forward;
    Vector3f m_up;
};

#endif // CAMERA_H
