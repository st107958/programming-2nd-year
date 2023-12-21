#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>

#include "Data.h"


#define M 2
#define N 2

std::mutex mut;
std::mutex mut1;

std::condition_variable cv;

template <class T>
void data_generator(std::queue<T> & q, Data<int> & data);

template <class T>
void data_processor(std::queue<T> & q, Data<int>& data);

template <class T>
T data_gen(Data<T> & data);

template <class T>
void data_proc(T temp);

template<class T>
bool More_data_to_gen(Data<T> & data)
{
    std::lock_guard<std::mutex> guard(mut1);

    if (data.data.empty())
    {
        std::cout << "ALL DATA GENERATED" << std::endl;

        return false;
    }

    return true;
}


int main(int argc, char* argv[])
{
    
    std::queue<int> q;

    Data<int> dat;

    for (int i = 0; i < 10; i++)
    {
        dat.Push(i);
    }
   
    std::vector<std::thread> gener;

    for (int i = 0; i < N; ++i)
    {
        gener.push_back(std::move(std::thread(data_generator<int>, std::ref(q), std::ref(dat))));
    }

    std::vector<std::thread> proc;

    for (int i = 0; i < N; ++i) 
    {
        proc.push_back(std::move(std::thread(data_processor<int>, std::ref(q), std::ref(dat))));
    }

    for (auto& thread : gener) {
        thread.join();
    }

    for (auto& thread : proc) {
        thread.join();
    }
}

template <class T>
void data_generator(std::queue<T> & q, Data<int> & data)
{
    while (More_data_to_gen(data))
    {
        T temp = data_gen(data);

        std::lock_guard<std::mutex> guard(mut);
        
        q.push(temp);
        
        cv.notify_one();
    }
}

template <class T>
void data_processor(std::queue<T> & q, Data<int>& data)
{
    while (More_data_to_gen(data) || (!q.empty()))
    {
        std::unique_lock<std::mutex> lock(mut);
        
        cv.wait(lock, [&q] { return !q.empty(); });

        T temp = q.front();

        q.pop();

        lock.unlock();
        
        data_proc(temp);
    }
}

template<class T>
T data_gen(Data<T> & data)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    T temp = data.Execute_data();

    mut1.lock();

    std::cout << "Data " << temp << " pulled" << std::endl;

    mut1.unlock();

    return temp;
}

template<class T>
void data_proc(T temp)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    mut1.lock();

    std::cout << "Data " << temp << " processed" << std::endl;

    mut1.unlock();
}
