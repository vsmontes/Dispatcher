#include <iostream>
#include <stdlib.h>

#include "Dispatcher.h"
#include "MatrixTask.h"


#define MAX_TASK_COUNT (1000)

int MATRIX_DIM = 13;

int THREAD_COUNT = 4;

int LINES_PER_THREAD = 5;

using namespace std;

int main(int argc, char ** argv)
{
	if (argc >= 4)
	{
		MATRIX_DIM = atoi(argv[1]);
		THREAD_COUNT = atoi(argv[2]);
		LINES_PER_THREAD = atoi(argv[3]);
	}
	else if (argc == 3)
	{
		MATRIX_DIM = atoi(argv[1]);
		THREAD_COUNT = atoi(argv[2]);
		LINES_PER_THREAD = (int)std::ceil((double)MATRIX_DIM/(double)THREAD_COUNT);
	}

	
	cout << "MATRIX_DIM : " << MATRIX_DIM << endl <<"THREAD_COUNT: " << THREAD_COUNT << endl << "LINES_PER_THREAD: " << LINES_PER_THREAD << endl; 

	CDispatcher	disp;

	CMatrixTask * mTask[MAX_TASK_COUNT];

	CMatrixTask::GlobalData = (void*)malloc(sizeof(MatrixGlobalData));

	MatrixGlobalData * gData = (MatrixGlobalData*)CMatrixTask::GlobalData;

	/*if (gData)
	{
		int count = 1;
		for (int i=0; i<MATRIX_DIM;i++)
		{
			for (int j=0; j<MATRIX_DIM;j++)
			{
				if (i==j)
				{
					gData->m1[i][j] = 2;		
					gData->m2[i][j] = 3;
				}
				else
				{
					gData->m1[i][j] = 0;		
					gData->m2[i][j] = 0;
				}
				gData->r[i][j] = 0;
				
				count++;
			}
		}
	}*/

	if (gData)
	{
		int count = 1;
		for (int i=0; i<MATRIX_DIM;i++)
		{
			for (int j=0; j<MATRIX_DIM;j++)
			{
				gData->m1[i][j] = rand();		
				gData->m2[i][j] = log10(rand());	
				gData->r[i][j] = 0;
				count++;
			}
		}
	}

	CMatrixTask::GlobalData = gData;

	int line_count = 0;
	int task_count = 0;
	for (int i=0; i< MAX_TASK_COUNT; i++)
	{
		mTask[i] = new CMatrixTask(line_count,LINES_PER_THREAD);
		line_count += LINES_PER_THREAD;
		task_count++;
		if (line_count == MATRIX_DIM)
			break;
		if (line_count > MATRIX_DIM)
		{
			line_count = MATRIX_DIM - (line_count - LINES_PER_THREAD);
			break;
		}
	}

	cout << "TASK COUNT: " << task_count << endl;

	for (int k=0; k<task_count; k++)
	{
		disp.m_Tasks.push(mTask[k]);
	}

	disp.m_ThreadCount = THREAD_COUNT;

	disp.Run();

#ifdef _DEBUG
	cout << "Results:" << endl;
	for (int i=0; i<MATRIX_DIM; i++)
	{
		for (int j=0; j<MATRIX_DIM; j++)
		{
			cout <<  ((MatrixGlobalData*)CMatrixTask::GlobalData)->r[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
#endif

	delete gData;

	return 0;
}