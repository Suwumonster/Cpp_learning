#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h";
int search(student stu[])
{
	int mark = 0;
	int max = stu[0].avescore;
	int i = 0;
	for (i = 1; i < 5; i++)
	{
		if (max < stu[i].avescore)
		{
			max = stu[i].avescore;
			mark = i;
		}
	}
	return mark;
}