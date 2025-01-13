#include <memory>
#include <mutex>

// Singleton ���ø� Ŭ����
template <typename T>
class Singleton {
public:
    // Singleton �ν��Ͻ��� ��� ���� �޼���
    static T& Instance() {
        static T instance; // C++11 ���� thread-safe
        return instance;
    }

    // ����� ������ ����
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

protected:
    // �⺻ �����ڿ� �Ҹ��ڴ� protected�� ��ȣ
    Singleton() = default;
    ~Singleton() = default;
};