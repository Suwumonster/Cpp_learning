#pragma once
class Circle
{
public:
	Circle();
	Circle(int a, int b, int c) :x(a), y(b), r(c) {};
	float getarea();
	void show();
	void set(int a, int b, int c);
private:
	int x;
	int y;
	int r;
};
class Rectangle
{
public:
	Rectangle();
	Rectangle(int x, int y) :length(x), wide(y) {};
	int getarea();
	void show();
	void set(int x, int y);
private:
	int length;
	int wide;
};
class Triangle
{
public:
	Triangle();
	Triangle(int a, int b, int c, int d, int e, int f)
		:x1(a), y1(b), x2(c), y2(d), x3(e), y3(f) {};
	double getarea();
	void show();
	void set(int a, int b, int c, int d, int e, int f);
private:
	int x1, y1;
	int x2, y2;
	int x3, y3;
};
