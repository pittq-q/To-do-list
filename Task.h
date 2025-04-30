#pragma once
#include "TechnicalFunctions.h"
#include <ctime>

class Task
{
private:
	char* taskTitle;
	char* taskText;
	struct tm deadline;
	char* taskStatus;

public:
	Task();

	Task(const Task& other);

	void CreateTask();

	void UpdateTask();

	void ViewTask(int count) const;

	void DeleteTask();

	bool IsEmpty() const;

	~Task();
};