#include "TechnicalFunctions.h"

void CheckingInput()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(LLONG_MAX, '\n');
	}
}
