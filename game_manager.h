#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "render_system.h"
#include "shader_manager.h"
#include "entity.h"
#include "line.h"
#include "triangle.h"
#include "entity_manager.h"
#include "camera_manager.h"
#include "cube.h"


class GameManager
{
public:
    GameManager(int width, int height, const char *title);
    ~GameManager();

    void run();
    void createRenderSystem();
    void createShaderManager();
    void createEntityManager();
    void createCameraManager();
    void createGeometry();
    void createWindow(int width, int height, const char *title);

    void update();

private:
    sf::RenderWindow m_window;
    sf::Clock m_clock;
    RenderSystem *m_renderSystem;
    ShaderManager *m_shaderManager;
    EntityManager *m_entityManager;
    CameraManager *m_cameraManager;
    Line *m_line;
    Line *m_line2;
    Line *m_line3;
    Line *m_line4;
    Triangle *m_triangle;
    Cube *m_cube;
};

#endif // GAME_MANAGER_H
