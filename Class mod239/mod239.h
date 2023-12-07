#pragma once
#include <iostream>
#define m 239

class mod
{
public:

	int value;

	mod(int x);

	~mod();

	void normalize();
	
	friend const mod operator+(const mod& left, const mod& right);
	friend const mod operator-(const mod& left, const mod& right);
	friend const mod operator*(const mod& left, const mod& right);
	friend const mod operator/(const mod& left, const mod& right);

	const mod operator+=(const mod& val);
	const mod operator-=(const mod& val);
	const mod operator*=(const mod& val);
	const mod operator/=(const mod& val);

	const bool operator<(mod& val);
	const bool operator>(mod& val);
	const bool operator<=(mod& val);
	const bool operator>=(mod& val);
	const bool operator==(mod& val);
	const bool operator!=(mod& val);

	friend std::istream& operator>>(std::istream& stream, mod& modm);
	friend std::ostream& operator<<(std::ostream& stream, const mod& modm);
};

