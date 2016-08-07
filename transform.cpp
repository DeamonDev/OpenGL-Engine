#include "transform.h"

Transform::Transform(const Vector3f &pos, const Vector3f &rot, const Vector3f &scale)
{
    m_position = pos;
    m_rotation = rot;
    m_scale = scale;
}
