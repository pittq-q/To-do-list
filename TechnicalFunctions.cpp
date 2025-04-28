#include "Task.h"

void CheckingInput()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
	}
	else
	{
		std::cin.ignore(LLONG_MAX, '\n');
	}
}

int UserChoice(int count, const char* error)
{
	int choice = 0;

	do
	{
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		CheckingInput();
		if (choice >= 1 && choice <= count)
		{
			return choice;
		}
		else
		{
			std::cout << error << std::endl;
		}
	} while (true);
}

int UserChoice(int count, const char* error, Task taskList[])
{
	int choice = 0;

	do
	{
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		CheckingInput();
		if (choice >= 1 && choice <= count && !taskList[choice - 1].IsEmpty())
		{
			return choice;
		}
		else
		{
			std::cout << error << std::endl;
		}
	} while (true);
}
