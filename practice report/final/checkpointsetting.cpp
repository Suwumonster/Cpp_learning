#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Windows.h>
using namespace std;
extern int(*mainp)();
void cpset(int * p)
{
	system("cls");
	char ch = 0;
	cout << "当前关卡数为" << *p << endl;
	cout << "设置关卡数：";
	cin >> *p;
	cout << "你输入的关卡数为" << *p << endl;
	cout << "输入b返回主菜单" << endl;
mark2:
	cin >> ch;
	if (ch == 'b')
	{
		mainp();
	}
	else
	{
		cout << "你输入的字符不是b，请重新输入！" << endl;
		goto mark2;
	}
}