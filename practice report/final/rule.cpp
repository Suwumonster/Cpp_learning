#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Windows.h>
#include "head.h"
using namespace std;
extern int(*mainp)();

void rule()
{
	system("cls");
	char ch = 0;
	cout << "游戏规则如下：" << endl;
	cout << "玩法：" << endl;
	cout << "电脑在每一关开头随机给出一个数字（不显示，需要你猜）" << endl;
	cout << "数字的位数=游戏难度" << endl;
	cout << "1.猜测---电脑会给出此次你猜测所得分数" << endl;
	cout << "2.根据上一次猜测所得分数猜测" << endl;
	cout << "猜对进入下一关，没猜对继续猜测，猜测次数用完输掉游戏！" << endl;
	cout << "闯完5关，赢得游戏！" << endl;
	cout << endl;
	cout << "关卡：" << endl;
	cout << "默认关卡数为5" << endl;
	cout << "可以在主菜单修改" << endl;
	cout << endl;
	cout << "游戏难度：" << endl;
	cout << "游戏初始难易度，即第一关的难度，默认为2。" << endl;
	cout << "游戏初始难度可以在主菜单设定。" << endl;
	cout << "每过一关游戏难度加一。" << endl;
	cout << endl;
	cout << "分数：" << endl;
	cout << "分数分为两种，第一种是个数分，" << endl;
	cout << "即你猜对该数的个数（无位置要求） 假如 电脑给出的是123 ，" << endl;
	cout << "你猜的是 144 或者 414 你所得的个数分都是1" << endl;
	cout << "第二种是准确分" << endl;
	cout << "即猜数准确程度，假设 给出123" << endl;
	cout << "你猜 124 得准确分2分，你猜 134 得 1 分" << endl;
	cout << "猜对几个得几分（有位置要求）" << endl;
	cout << endl;
	cout << "猜测次数，初始次数为10，每过一关加10,猜测一次减1。" << endl;
	cout << endl;
	cout << "输入b返回主菜单" << endl;

	mark:
	cin >> ch;
	if (ch == 'b')
	{
		mainp();
	}
	else
	{
		cout << "你输入的字符不是b，请重新输入！" << endl;
		goto mark;
	}
}