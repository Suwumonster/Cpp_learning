#define _CRT_SECURE_NO_WARNINGS 1
#include "stdafx.h"
#include "reader.h"
#include "rdatabase.h"
#include "book.h"
#include "bdatabase.h"
int main(int argc, char* argv[])
{
	int choice = 1, bookid, readerid;
	RDatabase ReaderDB;
	BDatabase BookDB;
	Reader* r;
	Book* b;
	char c;
	cout << "欢迎进入“小小图书馆”管理软件" << endl;
	cout << "------------------------------" << endl;
	while (choice != 0)
	{
		system("cls");
		cout << "----------------------------------------------" << endl;
		cout << "1: 借书 2 还书 3: 图书维护 4: 读者维护 0: 离开" << endl;
		cin >> choice;
		cout << "----------------------------------------------" << endl;
		switch (choice)
		{
		case 1:
			cout << "输入借书读者编号" << endl;
			cin >> readerid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在，不能借书！" << endl;
				cout << "按 b 返回菜单" << endl;
				while (cin >> c)
				{
					if (c == 'b')
					{
						break;
					}
				}
				break;
			}
			cout << "数据如下： 编号、图书名、在架(ps:1在架0不在架)" << endl;
			BookDB.list();
			cout << "输入图书编号" << endl;
			cin >> bookid;
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在，不能借书！" << endl;
				cout << "按 b 返回菜单" << endl;
				while (cin >> c)
				{
					if (c == 'b')
					{
						break;
					}
				}
				break;
			}
			if (b->borrowbook() == 0)
			{
				cout << "该图书已借出，不能借书！" << endl;
				cout << "按 b 返回菜单" << endl;
				while (cin >> c)
				{
					if (c == 'b')
					{
						break;
					}
				}
				break;
			}
			cout << "借书成功！" << endl;
			r->borrowbook(b->getnumber()); 
			cout << "按 b 返回菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 2:
			cout << "输入还书读者编号" << endl;
			cin >> readerid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在，不能还书！" << endl;
				cout << "按 b 返回菜单" << endl;
				while (cin >> c)
				{
					if (c == 'b')
					{
						break;
					}
				}
				break;
			}
			cout << "数据如下： 编号、图书名、在架(ps:1在架0不在架)" << endl;
			BookDB.list();
			cout << "输入图书编号" << endl;
			cin >> bookid;
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在，不能还书！" << endl;
				cout << "按 b 返回菜单" << endl;
				while (cin >> c)
				{
					if (c == 'b')
					{
						break;
					}
				}
				break;
			}
			if (r->retbook(b->getnumber()) == 0)
			{
				cout << "该读者没有这本书，不能还书！" << endl;
				cout << "按 b 返回菜单" << endl;
				while (cin >> c)
				{
					if (c == 'b')
					{
						break;
					}
				}
				break;
			}
			cout << "还书成功！" << endl;
			b->retbook();
			r->retbook(b->getnumber()); 
			cout << "按 b 返回菜单" << endl;
			while (cin >> c)
			{
				if (c == 'b')
				{
					break;
				}
			}
			break;
		case 3:
			BookDB.bookdata(); 
			break;
		case 4:
			ReaderDB.readerdata(); 
			break;
		case 0:
			break;
		default:
			cout << "输入错误!" << endl;
			Sleep(1000);
			break;
		}//end switch
	}//end while
	return 0;
}