#include <iostream>
#include <assert.h>	
#include "mod239.h"


void testmod239func();

int main(int argc, char argv[])
{
	
	mod A(10);
	mod B(6);
	mod C(8);

	A = A + C;

	std::cout << A;
	std::cin >> B;

	A = A + B;

	std::cout << A;

	testmod239func();

	return EXIT_SUCCESS;
}

void testmod239func()
{
	mod a(239);
	mod b(1);

	mod c1(1);
	mod c2(238);
	mod c3(-1);
	mod c4(-238);
	mod c5(0);

	mod d1 = a + b;
	mod d2 = a - b;
	mod d3 = b - b - b;
	mod d4 = b - a;
	mod d5 = b - b;

	mod t1 = c2 - b;
	mod t2 = t1 - b - b;

	assert(a == c5);
	assert(b == c4);
	assert(d1 == c1);
	assert(d2 == c2);
	assert(d3 == c3);
	assert(d4 == c4);
	assert(d5 == c5);
	assert(c2 == c3);

	assert(t1 < c2);
	assert(c2 >= t2);
	assert(t1 != t2);
	assert(c4 != c2);
	assert(c4 < c2);
}
