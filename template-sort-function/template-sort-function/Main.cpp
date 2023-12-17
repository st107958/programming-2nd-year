#include "SortFunctor.h"

#include <iostream>
#include <algorithm>

template <class T>
T SortFunction(T & cont, Typesort typesort, SortFunctor<T> sort);

int main(int argc, char argv[])
{
	std::vector<int> vector = {6, 1, 2, 4, 5, 3, 8, 8, 2, 7};

	for (const auto& element : vector) {
		std::cout << element << " ";
	}

	std::cout << std::endl;

	SortFunctor<std::vector<int>> ss;

	SortFunction<std::vector<int>>(vector, QuickSort, ss);

	for (const auto& element : vector) {
		std::cout << element << " ";
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
}

template<class T>
T SortFunction(T & cont, Typesort typesort, SortFunctor<T> sort)
{
	sort(cont, typesort);
	return cont;
}
