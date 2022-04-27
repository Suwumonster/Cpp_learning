#define _CRT_SECURE_NO_WARNINGS 1
#define PI 3.14
#include "Circle.h"
Circle::Circle()
{
	radius = 0;
}
Circle::Circle(float x)
{
	radius = x;
}
float Circle::getarea()
{
	return PI * radius * radius;
}