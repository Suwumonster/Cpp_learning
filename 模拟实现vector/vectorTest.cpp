//v2

#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"
using std::cout;
using std::endl;
using std::find;

namespace my_stl
{
	//测试const对象的输出
	void constTest(const vector<int>& v)
	{
		auto it = v.cbegin();
		while (it != v.cend())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		//cout << v.size() << endl;
		//cout << v.capacity() << endl;

		//for (int i = 0; i < 5; i++)
		//{
		//	cout << v[i] << " ";
		//}
		//cout << endl;
	}
	//测试begin、end、cbegin、cend、reserve、部分构造函数
	void test1()
	{
		vector<int> v1;
		vector<int> v2(5, 10);

		constTest(v2);

		//auto it = v2.begin();
		//while (it != v2.end())
		//{
		//	cout << *it << " ";
		//	it++;
		//}
		//cout << endl;

		//cout << v2.size() << endl;
		//cout << v2.capacity() << endl;

	}

	void test2()//测试resize
	{
		vector<int> v1(5, 1);
		constTest(v1);

		v1.resize(3);
		constTest(v1);

		v1.resize(10);
		constTest(v1);

	}

	//测试push_back和pop_back
	void test3()
	{
		vector<int> v1;
		constTest(v1);

		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		constTest(v1);

		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		constTest(v1);

		v1.pop_back();
		//v1.pop_back();
	}

	void test4()//测试insert和erase
	{
		vector<int> v;
		constTest(v);

		auto pos = v.end();
		for (int i = 1; i < 6; i++)
		{
			v.insert(pos, i);
			pos = v.end();
		}
		constTest(v);

		pos = find(v.begin(), v.end(), 3);
		v.insert(pos, 30);
		constTest(v);

		pos = find(v.begin(), v.end(), 30);
		v.erase(pos);
		constTest(v);

		//v.erase(pos);

	}

	void test5()//测试[] []consts
	{
		vector<int> v1;
		for (int i = 0; i < 5; i++)
		{
			v1.push_back(i);
		}

		for (int i = 0; i < 5; i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		constTest(v1);
	}

	void test6()//vector() reload crush test
	{
		std::string s = "hello";
		vector<int> v1(s.begin(), s.end());
		vector<int> v2(10, 2);

		constTest(v1);
		constTest(v2);
	}

	void test7()//test =reload
	{
		vector<int> v1;
		vector<int> v2(10, 2);
		vector<int> v3(5, 1);

		constTest(v1);
		constTest(v2);
		constTest(v3);

		v1 = v2;
		constTest(v1);
		constTest(v2);
		constTest(v3);

		v1 = v3;
		constTest(v1);
		constTest(v2);
		constTest(v3);
	}

	void test8()//test swap and copy construct
	{
		vector<vector<int>> vv1;
		
		vector<int> v(5, 1);
		for (int i = 0; i < 5; i++)
		{
			vv1.push_back(v);
		}

		vector<vector<int>> vv2(vv1);

		vv1.swap(vv2);
	}
}


int main()
{
	my_stl::test8();
	return 0;
}