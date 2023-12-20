#include "Fiber.h"
#include "Task.h"

Fiber::Fiber(int amount_of_tasks) : amaunt_of_tasks(amount_of_tasks) {}

void Fiber::AddTask(int priority, int number, int time )
{
	Task t(priority, number, time);

	tasks.push_back(t);

	this->amaunt_of_tasks++;
}

void Fiber::DeleteTask(Task task)
{
	/*auto newEnd = std::remove(tasks.begin(), tasks.end(), task);

	tasks.erase(newEnd, tasks.end());*/

	this->amaunt_of_tasks--;
}

Task* Fiber::NextTask()
{

	std::vector<int> temparr;
	if (tasks.size() > 0)
	{
		for (int i = 0; i < tasks.size(); ++i)
		{
			int temp = (tasks[i].number_of_subtasks * ((tasks.size() + 1) - tasks[i].task_priority));

			if (temp != 0)
			{
				for (int j = 0; j < temp; ++j)
				{
					temparr.push_back(i);
				}
			}

		}
	}
	

	int randtemp = abs(rand()) % (temparr.size());

	return &tasks[temparr[randtemp]];
}

void Fiber::DoTask(Task & task)
{
	task.SubTaskComplete();

	if (task.number_of_subtasks == 0)
	{
		std::cout << "TASK COMPLETE" << std::endl;

		DeleteTask(task);
	}
}

void Fiber::Proccesing()
{
	while (this->amaunt_of_tasks != 0)
	{
		DoTask(*NextTask());
	}

	std::cout << "ALL TASKS DONE" << std::endl;
}

Fiber::~Fiber()
{}
