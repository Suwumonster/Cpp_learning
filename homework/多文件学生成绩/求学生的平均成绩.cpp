#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h";
void ave(student stu[])
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		stu[i].avescore = stu[i].score[0] + stu[i].score[1] + stu[i].score[2];
		stu[i].avescore /= 3.0;
	}
}