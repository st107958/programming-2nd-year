#include <iostream>

class B
{
	virtual int F1(int a)
	{
		a++;
		return a;
	}

	virtual void F2(int & b)
	{
		b += 2;
	}

	virtual char F3(int c)
	{
		char temp;

		if (c == 0)
		{
			temp = 'yes';
		}
		else
		{
			temp = 'no';
		}

		return temp;
	}
};

class C : public B
{
public:
	int F1(int a) override
	{
		a++;
		return a;
	}

	void F2(int& b) override
	{
		b += 2;
	}

	char F3(int c) override
	{
		char temp;

		if (c == 0)
		{
			temp = 'yes';
		}
		else
		{
			temp = 'no';
		}

		return temp;
	}
};

int main(int argc, char* argv[])
{
	int x = 3;

	C c;

	std::cout << c.F1(x);

	return EXIT_SUCCESS;
}