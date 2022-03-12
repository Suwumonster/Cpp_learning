#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "head.h";
using namespace std;
void store(student stu[])
{
	int i = 0;
	cout << "请输入学号、班级、姓名、三门课成绩" << endl;
	for (i = 0; i < 5; i++)
	{
		cout << "第"<< i + 1 << "个学生" << endl;
		cin >> stu[i].ID;
		cin >> stu[i].classname;
		cin >> stu[i].name;
		cin >> stu[i].score[0];
		cin >> stu[i].score[1];
		cin >> stu[i].score[2];
	}
}