#define _CRT_SECURE_NO_WARNINGS 1
#include "BST.h"
#include <string>

namespace my_stl_Kmode
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

namespace my_stl_KVmode
{
	void test1()
	{
		BST<string, string> dict;
		dict.Insert("insert", "插入");
		dict.Insert("erase", "删除");
		dict.Insert("left", "左边");
		dict.Insert("string", "字符串");

		string str;
		while (cin >> str)
		{
			auto ret = dict.Find(str);
			if (ret)
			{
				cout << str << ":" << ret->_val << endl;
			}
			else
			{
				cout << "单词拼写错误" << endl;
			}
		}

		string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
		// 统计水果出现的次
		BST<string, int> countTree;
		for (auto str : strs)
		{
			auto ret = countTree.Find(str);
			if (ret == NULL)
			{
				countTree.Insert(str, 1);
			}
			else
			{
				ret->_val++;
			}
		}
		countTree.InOrder();
	}
}

int main()
{
	my_stl_KVmode::test1();
	return 0;
}