#include "CList.h"

#include <iostream>

int main(int argc, char* argv[])
{
	CLList<int> list(0);

	for (int i = 0; i < 10; i++)
	{
		list.InsertHead(i);
	}

	list.Display();

	for (int i = 0; i < 10; i++)
	{
		list.InsertTail(i);
	}

	list.Display();

	return EXIT_SUCCESS;
}