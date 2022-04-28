#define _CRT_SECURE_NO_WARNINGS 1
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include <iostream>
using namespace std;
int main()
{
	float r, x, y, a;
	cout << "输入 圆的半径 矩形的长和宽 正方形的边长" << endl;
	cin >> r >> x >> y >> a;
	Circle C(r);
	Rectangle R(x,y);
	Square S(a);
	cout << "圆的面积:" << C.getarea() << endl;
	cout << "矩形的面积:" << R.getarea() << endl;
	cout << "正方形的面积:" << S.getarea() << endl;
	return 0;
}