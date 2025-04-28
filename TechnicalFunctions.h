#pragma once
#include <iostream>

class Task;

void CheckingInput();

int UserChoice(int count, const char* error);

int UserChoice(int count, const char* error, Task taskList[]);