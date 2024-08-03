#define _CRT_SECURE_NO_WARNINGS 1
#include "BST.h"

namespace my_stl
{
	//no V only K
	void test1()//测试Insert、Find
	{
		BST<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		{
			t.Insert(a[i]);
		}
		t.Insert(8);
		t.InOrder();

		//t.Find(3)->_key = 4;
		t.InOrder();

	}
	void test2()//Erase 析构函数 test
	{
		BST<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		{
			t.Insert(a[i]);
		}
		t.InOrder();

		/*t.~BST();*/

		t.Erase(4);
		t.InOrder();

		t.Erase(6);
		t.InOrder();

		t.Erase(14);
		t.InOrder();

		t.Erase(3);
		t.InOrder();

		t.Erase(8);
		t.InOrder();

		t.Erase(1);
		t.InOrder();

		t.Erase(10);
		t.InOrder();

		t.Erase(13);
		t.InOrder();

		t.Erase(7);
		t.InOrder();
	}


	void test3()//test 拷贝构造 赋值重载
	{
		BST<int> t1;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		{
			t1.Insert(a[i]);
		}

		t1.InOrder();
		cout << endl;

		BST<int> t2(t1);

		t1.Insert(12);
		t1.InOrder();
		t2.InOrder();
		cout << endl;

		BST<int> t3;
		t3 = t1;
		t1.Erase(14);
		t1.InOrder();
		t2.InOrder();
		t3.InOrder();
		cout << endl;
	}

	void test4()//测试递归版本的增删查
	{
		BST<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		{
			t.InsertR(a[i]);
		}
		t.InsertR(8);
		t.InOrder();

		/*t.FindR(3)->_key = 4;
		t.InOrder();*/

		/*t.~BST();*/

		t.Erase(4);
		t.InOrder();

		t.Erase(6);
		t.InOrder();

		t.Erase(14);
		t.InOrder();

		t.Erase(3);
		t.InOrder();

		t.Erase(8);
		t.InOrder();

		t.Erase(1);
		t.InOrder();

		t.Erase(10);
		t.InOrder();

		t.Erase(13);
		t.InOrder();

		t.Erase(7);
		t.InOrder();
	}
}

int main()
{
	my_stl::test4();
	return 0;
}