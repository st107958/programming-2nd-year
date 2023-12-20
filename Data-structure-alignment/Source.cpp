#include <iostream>

class A
{
public:

	double d;
	double c;

	int a;
	int b;

	bool h;
	bool g;
	char e[42];	

	
	int f[2];
	
};

int main(int argc, char argv[])
{
	std::cout << sizeof(A);

	return EXIT_SUCCESS;
}