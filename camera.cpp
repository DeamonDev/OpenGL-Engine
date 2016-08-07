#include "camera.h"

Camera::Camera(const Vector3f &pos, float fov, float aspect, float zNear, float zFar)
{
    m_perspective = glm::perspective(fov, aspect, zNear, zFar);
    m_position = pos;
    m_forward = Vector3f(0, 0, 1);
    m_up = Vector3f(0, 1, 0);
}

void Camera::move(float delta)
{
    m_position += m_forward * delta;
}
