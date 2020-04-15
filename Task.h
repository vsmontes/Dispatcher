#pragma once
#include <stdlib.h>

class CTask
{
public:

	static void *	GlobalData;

	CTask(void);

	~CTask(void);

	virtual void	Exec();

	void *			LocalData;
};

