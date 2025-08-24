//
// Created by Hunor Zoltáni on 23.08.2025.
//

#pragma once
#include "Player.h"

namespace Application {
    constexpr int WINDOW_WIDTH = 800;
    constexpr int WINDOW_HEIGHT = 450;

    void Initialize();
    void Shutdown();

    void Update();
    void Render();

    void DrawDebugData(const Player& player);
}