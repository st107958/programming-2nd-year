#include "Queue.h"


int main(int argc, char argv[])
{
	int a[10] = { 1, 1, 2, 3, 6, 7, 5, 3, 7, 11 };
	queue<int> Aqueue;

	for (int i = 0; i < 10; i++)
	{
		Aqueue.push(i);
	}

	return EXIT_SUCCESS;
}