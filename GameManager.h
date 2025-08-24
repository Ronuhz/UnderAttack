//
// Created by Hunor Zoltáni on 24.08.2025.
//

#pragma once
#include <vector>

#include "Enemy.h"
#include "Player.h"

class GameManager {
public:
    Player m_player;
    std::vector<Enemy> m_enemies;
public:
    GameManager();
};
