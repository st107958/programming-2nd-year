#include <iostream>

class A
{

};

int main(int argc, char argv[])
{
	int x1 = 122;
	short h = 9;
	//bool d = 1;
	double y1 = 36568568;
	int x = 122;
	double y = 3345678;
	short h1 = 9;
	bool z = 1;
	double y2 = 38;

	std::cout << &x1 << std::endl;
	std::cout << &h << std::endl;
	/*std::cout << &d << std::endl;*/
	std::cout << &y1 << std::endl;
	std::cout << &x << std::endl;
	std::cout << &y << std::endl;
	std::cout << &h1 << std::endl;
	std::cout << &z << std::endl;
	std::cout << &y2 << std::endl;

	return EXIT_SUCCESS;
}