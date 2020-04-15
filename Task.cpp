#include "Task.h"

void *	CTask::GlobalData;

CTask::CTask(void)
{
	LocalData = NULL;

}


CTask::~CTask(void)
{
	if (LocalData)
		delete LocalData;
}


void CTask::Exec()
{
}