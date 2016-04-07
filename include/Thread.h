#pragma once

#include <thread>


class Thread
{
public:
	void start();
	virtual void run() = 0;
	void join();
	std::thread::id get_thread_id() const;
	void thread_task();

private:
	std::thread thread_;
};

