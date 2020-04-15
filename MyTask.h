#pragma once
#include "task.h"

#define DATA_SIZE (3000)

struct MyData
{
	double result;
	double data[DATA_SIZE];
};

class MyTask :
	public CTask
{
public:
	MyTask(void);
	~MyTask(void);

	virtual void Exec(void * data);
};

