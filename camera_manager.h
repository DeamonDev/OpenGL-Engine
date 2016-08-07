#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include <iostream>
#include <GL/glew.h>
#include "camera.h"
#include "shader_manager.h"

class CameraManager
{
public:
    CameraManager(const Vector3f& pos, float fov, float spect, float zNear, float zFar);
    ~CameraManager();

    inline Matrix4x4 getViewProjectionMatrix() const
    {
        return m_camera->getViewProjection();
    }

    void move(float delta);
    void setActive();

private:
    Camera *m_camera;
};

#endif // CAMERA_MANAGER_H
