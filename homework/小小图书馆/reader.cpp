#define _CRT_SECURE_NO_WARNINGS 1
#include<iomanip>
#include "stdafx.h"
#include "reader.h"
Reader::Reader() :name{ 0 }, borbook{ 0 }//读者姓名 //所借图书
{
	note = 1;//删除标记（1：已删，0：未删）
	number = 0;//读者编号
}
char* Reader::getname()//获得姓名
{
	return name;
}
int Reader::getnote() //获得删除标记
{
	return note;
}
int Reader::getnumber()//获得读者编号
{
	return number;
}
void Reader::setname(char na[])//设置姓名
{
	strcpy(name, na);
}
void Reader::addreader(int n, char* na)//添加读者
{
	note = 0;
	number = n;
	strcpy(name, na);
	for (int i = 0; i < Maxbor; i++)
	{
		borbook[i] = 0;
	}
}
void Reader::delreader()//设置删除标记
{
	note = 1;
	number = 0;
	strcpy(name, "0");
	for (int i = 0; i < 5; i++)
	{
		borbook[i] = 0;
	}
}
void Reader::borrowbook(int bookid)//借书操作
{
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] == 0)
		{ 
			borbook[i] = bookid; 
			return ; 
		}
	}
}
int Reader::retbook(int bookid)//还书操作
{
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] == bookid) 
		{ 
			borbook[i] = 0; 
			return 1; 
		}
	}
	return 0;
}
void Reader::list()//输出读者信息
{
	cout << number << setw(13) << name << setw(10)  <<"   借书编号：[";
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] != 0)
		{
			cout << borbook[i] << " ";
		}
	}
	cout << "]" << endl;
}

int Reader::check()
{
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] != 0)
		{
			return 1;
		}
	}
	return 0;
}