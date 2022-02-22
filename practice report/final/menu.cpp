#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "head.h"
using namespace std;
extern int(*mainp)();

int menu()
{
	system("cls");
	int option;
	static int level = 2;//难度
	static int plSet_cp = 5;//玩家设定自己的闯关关数
	int* pl = &level;
	int* pp = &plSet_cp;
	cout << "--------猜数字小游戏--------" << endl;
	cout << "           主菜单           " << endl;
	cout << "         1.开始游戏         " << endl;
	cout << "       2.查看游戏规则       " << endl;
	cout << "     3.设置游戏初始难易度   " << endl;
	cout << "        4.设置关卡数        " << endl;
	cout << "         5.结束游戏         " << endl;
	cout << "                    by:Suwu " << endl;
	cout << "输入选项编号进行选择：";
mark1:
	cin >> option;
	switch (option)
	{
	case 1:
		gameBegin(*pl , *pp);
		break;
	case 2:
		rule();
		break;
	case 3:
		settingLevel(pl);
		break;
	case 4:
		cpset(pp);
		break;
	case 5:
		return 0;
	default:
		cout << "你没有按照要求输入，请重新输入！" << endl;
		goto mark1;
	}
}



