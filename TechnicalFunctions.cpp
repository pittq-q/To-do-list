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

int UserChoice(int count, const char* error, const char* whatToEnter)
{
	char checkForAString[4];
	
	do
	{
		std::cout << whatToEnter << ": ";
		std::cin >> std::setw(4) >> checkForAString;
		CheckingInput();
		if (checkForAString[1] != '\0' || (checkForAString[0] - '0') < 1 || (checkForAString[0] - '0') > count)
		{
			std::cout << error << std::endl;
		}
		else
		{
			return checkForAString[0] - '0';
		}
	} while (true);
}

int UserChoice(int count, const char* error, const char* whatToEnter, Task taskList[])
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
