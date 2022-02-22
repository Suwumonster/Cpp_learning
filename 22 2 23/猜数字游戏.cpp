#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
using namespace std;
// 猜数字游戏 随机生成一个0-100的数字
// 输入数字根据生成数字 给出猜大 or 猜小
void menu()
{
	cout << "*************************" << endl;
	cout << "****   1.开始游戏    ****" << endl;
	cout << "****   0.退出游戏    ****" << endl;
	cout << "*************************" << endl;
	cout << "请输入你的选择:>";
}
void game()
{
	int num = rand() % 100 + 1;
	while (1)
	{
		int guess = 0;
		cout << "请猜数:>" << endl;
		cin >> guess;
		if (guess < num)
		{
			cout << "猜小了" << endl;
		}
		else if (guess > num)
		{
			cout << "猜大了" << endl;
		}
		else
		{
			cout << "恭喜你，猜对了！" << endl;
			break;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		cin >> input;
		if (input == 1)
		{
			game();
		}
	}
	while (input);
	return 0;
}