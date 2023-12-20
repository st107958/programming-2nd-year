#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>


#include "Data.h"

#define M 5
#define N 5

std::mutex mut;
std::mutex mut1;

std::condition_variable cv;

template <class T>
void data_generator(std::queue<T> & q, Data<int> & data);

template <class T>
void data_processor(std::queue<T> & q);

template <class T>
T data_gen(Data<T> & data);

template <class T>
void data_proc(T temp);



int main(int argc, char* argv[])
{
    std::queue<Data<int>> q;

    Data<int> dat;

    /*std::vector<std::thread> gener;*/

   /* for (int i = 0; i < M; ++i)  
    {
        gener.emplace_back([q, dat]() {
            data_generator<int> (q, dat);
            });
    }*/

    std::thread gener(data_generator<int>, q, dat);
    std::thread proc(data_processor<int>, q);


    /*for (int i = 0; i < N; ++i)
    {
        gener.push_back(std::thread(data_generator<int>, q, dat, i));
    }

    std::vector<std::thread> proc;

    for (int i = 0; i < N; ++i) 
    {
        proc.push_back(std::thread(data_processor<int>, q, i));
    }*/
}

template <class T>
void data_generator(std::queue<T> & q, Data<int> & data)
{
    while (data.More_data_to_gen())
    {
        T temp = data_gen(data);

        std::lock_guard<std::mutex> guard(mut);
        
        q.push(temp);
        
        cv.notify_one();
    }
}

template <class T>
void data_processor(std::queue<T> & q)
{
    while (true)
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
    T temp = data.Execute_data();

    mut1.lock();

    std::cout << "Data" << temp << "pulled" << std::endl;

    mut1.unlock();

    return temp;
}

template<class T>
void data_proc(T temp)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    mut1.lock();

    std::cout << "Data" << temp << "processed" << std::endl;

    mut1.unlock();
}
