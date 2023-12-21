#pragma once
#include <vector>

template <class T>
class Data
{
public:
    std::vector<T> data;
    bool data_to_gen;

    Data() {};

    T Execute_data()
    {
        T temp = this->data.back();

        this->data.pop_back();

        return temp;
    }

    void Push(T temp)
    {
        this->data.push_back(temp);

        this->data_to_gen = true;
    }

    bool empty()
    {
        if (data.empty)
        {
            return true;
        }

        return false;
    }

    ~Data() {};
};
