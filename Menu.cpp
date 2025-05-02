#include "Menu.h"

void StartMenu(Task* taskList, size_t SIZELIST)
{
	do
	{
		std::cout << "\nYOUR TO-DO-LIST" << std::endl << std::endl <<
			"1. View my tasks" << std::endl <<
			"2. Create a task" << std::endl <<
			"3. Exit" << std::endl << std::endl;

		switch (UserChoice(3, "Your choice is uncorrect. Please, choose from the following.", "Enter your choice"))
		{
		case 1:
			if (ViewTasks(taskList, SIZELIST))
			{
				MenuForTasks(taskList);
			}
			break;
		case 2:
			for (size_t i = 0; i < SIZELIST; ++i)
			{
				if (taskList[i].IsEmpty())
				{
					taskList[i].CreateTask();
					break;
				}
				else if (i == SIZELIST - 1)
				{
					std::cout << "Tasklist is full!" << std::endl << std::endl;
				}
			}
			break;
		case 3:
			return;
		}
	} while (true);
}

bool ViewTasks(const Task* taskList, size_t SIZELIST)
{
	bool hasTasks = false;

	for (int i = 0; i < SIZELIST; ++i)
	{
		if (!taskList[i].IsEmpty())
		{
			taskList[i].ViewTask(i);
			hasTasks = true;
		}
	}

	if (!hasTasks)
	{
		std::cout << "\nNo tasks available!" << std::endl << std::endl;
		return false;
	}
	return true;
}

void MenuForTasks(Task* taskList)
{
	std::cout << "What do you want?" << std::endl << std::endl
		<< "1. Mark the task as completed (it's just deliting the task)" << std::endl
		<< "2. Update the task" << std::endl
		<< "3. Return to main menu" << std::endl << std::endl;

	switch (UserChoice(3, "Your choice is uncorrect. Please, choose from the following.", "Enter your choice"))
	{
	case 1:
		taskList[UserChoice(10, "Your choice is uncorrect. Please, choose from the following.", "Choose the task", taskList) - 1].DeleteTask();
		break;
	case 2:
		taskList[UserChoice(10, "Your choice is uncorrect. Please, choose from the following.", "Choose the task", taskList) - 1].UpdateTask();
		break;
	case 3:
		return;
	}
}