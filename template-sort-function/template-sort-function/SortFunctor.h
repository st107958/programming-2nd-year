#pragma once

#include <iostream>
#include <algorithm>
#include <functional>

#include "Sorts.h"

enum Typesort { QuickSort, StableSort, PartialSort };

template <class T>
class SortFunctor
{
public:

	Typesort typesort;

	SortFunctor(Typesort typesort = Typesort::QuickSort);

	void operator()(T & container, Typesort typesort, int N = 0);

	~SortFunctor();
};



template<class T>
inline void SortFunctor<T>::operator() (T & container, Typesort typesort, int N)
{
	switch (typesort) {
	case 0:
		std::sort(container.begin(), container.end());
	case 1:
		std::stable_sort(container.begin(), container.end());
	case 2:
		std::partial_sort(container.begin(), container.begin() + N, container.end());
	}

}

template<class T>
SortFunctor<T>::SortFunctor(Typesort typesort) : typesort(typesort) {};

template<class T>
SortFunctor<T>::~SortFunctor() {};