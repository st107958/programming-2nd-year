#pragma once
#include <vector>
#include <iostream>

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

	bool More_data_to_gen()
	{
		if (this->data.empty())
		{
			std::cout << "ALL DATA GENERATED" << std::endl;

			return false;
		}

		return true;
	}

	~Data() {};
};