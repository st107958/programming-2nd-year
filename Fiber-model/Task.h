#pragma once

class Task
{
public:

	int task_priority;
	int number_of_subtasks;
	int subtask_completion_time;

	Task(int priority, int number, int time = 100);

	void SubTaskComplete();

	bool operator==(Task task);

	~Task();
};
