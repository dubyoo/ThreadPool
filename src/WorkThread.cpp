#include "WorkThread.h"
#include "ThreadPool.h"

WorkThread::WorkThread()
{

}

void WorkThread::run()
{
	while (true)
	{
		Task * task = nullptr;
		bool ret = thread_pool_->get_task(task);

		if (!ret)
			return;

		if (nullptr != task)
			execute_task(task);
	}
}

void WorkThread::register_thread_pool(ThreadPool * tp)
{
	thread_pool_ = tp;
}

void WorkThread::execute_task(Task * task)
{
	task->handle_task();
	delete task;
}
