#pragma once
#include <vector>
#include "Object.h"

class Field
{
public:
	std::vector<std::vector<std::vector<Object>>> field;

	void GenerateField();

	void Update();

};

