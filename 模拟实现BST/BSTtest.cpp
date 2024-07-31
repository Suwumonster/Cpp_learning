#define _CRT_SECURE_NO_WARNINGS 1
#include "BST.h"

namespace my_stl
{
	//no V only K
	void test1()//≤‚ ‘Insert°¢Find
	{
		BST<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		{
			t.Insert(a[i]);
		}
		t.Insert(8);
		t.InOrder();

		t._InOrder(t.Find(3));
		t._InOrder(t.Find(12));
	}
	void test2()//Erase
	{
		BST<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		{
			t.Insert(a[i]);
		}
		t.InOrder();

		t.~BST();

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
	my_stl::test2();
	return 0;
}