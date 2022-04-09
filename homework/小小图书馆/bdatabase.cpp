#define _CRT_SECURE_NO_WARNINGS 1
#include "stdafx.h"
#include<fstream>
#include"bdatabase.h"

BDatabase::BDatabase()//构造函数初始化：读文件
{
	Book s;
	top = -1;//图书记录指针
	fstream file;
	file.open("book.dat", ios::in | ios::binary);
	while (1)
	{
		file.read((char*)&s, sizeof(s));
		if (!file)
		{
			break;
		}
		top++;
		book[top] = s;//图书记录
	}
	file.close();
}
void BDatabase::clear()//全部删除
{
	int k = 0;
	for (int i = 0; k < top; i++)
	{
		if (book[i].getnote() == 0)
		{
			book[i].delbook();
			k++;
		}
	}
	top = -1;
}
Book* BDatabase::query(int bookid)//查找图书
{
	int k = 0;
	for (int i = 0; k <= top; i++)
	{
		if (book[i].getnote() == 0)
		{
			if (book[i].getnumber() == bookid)
			{
				return &book[i];
			}
			k++;
		}
	}
	return NULL;
}
int BDatabase::addbook(int n, char* na)//添加图书
{
	Book* p = query(n);
	if (p == NULL)
	{
		int k = 0;
		for (int i = 0; k < top; i++)
		{
			if (book[i].getnote() == 1)
			{
				book[i].addbook(n, na);
				top++;
				return 1;
			}
			else
			{
				k++;
			}
		}
		top++;
		book[top].addbook(n, na);
		return 1;
	}
	return 0;
}
void BDatabase::list()//输出图书信息
{
	int k = 0;
	for (int i = 0; k <= top; i++)
	{
		if (book[i].getnote() == 0)
		{
			book[i].list();
			k++;
		}
	}
}
BDatabase::~BDatabase() //析构函数：写文件
{
	fstream file;
	file.open("book.dat", ios::out | ios::binary);
	int k = 0;
	for (int i = 0; k <= top; i++)
	{
		if (book[i].getnote() == 0)
		{
			file.write((char*)&book[i], sizeof(book[i]));
			k++;
		}
	}
	file.close();
}
void BDatabase::bookdata()//图书库维护
{
	int choice = 1;
	char bookname[20];
	int bookid;
	Book* b;
	int temp = 0;
	char c;
	while (choice != 0)
	{
		system("cls");
		cout << "图书维护：" << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << "1:新增 2：更改书名 3：删除 4：查找 5：显示 6：全删 0：退出到主菜单" << endl;
		cin >> choice;
		cout << "--------------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1://新增书
			cout << "输入图书编号：";
			cin >> bookid;
			cout << "输入图书名：";
			cin >> bookname;
			temp = addbook(bookid, bookname); 
			if (temp)
			{
				cout << "增加成功" << endl;
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
			cout << "已有此书，增加失败" << endl;
			cout << "按 b 返回图书维护菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 2://更改书
			cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "更改失败！该图书不存在！" << endl;
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
			cout << "原来数据如下： 编号、图书名、在架(ps:1在架0不在架)" << endl;
			b->list();
			cout << "输入新的图书名：";
			cin >> bookname;
			b->setname(bookname); 
			cout << "更改成功！" << endl;
			cout << "按 b 返回图书维护菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 3://删除书
			cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "删除失败，该图书不存在！" << endl;
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
			if (b->borrowbook() == 0)//被借走了
			{
				cout << "删除失败，该图书被借走了，不在图书馆！" << endl;
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
			b->delbook();
			top--;
			cout << "已删除！" << endl;
			cout << "按 b 返回图书维护菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 4://查找
			cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "查找失败！该图书不存在！" << endl;
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
			cout << "数据如下： 编号、图书名、在架(ps:1在架0不在架)" << endl;
			b->list();
			cout << "按 b 返回图书维护菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 5://显示未删除书
			cout << "当前藏书" << top + 1 << "本" << endl;
			if (top + 1 != 0)
			{
				cout << "数据如下： 编号、图书名、在架(ps:1在架0不在架)" << endl;
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
		case 6://清除书
			clear();
			cout << "全删成功!" << endl;
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