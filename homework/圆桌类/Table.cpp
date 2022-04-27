#define _CRT_SECURE_NO_WARNINGS 1
#include "Table.h"
Table::Table()
{
	height = 0;
}
Table::Table(float x)
{
	height = x;
}
float Table::getheight()
{
	return height;
}