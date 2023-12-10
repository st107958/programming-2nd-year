#include "mod239.h"

void mod::normalize()
{
	this->value = this->value % m;

	if (this->value < 0)
	{
		this->value += m;
	};
}

mod::mod(int x = 0)
{
	this->value = x % m;

	this->normalize();
}

mod::~mod() {}

const mod mod::operator+=(const mod& val)
{
	this->value = (this->value + val.value) % m;

	this->normalize();

	return *this;
}

const mod mod::operator-=(const mod& val)
{
	this->value = (this->value - val.value) % m;

	this->normalize();

	return *this;
}

const mod mod::operator*=(const mod& val)
{
	this->value = (this->value * val.value) % m;

	this->normalize();

	return *this;
}

const mod mod::operator/=(const mod& val)
{
	this->value = (this->value / val.value) % m;

	this->normalize();

	return *this;
}

const bool mod::operator<(mod& val)
{
	this->normalize();
	val.normalize();

	if (this->value < val.value)
	{
		return true;
	}

	return false;
}

const bool mod::operator>(mod& val)
{
	this->normalize();
	val.normalize();

	if (this->value > val.value)
	{
		return true;
	}

	return false;
}

const bool mod::operator<=(mod& val)
{
	this->normalize();
	val.normalize();

	if (this->value <= val.value)
	{
		return true;
	}

	return false;
}

const bool mod::operator>=(mod& val)
{
	this->normalize();
	val.normalize();

	if (this->value >= val.value)
	{
		return true;
	}

	return false;
}

const bool mod::operator==(mod& val)
{
	this->normalize();
	val.normalize();

	if (this->value == val.value)
	{
		return true;
	}

	return false;
}

const bool mod::operator!=(mod& val)
{
	this->normalize();
	val.normalize();

	if (this->value != val.value)
	{
		return true;
	}

	return false;
}

const mod operator+(const mod& left, const mod& right)
{
	return mod(left.value + right.value);
}

const mod operator-(const mod& left, const mod& right)
{
	return mod(left.value - right.value);
}

const mod operator*(const mod& left, const mod& right)
{
	return mod(left.value * right.value);
}

const mod operator/(const mod& left, const mod& right)
{
	return mod(left.value / right.value);
}

std::istream& operator>>(std::istream& stream, mod& modm)
{
	stream >> modm.value;

	return stream;
}

std::ostream& operator<<(std::ostream & stream, const mod& modm)
{
	stream << modm.value;
	return stream;
}
