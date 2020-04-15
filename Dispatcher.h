#pragma once
#include <thread>
#include <queue>
#include <mutex>
#include "Task.h"

//#define NON_DETERMINISTIC_MODE

#define MAX_THREADS (100)

using namespace std;

class CDispatcher
{
public:

	bool m_Loop;

	std::queue<CTask*> m_Tasks;

	int m_ThreadCount;

	CDispatcher(void);

	~CDispatcher(void);

	void Run(void);

protected:

	mutex m_Mutex;

	thread	m_Threads[MAX_THREADS];

	void DoWork(void);
};

