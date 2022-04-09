#define _CRT_SECURE_NO_WARNINGS 1
#include "stdafx.h"
#include<fstream>
#include"rdatabase.h"
RDatabase::RDatabase()
{
	Reader s;
	top = -1;
	ifstream file;
	file.open("reader.dat", ios::in | ios::binary);
	while (1)
	{
		file.read((char*)&s, sizeof(s));
		if (!file)
		{
			break;
		}
		top++;
		read[top] = s;
	}
	file.close();
}
void RDatabase::clear()
{
	int k = 0;
	for (int i = 0; k < top; i++)
	{
		if (read[i].getnote() == 0)
		{
			read[i].delreader();
			k++;
		}
	}
	top = -1;
}
Reader* RDatabase::query(int readerid)
{
	int k = 0;
	for (int i = 0; k <= top; i++)
	{
		if (read[i].getnote() == 0)
		{
			if (read[i].getnumber() == readerid)
			{
				return &read[i];
			}
			k++;
		}
	}
	return NULL;
}
int RDatabase::addreader(int n, char* na)
{
	Reader* p = query(n);
	if (p == NULL)
	{
		int k = 0;
		for (int i = 0; k < top; i++)
		{
			if (read[i].getnote() == 1)
			{
				read[i].addreader(n, na);
				top++;
				return 1;
			}
			else
			{
				k++;
			}
		}
		top++;
		read[top].addreader(n, na);
		return 1;
	}
	return 0;
}
void RDatabase::list()
{
	int k = 0;
	for (int i = 0; k <= top; i++)
	{
		if (read[i].getnote() == 0)
		{
			read[i].list();
			k++;
		}
	}
}
RDatabase::~RDatabase()
{
	fstream file;
	file.open("reader.dat", ios::out | ios::binary);
	int k = 0;
	for (int i = 0; k <= top; i++)
	{
		if (read[i].getnote() == 0)
		{
			file.write((char*)&read[i], sizeof(read[i]));
			k++;
		}
	}
	file.close();
}
void RDatabase::readerdata()
{
	int choice = 1;
	char readername[20];
	int readerid;
	char c;
	int temp;
	Reader* r;
	while (choice != 0)
	{
		system("cls");
		cout << "读者维护：" << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "1:新增 2：更改 3：删除 4：查找 5：显示 6：全删 0：退出到主菜单" << endl;
		cin >> choice;
		cout << "------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:
			cout << "输入读者编号：";
			cin >> readerid;
			cout << "输入读者姓名：";
			cin >> readername;
			temp = addreader(readerid, readername); 
			if (temp)
			{
				cout << "增加成功！" << endl;
				cout << "按 b 返回图书维护菜单" << endl;
				while (cin >> c)
				{
					if (c == 'b')
					{
						break;
					}
				}
				break;
			}
			cout << "已有此读者，增加失败！" << endl;
			cout << "按 b 返回图书维护菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 2:
			cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				cout << "按 b 返回图书维护菜单" << endl;
				while (cin >> c)
				{
					if (c == 'b')
					{
						break;
					}
				}
				break;
			}
			cout << "原信息如下：" << endl;
			cout << "编号    姓名" << endl;
			r->list();
			cout << "输入新的姓名：";
			cin >> readername;
			r->setname(readername); 
			cout << "修改成功！" << endl;
			cout << "按 b 返回图书维护菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 3:
			cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				cout << "按 b 返回图书维护菜单" << endl;
				while (cin >> c)
				{
					if (c == 'b')
					{
						break;
					}
				}
				break;
			}
			if (r->check())//还有书没还
			{
				cout << "注销失败，该读者有书未还！" << endl;
				cout << "按 b 返回图书维护菜单" << endl;
				while (cin >> c)
				{
					if (c == 'b')
					{
						break;
					}
				}
				break;
			}
			r->delreader();
			top--;
			cout << "删除读者成功！" << endl;
			cout << "按 b 返回图书维护菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 4:
			cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				cout << "按 b 返回图书维护菜单" << endl;
				while (cin >> c)
				{
					if (c == 'b')
					{
						break;
					}
				}
				break;
			}
			cout << "找到了！" << endl;
			cout << "信息如下：" << endl;
			cout << "编号    姓名" << endl;
			r->list(); 
			cout << "按 b 返回图书维护菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 5:
			cout << "当前读者有" << top + 1 << "人" << endl;
			if (top + 1 != 0)
			{
				cout << "编号    姓名" << endl;
				list();
			}
			cout << "按 b 返回图书维护菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 6:
			clear();
			cout << "按 b 返回图书维护菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 0:
			break;
		default:
			cout << "输入错误!" << endl;
			Sleep(1000);
			break;
		} //end switch
	} //end while
}