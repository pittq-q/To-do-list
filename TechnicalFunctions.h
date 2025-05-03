#pragma once
#include <iostream>
#include <iomanip>

class Task;

enum InputType
{
	Extraction,
	Getline
};

void CheckingInput(InputType type);

int UserChoice(int count, const char* error, const char* whatToEnter);

int UserChoice(int count, const char* error, const char* whatToEnter, Task taskList[]);