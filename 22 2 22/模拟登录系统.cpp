#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;
// 模拟登录 最多登录三次 登录成功则显示
int main()
{
	int i = 0;
	char password[] = "suwu123";
	char inword[20] = { 0 };
	cout << "请输入密码 :>" << endl;
	for (i = 0; i < 3; i++)
	{
		cin >> inword;
		if (strcmp(password, inword) == 0)
		{
			cout << "登录成功！" << endl;
			break;
		}
		else
		{
			cout << "密码错误，请重新输入！" << endl;
		}
	}
	if (i == 3)
	{
		cout << "三次机会已用完，登录失败！" << endl;
	}
	return 0;
}