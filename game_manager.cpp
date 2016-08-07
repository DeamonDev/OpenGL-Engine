#include "game_manager.h"

GameManager::GameManager(int width, int height, const char *title)
{
    createWindow(width, height, title);
    createRenderSystem();
    createShaderManager();
    createEntityManager();
    createCameraManager();
    createGeometry();

    std::cout << "GameManager created" << std::endl;
}

void GameManager::createWindow(int width, int height, const char *title)
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 3;

    m_window.create(sf::VideoMode(width, height), title, sf::Style::Default, settings);
    m_window.setVerticalSyncEnabled(true);
}

void GameManager::createShaderManager()
{
    std::string vertexShaderLocation = "/home/peter/Projects/OpenGL/Cyclone3D/Cyclone3D/Shaders/basic_shader.vert";
    std::string fragmentShaderLocation = "/home/peter/Projects/OpenGL/Cyclone3D/Cyclone3D/Shaders/basic_shader.frag";

    m_shaderManager = new ShaderManager(vertexShaderLocation, fragmentShaderLocation);
}

void GameManager::createRenderSystem()
{
    m_renderSystem = new RenderSystem();
}

void GameManager::createGeometry()
{
    m_line = new Line(0.0f, 0.5f, 0.1f, -0.9f);
    m_line->setPosition(Vector3f(0.2f, 0.5f, 0.0f));
    m_entityManager->addObject(m_line);

    m_line2 = new Line(0.2f, 0.9f, -0.1f, -0.5f);
    m_line2->setPosition(Vector3f(0.1f, -1.0f, 0.0f));
    m_entityManager->addObject(m_line2);

    m_line3 = new Line(0.1f, -0.5f, 0.5f, -0.1f);
    m_entityManager->addObject(m_line3);

    m_line4 = new Line(0.0f, -2.0f, 0.0f, 20.0f);
    m_line4->setRotation(Vector3f(70.0f, 50.0f, 40.0f));
    m_entityManager->addObject(m_line4);

    m_triangle = new Triangle();
    m_entityManager->addObject(m_triangle);

    m_cube = new Cube();
    m_entityManager->addObject(m_cube);
}

void GameManager::update()
{
    float deltaTime = m_clock.getElapsedTime().asSeconds();

    m_triangle->setPosition(Vector3f(sin(deltaTime), 0.0f, cos(deltaTime)));
    m_triangle->setRotation(Vector3f(40.0f, deltaTime * 100.0f, deltaTime * 50.0f));

    m_cube->setPosition(Vector3f(0.0f, 0.0f, 10.0f));
    m_cube->setRotation(Vector3f(40.0f, deltaTime * 100.0f, deltaTime * 50.0f));
}

void GameManager::createEntityManager()
{
    m_entityManager = new EntityManager();
}

void GameManager::createCameraManager()
{
    m_cameraManager = new CameraManager(Vector3f(0.0f, 0.0f, -2.0f), 70.0f, ((float)m_window.getSize().x)/((float)m_window.getSize().y), 0.01f, 1000.0f);
}

void GameManager::run()
{
    while(m_window.isOpen())
    {
        sf::Event event;
        while(m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                m_window.close();

            if(event.key.code == sf::Keyboard::Escape)
                m_window.close();

            if(event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);

            if(event.type == sf::Event::MouseWheelMoved)
            {
                float delta = event.mouseWheel.delta * 0.1f;
                m_cameraManager->move(delta);
            }

        }
        update();

        m_renderSystem->render(m_shaderManager, m_entityManager, m_cameraManager);

        m_window.display();
    }
}

GameManager::~GameManager()
{
    delete m_entityManager;
    delete m_shaderManager;
    delete m_renderSystem;
    delete m_cameraManager;

    std::cout << "GameManager destroyed" << std::endl;
}
