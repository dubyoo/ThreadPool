#include <iostream>
#include <functional>
#include "Thread.h"


void Thread::start()
{
	thread_ = std::thread(std::mem_fn(&Thread::thread_task), this);			// create thread, bind thread function
	std::cout << "start thread(" << get_thread_id() << ")." << std::endl;
}

void Thread::join()
{
	thread_.join();
}

std::thread::id Thread::get_thread_id() const
{
	return thread_.get_id();
}

void Thread::thread_task()
{
	run();
}
