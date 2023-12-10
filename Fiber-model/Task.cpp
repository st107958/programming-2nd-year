#include "Task.h"

Task::Task(int priority, int number, int time) : task_priority(priority), number_of_subtasks(number), subtask_completion_time(time) {}

Task::~Task() {}
