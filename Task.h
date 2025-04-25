#pragma once
#include <iostream>

class Task
{
private:
	char* taskTitle;
	char* taskText;
	char* deadline;
	char* taskStatus;

public:
	Task();

	Task(const Task& other);

	void CreateTask();

	void UpdateTask(int* choice);

	void ViewTask(int count) const;

	void DeleteTask();

	bool IsEmpty() const;

	~Task();
};