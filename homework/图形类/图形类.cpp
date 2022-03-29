#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "c-head.h"
using namespace std;
Circle cir;
Rectangle rec;
Triangle tri;
void circle();
void rectangle();
void triangle();
int main()
{
	int i;
	while (1)
	{
		cout << "选择一种图形类:" << endl;
		cout << "1.圆" << endl;
		cout << "2.矩形" << endl;
		cout << "3.三角形" << endl;
		cout << "0.退出程序" << endl;
		cin >> i;
		if (i == 0)
		{
			break;
		}
		else if (i == 1)
		{
			circle();
		}
		else if (i == 2)
		{
			rectangle();
		}
		else if (i == 3)
		{
			triangle();
		}
	}
	return 0;
}

void circle()
{
	int n;
	int x, y, z;
	while (1)
	{
		cout << "选项:" << endl;
		cout << "1.定义圆心坐标和半径" << endl;
		cout << "2.展示圆的基本信息" << endl;
		cout << "3.求面积" << endl;
		cout << "0.退出圆类" << endl;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		else if (n == 1)
		{
			cin >> x >> y >> z;
			cir.set(x, y, z);
		}
		else if (n == 2)
		{
			cir.show();
		}
		else if (n == 3)
		{
			cout << cir.getarea() << endl;
		}
	}
}
void rectangle()
{
	int n;
	int x, y;
	while (1)
	{
		cout << "选项:" << endl;
		cout << "1.定义矩形的长和宽" << endl;
		cout << "2.展示矩形的基本信息" << endl;
		cout << "3.求面积" << endl;
		cout << "0.退出矩形类" << endl;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		else if (n == 1)
		{
			cin >> x >> y;
			rec.set(x, y);
		}
		else if (n == 2)
		{
			rec.show();
		}
		else if (n == 3)
		{
			cout << rec.getarea() << endl;
		}
	}
}

void triangle()
{
	int n;
	int a, b, c, d, e, f;
	while (1)
	{
		cout << "选项:" << endl;
		cout << "1.定义三角形的三点坐标" << endl;
		cout << "2.展示三角形的基本信息" << endl;
		cout << "3.求面积" << endl;
		cout << "0.退出三角形类" << endl;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		else if (n == 1)
		{
			cin >> a >> b >> c >> d >> e >> f;
			tri.set(a, b, c, d, e, f);
		}
		else if (n == 2)
		{
			tri.show();
		}
		else if (n == 3)
		{
			cout << tri.getarea() << endl;
		}
	}
}