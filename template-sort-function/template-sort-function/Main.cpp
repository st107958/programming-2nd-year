#include "SortFunctor.h"

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

template <class T>
T SortFunction(T & cont, Typesort typesort, SortFunctor<T> sort, int N = 0);

int main(int argc, char argv[])
{
	std::vector<int> vector = {6, 1, 2, 4, 5, 3, 8, 8, 2, 7};

	std::array<int, 4> A = { 3, 1, 6, 4 };

	std::array<int, 16> B = { 3, 1, 6, 4, 13, -534, 13125, 645362, 13213214, 312, 2, 9, 12312, -3123, 4324, -3432 };

	std::array<int, 5> C = { 3, 1, 6, 4, 0 };

	SortFunctor<std::vector<int>> s1;
	SortFunctor<std::array<int, 4>> s2;
	SortFunctor<std::array<int, 16>> s3;
	SortFunctor<std::array<int, 5>> s4;


	SortFunction<std::vector<int>>(vector, StableSort, s1);
	SortFunction<std::array<int, 4>>(A, QuickSort, s2);
	SortFunction<std::array<int, 16>>(B, QuickSort, s3);
	SortFunction<std::array<int, 5>>(C, PartialSort, s4, 3);


	for (const auto& element : vector) {
		std::cout << element << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; ++i)
	{
		std::cout << A[i] << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < 16; ++i)
	{
		std::cout << B[i] << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < 5; ++i)
	{
		std::cout << C[i] << " ";
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
}

template<class T>
T SortFunction(T & cont, Typesort typesort, SortFunctor<T> sort, int N)
{
	sort(cont, typesort, N);
	return cont;
}
