#include <memory>
#include <mutex>

// Singleton 템플릿 클래스
template <typename T>
class Singleton {
public:
    // Singleton 인스턴스를 얻는 정적 메서드
    static T& Instance() {
        static T instance; // C++11 이후 thread-safe
        return instance;
    }

    // 복사와 대입을 방지
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

protected:
    // 기본 생성자와 소멸자는 protected로 보호
    Singleton() = default;
    ~Singleton() = default;
};