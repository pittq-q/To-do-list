#pragma once
#include <iostream>
#include <iomanip>

class Task;

void CheckingInput();

int UserChoice(int count, const char* error, const char* whatToEnter);

int UserChoice(int count, const char* error, const char* whatToEnter, Task taskList[]);