#include "camera_manager.h"

CameraManager::CameraManager(const Vector3f& pos, float fov, float aspect, float zNear, float zFar)
{
    m_camera = new Camera(pos, fov, aspect, zNear, zFar);

    std::cout << "CameraManager created" << std::endl;
}

void CameraManager::setActive()
{
    glUniformMatrix4fv(1, 1, GL_FALSE, glm::value_ptr(m_camera->getViewProjection()));
}

void CameraManager::move(float delta)
{
    m_camera->move(delta);
}

CameraManager::~CameraManager()
{
    delete m_camera;

    std::cout << "CameraManager destroyed" << std::endl;
}
