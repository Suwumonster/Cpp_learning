#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <cmath>
#include "head.h"
using namespace std;
extern int (*mainp)();
void gameBegin(int n, int x)//n是难度、x是关卡数
{
	mark:
	system("cls");
	int j;
	int checkpoint;//游戏关卡
	static int change = 10;//猜测次数
	int guess;//玩家将输入的数字
	int score1 = 0, score2 = 0;//个数分、准确分
	int* ps1 = &score1;
	int* ps2 = &score2;
	srand((unsigned)time(NULL));
	for(checkpoint = 1; checkpoint <= x; checkpoint++)
	{
		cout << "一共有" << x << "关" << endl;
		cout << "当前是第" << checkpoint << "关" << endl;
		cout << "难度为" << n << endl;
		int number = rand() % ((int)pow(10, n) - (int)pow(10, checkpoint)) + (int)pow(10, checkpoint);//生成随机数
		int* pn = &number;
		int* pg = &guess;
		for (j = change; j > 0; j--)
		{
			check(pg, number, ps1, ps2, n);
			cout << "个数分为" << *ps1 << endl;
			cout << "准确分为" << *ps2 << endl;
			cout << "剩余可猜测次数" << j-1 << endl;
			if (*pg == number)
			{
				break;
			}
		}
		if (*pg != number && j == 0)
		{
			cout << "可猜测次数已用完，你输掉了游戏!" << endl;
			break;
		}
		if (checkpoint == x && *pg == number)
		{
			cout << "恭喜你赢得游戏！" << endl;
			break;
		}
		change += 10;
		n++;
	}
	char ch = 0;
	cout << "输入b返回主菜单，输入r重玩游戏。" << endl;
	cin >> ch;
	if (ch == 'b')
	{
		mainp();
	}
	else if (ch == 'r')
	{
		goto mark;
	}
}