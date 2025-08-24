//
// Created by Hunor Zoltáni on 23.08.2025.
//

#include <raylib.h>
#include "Entity.h"

Entity::Entity()
    : m_position({0, 0}), m_isAlive(true), m_health(100.0f) {}

void Entity::Draw() const  {
    DrawText(TextFormat("%.0f", m_health), m_position.x, m_position.y - 20, 20, ORANGE);
    DrawRectangle(m_position.x, m_position.y, 20, 20, ORANGE);
}

Vector2 Entity::GetPosition() const {
    return m_position;
}
