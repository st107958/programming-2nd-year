#include "Task.h"
#include "Fiber.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 

int main(int argc, char* argv[])
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	Fiber F;

	F.AddTask(2, 10);
	F.AddTask(1, 5);
	F.AddTask(4, 3);
	F.AddTask(5, 8);
	F.AddTask(3, 10);

	F.Proccesing();

	for (int i = 0; i < 5; i++) 
	{
		std::cout << "Subtausk of priority " << F.tasks[i].task_priority << " done " << F.tasks[i].testparam_subtask_done << " times "<< std::endl;
	}
	

	return EXIT_SUCCESS;
}