#define _CRT_SECURE_NO_WARNINGS 1
#include "Rectangle.h"
Rectangle::Rectangle()
{
	x = 0;
	y = 0;
}
Rectangle::Rectangle(float a, float b)
{
	x = a;
	y = b;
}
float Rectangle::getarea()
{
	return x * y;
}