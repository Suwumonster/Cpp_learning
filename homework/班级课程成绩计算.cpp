#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Id_avesco(int id[], int sco[][5], float avesco[]);
void avescore(int(* p)[5][5]);
int main()
{
	int id[5] = { 0 };//学号
	int sco[5][5] = { 0 };//分数
	float avesco[5] = { 0 };//学生平均分
	int(*p)[5][5] = &sco;
	Id_avesco(id, sco, avesco);
	avescore(p);
	return 0;
}
void Id_avesco(int id[], int sco[][5], float avesco[])
{
	int i, j = 0;

	for (i = 0; i < 5; i++)//输入学号和成绩
	{
		printf("请输入学号:>");
		scanf("%d", &id[i]);
		printf("请输入五门成绩:>\n");
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &sco[i][j]);
			avesco[i] += sco[i][j];
		}
		avesco[i] /= 5.0;
	}

	for (i = 0; i < 5; i++)//输出学号和成绩
	{
		printf("学号:%d 成绩:\n", id[i]);
		for (j = 0; j < 5; j++)
		{
			if (j != 0)
			{
				printf(" ");
			}
			printf("%d", sco[i][j]);
		}
		printf("\n");
		printf("平均成绩:%f\n", avesco[i]);
	}
}

void avescore(int (*p)[5][5])
{
	int i, sum = 0;
	int n;
	printf("要求第几门课程的平均分？:>");
	scanf("%d", &n);
	for (i = 0; i < 5; i++)
	{
		sum += *(*(*p + i) + (n - 1));
	}
	printf("%f", sum/5.0);
}