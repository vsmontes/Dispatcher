#include "MatrixTask.h"
#include <iostream>

using namespace std;

extern int MATRIX_DIM;

CMatrixTask::CMatrixTask(int start_line, int line_count)
{
	MatrixGlobalData * Data = (MatrixGlobalData*)CMatrixTask::GlobalData;

	LocalData = (MatrixLocalData*)malloc(sizeof(MatrixLocalData));

	if (Data)
	{
		((MatrixLocalData*)LocalData)->line_count = line_count;
		((MatrixLocalData*)LocalData)->start_line = start_line;
	}
	else
	{
		cout << "erro" << endl;
	}
}


CMatrixTask::~CMatrixTask(void)
{

}


void CMatrixTask::Exec()
{
	MatrixGlobalData * Data = (MatrixGlobalData*)CMatrixTask::GlobalData;

	MatrixLocalData * mydata = (MatrixLocalData*)LocalData;

	int end_line = mydata->start_line + mydata->line_count;

	for (unsigned int i=mydata->start_line; i< end_line; i++)
	{
		for (unsigned int j=0; j< MATRIX_DIM; j++)
		{
			for (unsigned int lc=0; lc< MATRIX_DIM; lc++)
			{
				Data->r[i][j] += Data->m1[i][lc] * Data->m2[lc][j];
				
			}
			//cout << Data->r[i][j] << "\t";
		}
		//cout << endl;
	}
}
