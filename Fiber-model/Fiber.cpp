#include "Fiber.h"
#include "Task.h"

void Fiber::AddTask(int priority, int number, int time)
{
	Task t(priority, number, time);

	tasks.push_back(t);
}

void Fiber::DeleteTask(Task task)
{
}

int Fiber::NextTask()
{
	std::vector<int> temparr;

	for (int i = 0; i < tasks.size(); ++i)
	{
		int temp = (tasks[i].number_of_subtasks * ((tasks.size() + 1) - tasks[i].task_priority));

		for (int j = 0; j < temp; ++j)
		{
			temparr.push_back(i);
		}
	}

	int randtemp = rand() % (temparr.size() + 1);



	return ;
}

void Fiber::Proccesing()
{
}

Fiber::~Fiber()
{
}
