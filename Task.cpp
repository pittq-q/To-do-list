#include "Task.h"

Task::Task()
	: taskTitle{ new char[20] {} }, taskText{ new char[64] {} }, deadline{}, taskStatus{ new char[6] {} }
{ }

Task::Task(const Task & other)
	: taskTitle{ new char[20] {} }, taskText{ new char[64] {} }, deadline{ other.deadline }, taskStatus{ new char[6] {} }
{
	strcpy_s(taskTitle, 20, other.taskTitle);
	strcpy_s(taskText, 64, other.taskText);
	strcpy_s(taskStatus, 6, other.taskStatus);
}

void Task::CreateTask()
{
	std::cout << "Enter a Title (max symbols - 20): ";
	std::cin.getline(taskTitle, 20);
	CheckingInput();

	std::cout << "Enter a Text (max symbols - 64): ";
	std::cin.getline(taskText, 64);
	CheckingInput();

	do
	{
		std::cout << "Enter a deadline (dd mm YYYY format): ";
		std::cin >> deadline.tm_mday >> deadline.tm_mon >> deadline.tm_year;
		CheckingInput();
		if (deadline.tm_mday < 1 || deadline.tm_mday > 31 || deadline.tm_mon < 1 || deadline.tm_mon > 12 || deadline.tm_year < 2025)
		{
			std::cout << "Enter the deadline using the format!" << std::endl;
		}
	} while (deadline.tm_mday < 1 || deadline.tm_mday > 31 || deadline.tm_mon < 1 || deadline.tm_mon > 12 || deadline.tm_year < 2025);
	
	strcpy_s(taskStatus, 6, "false");
}

void Task::UpdateTask()
{
	std::cin.ignore();
	switch (UserChoice(3, "Your choice is uncorrect. Please, choose from the following.", "Enter what do you want to change\n1 - Title\n2 - Text\n3 - deadline\n"))
	{
	case 1:
		std::cout << "Enter a new Title (max symbols - 20): ";
		std::cin.getline(taskTitle, 20);
		CheckingInput();
		break;
	case 2:
		std::cout << "Enter a new Text (max symbols - 64): ";
		std::cin.getline(taskText, 64);
		CheckingInput();
		break;
	case 3:
		do
		{
			std::cout << "Enter a new deadline (dd.mm.YYYY format): ";
			std::cin >> deadline.tm_mday >> deadline.tm_mon >> deadline.tm_year;
			CheckingInput();
			if (deadline.tm_mday < 1 || deadline.tm_mday > 31 || deadline.tm_mon < 1 || deadline.tm_mon > 12 || deadline.tm_year < 2025)
			{
				std::cout << "Enter the deadline using the format!" << std::endl;
			}
		} while (deadline.tm_mday < 1 || deadline.tm_mday > 31 || deadline.tm_mon < 1 || deadline.tm_mon > 12 || deadline.tm_year < 2025);
		break;
	}
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
		<< "Deadline: " << deadline.tm_mday << "." << deadline.tm_mon << "." << deadline.tm_year << std::endl
		<< "Status: " << taskStatus << std::endl << std::endl;
}

void Task::DeleteTask()
{
	Task::~Task();
	taskTitle = new char[20] {};
	taskText = new char[64] {};
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
	deadline = {};
	delete[] taskStatus;
	taskStatus = nullptr;
}