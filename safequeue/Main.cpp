#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <cassert>

class ThreadSafeQueue {
public:
    // Конструктор
    ThreadSafeQueue() {}

    // Добавление элемента в очередь
    void Enqueue(int value) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(value);
    }

    // Извлечение элемента из очереди
    bool Dequeue(int& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (queue_.empty()) {
            return false; // Очередь пуста
        }

        value = queue_.front();
        queue_.pop();
        return true;
    }

    // Проверка, пуста ли очередь
    bool IsEmpty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }

private:
    std::queue<int> queue_;
    mutable std::mutex mutex_;
};

// Тестовая функция
void TestThreadSafeQueue() {
    ThreadSafeQueue queue;

    // Поток для добавления элементов в очередь
    std::thread producer([&]() {
        for (int i = 1; i <= 5; ++i) {
            queue.Enqueue(i);
        }
        });

    // Поток для извлечения элементов из очереди
    std::thread consumer([&]() {
        int value;
        for (int i = 1; i <= 5; ++i) {
            assert(queue.Dequeue(value));
            std::cout << "Dequeued: " << value << std::endl;
        }
        });

    producer.join();
    consumer.join();

    assert(queue.IsEmpty()); // Проверка, что очередь пуста после завершения теста
    std::cout << "Test Passed!" << std::endl;
}

int main() {
    TestThreadSafeQueue();
    return 0;
}
