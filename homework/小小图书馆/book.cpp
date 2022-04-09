#define _CRT_SECURE_NO_WARNINGS 1
#include <iomanip>
#include "stdafx.h"
#include "book.h"
Book::Book() :name{ 0 }//书名
{
	note = 1;//删除标记（1：已删，0：未删）
	number = 0;//图书编号
	onshelf = 0;//上架标志 (1: 在架 0：不在架)
};
char* Book::getname()//获得书名
{
	return name;
}
int Book::getnote()//获得删除标记
{
	return note;
}
int Book::getnumber()//获得图书编号
{
	return number;
}
void Book::setname(char na[])//设置书名
{
	strcpy(name, na);
}
void Book::addbook(int n, char* na)//添加图书
{
	note = 0;
	number = n;
	strcpy(name, na);
	onshelf = 1;
}
void Book::delbook()//删除图书
{
	strcpy(name, "0");
	note = 1;
	number = 0;
	onshelf = 0;
}
int Book::borrowbook()//借书操作
{
	if (onshelf == 1)
	{
		onshelf = 0;
		return 1;
	}
	return onshelf;
}
void Book::retbook()//还书操作
{
	onshelf = 1;
}
void Book::list()//输出图书
{
	if (note != 1)
	{
		cout << setw(10) << number << setw(10) << name << setw(10) << onshelf << endl;
	}
}