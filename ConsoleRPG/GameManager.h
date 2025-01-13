#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Singleton.h"
#include <string>
#include <iostream>

// GameManager 클래스 정의
class GameManager : public Singleton<GameManager> {
public:
    void Initialize();
    void SetGameTitle(const std::string& title);
    const std::string& GetGameTitle() const;

private:
    friend class Singleton<GameManager>; // Singleton 클래스가 생성자에 접근할 수 있도록 friend 선언
    GameManager() = default; // 생성자는 private이지만 Singleton이 접근 가능
    ~GameManager() = default;

    std::string gameTitle;
};

#endif // GAMEMANAGER_H
