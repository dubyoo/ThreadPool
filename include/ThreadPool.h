#pragma once


#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "WorkThread.h"
#include "Task.h"

using namespace std;

typedef vector<WorkThread>::iterator THREADS_ITER;

class ThreadPool
{
public:
	ThreadPool(int threads_num);
	virtual ~ThreadPool();

	void start_thread_pool();
	void stop_thread_pool();

	bool add_task(Task* task);
	bool get_task(Task*& task);

	bool is_empty();
	bool is_full();

private:
	vector<WorkThread>	threads_;
	queue<Task*>		tasks_;
	mutex				mutex_;
	condition_variable	cond_;
	bool				is_started_;
};

