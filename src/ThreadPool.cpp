
#include <iostream>
#include "ThreadPool.h"

using namespace std;

ThreadPool::ThreadPool(int threads_num)
	: threads_(threads_num)
	, tasks_()
	, is_started_(false)
{
	THREADS_ITER it = threads_.begin();
	for (; it != threads_.end(); ++it)
	{
		it->register_thread_pool(this);
	}
}

ThreadPool::~ThreadPool()
{
	stop_thread_pool();
}

void ThreadPool::start_thread_pool()
{
	if (is_started_)
		return;

	is_started_ = true;
	cout << "starting thread pool ..." << endl;

	THREADS_ITER it = threads_.begin();
	for (; it != threads_.end(); ++it)
	{
		it->start();
	}
}

void ThreadPool::stop_thread_pool()
{
	if (!is_started_)
		return;

	is_started_ = false;
	cout << "stopping thread pool ..." << endl;

	cond_.notify_all();
	THREADS_ITER it = threads_.begin();
	for (; it != threads_.end(); ++it)
	{
		cout << "join thread (" << it->get_thread_id() << ")." << endl;
		it->join();
	}

	cout << "====== TaskQueue left " << tasks_.size() << " tasks. ======" << endl;

	while (!is_empty())
	{
		Task * task = tasks_.front();
		tasks_.pop();
		delete task;
	}
}

bool ThreadPool::add_task(Task* task)
{
	unique_lock<mutex> lock(mutex_);

	if (!is_full() && is_started_)
	{
		tasks_.push(task);
		cond_.notify_one();
		return true;
	}

	return false;
}

bool ThreadPool::get_task(Task*& task)
{
	unique_lock<mutex> lock(mutex_);
	while (is_empty() && is_started_)
	{
		cond_.wait(lock);
	}

	if (is_started_)
	{
		task = tasks_.front();
		tasks_.pop();
		return true;
	}

	return false;
}

bool ThreadPool::is_empty()
{
	return tasks_.empty();
}

bool ThreadPool::is_full()
{
	return false;
}
