#include "Dispatcher.h"
#include "Task.h"
#include <chrono>
#include <iostream>


CDispatcher::CDispatcher(void)
{
	m_ThreadCount = 1;
}


CDispatcher::~CDispatcher(void)
{
	if ( ! m_Tasks.empty() )
		throw "Tasks left without processing";
}

void CDispatcher::Run(void)
{
	m_Loop = true;

	auto start_time = chrono::high_resolution_clock::now();

	for (int i=0; i< m_ThreadCount; i++)
	{
		m_Threads[i] = thread(&CDispatcher::DoWork,this);
	}

	for (int i=0; i< m_ThreadCount; i++)
	{
		if (m_Threads[i].joinable())
			m_Threads[i].join();
	}

	auto end_time = chrono::high_resolution_clock::now();

	cout << "Running time: " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << " ms"  << endl;
}

void CDispatcher::DoWork(void)
{
#ifdef NON_DETERMINISTIC_MODE
	while (m_Loop)
	{
#endif
		bool haveWork = false;
		CTask * task = NULL;
		void * data = NULL;

		m_Mutex.lock();

		if (!m_Tasks.empty())
		{
			task = m_Tasks.front();
			m_Tasks.pop();
			haveWork = true;
		}

		m_Mutex.unlock();

		if ((task)&&(haveWork))
			task->Exec();
#ifdef NON_DETERMINISTIC_MODE
		else
			break;
	}
#endif
}

