#include "Task.h"

Task::Task()
	: taskTitle{ new char[20] {} }, taskText{ new char[64] {} }, deadline{ new char[11] {} }, taskStatus{ new char[6] {} }
{ }

Task::Task(const Task & other)
	: taskTitle{ new char[20] {} }, taskText{ new char[64] {} }, deadline{ new char[11] {} }, taskStatus{ new char[6] {} }
{
	strcpy_s(taskTitle, 20, other.taskTitle);
	strcpy_s(taskText, 64, other.taskText);
	strcpy_s(deadline, 11, other.deadline);
	strcpy_s(taskStatus, 6, other.taskStatus);
}

void Task::CreateTask()
{
	std::cin.ignore();
	std::cout << "Enter a Title (max symbols - 20): ";
	std::cin.getline(taskTitle, 20);

	std::cout << "Enter a Text (max symbols - 64): ";
	std::cin.getline(taskText, 64);

	do
	{
		std::cout << "Enter a deadline (dd.mm.YYYY format): ";
		std::cin.getline(deadline, 11);
		if (deadline[2] != '.' || deadline[5] != '.')
		{
			std::cout << "Enter the deadline using the format!" << std::endl;
		}
	} while (deadline[2] != '.' || deadline[5] != '.');
	
	strcpy_s(taskStatus, 6, "false");
}

void Task::UpdateTask(int* choice)
{
	do
	{
		std::cout << "What do you want to choose?" << std::endl << std::endl
			<< "1. Title" << std::endl
			<< "2. Text" << std::endl
			<< "3. Deadline" << std::endl << std::endl;
		std::cin >> *choice;
		if (*choice < 1 || *choice > 3)
		{
			std::cout << "Your choice is uncorrect. Please, choose from the following." << std::endl;
		}
	} while (*choice < 1 || *choice > 3);

	std::cin.ignore();
	switch (*choice)
	{
	case 1:
		std::cout << "Enter a new Title (max symbols - 20): ";
		std::cin.getline(taskTitle, 20);
		break;
	case 2:
		std::cout << "Enter a new Text (max symbols - 64): ";
		std::cin.getline(taskText, 64);
		break;
	case 3:
		do
		{
			std::cout << "Enter a new deadline (dd.mm.YYYY format): ";
			std::cin.getline(deadline, 11);
			if (deadline[2] != '.' || deadline[5] != '.')
			{
				std::cout << "Enter the deadline using the format!" << std::endl;
			}
		} while (deadline[2] != '.' || deadline[5] != '.');
		break;
	}
	*choice = 0;
}

void Task::ViewTask(int count) const
{
	if (taskTitle == nullptr || taskTitle[0] == '\0')
	{
		std::cout << count + 1 << ". (Empty task)" << std::endl;
		return;
	}
	std::cout << count + 1 << ". " << taskTitle << ": " << std::endl <<
		taskText << std::endl 
		<< "Deadline: " << deadline << std::endl 
		<< "Status: " << taskStatus << std::endl << std::endl;
}

void Task::DeleteTask()
{
	Task::~Task();
	taskTitle = new char[20] {};
	taskText = new char[64] {};
	deadline = new char[11] {};
	taskStatus = new char[6] {};
}

bool Task::IsEmpty() const
{
	return taskTitle == nullptr || taskTitle[0] == '\0';
}

Task::~Task()
{
	delete[] taskTitle;
	taskTitle = nullptr;
	delete[] taskText;
	taskText = nullptr;
	delete[] deadline;
	deadline = nullptr;
	delete[] taskStatus;
	taskStatus = nullptr;
}