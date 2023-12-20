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
	std::vector<Task> tasks;
	int amaunt_of_tasks;

public:

	Fiber(int amount_of_tasks = 0);

	void AddTask(int priority, int nubmer, int time = 100);

	void DeleteTask(Task task);

	Task* NextTask();

	void DoTask(Task & task);

	void Proccesing();

	~Fiber();

};

