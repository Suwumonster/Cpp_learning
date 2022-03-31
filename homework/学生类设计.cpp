#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int num = 0;//学生数量
class Student
{
public:
	Student();
	void SetInfo(int i, char n[20], char s, char d[5], char g[20], char l[20], char sc[20], char m[20]);
	void show();
private:
	int id;
	char name[20];
	char sex;
	char date[5];
	char grade[20];
	char lesson[20];
	char school[20];
	char major[20];
};
Student stu[50];
Student::Student() :name(""),date(""),grade(""),school(""), lesson(""),major("")
{
	id = 0;
	sex = 'u';//unknown
}
void Student::SetInfo(int i, char n[20],char s,char d[5], char g[20],char l[20], char sc[20], char m[20])
{
	id = i;
	strcpy(name, n);
	sex = s;
	strcpy(date, d);
	strcpy(grade, g);
	strcpy(lesson, l);
	strcpy(school, sc);
	strcpy(major, m);
	num++;
}
void Student::show()
{
	int i = 0;
	if (num == 0)
	{
		cout << "暂无学生信息" << endl;
	}
	else
	{
		cout << left << setw(15) << "学号 " << left << setw(15) << "姓名 " << left << setw(15) << "性别 ";
		cout << left << setw(15) << "出生日期 " << left << setw(15) << "年级 " << left << setw(15) << "班级 ";
		cout << left << setw(15) << "学院 " << left << setw(15) << "专业 " << endl;
		for (i = 0; i < num; i++)
		{
			cout << left << setw(15) << stu[i].id;
			cout << left << setw(15) << stu[i].name;
			cout << left << setw(15) << stu[i].sex;
			cout << left << setw(15) << stu[i].date;
			cout << left << setw(15) << stu[i].grade;
			cout << left << setw(15) << stu[i].lesson;
			cout << left << setw(15) << stu[i].school;
			cout << left << setw(15) << stu[i].major << endl;
		}
	}
}
int main()
{
	int i;
	char n[20]; 
	char s; 
	char d[5]; 
	char g[20]; 
	char l[20]; 
	char sc[20]; 
	char m[20];
	int j;
	while (1)
	{
		cout << "选项:" << endl;
		cout << "1.查看所有学生信息" << endl;
		cout << "2.修改/输入学生信息" << endl;
		cout << "0.退出程序" << endl;
		cin >> j;
		if (j == 0)
		{
			break;
		}
		else if (j == 1)
		{
			stu[0].show();
		}
		else if (j == 2)
		{
			int k;
			cout << "当前学生数目:" << num << endl;
			cout << "修改/输入第几位学生的信息?(必须<=50且<=(学生数目+1))" << endl;
			cin >> k;
			if (k <= 50 && k <= num + 1)
			{
				cout << "分别输入学号、姓名、性别(m/w)、出生日期(xxxx)、年级、班级、院系、专业" << endl;
				cin >> i >> n >> s >> d >> g >> l >> sc >> m;
				stu[k - 1].SetInfo(i, n, s, d, g, l, sc, m);
			}
			else
			{
				cout << "你输入的数不符合规格！" << endl;
			}
		}
	}
	return 0;
}