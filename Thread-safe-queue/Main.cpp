#include "Queue.h"

#include <thread>
#include <vector>
#include <iostream>
#include <gtest/gtest.h>

TEST(ThreadSafeQueueTest, PushTest) {
    queue<int> queue1;
    
    std::thread t1([&queue1]() {
        for (int i = 0; i < 1000; ++i) {
            queue1.push(i);
        }
        });

    std::thread t2([&queue1]() {
        for (int i = 1000; i < 2000; ++i) {
            queue1.push(i);
        }
        });

    t1.join();
    t2.join();

    EXPECT_EQ(queue1.size(), 1999); 
    
}

TEST(ThreadSafeQueueTest, PopTest) {
    queue<int> queue1;

    std::thread t1([&queue1]() {
        for (int i = 0; i < 1000; ++i) {
            queue1.push(i);
        }
        });

    std::thread t2([&queue1]() {
        for (int i = 1000; i < 2000; ++i) {
            queue1.push(i);
        }
        });

    t1.join();
    t2.join();

    std::thread t3([&queue1]() {
        for (int i = 0; i < 1000; ++i) {
            queue1.push(i);
        }
        });

    std::thread t4([&queue1]() {
        for (int i = 1000; i < 2000; ++i) {
            queue1.push(i);
        }
        });


    std::thread t5([&queue1]() {
        for (int i = 0; i < 1000; ++i) {
            queue1.pop();
        }
        });

    std::thread t6([&queue1]() {
        for (int i = 1000; i < 1999; ++i) {
            queue1.pop();
        }
        });

    
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    EXPECT_EQ(queue1.size(), 2000);

}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

