#define _CRT_SECURE_NO_WARNINGS 1
#include "priority_queue.h"

namespace my_stl
{
	void test1()
	{
		priority_queue<int> pq;
		pq.push(1);
		pq.push(2);
		pq.push(4);
		pq.push(3);
		pq.push(5);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;

		priority_queue<int, vector<int>, greater<int>> pq1;
		pq1.push(1);
		pq1.push(2);
		pq1.push(4);
		pq1.push(3);
		pq1.push(5);


		while (!pq1.empty())
		{
			cout << pq1.top() << " ";
			pq1.pop();

		}
		cout << endl;
	}
}

int main()
{
	my_stl::test1();
	return 0;
}