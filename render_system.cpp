#include "render_system.h"

RenderSystem::RenderSystem()
{
    std::cout << "RenderSystem created" << std::endl;
}

void RenderSystem::render(ShaderManager *shaderManager, EntityManager *entityManager, CameraManager *cameraManager)
{
    glUseProgram(shaderManager->getProgramHandle());

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    cameraManager->setActive();
    entityManager->drawObjects();
}

RenderSystem::~RenderSystem()
{
    std::cout << "RenderSystem destroyed" << std::endl;
}
