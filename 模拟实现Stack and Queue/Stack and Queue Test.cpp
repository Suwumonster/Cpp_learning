#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack and Queue.h"
namespace my_stl
{
	void test1()//test stack
	{
		stack<int> st1;
		stack<int> st2;

		st1.push(1);
		st1.push(2);
		st1.push(3);
		st1.push(4);

		st2.push(5);
		st2.push(6);
		st2.push(7);
		st2.push(8);

		st1.swap(st2);

		while (!st1.empty())
		{
			int tmp = st1.top();
			st1.pop();
			cout << tmp << " ";
		}
		cout << endl;

	}
	void test2()//test queue
	{
		queue<int> qu1;
		queue<int> qu2;

		qu1.push(1);
		qu1.push(2);
		qu1.push(3);
		qu1.push(4);

		qu2.push(5);
		qu2.push(6);
		qu2.push(7);
		qu2.push(8);

		qu1.swap(qu2);

		while (!qu1.empty())
		{
			int tmp = qu1.front();
			qu1.pop();
			cout << tmp << " ";
		}
		cout << endl;
	}
}

int main()
{
	my_stl::test2();
	return 0;
}