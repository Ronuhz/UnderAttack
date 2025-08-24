//
// Created by Hunor Zoltáni on 23.08.2025.
//

#pragma once
#include <raylib.h>
#include "Entity.h"

class Player : public Entity {
public:
    const float m_WIDTH;
    const float m_HEIGHT;
public:
    Player();

    void ProcessInput();
    void UpdateCamera();
    Camera2D GetCamera() const;
    void Draw() const override;
private:
    void InitializeCamera();
private:
    const unsigned int m_SPEED;
    Camera2D m_camera;
};
