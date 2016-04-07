#include <iostream>
#include <unistd.h>
#include "Task.h"

Task::Task()
{

}

Task::~Task()
{

}

bool Task::handle_task()
{
	std::cout << "Task::handle_task" << std::endl;
	return false;
}


ComputeTask::ComputeTask(int n1, int n2)
	: n1_(n1)
	, n2_(n2)
{

}

ComputeTask::~ComputeTask()
{

}

bool ComputeTask::handle_task()
{
	int result = n1_ * n2_;
	usleep(2000);				// sleep 2ms (simulate executing time)
//  std::cout << n1_ << " * " << n2_ << " = " << result << std::endl;
	return result;
}
