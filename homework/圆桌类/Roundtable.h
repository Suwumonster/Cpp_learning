#pragma once
#include "Circle.h"
#include "Table.h"
#ifndef _Roundtable_h_
#define _Roundtable_h_
class Roundtable :public Circle, public Table
{
public:
	Roundtable();
	Roundtable(float r, float h, char c[]);
	void display();
private:
	char color[10];
};
#endif 

