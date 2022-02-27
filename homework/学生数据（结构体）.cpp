#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//有10个学生，每个学生的数据包括学号、姓名、3门课的成绩，从键盘输入10个学生数据，要求
//打印出3门课总平均成绩，以及最高分的学生的数据（包括学号、姓名、3门课成绩、平均分数）
struct student
{
	char id[20];
	char name[20];
	int pj1;
	int pj2;
	int pj3;
	double average;
};
int main()
{
	student s[10] = { 0 };
	int i = 0;
	int maxMark = 0;//最高分学生的下标
	int max = 0;//最高平均分
	double As1 = 0;//第一科的总平均分
	double As2 = 0;//第二科的总平均分
	double As3 = 0;//第三科的总平均分

	for (i = 0; i < 10; i++)//输入数据
	{
		cout << "请输入第" << i + 1 << "位同学的学号、姓名、3门课的成绩（分别输入）" << endl;
		cin >> s[i].id;
		cin >> s[i].name;
		cin >> s[i].pj1;
		cin >> s[i].pj2;
		cin >> s[i].pj3;
		s[i].average = (s[i].pj1 + s[i].pj2 + s[i].pj3) / 3.0;
	}

	for (i = 0; i < 10; i++)//计算各科总平均分
	{
		As1 += s[i].pj1;
		As2 += s[i].pj2;
		As3 += s[i].pj3;
	}
	As1 /= 10.0;
	As2 /= 10.0;
	As3 /= 10.0;
	cout << "各科总平均分如下：" << endl;
	cout << As1 << '\t';
	cout << As2 << '\t';
	cout << As3 << endl;

	max = s[0].average;//先假设平均分最高的是第一位同学
	for (i = 1; i < 10; i++)//比较选出最高分的同学
	{
		if (max < s[i].average)
		{
			max = s[i].average;
			maxMark = i;
		}
	}
	cout << "最高分的学生的数据如下：" << endl;
	cout << s[maxMark].id << '\t';
	cout << s[maxMark].name << '\t';
	cout << s[maxMark].pj1 << '\t';
	cout << s[maxMark].pj2 << '\t';
	cout << s[maxMark].pj3 << '\t';
	cout << s[maxMark].average << endl;
	return 0;
}