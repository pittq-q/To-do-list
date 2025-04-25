#include "Menu.h"

void StartMenu(Task* taskList, size_t SIZELIST)
{
	int* choice = new int{ 0 };

	do
	{
		std::cout << "\nYOUR TO-DO-LIST" << std::endl << std::endl <<
			"1. View my tasks" << std::endl <<
			"2. Create a task" << std::endl <<
			"3. Exit" << std::endl << std::endl;

		do
		{
			std::cout << "Enter your choice: ";
			std::cin >> *choice;
			if (*choice != 1 && *choice != 2 && *choice != 3)
			{
				std::cout << "Your choice is uncorrect. Please, choose from the following." << std::endl;
			}
		} while (*choice != 1 && *choice != 2 && *choice != 3);

		switch (*choice)
		{
		case 1:
			if (ViewTasks(taskList, SIZELIST))
			{
				MenuForTasks(taskList, choice);
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
		}
	} while (*choice != 3);
	
	delete choice;
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

void MenuForTasks(Task* taskList, int* choice)
{
	std::cout << "What do you want?" << std::endl << std::endl
		<< "1. Mark the task as completed (it's just deliting the task)" << std::endl
		<< "2. Update the task" << std::endl
		<< "3. Return to main menu" << std::endl << std::endl;

	do
	{
		std::cout << "Enter your choice: ";
		std::cin >> *choice;
		if (*choice != 1 && *choice != 2 && *choice != 3)
		{
			std::cout << "Your choice is uncorrect. Please, choose from the following." << std::endl;
		}
	} while (*choice != 1 && *choice != 2 && *choice != 3);

	switch (*choice)
	{
	case 1:
		do
		{
			std::cout << "Choose a task: ";
			std::cin >> *choice;
			if (*choice < 1 || *choice > 10 || taskList[*choice - 1].IsEmpty())
			{
				std::cout << "Your choice is uncorrect. Please, choose from the following." << std::endl;
			}
		} while (*choice < 1 || *choice > 10 || taskList[*choice - 1].IsEmpty());

		taskList[*choice - 1].DeleteTask();
		break;
	case 2:
		do
		{
			std::cout << "Choose a task: ";
			std::cin >> *choice;
			if (*choice < 1 || *choice > 10 || taskList[*choice - 1].IsEmpty())
			{
				std::cout << "Your choice is uncorrect. Please, choose from the following." << std::endl;
			}
		} while (*choice < 1 || *choice > 10 || taskList[*choice - 1].IsEmpty());

		taskList[*choice - 1].UpdateTask(choice);
		break;
	case 3:
		*choice = 0;
		return;
	}
}