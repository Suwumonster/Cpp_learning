#pragma once
#include "Shape.h"
#ifndef _Circle_h_
#define _Circle_h_
class Circle :Shape
{
public:
	Circle();
	Circle(float);
	float getarea();
private:
	float r;
};
#endif
