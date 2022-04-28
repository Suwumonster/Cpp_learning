#pragma once
#include "Shape.h"
#ifndef _Rectangle_h_
#define _Rectangle_h_
class Rectangle:Shape
{
public:
	Rectangle();
	Rectangle(float, float);
	float getarea();
private:
	float x;
	float y;
};
#endif
