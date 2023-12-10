#pragma once
#include "Task.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>

class Fiber
{
	bool tasks_completed;
	std::vector<Task> tasks;

	Fiber();

	void AddTask(int priority, int nubmer, int time);

	void DeleteTask(Task task);

	int NextTask();

	void Proccesing();

	~Fiber();

};

