#pragma once
#include "task.h"
#include <vector>

using namespace std;

#define MAX_MATRIX_DIM	(10000)

struct MatrixGlobalData
{
	double		m1[MAX_MATRIX_DIM][MAX_MATRIX_DIM];
	double		m2[MAX_MATRIX_DIM][MAX_MATRIX_DIM];
	double		r[MAX_MATRIX_DIM][MAX_MATRIX_DIM]; 
};

struct MatrixLocalData
{
	int			start_line;
	int			line_count;
};

class CMatrixTask :	public CTask
{
public:

	CMatrixTask(int start_line, int line_count);

	virtual ~CMatrixTask(void);

	virtual void Exec();
};

