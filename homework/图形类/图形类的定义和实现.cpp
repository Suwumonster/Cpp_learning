#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
#include "c-head.h"
using namespace std;

Circle::Circle()
{
	x = 1;
	y = 1;
	r = 1;
}
float Circle::getarea()
{
	return 3.14 * r * r;
}
void Circle::show()
{
	cout << "圆心坐标为:(" << x << "," << y << ")." << endl;
	cout << "半径为:" << r << endl;
	cout << "直径为:" << 2 * r << endl;
	cout << "周长为:" << 2 * 3.14 * r << endl;
	cout << "面积为:" << getarea() << endl;
}
void Circle::set(int a, int b, int c)
{
	x = a;
	y = b;
	r = c;
}


Rectangle::Rectangle()
{
	length = 10;
	wide = 5;
}
int Rectangle::getarea()
{
	return length * wide;
}
void Rectangle::show()
{
	cout << "长方形的长、宽分别为:" << length << "," << wide << endl;
	cout << "周长为:" << length + wide << endl;
	cout << "面积为:" << getarea() << endl;
}
void Rectangle::set(int x, int y)
{
	length = x;
	wide = y;
}


Triangle::Triangle()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 1;
	x3 = 1;
	y3 = 0;
}
double Triangle::getarea()
{
	return abs((1.0 / 2) * (x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2));
}
void Triangle::show()
{
	float x, y, z = 0;
	x = sqrt((x2 - x1)* (x2 - x1) + (y2 - y1)* (y2 - y1));
	y = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	z = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	cout << "坐标为:(" << x1 << "," << y1 << ")." << endl;
	cout << "坐标为:(" << x2 << "," << y2 << ")." << endl;
	cout << "坐标为:(" << x3 << "," << y3 << ")." << endl;
	cout << "三边长分别为:" << x << "," << y << "," << z << endl;
	cout << "周长为:" << x + y + z << endl;
	cout << "面积为:" << getarea() << endl;
}
void Triangle::set(int a, int b, int c, int d, int e, int f)
{
	int x, y, n, m = 0;
	x = a - c;
	y = b - d;
	n = c - e;
	m = d - f;
	float i, j, k = 0;
	i = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	j = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	k = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	if ( (x*m != y*n) && (i + j > k))
	{
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
		x3 = e;
		y3 = f;
	}
	else
	{
		cout << "输入的坐标不能构成三角形！" << endl;
	}
}
