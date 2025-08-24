//
// Created by Hunor Zoltáni on 23.08.2025.
//

#include <raylib.h>
#include "Application.h"

int main() {
    Application::Initialize();

    while (!WindowShouldClose()) {
        Application::Update();

        Application::Render();
    }

    Application::Shutdown();
}