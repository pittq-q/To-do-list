#include <iostream>
#include "Task.h"
#include "Menu.h"

int main()
{
	size_t SIZELIST = 10;
	Task* taskList = new Task[SIZELIST];

	StartMenu(taskList, SIZELIST);
	
	return 0;
}