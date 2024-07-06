#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

namespace my_stl
{
	void consttest(const List<int>& lt)
	{
		auto it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		cout << lt.front() << endl;
		cout << lt.back() << endl;

	}
	//≤‚ ‘push pop
	void test1()
	{
		List<int> lt;
		lt.push_front(1);
		lt.push_front(2);
		lt.push_front(3);
		lt.push_front(4);
		consttest(lt);

		lt.pop_front();
		lt.pop_front();
		lt.pop_front();
		consttest(lt);


		//lt.push_back(1);
		//lt.push_back(2);
		//lt.push_back(3);
		//lt.push_back(4);
		//consttest(lt);

		//lt.pop_back();
		//lt.pop_back();
		//lt.pop_back();
		//consttest(lt);
	}

	//≤‚ ‘insert erase
	void test2()
	{
		List<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		consttest(lt);

		//auto pos = lt.begin();

		//pos++;
		//pos++;

		//lt.insert(pos, 30);
		//consttest(lt);

		auto pos = find(lt.begin(), lt.end(), 2);
		lt.erase(pos);
		consttest(lt);

		pos = find(lt.begin(), lt.end(), 4);
		lt.insert(pos, 40);
		consttest(lt);

	}

	void test3()//≤‚ ‘swap
	{
		List<int> lt1;
		List<int> lt2;

		lt1.push_back(5);
		lt1.push_back(6);
		lt1.push_back(7);
		lt1.push_back(8);

		lt2.push_back(1);
		lt2.push_back(2);
		lt2.push_back(3);
		lt2.push_back(4);

		consttest(lt1);
		consttest(lt2);

		lt1.swap(lt2);

		consttest(lt1);
		consttest(lt2);
	}

	void test4()//≤‚ ‘list(n, val) list(start, end)
	{
		List<int> lt(10, 1);
		consttest(lt);


		string s = "hello";
		List<int> lt1(s.begin(), s.end());
		consttest(lt1);

	}

	void test5()//≤‚ ‘ size øΩ±¥ππ‘Ï ∏≥÷µ÷ÿ‘ÿ
	{
		//List<int> lt(3, 1);
		//List<int> lt1(lt);
		////cout << lt.size() << endl;

		//consttest(lt);
		//consttest(lt1);

		//List<int> lt2;
		//lt2 = lt;
		//consttest(lt2);


		//∂‡÷ÿøΩ±¥
		//string s = "123";

		//List<string> lt;

		//lt.push_back(s);
		//lt.push_back(s);
		//lt.push_back(s);
		//lt.push_back(s);

		//for (auto e : lt)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;

		//List<string> lt1;
		//lt1 = lt;

		//for (auto e : lt1)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;

		//∂‡÷ÿ…ÓøΩ±¥
		string s = "123";
		List<string> lt;
		lt.push_back(s);
		lt.push_back(s);
		lt.push_back(s);
		lt.push_back(s);
		List<List<string>> llt;
		llt.push_back(lt);
		llt.push_back(lt);
		llt.push_back(lt);

		for (auto e : llt)
		{
			for (auto eoe : e)
			{
				cout << eoe << " ";
			}
			cout << endl;
		}
		cout << endl;

		List<List<string>> llt1(llt);
		List<List<string>> llt2;
		llt2 = llt;

	}

	void test6()//front back clear
	{
		List<int> lt1;
		List<int> lt2;

		lt1.push_back(5);
		lt1.push_back(6);
		lt1.push_back(7);
		lt1.push_back(8);

		cout << lt1.front() << endl;
		cout << lt1.back() << endl;
		consttest(lt1);

		lt1.clear();
		consttest(lt1);
	}
}
int main()
{
	my_stl::test6();
	return 0;
}