//
// Created by Hunor Zoltáni on 24.08.2025.
//

#include "Enemy.h"

Enemy::Enemy(Vector2 pos) {
    m_position = pos;
}


void Enemy::Draw() const {
    DrawText(TextFormat("%.0f", m_health), m_position.x, m_position.y - 20, 20, RED);
    DrawRectangle(m_position.x, m_position.y, 20, 20, RED);
}
