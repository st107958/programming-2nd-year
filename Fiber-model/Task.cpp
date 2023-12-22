#include "Task.h"
#include <thread>
#include <chrono>
#include <iostream>

Task::Task(int priority, int number, int time, int done) : 
	task_priority(priority), 
	number_of_subtasks(number), 
	subtask_completion_time(time),
	testparam_subtask_done(done)
{}

void Task::SubTaskComplete()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(subtask_completion_time));

	/*this->number_of_subtasks = this->number_of_subtasks - 1;*/

	this->testparam_subtask_done = this->testparam_subtask_done + 1;

	std::cout << "SubTask of priority " << task_priority << " completed" << std::endl;
}

bool Task::operator==(Task task)
{
	if ((this->task_priority == task.task_priority) && (this->number_of_subtasks == task.number_of_subtasks))
	{
		return true;
	}

	return false;
}

Task::~Task() {}
