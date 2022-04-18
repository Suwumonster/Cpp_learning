#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
typedef struct NODE
{
	char name[20];
	int data;
	int priority;
}node;
bool operator < (const node a,const node b)
{
	if (a.priority > b.priority)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	priority_queue <node> p;
	char c1[4] = { 0 };
	while (cin >> c1)
	{
		node n;
		if (strcmp(c1, "GET") == 0)
		{
			if (p.empty())
			{
				cout << "EMPTY QUEUE!" << endl;
			}
			else
			{
				n = p.top();
				cout << n.name << " " << n.data << endl;
				p.pop();
			}
		}
		else if (strcmp(c1, "PUT") == 0)
		{
			node n;
			cin >> n.name >> n.data >> n.priority;
			p.push(n);
		}
	}
	return 0;
}