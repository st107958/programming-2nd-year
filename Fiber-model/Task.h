#pragma once

class Task
{
public:

	int task_priority;
	int number_of_subtasks;
	int subtask_completion_time;

	Task(int priority, int number, int time);

	void SubTaskComplete();

	~Task();
};
