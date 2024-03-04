#include "Creature.h"

void Creature::GenerateGenom()
{
}

void Creature::Move(int x)
{
	if (x > 7 || x < 0) throw ("isn't a move");

	switch (x) {
	case 0:
		this->ChangeCoordinates(0, 1);
	case 1:
		this->ChangeCoordinates(1, 1);
	case 2:
		this->ChangeCoordinates(1, 0);
	case 3:
		this->ChangeCoordinates(1, -1);
	case 4:
		this->ChangeCoordinates(0, -1);
	case 5:
		this->ChangeCoordinates(-1, -1);
	case 6:
		this->ChangeCoordinates(-1, 0);
	case 7:
		this->ChangeCoordinates(-1, 1);
	}
}

void Creature::Eat()
{
}

void Creature::Die()
{
}
