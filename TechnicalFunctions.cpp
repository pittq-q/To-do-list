#include "Task.h"

void CheckingInput(InputType type)
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
	}
	else if (type == InputType::Extraction)
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
		CheckingInput(InputType::Extraction);
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
	char checkForAString[4];

	do
	{
		std::cout << whatToEnter << ": ";
		std::cin >> std::setw(4) >> checkForAString;
		CheckingInput(InputType::Extraction);
		if (checkForAString[1] != '\0' || (checkForAString[0] - '0') < 1 || (checkForAString[0] - '0') > count 
			|| taskList[checkForAString[0] - '0' - 1].IsEmpty())
		{
			std::cout << error << std::endl;
		}
		else
		{
			return checkForAString[0] - '0';
		}
	} while (true);
}
