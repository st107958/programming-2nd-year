#pragma once
#include "Object.h"
#include "Constant.h"

class Creature : public Object
{
	int m_hunger;
	int m_thirst;
	int m_health;
	int genom[GENOM_LENGTH] {0};

public:

	void GenerateGenom();

	void Move(int x);
	void Eat();
	void Die();
};

