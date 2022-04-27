#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include "Roundtable.h"
using namespace std;
Roundtable::Roundtable(): color{0}{}
Roundtable::Roundtable(float r, float h, char c[]): Circle(r),Table(h)
{
	strcpy(color, c);
}
void Roundtable::display()
{
	cout << "圆桌信息如下:" << endl;
	cout << "圆桌桌面面积:" << Roundtable::getarea() << endl;
	cout << "圆桌高:" << Roundtable::getheight() << endl;
	cout << "圆桌颜色:" << color << endl;
}