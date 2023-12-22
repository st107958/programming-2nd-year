#include <iostream>

class B
{
public:
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
private:
	int F1(int a) { std::cout << "PRIVATE FUNC"; return 1; }

	void F2(int& b) { std::cout << "PRIVATE FUNC"; }

	char F3(int c) { std::cout << "PRIVATE FUNC"; return 'a'; }
};

int main(int argc, char* argv[])
{
	int x = 3;

	C c;
	B* b = &c;
	b->F1(x);

	return EXIT_SUCCESS;
}