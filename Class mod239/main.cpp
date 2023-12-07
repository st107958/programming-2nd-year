#include <iostream>
#include <assert.h>	
#include "mod239.h"


void testmod239func();

int main(int argc, char argv[])
{
	
	/*mod A(10);
	mod B(6);
	mod C(8);
	A = A + C;
	std::cout << A;
	std::cin >> B;

	if(A == B)*/

	testmod239func();

	return EXIT_SUCCESS;
}

void testmod239func()
{
	mod a(239);
	mod b(1);
	mod c1(1);
	mod d1 = a + b;
	mod c2();
	assert(d1 == c1);
}
