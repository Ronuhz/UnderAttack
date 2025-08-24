//
// Created by Hunor Zoltáni on 24.08.2025.
//

#include "GameManager.h"

GameManager::GameManager()
: m_player(), m_enemies() {
    TraceLog(LOG_INFO, "Game Manager Initialized");
}
