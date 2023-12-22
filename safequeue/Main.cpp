#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <cassert>

class ThreadSafeQueue {
public:
    // �����������
    ThreadSafeQueue() {}

    // ���������� �������� � �������
    void Enqueue(int value) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(value);
    }

    // ���������� �������� �� �������
    bool Dequeue(int& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (queue_.empty()) {
            return false; // ������� �����
        }

        value = queue_.front();
        queue_.pop();
        return true;
    }

    // ��������, ����� �� �������
    bool IsEmpty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }

private:
    std::queue<int> queue_;
    mutable std::mutex mutex_;
};

// �������� �������
void TestThreadSafeQueue() {
    ThreadSafeQueue queue;

    // ����� ��� ���������� ��������� � �������
    std::thread producer([&]() {
        for (int i = 1; i <= 5; ++i) {
            queue.Enqueue(i);
        }
        });

    // ����� ��� ���������� ��������� �� �������
    std::thread consumer([&]() {
        int value;
        for (int i = 1; i <= 5; ++i) {
            assert(queue.Dequeue(value));
            std::cout << "Dequeued: " << value << std::endl;
        }
        });

    producer.join();
    consumer.join();

    assert(queue.IsEmpty()); // ��������, ��� ������� ����� ����� ���������� �����
    std::cout << "Test Passed!" << std::endl;
}

int main() {
    TestThreadSafeQueue();
    return 0;
}
