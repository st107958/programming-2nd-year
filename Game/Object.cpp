#include "Object.h"

void Object::ChangeCoordinates(int x, int y)
{
	this->m_x = this->m_x + x;
	this->m_y = this->m_y + y;
}
