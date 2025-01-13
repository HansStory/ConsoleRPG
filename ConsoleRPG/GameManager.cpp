#include "GameManager.h"

void GameManager::Initialize() {
    std::cout << "GameManager Initialized!" << std::endl;
}

void GameManager::SetGameTitle(const std::string& title) {
    gameTitle = title;
}

const std::string& GameManager::GetGameTitle() const {
    return gameTitle;
}
