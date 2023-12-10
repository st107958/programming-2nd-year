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

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

