#pragma once
#include "Object.h"

class Creature : public Object
{
	int m_hunger;
	int m_thirst;
	int m_health;

public:

	void Move(int x);
	void Eat();
	void Die();
};

