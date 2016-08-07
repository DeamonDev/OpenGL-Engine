#include "entity_manager.h"

EntityManager::EntityManager()
{
    std::cout << "EntityManager created" << std::endl;
}

void EntityManager::addObject(Entity *entity)
{
    m_entities.push_back(entity);
}

void EntityManager::drawObjects()
{
    for(int i = 0; i < m_entities.size(); i++)
    {
        m_entities[i]->draw();
    }
}

void EntityManager::destroyObjects()
{
    for(int i = 0; i < m_entities.size(); i++)
    {
        delete m_entities[i];
    }
}

void EntityManager::scaleObjects(float delta)
{
    for(int i = 0; i < m_entities.size(); i++)
    {
        m_entities[i]->changeScale(delta);
    }
}

EntityManager::~EntityManager()
{
    destroyObjects();

    std::cout << "EntityManager destroyed" << std::endl;
}
