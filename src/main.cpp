#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "ThreadPool.h"

int main()
{
	ThreadPool pool(10);
	pool.start_thread_pool();

	clock_t start_time = clock();
	std::srand((unsigned)start_time);

	int count = 20000;
	while (--count)
	{
		Task * cptask = new ComputeTask(std::rand(), std::rand());
		pool.add_task(cptask);
	}

	while (!pool.is_empty()) ;
	
	clock_t end_time = clock();
	double duration = (double)(end_time - start_time) / (double)CLOCKS_PER_SEC;
	cout << "====== Take time: " << duration << " ======" << endl;

	pool.stop_thread_pool();

	return 0;
}