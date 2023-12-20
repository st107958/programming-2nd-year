#pragma once

#include <iostream>
#include <algorithm>
#include <boost/sort/sort.hpp>

enum Typesort { QuickSort, MergeSort, StableSort, CountingSort };

template <class T>
class SortFunctor
{
public:

	Typesort typesort;

	SortFunctor(Typesort typesort = Typesort::QuickSort);

	void operator()(T & container, Typesort typesort);

	~SortFunctor();
};

template<class T>
inline void SortFunctor<T>::operator() (T & container, Typesort typesort)
{
	switch (typesort) {
	case 0:
		std::sort(container.begin(), container.end());
	case 1:
		std::sort(container.begin(), container.end());
	case 2:
		std::sort(container.begin(), container.end());
	case 3:
		std::sort(container.begin(), container.end());
	}

}

template<class T>
SortFunctor<T>::SortFunctor(Typesort typesort) : typesort(typesort) {};

template<class T>
SortFunctor<T>::~SortFunctor() {};