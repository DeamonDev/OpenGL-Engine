#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>
#include <iostream>
#include "entity.h"

class EntityManager
{
public:
    EntityManager();
    ~EntityManager();

    void addObject(Entity *entity);
    void drawObjects();
    void scaleObjects(float delta);
    void destroyObjects();

private:
    std::vector<Entity *> m_entities;
};

#endif // ENTITY_MANAGER_H
