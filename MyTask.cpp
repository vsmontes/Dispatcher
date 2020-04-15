#include "MyTask.h"


//
//
//MyTask::MyTask(void)
//{
//	MyData * myData = (MyData*)malloc(sizeof(MyData));
//
//	for (int i=0; i<DATA_SIZE;i++)
//	{
//		myData->data[i] = 1;
//	}
//
//	Data = myData;
//
//	DataSize = DATA_SIZE;
//}
//
//
//MyTask::~MyTask(void)
//{
//}
//
//
//void MyTask::Exec(void * data)
//{
//	MyData * mydata = (MyData*)data;
//
//	mydata->result = 0;
//	for (int i=0; i< DataSize; i++)
//		mydata->result += mydata->data[i];
//}