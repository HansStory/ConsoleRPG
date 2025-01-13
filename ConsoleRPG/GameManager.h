#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Singleton.h"
#include <string>
#include <iostream>

// GameManager Ŭ���� ����
class GameManager : public Singleton<GameManager> {
public:
    void Initialize();
    void SetGameTitle(const std::string& title);
    const std::string& GetGameTitle() const;

private:
    friend class Singleton<GameManager>; // Singleton Ŭ������ �����ڿ� ������ �� �ֵ��� friend ����
    GameManager() = default; // �����ڴ� private������ Singleton�� ���� ����
    ~GameManager() = default;

    std::string gameTitle;
};

#endif // GAMEMANAGER_H
