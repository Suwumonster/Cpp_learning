#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int num = 0;//员工个数
class Date
{
public:
	Date() :year(0), month(0), day(0) {};
	void SetYear(int y);
	void SetMonth(int m);
	void SetDay(int d);
	int GetYear();
	int GetMonth();
	int GetDay();
private:
	int year;
	int month;
	int day;
};
class employee
{
public:
	employee() :id(""), name(""), sex('u'), job("") {};
	void set();
	void show();
	friend int emp(employee& e, char n[20]);
private:
	char id[20];
	char name[20];
	char sex;
	Date date;
	char job[20];
};
employee em[50];
void employee::set()
{
	char i[20];
	char n[20];
	char s;
	int y1, m1, d1;
	char j[20];
	cin >> i >> n >> s;
	cin >> y1 >> m1 >> d1;
	cin >> j;
	strcpy(id, i);
	strcpy(name, n);
	sex = s;
	date.SetYear(y1);
	date.SetMonth(m1);
	date.SetDay(d1);
	strcpy(job, j);
}
void employee::show()
{
	cout << "编号:" << id << '\t';
	cout << "姓名:" << name << '\t';
	cout << "性别:" << sex << '\t';
	cout << "出生日期:" << date.GetYear() << "年" << date.GetMonth() << "月" << date.GetDay() << "日" << '\t';
	cout << "职位:" << job << endl;
}
int emp(employee&e,char n[20])
{
	if ((strcmp(e.id, n) == 0) || (strcmp(e.name, n) == 0))
	{
		cout << "找到了！" << endl;
		e.show();
		return 1;
	}
	else
	{
		return 0;
	}
}
void Date::SetYear(int y)
{
	year = y;
}
void Date::SetMonth(int m)
{
	month = m;
}
void Date::SetDay(int d)
{
	day = d;
}
int Date::GetYear()
{
	return year;
}
int Date::GetMonth()
{
	return month;
}
int Date::GetDay()
{
	return day;
}
int main()
{
	int k;
	while (1)
	{
		cout << "选项:" << endl;
		cout << "1.录入/修改员工信息" << endl;
		cout << "2.展示员工信息" << endl;
		cout << "3.通过编号/姓名查看员工信息" << endl;
		cout << "0.退出程序" << endl;
		cin >> k;
		if (k == 0)
		{
			break;
		}
		else if (k == 1)
		{
			int j;
			cout << "当前员工数目:" << num << endl;
			cout << "修改/输入第几位员工的信息?(必须<=50且<=(员工数目+1))" << endl;
			cin >> j;
			if (j <= 50 && j <= num + 1)
			{
				cout << "分别输入编号、姓名、性别(m/w)、出生日期(xxxx xx xx)、职位" << endl;
				em[j - 1].set();
				num++;
			}
			else
			{
				cout << "你输入的数不符合规格！" << endl;
			}
		}
		else if (k == 2)
		{
			if (num == 0)
			{
				cout << "暂无员工信息" << endl;
			}
			else
			{
				int count = 0;
				for (count = 0; count < num; count++)
				{
					em[count].show();
				}
			}
		}
		else if (k == 3)
		{
			cout << "请输入姓名或者编号:";
			char temp[20];
			cin >> temp;
			int i = 0;
			for (i = 0; i < num; i++)
			{
				if (emp(em[i], temp))
				{
					break;
				}
			}
			if (i == num)
			{
				cout << "查无此人" << endl;
			}
		}
	}
	return 0;
}