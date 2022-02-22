#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Windows.h>
#include "head.h"
using namespace std;
extern int(*mainp)();

void settingLevel(int* p)
{
	system("cls");
	char ch = 0;
	cout << "当前难度为" << *p << endl;
	cout << "设置游戏初始难度(PS:默认难度为2且难度必须大于等于2)：";

	mark1:
	cin >> *p;
	if (*p >= 2)
	{
		cout << "你设置的游戏难度为：" << *p << endl;
		cout << "输入b返回主菜单" << endl;
	}
	else
	{
		cout << "你没有按照要求输入，请重新输入！" << endl;
		goto mark1;
	}

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