//
// Created by Hunor Zoltáni on 23.08.2025.
//

#include "Application.h"
#include <raylib.h>

#include "GameManager.h"
#include "Player.h"

namespace Application {
    GameManager gameManager;

    void Initialize() {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        InitWindow(Application::WINDOW_WIDTH, WINDOW_HEIGHT, "Under Attack");
        // SetExitKey(KEY_NULL);
        TraceLog(LOG_INFO, "Application Initialized");
    }

    void Shutdown() {
        CloseWindow();
        TraceLog(LOG_INFO, "Application shut down");
    }

    void Update() {
        gameManager.m_player.ProcessInput();
        gameManager.m_player.UpdateCamera();

        // TODO: Temporary enemy spawning
        if (IsKeyPressed(KEY_SPACE)) {
            float randX = GetRandomValue(-200, 200);
            float randY = GetRandomValue(-200, 200);
            gameManager.m_enemies.push_back(Enemy({randX, randY}));
            TraceLog(LOG_INFO, "Enemy Spawned");
        }
    }

    void Render() {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(gameManager.m_player.GetCamera());
            for (auto enemy : gameManager.m_enemies)
                enemy.Draw();
            gameManager.m_player.Draw();
        EndMode2D();

        DrawDebugData(gameManager.m_player);

        EndDrawing();
    }

    void DrawDebugData(const Player& player) {
        DrawFPS(0, 0);
        DrawText(TextFormat("X: %.1f, Y: %.1f", player.GetPosition().x, player.GetPosition().y), 0, 20, 20, PURPLE);
        DrawText("Space to spawn Enemy", 0, 40, 20, BLACK);
    }
}