//
// Created by Hunor Zoltáni on 24.08.2025.
//

#pragma once
#include <raylib.h>

#include "Entity.h"

class Enemy : public Entity {
public:
    Enemy(Vector2 pos);
    void Draw() const override;
};
