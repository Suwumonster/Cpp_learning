#pragma once
struct student
{
	int ID;//Ñ§ºÅ
	char classname[20];//°à¼¶
	char name[20];
	int score[3];
	float avescore;
};
void store(student stu[]);
void ave(student stu[]);
int search(student stu[]);


