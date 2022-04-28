#define _CRT_SECURE_NO_WARNINGS 1
#define PI 3.14
#include "Circle.h"
Circle::Circle()
{
	r = 0;
}
Circle::Circle(float x)
{
	r = x;
}
float Circle::getarea()
{
	return PI * r * r;
}