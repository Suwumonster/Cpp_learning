#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
typedef struct Link
{
	int num;
	struct Link* next;
}link;
link* setLink()
{
	link* head = new link[sizeof(link)];
	link* temp;
	head->next = NULL;
	temp = head;
	int n = 0;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		link* newp = new link[sizeof(link)];
		newp->num = n;

		newp->next = NULL;
		temp->next = newp;
		temp = newp;
	}
	return head;
}
int main()
{
	int i = 0;
	cout << "input 0 - end" << endl;
	link* hp = setLink();
	link* p;
	p = hp->next;
	if (p != NULL)
	{
		cout << "linkelems:";
		while (p != NULL)
		{
			cout << p->num << " ";
			p = p->next;
		}
		cout << endl;
	}
	else
	{
		cout << "link does not exist!" << endl;
	}
	return 0;
}