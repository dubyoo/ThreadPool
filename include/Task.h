#pragma once


class Task
{
public:
	Task();
	virtual ~Task();
	virtual bool handle_task();
};



class ComputeTask : public Task
{
public:
	ComputeTask(int n1, int n2);
	virtual ~ComputeTask();
	virtual bool handle_task();

private:
	int n1_;
	int n2_;
};

