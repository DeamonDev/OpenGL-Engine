#ifndef ENTITY_H
#define ENTITY_H

#include "transform.h"

class Entity
{
public:
    Entity() { m_transform = new Transform(); }
    virtual ~Entity() { delete m_transform; }

    virtual void draw() { }
    virtual void setPosition(Vector3f newPosition) { m_transform->setPosition(newPosition); }
    virtual void setRotation(Vector3f newRotation) { m_transform->setRotation(newRotation); }
    virtual void setScale(Vector3f newScale) { m_transform->setScale(newScale); }

    virtual void changeScale(float delta) { m_transform->changeScale(delta); }

    Transform *m_transform;
};

#endif // ENTITY_H
