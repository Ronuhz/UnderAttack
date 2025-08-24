//
// Created by Hunor Zoltáni on 23.08.2025.
//

#include <raylib.h>
#include <raymath.h>
#include "Player.h"

#include <algorithm>

#include "Application.h"

Player::Player()
    : m_SPEED(150.0f), m_WIDTH(30), m_HEIGHT(50), m_camera()
{
    m_position = {Application::WINDOW_WIDTH / 2.0f, Application::WINDOW_HEIGHT / 2.0f};
    InitializeCamera();
}

void Player::ProcessInput() {
    const float deltaTime = GetFrameTime();
    Vector2 velocity = {0, 0};

    // Get input direction (normalized vector)
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) velocity.x += 1.0f;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) velocity.x -= 1.0f;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) velocity.y -= 1.0f;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) velocity.y += 1.0f;

    // Normalize diagonal movement so it's not faster than cardinal movement
    if (velocity.x != 0 || velocity.y != 0) {
        velocity = Vector2Normalize(velocity);
    }

    // Apply speed and deltaTime once
    m_position = Vector2Add(m_position, Vector2Scale(velocity, m_SPEED * deltaTime));
}

void Player::Draw() const {
    DrawText(TextFormat("%.0f", m_health), m_position.x, m_position.y - 20, 20, GREEN);
    DrawRectangle(m_position.x, m_position.y, m_WIDTH, m_HEIGHT, GREEN);
}

void Player::InitializeCamera() {
    m_camera = {0};
    m_camera.target = {m_position.x, m_position.y};
    m_camera.offset = {Application::WINDOW_WIDTH / 2.0f, Application::WINDOW_HEIGHT / 2.0f};
    m_camera.rotation = 0.0f;
    m_camera.zoom = 1.0f;
}

void Player::UpdateCamera() {
    m_camera.target.x = (int)m_position.x;
    m_camera.target.y = (int)m_position.y;

    // Keeps camera centered even if window is resized
    m_camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };

    // Consistent world area regardless of window size
    m_camera.zoom = std::min(
        (float)GetScreenWidth() / Application::WINDOW_WIDTH,
        (float)GetScreenHeight() / Application::WINDOW_HEIGHT
    );

    // INFO: Make camera lag behind the player
    // float deltaTime = GetFrameTime();
    // camera.target.x += (player.m_position.x - camera.target.x) * 12.0f * deltaTime;
    // camera.target.y += (player.m_position.y - camera.target.y) * 12.0f * deltaTime;
}

Camera2D Player::GetCamera() const {
    return m_camera;
}



