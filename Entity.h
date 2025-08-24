//
// Created by Hunor Zoltáni on 23.08.2025.
//

#pragma once
#include <raylib.h>

class Entity {
public:
    Entity();
    virtual void Draw() const;
    Vector2 GetPosition() const;
protected:
    Vector2 m_position;
    bool m_isAlive;
    float m_health;
};
