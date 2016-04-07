#pragma once

#include <iostream>
#include "Thread.h"
#include "Task.h"

using namespace std;

class ThreadPool;

class WorkThread : public Thread
{
public:
	WorkThread();
	virtual void run();
	void register_to_thread_pool(ThreadPool * tp);
	void execute_task(Task * task);

private:
	ThreadPool * thread_pool_;
};

