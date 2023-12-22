#pragma once

class Task
{
public:

	int task_priority;
	int number_of_subtasks;
	int subtask_completion_time;
	int testparam_subtask_done;

	Task(int priority, int number, int time = 100, int done = 0);

	void SubTaskComplete();

	bool operator==(Task task);

	~Task();
};
