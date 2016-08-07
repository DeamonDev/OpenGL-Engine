#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <iostream>
#include <GL/glew.h>
#include "shader_manager.h"
#include "entity.h"
#include "line.h"
#include "entity_manager.h"
#include "camera_manager.h"

class RenderSystem
{
public:
    RenderSystem();
    ~RenderSystem();

    void render(ShaderManager *shaderManager, EntityManager *entityManager, CameraManager *CameraManager);
};

#endif // RENDER_SYSTEM_H
